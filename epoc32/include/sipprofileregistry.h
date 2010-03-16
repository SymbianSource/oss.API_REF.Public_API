/*
* Copyright (c) 2003-2009 Nokia Corporation and/or its subsidiary(-ies).
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
* Description:
* Name        : sipprofileregistry.h
* Part of     : SIP Profile Client
* Interface   : SDK API, SIP Profile API
* The class for using SIP profiles
* Version     : 1.0
*
*/



#ifndef CSIPPROFILEREGISTRY_H
#define CSIPPROFILEREGISTRY_H

//  INCLUDES
#include <e32base.h>
#include <e32std.h>
#include <badesca.h>
#include "sipprofileregistrybase.h"

// FORWARD DECLARATIONS
class CSIP;
class CSIPConnection;
class CSIPProfile;
class MSIPProfileRegistryObserver;
class MSIPConnectionObserver;


// CLASS DECLARATION
/**
*  @publishedAll
*  @released
*
*  The class for retrieving SIP profiles from permanent storage.
*  This class provides services for retreiving SIP profiles
*  and enabling/disabling them for the usage.
*
*  The user can create only one instance of this class (a singleton class).
*
*  @lib sipprofilecli.lib
*/
class CSIPProfileRegistry: public CSIPProfileRegistryBase
    {
    public:  // Constructors and destructor
        /**
        * Two-phased constructor.
        * This constructor should be used if the client intends
        * to use SIP services with profiles.
        * @param aSip a SIP client providing connection to SIP stack.
        * @param aObserver a observer for SIP profile change events.
        */
        IMPORT_C static CSIPProfileRegistry* NewL(
            CSIP& aSip,
            MSIPProfileRegistryObserver& aObserver);

        /**
        * Two-phased constructor.
        * This constructor should be used if the client intends
        * to use SIP services with profiles.
        * Constructs an object and adds the pointer to the cleanup stack;
        * @param aSip a SIP client providing connection to SIP stack.
        * @param aObserver a observer for SIP profile change events.
        */
        IMPORT_C static CSIPProfileRegistry* NewLC(
            CSIP& aSip,
            MSIPProfileRegistryObserver& aObserver);

        /**
        * Destructor
        */
        IMPORT_C ~CSIPProfileRegistry();

    public: // New functions
        /**
        * Gets handle to the SIP server
        * @return handle to the SIP server
        */
        IMPORT_C CSIP& SIP() const;

        /**
        * Gets the SIP connection to be used with this SIP profile.
        * @pre IsEnabled() == ETrue
        * @param aProfile a sip profile
        * @return a SIP connection to be used; the owneship is transfered
        * @leave KErrNoMemory if out of memory
        * @capability NetworkServices
        */
        IMPORT_C CSIPConnection* ConnectionL(
            CSIPProfile& aProfile);

        /**
        * Enables the SIP profile for use.
        * Enabling the SIP profile will cause the SIP profile to
        * be registered if its status was unregistered.
        * The user must check the profile status after calling this
        * function. In case the profile is not registered the user must
        * wait until the it is notified about profile registration 
        * on MSIPProfileRegistryObserver-callback interface.
        * @param aProfile a sip profile to enable
        * @param aObserver a observer for SIP connection events
        * @leave KErrNotFound if non-existing profile is provided
        * @capability NetworkServices
        */
        IMPORT_C void EnableL(
            CSIPProfile& aProfile,
            MSIPConnectionObserver &aObserver);
        
        /**
        * Disables the usage of SIP profile
        * @param aProfile a sip profile to disable
        * @return KErrNone if SIP profile was successfully disabled; 
        *         system wide error otherwise
        * @capability NetworkServices
        */
        IMPORT_C TInt Disable(CSIPProfile& aProfile);

        /**
        * Tests is the SIP profile enabled for the use
        * @param aProfile a SIP profile to be checked
        * @return ETrue if SIP profile is enabled; EFalse otherwise
        */
        IMPORT_C TBool IsEnabled(const CSIPProfile& aProfile) const;
        
        /**
        * Force disables the usage of SIP profile
        * All Profile related activities will be stopped ungracefully
        * @param aProfile a sip profile to disable
        * @return KErrNone if SIP profile was successfully disabled; 
        *         system wide error otherwise
        * @capability NetworkControl
        */
        IMPORT_C TInt ForceDisable(CSIPProfile& aProfile);
        
        /**
        * Refreshes the Enabled SIP profile for use.
        * Refreshing the Enabled Profile will cause the SIP Profile to
        * get Registered if its status was not registered. 
        * This function has to be used when the profile is in Enabled state and 
        * might be unregistered due to a connection loss.
        * @param aProfile a sip profile to enable
        * @leave KErrNotFound if non-existing profile is provided
        * @leave KErrArgument if the profile is not previously Enabled and in Unregistered state.
        * @capability NetworkServices
        */
        
        IMPORT_C void RefreshEnableL(CSIPProfile& aProfile);

    public: 

        /**
        * @internalComponent
        */
        CSIPProfile* NewInstanceL();
    
    private:
        
        CSIPProfileRegistry();
        CSIPProfileRegistry(CSIP& aSip, MSIPProfileRegistryObserver& aObserver);
        void ConstructL();
        
    private: 

        CSIP& iSip;
        MSIPConnectionObserver* iConnectionObserver;
    };

#endif // CSIPPROFILEREGISTRY_H
