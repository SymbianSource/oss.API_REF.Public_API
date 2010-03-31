/*
* Copyright (c) 2004-2007 Nokia Corporation and/or its subsidiary(-ies).
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
* Description:  Virtual Phonebook base interface for contact field collections.
*
*/


#ifndef MVPBKBASECONTACTFIELDCOLLECTION_H
#define MVPBKBASECONTACTFIELDCOLLECTION_H

// INCLUDES
#include <e32cmn.h>
#include <e32def.h>

// FORWARD DECLARATIONS
class MVPbkBaseContact;
class MVPbkBaseContactField;
class MVPbkFieldType;

// CLASS DECLARATIONS

/**
 * Virtual Phonebook base contact field collection interface.
 * An abstract collection of read-only Virtual Phonebook contact fields.
 */
class MVPbkBaseContactFieldCollection
    {
    public:  // Destructor
        /**
         * Destructor.
         */
        virtual ~MVPbkBaseContactFieldCollection() { }

    public:  // Interface
        /**
         * Returns the parent contact of this field set.
         * @return The parent contact of this field set.
         */
        virtual MVPbkBaseContact& ParentContact() const =0;

        /**
         * Returns the number of fields in this collection.
         * @return The number of fields in this collection.
         */
        virtual TInt FieldCount() const =0;

        /**
         * Returns a read-only field in this collection.
         *
         * @param aIndex    Zero-based index of the field to return.
         * @return  Reference to a field at aIndex. Reference is 
         *          valid until FieldAt is called again.
         * @see MVPbkBaseContactFieldCollection::ConstFieldAt
         * @precond aIndex >= 0 && aIndex < FieldCount()
         *          Panic VPbkError::EInvalidFieldIndex is raised if the
         *          precondition does not hold.
         */
        virtual const MVPbkBaseContactField& FieldAt(
                TInt aIndex) const =0;

        /**
         * Returns an extension point for this interface or NULL.
         * @param aExtensionUid Uid of extension
         * @return Extension point or NULL
         */
        virtual TAny* BaseContactFieldCollectionExtension(
                TUid /*aExtensionUid*/) { return NULL; }
    };


#endif  // MVPBKBASECONTACTFIELDCOLLECTION_H

//End of file
