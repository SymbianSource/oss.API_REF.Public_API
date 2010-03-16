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
* Description:  Transport properties class declaration     
*
*/

#ifndef SEN_TRANSPORT_PROPERTIES_H
#define SEN_TRANSPORT_PROPERTIES_H

#include <SenXmlProperties.h>
#include <SenSoapEnvelope.h>

// CONSTANTS
_LIT8( KIapIdLocalName,              "IapId"            );
_LIT8( KSnapIdLocalName,              "SnapId"            );
_LIT8( KProxyHostLocalName,          "ProxyHost"        );
_LIT8( KProxyPortLocalName,          "ProxyPort"        );
_LIT8( KProxyUsageLocalName,         "ProxyUsage"       );
_LIT8( KSecureDialogLocalName,       "SecureDialog"     );
_LIT8( KDeviceIDLocalName,           "DeviceID"         );
_LIT8( KSoapActionLocalName,         "SOAPAction"       );
_LIT8( KUserAgentLocalName,          "User-Agent"       );
_LIT8( KDownloadFolderLocalName,     "DownloadFolder"   );
_LIT8( KFileAttachmentsLocalName,    "FileAttachments"  );
_LIT8( KMwsNamespaceLocalName,       "MwsNamespace"     );
_LIT8( KSenClientGeneratedMessageId, "MessageID"        );
_LIT8( KSenOnewayMessageOnOff,       "OneWayMessage"    );

_LIT8( KSenConnectionHeartbeat,      "Heartbeat"        );
_LIT8( KSenConnectionHeartbeatMaxTTL,"MaxTTL"           );
_LIT8( KSenConnectionHeartbeatMinTTL,"MinTTL"           );
_LIT8( KSenEndpointResource,         "EndpointResource" );

_LIT8( KNCIMConsumerKeyId,      "ConsumerKeyId"         );
_LIT8( KNCIMConsumerSecret,     "ConsumerSecret"        );
_LIT8( KNCIMConsumerServiceId,  "ConsumerServiceId"     );
_LIT8( KNCIMEndpoint,				"NCIMEndpoint"     );
_LIT8( KNCIMCountry,				"mcc"     );


/*
* Use Bool property to hold value. You can use convenient methods SetBoolPropertyL/BoolPropertyL.
* Value ETrue  - means NO dialog. If any problem occurs, then just an error is returned to the application. 
* Value EFalse - system IAP dialog is shown if any problem occurs
*/
_LIT8( KSenIAPDoNotPrompt,           "IAPDoNotPrompt"   );
_LIT8( KSenSNAPDoNotPrompt,           "SNAPDoNotPrompt"   );

// Property type attribute's name for HTTP headers:
_LIT8( KHttpHeaderType,              "HttpHeader"       );
_LIT8( KAttachmentFileType,          "FileAttachment"   );

class CSenTransportProperties : public CSenXmlProperties
    {
    public:
        /**
        * Basic constructor.
        * @return a pointer to new CSenTransportProperties class instance.
        */
        IMPORT_C static CSenTransportProperties* NewL();
        /**
        * Basic constructor.
        * @return a pointer to new CSenTransportProperties class instance.
        */
        IMPORT_C static CSenTransportProperties* NewLC();

        /**
        * Basic constructor.
		* @param aXmlUtf8 
    	* @param aParser It is a XML reader        
        * @return a pointer to new CSenTransportProperties class instance.
        */
        IMPORT_C static CSenTransportProperties* NewL(const TDesC8& aXmlUtf8,
                                                          CSenXmlReader& aParser);
        /**
        * Basic constructor.
		* @param aXmlUtf8 
    	* @param aParser It is a XML reader        
        * @return a pointer to new CSenTransportProperties class instance.
        */
        IMPORT_C static CSenTransportProperties* NewLC(const TDesC8& aXmlUtf8,
                                                           CSenXmlReader& aParser);

        /**
        * Basic constructor.
		* @param aElement
        * @return a pointer to new CSenTransportProperties class instance.
        */
        IMPORT_C static CSenTransportProperties* NewL(const CSenElement& aElement);
        /**
        * Basic constructor.
		* @param aElement
        * @return a pointer to new CSenTransportProperties class instance.
        */
        IMPORT_C static CSenTransportProperties* NewLC(const CSenElement& aElement);
    
        // From MSenProperties
        IMPORT_C virtual void SetReader(CSenXmlReader& aReader);
        IMPORT_C virtual TSenPropertiesClassType PropertiesClassType();
        IMPORT_C virtual void WriteToL(RWriteStream& aWriteStream);
        IMPORT_C virtual void ReadFromL(const TDesC8& aBuffer);
        IMPORT_C virtual HBufC8* AsUtf8L();
        IMPORT_C virtual HBufC8* AsUtf8LC();
        IMPORT_C virtual TInt SetPropertyL(const TDesC8& aName,
                                           const TDesC8& aValue);
        IMPORT_C virtual TInt PropertyL(const TDesC8& aName, TPtrC8& aValue);
        IMPORT_C virtual TInt SetIntPropertyL(const TDesC8& aName,
                                              const TInt aValue);
        IMPORT_C virtual TInt IntPropertyL(const TDesC8& aName,
                                           TInt& aValue);
        IMPORT_C virtual TInt SetBoolPropertyL(const TDesC8& aName,
                                               const TBool aValue);        
        IMPORT_C virtual TInt BoolPropertyL(const TDesC8& aName,
                                                TBool& aValue);
        IMPORT_C virtual TInt SetOmittedL(const TDesC8& aName, TBool aValue);
        IMPORT_C virtual TInt RemovePropertyL(const TDesC8& aName);
        IMPORT_C virtual TBool IsSafeToCast(TSenPropertiesClassType aClass);
        IMPORT_C virtual MSenProperties* CloneL() const;
        IMPORT_C virtual MSenProperties* Clone(TInt& aOkOrError) const;

       /**
        * Destructor.
        */
        IMPORT_C virtual ~CSenTransportProperties();
        
        IMPORT_C virtual TInt SetPropertyL(const TDesC8& aName,
                                           const TDesC8& aValue,
                                           const TDesC8& aType);

        IMPORT_C virtual TInt PropertyL(const TDesC8& aName,
                                        TPtrC8& aValue,
                                        TPtrC8& aType);
                                        
        /**
        * Gets the (connection) heartbeat property value as int.
        * @param aDelta     A TInt reference to be filled in with the
        *                       value of the heartbeat (in seconds).
        *                       Positive value means that a heartbeat
        *                       messages are sent to backend, keeping
        *                       the socket connection open (longlived
        *                       connection). Keeping heartbeat may be
        *                       costy, but increases performance in
        *                       scenarios, where multiple network
        *                       transactions take place within short
        *                       period (time window).
        * @return             KErrNone if no error, or some of the system
        *                       wide error codes.
        *                     KErrNotFound if shortlive connection defined
        */
        IMPORT_C virtual TInt HeartbeatL(TInt& aDelta);

        /**
        * Sets the (connection) heartbeat property value as int.
        * Note, that with some transports, like vTCP, the heartbeat
        * can also be used to control connection modes (longlive
        * vs. shortlive connection). 
        * Hertbeat value is called also as delta.
        * 
        * Together with delta You can also set parameters Min & Max TTL
        * Long and short connection is set in different way, below guider.
        *
        * To setup longlive connection:
        *   delta   : user defined
        *   min TTL : If not specified then the default value of 90 sec will be used
        *   max TTL : If not specified then the default value 1800 sec will be used
        *
        * To setup shortlive connection:
        *   delta   : -1
        *   min TTL : If not specified then the default value of 90 sec will be used
        *   max TTL : ignored
        *
        * So, providing a negative value
        * (-1) can be utilized to disable heartbeat and to switch
        * the connection mode to a short lived state. With vTCP
        * transport, if heartbeat of -1 is set, the socket will be
        * kept open only for effective timeout value (shortlived), 
        * 
        * @param aDelta    TInt reference to be filled in with 
        *                      the value of the heartbeat (in seconds)
        * @return              KErrNone if no error, or some of the system
        *                      wide error codes.
        */
        IMPORT_C virtual TInt SetHeartbeatL(TInt aDelta);
        
        /**
        * Gets the IAP ID.
        * @param aCurrentIapId  A TUint32 reference to be filled in with the
        *                       value of the IAP ID.
        * @return               KErrNone if no error, or some of the system
        *                       wide error codes.
        */
        IMPORT_C virtual TInt IapIdL(TUint32& aCurrentIapId);

        /**
        * Sets the IAP ID.
        * @param aIapId is the new IAP ID.
        */
        IMPORT_C virtual void SetIapIdL(TUint32 aIapId);

        /**
        * Gets the Proxy Port.
        * @param aProxyPort  A TInt reference to be filled in with the
        *                    value of the Proxy Port.
        * @return            KErrNone if no error, or some of the system
        *                    wide error codes.
        */
        IMPORT_C virtual TInt ProxyPortL(TInt& aProxyPort);

        /**
        * Sets the Proxy Port.
        * @param aProxyPort is the new Proxy Port.
        */
        IMPORT_C virtual void SetProxyPortL(TInt aProxyPort);

        /**
        * Gets the Proxy Host.
        * @param aProxyHost  A TPtrC8 reference to be filled in with the
        *                    value of the Proxy Host.
        * @return            KErrNone if no error, or some of the system
        *                    wide error codes.
        */
        IMPORT_C virtual TInt ProxyHostL(TPtrC8& aProxyHost);

        /**
        * Sets the Proxy Host.
        * @param aProxyHost is the new Proxy Host.
        */
        IMPORT_C virtual void SetProxyHostL(const TDesC8& aProxyHost);
        
        /**
        * Gets the Proxy Usage flag.
        * @param aProxyUsage A TBool reference to be filled in with the
        *                    value of the Proxy Usage.
        * @return            KErrNone if no error, or some of the system
        *                    wide error codes.
        */
        IMPORT_C virtual TInt ProxyUsageL(TBool& aProxyUsage);

        /**
        * Sets the Proxy Usage flag.
        * @param aProxyUsage is the new value for Proxy Usage.
        */
        IMPORT_C virtual void SetProxyUsageL(TBool aProxyUsage);

        /**
        * Gets the information if SecureDialog is shown or not.
        * @param aProxyUsage A TBool reference to be filled in with the
        *                    value of the SecureDialog flag.
        * @return            KErrNone if no error, or some of the system
        *                    wide error codes.
        */
        IMPORT_C virtual TInt SecureDialogL(TBool& aSecureDialog);

        /**
        * Sets the flag which controls showing of SecureDialog.
        * @param aSecureDialog is the new value for SecureDialog flag.
        */
        IMPORT_C virtual void SetSecureDialogL(TBool aSecureDialog);
        
        /**
        * Gets the information if IAPDialog is shown or not.
        * @param aIAPDialog A TBool reference to be filled in with the
        *                   value of the SecureDialog flag.
        * @return           KErrNone if no error, or some of the system
        *                   wide error codes.
        */
//        IMPORT_C virtual TInt IAPDialogL(TBool& aIAPDialog);

        /**
        * Sets the flag which controls showing of IAPDialog.
        * @param aIAPDialog is the new value for IAPDialog flag.
        */
//        IMPORT_C virtual void SetIAPDialogL(TBool aIAPDialog);

        /**
        * Gets the UserAgent.
        * @param aUserAgent  A TPtrC8 reference to be filled in with the
        *                    value of the UserAgent.
        * @return            KErrNone if no error, or some of the system
        *                    wide error codes.
        */
        IMPORT_C virtual TInt UserAgentL(TPtrC8& aUserAgent);
        
        /**
        * Sets the UserAgent.
        * @param aUserAgent is the new User Agent.
        */
        IMPORT_C virtual void SetUserAgentL(const TDesC8& aUserAgent);
        
        /**
        * Gets the device ID
        * @param aDeviceID  A TPtrC8 reference to be filled in with the
        *                    value of the Device ID.
        * @return            KErrNone if no error, or some of the system
        *                    wide error codes.
        */
        IMPORT_C virtual TInt DeviceIDL(TPtrC8& aDeviceID);

        /**
        * Sets the Device ID.
        * @param aDeviceID is the new Device ID.
        */
        IMPORT_C virtual void SetDeviceIDL(const TDesC8& aDeviceID);
        
        /**
        * Gets the Action of message
        * @param aAction A TPtrC8 reference to be filled in with the
        *                    value of the Action.
        * @return            KErrNone if no error, or some of the system
        *                    wide error codes.
        */
        IMPORT_C virtual TInt SoapActionL(TPtrC8& aAction);
        
        /**
        * Sets the Action.
        * @param aAction is the new Soap Action.
        */
        IMPORT_C virtual void SetSoapActionL(const TDesC8& aAction);
        
        /**
        * Apply binding.
        * @param aSoapVersion is the version of Soap (1.1 or 1.2).
        */
        IMPORT_C virtual void ApplyBindingL(TSOAPVersion aSoapVersion);

        /**
        * Gets download folder for incoming BLOB (binary large objects)
        * @param aDownloadFolder - A TPtrC8 reference to be filled in with the
        *                    value of the shared, public folder for downloaded 
        *                    content
        * @return            KErrNone if no error, or some of the system
        *                    wide error codes.
        */
        IMPORT_C virtual TInt DownloadFolderL(TPtrC8& aDownloadFolder);
        
        /**
        * Sets download folder for incoming BLOB (binary large objects)
        * @param aDownloadFolder shared, public folder for downloaded content
        */
        IMPORT_C virtual void SetDownloadFolderL(const TDesC8& aDownloadFolder);
        
        /**
        * Gets filename of file attachment
        * @param aCid - cid for filename
        * @param aFileName - filename of file attachment with current cid
        * @return            KErrNone if no error, or some of the system
        *                    wide error codes.
        */
        IMPORT_C virtual TInt FileAttachmentL(const TDesC8& aCid, HBufC8*& aFileName);
        
        /**
        * Sets filename of file attachment
        * @param aCid - cid for filename
        * @param aFileName - filename of file attachment with current cid
        * @return            KErrNone if no error, or some of the system
        *                    wide error codes.
        */
        IMPORT_C virtual TInt SetFileAttachmentL(const TDesC8& aCid, const TDesC8& aFileName);

        /**
        * Gets namespace of Microsoft schema
        * @param aMwsNamespace - namespace
        * @return            KErrNone if no error, or some of the system
        *                    wide error codes.
        */
        IMPORT_C virtual TInt MwsNamespaceL(TPtrC8& aMwsNamespace);
        
        /**
        * Sets namespace of Microsoft schema
        * @param aMwsNamespace - namespace
        * @return            KErrNone if no error, or some of the system
        *                    wide error codes.
        */
        IMPORT_C virtual void SetMwsNamespaceL(const TDesC8& aMwsNamespace);


        /**
        * Gets message ID
        * @param aMessageId - is the id of the message
        * @return            KErrNone if no error, or some of the system
        *                    wide error codes.
        */
        IMPORT_C virtual TInt MessageIdL(TPtrC8& aMessageId);

        /**
        * Sets message ID. Typically, this property is set per each message, instead of
        * applying the same message ID for whole consumer session (service connection)
        * @param aMessageID - is the ID of the message
        * @return            KErrNone if no error, or some of the system
        *                    wide error codes.
        */
        IMPORT_C virtual void SetMessageIdL(const TDesC8& aMessageId);

        /**
        * Gets one-way message mode.
        * @param aOnewayMsgOnOff A TBool reference to be filled in with the
        *                    value of the one-way message mode.
        * @return            KErrNone if no error, or some of the system
        *                    wide error codes.
        */
        IMPORT_C virtual TInt OnewayMessageOnOffL(TBool& aOnewayMessageOnOff);

        /**
        * Sets the one-way message mode on/off. Typically, one-way
        * messages are rarely used by default: instead, a request-
        * response pair (consumer[request]<->[response]provider)
        * transaction takes place.
        * However, if one-way message mode is enabled, sending such
        * message will typically result immediate callback from
        * the transport (plug-in) itself. This means, that the
        * actual service response from the provider is not being
        * waited. 
        * Common use case to enable one-way message is when service
        * connection is used in transmitting *responses* to notification
        * request(s) that some remote consumer (from outside device) has 
        * sent earlier.
        * Such notification requests may thus be received via hostlet 
        * connection (hc), and by enabling one-way message, once can reply
        * via service connection, instead of calling hc->RespondL method.
        * Furthermore, application might wish to enable one-way message
        * mode to hostlet connection, if it is not interested of replying
        * to these two-way notifications via hostlet connection, but wishes
        * to use service connection instead.
        * @param aOnewayMessageOnOff is the new value of one-way message mode.
        */
        IMPORT_C virtual void SetOnewayMessageOnOffL(TBool aOnewayMessageOnOff);

        /**
        * Sets the (connection) Max TTL for longlive connection.
        *
        * @see SetHeartbeatL(TInt aDelta)
        *
        * @param aMaxTTL      TInt reference to be filled in with 
        *                      the value of the max TTL (in seconds)
        * @return              KErrNone if no error, or some of the system
        *                       wide error codes.
        */
        IMPORT_C virtual TInt SetMaxTimeToLiveL(TInt aMaxTTL);
        
        /**
        * Gets the (connection) max TTL property value as int.
        *
        * @see SetHeartbeatL(TInt aDelta)
        *
        * @param aMaxTTL       A TInt reference to be filled in with the
        *                       value of the max TTL (in seconds).
        *
        * @return           KErrNotFound if shortlive connection defined
        *                   KErrNone if no error, or some of the system
        *                       wide error codes.
        */
        IMPORT_C virtual TInt MaxTimeToLiveL(TInt& aMaxTTL);

        /**
        * Sets the (connection) Min TTL
        *
        * @see SetHeartbeatL(TInt aDelta)
        *
        * @param aMaxTTL      TInt reference to be filled in with 
        *                      the value of the min TTL (in seconds)
        * @return              KErrNone if no error, or some of the system
        *                       wide error codes.
        */
        IMPORT_C virtual TInt SetMinTimeToLiveL(TInt aMinTTL);

        /**
        * Gets the (connection) min TTL property value as int.
        *
        * @see SetHeartbeatL(TInt aDelta)
        *
        * @param aMinTTL     A TInt reference to be filled in with the
        *                       value of the min TTL (in seconds).
        *
        * @return           KErrNone if no error, or some of the system
        *                       wide error codes.
        */
        IMPORT_C virtual TInt MinTimeToLiveL(TInt& aMinTTL);



        /**
        * Sets resource property value  for endpoint
        *
        *
        * @param aEndpointResource - is the suffix for endpoint
        *                      
        * @return              KErrNone if no error, or some of the system
        *                       wide error codes.
        */
        IMPORT_C virtual TInt SetEndpointResourceL(const TDesC8& aEndpointResource);

        /**
        * Gets resource property value for endpoint
        *
        *
        * @param aEndpointResource - is the suffix for endpoint
        *                      
        *
        * @return           KErrNone if no error, or some of the system
        *                       wide error codes.
        */
        IMPORT_C virtual TInt EndpointResourceL(TPtrC8& aEndpointResource);


    protected: // base class functions

        IMPORT_C virtual void BaseConstructL(const TDesC8& aLocalname, 
                                    const TDesC8& aXml,
                                    CSenXmlReader* aParser = NULL);

        IMPORT_C virtual void BaseConstructL(const TDesC8& aNamespace, 
                                    const TDesC8& aLocalname, 
                                    const TDesC8& aXml,
                                    CSenXmlReader* aParser = NULL);

        IMPORT_C virtual void BaseConstructL(const TDesC8& aNamespace, 
                                    const TDesC8& aLocalname, 
                                    const TDesC8& aQualifiedName, 
                                    const TDesC8& aXml,
                                    CSenXmlReader* aParser = NULL);

        IMPORT_C virtual void BaseConstructL(const CSenElement& aElement);
        
	public:
        /**
        * Sets the SNAP ID.
        * @param aSnapId is the new SNAP ID.
        */
        IMPORT_C void SetSnapIdL(TUint32 aSnapId); 

        /**
        * Gets the SNAP ID.
        * @param aCurrentSnapId  A TUint32 reference to be filled in with the
        *                       value of the SNAP ID.
        * @return               KErrNone if no error, or some of the system
        *                       wide error codes.
        */
        IMPORT_C TInt SnapIdL(TUint32& aCurrentSnapId); 
    protected:
        /**
        * Constructor.
        */
        IMPORT_C CSenTransportProperties();
        
    private:
        TInt iFileAttachmentNum;        
    };

#endif // SEN_TRANSPORT_PROPERTIES_H