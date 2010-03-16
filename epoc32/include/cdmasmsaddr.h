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
// Declares the cdmau address classes and constants.
// 
//



/**
 @file 
 @publishedAll
 @interim
*/

#if !(defined __CDMASMSADDR_H__)
#define __CDMASMSADDR_H__

#include <smsuaddr.h>
#include "tia637.h"

// CDMA SMS PROT public constants start 
_LIT(KCdmaSmsDatagram,"CDMA SMS Datagram");
/** Cdma SMS sockets family identifier. */
const TUint KCdmaSMSAddrFamily = 0x012;
/** Cdmd SMS sockets protocol ID. */
const TUint KCdmaSMSDatagramProtocol = KSMSDatagramProtocol;

// Followings are the Ioctl commands used in cdmssmsprot
// Ioctl commands that are supported in both cdma and gsm include the following from smsuaddr.h:
// KIoctlDeleteSmsMessage        = 0x0300; 
// KIoctlEnumerateSmsMessages    = 0x0301;
// KIoctlReadMessageSucceeded    = 0x0304; 
// KIoctlReadMessageFailed       = 0x0305; 
// KIoctlSendSmsMessage          = 0x0306; 
// KIoctlWriteSmsMessage         = 0x0307; 

// Gsm Ioctl commands 0x0308-0x0310 are not supported for cdma

/** Ioctl command for retrieving message identifier token object

@capability NetworkServices
@see RSocket::Ioctl(TUint aLevel,TUint aName,TDes8* aOption)
*/
const TUint KIoctlGetMsgId=0x0311;

/** Ioctl command for retrieving the last transport layer acknowledgement cause code
This command is valid only after a KIoctlSendSmsMessage ioctl command and
	aReqestStatus return one of the KErrCdmaSms extended errors and
	bearer reply option parameter was present in the previous sent message.
Otherwise the cause error received will be meaningless

@capability NetworkServices
@see RSocket::Ioctl(TUint aLevel,TUint aName,TDes8* aOption)
*/
const TUint KIoctlGetLastSendError=0x0312;
/** Value that aOptions could take when client demand traffic channel to stay open.
	Used only for KIoctlSendSmsMessage Ioctl command */
const TUint KKeepChannelOpen=0x01;

/** Maximum size of storage location */
const TInt KCdmaMaxLocationStorageSize=256;

typedef TBuf8<KCdmaMaxLocationStorageSize>	TCdmaSmsStorageLocation;


// CDMA SMS PROT public constants end

/**
Sockets for CDMA SMS messages must be bound to an address.  The 'address' 
provides a rule that tells the CDMA SMS stack which received messages should 
be given to the socket; see TCdmaSmsAddr for a more detailed explanation.

Each address must belong to a family.  The family must be one of the values 
listed below.
*/
enum TCdmaSmsAddrFamily
	{
	// as in GSMU
	/** This indicates that the address's family has not been set
	*/
	ECdmaSmsAddrUnbound=ESmsAddrUnbound,
	/** Sockets bound to a ECdmaSmsAddrSendOnly address can only be for 
	sending CDMA SMS messages; they will not receive any messages until they 
	are bound to a different address.

	Note that a socket bound to any address family except for 
	ECdmaSmsAddrLocalOperation can be used to send messages; not just 
	ECdmaSmsAddrSendOnly
	*/
	ECdmaSmsAddrSendOnly=ESmsAddrSendOnly,
	/** Sockets bound to a ECdmaSmsAddrLocalOperation address can only be used 
	for local protocol operations such as enumerating, writing and deleting 
	messages.  These sockets cannot be used for sending or receiving messages 
	until they are bound to a different address.
	
	Any socket kind of binded address and be used for writing and deleting messages.
	Only LocalOperation can be used for enumerating messages.
	*/
	ECdmaSmsAddrLocalOperation=ESmsAddrLocalOperation,
	/** 
	Sockets bound to a ECdmaSmsWemtAddrMatchIEI address will receive messages 
	on the WEMT teleservice that have a particular Information Element 
	Identifier (IEI). 

	As well as setting the address's family to ECdmaSmsWemtAddrMatchIEI, set 
	the address's 'port'to one of the IEIs in TSmsInformationElementIdentifier;
	 see CSmsInformationElement..  

	The following example binds a socket so that it will receive messages on 
	the WEMT teleservice that have the IEI "Special SMS Message Indication":

	@code
	smsaddr.SetCdmaSmsAddrFamily(ECdmaSmsWemtAddrMatchIEI);	
	smsaddr.SetPort(CSmsInformationElement::ESmsIEISpecialSMSMessageIndication);
	ret=socket.Bind(smsaddr);
	@endcode
	*/
	ECdmaSmsWemtAddrMatchIEI=ESmsAddrMatchIEI,
	/** 
	Sockets bound to a ECdmaSmsAddrMatchText address will receive messages 
	whose user data matches contains particular text.  The messages 
	teleservice does not matter.

	As well as setting the address's family to ECdmaSmsAddrMatchText, use 
	TCdmaSmsAddr::SetTextMatch to specify an ASCII string.  This string is 
	compared to the user data in the message.  If the two match then the 
	message is delivered to the socket.  The string can contain the wildcards 
	'?' to match one instance of any character and '*' to match any number of 
	characters.

	@code
	// match messages that start with 12345 
	smsaddr.SetCdmaSmsAddrFamily(ECdmaSmsAddrMatchText);
	smsaddr.SetTextMatch(_L8("12345"));
	ret=socketMatchText.Bind(smsaddr);

	// match messages that end with 12345
	smsaddr.SetCdmaSmsAddrFamily(ECdmaSmsAddrMatchText);
	smsaddr.SetTextMatch(_L8("*12345"));
	ret=socketMatchText.Bind(smsaddr);

	// match message that contain 12345
	smsaddr.SetCdmaSmsAddrFamily(ECdmaSmsAddrMatchText);
	smsaddr.SetTextMatch(_L8("*12345*"));
	ret=socketMatchText.Bind(smsaddr);
	@endcode
	*/
	ECdmaSmsAddrMatchText=ESmsAddrMatchText,
	/**
	Sockets bound to a ECdmaSmsWemtAddrApplication8BitPort address will 
	receive messages on the WEMT teleservice that are from a particular 8 bit 
	application port. 

	As well as setting the address's family to ECdmaSmsWemtAddrMatchIEI, set 
	the address's 'port' to an 8-bit  number.

	The following example binds a socket so that it will receive messages on 
	the WEMT teleservice that are on the port 83:

	@code
	smsaddr.SetCdmaSmsAddrFamily(ECdmaSmsWemtAddrApplication8BitPort);	
	smsaddr.SetPort(83);
	ret=socket.Bind(smsaddr);
	@endcode
	*/
	ECdmaSmsWemtAddrApplication8BitPort=ESmsAddrApplication8BitPort,
	/**
	This is similar to ECdmaSmsWemtAddrApplication8BitPort, except that the 
	WEMT message must be from a particular 16 bit application port.  The 
	address's port must be set to a 16-bit number.  For example:

	@code
	smsaddr.SetCdmaSmsAddrFamily(ECdmaSmsWemtAddrApplication16BitPort);	
	smsaddr.SetPort(1000);
	ret=socket.Bind(smsaddr);
	@endcode
	*/
  	ECdmaSmsWemtAddrApplication16BitPort=ESmsAddrApplication16BitPort,

	// new values

	/** 
	Sockets bound to a ECdmaSmsAddrTeleservice address will receive messages 
	on a particular teleservice.

	As well as setting the address's family to ECdmaSmsAddrTeleservice, use 
	TCdmaSmsAddr::SetTeleserviceId to set the required teleservice.  For 
	example, to receive messages on the WEMT teleservice:

	@code
	smsaddr.SetCdmaSmsAddrFamily(ECdmaSmsAddrTeleservice);
	smsaddr.SetTeleserviceId(KTeleserviceWEMT);
	ret=socket.Bind(smsaddr);
	@endcode
	*/
	ECdmaSmsAddrTeleservice =10,
	/**
	Sockets bound to a ECdmaSmsWemtAddrWdp address will receive messages on 
	the WAP teleservice that are for a particular WDP port.

	As well as setting the address's family to ECdmaSmsWemtAddrWdp, set the 
	address's 'port' to a WDP port.  For example:

	@code
	smsaddr.SetCdmaSmsAddrFamily(ECdmaSmsAddrWdp);
	smsaddr.SetPort(wdpPort);
	ret=socket.Bind(smsaddr);
	@endcode
	*/
	ECdmaSmsAddrWdp =11,
	/** 
	Sockets bound to a ECdmaSmsAddrBroadcast address will receive broadcast 
	messages.  Note that broadcast messages cannot be received using other 
	address family.

	Broadcast messages belong to a service category. A socket can 
	be bound so that it receives broadcast messages from a specified service 
	category. Alternatively it can receive all broadcast messages, whatever 
	the service category.

	As well as setting the address's family to ECdmaSmsAddrBroadcast, use 
	TCdmaSmsAddr::SetPort to set the required service category from those in 
	tia637::TServiceCategory.
	
	@code
	// Receive messages from the Emergency Broadcast service catagory
	smsaddr.SetCdmaSmsAddrFamily(ECdmaSmsAddrBroadcast);
	smsaddr.SetPort(KEmergencyBroadcasts);
	ret=broadcastSocket.Bind(smsaddr);

	// Receive messages from any service category by setting the port to zero
	smsaddr.SetCdmaSmsAddrFamily(ECdmaSmsAddrBroadcast);
	smsaddr.SetPort(0);
	ret=broadcastSocket2.Bind(smsaddr);
	@endcode
	*/
	ECdmaSmsAddrBroadcast=12
	};


/**
Sockets for CDMA SMS messages must be bound to an address. A 
socket's address can be thought of as a rule that tells the sockets server 
which messages should be delivered to the socket. When the CDMA SMS stack 
receives a message, it compares the message to the address (or rule) of each 
of the CDMA SMS sockets.  If the message's contents match one of the rules, 
the SMS stack uses Symbian OS's sockets server to pass the message to an 
appropriate socket.

The address is an instance of TCdmaSmsAddr.  Create an instance then use its 
setter methods to configure up the address.  Before receiving SMS messages, 
RSocket::Bind must be called to bind a socket to a appropriate address.

Each address must belong to a family. This broadly defines the type of rule 
used to match messages to socket.   Set an address's family with 
SetCdmaSmsAddrFamily.  Depending upon the family, call methods to set further 
address variables, thus refining the rule further. To understand address 
better, see the descriptions of the address families in TCdmaSmsAddrFamily.

Two sockets cannot be bound to the same address - the second attempt to bind a 
socket will fail.

Sometimes, a message is received matches several addresses, and so could 
be sent to more than one socket.  The messages are compared to address in a 
particular order; see CdmaSmsAddressPriority below for more information.
*/
class TCdmaSmsAddr : public TSockAddr
	{
public:
	/** Maximum length of the text pattern used to match the incoming text. */
	enum { EMaxTextMatchLength = 24 };
public:
	IMPORT_C TCdmaSmsAddr();
	IMPORT_C TCdmaSmsAddrFamily CdmaSmsAddrFamily() const;
	IMPORT_C void SetCdmaSmsAddrFamily(TCdmaSmsAddrFamily aFamily);		
	IMPORT_C TPtrC8 TextMatch() const;
	IMPORT_C void SetTextMatch(const TDesC8& aText);
	IMPORT_C TInt NumTextMatchChar() const;
	IMPORT_C TBool operator==(const TCdmaSmsAddr& aAddr) const;
	IMPORT_C TInt CdmaSmsAddressPriority()const;
	IMPORT_C tia637::TTeleserviceId TeleserviceId() const;
	IMPORT_C void SetTeleserviceId(tia637::TTeleserviceId aTeleserviceId);
	};

#endif //__CDMASMSADDR_H__
