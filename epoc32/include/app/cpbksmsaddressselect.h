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
*     Phonebook SMS address selection dialog.
*
*/


#ifndef __CPbkSmsAddressSelect_H__
#define __CPbkSmsAddressSelect_H__

//  INCLUDES
#include "CPbkPhoneNumberSelectBase.h"

// CLASS DECLARATION

/**
 * Phonebook SMS address selection dialog.
 */
class CPbkSmsAddressSelect : public CPbkPhoneNumberSelectBase
    {
    public:  // Interface
        /**
         * Constructor.
         */
        IMPORT_C CPbkSmsAddressSelect();

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
            };

        /**
         * Runs the SMS address selection query (if necessary).
         *
         * @param aParams   Parameters and return values of the query.
         * @return  ETrue if query was accepted, EFalse if canceled.
         * @see TParams
         */
        inline TBool ExecuteLD(TParams& aParams);

        /**
         * Destructor.
         */
        IMPORT_C ~CPbkSmsAddressSelect();

    private:  // from CPbkAddressSelect
        IMPORT_C const TDesC& QueryTitleL();
        IMPORT_C TInt QuerySoftkeysResource() const;

    private: // Data
        /// Own: Title for phonenumber selection list
        HBufC* iQueryTitle;
    }; 


// INLINE FUNCTIONS
inline TBool CPbkSmsAddressSelect::ExecuteLD(TParams& aParams)
    {
    return CPbkAddressSelect::ExecuteLD(aParams);
    }

#endif // __CPbkSmsAddressSelect_H__
            
// End of File
