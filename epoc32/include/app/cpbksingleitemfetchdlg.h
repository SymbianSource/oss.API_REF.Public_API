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
*      Phonebook Single Item Fetch API.
*
*/


#ifndef __CPbkSingleItemFetchDlg_H__
#define __CPbkSingleItemFetchDlg_H__

//  INCLUDES
#include <e32base.h>    // CBase
#include <cntdef.h>     // TContactItemId

//  FORWARD DECLARATIONS
class CContactViewBase;
class CPbkFetchDlg;
class CPbkSelectFieldDlg;
class CPbkContactEngine;
class CPbkFieldIdArray;
class CPbkContactItem;
class TPbkContactItemField;
class MObjectProvider;


// CLASS DECLARATION

/**
 * Phonebook Single Item Fetch API. This class is used to construct 
 * a Phonebook UI dialog where the user is able to select a single 
 * contact entry from a contact list. Then the user must select a 
 * particular field of that selected contact. The selected contact 
 * item and field are then returned to the client.
 */
class CPbkSingleItemFetchDlg : public CBase
    {
    public:  // Types
        /**
         * Single item fetch parameter class. 
         */
        class TParams
            {
            public:  // Input parameters
                /**
                 * Contact view to display. If NULL, loads the default
                 * contact view containing all names in the contact
                 * database.
                 */
                CContactViewBase* iContactView;

                /**
                 * Array of field types to fetch.
                 */
                const CPbkFieldIdArray* iFieldIdArray;

            public:  // Output parameters
                /**
                 * Returns an contact item of the selected entry, undefined 
                 * if the dialog is canceled. Caller is responsible of 
                 * deleting iContactItem.
                 */
                CPbkContactItem* iContactItem;

                /**
                 * Returns a field of the selected entry, undefined if the 
                 * dialog is canceled. This is iContactItem's field so it 
                 * is deleted when iContactItem is deleted.
                 */
                TPbkContactItemField* iContactItemField;

            public: // Additional input parameters
                /**
                 * OPTIONAL: Fetch softkey resource ID.
                 * If 0, Default softkeys are used.
                 */
                TInt iCbaId;

            public:  // Constructors
                /**
                 * C++ constructor.
                 */
                IMPORT_C TParams();

                // Compiler-generated destructor is ok for this class

                /**
                 * Returns a cleanup item which will handle cleanup of this
                 * object in case a leave occurs.
                 */
                IMPORT_C operator TCleanupItem();

            private: // Implementation
                static void Cleanup(TAny* aSelf);

            private:  // Unimplemented functions
                /// Unimplemented copy constructor
                TParams(const TParams&);
                /// Unimplemented assignment operator
                TParams& operator=(const TParams&);

            private:  // data
				/// Own: spare data
                TInt32 iSpare1;
            };

    public:  // Interface
        /**
         * Creates a new single entry fetch dialog.
         *
         * @param aParams   Fetch parameters, @see TParams
         * @param aEngine   Phonebook engine
         */
        IMPORT_C static CPbkSingleItemFetchDlg* NewL
            (TParams& aParams, CPbkContactEngine& aEngine);

        /**
         * @see CCoeControl::SetMopParent(MObjectProvider* aParent)
         */
        IMPORT_C void SetMopParent(MObjectProvider* aParent);

        /**
         * Executes this dialog.
         * NOTE: this object is deleted when ExecuteLD returns or leaves!
         * NOTE: current status pane layout is replaced with the Phonebook
         * one. Restoring the original pane is left to be the responsibility
         * of the caller.
         *
         * @return A non-zero value if not canceled.
         */
        IMPORT_C TInt ExecuteLD();

        /**
         * Destructor. Also cancels this dialog if ExecuteLD() has been called.
         */
        ~CPbkSingleItemFetchDlg();

    private:  // Implementation
        CPbkSingleItemFetchDlg(TParams& aParams, CPbkContactEngine& aEngine);
        void ConstructL();
        TBool EntryFetchAcceptedL(TContactItemId aCid);
        class TFetchCallback;
        friend class TFetchCallback;

    private:  // Data
        /// Own: parameters
        TParams& iParams;
        /// Ref: contact view containing contacts to choose from
        CContactViewBase* iContactView;
        /// Own: fetch dialog
        CPbkFetchDlg* iFetchDlg;
        /// Own: field selection dialog
        CPbkSelectFieldDlg* iFieldDlg;
        /// Own: Phonebook engine
        CPbkContactEngine& iPbkEngine;
        /// Own: contact item to return to user via iParams
        CPbkContactItem* iContactItem;
        /// Own: contact item field to return to user via iParams
        TPbkContactItemField* iContactItemField;
        /// Ref: set to ETrue in destructor
        TBool* iDestroyedPtr;
        /// Own: object provicer
        MObjectProvider* iObjectProvider;
    };

#endif // __CPbkSingleItemFetchDlg_H__

// End of File
