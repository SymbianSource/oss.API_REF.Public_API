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
*     Base class for Phonebook phone number selection queries.
*
*/


#ifndef __CPbkPhoneNumberSelectBase_H__
#define __CPbkPhoneNumberSelectBase_H__

//  INCLUDES
#include "CPbkAddressSelect.h"

// CLASS DECLARATION
/**
 * Base class for Phonebook phone number selection queries.
 */
class CPbkPhoneNumberSelectBase : public CPbkAddressSelect
    {
    protected:  // from CPbkAddressSelect
        /**
         * Common implementation of CPbkAddressSelect::AddressField for phone
         * number selection dialogs.
		 * @param aField The field to check
         */
        IMPORT_C TBool AddressField(const TPbkContactItemField& aField) const;

        /**
         * Common implementation of CPbkAddressSelect::NoAddressesL for phone
         * number selection dialogs.
         */
        IMPORT_C void NoAddressesL();
    }; 

#endif // __CPbkPhoneNumberSelectBase_H__
            
// End of File
