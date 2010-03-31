/*
* Copyright (c) 2002-2006 Nokia Corporation and/or its subsidiary(-ies). 
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
* Description:        Class implements (web) service credential functionality
*
*/








#ifndef SEN_CREDENTIAL2_H
#define SEN_CREDENTIAL2_H

//  INCLUDES
#include <e32base.h>
#include <s32strm.h>
#include <SenFragmentBase.h>
#include <SenDomFragmentBase.h>

// CONSTANTS
_LIT8(KCredentialsName2,     "Credentials");
_LIT8(KEndpointName2,        "Endpoint");
_LIT8(KSecurityMechIdName2,  "SecurityMechID");
_LIT8(KNotOnOrAfterName2,    "NotOnOrAfter");
_LIT8(KConditionsName2,      "Conditions");

_LIT8(KSenCredentialId,                 "CredentialId");
_LIT8(KSenCredentialValidUntil,         "ValidUntil");
_LIT8(KSenCredentialIdentifierLocalname,"Identifier");
_LIT8(KSenCredentialProperteisLocalname,"Properties");

// FORWARD DECLARATIONS
class SenDateUtils;
class CSenCredentialIdentifier;
class CSenXmlServiceDescription;
class CSenIdentityProvider;
class CSenServiceSession;
class CSenFacet;

// CLASS DECLARATION

/**
* Class implements (web) service credential functionality
*  @lib SenServDesc.lib
*  @since Series60 3.0
*/
class CSenCredential2 : public CSenFragmentBase
    {
    public:  // Constructors and destructor
        
        /**
        * Basic constructor.
        *
        * @since Series60 4.0
        */
        IMPORT_C static CSenCredential2* NewL();

        /**
        * Basic constructor.
        *
        * @since Series60 4.0
        */
        IMPORT_C static CSenCredential2* NewLC();

        /**
        * Basic constructor.
        *
        * @since Series60 4.0
        * @param aNsUri     is the XML namespace of this credential
        * @param aLocalName is the XML localname of this credential
        * @param aPrefix    is the prefix of this credential
        * @param aAttrs     are the XML attributes of this credential
        */
        IMPORT_C static CSenCredential2* NewL(const TDesC8& aNsUri,
                                     const TDesC8& aLocalName,
                                     const TDesC8& aQName,
                                     const RAttributeArray& aAttributes);

        /**
        * Basic constructor.
        *
        * @since Series60 4.0
        * @param aNsUri     is the XML namespace of this credential
        * @param aLocalName is the XML localname of this credential
        * @param aPrefix    is the prefix of this credential
        * @param aAttrs     are the XML attributes of this credential
        */
        IMPORT_C static CSenCredential2* NewLC(const TDesC8& aNsUri,
                                      const TDesC8& aLocalName,
                                      const TDesC8& aQName,
                                      const RAttributeArray& aAttributes);

        /**
        * Basic constructor.
        *
        * @since Series60 4.0
        * @param aNsUri     is the XML namespace of this credential
        * @param aLocalName is the XML localname of this credential
        * @param aPrefix    is the prefix of this credential
        * @param aAttrs     are the XML attributes of this credential
        * @param aParent    is the parent XML element of this credential
        */
        IMPORT_C static CSenCredential2* NewL(const TDesC8& aNsUri,
                                     const TDesC8& aLocalName,
                                     const TDesC8& aQName,
                                     const RAttributeArray& aAttributes,
                                     TXmlEngElement& aParent);

        /**
        * Basic constructor.
        *
        * @since Series60 4.0
        * @param aNsUri     is the XML namespace of this credential
        * @param aLocalName is the XML localname of this credential
        * @param aPrefix    is the prefix of this credential
        * @param aAttrs     are the XML attributes of this credential
        * @param aParent    is the parent XML element of this credential
        */
        IMPORT_C static CSenCredential2* NewLC(const TDesC8& aNsUri,
                                      const TDesC8& aLocalName,
                                      const TDesC8& aQName,
                                      const RAttributeArray& aAttributes,
                                      TXmlEngElement& aParent);

         /**
        * Basic constructor.
        *
        * @since Series60 4.0
        * @param aNsUri         is the XML namespace of this fragment
        * @param aLocalName     is the XML localname of this fragment
        * @param aPrefix        is the prefix of this fragment
        * @param aAttrs         are the XML attributes of this fragment
        * @param aParent        is the parent XML element of this fragment
        * @param aOwnerDocument is the document which will be the owner of
        *                       the elements of this fragment
        */
        IMPORT_C static CSenCredential2* NewL(const TDesC8& aNsUri,
                                     const TDesC8& aLocalName,
                                     const TDesC8& aQName,
                                     const RAttributeArray& aAttrs,
                                     TXmlEngElement& aParent,
                                     RSenDocument& aOwnerDocument);                                         

        /**
        * Basic constructor.
        *
        * @since Series60 4.0
        * @param aNsUri         is the XML namespace of this fragment
        * @param aLocalName     is the XML localname of this fragment
        * @param aPrefix        is the prefix of this fragment
        * @param aAttrs         are the XML attributes of this fragment
        * @param aParent        is the parent XML element of this fragment
        * @param aOwnerDocument is the document which will be the owner of
        *                       the elements of this fragment
        */
        IMPORT_C static CSenCredential2* NewLC(const TDesC8& aNsUri,
                                           const TDesC8& aLocalName,
                                           const TDesC8& aQName,
                                           const RAttributeArray& aAttrs,
                                           TXmlEngElement& aParent,
                                           RSenDocument& aOwnerDocument);

        /**
        * Constructor which copies itself from another credential.
        *
        * @since Series60 4.0
        * @param    aCredential     credential to copy from.
        * @return new CSenCredential instance pointer
        */
        IMPORT_C static CSenCredential2* NewL(const CSenCredential2& aCredential);

        /**
        * Constructor which copies itself from another credential.
        *
        * @since Series60 4.0
        * @param    aCredential     credential to copy from.
        * @return new CSenCredential instance pointer, which is left on
        *         cleanup stack.
        */
        IMPORT_C static CSenCredential2* NewLC(const CSenCredential2& aCredential);
        
        /**
        * Destructor.
        */
        IMPORT_C virtual ~CSenCredential2();        

        // New functions
        
        /**
        * Getter for the credential ID.
        *
        * @since Series60 4.0
        * @return the ID
        */
        IMPORT_C virtual const TDesC8& Id();

        /**
        * Getter for the credential expiration time.
        * @since Series60 3.0
        * @return the the expiration time
        */
        IMPORT_C virtual TTime& ValidUntil();

        /**
        * Setter for the credential expiration time.
        *
        * @since Series60 4.0
        * @param aTime  The new expiration time
        */
        IMPORT_C virtual void SetValidUntil(TTime& aTime);

    protected:  // Functions from base classes
        
        /**
        * C++ default constructor.
        */
        IMPORT_C CSenCredential2();


        IMPORT_C virtual void OnStartElementL(const RTagInfo& aElement,
        							          const RAttributeArray& aAttributes,
        						 	          TInt aErrorCode);
        
        /**
        * @since Series60 4.0
        * @param aNsUri is the XML namespace as UTF-8 descriptor
        * @param aLocalName is the XML localname as UTF-8 descriptor
        * @param aQName is the XML qualifiedname as UTF-8 descriptor
        * @param aAttributes is the list of XML attributes
        */
        IMPORT_C void BaseConstructL(const TDesC8& aNsUri,
                                     const TDesC8& aLocalName,
                                     const TDesC8& aQName,
                                     const RAttributeArray& aAttributes);

        /**
        * @since Series60 4.0
        * @param aNsUri is the XML namespace as UTF-8 descriptor
        * @param aLocalName is the XML localname as UTF-8 descriptor
        * @param aQName is the XML qualifiedname as UTF-8 descriptor
        * @param aAttributes is the list of XML attributes
        * @param aParent is the parent element, which may declare other
        *        namespaces.
        */
        IMPORT_C void BaseConstructL(const TDesC8& aNsUri,
                                     const TDesC8&  aLocalName,
                                     const TDesC8& aQName,
                                     const RAttributeArray& aAttributes,
                                     TXmlEngElement& aParent);

        /**
        * By default Symbian 2nd phase constructor is private.
        *
        * @since Series60 4.0
        * @param aNsUri is the XML namespace as UTF-8 descriptor
        * @param aLocalName is the XML localname as UTF-8 descriptor
        * @param aQName is the XML qualifiedname as UTF-8 descriptor
        * @param aAttributes is the list of XML attributes
        * @param aParent is the parent element, which may declare other
        *        namespaces.
        * @param aOwnerDocument is the document which will be the owner of
        *                       the elements of this credential
        */
        IMPORT_C void BaseConstructL(const TDesC8& aNsUri,
                                     const TDesC8&  aLocalName,
                                     const TDesC8& aQName,
                                     const RAttributeArray& aAttributes,
                                     TXmlEngElement& aParent,
                                     RSenDocument& aOwnerDocument);                                         
        /**
        * By default Symbian 2nd phase constructor is private.
        *
        * @since Series60 4.0
        * @param aCredential is the source credential to be copied.
        */
        IMPORT_C void BaseConstructL(CSenCredential2& aCredential);


    private:
        /**
        * By default Symbian 2nd phase constructor is private.
        *
        * BaseConstructL for setting XML localname for this Credential.
        * @since Series60 4.0
        * @param aLocalName XML localname for this Credential
        */
        IMPORT_C void ConstructL(const TDesC8& aLocalName);

        // New functions

        /**
        * Setter for Credential ID
        *
        * @since Series60 4.0
        * @param aId is the unique ID for this Credential
        */
        void SetIdL(const TDesC8& aId);

    private: // Data
        // Unique ID for this credential. Owned.
        HBufC8*                     iId;
        // One may use SenDateUtils to convert from XML date descrtor to TTime
        TTime                       iNotOnOrAfter;    
    };

#endif // SEN_CREDENTIAL2_H

// End of File


