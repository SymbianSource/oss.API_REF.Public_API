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
* Description:  Handle dialogs needed for browser operation
*
*/


#ifndef BRCTLDIALOGSPROVIDER_H
#define BRCTLDIALOGSPROVIDER_H

//  INCLUDES
#include <e32std.h>
#include <e32base.h>

/**
* Type of selection list
*/
enum TBrCtlSelectOptionType
    {
    ESelectTypeMultiple,  ///< Multiple select - Display a checkbox
    ESelectTypeSingle,    ///< Single select - Display a radio button
    ESelectTypeNone,      ///< Single select - Do not display any button
    /**
    * No buttons (single selection only)
    * OK softkey is available
    * Cancel button is not available
    */
    ESelectTypeOkOnly
    };

/**
* Defines the type of image if it cannot be recognized by the
* Symbian image conversion library.
*/

enum TBrCtlImageType
    {
    EImageTypeAny, ///< Automatically recognized by the image converter
    EImageTypeWbmp, ///< Wireless Bitmap (WBMP) image
    EImageTypeOta ///< Over The Air (OTA) image
    };


// FORWARD DECLARATIONS
class TBrCtlSelectOptionData;
class CBrCtlObjectInfo;
class TBrCtlImageCarrier;

/**
* The MBrDialogsProvider class provides functions implemented by
* the Browser Control to display dialogs, such as error notifications,
* authentication requests, and selection lists.
*
* Usage:
*
* @code
*  #include <BrCtlDialogsProvider.h>
*
*
* @see S60 Platform: Browser Control API Developer's Guide Version 2.0
* @lib BrowserEngine.lib
* @file BrCtlDialogsProvider.h
* @endcode     *
*/
class MBrCtlDialogsProvider
    {
    public: // New functions

        /**
        * Notifies the user of an error encountered during a download.
        * Some examples are: insufficient memory, unrecognized URL, and DNS not found.
        * @since 2.8
        * @param aErrCode The error that occured
        * @return void
        */
        virtual void DialogNotifyErrorL(TInt aErrCode) = 0;

        /**
        * Notifies the user of an error from the HTTP server
        * during a download. Some examples are: file not found, redirect error.
        * @since 2.8
        * @param aErrCode The error that occured
        * @param aUri The uri of the request that failed
        * @return void
        */
        virtual void DialogNotifyHttpErrorL(TInt aErrCode, const TDesC& aUri) = 0;

        /**
        * Navigates through your file system and selects a file;
        * analogous to the Browse command in Windows.
        * @since 2.8
        * @param aStartPath The initial displayed directory
        * @param aRootPath The top most directory that the user can go up to
        * @param aSelectedFileName The selected file name.
        * @return ETrue if the user selected a file
        * EFalse if the user cancelled the transaction and did not select a file.
        * @attiontion Returned on cleanup stack. Browser control will free the buffer.
        */
        virtual TBool DialogFileSelectLC(const TDesC& aStartPath,
                                         const TDesC& aRootPath,
                                         HBufC*& aSelectedFileName) = 0;

        /**
        * List selection dialog
        * @since 2.8
        * @param Title of the selection dialog. This is optional.
        * @param aBrCtlSelectOptionType The type of the list box.
        * Values: One of the following:
        * Check boxes (multiple selections allowed)
        * Radio buttons (single selection only). For example, highlight a URL listed
        *   in the session History.
        *   No buttons (single selection only)
        * No buttons (single selection only), OK softkey available
        * For example, if you are about to download a plug-in, you can choose
        * to display the content in the Web page or in a viewer application.
        * @param aOptions A list of options to display
        * @return EFalse if the user canceled the dialog selection
        * ETrue if the user selected an option.
        */
        virtual TBool DialogSelectOptionL(const TDesC& aTitle,
                                          TBrCtlSelectOptionType aBrCtlSelectOptionType,
                                          CArrayFix<TBrCtlSelectOptionData>& aOptions) = 0;

        /**
        * User Authentication dialog.
        * @since 2.8
        * @param aUrl The url requiring authentication
        * @param aRealm The realm requiring authentication
        * @param aDefaultUserName The user name that was used before for this realm and path, if any
        * @param aReturnedUserName The user name entered by the user
        * @param aReturnedPasswd The password entered by the user
        * @param aBasicAuthentication ETrue if basic authentication is required.
        * EFalse if another type of authentication is required; for example, Digest.
        * Default: EFalse
        * @return EFalse if the user cancelled the selection
        * ETrue if the user selected an option.
        @ attiontion User name and password are returned on cleanup stack.
        */
        virtual TBool DialogUserAuthenticationLC(const TDesC& aUrl,
                                                 const TDesC& aRealm,
                                                 const TDesC& aDefaultUserName,
                                                 HBufC*& aReturnedUserName,
                                                 HBufC*& aReturnedPasswd,
                                                 TBool aBasicAuthentication = EFalse) = 0;

        /**
        * Displays a message to the user.
        * For example, the message may inform the user
        * about an error encountered while processing a request.
        * @since 2.8
        * @param aMessage The message to display
        * @return void
        * @attention Softkeys are not supported.
        * The message disappears after a time out.
        */
        virtual void DialogNoteL(const TDesC& aMessage) = 0;

        /**
        * Display a note to the user with ok softkey only
        * @since 2.8
        * @param aTitle The title, could be empty
        * @param aMessage The message to display
        * @return void
        * @attention The OK softkey is supported.
        * The message displays until the user presses OK.
        */
        virtual void DialogAlertL(const TDesC& aTitle, const TDesC& aMessage) = 0;

        /**
        * Display confirmation message to the user.
        * For example, Are you sure you want to delete this?
        * @since 2.8
        * @param aTitle The title, could be empty
        * @param aMessage The message to display
        * @param aYesMessage The text to display on left softkey
        * @param aNoMessage The text to display on right softkey
        * @return EFalse if the user cancelled the selection
        * ETrue if the user selected an option.
        */
        virtual TBool DialogConfirmL(const TDesC& aTitle,
                                     const TDesC& aMessage,
                                     const TDesC& aYesMessage,
                                     const TDesC& aNoMessage) = 0;

        /**
        * Displays an input dialog to the user. Asks the user to input data.
        * @since 2.8
        * @param aTitle The title, could be empty
        * @param aMessage The message to display
        * @param aDefaultInput The default input if available
        * @param aReturnedInput The input entered by the user.
        * @return EFalse if the user cancelled the selection
        * ETrue if the user selected an option.
        * @attention Returned on the cleanup stack.
        */
        virtual TBool DialogPromptLC(const TDesC& aTitle,
                                     const TDesC& aMessage,
                                     const TDesC& aDefaultInput,
                                     HBufC*& aReturnedInput) = 0;

        /**
        * Displays information about the Netscape plug-in object and
        * requests confirmation before downloading the object.
        * @since 2.8
        * @param aBrCtlObjectInfo Information about the object to be downloaded.
        * The following information is passes as part of this object:
        * Content type
        * Size
        * Flag to indicate whether a viewer application exists for this content
        * Flag to indicate whether a Netscape plug-in exists that supports this content
        * Name of the application or Netscape plug-in with which the content can
        * be viewed on the mobile phone
        * @return EFalse if the user cancelled the selection
        * ETrue if the user selected an option.
        */
        virtual TBool DialogDownloadObjectL(CBrCtlObjectInfo* aBrCtlObjectInfo) = 0;

        /**
        * Display the images that appear in the current page
        * @since 2.8
        * @param aPageImages Array describing the images that appear in the current page.
        * The array contains the following elements for each image:
        * Image data
        * URL of the image
        * Title for the image
        * Image type
        * If the image type is WBMP or OTA, it must be specified.
        * Symbian can detect any other image type.
        * @return void
        */
        virtual void DialogDisplayPageImagesL(CArrayFixFlat<TBrCtlImageCarrier>& aPageImages) = 0;

        /**
        * Cancels the dialog displayed due to browser exit or destroyed pages.
        * @since 2.8
        * @return void
        */
        virtual void CancelAll() = 0;

        /**
        * Displays a dialog for searching on the page.
        * @since 3.0
        * @return void
        */
       virtual void DialogFindL() = 0;

    };


/**
* The TBrCtlSelectOptionData class represents a list of elements
* to display in the list box. This class is used for the List Selection Dialog.
* @code
*  #include <BrCtlDialogsProvider.h>
* @lib BrowserEngine.lib
* @since 2.8
* @file BrCtlDialogsProvider.h
* @endcode     *
*/
class TBrCtlSelectOptionData
    {
    public:
        /**
        * Default Constructor
        * @return TbrCtlSelectOptionData object
        * @since 2.8
        */
        inline TBrCtlSelectOptionData()
                {
                iText.Set(NULL, 0);
                iIsSelected = EFalse;
                iIsOptGroup = EFalse;
                iHasOnPick = EFalse;
                }

        /**
        * Constructor
        * @since 2.8
        * @param aText The text to display with this element
        * @param aIsSelected If the element is selected
        * @param aIsOptGroup If a title of option group or an element
        * @param aHasOnPick If has onPick, The dialog should close when the element is selected
        * @return TbrCtlSelectOptionData object
        */
        inline TBrCtlSelectOptionData( const TDesC& aText,
                                        TBool aIsSelected,
                                        TBool aIsOptGroup,
                                        TBool aHasOnPick )
                                                            {
                                                            iText.Set(aText);
                                                            iIsSelected = aIsSelected;
                                                            iIsOptGroup = aIsOptGroup;
                                                            iHasOnPick = aHasOnPick;
                                                            }
        /**
        * Gets the display text associated with a specified option.
        * @since 2.8
        * @return A reference to a Symbian TDesC object that
        * contains the text associated with this option.
        */
        inline const TDesC& Text() const {return iText;}
        /**
        * Indicates whether or not an option is selected.
        * @since 2.8
        * @return ETrue if the option is selected
        * EFalse if the option is not selected
        */
        inline TBool IsSelected() const {return iIsSelected;}
        /**
        * Indicates whether an option group member
        * variable is a group title or a selectable option.
        * @since 2.8
        * @return ETrue if the listed item is the title of an option group
        * EFalse if the listed item is one of the options from which to select
        */
        inline TBool IsOptGroup() const {return iIsOptGroup;}
        /**
        * Indicates whether or not the dialog closes when an option is selected.
        * @since 2.8
        * @return ETrue if the dialog closes when the element is selected.
        * This is known as having OnPick capability.
        * EFalse if the dialog does not close when the element is selected
        */
        inline TBool HasOnPick() const {return iHasOnPick;}
        /**
        * Sets the text of the option object.
        * @since 2.8
        * @param aText A reference to a TDesC object that contains the
        * text to associate with a particular option.
        * @return None
        */

        inline void SetText( TDesC& aText )             { iText.Set( aText ); }
        /**
        * Sets the selection state of an option.
        * @since 2.8
        * @param aIsSelected The state of the IsSelected member variable.
        * Value:
        * ETrue if the option is selected
        * EFalse if the option is not selected
        * @return None
        */
        inline void SetIsSelected( TBool aIsSelected )  { iIsSelected = aIsSelected; }
        /**
        * Sets the state of the option group member variable.
        * Indicates whether an option group member variable is a group title
        * or a selectable option.
        * @since 2.8
        * @param aIsOptGroup The state of the option group.
        * Value:
        * ETrue if the listed item is the title of an option group.
        * EFalse if the listed item is one of the options from which to select.
        * @return None
        */
        inline void SetIsOptGroup( TBool aIsOptGroup )  { iIsOptGroup = aIsOptGroup; }
        /**
        * Sets the state of the hasOnPick member variable.
        * Indicates whether or not the dialog closes when an option is selected.
        * @since 2.8
        * @param aHasOnPick
        * ETrue if the dialog closes when the element is selected. This
        * is known as having OnPick capability.
        * EFalse if the dialog does not close when the element is selected
        * @return None
        */
        inline void SetHasOnPick( TBool aHasOnPick )    { iHasOnPick = aHasOnPick; }

    private:    // Data
        // The text associated with the element
        TPtrC iText;
        // Flag if the element is selected
        TBool iIsSelected;
        // Flag if an element or oprion group title
        TBool iIsOptGroup;
        // Flag if the element has onPick
        TBool iHasOnPick;
    };

/**
* The CBrCtlObjectInfo class used to represent the information about the
* plugin object.
* @code
*  #include <BrCtlDialogsProvider.h>
* @lib BrowserEngine.lib
* @since 3.0
* @file BrCtlDialogsProvider.h
* @endcode     *
*/
class CBrCtlObjectInfo : public CBase
  {
  public:
        /**
        * Default Constructor
        * @since 2.8
        */
        CBrCtlObjectInfo();

        /**
        * Constructor
        * @since 3.0
        * @param aAppSupported A flag if there is a viewer app for this object
        * @param aPluginSupported A flag if there is a netscape plugin for this object
        * @param aSize The size of the object
        * @param aAppName The name of the viewer app or netscape plugin that supports this object
        * @param aFileType The content type of the object
        * @return CBrCtlObjectInfo object
        */
    CBrCtlObjectInfo(TBool aAppSupported, TBool aPluginSupported,
                         const TDesC& aSize, const TDesC& aAppName,
                         const TDesC& aFileType);
  public:
        /**
        * Sets the flag if there is a viewer app for this object
        * @since 3.0
        * @param aAppSupported ETrue if there is a viewer app for this object
        * EFalse if there is not a viewer app for this object.
        * @return None
        */
        inline void SetAppSupported(TBool aAppSupported) {iAppSupported = aAppSupported;}
        /**
        * Sets the flag if there is a netscape plugin for this object
        * @since 3.0
        * @param aPluginSupported ETrue if there is a netscape plugin for this object
        * EFalse if there is not a netscape plugin for this object.
        * @return None
        */
        inline void SetPluginSupported(TBool aPluginSupported) {iPluginSupported = aPluginSupported;}
        /**
        * Sets the size of the object
        * @since 3.0
        * @param aSize Symbian descriptor containing the size of the object
        * @return None
        */
        inline void SetSize(const TDesC& aSize) {iSize.Set(aSize);}
        /**
        * Sets the name of the viewer app or netscape plugin that supports this object
        * @since 3.0
        * @param aAppName  Symbian descriptor containing the name of
        * the viewer app or netscape plugin that supports this object.
        * @return None
        */
    inline void SetAppName(const TDesC& aAppName) {iAppName.Set(aAppName);}
        /**
        * Sets the content type of the object
        * @since 3.0
        * @param aFileType Symbian descriptor holding content type of the object
        * @return None
        */
    inline void SetFileType(const TDesC& aFileType) {iFileType.Set(aFileType);}
        /**
        * Tells if there is a viewer app for this object
        * @since 3.0
        * @param None
        * @return  ETrue if there is a viewer app for this object
        * EFalse if there is not a viewer app for this object.
        */
        inline TBool AppSupported() {return iAppSupported;}
        /**
        * Tells if there is a netscape plugin for this object
        * @since 3.0
        * @param None
        * @return ETrue if there is a netscape plugin for this object
        * EFalse if there is not a netscape plugin for this object.
        */
        inline TBool PluginSupported() {return iPluginSupported;}
        /**
        * Gets the size of the object
        * @since 3.0
        * @param None
        * @return Symbian descriptor containing the size of the object
        */
        inline const TDesC& Size() const {return iSize;}
        /**
        * Gets the name of the viewer app or netscape plugin that supports this object
        * @since 3.0
        * @param None
        * @return Symbian descriptor containing the name of
        * the viewer app or netscape plugin that supports this object.
        */
    inline const TDesC& AppName() const {return iAppName;}
        /**
        * Gets the content type of the object
        * @since 3.0
        * @param None
        * @return Symbian descriptor holding content type of the object
        */
    inline const TDesC& FileType() const {return iFileType;}
  private:
    // A flag if there is a viewer app for this object
        TBool iAppSupported;
        // A flag if there is a Netscape plugin for this object
    TBool iPluginSupported;
        // The size of the object
    TPtrC iSize;
        // The name of the viewer app or Netscape plugin
    TPtrC iAppName;
        // The content type of the object
    TPtrC iFileType;
  };

/**
* TheTBrCtlImageCarrier class used to give the information about the
* image.
* @code
*  #include <BrCtlDialogsProvider.h>
* @lib BrowserEngine.lib
* @since 2.8
* @file BrCtlDialogsProvider.h
* @endcode     *
*/
class TBrCtlImageCarrier
    {
    public:
        /**
        * Constructor
        * @since 2.8
        * @param aRawData The image data
        * @param aUrl The url of the image
        * @param aAltText The alt text of the image
        * @param aImageType The type of the image
        */
        TBrCtlImageCarrier(const TDesC8& aRawData, const TDesC& aUrl,
            const TDesC& aAltText, TBrCtlImageType aImageType, const TDesC& aContentType ) :
            iRawData( aRawData ),
            iUrl( aUrl ),
            iAltText( aAltText ),
            iImageType(aImageType),
      iContentType(aContentType)
            {
            }
        /**
        * Provides the image data
        * @since 3.0
        * @param None
        * @return Symbian descriptor containing image data
        */
        inline const TDesC8& RawData() const {return iRawData;}
        /**
        * Provides the url of the image
        * @since 3.0
        * @param None
        * @return Symbian descriptor containing url of the image
        */
        inline const TDesC& Url() const {return iUrl;}
        /**
        * Provides the alt text of the image
        * @since 3.0
        * @param None
        * @return Symbian descriptor containing alt text of the image
        */
        inline const TDesC& AltText() const {return iAltText;}
        /**
        * Provides the type of the image
        * @since 3.0
        * @param None
        * @return Symbian descriptor containing the type of the image
        */
        inline TBrCtlImageType ImageType() const {return iImageType;}
        /**
        * Provides the content type of the image
        * @since 3.1
        * @param None
        * @return Symbian descriptor containing content type of the image
        */
        inline const TDesC& ContentType() const {return iContentType;}
    private:
        TPtrC8 iRawData;
        TPtrC iUrl;
        TPtrC iAltText;
        TBrCtlImageType iImageType;
    TPtrC iContentType;
    };


#endif      // BRCTLDIALOGSPROVIDER_H

// End of File
