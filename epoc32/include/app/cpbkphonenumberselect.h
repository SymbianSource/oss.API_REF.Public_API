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
*       Phonebook call number selection dialog. This dialog implements the call
*       number selection logic of Phonebook.
*
*/


#ifndef __CPbkPhoneNumberSelect_H__
#define __CPbkPhoneNumberSelect_H__

//  INCLUDES
#include  "CPbkPhoneNumberSelectBase.h"

// CLASS DECLARATION

/**
 * Phonebook call number selection dialog. This dialog implements the call
 * number selection logic of Phonebook.
 */
class CPbkPhoneNumberSelect : public CPbkPhoneNumberSelectBase
    {
    public:  // Interface
        /**
         * Constructor.
         */
        IMPORT_C CPbkPhoneNumberSelect();

        /**
         * Parameters for ExecuteLD(TParams&).
         *
         * @see CPbkAddressSelect::TBaseParams
         * @see ExecuteLD(TParams&)
         */
        class TParams : public CPbkAddressSelect::TBaseParams
            {
            public:
                /**
                 * Constructor.
                 * @param aContact  Contact from which to select a phone number.
                 */
                IMPORT_C TParams(const CPbkContactItem& aContact);

            private: // data
				/// Own: spare data
                TInt32 iSpare1;
            };

        /**
         * Runs the phone number selection query (if necessary).
         *
         * @param aParams   Parameters and return values of the query.
         * @return  ETrue if query was accepted, EFalse if canceled.
         * @see TParams
         */
        IMPORT_C TBool ExecuteLD(TParams& aParams);

        /**
         * Destructor.
         */
        IMPORT_C ~CPbkPhoneNumberSelect();

    private:  // from CPbkAddressSelect
        IMPORT_C const TDesC& QueryTitleL();
        IMPORT_C TInt QuerySoftkeysResource() const;
        IMPORT_C TKeyResponse PbkControlKeyEventL
            (const TKeyEvent& aKeyEvent,TEventCode aType);
    
    private: // data members
        /// Own: Title for phonenumber selection list
        HBufC* iQueryTitle;
        // Spare data
        TInt32 iSpare1;
    }; 

#endif // __CPbkPhoneNumberSelect_H__
            
// End of File
