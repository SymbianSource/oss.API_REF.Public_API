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
* Description:  Virtual Phonebook contact store interface.
*
*/


#ifndef MVPBKCONTACTSTORE2_H
#define MVPBKCONTACTSTORE2_H

// INCLUDES
#include <e32def.h>

// FORWARD DECLARATION
class MVPbkSingleContactLinkOperationObserver;
class MVPbkContactOperationBase;

// CLASS DECLARATIONS

/**
 * This class is an extension to MVPbkContactStore.
 * See documentation of MVPbkContactStore from header mvpbkcontactstore.h 
 * 
 * You can access this extension by calling MVPbkContactStore->ContactStoreExtension()
 */
class MVPbkContactStore2
    {
    protected:
        
        /**
         * This extension cannot be destroyed through this interface.
         */
        virtual ~MVPbkContactStore2() {};
        
    public:
        
        /**
        * Returns own contact link asynchronously.
        * 
        * @params aObserver Operation observer
        * @return operation handle
        * @Asynchronous
        */
           virtual MVPbkContactOperationBase* OwnContactLinkL(
                   MVPbkSingleContactLinkOperationObserver& aObserver) const = 0;

    };


#endif // MVPBKCONTACTSTORE2_H

// End of File
