/*
* Copyright (c) 2002 Nokia Corporation and/or its subsidiary(-ies).
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
* Description: 
*    Phonebook Data Save service helper. Implements "Save to phonebook" 
*    menu functionality for external applications.
*
*/


#ifndef __CPbkDataSaveAppUi_H__
#define __CPbkDataSaveAppUi_H__

//  INCLUDES
#include <e32base.h>

// FORWARD DECLARATIONS
class CEikMenuPane;
class CPbkContactEngine;
class CPbkContactItem;
class CPbkFieldInfo;
class MPbkDataSaveCallback;
class CPbkFFSCheck;
class CPbkExtGlobals;


// CLASS DECLARATION

/**
 * Phonebook Data Save service helper. Implements "Save to phonebook" 
 * menu functionality for external applications.
 *
 * Note that in most cases current status pane layout is replaced with the
 * Phonebook one. Restoring the original pane is left to be
 * the responsibility of the client.
 */
class CPbkDataSaveAppUi : public CBase
    {
    public:  // Interface
        /**
         * Creates an instance of this class.
         *
         * @param aEngine   Phonebook engine instance.
         */
        IMPORT_C static CPbkDataSaveAppUi* NewL(CPbkContactEngine& aEngine);

        /**
         * Destructor. Destroys this object and cancels any open dialogs.
         */
        ~CPbkDataSaveAppUi();

        /**
         * Adds Phonebook data save menu items to a menu pane. Called from 
         * applications DynInitMenuPaneL. This call is not mandatory: 
         * if the application provides its own menus it may call
         * HandleCommandL directly from menu's command handler.
         *
         * @param aMenuPane     Menu pane where to add the menu items.
         * @param aCommandId    Id of command which to replace with Phonebook
         *                      data save menu items. This command id is stored
         *                      into this object as the base id after which are
         *                      app-specific command Ids reserved for Phonebook
         *                      data save API usage.
         * @see DynInitMenuPaneL
         * @see HandleCommandL
         */
        IMPORT_C void AddMenuItemsL(CEikMenuPane* aMenuPane, TInt aCommandId);

        /**
         * Updates Phonebook data save menu items. Called from applications 
         * DynInitMenuPaneL. This call is not mandatory: if the application 
         * provides its own menus it may call HandleCommandL directly 
         * from menu's command handler.
         *
         * @param aResourceId   Resource id of the menu pane as passed to 
         *                      MEikMenuObserver::DynInitMenuPaneL. If this 
         *                      resource id does not match with Phonebook data
         *                      save submenu this function does nothing.
         * @param aMenuPane     Menu pane as passed to 
         *                      MEikMenuObserver::DynInitMenuPaneL.
         * @see AddMenuItemsL
         */
        IMPORT_C void DynInitMenuPaneL(TInt aResourceId, CEikMenuPane* aMenuPane);

        /**
         * Handles a menu command inserted by AddMenuItemsL.
         *
         * @param aCommandId        Command to execute. iBaseCommandId+1 is
         *                          Create New Entry and iBaseCommandId+2 is
         *                          Add to Existing Entry. Use directly 
         *                          EPbkCmdDataSaveCreateNew or EPbkCmdDataSaveAddToExisting
         *                          if AddMenuItemsL is not called.
         * @param aFieldTypes       Field types where the user can select from.
         *                          If there is only one field type selection
         *                          list is not displayed.
         * @param aText             Text to put to the selected field.
         * @param aCallback         Calls back to this object if there are 
         *                          problems in adding the field. See 
         *                          MPbkDataSaveCallback class for details.
         * @return  ETrue if the command was executed and the data added, 
         *          EFalse if the operation was canceled in any stage.
         * @see AddMenuItemsL
         * @see MPbkDataSaveCallback
         * @see TPbkDataSaveCommandId in PbkDataSaveAppUi.hrh
         */
        IMPORT_C TBool HandleCommandL
            (TInt aCommandId, 
            CArrayPtr<CPbkFieldInfo>& aFieldTypes,
            const TDesC& aText,
            MPbkDataSaveCallback* aCallback=NULL);

        /**
         * Handles a menu command inserted by AddMenuItemsL.
         *
         * @param aCommandId        Command to execute. iBaseCommandId+1 is
         *                          Create New Entry and iBaseCommandId+2 is
         *                          Add to Existing Entry. Use directly 
         *                          EPbkCmdDataSaveCreateNew or EPbkCmdDataSaveAddToExisting
         *                          if AddMenuItemsL is not called.
         * @param aFieldTypes       Field types where the user can select from.
         *                          If there is only one field type selection
         *                          list is not displayed.
         * @param aDate             Date to put to the selected field.
         * @param aCallback         Calls back to this object if there are 
         *                          problems in adding the field. See 
         *                          MPbkDataSaveCallback class for details.
         * @return  ETrue if the command was executed and the data added, 
         *          EFalse if the operation was canceled in any stage.
         * @see AddMenuItemsL
         * @see MPbkDataSaveCallback
         * @see TPbkDataSaveCommandId in PbkDataSaveAppUi.hrh
         */
        IMPORT_C TBool HandleCommandL
            (TInt aCommandId, 
            CArrayPtr<CPbkFieldInfo>& aFieldTypes,
            const TTime& aDate,
            MPbkDataSaveCallback* aCallback=NULL);

        /**
         * Hides the "Exit" command from contact editor's options menu.
         * Call this function after creating this object.
         */
        IMPORT_C void HideEditorExitCommand();
        
    private:  // Implementation
        class MFieldData;
        class CTextFieldData;
        class CDateFieldData;
        class CCommandBase;
        class CCreateNewCommand;
        class CAddToExistingCommand;
        CPbkDataSaveAppUi(CPbkContactEngine& aEngine);
        void ConstructL();
        TBool DoHandleCommandL
            (TInt aCommandId, 
            CArrayPtr<CPbkFieldInfo>& aFieldTypes,
            MFieldData& aFieldData,
            MPbkDataSaveCallback* aCallback);

    private:  // Data
        /// Ref: Phonebook engine instance
        CPbkContactEngine* iEngine;
        /// Own: FFS space checker
        CPbkFFSCheck* iFFSCheck;
        /// Own: base command id
        TInt iBaseCommandId;
        /// Own: the currently executing command
        CCommandBase* iExecutingCommand;
        /// Own: flags
        TUint iFlags;
        /// Own: handle to UI extension factory
        CPbkExtGlobals* iExtGlobals;
    };


/**
 * Callback interface for CPbkDataSaveAppUi::HandleCommandL.
 */
class MPbkDataSaveCallback
    {
    public:  // Interface
        /**
         * Called by CPbkDataSaveAppUi::HandleCommandL if there is no field
         * available where to save the data and no new field could be added.
         * Default implementation does nothing.
         *
         * @param aContact  Contact where the field cannot be added.
         */
        IMPORT_C virtual void PbkDataSaveNoFieldL(CPbkContactItem& aContact);

        /**
         * Called from CPbkDataSaveAppUi::HandleCommandL if the aText is too 
         * long to fit into field.
         * Default implementation clips aText from the end. If an empty 
         * string is returned the field addition is canceled.
         *
         * @param aText         The original text.
         * @param aFieldInfo    The type of field where the text should be 
         *                      inserted.
         * @return  A substring of aText so that the substring's length is 
         *          <=aFieldInfo.MaxLength().
         */
        IMPORT_C virtual TPtrC PbkDataSaveClipTextL
            (const TDesC& aText, CPbkFieldInfo& aFieldInfo);
    };

#endif // __CPbkDataSaveAppUi_H__

// End of File
