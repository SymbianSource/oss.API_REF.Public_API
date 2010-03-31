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
* Description:  An interface for store contacts.
*
*/


#ifndef MVPBKSTORECONTACT2_H
#define MVPBKSTORECONTACT2_H


// FORWARD DECLARATIONS
class MVPbkStoreContactProperties;

// CLASS DECLARATIONS

/**
 * This class is an extension to MVPbkStoreContact.
 * See documentation of MVPbkStoreContact from header MVPbkStoreContact.h 
 * 
 *
 * @see MVPbkStoreContact
 * 
 */
class MVPbkStoreContact2
    {
    public:  // Destructor
        virtual ~MVPbkStoreContact2() { }

    public:

        /**   
         * Returns auxiliary properties.
         * Can return NULL if underlying store doesn't support any 
         * of MVPbkStoreContactProperties functions.
         *
         * @return A properties object
        */
        virtual MVPbkStoreContactProperties* PropertiesL() const =0;
          
        /**
         * Set the contact as the store's current own contact asynchronously. 
         *
         * @param aObserver The observer to call back when this operation
         *                  completes. The observer will not be called if this
         *                  function leaves.
         * @exception KErrInUse If another asynchronous operation is already
         *            in progress.
         * @exception KErrNotSupported If store does not support own contact
         */
        virtual void SetAsOwnL(MVPbkContactObserver& aObserver) const =0;
        
        
        
      
    };

#endif  // MVPBKSTORECONTACT2_H

//End of file
