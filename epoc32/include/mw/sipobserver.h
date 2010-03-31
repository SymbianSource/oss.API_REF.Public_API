/*
* Copyright (c) 2005-2009 Nokia Corporation and/or its subsidiary(-ies).
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
* Description:
* Name        : sipobserver.h
* Part of     : SIP Client
* Interface   : SDK API, SIP Client API
* Version     : 1.0
*
*/



#ifndef MSIPOBSERVER_H
#define MSIPOBSERVER_H

// INCLUDES
#include <e32std.h>

// FORWARD DECLARATIONS
class CSIPServerTransaction;

// CLASS DECLARATION

/**
*  @publishedAll
*  @released
*
*  An interface to be implemented by user of CSIP.
*  Interface allows to be able to receive SIP request from the SIP connection
*  that has not been initialized by the user.
*
*  @lib n/a
*/
class MSIPObserver
    {    
    public: // New functions
        /**
        * A SIP request has been received from the network.
        * This function is called when the SIP request was received using such
        * an IAP, for which the application has not created a CSIPConnection
        * object.
        * @pre aTransaction != 0
        * @param aIapId The IapId from which the SIP request was received.
        * @param aTransaction contains local address, remote address of a SIP
        *        message, as well as optional SIP message method, headers and
        *        body. The ownership is transferred.
        */
        virtual void IncomingRequest(TUint32 aIapId,
                                     CSIPServerTransaction* aTransaction) = 0;

        /**
        * The received SIP request time-outed and it is invalid i.e. cannot be used
        * anymore.
        * This will be called if the user fails to create a SIP connection and
        * does not send an appropriate SIP response.
        * @param aTransaction The time-outed transaction.
        */
        virtual void TimedOut(CSIPServerTransaction& aTransaction) = 0;
    };

#endif
