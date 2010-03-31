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

#ifndef __OBEXCONSTANTS_H
#define __OBEXCONSTANTS_H

#include <e32std.h>
#include <es_sock.h>
#include <ir_sock.h>
#include <bt_sock.h>
#include <obexpanics.h>

//common to request & resp digests

/** @internalComponent */
const TInt KChallResponseSize = 58;
/** @internalComponent */
const TInt KMinChallResponseSize = 18; //Nonce(16) + tag(1) + size(1)
/** @internalComponent */
const TInt KObexNonceSize = 16;
/** @internalComponent */
const TUint8 KObexRequireUID = 0x01;

//request or chall
/** @internalComponent */
const TUint KObexChallNonceTag = 0;
/** @internalComponent */
const TUint8 KObexChallOptionsTag = 0x01;
/** @internalComponent */
const TUint8 KObexChallRealmTag = 0x02;
/** @internalComponent */
const TInt KObexChallOptionSize = 1; //this can't be changed from one without making
/** @internalComponent */
const TUint KObexChallHeaderSize = 23; //assuming no Realm data

//response
/** @internalComponent */
const TUint KObexRespTag = 0;
/** @internalComponent */
const TInt KObexRespSize = 16;
/** @internalComponent */
const TUint8 KObexRespUserIDTag = 0x01;
/** @internalComponent */
const TUint8 KObexRespNonceTag = 0x02;

/** @internalComponent */
const TUint8 KObexHeaderTypeMask = 0xc0;
/** @internalComponent */
const TUint8 KObexHeaderTypeOffset = 6;

#ifdef _UNICODE
/** @internalComponent */
const TInt KUidOBEXTransportModule = 0x10003d56;
#else
/** @internalComponent */
const TInt KUidOBEXTransportModule = 0x1000169c;
#endif

/** @internalComponent */
const TInt KUsbIntStringDescLength = 30;

/** @internalComponent */
const TUint8 KFourByteTimeHeaderAddress = 0xc4;

// Header mask definitions.
// Old style accessor for which headers are present or
// should be sent by an object.  Now deprecated, use the
// header iterator instead.
/** @internalComponent */
const TUint16 KObexHdrName				= 0x0001;
/** @internalComponent */
const TUint16 KObexHdrType				= 0x0002;
/** @internalComponent */
const TUint16 KObexHdrLength			= 0x0004;
/** @internalComponent */
const TUint16 KObexHdrTime				= 0x0008;
/** @internalComponent */
const TUint16 KObexHdrDescription		= 0x0010;
/** @internalComponent */
const TUint16 KObexHdrTarget			= 0x0020;
/** @internalComponent */
const TUint16 KObexHdrConnectionID		= 0x0040;
/** @internalComponent */
const TUint16 KObexHdrBody				= 0x0080;
/** @internalComponent */
const TUint16 KObexHdrEndOfBody			= 0x0100;
/** @internalComponent */
const TUint16 KObexHdrHttp				= 0x0200;
/** @internalComponent */
const TUint16 KObexHdrAppParam			= 0x0400;
/** @internalComponent */
const TUint16 KObexHdrUserDefined		= 0x0800;
/** @internalComponent */
const TUint16 KObexHdrCount				= 0x1000;
/** @internalComponent */
const TUint16 KObexHdrCreatorID			= 0x2000;
/** @internalComponent */
const TUint16 KObexHdrWanUUID			= 0x4000;
/** @internalComponent */
const TUint16 KObexHdrObjectClass		= 0x8000;

/** @internalComponent */
const TUint8  KObexUserDefinedHdrAddrMin	 = 0x30; //start of user defined header address range
/** @internalComponent */
const TUint8  KObexUserDefinedHdrAddrMax	 = 0x3F; //end of user defined header address range

/** @internalComponent */
const TUint8 KObexVersion           	= 0x10;		///< Version 1.0 (still correct for Obex spec v 1.2)

/** @internalComponent */
const TUint8 KObexObjectFieldSize   	= 127;
/** @internalComponent */
const TUint8 KObexObjectDescriptionSize = 255;

// Extended errors for IrObex

/** Must not use as not in the allocated range */
const TInt KErrIrObexRespBase			= - 5500; 

/** Extended error for IrObex - No other infrared device found */
const TInt KErrIrObexClientNoDevicesFound = -5501;

/** Extended error for IrObex - Other IR device cannot handle IrObex */
const TInt KErrIrObexClientPeerDoesNotHaveObex = -5502;

/** Extended error for IrObex - Other IR device aborted the transfer */
const TInt KErrIrObexClientPutPeerAborted	= -5503;

/** Extended error for IrObex - Peer device aborted data transmission/obex sending */
const TInt KErrIrObexServerPutPeerAborted = -5507;

/** Extended error for IrObex - Cannot authorise the challenge so link dropped */
const TInt KErrIrObexConnectChallRejected = -5512;

// Other Obex errors defined in the system but no longer used
// Do not reuse the number!
// KErrIrObexClientPutPeerCannotHandleObject -5504
// KErrIrObexServerPutFileWriteError		-5509
// KErrIrObexClientFirstPutFailed			-5510
// KErrIrObexClientSubsequentPutFailed		-5511

/** Unexpected event for the given state */
const TInt KErrIrObexBadEvent = -5513;

/** Event occurred while Server is stopped */
const TInt KErrIrObexServerStopped = -5514;

/** Packet received while state machine is in a wait state */
const TInt KErrIrObexPacketDuringWait = -5515;

// There are other error codes defined at the end of this file,
// which are a direct mapping of specific Obex error codes and
// are returned by the client.


// Flags used by Connect
// ...None in OBEX 1.0

// Flags used by SetPath
/** @internalComponent */
const TUint8 KObexSetPathParent	= 0x01;

/**
Version number for TObexTransportInfo and derived classes.  
When iVersion is set to this value the following fields of TObexTransportInfo  
must be set:
iTransportName, 
iReceiveMtu
iTransmitMtu
The iVersion member variable must be set to this value. If in future any of the 
iFuture variables are used a new version constant will be created.

@see TObexTransportInfo
@publishedAll
@released
*/
const TInt KObexTransportInfoVersion0 = 0;	

/**
Default for the receive and transmit MTU sizes
Use this default value for setting the iReceiveMtu or iTransmitMtu in TObexTransportInfo
objects or derived classes.

@see TObexTransportInfo
@publishedAll
@released
*/
const TInt KObexDefaultMtuSize = 4000;

/**
Default value for the number of discovery slots to use.  Use this value as a default 
for iDiscoverySlots in TObexIrdaV2TransportInfo.  

@see TObexIrdaV2TransportInfo
@publishedAll
@released
*/
const TUint KObexIrdaDefaultDiscoverySlotsToUse = 1;

/**
Default value for the number of discovery attempts made.  Use this value as a default for iDiscoveryAttempts
in TObexIrdaV2TransportInfo.  
@see TObexIrdaV2TransportInfo
@publishedAll
@released
*/
const TUint KObexIrdaDefaultDiscoveryAttempts = 4;

// Constants used to define which transport Obex will run over.
// Used in TObexTransportInfo and TObexProtocolInfo's iTransport member.

/**
Protocol string when running over IrDA
@see TObexIrProtocolInfo
@see TObexTransportInfo
@publishedAll
@released
*/
_LIT(KObexIrTTPProtocol, "IrTinyTP");

/**
Protocol string when running over IrDA
Using this version indicates that the configuration object contains discovery parameters.
@see TObexIrProtocolInfo
@publishedAll
@released
*/
_LIT(KObexIrTTPProtocolV2, "IrTinyTP-V2");

/**
Protocol string when running over IrDA
Using this version indicates that the configuration object contains the device nickname.
@see TObexIrProtocolInfo
@publishedAll

@capability WriteDeviceData If the TObexIrV3TransportInfo is passed as the argument
                            to CObexServer::NewL or CObexClient::NewL and the associated 
                            name is valid.
@released
*/
_LIT(KObexIrTTPProtocolV3, "IrTinyTP-V3");

/**
Protocol string when running over Bluetooth
@see TObexBluetoothProtocolInfo
@see TObexTransportInfo
@publishedAll
@released
*/
_LIT(KObexRfcommProtocol, "RFCOMM");

/**
Protocol string when running over USB
@see TObexUsbProtocolInfo
@see TObexTransportInfo
@publishedAll
@released
*/
_LIT(KObexUsbProtocol, "USB");

/**
Place holder for...
protocol string that should be used 
if a Win32 emulator USB transport were 
to be created for testing.
@see TObexUsbProtocolInfo
@see TObexTransportInfo
@publishedAll
@released
*/
_LIT(KObexWin32UsbProtocol, "Win32Usb");

/**
Protocol string when running over USB using client driver extensions
@see TObexUsbProtocolInfoV2
@see TObexTransportInfo
@publishedAll
@released
*/
_LIT(KObexUsbProtocolV2, "USB-V2");

/** 
This class is derived for each underlying transport protocol OBEX 
runs over.

The iTransport member holds the unique name for the transport. For example for
infra-red (TinyTP) this is "IrTinyTP" or KObexIrTTPProtocol.

@see TObexIrProtocolInfo for running over TinyTP
@see TObexBluetoothProtocolInfo for running over Rfcomm
@see TObexUsbProtocolInfo for running over USB
@see TObexUsbProtocolInfoV2 for running over USB using client driver extensions

@see KObexIrTTPProtocol
@see KObexIrTTPProtocolV2
@see KObexRfcommProtocol
@see KObexUsbProtocol
@see KObexUsbProtocolV2

@publishedAll
@released
*/
NONSHARABLE_CLASS(TObexProtocolInfo)
	{
public:
	/** Holds the unique name for the transport. */
	TBuf<60> iTransport;
private:
	// This data padding has been added to help prevent future binary compatibility breaks	
	// Neither iPadding1 nor iPadding2 have been zero'd because they are currently not used
	TUint32     iPadding1; 
	TUint32     iPadding2; 		
	};

/** 
Used to describe IrDA specific protocol information
	
To access the default OBEX server, the IAS class value should be "OBEX"
and the IAS attribute name "IrDA:TinyTP:LsapSel". 

@publishedAll
@released
*/
NONSHARABLE_CLASS(TObexIrProtocolInfo) : public TObexProtocolInfo
	{
public:
	/** IrDA address information for this connection, as used in the IrDA sockets interface.
	Refer to the SDK for more information about this.
	Its main use is for setting the port that the local machine will listen on. */
	TIrdaSockAddr iAddr;
	/** The IAS class value that the OBEX session will register its listener port,
	or request remote port with. */
	TBuf8<KIASClassNameMax> iClassName;
	/** The IAS attribute value that the OBEX session will register its listener port,
	or request remote port with. */
	TBuf8<KIASAttributeNameMax> iAttributeName;
	/** The number of discovery slots to use. */
	TUint8 iDiscoverySlots;
	/** The number of discovery attempts to make. */
	TUint8 iDiscoveryAttempts;

private:
	// This data padding has been added to help prevent future binary compatibility breaks	
	// None of these padding variables have been zero'd because they are currently not used
	TUint16     iPadding1; 
	TUint32     iPadding2; 		
	TUint32     iPadding3; 
	TUint32     iPadding4; 	
	};

/** 
Used to describe Bluetooth specific protocol information
	
@publishedAll
@released
*/
NONSHARABLE_CLASS(TObexBluetoothProtocolInfo) : public TObexProtocolInfo
	{
public:
	/** 
	For OBEX servers:
	This defines the server channel on which the OBEX server listens 
	for connections. The server channel is set using SetPort on the 
	TRfcommSockAddr.
	Note:
	1) Unless the channel is defined as KRfcommPassiveAutoBind 
	it may be in use when the obex server attempts to 'bind' to it
	2) If the channel is defined as KRfcommPassiveAutoBind 
	then when the server is FIRST started it will attempt 
	to find a free RFComm channel. If this is successful 
	that free channel will be used as the server channel 
	for the life time of the obex server including
	when it is 'stopped' and re-'started'.
	3) When the obex server is stopped, and very
	briefly when a bluetooth connection comes down, the
	obex server releases its server channel. It is possible
	therefore that during this time another application might bind
	to it. This will cause an error when the obex server tries
	to re-bind.

	Also note that a Bluetooth OBEX server will itself set the Object Transfer
	bit in the Service Class as required by the Generic Object Exchange
	Profile so the user need not do this.	
	@see CObexServer
	
	For OBEX clients:
	This defines the server channel and the 
	device address to connect to. The server channel 
	and device address are set respectively using SetPort 
	and SetBTAddr on the TRfcommSockAddr.
	*/
	TRfcommSockAddr iAddr;
	
private:
	// This data padding has been added to help prevent future binary compatibility breaks	
	// Neither iPadding1 nor iPadding2 have been zero'd because they are currently not used
	TUint32     iPadding1; 
	TUint32     iPadding2; 	
	};

/** 
Used to describe USB specific protocol information
	
@publishedAll
@released
*/
NONSHARABLE_CLASS(TObexUsbProtocolInfo) : public TObexProtocolInfo
	{
public:
	/** Provides a string to be attached to the Obex function's Communication Class interface,
	which may be used to identify the Obex service. */
	TBuf16<KUsbIntStringDescLength> iInterfaceStringDescriptor;
	};

/** 
Used to set options used by the extended USB client driver for improved performance
	
@see TObexUsbProtocolInfo
@see RDevUsbcClient
@publishedAll
@released
*/
NONSHARABLE_CLASS(TObexUsbProtocolInfoV2) : public TObexUsbProtocolInfo
	{
public:
	/** Bitmap containing the bandwidth priorities to use on IN and OUT endpoints
	@see TUsbcBandwidthPriority
	*/
	TInt iBandwidthPriority;
	/** Specifies whether to use DMA on the bulk OUT endpoint */
	TBool iDmaOnOutEndpoint;
	/** Specifies whether to use DMA on the bulk IN endpoint */
	TBool iDmaOnInEndpoint;
	
private:
	// This data padding has been added to help prevent future binary compatibility breaks	
	// None of these padding variables have been zero'd because they are currently not used
	TUint32     iPadding1; 
	TUint32     iPadding2; 		
	TUint32     iPadding3; 
	TUint32     iPadding4; 	
	};

/**
Contains information about OBEX packet sizing policy, defining the
maximum buffer size for receive and transmit packets
*/
NONSHARABLE_CLASS(TObexProtocolPolicy)
	{
public:
	IMPORT_C TObexProtocolPolicy ();	// Sets version and default values

	IMPORT_C TInt SetReceiveMtu ( TUint16 aReceiveMtu );
	IMPORT_C TInt SetTransmitMtu ( TUint16 aTransmitMtu );
	IMPORT_C TUint16 Version () const;
	IMPORT_C TUint16 ReceiveMtu () const;
	IMPORT_C TUint16 TransmitMtu () const;

private:
	TUint16 iVersion;
	TUint16 iReceiveMtu;
	TUint16 iTransmitMtu;

	// This data padding has been added to help prevent future binary compatibility breaks	
	// None of these padding variables have been zero'd because they are currently not used
	TUint32     iPadding1; 
	TUint32     iPadding2; 		
	TUint32     iPadding3; 
	TUint32     iPadding4; 	
	};

struct TObexConnectionInfo;

/**
TObexConnectInfo
This structure contains information used during OBEX connection. iVersion
holds the encoded OBEX version of the machine, use @c VersionMajor() and
@c VersionMinor() to extract the parts of the version number (each having a
value from 0 to 15). @c iFlags holds OBEX connection flags. @c iWho holds 
the Who attribute from the connect packet, if any was specified, or 
otherwise has a length of 0. 
It is recommended that this class is only ever allocated on the heap as it is quite big.
*/
NONSHARABLE_CLASS(TObexConnectInfo)
	{
public:
	IMPORT_C TObexConnectInfo();
	IMPORT_C TUint8 VersionMajor() const;
	IMPORT_C TUint8 VersionMinor() const;
public:
	TUint8 iVersion; /** Encoded OBEX version of the machine*/
	TUint8 iFlags; /** iFlags holds OBEX connection flags*/
	TBuf8<KObexObjectDescriptionSize> iWho; /** the Who attribute from the connect packet, if any was specified */
	TBuf8<KObexObjectDescriptionSize> iTargetHeader; /** the Target header from the connect packet, if any was specified */
	
private:
	// This data padding has been added to help prevent future binary compatibility breaks	
	// Neither iPadding1 nor iPadding2 have been zero'd because they are currently not used
	TUint32     iPadding1; 
	TUint32     iPadding2; 	
	};



//if these codes are extended due to a IRObex spec update ensure 
//that the TInt immediately below are updated 
//and the default in the method IrOBEXUtil::ObexResponse is also updated
enum TObexResponse  
	{ 
/** Response is "Continue" */	
	ERespContinue			= 0x10,
	
/** Response is "Success" */		
	ERespSuccess			= 0x20,
	
/** Response is "Created" */		
	ERespCreated			= 0x21,
	
/** Response is "Accepted" */		
	ERespAccepted			= 0x22,
	
/** Response is "Non-Authenticated Information" */		
	ERespNonAuthInfo		= 0x23,
	
/** Response is "No Content" */			
	ERespNoContent			= 0x24,
	
/** Response is "Reset Content" */				
	ERespResetContent		= 0x25,
	
/** Response is "Partial Content" */					
	ERespPartialContent		= 0x26,
	
/** Response is "Multiple Choices" */						
	ERespMultipleChoices	= 0x30,
	
/** Response is "Moved Permanently" */						
	ERespMovedPerm			= 0x31,
	
/** Response is "Moved Temporarily" */							
	ERespMovedTemp			= 0x32,

/** Response is "See Other" */								
	ERespSeeOther			= 0x33,

/** Response is "Not Modified" */									
	ERespNotModified		= 0x34,

/** Response is "Use Proxy" */									
	ERespUseProxy			= 0x35,

/** Response is "Bad Request" */									
	ERespBadRequest			= 0x40,

/** Response is "Unauthorized" */									
	ERespUnauthorized		= 0x41,

/** Response is "Payment Required" */									
	ERespPaymentRequired	= 0x42,

/** Response is "Forbidden" */									
	ERespForbidden			= 0x43,

/** Response is "Not Found" */										
	ERespNotFound			= 0x44,

/** Response is "Method Not Allowed" */										
	ERespMethodNotAllowed	= 0x45,

/** Response is "Not Acceptable" */									
	ERespNotAcceptable		= 0x46,

/** Response is "Proxy Authentication is Required" */										
	ERespProxyAuthenReqd	= 0x47,

/** Response is "Timed Out" */										
	ERespTimedOut			= 0x48,

/** Response is "Conflict" */										
	ERespConflict			= 0x49,

/** Response is "Gone" */										
	ERespGone				= 0x4A,

/** Response is "Length Required" */										
	ERespLengthReqd			= 0x4B,

/** Response is "Precondition Failed" */											
	ERespPreCondFailed		= 0x4C,

/** Response is "Required Entity is Too Large" */											
	ERespReqEntityTooLarge	= 0x4D,

/** Response is "Required URL is Too Large" */											
	ERespReqURLTooLarge		= 0x4E,

/** Response is "Unsupported Media Type" */											
	ERespUnsupMediaType		= 0x4F,

/** Response is "Internal Error" */											
	ERespInternalError		= 0x50,

/** Response is "Not Implemented" */											
	ERespNotImplemented		= 0x51,

/** Response is "Bad Gateway" */											
	ERespBadGateway			= 0x52,

/** Response is "Service Unavailable" */											
	ERespServiceUnavail		= 0x53,

/** Response is "Gateway Timeout" */											
	ERespGatewayTimeout		= 0x54,

/** Response is "HTTP Version is Not Supported" */											
	ERespHTTPVerNotSupp		= 0x55,

/** Response is "Database is Full" */											
	ERespDatabaseFull		= 0x60,

/** Response is "Database is Locked" */											
	ERespDatabaseLocked		= 0x61,

/** Response is "Service is Unavailable" */											
	ERespServiceUnavailable = 0xD3,
	};


//some error codes to be used specifically by the client
//these shall, be mapped directly to OBEX defined error codes.
const TInt KErrIrObexRespSuccess		= KErrIrObexRespBase - ERespSuccess;			//-5532 returns 0x20 (0xA0)
const TInt KErrIrObexRespCreated		= KErrIrObexRespBase - ERespCreated;			//-5533 returns 0x21 (0xA1)
const TInt KErrIrObexRespAccepted		= KErrIrObexRespBase - ERespAccepted;			//-5534 returns 0x22 (0xA2)
const TInt KErrIrObexRespNonAuthInfo	= KErrIrObexRespBase - ERespNonAuthInfo;		//-5535 returns 0x23 (0xA3)
const TInt KErrIrObexRespNoContent		= KErrIrObexRespBase - ERespNoContent;			//-5536 returns 0x24 (0xA4)
const TInt KErrIrObexRespResetContent	= KErrIrObexRespBase - ERespResetContent;		//-5537 returns 0x25 (0xA5)
const TInt KErrIrObexRespPartialContent = KErrIrObexRespBase - ERespPartialContent;		//-5538 returns 0x26 (0xA6)
const TInt KErrIrObexRespMultipleChoices = KErrIrObexRespBase - ERespMultipleChoices;	//-5548 returns 0x30 (0xB0)
const TInt KErrIrObexRespMovedPerm		= KErrIrObexRespBase - ERespMovedPerm;			//-5549 returns 0x31 (0xB1)
const TInt KErrIrObexRespMovedTemp		= KErrIrObexRespBase - ERespMovedTemp;			//-5550 returns 0x32 (0xB2)
const TInt KErrIrObexRespSeeOther		= KErrIrObexRespBase - ERespSeeOther;			//-5551 returns 0x33 (0xB3)
const TInt KErrIrObexRespNotModified	= KErrIrObexRespBase - ERespNotModified;		//-5552 returns 0x34 (0xB4)
const TInt KErrIrObexRespUseProxy		= KErrIrObexRespBase - ERespUseProxy;			//-5553 returns 0x35 (0xB5)
const TInt KErrIrObexRespBadRequest		= KErrIrObexRespBase - ERespBadRequest;			//-5564 returns 0x40 (0xC0)
const TInt KErrIrObexRespUnauthorized	= KErrIrObexRespBase - ERespUnauthorized;		//-5565 returns 0x41 (0xC1)
const TInt KErrIrObexRespPaymentRequired = KErrIrObexRespBase - ERespPaymentRequired;	//-5566 returns 0x42 (0xC2)
const TInt KErrIrObexRespForbidden		= KErrIrObexRespBase - ERespForbidden;			//-5567 returns 0x43 (0xC3)
const TInt KErrIrObexRespNotFound		= KErrIrObexRespBase - ERespNotFound;			//-5568 returns 0x44 (0xC4)
const TInt KErrIrObexRespMethodNotAllowed = KErrIrObexRespBase - ERespMethodNotAllowed;	//-5569 returns 0x45 (0xC5)
const TInt KErrIrObexRespNotAcceptable	= KErrIrObexRespBase - ERespNotAcceptable;		//-5570 returns 0x46 (0xC6)
const TInt KErrIrObexRespProxyAuthenReqd = KErrIrObexRespBase - ERespProxyAuthenReqd;	//-5571 returns 0x47 (0xC7)
const TInt KErrIrObexRespTimedOut		= KErrIrObexRespBase - ERespTimedOut;			//-5572 returns 0x48 (0xC8)
const TInt KErrIrObexRespConflict		= KErrIrObexRespBase - ERespConflict;			//-5573 returns 0x49 (0xC9)
const TInt KErrIrObexRespGone			= KErrIrObexRespBase - ERespGone;				//-5574 returns 0x4A (0xCA)
const TInt KErrIrObexRespLengthReqd		= KErrIrObexRespBase - ERespLengthReqd;			//-5575 returns 0x4B (0xCB)
const TInt KErrIrObexRespPreCondFailed	= KErrIrObexRespBase - ERespPreCondFailed;		//-5576 returns 0x4C (0xCC)
const TInt KErrIrObexRespReqEntityTooLarge = KErrIrObexRespBase - ERespReqEntityTooLarge;//-5577 returns 0x4D (0xCD)
const TInt KErrIrObexRespReqURLTooLarge	= KErrIrObexRespBase - ERespReqURLTooLarge;		//-5578 returns 0x4E (0xCE)
const TInt KErrIrObexRespUnsupMediaType = KErrIrObexRespBase - ERespUnsupMediaType;		//-5579 returns 0x4F (0xCF)
const TInt KErrIrObexRespInternalError	= KErrIrObexRespBase - ERespInternalError;		//-5580 returns 0x50 (0xD0)
const TInt KErrIrObexRespNotImplemented = KErrIrObexRespBase - ERespNotImplemented;		//-5581 returns 0x51 (0xD1)
const TInt KErrIrObexRespBadGateway		= KErrIrObexRespBase - ERespBadGateway;			//-5582 returns 0x52 (0xD2)
const TInt KErrIrObexRespServiceUnavail = KErrIrObexRespBase - ERespServiceUnavail;		//-5583 returns 0x53 (0xD3)
const TInt KErrIrObexRespGatewayTimeout = KErrIrObexRespBase - ERespGatewayTimeout;		//-5584 returns 0x54 (0xD4)
const TInt KErrIrObexRespHTTPVerNotSupp = KErrIrObexRespBase - ERespHTTPVerNotSupp;		//-5585 returns 0x55 (0xD5)
const TInt KErrIrObexRespDatabaseFull	= KErrIrObexRespBase - ERespDatabaseFull;		//-5596 returns 0x60 (0xE0)
const TInt KErrIrObexRespDatabaseLocked = KErrIrObexRespBase - ERespDatabaseLocked;		//-5597 returns 0x61 (0xE1)

#endif // __OBEXCONSTANTS_H
