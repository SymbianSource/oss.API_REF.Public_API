/*
* Copyright (c) 2005 Nokia Corporation and/or its subsidiary(-ies). 
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
* Description: Serene property interface declaration      
*
*/

#ifndef M_SEN_PROPERTY_H
#define M_SEN_PROPERTY_H

// INCLUDES
#include <e32std.h>

class MSenProperty
    {
    public:
        /**
        * Gets the name of the property
        *
        * @return TPtrC8 containing name
        */
        virtual TPtrC8 Name() = 0;

        /**
        * Gets the type of the property
        *
        * @return TPtrC8 containing type
        */
        virtual TPtrC8 Type() = 0;

        /**
        * Gets the value of the property
        *
        * @return TPtrC8 containing value
        */
        virtual TPtrC8 Value() = 0;

        /**
        * Gets the integer value of the property
        *
        * @param aValue   A TInt reference to be filled in with the value of
        *                 the property.
        * @return         KErrNone if no error, or some of the system wide
        *                 error codes.
        */
        virtual TInt IntValue(TInt& aValue) = 0;

        /**
        * Gets the boolean value of the property
        *
        * @param aValue   A TBool reference to be filled in with the value of
        *                 the property.
        * @return         KErrNone if no error, or some of the system wide
        *                 error codes.
        */
        virtual TInt BoolValue(TBool& aValue) = 0;
        
        /**
        * Populates given array with the tokens delimited by given delimiter.
        * Note! Ownership of the TPtrC8 pointers is transfered to the caller.
        * @param aDelimiter Used delimiter.
        * @param aTokens    Array which will be populated by tokens.
        * @return           KErrNone if tokens were found.
        *                   KErrNotFound if tokens were not found.
        */
        virtual TInt ValueTokensL(const TDesC8& aDelimiter,
                                  RPointerArray<TPtrC8>& aTokens) = 0;
        
    };

#endif // M_SEN_PROPERTY_H

// End of File

