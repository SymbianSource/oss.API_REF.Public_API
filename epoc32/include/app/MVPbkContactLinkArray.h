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
* Description:  Virtual Phonebook interface for contact link array.
*
*/


#ifndef MVPBKCONTACTLINKARRAY_H
#define MVPBKCONTACTLINKARRAY_H

// INCLUDES
#include <e32cmn.h>
#include <e32std.h>

// FORWARD DECLARATIONS
class MVPbkContactLink;
class MVPbkStreamable;


// CLASS DECLARATIONS

/**
 * Virtual Phonebook contact link array.
 * This interface can be used to handle a read-only array of contact links.
 */
class MVPbkContactLinkArray
    {
    public: // Destructor
        /**
         * Destructor.
         */
        virtual ~MVPbkContactLinkArray() { }

    public: // Interface
        /**
         * Returns the number of links in this array.
         * @return Number of links in this array.
         */
        virtual TInt Count() const =0;

        /**
         * Returns a link in this array at aIndex.
         * @return Link in this array at aIndex.
         */
        virtual const MVPbkContactLink& At(TInt aIndex) const =0;

        /**
         * Conveniency wrapper for At().
         * @param aindex    Index to retrieve from the array.
         * @return Read-only reference to a contact link.
         */
        inline const MVPbkContactLink& operator[](TInt aIndex) const
            {
            return this->At(aIndex);
            }

        /**
         * Searches this array for a link.
         *
         * @param aLink the link to search.
         * @return The index where aLink was found or KErrNotFound.
         */
        virtual TInt Find(const MVPbkContactLink& aLink) const =0;

        /**
         * Packs the contents of this link array for IPC transfer.
         * @see MVPbkContactLink::PackLC
         * @see CVPbkContactManager::CreateLinksLC
         */
        virtual HBufC8* PackLC() const =0;

        /**
         * Returns persistent streaming interface for this link array, 
         * or NULL if persistent streaming is not supported.
         */
        virtual const MVPbkStreamable* Streamable() const =0;    

        /**
         * Returns an extension point for this interface or NULL.
         */
        virtual TAny* ContactLinkArrayExtension(
                TUid /*aExtensionUid*/) { return NULL; }

    };

#endif // MVPBKCONTACTLINKARRAY_H

// End of File
