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
*     Phonebook field selection dialog.
*
*/


#ifndef __CPbkSelectFieldDlg_H__
#define __CPbkSelectFieldDlg_H__

//  INCLUDES
#include <e32base.h>    // CBase

// FORWARD DECLARATIONS
class TPbkContactItemField;
class CPbkFieldArray;
class MPbkControlKeyObserver;
class CPbkContactItem;
class CPbkFieldAnalyzer;
class CPbkContactEngine;


// CLASS DECLARATION

/**
 * Phonebook field selection dialog. This class is used to show a Phonebook 
 * contact item field selection dialog to the user. The user is able to 
 * select a particular field from the dialog and this selection is returned
 * to the client.
 */
class CPbkSelectFieldDlg : public CBase
    {
    public:  // Interface
        /**
         * Constructor.
         */
        IMPORT_C CPbkSelectFieldDlg();

        /**
         * Runs the dialog and returns selected field.
         * NOTE: this object is deleted when this function 
         * returns or leaves.
         *
         * @param aArray  Array of TPbkContactItemFields
         * @param aCbaResourceId Softkey buttons for the control.
         * @param aHeading Possible heading for the control.
         * @param aFocusIndex Field index to focus initially.
         *
         * @return The selected contact item field or NULL.
         */
        IMPORT_C TPbkContactItemField* ExecuteLD
            (CPbkFieldArray& aArray, 
            TInt aCbaResourceId, 
            const TDesC& aHeading = KNullDesC, 
            TInt aFocusIndex=-1);

        /**
         * Destructor.
         */
        IMPORT_C ~CPbkSelectFieldDlg();

        /**
         * Registers aKeyObserver as a key event observer of this control.
         * Only one observer is supported and setting a new one removes the
         * previous setting. 
         *
         * @param aKeyObserver  A Phonebook control key observer.
         */
        IMPORT_C void SetObserver(MPbkControlKeyObserver* aKeyObserver);

        /**
         * Attempts to exit this dialog as if a soft button was pressed.
         * @see CAknPopupList::AttemptExitL(TBool).
         */
        IMPORT_C void AttemptExitL(TBool aAccept);

        /**
         * Sets aSelfPtr to NULL when this dialog is destroyed.
         * @precond !aSelfPtr || *aSelfPtr==this
         */
        IMPORT_C void ResetWhenDestroyed(CPbkSelectFieldDlg** aSelfPtr);

    private: // Data
        /// Specialized listbox class
        class CListBox;
        /// Own: ListBox inside the popuplist
        CListBox* iListBox;
        /// Specialized popup list class
        class CPopupList;
        /// Own: popup list query
        CPopupList* iPopupList;
        /// Ref: key event observer
        MPbkControlKeyObserver* iKeyObserver;
        /// Ref: Set to ETrue in destructor
        TBool* iDestroyedPtr;
        /// Ref: Set to NULL when this dialog is destroyed.
        CPbkSelectFieldDlg** iSelfPtr;
        /// Own: Spare data
        TInt32 iSpare1;
    }; 

#endif // __CPbkSelectFieldDlg_H__
            
// End of File
