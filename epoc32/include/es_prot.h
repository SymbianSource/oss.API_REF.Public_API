// Copyright (c) 1997-2009 Nokia Corporation and/or its subsidiary(-ies).
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

#if !defined(__ES_PROT_H__)
#define __ES_PROT_H__


#include <es_enum.h>

/**
ESock subsession unique id
@internalTechnology
*/
typedef TUint TSubSessionUniqueId;

/**
@internalComponent
*/
enum TConnStartType 
	{
	EConnStartExplicit,
	EConnStartImplicit
	};	

/**
@internalComponent
*/
enum TESOCKActivePriority
	{
	ESSExclusivePriority=100000,
	ECommReceivePriority=200,		///< Must always run.
	ECommTransmitPriority=100,
	ECAsyncImmediatePriority=75,	///< I.e. before a timer event goes off.
	ESocketTimerPriority=50,
	EActiveIpcPriority=20,
	EActiveHighPriority=10,
	EActiveMedPriority=0,
	EActiveLowPriority=-10,
	ECAsyncDeferredPriority=-20,
	};

/**
End of data,Socket can't receive more data.
@publishedPartner
@released
*/
const TUint KNewDataEndofData = 0xFFFFFFFF;

class CServProviderBase;
class CSocket;

class MSocketNotify
/** Abstract base class used by a CServProviderBase-derived object, through its 
iSocket member, to notify the socket server that various events have occurred. 

The class provides several up-call member functions.

All up-calls on an MSocketNotify should be made in the context of the socket 
server's thread - i.e. the thread which called NewSAPL() on the protocol. 

@publishedPartner
@released Since v5.0 */
	{
public:
	/** Delete and detach flags. */
	enum TDelete 
		{
		/** Delete SAP */	
		EDelete,
		/** Don't delete SAP */
		EDetach
		};
	/** Error codes. */
	enum TOperationBitmasks
		{
		/** An error has occurred which affects Send() operations */
		EErrorSend=0x0000001,  

		/** An error has occurred which affects Receive() operations. */
		EErrorRecv=0x0000002,

		/** An error has occurred which affects Connect() operations */
		EErrorConnect=0x0000004,

		/** An error has occurred which affects Close() operations */
		EErrorClose=0x00000008,

		/** An error has occurred which affects Ioctl() operations */
		EErrorIoctl=0x00000010,

		/** A fatal error has occurred */
		EErrorFatal=0x10000000,
		
		/** An error has occurred which affects all operations */
		EErrorAllOperations=0x7fffffff,
		};
	
	/**
	Indicates that new data is available on a service access point

	For a stream-oriented protocol aCount should be a byte count; for datagram-oriented 
	sockets aCount should be a datagram count.
	
	@note aCount is the amount of new data, not the total amount of data waiting 
	to be read.
	
	@param aCount The amount of new data. A value of KNewDataEndofData indicates 
	that the socket is in a half-closed state and will receive no more data. Any subsequent 
	reads will complete with KErrEof and a length of 0. */
	virtual void NewData(TUint aCount) = 0;
	/** Indicates that new buffer space is available on a service. */
	virtual void CanSend() = 0;
	/** Indicates that a connection attempt has completed successfully (for active opens).
	 
	There are four versions of this up-call: two are for active opens and two are for passive 
	opens. Both active and passive versions support a variant carrying user connection 
	data for protocols which support it.
	
	@note A connection-less protocol should never call the ConnectComplete() up-calls.
	@note A protocol should keep a count of sockets which have called ConnectComplete() 
	but have not had Start() called. Sockets in this state have their Error() 
	and NewData() calls deferred until Start() is called.*/
	virtual void ConnectComplete() = 0;
	/** Indicates that a connection attempt has completed successfully (for active opens).
	 
	There are four versions of this up-call: two are for active opens and two are for passive 
	opens. Both active and passive versions support a variant carrying user connection 
	data for protocols which support it.
	
	@note A connection-less protocol should never call the ConnectComplete() up-calls.
	@note A protocol should keep a count of sockets which have called ConnectComplete() 
	but have not had Start() called. Sockets in this state have their Error() 
	and NewData() calls deferred until Start() is called.
	
	@param aConnectData Connect data (if supported).
	*/
	virtual void ConnectComplete(const TDesC8& aConnectData) = 0;
	/** Indicates that a connection attempt has completed successfully (for passive opens). 
	
	There are four versions of this up-call: two are for active opens and two are for passive 
	opens. Both active and passive versions support a variant carrying user connection 
	data for protocols which support it.
	
	The versions of ConnectComplete() for passive opens carry a new SSP (socket service 
	provider, or SAP) for the newly created socket. A new socket will then be linked up to 
	the SSP and data transfer can take place. The original socket stays listening.
	
	@note A connection-less protocol should never call the ConnectComplete() up-calls.
	@note A protocol should keep a count of sockets which have called ConnectComplete() 
	but have not had Start() called. Sockets in this state have their Error() 
	and NewData() calls deferred until Start() is called.
	
	@param aSSP The new SSP for passive opens. 
	*/
    virtual void ConnectComplete(CServProviderBase& aSSP) = 0;
	/** Indicates that a connection attempt has completed successfully (for passive opens). 
	
	There are four versions of this up-call: two are for active opens and two are for passive 
	opens. Both active and passive versions support a variant carrying user connection 
	data for protocols which support it.
	
	The versions of ConnectComplete() for passive opens carry a new SSP (socket service 
	provider, or SAP) for the newly created socket. A new socket will then be linked up to 
	the SSP and data transfer can take place. The original socket stays listening.
	
	@note A connection-less protocol should never call the ConnectComplete() up-calls.
	@note A protocol should keep a count of sockets which have called ConnectComplete() 
	but have not had Start() called. Sockets in this state have their Error() 
	and NewData() calls deferred until Start() is called.
	
	@param aSSP The new SSP for passive opens. 
	@param aConnectData Connect data (if supported). */
	virtual void ConnectComplete(CServProviderBase& aSSP,const TDesC8& aConnectData) = 0;
	/** Indicates that the SAP has finished closing down. 
	
	This up-call is the response to a Shutdown(). A connection-oriented protocol should call 
	CanClose() when it has terminated communications with the remote host. Protocols can call 
	CanClose() from within their Shutdown() code. After CanClose() has been called, an SAP may 
	be deleted by the socket server.
	
	@note The protocol must not access the CServProviderBase object after calling CanClose().
	@param aDelete Delete SAP. 
	*/
	virtual void CanClose(TDelete aDelete=EDelete) = 0;
	/** Indicates that the SAP has finished closing down. 
	
	This up-call is the response to a Shutdown(). A connection-oriented protocol should call 
	CanClose() when it has terminated communications with the remote host. Protocols can call 
	CanClose() from within their Shutdown() code. After CanClose() has been called, an SAP may 
	be deleted by the socket server.
	
	@note The protocol must not access the CServProviderBase object after calling CanClose().
	@param aDisconnectData Any user data carried on the disconnect frame.
	@param aDelete Delete SAP. 
	*/
	virtual void CanClose(const TDesC8& aDisconnectData,TDelete aDelete=EDelete) = 0;
	/** Tells the socket server that an error state has arisen within the protocol. 
	
	It should not be used to report programmatic errors, either in the protocol 
	itself or the socket server (a panic should be used in these cases). When 
	Error() is called on a connection-oriented socket, the socket is moved into 
	a dead state which denies user access to it.
	
	@param anError KErrNone or another of the system-wide error codes. 
	@param anOperationMask A bitmask of TOperationBitmasks values specifying which 
	pending operations are affected by the Error up-call. */
	virtual void Error(TInt anError,TUint anOperationMask=EErrorAllOperations) = 0;
	/** Indicates that the other end of a connection has disconnected.
	
	This is analogous to CanClose(), but in this case the other end initiated it. 
	
	Once the client has called Shutdown() it is	illegal to call Disconnect(). Instead, 
	CanClose() or Error(KErrDisconnected) should be called.
	*/
	virtual void Disconnect(void) = 0;
	/** Indicates that the other end of a connection has disconnected.
	
	This is analogous to CanClose(), but in this case the other end initiated it. 
	
	Once the client has called Shutdown() it is	illegal to call Disconnect(). Instead, 
	CanClose() or Error(KErrDisconnected) should be called. 
	
	@param aConnectData User data in the disconnect frame.
	*/
	virtual void Disconnect(TDesC8& aDisconnectData) = 0;
	/** Indicates that the currently pending Ioctl has completed.
	
	The parameter aBuf is protocol defined - in fact it is defined by the specific 
	Ioctl.
	
	@param aBuf Any data requested by the Ioctl operation. */
	virtual void IoctlComplete(TDesC8* aBuf) = 0;

	/**
	Indicates that there are no bearer available

	@param  aConnectionParams, the connection parameters.
	*/
	virtual void NoBearer(const TDesC8& aConnectionParams) = 0;

	/**
	Indicates the bearer available.

	@param aConnectionInfo, Information about socket connection.
	*/
	virtual void Bearer(const TDesC8& aConnectionInfo) = 0;

	/**
	Indicates that this socket is now completed an asynchronous join
	with a sub-connection. It now can use the properties of the sub-connection
	*/
	virtual void JoinedSubConnection() {;};

	/**
	Indicates that this socket was not able to complete an asynchronous join
	with a sub-connection. The socket is still joined, but cannot use the
	properties of the sub-connection
	
	@param aError Reason the socket could not be joined
	*/
	virtual void SubConnectionJoinFailed(TInt /*aError*/) {;};

	/**
	Indicates that this socket has now completed an asynchronous leave
	from a sub-connection. The socket is now connected to the sub-connection
	anymore.
	*/
	virtual void LeftSubConnection() {;};

private:
	};


class TNifProgress;

class MConnectionNotify
/**
 * Callback interface from CConnectionProvdBase-derived classes
 * @internalTechnology
 */
	{
public:
	virtual void SelectionComplete(TInt aError, const TDesC8& aSelectionInfo) = 0;
	virtual void ConnectionError(TInt aError) = 0;
	virtual void LinkLayerOpen(TInt aError) = 0;
	virtual void LinkLayerClosed(TInt aError) = 0;
	virtual void ProgressNotification(TInt aStage, TInt aError) = 0;
	virtual void ProgressNotification(TSubConnectionUniqueId aSubConnectionUniqueId, TInt aStage, TInt aError) = 0;
	virtual void ServiceChangeNotification(TUint32 aId, const TDesC& aType) = 0;
	virtual void InterfaceStateChangeNotification(TDesC8& aInfo) = 0;
	virtual void NotifyDataSent(TSubConnectionUniqueId aSubConnectionUniqueId, TUint aUplinkVolume) = 0;
	virtual void NotifyDataReceived(TSubConnectionUniqueId aSubConnectionUniqueId, TUint aDownlinkVolume) = 0;
	
	virtual void SubConnectionEvent(const TSubConnectionEvent& aSubConnectionEvent) = 0;
	};

/**
@internalComponent
*/
enum TProtocolServiceInfo
	{
	ESocketSupport=0x00000001,		///< Can make sockets
	ETransport=0x00000002,			///< Can act as a transport - ie can be bound to
	EPreferMBufChains=0x00000004,	///< Will process MBufChains (I.e. won't convert them to descriptors)
	EPreferDescriptors=0x00000008,	///< Will process Descriptors (I.e. won't convert them to MBufChains)
	ECantProcessMBufChains=0x00000010,	///< Will Panic if asked to process an MBufChain
	ENeedMBufs=0x00000020,			///< Uses MBufChains internally.
	EUseCanSend=0x00000040,			///< Uses the inter-protocol CanSend upcall.
	EInterface=0x00000080,			///< Is a CInterfaceBase rather than CProtocolBase
	};

/**
@internalTechnology
*/
enum TProtocolType
	{
	ENormalProtocol,				///< Normal protocol
	EInterfaceProtocol				///< Has EInterface flags set and supports GetBinderL()
	};

/**
@internalComponent
*/
const TInt KUnlimitedSockets=-1;

struct TServerProtocolDesc : public TProtocolDesc
/**
Contains data that describes a particular protocol. 
@publishedPartner
@released

@see CProtocolFamilyBase::ProtocolList(). 
*/
	{
	TInt iServiceTypeInfo;  ///< Set this to 1 if the protocol supports socket creation
	TInt iNumSockets;       ///< The maximum number of SSPs the protocol supports
	};


class MResolverNotify
/**
@publishedPartner
@released
*/
	{
public:
	virtual void QueryComplete(TInt anError)=0;
	};

/** Ensure that the requested length for datagrams is bigger than any real one. This ensures that
naive providers deliver them without truncation, so allowing the client to perform continuation reads.
@internalTechnology
*/
const TUint KGetDataWholeDatagram = 0x40000000;

/**
Security checker class passed down to providers which is used to perform security checks on the client
of the provider.  The provider calls the CheckPolicy(...) method with a suitable TSecurityPolicy
class and a diagnostic string as arguments.

@see CServProviderBase
@see CResolverProvdBase

@code
_LIT_SECURITY_POLICY_C1(myPolicy1, ECapabilityNetworkServices);
...
TInt CMyProvider::SecurityCheck(MProvdSecurityChecker *aChecker)
{
	...
	if (aChecker->CheckPolicy(myPolicy1, "CMyProvider main") == KErrNone)
	{
		// client has NetworkServices capability
	}
	...
}
@endcode

@publishedPartner
@released
*/
class MProvdSecurityChecker 
{
public:
	/**
	Check the security policy of a client process.
	
	Called from a socket or resolver provider to check whether the client process conforms to a security policy.
	
	@param aPolicy A TSecurityPolicy class instance containing the security information to be checked against the client.
	@param aDiagnostic A diagnostic string used when logging system-wide security failures, else 0.
	@return KErrNone if client process has the required security information, else KErrPermissionDenied.
	(In the future, some other system error may be returned).
	*/
	virtual TInt CheckPolicy(const TSecurityPolicy& aPolicy, const char *aDiagnostic) = 0;
};

class RMBufChain;
class CSubConnectionProviderBase;
class CServProviderBase : public CBase
/** Service Access Point.

Provides transport services to a single protocol. Several of the calls to 
CServProviderBase have pre-conditions attached to them - for example 
a connection oriented protocol must have its local address set (either by 
a SetLocalName() or AutoBind()) before it is opened. If the socket server 
calls the CServProviderBase in such an erroneous way, the protocol should panic.

@publishedPartner
@released Since 5.0 */
	{
	friend class ProtocolManager;
public:

	/** Describes the behaviour the SAP should take on shutdown.*/
	enum TCloseType 
	{
		ENormal,        ///< The protocol should shutdown gracefully — no further input or output will be requested.
		EStopInput,     ///< The protocol should shut down gracefully — all further and pending input should be discarded.
		EStopOutput,    ///< The protocol should shutdown gracefully — all pending output should be discarded.
		EImmediate      ///< The protocol should close the connection immediately and free all resources without performing a graceful disconnect.
	};
	IMPORT_C CServProviderBase();
	IMPORT_C virtual ~CServProviderBase();

	IMPORT_C virtual void SetNotify(MSocketNotify* aSocket);
	//V1.0 itf support
	IMPORT_C virtual void SetSockType(TUint aSockType);
	IMPORT_C TUint SockType() const;

	IMPORT_C virtual void JoinSubConnectionL(CSubConnectionProviderBase& aSubConnProvider);
	IMPORT_C virtual void LeaveSubConnection(CSubConnectionProviderBase& aSubConnProvider);

public:

/**
pure virtual
*/
	/**
	Start a service provider.
	*/
	virtual void Start()=0;
	/** Gets the local name (address) of the socket service provider entity. The format 
	of the data in the TSockAddr object is defined by individual protocols.
	
	The local address is the address of the local machine plus a local port number. 
	Generally only the port number is important, unless you have two IP interfaces, 
	for example.
	
	@param anAddr The address to be filled in */
	virtual void LocalName(TSockAddr& anAddr) const =0;
	/** Sets the local name (address) of the socket service provider entity. The format 
	of the data in the TSockAddr object is defined by individual protocols.
	
	@param anAddr The address 
	@return Returns KErrNone if the local name is correctly set or, if this is 
	not the case, an informative error number. */
	virtual TInt SetLocalName(TSockAddr& anAddr)=0;
	/** Gets the remote name (address) of the socket service provider entity. The format 
	of the data in the TSockAddr object is defined by individual protocols.
	
	A remote address is either the address you're sending data to (non connection-oriented 
	sockets)* or the remote end of the connection. It is the address of the remote 
	machine (your peer in the network) plus a port number.
	
	@note RemName is only meaningful if the socket server client has called Connect() 
	to set up a default address for SendTo(). This function will only be called 
	on the protocol if this is the case.
	
	@param anAddr The address to be filled in */
	virtual void RemName(TSockAddr& anAddr) const =0;
	/** Sets the remote name (address) of the socket service provider entity. The format 
	of the data in the TSockAddr object is defined by individual protocols.
	
	@param anAddr The address 
	@return Returns KErrNone if the remote name is correctly set or, if this is 
	not the case, an informative error number. */
	virtual TInt SetRemName(TSockAddr& anAddr)=0;
	/** Gets some protocol specific option when called by the socket server on behalf of a 
	client. A protocol may pass the request down a protocol	stack (to protocols it is bound 
	to) using the GetOption() function of CProtocolBase.
	
	@param aLevel Option level.
	@param aName Option name.
	@param anOption Option data.
	@return System wide error code.
	*/
	virtual TInt GetOption(TUint level,TUint name,TDes8& anOption)const =0;
	/** Performs some protocol specific IO control. 
	
	@note If this function is called erroneously, the protocol should call Error() on the 
	socket. If an Ioctl call is already outstanding, the client will be panicked with the 
	value ETwoIoctls.
	
	@param aLevel Option level.
	@param aName Option name.
	@param anOption Option data.
	@return System wide error code.
	*/
	virtual void Ioctl(TUint level,TUint name,TDes8* anOption)=0;
	/** Cancels an outstanding Ioctl call. You are guaranteed only to have one outstanding 
	at once. 
	
	@param aLevel IOCTL level. 
	@param aName IOCTL name. 
	*/
	virtual void CancelIoctl(TUint aLevel,TUint aName)=0;
	/** Sets some protocol specific option when called by the socket server on behalf of a 
	client. A protocol may pass the request down a protocol	stack (to protocols it is bound 
	to) using the SetOption() function	of CProtocolBase.
	
	@param aLevel Option level.
	@param aName Option name.
	@param anOption Option data.
	@return System wide error code.
	*/
	virtual TInt SetOption(TUint level,TUint name,const TDesC8& anOption)=0;
	virtual void ActiveOpen()=0;
	/** Initiates a connection operation - this means that it tells the protocol to 
	attempt to connect to a peer. It is called by the socket server in response 
	to a connect request from a client. 
	
	This version of the function has user data in the connection frame.
	
	Only ever called on connection-oriented sockets. Such a socket 
	should always have both the local address and the remote address specified 
	before this function is called. If this is not the case then the protocol 
	should panic.
	
	When a connection has completed, the protocol should call ConnectComplete() 
	on its TNotify. If an error occurs during connection the protocol should not 
	call ConnectComplete() at all; instead it should call Error().
	
	@param aConnectionData If the protocol supports user specified connection 
	data, then it will be held in this buffer. */
	virtual void ActiveOpen(const TDesC8& aConnectionData)=0;
	/** Tells the protocol to start waiting for an incoming connection request on this 
	socket (i.e. port). It is called by the socket server in response to a listen 
	request from a client.
	
	Only ever called on connection-oriented sockets. Such a socket 
	should always have both the local address and the remote address specified 
	before this function is called. If this is not the case, then the protocol 
	should panic.
	
	The aQue parameter is the number of sockets which can be waiting for an outstanding 
	Start after calling ConnectComplete(). The protocol should keep a count of 
	sockets in this state - incrementing a variable in ConnectComplete(), and 
	decrementing it in Start().
	
	When a connection has completed, the protocol should call ConnectComplete() 
	on its TNotify. If an error occurs during connection the protocol should not 
	call ConnectComplete() at all; instead it should call Error().
	
	@param aQueSize Size of connect queue. 
	*/
	virtual TInt PassiveOpen(TUint aQueSize)=0;
	/** Tells the protocol to start waiting for an incoming connection request on this 
	socket (i.e. port). It is called by the socket server in response to a listen 
	request from a client.
	
	This version of the function has user data in the connection frame.
	
	Only ever called on connection-oriented sockets. Such a socket 
	should always have both the local address and the remote address specified 
	before this function is called. If this is not the case then the protocol 
	should panic.
	
	The aQue parameter is the number of sockets which can be waiting for an outstanding 
	Start after calling ConnectComplete(). The protocol should keep a count of 
	sockets in this state - incrementing a variable in ConnectComplete(), and 
	decrementing it in Start().
	
	When a connection has completed the protocol should call ConnectComplete() 
	on its TNotify. If an error occurs during connection the protocol should not 
	call ConnectComplete() at all; instead it should call Error().
	
	@param aQueSize size of connect queue 
	@param aConnectionData if the protocol supports user specified connection data 
	then it will be held in this buffer. */
	virtual TInt PassiveOpen(TUint aQueSize,const TDesC8& aConnectionData)=0;
	/** Terminates a connection (or closes a non connection-oriented socket down).
	 
	The value of the option argument specifies the type of processing which will 
	be required of the protocol after this function is called.
	
	Normally, when the socket server has called Shutdown() for a socket, it will 
	wait for the socket to call CanClose() before destroying the CServProviderBase 
	object. However, if the option argument is EImmediate, the CServProviderBase 
	will be destroyed as soon as Shutdown() returns.
	
	@param option The shutdown type. */
	virtual void Shutdown(TCloseType option)=0;
	/** Terminates a connection (or closes a non connection-oriented socket down). 
	
	The value of the option argument specifies the type of processing which will 
	be required of the protocol after this function is called.
	
	Normally, when the socket server has called Shutdown() for a socket, it will 
	wait for the socket to call CanClose() before destroying the CServProviderBase 
	object. However, if the option argument is EImmediate, the CServProviderBase 
	will be destroyed as soon as Shutdown() returns.
	
	@param option The shutdown type. 
	@param aDisconnectionData If the protocol supports disconnect data, any such 
	data required will be held in this buffer. */
	virtual void Shutdown(TCloseType option,const TDesC8& aDisconnectionData)=0;
	/** Specifies that the protocol should choose a local address for the service access 
	point itself. */
	virtual void AutoBind()=0;

// protocol read/write data; ESock v1.5 calls down to the v1.5 itf (RMBufChain). 
// v1.5-ready protocols implement this, laggard protocols inherit these base class
// implementations which call the v1.0 descriptor itf instead. 

	/** Sends data onto the network via the protocol.
	
	Connection-oriented sockets must be in a connected state (that is ConnectComplete() has 
	been called on their MSocketNotify before Write() is called).
	 
	The socket server keeps track of how much data is waiting and then tries to send it all 
	until the protocol tells it to hold off by returning 0 (datagram sockets) or 'less than 
	all data consumed' (stream sockets) to Write(). The protocol should call CanSend() when it 
	is ready to send more data.
	
	anAddr is the address to write the data to.	Connection oriented sockets always use the 
	default value.
	
	@param aDesc The data to be sent.
	@param aOptions Protocol specific options.
	@param anAddr Address to write the data to.
	
	@returns For stream-oriented protocols the return value is the number of bytes actually written. 
	If this is less than the length of the descriptor then the protocol should call CanSend() 
	when it is ready to send more data. For datagram-oriented protocols, the write should return 
	either 0 if the write cannot be completed, or the length of the descriptor if the write succeeds - 
	no other values are valid. If the Write() must return 0, then it should call CanSend() when it is 
	ready to send more data. If the Write() fails due to some error, then it should call Error() with 
	an informative error number.
	*/
	IMPORT_C virtual TUint Write(const TDesC8& aDesc,TUint options, TSockAddr* anAddr=NULL);
	/** Sends data onto the network via the protocol.
	
	Connection-oriented sockets must be in a connected state (that is ConnectComplete() has 
	been called on their MSocketNotify before Write() is called).
	 
	The socket server keeps track of how much data is waiting and then tries to send it all 
	until the protocol tells it to hold off by returning 0 (datagram sockets) or 'less than 
	all data consumed' (stream sockets) to Write(). The protocol should call CanSend() when it 
	is ready to send more data.
	
	anAddr is the address to write the data to.	Connection oriented sockets always use the 
	default value.
	
	@param aData The data to be sent.
	@param aOptions Protocol specific options.
	@param anAddr Address to write the data to.
	
	@returns For stream-oriented protocols the return value is the number of bytes actually written. 
	If this is less than the length of the descriptor then the protocol should call CanSend() 
	when it is ready to send more data. For datagram-oriented protocols, the write should return 
	either 0 if the write cannot be completed, or the length of the descriptor if the write succeeds - 
	no other values are valid. If the Write() must return 0, then it should call CanSend() when it is 
	ready to send more data. If the Write() fails due to some error, then it should call Error() with 
	an informative error number.
	*/
	IMPORT_C virtual TInt Write(RMBufChain& aData, TUint aOptions, TSockAddr* anAddr=NULL);

	/** Gets data which the protocol has indicated is waiting in its buffers using the NewData 
	up-call on the MSocketNotify. 
	
	GetData() will only ever be called for as much data as the protocol has specified it can process 
	using the NewData up-call. 
	
	For stream oriented protocols GetData() should fill the descriptor with data from the stream. On 
	a datagram protocol GetData() should copy one datagram into the descriptor and set the length of 
	the descriptor. If a full datagram will not fit into the supplied descriptor, the overflow should 
	be discarded. 
	
	anAddr should be filled in by the protocol with the address of where the data came from.
	
	@param aDesc  The buffer for data.
	@param aOptions Protocol specific options.
	@param anAddr Address where the data came from.
	*/
	IMPORT_C virtual void GetData(TDes8& aDesc,TUint options,TSockAddr* anAddr=NULL);
	/** Gets data which the protocol has indicated is waiting in its buffers using the NewData 
	up-call on the MSocketNotify. 
	
	GetData() will only ever be called for as much data as the protocol has specified it can process 
	using the NewData up-call. 
	
	For stream oriented protocols GetData() should fill the descriptor with data from the stream. On 
	a datagram protocol GetData() should copy one datagram into the descriptor and set the length of 
	the descriptor. If a full datagram will not fit into the supplied descriptor, the overflow should 
	be discarded. 
	
	anAddr should be filled in by the protocol with the address of where the data came from.
	
	@param aDesc  The buffer for data.
	@param aOptions Protocol specific options.
	@param anAddr Address where the data came from.
	*/
	IMPORT_C virtual TInt GetData(RMBufChain& aData, TUint aLength, TUint aOptions, TSockAddr* anAddr=NULL);

	/**  Use the class instance argument to perform security policy checks on the originating client process.
	
	This method is called when a SAP is created and when a socket is transferred between sessions.  The SAP is
	required to check whether the originating client process has enough privileges to request services from the SAP.
	The MProvdSecurityChecker class instance is used to perform security policy checks.  The SAP may choose
	to perform a security policy check in its SecurityCheck(...) method, or it may choose to store the
	MProvdSecurityChecker class instance argument and perform checking later (i.e. when subsequent
	SAP methods are called).
	
	@param aSecurityChecker Pointer to class used by SAP to perform security checks on the client process.  This
	pointer becomes invalid when the SAP is destroyed or detached.
	@returns KErrPermissionDenied if SAP wishes to disallow access to the client, else KErrNone.  This would
	normally be as a result of calling MProvdSecurityChecker::CheckPolicy(...) with a suitable security policy argument.
	*/
	IMPORT_C virtual TInt SecurityCheck(MProvdSecurityChecker *aSecurityChecker);
	
protected:
	/** On socket creation, the socket server sets this member to point to a server 
	notification interface. */
	MSocketNotify* iSocket;
private:
	//V1.0 interface support specifics
	HBufC8* iV1ShimDataIn;
	HBufC8* iV1ShimDataOut;
	TUint iSockType;
	};

class CProtocolBase;
class CResolverProvdBase : public CBase
/**
@publishedPartner
@released
*/
	{
	friend class ProtocolManager;
public:
	inline void SetNotify(MResolverNotify* aNotifier);

	/**
	@internalComponent
	*/
	virtual void CancelCurrentOperation()=0;

	/**  Use the class instance argument to perform security policy checks on the originating client process.
	
	This method is called when a resolver is created.  The resolver is required to check whether the originating
	client process has enough privileges to request services from the resolver.  The MProvdSecurityChecker
	class instance is used to perform security policy checks.  The resolver may choose to perform a security
	policy check in its SecurityCheck(...) method, or it may choose to store the MProvdSecurityChecker class
	instance argument and use it to perform checking later (i.e. when subsequent resolver methods are called).
	
	@param aSecurityChecker Pointer to class used by resolver to perform security checks on the client process.  This
	pointer becomes invalid when the resolver is destroyed or detached.
	@returns KErrPermissionDenied if resolver wishes to disallow access to the client, else KErrNone.  This would
	normally be as a result of calling MProvdSecurityChecker::CheckPolicy(...) with a suitable security policy argument.
	*/
	IMPORT_C virtual TInt SecurityCheck(MProvdSecurityChecker *aSecurityChecker);
	
protected:
	MResolverNotify* iNotify;
private:
	CProtocolBase* iProtocol;
	};

class CHostResolvProvdBase : public CResolverProvdBase
/**
Provides Host name resolver service
@publishedPartner
@released
*/
	{
	friend class ProtocolManager;
public:

	/**
	Get the Host name by name
	@param aName, results of name queries
	*/
	virtual void GetByName(TNameRecord& aName)=0;

	/**
	Gets the Host name by address
	@param aName, results of name queries
	*/
	virtual void GetByAddress(TNameRecord& aName)=0;

	/**
	Sets the Host name
	@param aNameBuf, name to set
	*/
	virtual void SetHostName(TDes& aNameBuf)=0;

	/**
	Gets the Host name 
	@param aNameBuf, name to retrieve
	*/
	virtual void GetHostName(TDes& aNameBuf)=0;
	IMPORT_C virtual TInt SetOption(TUint level,TUint name,const TDesC8& anOption);
    IMPORT_C virtual void Query(const TDesC8& aQryBuf, TDes8& aResBuf, TInt aCounter);
	};

class CServiceResolvProvdBase : public CResolverProvdBase
/**
@publishedPartner
@released
*/
	{
	friend class ProtocolManager;
public:
	
	/**
	Get the Host name by name
	@param aName, results of name queries
	*/
	virtual void GetByName(const TDesC& aNameBuf,TInt32& aPortNum)=0;
	
	/**
	Gets the Host name by address
	@param aName, results of name queries
	*/
	virtual void GetByNumber(TDes& aNameBuf,TInt32 aPortNum)=0;
	
	/**
	Sets the Host name
	@param aNameBuf, name to set
	*/
	virtual void RegisterService(const TDesC& aNameBuf,TInt32 aPortNum)=0;
	
	/**
	Gets the Host name 
	@param aNameBuf, name to retrieve
	*/
	virtual void RemoveService(const TDesC& aNameBuf,TInt32 aPortNum)=0;
	};

class CNetDBProvdBase : public CResolverProvdBase
/**
Provides network Database access
@publishedPartner
@released
*/
	{
	friend class ProtocolManager;
public:
	virtual void Query(TDes8& aBuffer)=0;
	virtual void Add(TDes8& aBuffer)=0;
	virtual void Remove(TDes8& aBuffer)=0;
	};

/**
Definition of argument to CConnectionProvdBase::SetUsageProfile()
Bitmap masks

@internalTechnology
*/
const TUint KConnProfileNone = 0;

/**
Definition of argument to CConnectionProvdBase::SetUsageProfile()
Bitmap masks

@internalTechnology
*/
const TUint KConnProfileLong = 1;

/**
Definition of argument to CConnectionProvdBase::SetUsageProfile()
Bitmap masks

@internalTechnology
*/
const TUint KConnProfileMedium = 2;

class TConnPref;
class CSubConnectionProviderBase;
class CNifIfBase;

class CConnectionProvdBase : public CBase
/**
 * Base class for connection providers (currently nifman)
 * @internalTechnology
 */
	{
	friend class ProtocolManager;
	friend class CConnection;
	friend class CConnectionSettingsShim; //to access the virtual "Do" db functions directly
public:
	IMPORT_C virtual ~CConnectionProvdBase();

	IMPORT_C TUint Id() const;
	IMPORT_C void SetConnectionProviderClient(MConnectionNotify* aClient);
	MConnectionNotify* ConnectionProviderClient();


	// SubConnectionProvider Management
	void JoinL(CSubConnectionProviderBase& aSubConnProvider);
	void Leave(CSubConnectionProviderBase& aSubConnProvider);

	virtual void StartL(TConnStartType aConnectType, const RMessagePtr2* aMessage) = 0;
	virtual void StartL(TConnStartType aConnectType, const TConnPref& aPref, const RMessagePtr2* aMessage) = 0;
	virtual void AttachToConnectionL(const TDesC8& aConnectionInfo, TBool aMonitorAttach, const RMessagePtr2* aMessage) = 0;
	virtual TInt Stop(TInt aError, const RMessagePtr2* aMessage) = 0;
	virtual void ProgressL(TNifProgressBuf& aBuffer) const = 0;
	virtual void ProgressL(TSubConnectionUniqueId aSubConnectionUniqueId, TNifProgressBuf& aBuffer) const = 0;
	virtual void LastProgressError(TNifProgressBuf& aBuffer) = 0;
	virtual void RequestServiceChangeNotificationL() = 0;
	virtual void CancelServiceChangeNotification() = 0;
	virtual void EnumerateConnectionsL(RPointerArray<TConnectionInfo>& aConnectionInfoPtrArray) = 0;
	virtual TBool AllInterfaceNotificationL() = 0;
	virtual void ControlL(TUint aOptionLevel, TUint aOptionName, TDes8& aOption, const RMessagePtr2* aMessage) = 0;
	virtual void SetUsageProfile(TUint aProfile) = 0;

	/**
	Stop the specified subconnection

	@param aSubConnectionUniqueId The id of the subconnection to be stopped
	@param aError The error code to be propogated to the clients of the subconnection
	*/
	virtual TInt Stop(TSubConnectionUniqueId aSubConnectionUniqueId, TInt aError, const RMessagePtr2* aMessage)=0;

	/**
	Find out the number of subconnetions on a connection

	@param aCount On return, contains the number of subconnections
	*/
	virtual TInt EnumerateSubConnections(TUint& aCount)=0;

	/**
	Get information about a subconnection specified only by generic index

	@param aIndex 
	@param aSubConnectionInfo An appropriate SubConnectionInfo-derived class; on return, this is filled in
	*/
	virtual TInt GetSubConnectionInfo(TUint aIndex, TDes8& aSubConnectionInfo)=0;

	/**
	Get information about a subconnection specifed by its unique id

	@param aSubConnectionInfo An appropriate SubConnectionInfo-derived class containing a valid TSubConnectionUniqueId; on return, this is filled in
	*/
	virtual TInt GetSubConnectionInfo(TDes8& aSubConnectionInfo)=0;

	/**	
	Register for all subconnection notifications
	*/
	virtual TInt AllSubConnectionNotificationEnable()=0;

	/**
	Cancel registration for AllSubConnectionNotification	
	*/
	virtual TInt CancelAllSubConnectionNotification()=0;

	/**
	Find out how much data has been sent and received

	@param aSubConnectionUniqueId The id of the subconnection to which this request refers
	@param aUplinkVolume The total number of bytes sent on this subconnection
	@param aDownlinkVolume The total number of bytes received on this subconnection
	*/
	virtual TInt DataTransferred(TSubConnectionUniqueId aSubConnectionUniqueId, TUint& aUplinkVolume, TUint& aDownlinkVolume)=0;

	/**
	Cancel a request for the amount of data sent and received

	@param aSubConnectionUniqueId The id of the subconnection that this request refers to
	@note At present this method is never called, as this is a synchronous operation on the server side
	*/
	virtual TInt DataTransferredCancel(TSubConnectionUniqueId aSubConnectionUniqueId)=0;

	/**
	Make a request for notifications about data sent at the specifed granularity on a specified subconnection

	@param aSubConnectionUniqueId The id of the subconnection to which this request refers
	@param aUplinkGranularity The granularity in bytes at which notifications should be sent
	*/
	virtual TInt SetDataSentNotificationGranularity(TSubConnectionUniqueId aSubConnectionUniqueId, TUint aUplinkGranularity)=0;

	/**
	Cancel a request for notifications about data sent on a specified subconnection

	@param aSubConnectionUniqueId The id of the subconnection to which this request refers
	*/
	virtual TInt DataSentNotificationCancel(TSubConnectionUniqueId aSubConnectionUniqueId)=0;

	/**
	Make a request for notifications about data received at the specifed granularity on a specified subconnection

	@param aSubConnectionUniqueId The id of the subconnection to which this request refers
	@param aDownlinkGranularity The granularity in bytes at which notifications should be sent
	*/
	virtual TInt SetDataReceivedNotificationGranularity(TSubConnectionUniqueId aSubConnectionUniqueId, TUint aDownlinkGranularity)=0;

	/**
	Cancel a request for notifications about data received on a specified subconnection

	@param aSubConnectionUniqueId The id of the subconnection to which this request refers
	*/
	virtual TInt DataReceivedNotificationCancel(TSubConnectionUniqueId aSubConnectionUniqueId)=0;

   /**
    * SendIoctlMessageL forwards Ioctl request to the target
    * Important - message has to be completed by the target. There is no notification back
    *       to the caller => meant for forwarding Ioctl messages the forwarding path is not really
    *       interested in apart from "routing informations"
    * @param aMessage forwarded message (it's the caller's resposibility to forward just Ioctl
    *                   messages)
    */
   	virtual void SendIoctlMessageL(const RMessage2& aMessage) = 0;
   	virtual void SendCancelIoctl() = 0;
   	
//PREQ399_REMOVE
#ifdef SYMBIAN_NETWORKING_3GPPDEFAULTQOS
    virtual CNifIfBase* GetNif(TInt aIndex) = 0;
#endif
//SYMBIAN_NETWORKING_3GPPDEFAULTQOS //PREQ399_REMOVE

	IMPORT_C void GetBoolSettingL(const TDesC& aSettingName, TBool& aValue );
	IMPORT_C void GetBoolSettingL(const TDesC& aSettingName, TBool& aValue, const RMessagePtr2* aMessage );
	IMPORT_C void GetDes16SettingL(const TDesC& aSettingName, TDes16& aValue );
	IMPORT_C void GetDes16SettingL(const TDesC& aSettingName, TDes16& aValue, const RMessagePtr2* aMessage );
	IMPORT_C void GetDes8SettingL(const TDesC& aSettingName, TDes8& aValue );
	IMPORT_C void GetDes8SettingL(const TDesC& aSettingName, TDes8& aValue, const RMessagePtr2* aMessage );
	IMPORT_C void GetIntSettingL(const TDesC& aSettingName, TUint32& aValue );
	IMPORT_C void GetIntSettingL(const TDesC& aSettingName, TUint32& aValue, const RMessagePtr2* aMessage );
	IMPORT_C HBufC* GetLongDesSettingLC(const TDesC& aSettingName, const RMessagePtr2* aMessage );
	IMPORT_C HBufC* GetLongDesSettingLC(const TDesC& aSettingName );

protected:
	IMPORT_C CConnectionProvdBase(TUint aId);
	IMPORT_C void CreateL(MConnectionNotify* aConnection);

	virtual void DoGetIntSettingL(const TDesC& aSettingName, TUint32& aValue, const RMessagePtr2* aMessage ) = 0;
	virtual void DoGetBoolSettingL(const TDesC& aSettingName, TBool& aValue, const RMessagePtr2* aMessage ) = 0;
	virtual void DoGetDes8SettingL(const TDesC& aSettingName, TDes8& aValue, const RMessagePtr2* aMessage ) = 0;
	virtual void DoGetDes16SettingL(const TDesC& aSettingName, TDes16& aValue, const RMessagePtr2* aMessage ) = 0;
	virtual HBufC* DoGetLongDesSettingLC(const TDesC& aSettingName, const RMessagePtr2* aMessage ) = 0;

protected:
	MConnectionNotify* iConnection;
	RPointerArray<CSubConnectionProviderBase> iSubConnProviders;
	TUint iId;
	};

class CProtocolFamilyBase;
class RMBufChain;
class CProtocolRef;
class CProtocolBase : public CBase
/** Protocols created by protocol families must be instances of sub-classes of 
the abstract CProtocolBase.
@publishedPartner
@released Since v5.0 */
	{
	friend class ProtocolManager;
	friend class CProtocolRef;

public:
	IMPORT_C virtual CServProviderBase* NewSAPL(TUint aProtocol);
	IMPORT_C virtual CHostResolvProvdBase* NewHostResolverL();
	IMPORT_C virtual CServiceResolvProvdBase* NewServiceResolverL();
	IMPORT_C virtual CNetDBProvdBase* NewNetDatabaseL();
	IMPORT_C CProtocolBase();
	IMPORT_C virtual ~CProtocolBase();
	CProtocolFamilyBase* ProtocolFamily();
	IMPORT_C virtual void Close();
	IMPORT_C virtual void Open();
	IMPORT_C virtual void CloseNow();
	IMPORT_C virtual void StartSending(CProtocolBase* aProtocol);	// Up
	IMPORT_C TPtrC Tag();
	IMPORT_C virtual void InitL(TDesC& aTag);	// From ProtocolManager before all binding.
	IMPORT_C virtual void StartL();	// From Protocol Manager - after all binding
	IMPORT_C virtual void BindL(CProtocolBase* protocol, TUint id);	// From higher protocol
	IMPORT_C virtual void BindToL(CProtocolBase* protocol);	// From Protocol Manager
	IMPORT_C virtual TInt Send(RMBufChain& aPDU,CProtocolBase* aSourceProtocol=NULL);	// Down
	IMPORT_C virtual TInt Send(TDes8& aPDU,TSockAddr* to,TSockAddr* from=NULL,CProtocolBase* aSourceProtocol=NULL);	// Done
	IMPORT_C virtual void Process(RMBufChain&,CProtocolBase* aSourceProtocol=NULL);	// Up
	IMPORT_C virtual void Process(TDes8& aPDU,TSockAddr* from,TSockAddr* to=NULL,CProtocolBase* aSourceProtocol=NULL);	// Up
	IMPORT_C virtual TInt GetOption(TUint level,TUint name,TDes8& option,CProtocolBase* aSourceProtocol=NULL);	// Down
	IMPORT_C virtual TInt SetOption(TUint level,TUint name,const TDesC8& option,CProtocolBase* aSourceProtocol=NULL);	// Down
	IMPORT_C virtual void Error(TInt anError,CProtocolBase* aSourceProtocol=NULL);	// Up

// Pure virtual
	/** Fills in the passed TServerProtocolDesc with data describing the protocol. 
	
	@param aProtocolDesc Protocol description object to fill in */
	virtual void Identify(TServerProtocolDesc* aProtocolDesc)const =0;	// from anyone.

	inline TInt RefCount() const;
protected:
	IMPORT_C void CanClose();	// Up
private:
	void TryDelete();
protected:
//	TProtocolDesc iDesc;
private:
	CProtocolRef* iManagerRef;
	TInt iRefCount;
	};

class CProtocolFamilyRef;
class CLibUnloader;
class CConnection;
class CConnectionProvdBase;
class CProtocolFamilyBase : public CBase
/** Defines the interface for protocol families. 

Protocol families must:

be able to identify the protocols which they can create

be able to create instances of protocol objects for all the protocols they 
advertise 

@publishedPartner
@released */
	{
friend class ProtocolManager;
friend class CProtocolFamilyRef;
public:
	IMPORT_C virtual ~CProtocolFamilyBase();
	IMPORT_C CProtocolFamilyBase();
	IMPORT_C virtual void Close();
	IMPORT_C virtual void Open();
	IMPORT_C virtual TInt Remove();
	IMPORT_C virtual TBool QueryVersionSupported(const TVersion& aVer) const;

	void SetLibraryL(RLibrary& aLib);

	// Pure virtual
	/** Initialises a protocol family. 
	
	After the CProtocolFamilyBase-derived object has been created, the first function 
	called by the socket server on that object is Install(). It is at this point that the
	CProtocolFamilyBase-derived object should perform any initialisation which it needs.
	
	@return System-wide error code */
	virtual TInt Install()=0;
	/** Creates a new protocol object. 
	
	During socket creation, after the socket server has called Open() on a protocol family, 
	it next calls this function to create an instance of a CProtocolBase-derived object - 
	the protocol itself.
	
	@param aSockType A supported socket type for the protocol family as advertised 
	in the protocol list. 
	@param aProtocol A protocol number specifying a protocol returned by ProtocolList(). 
	
	@return A protocol, or NULL if some error has prevented the protocol from being 
	created. */
	virtual CProtocolBase * NewProtocolL(TUint aSockType,TUint aProtocol)=0;
	/** Gets a list of supported protocols. 
	
	Called during initialisation, directly after Install(). ProtocolList() returns a list 
	of all the protocols in the protocol family. The protocol family object should allocate 
	memory to hold an array of TServerProtocolDesc structures. This function should then 
	fill them in and return the pointer and a count of the number of protocols 
	supported. The socket server caches this information, so that it does not 
	need to keep the protocol module loaded.
	
	The protocol family should not attempt to use static data (which it can't) 
	or to free this memory later, as the socket server will automatically free 
	this storage.
	
	@param aProtocolList This pointer is set to point to memory allocated by the 
	protocol family and filled in as described above 
	@return The number of protocols in this protocol family (and entries in the 
	list of protocols) */
	virtual TUint ProtocolList(TServerProtocolDesc*& aProtocolList)=0;

	inline TInt RefCount() const;

protected:

	/** Contains version information */
	TVersion iVersion;
private:
	TInt iRefCount;
	CLibUnloader* iLibUnloader;
	CProtocolFamilyRef* iManagerRef;
	};

/**
@publishedPartner
@released
*/
typedef CProtocolFamilyBase* (*TProtocolNew)();


class SocketTimer 
/**
@internalComponent
*/
	{
public:
	IMPORT_C static void Queue(TTimeIntervalMicroSeconds32 aTimeInMicroSeconds,TDeltaTimerEntry& aTimer);
	IMPORT_C static void Remove(TDeltaTimerEntry& aTimer);
	};

class SocketServExt
/**
@internalTechnology
*/
    {
public:
	IMPORT_C static CProtocolBase* FindAndLoadProtocolL(const TDesC& aName, TProtocolType aType=ENormalProtocol);
	IMPORT_C static CProtocolBase* FindAndLoadProtocolL(TUint aAddrFamily, TUint aSockType, TUint aProtocol);
	IMPORT_C static void InstallExtensionL(const TDesC& aDllName, const TDesC& aArgs);
	IMPORT_C static void OpenSession();
	IMPORT_C static void CloseSession();
	IMPORT_C static void InstallSchedulerWaitHook(TCallBack* aCall);
	};

class CSocketServExtRef;
class CSocketServExtBase : public CBase
/**
Base class for extensions

@internalTechnology
*/
	{
public:
	IMPORT_C virtual ~CSocketServExtBase();
protected:
	IMPORT_C CSocketServExtBase();
public:	
	virtual void InstallL(const TDesC& aArgs)=0;
	virtual void Remove()=0;
	//
private:
	friend class CSocketServExtRef;
	CSocketServExtRef* iExtRef;
	};


/**
KSoOwnerInfo

Definition for internal SetOption() from ESock to Provider to communicate
socket owner information.

@internalTechnology
@released
*/
const TInt KSOLProvider = 2;

const TUint KSoOwnerInfo = 1 | KSocketInternalOptionBit;

class TSoOwnerInfo
/**
Class used to communicate the owner of a socket from ESOCK to Provider.
@internalTechnology
*/
	{
public:
	TUidType	iUid;
	};

/**
KSoConnectionInfo

Definition for internal SetOption() from ESock to Provider to communicate
connection selection information.  Note that the information is opaque
to ESock and comes from Nifman in the form of a TSoIfConnectionInfo class.
@internalTechnology
*/
const TInt KSoConnectionInfo = 2 | KSocketInternalOptionBit;

/**
UID of Protocol Modules
@publishedPartner
@released */
const TInt KUidProtocolModule = 0x1000004A;

/**
UID of Unicode Protocol Modules

@internalTechnology
*/
const TInt KUidUnicodeProtocolModule = 0x10003d38;

/** @internalTechnology */
const TInt KUidEsockExtension = 0x10000387;

#include <es_prot.inl>

#endif
