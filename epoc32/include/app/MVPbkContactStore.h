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
* Description:  Virtual Phonebook contact store interface.
*
*/


#ifndef MVPBKCONTACTSTORE_H
#define MVPBKCONTACTSTORE_H

// INCLUDES
#include <e32def.h>
#include <mvpbkobjecthierarchy.h>
#include <mvpbkcontactoperationfactory.h>

// FORWARD DECLARATIONS
class CVPbkContactViewDefinition;
class MVPbkContactStoreObserver;
class MVPbkContactStoreProperties;
class MVPbkStoreContact;
class MVPbkContactGroup;
class MVPbkContactView;
class MVPbkContactLink;
class MVPbkFieldTypeList;
class MVPbkContactViewObserver;
class MVPbkContactStoreInfo;
class MVPbkSingleContactLinkOperationObserver;
class MVPbkContactOperationBase;

//Use this UID to access contact store extension 2. Used as a parameter to ContactStoreExtension() method.
const TUid KMVPbkContactStoreExtension2Uid = { 2 };

// CLASS DECLARATIONS

/**
 * A contact store interface that is implemented by all contact stores.
 *
 * Using this interface clients can access a single contact store. Usually
 * it's more suitable to use CVPbkContactManager and MVPbkContactStoreList
 * for accessing stores because multiple stores can be handled at a same
 * time.
 *
 * The store is opened asynchronously and it must not be used before
 * notification has arrived. If client opens the store it must also
 * close the store after usage.
 *
 * The interface can be used for retriveing properties and information
 * of the store and also for creating a view, a new contact or a
 * new group (if supported).
 *
 */
class MVPbkContactStore :
        public MVPbkObjectHierarchy,
        public MVPbkContactOperationFactory
    {
    public:  // Destructor

        /**
         * Clients don't destroy the stores directly because they don't
         * own them. The ownerships are managed by CVPbkContactManager.
         */
        virtual ~MVPbkContactStore() { }

    public:  // New functions
        /**
         * Returns fixed properties of this contact store.
         *
         * Fixed properties do not change when the store is open.
         * The store must be opened before retrieving the properties.
         *
         * @return Store properties.
         */
        virtual const MVPbkContactStoreProperties& StoreProperties() const = 0;

        /**
         * Opens this contact store asynchronously.
         *
         * Calls back the observer when the opening completes. Notice
         * that the same store instance can be opened by several observers.
         *
         * @param aObserver An observer for the store.
         * @exception KErrInUse If another asynchronous operation
         *            is already in progress.
         */
        virtual void OpenL(
                MVPbkContactStoreObserver& aObserver ) = 0;

        /**
         * Replaces an existing store and opens it asynchronously.
         *
         * E.g. If the database is a file then this replaces the database if
         * it's not locked by other clients. If the store
         * implementation can not implment replacing then this behaves
         * like OpenL.
         *
         * If the store does not exist, it is created if possible.
         * Calls back the observer when the opening completes.
         *
         * @param aObserver An observer for the store.
         */
        virtual void ReplaceL(
                MVPbkContactStoreObserver& aObserver ) = 0;

        /**
         * Closes this contact store from a single observer.
         *
         * This can be always called safely even if OpenL or ReplaceL
         * hasn't been called.
         * If the client calls OpenL it must also call this after usage,
         * The observer will no longer receive events from this store.
         * If there are other observers for the store then the store
         * will remain open for them.
         *
         * @param aObserver An observer that was given in OpenL or ReplaceL.
         */
        virtual void Close(
                MVPbkContactStoreObserver& aObserver ) = 0;

        /**
         * Creates a new contact associated to this store.
         *
         * The contact can be edited and then it must be committed by
         * calling MVPbkStoreContact::CommitL for actually saving
         * it to the store.
         *
         * @return A new contact associated to this store. Caller takes
         *         ownership of the returned contact.
         * @see MVPbkStoreContact
         * @see MVPbkStoreContact::CommitL
         */
        virtual MVPbkStoreContact* CreateNewContactLC() = 0;

        /**
         * Creates a new contact group associated to this store.
         *
         * MVPbkContactStoreProperties::SupportsContactGroups must be
         * true if this is used.
         * The contact group might be saved to the store immeadiately
         * depending on the store implementation.
         * It is left open for editing. Use CommitL to commit
         * the creation of the group and its content.
         *
         * @return A new contact group associated to this store. Caller takes
         *         the ownership of the returned contact group.
         * @exception KErrNotSupported if the store doesn't support groups.
         *              Client should check store properties before
         *              calling this.
         * @see MVPbkContactStoreProperties
         * @see MVPbkContactGroup
         * @see MVPbkStoreContact
         * @see MVPbkStoreContact::CommitL
         */
        virtual MVPbkContactGroup* CreateNewContactGroupLC() = 0;

        /**
         * Creates a new contact view from the store asynchronously.
         *
         * Client gets the ownership of the view. The content of
         * the view depends on the CVPbkContactViewDefinition. The
         * client must wait the observer event before using the view.
         *
         * @param aViewDefinition Defines the properties of the new view.
         * @param aObserver An observer for the view events.
         * @param aSortOrder Field types that are used in the view contact
         *                   in the same order as in this list. Notice that
         *                   stores may not support all possible field types
         *                   in a view contact. The implementation
         *                   of the view contact must have as many fields as
         *                   the sort order. If the store doesn't support the
         *                   field type in a view contact then it sets empty
         *                   data to the field.
         * @return  A new contact view object. Caller takes ownership of the
         *          returned contact.
         * @see MVPbkContactView
         * @see CVPbkContactViewDefinition
         */
        virtual MVPbkContactView* CreateViewLC(
                const CVPbkContactViewDefinition& aViewDefinition,
                MVPbkContactViewObserver& aObserver,
                const MVPbkFieldTypeList& aSortOrder ) = 0;

        /**
         * Returns contact groups contained in this store.
         *
         * MVPbkContactStoreProperties::SupportsContactGroups must be
         * true if this is used. Implementation should return an empty
         * link array and not NULL.
         *
         * @return Contact group identifiers contained in this store.
         */
        virtual MVPbkContactLinkArray* ContactGroupsLC() const = 0;

        /**
         * Returns a contact store information. Information can vary
         * runtime.
         *
         * @return Contact store information.
         */
        virtual const MVPbkContactStoreInfo& StoreInfo() const = 0;

        /**
         * This is part of Virtual Phonebook internal framefork and not
         * usable for clients. Clients use CVPbkContactManager
         * for creating links from a stream.
         *
         * Creates a link array from a stream. Stream contains the internals
         * of the contact link. Internals are the contact store implementation
         * specific part of the package format.
         *
         * NOTE: this must work wheter the OpenL has been called or not. This
         *       means that a link can not contain any data that would need
         *       an open store before internalizing.
         *
         * @param aStream A stream containing the link internals.
         * @return A new contact link.
         * @internal
         */
        virtual MVPbkContactLink* CreateLinkFromInternalsLC(
                RReadStream& aStream ) const = 0;

        /**
         * Returns an extension point for this interface or NULL.
         *
         * @param aExtensionUid no extensions defined currently.
         * @return an extension point for this interface or NULL.
         */
        virtual TAny* ContactStoreExtension(TUid /*aExtensionUid*/)
                { return NULL; }

    public: // From MVPbkObjectHierarchy

        MVPbkObjectHierarchy& ParentObject() const
            {
            return const_cast<MVPbkObjectHierarchy&>
                ( static_cast<const MVPbkObjectHierarchy&>( *this ) );
            }
        MVPbkContactStore& ContactStore() const
            {
            return const_cast<MVPbkContactStore&>( *this );
            }

    };

#endif // MVPBKCONTACTSTORE_H

// End of File
