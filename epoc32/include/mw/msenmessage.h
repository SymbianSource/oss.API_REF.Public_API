/*
* Copyright (c) 2006 Nokia Corporation and/or its subsidiary(-ies). 
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
* Description:        This is the superclass interface for wider set of 
*                concrete WSF message classes.
*
*/









#ifndef M_SEN_MESSAGE_H
#define M_SEN_MESSAGE_H

#include <e32std.h>

// FORWARD DECLARATIONS
class CSenElement;
class CSenXmlReader;

//using namespace SenContext;

// CONSTANTS
//namespace SenContext // consider whether or not to declare new SenMessage c++ namespace
//    {
//    // Message class type enumeration for class casting:        
//    }

// FORWARD DECLARATIONS
class MSenMessageContext;
class MSenProperties;

// CLASS DECLARATION
/**
* This is abstract interface defines set of WSF message classes, providing
* convenience for other components, which typically cast this to some
* subclass via IsSafeToCast() method.
* @lib SenMessages.lib
* @since Series60 4.0
*/
class MSenMessage
    {
    public:

		/**
		* Class Enumeration
		*/
        enum TClass
            {
            EMessageBase     = 0,
            EHttpGetMsg      = 1,
            EHttpPostMsg     = 2,
            EHttpPutMsg      = 3,
            EHttpDeleteMsg   = 4,
            ESoapEnvelope    = 5, 
            ESoapMessage     = 6,
            ESoapEnvelope2   = 7,
            ESoapMessage2    = 8,
            ESoapMessageDom2 = 9,
            EAtomMessage     = 10
            };
        /**
        * Direction Enumeration
        */    
        enum TDirection
            {
            EOutbound        = 0,
            EInbound         = 1
            };        
 
 		/**
 		* Gets the Message Type
 		*/
        virtual TClass Type() = 0;
        /**
        * Gets the Message Direction
        */
        virtual TDirection Direction() = 0;
        
        
        /**
        * Sets message context for this message. If context already
        * exists, it is discarded and replaced by this context
        * (context reset is performed).
        * @param apNotOwnedContext is the context.
        * Ownership is NOT transferred to this message.
        * @return
        *   KErrNone on success
        *   KErrArgument if apOwnedContext == NULL
        *   or system-wide errorcode otherwise.
        */
        virtual TInt SetContext(MSenMessageContext* apNotOwnedContext) = 0;
        
        /**
        * Getter for message's context
        * @return message context, if this message relates to
        *         (has associated with) such context, or NULL.
        */
        virtual MSenMessageContext* Context() = 0;

        /**
        * Sets properties for this message. Most typical use case
        * is to set message spesific transport properties.
        * @param apOwnedProperties pointer to the properties, which
        * ownership is transferred to this class. This is performed
        * in two different manners:
        *
        *  1. If message has context, the properties are (re)set into that context,
        *     discarding any pre-existing properties. 
        *
        *  2. If context is NOT available, properties will be directly owned by 
        *     this message.
        * @return
        *   KErrNone on success
        *   KErrArgument if apOwnedProperties == NULL
        *   or system-wide errorcode otherwise.
        */
        virtual TInt SetProperties(MSenProperties* apOwnedProperties) = 0;

        /**
        * Getter for message specific (transport) properties
        * @return (transport) properties of this message, 
        *         if such have been applied to this message
        *         or NULL otherwise.
        */
        virtual MSenProperties* Properties() = 0;

        virtual TBool IsSafeToCast(TClass aType) = 0;
        /**
        * Getter for transaction ID of this message.
        * In case of receiving a response message from 
        * service provider, this transaction ID may be
        * used to map the response with request that
        * the service consumer sent via service connection.
        * In such case, the consumer can store return 
        * value from SendL method that was invoked in 
        * order maintain this mapping.
        * @return the transaction ID of this message
        */        
        virtual TInt TxnId() = 0; 

        /**
        * Clone method that duplicates this message 
        * -- including all member data in the message.
        * For the service consumers, a typical use case
        * for cloning the message is when there is need
        * to preserve the received response beyond the
        * life time of a transaction. Normally, the
        * response messages, that are owned by service
        * connection are de-allocated after execution
        * returns from MSenServiceConsumer interface's
        * HandleMessageL or HandleErrorL method, back
        * to the service connection.
        * @return a pointer to a new message class instance,
        * which ownership IS transferred to a caller. Note
        * that caller is expected to cast this pointer to
        * a proper subclass via the use of IsSafeToCast 
        * method. In case of responses, the message type
        * is normally equal with the type of the request
        * message that was sent by the consumer.
        */        
        virtual MSenMessage* CloneL() = 0;
    };

#endif // M_SEN_MESSAGE_H

// End of File


