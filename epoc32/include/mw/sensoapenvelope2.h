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
* Description:        CSenSoapEnvelope is an utility class offering capability to
*                parse XML SOAP envelope and manipulation methods to alter its
*                contents.
*
*/








#ifndef SEN_SOAP_ENVELOPE2_H
#define SEN_SOAP_ENVELOPE2_H

//  INCLUDES
#include <SenDomFragmentBase.h>
#include <SenSoapConstants.h>
#include <MSenMessage.h>

// CONSTANTS
/*
// Now declared in <SenSoapConstants.h>
_LIT8(KSenSoapEnvelopeName,    	        "Envelope");
_LIT8(KSenSoapEnvelopePrefix,   	    "S");
_LIT8(KSenSoapEnvelopeXmlns,            "http://schemas.xmlsoap.org/soap/envelope/");
_LIT8(KSenSoap12EnvelopeXmlns,          "http://www.w3.org/2003/05/soap-envelope");
_LIT8(KSenSoapEnvelopeHeaderName,       "Header");
_LIT8(KSenSoapEnvelopeHeaderQName,      "S:Header");
_LIT8(KSenSoapEnvelopeBodyName,         "Body");
_LIT8(KSenSoapEnvelopeBodyQName,        "S:Body");
_LIT8(KSenSoapFaultName,                "Fault");

_LIT8(KSenSoapActionHeaderName,         "SOAPAction");
_LIT8(KSenSoapActionHeaderValueEmpty,   "\"\"");

const TInt KStateParsingSoapHeader  = 20; // ignore state   (even number)
const TInt KStateParsingSoapBody    = 40; // ignore state   (even number)
const TInt KStateParsingSoapFault   = 5;  // save state     (odd number)

enum TSOAPVersion
		{
		ESOAP11 = 1,
		ESOAP12
		};
*/

// FORWARD DECLARATIONS
class CSenSoapFault2;
class CSenTransportProperties;
class CSenMessageContext;
class MSenMessageContext;

// CLASS DECLARATION

/**
* CSenSoapEnvelope is an utility class offering capability to parse
* XML SOAP envelope and manipulation methods to alter its contents.
* Typically WSC uses this class to parse messages received through
* WSF HandleMessageL() and HandleErrorL() callbacks.
* Class has convenience methods for checking if a SOAP envelope body
* contains a fault and functionality to detach SOAP Fault object out
* from it. Also possibility to set SOAPAction HTTP header is supported.
*  @lib SenUtils.lib
*  @since Series60 4.0
*/
class CSenSoapEnvelope2 : public CSenFragmentBase, public MSenMessage
    {
    public:  // Constructors and destructor

        /**
        * Two-phased constructor.
        */
        IMPORT_C static CSenSoapEnvelope2* NewL();

        /**
        * Two-phased constructor.
        */
        IMPORT_C static CSenSoapEnvelope2* NewLC();

        /**
        * Two-phased constructor.
        */
        IMPORT_C static CSenSoapEnvelope2* NewL(MSenMessageContext& aContext);

        /**
        * Two-phased constructor.
        */
        IMPORT_C static CSenSoapEnvelope2* NewLC(MSenMessageContext& aContext);

        /**
        * Two-phased copy constructor.
        */
        IMPORT_C static CSenSoapEnvelope2* NewL(CSenSoapEnvelope2& aEnvelope);

        /**
        * Two-phased copy constructor.
        */
        IMPORT_C static CSenSoapEnvelope2* NewLC(CSenSoapEnvelope2& aEnvelope);

        /**
        * Destructor.
        */
        IMPORT_C virtual ~CSenSoapEnvelope2();

        // New functions

        /**
        * Sets body of the envelope.
        * @since Series60 4.0
        * @param aBody      Body (content) to be set.
        * @return SOAP body (content) which was just set
        */
        IMPORT_C virtual TPtrC8 SetBodyL(const TDesC8& aBody);

        /**
        * Sets body of the envelope.
        * @since Series60 4.0
        * @param aBody      Body (content) to be set.
        * @return SOAP body (content) which was just set
        */
        IMPORT_C virtual TXmlEngElement SetBodyL(TXmlEngElement aBodyElement);

        /**
        * Getter for envelopes body
        * @since Series60 4.0
        * @return body as TXmlEngElement
        */
        IMPORT_C virtual TXmlEngElement BodyL();

        /**
        * Getter for envelopes header
        * @since Series60 4.0
        * @return header as TXmlEngElement
        */
        IMPORT_C virtual TXmlEngElement HeaderL();

        /**
        * Adds an element to the header.
        * @since Series60 4.0
        * @param aHeaderElement new child element to be
        *        added inside Header  element. Ownership
        *        is always transferred to CSenSoapEnvelope.
        * @return added TXmlEngElement
        */
        IMPORT_C virtual TXmlEngElement AddHeaderL(TXmlEngElement aHeaderElement);

        /**
        * Getter for the envelope body as a UTF-8 form XML string.
        * @since Series60 4.0
        * @return body as a HBufC8 pointer. Ownership is transferred to caller.
        */
        IMPORT_C virtual HBufC8* BodyAsStringL();

        /**
        * Checks if this SOAP envelope body contains SOAP fault or not.
        * @since Series60 4.0
        * @return TBool ETrue if there is a fault, EFalse if not.
        */
        IMPORT_C virtual TBool IsFault();

        /**
        * Detaches the <Fault> element from the envelope, removing the element
        * from the envelope.
        * @since Series60 4.0
        * @return pointer to the soap fault. Caller takes the ownership.
        *         NULL if <Fault> element is non-existent.
        */
        IMPORT_C virtual CSenSoapFault2* DetachFaultL();

        /**
        * Gets the <Fault> element. Ownership is not transferred.
        * NULL if not a fault.
        * @since Series60 4.0
        * @return reference to SOAP fault object owned by this SOAP envelope
        */
        IMPORT_C virtual CSenSoapFault2* FaultL();

        /**
        * Sets the SOAP action HTTP header. WSF will use this value
        * while submitting this SOAP envelope request over HTTP/S transport.
        * @since Series60 4.0
        * @param aSoapAction    the SOAP Action HTTP header to be set.
        * The default value is KSenSoapActionHeaderValueEmpty, which is
        * two double quotation marks - "" - without any character in between.
        * SOAP specification requires double quotation marks, even if action
        * is empty.
        * If a string without double quotation marks is passed, it will be
        * wrapped inside double quotation marks, added in the beginning and
        * at the end of the actual SOAP Action string.
        *
        * @return newly set SOAP action header. String might have been
        * extended to include double quotation marks, if those were missing
        * from the argument.
        */
        IMPORT_C virtual TPtrC8 SetSoapActionL(const TDesC8& aSoapAction);

        /**
        * Gets the soap action header.
        * @since Series60 4.0
        * @return   current SOAP action header, which is always wrapped
        * inside double quotation marks. If SOAPAction has not been set
        * to this SOAP envelope instance, function will return zero-length
        * descriptor (KNullDesC8)
        */
        IMPORT_C virtual TPtrC8 SoapAction();

        /*
        * Getter for checking whether this message has at least one
        * valid <Header> element
        * @return ETrue, if <Header> element exists, EFalse otherwise.
        */
        IMPORT_C TBool HasHeader();

        /*
        * Getter for checking whether this message has valid <Body> element
        * @return ETrue, if <Body> element exists, EFalse otherwise.
        */
        IMPORT_C TBool HasBody();
        
        /**
        * Getter for currently effecitve SOAP version.
        * @return enumeration which dictates SOAP version.
        */
        IMPORT_C virtual TSOAPVersion SoapVersion();

    public: // From MSenMessage
        IMPORT_C virtual TClass Type();
        IMPORT_C virtual TDirection Direction();
        IMPORT_C virtual TInt SetContext(MSenMessageContext* apOwnedContext);
        IMPORT_C virtual MSenMessageContext* Context();
        IMPORT_C virtual TInt SetProperties(MSenProperties* apOwnedProperties);
        IMPORT_C virtual MSenProperties* Properties();

        IMPORT_C virtual TBool IsSafeToCast(TClass aType);
        IMPORT_C virtual TInt TxnId();
		IMPORT_C virtual MSenMessage* CloneL();

    protected:

        /**
         *  Constructor.
         */
        CSenSoapEnvelope2();
		/**
		* This method should be called from the deriving
		* classes ConstructL() methods.
	    * @since Series60 4.0
		*/
	    IMPORT_C void BaseConstructL(TSOAPVersion aVersion);

        /**
        * This method should be called from the deriving
        * classes ConstructL() methods.
        * @since Series60 4.0
        */
        IMPORT_C void BaseConstructL();

        /**
        * This method should be called from the deriving
        * classes ConstructL() methods.
        * @since Series60 4.0
        */
        IMPORT_C void BaseConstructL(MSenMessageContext& aMessage);

        /**
        * This method should be called from the deriving
        * classes ConstructL() methods.
        * @since Series60 4.0
        */
        IMPORT_C void BaseConstructL(MSenMessageContext& aMessage,
                                     TSOAPVersion aVersion);

        /**
        * This method should be called from the deriving
        * classes ConstructL() methods.
        * @since Series60 4.0
        */
        IMPORT_C void BaseConstructL(CSenSoapEnvelope2& aEnvelope);

        // New functions

        /**
        * This method should be overridden by subclasses.
        * Implements functionality to parse SOAP header if one is found
        * during parsing the envelope.
        * Parses all elements found under top <Header> element by
        * using DOM fragment.
        * @since Series60 4.0
        * @param aNsUri         The namespace URI of the new element
        * @param aLocalName     The local name of the new element
        * @param aQName         The qualified name of the new element
        * @param aAttributes    The attributes of the new element
        */
        IMPORT_C virtual void ParseHeaderL(const RTagInfo& aElement,
                                           const RAttributeArray& aAttributes);

        // Functions from base classes

        // From CSenFragmentBase
        IMPORT_C virtual void OnStartElementL(const RTagInfo& aElement,
    	                                      const RAttributeArray& aAttributes,
    	                                      TInt aErrorCode);                                            

        IMPORT_C virtual void OnEndElementL(const RTagInfo& aElement,
                                            TInt aErrorCode);

        IMPORT_C virtual CSenFragmentBase* CreateBodyFragmentL(const TDesC8& aNsUri,
                                                       const TDesC8& aLocalName,
                                                       const TDesC8& aPrefix,
                                                       const RAttributeArray& aAttributes,
                                                       TXmlEngElement& aParent,
                                                       RSenDocument& aOwnerDocument);

    protected: // Data
        // Internal members, protected so that deriving classes have access to them.
        CSenFragmentBase*           ipBodyFragment;
        CSenFragmentBase*           ipHeaderFragment;
        HBufC8*                     ipSoapAction;
        TInt                        iTransactionId;

        MSenProperties*             ipProperties;      // owned => safe upward cast is performed in de-alloc
        MSenMessageContext*         ipNotOwnedContext; // owned => safe upward cast is performed in de-alloc
        
        TAny* ipReserved;

        TBool               iFault;
        TDirection          iDirection;
    };

#endif // SEN_SOAP_ENVELOPE_H

// End of File



