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
* Description:  Declaration of RFavouritesDbIncremental
*
*/


#ifndef FAVOURITES_DB_INCREMENTAL_H
#define FAVOURITES_DB_INCREMENTAL_H

//  INCLUDES

#include <favouriteshandle.h>

// FORWARD DECLARATIONS

class RFavouritesDb;

// CLASS DECLARATION

/**
* Incremental object for Favourites Engine.
* This class provides incremental database administration (recovery,
* compaction). Usually client does not need to use this class.
*/
class RFavouritesDbIncremental: public RFavouritesHandle
    {
    public:     // update

        /**
        * Start incremental recovery on the given database.
        * @since 0.9 
        * @param aDb The database to be recovered.
        * @param aStep Placeholder for the step counter to be returned.
        * @return Error code.
        */
        IMPORT_C TInt Recover( RFavouritesDb& aDb, TInt& aStep );

        /**
        * Start incremental compaction on the given database.
        * @since 0.9 
        * @param aDb The database to be compacted.
        * @param aStep Placeholder for the step counter to be returned.
        * @return Error code.
        */
        IMPORT_C TInt Compact( RFavouritesDb& aDb, TInt& aStep );

        /**
        * Perform next step of incremental operation.
        * @since 0.9 
        * @param aStep Step counter.
        * @return Error code.
        */
        IMPORT_C TInt Next( TInt& aStep );

    };

#endif
            
// End of File
