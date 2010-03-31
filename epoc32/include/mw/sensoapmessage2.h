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
* Description:        CSenSoapMessage is an utility class offering capability to
*                parse XML SOAP envelope and manipulation methods to alter its
*                contents.
*
*/








#ifndef SEN_SOAP_MESSAGE2_H
#define SEN_SOAP_MESSAGE2_H

//  INCLUDES
#include <SenWsSecurityHeader2.h>
#include <SenSoapEnvelope2.h>

class MSenMessageContext;

// CLASS DECLARATION

/**
* CSenSoapMessage extends basic SOAP envelope functionality by
* offering methods to set the security header and security token.
* @lib SenUtils.lib
* @since Series60 4.0
*/
class CSenSoapMessage2 : public CSenSoapEnvelope2
    {
    public:  // Constructors and destructor

        /**
        * Two-phase constructor.
        */
        IMPORT_C static CSenSoapMessage2* NewL();

        /**
        * Two-phase constructor.
        */
        IMPORT_C static CSenSoapMessage2* NewLC();

        /**
        * Two-phase constructor.
        */
	    IMPORT_C static CSenSoapMessage2* NewL(TSOAPVersion aVersion);

        /**
        * Two-phase constructor.
        */
	    IMPORT_C static CSenSoapMessage2* NewLC(TSOAPVersion aVersion);

        /**
        * Two-phase constructor.
        */
        IMPORT_C static CSenSoapMessage2* NewL(TSOAPVersion aVersion, const TDesC8& aSecurityNs);

        /**
        * Two-phase constructor.
        */
        IMPORT_C static CSenSoapMessage2* NewLC(TSOAPVersion aVersion, const TDesC8& aSecurityNs);

        /**
        * Two-phase constructor.
        */
        IMPORT_C static CSenSoapMessage2* NewL(MSenMessageContext& aContext);

        /**
        * Two-phase constructor.
        */
        IMPORT_C static CSenSoapMessage2* NewLC(MSenMessageContext& aContext);

        /**
        * Two-phase constructor.
        */
	    IMPORT_C static CSenSoapMessage2* NewL(MSenMessageContext& aContext,
	                                           TSOAPVersion aVersion);

        /**
        * Two-phase constructor.
        */
	    IMPORT_C static CSenSoapMessage2* NewLC(MSenMessageContext& aContext,
	                                            TSOAPVersion aVersion);

        /**
        * Two-phase constructor.
        */
        IMPORT_C static CSenSoapMessage2* NewL(MSenMessageContext& aContext,
                                               TSOAPVersion aVersion,
                                               const TDesC8& aSecurityNs);

        /**
        * Two-phase constructor.
        */
        IMPORT_C static CSenSoapMessage2* NewLC(MSenMessageContext& aContext,
                                                TSOAPVersion aVersion,
                                                const TDesC8& aSecurityNs);

        /**
        * Two-phased copy constructor.
        */
        IMPORT_C static CSenSoapMessage2* NewL(CSenSoapMessage2& aMessage);

        /**
        * Two-phased copy constructor.
        */
        IMPORT_C static CSenSoapMessage2* NewLC(CSenSoapMessage2& aMessage);

        /**
        * Destructor.
        */
        IMPORT_C virtual ~CSenSoapMessage2();

        // New functions

        /**
        * Sets a new security header for the soap message. If existant, the
        * old security header is deleted and new one with given data is added.
        * @since Series60 4.0
        * @param    aData   Data to be used in the security header.
        */
        IMPORT_C void SetSecurityHeaderL(const TDesC8& aData);

        /**
        * Adds new token (content) to current security header,
        * appending to existing. The token is appended after the
        * current content of security token. Method instantiates
        * and adds default security header (without data), if
        * such was not set in beforehand.
        * @since Series60 4.0
        * @param    aNewToken   Token to be inserted.
        * @return   KErrNone or some system-wide Symbian error codes.
        */
        IMPORT_C TInt AddSecurityTokenL(const TDesC8& aNewToken);
        
    public: // From MSenMessage
        IMPORT_C virtual TClass Type();
        IMPORT_C virtual MSenMessage* CloneL();

    protected:

        /**
         *  C++ default constructor.
         */
        IMPORT_C CSenSoapMessage2::CSenSoapMessage2();

        // New functions

        /**
        * Helper function to make a new security header.
        * @since Series60 4.0
        * @param    aData   Default=NULL. Data to be set in the security header.
        * @return   new security header, which is located in the cleanup stack.
        *           Caller takes ownership.
        */
        IMPORT_C virtual CSenWsSecurityHeader2* NewSecurityHeaderLC(
                                                    const TDesC8* aData,
                                                    RSenDocument aDocument,
                                                    TXmlEngElement element);

        // Functions from base classes

        // From CSenSoapEnvelope
        IMPORT_C virtual void ParseHeaderL(const RTagInfo& aElement,
                                           const RAttributeArray& aAttributes);

        /**
        * This method should be called from the deriving classes ConstructL() methods.
        * @since Series60 4.0
        */
        IMPORT_C void BaseConstructL();

		/**
		* This method should be called from the deriving classes ConstructL() methods.
	    * @since Series60 4.0
		*/
	    IMPORT_C void BaseConstructL(TSOAPVersion aVersion);
	    
		/**
		* This method should be called from the deriving classes ConstructL() methods.
	    * @since Series60 4.0
		*/
        IMPORT_C void BaseConstructL(TSOAPVersion aVersion, const TDesC8& aSecurityNs);	    

        /**
        * This method should be called from the deriving classes ConstructL() methods.
        * @since Series60 4.0
        */
        IMPORT_C void BaseConstructL(MSenMessageContext& aContext);

		/**
		* This method should be called from the deriving classes ConstructL() methods.
	    * @since Series60 4.0
		*/
	    IMPORT_C void BaseConstructL(MSenMessageContext& aContext,
	                                 TSOAPVersion aVersion);
	    
		/**
		* This method should be called from the deriving classes ConstructL() methods.
	    * @since Series60 4.0
		*/
        IMPORT_C void BaseConstructL(MSenMessageContext& aContext,
                                     TSOAPVersion aVersion,
                                     const TDesC8& aSecurityNs);	    

        /**
        * This method should be called from the deriving
        * classes ConstructL() methods.
        * @since Series60 4.0
        */
        IMPORT_C void BaseConstructL(CSenSoapMessage2& aMessage);

    protected: // Data
        // Owned, but element not owned
        CSenWsSecurityHeader2* ipSecurityHeader;
    };

#endif // SEN_SOAP_MESSAGE_H

// End of File


