// Copyright (c) 1999-2009 Nokia Corporation and/or its subsidiary(-ies).
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

#ifndef BTSECMANCLIENT_H
#define BTSECMANCLIENT_H

#include <btmanclient.h>

/**
@internalAll
@released
Struct used to transfer BT address to host resolver to indicate notification of event
**/
NONSHARABLE_CLASS(TBTHostResolverNotification)
	{
public:
	TBTDevAddr iBDAddr;
	TInt iNotification;
	};

/**
@internalAll
@released
Struct used to transfer device information to host resolver.
**/
NONSHARABLE_CLASS(TBTHostResolverDeviceInfo)
	{
public:
	TBTDevAddr iBDAddr;
	TUint8 iPageScanRepMode;				/*!< Page Scan repetition mode of remote device*/
	TUint8 iPageScanMode;					/*!< Page scan mode of remote device*/
	TUint16 iClockOffSet;					/*!< clock off set of remote device*/
	};

/**
@internalAll
@released
Struct used to transfer new Juice information from host resolver client to server.
Juice information contains data pertaining to 
**/
NONSHARABLE_CLASS(TBTHostResolverNewJuice)
	{
public:
	TBTDevAddr iBDAddr;
	TUint32 iPageScanRepMode;				///< Page Scan repetition mode of remote device
	TUint32 iPageScanMode;					///< Page scan mode of remote device
	TUint32 iClockOffSet;					///< clock off set of remote device
	};


/**
@internalAll
@released
Struct used to transfer new link key event params from client to server.
**/
NONSHARABLE_CLASS(TBTSecManNewLinkKeyParams)
	{
public:
	TBTDevAddr iBDAddr;
	TBTLinkKey iLinkKey;
	};

/**
@internalAll
@released
Typedef'ed pckgbuf to send a TBTSecManNewLinkKeyParams object over IPC.
*/
typedef TPckgBuf<TBTSecManNewLinkKeyParams> TBTSecManNewLinkKeyParamsPckg;

/**
@internalAll
@released
Typedef'ed pckgbuf to send a TBTHostResolverNotification object over IPC.
*/
typedef TPckgBuf<TBTHostResolverNotification> TBTHostResolverNotificationPckg;


#endif
