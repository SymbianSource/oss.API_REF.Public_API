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
* Description:  Declaration of FavouritesDbObserver
*
*/


#ifndef FAVOURITES_DB_OBSERVER_H
#define FAVOURITES_DB_OBSERVER_H

//  INCLUDES

#include <e32base.h>
#include <d32dbms.h>

// CLASS DECLARATION

/**
* MFavouritesDbObserver is a Mixin for handling events from an CFavouritesDb. Users of
* CActiveFavouritesDbNotifier must derive from this.
*/
class MFavouritesDbObserver
    {

    public:     // new methods

        /**
        * Derived classes should implement this method, and act accordingly
        * to database events.
        * (Note that when a using a CActiveFavouritesDbNotifier, after a
        * RDbNotifier::EClose event the notifier is Cancel()-led.)
        * @since 0.9       
        * @param aEvent Database event.
        * @return void
        */
        IMPORT_C virtual void HandleFavouritesDbEventL
            ( RDbNotifier::TEvent aEvent ) = 0;

    };

#endif
            
// End of File
