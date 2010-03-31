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
* Description:  Declaration of CActiveFavouritesDbNotifier.
*
*/


#ifndef ACTIVE_FAVOURITES_DB_NOTIFIER_H
#define ACTIVE_FAVOURITES_DB_NOTIFIER_H

//  INCLUDES

#include <e32base.h>
#include <d32dbms.h>
#include <favouritesdbnotifier.h>

// FORWARD DECLARATION

class RFavouritesDb;
class MFavouritesDbObserver;

// CLASS DECLARATION

/**
* ActiveFavouritesDbNotifier is an Active object encapsulating a favourites database notifier. 
* Once this notifier is Start()-ed, it keeps watching the database and notifies the
* observer, until the database is closed by all clients (i.e. released by
* DBMS), or it is DoCancel()-led.
*/
class CActiveFavouritesDbNotifier : public CActive
    {
    public:     // Constructor and destructor

        /**
        * Constructor.
        * @since 0.9 
        * @param aDb The favourites database to watch for.
        * @param aObserver The Observer to be notified about database events.
        */
        IMPORT_C CActiveFavouritesDbNotifier( RFavouritesDb& aDb, MFavouritesDbObserver& aObserver );

        /**
        * Destructor.
        */
        IMPORT_C virtual ~CActiveFavouritesDbNotifier();

    protected:  // from CActive

        /**
        * Invoked when the outstanding request completes.
        * @since 0.9
        * @return void 
        */
        IMPORT_C void RunL();

        /**
        * Cancel any outstading request. It's implementation of the Cancel protocol;
        * @since 0.9
        * @return void 
        */
        IMPORT_C void DoCancel();

    public:     // new methods

        /**
        * Start the notifier. The notification request is automatically
        * renewed until it is cancelled, or the database is closed by
        * all clients (i.e. released by DBMS).
        * @since 0.9
        * @return Error code.
        */
        IMPORT_C TInt Start();

    private:

        /**
        * Request database change notification from the Favourites Engine.
        * @since 0.9
        * @return void 
        */
        void NotifyChange();

    private:    // data

        RFavouritesDbNotifier iNotifier;    ///< Notifier object.
        RFavouritesDb& iDb;                 ///< Handle to the database.
        MFavouritesDbObserver* iObserver;   ///< Pointer to observer.
    };

#endif
            
// End of File
