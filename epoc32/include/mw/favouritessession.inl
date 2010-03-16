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
* Description:  Implementation of inline methods of class RFavouritesSession.
*
*/


#ifndef FAVOURITES_SESSION_INL
#define FAVOURITES_SESSION_INL

// ---------------------------------------------------------
// RFavouritesSession::SendReceive
// ---------------------------------------------------------
//

void RFavouritesSession::SendReceive
( TInt aFunction, const TIpcArgs& aArgs, TRequestStatus& aStatus ) const
    {
    RSessionBase::SendReceive( aFunction, aArgs, aStatus );
    }

// ---------------------------------------------------------
// RFavouritesSession::SendReceive
// ---------------------------------------------------------
//
inline TInt RFavouritesSession::SendReceive
( TInt aFunction, const TIpcArgs& aArgs ) const
    {
    return RSessionBase::SendReceive( aFunction, aArgs );
    }

// ---------------------------------------------------------
// RFavouritesSession::SendReceive
// ---------------------------------------------------------
//
inline TInt RFavouritesSession::SendReceive( TInt aFunction ) const
    {
    return RSessionBase::SendReceive( aFunction );
    }

#endif
            
// End of File
