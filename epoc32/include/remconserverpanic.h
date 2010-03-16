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
// Panic codes for RemConServer. 
// The server may panic clients with these codes.
// 
//



/**
 @file
 @publishedAll
 @released
*/

#ifndef REMCONSERVERPANIC_H
#define REMCONSERVERPANIC_H

#include <e32base.h>

/** Panic category used by Rem Con server to panic the client. */
_LIT(KRemConClientPanicCat, "RemConClient");

/** Panic codes used by Rem Con server to panic the client. */
enum TRemConClientPanic
	{
	/** The client side has passed an illegal IPC value */
	ERemConClientPanicIllegalIpc										= 0,

	/** The client is already connection-oriented. */
	ERemConClientPanicAlreadyConnectionOriented 						= 1,

	/** The client has called GoConnectionless, ConnectBearer or 
	DisconnectBearer when the session is not connection-oriented. */
	ERemConClientPanicNotConnectionOriented 							= 2,

	/** The client called GoConnectionOriented with an unknown bearer UID. The 
	given UID is not a known implementation of the bearer interface. */
	ERemConClientPanicBearerPluginIncorrectInterface					= 3,

	/** The client requested Send when there was already a Send outstanding on 
	this session. */
	ERemConClientPanicSendAlreadyOutstanding							= 4,

	/** The client requested Receive when there was already a Receive 
	outstanding on this session. */
	ERemConClientPanicReceiveAlreadyOutstanding 						= 5,
	
	/** The client has not had their type set. */
	ERemConClientPanicClientTypeNotSet									= 6,

	/** The client has attempted to set the type of the session when it has 
	already been set. */
	ERemConClientPanicClientTypeAlreadySet								= 7,

	/** A client has used a bad or wrong session type in one of the following 
	ways:
	(a) The client has tried to set the type of the session to a bad type 
	(neither controller nor target). 
	(b) The client (not of controller type) has called GoConnectionOriented, 
	GoConnectionless, ConnectBearer, ConnectBearerCancel, DisconnectBearer or 
	DisconnectBearerCancel. */
	ERemConClientPanicBadType											= 8,

	/** A client tried to open a target session when there is already one in
	that client process. 
	
	This is no longer an illegal condition and so the panic will never
	be raised.
	*/
	ERemConClientPanicTwoTargetSessionsInOneProcess 					= 9,

	/** A badly-formed descriptor or other lump of data was sent from the 
	client side. */
	ERemConClientPanicBadDescriptor 									= 10,

	/** The client requested NotifyConnectionStatusChange when there was 
	already a NotifyConnectionStatusChange outstanding on this session. */
	ERemConClientPanicConnectionsNotificationAlreadyOutstanding 		= 11,
	
	/** The client has committed one of a number of abuses of the 
	ConnectBearer/DisconnectBearer interface. 
	With respect to Send, Receive, ConnectBearer and DisconnectBearer 
	messages, the following is a table of the legal states of a session 
	(- = not outstanding, X = outstanding):
	Send	Receive		Connect		Disconnect
	-		-			-			-
	X		-			-			-
	-		X			-			-
	-		-			X			-
	-		-			-			X
	X		X			-			-
	X		-			X			-
	-		X			X			-
	X		X			X			-
	-		X			-			X
	In other words, any combination of the four is legal except having a 
	DisconnectBearer outstanding at the same time as either a Send or a 
	ConnectBearer.
	In addition, the client cannot call GoConnectionOriented or 
	GoConnectionless while there's a Send, ConnectBearer or DisconnectBearer 
	outstanding.
	This code is also used to error attempts to post a ConnectBearer or 
	DisconnectBearer request which is already outstanding.
	This is all in the interests of tying the legal client side behaviour to a 
	minimum of sensible operations.
	*/
	ERemConClientPanicBearerControlOutstanding							= 12,

	/** The client has tried to send a response to a command which does not
	exist in the logs as having been delivered to that client.
	
	This is no longer an illegal condition and so the panic will never
	be raised.
	*/
	ERemConClientPanicNoCommand 										= 13,

	/** RRemConTarget::RegisterInterestedAPIs(...) is called on a non-target session
	(i.e. controller or undefined session). This doesn't make any sense because the 
	server only filters incoming commands for the target sessions.
	
	The client is paniced for misusing this API.
	*/
	ERemConClientPanicRegisterInterestedAPIsInNonTargetSession			= 14,	
	};

#endif // REMCONSERVERPANIC_H
