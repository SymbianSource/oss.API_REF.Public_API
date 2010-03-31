/*
* Copyright (c) 2002-2005 Nokia Corporation and/or its subsidiary(-ies). 
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
* Description: Hostlet call back interface
*
*/


#ifndef M_SEN_HOSTLET_H
#define M_SEN_HOSTLET_H

//  INCLUDES
#include <e32base.h> // for CBase
#include <badesca.h>

#include <MSenHostletRequest.h>
#include <MSenHostletResponse.h>
#include <SenXmlServiceDescription.h>
#include <SenServiceConnection.h> 

// FORWARD DECLARE

// CLASS DECLARATION
class MSenHostlet
    {
    public:
        /**
         * Main method for receiving incoming messages, which are typically SOAP / XML,
         * and for providing service for these requests.
         *  @param aRequestUtf8 the request that needs to be be processed by the
         *   hostlet application (local service provider).
         *  @param aResponse is where response data is to be set. 
         *   CSenHostletConnection::ResponsdL should be called 
         *   in order to send the response back to the requester
         *   (service consumer).
         */
        virtual TInt ServiceL(MSenHostletRequest& aRequest, MSenHostletResponse& aResponse) = 0;

        /**
        * Defines the service endpoint for this hostlet
        * @return endpoint that this hostlet has specified. If hostlet
        * implementation does not wish to define any endpoint, but to
        * use contract only, it should return KNullDesC8 (zero-length descriptor).
        * In such case, CSenHostletConnection constructor will attempt to resolve
        * secure identifier (UID3) of the application, and use that to generate
        * a locally unique endpoint. If the UID3 is not available, then the
        * constructor of CSenHostletConnection will leave with the following
        * error code: KErrSenNoContractNoEndPoint     
        *
        * Note: Hostlets, which don't provide endpoint and don't have UID3, cannot 
        * create hostlet connection: instead, CSenHostletConnection constructor
        * will leave with the following code: KErrSenNoContractNoEndPoint
        *
        * If endpoint is not specified, hostlet connection itself
        * will generate an endpoint from applications secure ID (UID3) if such is available,
        * and consumers can invoke the service via the provided contract ("service type" 
        * identifier).
        *
        */
        virtual TPtrC8 Endpoint() const = 0;

        /**
        * Defines the service constract URI for this hostlet
        * @return the URI identifier for the provided service, for example
        * "urn:liberty:id-sis-pp:2003-08". Note that there might be multiple
        * hostlets (local service providers) which all share common service
        * type, that is, they all have same service contract URI.
        *
        * Note: Hostlets, which don't provide endpoint and don't have UID3, cannot 
        * create hostlet connection: instead, CSenHostletConnection constructor
        * will leave with the following error code: KErrSenNoContractNoEndPoint
        */
        virtual TPtrC8 Contract() const = 0;

        /**
        * Defines the framework for this hostlet.
        * @return the framework ID. Default inline implementation 
        * returns RESTful service invocation framework ID, 
        * KDefaultRestServicesFrameworkID, as defined in SenServiceConnection.h
        */
        inline virtual TPtrC8 FrameworkId() const { return KDefaultRestServicesFrameworkID(); }

        /**
        * Each Hostlet implementation may further describes its service via this callback.
        * @param aSD is the description, where service specific attributes can be defined.
        * Default, inline implementation sets the endpoint, contract and framework ID
        * by calling the other, more simple callbacks.
        *
        * It is mandatory for each hostlet to define either endpoint or contract.
        * Otherwise, the constuctor of CSenHostletConnection will leave with the
        * following error code:
        *     KErrSenNoContractNoEndPoint - neither endpoint or contract was 
        *     specified. This is illegal, since the service would lack an identifier. 
        * 
        * @param aSD is the service description into which this hostlet may further
        * define other service specific information, like facets. Note that this 
        * call back is "stronger" than Endpoint() and Contract(), and thus any
        * value specified in this method will be in effect for the hostlet connection.
        */
        inline virtual void DescribeServiceL(CSenXmlServiceDescription& aSD) 
            { 
            aSD.SetEndPointL(Endpoint());
            aSD.SetContractL(Contract()); 
            aSD.SetFrameworkIdL(FrameworkId());
            } 

        /**
        * This callback function is invoked each time when any hostlet connection's
        * asynchronous RespondL is completed. Method can be used to trigger the 
        * release of some response releated system resources, as it is invoked 
        * after the response has been delivered to the consumer (application
        * may wish to close handles to reserved file or memory).
        *
        * @param aTxnId identifies what transaction (service message) was completed
        * @param aCompletionCode indicates whether transaction completed ok (KErrNone)
        * or not (error code).
        * @param aDesc may provide additional information about completed transaction,
        * typically this description is provided, if an error has occured.
        * It is optional for hostlet implementation to implement this method. 
        */
        inline virtual void OnServiceCompleteL(TInt /* aTxnId */, 
                                               TInt /* aCompletionCode */, 
                                               const TDesC8& /* aDesc*/ ) { ; }
                                             
				/**
        * Hostlet connection calls this method several times, passing a different
        * UID per each call. If application wants to provide particular interface
        * to hostlet connection (web services stack), it needs to return a pointer
        * to such M-class as a return value of this method. For any interface, that
        * application has not implemented, it is supposed to return NULL.
        * @param aUID is the unique identifier of some interface
        * @return value should be a valid (void) pointer to any interface implemented
        * by the application. NULL signalizes that application does not provide interface
        * for give UID. 
        */    
	    inline virtual TAny* GetInterfaceByUid( TUid /* aUID */ ) { return NULL; };                                             
    };


#endif // M_SEN_HOSTLET_H

// End of File
