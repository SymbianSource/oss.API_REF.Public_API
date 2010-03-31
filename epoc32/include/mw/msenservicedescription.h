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
* Description:        Interface (abstract) class for subclasses implementing the 
*                most common value objects used in WSF, which are used to
*                describe some invocable service. 
*
*/








#ifndef M_SEN_SERVICE_DESCRIPTION_H
#define M_SEN_SERVICE_DESCRIPTION_H

//  INCLUDES
#include <e32base.h>
#include <e32des8.h>    
#include <s32strm.h>

// CONSTANTS
_LIT8(KSenFacetValFalse,                "false");
_LIT8(KSenFacetValTrue,                 "true");

// Facet identifier (URN) constants:
_LIT8(KCompleteMessagesFacet,           "urn:nokia.com.serene:complete-messages");
_LIT8(KExposeLocalServiceFacet,         "urn:nokia.com.serene:expose");
_LIT8(KProviderSharableFacet,           "urn:nokia.com.serene.provider:sharable");
_LIT8(KProviderCompleteClientMsgsFacet, "urn:nokia.com.serene.provider:complete-client-messages") ;
_LIT8(KProviderLoadOnStartupFacet,      "urn:nokia.com.serene.provider:load-on-startup") ;
_LIT8(KProviderThreadsafeFacet,         "urn:nokia.com.serene.provider:threadsafe") ;
_LIT8(KProviderReinitializableFacet,    "urn:nokia.com.serene.provider:re-initializable") ;
_LIT8(KProviderStayOnBackgroundFacet,   "urn:nokia.com.serene.provider:stay-on-background") ;
_LIT8(KTransportClassFacet,             "urn:nokia.com:serene:transport:class");

// Transport plug-in types (ECOM cues / class types):
_LIT8(KSenTransportCueHTTP,              "com.nokia.wsf.transport.plugin.httpchannel");
_LIT8(KSenTransportCueVirtualTCP,        "com.nokia.wsf.transport.plugin.virtualtcp"); 
_LIT8(KSenTransportCueLocalEcom,         "com.nokia.wsf.transport.plugin.local");  
_LIT8(KSenTransportCueHostletConnection, "com.nokia.wsf.transport.plugin.hostlet");

// Transport schemes
_LIT8(KSenTransportSchemeHTTP,              "http");
_LIT8(KSenTransportSchemeTCP,               "tcp");
_LIT8(KSenTransportSchemeLocal,             "local");
_LIT8(KSenTransportSchemeHostlet,           "hostlet");
//_LIT8(KSenTransportSchemeVirtualTCP,        "vtcp"); 

const TInt KSenServiceDescriptionBaseScore = 100;

// FORWARD DECLARATIONS
class CSenFacet;

// DATA TYPES
typedef RPointerArray<CSenFacet> RFacetArray;

// CLASS DECLARATION

/**
* Interface (abstract) class for subclasses implementing the  most common value
* objects used in WSF, which are used to describe some invocable service. 
* All of the subclasses are capable of representing themselves in XML.
* @lib SenServDesc.lib
* @since Series60 3.0
*/
class MSenServiceDescription
    {
    public: 
        
        /**
        * DescriptionClassType enumeration.
        */
        IMPORT_C enum TDescriptionClassType
            {
            ERoot                               = 0, // not in use
            EBaseServiceDescription             = 1, // not in use
            EXmlServiceDescription              = 2,
            EIdentityProvider                   = 3, 
            EServicePattern                     = 4, 
            EServiceSession                     = 5,
            EWebServiceSession                  = 6,
            EBasicWebServiceSession             = 7,
            EIdWSFServiceSession                = 8,
            EIdWsfServiceInstance               = 9, 
            ECoreServiceConsumer                = 10,
            ESenInternalServiceConsumer         = 11,
            EIdWsfAuthenticationServiceClient   = 12,
            EIdWsfDiscoveryServiceClient        = 13,
            ERestServiceSession                 = 14,
            EWSStarServiceSession               = 15,
            EWSStarSTSClient                    = 16,
            EWSStarPolicyClient                 = 17,
            EWSDescription                      = 18,
            EWSPattern                          = 19,
            EAtomPubServiceSession              = 20,
            EAtomPubAuthClient                  = 21,
            EAccount                            = 22,
            EOviServiceSession                  = 23,
            EOviOAuthClient                     = 24
            };

        // New functions
    
        /**
        * The DescriptionClassType() method is used to resolve the real
        * subclass type in cases where instance of that class is seen
        * through one of its superclass interfaces. 
        * @since Series60 3.0
        * @return TDescriptionClassType enumeration identifying the class.
        */
        virtual TDescriptionClassType DescriptionClassType() = 0;

        /**
        * Method returns ETrue if this service description matches the given 
        * pattern.
        * The bits of information that are in the pattern are read and compared
        * to corresponding fields in this service description. Note that a pattern
        * may have far fewer fields and that only the non-null and non-zero-length
        * fields are compared.
        * For example, assume that a pattern with only a contract was defined;
        * with  the contract set to "urn:example.com:service". Each
        * service description with the same contract will match the pattern,
        * even if such a service description has non-null/non-zero-length fields
        * for other aspects.
        * @since Series60 3.0
        * @param    aPattern is a Service Description, typically with partial
        *           information.
        * @return TBool ETrue if match, EFalse otherwise. If the value is
        * not found from current instance, it is not used in comparison
        * (even if offered in the given pattern).
        */
        virtual TBool Matches(MSenServiceDescription& aPattern) = 0;

        /**
        * Getter for contract, which is typically some URI.
        * @since Series60 3.0
        * @return the Contract
        */
        virtual TPtrC8 Contract() = 0;

        /**
        * Method for checking if service description has a certain facet.
        * @since Series60 3.0
        * @param aURI       the facet to check, typically some URI.
        * @param aHasFacet  is ETrue if facet is found and EFalse, if not.
        * @return       KErrNone or other system-wide Symbian error codes.
        */
        virtual TInt HasFacetL(const TDesC8& aURI, TBool& aHasFacet) = 0;

        /*
        * Method for getting a facet value  from the service description 
        * @since Series60 3.0
        * @param aURI           the facet to get
        * @param aValueTo       a ref-to-pointer into which the value will
        *                       be allocated, which ownership is transferred
        *                       to the caller.
        * @return       KErrNone 
        *               KErrNoMemory value couldn't be allocated due to lack 
        *               of memory
        *               KErrNotFound if the wanted facet was not found.
        *               Other system-wide Symbian error codes.
        */
        virtual TInt FacetValue(TDesC8& aURI, HBufC8*& aValueTo) = 0;

        /**
        * Method for adding a facet. Will NOT override an already
        * existing facet with a same name.
        * @since Series60 3.0
        * @param        aFacet is the one to be added. A copy of the 
        *               the original facet instance will be added.
        * @return       KErrNone or other system-wide Symbian error codes.
        *               KErrAlreadyExists if a facet with same name exists
        */
        virtual TInt AddFacetL(const CSenFacet& aFacet) = 0;

        /**
        * Method for setting a facet.Adds a new facet, if non-existent.
        * But, if a facet with same name exists, it will be overridden.
        * @since Series60 3.0
        * @param        aFacet to be set. A copy of the original will be
        *               created.
        * @return       KErrNotFound if facet can not be found
        *               KErrNone     if facet was found
        *               KErrNoMemory if no memory could be allocated for the value
        *               Other system-wide Symbian error codes.
        */
        virtual TInt SetFacetL(const CSenFacet& aFacet) = 0;

        /**
        * Removes a characteristic (Facet) from the description
        * @since Series60 3.0
        * @param        aURI of the facet to be removed. 
        * @return       KErrNone     if a Facet was successfully removed
        *               KErrNotFound if a Facet could not be found
        *               Other system-wide Symbian error codes.
        */
        virtual TInt RemoveFacet(const TDesC8& aURI) = 0;

        /**
        * Method for getting all facets. Copies characteristics (Facets)
        * from the description into array. For each characteristic (Facet)
        * found in array the HasFacetL() method should return "ETrue".
        * @since Series60 3.0
        * @param        aFacetArray is typically an empty array, into where 
        *               copies of facets will be added. Ownership of the 
        *               items in this array is transferred to the caller.
        * @return       KErrNone or other system-wide Symbian error codes.
        */
        virtual TInt FacetsL(RFacetArray& aFacetArray) = 0;

        /**
        * This leaving variant of ScoreMatch() always returns a positive integer 
        * if this service description matches with the given pattern in at
        * least one aspect. Higher numbers mean closer match.
        *
        * In case of system error, method leaves.
        *
        * The bits of information that are in the pattern are read and compared
        * to corresponding fields in this ServiceDescription. Note that a pattern
        * may have far fewer fields and that only the non-null fields are compared.
        * For example, assume that a pattern with only a contract was defined;
        * with the contract set to "urn:example.com:service". 
        * Each ServiceDescription with the same contract will match the pattern,
        * even if such a ServiceDescription has non-null fields for other aspects.
        * @since Series60 3.0
        * @param    aPattern a ServiceDescription, typically with partial
        *           information.
        * @return the score. If nothing matches, returns 0
        */
        virtual TInt ScoreMatchL(MSenServiceDescription& aPattern) = 0;

        /**
        * Getter for endpoint.
        * @since Series60 3.0
        * @return The endpoint.
        */
        virtual TPtrC8 Endpoint() = 0;

        /**
        * Getter for the framework ID.
        * @since Series60 3.0
        * @return The framework ID or KNullDesC8 if no framework is set
        */
        virtual TPtrC8 FrameworkId() = 0;

        /**
        * Getter for the framework version.
        * @since Series60 3.0
        * @return The framework version or KNullDesC8 if not set.
        */
        virtual TPtrC8 FrameworkVersion() = 0;

        /**
        * Setter for contract.
        * @since Series60 3.0
        * @param aContract  the contract to be set.
        */
        virtual void SetContractL(const TDesC8& aContract) = 0;

        /**
        * Setter for endpoint.
        * @since Series60 3.0
        * @param aEndpoint to the service. Note that endpoint cannot 
        *        include characters which are illegal in XML. If endpoint
        *        is an URL which contains illegal characters (like '&'-char),
        *        those need to be encoded into XML entity form (like &amp;).
        *        EncodeHttpCharactersLC() method from XmlUtils can be used
        *        for encoding of basic XML entities.
        */
        virtual void SetEndPointL(const TDesC8& aEndPoint) = 0;

        /**
        * Gets the service description as XML fragment in UTF-8 format.
        * @since Series60 3.0
        * @return the service description as XML, which ownership is
        *         transferred to the caller.
        */
        virtual HBufC8* AsXmlL() = 0;

        /**
        * Gets the service description as XML, in Unicode (UCS-2)
        * @since Series60 3.0
        * @return the service description as XML, in Unicode (UCS-2)
        *         encoding form.
        */
        virtual HBufC* AsXmlUnicodeL() = 0;

        /**
        * Writes this service description as XML, in UTF-8 form to a stream
        * @since Series60 3.0
        * @param aWriteStream   to write into.
        */
        virtual void WriteAsXMLToL(RWriteStream& aWriteStream) = 0;
    };

#endif // M_SEN_SERVICE_DESCRIPTION_H

// End of File
