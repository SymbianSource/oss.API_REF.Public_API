/*
* Copyright (c) 2005 Nokia Corporation and/or its subsidiary(-ies). 
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
* Description: Http transport properties class declaration     
*
*/

#ifndef SEN_HTTP_TRANSPORT_PROPERTIES_H
#define SEN_HTTP_TRANSPORT_PROPERTIES_H

// INCLUDE
#include <SenTransportProperties.h>

// CONSTANTS
_LIT8(KSenHttpAcceptHeaderDelimiter, ",");

// Supported Http properties:

//// -- session properties:
_LIT8(KHttpMethodLocalName,     "HttpMethod");
_LIT8(KHttpVersionLocalName,    "HttpVersion");

//// -- HTTP headers names:
_LIT8(KContentTypeLocalName,    "Content-Type");
_LIT8(KAcceptLocalName,         "Accept");
_LIT8(KSlugLocalName,           "Slug");

// Supported Http methods:
_LIT8(KHttpGet,                 "Get");
_LIT8(KHttpPost,                "Post");
_LIT8(KHttpPut,                 "Put");
_LIT8(KHttpDelete,              "Delete");

// Supported Http versions:
_LIT8(KHttp10,                  "Http1.0");
_LIT8(KHttp11,                  "Http1.1");

//NOTE:
/**	In SendL(CSenSoapEnvelope& aMessage, const TDesC8& aProperties)
 *	or
 *	SubmitL(CSenSoapEnvelope& aMessage, const TDesC8& aProperties, HBufc8*& aResponseTO)  
 *	aProperties could be "HTTP GET" or "HTTP DELETE"
 *  aMessage is a soap message or serialized XML.
 *	This scenario is not supported. 
 *
 *	These are the function calls get called during this scenario
 *	iHttpProperties->SetHttpHeaderL(const TDesC8& aHeaderName, const TDesC8& aValue);
 *	iHttpProperties->SetHttpMethodL(CSenHttpTransportProperties::ESenHttpGet);
 *	SendL(CSenSoapEnvelope& aMessage, const TDesC8& aProperties);
**/

// CLASS DECLARATION
class CSenHttpTransportProperties : public CSenTransportProperties
    {
    public:
		/**
		 * HttpMethod Enumeration
		 */    		
        enum TSenHttpMethod
        	{
        	ESenHttpPut,
        	ESenHttpDelete,
        	ESenHttpGet,
            ESenHttpPost        	
            };
		/**
		 * HttpVersion Enumeration
		 */    		            
        enum TSenHttpVersion
        	{
        	ESenHttp10,
        	ESenHttp11
            };            
        /**
        * Basic constructor.
        * @return a pointer to new CSenHttpTransportProperties class instance.
        */
        IMPORT_C static CSenHttpTransportProperties* NewL();
        /**
        * Basic constructor.
        * @return a pointer to new CSenHttpTransportProperties class instance.
        */
        IMPORT_C static CSenHttpTransportProperties* NewLC();

        /**
        * Basic constructor.
		* @param aXmlUtf8 
    	* @param aParser It is a XML reader        
        * @return a pointer to new CSenHttpTransportProperties class instance.
        */
        IMPORT_C static CSenHttpTransportProperties* NewL(const TDesC8& aXmlUtf8,
                                                          CSenXmlReader& aParser);

        /**
        * Basic constructor.
		* @param aXmlUtf8 
    	* @param aParser It is a XML reader        
        * @return a pointer to new CSenHttpTransportProperties class instance.
        */
        IMPORT_C static CSenHttpTransportProperties* NewLC(const TDesC8& aXmlUtf8,
                                                           CSenXmlReader& aParser);

        /**
        * Basic constructor.
		* @param aElement
        * @return a pointer to new CSenHttpTransportProperties class instance.
        */
        IMPORT_C static CSenHttpTransportProperties* NewL(const CSenElement& aElement);
        /**
        * Basic constructor.
		* @param aElement 
        * @return a pointer to new CSenHttpTransportProperties class instance.
        */
        IMPORT_C static CSenHttpTransportProperties* NewLC(const CSenElement& aElement);
         
        /**
        * Gets the IAP ID.
        * @param aCurrentIapId  A TUint32 reference to be filled in with the
        *                       value of the IAP ID.
        * @return               KErrNone if no error, or some of the system
        *                       wide error codes.
        */
        virtual TInt IapIdL(TUint32& aCurrentIapId);

        /**
        * Sets the IAP ID.
        * @param aIapId is the new IAP ID.
        */
        virtual void SetIapIdL(TUint32 aIapId);

        /**
        * Gets the Proxy Port.
        * @param aProxyPort  A TInt reference to be filled in with the
        *                    value of the Proxy Port.
        * @return            KErrNone if no error, or some of the system
        *                    wide error codes.
        */
        virtual TInt ProxyPortL(TInt& aProxyPort);

        /**
        * Sets the Proxy Port.
        * @param aProxyPort is the new Proxy Port.
        */
        virtual void SetProxyPortL(TInt aProxyPort);

        /**
        * Gets the Proxy Host.
        * @param aProxyHost  A TPtrC8 reference to be filled in with the
        *                    value of the Proxy Host.
        * @return            KErrNone if no error, or some of the system
        *                    wide error codes.
        */
        virtual TInt ProxyHostL(TPtrC8& aProxyHost);

        /**
        * Sets the Proxy Host.
        * @param aProxyHost is the new Proxy Host.
        */
        virtual void SetProxyHostL(const TDesC8& aProxyHost);
        
        /**
        * Gets the Proxy Usage flag.
        * @param aProxyUsage A TBool reference to be filled in with the
        *                    value of the Proxy Usage.
        * @return            KErrNone if no error, or some of the system
        *                    wide error codes.
        */
        virtual TInt ProxyUsageL(TBool& aProxyUsage);

        /**
        * Sets the Proxy Usage flag.
        * @param aProxyUsage is the new value for Proxy Usage.
        */
        virtual void SetProxyUsageL(TBool aProxyUsage);

        /**
        * Gets the information if SecureDialog is shown or not.
        * @param aProxyUsage A TBool reference to be filled in with the
        *                    value of the SecureDialog flag.
        * @return            KErrNone if no error, or some of the system
        *                    wide error codes.
        */
        virtual TInt SecureDialogL(TBool& aSecureDialog);

        /**
        * Sets the flag which controls showing of SecureDialog.
        * @param aSecureDialog is the new value for SecureDialog flag.
        */
        virtual void SetSecureDialogL(TBool aSecureDialog);
        
        /**
        * Gets the information if IAPDialog is shown or not.
        * @param aIAPDialog A TBool reference to be filled in with the
        *                   value of the IAPDialog flag.
        * @return           KErrNone if no error, or some of the system
        *                   wide error codes.
        */
//        virtual TInt IAPDialogL(TBool& aIAPDialog);

        /**
        * Sets the flag which controls showing of IAPDialog.
        * @param aIAPDialog is the new value for IAPDialog flag.
        */
//        virtual void SetIAPDialogL(TBool aIAPDialog);

        /**
        * Gets the Content Type.
        * @param aContentType A TPtrC8 reference to be filled in with the
        *                     value of the Content Type.
        * @return             KErrNone if no error, or some of the system
        *                     wide error codes.
        */
        virtual TInt ContentTypeL(TPtrC8& aContentType);
        
        /**
        * Sets the Content Type.
        * @param aContentType is the new Content Type.
        */
        virtual void SetContentTypeL(const TDesC8& aContentType);
        
        /**
        * Gets the SoapAction.
        * @param aSoapAction A TPtrC8 reference to be filled in with the
        *                    value of the SoapAction.
        * @return            KErrNone if no error, or some of the system
        *                    wide error codes.
        */
        virtual TInt SoapActionL(TPtrC8& aSoapAction);
        
        /**
        * Sets the Soap Action.
        * @param aSoapAction is the new Soap Action.
        */
        virtual void SetSoapActionL(const TDesC8& aSoapAction);
        
        /**
        * Gets the UserAgent.
        * @param aUserAgent  A TPtrC8 reference to be filled in with the
        *                    value of the UserAgent.
        * @return            KErrNone if no error, or some of the system
        *                    wide error codes.
        */
        virtual TInt UserAgentL(TPtrC8& aUserAgent);
        
        /**
        * Sets the UserAgent.
        * @param aUserAgent is the new User Agent.
        */
        virtual void SetUserAgentL(const TDesC8& aUserAgent);

        /**
        * Gets the Accept.
        * @param aAccept     A TPtrC8 reference to be filled in with the
        *                    value of the Accept.
        * @return            KErrNone if no error, or some of the system
        *                    wide error codes.
        */
        virtual TInt AcceptL(TPtrC8& aAccept);
        
        /**
        * Sets the Accept.
        * @param aAccept is the new Accept value.
        */
        virtual void SetAcceptL(const TDesC8& aAccept);
        
        /**
        * Gets the Http method.
        * @param aHttpMethod A TSenHttpMethod reference to be filled in with
        *                    the value of the Http method.
        * @return            KErrNone if no error, or some of the system
        *                    wide error codes.
        */
        virtual TInt HttpMethodL(TSenHttpMethod& aHttpMethod);
        
        /**
        * Sets the Http method.
        * @param aHttpMethod is the new Http method.
        */
        virtual void SetHttpMethodL(TSenHttpMethod aHttpMethod);

        /**
        * Gets the Http version.
        * @param aHttpVersion A TSenHttpVersion reference to be filled in with
        *                     the value of the Http version.
        * @return             KErrNone if no error, or some of the system
        *                     wide error codes.
        */
        virtual TInt HttpVersionL(TSenHttpVersion& aHttpVersion);
        
        /**
        * Sets the Http version.
        * @param aHttpVersion is the new Http version.
        */
        virtual void SetHttpVersionL(TSenHttpVersion aHttpVersion);        

        /**
        * Gets the Http header.
        * @param aHeaderName  Name of the Http header.
        * @param aValue       A TPtrC8 reference to be filled in with the
        *                     value of the Http header.
        * @return             KErrNone if no error, or some of the system
        *                     wide error codes.
        */
        virtual TInt HttpHeaderL(const TDesC8& aHeaderName, TPtrC8& aValue);
        
        /**
        * Sets the Http header.
        * @param aHeaderName  Name of the Http header.
        * @param aValue       Value of the Http header
        */
        virtual void SetHttpHeaderL(const TDesC8& aHeaderName,
                                    const TDesC8& aValue);


        /**
        * Gets the device ID
        * @param aDeviceID  A TPtrC8 reference to be filled in with the
        *                    value of the Device ID.
        * @return            KErrNone if no error, or some of the system
        *                    wide error codes.
        */
        virtual TInt DeviceIDL(TPtrC8& aDeviceID);

        /**
        * Sets the Device ID.
        * @param aDeviceID is the new Device ID.
        */
        virtual void SetDeviceIDL(const TDesC8& aDeviceID);

        /**
        * Gets download folder for incoming BLOB (binary large objects)
        * @param aDownloadFolder - A TPtrC8 reference to be filled in with the
        *                    value of the shared, public folder for downloaded 
        *                    content
        * @return            KErrNone if no error, or some of the system
        *                    wide error codes.
        */
        virtual TInt DownloadFolderL(TPtrC8& aDownloadFolder);
        
        /**
        * Sets download folder for incoming BLOB (binary large objects)
        * @param aDownloadFolder - shared, public folder for downloaded content
        */
        virtual void SetDownloadFolderL(const TDesC8& aDownloadFolder);
             
        /**
        * Gets filename of file attachment
        * @param aCid - cid for filename
        * @param aFileName - filename of file attachment with current cid
        * @return            KErrNone if no error, or some of the system
        *                    wide error codes.
        */
        virtual TInt FileAttachmentL(const TDesC8& aCid, HBufC8*& aFileName);
        
        /**
        * Sets filename of file attachment
        * @param aCid - cid for filename
        * @param aFileName - filename of file attachment with current cid
        * @return            KErrNone if no error, or some of the system
        *                    wide error codes.
        */
        virtual TInt SetFileAttachmentL(const TDesC8& aCid, const TDesC8& aFileName);

        /**
        * Apply binding.
        * @param aSoapVersion is a soap1.2 or soap1.1.
        */
        virtual void ApplyBindingL(TSOAPVersion aSoapVersion);

        /**
        * Gets namespace of Microsoft schema
        * @param aMwsNamespace - namespace 
        * @return            KErrNone if no error, or some of the system
        *                    wide error codes.
        */
        virtual TInt MwsNamespaceL(TPtrC8& aMwsNamespace);
        
        /**
        * Sets namespace of Microsoft schema
        * @param aMwsNamespace - namespace
        * @return            KErrNone if no error, or some of the system
        *                    wide error codes.
        */
        virtual void SetMwsNamespaceL(const TDesC8& aMwsNamespace);

        // From MSenProperties
        virtual void SetReader(CSenXmlReader& aReader);
        virtual TSenPropertiesClassType PropertiesClassType();
        virtual void WriteToL(RWriteStream& aWriteStream);
        virtual void ReadFromL(const TDesC8& aBuffer);
        virtual HBufC8* AsUtf8L();
        virtual HBufC8* AsUtf8LC();
        virtual TBool IsSafeToCast(TSenPropertiesClassType aClass);
        virtual MSenProperties* CloneL() const;
        
        virtual TInt SetPropertyL(const TDesC8& aName, const TDesC8& aValue);
        virtual TInt PropertyL(const TDesC8& aName, TPtrC8& aValue);        
        virtual TInt SetPropertyL(const TDesC8& aName, const TDesC8& aValue, const TDesC8& aType);
        virtual TInt PropertyL(const TDesC8& aName, TPtrC8& aValue, TPtrC8& aType);
        virtual TInt SetIntPropertyL(const TDesC8& aName, const TInt aValue);
        virtual TInt IntPropertyL(const TDesC8& aName, TInt& aValue);
        virtual TInt SetBoolPropertyL(const TDesC8& aName, const TBool aValue);        
        virtual TInt BoolPropertyL(const TDesC8& aName, TBool& aValue);
        virtual TInt SetOmittedL(const TDesC8& aName, TBool aValue);
        virtual TInt RemovePropertyL(const TDesC8& aName);

       /**
        * Destructor.
        */
        virtual ~CSenHttpTransportProperties();

    protected: // base class functions

        virtual void BaseConstructL(const TDesC8& aLocalname, 
                                    const TDesC8& aXml,
                                    CSenXmlReader* aParser = NULL);

        virtual void BaseConstructL(const TDesC8& aNamespace, 
                                    const TDesC8& aLocalname, 
                                    const TDesC8& aXml,
                                    CSenXmlReader* aParser = NULL);

        virtual void BaseConstructL(const TDesC8& aNamespace, 
                                    const TDesC8& aLocalname, 
                                    const TDesC8& aQualifiedName, 
                                    const TDesC8& aXml,
                                    CSenXmlReader* aParser = NULL);

        virtual void BaseConstructL(const CSenElement& aElement);

	public:
        /**
        * Sets the SNAP ID.
        * @param aSnapId is the new SNAP ID.
        */
		virtual void SetSnapIdL(TUint32 aSnapId);

        /**
        * Gets the SNAP ID.
        * @param aCurrentSnapId  A TUint32 reference to be filled in with the
        *                       value of the SNAP ID.
        * @return               KErrNone if no error, or some of the system
        *                       wide error codes.
        */
        virtual TInt SnapIdL(TUint32& aCurrentSnapId);
    protected:
        /**
        * Constructor.
        */
        CSenHttpTransportProperties();
    private:
        HBufC8* AdaptDblQutesLC(const TDesC8& aValue);
    };

#endif // SEN_HTTP_TRANSPORT_PROPERTIES_H
