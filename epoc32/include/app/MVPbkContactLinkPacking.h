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
* Description:  Virtual Phonebook link packing interface for packing 
*                link internals.
*
*/


#ifndef MVPBKCONTACTLINKPACKING_H
#define MVPBKCONTACTLINKPACKING_H

// INCLUDES
#include <e32cmn.h>
#include <e32std.h>

// FORWARD DECLARATIONS
class RWriteStream;

// CLASS DECLARATIONS

/**
 * An interface Contact link packing.
 * This interface can be used to pack a contact link to a stream.
 */
class MVPbkContactLinkPacking
    {
    public: // destructor
        /**
         * Destructor.
         */
        virtual ~MVPbkContactLinkPacking() { }

    public: // interface
        /**
         * Returns the packed size of internals (excluding the store URI) of 
         * this link.
         * @return Packed size of internals (excluding the store URI) of 
         *         this link.
         */
        virtual TInt InternalPackedSize() const =0;

        /**
         * Appends the packed internals (excluding the URI) of this link.
         * @param aStream   Stream to append to this link.
         */
        virtual void PackInternalsL(RWriteStream& aStream) const =0;

        /**
         * Returns an extension point for this interface or NULL.
         * @param aExtensionUid Uid of extension.
         * @return Extension point or NULL.
         */
        virtual TAny* ContactLinkPackingExtension(
                TUid /*aExtensionUid*/) { return NULL; }

    };

#endif // MVPBKCONTACTLINKPACKING_H

// End of File
