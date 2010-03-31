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
* Description:  An interface for a list of contact stores.
*
*/


#ifndef MVPBKCONTACTSTORELIST_H
#define MVPBKCONTACTSTORELIST_H

// INCLUDES
#include <e32std.h>

// FORWARD DECLARATIONS
class MVPbkContactStore;
class MVPbkContactStoreListObserver;
class TVPbkContactStoreUriPtr;


// CLASS DECLARATIONS
/**
 * An interface for a list of contact stores.
 *
 * The interface provides an access to multiple stores. It's possible to open
 * and close all stores in single call using this interface. When client calls
 * OpenAllL it must also calls CloseAll after usage.
 *
 * @see CVPbkContactManager::ContactStoresL
 */
class MVPbkContactStoreList
    {
    public: // interface
        virtual ~MVPbkContactStoreList() { }

        /**
         * Returns the number of stores in the list.
         *
         * @return The number of stores in the list.
         */
        virtual TInt Count() const =0;

        /**
         * Returns the store in given index in the list.
         *
         * @param aIndex the index of the store in the list
         * @precond aIndex >= 0 && aIndex < Count()
         *              VPbkError::Panic(VPbkError::EInvalidStoreIndex)
         *              is raised if the precondition does not hold.
         * @return The store in the specified index.
         */
        virtual MVPbkContactStore& At(TInt aIndex) const =0;

        /**
         * Finds the contact store corresponding to the aUri.
         *
         * @param aUri the store URI to search for.
         * @return The contact store corresponding to the aUri or NULL.
         */
        virtual MVPbkContactStore* Find(
            const TVPbkContactStoreUriPtr& aUri) const =0;

        /**
         * Opens all stores in the list asynchronously.
         *
         * A client can not use stores before it has successfully opened
         * them. CloseAll must be always called by the same observer that has
         * opened stores.
         *
         * NOTE: There can be only one observer for one store list at a time.
         *
         * @param aObserver An observer for the stores.
         * @exception KErrInUse If one observer is currently opening this list.
         */
        virtual void OpenAllL(MVPbkContactStoreListObserver& aObserver) =0;

        /**
         * Closes all stores in the list.
         *
         * This is safe to call in all circumstances. Implementations
         * can not trust that OpenAllL has been called before.
         *
         * @param aObserver An observer for the close process.
         */
        virtual void CloseAll(MVPbkContactStoreListObserver& aObserver) =0;

        /**
         * Returns an extension point for this interface or NULL.
         *
         * @param aExtensionUid no extensions defined currently.
         * @return an extension point for this interface or NULL.
         */
        virtual TAny* ContactStoreListExtension(TUid /*aExtensionUid*/) 
                { return NULL; }

    };

#endif // MVPBKCONTACTSTORELIST_H

//End of file
