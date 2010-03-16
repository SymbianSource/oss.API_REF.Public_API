/*
* Copyright (c) 2006-2009 Nokia Corporation and/or its subsidiary(-ies).
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
* Name        : siphttpdigest.h
* Part of     : SIP Client
* Interface   : SDK API, SIP Client API
* Version     : 2.0
*
*/



#ifndef CSIPHTTPDIGEST_H
#define CSIPHTTPDIGEST_H

// INCLUDES 
#include <e32base.h>
#include "_sipcodecdefs.h"

// FORWARD DECLARATIONS
class CSIP;
class MSIPHttpDigestChallengeObserver;
class MSIPHttpDigestChallengeObserver2;
class CSIPClientTransaction;
class CSIPRefresh;

// CLASS DECLARATION

/**
* @publishedAll
* @released
*
* Class for managing SIP HTTP Digest security settings.
* Class provides functions for setting/removing
* HTTP Digest security mechanism related parameters.
* If the user does not use the class for the providing credentials for the
* received challenges, an error will be returned to the original request in
* case it was challenged.
* 
* Note that the user will be asked to provide credentials one realm
* at the time.
*
*  @lib sipclient.lib
*/
class CSIPHttpDigest : public CBase
	{
	public: // Constructors and destructor
	
		/**
		* Two-phased constructor.
		* @param aSIP a handle to SIP server
		* @param aObserver an observer for the received challenges
		* @return New object, ownership is transferred.
		*/
		IMPORT_C static CSIPHttpDigest*
			NewL(CSIP& aSIP,
				 MSIPHttpDigestChallengeObserver& aObserver);
				 
		/**
		* Two-phased constructor.
		* @param aSIP a handle to SIP server
		* @param aObserver an observer for the received challenges
		* @return New object, ownership is transferred.
		*/
		IMPORT_C static CSIPHttpDigest*
			NewLC(CSIP& aSIP,
				  MSIPHttpDigestChallengeObserver& aObserver);

		/**
		* Two-phased constructor.
		* @param aSIP a handle to SIP server
		* @param aObserver2 an observer for the received challenges
		* @return New object, ownership is transferred.
		*/
		IMPORT_C static CSIPHttpDigest*
			NewL(CSIP& aSIP,
				 MSIPHttpDigestChallengeObserver2& aObserver2);
				 
		/**
		* Two-phased constructor.
		* @param aSIP a handle to SIP server
		* @param aObserver2 an observer for the received challenges
		* @return New object, ownership is transferred.
		*/
		IMPORT_C static CSIPHttpDigest*
			NewLC(CSIP& aSIP,
				  MSIPHttpDigestChallengeObserver2& aObserver2);
				  
		IMPORT_C ~CSIPHttpDigest();

	public: // New functions

        /**
		* Sets credentials for the realm of the outbound proxy.
		* Must be used in case the realm is the realm of the outbound proxy and
		* the request for credentials was received from callback
		* MSIPHttpDigestChallengeObserver::ChallengeReceived.		
		* The user can set credentials only upon request from the
		* SIP implementation.
		* @pre aOutboundProxy, aRealm, aUsername and aPasswd must not be empty
		*	   descriptors.
		* @param aOutboundProxy an outbound proxy (FQDN or IP address)
		* @param aRealm servers's realm
		* @param aUsername user's name
		* @param aPasswd user's password for the given server's realm
		* @leave KErrNoMemory if out of memory
		* @leave KErrArgument if some of the parameters is an empty descriptor
		* @leave KErrSIPResourceNotAvailable if a required object has been
		*		 deleted
		*/
		IMPORT_C void SetCredentialsL(const TDesC8& aOutboundProxy,
			                          const TDesC8& aRealm,
			                          const TDesC8& aUsername,
			                          const TDesC8& aPasswd);
        /**
		* Sets parameters for the realm.
		* Should be used in case the realm is not a realm of an outbound proxy 
		* and the request for credentials was received from callback
		* MSIPHttpDigestChallengeObserver::ChallengeReceived.		
		* The user can set credentials only upon request from the
		* SIP implementation.
		* @pre aRealm, aUsername and aPasswd must not be empty descriptors.
		* @param aRealm servers's realm
		* @param aUsername user's name
		* @param aPasswd user's password for the given server's realm
		* @leave KErrNoMemory if out of memory
		* @leave KErrArgument if some of the parameters is an empty descriptor
		* @leave KErrSIPResourceNotAvailable if a required object has been
		*		 deleted
		*/
		IMPORT_C void SetCredentialsL(const TDesC8& aRealm,
			                          const TDesC8& aUsername,
			                          const TDesC8& aPasswd);

        /**
		* Sets credentials for the realm for the specific transaction.
		* Must be used when the request for credentials was received 
		* from callback MSIPHttpDigestChallengeObserver2::ChallengeReceived with 
		* CSIPClientTransaction as the parameter.
		* @pre aRealm, aUsername and aPasswd must not be empty descriptors.
		* @param aTransaction the transaction that was passed as a parameter
		*        to MSIPHttpDigestChallengeObserver2::ChallengeReceived
		* @param aOutboundProxy an outbound proxy (FQDN or IP address) if
		*        the challenge received had Proxy-Authenticate-header(s).
		*        Otherwise KNullDesC8 should passed.
		* @param aRealm servers's realm
		* @param aUsername user's name
		* @param aPasswd user's password for the given server's realm
		* @leave KErrNoMemory if out of memory
		* @leave KErrArgument if some of the parameters is an empty descriptor
		* @leave KErrSIPResourceNotAvailable if a required object has been
		*		 deleted
		*/
		IMPORT_C void SetCredentialsL(const CSIPClientTransaction& aTransaction,
		                              const TDesC8& aOutboundProxy,
			                          const TDesC8& aRealm,
			                          const TDesC8& aUsername,
			                          const TDesC8& aPasswd);

        /**
		* Sets credentials for the realm for the specific refresh.
		* Must be used when the request for credentials was received 
		* from callback MSIPHttpDigestChallengeObserver2::ChallengeReceived with 
		* CSIPRefresh as the parameter.
		* @pre aRealm, aUsername and aPasswd must not be empty descriptors.
		* @param aRefresh the refresh that was passed as a parameter
		*        to MSIPHttpDigestChallengeObserver2::ChallengeReceived
		* @param aOutboundProxy an outbound proxy (FQDN or IP address) if
		*        the challenge received had Proxy-Authenticate-header(s).
		*        Otherwise KNullDesC8 should passed.
		* @param aRealm servers's realm
		* @param aUsername user's name
		* @param aPasswd user's password for the given server's realm
		* @leave KErrNoMemory if out of memory
		* @leave KErrArgument if some of the parameters is an empty descriptor
		* @leave KErrSIPResourceNotAvailable if a required object has been
		*		 deleted
		*/
		IMPORT_C void SetCredentialsL(const CSIPRefresh& aRefresh,
		                              const TDesC8& aOutboundProxy,
			                          const TDesC8& aRealm,
			                          const TDesC8& aUsername,
			                          const TDesC8& aPasswd);
			            
        /**
		* Removes all set credentials for the realm.
		* Must not be used if the user implements 
		* MSIPHttpDigestChallengeObserver2.
		* @pre aRealm must not be an empty descriptor
		* @param aRealm servers's realm
		* @return KErrNone if no error
		*		  KErrArgument if aRealm is an empty descriptor
		*		  KErrNoMemory if out of memory
		*		  KErrNotFound if the given realm was not found
        */
		IMPORT_C TInt RemoveCredentials(const TDesC8& aRealm);
		
        /**
		* Removes all set credentials by the user.
		* Must not be used if the user implements 
		* MSIPHttpDigestChallengeObserver2.		
		* @return KErrNone if succesful; KErrNoMemory if out of memory 
        */
		IMPORT_C TInt RemoveCredentials();
					                                                        
		/**
		* Sets the observer	to listen for the possible received challenges. 
		* Replaces the existing MSIPHttpDigestChallengeObserver or
		* MSIPHttpDigestChallengeObserver2.
		* @param aObserver an observer for the received challenges. 
		*/
		IMPORT_C void SetObserver(MSIPHttpDigestChallengeObserver& aObserver);
		
		/**
		* Sets the observer	to listen for the possible received challenges. 
		* Replaces the existing MSIPHttpDigestChallengeObserver or
		* MSIPHttpDigestChallengeObserver2.
		* @param aObserver an observer for the received challenges. 
		*/
		IMPORT_C void SetObserver(MSIPHttpDigestChallengeObserver2& aObserver);		
		
		/**
		* Ignores the challenge for the realm. As a result the error will be
		* generated to the original SIP request. 
		* @pre aRealm must not be an empty descriptor
		* @param aRealm a realm for which the challenge was ignored
		* @return KErrNone if no error
		*		  KErrNotFound if the given realm was not found
		*		  KErrArgument if aRealm is an empty descriptor
		*/
		IMPORT_C TInt IgnoreChallenge(const TDesC8& aRealm);

		/**
		* Ignores the challenge for the realm for the specific transaction.
		* As a result KErrForbidden will be generated 
		* to the original SIP request.
		* @pre aRealm must not be an empty descriptor
		* @param aTransaction the transaction that was passed as a parameter
		*        to MSIPHttpDigestChallengeObserver2::ChallengeReceived		
		* @param aRealm a realm for which the challenge was ignored
		* @return KErrNone if no error
		*		  KErrNotFound if the given realm was not found
		*		  KErrArgument if aRealm is an empty descriptor
		*/
		IMPORT_C TInt IgnoreChallenge(const CSIPClientTransaction& aTransaction,
		                              const TDesC8& aRealm);

		/**
		* Ignores the challenge for the realm for the specific refresh.
		* As a result the error will be generated 
		* to the original SIP request.
		* @pre aRealm must not be an empty descriptor
		* @param aRefresh the refresh that was passed as a parameter
		*        to MSIPHttpDigestChallengeObserver2::ChallengeReceived		
		* @param aRealm a realm for which the challenge was ignored
		* @return KErrNone if no error
		*		  KErrNotFound if the given realm was not found
		*		  KErrArgument if aRealm is an empty descriptor
		*/
		IMPORT_C TInt IgnoreChallenge(const CSIPRefresh& aRefresh,
		                              const TDesC8& aRealm);

	public: // New functions, for internal use

		void CSIPDeleted();

	private: // Constructors

        CSIPHttpDigest(CSIP& aSIP);
		CSIPHttpDigest(const CSIPHttpDigest& aHttpDigest);
		CSIPHttpDigest& operator=(const CSIPHttpDigest& aHttpDigest);

		void ConstructL(MSIPHttpDigestChallengeObserver& aObserver);
		
		void ConstructL(MSIPHttpDigestChallengeObserver2& aObserver2);
       
    private: // New functions
    
		TInt RemoveCredentialParams(const TDesC8& aRealm) const;

		void SetCredentialParamsL(TUint32 aRequestId,
		                          TUint32 aRefreshId,
		                          const TDesC8& aOutboundProxy,
		                          const TDesC8& aRealm,
				                  const TDesC8& aUsername,
				                  const TDesC8& aPasswd) const;		
		
		TInt IgnoreChallenge(TUint32 aRequestId,
		                     TUint32 aRefreshId,
		                     const TDesC8& aRealm);       
          
    private: // Data

        CSIP* iSIP;

	private: // For testing purposes

	    UNIT_TEST(CSIP_Test)
	};

#endif // CSIPHTTPDIGEST_H
