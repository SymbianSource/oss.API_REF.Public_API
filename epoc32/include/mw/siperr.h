/*
* Copyright (c) 2004-2009 Nokia Corporation and/or its subsidiary(-ies).
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
* Description:
* Name          : siperr.h
* Part of       : SIP Client API
* Interface     : SDK, SIP Client API
* Version       : 1.0
*
*/



#ifndef SIPERR_H
#define SIPERR_H

#include <e32base.h>

/** @file 
* @publishedAll
* @released
*/

/** SIP message was malformed */
const TInt KErrSIPMalformedMessage = -17700;

/** Invalid SIP response received from registrar*/
const TInt KErrSIPInvalidRegistrarResponse = -17701;

/** SIP Request pending */
const TInt KErrSIPRequestPending = -17702;

/** The action cannot be performed in the current transaction state */
const TInt KErrSIPInvalidTransactionState = -17703;

/** Not allowed in dialogs current state */
const TInt KErrSIPInvalidDialogState = -17704;

/** Invalid request in SIP dialog */
const TInt KErrSIPInvalidDialogRequest = -17705;

/** Invalid response in SIP dialog */
const TInt KErrSIPInvalidDialogResponse = -17706;

/** Sending a SIP message failed. For example ICMP error occured */
const TInt KErrSIPTransportFailure = -17707;

/** No ACK was received after sending a 2xx response */
const TInt KErrSIPNoAckReceived = -17708;

/** Not allowed in registration's current state */
const TInt KErrSIPInvalidRegistrationState = -17709;

/** The contact given did not contain user part */
const TInt KErrSIPInvalidContact = -17710;

/** Object can't access a resource, since that has been deleted by user.
The user is expected to delete this object as it can no longer be used. */
const TInt KErrSIPResourceNotAvailable = -17711;

/** DNS query for the remote address failed */
const TInt KErrSIPResolvingFailure = -17712;

/** Authentication with a server failed */
const TInt KErrSIPForbidden = -17713;

/** Maximum number of allowed SigComp compartments exceeded */
const TInt KErrSIPMaxCompartmentsInUse = -17714;

/** Refresh initiated client transaction was terminated with
a 3xx, 4xx, 5xx or 6xx response.*/
const TInt KErrSIPTerminatedWithResponse = -17715;

/** Provided SIP outbound proxy is not responding*/
const TInt KErrSIPOutboundProxyNotResponding = -17716;

/** The URI type is not allowed in some field of the particular SIP message. 
Note that this does not mean that the URI type is forbidden in general. 
For example Contact-header of an INVITE must always contain a SIP-URI. 
Any other types are rejected with this error code. */
const TInt KErrSIPInvalidURIType = -17717;

/** ICMP error has occured */
const TInt KErrSIPICMPFailure = -17718;

#endif //SIPERR_H
