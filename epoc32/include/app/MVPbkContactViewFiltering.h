/*
* Copyright (c) 2006-2007 Nokia Corporation and/or its subsidiary(-ies).
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
* Description:  An interface for text based contact view filtering.
*
*/


#ifndef M_MVPBKCONTACTVIEWFILTERING_H
#define M_MVPBKCONTACTVIEWFILTERING_H

#include <e32def.h>
#include <bamdesca.h>

// FORWARDS DECLARATIONS
class MVPbkContactViewBase;
class MVPbkContactViewObserver;
class MVPbkContactBookmarkCollection;

/**
 * An interface for text based contact view filtering.
 *
 * Contact views can support filtering based on search string and
 * always included contacts by implementing this interface.
 *
 * A view stack usage:
 *
 * The client can create a stack structure of filtered views. E.g
 *
 * 1) Client creates a filtered view using find text "J"
 * 2) It then waits that the new view becomes ready.
 * 3) Then it uses the new view to create next level view for "Jo".
 * 4) The client waits that the new view becomes ready.
 * 5) The client again uses the new view for creating third level view "Joe"
 * 6) After the third filtered view becomes ready the client has 4 views:
 *    The base view that includes all the contacts and 3 filtered views
 *    for texts "J", "Jo" and "Joe". It's up to store implementation
 *    to optimize the used resources in case the store supports thousands
 *    of contacts.
 *
 * If client uses always included contacts then they must be same for all
 * views in a stack.
 *
 * View events must come in order: bottom view first.
 */
class MVPbkContactViewFiltering
    {
public:
    /**
     * Creates a new filtered view asynchronously.
     * 
     * The parent view will be filtered according to given criteria and
     * then the client will be notified via MVPbkContactViewObserver.
     * The parent view must be ready before creating a new filtered view,
     * The created view must be destroyed before the parent view and
     * not vice versa.
     *
     * @param aObserver The observer that will be notified when the view
     *                  is ready. Client shouldn't use the view before
     *                  it has been notified.
     * @param aFindWords An array of words that must match to the contact.
     * @param aAlwaysIncluded Contacts that must be in the view
     *                        even they don't match to aFindWords.
     *                        This an optional parameter. Give
     *                        NULL if not needed. Client must keep
     *                        the instance alive while the view exists.
     * @return a filtered view that must also support view filtering.
     */
    virtual MVPbkContactViewBase* CreateFilteredViewLC( 
            MVPbkContactViewObserver& aObserver,
            const MDesCArray& aFindWords,
            const MVPbkContactBookmarkCollection* aAlwaysIncluded ) = 0;
    
    /**
     * Updates an existing filtered view asynchronously. 
     * 
     * This must be implemented by the views that were previously
     * created by CreateFilteredViewLC. Otherwise leaves with KErrNotSupported.
     *
     * @param aFindWords an array of words that must match to the contact.
     * @param aAlwaysIncluded Contacts that must be in the view
     *                        even they don't match to aFindWords.
     *                        This an optional parameter. Give
     *                        NULL if not needed. Client must keep
     *                        the instance alive while the view exists.
     * @exception KErrNotSupported if the view itself is not a filtered view.
     */
    virtual void UpdateFilterL( 
            const MDesCArray& aFindWords,
            const MVPbkContactBookmarkCollection* aAlwaysIncluded ) = 0;
        
    /**
     * Returns an extension point for this interface or NULL.
     *
     * @param aExtensionUid no extensions defined currently.
     * @return an extension point for this interface or NULL.
     */
    virtual TAny* ContactViewFilteringExtension(TUid /*aExtensionUid*/) 
        { return NULL; }
        
protected:

    /**
     * Virtual Phonebook client doesn't own this instance.
     */
	~MVPbkContactViewFiltering() {}
    };


#endif // M_MVPBKCONTACTVIEWFILTERING_H
