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

#ifndef __ASSHDALARM_H__
#define __ASSHDALARM_H__


// System Includes
#include <e32base.h>
#include <s32strm.h>

// User Includes
#include <asshddefs.h>

#ifndef SYMBIAN_ENABLE_SPLIT_HEADERS

/**
 * The Alarm publish and subscribe category
 * 
 * @publishedPartner
 * @released
 */
const TUid KAlarmServerPubSubCategory = { 0x101f5027 };

/**
 * Used for subcribing missed alarms or time zone changes
 * @publishedPartner
 * @released
 */
const TUint KMissingAlarmPubSubKey = 100;

/**
 * The publish and subscribe data for KMissingAlarmPubSubKey
 * @publishedPartner
 * @released
 */
struct TMissedAlarmPubSubData
	{
	/**
	 * The value indicating the changes.
	 * 1 - Time zone has been changes but there are no missed alarms
	 * 2 - Some alarms have been missed after system time or time zone has changed.
	 */
	TUint8 iValue;
	
	/**
	 * The time that system time change took place, in universal (UTC) time 
	 */
	TTime iTimeOfChangeUtc;
	};

#ifdef SYMBIAN_SKIPPED_CALENDAR_ALARMS
/**
 * Used for subscribing to data used when searching for instances in Calendar
 * @publishedPartner
 * @released
 */
const TUint KSkippedAlarmInstancesPubSubKey = 101;

/**
 * The publish and subscribe data for KMissingAlarmInstancesPubSubKey
 * @publishedPartner
 * @released
 */
struct TASShdAlarmedInstanceParams
	{
	/**
	 * The start of the time range in local time.
	 */ 
	TTime iLocalStartTime;

	/**
	 * The end of the time range in local time.
	 */
	TTime iLocalEndTime;
	
	/**
	 * The alarm time types to include.
	 */
	TASShdAlarmTimeType iTimeType;
	};

#endif //SYMBIAN_SKIPPED_CALENDAR_ALARMS
#endif //SYMBIAN_ENABLE_SPLIT_HEADERS


#ifdef SYMBIAN_SYSTEM_STATE_MANAGEMENT

/**
 * Used for subcribing wake-up alarm set and unset notifications
 * Belonging to the KAlarmServerPubSubCategory alarm publish and subscribe category
 * 
 * @publishedPartner
 * @released
 */
const TUint KWakeupAlarmPubSubKey = 102;

/**
 * Alarm server sets KWakeupAlarmPubSubKey value to EActiveWakeupAlarmSet when there is an active
 * wakeup alarm in the alarm queue otherwise sets it to EActiveNoWakeupAlarmsSet. 
 * A wakeup alarm starts the device if it is powered off when the alarm expires. If 
 * the device is in normal mode then it works as a clock alarm.      
 * An active wakeup alarm is a wakeup alarm which has been set and has not started to alert yet.
 *  
 * EActiveWakeupAlarmUninitialized is used to notify the listeners of 'KWakeupAlarmPubSubKey' 
 * key that the Alarm Server has just started at the device boot time and it needs to internalize 
 * Alarm Queue from backup before checking for the presence of active wake-up alarm. 
 *  
 * @publishedPartner
 * @released
 */
enum TActiveWakeupAlarmStatus
    {
    EActiveWakeupAlarmUninitialized = 100,
    EActiveWakeupAlarmSet,
    EActiveNoWakeupAlarmsSet,
    };

#endif

/**
 * A client-side alarm object.
 * 
 * It contains all of the information needed to create an alarm in the Alarm Server.
 * 
 * @publishedAll
 * @released
 */
class TASShdAlarm
	{
public:										

	IMPORT_C TASShdAlarm();

public:										

	IMPORT_C void InternalizeL(RReadStream& aStream);
	IMPORT_C void ExternalizeL(RWriteStream& aStream) const;

public:								
    // Read-Only Access
    
    /**
     * Returns the alarm status.
     * 
     * @return Alarm status.
     */
	inline TAlarmStatus	Status() const { return iStatus; }

	/**
	 * Returns the alarm state.
	 * 
	 * @return Alarm state.
	 */
	inline TAlarmState State() const { return iState; }

	IMPORT_C TBool HasAssociatedData() const;
	IMPORT_C TBool HasOwningSession() const;
	IMPORT_C TBool HasBecomeOrphaned() const;
	
public:								

	IMPORT_C void Reset();

    /**
     * Returns a writable version of the alarm's unique identifier.
     * 
     * @return Reference to the unique identifier.
     */
	inline TAlarmId& Id() { return iAlarmId; }

	/**
	 * Return the alarm's unique identifier.
	 * 
	 * @return The unique identifier.
	 */
	inline TAlarmId	Id() const { return iAlarmId; }
		
	/**
	 * The Secure ID is only used in the secured platform
	 */ 
	
	// adds a SID to the alarms private field
	inline void SetSid(const TSecureId& aSecureID) {iTASShdAlarmSID = aSecureID;}
	
	//	returns the SID of the alarm's creator
	inline TSecureId GetSid() const {return iTASShdAlarmSID;}

    /**
     * Returns a writable version of the next time the alarm is scheduled to expire.
     * 
     * @return Next expiry time.
     */
	inline TTime& NextDueTime() { return iNextDueTime; }

    /**
     * Returns the next time that the alarm is scheduled to expire.
     * 
     * @return Next expiry time.
     */
	inline const TTime&	NextDueTime() const { return iNextDueTime; }

    /**
     * Returns a writable version of the alarm's original expiry time.
     * 
     * @return Original expiry time.
     */
	inline TTime& OriginalExpiryTime() { return iOriginalExpiryTime; }

    /**
     * Returns the alarm's original expiry time.
     * 
     * The original expiry time is the same as the next due time, unless the alarm
     * has been snoozed. In that case, the original expiry time is the time when
     * the alarm first expired, and the next due time is when it is to re-awaken
     * after the snooze.
     * 
     * @return Original expiry time.
     */
	inline const TTime& OriginalExpiryTime() const { return iOriginalExpiryTime; }

    /**
     * Returns a writable version of the alarm's category.
     * 
     * Clients can use the category to tag each alarm with a specific code. This
     * allows clients to identify all related alarms, such as all alarms associated
     * with a particular application or application engine.
     * 
     * @return Alarm category.
     */
	inline TAlarmCategory& Category() { return iCategory; }

    /**
     * Return this alarm's category.
     * 
     * @return Alarm category.
     */
	inline TAlarmCategory Category() const { return iCategory; }

    /**
     * Returns a writable version of the alarm's characteristics.
     * 
     * @return Alarm characteristics bit flags.
     */
	inline TAlarmCharacteristicsFlags& Characteristics() { return iCharacteristics; }

    /**
     * Returns the alarm's characteristics
     * 
     * @return Alarm characteristics bit flags.
     */
	inline TAlarmCharacteristicsFlags Characteristics() const { return iCharacteristics; }

    /**
     * Returns a writable version of the alarm's repeat definition.
     * 
     * The repeat definition controls the alarm's behaviour after it has expired.
     * For example, you can set the repeat definition so that the server automatically
     * queues the alarm to expire again in exactly 24 hours time.
     * 
     * @return Alarm repeat definition.
     */
	inline TAlarmRepeatDefinition& RepeatDefinition() { return iRepeatDefinition; }

    /**
     * Returns the repeat definition for the alarm.
     * 
     * @return The alarm's repeat definition.
     */
	inline TAlarmRepeatDefinition RepeatDefinition() const { return iRepeatDefinition; }

    /**
     * Returns a writable version of the alarm's message.
     * 
     * The message is usually displayed in the application UI when the alarm expires.
     * 
     * @return Reference to the alarm's associated message.
     */
	inline TAlarmMessage& Message() { return iMessage; }

    /**
     * Returns the alarm's message.
     * 
     * The message is usually displayed in the application UI when the alarm expires.
     * 
     * @return Reference to the alarm's associated message.
     */
	inline const TAlarmMessage& Message() const { return iMessage; }

    /**
     * Return a writable version of the alarm sound's filename.
     * 
     * @return Reference to the alarm's sound filename.
     */
	inline TAlarmSoundName& SoundName() { return iSoundName; }

    /**
     * Returns the alarm's sound filename.
     * 
     * @return Sound filename.
     */
	inline const TAlarmSoundName& SoundName() const { return iSoundName; }

    /**
     * Returns the alarm session type.
     * 
     * @return Alarm session type.
     */
	inline TAlarmDayOrTimed DayOrTimed() const { return iDayOrTimed; }

    /**
     * Returns a writable version of the alarm type, i.e. day, timed
     * 
     * @return iDayOrTimed.
     */ 
	inline TAlarmDayOrTimed& DayOrTimed() { return iDayOrTimed; }
   
	IMPORT_C void SetUtcNextDueTime(TTime aUtcTime);
	IMPORT_C void SetDeQueueIfDueTimeInPast();
	
#ifdef SYMBIAN_SYSTEM_STATE_MANAGEMENT
	IMPORT_C void SetWakeup(TBool aEnabled);
	IMPORT_C TBool IsWakeup() const;
#endif

#ifdef SYMBIAN_ALARM_REPEAT_EXTENSIONS
	IMPORT_C TInt SetAlarmDays(TUint8 aAlarmDays);
	IMPORT_C TUint8 AlarmDays() const;
	IMPORT_C void SetContinuous(TBool aContinuous);
	IMPORT_C TBool Continuous();
#endif
	
public:										
    // CLient Data Access 

    /**
     * Returns a writable version of the alarm's client flags.
     * 
     * The client flags may be used for any client-specific data - the alarm server does not use them.
     * 
     * @return Reference to the alarm's bit flags.
     */
	inline TBitFlags16& ClientFlags() { return iClientFlags; }

    /**
     * Returns this alarm's client flags.
     * 
     * @return Reference to the alarm's bit flags.
     */
	inline TBitFlags16 ClientFlags() const { return iClientFlags; }

    /**
     * Returns the client data from slot 1 for this alarm.
     * 
     * @return The first client-specific integer.
     */
	inline TInt	ClientData1() const { return iClientData1; }

    /**
     * Returns a writable version of the client data from slot 1 for this alarm.
     * 
     * @return Reference to the first client-specific integer.
     */
	inline TInt& ClientData1() { return iClientData1; }

    /**
     * Returns the client data from slot 2 for this alarm.
     * 
     * @return The second client-specific integer.
     */
	inline TInt ClientData2() const { return iClientData2; }

    /**
     * Returns the client data from slot 2 for this alarm.
     * 
     * @return The second client-specific integer.
     */
	inline TInt& ClientData2() { return iClientData2; }
		
	
    /**
     * Tests whether the alarm is floating.
     * 
     * Floating alarms expire at a given wall-clock time regardless of the 
     * current locale and whether any daylight saving time rules are in force.
     * 
     * @return True if the alarm is floating.
     */
	inline TBool IsFloating() const { return iCharacteristics.IsClear(EAlarmCharacteristicsIsFixed); }
	
protected:									
    // Internal Flags
    
#ifndef SYMBIAN_ENABLE_SPLIT_HEADERS
	/*
	 * @internalAll
	 */
	enum TASShdAlarmFlags
		{
		/**
		 * @publishedAll
		 */
		EASShdAlarmFlagsHasAssociatedData	= 0,

		/**
		 * @publishedAll
		 */
		EASShdAlarmFlagsHasOwningSession	= 1,

		/**
		 * @publishedAll
		 */
		EASShdAlarmFlagsHasBecomeOrphaned	= 2,
		
		/**
		 * Set if alarm is disabled manually so that can not be enabled when locale changes.
		 * 
		 * @publishedAll 
		 */
		EASShdAlarmFlagsPermanentDisabled	= 4
		};
#endif

private:
#ifndef SYMBIAN_ENABLE_SPLIT_HEADERS
    
#ifdef SYMBIAN_SYSTEM_STATE_MANAGEMENT
	/*
	 * @internalComponent
	 */
	enum TASShdAlarmFlags2
		{
		EASShdAlarmFlag2Wakeup = 0,
		};
#endif
	
#ifdef SYMBIAN_ALARM_REPEAT_EXTENSIONS
    /*
	 * @internalComponent
	 */
	enum TASShdAlarmFlags2AlarmRepeatExtensions
		{
		EASShdAlarmFlag2AlarmDayMonday		= 1,
		EASShdAlarmFlag2AlarmDayTuesday		= 2,
		EASShdAlarmFlag2AlarmDayWednesday	= 3,
		EASShdAlarmFlag2AlarmDayThursday	= 4,
		EASShdAlarmFlag2AlarmDayFriday		= 5,
		EASShdAlarmFlag2AlarmDaySaturday	= 6,
		EASShdAlarmFlag2AlarmDaySunday		= 7,
		EASShdAlarmFlag2Continuous			= 8
		};
#endif
	
#endif //SYMBIAN_ENABLE_SPLIT_HEADERS

		
protected:									

    /**
	 * Various flags - used internally by the alarm object
	 */
	TBitFlags8 iFlags;

	/**
	 * This represents the desired behaviour for a given alarm.
	 * The Alarm Server uses this information to control the
	 * behaviour of the alarm.
	 *
	 * @see TAlarmCharacteristics
	 */
	TAlarmCharacteristicsFlags iCharacteristics;

	/**
	 * The unique identifier assoicated with each alarm maintained
	 * by the alarm world server.
	 */
	TAlarmId iAlarmId;
	
	/**
	 * The status of this alarm (e.g. enabled, disabled)
	 */
	TAlarmStatus iStatus;

	/**
	 * The state of this alarm (e.g. queued, notifying, notified, snoozed etc)
	 */
	TAlarmState	iState;

	/**
	 * The type of this alarm (e.g. day, timed)
	 */
	TAlarmDayOrTimed iDayOrTimed;

	/**
	 * Controls how the alarm repeats after it has expired. Note that
	 * session alarms are not allowed to repeat (they must be "once
	 * only").
	 */
	TAlarmRepeatDefinition iRepeatDefinition;

	/**
	 * This UID is supplied by the client and is used to indicate
	 * the category that this alarm is part of. The Alarm Server
	 * is category-agnostic, that is, this information is for
	 * the client's use only
	 */
	TAlarmCategory iCategory;

	/**
	 * The date and time at which this alarm is next due. For alarms
	 * that haven't been snoozed, then this is the original due time.
	 *
	 * For alarms that have been snoozed, this is the time at which
	 * the alarm will reawaken.
	 */
	TTime iNextDueTime;

	/**
	 * This attribute is only used in the instance whereby an alarm
	 * is snoozed. It represents the time at which the alarm first 
	 * expired.
	 */
	TTime iOriginalExpiryTime;

	/**
	 * The message associated with this alarm, typically used
	 * in an application UI to inform the user as to the reason
	 * for the alarm.
	 */
	TAlarmMessage iMessage;

	/**
	 * A descriptor which holds the name of the sound file which
	 * should be played when the alarm expires.
	 */
	TAlarmSoundName iSoundName;

protected:									
    
    // Client Specific Data
    
	/**
	 * Flags for use by any particular client. These will
	 * only be relevant to a client who can interpret them.
	 */
	TBitFlags16 iClientFlags;

	/**
	 * For arbitrary client data 1
	 */
	TInt iClientData1;

	/**
	 * For arbitrary client data 2
	 */
	TInt iClientData2;

private:									
    // Binary Compatibility Proofing 
	TSecureId iTASShdAlarmSID;

#ifdef SYMBIAN_SYSTEM_STATE_MANAGEMENT
	/**
	 * Various flags - used internally by the alarm object
	 */
	TBitFlags16 iFlags2;
	TUint16 iTASShdAlarm_2;
#else
	
#ifdef SYMBIAN_ALARM_REPEAT_EXTENSIONS
	/**
	 * Various flags - used internally by the alarm object
	 */
	TBitFlags16 iFlags2;
	TUint16 iTASShdAlarm_2;
#else
	TAny* iTASShdAlarm_2;
#endif
#endif
	TAny* iTASShdAlarm_3;
	};

#endif // #ifndef __ASSHDALARM_H__
