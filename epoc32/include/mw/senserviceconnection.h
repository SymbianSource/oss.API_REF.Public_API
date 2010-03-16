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
* Description:        CSenServiceConnection offers public API for
*                service consumers to access invocable services, 
*                as a part of the Web Services Framework (WSF).
*
*/









#ifndef SEN_SERVICE_CONNECTION_H
#define SEN_SERVICE_CONNECTION_H

//  INCLUDES
#include <e32base.h> // for CActive
#include <MSenServiceConsumer.h>
#include <MSenServiceDescription.h>

#include <MSenAuthenticationProvider.h>

#include <SenSoapMessage.h>
#include <SenSoapMessage2.h>
//#include <SenAtomEntry.h>


#include <MSenMessage.h>

// CONSTANTS
const TInt KErrSenNotInitialized                    =   -30291;
const TInt KErrSenServiceConnectionBusy             =   -30292;
const TInt KErrConnectionInitializing               =   -30293;
const TInt KErrConnectionExpired                    =   -30294;
const TInt KErrSubmitting                           =   -30295;
const TInt KErrSenSoapFault                         =   -30296; 
const TInt KErrSenInternal                          =   -30297;
const TInt KErrSenNoEndpoint                        =   -30298;
const TInt KErrSenNoContract                        =   -30299;

const TInt KErrSenProviderIdInUseByAnotherEndpoint  =   -30305;
const TInt KErrSenNoContractNoEndPoint              =   -30306;

const TInt KErrSenBrokenSoapEnvelope                =   -30307;
const TInt KErrSenBrokenSoapFault                   =   -30308;
const TInt KErrSenCancelled                         =   -30309;


// HTTP transport error codes:
const TInt KErrSenNoHttpResponseBody                =   -30310;
const TInt KErrSenNoHttpContentType                 =   -30311;
const TInt KErrSenHttpRedirectRequiresConfirmation  =   -30312;

// SOAP message verification error codes:
const TInt KErrSenNoSoapBody                        =   -30313;
const TInt KErrSenNoSoapHeader                      =   -30314;
const TInt KErrSenNoPermission                      =   -30315; 

const TInt KErrSenHostNotAvailable                  =   -30318;

const TInt KErrSenAuthenticationFault               =   -30319;
const TInt KErrSenNoEndUserPermission               =   -30321;


const TInt KSenConnectionStatusCreateFailed         =  -1; // post-state
const TInt KSenConnectionStatusNew                  =   0; // post-state
const TInt KSenConnectionStatusReady                =   1; // post-state
const TInt KSenConnectionStatusExpired              =   2; // post-state
const TInt KSenConnectionStatusAuthentication       =   3; // pre-state
const TInt KSenConnectionStatusDiscovery            =   4; // pre-state
const TInt KSenConnectionStatusMetadataExchange     =   5; // pre-state

_LIT8(KDefaultBasicWebServicesFrameworkID,          "WS-I");
_LIT8(KDefaultIdWsfFrameworkID,                     "ID-WSF"); 
_LIT8(KDefaultRestServicesFrameworkID,              "REST");
_LIT8(KDefaultWSStarFrameworkID,                    "WS-STAR");
_LIT8(KDefaultAtomPubFrameworkID,                   "ATOM-PUB");
_LIT8(KDefaultOviFrameworkID,                       "OVI");

const TInt KSenTransportStatusCodeOffsetBaseHttp = 1000;
const TInt KSenTransportStatusCodeOffsetBaseVtcp = 2000;

const TInt KSenTransportStatusCodeVtcpInit =        2001; // KSenTransportStatusCodeOffsetBaseVtcp +1 
const TInt KSenTransportStatusCodeVtcpActive =      2002; // KSenTransportStatusCodeOffsetBaseVtcp +2 
const TInt KSenTransportStatusCodeVtcpSuspended =   2003; // KSenTransportStatusCodeOffsetBaseVtcp +3 
const TInt KSenTransportStatusCodeVtcpInactive =    2004; // KSenTransportStatusCodeOffsetBaseVtcp +4
const TInt KSenTransportStatusCodeVtcpUnavailable = 2005; // KSenTransportStatusCodeOffsetBaseVtcp +5

// FORWARD DECLARATIONS
class CSenServicePattern;
class CSenIdentityProvider;

// CLASS DECLARATION

/**
  * The class for connecting to service providers
  * through Web Services Framework (WSF). 
  *
  * The class offers asynchronous construction of a
  * service connection. Further, there are asynchronous
  * and synchronous interaction methods for e.g. sending 
  * and receiving data from (possibly remote) service.
  * 
  * WSF offers two default frameworks:
  *
  *   1. Identity Based Web Services Framework
  *      (ID-WSF). The framework ID for this is 
  *      KDefaultIdWsfFrameworkID ("ID-WSF").
  * 
  *   2. Basic Web Services Framework. Framework
  *      ID is KDefaultBasicWebServicesFrameworkID
  *      ("WS-I").
  * 
  * The most typical use of CSenServiceConnection
  * is to interact with a service of certain type
  * through some invocable framework and submitting
  * and receiving messages.
  *
  * In case of WebServices, the actual service is remote
  * and submitted messages are SOAP envelopes. However,
  * CSenServiceConnection supports accessing any
  * ServiceInvocationFramework which ECOM plug-in
  * implementation is present. These plug-ins may
  * further communicate with some service, including
  * local services. 
  * 
  * The link between CSenServiceConnection and any plug-in
  * implementation interacting with some service is the
  * framework ID, which is a property of ServiceDescription (SD)
  * and accessible via MSenServiceDescription interface, which
  * each SD class must implement. 
  * 
  * When creating a connection, one offers predefined SD as
  * an argument for asynchronous constructor. Or, optionally 
  * only a Liberty Alliance ID-WSF specific contract string 
  * - typically some URN. If only contract is offered, then
  * the created connection defaults to ID-WSF service and 
  * ID-WSF framework (ID) will be used.
  * 
  * The WSF further uses the offered framework ID while looking
  * up any matching framework plug-in implementation. As a
  * result the SD might be offered to several plug-ins.
* 
* @lib SenServConn.lib
*  @since Series60 3.0
*/

class CSenServiceConnection : public CActive, public MSenFragment
    {
    public: // Constructors and destructor

        /**
        * Two-phased constructor intended for Identity based service 
        * consumers (like ID-WSF). The pointer is left on the cleanup stack.
        * This constructor is ASYNCHRONOUS and the actual state of
        * created connection has to be observed from SetStatus() AND
        * HandleErrorL() functions.
        * If service is found, the SetStatus() call-back is performed
        * with a status value KSenConnectionStatusReady (1).
        * Contract of the service (typically some URN) is provided.
        * Authentication for the Web Service Provider (WSP) connection 
        * is resolved using one of the identity providers which have 
        * been associated with this contract (typically an URN).
        *
        * This constructor is ASYNCHRONOUS and the actual state of newly
        * created connection has to be observed from SetStatus() AND
        * HandleErrorL() functions.
        * If service is found, a SetStatus call-back with value
        * KSenConnectionStatusReady (1) is executed.
        * If some error occurs, HandleErrorL() will be called to inform the
        * creator of this connection (service consumer application)
        *
        *    For example, if service is not found, a system wide error
        *    code of -1 is deliver via HandleErrorL() to WSC.
        *
        *    Second example: server response HTTP 501 means, that this error
        *    code. 501 will be delivered via HandleErrorL() to WSC.
        *    This can happen in ID-WSF connection being initialized, if
        *    either Authentication Service (AS) or Discovery Service (DS)
        *    cannot be reached.
        *
        * @param aConsumer      (web) service consumer (for call-backs)
        * @param aContract      contract of the service, typically an URI.
        * @return a pointer to a CSenServiceConnection instance.
        *
        */
        IMPORT_C static CSenServiceConnection* NewL(MSenServiceConsumer& aConsumer,
                                                    const TDesC8& aContract);

        /**
        * Two-phased constructor intended for Identity based service 
        * consumers (like ID-WSF). 
        * This constructor is ASYNCHRONOUS and the actual state of
        * created connection has to be observed from SetStatus() and
        * HandleErrorL() functions.
        * If service is found, the SetStatus() call-back is performed
        * with a status value KSenConnectionStatusReady (1).
        * Contract of the service (typically some URN) is provided.
        * Authentication for the Web Service Provider (WSP) connection 
        * is resolved using one of the identity providers which have 
        * been associated with this contract (typically an URN).
        * This constructor is ASYNCHRONOUS and the actual state of newly
        * created connection has to be observed from SetStatus() AND
        * HandleErrorL() functions.
        * If service is found, a SetStatus call-back with value
        * KSenConnectionStatusReady (1) is executed.
        * If some error occurs, HandleErrorL() will be called to inform the
        * creator of this connection (service consumer application)
        *
        *    For example, if service is not found, a system wide error
        *    code of -1 is deliver via HandleErrorL() to WSC.
        *
        *    Second example: server response HTTP 501 means, that this error
        *    code. 501 will be delivered via HandleErrorL() to WSC.
        *    This can happen in ID-WSF connection being initialized, if
        *    either Authentication Service (AS) or Discovery Service (DS)
        *    cannot be reached.
        *
        * @param aConsumer      (web) service consumer (for call-backs)
        * @param aContract      contract of the service, typically an URI.
        * @return a pointer to a CSenServiceConnection instance.
        *                       The pointer is left on the cleanup stack.
        */
        IMPORT_C static CSenServiceConnection* NewLC(MSenServiceConsumer& aObserver,
                                                     const TDesC8& aContract);

        /**
        * Two-phased constructor using a service description.
        * This constructor is ASYNCHRONOUS and the actual state of
        * created connection has to be observed from SetStatus() and
        * HandleErrorL() functions.
        * If service is found, the SetStatus() call-back is executed
        * with a status value KSenConnectionStatusReady (1)
        * For ID-WSF connections, the authentication for the Web Service
        * Provider (WSP) connection is resolved using one of the identity 
        * providers which have been associated with the contract found in 
        * the SD. At minimum, the contract of the service (typically some URN)
        * has to provided in the SD.
        * Basic Web Service consumers instantiate a SD where an endpoint
        * and framework ID KDefaultBasicWebServicesFrameworkID are defined.
        * @param    aObserver connection observer.
        * @param    aServiceDescription is the description used to
        *               obtain a service connection.
        * @return   a pointer to a CSenServiceConnection instance.
        */
        IMPORT_C static CSenServiceConnection* NewL(MSenServiceConsumer& aObserver,
                                                    MSenServiceDescription& aServiceDescription);

        /**
        * Two-phased constructor using a service description. The pointer
        * is left on the cleanup stack.
        * This constructor is ASYNCHRONOUS and the actual state of
        * created connection has to be observed from SetStatus() AND
        * HandleErrorL() functions.
        * If service is found, the SetStatus() call-back is executed
        * with a status value KSenConnectionStatusReady (1)
        * For ID-WSF connections, the authentication for the Web Service
        * Provider (WSP) connection is resolved using one of the identity 
        * providers which have been associated with the contract found in 
        * the SD. At minimum, the contract of the service (typically some URN)
        * has to provided in the SD.
        * Basic Web Service consumers instantiate a SD where an endpoint
        * and framework ID KDefaultBasicWebServicesFrameworkID are defined.
        * @param    aObserver connection observer.
        * @param    aServiceDescription is the description used to
        *               obtain a service connection.
        * @return   a pointer to a CSenServiceConnection instance.
        *               The pointer is left on the cleanup stack.
        */
        IMPORT_C static CSenServiceConnection* NewLC(MSenServiceConsumer& aObserver,
                                                     MSenServiceDescription& aServiceDescription);

        /*
        * The ServicePattern version of two phased constructor. 
        * Note, that this method is intended to be used by service consumers
        * wishing to initialize connection in specific context called
        * consumer policy. In consumer policy, certain properties 
        * can be set to further define what kind of connection is acceptable
        * and how the connection interacts with transport (for example, which
        * Internet Access Point (IAP) will be used).
        * However, any ConsumerPolicy feature is applicable in 
        * one-policy-per-client scope and not used as a common policy.
        * To set permanent information about known WSP, please use the
        * CSenXmlServiceDescription, which implements MSenProviderPolicy
        * interface.
        * This constructor is ASYNCHRONOUS and the actual state of
        * created connection has to be observed from SetStatus() and
        * HandleErrorL() functions.
        * If service is found, the SetStatus() call-back is executed
        * with a status value KSenConnectionStatusReady (1)
        * For ID-WSF connections, the authentication for the Web Service
        * Provider (WSP) connection is resolved using one of the identity 
        * providers which have been associated with the contract found in 
        * the SD. At minimum, the contract of the service (typically some URN)
        * has to provided in the SD.
        * Basic Web Service consumers instantiate a SD where an endpoint
        * and framework ID KDefaultBasicWebServicesFrameworkID are defined.
        * @param    aObserver connection observer.
        * @param    aServiceDescription is the description used to
        *               obtain a service connection. 
        * @return   a pointer to a CSenServiceConnection instance.
        */
        IMPORT_C static CSenServiceConnection* NewL(MSenServiceConsumer& aObserver,
                                                    CSenServicePattern& aServicePattern);
    
        /*
        * The ServicePattern version of two phased constructor. 
        * Note, that this method is intended to be used by service consumers
        * wishing to initialize connection in specific context called
        * consumer policy. In consumer policy, certain properties 
        * can be set to further define what kind of connection is acceptable
        * and how the connection interacts with transport (for example, which
        * Internet Access Point (IAP) will be used).
        * However, any ConsumerPolicy feature is applicable in 
        * one-policy-per-client scope and not used as a common policy.
        * To set permanent information about known WSP, please use the
        * CSenXmlServiceDescription, which implements MSenProviderPolicy
        * interface.
        * This constructor is ASYNCHRONOUS and the actual state of
        * created connection has to be observed from SetStatus() and
        * HandleErrorL() functions.
        * If service is found, the SetStatus() call-back is executed
        * with a status value KSenConnectionStatusReady (1)
        * For ID-WSF connections, the authentication for the Web Service
        * Provider (WSP) connection is resolved using one of the identity 
        * providers which have been associated with the contract found in 
        * the SD. At minimum, the contract of the service (typically some URN)
        * has to provided in the SD.
        * Basic Web Service consumers instantiate a SD where an endpoint
        * and framework ID KDefaultBasicWebServicesFrameworkID are defined.
        * @param    aObserver connection observer.
        * @param    aServiceDescription is the description used to
        *               obtain a service connection. 
        * @return   a pointer to a CSenServiceConnection instance.
        *               The pointer is left on the cleanup stack.
        */
        IMPORT_C static CSenServiceConnection* NewLC(MSenServiceConsumer& aObserver,
                                                     CSenServicePattern& aServicePattern);
        
        /**
        * Two-phased constructor intended for Identity based service 
        * consumers (like ID-WSF). The pointer is left on the cleanup stack.
        * This constructor is ASYNCHRONOUS and the actual state of
        * created connection has to be observed from SetStatus() AND
        * HandleErrorL() functions.
        * If service is found, the SetStatus() call-back is performed
        * with a status value KSenConnectionStatusReady (1).
        * Contract of the service (typically some URN) is provided.
        * Authentication for the Web Service Provider (WSP) connection 
        * is resolved using one of the identity providers which have 
        * been associated with this contract (typically an URN).
        *
        * This constructor is ASYNCHRONOUS and the actual state of newly
        * created connection has to be observed from SetStatus() AND
        * HandleErrorL() functions.
        * If service is found, a SetStatus call-back with value
        * KSenConnectionStatusReady (1) is executed.
        * If some error occurs, HandleErrorL() will be called to inform the
        * creator of this connection (service consumer application)
        *
        *    For example, if service is not found, a system wide error
        *    code of -1 is deliver via HandleErrorL() to WSC.
        *
        *    Second example: server response HTTP 501 means, that this error
        *    code. 501 will be delivered via HandleErrorL() to WSC.
        *    This can happen in ID-WSF connection being initialized, if
        *    either Authentication Service (AS) or Discovery Service (DS)
        *    cannot be reached.
        *
        * @param aConsumer      (web) service consumer (for call-backs)
        * @param aContract      contract of the service, typically an URI.
        * @return a pointer to a CSenServiceConnection instance.
        * @param aAuthProvider      Authentication Provider
        */        
        IMPORT_C static CSenServiceConnection* NewL(MSenServiceConsumer& aConsumer,
                                                    const TDesC8& aContract,
                                                    MSenExtendedConsumerInterface& aExtendedConsumer);
        /**
        * Two-phased constructor intended for Identity based service 
        * consumers (like ID-WSF). 
        * This constructor is ASYNCHRONOUS and the actual state of
        * created connection has to be observed from SetStatus() and
        * HandleErrorL() functions.
        * If service is found, the SetStatus() call-back is performed
        * with a status value KSenConnectionStatusReady (1).
        * Contract of the service (typically some URN) is provided.
        * Authentication for the Web Service Provider (WSP) connection 
        * is resolved using one of the identity providers which have 
        * been associated with this contract (typically an URN).
        * This constructor is ASYNCHRONOUS and the actual state of newly
        * created connection has to be observed from SetStatus() AND
        * HandleErrorL() functions.
        * If service is found, a SetStatus call-back with value
        * KSenConnectionStatusReady (1) is executed.
        * If some error occurs, HandleErrorL() will be called to inform the
        * creator of this connection (service consumer application)
        *
        *    For example, if service is not found, a system wide error
        *    code of -1 is deliver via HandleErrorL() to WSC.
        *
        *    Second example: server response HTTP 501 means, that this error
        *    code. 501 will be delivered via HandleErrorL() to WSC.
        *    This can happen in ID-WSF connection being initialized, if
        *    either Authentication Service (AS) or Discovery Service (DS)
        *    cannot be reached.
        *
        * @param aConsumer      (web) service consumer (for call-backs)
        * @param aContract      contract of the service, typically an URI.
        * @param aAuthProvider      Authentication Provider        
        * @return a pointer to a CSenServiceConnection instance.
        *                       The pointer is left on the cleanup stack.
        */    
        IMPORT_C static CSenServiceConnection* NewLC(MSenServiceConsumer& aConsumer,
                                                     const TDesC8& aContract,
                                                     MSenExtendedConsumerInterface& aExtendedConsumer);
    
        /**
        * Two-phased constructor using a service description.
        * This constructor is ASYNCHRONOUS and the actual state of
        * created connection has to be observed from SetStatus() and
        * HandleErrorL() functions.
        * If service is found, the SetStatus() call-back is executed
        * with a status value KSenConnectionStatusReady (1)
        * For ID-WSF connections, the authentication for the Web Service
        * Provider (WSP) connection is resolved using one of the identity 
        * providers which have been associated with the contract found in 
        * the SD. At minimum, the contract of the service (typically some URN)
        * has to provided in the SD.
        * Basic Web Service consumers instantiate a SD where an endpoint
        * and framework ID KDefaultBasicWebServicesFrameworkID are defined.
        * @param    aConsumer connection observer.
        * @param    aServiceDescription is the description used to
        *               obtain a service connection.
        * @param 	aAuthProvider      Authentication Provider                
        * @return   a pointer to a CSenServiceConnection instance.
        */    
        IMPORT_C static CSenServiceConnection* NewL(MSenServiceConsumer& aConsumer,
                                                    MSenServiceDescription& aServiceDescription,
                                                    MSenExtendedConsumerInterface& aExtendedConsumer);
    
        /**
        * Two-phased constructor using a service description. The pointer
        * is left on the cleanup stack.
        * This constructor is ASYNCHRONOUS and the actual state of
        * created connection has to be observed from SetStatus() AND
        * HandleErrorL() functions.
        * If service is found, the SetStatus() call-back is executed
        * with a status value KSenConnectionStatusReady (1)
        * For ID-WSF connections, the authentication for the Web Service
        * Provider (WSP) connection is resolved using one of the identity 
        * providers which have been associated with the contract found in 
        * the SD. At minimum, the contract of the service (typically some URN)
        * has to provided in the SD.
        * Basic Web Service consumers instantiate a SD where an endpoint
        * and framework ID KDefaultBasicWebServicesFrameworkID are defined.
        * @param    aConsumer connection observer.
        * @param    aServiceDescription is the description used to
        *               obtain a service connection.
        * @param 	aAuthProvider      Authentication Provider                        
        * @return   a pointer to a CSenServiceConnection instance.
        *               The pointer is left on the cleanup stack.
        */    
        IMPORT_C static CSenServiceConnection* NewLC(MSenServiceConsumer& aConsumer,
                                                     MSenServiceDescription& aServiceDescription,
                                                     MSenExtendedConsumerInterface& aExtendedConsumer);
    
        /*
        * The ServicePattern version of two phased constructor. 
        * Note, that this method is intended to be used by service consumers
        * wishing to initialize connection in specific context called
        * consumer policy. In consumer policy, certain properties 
        * can be set to further define what kind of connection is acceptable
        * and how the connection interacts with transport (for example, which
        * Internet Access Point (IAP) will be used).
        * However, any ConsumerPolicy feature is applicable in 
        * one-policy-per-client scope and not used as a common policy.
        * To set permanent information about known WSP, please use the
        * CSenXmlServiceDescription, which implements MSenProviderPolicy
        * interface.
        * This constructor is ASYNCHRONOUS and the actual state of
        * created connection has to be observed from SetStatus() and
        * HandleErrorL() functions.
        * If service is found, the SetStatus() call-back is executed
        * with a status value KSenConnectionStatusReady (1)
        * For ID-WSF connections, the authentication for the Web Service
        * Provider (WSP) connection is resolved using one of the identity 
        * providers which have been associated with the contract found in 
        * the SD. At minimum, the contract of the service (typically some URN)
        * has to provided in the SD.
        * Basic Web Service consumers instantiate a SD where an endpoint
        * and framework ID KDefaultBasicWebServicesFrameworkID are defined.
        * @param    aConsumer connection observer.
        * @param    aServiceDescription is the description used to
        *               obtain a service connection.
        * @param 	aAuthProvider      Authentication Provider                                 
        * @return   a pointer to a CSenServiceConnection instance.
        */    
        IMPORT_C static CSenServiceConnection* NewL(MSenServiceConsumer& aConsumer,
                                                    CSenServicePattern& aServicePattern,
                                                    MSenExtendedConsumerInterface& aExtendedConsumer);

        /*
        * The ServicePattern version of two phased constructor. 
        * Note, that this method is intended to be used by service consumers
        * wishing to initialize connection in specific context called
        * consumer policy. In consumer policy, certain properties 
        * can be set to further define what kind of connection is acceptable
        * and how the connection interacts with transport (for example, which
        * Internet Access Point (IAP) will be used).
        * However, any ConsumerPolicy feature is applicable in 
        * one-policy-per-client scope and not used as a common policy.
        * To set permanent information about known WSP, please use the
        * CSenXmlServiceDescription, which implements MSenProviderPolicy
        * interface.
        * This constructor is ASYNCHRONOUS and the actual state of
        * created connection has to be observed from SetStatus() and
        * HandleErrorL() functions.
        * If service is found, the SetStatus() call-back is executed
        * with a status value KSenConnectionStatusReady (1)
        * For ID-WSF connections, the authentication for the Web Service
        * Provider (WSP) connection is resolved using one of the identity 
        * providers which have been associated with the contract found in 
        * the SD. At minimum, the contract of the service (typically some URN)
        * has to provided in the SD.
        * Basic Web Service consumers instantiate a SD where an endpoint
        * and framework ID KDefaultBasicWebServicesFrameworkID are defined.
        * @param    aConsumer connection observer.
        * @param    aServiceDescription is the description used to
        *               obtain a service connection.
        * @param 	aAuthProvider      Authentication Provider                                          
        * @return   a pointer to a CSenServiceConnection instance.
        *               The pointer is left on the cleanup stack.
        */
        IMPORT_C static CSenServiceConnection* NewLC(MSenServiceConsumer& aConsumer,
                                                     CSenServicePattern& aServicePattern,
                                                     MSenExtendedConsumerInterface& aExtendedConsumer);

        // New functions

        /**
        * Send an ASYNCHRONOUS request to a service.
        * In ID-WSF, the request data is a SOAP Body.
        * Response message is received either via 
        * HandleMessageL() or HandleErrorL() callback.
        * There are two default frameworks available - 
        * the Identity Based Web Service Framework (which ID is "ID-WSF") 
        * and the Basic Web Services Framework (which ID is "WS-I"). 
        * Please note, that Basic Web Services framework does NOT support this method.
        * Instead, one should send complete SOAP envelopes using SendL(CSenSoapEnvelope&).
        * So, currently this method is supported only in ID-WSF.
        * @param aRequest outgoing request message.
        * @return Transaction ID (positive integer) or error code, if method fails.
        * Transaction ids:
        * Positive integers                 SendL returns transaction ID of the request,
        *                                   which can be later on utilized inside
        *                                   HandleMessageL and HandleErrorL methods,
        *                                   in order to map request and its response
        *                                   together.
        * Error codes:
        * KErrSenNotInitialized             Connection has not been initialized.
        * KErrSenServiceConnectionBusy      Connection is already busy with another
        *                                   request.
        * KErrConnectionInitializing        Connection is still initializing and
        *                                   cannot yet process commands.
        * KErrConnectionExpired             Credential for the connection is 
        *                                   expired and needs to be renewed. 
        *                                   This can be done by instantiating a new
        *                                   ServiceConnection.
        * KErrSubmitting                    An error occurred
        * KErrNoMemory                      Not enough memory to process the message.
        * Other error codes are system-wide Symbian error codes.
        */
        virtual TInt SendL(const TDesC8& aRequest) = 0;


        /**
        * Submit a synchronous request to a service
        * (in ID-WSF, the SOAP message Body) and receive a response as XML.
        * There are two default frameworks available -
        * the Identity Based Web Service Framework (which ID is "ID-WSF") 
        * and the Basic Web Services Framework (which ID is "WS-I"). 
        * Please note, that Basic Web Services framework does NOT support this method.
        * Instead, one must send complete SOAP envelopes using SubmitL(CSenSoapEnvelope&).
        * So, currently this method is supported only in ID-WSF.
        * @param aRequest outgoing request message.
        * @param aResponse the resolved response message.
        *        The ownership of the aResponse is transfered to the caller.
        *        The response is service specific part of the response. 
        *        For ID-WSF services response contents is the SOAP Body, or complete SOAP 
        *        envelope as XML, depending on the complete server messages on/off setting 
        *       (default is off).
        * @return status/error code.
        * Status codes:
        * KErrNone                          ok
        * Error codes:
        * KErrSenNotInitialized             Connection has not been initialized.
        * KErrSenServiceConnectionBusy      Connection is already busy with another request.
        * KErrConnectionInitializing        Connection is still initializing and
        *                                   cannot yet process commands.
        * KErrConnectionExpired             Credential for the connection is 
        *                                   expired and needs to be renewed. 
        *                                   This can be done by instantiating a new
        *                                   ServiceConnection.
        * KErrSubmitting                    An internal error occurred.
        * KErrSenInternal                   Internal state is invalid.
        * Other error codes are system-wide Symbian error codes.
        */
        virtual TInt SubmitL(const TDesC8& aRequest, HBufC8*& aResponse) = 0;

        
        /**
        * Consumer application can use this method to check that 
        * service connection is in ready state.
        * In ID-WSF, this means that WSF interprets that credentials 
        * for the service connection are valid (not expired).
        * @param aReady indicates that the connection is ready to be used.
        * @return           status/error code.
        * Status codes:
        * KErrNone               ok
        * Error codes are system-wide Symbian error codes.
        */
        virtual TInt IsReady(TBool& aReady) = 0;


        /**
        * Check if the underlying service connection has a certain characteristic
        * called a facet.
        * Currently, only ID-WSF framework supports facets.
        * For example, if consumer application is interested to resolve if 
        * initialized service connection has a facet indicating that service
        * is free of charge (for e.g. "urn:framework.com.free:cost"), the 
        * method used to check this would be:
        * _LIT8(KFacetOfFreeService, "urn:some.service.free:cost");
        * int err = HasFacetL(KFacetOfFreeService, hasFacet);
        *
        * In the service session of initialed connection, this would be the form 
        * of the facet element:
        * <Facet name="urn:framework.com.free:cost"/>
        *
        * If there is no facet in the service connection then the element is not
        * present.
        * @param aURI           the name of the facet
        * @param aHasFacet      will indicate if underlying service has a certain
        *                       characteristic.
        * @return status/error code.
        * Status codes:
        * KErrNone                          ok
        * Error codes:
        * KErrSenNotInitialized             Connection has not been initialized.
        * KErrConnectionInitializing        Connection is still initializing and
        *                                   cannot yet process commands.
        * KErrConnectionExpired             Connection is expired and needs to be
        *                                   renewed.
        * KErrBadDescriptor                 The aUri parameter was an invalid
        *                                   descriptor.
        * Other error codes are system-wide Symbian error codes.
        */
        virtual TInt HasFacetL(const TDesC8& aURI, TBool& aHasFacet) = 0;


        /**
        * Consumer application can use this method to set flag which defines
        * whether or not the consumer wishes to receive complete SOAP envelope 
        * from the service.
        * If complete server messages mode is off, then only the <Body> element
        * is received from the SOAP envelope, otherwise full SOAP envelope.
        * Note: Calling this function must not be done before connection is 
        * initialized (the observer's SetStatus() has been called with value 
        * KSenConnectionStatusReady).
        * Calling this function should be done before sending or submitting
        * anything.
        * @param aCompleteOnOff defines the content of HandleMessageL() callback.   
        *              If set to ETrue (ON), then complete SOAP envelopes are
        *              received, including <Header> element.
        *              If set to EFalse (OFF), only the service specific
        *              content - SOAP envelope <Body> element - is received.
        *              In WSF frameworks the default settings are:
        *              1. In ID-WSF, the complete server messages is OFF.
        *              2. In Basic Web Services, the default is ON.
        * @return status/error code.
        * Status codes:
        * KErrNone                          ok
        * Error codes:
        * KErrSenNotInitialized             Connection has not been initialized.
        * KErrConnectionInitializing        Connection is still initializing and
        *                                   cannot yet process commands.
        * KErrConnectionExpired             Connection is expired and needs to be
        *                                   renewed.
        * Other error codes are system-wide Symbian error codes.
        */
        virtual TInt CompleteServerMessagesOnOff(const TBool& aCompleteOnOff) = 0;


        /*
        * Sends a SOAP message to the service. The SOAP envelope may contain
        * proprietary headers. The system will augment the message with the
        * appropriate headers specified in the service invocation framework,
        * so a client application should add only non-standard headers; and
        * if it doesn't need to set such headers it is strongly recommended
        * to use SendL(TDesC8&), which is meant for that.
        * This is an asynchronous function, that returns immediately.
        * When the service responds, the SOAP envelope content will
        * be received via HandleMessageL() callback. In case of an
        * error - like a SOAP fault - HandleErrorL() will be called
        * with appropriate error code.
        * There are two default frameworks available -
        * the Identity Based Web Service Framework (which ID is "ID-WSF") 
        * and the Basic Web Services Framework (which ID is "WS-I"). 
        * Please note, that ID-WSF does NOT support this method. 
        * Instead, one should send SOAP envelope Bodies using 
        * SendL(const TDesC8&).
        * So, currently this method is supported only in Basic Web Services framework.
        * @param aMessage  The service specific message - a full SOAP envelope 
        * @return Transaction ID (positive integer) or error code, if method fails.
        * Transaction ids:
        * Positive integers                 SendL returns transaction ID of the request,
        *                                   which can be later on utilized inside
        *                                   HandleMessageL and HandleErrorL methods,
        *                                   in order to map request and its response
        *                                   together.
        * Error codes:
        * KErrSenNotInitialized             Connection has not been initialized.
        * KErrSenServiceConnectionBusy      Connection is already busy with another
        *                                   request.
        * KErrConnectionInitializing        Connection is still initializing and
        *                                   cannot yet process commands.
        * KErrConnectionExpired             Connection is expired and needs to be
        *                                   renewed.
        * KErrSubmitting                    An internal error has occurred.
        * KErrNoMemory                      Not enough memory to process the 
        *                                   message.
        * Other error codes are system-wide Symbian error codes.
        */
        virtual TInt SendL(CSenSoapEnvelope& aMessage) = 0;


        /*
        * Submits a SOAP message to the service. This is a synchronous call,
        * returning  a SOAP envelope that was received from the service.
        * There are two default frameworks available:
        * the Identity Based Web Service Framework (which ID is "ID-WSF") 
        * and the Basic Web Services Framework (which ID is "WS-I"). 
        * Please note, that ID-WSF does NOT support this method. 
        * Instead, one should send SOAP envelope Bodies using SendL(const TDesC8&).
        * So, currently this method is supported only in Basic Web Services framework.
        * @param    aMessage SOAPEnvelope with the service specific message
        *                    without any framework wrapping
        * @param    aResponseTo  This is a ref-to-pointer where response 
        *                        from the service will be allocated. If the
        *                        complete server messages mode is set to OFF,
        *                        then only <Body> element will be returned, 
        *                        otherwise a complete SOAP envelope.
        *                        The ownership of aResponse is transfered to 
        *                        the caller.
        * @return status/error code
        * Status codes:
        * KErrNone                          ok
        * Error codes:
        * KErrSenNotInitialized             Connection has not been initialized.
        * KErrSenServiceConnectionBusy      Connection is already busy with another
        *                                   request.
        * KErrConnectionInitializing        Connection is still initializing and
        *                                   cannot yet process commands.
        * KErrConnectionExpired             Connection is expired and needs to be
        *                                   renewed.
        * KErrSubmitting                    An internal error has occurred.
        * KErrNoMemory                      Not enough memory to process the 
        *                                   message.
        * KErrSenInternal                   Internal state is invalid.
        * Other error codes are system-wide Symbian error codes.
        */
        virtual TInt SubmitL(CSenSoapEnvelope& aMessage, HBufC8*& aResponseTo) = 0;


        /**
        * Gets service description of current connection.
        * @param aServiceDescription Contains the service description on return
        * @return status/error code.
        * Status codes:
        * KErrNone                          ok
        * Error codes:
        * KErrSenNotInitialized             Connection has not been initialized.
        * KErrSenServiceConnectionBusy      Connection is already busy with another
        *                                   request.
        * KErrConnectionInitializing        Connection is still initializing and
        *                                   cannot yet process commands.
        * KErrConnectionExpired             Connection is expired and needs to be
        *                                   renewed.
        * KErrUnderFlow                     Server side returned invalid service
        *                                   description.
        * KErrUnknown                       Client-Server request mismatch.
        * Other error codes are system-wide Symbian error codes.
        */
        virtual TInt ServiceDescriptionL(HBufC8*& aServiceDescription) = 0;


        /**
        * Starts an application level transaction. The consumer may now start 
        * to communicate with some service withing a chain of correlated messages.
        * When responding to a certain SOAP message inside a transaction, the last
        * received message ID is used as "refToMessageId". 
        * From default frameworks, only ID-WSF supports transactions.
        * @return   KErrNone if no errors occur.
        *           Other error codes are system-wide Symbian error codes.
        */
        virtual TInt StartTransaction() = 0;


        /**
        * Stops application level transaction by resetting the "refToMessageId".
        * After stopping a transaction the next message will have no 
        * "refToMessageId"
        * @return   KErrNone if no errors occur.
        *           Other error codes are system-wide Symbian error codes.
        */
        virtual TInt TransactionCompleted() = 0;


        /*
        * Returns the transasction ID of this message or error. Id is guaranteed
        * to return unique ID  when called from inside HandleMessageL() or 
        * HandleErrorL callback. This transasction ID may be used to map the 
        * response with the preceedeing SendL() call (a request).
        * @return TInt transaction ID, or KErrNotFound, if no transaction is
        * on-going.
        */
        virtual TInt TxnId() = 0;


        /**
        * Sets transport specific properties which apply as long as this connection
        * is alive (session). Furthermore, the properties are effective for this session
        * in cumulative manner: each property has unique key (name) which is associated
        * to the actual value of that property. When SetTransportPropertiesL method is 
        * called multiple times - in sequence - the last value for each key overrides any
        * previous definitions. If any latter call introduces new keys (property names),
        * they are appended to the list of currently effective properties. 
        * Also note, that it is also possible to set message specific properties when making
        * a SendL/SubmitL call. If such transport properties for message are provided, and
        * those include updates to some properties, the new ones are effective only for that
        * certain message, i.e. those are transaction specific. For any following message,
        * that is sent over a service connection, the session specific properties apply,
        * assuming that the new message does not (again) override some of the property values.
        * @param aProperties contains the transport properties in serialized (UTF-8) form.
        * With HTTP, this descriptor is typically created by utilizing CSenHttpProperties class.
        * @return KErrNone if successful or otherwise some system-wide error code.
        */
        virtual TInt SetTransportPropertiesL(const TDesC8& aProperties) = 0;


        /*
        * Method returns currently effective transport properties as a serialized
        * descriptor. With HTTP, one may utilize CSenHttpProperities class in
        * order to read this data into properties object. Note that returned 
        * list of properties also includes properties, which are defined as default
        * for certain transport in the webservice framework.
        */
        virtual TInt TransportPropertiesL(HBufC8*& aProperties) = 0;


        /**
        * Send an ASYNCHRONOUS request to a service.
        * In ID-WSF, the request data is a SOAP Body.
        * Response message is received either via 
        * HandleMessageL() or HandleErrorL() callback.
        * There are two default frameworks available - 
        * the Identity Based Web Service Framework (which ID is "ID-WSF") 
        * and the Basic Web Services Framework (which ID is "WS-I"). 
        * Please note, that Basic Web Services framework does NOT support this method.
        * Instead, one should send complete SOAP envelopes using SendL(CSenSoapEnvelope&).
        * So, currently this method is supported only in ID-WSF.
        * @param aRequest outgoing request message.
        * @param aProperties contains transport spesific properties, serialized
        * into descriptor. With HTTP, one can create this by utilizing specialized
        * CSenHttpProperties class.
        * @return Transaction ID (positive integer) or error code, if method fails.
        * Transaction ids:
        * Positive integers                 SendL returns transaction ID of the request,
        *                                   which can be later on utilized inside
        *                                   HandleMessageL and HandleErrorL methods,
        *                                   in order to map request and its response
        *                                   together.
        * Error codes
        * KErrSenNotInitialized             Connection has not been initialized.
        * KErrSenServiceConnectionBusy      Connection is already busy with another
        *                                   request.
        * KErrConnectionInitializing        Connection is still initializing and
        *                                   cannot yet process commands.
        * KErrConnectionExpired             Credential for the connection is 
        *                                   expired and needs to be renewed. 
        *                                   This can be done by instantiating a new
        *                                   ServiceConnection.
        * KErrSubmitting                    An error occurred
        * KErrNoMemory                      Not enough memory to process the message.
        * Other error codes are system-wide Symbian error codes.
        */
        virtual TInt SendL(const TDesC8& aRequest, const TDesC8& aProperties) = 0;

        
        /**
        * Submit a request via SYNCHRONOUS call to a service
        * (in ID-WSF, the SOAP message Body) and receive a response as XML.
        * There are two default frameworks available -
        * the Identity Based Web Service Framework (which ID is "ID-WSF") 
        * and the Basic Web Services Framework (which ID is "WS-I"). 
        * Please note, that Basic Web Services framework does NOT support this method.
        * Instead, one must send complete SOAP envelopes using SubmitL(CSenSoapEnvelope&).
        * So, currently this method is supported only in ID-WSF.
        * @param aRequest outgoing request message.
        * @param aResponse the resolved response message.
        *        The ownership of the aResponse is transfered to the caller.
        *        The response is service specific part of the response. 
        *        For ID-WSF services response contents is the SOAP Body, or complete SOAP 
        *        envelope as XML, depending on the complete server messages on/off setting 
        *       (default is off).
        * @param aProperties contains transport spesific properties, serialized
        * into descriptor. With HTTP, one can create this by utilizing specialized
        * CSenHttpProperties class.
        * @return status/error code.
        * Status codes:
        * KErrNone                          ok
        * Error codes:
        * KErrSenNotInitialized             Connection has not been initialized.
        * KErrSenServiceConnectionBusy      Connection is already busy with another request.
        * KErrConnectionInitializing        Connection is still initializing and
        *                                   cannot yet process commands.
        * KErrConnectionExpired             Credential for the connection is 
        *                                   expired and needs to be renewed. 
        *                                   This can be done by instantiating a new
        *                                   ServiceConnection.
        * KErrSubmitting                    An internal error occurred.
        * KErrSenInternal                   Internal state is invalid.
        * Other error codes are system-wide Symbian error codes.
        */
        virtual TInt SubmitL(const TDesC8& aRequest, const TDesC8& aProperties, HBufC8*& aResponse) = 0;


        /*
        * Sends a SOAP message to the service. The SOAP envelope may contain
        * proprietary headers. The system will augment the message with the
        * appropriate headers specified in the service invocation framework,
        * so a client application should add only non-standard headers; and
        * if it doesn't need to set such headers it is strongly recommended
        * to use SendL(TDesC8&), which is meant for this.
        * This is an asynchronous function, that returns immediately.
        * When the service responds, the SOAP envelope content will
        * be received via HandleMessageL() callback. In case of an
        * error - like a SOAP fault - HandleErrorL() will be called
        * with appropriate error code.
        * There are two default frameworks available -
        * the Identity Based Web Service Framework (which ID is "ID-WSF") 
        * and the Basic Web Services Framework (which ID is "WS-I"). 
        * Please note, that ID-WSF does NOT support this method. 
        * Instead, one should send SOAP envelope Bodies using 
        * SendL(const TDesC8&).
        * So, currently this method is supported only in Basic Web Services framework.
        *
        * NOTE:
        * Message is send as serialized XML or Soap message to SendL 
        * aProperties could be "HTTP GET" or "HTTP DELETE"  
        * HTTP GET or HTTP DELETE transport property has been enabled via CSenHttpTransportProperties. 
        * This scenario is not supported  
        *
        * @param aMessage  The service specific message - a full SOAP envelope 
        * @param aProperties contains transport spesific properties, serialized
        * into descriptor. With HTTP, one can create this by utilizing specialized
        * CSenHttpProperties class.
        * @return Transaction ID (positive integer) or error code, if method fails.
        * Transaction ids:
        * Positive integers                 SendL returns transaction ID of the request,
        *                                   which can be later on utilized inside
        *                                   HandleMessageL and HandleErrorL methods,
        *                                   in order to map request and its response
        *                                   together.
        * Error codes:
        * KErrSenNotInitialized             Connection has not been initialized.
        * KErrSenServiceConnectionBusy      Connection is already busy with another
        *                                   request.
        * KErrConnectionInitializing        Connection is still initializing and
        *                                   cannot yet process commands.
        * KErrConnectionExpired             Connection is expired and needs to be
        *                                   renewed.
        * KErrSubmitting                    An internal error has occurred.
        * KErrNoMemory                      Not enough memory to process the 
        *                                   message.
        * KErrNotSupported					HTTP GET or HTTP DELETE is enabled        
        * Other error codes are system-wide Symbian error codes.
        */
        virtual TInt SendL(CSenSoapEnvelope& aMessage, const TDesC8& aProperties) = 0;

        /*
        * Submits a SOAP message to the service. This is a synchronous call,
        * returning  a SOAP envelope that was received from the service.
        * There are two default frameworks available:
        * the Identity Based Web Service Framework (which ID is "ID-WSF") 
        * and the Basic Web Services Framework (which ID is "WS-I"). 
        * Please note, that ID-WSF does NOT support this method. 
        * Instead, one should send SOAP envelope Bodies using SendL(const TDesC8&).
        * So, currently this method is supported only in Basic Web Services framework.
        *
        * NOTE:
        * Message is send as serialized XML or Soap message to SubmitL 
        * aProperties could be "HTTP GET" or "HTTP DELETE"  
        * HTTP GET or HTTP DELETE transport property has been enabled via CSenHttpTransportProperties. 
        * This scenario is not supported
        *
        * @param aMessage SOAPEnvelope with the service specific message
        * without any framework wrapping
        * @param aProperties contains transport spesific properties, serialized
        * into descriptor. With HTTP, one can create this by utilizing specialized
        * CSenHttpProperties class.
        * @param    aResponseTo  This is a ref-to-pointer where response 
        *                        from the service will be allocated. If the
        *                        complete server messages mode is set to OFF,
        *                        then only <Body> element will be returned, 
        *                        otherwise a complete SOAP envelope.
        *                        The ownership of aResponse is transfered to 
        *                        the caller.
        * @return status/error code
        * Status codes:
        * KErrNone                          ok
        * Error codes:
        * KErrSenNotInitialized             Connection has not been initialized.
        * KErrSenServiceConnectionBusy      Connection is already busy with another
        *                                   request.
        * KErrConnectionInitializing        Connection is still initializing and
        *                                   cannot yet process commands.
        * KErrConnectionExpired             Connection is expired and needs to be
        *                                   renewed.
        * KErrSubmitting                    An internal error has occurred.
        * KErrNoMemory                      Not enough memory to process the 
        *                                   message.
        * KErrSenInternal                   Internal state is invalid.
        * KErrNotSupported					HTTP GET or HTTP DELETE is enabled        
        * Other error codes are system-wide Symbian error codes.
        */
        virtual TInt SubmitL(CSenSoapEnvelope& aMessage, const TDesC8& aProperties, HBufC8*& aResponseTo) = 0;

        /*
        * Sends a SOAP message to the service. The SOAP envelope may contain
        * proprietary headers. The system will augment the message with the
        * appropriate headers specified in the service invocation framework,
        * so a client application should add only non-standard headers.
        * This is an asynchronous function, that returns immediately.
        * When the service responds, the SOAP envelope content will
        * be received via HandleMessageL() callback. In case of an
        * error - like a SOAP fault - HandleErrorL() will be called
        * with appropriate error code.
        * There are two default frameworks available -
        * the Identity Based Web Service Framework (which ID is "ID-WSF") 
        * and the Basic Web Services Framework (which ID is "WS-I"). 
        * Please note, that ID-WSF does NOT support this method. 
        * Instead, one should send SOAP envelope Bodies using 
        * SendL(const TDesC8&).
        * So, currently this method is supported only in Basic Web Services framework.
        *
        * @param aMessage  The service specific message - a full SOAP envelope 
        * @return Transaction ID (positive integer) or error code, if method fails.
        * Transaction ids:
        * Positive integers                 SendL returns transaction ID of the request,
        *                                   which can be later on utilized inside
        *                                   HandleMessageL and HandleErrorL methods,
        *                                   in order to map request and its response
        *                                   together.
        * Error codes:
        * KErrSenNotInitialized             Connection has not been initialized.
        * KErrSenServiceConnectionBusy      Connection is already busy with another
        *                                   request.
        * KErrConnectionInitializing        Connection is still initializing and
        *                                   cannot yet process commands.
        * KErrConnectionExpired             Connection is expired and needs to be
        *                                   renewed.
        * KErrSubmitting                    An internal error has occurred.
        * KErrNoMemory                      Not enough memory to process the 
        *                                   message.
        * KErrNotSupported					HTTP GET or HTTP DELETE is enabled
        * Other error codes are system-wide Symbian error codes.
        */
        virtual TInt SendL(MSenMessage& aMessage) = 0;

        /*
        * Submits a SOAP message to the service. This is a synchronous call,
        * returning  a SOAP envelope that was received from the service.
        * There are two default frameworks available:
        * the Identity Based Web Service Framework (which ID is "ID-WSF") 
        * and the Basic Web Services Framework (which ID is "WS-I"). 
        * Please note, that ID-WSF does NOT support this method. 
        * Instead, one should send SOAP envelope Bodies using SendL(const TDesC8&).
        * So, currently this method is supported only in Basic Web Services framework.
        *
        * @param aMessage SOAPEnvelope with the service specific message
        * without any framework wrapping
        * @param    aResponseTo  This is a ref-to-pointer where response 
        *                        from the service will be allocated. If the
        *                        complete server messages mode is set to OFF,
        *                        then only <Body> element will be returned, 
        *                        otherwise a complete SOAP envelope.
        *                        The ownership of aResponse is transfered to 
        *                        the caller.
        * @return status/error code
        * Status codes:
        * KErrNone                          ok
        * Error codes:
        * KErrSenNotInitialized             Connection has not been initialized.
        * KErrSenServiceConnectionBusy      Connection is already busy with another
        *                                   request.
        * KErrConnectionInitializing        Connection is still initializing and
        *                                   cannot yet process commands.
        * KErrConnectionExpired             Connection is expired and needs to be
        *                                   renewed.
        * KErrSubmitting                    An internal error has occurred.
        * KErrNoMemory                      Not enough memory to process the 
        *                                   message.
        * KErrSenInternal                   Internal state is invalid.
        * KErrNotSupported					HTTP GET or HTTP DELETE is enabled
        * Other error codes are system-wide Symbian error codes.
        */
        virtual TInt SubmitL(MSenMessage& aMessage, CSenSoapEnvelope2*& aResponseTo) = 0;
        
        /**
        * Getter for currently active transaction (service response) that is
        * being handled by the service consumer.
        * @return a pointer to currently active transaction (service response).
        *         It is guarenteed, that the method returns a pointer to
        *         transaction only when called inside HandleMessageL or
        *         HandleErrorL callback methods of MSenServiceConsumer,
        *         otherwise it will return NULL.
        */
        virtual MSenMessage* Response() = 0;
        
        /**
        * Cancels any active request, if pending transaction 
        * (txn) can be found with given txn ID.
        * @param aTransactionID is the transaction ID to be cancelled. This id has earlier been
        * acquired from a call to some of the asynchronous SendL variants.

        * @return KErrNone on success
        *         KErrNotFound, if there is no pending transaction (active request),
        *         or some of the system-wide error codes otheriwise.
        */
        virtual TInt CancelTransaction(TInt aTransactionID) = 0;
        
        /**
        * Getter for the identity provider (XML) service description. 
        * @param apIdentityProvider will point to a new IDP instance,
        * if such is associated with this connection (and this connection
        * was ready before calling this method), or NULL otherwise.
        * @return KErrNone if IDP description can be found, or some
        * of the system wide error code otherwise.
        */
        virtual TInt IdentityProviderL(CSenIdentityProvider*& apIdentityProvider) = 0;

        /**
        * Getter for the identifier  of this connection.
        * @return the identifier as integer.
        */
        virtual TInt Identifier() = 0;
        
        /**
        * Registers observer of BLOBs transfer progress.
        *
        * @param aFilesObserver Implementation of transfer progress observer.
        */
    
    protected:
        
        /**
        * C++ default constructor.
        */
        CSenServiceConnection();
    
    };

#endif //SEN_SERVICE_CONNECTION_H

// End of File

