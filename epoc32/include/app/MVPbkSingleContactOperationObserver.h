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
* Description:  An observer interface for asynchronous single contact 
*                operations
*
*/


#ifndef MVPBKSINGLECONTACTOPERATIONOBSERVER_H
#define MVPBKSINGLECONTACTOPERATIONOBSERVER_H

// INCLUDES
#include <e32cmn.h>

// FORWARD DECLARATIONS
class MVPbkContactOperationBase;
class MVPbkStoreContact;

// CLASS DECLARATIONS

/**
 * An observer interface for asynchronous single contact operations.
 * 
 * The interface is used in asynchronous operations that are related
 * to one contact.
 */
class MVPbkSingleContactOperationObserver
    {
    public:  // Interface
        /**
         * Called when the operation is completed.
         *
         * A client has the operation as a member and it can delete the operation
         * instance in this function call. If the implementation of the store
         * calls the function from the operation instance it must not handle
         * any member data after calling it.
         *
         * @param aOperation The completed operation.
         * @param aContact The contact returned by the operation.
         *                 A client must take the ownership immediately.
         *
         *                  NOTE:
         *                  If you use CleanupStack for MVPbkStoreContact
         *                  Use MVPbkStoreContact::PushL or
         *                  CleanupDeletePushL from e32base.h.
         *                  (Do Not Use CleanupStack::PushL(TAny*) because
         *                  then the virtual destructor of the M-class
         *                  won't be called when the object is deleted).
         */
        virtual void VPbkSingleContactOperationComplete(
                MVPbkContactOperationBase& aOperation,
                MVPbkStoreContact* aContact ) = 0;

        /**
         * Called if the operation fails.
         *
         * A client has the operation as a member and it can delete the operation
         * instance in this function call. If the implementation of the store
         * calls the function from the operation instance it must not handle
         * any member data after calling it.
         *
         * @param aOperation The failed operation.
         * @param aError An error code of the failure.
         */
        virtual void VPbkSingleContactOperationFailed(
                MVPbkContactOperationBase& aOperation, 
                TInt aError ) = 0;

        /**
         * Returns an extension point for this interface or NULL.
         *
         * @param aExtensionUid no extensions defined currently.
         * @return An extension point for this interface or NULL.
         */
        virtual TAny* SingleContactOperationObserverExtension( 
                TUid /*aExtensionUid*/ ) { return NULL; }

    protected:  // Destructor
        virtual ~MVPbkSingleContactOperationObserver() { }

    };

#endif // MVPBKSINGLECONTACTOPERATIONOBSERVER_H

//End of file

