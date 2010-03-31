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
* Description:        Class describes some IdentityProvider service
*
*/








#ifndef SEN_IDENTITY_PROVIDER_H
#define SEN_IDENTITY_PROVIDER_H

//  INCLUDES
#include <SenXmlServiceDescription.h>

// CONSTANTS
const TInt KSenAuthMaxUsernameLength = 32;
const TInt KSenAuthMaxPasswordLength = 16;

_LIT8(KIdentityProvider8, "IdentityProvider"); 	//@depricated
_LIT8(KFakeIMEI8, "012345678901234");		//@depricated
_LIT8(KContract8, "urn:liberty:as:2004-04");		//@depricated
_LIT8(KSenIdpLocalname,                 "IdentityProvider");
_LIT8(KSenIdpLibertyIdWsfAsContract,            "urn:liberty:as:2004-04");
_LIT8(KWSAtomPubAuthenticationServiceContract,  "urn:atompub:as");
_LIT8(KWSOviAuthenticationServiceContract,      "urn:ovi:as");
_LIT8(KWSStarSTSContract,                       "urn:wstar:sts");
_LIT8(KImei, "IMEI");		//@depricated
_LIT8(KType, "type");		//@depricated

_LIT8(KAuthzID8, "AuthzID");		//@depricated
_LIT8(KAdvisoryAuthnID8, "AdvisoryAuthnID");			//@depricated	
_LIT8(KPassword8, "Password");		//@depricated
_LIT8(KProviderID8, "ProviderID");		//@depricated
_LIT8(KSenIdpAuthzIDLocalname,          "AuthzID");
_LIT8(KSenIdpAdvisoryAuthnIdLocalname,  "AdvisoryAuthnID");
_LIT8(KSenIdpPasswordLocalname,         "Password");
_LIT8(KSenIdpProviderIdLocalname,       "ProviderID");
_LIT8(KSenAccountExtensions,            "AccountExtensions");
_LIT8(KSenAccAutoSignIn,                "AutoSignIn");
                
// DATA TYPES
class TSenAuthentication
    {
    public:
        TBuf8<KSenAuthMaxUsernameLength> iUsername;
        TBuf8<KSenAuthMaxPasswordLength> iPassword;
    };

// FORWARD DECLARATIONS
class MSenIdentityManager;

// CLASS DECLARATION

/**
*  Class describes some IdentityProvider service
*  Class is intented to be used when registrating
*  information about some identity providing service.
*  In case of ID-WSF framework, the IdentityProvider
*  and Authentication Service are behind same endpoint.
*  Typically, ID-WSF service consumers call both
*  RegisterIdentityProviderL() and 
*  RegisterServiceDescriptionL() methods as defined
*  in Service Management API (CSenServiceManager).
*  Basic Web Service consumers use this class to register
*  BASIC-AUTH credentials to certain pre-known service endpoint.
*  @lib SenServDesc.lib
*  @since Series60 3.0
*/
class CSenIdentityProvider : public CSenXmlServiceDescription
    {
    public:  // Constructors and destructor
        
        /**
        * Two-phased constructor.
        * Note: contract defaults here to "urn:liberty:as:2004-04"
        * @since Series60 3.0
        * @param aEndpoint the service endpoint. Note that endpoint cannot 
        *        include characters which are illegal in XML. If endpoint
        *        is an URL which contains illegal characters (like '&'-char),
        *        those need to be encoded into XML entity form (like &amp;).
        *        EncodeHttpCharactersLC() method from XmlUtils can be used
        *        for encoding of basic XML entities.
        * @return a new CSenIdentityProvider
        */
        IMPORT_C static CSenIdentityProvider* NewL( const TDesC8& aEndpoint );

        /**
        * Two-phased constructor.
        * Note: contract defaults here to "urn:liberty:as:2004-04"
        * @since Series60 3.0
        * @param aEndpoint the service endpoint. Note that endpoint cannot 
        *        include characters which are illegal in XML. If endpoint
        *        is an URL which contains illegal characters (like '&'-char),
        *        those need to be encoded into XML entity form (like &amp;).
        *        EncodeHttpCharactersLC() method from XmlUtils can be used
        *        for encoding of basic XML entities.
        * @return a new CSenIdentityProvider, which pointer is left on
        *         cleanup stack.
        */
        IMPORT_C static CSenIdentityProvider* NewLC( const TDesC8& aEndpoint );

        /**
        * Two-phased constructor.
        * @since Series60 3.0
        * @param aEndpoint the service endpoint. Note that endpoint cannot 
        *        include characters which are illegal in XML. If endpoint
        *        is an URL which contains illegal characters (like '&'-char),
        *        those need to be encoded into XML entity form (like &amp;).
        *        EncodeHttpCharactersLC() method from XmlUtils can be used
        *        for encoding of basic XML entities.
        * @param aContract identifies the service type. Typically some URN.
        *        Default is Liberty ID-WSF Authentication Service contract:
        *        -- urn:liberty:as:2004-04
        * @return a new CSenIdentityProvider
        */
        IMPORT_C static CSenIdentityProvider* NewL( const TDesC8& aEndpoint,
                                                    const TDesC8& aContract );

        /**
        * Two-phased constructor.
        * @since Series60 3.0
        * @param aEndpoint the service endpoint. Note that endpoint cannot 
        *        include characters which are illegal in XML. If endpoint
        *        is an URL which contains illegal characters (like '&'-char),
        *        those need to be encoded into XML entity form (like &amp;).
        *        EncodeHttpCharactersLC() method from XmlUtils can be used
        *        for encoding of basic XML entities.
        * @param aContract identifies the service type. Typically some URN.
        *        Default is Liberty ID-WSF Authentication Service contract:
        *        -- urn:liberty:as:2004-04
        * @return a new CSenIdentityProvider, which pointer is left on
        *         cleanup stack.
        */
        IMPORT_C static CSenIdentityProvider* NewLC(const TDesC8& aEndpoint,
                                                    const TDesC8& aContract );
        
        /**
        * Two-phased constructor.
        * @since Series60 3.0
        * @param aEndpoint the service endpoint. Note that endpoint cannot 
        *        include characters which are illegal in XML. If endpoint
        *        is an URL which contains illegal characters (like '&'-char),
        *        those need to be encoded into XML entity form (like &amp;).
        *        EncodeHttpCharactersLC() method from XmlUtils can be used
        *        for encoding of basic XML entities.
        * @param aContract identifies the service type. Typically some URN.
        *        Default is Liberty ID-WSF Authentication Service contract:
        *        -- urn:liberty:as:2004-04
        * @param aProviderID is identifier of this IdentityProvider. It is a
        *        unique key pointing to some known endpoint.
        * @return a new CSenIdentityProvider
        */
        IMPORT_C static CSenIdentityProvider* NewL( const TDesC8& aEndpoint,
                                                    const TDesC8& aContract,
                                                    const TDesC8& aProviderID);

        /**
        * Two-phased constructor.
        * @since Series60 3.0
        * @param aEndpoint the service endpoint. Note that endpoint cannot 
        *        include characters which are illegal in XML. If endpoint
        *        is an URL which contains illegal characters (like '&'-char),
        *        those need to be encoded into XML entity form (like &amp;).
        *        EncodeHttpCharactersLC() method from XmlUtils can be used
        *        for encoding of basic XML entities.
        * @param aContract identifies the service type. Typically some URN.
        *        Default is Liberty ID-WSF Authentication Service contract:
        *        -- urn:liberty:as:2004-04
        * @param aProviderID is identifier of this IdentityProvider. It is a
        *        unique key pointing to some known endpoint. Required only
        *        for ID-WSF framework.
        * @return a new CSenIdentityProvider, which pointer is left on
        *         cleanup stack.
        */
        IMPORT_C static CSenIdentityProvider* NewLC(const TDesC8& aEndpoint,
                                                    const TDesC8& aContract,
                                                    const TDesC8& aProviderID);

        /**
        * Two-phased constructor.
        * @since Series60 3.0
        * @param aEndpoint the service endpoint. Note that endpoint cannot 
        *        include characters which are illegal in XML. If endpoint
        *        is an URL which contains illegal characters (like '&'-char),
        *        those need to be encoded into XML entity form (like &amp;).
        *        EncodeHttpCharactersLC() method from XmlUtils can be used
        *        for encoding of basic XML entities.
        * @param aContract identifies the service type. Typically some URN.
        *        Default is Liberty ID-WSF Authentication Service contract:
        *        -- urn:liberty:as:2004-04
        * @param aProviderID is identifier of this IdentityProvider. It is a
        *        unique key pointing to some known endpoint. Required only
        *        for ID-WSF framework.
        * @param aServiceID is a unique contract to some invocable service.
        *        Typically some URN. If this IDP is registered to ID-WSF 
        *        framework, this ServiceID will be appended into list of
        *        services which trust this IDP, and the actual IDP "knows".
        * @return a new CSenIdentityProvider
        */
        IMPORT_C static CSenIdentityProvider* NewL( const TDesC8& aEndpoint,
                                                    const TDesC8& aContract,
                                                    const TDesC8& aProviderID,
                                                    const TDesC8& aServiceID);

        /**
        * Two-phased constructor.
        * @since Series60 3.0
        * @param aEndpoint the service endpoint. Note that endpoint cannot 
        *        include characters which are illegal in XML. If endpoint
        *        is an URL which contains illegal characters (like '&'-char),
        *        those need to be encoded into XML entity form (like &amp;).
        *        EncodeHttpCharactersLC() method from XmlUtils can be used
        *        for encoding of basic XML entities.
        * @param aProviderID is identifier of this IdentityProvider. It is a
        *        unique key pointing to some known endpoint. Required only
        *        for ID-WSF framework.
        * @param aContract identifies the service type. Typically some URN.
        *        Default is Liberty ID-WSF Authentication Service contract:
        *        -- urn:liberty:as:2004-04
        * @param aServiceID is a unique contract to some invocable service.
        *        Typically some URN. If this IDP is registered to ID-WSF 
        *        framework, this ServiceID will be appended into list of
        *        services which trust this IDP, and the actual IDP "knows".
        * @return a new CSenIdentityProvider, which pointer is left on
        *         cleanup stack.
        */
        IMPORT_C static CSenIdentityProvider* NewLC(const TDesC8& aEndpoint,
                                                    const TDesC8& aContract,
                                                    const TDesC8& aProviderID,
                                                    const TDesC8& aServiceID);

        /**
        * Destructor.
        */
        IMPORT_C virtual ~CSenIdentityProvider();

        // New functions

        /**
        * A getter.
        * @since Series60 3.0
        * @return a pointer to authorization id
        */
        IMPORT_C virtual TPtrC8 AuthzID();

        /**
        * A getter.
        * @since Series60 3.0
        * @return a pointer to advisory authentication id
        */
        IMPORT_C virtual TPtrC8 AdvisoryAuthnID();

        /**
        * A getter.
        * @since Series60 3.0
        * @return a pointer to provider id
        */
        IMPORT_C TPtrC8 ProviderID();

        /**
        * A getter.
        * @since Series60 3.0
        * @return a pointer to password
        */
        IMPORT_C virtual TPtrC8 Password();

        /**
        * A getter.
        * @since Series60 3.0
        * @return a pointer to IMEI
        */
        IMPORT_C const TDesC8& IMEI();

        /**
        * A getter.
        * @since Series60 3.0
        * @return a pointer to username
        */
        IMPORT_C TPtrC8 UserName();

        /**
        * Setter
        * @since Series60 3.0
        * @param aProviderID the set id
        * @return KErrNone or other system-wide Symbian error codes.
        */
        IMPORT_C TInt SetProviderID( const TDesC8& aProviderID );

        /**
        * Setter for ServiceID. ServiceID is the contract of some
        * invocable service, typically some URN.
        * Note, that when registering an IDP the possibly existing
        * list of ServiceIDs is not cleared, but the ServiceID set
        * via this method is added as new entry into that list, if
        * it was non-existent.
        * @since Series60 3.0
        * @param aServiceID the set id
        * @return KErrNone or other system-wide Symbian error codes.
        */
        IMPORT_C TInt SetServiceID( const TDesC8& aServiceID );

        /**
        * @since Series60 3.0
        * @param aServiceDescription the service description to check
        * @return   ETrue if the ServiceDescription, i.e. its endpoint
        *                 or contract, is associated to this IdentityProvider.
        *                 Or if the ServiceDescription is about this
        *                 IdentityProvider.
        *           EFalse otherwise
        */
        IMPORT_C TBool IsTrustedByL( MSenServiceDescription& aServiceDescription );

        /**
        * @since Series60 3.0
        * @param aProviderIdOrServiceId    IdentityProvider ID, or Service ID
        *                 which is being checked. Service ID is typically URI
        *                 (service contract or service endpoint).
        * @return   ETrue if the ServiceDescription, i.e. its endpoint
        *                 or contract, is associated to this IdentityProvider.
        *                 Or if the ServiceDescription is about this
        *                 IdentityProvider.
        *           EFalse otherwise
        */
        IMPORT_C TBool IsTrustedByL( const TDesC8& aProviderIdOrServiceId );

        /**
        * Checks if this identity provider is set as default .
        * @since Series60 3.0
        * @return ETrue if default-attribute was set, EFalse otherwise
        */
        IMPORT_C TBool IsDefault();

        /**
        * Sets the user information.
        *   Status codes:
        *   KErrNone        ok
        *   Other codes are system error codes.
        * @since Series60 3.0
        * @param aAuthzID Authorization id.
        * @param aAdvisoryAuthnID Advisory authorization id.
        * @param aPassword Password.
        * @return status/error code.
        */
        IMPORT_C TInt SetUserInfoL( const TDesC8& aAuthzID,
                                    const TDesC8& aAdvisoryAuthnID,
                                    const TDesC8& aPassword );

        /**
        * @deprecated. This method is no longer in use.
        * Creates http-credentials by making password-username pair 
        * and encoding it with BASE-64.
        * @since Series60 3.0
        * @param    aIdMgr  Identitymanager which is used to obtain a password
        *                   if no password for this identityprovider was set.
        * @return   a newly allocated credentialbuffer. Ownership is transferred 
        *           to the caller.
        */
        IMPORT_C HBufC8* HttpCredentialsL( MSenIdentityManager& aIdMgr );
    
        // Functions from base classes
    
        // From CSenXmlServiceDescription
        
        /**
        * @since Series60 3.0
        * @return Descriptor containing service description local name
        *                    for this service description.
        *                    This is the localname of the element, when this class is
        *                    represented as an XML element. 
        */
        IMPORT_C const TDesC8& NewElementName();

        /**
        * Setter for (identity) provider ID (leaving variant)
        * @since Series60 4.0
        * @param aProviderID the unique identifier of the (identity) provider
        * @return KErrNone on success, KErrArgument if aProviderID is a
        * zero-length descriptor, or one of the system-wide error codes
        * otherwise.
        */
        IMPORT_C TInt SetProviderIdL( const TDesC8& aProviderID );
        
        IMPORT_C TInt SetAccountExtensionsL(const TDesC8& aDetail);
        
        IMPORT_C TPtrC8 AccountExtensions(CSenElement*& aAccExt);

    protected:  
    
        /*
          C++ default constructor
        */
        IMPORT_C CSenIdentityProvider( TDescriptionClassType aType );
        

        // Functions from base classes
    
        // From CSenXmlServiceDescription
        
        /**
        * Standard 2nd phase constructor.   
        * @since Series60 3.0
        * @param aEndpoint the service endpoint. Note that endpoint cannot 
        *        include characters which are illegal in XML. If endpoint
        *        is an URL which contains illegal characters (like '&'-char),
        *        those need to be encoded into XML entity form (like &amp;).
        *        EncodeHttpCharactersLC() method from XmlUtils can be used
        *        for encoding of basic XML entities.
        */
        IMPORT_C void ConstructL(const TDesC8& aEndPoint);
        
        /**
        * @since Series60 3.0
        * @param aEndpoint the service endpoint. Note that endpoint cannot 
        *        include characters which are illegal in XML. If endpoint
        *        is an URL which contains illegal characters (like '&'-char),
        *        those need to be encoded into XML entity form (like &amp;).
        *        EncodeHttpCharactersLC() method from XmlUtils can be used
        *        for encoding of basic XML entities.
        * @param aContract identifies the service type. Typically some URN.
        *        Default contract is Liberty ID-WSF Authentication Service
        *        - "urn:liberty:as:2004-04".
        */
        IMPORT_C void ConstructL(const TDesC8& aEndPoint,
                                 const TDesC8& aContract);

        /**
        * @since Series60 3.0
        * @param aEndpoint the service endpoint. Note that endpoint cannot 
        *        include characters which are illegal in XML. If endpoint
        *        is an URL which contains illegal characters (like '&'-char),
        *        those need to be encoded into XML entity form (like &amp;).
        *        EncodeHttpCharactersLC() method from XmlUtils can be used
        *        for encoding of basic XML entities.
        * @param aContract identifies the service type. Typically some URN.
        *        Default contract is Liberty ID-WSF Authentication Service
        *        - "urn:liberty:as:2004-04".
        * @param aProviderID is identifier of this IdentityProvider. It is a
        *        unique key pointing to some known endpoint. Required only
        *        for ID-WSF framework.
        */
        IMPORT_C void ConstructL(const TDesC8& aEndPoint,
                                 const TDesC8& aContract,
                                 const TDesC8& aProviderID);

        /**
        * @since Series60 3.0
        * @param aEndpoint the service endpoint. Note that endpoint cannot 
        *        include characters which are illegal in XML. If endpoint
        *        is an URL which contains illegal characters (like '&'-char),
        *        those need to be encoded into XML entity form (like &amp;).
        *        EncodeHttpCharactersLC() method from XmlUtils can be used
        *        for encoding of basic XML entities.
        * @param aContract identifies the service type. Typically some URN.
        *        Default contract is Liberty ID-WSF Authentication Service
        *        - "urn:liberty:as:2004-04".
        * @param aProviderID is identifier of this IdentityProvider. It is a
        *        unique key pointing to some known endpoint. Required only
        *        for ID-WSF framework.
        * @param aServiceID is a unique contract to some invocable service.
        *        Typically some URN. If this IDP is registered to ID-WSF 
        *        framework, this ServiceID will be appended into list of
        *        services which trust this IDP, and the actual IDP "knows".
        */
        IMPORT_C void ConstructL( const TDesC8& aEndPoint,
                                  const TDesC8& aContract,
                                  const TDesC8& aProviderID,
                                  const TDesC8& aServiceID );
    };

#endif // SEN_IDENTITY_PROVIDER_H

// End of File
