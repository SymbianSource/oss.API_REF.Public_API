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
* Description: Callback interface for service consumers        
*
*/

#ifndef M_SEN_SERVICE_CONSUMER_H
#define M_SEN_SERVICE_CONSUMER_H

const TUid KSenInterfaceUidFilesObserver            = { 0x101F9742 }; // MSenFilesObserver
const TUid KSenInterfaceUidAuthenticationProvider   = { 0x10282C6F }; // MSenAuthenticationProvider
// CLASS DECLARATION

/**
 * Callback interface for service consumers
 */
class MSenServiceConsumer
    {
    public: 
        
        // New functions
        
        /**
        * Callback, which is invoked when a message is received from invoked service.
        * Inside this method, it is guarenteed, that the TxnId() getter provided by
        * CSenServiceConnection class will return valid transaction ID. This allows 
        * one to map the ID of sent request, returned from CSenServiceConnection::SendL
        * with the response that is provided in this callback.
        * @param aMessage incoming message.
        */
        virtual void HandleMessageL(const TDesC8& aMessage) = 0;

        /**
        * Callback, which is invoked when an error message is received from invoked service.
        * Inside this method, it is guarenteed, that the TxnId() getter provided by
        * CSenServiceConnection class will return valid transaction ID. This allows 
        * one to map the ID of sent request, returned from CSenServiceConnection::SendL
        * with the response that is provided in this callback.
        * @param aErrorCode is the error code (negative number)
        * Error codes are some of the following:
        * KErrSenNotInitialized             Connection hasn't been initialized.
        * KErrConnectionInitializing        Connection is still initializing.
        * KErrSubmitting                    Submitting a message failed, 
        *                                   e.g. tried to send a NULL message.
        * KErrConnectionExpired             Connection has expired and needs to be
        *                                   renewed.
        * KErrSenSoapFault                  A SOAP fault occurred, aErrorMessage should 
        *                                   contain more detailed information.
        * KErrSenInternal                   Internal error in Web Services 
        *                                   framework
        * KErrUnknown                       An unexpected major error has occurred
        *                                   and cause is unknown.
        * Other possible error codes can be HTTP error codes or 
        * system-wide Symbian error codes.
        * @param aErrorMessage contains the error message data; with SOAP based services,
        * possibly a SOAP fault as XML.
        */
        virtual void HandleErrorL(const TInt aErrorCode, 
                                  const TDesC8& aErrorMessage) = 0;

        /**
        * This method is called when the status of the connection
        * to the service changes.
        * @param aStatus is connection state indicator, which
        * could be specified by the actual service invocation framework
        * implementation. The following status codes are possible for
        * any installed framework:
        * KSenConnectionStatusNew              Connection is being initialized, but not yet ready.
        * KSenConnectionStatusReady            Connection is ready to be used. For example, SubmitL()
        *                                      and SendL() methods (depending of framework) are in
        *                                      invocable state.
        * KSenConnectionStatusExpired          Connection is expired. Typically, a new connection
        *                                      needs next to be initialized in order to communicate
        *                                      with the underlying service behind this service
        *                                      connection.
        */
        virtual void SetStatus(const TInt aStatus) = 0;
    };

/**
 * Callback interface for trnsfer progress observer
 */
class MSenFilesObserver
    {
    public:
    /**
    * This method is called when new part of BLOB is sent or received.
    *
    * @param aTxnId Transaction ID.
    * @param aIncoming ETrue if it is incoming BLOB, EFalse if outgoing.
    * @param aMessage SOAP message for incoming messages with BLOBs.
    * @param aCid CID of current BLOB.
    * @param aProgress Count of sent/received BLOB bytes.
    */
    virtual void TransferProgress(TInt aTxnId, TBool aIncoming, const TDesC8& aMessage,
            const TDesC8& aCid, TInt aProgress) = 0;
    };
class MSenExtendedConsumerInterface
    {       
    public: 
	    inline virtual TAny* GetInterfaceByUid( TUid /* aUID */ ) { return NULL; };
    };    

#endif // M_SEN_SERVICE_CONSUMER_H

// End of File
