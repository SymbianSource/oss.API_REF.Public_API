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
// API for the Remote Control server side.
// Used by the Remote Control client side library.
// 
//



/**
 @file
 @internalComponent
*/

#ifndef REMCONSERVER_H
#define REMCONSERVER_H

#include <remcon/operationinformation.h>

const TUint32 KRemConSrvTUint = 0x101f9067;
const TUid KRemConSrvUid = {KRemConSrvTUint};

_LIT(KRemConServerImg, "z:\\sys\\bin\\remconserver.exe");

_LIT(KRemConServerName, "!RemConSrv");

/** Version numbers. */
const TInt8 KRemConSrvMajorVersionNumber = 1;
const TInt8 KRemConSrvMinorVersionNumber = 1;
const TInt16 KRemConSrvBuildNumber = 0;

/** IPC messages supported by the server. */
enum TRemConIpc
	{
	ERemConDbgMarkHeap						= 0, // the 1st message must be 0 for CPolicyServer to start up
	ERemConDbgCheckHeap 					= 1,
	ERemConDbgMarkEnd						= 2,
	ERemConDbgFailNext						= 3,
	ERemConSetClientType					= 4,
	ERemConGoConnectionOriented 			= 5,
	ERemConGoConnectionless 				= 6,
	ERemConConnectBearer					= 7,
	ERemConConnectBearerCancel				= 8,
	ERemConDisconnectBearer 				= 9,
	ERemConDisconnectBearerCancel			= 10,
	ERemConSend 							= 11,
	ERemConSendCancel						= 12,
	ERemConReceive							= 13,
	ERemConReceiveCancel					= 14,
	ERemConGetConnectionCount				= 15,
	ERemConGetConnections					= 16,
	ERemConNotifyConnectionsChange			= 17,
	ERemConNotifyConnectionsChangeCancel	= 18,
	ERemConRegisterInterestedAPIs			= 19,
	ERemConSendUnreliable					= 20,
	};

#endif // REMCONSERVER_H
