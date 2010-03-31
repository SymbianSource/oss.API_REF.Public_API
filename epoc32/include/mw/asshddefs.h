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

#ifndef __ASSHDDEFS_H__
#define __ASSHDDEFS_H__

/** @file
@publishedAll
@released */

// System includes
#include <e32std.h>
#include <babitflags.h>

// Constants

/** Maximum length of an alarm message. The message is usually displayed by the 
alarm UI. */
const TInt KMaxAlarmMessageLength = 0x80;
/** Maximum length of the filename of the sound played when an alarm expires. */
const TInt KMaxAlarmSoundNameLength = KMaxFileName;

// Type definitions
/** A unique identifier allocated to each new alarm by the alarm server, so that 
the client can identify them. By default, KNullAlarmId. */
typedef TInt TAlarmId;
/** A unique identifier that can optionally be used by clients to group 
alarms into categories, for instance alarms associated with a particular application 
or application engine. The alarm server ignores the category. It is relevant 
to the client alone. */
typedef TUid TAlarmCategory;
//
/** Flags that define an alarm's characteristics.

@see TAlarmCharacteristics */
typedef TBitFlags8 TAlarmCharacteristicsFlags;
//

/** A type to identify what kind of alarms should be deleted when using the API
RASCliSession::AlarmDeleteByCategory()
@see TTDeleteTypeEnum */
typedef TInt TDeleteType;
 
/** Stores the text message associated with an alarm. */
typedef TBuf<KMaxAlarmMessageLength> TAlarmMessage;
/** Stores the name of a sound file which is played when an alarm activates. */
typedef TBuf<KMaxAlarmSoundNameLength> TAlarmSoundName;
//
/** Defines a null alarm identifier. */
const TAlarmId KNullAlarmId	= 0;
//
/** Defines the length in seconds of an alarm sound offset. */
const TInt KDefaultSoundPlayOffsetInSeconds	= 0;
/** Defines the length in seconds of an alarm sound duration. */
const TInt KDefaultSoundPlayDurationInSeconds = 30;

// Constants
/** A category that can be assigned to identify clock alarms to the client. The 
server does not distinguish between alarm types. */
const TAlarmCategory KASCliCategoryClock		= { 0x101F5030 };

/** Defines whether an alarm is enabled or disabled: 

An enabled alarm activates at a specified time. 

A disabled alarm remains in the alarm server queue but is not active. 

You can get or set an alarm's status using the RASCliSession class. */
enum TAlarmStatus
	{
	/** The alarm is currently enabled. */
	EAlarmStatusEnabled = 0,

	/** The alarm is currently disabled, and will not expire. */
	EAlarmStatusDisabled,
	};

/** Represents an alarm's state. Alarms can have only one state. */
enum TAlarmState
	{
	/** The alarm state is not currently known by the alarm server. */
	EAlarmStateInPreparation = -1,

	/** The alarm is waiting for its expiry time to be reached. */
	EAlarmStateQueued = 0,

	/** The alarm is snoozed. When the snooze period is over, the alarm expires again. */
	EAlarmStateSnoozed,

	/** The alarm is waiting to be notified. 
	
	This state occurs when an alarm expires while another is being notified. When 
	this happens, the alarm being notified changes state to EAlarmStateWaitingToNotify. 
	This means that if it is set to be the next alarm to be notified, notification 
	will happen after the newly expired alarm has been notified and dismissed. */
	EAlarmStateWaitingToNotify,

	/** The alarm is currently notifying. */
	EAlarmStateNotifying,

	/** The alarm has already notified and has been dismissed. Any alarm which remains 
	in this state is dead. */
	EAlarmStateNotified
	};

/** Defines an alarm session type as timed or untimed. This property is ignored by 
the alarm server, and is for use by the client only. */
enum TAlarmDayOrTimed
	{
	/** Timed alarm type (default). This alarm belongs to a timed event. This is an event 
	with a defined start and finish time. The alarm notification 
	time is specified as an offset from the event's start time, so that when the 
	event time changes, so does the alarm time. */
	EASShdAlarmTypeTimed = 0,

	/** Day alarm type. This alarm belongs to untimed events; these do not have 
	a defined start and finish time, but have an activation time. */
	EASShdAlarmTypeDay
	};

/** Defines the sound state of the global alarm server . */
enum TAlarmGlobalSoundState
	{
	/** When an alarm expires, the alarm sound is played. */
	EAlarmGlobalSoundStateOn = 0,

	/** When an alarm expires, no sound plays. */
	EAlarmGlobalSoundStateOff
	};

/** Defines how an alarm is to be repeated. */
enum TAlarmRepeatDefinition
	{
	/** The alarm expires only once, and is then deleted from the alarm server. By 
	default, all alarms behave this way. 
	
	Standard repeat-once alarms are date relative, that is, they occur on a fixed 
	date and point in time. 
	
	If the user changes the system date or time so that the new time is in the 
	future, and the new time is after the previously calculated expiry time:
	
	By less than 12 hours, the alarm expires immediately. 
	
	By more than 12 horus, the alarm is silently discarded. 
	
	If the user changes the system date or time so that the new time is before 
	the next calculated expiry time, the alarm type continues to be a
	"Repeat once" alarm*/
	EAlarmRepeatDefintionRepeatOnce	= 0,

	/** When initially scheduling the alarm, the date is always within the 
	next 24 hours. For example:
	
	The current time is 15:00, and the alarm time specified is 14:00. The 
	alarm expires tomorrow at 14:00. 
	
	The current time is 15:00, and the alarm time specified is 16:00. The 
	alarm expires today at 16:00. 
	
	If the alarm is missed, i.e. because the alarm server is inactive, then 
	the alarm changes its type from "Repeat in the next 24 Hours" to "Repeat once".
	
	If the user changes the system date or time so that the new time is in the 
	future, and the new time is after the previously calculated expiry time:
	
	By less than 12 hours, the alarm expires immediately. 
	
	By more than 12 horus, the alarm is silently discarded. 
	
	If the user changes the system date or time so that the new time is 
	before the next calculated expiry time:

	By less than 12 hours, no change in alarm type, and the alarm 
	remains queued.

	By greater than 12 hours, the alarm changes its type from 
	"Repeat in the next 24 Hours" to "Repeat once".	Subsequent changes in system 
	time result in the behaviour described by the EAlarmRepeatDefintionRepeatOnce 
	characteristic. */
	EAlarmRepeatDefintionRepeatNext24Hours,

	/** The alarm repeats every day at the same time. If the user changes the system 
	date or time, this alarm behaves in the same way as a "Repeat once" alarm, 
	except that the alarm is not deleted, but rescheduled for the next available 
	time. 
	
	If the user changes the system date or time to a point in the past, there 
	are no phantom alarm expiries. */
	EAlarmRepeatDefintionRepeatDaily,

	/** The alarm repeats every work day at the same time. If the user changes the 
	system date or time, this alarm behaves in the same way as a "Repeat once" 
	alarm, except that the alarm is not deleted, but rescheduled for the next 
	available time. 
	
	If the user changes the system date or time to a point in the past, there 
	are no phantom alarm expiries. */
	EAlarmRepeatDefintionRepeatWorkday,

	/** The alarm repeats every week, on the same day at the same time. If the user 
	changes the system date or time, this alarm behaves in the same way as a "Repeat 
	once" alarm, except that the alarm is not deleted, but rescheduled for the 
	next available time.
	
	If the user changes the system date or time to a point in the past, there 
	are no phantom alarm expiries. */
	EAlarmRepeatDefintionRepeatWeekly,

#ifdef SYMBIAN_ALARM_REPEAT_EXTENSIONS
	/** The alarm repeats every specified day at the same time. If the user
	changes the system date or time, this alarm behaves in the same way as a
	"repeat once" alarm, except that the alarm is not deleted, but rescheduled
	for the next available time.
	 
    If the user changes the system date or time to a point in the past, there
    are no phantom alarm expiries.*/ 
	EAlarmRepeatDefinitionRepeatDailyOnGivenDays
#endif
	};

/** Defines various alarm characteristics. */
enum TAlarmCharacteristics
	{
	/** Sets an alarm to be session-only. This alarm only exists as long as a session 
	is maintained with the alarm server. Session alarms are removed from the alarm 
	queue when the originating session disconnects from the server. By default, 
	all alarms are persistent and remain so, even after the initiating session 
	has disconnected. */
	EAlarmCharacteristicsSessionSpecific = 0,

	/** Do not display a screen. By default, all alarms result in a suitable screen 
	being displayed, depending on the device. Use this flag to disable this default 
	behaviour. */
	EAlarmCharacteristicsDoNotNotifyAlarmAlertServer = 1,

	/** Sets an alarm to be floating - floating alarms expire at the current local time,
	regardless of the current locale or DST rules.*/
	EAlarmCharacteristicsIsFixed = 2,
	
	/** Do not notify if its due time is in the past.*/
	EAlarmCharacteristicsDeQueueIfDueTimeInPast = 3,
	//
	EAlarmCharacteristicsLast
	};

/** This enumeration defines the events that can be reported by the alarm server. 

These events are channelled to the client using the RASCliSession::NotifyChange() 
method. 

@see TAlarmState */
enum TAlarmChangeEvent
	{
	/** An alarm has changed state. 
	
	@see TAlarmState */
	EAlarmChangeEventState = 1,

	/** An alarm has changed status. 
	
	@see TAlarmStatus */
	EAlarmChangeEventStatus = 2,

	/** An alarm has changed characteristics. 
	
	@see TAlarmCharacteristics */
	EAlarmChangeEventCharacteristics = 3,

	/** An alarm has been deleted from the queue of alarms. */
	EAlarmChangeEventAlarmDeletion = 4,

	/** An alarm has been added to the queue of alarms. */
	EAlarmChangeEventAlarmAddition = 5,

	/** An alarm has expired. */
	EAlarmChangeEventTimerExpired = 6,

	/** The sound for an alarm has just started playing. */
	EAlarmChangeEventSoundPlaying = 7,

	/** The sound for an alarm has just stopped playing. */
	EAlarmChangeEventSoundStopped = 8,

	/** The sound intervals associated with sound timing have changed. */
	EAlarmChangeEventPlayIntervalsChanged = 9,

	/** The global sound state (on/off) has changed. */
	EAlarmChangeEventGlobalSoundStateChanged = 10,

	/** The next alarm at the head of the alarm queue has changed. */
	EAlarmChangeEventHeadQueueItemChanged = 11,

	/** The system date or time has changed, or the days defined as workdays have changed. */
	EAlarmChangeEventSystemDateTimeChanged = 12,

	/** The alarm alert server has been instructed to show the 'alarm expired' display. */
	EAlarmChangeEventAlarmUIVisible = 13,

	/** The alarm alert server has been instructed to hide the 'alarm expired' display. */
	EAlarmChangeEventAlarmUIInvisible = 14,

	/** Alarm sounds have been temporarily silenced, the current alarm has been paused 
	or re-enabled. */
	EAlarmChangeEventSoundSilence = 15,

	/** The data associated with an alarm has changed. */
	EAlarmChangeEventAlarmData = 16,

	/** A restore from backup of the alarm server has started. Alarms cannot be added/deleted 
	until this has finished.  */
	EAlarmChangeEventRestoreStarted = 17,

	/** A restore from backup of the alarm server has failed. Alarms can be added/deleted again. */
	EAlarmChangeEventRestoreFailed = 18,

	/** A restore from backup of the alarm server has completed. The alarm queue has changed. */
	EAlarmChangeEventRestoreCompleted = 19,

	/** Last change event (anchor). This is always at the end of the list. */
	EAlarmChangeEventLast,
	
	/** An undefined alarm event has occurred. */
	EAlarmChangeEventUndefined = 0
	};

/** Identifies server-initiated panics relating to the client session. */
enum TAlarmServerInitiatedClientPanic
	{
	/** This panic occurs when the client requests a copy of any data attached to an 
	alarm, but does not supply enough buffer space to contain the data. */
	EAlarmServerInitiatedClientPanicInsufficientRoomForAlarmData = 0,

	/** This panic usually occurs when a client method tries to write to a descriptor 
	(sometimes asynchronously), and the client-supplied descriptor is not valid. */
	EAlarmServerInitiatedClientPanicBadDescriptor = 1,

	/** This panic occurs when a client already has an outstanding notification request, 
	but attempts to request another. */
	EAlarmServerInitiatedClientPanicChangeNotificationAlreadyOutstanding = 2,

	/** This panic occurs when a client tries to perform an invalid operation. */
	EAlarmServerInitiatedClientPanicInvalidOperation = 3,

	/** This panic occurs when a request to add an alarm contains a null alarm identiifer. 
	In the case of alarms with notifications, the client should pre-allocate the 
	alarm identifier before requesting the notification. */
	EAlarmServerInitiatedClientPanicBadPreAllocatedAlarmId = 4

	};

/** Identifies what kind of alarms the client wants to delete. */
enum TDeleteTypeEnum
	{
	/** All type of alarms. */
	EAllAlarms = 0,
	/** Alarms future of the current time */
	EFuture = 1,
	/** Alarms in the past of the current time but notifying, or waiting to notify, or snoozed by, the user  */
	EActive = 2,
	/** alarms that has been dismissed by the user  */
	EExpired = 4
	};

#ifdef SYMBIAN_ALARM_REPEAT_EXTENSIONS
/**
This enumeration indicates which days of the week an alarm with a repeat
definition of EAlarmRepeatDefinitionRepeatDailyOnGivenDays activates on.  Days
are combined using the bitwise OR operator.

@prototype
*/
enum TAlarmDays
    {
    /** Alarm is active on Monday. */
    EAlarmDayMonday    = 0x01,
    /** Alarm is active on Tuesday. */
    EAlarmDayTuesday   = 0x02,
    /** Alarm is active on Wednesday. */
    EAlarmDayWednesday = 0x04,
    /** Alarm is active on Thursday. */
    EAlarmDayThursday  = 0x08,
    /** Alarm is active on Friday. */
    EAlarmDayFriday    = 0x10,
    /** Alarm is active on Saturday. */
    EAlarmDaySaturday  = 0x20,
    /** Alarm is active on Sunday. */
    EAlarmDaySunday    = 0x40
    };
#endif

#ifdef SYMBIAN_SKIPPED_CALENDAR_ALARMS
/** Identifies the type of alarm which was missed.  A UTC offset change will only
affect floating alarms whereas a system time change may affect either floating
or fixed alarms.
@see TASShdAlarmedInstanceParams
@see CASSrvAlarmQueue::MEnvChangeHandleEvent
*/
enum TASShdAlarmTimeType
	{
	/** Floating time alarm. */
	EFloating,
	/** Floating or fixed time alarm. */
	EFloatingOrFixed
	};
#endif

#endif
