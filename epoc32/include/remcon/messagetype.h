// Copyright (c) 2004-2009 Nokia Corporation and/or its subsidiary(-ies).
// All rights reserved.
// This component and the accompanying materials are made available
// under the terms of the License "Symbian Foundation License v1.0" to Symbian Foundation members and "Symbian Foundation End User License Agreement v1.0" to non-members
// which accompanies this distribution, and is available
// at the URL "http://www.symbianfoundation.org/legal/licencesv10.html".
//
// Initial Contributors:
// Nokia Corporation - initial contribution.
//
// Contributors:
//
// Description:
//



/**
 @file
 @publishedPartner
 @released
*/

#ifndef MESSAGETYPE_H
#define MESSAGETYPE_H

/**
Message type enumeration.
*/
enum TRemConMessageType
	{
	/** Undefined message type. */
	ERemConMessageTypeUndefined = 0,

	/** Command. */
	ERemConCommand,
	
	/** Response. */
	ERemConResponse,

	/** Errored Response or Reject. */
	/** Treated as a command completion by RemCon */
	ERemConReject,
	
	/** NotifyCommand */
	ERemConNotifyCommand,
	};

enum TRemConMessageSubType
	{
	/** Default command or response */
	ERemConMessageDefault = 0,
	
	/** Notify command requiring an interim response and (later) changed response */
	ERemConNotifyCommandAwaitingInterim,
	
	/** Notify command requiring only a changed response, after notify has been readdressed */
	ERemConNotifyCommandAwaitingChanged,
	
	/** Notify interim response */
	ERemConNotifyResponseInterim,
	
	/** Notify changed response */
	ERemConNotifyResponseChanged,
	};

#endif // MESSAGETYPE_H
