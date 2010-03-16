/*
* Copyright (c) 2004 Nokia Corporation and/or its subsidiary(-ies). 
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
* Description:  Interface for Instant Messaging services
*
*/


#ifndef OPENAPI_IM_CLIENT_H
#define OPENAPI_IM_CLIENT_H

// INCLUDES
#include <e32base.h>
#include <bamdesca.h>
#include <cntdef.h>

// CONSTANTS

// FORWARD DECLARATIONS
class MImObserver;
class MImClientDetailedError;

// CLASS DECLARATION
/**
*  Instant Messaging interface class
*  This interface class provides methods to send and receive instant messages.
*  Application to be able to receive IMs it must register its own observer
*  using this interface class.
*  This interface can be obtained using a factory method from the CImConnection
*  class.
*
*  @lib imclient.lib
*  @since S60 3.0
*/
class MImClient
    {

    public:

        virtual ~MImClient() {}

        /**
        * Method for registering the IM client to the WV Engine.
        * This method is synchronous.
        * @since S60 3.0
        * @param aObserver observer object used for notifying the user
        *        software
        * @leave KImApiErrAlreadyRegistered if it was registered already or other system wide error code
        */
        virtual void RegisterObserverL(
            MImObserver* aObserver ) = 0;

        /**
        * Method for unregistering the IM Sender from the WV Engine.
        * This method is synchronous method.
        * @since S60 3.0
        */
        virtual void UnregisterObserver( ) = 0;

        /**
        * Method for sending person-to-person text message (UNICODE) using
        * Contact Model IDs. This method is asynchronous and it’s completion
        * is signaled in HandleMessageSentL() method.
        * The method will leave on error. The API specific error codes are
        * in imerrors.h file
        * @since S60 3.0
        * @param aContactItem Contact Model ID of the recipient
        * @param aContent The content of the message in UNICODE
        * @return operation code
        * @leave KImApiErrNotRegistered observer was not registered
        * @leave KImApiErrInvalidContactId the contact ID does not have a corresponding User ID
        */
        virtual TInt SendPToPMessageL(
            const TContactItemId& aContactItem,
            const TDesC16& aContent ) = 0;

        /**
        * Method for sending person-to-person text message (UNICODE) using
        * Contact Model IDs. This method is asynchronous and its completion
        * is signaled in HandleMessageSentL() method.
        * The method will leave on error. The API specific error codes are
        * in imerrors.h file
        * Please note that one contact can have more than one assigned IM user
        * ID. Sending IM to those contacts will result in partial success.
        * @since S60 3.0
        * @param aContactIds Contact Model Ids of the recipient(s)
        * @param aContent The content of the message in UNICODE
        * @return operation code
        * @leave KImApiErrNotRegistered observer was not registered
        * @leave KImApiErrInvalidContactId the contact ID does not have a corresponding User ID
        */
        virtual TInt SendPToPMessageL(
            const CContactIdArray& aContactIds,
            const TDesC16& aContent ) = 0;

        /**
        * Method for sending person-to-person binary (or 8bit text) message
        * using Contact Model IDs. This method is asynchronous and its
        * completion is signaled in HandleMessageSentL() method.
        * The method will leave on error. The API specific error codes are
        * in imerrors.h file
        * Please note that one contact can have more than one assigned IM user
        * ID. Sending IM to those contacts will result in partial success.
        * @since S60 3.0
        * @param aContactIds Contact Model Ids of the recipient(s)
        * @param aContentType MIME type of the content
        * @param aContent The content of the message
        * @return operation code
        *
        * NOTE: Not yet supported!
        */
        virtual TInt SendPToPMessageL(
            const CContactIdArray& aContactIds,
            const TDesC& aContentType,
            const TDesC8& aContent ) = 0;

        /**
        * Method for sending person-to-person text message using
        * directly the User IDs.
        * This method is asynchronous and its completion is signaled
        * in HandleMessageSentL() method.
        * The method will leave on error. The API specific error codes are
        * in imerrors.h file
        * @since S60 3.0
        * @param aUserId the recipient of the message
        * @param aContent the message in UNICODE
        * @return operation code.
        * @leave KImApiErrNotRegistered observer was not registered
        * @leave KImApiErrInvalidUserId wrong User ID
        */
        virtual TInt SendPToPMessageL(
            const TDesC& aUserId,
            const TDesC16& aContent ) = 0;

        /**
        * Method for sending person-to-person text message using
        * directly the User IDs.
        * This method is asynchronous and its completion is signaled
        * in HandleMessageSentL() method.
        * The method will leave on error. The API specific error codes are
        * in imerrors.h file
        * @since S60 3.0
        * @param aUserIds recipient(s) of the message
        * @param aContent the message in UNICODE
        * @return operation code.
        * @leave KImApiErrNotRegistered observer was not registered
        * @leave KImApiErrInvalidUserId wrong User ID
        */
        virtual TInt SendPToPMessageL(
            const MDesCArray& aUserIds,
            const TDesC16& aContent ) = 0;

        /**
        * Method for sending person-to-person binary (or 8 bit text) message
        * using directly the User IDs.
        * This method is asynchronous and its completion is signaled
        * in HandleMessageSentL() method.
        * The method will leave on error. The API specific error codes are
        * in imerrors.h file
        * @since S60 3.0
        * @param aUserIds recipient(s) of the message
        * @param aContentType MIME type of the message
        * @param aContent the message
        * @return operation code.
        *
        * NOTE: Not yet supported!
        */
        virtual TInt SendPToPMessageL(
            const MDesCArray& aUserIds,
            const TDesC& aContentType,
            const TDesC8& aContent ) = 0;

    };


// CLASS DECLARATION
/**
*  Observer interface for Instant Messaging
*  The user shall implement this interface and register it through the MImClient
*  interface to the API to be able to receive IMs
*
*  @lib imclient.lib
*  @since S60 3.0
*/
class MImObserver
    {

    public:

        /**
        * This method is called when the SendPToPMessageL succeeded
        * @since S60 3.0
        * @param aOpCode operation code matching the called functions.
        * @param aErrorCode error codes.
        */
        virtual void HandleMessageSentL(
            const TInt aOpCode,
            const TInt aErrorCode ) = 0;

        /**
        * This method is called when the SendPToPMessageL failed for some reason.
        * If the IM was sent to more recipients the error can be a partial
        * success. In that case the detailed error codes for each user can
        * fetched separately. Please note that the aDetailedError is valid
        * during the function call. After that it gets destroyed in the API.
        * @since S60 3.0
        * @param aOpCode operation code matching the called functions.
        * @param aErrorCode error codes.
        * @param aDetailedError list of errors for each failed user ID.
        */
        virtual void HandleSendErrorL(
            const TInt aOpCode,
            const TInt aErrorCode,
            MImClientDetailedError* aDetailedError ) = 0;

        /**
        * This method is called when a new point-to-point text message
        * has arrived.
        * @since S60 3.0
        * @param aErrorCode error codes (to be defined)
        * @param aContactId Contact model ID of the sender
        * @param aUserId UserID of the message sender
        * @param aMessageType MIME type of the received message
        * @param aContent the message in UNICODE
        */
        virtual void HandleNewPToPMessageL(
            const TInt aErrorCode,
            const TContactItemId  aContactId,
            const TDesC& aUserId,
            const TDesC& aMessageType,
            const TDesC16& aContent ) = 0;

        /**
        * This method is called when a new point-to-point message (8bit)
        * has arrived. The message can be text or binary data.
        * @since S60 3.0
        * @param aErrorCode error codes (to be defined)
        * @param aContactId Contact model ID of the sender
        * @param aUserId UserID of the message sender
        * @param aMessageType MIME type of the received message
        * @param aContent the message
        *
        * NOTE: Not yet supported!
        */
        virtual void HandleNewPToPMessageL(
            const TInt aErrorCode,
            const TContactItemId  aContactId,
            const TDesC& aUserId,
            const TDesC& aMessageType,
            const TDesC8& aContent ) = 0;

    };

// CLASS DECLARATION
/**
*  Detailed errors accessor class
*  @lib imclient.lib
*  @since S60 3.0
*/
class MImClientDetailedError
    {

    public:
        /**
        * Gets the number of failed User IDs
        * @since S60 3.0
        * @return number of failed user IDs
        */
        virtual TInt Count() = 0;

        /**
        * Gets the failed User ID
        * @since S60 3.0
        * @param aIndex index of the user in the list
        * @return failed user ID
        */
        virtual const TDesC& UserId( TInt aIndex ) = 0;

        /**
        * Gets the reason of the failure. The API specific error codes are
        * defined in imerrors.h file.
        * @since S60 3.0
        * @param aIndex index of the user in the list
        * @return the fail reason
        */
        virtual TInt ErrorCode( TInt aIndex ) = 0;

    };

#endif
// End of File
