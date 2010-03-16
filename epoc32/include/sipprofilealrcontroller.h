/*
* Copyright (c) 2007-2009 Nokia Corporation and/or its subsidiary(-ies).
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
* Name          : sipprofilealrcontroller.h
* Part of       : SIP / SIP Profile Agent
* Version       : SIP/6.0 
*
*/



#ifndef CSIPPROFILEALRCONTROLLER_H
#define CSIPPROFILEALRCONTROLLER_H

// INCLUDES
#include <e32base.h>

// FORWARD DECLARATIONS
class CSIPProfileRegistryBase;
class MSipProfileAlrObserver;

// CLASS DECLARATION
/**
*  @publishedAll
*  @released
*
*  This class provides functions to control 
*  ALR (Application Level Roaming) for SIP profiles that have 
*  a SNAP (Service Network Access Point) ID configured. 
*  By default the clients allow automatic roaming between 
*  IAPs (Internet Access Point) for a SIP profile. 
*  The clients wanting to control the roaming must instantiate this class.
*  After that all the IAP availability events received through 
*  MSipProfileAlrObserver::AlrEvent must be allowed or disallowed.
*
*  @lib sipprofilecli.lib
*/
class CSipProfileAlrController : public CBase
    {
    public: // Constructors and destructor
    
        /**
        * Two-phased constructor.
        * @param aRegistry a SIP profile registry instance.
        * @param aObserver a observer for IAP migration events.
        */
        IMPORT_C static CSipProfileAlrController* NewL(
            CSIPProfileRegistryBase& aRegistry,
            MSipProfileAlrObserver& aObserver );

        /**
        * Two-phased constructor.
        * Constructs an object and adds the pointer to the cleanup stack.
        * @param aRegistry a SIP profile registry instance.
        * @param aObserver a observer for IAP migration events.
        */
        IMPORT_C static CSipProfileAlrController* NewLC(
            CSIPProfileRegistryBase& aRegistry,
            MSipProfileAlrObserver& aObserver );   
    
        /**
        * Destructor.
        */
        ~CSipProfileAlrController();

    public: // New functions

        /**
        * Allows SIP Profile Agent to start the migration 
        * to a new IAP for the profile.
        * If also all the other clients allow the migration,
        * migration will be started and all the clients are informed
        * with MSipProfileAlrObserver::AlrEvent(EMigrationStarted,...).
        * When MSipProfileAlrObserver::AlrEvent(EMigrationCompleted,...)
        * gets called the migration has been completed and
        * the related SIP profile has been registered via the new IAP. 
        * @param aProfileId the SIP profile id
        * @param aIapId the new IAP id. 
        */
        IMPORT_C void AllowMigrationL( TUint32 aProfileId,
                                       TUint32 aIapId );

        /**
        * Disallows SIP Profile Agent to migrate 
        * to a new IAP for the profile.
        * After the client calls this function all the clients are informed
        * with MSipProfileAlrObserver::AlrError(...).
        * @param aProfileId the SIP profile id
        * @param aIapId the new IAP id. 
        */
        IMPORT_C void DisallowMigrationL( TUint32 aProfileId,
                                          TUint32 aIapId );
                                          
        /**
        * Refreshes the list of available IAPs for 
        * the SNAP configured for the profile.
        * If a new better IAP is available, it is offered via
        * MSipProfileAlrObserver::AlrEvent(EIapAvailable,...).
        * This function should be called if migration 
        * to a IAP has been previously disallowed and the client wants to 
        * check whether the better IAP is still available.
        * @param aProfileId the SIP profile id 
        */
        IMPORT_C void RefreshIapAvailabilityL( TUint32 aProfileId ); 


    private: // Constructors:

        CSipProfileAlrController( CSIPProfileRegistryBase& aRegistry );        
        void ConstructL( MSipProfileAlrObserver& aObserver );
        
    private: // Data
    
    	CSIPProfileRegistryBase& iRegistry;
    
    private: // For testing purposes	

	    friend class CSIPProfileAlrControllerTest;        
    };

#endif // CSIPPROFILEALRCONTROLLER_H
