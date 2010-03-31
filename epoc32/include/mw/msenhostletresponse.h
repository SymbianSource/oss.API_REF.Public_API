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
* Description: Hostlet response call back interface        
*
*/


#ifndef MSEN_HOSTLET_RESPONSE_H
#define MSEN_HOSTLET_RESPONSE_H

#include <e32base.h>

// FORWARD DECLARE
class MSenProperties;
class MSenMessage;


class MSenHostletResponse
    {
    public:
        /**
        *  Set the response
        * @param aResponseUtf8 is the response that this hostlet is providing
        * @param aCode can be set to error code, in case that request is not
        * accepted by this hostlet.
        * @param aResponseProperties may be provided in order to pass (transport)
        * properties with the response.
        * @param aResponseMessage may be provided in order to pass concrete
        * message object with the response (like libxml2 based SOAP-ENV,
        * CSenSoapEnvelope2)
        */
        virtual void SetResponseUtf8L(const TDesC8& aResponseUtf8, 
                                      const TInt aResponseCode = KErrNone, 
                                      MSenProperties* aResponseProperties = NULL,
                                      MSenMessage* apMessage = NULL) = 0;
        
        /**
        * Getter for request (transaction) ID
        * @return the id of the request to which this is a response for
        */ 
        virtual TInt RequestId() const = 0;
        
        /**
        * Getter for response data
        * @return the set response as UTF-8 descriptor
        */
        virtual TPtrC8 ResponseUtf8() = 0;

        /**
        * Getter for response code
        * @return the response code (KErrNone or some error) that hostlet has provided
        */
        virtual TInt ResponseCode() const = 0;
        
        /**
        * Getter for response properties
        */
        virtual MSenProperties* ResponseProperties() = 0;
    };

#endif // MSEN_HOSTLET_RESPONSE_H
