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
*       Field type selection dialog for Phonebook's Create New / Edit Memory entry
*       functions.
*
*/


#ifndef __CPbkMemoryEntryAddItemDlg_H__
#define __CPbkMemoryEntryAddItemDlg_H__

//  INCLUDES
#include <e32base.h>

// FORWARD DECLARATIONS
class CPbkFieldInfo;
class CEikFormattedCellListBox;
class CAknPopupList;

// CLASS DECLARATION

/**
 * Field type selection dialog for Phonebook's Create New- and Edit Memory 
 * entry-functions. 
 * Also used externally for Create New Entry- and Add to Existing 
 * Entry-services.
 */
class CPbkMemoryEntryAddItemDlg : public CBase
    {
    public:  // Interface
        /**
         * Constructor.
         */
        IMPORT_C CPbkMemoryEntryAddItemDlg();

        /**
         * Sets *aSelfPtr to NULL when this dialog is destroyed.
         * @precond !aSelfPtr || *aSelfPtr==this
         */
        IMPORT_C void ResetWhenDestroyed(CPbkMemoryEntryAddItemDlg** aSelfPtr);

        /**
         * Run the dialog and return selected field info.
         *
         * @param aFieldInfos   An array of field info objects to select from.
         * @param aCbaResource  Cba buttons to use with the dialog.
         * @return Pointer to a field info in aFieldInfos or NULL if canceled.
         */
        IMPORT_C CPbkFieldInfo* ExecuteLD
            (CArrayPtrFlat<CPbkFieldInfo>& aFieldInfos, TInt aCbaResource);

        /**
         * Run the dialog and return selected field info.
         *
         * @param aFieldInfos   An array of field info objects to select from.
         * @param aCbaResource  Cba buttons to use with the dialog.
         * @param aTitleText    Text to put into popup list's title. No title
         *                      pane if aTitleText is empty.
         * @return Pointer to a field info in aFieldInfos or NULL if canceled.
         */
        IMPORT_C CPbkFieldInfo* ExecuteLD
            (CArrayPtr<CPbkFieldInfo>& aFieldInfos, 
            TInt aCbaResource,
            const TDesC& aTitleText);

        /**
         * Basic ExecuteLD for derived classes to override.
		 * @param aFieldInfos An array of field info objects to select from.
         */
        IMPORT_C virtual CPbkFieldInfo* ExecuteLD
			(CArrayPtr<CPbkFieldInfo>& aFieldInfos);

        /**
         * Destructor.
         * Also cancels and dismisses this popup list, in other words makes
         * ExecuteLD return just like cancel was pressed.
         */
        IMPORT_C ~CPbkMemoryEntryAddItemDlg();

    public: // internal implementation
        /**
         * @internal
         * Sorts the field info objects according to Phonebook specific rules.
         */
        void SortFieldInfoArray();

    protected:  // Interface for derived classes
        /**
         * Creates list items, sets Cba and title.
         * Executed before RunLD.
         * First part of ExecuteLD.
		 * @param aFieldInfos   An array of field info objects to select from.
		 * @param aCbaResource  Cba buttons to use with the dialog
		 * @param aTitle Text to put into popup list's title
         */
        void PrepareLC(CArrayPtr<CPbkFieldInfo>& aFieldInfos, 
            TInt aCbaResource, const TDesC& aTitle);

        /**
         * Execute the initialized dialog.
         * Second part of ExecuteLD.
		 * @return Pointer to a field info
         */
        CPbkFieldInfo* RunLD();

    private:  // Spare virtual functions
        IMPORT_C virtual void Reserved_1();
        IMPORT_C virtual void Reserved_2();

    private: // Data types
        class CListBoxModel;

    private: // Data members
        /// Own: list box.
        CEikFormattedCellListBox* iListBox;
        /// Own: popup listbox.
        CAknPopupList* iPopupList;
        /// Ref: Referred boolean is set to ETrue when this object is destroyed.
        TBool* iDestroyedPtr;
        /// Ref: set to NULL from destructor
        CPbkMemoryEntryAddItemDlg** iSelfPtr;
        // Own: Sort Field Infos 
        TBool iSortFieldInfos;
    };


/**
 * Field type selection dialog for Phonebook's Create New service.
 * This service can be used to show a popup dialog of Phonebook field
 * types and then let the user select a particular field type from it.
 */
class CPbkItemTypeSelectCreateNew : public CPbkMemoryEntryAddItemDlg
    {
    public:  // Interface
        /**
         * Constructor.
         */
        IMPORT_C CPbkItemTypeSelectCreateNew();

        /**
         * Destructor.
         * Also cancels and dismisses this popup list, in other words makes
         * ExecuteLD return just like cancel was pressed.
         */
        IMPORT_C ~CPbkItemTypeSelectCreateNew();

    public:  // from CPbkMemoryEntryAddItemDlg
        /**
         * Runs this dialog and returns the selected field info.
         *
         * @param aFieldInfos   An array of field info objects to select from.
         * @return Pointer to a field info in aFieldInfos or NULL if canceled.
         */
        IMPORT_C CPbkFieldInfo* ExecuteLD(CArrayPtr<CPbkFieldInfo>& aFieldInfos);

    private:  // Data
        /// Own: popup list title text
        HBufC* iTitleBuf;
        // Spare data
        TInt32 iSpare1;
    };


/**
 * Field type selection dialog for Phonebook's Add to Existing-service. 
 * This service can be used to show a popup dialog of Phonebook field
 * types and then let the user select a particular field type from it.
 */
class CPbkItemTypeSelectAddToExisting : public CPbkMemoryEntryAddItemDlg
    {
    public:  // Interface
        /**
         * Constructor.
         */
        IMPORT_C CPbkItemTypeSelectAddToExisting();

        /**
         * Destructor.
         * Also cancels and dismisses this popup list, in other words makes
         * ExecuteLD return just like cancel was pressed.
         */
        IMPORT_C ~CPbkItemTypeSelectAddToExisting();

    public:  // from CPbkMemoryEntryAddItemDlg
        /**
         * Run this dialog and return selected field info.
         *
         * @param aFieldInfos   An array of field info objects to select from.
         * @return Pointer to a field info in aFieldInfos or NULL if canceled.
         */
        IMPORT_C CPbkFieldInfo* ExecuteLD(CArrayPtr<CPbkFieldInfo>& aFieldInfos);

    private:  // Data
        /// Own: popup list title text
        HBufC* iTitleBuf;
        // Spare data
        TInt32 iSpare1;
    };

#endif  // __CPbkMemoryEntryAddItemDlg_H__
            
// End of File
