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
* Description:  An observer interface for observing events related
*                to a list of contact stores
*
*/


#ifndef MVPBKCONTACTSTORELISTOBSERVER_H
#define MVPBKCONTACTSTORELISTOBSERVER_H


// INCLUDES
#include <mvpbkcontactstoreobserver.h>

// CLASS DECLARATIONS

/**
 * An observer interface for observing events from a list of contact stores.
 *
 * The interface is implemented by the client who is opening a list of stores.
 *
 * @see MVPbkContactStoreList
 */
class MVPbkContactStoreListObserver : public MVPbkContactStoreObserver
    {
    public:  // New functions
        /**
         * Called when the opening process is complete. 
         *
         * Before this all stores have sent StoreReady or StoreUnavailable 
         * event. The client can not trust that all stores are available
         * for use when this is called.
         */
        virtual void OpenComplete() =0;
        
        /**
         * Returns an extension point for this interface or NULL.
         *
         * @param aExtensionUid no extensions defined currently.
         * @return an extension point for this interface or NULL.
         */
        virtual TAny* ContactStoreListObserverExtension(TUid /*aExtensionUid*/)
                { return NULL; }

    protected:  // Destructor
        virtual ~MVPbkContactStoreListObserver() { }

    };


#endif  // MVPBKCONTACTSTORELISTOBSERVER_H

//End of file
