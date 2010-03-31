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
* Description:        This utility class represents SOAP fault element according to
*                SOAP fault specification. 
*
*/








#ifndef SEN_SOAP_FAULT_H
#define SEN_SOAP_FAULT_H

//  INCLUDES
#include <SenDomFragmentBase.h>
#include <SenSoapConstants.h>

// CLASS DECLARATION

/**
* This utility class represents SOAP fault element according to SOAP fault 
* specification. 
* SOAP fault element has following child elements: 
*  faultcode, 
*  faultstring, 
*  faultactor 
*  detail
*
*  @lib SenUtils.lib
*  @since Series60 3.0
*/
class CSenSoapFault2 : public CSenDomFragmentBase
    {
    public:  // Constructors and destructor
        
        /**
        * Copy constructor, making a copy of the original source element.
        * @since Series60 3.0
        * @param aElement   Element which is copied into SoapFault.
        */
        IMPORT_C static CSenSoapFault2* NewL(TXmlEngElement& aElement);

        /**
        * Constructor which, takes
        * 1) TXmlEngElement which is already owned by other Fragment and
        * 2) RSenDocument which is owned by that same other Fragment.
        * Constructor takes a copy of RSenDocument => given element
        * will be destructed when both original Fragment and
        * CSenSoapFault2 have been destructed. Given element will
        * be root element of CSenSoapFault2.
        *
        * @since Series60 3.0
        * @param aElement   Soap Fault element.
        * @param aDocument  Original document holding given Soap Fault
        *                   element.
        */
        IMPORT_C static CSenSoapFault2* NewL(TXmlEngElement& aElement,
                                             RSenDocument& aDocument);

        /**
        * Basic constructor.
        * @since Series60 3.0
        * @param aNsUri is the XML namespace of this SOAP fault
        * @param aLocalName is the localname for this SOAP fault
        * @param aQName is the qualifiedname for this SOAP fault
        * @param aAttributes are the XML attributes for this SOAP fault
        * Parameters are used to construct the soap fault.
        */
        IMPORT_C static CSenSoapFault2* NewL(const TDesC8& aNsUri,
                                            const TDesC8& aLocalName,
                                            const TDesC8& aPrefix,
                                            const RAttributeArray& aAttributes,
                                            TXmlEngElement& aElement,
                                            RSenDocument& aDocument);
            
        /**
        * Destructor.
        */
        IMPORT_C virtual ~CSenSoapFault2();

        // New functions
        
        /**
        * @since Series60 3.0
        * @return the content of <faultcode> element as UTF-8 form string
        * or KNullDesC8, if element is not available
        */
        IMPORT_C TPtrC8 FaultCode();

		/**
		* @since Series60 4.0
		* @return the content of <Subcode> element as UTF-8 form string
		* or KNullDesC8, if element is not available
		*/
		IMPORT_C TPtrC8 FaultSubcode();

		/**
        * @since Series60 3.0
        * @return the content of <faultstring> element as UTF-8 form string
        * or KNullDesC8, if element is not available
        */
        IMPORT_C TPtrC8 FaultString();

        /**
        * @since Series60 3.0
        * @return the content of <faultactor> element as UTF-8 form string
        * or KNullDesC8, if element is not available
        */
        IMPORT_C TPtrC8 FaultActor();

        /**
        * @since Series60 3.0
        * @return the content of <detail> element as UTF-8 form string
        * or KNullDesC8, if element is not available
        */
        IMPORT_C TPtrC8 Detail();
        
    protected:  
        
        /**
        * C++ default constructor
        */
        IMPORT_C CSenSoapFault2();
        
        /**
        * Basic ConstructL function
        * @since Series60 3.0
        * @param aElement is the TXmlEngElement from which data to this
        *                 SOAP fault object is to be copied.
        */
        IMPORT_C void ConstructL(TXmlEngElement& aElement);

        /**
        * ConstructL method which takes
        * 1) TXmlEngElement which is already owned by other Fragment and
        * 2) RSenDocument which is owned by that same other Fragment.
        * Constructor takes a copy of RSenDocument => given element
        * will be destructed when both original Fragment and
        * CSenSoapFault2 have been destructed. Given element will
        * be root element of CSenSoapFault2.
        *
        * @since Series60 3.0
        * @param aElement   Soap Fault element.
        * @param aDocument  Original document holding given Soap Fault
        *                   element.
        */
        IMPORT_C void ConstructL(TXmlEngElement& aElement, RSenDocument& aDocument);

        /**
        * Basic ConstructL function
        * @since Series60 3.0
        * @param aNsUri is the XML namespace URI of this SOAP fault
        * @param aLocalName is the XML localname URI of this SOAP fault
        * @param aQName is the XML qualifiedname URI of this SOAP fault
        * @param aAttributes are the XML attributes for this SOAP fault
        */
        IMPORT_C void ConstructL(const TDesC8& aNsUri,
                                 const TDesC8& aLocalName,
                                 const TDesC8& aPrefix,
                                 const RAttributeArray& aAttributes,
                                 TXmlEngElement& aElement,
                                 RSenDocument& aDocument);
    };

#endif // SEN_SOAP_ENVELOPE_H

// End of File
