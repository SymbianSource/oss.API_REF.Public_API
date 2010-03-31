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
* Description:  An interface for store contacts.
*
*/


#ifndef MVPBKSTORECONTACT_H
#define MVPBKSTORECONTACT_H


// INCLUDES
#include <e32base.h>
#include <mvpbkbasecontact.h>
#include <mvpbkviewcontact.h>

// Includes needed for covariant return types
#include <mvpbkstorecontactfieldcollection.h>

// FORWARD DECLARATIONS
class MVPbkContactStore;
class MVPbkContactObserver;
class MVPbkStoreContactField;
class MVPbkFieldType;
class MVPbkContactLinkArray;
class MVPbkContactGroup;
class MVPbkStoreContactProperties;

// CONSTANTS
const TInt KVPbkStoreContactUnlimitedNumber = -1;

//Use this UID to access contact store extension 2.
// Used as a parameter to ContactStoreExtension() method.
const TUid KMVPbkStoreContactExtension2Uid = { 2 };
// CLASS DECLARATIONS

/**
 * An interface for store contacts.
 *
 * A store contact is a contact that includes all the fields of
 * the contact. For this reason it usually contains more data compared
 * to the corresponding view contact. It can contain all types of fields that
 * are supported by the its parent store.
 *
 * The store contact can be edited if it's not read-only. The client must
 * first lock the existing contact then edit it and finally commit the changes.
 *
 * @see MVPbkContactStore
 * @see MVPbkViewContact
 */
class MVPbkStoreContact : public MVPbkBaseContact,
                          public MVPbkObjectHierarchy
    {
    public:  // Destructor
        virtual ~MVPbkStoreContact() { }

    public: // From MVPbkBaseContact (covariant return types)
        const MVPbkStoreContactFieldCollection& Fields() const =0;

    public:  // New functions
        /**
         * Pushes an item on the cleanup stack.
         *
         * Clients must use either this function or CleanupDeletePushL 
         * from e32base.h.
         *
         * CleanupStack::PushL(TAny*) must not be used because the virtual
         * destructor of M-class won't be called.
         * This function should be used to make sure that the virtual destructor
         * of this object is called when popped and destroyed from the cleanup
         * stack.
         */
        inline void PushL();

        /**
         * Returns this contact's parent store.
         *
         * @return The parent store of the contact.
         */
        virtual MVPbkContactStore& ParentStore() const =0;

        /**
         * Returns this contact's fields (read-write).
         *
         * @return A collection of contact fields.
         */
        virtual MVPbkStoreContactFieldCollection& Fields() =0;

        /**
         * Creates a new field for this contact.
         *
         * The new field must be added to the contact using AddFieldL.
         *
         * @param aFieldType  A type of the field to create. Must be found in
         *                    ParentStore().SupportedFieldTypes().
         * @return A new field object. The returned object is left on the
         *         cleanup stack.
         * @exception KErrNotSupported if the field type is not supported.
         * @exception KErrAccessDenied if the contact can not be modified.
         */
        virtual MVPbkStoreContactField* CreateFieldLC(
                const MVPbkFieldType& aFieldType) const =0;

        /**
         * Adds a new field to the contact.
         * 
         * The field must be previously created with CreateFieldLC and
         * it must NOT be used after adding.
         *
         * If the client needs the field after adding it must be retrieved
         * using Fields().
         *
         * @param aField A new field that was created using CreateFieldLC.
         *               This object takes ownership of the field.
         * @precond aField must not be NULL or 
         *          VPbkError::Panic(VPbkError::ENullContactField) is raised.
         * @precond aField must be returned from this->CreateFieldLC or
         *          VPbkError::Panic(VPbkError::EInvalidContactField) panic is raised.
         * @postcond this->Fields().FieldCount() == 
         *           old(this->Fields().FieldCount()) + 1
         * @return The index of the new field in the field collection.
         * @exception KErrAccessDenied if the contact can not be modified.
         */
        virtual TInt AddFieldL(MVPbkStoreContactField* aField) =0;

        /**
         * Removes a field from the contact.
         *
         * @param aIndex A zero-based index of the field to remove.
         * @precond aIndex >= 0 && aIndex < FieldCount().
         *          Panics with VPbkError::EInvalidFieldIndex.
         * @precond The contact is not read-only otherwise panics with 
         *          VPbkError::EInvalidAccessToReadOnlyContact.
         * @postcond this->Fields().FieldCount() == 
         *           old(this->Fields().FieldCount()) - 1
         */
        virtual void RemoveField(TInt aIndex) =0;

        /**
         * Removes all the fields from the contact.
         *
         * @precond The contact is not read-only otherwise panics with 
         *          VPbkError::EInvalidAccessToReadOnlyContact.
         * @postcond this->Fields().FieldCount() == 0
         */
        virtual void RemoveAllFields() =0;

        /**
         * Locks this contact for modification asynchronously.
         *
         * Once the observer is notified this contact is locked and cab
         * be modified.
         *
         * @param aObserver The observer to call back when the operation
         *                  completes. The observer will not be called if this
         *                  function leaves.
         * @exception KErrInUse If another asynchronous operation is 
         *            already in progress.
         * @exception KErrAccessDenied if the contact can not be modified.
         */
        virtual void LockL(MVPbkContactObserver& aObserver) const =0;

        /**
         * Saves the contact to its associated store asynchronously.
         *
         * LockL must have been called before commit if this is
         * an existing contact. Otherwise ContactOperationFailed is called
         * with KErrAccessDenied.
         *
         * @param aObserver The observer to call back when this operation
         *                  completes. The observer will not be called if this
         *                  function leaves.
         * @exception KErrInUse If another asynchronous operation is already
         *            in progress.
         * @exception KErrAccessDenied if the contact can not be modified.
         */
        virtual void CommitL(MVPbkContactObserver& aObserver) const =0;

        /**
         * Returns the identifiers of the groups that the contact 
         * belongs to.
         *
         * @return The groups that this contact belongs to.
         */
        virtual MVPbkContactLinkArray* GroupsJoinedLC() const =0;

        /**
         * Returns the group interface of the store contact if this contact
         * is a group.
         * If this contact is not a group, NULL is returned.
         *
         * @return The group interface or NULL.
         */
        virtual MVPbkContactGroup* Group() =0;
        
        /**
         * Returns the maximum amount of fields of given type that can be
         * inserted to the contact.
         *
         * E.g. A USIM ADN contact can have 1 or more phone numbers but there
         * is a limit that the store in USIM defines.
         * On the other hand the contact in the Contacts Model data base
         * doesn't have limits.
         *
         * @param aType The field type of the field
         * @return The maximum amount fields of given type in the contact
         *         or KVPbkStoreContactUnlimitedNumber it there is no limit
         *         set by the store contact
         */
        virtual TInt MaxNumberOfFieldL(const MVPbkFieldType& aType) const =0;

        
        /**
         * Returns an extension point for this interface or NULL.
         *
         * @param aExtensionUid no extensions defined currently.
         * @return An extension point for this interface or NULL.
         */
        virtual TAny* StoreContactExtension(TUid /*aExtensionUid*/) 
                { return NULL; }

    public:  // from MVPbkBaseContact
        /// Do not override
        virtual TBool IsSame(const MVPbkBaseContact& aOtherContact) const
            {
            return aOtherContact.IsSame(*this);
            }

        // Do not override
        virtual TBool IsSame(const MVPbkViewContact& aOtherContact) const
            {
            return aOtherContact.IsSame(*this, &ContactStore());
            }
    };


// INLINE FUNCTIONS
inline void MVPbkStoreContact::PushL()
    {
    CleanupDeletePushL(this);
    }

#endif  // MVPBKSTORECONTACT_H

//End of file
