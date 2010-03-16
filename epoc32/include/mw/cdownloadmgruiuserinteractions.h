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
* Description:  Supports user interaction dialogs for downloads
*
*/



#ifndef CDOWNLOADMGRUIUSERINTERACTIONS_H
#define CDOWNLOADMGRUIUSERINTERACTIONS_H

//  INCLUDES
#include <CDownloadMgrUiBase.h>
#include <DownloadMgrClient.h>
#include <vwsdef.h>

// CONSTANTS
_LIT8( KDrmInnerContentTypesToLaunch, "application/java-archive application/x-java-archive x-epoc/x-sisx-app application/x-pip" );
_LIT8( KSisxApplication, "x-epoc/x-sisx-app application/vnd.symbian.install x-epoc/x-app268436505" );
_LIT8( KPipApplication, "application/x-pip" );
_LIT8( KWidgetMimeType, "application/x-nokia-widget" );
_LIT8( KSharingConfig, "application/isf.sharing.config" );

// DATA TYPES
enum TClientAppExitType
    {
    ETerminatedByUser,
    ETerminatedBySystem
    };

// FORWARD DECLARATIONS
class CUserInteractionsUtils;
class CDownloadMgrUiLibRegistry;
class CAsyncEventHandlerArray;
class CEikAppUi;
class CUserInteractionsExtension;

// CLASS DECLARATION

/**
*  The User Interactions supports the followings:
*  - User confirmation when content-type header arrives
*  - Handling completed downloads
*  - Querying HTTP authentication credentials
*  - Querying proxy authentication credentials
*  - Error notification
*  - Client App termination by the User
*
*  @lib Download Manager UI Lib
*  @since Series 60 2.8
*/
NONSHARABLE_CLASS( CDownloadMgrUiUserInteractions ) : 
                                                public CDownloadMgrUiBase,
                                                public MHttpDownloadMgrObserver
    {
    public:  // Constructors and destructor
        
        /**
        * Two-phased constructor.
        */
        static CDownloadMgrUiUserInteractions* NewL
               ( CDownloadMgrUiLibRegistry& aRegistryModel );
        
        /**
        * Destructor.
        */
        virtual ~CDownloadMgrUiUserInteractions();

    public: // New functions

        /**
        * Client Apps can call this function before exiting the application. 
        * It should be called when the user terminates the application. 
        * It opens a confirmation query.
        * @return OK to exit? True/False. It is only a suggested value!
        */
        IMPORT_C TBool OkToExitL();

        /**
        * Client Apps can call this function in the App UI's destructor. 
        * It has been made non-leavable, so it can be called without TRAP.
        * It initializes Grouped Soft Notifications, if necessary.
        * @param aAppUi Reference to the actual App UI.
        * @param aExitType Exit type when this function is called.
        *                  Only ETerminatedBySystem is supported.
        * @param aViewId View ID of the view where to switch in case user chooses
        *                accept softkey in the soft notification.
        * @param aCustomMessageId Custom message ID.
        * @param aViewActivationMsg Custom message sent to the view in 
        *                           the view activation process.
        * @return Error code or KErrNone.
        */
        IMPORT_C TInt PrepareToExit( CEikAppUi& aAppUi, 
                                     TClientAppExitType aExitType, 
                                     TVwsViewId aViewId, 
                                     TUid aCustomMessageId, 
                                     const TDesC8& aViewActivationMsg );

        /**
        * Client Apps can call this function in the App UI's destructor. 
        * It has been made non-leavable, so it can be called without TRAP.
        * It initializes Grouped Soft Notifications, if necessary.
        * @param aAppUid 3rd UID of the application.
        * @param aViewId View ID that needs to be activated.
        * @param aCustomMessageId Custom message ID.
        * @return Error code or KErrNone.
        */
        IMPORT_C TInt PrepareToExit( TUint32 aAppUid,
                                     TUint32 aViewId, 
                                     TUint32 aCustomMessageId );

        /**
        * Currently it supports handling completed download.
        * COD download is deleted, otherwise normal behaviour, that 
        * depends on EDlAttrAction (EDoNothing/EMove/ELaunch).
        * @param aDownload The actual download
        * @return -
        */
        IMPORT_C void HandleDownloadL( RHttpDownload& aDownload );

        /**
        * The number of download confirmations being shown.
        * @return Non-negative integer value.
        */
        TInt DownloadConfirmationsShown() const;

        /**
        * Ask if a handler or something uses the UI, so 
        * others should postpone their tasks that require UI.
        * @return yes/no.
        */
        TBool IsUiBusy() const;

        /**
        * Is a Cod ServiceFlow running?
        * @return yes/no.
        */
        TBool IsCodServiceFlowRunning() const;

        /**
        * Is Cod ServiceFlow running of the given download?
        * @param aDownload The download in question.
        * @return yes/no.
        */
        TBool IsCodServiceFlowRunning( RHttpDownload& aDownload ) const;

        /**
        * Is a Cod ServiceFlow running?
        * LEAVing version.
        * @return yes/no.
        */
        TBool IsCodServiceFlowRunningL() const;

        /**
        * Is Cod ServiceFlow running of the given download?
        * LEAVing version.
        * @param aDownload The download in question.
        * @return yes/no.
        */
        TBool IsCodServiceFlowRunningL( RHttpDownload& aDownload ) const;

        /**
        * Postpone handling the given COD download. The download is placed to a 
        * LIFO queue, and SetHandlerRunning( EFalse ) handles (restarts) the first 
        * download in it.
        * @param aDownload The download to be postponed.
        */
        void PostponeCodHandlingL( RHttpDownload& aDownload );

        /**
        * Check if the given download is postponed.
        * @param aDownload The download in question.
        * @return true/false.
        */
        TBool IsPostponed( RHttpDownload& aDownload ) const;

        /**
        * Schedule a postponed download for running.
        */
        void SchedulePostponedDownloadL();

    public: // Functions from CDownloadMgrUiBase

        /// Attribute enumerations.
        enum TDownloadMgrUiUserInteractionsAttr
            {
            EAttrSuppressDownloadConfirmation ///< TBool, default: EFalse
            };

        IMPORT_C virtual void GetIntAttributeL( const TUint aAttribute, TInt32& aValue );
        IMPORT_C virtual void GetBoolAttributeL( const TUint aAttribute, TBool& aValue );
        IMPORT_C virtual void GetStringAttributeL( const TUint aAttribute, TDes16& aValue  );
        IMPORT_C virtual void GetStringAttributeL( const TUint aAttribute, TDes8& aValue  );
        IMPORT_C virtual void SetIntAttributeL( const TUint aAttribute, TInt32 aValue );
        IMPORT_C virtual void SetBoolAttributeL( const TUint aAttribute, TBool aValue );
        IMPORT_C virtual void SetStringAttributeL( const TUint aAttribute, const TDesC16& aValue );
        IMPORT_C virtual void SetStringAttributeL( const TUint aAttribute, const TDesC8& aValue );

    protected: // Constructors

        /**
        * C++ default constructor.
        */
        CDownloadMgrUiUserInteractions( CDownloadMgrUiLibRegistry& aRegistryModel );

        /**
        * By default Symbian 2nd phase constructor is private.
        */
        void ConstructL();

    protected: // New functions

        // Event handler functions

        /**
        * Wraps DoHandleCompletionWithQueryL() to ensure that only one instance
        * of the dialog is displayed at any point in time.
        * @param aDownload The actual download
        * @return void
        */
        void HandleCompletionWithQueryL( RHttpDownload& aDownload, 
                                                                 TBool aIsUiBusy, 
                                                                 TBool aIsSupported, 
                                                                 TBool aIsDrm, 
                                                                 TBool aDrmRightsOnPhone );
        /**
        * Handle download completion with query (wait) dialog.
        * @param aDownload The actual download
        * @return -
        */
        void DoHandleCompletionWithQueryL( RHttpDownload& aDownload, 
                                                                 TBool aIsUiBusy, 
                                                                 TBool aIsSupported, 
                                                                 TBool aIsDrm, 
                                                                 TBool aDrmRightsOnPhone );

        /**
        * Leaving version of PrepareToExit().
        * @return None.
        */
        void PrepareToExitL( CEikAppUi* aAppUi, 
                             TClientAppExitType aExitType, 
                             TVwsViewId aViewId, 
                             TUid aCustomMessageId, 
                             const TDesC8& aViewActivationMsg );

        /**
        * Is a stand-alone instance running from the very same application?
        * @return True/False.
        */
        TBool IsStandAloneAppRunning();

        /**
        * Delete Event Handler(s) showing download confirmation query.
        * @param aDownload The actual download.
        */
        void DeleteEventHandlerShowingDlConfirmation( RHttpDownload& aDownload );

        /**
        * Delete Event Handler(s) belonging to the given download.
        * @param aDownload The actual download.
        */
        void DeleteEventHandlers( RHttpDownload& aDownload );

        /**
        * Handle completed normal download (not COD or OMA, not DRM).
        * @param aDownload The actual download
        * @return -
        */
        void HandleNormalDownloadL( RHttpDownload& aDownload );

        /**
        * Check if the download is COD.
        * @param aDownload The actual download
        * @return ETrue/EFalse
        */
        TBool CodDownloadL( RHttpDownload& aDownload ) const;

    protected: // Functions from MHttpDownloadMgrObserver

        virtual void HandleDMgrEventL( RHttpDownload& aDownload, 
                                       THttpDownloadEvent aEvent );

    private:  // Data
        
        CUserInteractionsExtension* iExtension; ///< Extension class, Owned.

        CUserInteractionsUtils*     iUiUtils; /**< Owned. Should be only one 
                                                   instance in the UILib! */
        CAsyncEventHandlerArray*    iEventHandlerArray; ///< Owned.

        TBool                       iDlgActive;

    private: // Friend classes

        friend class CUserInteractionsExtension;
    };

#endif /* CDOWNLOADMGRUIUSERINTERACTIONS_H */
