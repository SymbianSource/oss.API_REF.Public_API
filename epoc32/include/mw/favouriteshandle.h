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
* Description:  Declaration of RFavouritesHandle
*
*/


#ifndef FAVOURITES_HANDLE_H
#define FAVOURITES_HANDLE_H

//  INCLUDES

#include <e32base.h>
#include <FavouritesSession.h>

// CLASS DECLARATION

/**
* RFavouritesHandle is the favourite object handle.
*/
class RFavouritesHandle
    {

    public:     // Constructor and destructor
        
        /**
        * Constructor.
        * @since 0.9       
        */
        inline RFavouritesHandle();

        /**
        * Close the object.
        * @since 0.9       
        * return void
        */
        IMPORT_C void Close();

    public:     // New methods

        /**
        * Get handle number.
        * @since 0.9       
        * @return Handle number.
        */
        inline TInt Handle() const;

    protected:  // New methods

        /**
        * Open the object.
        * @since 0.9       
        * @param aSess Session to be used.
        * @param aFunction Function.
        * @param aArgs Arguments.
        * @return Error code.
        */
        TInt Open
            (
            RFavouritesSession& aSess,
            TInt aFunction,
            const TIpcArgs& aArgs
            );

        /**
        * Open this object using other object.
        * @since 0.9       
        * @param aHandle Handle used to open this object.
        * @param aFunction Function.
        * @param aArgs Arguments.
        * @return Error code.
        */
        TInt Open
            (
            RFavouritesHandle& aHandle,
            TInt aFunction,
            const TIpcArgs& aArgs
            );

        /**
        * Message passing routine.
        * @since 0.9       
        * @param aFunction Function.
        * @param aArgs Arguments.
        * @param aStatus Request status.
        */
        void SendReceive
            (
            TInt aFunction,
            const TIpcArgs& aArgs,
            TRequestStatus& aStatus
            ) const;

        /**
        * Message passing routine.
        * @since 0.9       
        * @param aFunction Function.
        * @param aArgs Arguments.
        * @return Error code.
        */
        TInt SendReceive( TInt aFunction, const TIpcArgs& aArgs ) const;

        /**
        * Message passing routine.
        * @since 0.9       
        * @param aFunction Function.
        * @return Error code.
        */
        TInt SendReceive( TInt aFunction ) const;

    protected:  // Data

        RFavouritesSession iSess;   ///< Session handle.
        TInt iHandle;               ///< Handle number.

    };

#include <FavouritesHandle.inl>

#endif
            
// End of File
