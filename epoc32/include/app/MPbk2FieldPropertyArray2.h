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


#ifndef MPBK2FIELDPROPERTYARRAY2_H
#define MPBK2FIELDPROPERTYARRAY2_H

// INCLUDE FILES
#include <e32def.h>

// FORWARD DECLARATIONS
class MPbk2FieldProperty;
class MVPbkFieldType;

// CLASS DECLARATION
/**
 * This class is an extension to MPbk2FieldPropertyArray.
 * See documentation of MPbk2FieldPropertyArray from header
 * MPbk2FieldPropertyArray.h 
 * 
 * You can access this extension by calling
 * MPbk2FieldPropertyArray->FieldPropertyArrayExtension()
 */
class MPbk2FieldPropertyArray2
    {
    public: // Interface
        /**
         * Returns a property for the field type and given name or NULL.
         *
         * @param aFieldType    The field type whose property is
         *                      searched for.
         * @param aName    Name for the filed type
         * @return  A field property for the field type
         *          or NULL if not found.
         */
        virtual const MPbk2FieldProperty* FindProperty(
                    const MVPbkFieldType& aFieldType,
                    const TDesC& aName ) const = 0;

    protected:
        /**
         * Destructor.
         */
        virtual ~MPbk2FieldPropertyArray2()
                {}
    };

#endif // MPBK2FIELDPROPERTYARRAY2_H

// End of File
