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
*      Phonebook Single Entry Fetch dialog API.
*
*/


#ifndef __CPbkSingleEntryFetchDlg_H__
#define __CPbkSingleEntryFetchDlg_H__

//  INCLUDES
#include <e32base.h>    // CBase
#include <cntdef.h>     // TContactItemId

//  FORWARD DECLARATIONS
class CContactViewBase;
class CPbkFetchDlg;
class CPbkContactEngine;
class MObjectProvider;
class MPbkFetchKeyCallback;
class MPbkFetchDlgAccept;


// CLASS DECLARATION
/**
 * Phonebook Single Entry Fetch API. This class is used to construct 
 * a Phonebook UI dialog where the user is able to select a single 
 * contact entry from a contact list. The user selection is then returned 
 * to the client.
 */
class CPbkSingleEntryFetchDlg : 
        public CBase
    {
    public:  // Types
        /**
         * Single entry fetch parameter class. 
         */
        class TParams
            {
            public:  // Input parameters
                /**
                 * Contact database. If NULL, the contact database is 
                 * retrieved from TLS or constructed if not available.
                 * If you have a Contact database on the client side
                 * please supply it here. 
                 */
                CPbkContactEngine* iPbkEngine;

                /**
                 * Contact view to display. If NULL, loads the default
                 * contact view containing all names in the contact
                 * database.
                 * @see CPbkContactEngine::AllContactsView()
                 * @see CPbkContactEngine::FilteredContactsViewL()
                 */
                CContactViewBase* iContactView;

                /**
                 * OPTIONAL: Fetch key event callback. 
                 * If NULL, not applicable.
                 */
                MPbkFetchKeyCallback* iFetchKeyCallback;

                /**
                 * OPTIONAL: Fetch accept callback.
                 * If NULL, not applicable.
                 */
                MPbkFetchDlgAccept* iFetchDlgAccept;

            public:  // Output parameters
                /**
                 * Returns the id of the selected entry, undefined if the dialog
                 * is canceled.
                 */
                TContactItemId iSelectedEntry;

            public: // Additional input parameters
                /**
                 * OPTIONAL: Fetch softkey resource ID.
                 * If 0, default softkeys are used.
                 */
                TInt iCbaId;

            public:  // Constructors
                /**
                 * C++ Constructor.
                 */
                IMPORT_C TParams();

                // Compiler-generated destructor is ok for this class

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
         * @return New instance of this class.
         */
        IMPORT_C static CPbkSingleEntryFetchDlg* NewL(TParams& aParams);

        /**
         * @see CCoeControl::SetMopParent(MObjectProvider* aParent)
         */
        IMPORT_C void SetMopParent(MObjectProvider* aParent);

        /**
         * Sets *aSelfPtr to NULL when this dialog is destroyed.
         * @precond !aSelfPtr || *aSelfPtr==this
         */
        IMPORT_C void ResetWhenDestroyed(CPbkSingleEntryFetchDlg** aSelfPtr);

        /**
         * Executes this dialog.
         * NOTE: this object is deleted when ExecuteLD returns or leaves!
         * NOTE: current status pane layout is replaced with the Phonebook
         * one. Restoring the original pane is left to be the responsibility
         * of the caller.
         *
         * @return A non-zero value if accepted, 0 if canceled.
         */
        IMPORT_C TInt ExecuteLD();

        /**
         * Destructor. Also cancels this dialog and makes ExecuteLD return.
         */
        ~CPbkSingleEntryFetchDlg();

    private:  // Implementation
        CPbkSingleEntryFetchDlg(TParams& aParams);
        void ConstructL();
        static void Panic(TInt aReason);

    private:  // Data
        /// Own: parameters
        TParams& iParams;
        /// Own: fetch dialog
        CPbkFetchDlg* iFetchDlg;
        /// Ref: Phonebook engine
        CPbkContactEngine* iPbkEngine;
        /// Own: Phonebook engine
        CPbkContactEngine* iOwnPbkEngine;
        /// Ref: contact view to use for fetcing
        CContactViewBase* iContactView;
        /// Ref: set to ETrue in destructor
        TBool* iDestroyedPtr;
        /// Ref: pointer to self
        CPbkSingleEntryFetchDlg** iSelfPtr;
        /// Own: Object Provider
        MObjectProvider* iObjectProvider;
    };

#endif // __CPbkSingleEntryFetchDlg_H__

// End of File
