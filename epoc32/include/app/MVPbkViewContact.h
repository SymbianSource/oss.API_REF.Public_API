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
* Description:  An interface for a view contact
*
*/


#ifndef MVPBKVIEWCONTACT_H
#define MVPBKVIEWCONTACT_H


// INCLUDES
#include <e32def.h>
#include <mvpbkbasecontact.h>


// FORWARD DECLARATIONS
class MVPbkContactViewBase;
class MVPbkContactStore;
class MVPbkExpandable;

// CLASS DECLARATIONS

/**
 * An interface for a view contact.
 *
 * As the name already says the view contact is a contact in a view.
 * It contains the fields that were defined in the sort order of the view.
 * However, a store implementation possibly have limitations of field types
 * that can be used in the sort order. If the store doesn't support the given
 * field type in a view contact it sets the data of those fields to zero length.
 * The order of the fields are same as in a sort order.
 *
 * @see MVPbkContactViewBase
 */
class MVPbkViewContact : public MVPbkBaseContact
    {
    protected:  // destructor
        /**
         * Destructor.
         */
        virtual ~MVPbkViewContact() { }

    public:  // New functions
        /**
         * Returns the parent view of the contact.
         *
         * @return The parent view of the contact.
         */
        virtual MVPbkContactViewBase& ParentView() const = 0;

        /**
         * Reads the whole contact from the store asynchronously.
         *
         * A client can use this if it has a reference of the view contact but
         * it needs all the data fields instead of only those that are included
         * in the view contact.
         *
         * The contact is returned in a call back.
         *
         * @param aObserver An observer to call back when this operation 
         *                  completes. The observer will not be called if this
         *                  function leaves.
         * @exception KErrInUse If another asynchronous operation is already 
         *                      in progress.
         */
        virtual void ReadL( MVPbkContactObserver& aObserver ) const = 0;

        /**
         * Reads the whole contact and locks it for modification 
         * asynchronously.
         *
         * A client can use this if it has a reference of the view contact and
         * it needs to modify the contact.
         *
         * The contact is returned in a call back.
         *
         * @param aObserver An observer to call back when this operation 
         *                  completes. The observer will not be called if this
         *                  function leaves.
         * @exception KErrInUse If another asynchronous operation is already 
         *                      in progress.
         * @exception KErrAccessDenied if contact is read-only
         */
        virtual void ReadAndLockL( MVPbkContactObserver& aObserver ) const = 0;

        /**
         * Returns expandable interface for this object or NULL if expanding is 
         * not supported.
         *
         * Examples are a contact group that can be expanded to its members view
         * or a folding view that can be extended to its internals. Client can
         * get the type of the view from MVPbkContactViewBase::Type which is useful
         * for knowing the type of expansion.
         *
         * @return An expansion or NULL.
         */
        virtual MVPbkExpandable* Expandable() const = 0;

        /**
         * Returns ETrue if two contacts are same.
         *
         * @param aOtherContact A contact to be compared.
         * @param aContactStore The store of the aOtherContact.
         * @return ETrue if two contacts are same.
         */
        virtual TBool IsSame( const MVPbkViewContact& aOtherContact, 
                              const MVPbkContactStore* aContactStore ) const = 0;
        
        /**
         * Returns ETrue if two contacts are same.
         *
         * @param aOtherContact A contact to be compared.
         * @param aContactStore The store of the aOtherContact.
         * @return ETrue if two contacts are same.
         */                    
        virtual TBool IsSame( const MVPbkStoreContact& aOtherContact, 
                              const MVPbkContactStore* aContactStore ) const = 0;
       
        /**
         * Returns an extension point for this interface or NULL.
         *
         * @param aExtensionUid no extensions defined currently.
         * @return An extension point for this interface or NULL.
         */
        virtual TAny* ViewContactExtension( TUid /*aExtensionUid*/ ) 
                { return NULL; }

    public:  // from MVPbkBaseContact
        /// Do not override
        virtual TBool IsSame( const MVPbkBaseContact& aOtherContact ) const
            {
            return aOtherContact.IsSame(*this);
            }

    };


#endif  // MVPBKVIEWCONTACT_H

//End of file


