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
// Interface Manager API
// 
//



/**
 @file
*/


#if !defined(__NIFMAN_H__)
#define __NIFMAN_H__

#include <es_prot.h>
#include <nifvar.h>
#include <cdbover.h>

class CNifMan;
class CNifFactory : public CObject
/**
Manager classes

@publishedPartner
@released
*/
	{
friend class CNifMan;
public:
	IMPORT_C CNifFactory();
	IMPORT_C virtual TInt Open();
	IMPORT_C virtual void Close();
	IMPORT_C static void Cleanup(TAny* aObject);
    IMPORT_C static TInt ControlledDelete(TAny* aFactory);
	IMPORT_C void InitL(RLibrary& aLib, CObjectCon& aCon);

protected:
	IMPORT_C ~CNifFactory();
	virtual void InstallL()=0;
	RLibrary iLib;
	CAsyncCallBack* iAsyncDtor;
	};

/**
Static internal API class
@internalComponent
*/
enum TNifSocketState { ENifBuffers2048=-4, ENifBuffers1024, ENifBuffers512, 
					   ENifSocketNull=-1,
                       ENifSocketCreated=0, ENifSocketOpen=3, ENifSocketConnected=4,
					   ENifSocketError=9 };

class MNifIfUser;
class MNifIfNotify;
class CNifIfBase;
class CNifAgentBase;
class CSockSession;
class CConnectionProvdBase;
class Nif
/**
@internalTechnology
*/
	{
public:
	/** Network protocol support */
	IMPORT_C static void BindL(MNifIfUser& aUser, TAny* aId, TDes& aResult, const TDesC& aName=TPtrC(0,0));
	IMPORT_C static void NetworkLayerClosed(MNifIfUser& aUser);
	IMPORT_C static void StartL(TDes& aResult, const TDesC& aName=TPtrC());
	IMPORT_C static void Stop(const TDesC& aName=TPtrC());
	IMPORT_C static CNifIfBase* CreateInterfaceL(const TDesC& aName, MNifIfNotify* aNotify);
	IMPORT_C static CNifAgentBase* CreateAgentL(const TDesC& aAgentName, const TBool aNewInstance = EFalse);
	IMPORT_C static void CheckInstalledMBufManagerL();
	IMPORT_C static CProtocolBase* IsProtocolLoaded(const TDesC& aName);
	IMPORT_C static void CheckInstalledL();
	IMPORT_C static TInt SetSocketState(TNifSocketState aState, CServProviderBase* aProvd);
	IMPORT_C static void ProgressL(TNifProgress& aProgress, const TDesC& aName=TPtrC());
	IMPORT_C static void Stop(TAny* aId, CNifIfBase* aIf=0);
	IMPORT_C static void ProgressL(TNifProgress& aProgress, TAny* aId, CNifIfBase* aIf=0);
	IMPORT_C static CConnectionProvdBase* NewConnectionL(MConnectionNotify* aConnection, TUint aId);
	/** deprecated function */
	IMPORT_C static CNifIfBase* CreateInterfaceL(const TDesC& aName);
	};


/**
Client side classes
async message for progress notifier

@publishedAll
@deprecated 7.0s - replaced with RConnection API
*/
const TInt KDefaultNifSlots = 1;	


/**
@publishedPartner
@released
@capability NetworkControl These control options affect configuration at the designated level.  
@ref RConnection::Control
*/
const TUint KCOLInterface = 100;

/**
@publishedPartner
@released
@capability NetworkControl These control options affect configuration at the designated level.  
@ref RConnection::Control
*/
const TUint KCOLAgent     = 200;


// RConnection::Ioctl() level for NIFMAN

/**
@publishedPartner
@released
@ref RConnection::Ioctl
*/
const TUint KCOLConfiguration = 300;

#ifdef _DEBUG
/**
Debug-only option level used to pass test-only option names onto PPP.
@internalTechnology
*/
const TUint KCOLLinkLayerTestLevel = 325;
#endif


// RConnection::Control() options

/**
@publishedPartner
@released
@capability NetworkControl Restrict ability to switch on/off idle timers  
@ref RConnection::Control
*/
const TUint KConnDisableTimers = KConnReadUserDataBit | 1;

/**
@publishedPartner
@released
@ref RConnection::Control
*/
const TUint KConnGetInterfaceName = KConnReadUserDataBit | KConnWriteUserDataBit | 2;


// RConnection::Ioctl() options

/**
@publishedPartner
@released
@ref RConnection::Ioctl
*/
const TUint KConnGetCurrentAddr = KConnWriteUserDataBit | 3;

/**
@publishedPartner
@released
@ref RConnection::Ioctl
*/
const TUint KConnGetServerAddr = KConnWriteUserDataBit | 4;

/**
@publishedPartner
@released
@ref RConnection::Ioctl
*/
const TUint KConnGetAddrLeaseTimeRemain = KConnWriteUserDataBit | 5;

/**
@publishedPartner
@released
@capability NetworkControl Restrict ability to release a configured address  
@ref RConnection::Ioctl
*/
const TUint KConnAddrRelease = 6;

/**
@publishedPartner
@released
@capability NetworkControl Restrict ability to renew a configured address  
@ref RConnection::Ioctl 

This option is used for user initiated RENEW request where an attempt 
is made to renew the lease obtained from the orginal DHCP server.
If the server response is not received before the default timeout(RebindTimeT2 - RenewalTimeT1)
the dhcp client will then initiate a REBIND.An user defined timeout can also be
supplied when using this option which will override the default timeout value. 

@code
	RConnection conn; 
	TRequestStatus stat;
	//Start a connection 
	..... 
	.....	
	//Option1: Initiate a Renew request. 
	conn.Ioctl(KCOLConfiguration, KConnAddrRenew, stat);

	//Option2: Initiate a Renew request with a user defined timeout 
	TInt secValue(2); //Eg timeout set to 2secs
	TPckg<TInt> val(secValue);		
	conn.Ioctl(KCOLConfiguration, KConnAddrRenew, stat,&val);
@endcode
*/
const TUint KConnAddrRenew = 7;

/**
@internalTechnology
@released 9.1
*/
const TUint KNifSessionSetConnectionAttempt = KConnInternalOptionBit|8;

/**
@internalTechnology
@released 9.1
*/
const TUint KNifSessionGetConnectionAttempt = KConnInternalOptionBit|9;
/**
@internalTechnology
@released 9.1
*/
const TUint KNifSessionSetBlockProgresses = KConnInternalOptionBit|10;

/**
@internalTechnology
@released 9.1
*/
const TUint KNifSessionGetBlockProgresses = KConnInternalOptionBit|11;

/**
@internalTechnology
@released 9.1
*/
const TUint KNifSessionGetStopping = KConnInternalOptionBit|12;

// DHCP specific RConnection::Ioctl options
/**
@publishedPartner
@released
@ref RConnection::Ioctl
*/const TUint KConnGetDhcpRawOptionData = KConnWriteUserDataBit|KConnReadUserDataBit|100;

/**
@publishedPartner
@released
@ref RConnection::Ioctl
*/
const TUint KConnGetSipServerAddr = KConnWriteUserDataBit|KConnReadUserDataBit|101;

/**
@publishedPartner
@released
@ref RConnection::Ioctl
*/
const TUint KConnGetSipServerDomain = KConnWriteUserDataBit|KConnReadUserDataBit|102;

#ifdef SYMBIAN_NETWORKING_DHCPSERVER
/**
@internalTechnology
@released
@ref RConnection::Ioctl
*/
const TUint KConnSetDhcpRawOptionData = KConnWriteUserDataBit|KConnReadUserDataBit|103;
#endif // SYMBIAN_NETWORKING_DHCPSERVER

#ifdef SYMBIAN_NETWORKING_DHCP_MSG_HEADERS
/**
* This constant is used to retrieve the DHCP Header Sname which is the 
* host name of the next available server. This is sometimes overloaded 
* to carry option value 66 which is the TftpServerName. 
* @publishedPartner
* @released
* @see RConnection::Ioctl()
*/
const TUint KConnGetDhcpHdrSname = KConnWriteUserDataBit|KConnReadUserDataBit|104;

/**
* This constant is used to retrieve the DHCP Header Siaddr which is the 
* IPAddress of the next available server.
* @publishedPartner
* @released
* @see RConnection::Ioctl()
*/
const TUint KConnGetDhcpHdrSiaddr = KConnWriteUserDataBit|KConnReadUserDataBit|105;

/**
* This constant is used to retrieve the DHCP Option 66, Tftp Server Name.
* @publishedPartner
* @released
* @see RConnection::Ioctl()
*/
const TUint KConnGetTftpServerName = KConnWriteUserDataBit|KConnReadUserDataBit|106;

/**
* This constant is used to retrieve the DHCP Option 150, Tftp Server Address.
* @publishedPartner
* @released
* @see RConnection::Ioctl()
*/
const TUint KConnGetTftpServerAddr = KConnWriteUserDataBit|KConnReadUserDataBit|107;


/**
* This constant is used to retrieve multiple opcode data in a raw format.
* @publishedPartner
* @released
* @see RConnection::Ioctl()
*/
const TUint KConnDhcpGetMultipleParams  = KConnWriteUserDataBit|KConnReadUserDataBit|108;
#endif //SYMBIAN_NETWORKING_DHCP_MSG_HEADERS


/**
@publishedPartner
@released
*/
const TUint KConnMaxInterfaceName = 32;

class TConnInterfaceName
/**
@publishedPartner
@released
*/
	{
public:
	TUint iIndex;
	TBuf<KConnMaxInterfaceName> iName;
	};
/**
@internalTechnology
*/
enum TAgentConnectType 
	{
	EAgentStartDialOut,
	EAgentReconnect,
	EAgentStartCallBack,
	EAgentNone,
	EAgentStartDialIn
	};

#endif // __NIFMAN_H__
