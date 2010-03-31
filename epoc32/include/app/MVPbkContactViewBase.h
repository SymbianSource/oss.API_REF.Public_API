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
* Description:  An interface for contact views.
*
*/


#ifndef MVPBKCONTACTVIEWBASE_H
#define MVPBKCONTACTVIEWBASE_H

// INCLUDES
#include <e32cmn.h>
#include <vpbkcontactview.hrh>
#include <bamdesca.h>

// FORWARD DECLARATIONS
class MVPbkContactViewObserver;
class MVPbkViewContact;
class MVPbkContactLink;
class MVPbkFieldTypeList;
class MVPbkContactBookmark;
class MVPbkContactViewFiltering;

// CLASS DECLARATIONS

/**
 * An common interface for different contact views.
 * 
 * The contact view interface has many implementations. It can be a view from
 * a single contact store or it can be a composite of contact/group views from
 * different stores. It's also possible that it contains folding items that
 * are not from any store. The client defines the view structure.
 * 
 * The most common usage is that client uses CVPbkContactManager 
 * for creating a contact view and defines the structure of the view.
 * @see CVPbkContactManager::CreateContactViewLC
 */
class MVPbkContactViewBase
    {
    public:  // Destructor

        /**
         * Destructor.
         */
        virtual ~MVPbkContactViewBase() { }

    public:  // New functions

        /**
         * Returns type of this contact view.
         *
         * @return A contact view type.
         */
        virtual TVPbkContactViewType Type() const = 0;

        /**
         * Changes sort order of the view asynchronously.
         *
         * Clients of this view will get an event via MVPbkContactViewObserver
         * interface when the order has been updated. The leaf view sends
         * a pair of events. First it sends ContactViewUnavailable and then
         * after the order has been changed ContactViewReady. However if
         * the view is of type EVPbkCompositeView the client doesn't necessary
         * receive ContactViewUnavailable at all because it might be that
         * there is always some subview ready in the composite.
         *
         * @param aSortOrder A new sort order for this view.
         * @exception KErrArgument Possible reasons: a client tries to change
         *                         a sort order of platform defined shared
         *                         view against the platform setting.
         * @see CVPbkSortOrder
         */
        virtual void ChangeSortOrderL(
                const MVPbkFieldTypeList& aSortOrder ) = 0;

        /**
         * Returns the current sort order of the view.
         *
         * The sort order is a sub set of master field types from
         * CVPbkContactManager.
         *
         * @return The sort order of the view.
         */
        virtual const MVPbkFieldTypeList& SortOrder() const = 0;

        /**
         * Refreshes the view contents asynchronously.
         * 
         * All handles to this view's contacts are invalidated.
         * Clients of this view will get an event via MVPbkContactViewObserver
         * interface when the view has been refreshed.
         */
        virtual void RefreshL() = 0;
        
        /**
         * Returns the number of contacts in this view.
         *
         * @return The number of contacts.
         */
        virtual TInt ContactCountL() const = 0;

        /**
         * Returns a contact in this view. 
         *
         * The returned reference may be invalidated when this 
         * function is called again. For that reason clients should prefer
         * not to save references to the contacts retrieved from this function.
         *
         * @param aIndex An index of the contact in this view.
         * @return A reference to a contact in this view at aIndex.
         * @precond aIndex >= 0
         *              VPbkError::Panic(VPbkError::EInvalidContactIndex)
         *              is raised if the precondition does not hold.
         * @exception KErrArgument if aIndex >= ContactCountL()
         */
        virtual const MVPbkViewContact& ContactAtL(
                TInt aIndex ) const = 0;

        /**
         * Creates and returns a link that points to contact at aIndex.
         *
         * NOTE: If the view contact is not from any store it can return
         *       also NULL. E.g. if the view contact is a folding 
         *       contact view that it's not saved to any store.
         *       The NULL is not pushed onto the cleanup stack.
         *
         * @param aIndex An index of the contact for which the link
         *               is created.
         * @return A new link object pointing to contact at aIndex or NULL if
         *          the link can't be created (e.g. a folder).
         * @precond aIndex >= 0
         *          VPbkError::Panic(VPbkError::EInvalidContactIndex)
         *          is raised if the precondition does not hold.
         * @exception KErrArgument if aIndex >= ContactCountL()
         */
        virtual MVPbkContactLink* CreateLinkLC(
                TInt aIndex ) const = 0;

        /**
         * Returns The index of the aContactLink in this view.
         *
         * If the identifier is not found from the view then
         * KErrNotFound is returned. If the view is not from
         * any store (e.g. a folding view) then it will also
         * return KErrNotFound.
         *
         * NOTE: the implementation of this function probably
         *       must loop the view which means that calling
         *       this function frequently or in a loop can
         *       be slow when there are lots of contacts.
         *
         * @param aContactLink A link whose index is searched for.
         * @return The index of the link or KErrNotFound.
         */
        virtual TInt IndexOfLinkL(
                const MVPbkContactLink& aContactLink ) const = 0;

        /**
         * Adds an observer to this contact view asynchronously. 
         *
         * The observer will be notified after it has been added
         * to the view.
         *
         * @param aObserver A new observer for the view.
         */
        virtual void AddObserverL(
                MVPbkContactViewObserver& aObserver ) = 0;

        /**
         * Removes an observer from this contact view.
         *
         * This method can be called even if aObserver has not been
         * previously added. In that case, no observers are removed.
         *
         * @param aObserver The observer to be removed.
         */
        virtual void RemoveObserver(
                MVPbkContactViewObserver& aObserver ) = 0;
        
        /**
         * Returns ETrue if this view is from a store identified 
         * by aContactStoreUri.
         *
         * @param aContactStoreUri The whole URI of the contact store.
         * @return ETrue if the view was from the given store.
         *
         * @see TVPbkContactStoreUriPtr::UriDes
         */
        virtual TBool MatchContactStore(
                const TDesC& aContactStoreUri ) const = 0;
        
        /**
         * Returns ETrue if this view is from a store domain identified 
         * by aContactStoreDomain.
         *
         * @param aContactStoreDomain The domain part of the contact store URI.
         *                            The domain can be retrieved from the 
         *                            whole contact store URI using class 
         *                            TVPbkContactStoreUriPtr and 
         *                            EContactStoreUriStoreType.
         *                            An implementation compares the
         *                            EContactStoreUriStoreType part of 
         *                            its own URI to aContactStoreDomain.
         *                            
         * @return ETrue if the view was from the same store domain.
         * @see TVPbkContactStoreUriPtr
         */
        virtual TBool MatchContactStoreDomain(
                const TDesC& aContactStoreDomain ) const = 0;
        
        /**
         * Creates and returns a bookmark that points to the
         * view contact at aIndex.
         *
         * @param aIndex An index of the contact in the view.
         * @return A new bookmark to the view item.
         * @precond aIndex >= 0
         *          VPbkError::Panic(VPbkError::EInvalidContactIndex)
         *          is raised if the precondition does not hold.
         */
        virtual MVPbkContactBookmark* CreateBookmarkLC(
                TInt aIndex ) const = 0;

        /**
         * Returns an index of the contact in the view.
         *
         * If the identifier is not found from the view then
         * KErrNotFound is returned.
         *
         * NOTE: the implementation of this function probably
         *       must loop the view which means that calling
         *       this function frequently or in a loop can
         *       be slow when there are lots of contacts.
         *
         * @param aContactBookmark A bookmark that identifies
         *                         a contact in the view.
         * @return An index of the contact in the view or KErrNotFound.
         */
        virtual TInt IndexOfBookmarkL(
                const MVPbkContactBookmark& aContactBookmark ) const = 0;
        
        /**
         * Returns an interface for text based contact filtering support.
         *
         * If the view doesn't support filtering then this returns NULL. 
         * Filtering must be supported in all views created from a contact
         * store. However, it's possible to implement a view that doesn't
         * need a filtering support and therefore clients must always check
         * the returned pointer.
         *
         * @return A filtering interface or NULL
         */
        virtual MVPbkContactViewFiltering* ViewFiltering() = 0;
        
        /**
         * Returns an extension point for this interface or NULL.
         *
         * @param aExtensionUid no extensions defined currently.
         * @return an extension point for this interface or NULL.
         */
        virtual TAny* ContactViewBaseExtension(TUid /*aExtensionUid*/) 
                { return NULL; }
    };


#endif // MVPBKCONTACTVIEWBASE_H

// End of File
