/*
* Copyright (c) 2004-2006 Nokia Corporation and/or its subsidiary(-ies).
* All rights reserved.
* This component and the accompanying materials are made available
* under the terms of "Eclipse Public License v1.0"
* which accompanies this distribution, and is available
* at the URL "http://www.eclipse.org/legal/epl-v10.html".
*
* Initial Contributors:
* Nokia Corporation - initial contribution.
*
* Contributors:
*
* Description:  RSFW Mount Manager API
*
*/


#ifndef CRSFWMOUNTMAN_H
#define CRSFWMOUNTMAN_H

#include <e32cmn.h>
#include <e32base.h>
#include <f32file.h>
#include <s32strm.h>

#include <rsfwmountentry.h> // mount entry constants

class TRsfwMountInfo;

// FORWARD DECLARATIONS
class CRsfwMountEntry;
class CRsfwMountManImpl;
class CDesC16Array;

// CONSTANTS
// the secure UID of the server, used as a P&S key category
const TUid KRfeServerSecureUid = { 0x101F970D };
//the maximum number of remote drives
const TInt KMaxRemoteDrives = 9;

// DATA TYPES
// Event types for MRsfwMountManObserver
enum TMountManEvent
    {
    EMountManEventMountConfigurationChanged = 1,
    EMountManEventMounted
    };

// P&S keys
// for notifying UI that a remote drive has been connected or disconnected
enum TRfePSKeys
	{
	ERsfwPSKeyConnect
	};

// Connection states
const TUint KMountStronglyConnected = 0x01;
const TUint KMountConnecting = 0x02; // temporary state during establishing a connection
                                     // to the drive, not to be used via MountMan API
const TUint KMountNotConnected      = 0x03;

// CLASS DECLARATION
/**
 *  Interface for receiving mounting events
 *
 *  @lib mountman.dll
 *  @since Series 60 3.1
 */

class MRsfwMountManObserver
    {
public:
    /**
     * Handles an event emanating from a CRsfwMountMan class
     *
     * @param aEventType type of the event
     * @param aStatus status code
     * @param aArg miscellaneous arguments
     */
    virtual void HandleMountManEventL(TMountManEvent aEvent,
                                      TInt aStatus,
                                      TAny* aArg) = 0;
    };

/**
 *  Encapsulates remote mount configuration.
 *
 *  @lib rsfwmountman.dll
 *  @since Series 60 3.1
 */
class TRsfwMountConfig
    {
public:   // New functions
    IMPORT_C void ExternalizeL(RWriteStream& aStream) const;
    IMPORT_C void InternalizeL(RReadStream& aStream);

public:   // Data
    TChar                         iDriveLetter;
    TBuf<KMaxMountNameLength>     iName;
    TBuf<KMaxMountUriLength>      iUri;
    TBuf<KMaxMountUserNameLength> iUserName;
    TBuf<KMaxMountPasswordLength> iPassword;
    TBuf<KMaxMountAuxDataLength>  iAuxData;
    TUint                         iFlags;
    TInt                          iInactivityTimeout;
    };
    

/**
 *  Encapsulates remote mount status information.
 *
 *  @lib rsfwmountman.dll
 *  @since Series 60 3.1
 */
class TRsfwMountStatus
    {
public:   // Data
    TInt                          iVolumeId;
    /** iMountState is not used and will be removed */
    TUint                         iMountState;  
    /** see KMountStronglyConnected and other connection states */
    TUint                         iConnectionState; 
    TInt                          iCachedSize;
    TInt                          iInactivityTime;
    TInt                          iInactivityTimeout;
    TBool                         iPermanence;
    };
    

/**
 *  Encapsulates all information about a mount.
 *
 *  @lib rsfwmountman.dll
 *  @since Series 60 3.1
 */
class TRsfwMountInfo
    {
public:   // New functions
    void ExternalizeL(RWriteStream& aStream) const;
    void InternalizeL(RReadStream& aStream);

public:   // Data
    TRsfwMountConfig                  iMountConfig;
    TRsfwMountStatus                  iMountStatus;
    }; 
    



// CLASS DECLARATION

/**
 *  Class for managing mounts to remote file repositories
 *
 *  @lib mountman.dll
 *  @since Series 60 3.1
 */

class CRsfwMountMan : public CBase
    {
public: // Constructors and destructor
    /**
     * Two-phased constructor.
     *
     * @param aDefaultFlags must be set to KMountFlagInteractive
     *   if the user is to be prompted during the mount procedure.
     *   Otherwise the parameter can be set to zero.
     * @param mount event observer
     * @return pointer to the created CRsfwMountMan object instance
     */
    IMPORT_C static CRsfwMountMan* NewL(TUint aDefaultFlags,
                                    MRsfwMountManObserver* aMountManObserver);

    /**
     * Destructor.
     */
    IMPORT_C virtual ~CRsfwMountMan();

public: // New functions
    /**
     * Returns a list of friendly names of all mount configurations
     * in the mount configuration repository.
     * The entries are returned in the order that they appear in the
     * repository.
     * @param aNames friendly names
     * @return nothing
     */
    IMPORT_C void GetMountNamesL(CDesC16Array* aNames) const;

    /**
     * Gets the mount configuration entry having the given friendly name.
     * The caller must make sure that the name is unique.
     * @param aId friendly name
     * @return a pointer to the configuration entry or NULL if not found
     */
    IMPORT_C const CRsfwMountEntry* MountEntryL(const TDesC& aName) const;

    /**
     * Gets the mount configuration entry for the given drive letter.
     * @param aDriveLetter drive letter
     * @return a pointer to the configuration entry or NULL if not found
     */
    IMPORT_C const CRsfwMountEntry* MountEntryL(TChar aDriveLetter) const;

    /**
     * Adds a mount configuration entry in the configurations and
     * mounts the drive in the File Server.
     * If the drive letter item is not set in the configuration,
     * a free letter will be allocated.
     * Then the EMountEntryItemDrive value in aMountEntry will be changed.
     * The EMountEntryItemIndex item of aMountEntry is used for
     * positioning the entry in a specific order in the configuration database
     * (the index itself is not stored)
     *
     * @param aMountEntry mount configuration entry
     *  the ownership of the pointer is transferred to CRsfwMountMan
     * @return nothing
     * @leave KErrInUse selected drive letter already in used
     * @leave KErrInUse selected name is in use
     * @leave KErrInUse 9 remote drives already define
     * (Number of remote drives is limited by default to 9 so that drive 
     *  letters are also available for other technologies)
     * @leave KErrAccessDenied program does not have sufficient capabilities
     *        required capabilities are DiskAdmin (to mount new remote drive in 
     *        File Server) and WriteDeviceData (to add new remote drive to
     *         Central Repository)
     * @leave KErrNotFound
     *        File System plug-in, Central Repository table etc. not found
     */
    IMPORT_C void AddMountEntryL(CRsfwMountEntry* aMountEntry);

    /**
     * Deletes a mount entry from the configurations and unmounts the drive.
     * Nothing is done if the entry does not exist.
     *
     * @param aName name
     * @return nothing
     */
    IMPORT_C void DeleteMountEntryL(const TDesC& aName);

    /**
     * Deletes a mount entry from the configurations and unmounts the drive.
     * Nothing is done if the entry does not exist.
     *
     * @param aDriveLetter drive letter
     * @return nothing
     */
    IMPORT_C void DeleteMountEntryL(TChar aDriveLetter);

  
    /**
     * Gets a list of all drives as seen by the File Server
     *
     * Returns drive letters. 
     * Letters for local drives are in the front of the list
     * Letters for remote drives in order defined in CenRep
     *   The number of the drives is the same as the length of the list
     *
     * @param aDriveList returned drive list
     * @return number of remote drives
     */
    IMPORT_C TInt GetAllDrivesL(TDriveList& aDriveList) const;

    /**
     * Gets a list of all remote drives as seen by the File Server
     *
     * The list contains the letters of the remote drives.
     * Letters for remote drives in order defined in CenRep
     *   The number of the drives is the same as the length of the list
     *
     * @param aDriveList returned drive list
     * @return number of remote drives
     */
    IMPORT_C TInt GetRemoteMountListL(TDriveList& aDriveList) const;
    
    /**
     * Gets mount information for an active remote drive.
     *
     * The information consists of static configuration information and
     *   status information (such as strongly or weakly connected).
     * Note that if the drive is not atctive this function will 
     * return -1, you need to use MountEntryL to get just the static 
     * configuration information
     *
     * @param aDriveLetter drive letter of the mount
     * @param aMountInfo returned information
     * @return error code
     */
    IMPORT_C TInt GetMountInfo(TChar aDriveLetter, TRsfwMountInfo& aMountInfo) const;

    /**
     * Sets the connection state of a mount for an active remote drive
     *
     * @param aDriveLetter drive letter of the mount
     * @param aConnectionState
     *   The following connection states have been defined:
     *     KMountStronglyConnected = strongly connected state
     *     KMountWeaklyConnected   = weakly connected state
     *     KMountNotConnected      = disconnected state
     *
     * @return error code
     */
    IMPORT_C TInt SetMountConnectionState(TChar aDriveLetter,
                                          TUint aConnectionState);

    /**
     * Changes a mount configuration entry in the configurations
     *  
     * @param aMountEntry mount configuration entry
     *  the ownership of the pointer is transferred to CRsfwMountMan
     * @return nothing
     * @leave KErrInUse if the name of the mount is used by other mount
     * @leave KErrAccessDenied program does not have sufficient capabilities
     *        required capabilities are DiskAdmin (to mount new remote drive in 
     *        File Server) and WriteDeviceData (to add new remote drive to
     *         Central Repository)
     * @leave KErrNotFound if mount with given letter not found or
     *        File System plug-in, Central Repository table etc. not found
     */
    IMPORT_C void EditMountEntryL(CRsfwMountEntry* aMountEntry);
    
    
     /**
     * Refresh a remote directory
     *
     * Ensures that contents of a remote directory are up to date.
     * Synchronous variant deletes the currently cached version.
     * Note that this function intentionally does not return directory
     * contents. All data should be read through the File Server instead.
     *
     * @return KErrArgument Path refers to a file
     *         KErrNotFound path is not found from cache
     */
    IMPORT_C TInt RefreshDirectory(const TDesC& aPath);

    /**
     * Some applications have problems with handling remote files.
     * Function checks whether app with given UID is one of them.
     *  
     * @param aUid UID of the application
     * @return ETrue if it is on the black list, otherwise EFalse
     */    
    IMPORT_C TBool IsAppOnBlackList(TUid aUid) const;
    
    
     /**
     * Cancels an active remote file upload or download
     * 
     * @param aFile file name
     * @return one of the system wide error codes.
     */    
    IMPORT_C TInt CancelRemoteTransfer(const TDesC& aFile);
    
    
    /**
     * Sets the connection state of a mount for an active remote drive
     * sends a bling request, does not wait for reply
     *
     * @param aDriveLetter drive letter of the mount
     * @param aConnectionState
     *   The following connection states have been defined:
     *     KMountStronglyConnected = strongly connected state
     *     KMountWeaklyConnected   = weakly connected state
     *     KMountNotConnected      = disconnected state
     *
     * @return error code
     */
    IMPORT_C TInt SetMountConnectionStateBlind(TChar aDriveLetter,
                                          TUint aConnectionState);

    
private:
    /**
     * C++ default constructor
     */
    CRsfwMountMan();
    
    /**
     * Second phase constructor
     */
    void ConstructL(TUint aDefaultFlags,
                    MRsfwMountManObserver* aMountManObserver);

private: // Data
    CRsfwMountManImpl* iMountManImpl; // implementation
    };

#endif // CRSFWMOUNTMAN_H

// End of File
