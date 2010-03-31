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
* Description:  Virtual Phonebook observer interface for batch operations.
*
*/



#ifndef MVPBKBATCHOPERATIONOBSERVER_H
#define MVPBKBATCHOPERATIONOBSERVER_H

// INCLUDES
#include <e32cmn.h>

// FORWARD DECLARATIONS
class MVPbkContactOperationBase;
class MVPbkStoreContact;

// CLASS DECLARATIONS

/**
 * Virtual Phonebook asynchronous multi contact operation observer interface.
 * This observer interface is used to signal the client during a 
 * batch operation, which involves operations to e.g. multiple contacts.
 * The client is signaled during the operations steps and then signaled
 * of the completion of the whole operation.
 */
class MVPbkBatchOperationObserver
    {
    public:  // Interface
        /**
         * Called when one step of the operation is completed.
         *
         * @param aOperation Operation whose step has completed
         * @param aStepSize Size of the performed step
         */
        virtual void StepComplete( 
                MVPbkContactOperationBase& aOperation,
                TInt aStepSize ) = 0;

        /**
         * Called when one step of the operation fails.
         *
         * @param aOperation Operation whose step has failed
         * @param aStepSize Size of the performed step
         * @param aError Error that occured
         * @return ETrue if the batch operation should continue, 
         *               EFalse otherwise
         *         NOTE! If returning ETrue the operation can NOT be deleted.
         *               Operation should be deleted in OperationCompleted() 
         *               function.
         *               If returning EFalse the operation can be deleted
         *               safely.
         */
        virtual TBool StepFailed(
                MVPbkContactOperationBase& aOperation,
                TInt aStepSize, TInt aError ) = 0;

        /**
         * Called when operation is completed.
         * This is called when all steps are executed. If EFalse is returned
         * in StepFailed() call this function is NOT called.
         *
         * @param aOperation    the completed operation
         */
        virtual void OperationComplete( 
                MVPbkContactOperationBase& aOperation ) = 0;

        /**
         * Returns an extension point for this interface or NULL.
         * @param aExtensionUid Uid of extension
         * @return Extension point or NULL
         */
        virtual TAny* BatchOperationObserverExtension( 
                TUid /*aExtensionUid*/ ) { return NULL; }

    protected:  // Destructor
        /**
         * Destructor.
         */
        virtual ~MVPbkBatchOperationObserver() { }

    };

#endif // MVPBKBATCHOPERATIONOBSERVER_H

// End of file
