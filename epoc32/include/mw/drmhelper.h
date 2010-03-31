/*
* Copyright (c) 2003, 2004 Nokia Corporation and/or its subsidiary(-ies).
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
* Description:  Class to show miscellaneous DRM related error notes and 
*                details about rights 
*
*/



#ifndef __DRMHELPER_H__
#define __DRMHELPER_H__

//  INCLUDES
#include <e32base.h>
#include <ConeResLoader.h>
#include <apparc.h>
#include <rdrmhelper.h>
#include <aknserverapp.h>
#include <caf/caf.h>
#include <caf/content.h>
#include <caf/data.h>
#include <eikdialg.h>

using namespace ContentAccess;

// CONSTANTS
const TInt KDRMHelperDefaultCountThreshold = 3;
const TInt KDRMHelperDefaultTimeThreshold = 7;
const TInt KDRMHelperDefaultPercentageThreshold = 10;
const TInt KDRMHelperNoteMaxSize ( 256 );  

// MACROS

// DATA TYPES
enum TDRMHelperPreviewMediaType
        {
        EPreviewTypeAudio,
        EPreviewTypeVideo
        };
// FUNCTION PROTOTYPES

// FORWARD DECLARATIONS
class DRMCommon;
class CDRMRightsConstraints;
class CDRMRights;
class CStringResourceReader;
class TDataType;
class CCoeEnv;
class CConsumeData;
class CDRMPermission;
class CDRMConstraint;
class CAknGlobalNote;
class CAknWaitDialog;
class CDRMHelperInfoNoteWrapper;
class CSchemeHandler;
class CMediatorEventProvider;

// CLASS DECLARATION

/**
*  Helper class for wrapping CDRMRightsConstraints.
*
*  @lib drmhelper.lib
*  @since Series 60 2.1
*/
class CDRMHelperRightsConstraints : public CBase
    {
    public:  // Constructors and destructor
        
        /**
        * Two-phased constructor.
        */
        static CDRMHelperRightsConstraints* NewL( 
            CDRMRightsConstraints* aConstraints );
        static CDRMHelperRightsConstraints* NewLC( 
            CDRMRightsConstraints* aConstraints );
        
        /**
        * Destructor.
        */
        IMPORT_C ~CDRMHelperRightsConstraints();

    public: // New functions

        /**
        * checks if the object contains any restrictions 
        * or if usage is unconstrained.        
        * @return ETrue if usage is unconstrained
        */
        IMPORT_C TBool FullRights();

        /**
        * checks if the object contains only preview rights 
        * @return ETrue if object contains only preview rights
        */
        IMPORT_C TBool IsPreview();

        /**
        * Gets number of counts left and number of original counts.
        * Leaves with KErrNotFound if object doesn't have count based rights.
        * @param aCounter: (out) counts left
        * @param aOriginalCounter: (out) number of counts when stored to 
        *                          rights db
        * @return -
        */
        IMPORT_C void GetCountersL( TUint32& aCounter, 
            TUint32& aOriginalCounter );

        /**
        * Gets start time of time based rights.
        * Leaves with KErrNotFound if object doesn't have time based rights.
        * @param aStartTime: (out) start time
        * @return -
        */
        IMPORT_C void GetStartTimeL( TTime& aStartTime );

        /**
        * Gets end time of time based rights.
        * Leaves with KErrNotFound if object doesn't have time based rights.
        * @param aEndTime: (out) start time
        * @return -
        */
        IMPORT_C void GetEndTimeL( TTime& aEndTime );

        /**
        * Gets interval time constraint.
        * Leaves with KErrNotFound if object doesn't have interval constraint.
        * @param aInterval: (out) interval
        * @return -
        */
        IMPORT_C void GetIntervalL( TTimeIntervalSeconds& aInterval );

        /**
        * Gets start time of activated interval constraint.
        * Leaves with KErrNotFound if interval has not been started yet.
        * @param aStartTime: (out) start time of activated interval
        * @return -
        */

        IMPORT_C void GetIntervalStartL( TTime& aStartTime );
        /**
        * Gets number of counts left, number of original counts and timer 
        * value for timed-count constraint.
        * Leaves with KErrNotFound if object doesn't have timed-count 
        * constraint.
        * @param aCounter: (out) counts left
        * @param aOriginalCounter: Invalid, value returned same as aCounter
        * @param aTimer: (out) timer value
        * @return -
        * @since Series 60 3.0
        */
        IMPORT_C void GetTimedCountL( TUint32& aCounter, 
            TUint32& aOriginalCounter, TTimeIntervalSeconds& aTimer );

        /**
        * Gets accumulated time left.
        * Leaves with KErrNotFound if object doesn't have accumulated time 
        * constraint.
        * @param aAccumulatedTime: (out) accumulated time left
        * @return -
        * @since Series 60 3.0
        */
        IMPORT_C void GetAccumulatedTimeL( TTimeIntervalSeconds& aAccumulatedTime );

    private:

        /**
        * C++ default constructor.
        */
        CDRMHelperRightsConstraints( CDRMRightsConstraints* aConstrains );

        /**
        * By default Symbian 2nd phase constructor is private.
        */
        void ConstructL();

    private:    // Data
        // pointer to CDRMRightsConstraints object
        CDRMRightsConstraints* iConstraints;
    };


/**
*  Handles some error situations DRM-aware applications may encounter.
*
*  @lib drmhelper.lib
*  @since Series 60 2.1
*/
class CDRMHelper : public CBase, public MAknServerAppExitObserver
    {
    public:     // Data
    
    enum TDRMHelperNotificationID
        {
        ETActivateTextId = 1,
        ETCountBasedErrorTextId = 2 ,
        ETCountUsageReduceId = 3,
        ETCountUsageReduceMediaId = 4
        };

    enum TDRMHelperConsumeAction
        {
        EStart,
        EFinish,
        EPause, 
        EContinue
        };

    enum TDRMHelperOMALevel
        {
        EOMA_None, 
        EOMA_1_0,
        EOMA_2_0
        };
        
	enum TDRMHelperPreviewType 
		{
		ENoPreview, 
		EEmbeddedPreview,
		EPreviewRights
		};

    enum TDRMHelperAutomatedType
        {
        EAutomatedTypeRingingTone,
        EAutomatedTypeMessageAlert,
        EAutomatedTypeEmailAlert,
        EAutomatedTypeIMAlert,
        EAutomatedTypeCalendarAlarm,
        EAutomatedTypeScreenSaver,
        EAutomatedTypeWallpaper, 
        EAutomatedTypeTheme,
        EAutomatedTypeClockAlarm, 
        EAutomatedTypeOther = KMaxTUint8
        };

    enum TDRMHelperDRMMethods
        {
        EForwardLock = 0x0001, 
        ECombinedDelivery = 0x0002, 
        ESeparateDelivery = 0x0004, 
        ESuperDistribution = 0x0008
        };

    public:  // Constructors and destructor
        
        /**
        * Two-phased constructor.
        */
        IMPORT_C static CDRMHelper* NewL( CCoeEnv& aCoeEnv );
        IMPORT_C static CDRMHelper* NewLC( CCoeEnv& aCoeEnv );

        /**
        * Two-phased constructor.
        * @since Series 60 2.6
        */
        IMPORT_C static CDRMHelper* NewL();
        IMPORT_C static CDRMHelper* NewLC();
        
        /**
        * Two-phased constructor.
        * @since Series 60 3.0
        */
        IMPORT_C static CDRMHelper* NewL( CCoeEnv& aCoeEnv, RFs& aFs );
        IMPORT_C static CDRMHelper* NewLC( CCoeEnv& aCoeEnv, RFs& aFs );

        /**
        * Two-phased constructor.
        * @since Series 60 3.0
        */
        IMPORT_C static CDRMHelper* NewL( RFs& aFs );
        IMPORT_C static CDRMHelper* NewLC( RFs& aFs );
        
        /**
        * Destructor.
        */
        IMPORT_C ~CDRMHelper();

       
    public: 

        /**
        * Displays appropriate error note depending on error code.
        * @param aError: error code returned by DRM engine
        * @param aURI: URI of the file
        * @return 
        * - Button code, if user selected "buy rights" or "launch rights 
        *   manager" in query.
        * - 0 if user selected "No", "Back" or "Cancel" (or whatever which 
        *   just dismiss the query)
        * - 0 if just a simple error note is displayed
        */
        IMPORT_C TInt HandleErrorL( TInt aError, 
            const TDesC8& aURI );


        /**
        * Displays:
        * Handles error situations 'rights expired', 'no rights' and
        * 'rights database corrupted'.
        * @param aError: error code returned by DRM engine
        * @param aFileName: full path to file
        * @return 
        * - Button code, if user selected "buy rights" or "launch rights 
        *   manager" in query.
        * - 0 if user selected "No", "Back" or "Cancel" (or whatever which 
        *   just dismiss the query)
        * - 0 if just a simple error note is displayed
        */
        IMPORT_C TInt HandleErrorL( TInt aError, 
            const TDesC& aFileName );


        /**
        * Displays:
        * Handles error situations 'rights expired', 'no rights' and
        * 'rights database corrupted'.
        * @param aError: error code returned by DRM engine
        * @param aFileHandle: file handle to the file
        * @return 
        * - Button code, if user selected "buy rights" or "launch rights 
        *   manager" in query.
        * - 0 if user selected "No", "Back" or "Cancel" (or anything that 
        *   just dismisses the query)
        * - 0 if just a simple error note is displayed
        * @since  3.0
        */
        IMPORT_C TInt HandleErrorL( TInt aError, 
            RFile& aFileHandle );

       /**
        * Handles DRM-specific error situations. Should be called instead of 
        * HandleErrorL if user should be asked to play embedded preview or get 
        * preview/silent rights if there is no valid rights and either embedded preview or
        * preview rights are available.
        * @param aError: error code to be handled.
        * @param aFile: handle of file for which error was received.
        * @param aEmbeddedPreviewUri: contain URI of embedded preview part 
        * upon return if caller should play the embedded preview. If embedded
        * preview should not be played this is NULL. Must be freed by caller.
        * @return KErrNone if the content is now usable (e.g. silent rights or preview rights were gotten). If
        *                  the return code is KErrNone and the aEmbeddedPreviewUri parameter is not NULL,
        *                  the player should use embedded preview
        *         KErrCancel if the user cancelled any of the actions within the function
        *         KErrCANoRights and KErrCANoPermission if after the function call, still no rights exist
        *         KErrCompletion if the user did launch the browser, but it is not clear whether the content
        *                  was activated
        * @since S60 3.1
        */
        IMPORT_C TInt HandleErrorOrPreviewL( 
            TInt aError, 
            RFile& aFile, 
            HBufC8*& aEmbeddedPreviewUri );

       /**
        * Handles DRM specific error situations. Should be called instead of 
        * HandleErrorL if user should be asked to play embedded preview or get 
        * preview/silent rights if there is no valid rights and either embedded preview or
        * preview rights are available.
        * @param aError: error code to be handled.
        * @param aFileName: name of file for which error was received.
        * @param aEmbeddedPreviewUri: contain URI of embedded preview part 
        * upon return if caller should play the embedded preview. If embedded
        * preview should not be played this is NULL. Must be freed by caller.
        * @return KErrNone if the content is now usable (e.g. silent rights or preview rights were gotten). If
        *                  the return code is KErrNone and the aEmbeddedPreviewUri parameter is not NULL,
        *                  the player should use embedded preview
        *         KErrCancel if the user cancelled any of the actions within the function
        *         KErrCANoRights and KErrCANoPermission if after the function call, still no rights exist
        *         KErrCompletion if the user did launch the browser, but it is not clear whether the content
        *                  was activated
        * @since S60 3.1
        */
        IMPORT_C TInt HandleErrorOrPreviewL( 
            TInt aError, 
            const TDesC& aFileName, 
            HBufC8*& aEmbeddedPreviewUri );

        /**
        * Check rights for the content. If there is less than given amount 
        * of usage time/count left, appropriate note is displayed
        * depending on situation.
        * @param  aURI: URI of the file
        * @return Button code
        */
        // causes conflict with other CheckRightsAmount method, removed for now...
//        IMPORT_C TInt CheckRightsAmountL( const TDesC8& aURI );


        /**
        * Check rights for the file. If there is less than given amount 
        * of usage time/count/percentage left, appropriate note is displayed
        * depending on situation.
        * @param  aFileName: Full path to file
        * @return Button code
        */
        // causes conflict with other CheckRightsAmount method, removed for now...
//        IMPORT_C TInt CheckRightsAmountL( const TDesC& aFileName );
                

        /**
        * Check rights for the file. If there is less than given amount 
        * of usage time/count/percentage left, appropriate note is displayed
        * depending on situation.
        * @param  aFileHandle: file handle to the file
        * @return Button code
        * @since  3.0
        */
        // causes conflict with other CheckRightsAmount method, removed for now...
//        IMPORT_C TInt CheckRightsAmountL( RFile& aFileHandle );


        /**
        * Check rights for the file. If there is less than given amount 
        * of usage time/count left, one of the following note is displayed
        * depending on situation:
        * 'Usage rights about to expire. View details?'
        * 'Usage rights about to expire. %N days left. View details?'
        * 'Usage rights about to expire. 1 day left. View details?'
        * 'Usage rights about to expire. %N counts left. View details?'
        * 'Usage rights about to expire. 1 count left. View details?'
        * It also checks that rights are valid and displays appropriate note,
        * if they are not.
        * @param  aFileName: Full path to file
        * @param  aCount: Threshold value for count limit
        * @param  aDays: Threshold value for time limit in days
        * @return Button code
        */
        IMPORT_C TInt CheckRightsAmountL( const TDesC& aFileName, 
            TInt aCount = KDRMHelperDefaultCountThreshold, 
            TInt aDays = KDRMHelperDefaultTimeThreshold );


        /**
        * Check rights for the file. If there is less than given amount 
        * of usage time/count left, one of the following note is displayed
        * depending on situation:
        * 'Usage rights about to expire. View details?'
        * 'Usage rights about to expire. %N days left. View details?'
        * 'Usage rights about to expire. 1 day left. View details?'
        * 'Usage rights about to expire. %N counts left. View details?'
        * 'Usage rights about to expire. 1 count left. View details?'
        * It also checks that rights are valid and displays appropriate note,
        * if they are not.
        * @param  aFileHandle: file handle to the file
        * @param  aCount: Threshold value for count limit
        * @param  aDays: Threshold value for time limit in days
        * @return Button code
        * @since  3.0
        */
        IMPORT_C TInt CheckRightsAmountL( RFile& aFileHandle, 
            TInt aCount = KDRMHelperDefaultCountThreshold, 
            TInt aDays = KDRMHelperDefaultTimeThreshold );


        /**
        * Check rights for the file. If there is less than given amount 
        * of usage time/count left, one of the following note is displayed
        * depending on situation:
        * 'Usage rights about to expire. View details?'
        * 'Usage rights about to expire. %N days left. View details?'
        * 'Usage rights about to expire. 1 day left. View details?'
        * 'Usage rights about to expire. %N counts left. View details?'
        * 'Usage rights about to expire. 1 count left. View details?'
        * It also checks that rights are valid and displays appropriate note,
        * if they are not.
        * @param  aUri: Content URI
        * @param  aCount: Threshold value for count limit
        * @param  aDays: Threshold value for time limit in days
        * @return Button code
        */
        IMPORT_C TInt CheckRightsAmountL( const TDesC8& aUri, 
            TInt aCount = KDRMHelperDefaultCountThreshold, 
            TInt aDays = KDRMHelperDefaultTimeThreshold );


        /**
        * Check rights for the file. If there is less than aThreshold percent 
        * of usage time/count left, one of the following note is displayed
        * depending on situation:
        * 'Usage rights about to expire. View details?'
        * 'Usage rights about to expire. %N days left. View details?'
        * 'Usage rights about to expire. 1 day left. View details?'
        * 'Usage rights about to expire. %N counts left. View details?'
        * 'Usage rights about to expire. 1 count left. View details?'
        * It also checks that rights are valid and displays appropriate note,
        * if they are not.
        * @param  aFileName: Full path to file
        * @param  aThreshold: Threshold value in percents for displaying the note
        * @return Button code
        */
        IMPORT_C TInt CheckRightsPercentL( const TDesC& aFileName, 
            TInt aThreshold = KDRMHelperDefaultPercentageThreshold );


        /**
        * Check rights for the file. If there is less than aThreshold percent 
        * of usage time/count left, one of the following note is displayed
        * depending on situation:
        * 'Usage rights about to expire. View details?'
        * 'Usage rights about to expire. %N days left. View details?'
        * 'Usage rights about to expire. 1 day left. View details?'
        * 'Usage rights about to expire. %N counts left. View details?'
        * 'Usage rights about to expire. 1 count left. View details?'
        * It also checks that rights are valid and displays appropriate note,
        * if they are not.
        * @param  aFileHandle: file handle to the file
        * @param  aThreshold: Threshold value in percents for displaying the note
        * @return Button code
        * @since  3.0
        */
        IMPORT_C TInt CheckRightsPercentL( RFile& aFileHandle, 
            TInt aThreshold = KDRMHelperDefaultPercentageThreshold );


        /**
        * Launches DRM Rights Manager UI embedded with details view related 
        * to given content.
        * @param aURI: URI of the file
        * @return -
        */
        IMPORT_C void LaunchDetailsViewEmbeddedL( 
            const TDesC8& aURI );

		
        /**
        * Launches DRM Rights Manager UI embedded with details view related 
        * to given file.
        * @param aFileName: Full path to file
        * @return -
        */
        IMPORT_C void LaunchDetailsViewEmbeddedL( 
            const TDesC& aFileName );


        /**
        * Launches DRM Rights Manager UI embedded with details view related 
        * to given file.    
        * @param  aFileHandle: file handle to the file
        * @return -
        * @since  3.0
        */
        IMPORT_C void LaunchDetailsViewEmbeddedL( 
            RFile& aFileHandle );


        /**
        * Launches DRM Rights Manager UI embedded with details view related 
        * to given content.
        * @param aContentURI: URI of the content
        * @return -
        */
        IMPORT_C void LaunchDetailsViewEmbeddedL( 
            const HBufC8* aContentURI );


        /**
        * Gets details of rights object associated of given file.
        *
        * @param[in]  aFileName Full path to file
        * @param[in]  aIntent ContentAccess::EPlay, ContentAccess::EView,
        * ContentAccess::EPrint or ContentAccess::EExecute 
        * @param[out] aExpired ETrue if rights are not valid. If this is ETrue
        * and some constraints are returned, rights will become valid in future
        * @param[out] aSendingAllowed ETrue if content can be sent
        * @param[out] aPlay play constraints, must be deleted by caller
        * @param[out] aDisplay display constraints, must be deleted by caller
        * @param[out] aExecute execute constraints, must be deleted by caller
        * @param[out] aPrint print constraints, must be deleted by caller
        *
        * @leave KErrArgument file is not DRM-protected.
        * @leave KErrCANoRights no rights
        * @see caferr.h
        * @see caftypes.h
        */
        IMPORT_C void GetRightsDetailsL( const TDesC& aFileName, 
            TUint32 aIntent, TBool& aExpired, TBool& aSendingAllowed, 
            CDRMHelperRightsConstraints*& aPlay, 
            CDRMHelperRightsConstraints*& aDisplay, 
            CDRMHelperRightsConstraints*& aExecute, 
            CDRMHelperRightsConstraints*& aPrint );


        /**
        * Gets details of rights object associated of given file.
        * 
        * @param[in]  aFileHandle file handle to the file
        * @param[in]  aIntent ContentAccess::EPlay, ContentAccess::EView,
        * ContentAccess::EPrint or ContentAccess::EExecute 
        * @param[out] aExpired ETrue if rights are not valid. If this is ETrue
        * and some constraints are returned, rights will become valid in future
        * @param[out] aSendingAllowed ETrue if content can be sent
        * @param[out] aPlay play constraints, must be deleted by caller
        * @param[out] aDisplay display constraints, must be deleted by caller
        * @param[out] aExecute execute constraints, must be deleted by caller
        * @param[out] aPrint print constraints, must be deleted by caller
        *
        * @leave KErrArgument file is not DRM-protected.
        * @leave KErrCANoRights no rights
        * @see caferr.h
        * @see caftypes.h
        *
        * @since  3.0
        */
        IMPORT_C void GetRightsDetailsL( RFile& aFileHandle,  
            TUint32 aIntent, TBool& aExpired, TBool& aSendingAllowed, 
            CDRMHelperRightsConstraints*& aPlay, 
            CDRMHelperRightsConstraints*& aDisplay, 
            CDRMHelperRightsConstraints*& aExecute, 
            CDRMHelperRightsConstraints*& aPrint );


        /**
        * Gets details of rights object associated of given file.
        *
        * @param[in]  aFileName Full path to file
        * @param[in]  aIntent ContentAccess::EPlay, ContentAccess::EView,
        * ContentAccess::EPrint or ContentAccess::EExecute 
        * @param[out] aExpired ETrue if rights are not valid. If this is ETrue
        * and some constraints are returned, rights will become valid in future
        * @param[out] aSendingAllowed ETrue if content can be sent
        * @param[out] aPlay play constraints, must be deleted by caller
        * @param[out] aDisplay display constraints, must be deleted by caller
        * @param[out] aExecute execute constraints, must be deleted by caller
        * @param[out] aPrint print constraints, must be deleted by caller
        *
        * @leave KErrArgument file is not DRM-protected.
        * @leave KErrCANoRights no rights
        * @see caferr.h
        * @see caftypes.h
        */
        IMPORT_C void GetRightsDetailsL( const TDesC& aFileName, 
            TUint32 aIntent, TBool& aExpired, TBool& aSendingAllowed, 
            CDRMRightsConstraints*& aPlay, 
            CDRMRightsConstraints*& aDisplay, 
            CDRMRightsConstraints*& aExecute, 
            CDRMRightsConstraints*& aPrint ); 


        /**
        * Gets details of rights object associated of given file.
        * 
        * @param[in]  aFileHandle file handle to the file
        * @param[in]  aIntent ContentAccess::EPlay, ContentAccess::EView,
        * ContentAccess::EPrint or ContentAccess::EExecute 
        * @param[out] aExpired ETrue if rights are not valid. If this is ETrue
        * and some constraints are returned, rights will become valid in future
        * @param[out] aSendingAllowed ETrue if content can be sent
        * @param[out] aPlay play constraints, must be deleted by caller
        * @param[out] aDisplay display constraints, must be deleted by caller
        * @param[out] aExecute execute constraints, must be deleted by caller
        * @param[out] aPrint print constraints, must be deleted by caller
        *
        * @leave KErrArgument file is not DRM-protected.
        * @leave KErrCANoRights no rights
        * @see caferr.h
        * @see caftypes.h
        *
        * @since  3.0
        */
        IMPORT_C void GetRightsDetailsL( RFile& aFileHandle,  
            TUint32 aIntent, TBool& aExpired, TBool& aSendingAllowed, 
            CDRMRightsConstraints*& aPlay, 
            CDRMRightsConstraints*& aDisplay, 
            CDRMRightsConstraints*& aExecute, 
            CDRMRightsConstraints*& aPrint ); 


        /**
        * Registers given content to be used as an automated content. This
        * function is used when registering application listens expiry 
        * notifications itself
        * @param  aURI: content URI
        * @return System wide error code (KErrCancel if user pressed no to 
        * query).
        * @since Series 60 2.6
        */
        IMPORT_C TInt SetAutomated( const TDesC8& aURI );


        /**
        * Registers given content to be used as an automated content. This
        * function is used when registering application listens expiry 
        * notifications itself.
        * @param  aFileName: Full path to file
        * @return System wide error code (KErrCancel if user pressed no to 
        * query).
        * @since Series 60 2.6
        */
        IMPORT_C TInt SetAutomated( const TDesC& aFilename );


        /**
        * Registers given content to be used as an automated content. This
        * function is used when registering application listens expiry 
        * @param  aFileHandle: file handle to the file
        * @return System wide error code (KErrCancel if user pressed no to 
        * query).
        * @since  3.0
        */
        IMPORT_C TInt SetAutomated( RFile& aFileHandle );


        /**
        * Displays the confirmation query about setting given content as an
        * automated content. Note that this function does not actually
        * register content, just displays the note
        * @param  aURI: content URI
        * @return System wide error code (KErrCancel if user pressed no to 
        * query).
        * @since Series 60 2.6
        */
        IMPORT_C TInt ShowAutomatedNote( const TDesC8& aURI );


        /**
        * Displays the confirmation query about setting given content as an
        * automated content. Note that this function does not actually
        * register content, just displays the note
        * @param  aFileName: Full path to file
        * @return System wide error code (KErrCancel if user pressed no to 
        * query).
        * @since Series 60 2.6
        */
        IMPORT_C TInt ShowAutomatedNote( const TDesC& aFilename );


        /**
        * Displays the confirmation query about setting given content as an
        * automated content. Note that this function does not actually
        * register content, just displays the note
        * @param  aFileHandle: file handle to the file
        * @return System wide error code (KErrCancel if user pressed no to 
        * query).
        * @since  3.0
        */
        IMPORT_C TInt ShowAutomatedNote( RFile& aFileHandle );


        /**
        * Registers given content to be used as an automated content. This
        * function is used when phone application listens to expiry notifications.
        * @param  aURI: content URI
        * @return System wide error code (KErrCancel if user pressed no to 
        * query).
        * @since Series 60 2.6
        */
        IMPORT_C TInt SetAutomatedPassive( const TDesC8& aURI );


        /**
        * Registers given content to be used as an automated content. This
        * function is used when phone application listens to expiry notifications.
        * @param  aFileName: Full path to file
        * @return System wide error code (KErrCancel if user pressed no to 
        * query).
        * @since Series 60 2.6
        */
        IMPORT_C TInt SetAutomatedPassive( const TDesC& aFilename );


        /**
        * Registers given content to be used as an automated content. This
        * function is used when phone application listens to expiry notifications.
        * @param  aFileHandle: file handle to the file
        * @return System wide error code (KErrCancel if user pressed no to 
        * query).
        * @since  3.0
        */
        IMPORT_C TInt SetAutomatedPassive( RFile& aFileHandle );


        /**
        * Registers given content to be used as an automated content without
        * confirmation query.
        * @param aURI: content URI
        * @param aActive: ETrue if registering application itself listens
        *                 expiry notifications
        * @return System wide error code (KErrCancel if user pressed no to 
        * query).
        * @since Series 60 2.6
        */
        IMPORT_C TInt SetAutomatedSilent( const TDesC8& aURI, TBool aActive );


        /**
        * Registers given content to be used as an automated content without
        * confirmation query.
        * @param  aFileName: Full path to file
        * @param  aActive: ETrue if registering application itself listens
        *                  expiry notifications
        * @return System wide error code (KErrCancel if user pressed no to 
        * query).
        * @since Series 60 2.6
        */
        IMPORT_C TInt SetAutomatedSilent( const TDesC& aFilename, 
            TBool aActive );


        /**
        * Registers given content to be used as an automated content without
        * confirmation query.
        * @param  aFileHandle: file handle to the file
        * @param  aActive: ETrue if registering application itself listens
        *                  expiry notifications
        * @return System wide error code (KErrCancel if user pressed no to 
        * query).
        * @since  3.0
        */
        IMPORT_C TInt SetAutomatedSilent( RFile& aFileHandle,  
            TBool aActive );


        /**
        * Unregisters given content to be used as an automated content.
        * @param aURI: content URI
        * @return System wide error code.
        * @since Series 60 2.6
        */
        IMPORT_C TInt RemoveAutomated( const TDesC8& aURI );


        /**
        * Unregisters given content to be used as an automated content.
        * @param  aFileName: Full path to file
        * @return System wide error code.
        * @since Series 60 2.6
        */
        IMPORT_C TInt RemoveAutomated( const TDesC& aFilename );


        /**
        * Unregisters given content to be used as an automated content.
        * @param  aFileHandle: file handle to the file
        * @return System wide error code.
        * @since  3.0
        */
        IMPORT_C TInt RemoveAutomated( RFile& aFileHandle );


        /**
        * Unregisters given content to be used as an automated content.
        * This function must be used when content was registered using 
        * SetAutomatedPassive.
        * @param  aURI: content URI
        * @return System wide error code.
        * @since Series 60 2.6
        */
        IMPORT_C TInt RemoveAutomatedPassive( const TDesC8& aURI );


        /**
        * Unregisters given content to be used as an automated content.
        * This function must be used when content was registered using 
        * SetAutomatedPassive.
        * @param  aFileName: Full path to file
        * @return System wide error code.
        * @since Series 60 2.6
        */
        IMPORT_C TInt RemoveAutomatedPassive( const TDesC& aFilename );


        /**
        * Unregisters given content to be used as an automated content.
        * This function must be used when content was registered using 
        * SetAutomatedPassive.
        * @param  aFileHandle: file handle to the file
        * @return System wide error code.
        * @since  3.0
        */
        IMPORT_C TInt RemoveAutomatedPassive( RFile& aFileHandle );


        /**
        * Checks if given content can be set as an automated content.
        * @param  aURI: content URI
        * @param  aValue: ETrue if content can be set as automated.
        * @return System wide or DRM specific error code.
        * @since Series 60 2.6
        */
        IMPORT_C TInt CanSetAutomated( const TDesC8& aURI, 
            TBool& aValue );


        /**
        * Checks if given content can be set as an automated content.
        * @param  aFileName: Full path to file
        * @param  aValue: ETrue if content can be set as automated.
        * @return System wide or DRM specific error code.
        * @since Series 60 2.6
        */
        IMPORT_C TInt CanSetAutomated( const TDesC& aFilename, 
            TBool& aValue );


        /**
        * Checks if given content can be set as an automated content.
        * @param  aFileHandle: file handle to the file
        * @param  aValue: ETrue if content can be set as automated.
        * @return System wide or DRM specific error code.
        * @since  3.0
        */
        IMPORT_C TInt CanSetAutomated( RFile& aFileHandle, 
            TBool& aValue );


        /**
        * Informs DRMHelper that idle-screen has been activated.
        * @return -
        * @since Series 60 2.6
        */
        IMPORT_C void IndicateIdle();

        /**
        * Handle the general UI based error notes 
        * @since  3.0
        * @param aTextId The code for DRM general notification note.
        * @param aURI The DRM files URI, that caused the DRM error.
        * @return KErrnone if everything went ok, else wide scale of Symbian errors
        */
        IMPORT_C TInt ShowDRMUINotification2L( TDRMHelperNotificationID aTextId,
            const TDesC8& aURI );


        /**
        * Handle the general UI based error notes 
        * @since  3.0
        * @param aTextId The code for DRM general notification note.
        * @param aFileName The DRM file's name and path, that caused the DRM error.
        * @return KErrnone if everything went ok, else wide scale of Symbian errors
        */
        IMPORT_C TInt ShowDRMUINotification2L( TDRMHelperNotificationID aTextId,
            const TDesC& aFileName );


        /**
        * Set count limit for CheckRightsAmountL
        * @param aCounts: new count limit for displaying the note.
        * @return -
        */
        IMPORT_C void SetCountLimitL( TUint aCounts );

        
        /**
        * Set time limit in days for CheckRightsAmountL
        * @param aDays: new time limit for displaying the note.
        * @return -
        */
        IMPORT_C void SetTimeLimitL( TUint aDays );


        /**
        * Set percentage limit for CheckRightsAmountL. Applies to both counts and time.
        * @param aPercentage: new limit for displaying the note.
        * @return -
        */
        IMPORT_C void SetPercentageLimitL( TUint aPercentage );


        /**
        * GetContentURIList
        *
        * Returns a list of all content URIs that have rights in the rights 
        * database.
        *
        * @since  2.5
        * @param  aURIList: Out parameter for the URI list.
        * @return Ok if the URI list could be retreived.
        */
        IMPORT_C TInt GetContentURIList(
            RPointerArray<HBufC8>*& aURIList);

    
        /**
        * DataTypesCount
        *
        * Returns the number of previously registered datatypes which are
        * supported by the DRM system and associated applications.
        *
        * @since  2.0
        * @param  aCount: Out parameter for the datatype count
        * @return EOk if the number of datatypes has been returned correctly
        */
        IMPORT_C TInt DataTypesCount(
            TInt& aCount);

    
        /**
        * SupportedDataType
        *
        * Returns a specific datatype which has been registered before by giving an index
        *
        * @since  2.0
        * @param  aIndex: Number of the datatype to return
        * @param  aDataType: Out parameter for the datatype
        * @return EOk if the datatype was returned correctly
        */
        IMPORT_C TInt SupportedDataType(
            const TInt aIndex, TDataType& aDataType);

    
        /**
        * RegisterDataType
        *
        * Registers a datatype as a supported datatype.
        *
        * @since  2.0
        * @param  aDataType: Datatype to register
        * @return EOk if the datatype has been registered
        */
        IMPORT_C TInt RegisterDataType(
            const TDataType& aDataType);

    
        /**
        * UnRegisterDataType
        *
        * Unregisters a datatype via its index.
        *
        * @since  2.5
        * @param  aIndex: Number of the datatype to unregister
        * @return EOk if the datatype has been unregistered
        */
        IMPORT_C TInt UnRegisterDataType(
            const TInt aIndex);


        /**
        * SupportedDRMMethods
        *
        * Returns the supported DRM protection methods and the OMA compliance
        * level of the DRM engine
        *
        * @since  2.0
        * @param  aDRMMethod: Out parameter, bit mask containing any 
        *         combination of EForwardLock, ECombinedDelivery, 
        *         ESeparateDelivery etc.
        * @param  aOMALevel: OMA compliance of the DRM engine
        * @return DRMCommon error code
        */
    
        IMPORT_C TInt SupportedDRMMethods2(
            TInt& aDRMMethod, TDRMHelperOMALevel& aOMALevel);

    
        /**
        * Consume2
        *
        * Overrides any rights consumption. This function must only be used by
        * applications with user interaction and not by intermediate components.
        * The main use cases are signalling that content is to be installed
        * (including thumbnail generation), or that content is to be consumed.
        * They are characterized as calls to this function with the correct
        * intent (i.e. EPlay or EInstall) and the corresponding action (i.e.
        * telling whether the indicated intent is started or finished).
        * Calls to this function must be the result of a user interaction or
        * otherwise high level event.
        *
        * @since  3.0
        * @param  aContentURI: URI of the content which will be consumed
        * @param  aRightsSpec: the consumption intent (EPlay, EDisplay, EPrint,
        *         EExecute or EInstall)
        * @param  anAction: the consumption action, telling whether the
        *         content consumption starts or finishes.
        * @return EOk if consume action was successfully signalled to the engine.
        */
        IMPORT_C TInt Consume2(
		    const TDesC8& aContentURI,
		    TUint32 aRightsSpec,
		    TDRMHelperConsumeAction anAction);


        /**
        * ConsumeFile2
        *
        * Overrides any rights consumption. This function must only be used by
        * applications with user interaction and not by intermediate components.
        * The main use cases are signalling that content is to be installed
        * (including thumbnail generation), or that content is to be consumed.
        * They are characterized as calls to this function with the correct
        * intent (i.e. EPlay or EInstall) and the corresponding action (i.e.
        * telling whether the indicated intent is started or finished).
        * Calls to this function must be the result of a user interaction or
        * otherwise high level event.
        *
        * @since  3.0
        * @param  
        * @param  aRightsSpec: the consumption intent (EPlay, EDisplay, EPrint,
        *         EExecute or EInstall)
        * @param  anAction: the consumption action, telling whether the
        *         content consumption starts or finishes.
        * @return EOk if consume action was successfully signalled to the engine.
        */
        IMPORT_C TInt ConsumeFile2(
		    const TDesC& aFileName,
		    TUint32 aRightsSpec,
		    TDRMHelperConsumeAction anAction);


        /**
        * ConsumeFile2
        *
        * Overrides any rights consumption. This function must only be used by
        * applications with user interaction and not by intermediate components.
        * The main use cases are signalling that content is to be installed
        * (including thumbnail generation), or that content is to be consumed.
        * They are characterized as calls to this function with the correct
        * intent (i.e. EPlay or EInstall) and the corresponding action (i.e.
        * telling whether the indicated intent is started or finished).
        * Calls to this function must be the result of a user interaction or
        * otherwise high level event.
        *
        * @since  3.0
        * @param  aFileHandle: file handle to the file
        * @param  aRightsSpec: the consumption intent (EPlay, EDisplay, EPrint,
        *         EExecute or EInstall)
        * @param  anAction: the consumption action, telling whether the
        *         content consumption starts or finishes.
        * @return EOk if consume action was successfully signalled to the engine.
        */
        IMPORT_C TInt ConsumeFile2(
		    RFile& aFileHandle, 
		    TUint32 aRightsSpec,
		    TDRMHelperConsumeAction anAction);

		/**
        * Acquires rights for given content if rights have been expired or rights are missing.
		* If content already has valid or future rights, does nothing.
		* This function should be called when user selects activate from options menu.
		* Leaves with system-wide error code in case of error.
        * @param aContent: Content object
        */
		IMPORT_C void ActivateContentL(CData& aContent);

		/**
        * Acquires rights for given content if rights have been expired or rights are missing.
		* If content already has valid or future rights, does nothing.
		* This function should be called when user selects activate from options menu.
		* Leaves with system-wide error code in case of error.
        * @param aFileName: Full path to file
        */
		IMPORT_C void ActivateContentL(TDesC& aFileName);

		/**
        * Checks if given content has embedded preview or if it is possible to get preview rights for it.
		* Leaves with system-wide error code in case of error.
        * @param aContent: Content object
		* @param aPreviewUri: Out: URI of the embedded preview or PreviewRights URL. Must be freed by caller
		* @return preview type
        */
		IMPORT_C TDRMHelperPreviewType HasPreviewL(CData& aContent, HBufC8*& aPreviewUri);

		/**
        * Checks if given content has embedded preview or if it is possible to get preview rights for it.
		* Leaves with system-wide error code in case of error.
        * @param aFileName: Full path to file.
		* @param aPreviewUri: Out: URI of the embedded preview or PreviewRights URL. Must be freed by caller
		* @return preview type
        */
		IMPORT_C TDRMHelperPreviewType HasPreviewL(TDesC& aFileName, HBufC8*& aPreviewUri);

		/**
        * Acquires preview rights for given content.
		* Leaves with system-wide error code in case of error.
        * @param aContent: Content object
        */
		IMPORT_C void GetPreviewRightsL(CData& aContent);

		/**
        * Acquires preview rights for given content.
		* Leaves with system-wide error code in case of error.
        * @param aFileName: Full path to file.
        */
		IMPORT_C void GetPreviewRightsL(TDesC& aFileName);

		/**
        * This method should be called after embedded preview has been played.
		* It asks from user if he/she wants to buy rights and acquires those if user agrees.
		* Leaves with system-wide error code in case of error.
        * @param aContent: Content object.
		* @return ETrue if user selects to buy rights.
        */
		IMPORT_C TBool EmbeddedPreviewCompletedL(CData& aContent);

		/**
        * This method should be called after embedded preview has been played.
		* It asks from user if he/she wants to buy rights and acquires those if user agrees.
		* Leaves with system-wide error code in case of error.
        * @param aFileName: Full path to file.
		* @return ETrue if user selects to buy rights.
        */
		IMPORT_C TBool EmbeddedPreviewCompletedL(TDesC& aFileName);

		/**
        * Checks if given content has InfoUrl.
		* Leaves with system-wide error code in case of error.
        * @param aContent: Content object.
		* @param aInfoUrl: Out: InfoUrl. Must be freed by caller.
		* @return ETrue if content has InfoUrl.
        */
		IMPORT_C TBool HasInfoUrlL(CData& aContent, HBufC8*& aInfoUrl);

		/**
        * Checks if given content has InfoUrl.
		* Leaves with system-wide error code in case of error.
        * @param aFileName: Full path to file.
		* @param aInfoUrl: Out: InfoUrl. Must be freed by caller.
		* @return ETrue if content has InfoUrl.
        */
		IMPORT_C TBool HasInfoUrlL(TDesC& aFileName, HBufC8*& aInfoUrl);

		/**
        * Opens browser with InfoUrl of the content.
		* Leaves with system-wide error code in case of error.
        * @param aContent: Content object.
        */
		IMPORT_C void OpenInfoUrlL(CData& aContent);

		/**
        * Opens browser with InfoUrl of the content.
		* Leaves with system-wide error code in case of error.
        * @param aFileName: Full path to file.
        */
		IMPORT_C void OpenInfoUrlL(TDesC& aFileName);

        /**
        * Sets the type of automated content to be registered. This method 
        * should be called before calling any of SetAutomated* methods.
        * @param  aAutomatedType: type of automated content
        * @return System wide error code
        * @since Series 60 3.0
        */
        IMPORT_C TInt SetAutomatedType( TDRMHelperAutomatedType aAutomatedType );
        
        /**
        * Sets media type of content for preview. Should be called prior to 
        * calling HandleErrorOrPreviewL or EmbeddedPreviewCompletedL. 
        * @param aMediaType: media type of content.
        * @return System wide error code
        * @since S60 3.1u
        */
        IMPORT_C TInt SetPreviewMediaType( 
            TDRMHelperPreviewMediaType aMediaType );

    protected:  // New functions
        
        /**
        * ?member_description.
        * @since ?Series60_version
        * @param ?arg1 ?description
        * @return ?description
        */
        //?type ?member_function( ?type ?arg1 );

    protected:  // Functions from base classes
        
        /**
        * From ?base_class ?member_description
        */
        //?type ?member_function();


    private:

        /**
        * C++ default constructor.
        */
        CDRMHelper( CCoeEnv& aCoeEnv );
        CDRMHelper();

        /**
        * By default Symbian 2nd phase constructor is private.
        */
        void ConstructL( RFs* aFs );

        // Prohibit copy constructor if not deriving from CBase.
        // ?classname( const ?classname& );
        // Prohibit assigment operator if not deriving from CBase.
        // ?classname& operator=( const ?classname& );

        /**
        * Display query dialog
        */
        TInt DisplayQueryWithIdL( TInt aTextResourceId, TInt aQueryResourceId );
        TInt DisplayQueryWithIdValueL( TInt aTextResourceId, TInt aQueryResourceId, 
                                       const TDesC& aString );
        TInt DisplayQueryL( TInt aTextResourceId, TInt aValue );
        TInt DisplayQueryL( TInt aTextResourceId, const TDesC& aString );
        TInt DisplayQueryL( 
        	TInt aTextResourceId, 
        	const TDesC& aString, 
            TInt aValue,
        	TInt aStringPos = -1,
        	TInt aValuePos = -1 );
        TInt DisplayQueryL( TDesC& aPromptText, TInt aQueryResourceId );

        /**
        * Display information note
        */
        void DisplayInfoNoteL( TInt aTextResourceId );
        void DisplayInfoNoteL( TInt aTextResourceId, const TDesC& aString );
        void DisplayInfoNoteL( TInt aTextResourceId, TInt aValue );
        void DisplayInfoNoteL( TDesC& aPromptText, TInt aResourceId, 
                               const TDesC& aString = KNullDesC, TInt aValue = -1 );

        /**
        * Launch browser embedded
        */
        void LaunchBrowserL( HBufC8* aUrl );
        void LaunchBrowserL( HBufC* aUrl );

        /**
        * Get rights-issuer URI from DCF file
        */
        void GetRightsIssuerL( const CData& aContent, HBufC*& aIssuer );

        /**
        * Get time and count based constraints
        */
        TInt GetCounts( CDRMRightsConstraints* aConstraint, 
            TUint32& aOriginalCount, TTimeIntervalDays& aDuration );

        TInt GetCounts( CDRMRightsConstraints* aConstraint,
            TUint32& aCountLeft, TTime& aEndTime );
            
        TInt GetCounts( CDRMConstraint* aConstraint, 
            TUint32& aOriginalCount, TTimeIntervalDays& aDuration );

        TInt GetCounts( CDRMConstraint* aConstraint,
            TUint32& aCountLeft, TTime& aEndTime );

        /**
        * Launch rights manager UI
        */
        void LaunchRightsManagerUiL( const TDesC& aParam16 );

        /**
        * Form string needed to launch rights manager UI embedded.
        */
        void CreateLaunchParamL( TUint32 aLocalId, const HBufC8* aUrl, 
            HBufC*& aLaunchParam );

        /**
        * Strip path and extension from given filename.
        * Caller is responsible for freeing returned buffer
        */
        TPtrC StripPathAndExtension( const TDesC& aFileName );

        /**
        * Get expiration details of file.
        * Returns DRMCommon::ENoRights if no rights object found or
        * CDRMRights::TExpiration value
        */
        TInt GetExpirationDetails( HBufC8* aContentUri, TInt aIntent, 
                                   CDRMRights*& aRightsObject );

        /**
        * Get expiration time of given rights object
        */
        TInt CalculateEndTime( CDRMRights* aRights, TInt aIntent, 
            TTime& aEndTime, TBool& aInactive );

        /**
        * Get end time of given constraint
        */
        TInt GetEndTime( CDRMRightsConstraints* aConstraint, 
            TTime& aEndTime, TBool& aInactive );
        
        /**
        * Register content as automated
        */
        TInt PerformSetAutomatedL( const CData& aContent, TBool aActive );
        TInt DoSetAutomatedL( const TDesC8& aURI, TBool aActive, 
            const HBufC* aMimeType );

        /**
        * Display confirmation query about setting as automated. Does not 
        * actually register.
        */
        TInt PerformShowAutomatedNoteL( const CData& aContent );
        TInt DoShowAutomatedNoteL( const TDesC8& aURI, 
            const HBufC* aMimeType );

        /**
        * Register content as automated without showing any queries
        */
        TInt PerformSetAutomatedSilentL( const CData& aContent, TBool aActive );
        TInt DoSetAutomatedSilent( const TDesC8& aURI, TBool aActive, TInt aIntent );

        /**
        * Returns default intent for the mimetype
        */
        TInt Intent( const HBufC* aMimeType );
        
        /**
        * Checks if content can be used as automated content
        */
        TInt PerformCanSetAutomatedL( const CData& aContent,TBool& aValue );
        TInt DoCanSetAutomated( const TDesC8& aURI, const HBufC* aMimeType, 
            TBool& aValue );
        TBool DoCheckSkinCanSetAutomated(CDRMRights* aRights);
            
        /**
        * Gets mimetype based on content URI
        */
        HBufC* MimeTypeFromURIL( const TDesC8& aURI );
        
        /**
        * Gets corresponding filename (including full path) based on content 
        * URI
        */
        TInt GetFileHandleFromURIL( const TDesC8& aURI, RFile& aFileHandle );

        /**
        * Get start time of given rights object
        */
        TInt GetStartTime( CDRMRights* aRights, TInt aIntent, 
            TTime& aStartTime );

        /**
        * Displays info note of rights that are not yet valid 
        */
        TInt ShowFutureNoteL( const HBufC* aMimeType, CDRMRights* aRightsObject );

        /**
        * Handles error by displaying appropriate note to user.
        */
        TInt DoHandleErrorL( TInt aError, HBufC8* aContentUri, HBufC* aMimeType, 
            HBufC* aRIUrl, HBufC* aDomainRoUrl, HBufC* aEta, HBufC8* aRiId8,
            HBufC8* aDomainId8, const TDesC& aFileName );
            
        /**
        * Checks if rights are about to expire.
        */
        TInt DoCheckRightsPercentL( HBufC8* aContentUri, HBufC* aMimeType, 
            HBufC* aRIUrl, const TDesC& aFileName, TInt aThreshold );

        TInt DoCheckRightsAmountL( HBufC8* aContentUri, HBufC* aMimeType, 
            HBufC* aRIUrl, const TDesC& aFileName, TInt aCount, TInt aDays );
            
        /**
        * Gets rights details.
        */
        void DoGetRightsDetailsL( HBufC8* aContentUri, TUint32 aIntent,
            TBool& aExpired, CDRMHelperRightsConstraints*& aPlay,
            CDRMHelperRightsConstraints*& aDisplay, 
            CDRMHelperRightsConstraints*& aExecute,
            CDRMHelperRightsConstraints*& aPrint );

        void DoGetRightsDetailsL( CData* aContent, TUint32 aIntent,
            TBool& aExpired, TBool& aSendingAllowed, CDRMRightsConstraints*& aPlay,
            CDRMRightsConstraints*& aDisplay, 
            CDRMRightsConstraints*& aExecute,
            CDRMRightsConstraints*& aPrint );
		
        /**
        * Get constraints for given rights
        */
        void GetConstraintsL( 
            CDRMRights& aRights, 
            CDRMHelperRightsConstraints*& aPlay,
            CDRMHelperRightsConstraints*& aDisplay,
            CDRMHelperRightsConstraints*& aExecute,
            CDRMHelperRightsConstraints*& aPrint );

		/**
		* Unregisters automated content.
		*/
		TInt PerformRemoveAutomatedL( const CData& aContent, TBool aActive );
		
		void HandleServerAppExit(TInt aReason);

        void CheckPreviewUriL( 
            const CData* aContent, 
            HBufC*& aEmbeddedPreviewUri, 
            TInt& aPreviewType );
        
        TInt DisplayPopupWindowsForPreviewL(TInt aPreviewType);

        /**
		* Returns correct resource id for automated content notes.
		* If aExpired is ETrue, aSecondParameter indicates if RI URL exists
		* If aExpired is EFalse, aSecondParameter indicates if there is one day left
        * aRejectReason tells the constraints which are invalid.
		*/
		TInt AutomatedResIdL( TBool aExpired, TBool aSecondParameter, TUint32 aRejectReason );

        /** 
        * Returns the correct resource id for expired and no rights notes
        */		    
        TInt ErrorResIdL( const TDesC8& aContentUri, TInt aIntent, 
            TBool aRightsIssuer, TBool aExpired );

        /** 
        * Returns the constraints which are invalid
        */		    
        TUint32 RejectReasonL( TInt aIntent, const TDesC8& aContentUri );
        
        /** 
        * Prepares secondary display for DRM notes
        */
        void PrepareSecondaryDisplayL( CEikDialog& aDialog, TInt aResourceId,
                                       const TDesC& aString = KNullDesC, TInt aValue = -1 ); 

        /** 
        * Cancels secondary display for DRM notes
        */
        void CancelSecondaryDisplayL( TInt aResourceId );
                
        /** 
        * Check whether a file as a silent rights URL which can be used, i.e the URL is valid
        * and on the white list.
        */
        HBufC8* HasSilentRightsUrlL( CData* aContent );
        
        /** 
        * Get rights silently
        */
        TInt GetSilentRightsL( const TDesC8& aUrl );

        /** 
        * Check if the user has allowed silent rights
        */
        TBool SilentRightsAllowedL();

        /** 
        * Check if browser AP has been defined
        */
        TBool BrowserAPDefinedL();

    protected:  // Data
        // ?one_line_short_description_of_data
        //?data_declaration;

    private:    // Data
        CCoeEnv*                iCoeEnv;

        // DRM engine
        DRMCommon*              iDRMCommon;

        // used to make launching rights manager ui synchronous
        CActiveSchedulerWait    iWait;
   
        RDRMHelper              iHelperServer;
        
        // is CoeEnv used
        TBool                   iUseCoeEnv;

        // Used to read resources when CoeEnv is not available
        CStringResourceReader*  iStringResourceReader;
        
        TBool                   iOma2;
        	
        RPointerArray<CConsumeData> iConsumeList;
        
        TInt                    iAutomatedType;
   
        RFs                     iFs;
        
        TBool                   iFsOwned;
        
        TInt                    iPreviewMediaType;
        
        // Used to queue up global notes
        RPointerArray<CDRMHelperInfoNoteWrapper>      iNoteList;
        
        CSchemeHandler*         iSchemeHandler;

        TBool                   iReturnCancel;

        // Used to send cancel events to cover ui
        CMediatorEventProvider* iEventProvider;

    public:     // Friend classes
    protected:  // Friend classes
    private:    // Friend classes

    };

#endif      // __DRMHELPER_H__   
            
// End of File

