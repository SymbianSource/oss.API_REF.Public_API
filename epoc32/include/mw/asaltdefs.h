// Copyright (c) 1999-2009 Nokia Corporation and/or its subsidiary(-ies).
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

#ifndef __ASALTDEFS_H__
#define __ASALTDEFS_H__

/** @file
@publishedAll
@released
*/
// System includes
#include <e32std.h>
#include <babitflags.h>

/** 
 Flags used to indicate the States for enum TASAltStateFlags
 */
typedef TBitFlags TASAltClientServerStateFlags;

/** 
 Major Version used while connecting to the Alarm Alert Server
 */
const TInt KASAltVersionMajor = 3;

/** 
 Minor Version used while connecting to the Alarm Alert Server
 */
const TInt KASAltVersionMinor = 0;

/** 
 Build Version used while connecting to the Alarm Alert Server
 */
const TInt KASAltVersionBuild = 0;

/** 
 Number of message Slots
 */
const TInt KAlmMessageSlots	= 5;

/** 
 The individual op codes which the Alert Server and Alarm Server
 handshake using
 */
enum TASAltOpCode
    {
	/**
	 Notify the alarm server (asynchronously) when the Alert Server
	 wishes to perform some action.
	 */
    EASAltOpCodeNotify = 0,

	/**
	 Cancel an earlier notification
	 */
    EASAltOpCodeNotifyCancel,

	/**
	 Change the visibility of the Alert Server UI furniture
	 */
	EASAltOpCodeVisible,

	/**
	 Update the Alert Server flags
	 */
    EASAltOpCodeSetState,

	/**
	 Inform the Alert Server of the currently notifying alarm
	 */
    EASAltOpCodeSetAlarm,

	/**
	 Inform the Alert Server that the currently alerting alarm
	 has been snoozed.
	 */
	EASAltOpCodeSetDeferTime,

	/**
	 Retrieve the time from the Alert Server when a quiet period 
	 should be terminated
	 */
	EASAltOpCodeGetUserTime,

	/**
	 Create an outstanding request with the Alert Server. Used
	 as a mechanism to obtain Alert Server thread death notifications.
	 */
	EASAltOpCodeLogon,

	/**
	 Ask the Alert Server to start playing the specified alarm sound
	 */
	EASAltOpCodeStartPlayingSound,

	/**
	 Ask the Alert Server to stop playing any sound
	 */
	EASAltOpCodeStopPlayingSound

	/**
	Ask the  Alert Server to change vissibility for all alarms
	*/
	, EASAltOpCodeVisibleAll,
	
	/**
	Ask the  Alert Server to update states for all alarms
	*/
	EASAltOpCodeSetStateAll,
	
	/**
	Ask the  Alert Server to stop playing all sounds.
	*/
	EASAltOpCodeStopPlayingSoundAll,
	
	/**
	Ask the  Alert Server to delete alarm with provided Id
	*/
	EASAltOpCodeDeleteAlarm,

	/**
	 Retrieve the time from the Alert Server when a quiet period 
	 should be terminated
	 */

	EASAltOpCodeGetEndQuietTime,

	/**
	Ask the Alarm Server to get number of simultaneously supported alarms
	*/
	EASAltOpCodeGetMaxAlarms,
	
	/**
	Ask the  Alert Server to delete all alarms
	*/
	EASAltOpCodeDeleteAlarmAll,
			
	EASAltOpCodeLast
	
	
    };

/**
 All communication from the Alert Server to the Alarm Server
 occurs via a single outstanding TRequesStatus which is handled
 by the Alarm Server (as an active object). This enumeration
 describes the type of action that the Alarm Server should take in
 response to a request from the Alert Server.
 */
enum TASAltAlertServerResponse
	{
	/**
	 The Alert Server wishes the Alarm Server to
	 silence all alarms.
	 */
	EASAltAlertServerResponseSilence = 0,

	/**
	 The Alert Server wishes the Alarm Server to
	 enter a global quiet period.
	 */
	EASAltAlertServerResponseQuietPeriod,

	/**
	 The Alert Server wishes the Alarm Server to
	 acknowledge (clear) the currently notifying alarm.
	 */
	EASAltAlertServerResponseClear,

	/**
	 The Alert Server wishes the Alarm Server to
	 acknowledge (clear) the currently notifying alarm
	 and all others that are awaiting notification.
	 */
	EASAltAlertServerResponseClearAll,

	/**
	 The Alert Server wishes the Alarm Server to
	  snooze the currently notifying alarm.
	 */
	EASAltAlertServerResponseSnooze,

	/**
	 The Alert Server wishes the Alarm Server to
	 temporarily pause all sound (i.e stop sending sound
	 play events to the Alert Server).
	 */
	EASAltAlertServerResponsePauseSound
	};

/**
 Flags for TASAltClientServerStateFlags
 */
enum TASAltStateFlags
	{
	/**
	 The Alert Server should not play any sound
	 */
	EASAltStateFlagsSilentRunning = 1,

	/**
	 The Alarm Server is currently within a quiet period
	 */
	EASAltStateFlagsInQuietPeriod = 2,

	/**
	 The Alarm Server currently has more than one alarm
	 ready to notify.
	 */
	EASAltStateFlagsMoreThanOneDueAlarm	= 3,

	/**
	 There wasn't sufficient memory within the Alarm
	 Server to allocate room for a snoozed alarm. I'm
	 note convinced we need this anymore
	 */
	EASAltStateFlagsNoMemoryForSnoozeAlarm = 4,

	/**
	 There isn't any sound filename for the current
	 alarm.
	 */
	EASAltStateFlagsAlarmHasNoSoundFileName	= 5,

	/**
	 This isn't used by the Alert Server.
	 */
	EASAltStateFlagsSoundIsPaused = 6

	};

// Literal constants
_LIT(KAlarmAlertServerName, "!AlarmAlertServer");


#endif
