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
* Description:  An interface for the field collection of the store contact
*
*/


#ifndef MVPBKSTORECONTACTFIELDCOLLECTION_H
#define MVPBKSTORECONTACTFIELDCOLLECTION_H


// INCLUDES
#include <e32def.h>
#include <mvpbkbasecontactfieldcollection.h>

// Includes needed for covariant return types
#include <mvpbkstorecontactfield.h>

// FORWARD DECLARATIONS
class MVPbkStoreContact;
class MVPbkStoreContactField;

// CLASS DECLARATIONS

/**
 * An interface for the field collection of the store contact
 *
 * A field collection interface can be used for looping the contact fields.
 */
class MVPbkStoreContactFieldCollection : public MVPbkBaseContactFieldCollection
    {
    public:  // Destructor
        /**
         * Destructor.
         */
        virtual ~MVPbkStoreContactFieldCollection() { }

    public: // From MVPbkBaseContactFieldCollection (covariant return types))
         const MVPbkStoreContactField& FieldAt(TInt aIndex) const =0;

    public:  // New functions
        /**
         * Returns a field in this collection.
         *
         * @param aIndex A zero-based index of the field to return.
         * @return A reference to the field at aIndex. Reference is valid until 
         *         FieldAt is called again. If you need a permanent copy,
         *         call MVPbkStoreContactField::CloneLC to the returned
         *         field.
         * @see MVPbkStoreContactField::CloneLC
         * @precond aIndex >= 0 && aIndex < FieldCount()
         *          VPbkError::Panic(VPbkError::EInvalidFieldIndex) is raised
         *          if the precondition does not hold.
         */
        virtual MVPbkStoreContactField& FieldAt( TInt aIndex ) = 0;

        /**
         * Returns a copy of the field in this collection.
         *
         * Client gets the ownership of the field.
         *
         * @param aIndex A zero-based index of the field to return.
         * @return  A new instance to the field at aIndex. The field is valid
         *          as long as the parent contact is valid
         * @precond aIndex >= 0 && aIndex < FieldCount()
         *          VPbkError::Panic(VPbkError::EInvalidFieldIndex) is raised
         *          if the precondition does not hold.
         */
        virtual MVPbkStoreContactField* FieldAtLC( TInt aIndex ) const = 0;

        /**
         * Returns the parent contact of the field collection
         *
         * @return the parent contact of the field collection
         */
        virtual MVPbkStoreContact& ParentStoreContact() const = 0;
        
        /**
         * Returns a field in this collection identified by a contact field 
         * link.
         *
         * A contact field link can be created using the MVPbkStoreContactField
         * interface. The same link works then as a contact link and 
         * a field link.
         *
         * NOTE: implementations of stores are possibly using an index
         *       of the field as an identifier so clients should prefer not
         *       to save field links permanently. E.g modifying the contact
         *       can invalidate the link in some store implementations.
         *       A field link is practical in use cases where the link is
         *       created and immediately given to another component.
         *
         * @param aContactLink A valid contact field link.
         * @return A field in this collection identified by aContactLink or NULL
         *          if the link does not contain field information or if the 
         *          link does not refer to the parent contact of this field collection.
         */
        virtual MVPbkStoreContactField* RetrieveField(
            const MVPbkContactLink& aContactLink ) const = 0;

        /**
         * Returns an extension point for this interface or NULL.
         *
         * @param aExtensionUid no extensions defined currently.
         * @return An extension point for this interface or NULL.
         */
        virtual TAny* StoreContactFieldCollectionExtension( 
                TUid /*aExtensionUid*/ ) { return NULL; }
    };


#endif  // MVPBKSTORECONTACTFIELDCOLLECTION_H

//End of file


