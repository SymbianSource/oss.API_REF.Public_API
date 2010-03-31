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
* Description:  Virtual Phonebook contact link for referencing contacts 
*                in different stores.
*
*/


#ifndef MVPBKCONTACTLINK_H
#define MVPBKCONTACTLINK_H

// INCLUDES
#include <e32cmn.h>
#include <e32std.h>
#include <cvpbkcontactlinkarray.h>

// FORWARD DECLARATIONS
class TVPbkContactStoreUriPtr;
class MVPbkStreamable;
class MVPbkContactStore;
class MVPbkContactLinkPacking;
class MVPbkBaseContact;


// CLASS DECLARATIONS

/**
 * Virtual Phonebook Contact link.
 * An object that uniquely identifies a single Contact and its ContactStore.
 */
class MVPbkContactLink
    {
    public: // destructor
        /**
         * Destructor.
         */
        virtual ~MVPbkContactLink() { }

    public: // interface
        /**
         * Packages this link for IPC transfer.
         * Read it using CVPbkContactLinkArray::NewL.
         * @return Packed link.
         * @see CVPbkContactLinkArray::NewL
         */
        HBufC8* PackLC();

        /**
         * Returns the contact store which this link belongs to.
         * @return Contact store associated with this link.
         */
        virtual MVPbkContactStore& ContactStore() const =0;

        /**
         * Returns ETrue if this link refers to the same contact than
         * aOther, EFalse otherwise.
         * @param aOther Contact to check equality for.
         * @return ETrue if this link refers to the same contact than
         *         aOther, EFalse otherwise.
         */
        virtual TBool IsSame(const MVPbkContactLink& aOther) const =0;
        
        /**
         * Checks if this link refers to the contact aContact.
         * @param aContact Contact to check.
         * @return ETrue if this link refers to aContact, EFalse otherwise.
         */
        virtual TBool RefersTo(const MVPbkBaseContact& aContact) const =0;
        
        /**
         * Returns persistent streaming interface for this object, or NULL
         * if persistent streaming is not supported.
         * @return Persistent streaming object or NULL if not supported.
         */
        virtual const MVPbkStreamable* Streamable() const =0;

        /**
         * Returns a packing interface for this link.
         * @see CVPbkContactLinkArray
         * @internal
         * @return Link packing object.
         */
        virtual const MVPbkContactLinkPacking& Packing() const = 0;
        
        /**
         * Returns a clone of this contact link.
         * @return Contact link copy.
         */
        virtual MVPbkContactLink* CloneLC() const =0;

        /**
         * Returns an extension point for this interface or NULL.
         * @param aExtensionUid Uid of extension.
         * @return Extension point or NULL.
         */
        virtual TAny* ContactLinkExtension(
                TUid /*aExtensionUid*/) { return NULL; }
    };


// INLINE FUNCTIONS
inline HBufC8* MVPbkContactLink::PackLC()
    {
    CVPbkContactLinkArray* array = CVPbkContactLinkArray::NewLC();
    MVPbkContactLink* clone = CloneLC();
    array->AppendL(clone);
    CleanupStack::Pop(); // clone
    HBufC8* packed = array->PackLC();
    CleanupStack::Pop(); // packed
    CleanupStack::PopAndDestroy(); // array
    CleanupStack::PushL(packed);
    return packed;
    }

#endif // MVPBKCONTACTLINK_H

// End of File
