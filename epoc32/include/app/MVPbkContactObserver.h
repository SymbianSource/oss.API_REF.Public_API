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
* Description:  Virtual Phonebook observer interface for contact 
*                operations (Delete, Commit...).
*
*/


#ifndef MVPBKCONTACTOBSERVER_H
#define MVPBKCONTACTOBSERVER_H

// INCLUDES
#include <e32cmn.h>
#include <e32std.h>

// FORWARD DECLARATIONS
class MVPbkStoreContact;


// CLASS DECLARATIONS

/**
 * Virtual Phonebook Contact operation observer interface.
 * This interface is used to signal the contact operation client 
 * of events.
 */
class MVPbkContactObserver
    {
    public:  // Types
        /**
         * Operation codes for Contact operation observers.
         */
        enum TContactOp
            {
            /// Unknown operation
            EContactOperationUnknown = 0,
            /// See MVPbkViewContact::ReadL
            EContactRead,
            /// See MVPbkViewContact::ReadAndLockL
            EContactReadAndLock,
            /// See MVPbkBaseContact::DeleteL
            EContactDelete,
            /// See MVPbkStoreContact::LockL
            EContactLock,
            /// See MVPbkStoreContact::Commit
            EContactCommit,
            /// See MVPbkContactStore::SetOwnContacL
            EContactSetOwn
            };

        /// Forward declaration for MVPbkContactObserver::TResult extension
        struct TResultExt;

        /**
         * Result object for Contact operation observers.
         */
        struct TContactOpResult
            {
            ///Own: Operation code
            TContactOp iOpCode;

            /**
             * New Store Contact object.
             * Set if iOpCode is EContactRead or EContactReadAndLock.
             * If set client takes ownership of the object.
             */
            MVPbkStoreContact* iStoreContact;

            ///Own: Reserved for Extension
            TResultExt* iExtension;
            };

    public:  // Interface
        /**
         * Called when a contact operation has succesfully completed.
         *
         * NOTE: If you use Cleanupstack for MVPbkStoreContact use 
         * MVPbkStoreContact::PushL or CleanupDeletePushL from e32base.h.
         * (Do Not Use CleanupStack::PushL(TAny*) because then the virtual 
         * destructor of the M-class won't be called when the object 
         * is deleted).
         *
         * @param aResult   The result of the operation. The client takes
         *                  the ownership of the iStoreContact immediately
         *                  if set in aResult.
         */
        virtual void ContactOperationCompleted(TContactOpResult aResult) =0;

        /**
         * Called when a contact operation has failed.
         *
         * @param aOpCode           The operation that failed.
         * @param aErrorCode        System error code of the failure.
         *							KErrAccessDenied when EContactCommit 
         *							means that contact hasn't been locked.
         * @param aErrorNotified    ETrue if the implementation has already
         *                          notified user about the error, 
         *                          EFalse otherwise.
         */
        virtual void ContactOperationFailed
            (TContactOp aOpCode, TInt aErrorCode, TBool aErrorNotified) =0;

        /**
         * Returns an extension point for this interface or NULL.
         * @param aExtensionUid Uid of extension.
         * @return Extension point or NULL.
         */
        virtual TAny* ContactObserverExtension(
                TUid /*aExtensionUid*/) { return NULL; }

    protected:  // Destructor
        /**
         * Destructor.
         */
        virtual ~MVPbkContactObserver() { }

    };

#endif  // MVPBKCONTACTOBSERVER_H

// End of File
