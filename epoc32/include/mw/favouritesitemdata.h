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
* Description:  Declaration of FavouritesItemData
*
*/


#ifndef FAVOURITES_ITEM_DATA_H
#define FAVOURITES_ITEM_DATA_H

//  INCLUDES

#include <e32base.h>

// FORWARD DECLARATION

class RWriteStream;
class RReadStream;

// CLASS DECLARATION

/**
* MFavouritesItemData is the Mixin class for representing extra data for a favourites item.
*/
class MFavouritesItemData
    {

    public:     // streaming

        /**
        * Externalize into a stream.
        * @since 0.9       
        * @param aStream The stream to externalize to.
        */
        IMPORT_C virtual void ExternalizeL( RWriteStream& aStream ) const = 0;

        /**
        * Internalize from a stream.
        * @since 0.9       
        * @param aStream The stream to externalize from.
        */
        IMPORT_C virtual void InternalizeL( RReadStream& aStream ) = 0;

    };

#endif
            
// End of File
