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

#if !defined (__ES_ENUM_H__)
#define __ES_ENUM_H__

#include <e32std.h>
#include <nifvar.h>
#include <es_sock.h>

class TConnArgBase
/**
 * Base class for many arguments to RConnection functions.  Provides versioning information.
 * @note Not intended for user instantiation
 * @publishedAll
 * @released since v7.0s
 */
	{
public:
	inline TConnArgBase();
	inline TUint8 Version() const;

protected:
	inline TConnArgBase(TUint8 aVersion);

protected:
	TUint8 iVersion;
	TUint8 iReserved[3];
	};

/**
 * Versioning information for connection arguments
 * @publishedAll
 * @released since v7.0s
 */
const TUint8 KConnArgVersion1 = 1;

/**
Versioning information for connection arguments

@publishedAll
@released
*/
const TUint8 KConnArgVersion2 = 2;

class TConnectionInfo : public TConnArgBase
/**
@publishedAll
@released since v7.0s
*/
	{
public:
	inline TConnectionInfo();
	TConnectionInfo(const TDesC8& aConnectionInfo /*as passed to ::Bearer/::NoBearer*/);
	inline TConnectionInfo(TUint32 aIapId, TUint32 aNetId);

	static TBool IsLocalBearer(const TDesC8& aConnectionInfo);
	
protected:
	inline TConnectionInfo(TUint8 aVersion, TUint32 aIapId, TUint32 aNetId);

public:
	TUint32 iIapId;
	TUint32 iNetId;
	};

/**
@publishedAll
@released since v7.0s
*/
typedef TPckgBuf<TConnectionInfo> TConnectionInfoBuf;

class TConnectionInfoV2 : public TConnectionInfo
/**
 * Connection information structure (version 2)
 * Extends basic connection info with connection type information
 * @publishedPartner
 * @released since v7.0s
 * @see TConnectionInfo
*/
	{
public:
	inline TConnectionInfoV2();
	inline TConnectionInfoV2(TUint32 aIapId, TUint32 aNetId, TConnectionType aConnectionType);
	inline TConnectionType ConnectionType();

protected:
	inline TConnectionInfoV2(TUint8 aVersion, TUint32 aIapId, TUint32 aNetId, TConnectionType aConnectionType);

private:
	TConnectionType iConnectionType;
	};

/**
@publishedPartner
@released since v7.0s
*/
typedef TPckgBuf<TConnectionInfoV2> TConnectionInfoV2Buf;

class TSubConnectionInfo : public TConnArgBase
/**
 * Base class for information about a subconnection
 * @publishedPartner
 * @released since v7.0s
 * @note Classes for information about a specific connection type should derive from this class
 * @note Generic classes for most bearers are defined in nifconninfo.h
 * @note Classes with increasingly specific parameters for a connection type should derive from the more generic class of the same connection type, as clients can assume that any less specific TSubConnectionInfo-derived classes are acceptable for use in GetSubConnectionInfo() calls.
 */
	{
public:
	inline TSubConnectionInfo();

public:
	TSubConnectionUniqueId iSubConnectionUniqueId;
	TConnectionType iConnectionType;
	TTime iTimeStarted;
	};

/**
The following classes are used with RConnection::AllInterfaceNotification() to receive information
about interfaces coming up and going down.
*/

/**
@publishedAll
@released since v7.0s
*/
enum TConnInterfaceState
	{
	EInterfaceUp,
	EInterfaceDown
	};

class TInterfaceNotification
/**
@publishedAll
@released since v7.0s
*/
	{
public:
	TConnectionInfo iConnectionInfo;
	TConnInterfaceState iState;
	};

/**
@internalTechnology
*/
typedef TPckgBuf<TInterfaceNotification> TInterfaceNotificationBuf;

/**
Types of events that can occur on a subconnection

@publishedAll
@released
*/
enum TSubConnectionEventType
/**
 * Types of events that can occur on a subconnection
 * @publishedPartner
 * @released since v7.0s
 */
	{
	ESubConnectionOpened,           ///< Connection values 0-9999 for agent-based events
	ESubConnectionClosed,           ///< Connection values 0-9999 for agent-based events
	ESubConnectionQoSChanged = 1000 ///< Connection values 10000-19999 for nif-based events
	};

class TSubConnectionEvent
/**
 * Base class for structures that provide information related to a specific subconnection event
 * @note Classes derived from this must not exceed KMaxSubConnectionEventSize bytes in size
 * @publishedPartner
 * @released since v7.0s
 */
	{
public:
	IMPORT_C TSubConnectionEvent* CloneL() const;
	IMPORT_C TUint Length() const;

protected:
	IMPORT_C TSubConnectionEvent(TSubConnectionEventType aEventType, TUint aLength);
public:
	TSubConnectionUniqueId iSubConnectionUniqueId;
	TSubConnectionEventType iEventType;
protected:
	TUint iLength;
	};

class TSubConnectionOpenedEvent : public TSubConnectionEvent
/**
 * Information about a subconnection that has just been opened
 * @publishedPartner
 * @released since v7.0s
 * @note This class currently not passed to clients, as it is (essentially) empty
 */
	{
public:
	IMPORT_C TSubConnectionOpenedEvent();
	};

class TSubConnectionClosedEvent : public TSubConnectionEvent
/**
 * Information about a subconnection that has just been closed
 * @publishedPartner
 * @released since v7.0s
 * @note The time closed uses universal time as a time zone
 */
	{
public:
	IMPORT_C TSubConnectionClosedEvent();
public:
	TUint iTotalUplinkDataVolume;
	TUint iTotalDownlinkDataVolume;
	TTime iTimeClosed;	// universal time
	};

class TSubConnectionQoSChangedEvent : public TSubConnectionEvent
/**
 * Information about a subconnection on which the QoS settings have just changed. This only signals that QoS has changed. If the client wants to know what has changed should then get TSubConnectionInfo
 * @publishedPartner
 * @released since v7.0s
 * @note This will be produced by NIFs when QoS changes
 */
	{
public:
	IMPORT_C TSubConnectionQoSChangedEvent();
	};

/**
@internalTechnology
*/
typedef TPckgBuf<TInterfaceNotification> TInterfaceNotificationBuf;


/**
The following classes are used to enumerate clients and sockets associated with a 
particular connection.  RConnection::Control() is used to retrieve this information.
*/

class TConnectionEnumArg : public TConnArgBase
/**
for KCoEnumerateConnectionClients and KCoEnumerateConnectionSockets
@publishedPartner
@released since v7.0s
*/
	{
public:
	inline TConnectionEnumArg();
public:
	TUint iIndex;
	TUint iCount;
	};

/**
@internalComponent
*/
typedef TPckgBuf<TConnectionEnumArg> TConnEnumArgBuf;

class TConnectionClientInfo
/**
@publishedPartner
@released since v7.0s
*/
	{
public:
	inline TConnectionClientInfo();
	inline TConnectionClientInfo(TUint aProcId, TUint aUid, TUint aThreadId);
public:
	TProcessId iProcessId;
	TUid iUid;
	TThreadId iThreadId;
	};

class TConnectionGetClientInfoArg : public TConnArgBase
/**
for KCoGetConnectionClientInfo
@publishedPartner
@released since v7.0s
*/
	{
public:
	inline TConnectionGetClientInfoArg();
public:
	TUint iIndex;
	TConnectionClientInfo iClientInfo;
	};

/**
@internalComponent
*/
typedef TPckgBuf<TConnectionGetClientInfoArg> TConnGetClientInfoArgBuf;

class TConnectionSocketInfo
/**
@internalComponent
*/
	{
public:
	inline TConnectionSocketInfo();
public:
	TUint iAddressFamily;
	TUint iProtocol;
	TSockAddr iSourceAddress;
	TSockAddr iDestinationAddress;
	};

class TConnectionGetSocketInfoArg : public TConnArgBase
/**
for KCoGetConnectionSocketInfo

@internalComponent
*/
	{
public:
	TConnectionGetSocketInfoArg();
public:
	TUint iIndex;
	TConnectionSocketInfo iSocketInfo;
	};

/**
@internalComponent
*/
typedef TPckgBuf<TConnectionGetSocketInfoArg> TConnGetSocketInfoArgBuf;

#include <es_enum.inl>

#endif // __ES_ENUM_H__
