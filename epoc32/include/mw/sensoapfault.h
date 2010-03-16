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
* Description:        This utility class represents SOAP fault element according to
*                SOAP fault specification. 
*
*/








#ifndef SEN_SOAP_FAULT_H
#define SEN_SOAP_FAULT_H

//  INCLUDES
#include <SenBaseElement.h>
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
class CSenSoapFault : public CSenBaseElement
    {
    public:  // Constructors and destructor
        
        /**
        * Copy constructor, making a copy of the original source element.
        * @since Series60 3.0
        * @param aCopiedSource  Element where source will be copied.
        */
        IMPORT_C static CSenSoapFault* NewL(CSenElement& aCopiedSource);

        /**
        * Basic constructor.
        * @since Series60 3.0
        * @param aNsUri is the XML namespace of this SOAP fault
        * @param aLocalName is the localname for this SOAP fault
        * @param aQName is the qualifiedname for this SOAP fault
        * @param aAttributes are the XML attributes for this SOAP fault
        * Parameters are used to construct the soap fault.
        */
        IMPORT_C static CSenSoapFault* NewL(const TDesC8& aNsUri,
                                            const TDesC8& aLocalName,
                                            const TDesC8& aQName,
                                            const RAttributeArray& aAttributes);
            
        /**
        * Destructor.
        */
        IMPORT_C virtual ~CSenSoapFault();

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
        IMPORT_C CSenSoapFault();
        
        /**
        * Basic ConstructL function
        * @since Series60 3.0
        * @param aCopiedSource is the CSenElement from which data to this
        *        SOAP fault object is to be copied.
        */
        IMPORT_C void ConstructL(CSenElement& aCopiedSource);

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
                                 const TDesC8& aQName,
                                 const RAttributeArray& aAttributes);
    };

#endif // SEN_SOAP_ENVELOPE_H

// End of File
