/*
* Copyright (c) 2006 Nokia Corporation and/or its subsidiary(-ies). 
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
* Description:        This header provides SOAP specific constants.
*
*/








#ifndef SEN_SOAP_CONSTANTS_H
#define SEN_SOAP_CONSTANTS_H

// CONSTANTS

/// Envelope:
_LIT8(KSenSoap12ContentTypeHeaderValue, "application/soap+xml; charset=utf-8");
_LIT8(KSenSoap12AcceptHeaderValue,      "application/soap+xml");
_LIT8(KSenSoapEnvelopeName,             "Envelope");
_LIT8(KSenSoapEnvelopePrefix,   	    "S");
_LIT8(KSenSoapEnvelopeQName,            "S:Envelope");

_LIT8(KSenSoapEnvelopeXmlns,            "http://schemas.xmlsoap.org/soap/envelope/");
_LIT8(KSenSoap12EnvelopeXmlns,          "http://www.w3.org/2003/05/soap-envelope");
_LIT8(KSenSoapEnvelopeHeaderName,       "Header");
_LIT8(KSenSoapEnvelopeHeaderQName,      "S:Header");
_LIT8(KSenSoapEnvelopeBodyName,         "Body");
_LIT8(KSenSoapEnvelopeBodyQName,        "S:Body");
_LIT8(KSenSoapFaultName,                "Fault");

/// Action
_LIT8(KSenSoapActionHeaderName,         "SOAPAction");
_LIT8(KSenSoapActionHeaderValueEmpty,   "\"\""); 

/// Security
_LIT8(KSecurityName,                "Security");
_LIT8(KBinarySecurityToken,         "BinarySecurityToken");
_LIT8(KSecurityXmlNs,               "http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-wssecurity-secext-1.0.xsd");
_LIT8(KSecuritySchemeXmlNs,         "http://schemas.xmlsoap.org/ws/2003/06/secext");
_LIT8(KSecurityXmlNsPrefix,         "wsse");

_LIT8(KSecurityAttrType,            "Type");           // name of the XML attribute 
_LIT8(KSecurityAttrTypeText,        "PasswordText");   // for default type: wsse:PasswordText
_LIT8(KSecurityAttrTypeDigest,      "PasswordDigest"); // digest type: wsse:Digest

_LIT8(KSecurityTokenReference,      "SecurityTokenReference");
_LIT8(KSecurityUtilityXmlNs,        "http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-wssecurity-utility-1.0.xsd");
_LIT8(KSecurityUtilityXmlNsPrefix,  "wsu");

_LIT8(KSecurityUtilityId, "Id");
_LIT8(KSecurityUtilityWsuId, "wsu:Id");


const TInt KStateParsingSoapHeader  = 20; // ignore state   (even number)
const TInt KStateParsingSoapBody    = 40; // ignore state   (even number)
const TInt KStateParsingSoapFault   = 5;  // save state     (odd number)

/// Fault
// CONSTANTS
_LIT8(KFaultCodeLocalname,      "faultcode");   // "faultcode" is intended for use by software to
                                                // provide an algorithmic mechanism for
                                                // identifying the fault.

_LIT8(KFaultStringLocalname,    "faultstring"); // "faultstring" is intended to provide a human
                                                // readable explanation of the fault and is not
                                                // intended for algorithmic processing.

_LIT8(KFaultActorLocalname,     "faultactor");  // "faultactor" is intended to provide information
                                                // about which SOAP node on the SOAP message path
                                                // caused the fault to happen.
                                                // The value of the "faultactor" is a URI
                                                // identifying the source of the fault.
                                                
_LIT8(KDetailLocalname,         "detail");      // "detail" is intended for carrying application
                                                // specific error information related to the SOAP
                                                // Body. It MUST be present when the contents of
                                                // the SOAP Body could not be processed
                                                // successfully.
                                                
// SOAP 1.2 (http://www.w3.org/TR/soap12-part1/):
_LIT8(KFault12CodeLocalname,	"Code");		// "Code" has a mandatory "Value" element
                                                // information item and may have an optional
                                                // Subcode element information item.

_LIT8(KFault12SubcodeLocalname,	"Subcode");		// "Subcode" has a mandatory "Value" element
                                                // information item and may have an optional
                                                // Subcode element information item.

_LIT8(KFault12ValueLocalname,	"Value");		// In "Code" element:
                                                //    The type of the Value element information
                                                //    item is env:faultCodeEnum. SOAP defines a
                                                //    small set of SOAP fault codes covering high
                                                //    level SOAP faults.
                                                // In "Subcode" element:
                                                //    The type of the Value element information
                                                //    item is xs:QName. The value of this element
                                                //    is an application defined subcategory of
                                                //    the value of the Value child element
                                                //    information item of the Subcode element
                                                //    information item's parent element information
                                                //    item.
                                                
_LIT8(KFault12ReasonLocalname,	"Reason");		// "Reason" has one or more "Text" element
                                                // information item children. Each child "Text"
                                                // element information item SHOULD have a
                                                // different value for its "xml:lang" attribute
                                                // information item.
                                                
_LIT8(KFault12TextLocalname,	"Text");		// "Text" has a mandatory attribute information
                                                // item  with a [local name] of lang and
                                                // [namespace name] of 
                                                // "http://www.w3.org/XML/1998/namespace".
                                                // Note that the definition in of the lang
                                                // attribute information item requires that the
                                                // [prefix] is "xml" or any capitalization thereof.
                                                //
                                                // "Text" is similar to the 'Reason-Phrase' defined
                                                // by HTTP [RFC 2616] and SHOULD provide
                                                // information explaining the nature of the fault.
                                                // It is not intended for algorithmic processing.

_LIT8(KFault12NodeLocalname,	"Node");		// "Node" is intended to provide information about
                                                // which SOAP node on the SOAP message path caused
                                                // the fault to happen.
                                                // "Node" contains the URI of the SOAP node that
                                                // generated the fault.

_LIT8(KFault12DetailLocalname,	"Detail");		// "Detail" MAY be present in a SOAP fault in
                                                // which case it carries additional information
                                                // relative to the SOAP fault codes describing
                                                // the fault. For example, the Detail element
                                                // information item might contain information about
                                                // a message not containing the proper credentials,
                                                // a timeout, etc. The presence of the Detail
                                                // element information item has no significance as
                                                // to which parts of the faulty SOAP message were
                                                // processed.

// SOAP Fault Codes in SOAP 1.2 (http://www.w3.org/TR/soap12-part1/):
_LIT8(KDataEncodingUnknown,     "DataEncodingUnknown");
                                                // A SOAP header block or SOAP body child element 
                                                // information item targeted at the faulting SOAP
                                                // node is scoped (see 5.1.1 SOAP encodingStyle
                                                // Attribute) with a data encoding that the
                                                // faulting node does not support.

_LIT8(KMustUnderstand,          "MustUnderstand");
                                                // An immediate child element information item of
                                                // the SOAP Header element information item
                                                // targeted at the faulting node that was not
                                                // understood by the faulting node contained a SOAP
                                                // mustUnderstand attribute information item with a
                                                // value of "true".
                                                
_LIT8(KReceiver,                "Receiver");    // The message could not be processed for reasons
                                                // attributable to the processing of the message
                                                // rather than to the contents of the message
                                                // itself. For example, processing could include
                                                // communicating with an upstream SOAP node, which
                                                // did not respond. The message could succeed if
                                                // resent at a later point in time.
                                                
_LIT8(KSender,                  "Sender");      // The message was incorrectly formed or did not
                                                // contain the appropriate information in order to
                                                // succeed. For example, the message could lack the
                                                // proper authentication or payment information. It
                                                // is generally an indication that the message is
                                                // not to be resent without change.

_LIT8(KVersionMismatch,         "VersionMismatch");
                                                // The faulting node found an invalid element
                                                // information item instead of the expected
                                                // Envelope element information item. The namespace,
                                                // local name or both did not match the Envelope
                                                // element information item required by this
                                                // recommendation.

enum TSOAPVersion
        {
        ESOAP11 = 1,
        ESOAP12
        };

#endif // SEN_SOAP_CONSTANTS_H




