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
* Description:  Profile name interface.
*
*/



#ifndef MPROENGPROFILENAME_H
#define MPROENGPROFILENAME_H

// INCLUDES
#include <e32std.h>

// FORWARD DECLARATIONS
class MProEngProfileNameExt; 

// CLASS DECLARATION

/**
*  Profile name interface.
*  This interface offers methods to get profile ID and to get and set the
*  profile name.
*
*  @lib N/A
*  @since 3.1
*/
class MProEngProfileName
    {
    protected:  // Destructor

        virtual ~MProEngProfileName() {};

    public:
        /**
        * Returns ID of the profile.
        * @since 3.1
        * @return Returns ID of the profile.
        */
        virtual TInt Id() const = 0;

        /**
        * Returns the name of the profile.
        * @since 3.1
        * @return Returns name of the profile.
        */
        virtual const TDesC& Name() const = 0;

        /**
        * Set the name of the profile.
        * @since 3.1
        * @param aName Name of the profile.
        * @return KErrNone if succesful,
        *         KErrAccessDenied if name setting of this profile is read-only,
        *         KErrAlreadyExists if the name is already used by another
        *         profile.
        *         
        */
        virtual TInt SetNameL( const TDesC& aName ) = 0;

    private: // Extension interface

        /**
        * This member is internal and not intended for use.
        */
        virtual MProEngProfileNameExt* Extension() { return NULL; }

    };

#endif      // MPROENGPROFILENAME_H

// End of File

