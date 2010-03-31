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
* Description:  Virtual Phonebook abstract asynchronous contact operation.
*
*/


#ifndef MVPBKCONTACTOPERATION_H
#define MVPBKCONTACTOPERATION_H

// INCLUDES
#include "mvpbkcontactoperationbase.h"

// CLASS DECLARATIONS

/**
 * Virtual Phonebook abstract asynchronous contact operation.
 * The operation can be cancelled by deleting the operation object.
 */
class MVPbkContactOperation : 
        public MVPbkContactOperationBase
    {
    public:  // Interface
        /**
         * Starts the contact operation.
         */
        virtual void StartL() =0;

        /**
         * Cancels the operation.
         */
        virtual void Cancel() =0;

        /**
         * Returns an extension point for this interface or NULL.
         * @param aExtensionUid Uid of extension.
         * @return Extension point or NULL.
         */
        virtual TAny* ContactOperationExtension(
                TUid /*aExtensionUid*/) { return NULL; }
    };

#endif // MVPBKCONTACTOPERATION_H

// End of file

