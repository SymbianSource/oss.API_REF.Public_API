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
* Description:  Virtual Phonebook interface for contact groups.
*
*/


#ifndef MVPBKCONTACTGROUP_H
#define MVPBKCONTACTGROUP_H


// INCLUDES
#include <e32base.h>
#include <mvpbkstorecontact.h>
#include <mvpbkstorecontact2.h>

// FORWARD DECLARATIONS
class MVPbkContactLinkArray;


// CLASS DECLARATIONS

/**
 * An interface for Virtual Phonebook contact groups.
 * This interface can be used to manipulate contact groups.
 *
 * @see MVPbkContactStore
 */
class MVPbkContactGroup : public MVPbkStoreContact,
                          public MVPbkStoreContact2
    {
    public:  // Destructor
        /**
         * Destructor.
         */
        virtual ~MVPbkContactGroup() { }

    public:  // Interface
        /**
         * Sets the group label.
         * @param aLabel    New label to set for the group.
         */
        virtual void SetGroupLabelL(const TDesC& aLabel) =0;
        
        /**
         * Returns the group label.
         * @return The group label.
         */
        virtual TPtrC GroupLabel() const =0;
        
        /**
         * Adds new contact to this group.
         *
         * @param aContact  Contact to add to this group.
         */
        virtual void AddContactL(const MVPbkContactLink& aContactLink) =0;
        
        /**
         * Removes a contact from this group.
         *
         * @param aContact  Contact to remove from this group.
         */
        virtual void RemoveContactL(const MVPbkContactLink& aContactLink) =0;
        
        /**
         * Returns links to the items in this group.
         * @return Links to the items in this group.
         */
        virtual MVPbkContactLinkArray* ItemsContainedLC() const =0;
        
        /**
         * Returns an extension point for this interface or NULL.
         * @param aExtensionUid Uid of extension.
         * @return Extension point or NULL.
         */
        virtual TAny* ContactGroupExtension(
                TUid /*aExtensionUid*/) { return NULL; }
    };

#endif  // MVPBKCONTACTGROUP_H

// End of File
