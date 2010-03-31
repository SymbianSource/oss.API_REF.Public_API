// Copyright (c) 2003-2009 Nokia Corporation and/or its subsidiary(-ies).
// All rights reserved.
// This component and the accompanying materials are made available
// under the terms of "Eclipse Public License v1.0"
// which accompanies this distribution, and is available
// at the URL "http://www.eclipse.org/legal/epl-v10.html".
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
 @publishedAll
 @released
*/

#ifndef __OBEXTYPES_H
#define __OBEXTYPES_H

#include <e32std.h>
#include <e32des8.h>
#include <e32des16.h>
#include <utf.h> // Required for source compatability
#include <obexconstants.h>

typedef TUint16 TObexHeaderMask;
typedef TUint8 TObexOpcode;
typedef TBuf8<16> TNonce;

class TObexProtocolInfo;
class TObexIrProtocolInfo;
class TObexBluetoothProtocolInfo;
class TObexUsbProtocolInfo;
class TObexUsbProtocolInfoV2;
class TObexProcotolPolicy;
struct TObexConnectionInfo;
class TObexConnectInfo;

class CObexPacket;
class CObexHeader;
class CObexUnderlyingHeader;
class MObexHeaderCheck;
class CObexHeaderSet;
class CObexBaseObject;
class CObexFileObject;
class CObexBufObject;
class CObexNullObject;
class MObexNotify;
class MObexAuthChallengeHandler;
class CObexTransport;
class CObexConnector;
class TObexInternalHeader;
class CObexAuthenticator;
class CObex;
class TObexSetPathData;
class CObexClient;
class MObexServerNotify;
class CObexServer;
class CObexServerStateMachine;
class MObexServerNotify;
class MObexServerNotifyAsync;
class CObexServerNotifySyncWrapper;


#endif // __OBEXTYPES_H
