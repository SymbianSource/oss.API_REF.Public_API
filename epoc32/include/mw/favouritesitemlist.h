/*
* Copyright (c) 2002 Nokia Corporation and/or its subsidiary(-ies).
* All rights reserved.
* This component and the accompanying materials are made available
* under the terms of the License "Eclipse Public License v1.0"
* which accompanies this distribution, and is available
* at the URL "http://www.eclipse.org/legal/epl-v10.html".
*
* Initial Contributors:
* Nokia Corporation - initial contribution.
*
* Contributors:
*
* Description:  Declaration of FavouritesItemList
*
*/


#ifndef FAVOURITES_ITEM_LIST_H
#define FAVOURITES_ITEM_LIST_H

// INCLUDE FILES

#include <e32base.h>

// CONSTANTS

// FORWARD DECLARATION

class CFavouritesItem;
class RWriteStream;
class RReadStream;

// CLASS DECLARATION

/**
* CFavouritesItemList is the Array of CFavouritesItem-s. 
* Items are owned and deleted upon destruction.
* Note: using this array downcasted to its base can result in leaks.
* Delete method of base class is not virtual!
*/
class CFavouritesItemList: public CArrayPtrFlat<CFavouritesItem>
    {
    public:     // Constructor and destructor

        /**
        * Constructor.
        * @since 0.9       
        */
        IMPORT_C CFavouritesItemList();

        /**
        * Destructor. Elements are destroyed.
        * @since 0.9       
        */
        IMPORT_C virtual ~CFavouritesItemList();

    public:     // new methods

        /**
        * Remove and destroy an element. Invalid params will Panic.
        * @since 0.9       
        * @param aIndex Index of element to delete.
        * @return void 
        */
        IMPORT_C void Delete( TInt aIndex );

        /**
        * Remove and destroy elements. Invalid params Panic.
        * @since 0.9       
        * @param aIndex Index of start element to delete.
        * @param aCount Number of items to delete.
        * @return void
        */
        IMPORT_C void Delete( TInt aIndex, TInt aCount );

    public:     // Sorting

        /**
        * Comparison function type; compare two items. Should leave in error.
        * @since 0.9       
        * @param aLeft item to compare to aRight.
        * @param aRight Item to compare to aLeft.
        * @return
        *   - negative value, if aLeft is less than aRight;
        *   - 0,              if aLeft equals to aRight;
        *   - positive value, if aLeft is greater than aRight.
        */
        typedef TInt (*ComparisonFuncL)
            ( const CFavouritesItem& aLeft, const CFavouritesItem& aRight );

        /**
        * Sort the list using bubble-sort.
        * @since 0.9       
        * @param aCompareItemsL Function to be used two elements.
        */
        IMPORT_C void SortL( ComparisonFuncL aCompareItemsL );

    public:     // Uid <--> array index conversion

        /**
        * Convert Uid to index.
        * @since 0.9       
        * @param aUid Uid to convert.
        * @return Index for this Uid, or -KErrNotFound if not found.
        */
        IMPORT_C TInt UidToIndex( TInt aUid ) const;

        /**
        * Convert index to Uid.
        * @since 0.9       
        * @param aIndex Index to convert.
        * @return Uid for this index, or KFavouritesNullUid if not found.
        */
        IMPORT_C TInt IndexToUid( TInt aIndex ) const;

        /**
        * Get pointer to item having aUid.
        * @since 0.9       
        * @param aUid Uid of item to look for.
        * @return Pointer to item having aUid, or NULL if there is no such
        * item. Item is still owned by the list.
        */
        IMPORT_C const CFavouritesItem* ItemByUid( TInt aUid ) const;

    public:     // (But not exported:) Streaming

        /**
        * Externalize into a stream.
        * @since 0.9       
        * @param aStream The stream to externalize to.
        */
        void ExternalizeL( RWriteStream& aStream ) const;

        /**
        * Internalize from a stream. Existing data is kept, new ones appended.
        * @since 0.9       
        * @param aStream The stream to externalize from.
        */
        void InternalizeL( RReadStream& aStream );

    };

#endif

// End of file
