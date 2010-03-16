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
* Description:  Declaration of FavouritesDbNotifier
*
*/


#ifndef FAVOURITES_DB_NOTIFIER_H
#define FAVOURITES_DB_NOTIFIER_H

//  INCLUDES

#include <FavouritesHandle.h>

// FORWARD DECLARATIONS

class RFavouritesDb;

// CLASS DECLARATION

/**
* RFavouritesDbNotifier is the Favourites database change notifier 
* for the Favourites Engine. It provides notification of database changes.
*/
class RFavouritesDbNotifier: public RFavouritesHandle
    {
    public:     // update

        /**
        * Open the notifier.
        * @since 0.9 
        * @param aDb The database to be watched.
        * @return Error code.
        */
        IMPORT_C TInt Open( RFavouritesDb& aDb );

        /**
        * Request notification about all database events.
        * @since 0.9 
        * @param aStatus Request status.
        * @return void 
        */
        IMPORT_C void NotifyAllEvents( TRequestStatus& aStatus );

        /**
        * Request notification about database changes.
        * @since 0.9 
        * @param aStatus Request status.
        * @return void
        */
        IMPORT_C void NotifyChange( TRequestStatus& aStatus );

        /**
        * Cancel the outstanding request (if any).
        * @since 0.9 
        * @return void
        */
        IMPORT_C void Cancel();

    };

#endif
            
// End of File
