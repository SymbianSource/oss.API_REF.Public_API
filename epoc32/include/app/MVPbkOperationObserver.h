/*
* Copyright (c) 2005-2007 Nokia Corporation and/or its subsidiary(-ies).
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
* Description:  Observer interfaces for asynchronous operations
*
*/


#ifndef VPBKOPERATIONOBSERVER_H
#define VPBKOPERATIONOBSERVER_H

// INCLUDES
#include <e32base.h>

class MVPbkContactOperationBase;
// CLASS DECLARATION

/**
 * An observer for asynchronous operations that do not return anything.
 */
class MVPbkOperationObserver
    {
    public:

    	/**
    	 * The operation was completed succesfully.
    	 * 
    	 * @param aOperation operation handle
    	 */
        virtual void VPbkOperationCompleted(
                MVPbkContactOperationBase* aOperation ) = 0;

    protected:
        /* Destroying via this interface is not allowed */
        ~MVPbkOperationObserver(){}
    };

/**
 * An observer for asynchronous operations
 * that return result of ResultType type.
 */
template<typename ResultType>
class MVPbkOperationResultObserver
    {
    public:

        /**
         * The operation was completed succesfully.
         * 
         * @param aOperation operation handle
         * @param aOperationResult operation result
         */
        virtual void VPbkOperationResultCompleted(
                MVPbkContactOperationBase* aOperation,
                ResultType aOperationResult ) = 0;
        
    protected:
        /* Destroying via this interface is not allowed */
        ~MVPbkOperationResultObserver(){}
    };

/**
 * An observer for asynchronous operations 
 * to receive error notifications when an operation fails.
 */
class MVPbkOperationErrorObserver
    {
    public:
        
        /**
         * An error occured in the operation that was requested.
         * 
         * @param aOperation operation handle 
         * @param aError Operation error code.
         */
        virtual void VPbkOperationFailed(
                MVPbkContactOperationBase* aOperation,
                TInt aError ) = 0;
        
    protected:
        /* Destroying via this interface is not allowed */
        ~MVPbkOperationErrorObserver(){}
    };

#endif //VPBKOPERATIONOBSERVER_H
//End of file
