/*
* Copyright (c) 2006 Nokia Corporation and/or its subsidiary(-ies).
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
* Description:  Enum Definition of the Browser Control API
*
*/


#ifndef BRCTLDEFS_H
#define BRCTLDEFS_H

//  INCLUDES

// DATA TYPES

// FORWARD DECLARATIONS

// EXPORTED FUNCTION

/**
* The TBrCtlDefs class contains definitions of custom data types for the Browser Control API.
*
* Usage:
*
* @code
*  #include <brctldefs.h>
*
* @see S60 Platform: Browser Control API Developer's Guide Version 2.0
* @lib BrowserEngine.lib
* @since 3.0
* @file brctldefs.h
* @endcode     *
*/
class TBrCtlDefs
    {
    public:
        /**
         * The Browser Control uses 600 command IDs, whose default
         * range is from 15000 - 15600. The host application can specify
         * any desired range through the API.
         */
        enum TBrCtlCommandId
            {
            ECommandIdBrowserBase = 0, ///< The base Browser ID.
            ECommandIdSubscribeToBase = 90, ///< The SubscribeToBase ID.
            ECommandIdPluginBase = 100, ///< The base plug-in ID.
            ECommandIdWMLBase = 300, ///< The base WML ID.
            ECommandIdRange = 600,   ///< The maximum number of command IDs.
            ECommandIdBase = 15000   ///< The base value for the command IDs.

            };
        /**
        * Rules that determine in which mode the cache operates.
        */
        enum TBrCtlCacheMode
            {
            /**
            * Normal caching operation.
            * If the requested entity is in the cache and it has not expired,
            * get it from the cache. If the requested entity is not in the cache,
            * or if it has expired, the browser should request it from the server.
            */
            ECacheModeNormal = 0,
            /**
            * If the requested entity is in the cache, get it from the cache
            * even if it has expired. If the requested entity is not in the cache,
            * the browser should request it from the server.
            */
            ECacheModeHistory,
            /**
            * The browser should request the content from the server even if it is in the cache.
            */
            ECacheModeNoCache,
            /**
            * If the requested entity is in the cache, get it from the cache
            * even if it has expired. If the requested entity is not in the cache,
            * return an error.
            */
            ECacheModeOnlyCache
            };
        /**
        * The host application can send these commands
        * to the Browser Control by calling the HandleCommandL function.
        * @attention The host application should define the base for the command
        * IDs and add that base to the enum value of each command.
        */
        enum TBrCtlCommands
            {
            ECommandDisconnect = 0, ///< Unloads the HTTP Framework
            ECommandCancelFetch, ///< Cancels all outstanding requests
            ECommandOpen, ///< Activates the focused element
            ECommandReload, ///< Reloads the current page
            ECommandBack, ///< Loads the previous page, if available
            /**
            * Loads the next page. This command is used only to return
            * to the next page after going back to a previous page.
            */
            ECommandForward,
            ECommandClearHistory, ///< Clears the history stack
            /**
            * Shows a list of history entries. Do not use this parameter if
            * LoadDataL or InitLoadDataL are used.
            */
            ECommandShowHistory,
            ECommandAccept, ///< Accepts the input data in the editor.
            /**
            * Cancels the input data in the editor. Sets the focus back
            * on the browser after the focus is shifted to a plug-in.
            */
            ECommandCancel,
            ECommandOpenToViewer, ///< Opens object data in an external viewer
            /**
            * Adds the contact information of the link currently selected to
            * the phone book
            */
            ECommandAddToPhoneBook,
            /**
            *Makes a phone call using the phone number in the link currently selected
            */
            ECommandMakeCall,
            ECommandRemoveFileName, ///< Removes the file name from a file selection box
            ECommandShowImages, ///< Shows a list of the images in the current page
            ECommandLoadImages, ///< Loads images when automatic image loading is turned off
            ECommandGainFocus, ///< Called when the Browser Control returns from background
            ECommandLoseFocus, ///< Called when the Browser Control goes to the background
            /**
            * Do not call this parameter. It is a base for the next three commands.
            */
            ECommandFindItem,
            /**
            * Displays the FindItem dialog and highlights all of the
            * phone numbers in the current page. Use this parameter only
            * if you specified the ECapabilityFindItem capability.
            */
            ECommandFindItemPhoneNumber,
            /**
            * Displays the FindItem dialog and highlights all of the e-mail
            * addresses in the current page. Use this parameter only if you
            * specified the ECapabilityFindItem capability.
            */
            ECommandFindItemEMail,
            /**
            * Displays the FindItem dialog and highlights all of the URLs in
            * the current page. Use this parameter only if you specified
            * the ECapabilityFindItem capability.
            */
            ECommandFindItemAddress,
            ECommandFindKeyword, ///< Reserved for future use.
            ECommandClearFind, ///< Reserved for future use.
            ECommandShowThumbnailView, ///< Reserved for future use.
            ECommandShowDownloads, ///< Tells the Download Manager to display the list of downloads.
            /**
            * Saves the following launch parameters when the application
            * unexpectedly shuts down. These parameters all have the prefix ESettingsLaunch:
            * AppUid, ViewId, CustomMessageId
            * When the phone reboots, it uses these parameters to restart
            * the host application and resume the interrupted downloads.
            * NOTE: These parameters must be set before calling this command.
            */
            ECommandSaveLaunchParams,
            ECommandOneStepBack, ///< Reserved for future use.
            ECommandAppForeground, ///<
            ECommandAppBackground, ///<
            ECommandOpenNewWindow, ///<
            ECommandClearAutoFormFillData, ///<
            ECommandClearAutoFormFillPasswordData, ///<
            ECommandFreeMemory, ///<
            ECommandMemoryGood, ///<
            ECommandDumpRenderTree, ///<
            ECommandUnloadWMLEngine, ///<
            ECommandSmartLinkMakeCall, ///<
            ECommandSmartLinkSendMessage, ///<
            ECommandSmartLinkAddToPhoneBook, ///<
            ECommandShowToolBar, ///<Shows the toolbar
            ECommandSmartLinkSendEmail, ///<
            ECommandShowAnchorHref,  ///<Display the URL of a hyperlink - supported only for HTML
            ECommandLoadFocusedImage, ///<Load the focuesd image - supported only for HTML
            ECommandUnLoadPluginWindows, ///<Unload plugin windows
            /**
            * Displays the FindItem dialog and highlights all of the VoIP
            * addresses in the current page. Use this parameter only if you
            * specified the ECapabilityFindItem capability.
            */
            ECommandFindItemVoIPAddress, ///<Find VoIP address item
            ECommandSmartLinkMakeVoipCall,   ///<MakeVoip Callthrough smartlink
            /**
            * Zoom Slider configuration.
            */
            ECommandZoomSliderShow, ///< Zoom slider visible.
            ECommandZoomSliderHide, ///< Zoom slider hidden.
            ECommandHistoryNavigateForward,
            ECommandHistoryNavigateBack,
            /*
             ** Enter/Exit Fullscreen Browsing
             */
             ECommandEnterFullscreenBrowsing,
             ECommandLeaveFullscreenBrowsing,
             ECommandZoomIn,
             ECommandZoomOut
            };
        /**
        * The load event that occurred.
        */
        enum TBrCtlLoadEvent
            {
            EEventNone = 0,                     // Non event, Not used.
            /**
            * A page is beginning to load. This includes images, scripts,
            * style sheets, and anything else embedded in the page as a single load event.
            */
            EEventNewContentStart,
            /** A URL is beginning to load. This notifies the observer of a
            * separate load event for each image or other element embedded in the page.
            */
            EEventUrlLoadingStart,
            /**
            * The first data chunk has arrived. This occurs when the response
            * headers are received.
            */
            EEventNewUrlContentArrived,
            /**
            * Another data chunk has arrived.
            * This occurs for each chunk of data that is loaded, including the first chunk.
            */
            EEventMoreUrlContentArrived,
            /**
            * The first chunk of content is displayed. The previous page is
            * destroyed at this time. This occurs once per page.
            */
            EEventNewContentDisplayed,
            /**
            * Another chunk of content is displayed. This occurs for each
            * chunk of content that is displayed, except for the first chunk.
            */
            EEventMoreContentDisplayed,
            EEventUrlLoadingFinished,           ///< A URL has finished loading.
            /**
            * The page has finished loading. If the host application draws a
            * progress bar, it can be removed when this event is received.
            */
            EEventLoadFinished,
            EEventContentFinished,  ///< The content has finished loading.
            /**
            * A page title was encountered. After receiving this
            * event, the host application can call PageInfoLC to receive the page title.
            */
            EEventTitleAvailable,
            EEventLoadError,      ///< An error occurred while loading the page.
            /**
            * The user is navigating from a non-secure page to a secure page.
            * The host application displays a secure icon, if needed.
            */
            EEventEnteringSecurePage,
            /**
            * The user is navigating from a secure page to a non-secure page.
            * If the host application displays a secure icon, that icon should be removed.
            */
            EEventExitingSecurePage,
            /**
            * The user is entering a secure page that contains non-secure items.
            */
            EEventSomeItemsNotSecure,
            /**
            * The user is submitting information to a non-secure page.
            */
            EEventSubmittingToNonSecurePage,
            /**
            * User confirmation is required to redirect the browser.
            */
            EEventRedirectConfirmation,
            /**
            * User confirmation is required to repost a page that has been viewed previously.
            */
            EEventRepostConfirmation,
            /**
            * The user is entering a non-secure page that contains secure items.
            */
            EEventSecureItemInNonSecurePage,
            /**
            * Authentication failed or was cancelled.
            */
            EEventAuthenticationFailed,
            /**
            * A file is beginning to upload.
            */
            EEventUploadStart,
            /**
            * A file has finished uploading; the last chunk of data has been transmitted.
            */
            EEventUploadFinished,
            /**
            * Length of the data transmitted and the cumulative size of the uploaded file.
            */
            EEventUploadIncrement,
            EEventFaviconAvailable,
            EEventThumbnailAvailable
            };
        /**
        * The setting to manipulate.
        */

        enum TBrCtlSettings
            {
            ESettingsUnknown = -1, ///< Not used
            /**
            * If set to On, large pages are optimized for display on a small screen.
            * If set to Off, all pages display in their original format.
            */
            ESettingsSmallScreen = 0,
            /**
            * If set to On, images automatically load when a page is downloaded.
            * If set to Off, images are not loaded. Default: On
            */
            ESettingsAutoLoadImages,
            /**
            * If set to All.Large, all text is shown 40% larger than its declared size.
            * If set to Larger, all text is shown 20% larger than its declared size.
            * If set to Normal, all text is shown as its declared size.
            * If set to Smaller, all text is shown 20% smaller than its declared size.
            * If set to All.Small, all text is shown 40% smaller than its declared size.
            */
            ESettingsFontSize,
            /**
            * If set to On, the host application is embedded within another application.
            * If set to Off, the host application is not embedded within another application.
            */
            ESettingsEmbedded,
            /**
            * If set to On, paragraphs are automatically wrapped to fit into the display width.
            * If set to Off, paragraphs are not automatically wrapped.
            * @attention This parameter is not shown if ESettingsSmallScreen is set to On.
            */
            ESettingsTextWrapEnabled,
            /**
            * If set to Allow, the user can send and receive cookie information.
            * If set to Reject, the user cannot send or receive cookie information.
            */
            ESettingsCookiesEnabled,
            /**
            * If set to Finest, external style sheets are downloaded when
            * Small Screen Layout is used. If set to Fastest, external style
            * sheets are not downloaded when Small Screen Layout is used.
            * Default value: Fastest
            */
            ESettingsCSSFetchEnabled,
            /**
            * If set to Enable, ECMA Script is enabled.
            * If set to Disable, ECMA Script is disabled.
            * Default value: Enable
            */
            ESettingsECMAScriptEnabled,
            /**
            * Device unique identification number sent to a server for billing
            * purposes in e-commerce. If set to Enable, the Browser Control
            * sends the International Mobile Equipment Identity (IMEI) to the server.
            * If set to Disable, the Browser Control does not send the IMEI to the server.
            * Default value: Disable
            */
            ESettingsIMEINotifyEnabled,
            /**
            * Character coding. If set to Automatic, the character set is
            * automatically selected according to the following criteria, in order or priority:
            * 1. Detected from the Byte Order Mark (BOM)
            * 2. Detected from XML Document Type Definition (DTD)
            * 3. Declared in <meta> element
            * 4. Detected from HTTP headers
            * 5. Variant-specific default character set for automatic detection.
            * Possible character codings are:
            * Latin
            * Simplified Chinese
            * Traditional Chinese
            * Unicode (UTF-8)
            * Unicode (ucs-2)
            * ISO 8859 - 2,4,5,7,or 9
            * Hebrew (ISO-Logical)
            * Hebrew (ISO-Visual)
            * Hebrew (Windows)
            * Arabic (ISO)
            * Arabic (Windows)
            * Windows - 1250, 1251, 1253, 1254, or 1257
            * Thai
            * Thai (Windows 874)
            * Shift_jis
            * Euc-jp
            * ISO-2022-jp
            * The default value is variant-specific.
            */
            ESettingsCharacterset,
            /**
            * URL of the initial page. Tells the
            * Browser Control to send the referrer header in the request.
            */
            ESettingsSendRefererHeader,
            /**
            * One of the following:
            * Certificate not valid yet
            * Server certificate expired
            * Server certificate not received
            * Invalid server certificate
            * Authority certificate not valid yet
            * Authority certificate expired
            * Authority certificate not found
            * Authority certificate corrupted
            */
            ESettingsSecurityWarnings,
            /**
            * Default access point for the Browser Control to use when
            * connecting to the network.
            */
            ESettingsApId,
            ESettingsCurrentZoomLevelIndex, ///< Reserved for future use.
            ESettingsPageOverview,  ///< Reserved for future use.
            ESettingsNumOfDownloads, ///< Number of downloads in progress.
            /**
            * UID of the application to
            * restart after a reboot in order to continue an interrupted download.
            */
            ESettingsLaunchAppUid,
            /**
            * View ID of the application to
            * restart after a reboot in order to continue an interrupted download.
            */
            ESettingsLaunchViewId,
            /**
            * Message that asks the user whether to resume the download.
            */
            ESettingsLaunchCustomMessageId, ///< Reserved for future use.
            ESettingsBackList, ///< Reserved for future use.
            ESettingsAutoRefresh, ///< Reserved for future use.
            /**
            * If set, the browser encodes URLs using UTF-8 instead of
            * the original content encoding.
            * @attention This is recommended only for the APAC region.
            */
            ESettingsBrowserUtf8Encoding,
            ESettingsAutoFormFillEnabled, ///< For enabling the auto fill
            ESettingsSavedPage,           ///< Save the page
            ESettingsSmartLink,
            ESettingsAutoOpenDownloads, // For automatically open the downloaded files
            ESettingsDisableFlash, ///<Enable/Disable the flash
            ESettingsScriptLog,         /// script log
            /**
            * Toolbar buttons configuration settings
            */
            ESettingsToolbarOnOff,
            ESettingsToolbarButton1Cmd,
            ESettingsToolbarButton2Cmd,
            ESettingsToolbarButton3Cmd,
            ESettingsToolbarButton4Cmd,
            ESettingsToolbarButton5Cmd,
            ESettingsToolbarButton6Cmd,
            ESettingsToolbarButton7Cmd,
            /**
            * Browser Zoom level configuration settings
            */
            ESettingsZoomLevelMin,          ///< Minimum Zoom level supported
            ESettingsZoomLevelMax,          ///< Maximum Zoom level supported
            ESettingsZoomLevelDefault,      ///< Default Zoom level for new page
            /*
            * Browser cursor show mode -- some phone doesn't have cursor inside Browser
            */
            ESettingsCursorShowMode,
            
            /*
             * Enter key mode - default behavior is like in desktop browser - submit the form
             * The alternative is to select the link is one is activated.
             */
            ESettingsEnterKeyMode, 
            
            ESettingsMaxEnum              ///< Must be last one
            };

            /**
            * The size of the font selected.
            */
        enum TBrCtlFontSizeLevel
            {
            /**
            * Text is shown 40% smaller than its declared size.
            */
            EFontSizeLevelAllSmall = 0,
            /**
            * Text is shown 20% smaller than its declared size.
            */
            EFontSizeLevelSmaller,
            /**
            * Text is shown as its declared size.
            */
            EFontSizeLevelNormal,
            /**
            * Text is shown 20% larger than its declared size.
            */
            EFontSizeLevelLarger,
            /**
            * Text is shown 40% larger than its declared size.
            */
            EFontSizeLevelAllLarge
            };
        /**
        * Configuration options for the Browser Control
        */
        enum TBrCtlCapabilities
            {
            /**
            * Displays horizontal and vertical scroll bars.
            */
            ECapabilityDisplayScrollBar         = 0x0001,
            /**
            * Sends request to load embedded content to the host application.
            * The host application indicates whether or not the load request
            * should proceed.
            */
            ECapabilityClientResolveEmbeddedURL = 0x0002,
            /**
            * Sends request to load a URL to the host application.
            * The host application indicates whether or not the load
            * request should proceed.
            */
            ECapabilityClientNotifyURL          = 0x0004,
            /**
            * Disables input boxes and Netscape plug-ins.
            */
            ECapabilityDisableInputAndPlugins   = 0x0008,
            /**
            * Adds Find Item to the Options menu.
            */
            ECapabilityFindItem                 = 0x0010,
            /**
            * Allows network access for HTTP requests.
            * If this option is not set, HTTP requests will fail.
            */
            ECapabilityLoadHttpFw               = 0x0020,
            /**
            * Employs the Download Manager to download content, such as audio or video files.
            */
            ECapabilityUseDlMgr                 = 0x0040,
            /**
            * Launches a viewer application to view the downloaded content.
            */
            ECapabilityLaunchViewer             = 0x0080,
            ECapabilityGraphicalHistory     = 0x0100, ///< Reserved for future use.
            ECapabilitySavedPage        = 0x0200,  ///< Reserved for future use.
            ECapabilityConfirmDownloads = 0x0400, ///< Enables confirmation dialog in the Download Manager.
            ECapabilityAutoFormFill     = 0x0800,
            ECapabilityCursorNavigation = 0x1000,
            ECapabilityGraphicalPage    = 0x2000,
            ECapabilityAccessKeys       = 0x4000,
            ECapabilityFavicon          = 0x8000,
            ECapabilityToolBar          = 0x00010000,
            ECapabilityWebKitLite       = 0x00020000,
            ECapabilityFitToScreen      = 0x00040000
            };

        /**
        * Gets the requested page information.
        */
        enum TBrCtlPageInfo
            {
            EPageInfoTitle = 0, ///< Page title, if a title was specified
            EPageInfoUrl,    ///< URL of the current page
            EPageInfoContent, ///< Page content as a text buffer
            EPageInfoSavedPage, ///< Page content, including all embedded content, as a buffer
            EPageInfoFocusedNodeUrl //< URL of the focused link. The function leaves if the focus is not on an anchor or imagemap
            };
        /**
        * Indicates whether the browser is in Image Map view.
        */
        enum TBrCtlState
            {
            /**
            * Currently, the
            * only state change that can be observed is in and out of Image Map view.
            */
            EStateImageMapView = 0,
            EStateHistoryView, ///< For future use
            EStateThumbnailView, ///< For future use
            EStateWmlView,        ///< For WML view
            EStateSmartTextView,   ///< For Smart text recognition mode
            EStateToolBarMode,      ///< For toolbar
            EStatePluginPlayer,
            EStateScriptLog,
            EStateZoomSliderMode,    ///< For ZoomSlider
            EStateFullscreenBrowsing,    ///< For entering/escaping fullscreen browsing
            EStateHistoryBeginning,
            EStateHistoryEnd,
            EStateSynchRequestMode,  ///< For synchronous (XHR) requests
            EStatePluginFullScreen
            };
        /**
        * Type of the focused element.
        */
        enum TBrCtlElementType
            {
            EElementNone = 0, ///< No element is present.
            EElementImageBox, ///< Box containing an image.
            /**
            * Element used to create either of the following:
            * A link to another document
            * A bookmark within a document
            */
            EElementAnchor,
            EElementTelAnchor, ///< Anchor with a "tel:" scheme
            EElementMailtoAnchor, ///< Anchor with a "mailto:" scheme
            EElementInputBox, ///< Input box that can be selected and activated.
            EElementActivatedInputBox, ///< Input box that contains an entry field into which the user can type.
            /**
            * Box that contains a list of items. The user
            * can select one of the items by clicking it.
            */
            EElementSelectBox,
            /**
            * Push button that can contain text or images. For example, Submit.
            */
            EElementButton,
            EElementTextAreaBox, ///< Input box that contains more than one line.
            EElementRootBox, ///< Root of the document.
            EElementObjectBox, ///< Placeholder for a plug-in that has not yet been downloaded.
            /**
            * Box containing a plug-in that the user can
            * manipulate; for example, by navigating links.
            */
            EElementActivatedObjectBox,
            EElementDownloadedObjectBox, ///< Plug-in that is present but is not being manipulated.
            EElementFileSelectionBoxNoContent, ///< File-browsing box in which no file is selected.
            EElementFileSelectionBoxWithContent, ///< File-browsing box in which a file was selected previously.
            EElementAreaBox, ///< Image map.
            EElementCheckBoxChecked, ///< A check box that was selected.
            EElementCheckBoxUnChecked, ///< A check box that was not selected.
            EElementRadioButtonSelected, ///< A radio button that was selected.
            EElementRadioButtonUnSelected, ///< A radio button that was not selected.

            EElementMouseButtonListener, ///< A Mouse button listener
            EElementScrollBar,    ///< A scroll bar

            EElementSmartLinkTel, ///< A telephone number in the page.
            EElementSmartLinkEmail, ///< an email address in the page.
            EElementBrokenImage, ///< A missing image
            EElementSmartLinkVoip, ///< A voip smartlink
            EElementSelectMultiBox ///< A select box with multiple select
        };

        /**
        * Identifies the navigation direction
        */
        enum TBrCtlNavigationDirection
            {
            ENavigationBack, ///< Navigate to the previous page
            ENavigationForward ///< Navigate to the next page
            };

       /**
        * Returns information about the version of the Browser Control.
        */
        enum TBrCtlVersionInfo
          {
          EVersionInfoName = 0, ///< Name of the Browser Control
          EVersionInfoVersion,  ///< Version of the Browser Control
          EVersionInfoBuild,    ///< Build of the Browser Control
          EBrowserVersion   ///< Browser Version
          };

        /**
        * Returns information about the version of the Browser Control.
        */
        enum TBrCtlParams
            {
            EParamsUnknown = -1, ///< Not used
            /**
            * List of content types that do not use the Download Manager
            */
            EParamsSelfDownoadableTypes = 0,
            /**
            * List of headers that the Browser Control should add to each request
            */
            EParamsRequestHeaders,
            EParamsMax ///< Not used
            };

        /**
        * Reserved for future use
        */
    enum TBrCtlFindResponse
      {
      EFindNoMatches = 0, ///< Reserved for future use
      EFindWrapAround,    ///< Reserved for future use
      EFindAllMatches,    ///< Reserved for future use
      EFindMatch          ///< Reserved for future use
      };

    /**
    * Specifies the type of method to call to fetch a URL.
    * The MbrCtlWindowObserver employs this method.
    */
        enum TBrCtlMethod
            {
            /**
            * Get method should be used to fetch content from a URL
            */
            EMethodGet,
            /**
            * POST method should be used to fetch content from a URL
            */
            EMethodPost
            };
     /**
     * Commands sent by the host application
     * to the Browser Control by calling the HandleDownloadCommandL function.
     */
      enum TBrCtlDownloadCmd
      {
      /**
      * Pauses the download identified
      * by the aTransId parameter of the HandleDownloadCommandL function.
      */
      EDownloadCmdPause,
      /**
      * Resumes the download identified by
      * the aTransId parameter of the HandleDownloadCommandL function.
      */
      EDownloadCmdResume,
      /**
      * Cancels the download identified by the
      * aTransId parameter of the HandleDownloadCommandL function.
      */
      EDownloadCmdCancel,
      /**
      * Notifies the Download Manager that the download is progressive.
      * This means that the file can be played while the download is in progress.
      */
      EDownloadCmdMarkAsProgressive,
      /**
      * Notifies the Download Manager that the download is not progressive.
      * This means that the file cannot be played while the download is in progress.
      */
      EDownloadCmdMarkAsNotProgressive
      };

    enum TBrCtlBitmapInfo
      {
      EBitmapThumbnail = 0,
      EBitmapFavicon
      };

    /**
    * The client commands.
    */
    enum TBrCtlClientCommands
        {
        EClientCommandLaunchFindKeyword = 0,
        EClientCommandSubscribeToFeeds,
        EClientCommandShowContextMenu,
        EClientCommandToolbarSettings,
        EClientCommandGotoWebAddress,
        EClientCommandManageBookmarks,
        EClientCommandSaveAsBookmark,
        EClientCommandZoomIn,
        EClientCommandZoomOut,
        EClientCommandGoToHompage,
        EClientCommandRotateScreen,
        EClientCommandSavePage,
        EClientCommandSwitchWindow,
        EClientCommandShowHelp,
        EClientCommandToolbarConfigure,
        EClientCommandToolbarShowKeymap,
        EClientCommandFullScreen,
        EClientCommandZoomMode
        };

    /**
    * The widget params.
    */
    enum TBrCtlWidgetParams
        {
        EWidgetIdentifier = 0,
        EWidgetBundleId,
        EWidgetBasePath,
        EWidgetPublishState,
        EWidgetNetworkState
        };

    /**
    * Orientation for rotating display
    */
    enum TBrCtlOrientation
        {
        EOrientationUndefined = 0,
        EOrientationLandscape,
        EOrientationPortrait
        };

    /**
    * How to notify javascript logs.
    */
    enum TBrCtlScriptLog
            {
            /**
            * script log output disabled
            */
            EScriptLogDisable,
            /**
            * script log output to a log file
            */
            EScriptLogToFile,
            /**
            * script log output to GUI console
            */
            EScriptLogToConsole,
            /**
            * script log output to both GUI console and file
            */
            EScriptLogToConsoleFile
            };

    enum TBrCtlFormData
        {
        EFormDataOff,
        EFormDataOnly,
        EFormDataPlusPassword
        };
    enum TCursorSettings
        {
        ENoCursor = 0,
        EDefaultCursor
        };
    
    enum TEnterKeySettings
        {
        EEnterKeyDefault = 0,
        EEnterKeyCanActivateLink
        };
    };
#endif      // BRCTLDEFS_H

// End of File
