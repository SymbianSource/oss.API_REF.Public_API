/*
* Copyright (c) 2007-2009 Nokia Corporation and/or its subsidiary(-ies).
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
* Name        : sip.h
* Part of     : SIP Client
* Interface   : SDK API, SIP Client API
* Version     : 2.0
*
*/



#ifndef CSIP_H
#define CSIP_H

// INCLUDES
#include <e32base.h>

// FORWARD DECLARATIONS
class CDesC8Array;
class MSIPObserver;
class CSIPConnection;
class CSIPImplementation;

// CLASS DECLARATION

/**
*  @publishedAll
*  @released
*
*  Class for connecting to SIP server.
*
*  This class provides the connection to the SIP server and
*  provides functions for quering supported SIP security mechanisms and
*  the support of signalling compression (SigComp).
*
*  Note that the implementation uses strings defined in the SIP Codec
*  string pool. During instantiation the class will open SIP codec string pool 
*  for getting static strings and getting and setting dynamic strings.
* 
*  The user can create only one instance of this class. (a singleton class).
*
*  @lib sipclient.lib
*/
class CSIP : public CBase
	{
    public: // Constructors and destructor

	    /**
        * Two-phased constructor.
		* @param aUid an unique id that identifies client
		* @param aObserver a observer for asynchronous event
        * @return New object, ownership is transferred
        * @capability WriteDeviceData
        */
		IMPORT_C static CSIP* NewL(const TUid& aUid,
                                   MSIPObserver& aObserver);

	    /**
        * Two-phased constructor.
		* Constructs an object and adds the pointer to the cleanup stack.
		* @param aUid an unique id that identifies client
		* @param aObserver a observer for asynchronous event
        * @return New object, ownership is transferred
        * @capability WriteDeviceData
        */
		IMPORT_C static CSIP* NewLC(const TUid& aUid,
                                    MSIPObserver& aObserver);                                   

        /**
        * Destructor.               
        */
		IMPORT_C ~CSIP();

    public: // New functions

		/**
		* Gets all supported security mechanisms
		* @return supported SIP security mechanisms names (e.g. digest);
        *         the ownership is transferred
		*/
		IMPORT_C CDesC8Array* SupportedSecurityMechanismsL() const;

		/**
		* Checks if the signalling compression (SigComp) is supported.
        * Leaves on failure with a system wide error code.
		* @return ETrue if supported, EFalse otherwise
		*/
		IMPORT_C TBool IsSigCompSupportedL() const;

		/**
		* Gets negotiated security mechanism with the next hop
		* on the signaling path.
		* @param aHop the next hop's FQDN or numeric IP address
		* @return negotiated security mechanism or zero-pointer in case no
		*		  security mechanism was negotiated with the next hop;
		*		  the ownership is transferred
		*/
		IMPORT_C HBufC8* NegotiatedSecurityMechanismL(const TDesC8& aHop);

		/**
		* Checks if the user has a connection created for given IAP-id
		* @param aIapId IAP-id
 		* @return sip connection or 0-pointer if connection does not exist.
        *         Ownership is not transferred.
		*/
		IMPORT_C CSIPConnection* Connection(TUint32 aIapId) const;
		
        /*
        * By default the SIP built-in security mechanisms are enabled.
        * @param aEnabled if set to EFalse the build-in SIP security handling 
        *        mechanism is disabled.
        */
        IMPORT_C void SetSecurityHandlingL(TBool aEnabled);

        /*
        * Tests if SIP security handling mechanism is enabled/disabled
        * @return ETrue if built-in mechanisms are enabled, EFalse otherwise.
        */
        IMPORT_C TBool IsSecurityHandlingEnabled() const;		

	public: // New functions, for internal use

		/**
		* Returns the CSIPImplementation.
		*
 		* @return CSIPImplementation
		*/
		CSIPImplementation& Implementation();
		
    private: // Constructors
        CSIP();

        void ConstructL(const TUid& aUid, MSIPObserver& aObserver);

	private: // Data
		CSIPImplementation* iImplementation;

	private: // For testing purposes
#ifdef CPPUNIT_TEST
	    friend class CSIP_Test;
        friend class CSIPRegistrationBinding_Test;
        friend class CSIPInviteDialogAssoc_Test;
        friend class CSIPSubscribeDialogAssoc_Test;
        friend class CSIPReferDialogAssoc_Test;
#endif
		void __DbgTestInvariant() const;
	
		};

#endif
