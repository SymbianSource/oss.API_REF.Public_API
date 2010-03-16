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

#ifndef __SACLS_H__
#define __SACLS_H__

#include <e32std.h>

/**
System agent 2 - maintained entries
@publishedAll
@released
*/
const TInt KUidProfileValue		=0x100052D2;
const TUid KUidProfile			={KUidProfileValue};

/**
@capability WriteDeviceData capability is required for changing KUidPhonePwr property value.
@publishedAll
@released
*/
const TInt KUidPhonePwrValue=0x100052C5;
const TUid KUidPhonePwr={KUidPhonePwrValue};

/**
@publishedAll
@released
*/
enum TSAPhoneStatus
	{
	ESAPhoneOff,
	ESAPhoneOn
	};

/**
@capability WriteDeviceData capability is required for changing KUidSIMStatus property value.
@publishedAll
@released
*/
const TInt KUidSIMStatusValue	=0x100052C6;
const TUid KUidSIMStatus		={KUidSIMStatusValue};

/**
@publishedAll
@released
*/
enum TSASIMStatus
	{
	ESASimOk,
	ESASimNotPresent,
	ESASimRejected
	};

/**
@capability WriteDeviceData capability is required for changing KUidNetworkStatus property value.
@publishedAll
@released
*/
const TInt KUidNetworkStatusValue=0x100052C7;
const TUid KUidNetworkStatus	={KUidNetworkStatusValue};

/**
@publishedAll
@released
*/
enum TSANetworkStatus
	{
	ESANetworkAvailable,
	ESANetworkUnAvailable
	};

/**
@capability WriteDeviceData capability is required for changing KUidNetworkStrength property value.
@publishedAll
@released
*/
const TInt KUidNetworkStrengthValue  =0x100052C8;
const TUid KUidNetworkStrength  ={KUidNetworkStrengthValue};

/**
@publishedAll
@released
*/
enum TSANetworkStrength
	{
	ESANetworkStrengthNone,
	ESANetworkStrengthLow,
	ESANetworkStrengthMedium,
	ESANetworkStrengthHigh,
	ESANetworkStrengthUnknown
	};

/**
@capability WriteDeviceData capability is required for changing KUidChargerStatus property value.
@publishedAll
@released
*/
const TInt KUidChargerStatusValue	=0x100052C9;
const TUid KUidChargerStatus	={KUidChargerStatusValue};

/**
@publishedAll
@released
*/
enum TSAChargerStatus
	{
	ESAChargerConnected,
	ESAChargerDisconnected,
	ESAChargerNotCharging
	};

/**
@capability WriteDeviceData capability is required for changing KUidBatteryStrength property value.
@publishedAll
@released
*/
const TInt KUidBatteryStrengthValue  =0x100052CA;
const TUid KUidBatteryStrength  ={KUidBatteryStrengthValue};

/**
@publishedAll
@released
*/
enum TSABatteryStrength
	{
	ESABatteryAlmostEmpty,
	ESABatteryLow,
	ESABatteryFull
	};

/**
@capability WriteDeviceData capability is required for changing KUidCurrentCall property value.
@publishedAll
@released
*/
const TInt KUidCurrentCallValue	=0x100052CB;
const TUid KUidCurrentCall		={KUidCurrentCallValue};

/**
@publishedAll
@released
*/
enum TSACurrentCall
	{
	ESACallNone,
	ESACallVoice,
	ESACallFax,
	ESACallData,
	ESACallAlerting,
	ESACallRinging,
	ESACallAlternating,
	ESACallDialling,
	ESACallAnswering,
	ESACallDisconnecting
	};

/**
@publishedAll
@released
*/
const TInt KUidDataPortValue	=0x100052CC;
const TUid KUidDataPort			={KUidDataPortValue};

/**
@publishedAll
@released
*/
enum TSAPort
	{
	ESADataPortIdle,
	ESADataPortBusy	
	};

/**
@publishedAll
@released
*/
const TInt KUidInboxStatusValue	=0x100052CD;
const TUid KUidInboxStatus		={KUidInboxStatusValue};

/**
@publishedAll
@released
*/
enum TSAInboxStatus
	{
	ESAInboxEmpty,
	ESADocumentsInInbox
	};

/**
@publishedAll
@released
*/
const TInt KUidOutboxStatusValue=0x100052CE;
const TUid KUidOutboxStatus		={KUidOutboxStatusValue};

/**
@publishedAll
@released
*/
enum TSAOutboxStatus
	{
	ESAOutboxEmpty,
	ESADocumentsInOutbox
	};

/**
@publishedAll
@released
*/
const TInt KUidClockValue		=0x100052CF;
const TUid KUidClock			={KUidClockValue};

/**
@publishedAll
@released
*/
enum TSAClock
	{
	ESAAm,
	ESAPm
	};

/**
No longer used
@publishedAll
@released
*/
const TInt KUidAlarmValue		=0x100052D0;
const TUid KUidAlarm			={KUidAlarmValue};

/**
@publishedAll
@released
*/
enum TSAAlarm
	{
	ESAAlarmOff,
	ESAAlarmOn,
	};

/**
@publishedAll
@released
*/
const TInt KUidIrdaStatusValue	=0x100052D1;
const TUid KUidIrdaStatus		={KUidIrdaStatusValue};

/**
@publishedAll
@released
*/
enum TSAIrdaStatus
	{
	ESAIrLoaded,		//IRDA Irlap layer loaded
	ESAIrDiscoveredPeer,//Discovery begin
	ESAIrLostPeer,		//Discovery end
	ESAIrConnected,		//IRDA Irlap layer connected
	ESAIrBlocked,		//IRDA Irlap layer blocked
	ESAIrDisConnected,	//IRDA Irlap layer disconnected
	ESAIrUnloaded		//IRDA Irlap layer unloaded
	};
	
//-----------------------------------------------------------------------------
	
/**
This is a duplicate of Swi::KUidSoftwareInstallKey from swi/swispubsubdefs.h
This is the publish and subscribe property used by Secure Software Install to 
publish its current state. The publish and subscribe key is defined by 
SysAgent2 server, but we do not want to have a dependency to the security 
subsystem, so we redefine a constant with the same key value here so it may be used
by this and other Core OS layer components. We also define the property's
values in sacls.h too, see TSASwisOperation & TSASwisOperationStatus.

@internalTechnology
*/
const TInt KSAUidSoftwareInstallKeyValue = 0x102047B7;

/**
This is a duplicate of Swi::KSwisOperationMask from swi/swispubsubdefs.h
@see KSAUidSoftwareInstallKeyValue
@internalTechnology
*/
const TUint KSASwisOperationMask = 0xFF;

/**
This is a duplicate of Swi::TSwisOperation from swi/swispubsubdefs.h
@see KSAUidSoftwareInstallKeyValue
@internalTechnology
*/
enum TSASwisOperation
	{	
	ESASwisNone			= 0x00, ///< No operation
	ESASwisInstall		= 0x01, ///< Swis install operation is in progress
	ESASwisUninstall	= 0x02, ///< Swis uninstall operation is in progress
	ESASwisRestore		= 0x04  ///< Swis restore operation is in progress
	};


/**
This is a duplicate of Swi::KSwisOperationStatusMask from swi/swispubsubdefs.h
@see KSAUidSoftwareInstallKeyValue
@internalTechnology
*/
const TUint KSASwisOperationStatusMask = 0xFF00;  
	
/**
This is a duplicate of Swi::TSwisOperationStatus from swi/swispubsubdefs.h
@see KSAUidSoftwareInstallKeyValue
@internalTechnology
*/
enum TSASwisOperationStatus
	{
	ESASwisStatusNone		= 0x0000, ///< The current operation is in progress
	ESASwisStatusSuccess	= 0x0100, ///< The current/last operation succeeded
	ESASwisStatusAborted	= 0x0200  ///< The current/last operation failed		
	};	


//-----------------------------------------------------------------------------
		
/**
This is a duplicate of KUidJavaInstallKey from swi/swispubsubdefs.h
This is the Publish and Subscribe property used by Java install to publish its current 
state. The publish and subscribe key is defined by SysAgent2 server, but we
do not want to have a dependency to the security subsystem, so we redefine a constant 
with the same value here.
@internalTechnology
*/
const TInt KSAUidJavaInstallKeyValue = 0x1020806E;


/** This is the global definition used by Software Install server (SWIS)
This is the publish and subscribe property used by SWI to publish the most
recently installed or updated application. If the application has 
subsequently been uninstalled the value may refer to an application
that no longer exists. Has value KUidNull if no applications have been 
installed
 
@publishedPartner
@released
@capability ECapabilityTrustedUI capability is required to modify the value of this property
*/
const TUint KUidSwiLatestInstallation = 0x10272C8E;

/** This is the global definition of KUidJmiLatestInstallation used
by Java Midlet Installer
This is the publish and subscribe property used by JMI to publish the most
recently installed application. If the application has 
subsequently been uninstalled the value may refer to an application
that no longer exists. Has value KUidNull if no applications have been 
installed 

@publishedPartner
@released
@capability ECapabilityTrustedUI capability is required to modify the value of this property
*/
const TUint KUidJmiLatestInstallation = 0x10272D3D;


/** This is the global definitioin of KUidUnifiedCertstoreFlag. This publish
and subscribe property is used to notify users of changes in the unified certstore

@publishedPartner
@released
*/
const TUint KUidUnifiedCertstoreFlag = 0x10272C83;

/**
This is a duplicate of KUidBackupRestoreKey from the secure backup engine's sbdefs.h
This is the Publish and Subscribe property used by Secure Backup Engine to publish its current 
state. The publish and subscribe key is defined by SysAgent2 server.
@publishedAll
@released
*/
const TUint KUidBackupRestoreKey = 0x10202792;


/** 
This is a duplicate of KPosLastKnownLocationCategory from lbs's epos_lastknownlocationpsykeys.h
It should NOT be used directly.
Defines value UID of Location P&S keys category.
The publish and subscribe key is defined by SysAgent2 server.
@internalTechnology
 */
const TInt KSAPosLastKnownLocationCategoryValue	= 0x10009BFA;
const TUid KSAPosLastKnownLocationCategory = { KSAPosLastKnownLocationCategoryValue };

/**
This is a duplicate of KPosLastKnownLocation from lbs's epos_lastknownlocationpsykeys.h
ID of the Last Known Location key.
It should NOT be used directly.
Contains binary values, a buffer with packaged TPositionInfo.

If it contains a buffer, which length does not match TPositionInfo,
such value shall be ignored.

Client must have ReadDeviceData capability in order to read this key.
@internalTechnology
*/
const TInt KSAPosLastKnownLocation = 0x00000001;

/** 
This is a duplicate of KPosIndicatorCategoryUid from lbs's locationfwdomainpskeys.h
It should NOT be used directly.
Defines UID of Positioning Indicator P&S keys category. 
@internalTechnology
*/
const TInt KSAPosIndicatorCategoryValue = 0x101F7A79 ;
const TUid KSAPosIndicatorCategory = {KSAPosIndicatorCategoryValue};

/**
This is a duplicate of KPosIntGpsHwStatus from lbs's locationfwdomainpskeys.h
ID of the Integrated GPS HW Status key.
It should NOT be used directly.
May contain values defined by @ref TPosIntGpsHwIndicatorState.

Default value (i.e. when this key is not found) is EPosIntGpsHwIndicatorOff.

If it contains any other value than defined in @ref TPosIntGpsHwState,
such value shall be ignored and TPosIndicatorState::EPosIntGpsHwIndicatorOff
shall be assumed.
@internalTechnology
*/
const TInt KSAPosIntGpsHwStatus = 0x00000001;
// Deprecated - redundant method no longer used by system software
IMPORT_C TInt StartSysAgt2();

#endif //__SACLS_H__
