// Copyright (c) 2003-2009 Nokia Corporation and/or its subsidiary(-ies).
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
#include <obex/internal/obextransportconstants.h>

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
