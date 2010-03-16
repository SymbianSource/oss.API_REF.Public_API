/*
* Copyright (c) 2002-2006 Nokia Corporation and/or its subsidiary(-ies). 
* All rights reserved.
* This component and the accompanying materials are made available
* under the terms of the License "Symbian Foundation License v1.0" to Symbian Foundation members and "Symbian Foundation End User License Agreement v1.0" to non-members
* which accompanies this distribution, and is available
* at the URL "http://www.symbianfoundation.org/legal/licencesv10.html".
*
* Initial Contributors:
* Nokia Corporation - initial contribution.
*
* Contributors:
*
* Description:  SDK Publish&Subscribe definitions of the
*                HW Resource Manager for the Power State API.
*
*/


#ifndef HWRMPOWERSTATESDKPSKEYS_H
#define HWRMPOWERSTATESDKPSKEYS_H

// INCLUDES
#include <e32std.h>

/** 
* @file hwrmpowerstatesdkpskeys.h
* 
* The API provides the P&S power state keys that are updated by the HW Resource 
* Manager Server. These keys provide up-to-date information on the charging 
* status, battery level and battery state of the device. Any application may 
* subscribe to these P&S keys that are updated to receive notifications of 
* any change in state.
*
* This interface relies on the Publish and Subscribe (P&S) interface provided
* by Symbian. P&S is used by HW Resource Manager to globally publish the power
* state information.
*
* The P&D UID is #KPSUidHWRMPowerState and following keys are provided:
* - #KHWRMBatteryLevel
* - #KHWRMBatteryStatus
* - #KHWRMChargingStatus
*/

/**
* P&S UID for all power state information keys provided by this API.
*/
const TUid KPSUidHWRMPowerState = { 0x10205041 }; 


/**
* P&S key to represent the battery level of the device. It can also be related
* to the number of battery bars displayed. This property is updated only when
* battery level changes. Valid values are defined by the enum #EPSHWRMBatteryLevel
* and range from -1 to 7. <br>
* If an error has occurred or the battery level has not yet been initialized, 
* the enumeration value of #EBatteryLevelUnknown is used. In all other cases 
* the battery level is used with level 0 being the lowest (battery empty) and 
* level 7 the highest (battery full).
*
* @see EPSHWRMBatteryLevel
*/
const TUint32 KHWRMBatteryLevel = 0x00000001;

/**
* Battery level of device. Can be related to the number of battery bars 
* displayed by the device.
*/
enum EPSHWRMBatteryLevel
    {
    EBatteryLevelUnknown        = -1,   ///< Uninitialized or some other error
    EBatteryLevelLevel0         = 0,    ///< Lowest battery level
    EBatteryLevelLevel1         = 1,
    EBatteryLevelLevel2         = 2,
    EBatteryLevelLevel3         = 3,
    EBatteryLevelLevel4         = 4,
    EBatteryLevelLevel5         = 5,
    EBatteryLevelLevel6         = 6,
    EBatteryLevelLevel7         = 7     ///< Highest battery level
    };


/**
* Battery status of device. 
* This property may be updated to same status as previously, to indicate
* the note in question needs to be shown again.
*
* #EBatteryStatusLow update comes approximately ten times before 
* battery is completely empty and it comes at approximately
* 10 minute intervals. If phone is in-call mode, update comes at 
* approximately 1 minute intervals.
*
* #EBatteryStatusEmpty comes slightly before phone must power down 
* automatically because of insufficient battery power.  
*
* @see EPSHWRMBatteryStatus
*/
const TUint32 KHWRMBatteryStatus = 0x00000002;

/**
* Battery status of device.
*/
enum EPSHWRMBatteryStatus
    {
    EBatteryStatusUnknown        = -1, ///< Uninitialized or some other error
    EBatteryStatusOk             = 0,  ///< This can also be used during charging
    EBatteryStatusLow            = 1,  ///< Show note to user "Battery low"
    EBatteryStatusEmpty          = 2   ///< Show "recharge battery" note to user
    };

/**
* Charging status of device.
* This property is updated only when charging status changes.
*
* @see EPSHWRMChargingStatus
*/
const TUint32 KHWRMChargingStatus = 0x00000003;

/**
* Charging status of device.
*/
enum EPSHWRMChargingStatus
    {
    EChargingStatusError              = -1, ///< Some error has occurred when charger is connected or charging. 
    EChargingStatusNotConnected       = 0,  ///< Charger not connected/uninitialized
    EChargingStatusCharging           = 1,  ///< Device is charging
    EChargingStatusNotCharging        = 2,  ///< Charger is connected, device not charging
    EChargingStatusAlmostComplete     = 3,  ///< Charging almost completed
    EChargingStatusChargingComplete   = 4,  ///< Charging completed
    EChargingStatusChargingContinued  = 5   ///< Charging continued after brief interruption
    };


#endif      // HWRMPOWERSTATESDKPSKEYS_H
