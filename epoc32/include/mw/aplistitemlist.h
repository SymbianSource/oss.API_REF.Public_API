/*
* Copyright (c) 2002 Nokia Corporation and/or its subsidiary(-ies). 
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
* Description:  Declaration of the CApListItemList class.
*
*/


#ifndef CAPLISTITEMLIST_H
#define CAPLISTITEMLIST_H

// Deprecation warning
#warning This header file has been deprecated. Will be removed in one of the next SDK releases.
 
 
//  INCLUDES
#include <e32base.h>
#include <ApEngineVer.h>

// FORWARD DECLARATION

class CApListItem;

// CLASS DECLARATION
/**
*  A list of CApListItem-s pointers; items are owned.
*/
class CApListItemList : public CArrayPtrFlat<CApListItem>
    {
    public:  // Constructors and destructor

        /**
        * C++ default constructor.
        *
        * @deprecated
        */
        IMPORT_C CApListItemList();

        /**
        * Destructor. Items in the list are destroyed.
        *
        * @deprecated
        */
        IMPORT_C virtual ~CApListItemList();

    public:  // New methods

        /**
        * Get pointer to the item having aUid,
        * or NULL if no such item is in the
        * list.
        * @param aUid Uid of item to get.
        * @return Pointer to the item having uid aUid, or NULL. Ownership
        * not passed (the list still owns the item).
        *
        * @deprecated
        */
        IMPORT_C CApListItem* ItemForUid( TUint32 aUid ) const;

    };

#endif

// End of File
