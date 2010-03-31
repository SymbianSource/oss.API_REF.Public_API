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
* Description:  An interface for field type selectors.
*
*/


#ifndef MVPBKFIELDTYPESELECTOR_H
#define MVPBKFIELDTYPESELECTOR_H

// INCLUDES
#include <e32def.h>

// FORWARD DECLARATIONS
class MVPbkFieldType;

// CLASS DECLARATIONS

/**
 * An interface for field type selectors.
 *
 * A field type selector can be used for selecting certain
 * field types from a set of field types. E.g client could create
 * a selector of all telephone number fields and then loop 
 * a field type list for getting those field types that matches the selector.
 *
 * @see E.g. CVPbkFieldTypeSelector
 */
class MVPbkFieldTypeSelector
    {
    public: // Interface

        /**
         * Returns true if the given field type belongs to the set
         * defined by this field type selector.
         *
         * @param aFieldType The field type to test.
         * @return ETrue if the given field type is included.
         */
        virtual TBool IsFieldTypeIncluded(
                const MVPbkFieldType& aFieldType ) const = 0;

        /**
         * Returns an extension point for this interface or NULL.
         *
         * @param aExtensionUid no extensions defined currently.
         * @return An extension point for this interface or NULL.
         */
        virtual TAny* FieldTypeSelectorExtension( TUid /*aExtensionUid*/ )
            { return NULL; }

    protected: // Protected destructor

        /**
         * Destructor.
         */
        virtual ~MVPbkFieldTypeSelector() { }

    };

#endif // MVPBKFIELDTYPESELECTOR_H

// End of File
