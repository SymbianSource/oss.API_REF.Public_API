/*
* Copyright (c) 2009 Nokia Corporation and/or its subsidiary(-ies).
* All rights reserved.
* This component and the accompanying materials are made available
* under the terms of the License "Symbian Foundation License v1.0" to Symbian Foundation members and "Symbian Foundation End User License Agreement v1.0" to non-members
* which accompanies this distribution, and is available
* at the URL "http://www.symbianfoundation.org/legal/licencesv10.html".
*
* Initial Contributors:
* Nokia Corporation - initial contribution.
*
* Contributors:
*
* Description:  Profile name array interface.
*
*/



#ifndef MPROENGPROFILENAMEARRAY_H
#define MPROENGPROFILENAMEARRAY_H

//  INCLUDES
#include <BAMDESCA.H> // MDesCArray

// FORWARD DECLARATIONS
class MProEngProfileName;
class MProEngProfileNameArrayExt;

// CLASS DECLARATION

/**
*  Profile name array interface.
*
*  How to use:
*  Get profile names array with MProEngEngine::ProfileNameArrayLC().
*  @code
*  MProEngProfileNameArray* nameArray =
*      iProfileEngine->ProfileNameArrayLC();
*  @endcode
*
*  @lib ProfileEngine.lib
*  @since 3.1
*/
class MProEngProfileNameArray : public MDesCArray
    {
    public: // New functions

        /**
        * Return the ID of the profile in the given array index.
        * @since 3.1
        * @param aIndex index of the profile.
        * @return Return the ID of the profile in the given array index.
        *         KErrNotFound if the index is out of bounds.
        */
        virtual TInt ProfileId( TInt aIndex ) const = 0;

        /**
        * Find profile index by ID of the profile.
        * @since 3.1
        * @param aId ID of the profile.
        * @return Return index of the profile. KErrNotFound if
        *         profile isn't found.
        */
        virtual TInt FindById( TInt aId ) const = 0;

        /**
        * Find profile index by name of the profile.
        * @since 3.1
        * @param aProfileName name of the profile.
        * @return Return index of the profile. KErrNotFound if
        *         profile isn't found.
        */
        virtual TInt FindByName( const TDesC& aProfileName ) const = 0;

    private: // Extension interface

        /**
        * This member is internal and not intended for use.
        */
        virtual MProEngProfileNameArrayExt* Extension() { return NULL; }

    };

#endif      // MPROENGPROFILENAMEARRAY_H

// End of File

