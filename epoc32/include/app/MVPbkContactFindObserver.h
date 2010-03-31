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
* Description:  Virtual Phonebook observer interface for find operation.
*
*/


#ifndef MVPBKCONTACTFINDOBSERVER_H
#define MVPBKCONTACTFINDOBSERVER_H

// INCLUDE FILES
#include <e32cmn.h>
#include <e32base.h>
// included here, instead of forward declared, so that clients
// don't delete an incomplete class.
#include <mvpbkcontactlinkarray.h>


/**
 * Virtual Phonebook Find observer.
 * This interface is used to signal find clients of the operation 
 * progress and give the find results to the client.
 */
class MVPbkContactFindObserver
    {
    public: // Interface
        /**
         * Called when find is complete. Caller takes ownership of the results
         * In case of an error during find, the aResults may contain only 
         * partial results of the find
         *
         * @param aResults Array of contact links that matched the find
         *                 Callee must take ownership of this object in
         *                 the start of the function, ie. in case the 
         *                 function leaves the results must be destroyed. 
         *                 The find operation can be destroyed at the end 
         *                  of this callback.
         */
        virtual void FindCompleteL( MVPbkContactLinkArray* aResults ) = 0;

        /**
         * Called in case the find fails for some reason. The find operation
         * can be destroyed at the end of this callback.
         * 
         * @param aError One of the system wide error codes.
         *        KErrNotReady if store is not ready (not open or unavailable)
         */
        virtual void FindFailed( TInt aError ) = 0;

        /**
         * Returns an extension point for this interface or NULL.
         * @param aExtensionUid Uid of extension.
         * @return Extension point or NULL.
         */
        virtual TAny* ContactFindObserverExtension( 
                TUid /*aExtensionUid*/ ) { return NULL; }

    protected:  // Destructor
        /**
         * Destructor.
         */
        virtual ~MVPbkContactFindObserver() { }

	};

#endif // MVPBKCONTACTFINDOBSERVER_H

// End of File
