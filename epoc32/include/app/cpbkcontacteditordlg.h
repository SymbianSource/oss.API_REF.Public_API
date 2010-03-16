/*
* Copyright (c) 2002 Nokia Corporation and/or its subsidiary(-ies).
* All rights reserved.
* This component and the accompanying materials are made available
* under the terms of the License "Symbian Foundation License v1.0" to Symbian Foundation members and "Symbian Foundation End User License Agreement v1.0" to non-members
* which accompanies this distribution, and is available
* at the URL "http://www.symbianfoundation.org/legal/licencesv10.html".
*
* Initial Contributors:
* Nokia Corporation - initial contribution.
*
* Contributors:
*
* Description: 
*     Phonebook contact editor dialog.
*
*/


#ifndef __CPbkContactEditorDlg_H__
#define __CPbkContactEditorDlg_H__

//  INCLUDES
#include <AknForm.h>    // CAknForm
#include <cntdef.h>     // TContactItemId
#include <babitflags.h>     // TBitFlags


// FORWARD DECLARATIONS
class CAknTitlePane;
class CPbkContextPaneIcon;
class CPbkThumbnailPopup;
class CPbkThumbnailCmd;
class CPbkContactEditorFieldArray;
class CPbkContactEngine;
class CPbkContactItem;
class MPbkContactEditorStrategy;
class MPbkEditorOkToExitCallback;
class CAknNavigationControlContainer;


// CLASS DECLARATION

/**
 * A contact editing dialog implementation. This class can be used
 * to construct an UI editor dialog that is specifically tailored
 * to edit contacts in a similar fashion as in the platform contacts
 * application. 
 */
class CPbkContactEditorDlg :
        public CAknForm
    {
    public:  // Constructors and destructor
        /**
         * Creates an instance of an editor dialog for an aContactItem.
         *
         * @param aEngine   Phonebook engine
         * @param aContactItem  Contact item to edit
         * @param aIsNewContact Set to ETrue if aContactItem is a new contact
         *        (not yet in the database)
         * @param aFocusIndex   Optional index of field to focus initially, 
         *                      default behaviour is to focus the topmost field.
         * @param aEdited   If ETrue sets the contact initially to the edited state.
         *        Use when some data is added to aContactItem
         *        that needs to be saved even if user edits
         *        nothing. Default behaviour is to set the contact to 
         *        non-edited state.
         * @return A new dialog object.
         */
        IMPORT_C static CPbkContactEditorDlg* NewL
            (CPbkContactEngine& aEngine,
            CPbkContactItem& aContactItem,
            TBool aIsNewContact,
            TInt aFocusIndex=-1,
            TBool aEdited=EFalse);

        /**
         * Destructor.
         */
        ~CPbkContactEditorDlg();

    public:  // Interface
        /**
         * Sets aSelfPtr to NULL when this dialog is destroyed.
         * @precond Precondition: !aSelfPtr || *aSelfPtr==this
         */
        IMPORT_C void ResetWhenDestroyed(CPbkContactEditorDlg** aSelfPtr);

        /**
         * Runs the dialog. This object is destroyed when this function
         * returns or leaves.
         * NOTE: Current status pane layout is replaced with the
         *       Phonebook one. Restoring the original pane is left to be
         *       the responsibility of the caller.
         *
         * @return  The id of the saved contact. KNullContactId if not saved.
         *          Please note that the contact item (aContactItem passed
         *          to NewL) might be modified even if it is not saved to the
         *          database.
         */
        IMPORT_C TContactItemId ExecuteLD();

        /**
         * Hides the 'Exit' command from the options menu. This must be called
         * before calling ExecuteLD.
         */
        IMPORT_C void HideExitCommand();

        /**
         * Sets help context. There are many applications using contact editor
         * and they may have an own help topic to be shown, when editor's help
         * is launched. With this command it's possible to define the used
         * help content. If not called after, uses Phonebook's own help context
         * as default.
         * @param aContext Help context to use
         */
        IMPORT_C void SetHelpContext(TCoeHelpContext aContext);

        /**
         * Sets exit callback. The callback is called before exit happens.
         * If the callback returns EFalse, the exit process is cancelled.
         * @param aCallback Exit callback
         */
        IMPORT_C void SetExitCallback(MPbkEditorOkToExitCallback* aCallback);

        /**
         * Sets the exit command in the options menu to forward aCommandId to the
         * application framework. Allows clients to process and capture the exit 
         * command in the application exit situation.
         * @param aCommandId    Command id to send to the framework when the exit
         *                      occurs.
         */
        IMPORT_C void SetExitCommandId(TInt aCommandId);

    private:  // from CCoeControl
        TKeyResponse OfferKeyEventL(const TKeyEvent& aKeyEvent, TEventCode aType);
        void GetHelpContext(TCoeHelpContext& aContext) const;

    private:  // Command handlers
        void CmdSaveL();
        void CmdDoneL();
        void CmdEditItemLabelL();
        void CmdAddItemL();
        void CmdDeleteItemL();
        void CmdFetchThumbnailL();
        void CmdRemoveThumbnailL();

    private:  // From CAknForm
        void PreLayoutDynInitL();
        void PostLayoutDynInitL();
        void SetInitialCurrentLine();
        void ProcessCommandL(TInt aCommandId);
        void DynInitMenuPaneL(TInt aResourceId, CEikMenuPane* aMenuPane);
        TBool OkToExitL(TInt aKeycode);
        void HandleControlStateChangeL(TInt aControlId);

    protected:  // Constructors
        CPbkContactEditorDlg
            (CPbkContactEngine& aEngine,
            CPbkContactItem& aContactItem,
            TInt aFocusIndex);
        void BaseConstructL(TBool aIsNewContact, TBool aEdited);

    protected:  // Implementation
        void StoreTitlePaneTextL();
        void ConstructContextMenuL();
        void ConstructNaviPaneL();
        TBool IsNewContact() const;
        void UpdateTitlePaneL();
        void CloseAllPopups();
        TBool ContactAlreadyExistsL(); 
        TBool DuplicateNameMatchL(CContactIdArray* aIdArray); 
        TBool CheckForDuplicateEntryL(); 
	    void ReloadThumbnailL();

        void WriteContactToDbL();

        /// State flag values for CPbkContactEditorDlg
        enum TStateFlag
            {
            EHideExit, // Hide exit
            EEscKeyReceived, /// Espace key received
            EUnderDestruction // The dialog is under destruction
            };

    protected: // data
        /// Ref: Contact item under editing
        CPbkContactItem& iContactItem;
        /// Own: Contact editor field manager
        CPbkContactEditorFieldArray* iFieldManager;

    private:  // Data
        /// Ref; Contact engine
        CPbkContactEngine& iEngine;
        /// Own: Index of field to focus initially
        TInt iFocusIndex;
        /// Own: state flags
        mutable TBitFlags iStateFlags;
        /// Ref: pointer to ExecuteLD return value
        TContactItemId* iSavedContactPtr;
        /// Ref: application's title pane
        CAknTitlePane* iTitlePane;
        /// Own: Title pane text to restore on exit
        HBufC* iStoredTitlePaneText;
        /// Own: Phonebook context pane icon
        CPbkContextPaneIcon* iContextPaneIcon;
        /// Own: Thumbnail image handler
        CPbkThumbnailPopup* iThumbnailHandler;
        /// Own: context menu bar
        CEikMenuBar* iContextMenuBar;
        /// Own: Thumbnail command handler
        CPbkThumbnailCmd* iThumbnailCmd;
        /// Own: editor dialog strategy
        MPbkContactEditorStrategy* iEditorStrategy;
        /**
         * Ref: self pointer for easier leave handling
         * @invariant !iSelfPtr || *iSelfPtr==this
         */
        CPbkContactEditorDlg** iSelfPtr;
        class CExtension;
        /// Own: for adding extensions
        CExtension* iExtension;
        /// Own: the help context to use
        TCoeHelpContext iHelpContext;
        /// Ref: Contact editor exit callback
        MPbkEditorOkToExitCallback* iExitCallback;
        /// Own: exit command id
        TInt iExitCommandId;
        /// Ref: status pane handle
        CAknNavigationControlContainer* iNaviContainer;

    private: // friends
        friend class CExtension;
     };

#endif // __CPbkContactEditorDlg_H__

// End of File
