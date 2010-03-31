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
* Description:  Definition of the Browser Control API
*
*/


#ifndef BRCTLINTERFACE_H
#define BRCTLINTERFACE_H

//  INCLUDES
#include <../bidi.h>
#include <e32std.h>
#include <e32base.h>
#include <coecntrl.h>
#include <eikmenup.h>
#include <ssl.h>

#include <brctldialogsprovider.h>
#include <brctllayoutobserver.h>
#include <brctllinkresolver.h>
#include <brctlsoftkeysobserver.h>
#include <brctlspecialloadobserver.h>
#include <brctlwindowobserver.h>
#include <brctldownloadobserver.h>
#include <brctldefs.h>

// DATA TYPES

// FORWARD DECLARATIONS
class MBrCtlDataLoadSupplier;
class MBrCtlDataLoadConsumer;
class MBrCtlLoadEventObserver;
class MBrCtlDialogsProvider;
class TBrCtlWmlServiceOption;
class TBrCtlSubscribeTo;
class MBrCtlStateChangeObserver;
class MBrCtlCommandObserver;
class MWidgetCallback;
class MWidgetExtension;
class CBrCtlInterface;
class CPluginInfo;
class TBrCtlImageCarrier;

/**
* Creates the browser control.
*
* @param aParent                      Parent window of the browser control
* @param aRect                        Bounding rectangle for the browser control
* @param aBrCtlCapabilities           Desired capabilities of the browser control.
* For example, displaying scroll bars, allowing network access for HTTP requests.
* @see For a complete list of capability options, see TBrCtlCapabilities
* @param aCommandIdBase               Base values for Command IDs for Browser Control.
* These are added to ensure that each Command ID is unique; Browser Control command IDs must be different from the host application command IDs.
* @see For more information, see TBrCtlCommandId
* @param aBrCtlSoftkeysObserver       Softkeys observer.
* Default: the host application does not update the softkeys.
* @see For more information, see MBrCtlSoftkeysObserver class
* @param aBrCtlLinkResolver           Link Resolver. Must be provided if ECapabilityClient
* ResolveEmbeddedURL or ECapabilityClientNotifyURL is set.
* @see For more information, see MBrCtlLinkResolver class.
* @param aBrCtlSpecialLoadObserver    Special Load Observer.
* @see MBrCtlSpecialLoadObserver class for more details of special load observer.
* @param aBrCtlLayoutObserver         Layout Observer.
* Default:
* Non-markup pages are not handled by the browser.
* Non-HTTP(S) schemes are not handled by the browser.
* Connection is created by the Proxy Filter.
* @see For more information, see MBrCtlLayoutObserver class
* @param aBrCtlDialogsProvider        Dialogs Provider.
* @see For more information, see MBrCtlDialogsProvider class
* @param aBrCtlWindowObserver         Window Observer.
* @see For more information, see MBrCtlWindowObserver class
* @param aBrCtlDownloadObserver       Downlaod observer
* @see For more information,  MBrCtlDownloadObserver class
* @return a pointer to CBrCtlInterface class or NULL if this function fails.
*/
IMPORT_C CBrCtlInterface* CreateBrowserControlL(CCoeControl* aParent, TRect aRect,
    TUint aBrCtlCapabilities, TUint aCommandIdBase = TBrCtlDefs::ECommandIdBase,
    MBrCtlSoftkeysObserver* aBrCtlSoftkeysObserver = NULL,
    MBrCtlLinkResolver* aBrCtlLinkResolver = NULL,
    MBrCtlSpecialLoadObserver* aBrCtlSpecialLoadObserver = NULL,
    MBrCtlLayoutObserver* aBrCtlLayoutObserver = NULL,
    MBrCtlDialogsProvider* aBrCtlDialogsProvider = NULL,
    MBrCtlWindowObserver* aBrCtlWindowObserver = NULL,
  MBrCtlDownloadObserver* aBrCtlDownloadObserver = NULL );

/**
* The CBrCtlInterface class is the base class of the Browser Control API.
* All clients of browser control must use this class. The functions defined
* in the CBrCtlInterface class implement basic Browser Control functionality.
* You can customize the Browser Control to extend its functionality by
* implementing additional interface classes in the host application. Examples
* of such classes are MBrCtlDataLoadSupplier, MBrCtlDialogsProvider,
* MBrCtlDialogsProvider etc.
*
* Usage:
*
* @code
*  #include <brctlinterface.h>
*  // Interface that provides dialogs used by the Browser Control.
*  #include <brctldialogsprovider.h>
*  // Interface used to receive scrolling events.
*  #include <brctllayoutobserver.h>
*  //Interface that provides a callback mechanism for receiving the
*  //content of an embedded link or the content of a user-initiated
*  //load request.
*  #include <brctllinkresolver.h>
*  //Interface that handles requests to change the softkeys.
*  #include <brctlsoftkeysobserver.h>
*  //Interface that handles special load needs.
*  #include <brctlspecialloadobserver.h>
*  //Reserved for future use.
*  #include <brctlwindowobserver.h>
*  //Interface that passes download events from the
*  //Download Manager through the Browser Control to the
*  //host application.
*  #include <brctldownloadobserver.h>
*  Enum Definition of the Browser Control API.
*  #include <brctldefs.h>
*
*
*   The following types of things you can do with the Browser Control API.
*
* Creating a basic Browser Control
* Creating a Browser Control with observer interfaces
* Loading content
* Passing content incrementally
* Receiving load progress events
* Handling special load requests
* Customizing dialogs
* Specifying the softkeys
* Resolving links
* Customizing scroll bars
* Receiving change-of-state events
*
* @see S60 Platform: Browser Control API Developer's Guide Version 2.0
* @lib BrowserEngine.lib
* @since 2.8
* @file brctlinterface.h
* @endcode     *
*/
class CBrCtlInterface : public CCoeControl
    {
    public:  // Constructors and destructor

        /**
        * Destructor.
        */
      inline virtual ~CBrCtlInterface() {}

    public: // New functions

        /**
        * Passes a command to the Browser Control..
        * @since 2.8
        * @param aCommand The command that the Browser Control should process
        * @return void
        * @see TBrCtlCommands, For a complete list of commands,
        */
        IMPORT_C virtual void HandleCommandL(TInt aCommand) = 0;

        /**
        * Return the display size that would be needed to see all the content
        * @since 2.8
        * @return The display size that would be needed to see all the content
        */
        IMPORT_C virtual TSize ContentSize() = 0;

        /**
        * Update a Browser Control setting
        * @since 2.8
        * @param aSetting The setting to update
        * @param aValue The new value of the setting
        * @leave KErrArgument if the value of aSetting is out of range.
        * @return void
        */
        IMPORT_C virtual void SetBrowserSettingL(TUint aSetting, TUint aValue) = 0;

        /**
        * Get a setting from the Browser Control
        * @since 2.8
        * @param aSetting The setting to get
        * @leave KErrArgument if the value of aSetting is out of range.
        * @return The value of the setting
        */
        IMPORT_C virtual TUint BrowserSettingL(TUint aSetting) = 0;

        /**
        * Request the Browser Control to display the content of a buffer
        * @since 2.8
        * @param aUrl A url that refers to the data. If a url scheme is used, it must be "data:"
        * @param aData The content to display. Browser Control does not take ownership
        * @param aDataType The data type of the data
        * @param aCharsetUid The UID of the character converter of the content's charset 0 assumed Latin-1
        * @return void
        * @attention If you use this function, the Browser Control does not keep
        * track of the history. If the data is not markup, Browser Control uses
        * the Special Load Observer to pass the content back to the Host Application.
        * The Special Load Observer uses the Document Handler to send the content
        * to the proper application.
        */
        IMPORT_C virtual void LoadDataL(const TDesC& aUrl,
                                const TDesC8& aData,
                                const TDataType& aDataType,
                                TUid aCharsetUid) = 0;

        /**
        * Request the Browser Control to display content incrementaly
        * @since 2.8
        * @param aUrl A url that refers to the data. If a url scheme is used, it must be "data:"
        * @param aDataType The data type of the data
        * @param aCharsetUid The UID of the character converter of the content's charset 0 assumed Latin-1
        * @param aContentLength The length of the content.
        * @param aBrCtlDataLoadSupplier A callback interface to stop passing data if an error occured in the Browser Control
        * @param aBrCtlDataLoadConsumer A callback interface returned by the browser. Data should be passed to that interface
        * @return void
        * @attension If you use this function, the Browser Control does not keep
        * track of the history.If the content type of the data is not markup, Browser
        * Control uses the Special Load Observer to pass the content back to the Host
        * Application. The Special Load Observer uses the Document Handler to send
        * the content to the proper application.
        */
        // The url scheme must be "data:" The url is needed as reference to this load request
        IMPORT_C virtual void InitLoadDataL(const TDesC& aUrl,
                                    const TDataType& aDataType,
                                    TUid aCharsetUid,
                                    TUint aContentLength,
                                    MBrCtlDataLoadSupplier* aBrCtlDataLoadSupplier,
                                    MBrCtlDataLoadConsumer** aBrCtlDataLoadConsumer) = 0;

        /**
        * Request the Browser Control to load a url
        * @since 2.8
        * @param aUrl The url to load
        * @param aApId The Access Point Id to use
        * @param aCacheMode The cache mode to use.
        * Values: One of the following:
        *            ECacheModeNormal
        *            ECacheModeHistory
        *            ECacheModeNoCache
        *            ECacheModeOnlyCache
        * @see For a description of each of these values, see TBrCtlCacheMode
        * @return void
        */
        IMPORT_C virtual void LoadUrlL( const TDesC& aUrl,
                                        TInt aApId = -1,
                                        TBrCtlDefs::TBrCtlCacheMode aBrCtlCacheMode = TBrCtlDefs::ECacheModeNormal) = 0;

        /**
        * Request the Browser Control to load and display a file from the file system
        * @since 2.8
        * @param aFileName The name of the file
        * @return void
        */
        IMPORT_C virtual void LoadFileL(const TDesC& aFileName) = 0;

        /**
        * Request the Browser Control to load and display a file from the file system
        * @since 2.8
        * @param aFileHandle The handle of the file
        * @return void
        */
        IMPORT_C virtual void LoadFileL(RFile& aFileHandle) = 0;

        /*                                        
        * Return the WML Options for the current page
        * @since 2.8
        * @param
        * @return The WML Options for the current page
        */
        IMPORT_C virtual RPointerArray<TBrCtlWmlServiceOption>* WMLOptionMenuItemsL()  = 0;

        /**
        * Request the Browser Control to add its own options to the option menu
        * @since 2.8
        * @param aMenuPane Handle of the menu that will contain the options
        * @param aResourceId The resource ID of the menu
        * @param aAfter WML options should be added after that index
        * @return void
        */
        IMPORT_C virtual void AddOptionMenuItemsL(CEikMenuPane& aMenuPane, TInt aResourceId, TInt aAfter=-1 ) = 0;

        /**
        * Request the Browser Control to clear the cache
        * @since 2.8
        * @return The number of bytes that were freed from cache.
        */
        IMPORT_C virtual TUint ClearCache() = 0;

        /**
        * Ask the Browser Control if a URL is in cache
        * @since 2.8
        * @param aUrl The Url
        * @return ETrue, if a specific Url is in cache
        * EFalse if the URL is not in the cache
        */
        IMPORT_C virtual TBool IsUrlInCache(TDesC& aUrl) = 0;

        /**
        * Ask the Browser Control to clear a URL from the cache
        * @since 2.8
        * @param aUrl The Url
        * @return KErrNone if the URL is cleared from the cache
        * Error message is the URL has not been cleared.
        */
        IMPORT_C virtual TInt ClearItemInCache(TDesC& aUrl) = 0;

        /**
        * Request the Browser Control to return info about the page. The info is returned on the Cleanup Stack.
        * @since 2.8
        * @param aBrCtlPageInfo The type of requested info
        * @return A descriptor containing the requested page info
        * @attention The information is returned on the Cleanup stack.
        */
        IMPORT_C virtual HBufC* PageInfoLC(TBrCtlDefs::TBrCtlPageInfo aBrCtlPageInfo ) = 0;

        /**
        * From CBrCtlInterface Query the Browser Control
        * if there is a previous or next (depending on aDirection) element in history stack
        * @param aDirection
        * ENavigationBack if you wish to query whether there is a previous element
        * in the history stack.
        * ENavigationForward if you wish to query whether there is a subsequent
        * element in the history stack.
        * @since 2.8
        * @return ETrue if can go aDirection, EFalse otherwise
        */
        IMPORT_C virtual TBool NavigationAvailable( TBrCtlDefs::TBrCtlNavigationDirection aDirection ) = 0;

        /**
        * Request the Browser Control to save the current content to a file
        * @since 2.8
        * @param aFileName The name of the file to use for saving the content
        * @return The number of bytes in the saved file
        */
        IMPORT_C virtual TUint16 SaveToFileL(const TDesC& aFileName) = 0;

        /**
        * Request the Browser Control to pass the server's certificate info for the current page
        * @since 2.8
        * @return Certificate info of the server of the current page
        */
        IMPORT_C virtual const TCertInfo* CertInfo() = 0;

        /**
        * Request the Browser Control to register for load events
        * @since 2.8
        * @param aBrCtlLoadEventObserver A load events observer to add
        * @return void
        * @attenstion Call this function immediately after creating the Browser Control.
        * For multiple registrations, the host application may call this function more than once.
        * Observers must unregister before deleting the Browser Control.
        */
        IMPORT_C virtual void AddLoadEventObserverL(MBrCtlLoadEventObserver* aBrCtlLoadEventObserver) = 0;

        /**
        * Request the Browser Control to unregister for load events
        * @since 2.8
        * @param aBrCtlLoadEventObserver A load events observer to remove
        * @return void
        * @attenstion Call this function for each Load Observer that was previously registered.


        */
        IMPORT_C virtual void RemoveLoadEventObserver(MBrCtlLoadEventObserver* aBrCtlLoadEventObserver) = 0;

        /**
        * Return the number of images in the current page
        * @since 2.8
        * @param
        * @return The number of images in the current page
        */
        IMPORT_C virtual TInt ImageCountL() = 0;

        /**
        * Returns the focused element
        * @since 2.8
        * @return The type of the focused element
        * @attension The host application may need to perform special processing,
        * such as updating the softkeys, when a specific element has the focus.
        */
        IMPORT_C virtual TBrCtlDefs::TBrCtlElementType FocusedElementType() = 0;

        /**
        * Register an observer for state changes
        * @since 2.8
        * @param aBrCtlStateChangeObserver The observer to register
        * @return void
        * @attenstion The Observer must unregister before deleting the Browser Control.
        */
        IMPORT_C virtual void AddStateChangeObserverL(MBrCtlStateChangeObserver* aBrCtlStateChangeObserver) = 0;

        /**
        * Unregister an observer for state changes
        * @since 2.8
        * @param The observer to unregister
        * @return void
        */
        IMPORT_C virtual void RemoveStateChangeObserver(MBrCtlStateChangeObserver* aBrCtlStateChangeObserver) = 0;

        /**
        * Request the Browser Control to return info about the Browser Control version. The info is returned on the Cleanup Stack.
        * @since 2.8
        * @param aVersionInfo The type of requested info
        * @return A descriptor containing the requested page info
        * @attention The information is returned on the Cleanup Stack.
        */
        IMPORT_C virtual HBufC* VersionInfoLC(TBrCtlDefs::TBrCtlVersionInfo aVersionInfo) = 0;

        /**
        * Pass a list of content types to the Browser Control.
        * These content types will not be using the download manager.
        * The list must be separated by ';' e.g. "text/html;text/wml"
        * @since 2.8
        * @param aContentTypes The content types that should not use Download Manager
        * @return void
        * @deprecated This function is deprecated. Use the
        * EParamsSelfDownloadableTypes parameter of the SetParamL function instead.
        */
        IMPORT_C virtual void SetSelfDownloadContentTypesL(TDesC& aContentTypes) = 0;

        /**
        * Update a Browser Control parameter. consequent calls with the
        * same aParam will replace the value, and not append to it.
        * @since 2.8
        * @param aParam The parameter to update
        * @param aValue The new value of the parameter
        *        EParamsSelfDownoadableTypes: Pass a list of content types to the
        *        Browser Control. These content types will not be using the
        *        download manager. The list must be separated by ';' e.g.
        *        "text/html;text/wml"
        *
        *        EParamsRequestHeaders: Pass a list of headers that the
        *        Browser Control. These headers will be added to each request.
        *        The list must be separated by '\r'. The header name and value must be
        *        separated by ':'  e.g.
        *        "x-myheader: myvalue\rx-myotherheader: myothervalue"
        * @return void
        */
        IMPORT_C virtual void SetParamL(TBrCtlDefs::TBrCtlParams aParam, const TDesC& aValue) = 0;

        /**
        * Request the Browser Control to load a saved page.
        * @since 3.0
        * @param aUid a unique identifier for the saved page
        * @param aSavedPageBuffer buffer which contains the content of the saved page
        * @return void
        */
        IMPORT_C virtual void LoadSavedPageL(const TDesC& aUid, TDesC& aSavedPageBuffer) = 0;

        /**
        * Return the zoom levels index
        * @since 3.0
        * @return The zoom levels array.
        */
        IMPORT_C virtual RArray<TUint>* ZoomLevels() const = 0;

       /**
        * Perform the incremental find operation
        * @param aKeyword String to be find.
        * @since 3.0
        * @return TBrCtlFindResponse
        */
        IMPORT_C virtual int FindKeyword( const TDesC& aKeyword ) = 0;

        /**
        * Continue the incremental find operation
        * @since 3.0
        * @param aFowardDirection TRUE if search is in forword direction.
        * For backword direction, it is FALSE.
        * @return TBrCtlFindResponse
        * @attention Method that is called when the user searches for the next
        * keyword in the doc.
        *
        */
        IMPORT_C virtual TBrCtlDefs::TBrCtlFindResponse FindKeywordAgain( TBool aFowardDirection ) = 0;

        /**
        * Return information about the linked feeds in the current page - used to
        * build a "Subscribe to" submenu.
        * @since 3.0
        * @return Information about the linked feeds in the current page.  The
        *         caller adopts the result.
        */
        IMPORT_C virtual const RPointerArray<TBrCtlSubscribeTo>& SubscribeToMenuItemsL() = 0;



    public: // Functions from base classes

        // Functions from CCoeControl

        /**
        * From CCoeControl Return the minimum size the Browser Control can use
        * @since 2.8
        * @return The minimum size that the Browser Control can use.
        * @attention This function is inherited from the Symbian CCoeControl class.
        */
        IMPORT_C virtual TSize MinimumSize() = 0;

        /**
        * From CCoeControl Pass key events to the Browser Control
        * @since 2.8
        * @param aKeyEvent The key event
        * @param aType The key code
        * @return If the Browser Control consumed the key event or not
        * @attention This function is inherited from the Symbian CCoeControl class.
        */
        IMPORT_C virtual TKeyResponse OfferKeyEventL(const TKeyEvent& aKeyEvent, TEventCode aType) = 0;

        /**
        * From CCoeControl Sets that the Browser Control has keyboard focus.
        * @since 2.8
        * @param aFocus If the Browser Control gets or loses focus
        * @param ENoDrawNow If the Browser Control should redraw itself as result of focus change
        * @return void
        * @attention This function is inherited from the Symbian CCoeControl class.
        */
        IMPORT_C virtual void SetFocus(TBool aFocus, TDrawNow aDrawNow = ENoDrawNow) = 0;

        /*
        * This method calls to download manager in order to display query "Cancel
        * outstanding downloads?" and cancel if it requested by user
        * @param none
        * @return ETrue if it is OK to exit; EFalse - if it is not OK to exit
        */
        IMPORT_C virtual TBool OkToExit() = 0;


        /**
        * This method calls to download manager in order to send the commands (EDownloadCmdPause,DownloadCmdResume,
    * EDownloadCmdCancel, EDownloadCmdMarkAsProgressive, EDownloadCmdMarkAsNotProgressive )
        * @param aCommand The command that the Browser Control should process
        * @param aTransId The transaction Id associated with this command
        * @return void
        */
    IMPORT_C virtual void HandleDownloadCommandL(TUint16 aTransId, TBrCtlDefs::TBrCtlDownloadCmd aCommand) = 0;

     /**
        * Request icon for the given url
        * @since 3.1
        * @param aUrl url to a favicon or a page
        * @param aBitmapInfo info on whether to retun a favicon or a page icon
        * @return favion icon or page icon
        */
    IMPORT_C virtual CGulIcon* GetBitmapData(const TDesC& aUrl, TBrCtlDefs::TBrCtlBitmapInfo aBitmapInfo) = 0;

        /**
        * Register a client command interface for the browser engine
        * @since 3.1
        * @param The observer to register
        * @return void
        */
        IMPORT_C virtual void AddCommandObserverL(MBrCtlCommandObserver* aBrCtlCommandObserver) = 0;

        /**
        * Unregister a client command interface for the browser engine
        * @since 3.1
        * @param The observer to unregister
        * @return void
        */
        IMPORT_C virtual void RemoveCommandObserver(MBrCtlCommandObserver* aBrCtlCommandObserver) = 0;

        /**
        * Unregister a client command interface for the browser engine
        * @since 3.1
        * @param The observer to unregister
        * @return void
        */
        IMPORT_C virtual MWidgetExtension* CreateWidgetExtensionL(MWidgetCallback& aWidgetCallback) = 0;

        /**
        * Get information about the focused image. The function leaves if the focus is not on an image
        * @since 3.2
        * @param
        * @return The requested information
        */
        IMPORT_C virtual TBrCtlImageCarrier* FocusedImageLC() = 0;

        /**
        * Requests the Browser Control to POST to a URL
        * @since 5.0
        * @param aUrl URL to which the Browser Control sends the POST request
        * @param aContentType Content type of the data to be posted
        * @param aPostData Data to be posted
        * @param aBoundary Boundary for form-data or multi-part content. 
        * @param aReserved For future use only
        * @return void
        */        
        IMPORT_C virtual void PostUrlL (const TDesC& aUrl, 
                                        const TDesC8& aContentType, 
                                        const TDesC8& aPostData, 
                                        const TDesC8* aBoundary, 
                                        TAny* aReserved) = 0;
        /**
        * Requests the Browser Control for offscreen bitmap
        * @since 5.0
        * @ fills offscreen bitmap.The bitmap memory has to be set and freed by the api calling that function.
        * @return void. 
        */
        IMPORT_C virtual void TakeSnapshotL(CFbsBitmap& snapshot) = 0; 
    };


/**
* The MBrCtlDataLoadSupplier class is a callback interface that
* provides the Browser Control with the ability to display content incrementally.
* It does this by providing a means for the Browser Control to cancel the load operation
* if an error occurs.
* For example, if the Browser Control runs out of memory during the
* load operation, it can cancel that operation by means of this interface.
*
* Usage:
*
* @code
*  #include <brctlinterface.h>
* @see S60 Platform: Browser Control API Developer's Guide Version 2.0
* @lib BrowserEngine.lib
* @since 2.8
* @file brctlinterface.h
* @endcode     *
*/
class MBrCtlDataLoadSupplier
    {
    public: // New functions
        /**
        * Cancel the load operation
        * @since 2.8
        * @return void
        */
    virtual void CancelLoad() = 0;
    };



/**
* The MBrCtlDataLoadConsumer class is a callback interface that provides
* the Browser Control with the ability to receive content incrementally.
*
* @code
*  #include <brctlinterface.h>
* @see S60 Platform: Browser Control API Developer's Guide Version 2.0
* @lib BrowserEngine.lib
* @since 2.8
* @file brctlinterface.h
* @endcode     *
*/
class MBrCtlDataLoadConsumer
    {
    public: // New functions
        /**
        * Pass the next data chunk
        * @since 2.8
        * @param aData The data chunk to process
        * @return void
        */
        virtual void HandleNextDataChunk(const TDesC8& aData) = 0;

        /**
        * Inform the Browser Control about completion of data load
        * @since 2.8
        * @return void
        */
        virtual void HandleLoadComplete() = 0;

        /**
        * Inform the Browser Control that an error occured
        * if HandleError() is called, then LoadComplete() is infered.
        * @since 2.8
        * @param aError The error code
        * @return void
        */
        virtual void HandleError(TInt aError) = 0;
    };

/**
* The MBrCtlLoadEventObserver interface receives load progress events.
* The host application can implement this interface.
*
* @code
*  #include <brctlinterface.h>
* @see S60 Platform: Browser Control API Developer's Guide Version 2.0
* @lib BrowserEngine.lib
* @since 2.8
* @file brctlinterface.h
* @endcode     *
*/
class MBrCtlLoadEventObserver
    {
    public: // New functions
        /**
        * A load events notification
        * @since 2.8
        * @param aLoadEvent The load event
        * @param aSize Size depends on the event
        * @param aTransactionId The transaction id of the transaction that had this event
        * @return void
        */
        virtual void HandleBrowserLoadEventL(TBrCtlDefs::TBrCtlLoadEvent aLoadEvent, TUint aSize, TUint16 aTransactionId) = 0;
    };

/**
* The TBrCtlWmlServiceOption class wraps information about the WML DO elements.
* For more information about the DO tag, see http://www.w3schools.com/wap/tag_do.asp.
* @code
*  #include <brctlinterface.h>
* @lib BrowserEngine.lib
* @since 2.8
* @file brctlinterface.h
* @endcode     *
*/
class TBrCtlWmlServiceOption
    {
    public:
        /**
        * Constructor
        * @since 2.8
        * @param aText The text to display in the WML service options
        * @param aElemID The element Id to use when the user selects this command
        * @param aActualElemID Internal to the Browser Control. The host
        * application should not modify this parameter.
        */
        TBrCtlWmlServiceOption(HBufC* aText, TUint aElemID, TUint aActualElemID);
        /**
        * Displays the text for the WML service options
        * @since 2.8
        * @return Text to display for the WML service options
        */
        inline const TDesC& Text() {return *iText;}
        /**
        * Gets the command ID to use when the user selects this command
        * @since 2.8
        * @return Element ID employed when the user selects this command
        */
        inline TUint ElemID(){return iElemID;}
        /**
        * Gets the actual element ID defined in the WML page.
        * @since 2.8
        * @return Actual element ID
        * @attention This parameter is internal to the Browser Control.
        * The host application should not modify this parameter.
        */
        inline TUint ActualElemID(){return iActualElemID;}

        /**
        * Destructor.
        */
        ~TBrCtlWmlServiceOption();

    private:    // Data
        /**
        * Default constructor
        * @since 2.8
        */
        TBrCtlWmlServiceOption() {};

        // The text to display in the WML service options
        HBufC* iText;
        // The element Id to use when the user selects this command
        TUint iElemID;
        // The actual element Id
        TUint iActualElemID;
    };

/**
* The TBrCtlSubscribeTo class provides information of Subscribe to items.
* @code
*  #include <brctlinterface.h>
* @lib BrowserEngine.lib
* @since 2.8
* @file brctlinterface.h
* @endcode     *
*/
class TBrCtlSubscribeTo
    {
    public:
        /**
        * Constructor
        * @since 3.0
        * @param aText The text to display in the subscribe to option.  aText
        *              is adopted.
        * @param aCommandID The menu command Id to use when the user selects it.
        */
        TBrCtlSubscribeTo(const TPtrC& aTitle, const TPtrC& aUrl, TUint aCommandID);

        /**
        * Returns the title.
        * @since 3.0
        * @return The title.
        */
        inline const TPtrC& Title() {return iTitle;}

        /**
        * Returns the url.
        * @since 3.0
        * @return The url.
        */
        inline const TPtrC& Url() {return iUrl;}

        /**
        * Returns the command.
        * @since 3.0
        * @return The command.
        */
        inline TUint CommandID() {return iCommandID;}

    private:
        /**
        * Default constructor
        * @since 3.0
        */
        TBrCtlSubscribeTo();

    private:    // Data
        const TPtrC iTitle;
        const TPtrC iUrl;

        TUint iCommandID;
    };

/**
* The MBrCtlStateChangeObserver class receives state-changed events.
* At the present time, there is only one state-changed event.
* This event is generated when the browser switches to and from
* the Image Map view. In Image Map view, only an image map is displayed,
* which enables the user to navigate. The host application can
* implement this interface in order to find out when the view
* changes to and from the Image Map view.
* @code
*  #include <brctlinterface.h>
* @lib BrowserEngine.lib
* @since 2.8
* @file brctlinterface.h
* @endcode     *
*/
class MBrCtlStateChangeObserver
    {
    public:
        /**
        * Notifies the Browser Control of a state-changed event.
        * @param aState Indicates whether or not the browser is in Image Map view.
        * Value:EStateImageMapView
        * @param aValue Indicates the state being changed.
        * Values:
        * ETrue indicates entering Image Map view
        * EFalse indicates exiting Image Map view
        * @since 2.8
        * @return void
        */
        virtual void StateChanged(TBrCtlDefs::TBrCtlState aState, TInt aValue) = 0;
    };

// CLASS DECLARATION
/**
*  This class provides a mechanism for the browser engine to pass commands to the client
*
*  @lib BrowserEngine.lib
*  @since 3.1
*/
class MBrCtlCommandObserver
    {
    public: // New functions
        /**
        * Method to call client to execute commands
        * @since 3.1
        * @param A callback command
        * @param Array of attribute names
        * @param Array of attribute values
        * @return void
        */
        virtual void HandleCommandL(TBrCtlDefs::TBrCtlClientCommands aCommand, const CArrayFix<TPtrC>& aAttributesNames,
                                     const CArrayFix<TPtrC>& aAttributeValues) = 0;
    };

// CLASS DECLARATION
/**
*  This class provides a mechanism for the browser engine to interact with the widget host application
*
*  @lib BrowserEngine.lib
*  @since 3.2
*/
class MWidgetCallback
    {
    public:
        /**
        * Navigates through your file system and selects a file of specific mime type;
        * analogous to the Browse command in Windows.
        * @since 3.2
        * @param aSelectedFileName The selected file name.
        * @param aMimeType The accepted mime type.
        * @return ETrue if the user selected a file
        * EFalse if the user cancelled the transaction and did not select a file.
        * @attiontion Returned on cleanup stack. Browser control will free the buffer.
        */
        virtual TBool DialogMimeFileSelectLC(HBufC*& aSelectedFileName,
                                 const TDesC& aMimeType) = 0;

       /**
        * Called to show or hide softkeys
        * @since 3.1
        * @param aVisible ETrue to show softkeys, EFalse when full screen is needed
        */
        virtual void SetSoftkeysVisible(TBool aVisible) = 0;

        /**
        * Called to change the display orientation to landscape
        * @since 3.1
        */
        virtual void SetDisplayMode(TBrCtlDefs::TBrCtlOrientation aOrientation) = 0;

        //Reserved for future use
        virtual TInt Reserved_1(TAny*& a0, TAny* a1, TAny* a2) = 0;
        virtual TInt Reserved_2(TAny*& a0, TAny* a1, TAny* a2) = 0;
        virtual TInt Reserved_3(TAny*& a0, TAny* a1, TAny* a2) = 0;
        virtual TInt Reserved_4(TAny*& a0, TAny* a1, TAny* a2) = 0;
        virtual TInt Reserved_5(TAny*& a0, TAny* a1, TAny* a2) = 0;
        virtual TInt Reserved_6(TAny*& a0, TAny* a1, TAny* a2) = 0;
        virtual TInt Reserved_7(TAny*& a0, TAny* a1, TAny* a2) = 0;
        virtual TInt Reserved_8(TAny*& a0, TAny* a1, TAny* a2) = 0;
        virtual TInt Reserved_9(TAny*& a0, TAny* a1, TAny* a2) = 0;
        virtual TInt Reserved_10(TAny*& a0, TAny* a1, TAny* a2) = 0;
    };

// CLASS DECLARATION
/**
*  This class provides an extension mechanism for the widget host app to interact with the browser engine
*  This class includes the Widget specific extension needed in the browser engine
*  @lib BrowserEngine.lib
*  @since 3.2
*/
class MWidgetExtension
    {
    public: // New functions
        /**
        * Method to set parameters in the browser engine
        * @since 3.2
        * @param The widget identifier
        * @param The value for the paramater
        * @return void
        */
        virtual void SetParamL(TBrCtlDefs::TBrCtlWidgetParams aParam, const TDesC& aValue) = 0;

        /**
        * Method to set parameters in the browser engine
        * @since 3.2
        * @param The widget parameter aParam
        * @param The value for the paramater
        * @return void
        */
        virtual void SetParamL(TBrCtlDefs::TBrCtlWidgetParams aParam, TUint aValue) = 0;

        /**
        * Method to invoke callback function for right soft key
        * @since 3.2
        * @param none
        * @return ETrue if there is a rightsoftkey callback, else EFalse
        */
        virtual TBool HandleCommandL( TInt aCommandId ) = 0;

    };
#endif      // BRCTLINTERFACE_H

// End of File
