/*
* Copyright (c) 2003-2009 Nokia Corporation and/or its subsidiary(-ies).
* All rights reserved.
* This component and the accompanying materials are made available
* under the terms of "Eclipse Public License v1.0"
* which accompanies this distribution, and is available
* at the URL "http://www.eclipse.org/legal/epl-v10.html".
*
* Initial Contributors:
* Nokia Corporation - initial contribution.
*
* Contributors:
*
* Description:
* Name        : sipmanagedprofileregistry.h
* Part of     : SIP Profile Client
* Interface   : SDK API, SIP Profile API
* The class for managing SIP profiles
* Version     : 1.0
*
*/



#ifndef CSIPMANAGEDPROFILEREGISTRY_H
#define CSIPMANAGEDPROFILEREGISTRY_H

//  INCLUDES
#include <e32base.h>
#include <e32std.h>
#include "sipprofileregistrybase.h"

// FORWARD DECLARATIONS
class CSIPProfile;
class CSIPManagedProfile;
class MSIPProfileRegistryObserver;


// CLASS DECLARATION
/**
*  @publishedAll
*  @released
*
*  The class for managing SIP profiles.
*  This class provides the functions for
*  adding/updating/removing profiles.
*
*  @lib sipprofilecli.lib
*/
class CSIPManagedProfileRegistry: public CSIPProfileRegistryBase
    {
    public:  // Constructors and destructor
        /**
        * Two-phased constructor.
        * @param aObserver a observer for SIP profile change events.
        */
        IMPORT_C static CSIPManagedProfileRegistry* NewL(
                        MSIPProfileRegistryObserver& aObserver);

        /**
        * Two-phased constructor.
        * Constructs an object and adds the pointer to the cleanup stack;
        * @param aObserver a observer for SIP profile change events.
        */
        IMPORT_C static CSIPManagedProfileRegistry* NewLC(
                        MSIPProfileRegistryObserver& aObserver);

        /**
        * Destructor
        */
        IMPORT_C ~CSIPManagedProfileRegistry();
    public: //new functions

        /**
        * Instantiates new profile with default values 
        * for given type.
        * @param aType a SIP profile type to be created
        * @return pre-filled instance of given type profile type;
                * the ownership is transferred
        */
        IMPORT_C CSIPManagedProfile* CreateL(const TSIPProfileTypeInfo& aType); 

        /**
        * Checks if profile is not used by other applications.
        * @param aSIPProfile a SIP profile
        * @return ETrue if its being used by other applications, EFalse otherwise
        * @capability ReadUserData
        */
        IMPORT_C TBool IsInUseL(const CSIPProfile& aSIPProfile) const; 

        /**
        * Saves new profile or changes to a profile to the persistent storage.
        * This function must be called after desired values are set or updated
        * in the SIP profile. 
        * If the profile is marked for auto-registration and the profile is 
        * updated the profile will be re-registered.
        * Function leaves on failure.
        * @param aSIPProfile a sip profile to save
        * @capability WriteDeviceData
        * @capability NetworkServices
        */
        IMPORT_C void SaveL(CSIPProfile& aSIPProfile);

        /**
        * Removes and deletes SIP profile from the persistent storage.
        * Function leaves on failure.
        * If the profile is registered it will be de-registered before the
        * removal from the persistent storage.
        * @param aSIPProfile a sip profile to delete
        * @capability WriteDeviceData
        * @capability NetworkServices
        */
        IMPORT_C void DestroyL(CSIPProfile& aSIPProfile);

    private:

        CSIPManagedProfileRegistry(MSIPProfileRegistryObserver& aObserver);

        void ConstructL();

        /**
        * Creates a new instance of type CSIPManagedProfile
        * @return new instance
        */
        CSIPProfile* NewInstanceL();
    };

#endif // CSIPMANAGEDPROFILEREGISTRY_H
