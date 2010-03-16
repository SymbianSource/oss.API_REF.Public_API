/*
* Copyright (c) 2002-2007 Nokia Corporation and/or its subsidiary(-ies). 
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
* Description:  This file contains SDK central repository key definitions
*                for the vibra
*
*/


#ifndef HWRMVIBRASDKCRKEYS_H
#define HWRMVIBRASDKCRKEYS_H

#include <e32std.h>

/** 
* @file hwrmvibrasdkcrkeys.h
* 
* The API provides the vibra related Centrl Repository keys. 
* These keys provide information on the vibra setting controlled by
* Profiles, maximum vibrating time supported by the device and 
* minimum time vibra cannot be started after it was forcibly 
* turned off when maximum time was reached. In addition keys
* provide tactile feedback setting controlled by profiles and 
* default intensity and duration for feedback vibration.
*
* This interface relies on the Central Repository (CenRep) interface provided
* by Symbian. 
*
* The CenRep UID is #KCRUidVibraCtrl and following keys are provided:
* - #KVibraCtrlProfileVibraEnabled
* - #KVibraCtrlMaxTime
* - #KVibraMinOffTime
*/

/**
* CenRep UID for all vibra related settings keys provided by this API.
*/
const TUid KCRUidVibraCtrl = {0x10200C8B};

/**
* Vibra setting controlled by Profiles. 
* 
* Possible integer values:
*
* 0 = Vibra is off in profile (default value) <br>
* 1 = Vibra is on in profile <br>
*/
const TUint32 KVibraCtrlProfileVibraEnabled     = 0x00000001;

/**
* Maximum vibrating time supported by device. 
* 
* Value is milliseconds as an integer. 
* If value is zero, no maximum time is supported.
* Maximum supported time is TMaxTInt microseconds in milliseconds.
*
* Value is read-only.
*
* Default value: 10000.
*/
const TUint32 KVibraCtrlMaxTime                 = 0x00000002;

/**
* Minimum time vibra cannot be started after it was
* forcibly turned off when maximum time was reached.
* This can be used to enforce vibra cooling after long 
* use periods.
*
* Value is milliseconds as an integer.
*
* Value is read-only.
*
* Default value: 0
*/
const TUint32 KVibraMinOffTime                  = 0x00000003;

/**
* Tactile feedback setting controlled by Profiles. 
* 
* Possible integer values:
*
* 0 = Tactile feedback is off in profile (default value) <br>
* 1 = Tactile feedback is on in profile <br>
*/
const TUint32 KVibraCtrlProfileFeedbackEnabled  = 0x00000004;

/**
* Tactile feedback vibration default intensity. 
* 
* Possible default intensity values are from the range -100...100.
*
* Value is read-only.
*
* Default value: 100
*/
const TUint32 KVibraCtrlFeedbackIntensity       = 0x00000005;

/**
* Tactile feedback vibration default duration. 
* 
* Value is milliseconds as an integer.
*
* Value is read-only.
*
* Default value: 20
*/
const TUint32 KVibraCtrlFeedbackDuration        = 0x00000006;


#endif  // HWRMVIBRASDKCRKEYS_H
            
// End of File
