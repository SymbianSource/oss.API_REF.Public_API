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
* Description:  Virtual Phonebook base interface for contacts.
*
*/


#ifndef MVPBKBASECONTACT_H
#define MVPBKBASECONTACT_H

// INCLUDES
#include <e32cmn.h>
#include <e32def.h>

// FORWARD DECLARATIONS
class MVPbkContactObserver;
class MVPbkBaseContactFieldCollection;
class MVPbkContactLink;
class MVPbkContactBookmark;
class MVPbkViewContact;
class MVPbkStoreContact;

// CLASS DECLARATIONS

/**
 * Virtual Phonebook read-only base contact interface.
 * This class is used as a high-level interface for contacts in the
 * Virtual Phonebook.
 */
class MVPbkBaseContact
    {
    protected:  // Destructor
        /**
         * Destructor.
         */
        virtual ~MVPbkBaseContact() { }

    public:  // Interface
        /**
         * Returns this contact's fields (read only).
         * @return This contact's fields in read only mode.
         */
        virtual const MVPbkBaseContactFieldCollection& Fields() const =0;

        /**
         * Returns true if this a representation of the same contact.
         *
         * @param aOtherContact a contact this contact is compared against.
         * @return ETrue if this and aOtherContact represent the same contact.
         */
        virtual TBool IsSame(const MVPbkBaseContact& aOtherContact) const =0;

        /**
         * Returns true if this a representation of the same contact.
         *
         * @param aOtherContact a contact this contact is compared against.
         * @return ETrue if this and aOtherContact represent the same contact.
         */
        virtual TBool IsSame(const MVPbkStoreContact& aOtherContact) const =0;

        /**
         * Returns true if this a representation of the same contact.
         *
         * @param aOtherContact a contact this contact is compared against.
         * @return ETrue if this and aOtherContact represent the same contact.
         */
        virtual TBool IsSame(const MVPbkViewContact& aOtherContact) const =0;

        /**
         * Creates link representing this contact.
         *
         * @return A link or NULL if the contact doesn't exist in the store,
         *         e.g. a folding contact in the view could be that kind or
         *         a new contact that hasn't been committed to the store.
         *         NULL is not put into the CleanupStack.
         */
        virtual MVPbkContactLink* CreateLinkLC() const =0;

        /**
         * Deletes this contact from store asynchronously.
         *
         * @param aObserver The observer to call back when this operation
         *                  completes. The observer will not be called
         *                  if this function leaves.
         * @exception KErrInUse If another asynchronous operation is already
         *                      in progress.
         * @exception KErrAccessDenied if the contact can not be modified.
         */
        virtual void DeleteL(MVPbkContactObserver& aObserver) const =0;

        /**
         * Returns ETrue if this view contact is from given store
         *
         * @param aContactStoreUri the URI of the store to compare
         * @return ETrue if the view contact was from the given store
         */
        virtual TBool MatchContactStore(
                const TDesC& aContactStoreUri) const =0;

        /**
         * Returns ETrue if this contact is from the same store
         * domain as the given one.
         *
         * @param aContactStoreDomain the the store domain
         * @return ETrue if the contact was from the same store domain.
         */
        virtual TBool MatchContactStoreDomain(
                const TDesC& aContactStoreDomain) const =0;

        /**
         * Creates and returns a bookmark that points to the contact.
         * Bookmark can be used to retrieve an index of the contact in
         * the view.
         *
         * @return A new bookmark to the contact
         */
        virtual MVPbkContactBookmark* CreateBookmarkLC() const =0;

        /**
         * Returns an extension point for this interface or NULL.
         * @param aExtensionUid Extension identifier.
         */
        virtual TAny* BaseContactExtension(TUid /*aExtensionUid*/)
                { return NULL; }
    };

//Use this UID to access base contact extension 2.
// Used as a parameter to BaseContactExtension() method.
const TUid KVPbkBaseContactExtension2Uid = { 2 };

/**
 * This class is an extension to MVPbkBaseContact.
 * See documentation of MVPbkBaseContact from header MVPbkBaseContact.h
 *
 * @see MVPbkBaseContact
 *
 */
class MVPbkBaseContact2
    {
    protected:  // Destructor
        virtual ~MVPbkBaseContact2() { }

    public:

        /**
         * Function returns true if contact is the store's current own contact.
         *
         * @param aError KErrNotSupported If store does not support own contact
         */
        virtual TBool IsOwnContact( TInt& aError ) const =0;

    };


#endif  // MVPBKBASECONTACT_H

// End of file
