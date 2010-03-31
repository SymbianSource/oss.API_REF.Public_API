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
* Description:  a contact store information interface
*
*/


#ifndef MVPBKCONTACTSTOREINFO_H
#define MVPBKCONTACTSTOREINFO_H


// INCLUDES
#include <e32cmn.h>

// CONSTANTS
const TInt KVPbkStoreInfoUnlimitedNumber = -1;

// CLASS DECLARATIONS

/**
 * A contact store information interface.
 *
 * The interface offers access to contact store information that
 * can change runtime.
 */
class MVPbkContactStoreInfo
    {
    public:  // Destructor
        /**
         * Destructor.
         */
        virtual ~MVPbkContactStoreInfo() {}

    public:  // New functions
        /**
         * Returns the maximum number of contacts that the store can have
         *
         * Client must always check the return value and compare it to
         * to the KVPbkStoreInfoUnlimitedNumber.
         *
         * @return The maximum number of contacts that the store can have
         *         or KVPbkStoreInfoUnlimitedNumber if the store hasn't got
         *         a limit.
         */
        virtual TInt MaxNumberOfContactsL() const =0;
        
        /**
         * Returns the current number of contacts in the store
         *
         * @return The current number of contacts in the store
         */
        virtual TInt NumberOfContactsL() const =0;
        
        /**
         * Returns the amount of memory in bytes that this store reserves
         * in the media it resides. 
         *
         * This is practical to implement for stores whose database is in 
         * the file system. All store implementations don't know their
         * memory consumption and in that case zero is returned.
         *
         * @return The amount of memory (bytes) that this store reserves 
         *         in the media it resides or zero if the information is
         *         not available (e.g in SIM stores)
         */
        virtual TInt64 ReservedMemoryL() const =0;
        
        /**
         * Returns the amount of memory in bytes that can be used 
         * for the new contacts.
         *
         * This is practical to implement for stores whose database is in 
         * the file system. All store implementations don't know this
         * information and in that case zero is returned.
         * 
         * @return Returns the amount of memory (bytes) that can be used for 
         *         the new contacts or zero if the information is not available
         */
        virtual TInt64 FreeMemoryL() const =0;
        
        /**
         * Returns the maximum number of groups that the store can have
         *
         * @return The maximum number of groups that the store can have
         *         or KVPbkStoreInfoUnlimitedNumber if the store hasn't got
         *         a limit. Zero if store doesn't support groups.
         */
        virtual TInt MaxNumberOfGroupsL() const =0;
        
        /**
         * Returns the current amount of groups in the store.
         *
         * @return The current amount of groups in the store
         */
        virtual TInt NumberOfGroupsL() const =0;
        
        /**
         * Returns an extension point for this interface or NULL.
         *
         * @param aExtensionUid no extensions defined currently.
         * @return an extension point for this interface or NULL.
         */
        virtual TAny* ContactStoreInfoExtension(TUid /*aExtensionUid*/) 
                { return NULL; }
    };


#endif  // MVPBKCONTACTSTOREINFO_H

//End of file
