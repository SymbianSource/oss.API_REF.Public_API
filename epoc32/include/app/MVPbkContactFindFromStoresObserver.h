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
* Description:  Virtual Phonebook observer API for finding contacts from 
*                the stores.
*
*/


#ifndef MVPBKCONTACTFINDFROMSTORESOBSERVER_H
#define MVPBKCONTACTFINDFROMSTORESOBSERVER_H


#include <e32def.h>
// included here, instead of forward declared, so that clients
// dont delete an incomplete class.
#include <mvpbkcontactlinkarray.h>

class MVPbkContactStore;

/**
 * An observer interface for finding contacts from the stores.
 * This interface is used to signal find clients of the 
 * operations progress.
 */
class MVPbkContactFindFromStoresObserver
    {
    public: // Interface
        /**
         * This is called when one store completes its find. If this
         * leaves then FindFromStoreFailed is called. Client takes 
         * the ownership of all results immediately!
         *
         * FindFromStoresOperationComplete is called after
         * all stores have called either this or FindFromStoreFailed.
         *
         * @param aStore    The store whose find results are available
         * @param aResultsFromStore The find results from the store.
         *                          Client takes the ownership immediately!
         */
        virtual void FindFromStoreSucceededL( MVPbkContactStore& aStore, 
            MVPbkContactLinkArray* aResultsFromStore ) = 0;

        /**
         * Called when a find operation of one store fails. Doesn't stop
         * the find from other stores in the case there are multiple stores.
         *
         * @param aStore    The failed store.
         * @param aError    A system wide error code from the 
         *                  store implementation.
         */
        virtual void FindFromStoreFailed( 
                MVPbkContactStore& aStore, TInt aError ) = 0;

        /**
         * This is called after all stores have called either 
         * FindFromStoreSucceed or FindFromStoreFailed. It's called 
         * also when there are no stores that offer find operation.
         */
        virtual void FindFromStoresOperationComplete() = 0;
            
        /**
         * Returns an extension point for this interface or NULL.
         * @param aExtensionUid Uid of extension.
         * @return Extension point or NULL.
         */
        virtual TAny* ContactFindFromStoresObserverExtension(
                TUid /*aExtensionUid*/) { return NULL; }

    protected:
        /**
         * Destructor.
         */
        virtual ~MVPbkContactFindFromStoresObserver() {}

    };

#endif // MVPBKCONTACTFINDFROMSTORESOBSERVER_H

// End of File
