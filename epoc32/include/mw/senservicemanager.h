/*
* Copyright (c) 2002-2005 Nokia Corporation and/or its subsidiary(-ies). 
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
* Description:        CSenServiceManager class offers API for
*                accessing and managing WebServicesFramework  
*                (WSF) service and identity related data.
*
*/








#ifndef SEN_SERVICE_MANAGER_H
#define SEN_SERVICE_MANAGER_H

//  INCLUDES
#include <e32base.h> // for CActive
#include <e32std.h>  // for RPointerArray
#include <badesca.h>

#include <MSenServiceConsumer.h>
#include <MSenServiceDescription.h>
#include <SenCredential2.h>
#include <SenXmlProperties.h>
#include "MSenAuthenticationProvider.h"

// FORWARD DECLARATIONS
class CSenXmlServiceDescription;
class CSenIdentityProvider;

// DATA TYPES
typedef RPointerArray<CSenXmlServiceDescription> RServiceDescriptionArray;
typedef RPointerArray<CSenCredential2> RCredentialArray;
typedef RPointerArray<CSenXmlProperties> RCredentialPropertiesArray;

// CLASS DECLARATION

/**
* CSenServiceManager class offers API for accessing and managing 
* WebServicesFramework (WSF) service and identity related data.
* The class is designed using abstract factory pattern: 
* it only offers a instance (pointer) to the actual implementation 
* class meeting this interface.
* Typically, service consumers use of CSenServiceManager to register service
* or identity based data, which is required for accessing some invocable, 
* possibly remote service.
* The class is meant for both default frameworks offered by WSF 
* and for any custom plug-in service invocation framework implementation.
* The default frameworks are:
*      1) Identity Based Web Services Framework (ID-WSF).
*      2) Basic Web Services Framework.
* For Basic Web Service consumer, the only applicable operations are 
* Identity data managing methods. These can be used to make connection 
* specific Basic Authentication (BASIC-AUTH) credentials available without 
* later end-user interaction. Otherwise required authentication info 
* will be requested via notifier dialog prompts.
* ID-WSF consumer has to use the CSenServiceManager methods to register 
* authentication service description and identity provider (which are 
* the same service in ID-WSF) and finally associate some actual service 
* (contract to a WSP) to this IDP.
* 
* The current client-server framework implementation of CSenServiceManager 
* is synchronous, although class inherits CActive for future extensions.
* So, the class instance will not be an active object handled 
* by ActiveScheduler, and it does not have implementation 
* in RunL() or DoCancel() methods.
*
*  @lib SenServMgr.lib
*  @since Series60 3.0
*/
class CSenServiceManager : public CActive
    {
    public: // Constructors and destructor

        /**
        * Two-phased constructor.
        */
        IMPORT_C static CSenServiceManager* NewL();
    
        /**
        * Two-phased constructor.
        */
        IMPORT_C static CSenServiceManager* NewLC();
        
        /**
        * Two-phased constructor.
        */
        IMPORT_C static CSenServiceManager* NewL(MSenAuthenticationProvider& aAuthProvider);
    
        /**
        * Two-phased constructor.
        */
        IMPORT_C static CSenServiceManager* NewLC(MSenAuthenticationProvider& aAuthProvider);

        // New functions

        /**
        * Consumers use this to find services with matching URI 
        * (contract or endpoint) of the service. ID-WSF consumers
        * typically use the service type (contract) they are
        * interested on. 
        * Contract is typically some URN and most endpoints are URLs.
        * The Basic Web Service descriptions are not written into WSF
        * database, so they cannot be searched using this method.
        * @param    aUri specifies the search string (contract or endpoint)
        *           which will be used to find matching service descriptions.
        * @param    aList an array with 0 or more service descriptions which
        *           are already registered to WSF.
        *           The ownership of the array is passed to the caller so before
        *           the array goes out of scope in the client, the caller must
        *           call RPointerArray::ResetAndDestroy() on the array to free any
        *           entries.
        * @return status/error code.
        * Status codes:
        * KErrNone                      ok
        * Error codes:
        * KErrNotFound                  No matching service description was found.
        * Other error codes are system-wide Symbian error codes.
        */
        virtual TInt ServiceDescriptionsL(  const TDesC8& aURI,
                                            RServiceDescriptionArray& aList) = 0;

        /**
        * Consumers use this to find services with matching 
        * service description. The service description may 
        * include specific contract or endpoint of the service
        * as a searching criteria.
        * Contract is typically some URN and most endpoints are URLs.
        * The Basic Web Service descriptions are not written into WSF
        * database, so they cannot be searched using this method.
        * @param    aSD a service description specifying search pattern 
        *           (which includes contract, URI or both) used to find 
        *           matching service descriptions.
        * @param    aList an array with 0 or more ServiceDescriptions which
        *           are already registered to WSF.
        *           The ownership of the array is passed to the caller so before
        *           the array goes out of scope in the client, the caller must
        *           call RPointerArray::ResetAndDestroy() on the array to free any
        *           entries.
        * @return status/error code.
        * Status codes:
        * KErrNone                      ok
        * Error codes:
        * KErrNotFound                  No matching service descriptions found.
        * Other error codes are system-wide Symbian error codes.
        */
        virtual TInt ServiceDescriptionsL(  MSenServiceDescription& aSD,
                                            RServiceDescriptionArray& aList) = 0;

        /**
        * Used by consumer applications to register new service to WSF
        * The service could not otherwise be discovered while creating 
        * a service connection. ID-WSF Authentication Service is an 
        * example of this kind of remote service.
        * The Basic Web Service consumer does not need to and cannot 
        * register any service related data.
        * In service description, the default framework ID is "ID-WSF",
        * through which frameworks performing the actual registration
        * are looked up. For any custom framework plug-in, the framework
        * ID must be separately set.
        * For ID-WSF service descriptions  it is mandatory to set both 
        * contract and endpoint.
        * Calling the method performs one of the following:
        *      1. It registers a new service description
        *      2. It updates an existing service description
        *         with matching contract and endpoint.
        * @param    aSD a service description to be registered
        * @return status/error code.
        * Status codes:
        * KErrNone                      ok
        * Error codes:
        * KErrNotReady                  Service description couldn't be registered,
        *                               e.g. because end-user permission to modify
        *                               WSF data was not granted (a dialog prompt).
        * KErrNotFound                  Web Services framework couldn't find any
        *                               required framework plug-in used to register 
        *                               a service description of a given type
        *                               (framework ID).
        * KErrSenNoContract             Given service description didn't have
        *                               a contract specified, even if the used
        *                               framework needs one. For ID-WSF it is
        *                               mandatory to define a contract for
        *                               service description registration.
        * KErrSenNoEndpoint             Given service description didn't have
        *                               a endpoint specified, even if the used
        *                               framework needs one. For ID-WSF it is
        *                               mandatory to define an endpoint for
        *                               service description registration.
        * KErrSenNoContractNoEndPoint   Given service description didn't have
        *                               an endpoint and contract specified, even if the used
        *                               framework needs one. For ID-WSF it is
        *                               mandatory to define both an endpoint and contract for
        *                               service description registration.
        * Other error codes are system-wide Symbian error codes.
        */
        virtual TInt RegisterServiceDescriptionL(MSenServiceDescription& aSD) = 0;

        /**
        * Used by consumer application to to inform the ServiceManager 
        * about a service which no longer is available. The ServiceManager
        * will remove the service from its database as soon as it is no 
        * longer used.
        * @param    aSD a ServiceDescription to be unregistered
        * @return status/error code.
        * Status codes:
        * KErrNone                      ok
        * Error codes:
        * KErrBadDescriptor             aSD was invalid service description and
        *                               couldn't be unregistered.
        * KErrNotReady                  Service description couldn't be registered,
        *                               e.g. because end-user permission to modify
        *                               WSF data was not granted (a dialog prompt).
        * KErrNotFound                  Couldn't find a matching framework to 
        *                               register service description or couldn't
        *                               find a matching service description.
        * KErrSenNoContract             Given service description didn't have
        *                               a contract specified, even if the used
        *                               framework needs one.
        * KErrSenNoEndpoint             Given service description didn't have
        *                               a endpoint specified, even if the used
        *                               framework needs one.
        * KErrSenNoContractNoEndPoint   Given service description didn't have
        *                               an endpoint and contract specified, even if the used
        *                               framework needs one. For ID-WSF it is
        *                               mandatory to define both an endpoint and contract for
        *                               service description registration.
        * Other error codes are system-wide Symbian error codes.
        */
        virtual TInt UnregisterServiceDescriptionL(
                                                MSenServiceDescription& aSD) = 0;

        /**
        * Register an identity provider for the current active identity.
        * It is required for both Basic Web Service and ID-WSF consumers
        * that endpoint is defined in identity provider instance to make
        * this data accessible later on while creating a service connection.
        * @param    aProvider   an identity provider to be registered
        * @return status/error code.
        * Status codes:
        * KErrNone                      ok
        * Error codes:
        * KErrBadDescriptor             aProvider was an invalid identity provider
        *                               and couldn't be registered.
        * KErrNotReady                  Service description couldn't be registered,
        *                               e.g. because end-user permission to modify
        *                               WSF data was not granted (a dialog prompt).
        * KErrSenProviderIdInUseByAnotherEndpoint   
        *                               attempt to register an identity provider
        *                               failed, because ProviderID was already
        *                               reserved in the use of another endpoint.
        *
        *                               A possible work-around for this would be
        *                               to unregister such conflicting identity     
        *                               provider using this particular ProviderID,
        *                               but this solution is not recommended. Instead,
        *                               separate providers, locating in different 
        *                               endpoints, SHOULD always use different 
        *                               ProviderIDs.
        * Other error codes are system-wide Symbian error codes.
        */
        virtual TInt RegisterIdentityProviderL(CSenIdentityProvider& aProvider) = 0;

        /**
        * Unregister an identity provider from the current active Identity.
        * @param    aProvider an identity provider to be unregistered
        * @return status/error code.
        * Status codes:
        * KErrNone                      ok
        * Error codes:
        * KErrBadDescriptor             aProvider was an invalid identity provider
        *                               and couldn't be unregistered.
        * KErrNotReady                  Identity provider couldn't be unregistered,
        *                               e.g. because user didn't allow it.
        * KErrNotFound                  aProvider was not found and couldn't be
        *                               unregistered.
        * Other error codes are system-wide Symbian error codes.
        */
        virtual TInt UnregisterIdentityProviderL(
                                        CSenIdentityProvider& aProvider) = 0;


        /**
        * Consumer applications use this method to associate 
        * some pre-registered service to certain (registered)
        * identity provider. The association adds the service ID
        * (contract of the service that trusts this identity
        * provider) into WSF identity database.
        * In ID-WSF, consumers typically associate authentication
        * service description with some identity provider. This
        * way the ID-WSF framework can find the identity provider 
        * by using the contract of the service as a search pattern
        * (for e.g. liberty AS contract).
        * @param aURI either the contract or the endpoint 
        *             identifying some  service
        * @param aProviderID the ID of an identity provider
        * @return status/error code.
        * Status codes:
        * KErrNone                      ok
        * Error codes:
        * KErrArgument                  Either or both of the parameters were
        *                               zero-length or invalid descriptors
        * KErrNotReady                  Identity provider couldn't be unregistered,
        *                               e.g. because user didn't allow it.
        * KErrNotFound                  Web Services framework couldn't find
        *                               the identity provider by given provider ID.
        */
        virtual TInt AssociateServiceL( const TDesC8& aURI,
                                        const TDesC8& aProviderID) = 0;

        /**
        * Dissociate a service from an identity provider.
        * @param aServiceID the contract or endpoint of a service
        * @param aProviderID the id of an identity provider
        * @return status/error code.
        * Status codes:
        * KErrNone                      ok
        * Error codes:
        * KErrArgument                  Either or both of the parameters were
        *                               zero-length or invalid descriptors
        * KErrNotReady                  Service couldn't be dissociated, 
        *                               e.g. because user didn't allow it.
        * KErrNotFound                  Web Services framework couldn't find
        *                               the identity provider by given 
        *                               provider ID.
        */
        virtual TInt DissociateServiceL(const TDesC8& aServiceID,
                                        const TDesC8& aProviderID) = 0;
         
        /**
        * Consumer applications use this method for finding Credentials.
        * IdentityProvider or Username and Password are given either via 
        * IdentityProviderL() callback or UsernameL() and Password()
        * callbacks from MSenAuthenticationProvider (which can be given
        * through specialized NewL or NewLC methods).
        *
        * @param    aEndpoint       the endpoint which identifies the Credential
        * @param    aCredentials    an array with 0 or more Credentials.
        *                           The ownership of the array (and Credentials)
        *                           is passed to the caller so before the array
        *                           goes out of scope in the client, the caller
        *                           must call RPointerArray::ResetAndDestroy()
        *                           on the array to close the array and delete
        * @param    aCredentialProperties    an array with 0 or more
        *                           CredentialsProperties.
        *                           The ownership of the array (and
        *                           CredentialProperties) is passed to the caller
        *                           so before the array goes out of scope in the 
        *                           client, the caller must call
        *                           RPointerArray::ResetAndDestroy()
        *                           on the array to close the array and delete
        *                           all the CredentialProperties in the array.
        *                           Note: aCredentials array and
        *                                 aCredentialProperties array are in
        *                                 sync. If Credential has properties,
        *                                 properties are placed in same 
        *                                 position in aCredentialProperties array
        *                                 as raleted Credential in aCredentials
        *                                 array.
        *                           Note: If Credential has no properties,
        *                                 there is NULL in related position
        *                                 in aCredentialProperties array.
        *                           all the Credentials in the array.
        * Status codes:
        * KErrNone                  ok
        *
        * Error codes:
        * KErrNotFound              Web Services framework couldn't find
        *                           the Credentials using given Endpoint.
        * KErrSenNoPermission       Given IdentityProvider or Username and
        *                           Password did not match for IdentityProvider
        *                           which is related to found Credential(s).
        * Other error codes are system-wide Symbian error codes.
        */
        virtual TInt CredentialsL(const TDesC8& aEndpoint,
                                  RCredentialArray& aCredentials,
                                  RCredentialPropertiesArray& aCredentialProperties) = 0;
        
        /**
        * Consumer applications use this method for finding Credentials.
        *
        * @param    aEndpoint       the endpoint which identifies the Credential
        * @param    aIdP            the IdentityProvider which should match
        *                           for IdentityProvider which is related to
        *                           found Credential(s).
        * @param    aCredentials    an array with 0 or more Credentials.
        *                           The ownership of the array (and Credentials)
        *                           is passed to the caller so before the array
        *                           goes out of scope in the client, the caller
        *                           must call RPointerArray::ResetAndDestroy()
        *                           on the array to close the array and delete
        *                           all the Credentials in the array.
        * @param    aCredentialProperties    an array with 0 or more
        *                           CredentialsProperties.
        *                           The ownership of the array (and
        *                           CredentialProperties) is passed to the caller
        *                           so before the array goes out of scope in the 
        *                           client, the caller must call
        *                           RPointerArray::ResetAndDestroy()
        *                           on the array to close the array and delete
        *                           all the CredentialProperties in the array.
        *                           Note: aCredentials array and
        *                                 aCredentialProperties array are in
        *                                 sync. If Credential has properties,
        *                                 properties are placed in same 
        *                                 position in aCredentialProperties array
        *                                 as raleted Credential in aCredentials
        *                                 array.
        *                           Note: If Credential has no properties,
        *                                 there is NULL in related position
        *                                 in aCredentialProperties array.
        * Status codes:
        * KErrNone                  ok
        *
        * Error codes:
        * KErrNotFound              Web Services framework couldn't find
        *                           the Credentials using given Endpoint.
        * KErrSenNoPermission       Given IdentityProvider did not match for
        *                           IdentityProvider which is related to
        *                           found Credential.
        * Other error codes are system-wide Symbian error codes.
        */
        virtual TInt CredentialsL(const TDesC8& aEndpoint,
                                  const CSenIdentityProvider& aIdP,
                                  RCredentialArray& aCredentials,
                                  RCredentialPropertiesArray& aCredentialProperties) = 0;
        
        /**
        * Consumer applications use this method for finding Credentials.
        *
        * @param    aEndpoint       the endpoint which identifies the Credential
        * @param    aUserName       the username which should match for 
        *                           username in IdentityProvider which is related
        *                           to found Credential(s).
        * @param    aPassword       the password which should match for 
        *                           password in IdentityProvider which is related
        *                           to found Credential(s).
        * @param    aCredentials    an array with 0 or more Credentials.
        *                           The ownership of the array (and Credentials)
        *                           is passed to the caller so before the array
        *                           goes out of scope in the client, the caller
        *                           must call RPointerArray::ResetAndDestroy()
        *                           on the array to close the array and delete
        *                           all the Credentials in the array.
        * @param    aCredentialProperties    an array with 0 or more
        *                           CredentialsProperties.
        *                           The ownership of the array (and
        *                           CredentialProperties) is passed to the caller
        *                           so before the array goes out of scope in the 
        *                           client, the caller must call
        *                           RPointerArray::ResetAndDestroy()
        *                           on the array to close the array and delete
        *                           all the CredentialProperties in the array.
        *                           Note: aCredentials array and
        *                                 aCredentialProperties array are in
        *                                 sync. If Credential has properties,
        *                                 properties are placed in same 
        *                                 position in aCredentialProperties array
        *                                 as raleted Credential in aCredentials
        *                                 array.
        *                           Note: If Credential has no properties,
        *                                 there is NULL in related position
        *                                 in aCredentialProperties array.
        * Status codes:
        * KErrNone                  ok
        *
        * Error codes:
        * KErrNotFound              Web Services framework couldn't find
        *                           the Credentials using given Endpoint.
        * KErrSenNoPermission       Given IdentityProvider did not match for
        *                           IdentityProvider which is related to
        *                           found Credential.
        * Other error codes are system-wide Symbian error codes.
        */
        virtual TInt CredentialsL(const TDesC8& aEndpoint,
                                  const TDesC8& aUserName,
                                  const TDesC8& aPassword,
                                  RCredentialArray& aCredentials,
                                  RCredentialPropertiesArray& aCredentialProperties) = 0;

        /**
        * Consumer applications use this method for finding Credentials.
        * IdentityProvider or Username and Password are given either via 
        * IdentityProviderL() callback or UsernameL() and Password()
        * callbacks from MSenAuthenticationProvider (which can be given
        * through specialized NewL or NewLC methods).
        *
        * @param    aPattern        the pattern which identifies the Credential
        *                           Note: Pattern which was used to add Credential
        *                                 has to be used for finding Credential.
        *                           Note: Used Framework should specify what
        *                                 kind of pattern should be used
        *                                 for storing framework specific
        *                                 Credentials.
        * @param    aCredentials    an array with 0 or more Credentials.
        *                           The ownership of the array (and Credentials)
        *                           is passed to the caller so before the array
        *                           goes out of scope in the client, the caller
        *                           must call RPointerArray::ResetAndDestroy()
        *                           on the array to close the array and delete
        *                           all the Credentials in the array.
        * @param    aCredentialProperties    an array with 0 or more
        *                           CredentialsProperties.
        *                           The ownership of the array (and
        *                           CredentialProperties) is passed to the caller
        *                           so before the array goes out of scope in the 
        *                           client, the caller must call
        *                           RPointerArray::ResetAndDestroy()
        *                           on the array to close the array and delete
        *                           all the CredentialProperties in the array.
        *                           Note: aCredentials array and
        *                                 aCredentialProperties array are in
        *                                 sync. If Credential has properties,
        *                                 properties are placed in same 
        *                                 position in aCredentialProperties array
        *                                 as raleted Credential in aCredentials
        *                                 array.
        *                           Note: If Credential has no properties,
        *                                 there is NULL in related position
        *                                 in aCredentialProperties array.
        * Status codes:
        * KErrNone                  ok
        *
        * Error codes:
        * KErrNotFound              Web Services framework couldn't find
        *                           the Credentials using given Endpoint.
        * KErrSenNoPermission       Given IdentityProvider or Username and
        *                           Password did not match for IdentityProvider
        *                           which is related to found Credential(s).
        * Other error codes are system-wide Symbian error codes.
        */
        virtual TInt CredentialsL(const MSenServiceDescription& aPattern,
                                  RCredentialArray& aCredentials,
                                  RCredentialPropertiesArray& aCredentialProperties) = 0;
        
        /**
        * Consumer applications use this method for finding Credentials.
        *
        * @param    aPattern        the pattern which identifies the Credential
        *                           Note: Pattern which was used to add Credential
        *                                 has to be used for finding Credential.
        *                           Note: Used Framework should specify what
        *                                 kind of pattern should be used
        *                                 for storing framework specific
        *                                 Credentials.
        * @param    aIdP            the IdentityProvider which should match
        *                           for IdentityProvider which is related to
        *                           found Credential(s).
        * @param    aCredentials    an array with 0 or more Credentials.
        *                           The ownership of the array (and Credentials)
        *                           is passed to the caller so before the array
        *                           goes out of scope in the client, the caller
        *                           must call RPointerArray::ResetAndDestroy()
        *                           on the array to close the array and delete
        *                           all the Credentials in the array.
        * @param    aCredentialProperties    an array with 0 or more
        *                           CredentialsProperties.
        *                           The ownership of the array (and
        *                           CredentialProperties) is passed to the caller
        *                           so before the array goes out of scope in the 
        *                           client, the caller must call
        *                           RPointerArray::ResetAndDestroy()
        *                           on the array to close the array and delete
        *                           all the CredentialProperties in the array.
        *                           Note: aCredentials array and
        *                                 aCredentialProperties array are in
        *                                 sync. If Credential has properties,
        *                                 properties are placed in same 
        *                                 position in aCredentialProperties array
        *                                 as raleted Credential in aCredentials
        *                                 array.
        *                           Note: If Credential has no properties,
        *                                 there is NULL in related position
        *                                 in aCredentialProperties array.
        * Status codes:
        * KErrNone                  ok
        *
        * Error codes:
        * KErrNotFound              Web Services framework couldn't find
        *                           the Credentials using given Endpoint.
        * KErrSenNoPermission       Given IdentityProvider did not match for
        *                           IdentityProvider which is related to
        *                           found Credential.
        * Other error codes are system-wide Symbian error codes.
        */
        virtual TInt CredentialsL(const MSenServiceDescription& aPattern,
                                  const CSenIdentityProvider& aIdP,
                                  RCredentialArray& aCredentials,
                                  RCredentialPropertiesArray& aCredentialProperties) = 0;
                                  
        /**
        * Consumer applications use this method for finding Credentials.
        *
        * @param    aPattern        the pattern which identifies the Credential
        *                           Note: Pattern which was used to add Credential
        *                                 has to be used for finding Credential.
        *                           Note: Used Framework should specify what
        *                                 kind of pattern should be used
        *                                 for storing framework specific
        *                                 Credentials.
        * @param    aUserName       the username which should match for 
        *                           username in IdentityProvider which is related
        *                           to found Credential(s).
        * @param    aPassword       the password which should match for 
        *                           password in IdentityProvider which is related
        *                           to found Credential(s).
        * @param    aCredentials    an array with 0 or more Credentials.
        *                           The ownership of the array (and Credentials)
        *                           is passed to the caller so before the array
        *                           goes out of scope in the client, the caller
        *                           must call RPointerArray::ResetAndDestroy()
        *                           on the array to close the array and delete
        *                           all the Credentials in the array.
        * @param    aCredentialProperties    an array with 0 or more
        *                           CredentialsProperties.
        *                           The ownership of the array (and
        *                           CredentialProperties) is passed to the caller
        *                           so before the array goes out of scope in the 
        *                           client, the caller must call
        *                           RPointerArray::ResetAndDestroy()
        *                           on the array to close the array and delete
        *                           all the CredentialProperties in the array.
        *                           Note: aCredentials array and
        *                                 aCredentialProperties array are in
        *                                 sync. If Credential has properties,
        *                                 properties are placed in same 
        *                                 position in aCredentialProperties array
        *                                 as raleted Credential in aCredentials
        *                                 array.
        *                           Note: If Credential has no properties,
        *                                 there is NULL in related position
        *                                 in aCredentialProperties array.
        *                                 
        * Status codes:
        * KErrNone                  ok
        *
        * Error codes:
        * KErrNotFound              Web Services framework couldn't find
        *                           the Credentials using given Endpoint.
        * KErrSenNoPermission       Given IdentityProvider did not match for
        *                           IdentityProvider which is related to
        *                           found Credential.
        * Other error codes are system-wide Symbian error codes.
        */
        virtual TInt CredentialsL(const MSenServiceDescription& aPattern,
                                  const TDesC8& aUserName,
                                  const TDesC8& aPassword,
                                  RCredentialArray& aCredentials,
                                  RCredentialPropertiesArray& aCredentialProperties) = 0;
        /**
        * Consumer applications use this method for adding Credential.
        *
        * @param    aEndpoint       the endpoint which identifies the Credential
        * @param    aIdP            the IdentityProvider which will be related
        *                           to added Credential.
        * @param    aCredential     the Credential which will be added.
        * Status codes:
        * KErrNone                  ok
        *
        * Error codes:
        * KErrBadDescriptor         One of the parameters was invalid.
        * KErrNotFound              Given IdentityProvider was not found
        *                           and because of that Credential could
        *                           not be added. (Fix: Register IdentityProvider
        *                           first and try to add Credential after that.)
        *                           
        * Other error codes are system-wide Symbian error codes.
        */
        virtual TInt AddCredentialL(const TDesC8& aEndpoint,
                                    const CSenIdentityProvider& aIdP,
                                    const CSenCredential2& aCredential) = 0;
                                        
        /**
        * Consumer applications use this method for adding Credential.
        *
        * @param    aPattern        the pattern which identifies the Credential
        *                           Note: Exactly the same pattern has to be
        *                                 used for finding Credential.
        *                           Note: Used Framework should specify what
        *                                 kind of pattern should be used
        *                                 for handling framework specific
        *                                 Credentials.
        * @param    aIdP            the IdentityProvider which will be related
        *                           to added Credential.
        * @param    aCredential     the Credential which will be added.
        *
        * Status codes:
        * KErrNone                  ok
        *
        * Error codes:
        * KErrBadDescriptor         One of the parameters was invalid.
        * KErrNotFound              Given IdentityProvider was not found
        *                           and because of that Credential could
        *                           not be added. (Fix: Register IdentityProvider
        *                           first and try to add Credential after that)
        *                           
        * Other error codes are system-wide Symbian error codes.
        */
        virtual TInt AddCredentialL(const MSenServiceDescription& aPattern,
                                    const CSenIdentityProvider& aIdP,
                                    const CSenCredential2& aCredential) = 0;
                                    
        /**
        * Consumer applications use this method for adding Credential.
        *
        * @param    aEndpoint               the endpoint which identifies the
        *                                   Credential
        * @param    aIdP                    the IdentityProvider which will be
        *                                   related to added Credential.
        * @param    aCredential             the Credential which will be added.
        * @param    aCredentialProperties   the properties for Credential
        * Status codes:
        * KErrNone                  ok
        *
        * Error codes:
        * KErrBadDescriptor         One of the parameters was invalid.
        * KErrNotFound              Given IdentityProvider was not found
        *                           and because of that Credential could
        *                           not be added. (Fix: Register IdentityProvider
        *                           first and try to add Credential after that.)
        *                           
        * Other error codes are system-wide Symbian error codes.
        */
        virtual TInt AddCredentialL(const TDesC8& aEndpoint,
                                    const CSenIdentityProvider& aIdP,
                                    const CSenCredential2& aCredential,
                                    const CSenXmlProperties& aCredentialProperties) = 0;
                                        
        /**
        * Consumer applications use this method for adding Credential.
        *
        * @param    aPattern                the pattern which identifies the
        *                                   Credential
        *                                   Note: Exactly the same pattern has
        *                                         to be used for finding
        *                                         Credential.
        *                                   Note: Used Framework should specify
        *                                         what kind of pattern should be
        *                                         used for handling framework
        *                                         specific Credentials.
        * @param    aIdP                    the IdentityProvider which will be
        *                                   related to added Credential.
        * @param    aCredential             the Credential which will be added.
        * @param    aCredentialProperties   the properties for Credential
        *
        * Status codes:
        * KErrNone                  ok
        *
        * Error codes:
        * KErrBadDescriptor         One of the parameters was invalid.
        * KErrNotFound              Given IdentityProvider was not found
        *                           and because of that Credential could
        *                           not be added. (Fix: Register IdentityProvider
        *                           first and try to add Credential after that)
        *                           
        * Other error codes are system-wide Symbian error codes.
        */
        virtual TInt AddCredentialL(const MSenServiceDescription& aPattern,
                                    const CSenIdentityProvider& aIdP,
                                    const CSenCredential2& aCredential,
                                    const CSenXmlProperties& aCredentialProperties) = 0;
                                    
        /**
        * Consumer applications use this method for removing Credentials.
        *
        * @param    aPattern        the pattern which identifies the Credential
        *                           Note: Pattern which was used to add Credential
        *                                 has to be used for removing Credential.
        *                           Note: Used Framework should specify what
        *                                 kind of pattern should be used
        *                                 for handling framework specific
        *                                 Credentials.
        * @param    aIdP            the IdentityProvider which should match
        *                           for IdentityProvider which is related to
        *                           found Credential(s).
        * Status codes:
        * KErrNone                  ok
        *
        * Error codes:
        * KErrNotFound              Web Services framework couldn't find
        *                           the Credentials using given Pattern.
        * KErrSenNoPermission       Given IdentityProvider did not match for
        *                           IdentityProvider which is related to
        *                           found Credential(s).
        * Other error codes are system-wide Symbian error codes.
        */
        virtual TInt RemoveCredentialsL(const MSenServiceDescription& aPattern,
                                        const CSenIdentityProvider& aIdP) = 0;

        /**
        * Consumer applications use this method for removing Credentials.
        *
        * @param    aIdP            the IdentityProvider which should match
        *                           for IdentityProvider which is related to
        *                           found Credential(s).
        * Status codes:
        * KErrNone                  ok
        *
        * Error codes:
        * KErrNotFound              Web Services framework couldn't find
        *                           the Credentials using given Pattern.
        * KErrSenNoPermission       Given IdentityProvider did not match for
        *                           IdentityProvider which is related to
        *                           found Credential(s).
        * Other error codes are system-wide Symbian error codes.
        */
        virtual TInt RemoveCredentialsL(const CSenIdentityProvider& aIdP) = 0;

        /**
        * Consumer applications use this method for removing Credentials.
        *
        * @param    aPattern        the pattern which identifies the Credential
        *                           Note: Pattern which was used to add Credential
        *                                 has to be used for finding Credential.
        *                           Note: Used Framework should specify what
        *                                 kind of pattern should be used
        *                                 for handling framework specific
        *                                 Credentials.
        * @param    aUserName       the username which should match for 
        *                           username in IdentityProvider which is related
        *                           to found Credential(s).
        * @param    aPassword       the password which should match for 
        *                           password in IdentityProvider which is related
        *                           to found Credential(s).
        * Status codes:
        * KErrNone                  ok
        *
        * Error codes:
        * KErrNotFound              Web Services framework couldn't find
        *                           the Credentials using given Pattern.
        * KErrSenNoPermission       Given Username and Password did not match for
        *                           IdentityProvider which is related to
        *                           found Credential(s).
        * Other error codes are system-wide Symbian error codes.
        */
        virtual TInt RemoveCredentialsL(const MSenServiceDescription& aPattern,
                                        const TDesC8& aUserName,
                                        const TDesC8& aPassword) = 0;
                                        
        
        /**
        * This method provides an interface which is identified by unique ID (UID).
        * @param aUID is the UID of the interface being requested
        * @return TAny* pointer to the interface, or if no interface to 
        * given UID exists, function returns NULL. In typical cases, returned
        * pointer should be cast to some preknown M-class pointer (the actual
        * new interface).
        *
        * Currently, there is only one supported interface:
        * KSenInterfaceUidInternalServiceManager => MSenInternalServiceManager
        */  
        virtual TAny* InterfaceByUid( TUid aUID ) = 0;

    protected:
    
        /**
        * C++ default constructor 
        */
        CSenServiceManager();
    };

#endif //SEN_SERVICE_MANAGER_H

// End of File

