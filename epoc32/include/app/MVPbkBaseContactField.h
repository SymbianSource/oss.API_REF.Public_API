/*
* Copyright (c) 2002-2007 Nokia Corporation and/or its subsidiary(-ies).
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
* Description:  Virtual Phonebook base interface for contact fields.
*
*/


#ifndef MVPBKBASECONTACTFIELD_H
#define MVPBKBASECONTACTFIELD_H

// INCLUDES
#include <e32cmn.h>
#include <e32std.h>
#include <mvpbkobjecthierarchy.h>

// FORWARD DECLARATIONS
class MVPbkBaseContact;
class MVPbkFieldType;
class MVPbkFieldTypeList;
class MVPbkContactFieldData;

// CLASS DECLARATIONS

/**
 * Virtual Phonebook Base contact field interface.
 * An abstract interface Virtual Phonebook read-only contact fields.
 */
class MVPbkBaseContactField
    {
    public:  // Destructor
        /**
         * Destructor.
         */
        virtual ~MVPbkBaseContactField() { }

    public:  // Interface
        /**
         * Returns the parent contact where this field is from.
         *
         * @return The parent contact where this field is from.
         */
        virtual MVPbkBaseContact& ParentContact() const = 0;

        /**
         * Returns this field's type or NULL if no mapping exists
         * between the native type and virtual phonebook type.
         *
         * @param aMatchPriority    matching priority to use.
         * @return The field type or NULL
         * @postcond !FieldType(list) || list.ContainsSame(*FieldType(list))
         */
        virtual const MVPbkFieldType* MatchFieldType(
                TInt aMatchPriority) const =0;
        
        /**
         * Returns the best matching type of the field or NULL 
         * if no mapping exists between the native type and 
         * virtual phonebook type. This is the same as looping 
         * MatchFieldType from priority 0 and getting the first 
         * matched type.
         *
         * @return The field type or NULL
         * @postcond !FieldType(list) || list.ContainsSame(*FieldType(list))
         */
        virtual const MVPbkFieldType* BestMatchingFieldType() const = 0;

        /**
         * Returns this field's data storage (read-only). The actual
         * data type can be get using the static Cast functions in actual
         * classes.
         * 
         * @see MVPbkContactFieldTextData
         * @see MVPbkContactFieldBinaryData
         * @see MVPbkContactFieldDateTimeData
         * @return This field's data storage (read-only).
         */
        virtual const MVPbkContactFieldData& FieldData() const = 0;

        /**
         * Returns true if this field is the same as another field in the
         * contact instance. 
         * Doesn't work for fields from different contact instances.
         * Always use this method instead of direct pointer comparison.
         *
         * @param aOther another field inside the contact
         * @return ETrue if contact is same
         */
        virtual TBool IsSame(const MVPbkBaseContactField& aOther) const = 0;

        /**
         * Returns an extension point for this interface or NULL.
         * @param aExtensionUid Uid of extension
         * @return Extension point or NULL
         */
        virtual TAny* BaseContactFieldExtension(
                TUid /*aExtensionUid*/) { return NULL; }

    };

#endif  // MVPBKBASECONTACTFIELD_H

// End of file
