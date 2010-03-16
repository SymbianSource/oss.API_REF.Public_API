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
* Description:  Profile engine interface.
*
*/



#ifndef MPROENGENGINE_H
#define MPROENGENGINE_H

// INCLUDES
#include <e32def.h>

// FORWARD DECLARATIONS
class RFs;
class MProEngProfile;
class MProEngProfileNameArray;
class MProEngChangeObserverExt;

// CLASS DECLARATION

/**
*  Profile engine interface.
*  This class offers methods to get active profile, active profile ID,
*  profile names array and set active profile.
*  How to use:
*  @code
*  // Create profile engine by using Factory:
*  MProEngEngine* profileEngine = NewEngineL();
*
*  // Free resources with MProEngEngine::Release();
*  profileEngine->Release();
*  // or if you release resources in destructor:
*  if( iEngine )
*      {
*      iEngine->Release();
*      }
*
*  // If you put this class to CleanupStack then use void CleanupReleasePushL()
*     CleanupReleasePushL( *profileEngine );
*  @endcode
*
*  @lib ProfileEngine.lib 
*  @since 3.1
*/
class MProEngEngine
    {
    public:  // Destructor

        virtual ~MProEngEngine() {};

    public:

        /**
        * Free resources of MProEngEngine.
        * @since 3.1
        */
        virtual void Release() = 0;

        /**
        * Return active profile, ownership transferred.
        * @since 3.1
        * @return Instance of the MProfile
        */
        virtual MProEngProfile* ActiveProfileLC() = 0;

        /**
        * Return active profile, ownership transferred.
        * @since 3.1
        * @return Instance of the MProfile
        */
        virtual MProEngProfile* ActiveProfileL() = 0;

        /**
        * Return active profile ID or system error code.
        * @since 3.1
        * @return Active profile ID or system error code.
        */
        virtual TInt ActiveProfileId() = 0;

        /**
        * Return profile name array, ownership transferred.
        * @since 3.1
        * @return Instance of the profile name array
        */
        virtual MProEngProfileNameArray* ProfileNameArrayLC() = 0;

        /**
        * Set the active profile, if ID is incorrect then leave with
        * KErrNotFound. This method can be called only by processes having
        * WriteDeviceData capability.
        * @since 3.1
        * @param aId Profile ID
        */
        virtual void SetActiveProfileL( TInt aId ) = 0;

        /**
        * Return the settings of the profile with the given ID. The created
        * object is pushed in the cleanup stack and the ownership is
        * transferred. Leave with KErrNotFound if a profile with the given ID
        * can not be found.
        * @since 3.1
        * @param aId Profile ID
        * @return Instance of the MProEngProfile
        */
        virtual MProEngProfile* ProfileLC( TInt aId ) = 0;

        /**
        * Return the settings of the profile with the given ID, the ownership
        * of the created object is transferred. Leave with KErrNotFound if a
        * profile with the given ID can not be found.
        * @since 3.1
        * @param aId Profile ID
        * @return Instance of the MProEngProfile
        */
        virtual MProEngProfile* ProfileL( TInt aId ) = 0;

    private: // Extension interface

        /**
        * This member is internal and not intended for use.
        */
        virtual MProEngChangeObserverExt* Extension() { return NULL; }

    };

#endif      //  MPROENGENGINE_H

// End of File

