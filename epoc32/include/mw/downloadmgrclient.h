/*
* Copyright (c) 2002-2004 Nokia Corporation and/or its subsidiary(-ies).
* All rights reserved.
* This component and the accompanying materials are made available
* under the terms of the License "Eclipse Public License v1.0"
* which accompanies this distribution, and is available
* at the URL "http://www.eclipse.org/legal/epl-v10.html".
*
* Initial Contributors:
* Nokia Corporation - initial contribution.
*
* Contributors:
*
* Description:  This file contains the definition of the Client interface of Download Mgr Server.
*
*/


#ifndef __DOWNLOADMGR_CLIENT_H__
#define __DOWNLOADMGR_CLIENT_H__

//  INCLUDES
#include <e32base.h>
#include <f32file.h>
#include <HttpDownloadMgrCommon.h>
#include <http.h>

// FORWARD DECLARATIONS
class CDownloadMgrHandler;
class RHttpDownload;
class MHttpDownloadMgrObserver;
class CDefaultAttrib;
class CRHttpDownloadExtension;
class CRHttpDownloadMgrExtension;
class CRHttpDlExtension;
class CEikonEnv;
class CTransactionObserver;
class THttpTransactionCallback;
class CCodDownload;
class CCodObserver;

/**
* Calculate a hash and in the form of a 32 character hex result.
* @param aMessage Source.
* @param aHash Hash value.
* @return None.        
*/
void HashL( const TDesC8& aMessage, TDes8& aHash );

// TYPEDEFS
typedef CArrayPtrFlat< RHttpDownload > CDownloadArray;
typedef CArrayPtrFlat< MHttpDownloadMgrObserver >  CDownloadMgrObserver;

// CLASS DECLARATION

/**
*  Contains download states
*
*  @lib -
*  @since Series 60 2.8
*/
NONSHARABLE_CLASS( THttpDownloadEvent )
    {
    public: // Data
        // download state
        THttpDownloadState iDownloadState;
        // download progress state
        THttpProgressState iProgressState;
    };

/**
*  Provides the interface for notification of events from a Download Manager 
*  session and its subsessions.
*
*  @lib -
*  @since Series 60 2.8
*/
class MHttpDownloadMgrObserver
    {

    public:

        /**
        * Indicates an event.
        * @param aDownload The download with which the event occured.
        * @param aEvent Event type.
        * @return None.
        */
        virtual void HandleDMgrEventL( RHttpDownload& aDownload, THttpDownloadEvent aEvent ) = 0;
    };

/**
*  Provides the interface for sending next uri to 
*  the client when downloading OMA or COD.
*
*  @lib -
*  @since Series 60 3.0
*/
class MHttpDownloadMgrNextUriObserver
    {

    public:

        /**
        * Send next uri to the client. The client can then handle it.
        * @param aDownload Reference to the download.
        * @param aUri Next URI of the OMA or COD download.
        * @return None.
        */
        virtual void NextUriL( RHttpDownload& aDownload, const TDesC8& aUri ) = 0;
    };

/**
*  Creates a download manager session and performs operations on it 
*
*  @lib -
*  @since Series 60 2.8
*/
NONSHARABLE_CLASS( RHttpDownloadMgr ) : public RSessionBase,
                                        public MHttpDownloadMgrObserver
	{
    public:
        /**
        * C++ default constructor.
        */
        IMPORT_C RHttpDownloadMgr();

    public:  // New functions

        /**
        * Creates a download manager session.
        * @param aAppUid Client application's UID.
        * @param aObserver Observer
        * @param aMaster Indicates whether (if ETrue) this instance 
        * inherints all downloads of other instances. (stand-alone app flag).
        * @return None.
        */
        IMPORT_C void ConnectL( TUid aAppUid,
                                MHttpDownloadMgrObserver& aObserver,
                                TBool aMaster );

        /**
        * Gives version information.
        * @param -
        * @return TVersion Contains version information.
        */
        IMPORT_C TVersion Version() const;

        /**
        * Closes download manager session.
        * @param -
        * @return None.
        */
        IMPORT_C void Close();

        /**
        * Returns a list of the current downloads.
        * @param -
        * @return CDownloadArray
        */
        IMPORT_C const CDownloadArray& CurrentDownloads() const;

        /**
        * Creates a new download subsession.
        * @param aUrl The url to be downloaded.
        * @param aResult The result is true if the download is created.
        * If the URL is already being downloaded the seult is false.
        * @return RHttpDownload&
        */
        IMPORT_C RHttpDownload& CreateDownloadL( const TDesC8& aUrl, TBool& aResult );

        /**
        * Creates a new download subsession. It creates a new one even
        * if the URL is already beeing downloaded.
        * @param aUrl The url to be downloaded.
        * If the URL is already being downloaded the seult is false.
        * @return RHttpDownload&
        */
        IMPORT_C RHttpDownload& CreateDownloadL( const TDesC8& aUrl );

        /**
        * Creates a new download in client side.
        * @param aHttpTransaction http transaction.
        * @param aResult The result is true if the download is created.
        * If the URL is already being downloaded the seult is false.        
        */
        IMPORT_C RHttpDownload& CreateClientSideDownloadL( TInt aHttpTransaction,TBool& aResult );

        /**
        * Creates a new download subsession for COD.
        * @param aUrl The url from the COD is downloaded.
        * @param aBuf The COD descriptor.
        * @param aMimeType The mimetype.
        * @param aEikEnv Eikon environment or NULL. Can be NULL if download
        * does not require UI functionality.        
        * @param aResult The result is true if the download is created.       
        * If the URL is already being downloaded the seult is false.
        * @return RHttpDownload&
        */
        IMPORT_C RHttpDownload& CreateCodDownloadL( const TDesC8& aUrl,
                                                    const TDesC8& aBuf,
                                                    const TDesC8& aMimeType,
                                                    CEikonEnv* aEikEnv,
                                                    TBool& aResult );

        /**
        * Finds if the download is already created
        * @since 2.8
        * @param aUrl given URL
        * @param aMsgBody Message body from post operation
        * @return Returns a pointer to the found download or null.
        *         This pointer is NOT owned by the client!
        */        
        IMPORT_C RHttpDownload* FindDownload( const TDesC8& aUrl, const TDesC8& aMsgBody );

        /**
        * Pauses all downloads.
        * @param -
        * @return None.
        */
        IMPORT_C TInt PauseAll();

        /**
        * Resumes all downloads.
        * @param -
        * @return None.
        */
        IMPORT_C TInt StartAll();

        /**
        * Resets all downloads.
        * @param -
        * @return None.
        */
        IMPORT_C TInt ResetAll();

        /**
        * Deletes all downloads.
        * @param -
        * @return None.
        */
        IMPORT_C TInt DeleteAll();

        /**
        * Disconnect the http connection and pauses all downloads.
        * @param -
        * @return None.
        */
        IMPORT_C TInt Disconnect();

		/**
		* Gets the value for a TInt attribute.
		* @param aAttribute Identifies the attribute to be retrived.
		* @param aValue On completion, contains the requested TInt attribute.
        * @return None.
		*/
		IMPORT_C TInt GetIntAttribute( const TUint aAttribute, TInt32& aValue );

		/**
		* Gets the value for a TBool attribute.
		* @param aAttribute Identifies the attribute to be retrived.
		* @param aValue On completion, contains the requested TBool attribute.
        * @return None.
		*/
		IMPORT_C TInt GetBoolAttribute( const TUint aAttribute, TBool& aValue );

		/**
		* Gets the value for a TDes16 attribute.
		* @param aAttribute Identifies the attribute to be retrived.
		* @param aValue On completion, contains the requested TDes16 attribute.
        * @return None.
		*/
		IMPORT_C TInt GetStringAttribute( const TUint aAttribute, TDes16& aValue  );

		/**
		* Gets the value for a TDes8 attribute.
		* @param aAttribute Identifies the attribute to be retrived.
		* @param aValue On completion, contains the requested TDes8 attribute.
        * @return None.
		*/
        IMPORT_C TInt GetStringAttribute( const TUint aAttribute, TDes8& aValue  );

		/**
		* Sets the value for a TInt attribute.
		* @param aAttribute Identifies the attribute to be set.
		* @param aValue The value to be set.
        * @return None.
		*/
		IMPORT_C TInt SetIntAttribute( const TUint aAttribute, TInt32 aValue );

		/**
		* Sets the value for a TBool attribute.
		* @param aAttribute Identifies the attribute to be set.
		* @param aValue The value to be set.
        * @return None.
		*/
		IMPORT_C TInt SetBoolAttribute( const TUint aAttribute, TBool aValue );

		/**
		* Sets the value for a TDesC attribute.
		* @param aAttribute Identifies the attribute to be set.
		* @param aValue The value to be set.
        * @return None.
		*/
		IMPORT_C TInt SetStringAttribute( const TUint aAttribute, const TDesC16& aValue );

		/**
		* Sets the value for a TDesC8 attribute.
		* @param aAttribute Identifies the attribute to be set.
		* @param aValue The value to be set.
        * @return None.
		*/
        IMPORT_C TInt SetStringAttribute( const TUint aAttribute, const TDesC8& aValue );

		/**
		* Sets the value for the default TInt attribute.
		* @param aAttribute Identifies the attribute to be set.
		* @param aValue The value to be set.
        * @return None.
		*/
		IMPORT_C TInt SetDefaultIntAttribute( const TUint aAttribute, TInt32 aValue );

		/**
		* Sets the value for the default TBool attribute.
		* @param aAttribute Identifies the attribute to be set.
		* @param aValue The value to be set.
        * @return None.
		*/
		IMPORT_C TInt SetDefaultBoolAttribute( const TUint aAttribute, TBool aValue );

		/**
		* Sets the value for the default TDesC attribute.
		* @param aAttribute Identifies the attribute to be set.
		* @param aValue The value to be set.
        * @return None.
		*/
		IMPORT_C TInt SetDefaultStringAttribute( const TUint aAttribute, const TDesC16& aValue );

		/**
		* Sets the value for the default TDesC8 attribute.
		* @param aAttribute Identifies the attribute to be set.
		* @param aValue The value to be set.
        * @return None.
		*/
        IMPORT_C TInt SetDefaultStringAttribute( const TUint aAttribute, const TDesC8& aValue );

		/**
		* Adds client to the observer list.
		* @param aObserver Observer.
        * @return None.
		*/
        IMPORT_C void AddObserverL( MHttpDownloadMgrObserver& aObserver );

		/**
		* Removes client from the observer list.
		* @param aObserver Observer.
        * @return None.
		*/
        IMPORT_C void RemoveObserver( MHttpDownloadMgrObserver& aObserver );
        
		/**
		* Set next uri observer.
		* @param aObserver Observer.
        * @return None.
		*/        
        IMPORT_C void SetNextUriObserver( MHttpDownloadMgrNextUriObserver* aObserver );

    protected: // from MHttpDownloadMgrObserver

        /**
        * Indicates an event.
        * @param aDownload The download with which the event occured.
        * @param aEvent Event type.
        * @return None.
        */
        void HandleDMgrEventL( RHttpDownload& aDownload, THttpDownloadEvent aEvent );

    private:

        /**
        * Indicates the session's event.
        * @param aHandle Unique identifier of server side subsession.
        * @param aEvent Event type.
        * @return None.
        */
        void HandleSessionEventL( TInt aHandle, THttpDownloadEvent aEvent );

    private:  // New functions

        /**
        * Creates a download manager session.
        * @param aAppUid Client application's UID.
        * @param aObserver Observer
        * @param aMaster Indicates whether (if ETrue) this instance 
        * inherints all downloads of other instances. (stand-alone app flag).
        * @return None.
        */
        void DoConnectL( TUid aAppUid,
                         MHttpDownloadMgrObserver& aObserver,
                         TBool aMaster );

        /**
        * Initializes the download manager session.
        * @param aAppUid Client app's UID.
        * @param aObserver Observer to add to the observer list.
        * @param aMaster Indicates whether (if ETrue) this instance 
        * inherints all downloads of other instances. (stand-alone app flag).
        * @return None.
        */
        void InitializeL( TUid aAppUid,
                          MHttpDownloadMgrObserver& aObserver,
                          TBool aMaster );

    protected: // New functions

        /**
        * Adds the created download to the list. If it is already added, 
        * then it will do nothing.
        * @param aElement Download subsession.
        * @return RHttpDownload& reference to the added item in the list.
        */
        RHttpDownload& AddToArrayL( RHttpDownload* aElement );

    private:  // New functions

        /**
        * Removes the download from the list.
        * @param aElement Download subsession.
        * @return None.
        */
        void RemoveFromArray( RHttpDownload* aElement );

        /**
        * Finds the download in the list.
        * @param aElement Download subsession.
        * @param aIndex Index of the element found.
        * @return KErrNone if found, KErrNotFound otherwise..
        */
        TInt FindInArray( RHttpDownload* aElement, TInt& aIndex ) const;

        /**
        * Returns a reference to the download identified by a handle.
        * @param aHandle Handle identifier.
        * @return RHttpDownload&
        */
        RHttpDownload& DownloadFromHandleL( TUint aHandle );

        /**
        * Finds observer based on index.
        * @param aObserver Observer found.
        * @param aIndex Index.
        * @return TInt
        */
        TInt FindObserver( MHttpDownloadMgrObserver& aObserver, TInt& aIndex ) const;

        /**
        * Attach client to the session.
        * @param aBuf Buffer to the subsession IDs.
        * @return None.
        */
        void AttachL( TDes8& aBuf );

        /**
        * Close a download subsession.
        * @param aElement Download subsession.
        * @return None.
        */
        void CloseDownload( RHttpDownload* aElement );

		/**
		* Packes the default values of the attributes.
		* @param -
        * @return bbuffer of the packed attribs.
		*/
        HBufC8* PackedDefaultAttributesLC();

		/**
		* Sets the default value for the TInt32 attribute.
		* @param aAttribute Identifies the attribute to be set.
		* @param aValue The value to be set.
        * @return None.
		*/
        void DoSetDefaultAttributeL( const TUint aAttribute, TInt32 aValue );

		/**
		* Sets the default value for the TBool attribute.
		* @param aAttribute Identifies the attribute to be set.
		* @param aValue The value to be set.
        * @return None.
		*/
        void DoSetDefaultAttributeL( const TUint aAttribute, TBool aValue );

		/**
		* Sets the default value for the TDesC8 attribute.
		* @param aAttribute Identifies the attribute to be set.
		* @param aValue The value to be set.
        * @return None.
		*/
        void DoSetDefaultAttributeL( const TUint aAttribute, const TDesC8& aValue );

		/**
		* Sets the default value for the TDesC16 attribute.
		* @param aAttribute Identifies the attribute to be set.
		* @param aValue The value to be set.
        * @return None.
		*/
        void DoSetDefaultAttributeL( const TUint aAttribute, const TDesC16& aValue );

        /**
        * Start session's event notification.
        * @param aStatus Handler's request status.
        * @return None.
        */
        void StartSessionEventNotification( const TDesC8& aDownloadState,
                                            const TDesC8& aProgressState,
                                            const TDesC8& aHandle,
                                            TRequestStatus& aStatus );

        /**
        * Cancels session's event notification.
        * @param -
        * @return None.
        */
        void CancelSessionEventNotification();
        
        /**
        * Leave version of FindDownload
        */
        RHttpDownload* DoFindDownloadL( const TDesC8& aUrl, const TDesC8& aMsgBody );
        
        /**
        * Gets the number of client side download.
        * @param aValue Num of client side download
        * @return Error code.
        */        
        TInt NumberOfClientSideDownload( TInt32& aValue );
        
        /**
        * Tells that event is being broadcasted.
        * @param None
        * @return TBool.
        */         
        TBool IsEventBroadcasting();
        
        /**
        * Do-Indicates the session's event.
        * @param aHandle Unique identifier of server side subsession.
        * @param aEvent Event type.
        * @return None.
        */
        void DoHandleSessionEventL( TInt aHandle, THttpDownloadEvent aEvent );

        /**
        * Broadcasts an event.
        * @param aDownload The download with which the event occured.
        * @param aEvent Event type.
        * @return None.
        */
        void BroadcastEvent( RHttpDownload& aDownload, 
                             THttpDownloadEvent aEvent );

        /**
        * Returns the next uri observer from the extension calss.
        * @return Next uri observer.
        */                             
        MHttpDownloadMgrNextUriObserver* NextUriObserver() const;
        
        /**
        * Returns the session id
        * @return session id
        */
        TInt SessionId() const;

        /**
        * Broadcast deleting event.
        * @param aDownload download is beenig deleted.
        * @return None.
        */        
//        void BroadcastDeleting( RHttpDownload& aDownload );
        
        /**
        * Returns the the event priority flag
        * @return TInt
        */        
        TInt EventPriorityFlag() const;
        
        /**
        * Increments the event priority flas
        * @return void
        */        
        void IncrementEventPriorityFlag();
        
        /**
        * Decrements the event priority flag
        * @return void
        */        
        void DecrementEventPriorityFlag();        
                             
    private:     // Data
        // The client application UID.
        TUid                             iAppUid;
        // List of downloads.
        CDownloadArray*                  iDownloadArray;  ///< Owned.
        // List of observers.
        CDownloadMgrObserver*            iObservers;      ///< Owned.
        // Default attributes.
        CArrayPtrFlat< CDefaultAttrib >* iDefaultAttribs; ///< Owned.
        // Moved event handler
        CDownloadMgrHandler*             iManagerHandler; ///< Owned.
        // Extension class
        CRHttpDownloadMgrExtension*      iExtension;      ///< Owned.

    public:     // Friend classes

        friend class RHttpDownload;
        friend class CDownloadMgrHandler;
        friend class CTransactionObserver;
        friend class CCodObserver;        
	};

/**
*  Creates a download manager subsession and performs operations on it 
*
*  @lib -
*  @since Series 60 2.8
*/
NONSHARABLE_CLASS( RHttpDownload ): public RSubSessionBase
	{
    public:
        /**
        * Cod download progress states
        */
        enum TCodProgressState
            {
            ENotActive,
            EPaused,
            EInProgress
            };
    private:

        /**
        * C++ default constructor.
        */
        RHttpDownload( RHttpDownloadMgr* aServer );

    public:  // New functions

        /**
        * Starts downloading.
        * @param -
        * @return None.
        */
        IMPORT_C TInt Start();

        /**
        * Pauses downloading.
        * @param -
        * @return None.
        */
        IMPORT_C TInt Pause();

        /**
        * Resets downloading.
        * @param -
        * @return None.
        */
        IMPORT_C TInt Reset();

        /**
        * Deletes downloading.
        * @param -
        * @return None.
        */
        IMPORT_C TInt Delete();

        /**
        * Moves downloaded content to the previously specified location
        * @param -
        * @return None.
        */
        IMPORT_C TInt Move();

		/**
		* Gets the value for a TInt attribute.
		* @param aAttribute Identifies the attribute to be retrived.
		* @param aValue On completion, contains the requested TInt attribute.
        * @return None.
		*/
		IMPORT_C TInt GetIntAttribute( const TUint aAttribute, TInt32& aValue );

		/**
		* Gets the value for a TBool attribute.
		* @param aAttribute Identifies the attribute to be retrived.
		* @param aValue On completion, contains the requested TBool attribute.
        * @return None.
		*/
		IMPORT_C TInt GetBoolAttribute( const TUint aAttribute, TBool& aValue );

		/**
		* Gets the value for a TDes16 attribute.
		* @param aAttribute Identifies the attribute to be retrived.
		* @param aValue On completion, contains the requested TDes16 attribute.
        * @return None.
		*/
		IMPORT_C TInt GetStringAttribute( const TUint aAttribute, TDes16& aValue  );

		/**
		* Gets the value for a TDes8 attribute.
		* @param aAttribute Identifies the attribute to be retrived.
		* @param aValue On completion, contains the requested TDes8 attribute.
        * @return None.
		*/
        IMPORT_C TInt GetStringAttribute( const TUint aAttribute, TDes8& aValue  );

        /**
        * Gets the download's destination file's handle.
        * @param aFile RFile that adopts file handle from download.
        */
        IMPORT_C TInt GetFileHandleAttribute( RFile& aFile );
        
		/**
		* Sets the value for a TInt attribute.
		* @param aAttribute Identifies the attribute to be set.
		* @param aValue The value to be set.
        * @return None.
		*/
		IMPORT_C TInt SetIntAttribute( const TUint aAttribute, TInt32 aValue );

		/**
		* Sets the value for a TDesC attribute.
		* @param aAttribute Identifies the attribute to be set.
		* @param aValue The value to be set.
        * @return None.
		*/
		IMPORT_C TInt SetBoolAttribute( const TUint aAttribute, TBool aValue );

		/**
		* Sets the value for a TDesC attribute.
		* @param aAttribute Identifies the attribute to be set.
		* @param aValue The value to be set.
        * @return None.
		*/
		IMPORT_C TInt SetStringAttribute( const TUint aAttribute, const TDesC16& aValue );

		/**
		* Sets the value for a TDesC8 attribute.
		* @param aAttribute Identifies the attribute to be set.
		* @param aValue The value to be set.
        * @return None.
		*/
        IMPORT_C TInt SetStringAttribute( const TUint aAttribute, const TDesC8& aValue );

        /**
        * Sets the download's destination file handle.
        * @param aFile RFile to be transfered to server.
        * @return KErrNotSupported on non-support platform.
        * @return KErrBadHandle is file is not opened.
        */
        IMPORT_C TInt SetFileHandleAttribute( RFile& aFile );
		/**
		* Gets the value for a TInt attribute.
		* @param aAttribute Identifies the attribute to be retrived.
		* @param aMoIndex Identifies the media object index.
		* @param aValue On completion, contains the requested TInt attribute.
        * @return None.
		*/
		IMPORT_C TInt GetIntAttribute( const TUint aAttribute, const TInt32& aMoIndex, TInt32& aValue );
		
		/**
		* Gets the value for a TBool attribute.
		* @param aAttribute Identifies the attribute to be retrived.
		* @param aMoIndex Identifies the media object index.
		* @param aValue On completion, contains the requested TBool attribute.
        * @return None.
		*/
		IMPORT_C TInt GetBoolAttribute( const TUint aAttribute, const TInt32& aMoIndex, TBool& aValue );
		
		/**
		* Gets the value for a TDes16 attribute.
		* @param aAttribute Identifies the attribute to be retrived.
		* @param aMoIndex Identifies the media object index.
		* @param aValue On completion, contains the requested TDes16 attribute.
        * @return None.
		*/
		IMPORT_C TInt GetStringAttribute( const TUint aAttribute, const TInt32& aMoIndex, TDes16& aValue );
        
        /**
		* Gets the value for a TDes8 attribute.
		* @param aAttribute Identifies the attribute to be retrived.
		* @param aMoIndex Identifies the media object index.
		* @param aValue On completion, contains the requested TDes8 attribute.
        * @return None.
		*/
        IMPORT_C TInt GetStringAttribute( const TUint aAttribute, const TInt32& aMoIndex, TDes8& aValue );
		
		/**
		* Sets the value for a TDesC attribute.
		* @param aAttribute Identifies the attribute to be set.
		* @param aMoIndex Identifies the media object index.
		* @param aValue The value to be set.
        * @return None.
		*/
		IMPORT_C TInt SetStringAttribute(const TUint aAttribute, const TInt32& aMoIndex, const TDesC16& aValue );
        
        /**
        * Sets the download data (media information).
        * @param sizeBytes The length of descriptor (second parameter) in bytes.
		* @param aValue The value to be set.
        * @return None.
        */
        IMPORT_C TInt SetDownloadDataAttribute( const TDesC8& aValue );
        
        /**
        * Sets the download data (media information).
        * @param sizeBytes The length of descriptor (second parameter) in bytes.
		* @param aValue The value to be set.
        * @return None.
        */
        IMPORT_C TInt SetTrackDataAttribute( const TInt aIndex, const TDesC8& aValue );

    public: // New functions

        /**
        * Closes download subsession.
        * @param -
        * @return None.
        */
        void Close();
        

        /**
        * Indicates whether the download is closed.
        * @param - None
        * @return TBool - ETrue if download is closed else EFalse.
        */        
        TBool IsClosed()
        {
            return iClosed;
        }
        
        /**
        * Resume COD download.
        * @param -
        * @return None.
        */
		void ResumeCodDownloadL()  ;
		
		/**
        * Get Downloaded Size of product.
        * @param -
        * @return TInt.
        */
		TInt GetProductDownloadedSize();        
        
     private: // New functions
     
        /**
        * Closes download subsession. This is called internally to close the sub session when the download
        * is completed. Only the subsession will be closed but retains the RHttpDownload object.
        * @return none.
        */
        void CloseSubSession();
        
        /**
        * This is called internally to save the downloaded subsession before closing the subsession
        * @param -
        * @return None.
        */
        void SaveDownloadInfoL();

        /**
        * Creates download subsession.
        * @param aUrl The url to be downloaded.
        * @return None.
        */
        void CreateL( const TDesC8& aUrl, const TPtr8 aPackedAttribs );

        /**
        * Attaches subsession to the server subsession by handle.
        * @param aHandle A handle which identifies the server subsession.
        * @return None.
        */
        void AttachL( TInt aHandle );

        /**
        * Start event notification.
        * @param aDownloadState State.
        * @param aProgressState Progress.
        * @param aEventAttrib Packed attribs
        * @param aStatus Handler's request status.
        * @return None.
        */
        void StartEventNotification( TDes8& aDownloadState,
                                     TDes8& aProgressState,
                                     TDes8& aEventAttrib,                                     
                                     TRequestStatus& aStatus );

        /**
        * Cancels event notification.
        * @param -
        * @return None.
        */
        void CancelEventNotification();

        /**
        * Returns true if the handle is equals with the stored one.
        * @param aHandle Handle.
        * @return TBool.
        */
        TBool IsDownload( TInt aHandle );
        
        /**
        * Returns true if the params belongs to this download.
        * @since 2.8
        * @param aParsedReqUrl given URL
        * @param aMsgBody Message body from post operation
        * @return TBool
        */           
        TBool IsDownloadL( const TUriParser8& aParsedReqUrl, 
                           const TDesC8& aMsgBody );

		/**
		* Sets the default value for the attributes.
		* @param aDownload The download which default attributes to be set.
        * @return None.
		*/
        void SetDefaultAttributesL( const TDesC8& aPackedAttribs );

		/**
		* Buffers attributes which need when a client deletes download.
		* @param None.
        * @return None.
		*/
        void BufferAttributesL();

		/**
		* Sets event type.
		* @param aEventType.
        * @return None.
		*/
        void SetEventType( THttpDownloadState aEventType );

		/**
		* Sets http transaction.
		* @param aHttpTransaction.
        * @return None.
		*/
        void SetHttpTransactionL( TInt aHttpTransaction );

		/**
		* Delete http transaction.
		* @param .
        * @return None.
		*/
        void DeleteTransaction();
        
		/**
		* Initialize OMA DD download.
        * @param aBuf The descriptor.
        * @param aType Descriptor data type.
        * @param aEikEnv Eikon environment or NULL. Can be NULL if download
        * does not require UI functionality. If download needs UI but NULL is
        * passed here, the download fails with EFailedPermanent KErrCancel.
        * @return None.
		*/        
        void InitCodDownloadL( const TDesC8& aBuf, 
                               const TDesC8& aMimeType,
                               CEikonEnv* aEikEnv );

		/**
		* Initialize paused OMA DD download.
        * @param aAppUid App UID of the client.
        * @return None.
		*/ 
       void InitPausedCodDownloadL( const TUid aAppUid );
       
		/**
		* Starts COD download.
        * @return None.
		*/                               
        void DoStartCodL();
        
		/**
		* Checks the mime type of a completed content.
		* Creates a cod download if it is considered as OMA DD.
		* The return value is the result of the checking.
		* Leaves in case of failure.
        * @return TBool.
		*/         
        TBool CheckContentTypeAndCreateCodDownloadL();

		/**
		* Sets the error value.
		* @param aAttribute Identifies the attribute to be set.
		* @param aValue The value to be set.
        * @return None.
		*/        
        TInt SetOnError( TInt aError,
                         THttpDownloadMgrError aDlError = EGeneral ); 

#ifdef DEAD_CODE
		/**
		* Allocate buffer for event attribute. Part of IPC optimalization.
        * @return HBufC8.
		*/      
        HBufC8* AllocEventAttribBufL();
#endif
        
		/**
		* Unpack event attribute package.
		* @param aPack Packed attributes.
        * @return None.
		*/          
        void UnpackEventAttribL( const TDesC8& aPack );

        /**
        * True if it is a client side download
        * @param -
        * @return TBool.
        */                                        
        TBool IsClientSideDownload() const;
        
        /**
        * Tells that download should be deleted.
        * @param None
        * @return TBool.
        */         
        TBool IsToBeDeleted();
        
        /**
        * Starts downloading.
        * @param None
        * @return None.
        */         
        void DoStartL(); 
        
        /**
        * Returns the the event priority flag from session
        * @return TInt
        */        
        TInt EventPriorityFlag() const;
        
        /**
        * ETrue if download should be deleted on COD completion.
        * @return TBool
        */         
        TBool IsDeleteCodWhenDone() const;
        
        /**
        * Sets COD in progress flag.
        * @return None
        */        
        void SetCodInProgress( TCodProgressState aVal ); 

        /**
        * Attach to an existing download.
        * @param aDlId Download ID.
        * @return None.
        */
        void AttachToDownloadL( const TInt32 aDlId );
        
        /**
        * Sets COD in progress flag.
        * @return iExtension
        */
        TInt32 ActiveMoIndex() const;
        
        /**
        * To stop waiting loop of AS
        * @return None.
        */
        void StopWaitingAS();

    private:    // Data
        // Event notification handler.
        CDownloadMgrHandler*     iDownloadHandler;  ///< Owned.
        // Download manager session.
        RHttpDownloadMgr*        iDownloadMgr;      ///< NOT Owned.
        // Unique identifier of server side subsession.
        TInt                     iHandle;
        // Extension class
        CRHttpDownloadExtension* iExtension;        ///< Owned.

        CTransactionObserver*    iTransactionObserver;
        RHTTPTransaction*        iHttpTransaction;
        // Descriptor Based download COD/DD
        CCodDownload*            iCodDownload;      ///< Owned.        
        // Cod observer
        CCodObserver*            iCodObserver;    ///< Owned.
        // Client Side Download
        TBool                    iClientSideDownload;
        // Boolean flag which indicates download closure
        TBool                    iClosed;
        // Boolean flag which indicates download subsession closure
        TBool                    iClosedSubSession;
        // Extension class to cache the cloased subsession
        CRHttpDlExtension* 		 iDlExtension;        ///< Owned.
        
        CActiveSchedulerWait*    iWait;
        
        // Boolean flag which indicates Active Scheduler is Ready
        TBool                    iASReady;
        
    public:     // Friend classes
 
        friend class CDownloadMgrHandler;
        friend class RHttpDownloadMgr;
        friend class RHttpDownloadMgrApiExt;
        friend class CTransactionObserver;
        friend class CCodObserver;
        friend class CDownloadMgrHandler;

	};

#endif /* __DOWNLOADMGR_CLIENT_H__ */

