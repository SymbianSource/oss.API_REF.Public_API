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
* Description:           Class implements the most common value object used in WSF, 
*                which is used to  describe some invocable service. 
*
*/











#ifndef SEN_XML_SERVICE_DESCRIPTION_H
#define SEN_XML_SERVICE_DESCRIPTION_H

//  INCLUDES
#include <e32base.h>
#include <e32des8.h>
#include <e32std.h>
#include <MSenServiceDescription.h>
#include <MSenProviderPolicy.h>
#include <SenDomFragment.h>

// CONSTANTS
const TInt KStateParsingCredentials         = 12;
const TInt KStateParsingSingleCredential    = 122;
const TInt KStateParsingProviderPolicy      = 1222;
const TInt KStateParsingServicePolicy       = 12222;

_LIT8( KSenAttrSoap12,                  "SOAP12"               );
_LIT8( KSenAttrAddressing,              "Addressing"           );
_LIT8( KSenAttrClientEntropy,           "ClientEntropy"        );
_LIT8( KSenAttrTokenType,               "TokenType"            );
_LIT8( KSenAttrPassportExtensions,      "PassportExtensions"   );
_LIT8( KSenAttrMetadataEndpoint,        "MetadataEndpoint"     );
_LIT8( KSenAttrUsernameTokenOverTLS,    "UsernameTokenOverTLS" );
_LIT8( KSenAttrPromptUserInfo,          "promptUserInfo"       );

_LIT8( KSenLocalnameAppInfo,            "AppInfo"               );
_LIT8( KSenLocalnameWAPGW,              "WAPGW"                 );
_LIT8( KSenLocalnameMwsNamespace,       "MwsNamespace"          );
// FORWARD DECLARATIONS
class CSenCredential;
class CSenProviderPolicy;
class CSenServicePolicy;
class MSenServicePolicy;

// DATA TYPES
typedef RPointerArray<CSenCredential> RCredentialList;

// CLASS DECLARATION

/**
* CSenXmlServiceDescription class implements the most
* common value object used in WSF, which is used to 
* describe some invocable service. 
*
* Class offers basic properties which describe some
* service and methods to manipulate this info. These
* properties are stored in XML fragment format and 
* a class instance can be represented as one XML tree.
*
* The main properties for service description are:
*    - contract (typically some URI)
*    - endpoint (typically some URL)
*    - frameworkID
*
*  @lib SenServDesc.lib
*  @since Series60 3.0
*/
class CSenXmlServiceDescription : public CSenDomFragment,
                                  public MSenServiceDescription,
                                  public MSenProviderPolicy
    {
    public:  // Constructors and destructor
        
        /**
        * Standard 2 phase constructor
        * @return a pointer to a new CSenXmlServiceDescription instance.
        */
        IMPORT_C static CSenXmlServiceDescription* NewL();

        /**
        * Standard 2 phase constructor
        * @return a pointer to a new CSenXmlServiceDescription instance,
        *        which is left on cleanup stack.
        */
        IMPORT_C static CSenXmlServiceDescription* NewLC();

        /**
        * Standard 2 phase constructor
        * @param aNamespaceURI namespace URI for the service description.
        * @return a pointer to a new CSenXmlServiceDescription instance
        */
        IMPORT_C static CSenXmlServiceDescription* NewL(const TDesC8& aNamespaceURI);

        /**
        * Standard 2 phase constructor
        * @param aNamespaceURI namespace URI for the service description.
        * @return a pointer to a new CSenXmlServiceDescription instance,
        *        which is left on cleanup stack.
        */
        IMPORT_C static CSenXmlServiceDescription* NewLC(const TDesC8& aNamespaceURI);

        /**
        * Standard 2 phase constructors
        * @param aEndpoint the service endpoint. Note that endpoint cannot 
        *        include characters which are illegal in XML. If endpoint
        *        is an URL which contains illegal characters (like '&'-char),
        *        those need to be encoded into XML entity form (like &amp;).
        *        EncodeHttpCharactersLC() method from XmlUtils can be used
        *        for encoding of basic XML entities.
        * @param aContract identifies the service type. 
        * @return a pointer to a new CSenXmlServiceDescription instance
        */
        IMPORT_C static CSenXmlServiceDescription* NewL(const TDesC8& aEndPoint,
                                                        const TDesC8& aContract);

        /**
        * Standard 2 phase constructors
        * @param aEndpoint the service endpoint. Note that endpoint cannot 
        *        include characters which are illegal in XML. If endpoint
        *        is an URL which contains illegal characters (like '&'-char),
        *        those need to be encoded into XML entity form (like &amp;).
        *        EncodeHttpCharactersLC() method from XmlUtils can be used
        *        for encoding of basic XML entities.
        * @param aContract identifies the service type. 
        * @return a pointer to a new CSenXmlServiceDescription instance,
        *        which is left on cleanup stack.
        */
        IMPORT_C static CSenXmlServiceDescription* NewLC(const TDesC8& aEndPoint,
                                                         const TDesC8& aContract);
        
        /**
        * Destructor.
        */
        IMPORT_C virtual ~CSenXmlServiceDescription();

        // New functions

        /**
        * Setter for the framework ID.
        * The developer may use a FrameworkID to search for a session of    
        * (i.e. connection to) a certain service invocation framework.
        * @since Series60 3.0
        * @param aFrameworkId
        * If set to KNullDesC8, then any matching framework may be used.
        * The default frameworkID in WSF is "ID-WSF" 
        * (KDefaultIdWsfFrameworkID).
        * Note that Basic Web Services MUST use "WS-I" 
        * (KDefaultBasicWebServicesFrameworkID).
        */
        IMPORT_C void SetFrameworkIdL(const TDesC8& aFrameworkID);

        /**
        * Method returns the localname for this service description.
        * This is the localname of the element, when this class is
        * represented as an XML element.
        * @since Series60 3.0
        * @return descriptor to XML localname of this service description
        */
        IMPORT_C virtual const TDesC8& NewElementName();
        
        /**
        * Returns list of credentials. Ownership is not transferred, any
        * modifications to the contents of the list modify the real objects.
        * @since Series60 3.0
        * @return the list of credentials (CSenCredential objects).
        */
        IMPORT_C  RCredentialList& Credentials();        

        // Functions from base classes
    
        // From MSenProviderPolicy
        IMPORT_C virtual void SetIapIdL(TUint32 aIapId);
        IMPORT_C virtual TInt IapId(TUint32& aCurrentIapId);
        IMPORT_C virtual void SetIdentityProviderIdsL(
                                        CSenIdentityProviderIdArray8& aList);
		IMPORT_C TInt SetTransportPropertiesL(const TDesC8& aProperties);

        IMPORT_C virtual TInt AddIdentityProviderIdL(TDesC8& aProviderId);
        IMPORT_C virtual TInt RebuildFrom(MSenProviderPolicy& aTemplate);
        IMPORT_C virtual const CSenIdentityProviderIdArray8&
                                                    IdentityProviderIds8L();
	    IMPORT_C TInt TransportPropertiesL(HBufC8*& aProperties);
        
        IMPORT_C virtual TBool Accepts(MSenProviderPolicy& aPolicyPattern);
        
        // From MSenServiceDescription:
        IMPORT_C TDescriptionClassType DescriptionClassType();
        IMPORT_C TBool Matches(MSenServiceDescription& aPattern);
        IMPORT_C TPtrC8 Contract();

        // New method
         /**
        * Method for checking if service description has a certain facet.
        * @since Series60 3.0
        * @param aURI       the facet to check, typically some URI.
        * @param aHasFacet  is ETrue if facet is found and EFalse, if not.
        * @return       KErrNone or other system-wide Symbian error codes.
        */
        IMPORT_C virtual TInt HasFacetL(const TDesC8& aURI, TBool& aHasFacet);
        
        // From MSenServiceDescription
        IMPORT_C virtual TInt FacetValue(TDesC8& aURI, HBufC8*& aValueTo);
        IMPORT_C virtual TInt AddFacetL(const CSenFacet& aFacet);
        IMPORT_C virtual TInt SetFacetL(const CSenFacet& aFacet);
        IMPORT_C virtual TInt RemoveFacet(const TDesC8& aURI);
        IMPORT_C virtual TInt FacetsL(RFacetArray& aFacetArray);
        
        // New method
        /**
        * On success, this method returns a positive integer if this 
        * service description matches with the given pattern in at 
        * least one aspect. Higher numbers mean a closer match.
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
        * @return the score or error. If nothing matches, returns 0. In case of 
        *  any error, a negative value is returned. 
        */
        IMPORT_C virtual TInt ScoreMatchL(MSenServiceDescription& aPattern);

        // From MSenServiceDescription

        IMPORT_C TPtrC8 Endpoint();
        IMPORT_C TPtrC8 FrameworkId();
        IMPORT_C TPtrC8 FrameworkVersion();
        IMPORT_C void SetContractL(const TDesC8& aContract);
        IMPORT_C void SetEndPointL(const TDesC8& aEndPoint);
        
        // From CSenBaseFragment 
        
        /** 
        * Gets the service description as XML fragment in UTF-8 format.
        * @since Series60 3.0
        * @return the service description as XML, which ownership is
        *         transferred to the caller.
        */
        IMPORT_C virtual HBufC8* AsXmlL();

        /**
        * Gets the service description as XML, in Unicode (UCS-2)
        * @since Series60 3.0
        * @return the service description as XML, in Unicode (UCS-2)
        *         encoding form.
        */
        IMPORT_C virtual HBufC* AsXmlUnicodeL();

        /**
        * Writes this service description as XML, in UTF-8 form to a stream
        * @since Series60 3.0
        * @param aWriteStream   to write into.
        */
        IMPORT_C virtual void WriteAsXMLToL(RWriteStream& aWriteStream);


        // From CSenDomFragment 
        
        /**
        * Method looks for FrameworkID attribute from the given XML attribute
        * array and if one is found, sets its value for this instance. In
        * addition, all the namespace attributes are copied. All other
        * attributes are discarded.
        * @since Series60 3.0
        * @param aAttributes    the attribute list.
        */
        IMPORT_C void SetAttributesL(const RAttributeArray& aAttributes);

        /**
        * Resumes the parsing. Called by the delegate fragment 
        * in order to notify owner, which needs to regain 
        * (take over) parsing. For example, when a policy fragment
        * is parsed, the service description fragment should
        * resume parsing the rest of its own XML document 
        * representation.
        * @since Series60 3.0
        * @param aNsUri     The namespace URI of the current element
        * @param aLocalName The local name of the current element
        * @param aQName     The qualified name of the current element
        */
        IMPORT_C void ResumeParsingFromL(const TDesC8& aNsUri,
                                         const TDesC8& aLocalName,
                                         const TDesC8& aQName);
                
    protected:  // New functions
        
        /**
        * C++ default constructor.
        * @param aType enumeration defining the type of this class.
        */
        IMPORT_C CSenXmlServiceDescription(TDescriptionClassType aType);
        
        /**
         * Basic ConstructL function.
         */
        IMPORT_C void ConstructL();

        /**
        * Basic ConstructL function.
        * @since Series60 3.0
        * @param aNamespaceURI for this service description, which is
        *        also an XML element.
        */
        IMPORT_C void ConstructL(const TDesC8& aNamespaceURI);

        /**
        * Basic ConstructL function.
        * @since Series60 3.0
        * @param aEndpoint the service endpoint. Note that endpoint cannot 
        *        include characters which are illegal in XML. If endpoint
        *        is an URL which contains illegal characters (like '&'-char),
        *        those need to be encoded into XML entity form (like &amp;).
        *        EncodeHttpCharactersLC() method from XmlUtils can be used
        *        for encoding of basic XML entities.
        * @param aContract identifies the service type, typically some URN.
        */
        IMPORT_C void ConstructL(const TDesC8& aEndPoint, const TDesC8& aContract);

        // Functions from base classes
        
        // From CSenDomFragment 
        
        /**
        * Callback function which implements the XML content handler interface.
        * @since Series60 3.0
        * @param aNsURI     The namespace URI of the new element
        * @param aLocalName The local name of the new element
        * @param aQName     The qualified name of the new element
        * @param aAttributes    The attributes of the new element
        */
        IMPORT_C virtual void StartElementL(const TDesC8& aNsUri,
                                            const TDesC8& aLocalName,
                                            const TDesC8& aQName,
                                            const RAttributeArray& aAttributes);

        // From CSenBaseFragment 
        /**
        * Callback function which implement the XML content handler interface.
        * @since Series60 3.0
        * @param aNsUri     The namespace URI of the new element
        * @param aLocalName The local name of the new element
        * @param aQName     The qualified name of the new element
        */
        IMPORT_C virtual void EndElementL(const TDesC8& aNsUri,
                                          const TDesC8& aLocalName,
                                      const TDesC8& aQName);
                                          
    public:
        /**
        * Method returns ETrue if the primary keys of this service description
        * are equal. Definition of primary keys varies on concrete implementations.
        *
        * In a typical XML sub class implementation the primary keys are Contract 
        * and Endpoint elements. 
        *
        * Difference to Match() method is that primary keys - often descriptors - 
        * MUST be equal both in this service description and in aCandidate, unlike
        * in Match(), where argument is more like wildcard pattern matching even
        * in cases where it includes fewer fields (less information).
        *
        * @since Series60
        * @param    aCandidate is a service description, which primary keys are
        *           checked in this comparison.
        *
        * @return TBool ETrue if primary keys are equal, EFalse otherwise. 
        */
        IMPORT_C TBool HasEqualPrimaryKeysL(MSenServiceDescription& aCandidate);

        /*
        * Method checks specific pieces of information to determine, whether this
        * service description is local or not. Typically this is defined by the
        * endpoint's scheme, which is KSenTransportSchemeLocal in most of the cases,
        * when this method returns true.
        * @return boolean indicating whether this endpoint is local or not.
        */
        IMPORT_C TBool IsLocalL(); 


        /*
        * Method for binding transport plug-in type with the endpoint in question.
        * Function adds/sets XML attribute called "cue" for <Endpoint> element:
        *  
        *  <ServiceDescription>
        *    <Endpoint cue="com.nokia.wsf.transport.plugin.hostlet">
        *        local://urn:nokia.com.test.hostlet
        *    </Endpoint>
        *  </ServiceDescription>
        *
        * In above example, eventhough endpoint scheme "local://" would normally
        * invoke different type of plug-in (ECOM hostlet), the "cue" attribute 
        * overrides this, and forces hostlet connection transport plug-in to be
        * loaded.
        *
        * Transport plug-in types (cues):
        *
        *    _LIT8(KSenTransportCueHTTP,              "com.nokia.wsf.transport.plugin.httpchannel");
        *    _LIT8(KSenTransportCueVirtualTCP,        "com.nokia.wsf.transport.plugin.virtualtcp");
        *    _LIT8(KSenTransportCueLocalEcom,         "com.nokia.wsf.transport.plugin.local");  
        *    _LIT8(KSenTransportCueHostletConnection, "com.nokia.wsf.transport.plugin.hostlet");
        *
        *
        * Note that this method does not attempt to load the plug-in - it might not
        * even exist in the system. Neither is this attribute checked when XML service
        * description is parsed. As a conclusion, if non-existant plug-ins are bind 
        * to endpoints, they will be ignored, and the transport is created in normal
        * way and plug-in is chosen based on endpoint scheme and/or defaults.
        * 
        * @param aTransportCue is the ECOM cue of CSenTransport implementation.
        * In ECOM resource files, cue is the value of "default_data" property.
        * @return KErrNone on success
        *         KErrSenNoEndpoint, if  endpoint element does not exist in this XML
        *         service description.
        */
        IMPORT_C TInt SetTransportCueL(const TDesC8& aTransportCue);


        /**
        * Getter for transport cue, assuming that attribute has been set,
        * and that has "cue" -attribute.
        * @return transport plug-in ECOM cue, or KNullDesC8, if it has
        * not been set in this service description. In each ECOM resource
        * file the cue is defined by "default_data" property.
        */
        IMPORT_C TPtrC8 TransportCue();

        /**
        * Getter for (web) service policy
        * @return pointer to service policy, or NULL, if it is not available
        */
        IMPORT_C MSenServicePolicy* ServicePolicy();

        /**
        * Method provides convenient way to add a new value in Client Policy
        * This method will add elements such as <SOAP12> or <UsernameTokenOverTLS>
        * in the Policy to be used by stack. Infact this method adds a new element 
        * in xml representation of ServicePolicy.
        * @param aName is the Name of the attribute.
        * @return KErrNone on success, KErrArgument if any of the arguments 
        * (descriptors) is of zero-length, or one of the system-wide 
        * error codes otherwise.
        */
        IMPORT_C TInt SetPolicyL(const TDesC8& aName);

        /**
        * Method provides convenient way to add a new value in Client Policy
        * This method will add elements such as <Addressing>
        * in the Policy to be used by stack. Infact this method adds a new element 
        * in xml representation of ServicePolicy and adds its value as contents of the element.
        * <Addressing>http://schemas.xmlsoap.org/ws/2004/03/addressing</Addressing>
        * @param aName is the Name of the Policy attribute.
        * @param aValue is the Contents of the Policy attribute.
        * @return KErrNone on success, KErrArgument if any of the arguments 
        * (descriptors) is of zero-length, or one of the system-wide 
        * error codes otherwise.
        */
        IMPORT_C TInt SetPolicyL(const TDesC8& aName, const TDesC8& aValue);

        /**
        * Method provides convenient way to add a new value in Client Policy
        * This method will add elements such as <Addressing>
        * in the Policy to be used by stack, plus it will add one specified
        * attribute (name and value) for that element. Infact this method adds
        * a new element - and it's attribute - in the xml representation of 
        * ServicePolicy element, which is direct child to ServiceDescription
        * (root element) document.
        * <MetadataEndpoint method = "GET">http://www.mypolicyendpoint.com/policy2/</MetadataEndpoint>
        * @param aName is the Name of the Policy attribute.
        * @param aValue is the Contents of the Policy attribute.
        * @param aAttribName is the Name of the attribute in element aName
        * @param aAttribValue is the Contents of the aAttribName attribute.
        * @return KErrNone on success, KErrArgument if any of the arguments 
        * (descriptors) is of zero-length, or one of the system-wide 
        * error codes otherwise.
        */
        IMPORT_C TInt SetPolicyL(const TDesC8& aName, const TDesC8& aValue, const TDesC8& aAttribName, const TDesC8& aAttribValue);

        /**
        * Setter for (identity) provider ID
        * @since Series60 5.0
        * @param aProviderID the unique identifier of the (identity) provider
        * @return KErrNone on success, KErrArgument if aProviderID is of zero-length,
        * or one of the system-wide Symbian error codes otherwise.
        */
        IMPORT_C TInt SetProviderIdL( const TDesC8& aProviderID );
        
        /**
        * Getter for (identity) provider ID
        * @since Series60 5.0
        * @return the (locally) unique identifier of the (identity) provider
        * @return KErrNone on success, KErrArgument if aProviderID is of zero-length,
        * or one of the system-wide Symbian error codes otherwise.
        */
        IMPORT_C TPtrC8 ProviderId();

        /**
        * Setter for userinfo (KSenAttrPromptUserInfo) attribute, which 
        * - password notifier dialog is shown to end-user or not, when 
        * authentication fails (due wrong, or incomplete userinfo).
        * @param aPromptUserInfoMode 
        *  EFalse dictates that an error must be returned when creating
        *         a service connection and userinfo is not accepted by 
        *         (remote) authentication, instead of showing the dialog.
        *  ETrue (or if attribute does not exist in this XML SD) means that
        *         end-user should be prompted (default behaviour). The number
        *         of retry attempts (each showing a dialog) is service invocation
        *         framework spesific; typically 3 retries are permitted.     
        */
        IMPORT_C void CSenXmlServiceDescription::SetPromptUserInfoL( TBool aPromptUserInfoMode );

        /**
        * Getter for current userinfo mode (KSenAttrPromptUserInfo attribute).
        * @return Boolean that indicates the mode:
        *  EFalse means that end-user prompts (notifier dialogs) have been 
        *  explicitely surpressed, and thus will not be shown to end-user:
        *  attribute value is exactly as follows: "false"
        *  ETrue means that attribute named as KSenAttrPromptUserInfo 
        *  does not exist (default), or it has ANY value OTHER than "false"
        */
        IMPORT_C TBool PromptUserInfo();

	public:
		/**
        * Sets the SNAP ID.
        * @param aIapId  A TUint32 Snap ID
        */
        IMPORT_C void SetSnapIdL(TUint32 aIapId); 
		/**
        * Gets the SNAP ID.
        * @param aCurrentSnapId  A TUint32 reference to be filled in with the
        *                       value of the SNAP ID.
        * @return               KErrNone if no error, or some of the system
        *                       wide error codes.
        */
        IMPORT_C TInt SnapId(TUint32& aCurrentIapId); 
		
    private:
        TInt FacetValueL(TDesC8& aURI, HBufC8*& aValueTo);
        TInt RemoveFacetL(const TDesC8& aURI);

    protected: // Data
        // the type of this class instance
        const TDescriptionClassType iType;

    private: // Data
        CSenServicePolicy* iServicePolicy;
        CSenCredential* iCredential;
        RCredentialList iCredentialList;

        // Timestamp indicating validity of credentials. Using SenDateUtils 
        // FromXmlDateTimeL and ToXmlDateTimeUtf8L is recommended for conversions.
        TTime iNotOnOrAfter;
        CSenProviderPolicy* iProviderPolicy;
    };

#endif // SEN_XML_SERVICE_DESCRIPTION_H

// End of File


