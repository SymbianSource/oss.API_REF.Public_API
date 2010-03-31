// Copyright (c) 2005-2009 Nokia Corporation and/or its subsidiary(-ies).
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

#ifndef __OBEXIRTRANSPORTINFO_H__
#define __OBEXIRTRANSPORTINFO_H__

#include <ir_sock.h>
#include <obextransportinfo.h>

/**
Concrete transport info type for use when using Irda ttp  transport controller.
@see KObexIrTTPProtocol
@publishedAll
@released
*/
NONSHARABLE_CLASS(TObexIrTransportInfo) : public TObexTransportInfo

	{
//From TObexIrProtocolInfo
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
	};

/**
Concrete transport info type for use when using Irda ttp  transport controller, with discovery extensions.
@see KObexIrTTPProtocolV2
@publishedAll
@released
*/
NONSHARABLE_CLASS(TObexIrV2TransportInfo) : public TObexIrTransportInfo

	{
//From TObexIrProtocolInfo
public:
	/** The number of discovery slots to use. */
	TUint8 iDiscoverySlots;
	/** The number of discovery attempts to make. */
	TUint8 iDiscoveryAttempts;
	
private:
	// This data padding has been added to help prevent future binary compatibility breaks	
	// None of these padding variables have been zero'd because they are currently not used
	TUint32     iPadding1; 
	TUint32     iPadding2; 		
	TUint32     iPadding3; 
	TUint32     iPadding4; 	
	};


/**
Concrete transport info type for use when using Irda ttp transport controller, with nickname extension.
@see KObexIrTTPProtocolV3
@publishedAll

@capability WriteDeviceData If the TObexIrV3TransportInfo is passed as the argument
                            to CObexServer::NewL or CObexClient::NewL and the associated 
                            name is valid.

@released
*/
NONSHARABLE_CLASS(TObexIrV3TransportInfo) : public TObexIrV2TransportInfo
	{
public:
	/** The device nickname.  The maximum length in the IrDA specification
	is defined as 23 - (number of hint octets [2] + 1)  =  20
	*/
	TBuf<20> iLocalDeviceNickname;
	
	/** A flag indicating if the device nickname field is valid.  This
	allows Symbian to make further derivations of this interface without making
	the device nickname mandatory */
	TBool iLocalDeviceNicknameValid;
	};

#endif // __OBEXIRTRANSPORTINFO_H__
