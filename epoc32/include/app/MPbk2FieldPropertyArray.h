/*
* Copyright (c) 2005-2007 Nokia Corporation and/or its subsidiary(-ies).
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
* Description:  Phonebook 2 field property array interface.
*
*/


#ifndef MPBK2FIELDPROPERTYARRAY_H
#define MPBK2FIELDPROPERTYARRAY_H

// INCLUDE FILES
#include <e32def.h>

// FORWARD DECLARATIONS
class MPbk2FieldProperty;
class MVPbkFieldType;

//Use this UID to access field property array extension 2. Used as a parameter
//to FieldPropertyArrayExtension() method.
const TUid KMPbk2FieldPropertyArrayExtension2Uid = { 2 };

/**
 * Phonebook 2 field property array interface.
 *
 * @see MPbk2FieldProperty
 */
class MPbk2FieldPropertyArray
    {
    public: // Interface

        /**
         * Destructor.
         */
        virtual ~MPbk2FieldPropertyArray()
                {}

        /**
         * Returns a property for the field type or NULL.
         *
         * @param aFieldType    The field type whose property is
         *                      searched for.
         * @return  A field property for the field type
         *          or NULL if not found.
         */
        virtual const MPbk2FieldProperty* FindProperty(
                const MVPbkFieldType& aFieldType ) const = 0;

        /**
         * Returns the number of properties in the array.
         *
         * @return Number of properties in the array.
         */
        virtual TInt Count() const = 0;

        /**
         * Returns the property at given index.
         *
         * @param aIndex        The index of the property.
         * @return  Property at given index.
         */
        virtual const MPbk2FieldProperty& At(
                TInt aIndex ) const = 0;

        /**
         * Returns an extension point for this interface or NULL.
         *
         * @param aExtensionUid     Extension UID.
         * @return  Extension point.
         */
        virtual TAny* FieldPropertyArrayExtension(
                TUid /*aExtensionUid*/ )
            {
            return NULL;
            }
    };

#endif // MPBK2FIELDPROPERTYARRAY_H

// End of File
