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
* Description:  Supports Download Menu and Downloads List
*
*/

#ifndef CDOWNLOADMGRUIDOWNLOADSLIST_H
#define CDOWNLOADMGRUIDOWNLOADSLIST_H

//  INCLUDES
#include <cdownloadmgruibase.h>
#include <downloadmgrclient.h>
#include <httpdownloadmgrcommon.h>
#include <downloadslistdlgobserver.h>

#include <AiwServiceHandler.h>
#include <AiwCommon.hrh>

// FORWARD DECLARATIONS
class CDownloadMgrUiDownloadMenu;
class CDownloadMgrUiUserInteractions;
class CDownloadsListArray;
class CDownloadsListDlg;
class CUserInteractionsUtils;
class CDownloadMgrUiLibRegistry;
class CAsyncEventHandlerArray;
class CAsyncEventHandlerBase;
class CDownloadsListExtension;

// CLASS DECLARATION

/**
*  Display list of downloads.
*
*  @lib Download Manager UI Lib
*  @since Series 60 2.8
*/
NONSHARABLE_CLASS( CDownloadMgrUiDownloadsList ) : 
                                                public CDownloadMgrUiBase, 
                                                public MHttpDownloadMgrObserver,
                                                public MDownloadsListDlgObserver,
                                                public MAiwNotifyCallback 
    {
    public:  // Constructors and destructor
        
        /**
        * Two-phased constructor.
        */
        static CDownloadMgrUiDownloadsList* NewL
               ( CDownloadMgrUiLibRegistry& aRegistryModel );
        
        /**
        * Destructor.
        */
        virtual ~CDownloadMgrUiDownloadsList();

    public: // New functions

        // -------------------------------------------------------------
        // ************** Download Menu
        // -------------------------------------------------------------

        /**
        * Access the Download Menu utility.
        * @since Series 60 2.8
        * @return -
        */
        IMPORT_C CDownloadMgrUiDownloadMenu& DownloadMenu() const;

        // -------------------------------------------------------------
        // ************** Downloads List
        // -------------------------------------------------------------

        /**
        * Display the list of downloads (the method does not block the scheduler).
        * It means that this method initializes an active object, that completes 
        * itself and it executes the Downloads List dialog in it's RunL.
        * Using this method the caller is not blocked by the wait-dialog.
        * @since Series 60 2.8
        * @return -
        */
        IMPORT_C void DisplayDownloadsListL();

        /**
        * Display the list of downloads (the method does not block the scheduler).
        * It means that this method initializes an active object, that completes 
        * itself and it executes the Downloads List dialog in it's RunL.
        * Using this method the caller is not blocked by the wait-dialog.
        * This method is not exported!
        * @param aHighlightDl This download is highlighted in the list.
        * @since Series 60 3.0
        * @return -
        */
        void DisplayDownloadsListL( RHttpDownload& aHighlightDl );

        /**
        * Cancel displaying the list of downloads.
        * @since Series 60 2.8
        * @return -
        */
        IMPORT_C void CancelDisplayingDownloadsList();

        /**
        * Is the List of Downloads visible?
        * @since Series 60 2.8
        * @return ETrue/EFalse
        */
        IMPORT_C TBool IsVisible() const;

        /**
        * Number of downloads in the List of Downloads.
        * @since Series 60 2.8
        * @return TInt
        */
        IMPORT_C TInt Count() const;

        /**
        * Remove the given download from the list.
        */ 
        void DeleteDownloadL( RHttpDownload& aDownload );

        /**
        * Is one of them progressive
        * @since Series 60 3.2
        * @return TBool 
        */
        TBool IsOneProgressive();
        
        /**
        * Is one of them progressive
        * @since Series 60 3.2
        * @return TBool 
        */
        inline TBool IsProgressiveDownloadEnabled() {return iProgressiveDownload; }
        
        /**
        * Gets the value of downloadlist hide
        * @return TBool 
        */
        inline TBool GetDownloadHide() { return iDownloadListHide; }
#ifdef BRDO_SINGLE_CLICK_ENABLED_FF
        /**
        * Adding Aiw Commands to the given MenuPane
        */
        void AIWPlugInMenusL(TInt aResourceId,CEikMenuPane* aMenuPane);
#endif        

    public: // Functions from CDownloadMgrUiBase

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
        CDownloadMgrUiDownloadsList( CDownloadMgrUiLibRegistry& aRegistryModel );

        /**
        * By default Symbian 2nd phase constructor is private.
        */
        void ConstructL();

    protected: // New functions

        // -------------------------------------------------------------
        // ************** List box utilities
        // -------------------------------------------------------------

        /**
        * Add downloads to the list residing in aDownloadMgr.
        * If a given download is already on the list, the list item is only updated.
        */ 
        void AddDownloadsToListModelL( CDownloadsListArray& aLBModel, 
                                       RHttpDownloadMgr& aDownloadMgr );

        /**
        * Add the download to the list.
        * If the download is already on the list, the list item is only updated.
        * This method should be used for adding new downloads - 
        * not for updating existing ones.
        * @return Returns the index relative to zero of the appended or updated item.
        */
        TInt AddDownloadToListModelL( CDownloadsListArray& aLBModel, 
                                      RHttpDownload& aDownload );

        // -------------------------------------------------------------
        // ************** Responses to download events
        // -------------------------------------------------------------

        void NewDownloadCreatedL( RHttpDownload& aDownload );
        void UpdateProgressInfoL( RHttpDownload& aDownload, THttpDownloadEvent aEvent );
        void DownloadPausedL( RHttpDownload& aDownload, THttpDownloadEvent aEvent );
        void DownloadCompletedL( RHttpDownload& aDownload, THttpDownloadEvent aEvent );
        void DownloadFailedL( RHttpDownload& aDownload, THttpDownloadEvent aEvent );
        void PauseableStateChangedL( RHttpDownload& aDownload, TBool aPausable );

        // -------------------------------------------------------------
        // ************** Other utility
        // -------------------------------------------------------------

        void HideMenu();

    protected: // Functions from MHttpDownloadMgrObserver

        virtual void HandleDMgrEventL( RHttpDownload& aDownload, THttpDownloadEvent aEvent );

    protected: // Functions from MDownloadsListDlgObserver

        virtual void PreLayoutDynInitL( CDownloadsListDlg& aDialog );
        virtual void ProcessCommandL( CDownloadsListDlg& aDialog, TInt aCommandId );
        virtual void DynInitMenuPaneL( CDownloadsListDlg& aDialog, TInt aResourceId, CEikMenuPane* aMenuPane );
        virtual TKeyResponse OfferKeyEventL( CDownloadsListDlg& aDialog, const TKeyEvent& aKeyEvent, TEventCode aType );


    protected: // Function from MAIWNotifyCallback 
        TInt HandleNotifyL( TInt /*aCmdId*/,
                            TInt /*aEventId*/,
                            CAiwGenericParamList& /*aEventParamList*/,
                            const CAiwGenericParamList& /*aInParamList*/ ){return KErrNone;}
    private: 
        void AttachAIWInterestL();
        void HandleAIWCommandL(TInt aCommand, RHttpDownload& aDownload);
        void InitializeAIWPlugInMenusL( TInt aResourceId, 
                                        CEikMenuPane* aMenuPane,
                                        RHttpDownload& aDownload );
        void ProvideInputParametersL( CAiwGenericParamList& aParams,
                                      TInt& /*aCommandOptions*/,
                                      RHttpDownload& aDownload);
                                      
        void LaunchFileManagerApplication();

    public:
        /**
        * Sets the value of downloadlist hide
        * @return void 
        */
        void SetDownloadListHide( TBool aHide );

    private:  // Data
        
        CDownloadsListExtension*    iExtension; ///< Extension class. Owned.

        CUserInteractionsUtils*     iUiUtils; ///< Utility. Owned.
        CDownloadMgrUiDownloadMenu* iDownloadMenu; ///< Download Menu utility. Owned.
        CAsyncEventHandlerArray*    iEventHandlerArray; ///< Owned.
        CDownloadsListArray*        iListModel; ///< Association array: list item-download. Owned.
        CDownloadsListDlg*          iDialog; ///< Owned. Unused member.
        TBool                       iIsVisible; ///< Unused member.
		TBool						iIsTimerStarted;
		CAiwServiceHandler* iAIWServiceHandler;
		TBool						iProgressiveDownload;
		
		TBool						iIsCancelInProgress;
		TBool                       iPlatformSupportsGallery;

        TBool                       iDownloadListHide;
    private: // Friend classes

        friend class CDownloadsListExtension;
    };

#endif /* CDOWNLOADMGRUIDOWNLOADSLIST_H */
