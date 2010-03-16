/*
* Copyright (c) 2004 Nokia Corporation and/or its subsidiary(-ies).
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
* Description:  Implementation of inline methods of class RFavouritesHandle.
*
*/


#ifndef FAVOURITES_HANDLE_INL
#define FAVOURITES_HANDLE_INL

/**
 * Implementation of RFavouritesHandle::RFavouritesHandle()
 * @since 0.9       
 */

RFavouritesHandle::RFavouritesHandle(): iHandle( 0 )
    {
    }

/**
 * Implementation of RFavouritesHandle::Handle()
 * @since 0.9       
 * @return the handle 
 */

TInt RFavouritesHandle::Handle() const
    {
    return iHandle;
    }

#endif
            
// End of File
