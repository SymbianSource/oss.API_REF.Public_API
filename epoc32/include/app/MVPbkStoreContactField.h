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
* Description:  An interface for the field of the store contact
*
*/

#ifndef MVPBKSTORECONTACTFIELD_H
#define MVPBKSTORECONTACTFIELD_H

// INCLUDES
#include <e32std.h>
#include <mvpbkbasecontactfield.h>

// CONSTANTS
/// A constant that indicates that the store doesn't set limits
/// to the length of the label
const TInt KVPbkUnlimitedLabelLength = -1;

// FORWARD DECLARATIONS
class MVPbkContactLink;

// CLASS DECLARATIONS

/**
 * An interface for the field of the store contact.
 *
 * Client can access the contact field using this interface. The field
 * can have a label and a data.
 *
 * A new field can be created using the MVPbkStoreContact interface.
 * For looping the contact fields see MVPbkStoreContactFieldCollection.
 * The parent of the field in the object hierarchy is the store contact.
 *
 * @see CVPbkContactFieldTypeIterator
 * @see CVPbkFieldTypeSelector
 */
class MVPbkStoreContactField : public MVPbkBaseContactField,
                               public MVPbkObjectHierarchy
    {
    public:  // Destructor
        /**
         * Destructor
         */
        virtual ~MVPbkStoreContactField() { }

    public: // From MVPbkBaseContactField
        virtual const MVPbkContactFieldData& FieldData() const = 0;

    public:  // New functions
        /**
         * Returns ETrue if the field supports label.
         *
         * Overwrites the global setting in MVPbkContactStoreProperties.
         * This must be confirmed before using SetFieldLabelL or
         * MaxLabelLength.
         *
         * @return ETrue if the field supports label. Otherwise EFalse.
         */
        virtual TBool SupportsLabel() const = 0;

        /**
         * Returns the label of the field or KNullDesC if there is no field
         * label.
         *
         * @return The label of the field or KNullDesC
         */
        virtual TPtrC FieldLabel() const = 0;

        /**
         * Sets this field's label.
         *
         * SupportsLabel must be true for using this.
         *
         * @param aText The label for the field.
         */
        virtual void SetFieldLabelL( const TDesC& aText ) = 0;

        /**
         * Gets the maximum length of the label.
         *
         * SupportsLabel must be true for using this.
         *
         * @return The maximum length of the label or KVPbkUnlimitedLabelLength
         *         if the store has no limits. Zero should be returned in other
         *         cases though this shouldn't be called if labels are
         *         not supported.
         */
        virtual TInt MaxLabelLength() const = 0;

        /**
         * Returns the data storage (read-write) of the field.
         *
         * The data type depends on the field and it's client's responsibility
         * to check the type before casting the type.
         *
         * @return The data storage of the field.
         * @see MVPbkContactFieldTextData::Cast
         * @see MVPbkContactFieldDateTimeData::Cast
         * @see MVPbkContactFieldBinaryData::Cast
         */
        virtual MVPbkContactFieldData& FieldData() = 0;

        /**
         * Clones the field.
         *
         * Pushes the created copy to the cleanup stack.
         *
         * @return A copy of the field.
         * @see MVPbkStoreContactFieldCollection::FieldAt
         */
        virtual MVPbkStoreContactField* CloneLC() const = 0;

        /**
         * Creates a link representing the contact and the field.
         *
         * The field can be later retrieved using the RetrieveField of
         * MVPbkStoreContactFieldCollection interface.
         *
         * NOTE: implementations of stores are possibly using an index
         *       of the field as an identifier so clients should prefer not
         *       to save field links permanently. E.g modifying the contact
         *       can invalidate the link in some store implementations.
         *       A field link is practical in use cases where the link is
         *       created and immediately given to another component.
         *
         * @return A link representing the contact and the field or NULL
         *         if the contact doesn't exist in the store. E.g a new
         *         contact that hasn't been committed has no unique
         *         identifier yet.
         *         NULL is not put into the CleanupStack.
         */
        virtual MVPbkContactLink* CreateLinkLC() const = 0;

        /**
         * Returns an extension point for this interface or NULL.
         *
         * @param aExtensionUid no extensions defined currently.
         * @return An extension point for this interface or NULL.
         */
        virtual TAny* StoreContactFieldExtension( TUid /*aExtensionUid*/ )
            { return NULL; }
    };


#endif  // MVPBKSTORECONTACTFIELD_H

// End of file
