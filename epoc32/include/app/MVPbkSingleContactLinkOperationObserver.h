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
* Description:  An observer interface for asynchronous single contact link
*                operations
*
*/


#ifndef MVPBKSINGLECONTACTLINKOPERATIONOBSERVER_H
#define MVPBKSINGLECONTACTLINKOPERATIONOBSERVER_H

// INCLUDES
#include <e32cmn.h>

// FORWARD DECLARATIONS
class MVPbkContactOperationBase;
class MVPbkContactLink;

// CLASS DECLARATIONS

/**
 * An observer interface for asynchronous single contact link operations.
 * 
 * The interface is used in asynchronous operations that are related
 * to one contact link.
 */
class MVPbkSingleContactLinkOperationObserver
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
         * @param aLink    The contact link returned by the operation.
         *                 A client must take the ownership immediately.
         *
         *                  NOTE:
         *                  If you use CleanupStack for MVPbkContactLink
         *                  Use CleanupDeletePushL from e32base.h.
         *                  (Do Not Use CleanupStack::PushL(TAny*) because
         *                  then the virtual destructor of the M-class
         *                  won't be called when the object is deleted).
         */
        virtual void VPbkSingleContactLinkOperationComplete(
                MVPbkContactOperationBase& aOperation,
                MVPbkContactLink* aLink ) = 0;

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
        virtual void VPbkSingleContactLinkOperationFailed(
                MVPbkContactOperationBase& aOperation, 
                TInt aError ) = 0;

        /**
         * Returns an extension point for this interface or NULL.
         *
         * @param aExtensionUid no extensions defined currently.
         * @return An extension point for this interface or NULL.
         */
        virtual TAny* SingleContactLinkOperationObserverExtension( 
                TUid /*aExtensionUid*/ ) { return NULL; }

    protected:  // Destructor
        virtual ~MVPbkSingleContactLinkOperationObserver() { }

    };

#endif // MVPBKSINGLECONTACTLINKOPERATIONOBSERVER_H

//End of file

