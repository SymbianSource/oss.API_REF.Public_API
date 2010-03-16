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

#ifndef PANPROG_H
#define PANPROG_H

#include <nifvar.h>

/**
@file
@note Constant definitions for clients using PAN agent.
Includes constants for controlling the state of the PAN network
*/

/**
Base value for constants for use with Control() call
@publishedPartner
@released
@see RConnection::Control
@note KCO* values for use with PAN agent
*/
const TInt KCOAgentPanBase = 0x1000;


/**
@publishedPartner
@released
@see RConnection::Control

Bring a new device into the PAN network.  The Control() call will complete as
soon as the PAN agent has started the process, so it may be several seconds
before the device is addressable.  It is also possible for the connection
attempt to fail even if the Control() method returns KErrNone, due to the
actual processing occuring asynchronously.

@code
RConnection connection;
TBTDevAddr remoteDeviceToAdd;
...
<Connect RConnection object, and find the remote device to add to the PAN>
...
TPtr8 ptr = remoteDeviceToAdd.Des();
User::LeaveIfError(connection.Control(KCOLAgent, KCOAgentPanConnectDevice, ptr));
@endcode

The use of a temporary TPtr is safe, as the Control method is synchronous.

@note KCO* value for use with PAN agent
*/
const TInt KCOAgentPanConnectDevice = KCOAgentPanBase | KConnReadUserDataBit;


/**
@publishedPartner
@released
@see RConnection::Control

Attempt to remove a connected device from the PAN network.

@code
RConnection connection;
TBTDevAddr remoteDeviceToRemove;
...
<Connect RConnection object, and find the remote device to remove from the PAN>
...
TPtr8 ptr = remoteDeviceToRemove.Des();
User::LeaveIfError(connection.Control(KCOLAgent, KCOAgentPanDisconnectDevice, ptr));
@endcode

The use of a temporary TPtr is safe, as the Control method is synchronous.

@note KCO* value for use with PAN agent
*/
const TInt KCOAgentPanDisconnectDevice = KCOAgentPanBase + 1 | KConnReadUserDataBit;



/**
@publishedPartner
@released
@see RConnection::Control

Return a list of connected devices.  If the buffer supplied is too small to
hold all of the device addresses, as many as will fit will be returned.  The
descriptor length will be adjusted to reflect the total connected device count.

@note Devices which are still in the process of connecting to the PAN network
will not be included.

@code
RConnection connection;
...
<Connect RConnection object>
...
TBuf8<7 * sizeof(TBTDevAddr)> buffer;
User::LeaveIfError(connection.Control(KCOLAgent, KCOAgentPanEnumerateDevices, buffer));

// For a c-style array:
TInt connectedDevices = buffer.Length() / sizeof(TBTDevAddr);
const TBTDevAddr* devices = reinterpret_cast<const TBTDevAddr*>(buffer.Ptr());
const TBTDevAddr device2 = devices[2];

// Or to iterate through the list:
TInt start = 0;
while (start < buffer.Length())
	{
	const TBTDevAddr* thisDevice = reinterpret_cast<const TBTDevAddr*>(buffer.Ptr() + start);
	start += sizeof(TBTDevAddr);
	}
@endcode

@note KCO* value for use with PAN agent
*/
const TInt KCOAgentPanEnumerateDevices = KCOAgentPanBase + 2 | KConnWriteUserDataBit;

enum TPANAgentProgress
/**
PAN agent progress values
@publishedAll
@released
*/
	{
	EPanAgtInitialising		= KMinAgtProgress,
	EPanAgtConnected        = KConnectionOpen,		///< Agent is up and running
	EPanAgtIdle,									///< Agent is idle
	EPanAgtListening,								///< Listening for incoming connections
	EPanAgtURole,									///< In U role
	EPanAgtGnRole,									///< In GN role
	EPanAgtNapRole,									///< In NAP role
	EPanAgtConnectedNewDevice,						///< A device has connected
	EPanAgtDisconnectedDevice,						///< A device has disconnected
	EPanAgtReconfiguringPiconet,					///< Role change is in progress
	EPanAgtUplinkRequired,							///< A connection authorised to use the uplink exists
	EPanAgtUplinkNotRequired,						///< A connection authorised to use the uplink does not exists
	EPanAgtDisconnecting 	= KConnectionStartingClose,
	EPanAgtDisconnected     = KConnectionClosed
	};
	
enum TPanNapNetworkType
/**
Type of network provided by the NAP gateway
@publishedAll
@released
*/
	{
	EPstn = 0x0000,
	EIsdn = 0x0001,
	EDsl = 0x0002,
	ECableModem = 0x0003,
	E10MbEthernet = 0x0004,
	E100MbEthernet = 0x0005,
	E4MbTokenRing = 0x0006,
	E16MbTokenRing = 0x0007,
	E100MbTokenRing = 0x0008,
	EFddi = 0x0009,
	EGsm = 0x000A,
	ECdma = 0x000B,
	EGprs = 0x000C,
	E3GCellular = 0x000D,
	EOther = 0xFFFE
	};

#endif // PANPROG_H
