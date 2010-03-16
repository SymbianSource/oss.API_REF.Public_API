// Copyright (c) 1999-2009 Nokia Corporation and/or its subsidiary(-ies).
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

#ifndef __ASSHDALARM_H__
#define __ASSHDALARM_H__


// System includes
#include <e32base.h>
#include <s32strm.h>

// User includes
#include <asshddefs.h>

///////////////////////////////////////////////////////////////////////////////////////
// ----> TASShdAlarm (header)
///////////////////////////////////////////////////////////////////////////////////////

/** The Alarm publish and subscribe category
@publishedPartner
@released
*/
const TUid KAlarmServerPubSubCategory = { 0x101f5027 };

/** Used for subcribing missed alarms or time zone changes
@publishedPartner
@released
*/
const TUint KMissingAlarmPubSubKey = 100;

/** The publish and subscribe data for KMissingAlarmPubSubKey
@publishedPartner
@released
*/
struct TMissedAlarmPubSubData
	{
	/** The value indicating the changes. 
	1 - Time zone has been changes but there are no missed alarms
	2 - Some alarms have been missed after system time or time zone has changed.
	*/
	TUint8 iValue;
	
	/** The time that system time change took place, in universal (UTC) time */
	TTime iTimeOfChangeUtc;
	};

/** Used for subscribing to data used when searching for instances in Calendar
@publishedPartner
@released
*/
const TUint KSkippedAlarmInstancesPubSubKey = 101;

/** The publish and subscribe data for KMissingAlarmInstancesPubSubKey
@publishedPartner
@released
*/
struct TASShdAlarmedInstanceParams
	{
	/** The start of the time range in local time. */ 
	TTime iLocalStartTime;

	/** The end of the time range in local time. */
	TTime iLocalEndTime;
	
	/** The alarm time types to include. */
	TASShdAlarmTimeType iTimeType;
	};


class TASShdAlarm
/** A client-side alarm object. 

It contains all of the information needed to create an alarm in 
the Alarm Server. 
@publishedAll
@released
*/
	{
///////////////////////////////////////////////////////////////////////////////////////
public:										// CONSTRUCT
///////////////////////////////////////////////////////////////////////////////////////

	IMPORT_C TASShdAlarm();

///////////////////////////////////////////////////////////////////////////////////////
public:										// INTERNALIZE / EXTERNALIZE
///////////////////////////////////////////////////////////////////////////////////////

	IMPORT_C void InternalizeL(RReadStream& aStream);

	IMPORT_C void ExternalizeL(RWriteStream& aStream) const;

///////////////////////////////////////////////////////////////////////////////////////
public:										// READ-ONLY ACCESS
///////////////////////////////////////////////////////////////////////////////////////

	inline TAlarmStatus	Status() const				
	/** Returns the alarm status. 
	
	@return Alarm status. */
		{ return iStatus; }

	inline TAlarmState State() const
	/** Returns the alarm state. 
	
	@return Alarm state. */
		{ return iState; }

	inline TBool HasAssociatedData() const;

	inline TBool HasOwningSession() const;

	inline TBool HasBecomeOrphaned() const;
	
///////////////////////////////////////////////////////////////////////////////////////
public:										// READ-ONLY & MODIFIABLE
///////////////////////////////////////////////////////////////////////////////////////

	IMPORT_C void Reset();

	inline TAlarmId& Id()
	/** Returns a writable version of the alarm's unique identifier. 
	
	@return Reference to the unique identifier. */
		{ return iAlarmId; }

	inline TAlarmId	Id() const
	/** Return the alarm's unique identifier. 
	
	@return The unique identifier. */
		{ return iAlarmId; }
		
//The Secure ID is only used in the secured platform
		
	// adds a SID to the alarms private field
	inline void SetSid(const TSecureId& aSecureID) 
		{iTASShdAlarmSID = aSecureID;}

	//	returns the SID of the alarm's creator
	inline TSecureId GetSid() const 
		{return iTASShdAlarmSID;}

	inline TTime& NextDueTime()
	/** Returns a writable version of the next time the alarm is scheduled to expire. 
	
	@return Next expiry time. */
		{ return iNextDueTime; }

	inline const TTime&	NextDueTime() const
	/** Returns the next time that the alarm is scheduled to expire. 
	
	@return Next expiry time. */
		{ return iNextDueTime; }

	inline TTime& OriginalExpiryTime()
	/** Returns a writable version of the alarm's original expiry time. 
	
	@return Original expiry time. */
		{ return iOriginalExpiryTime; }

	inline const TTime& OriginalExpiryTime() const
	/** Returns the alarm's original expiry time. 
	
	The original expiry time is the same as the next due time, unless the alarm 
	has been snoozed. In that case, the original expiry time is the time when 
	the alarm first expired, and the next due time is when it is to re-awaken 
	after the snooze. 
	
	@return Original expiry time. */
		{ return iOriginalExpiryTime; }

	inline TAlarmCategory& Category()
	/** Returns a writable version of the alarm's category. 
	
	Clients can use the category to tag each alarm with a specific code. This 
	allows clients to identify all related alarms, such as all alarms associated 
	with a particular application or application engine. 
	
	@return Alarm category. */
		{ return iCategory; }

	inline TAlarmCategory Category() const 
	/** Return this alarm's category. 
	
	@return Alarm category. */
		{ return iCategory; }

	inline TAlarmCharacteristicsFlags& Characteristics() 
	/** Returns a writable version of the alarm's characteristics. 
	
	@return Alarm characteristics bit flags. */
		{ return iCharacteristics; }

	inline TAlarmCharacteristicsFlags Characteristics() const 
	/** Returns the alarm's characteristics 
	
	@return Alarm characteristics bit flags. */
		{ return iCharacteristics; }

	inline TAlarmRepeatDefinition& RepeatDefinition() 
	/** Returns a writable version of the alarm's repeat definition. 
	
	The repeat definition controls the alarm's behaviour after it has expired. 
	For example, you can set the repeat definition so that the server automatically 
	queues the alarm to expire again in exactly 24 hours time.
	
	@return Alarm repeat definition. */
		{ return iRepeatDefinition; }

	inline TAlarmRepeatDefinition RepeatDefinition() const 
	/** Returns the repeat definition for the alarm. 
	
	@return The alarm's repeat definition. */
		{ return iRepeatDefinition; }

	inline TAlarmMessage& Message()	
	/** Returns a writable version of the alarm's message. 
	
	The message is usually displayed in the application UI 
	when the alarm expires.
	
	@return Reference to the alarm's associated message. */
		{ return iMessage; }

	inline const TAlarmMessage& Message() const 
	/** Returns the alarm's message. 
	
	The message is usually displayed in the application UI when the alarm expires. 
	
	@return Reference to the alarm's associated message. */
		{ return iMessage; }

	inline TAlarmSoundName& SoundName() 
	/** Return a writable version of the alarm sound's filename. 
	
	@return Reference to the alarm's sound filename. */
		{ return iSoundName; }

	inline const TAlarmSoundName& SoundName() const	
	/** Returns the alarm's sound filename. 
	
	@return Sound filename. */
		{ return iSoundName; }
		
	inline TAlarmDayOrTimed DayOrTimed() const
	/** Returns the alarm session type. 
	
	@return Alarm session type. */
		{ return iDayOrTimed; }

		
	inline TAlarmDayOrTimed&	DayOrTimed()	
	/** Returns a writable version of the alarm type, i.e. day, timed
	
	@return iDayOrTimed. */	
	{ return iDayOrTimed; }

   
	IMPORT_C void SetUtcNextDueTime(TTime aUtcTime);
	
	IMPORT_C void SetDeQueueIfDueTimeInPast();
	
	IMPORT_C TInt SetAlarmDays(TUint8 aAlarmDays);
	IMPORT_C TUint8 AlarmDays() const;
	IMPORT_C void SetContinuous(TBool aContinuous);
	IMPORT_C TBool Continuous();
	
///////////////////////////////////////////////////////////////////////////////////////
public:										// CLIENT DATA ACCESS
///////////////////////////////////////////////////////////////////////////////////////

	inline TBitFlags16& ClientFlags()
	/** Returns a writable version of the alarm's client flags. 
	
	The client flags may be used for any client-specific data - 
	the alarm server does not use them.

	@return Reference to the alarm's bit flags. */
		{ return iClientFlags; }

	inline TBitFlags16 ClientFlags() const 
	/** Returns this alarm's client flags. 
	
	@return Reference to the alarm's bit flags. */
		{ return iClientFlags; }

	inline TInt	ClientData1() const 
	/** Returns the client data from slot 1 for this alarm. 
	
	@return The first client-specific integer. */
		{ return iClientData1; }

	inline TInt& ClientData1() 
	/** Returns a writable version of the client data from slot 1 for this alarm. 
	
	@return Reference to the first client-specific integer. */
		{ return iClientData1; }

	inline TInt ClientData2() const
	/** Returns the client data from slot 2 for this alarm. 
	
	@return The second client-specific integer. */
		{ return iClientData2; }

	inline TInt& ClientData2() 
	/** Returns the client data from slot 2 for this alarm. 
	
	@return The second client-specific integer. */
		{ return iClientData2; }
		
	inline TBool IsFloating() const
	/** Tests whether the alarm is floating. 

	Floating alarms expire at a given wall-clock time regardless of the current locale and
	whether any daylight saving time rules are in force.
		
	@return True if the alarm is floating.
	*/
	{ return iCharacteristics.IsClear(EAlarmCharacteristicsIsFixed); }
	




///////////////////////////////////////////////////////////////////////////////////////
protected:									// INTERNAL FLAGS
///////////////////////////////////////////////////////////////////////////////////////

	/*
	 * @internalAll
	 */
	enum TASShdAlarmFlags
		{

		/*
		 * @internalAll
		 */
		EASShdAlarmFlagsHasAssociatedData	= 0,

		/*
		 * @internalAll
		 */
		EASShdAlarmFlagsHasOwningSession	= 1,

		/*
		 * @internalAll
		 */
		EASShdAlarmFlagsHasBecomeOrphaned	= 2,
		
		/*
		 * @internalAll Set if alarm is disabled manually so that can not be enabled when
		 * locale changes.
		 */
		EASShdAlarmFlagsPermanentDisabled	= 4

		};

private:
	/*
	 * @internalComponent
	 */
	enum TASShdAlarmFlags2
		{
		EASShdAlarmFlag2Wakeup				= 0,
		};

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

		
///////////////////////////////////////////////////////////////////////////////////////
protected:									// MEMBER DATA
///////////////////////////////////////////////////////////////////////////////////////

	/*
	 * Various flags - used internally by the alarm object
	 */
	TBitFlags8 iFlags;

	/*
	 * This represents the desired behaviour for a given alarm.
	 * The Alarm Server uses this information to control the
	 * behaviour of the alarm.
	 *
	 * @see TAlarmCharacteristics
	 */
	TAlarmCharacteristicsFlags iCharacteristics;

	/*
	 * The unique identifier assoicated with each alarm maintained
	 * by the alarm world server.
	 */
	TAlarmId iAlarmId;
	
	/*
	 * The status of this alarm (e.g. enabled, disabled)
	 */
	TAlarmStatus iStatus;

	/*
	 * The state of this alarm (e.g. queued, notifying, notified, snoozed etc)
	 */
	TAlarmState	iState;

	/*
	 * The type of this alarm (e.g. day, timed)
	 */
	TAlarmDayOrTimed iDayOrTimed;

	/*
	 * Controls how the alarm repeats after it has expired. Note that
	 * session alarms are not allowed to repeat (they must be "once
	 * only").
	 */
	TAlarmRepeatDefinition iRepeatDefinition;

	/*
	 * This UID is supplied by the client and is used to indicate
	 * the category that this alarm is part of. The Alarm Server
	 * is category-agnostic, that is, this information is for
	 * the client's use only
	 */
	TAlarmCategory iCategory;

	/*
	 * The date and time at which this alarm is next due. For alarms
	 * that haven't been snoozed, then this is the original due time.
	 *
	 * For alarms that have been snoozed, this is the time at which
	 * the alarm will reawaken.
	 */
	TTime iNextDueTime;

	/*
	 * This attribute is only used in the instance whereby an alarm
	 * is snoozed. It represents the time at which the alarm first 
	 * expired.
	 */
	TTime iOriginalExpiryTime;

	/*
	 * The message associated with this alarm, typically used
	 * in an application UI to inform the user as to the reason
	 * for the alarm.
	 */
	TAlarmMessage iMessage;

	/*
	 * A descriptor which holds the name of the sound file which
	 * should be played when the alarm expires.
	 */
	TAlarmSoundName iSoundName;

///////////////////////////////////////////////////////////////////////////////////////
protected:									// CLIENT SPECIFIC DATA
///////////////////////////////////////////////////////////////////////////////////////

	/*
	 * Flags for use by any particular client. These will
	 * only be relevant to a client who can interpret them.
	 */
	TBitFlags16 iClientFlags;

	/*
	 * For arbitrary client data 1
	 */
	TInt iClientData1;

	/*
	 * For arbitrary client data 2
	 */
	TInt iClientData2;

///////////////////////////////////////////////////////////////////////////////////////
private:									// BC PROOFING
///////////////////////////////////////////////////////////////////////////////////////
	TSecureId iTASShdAlarmSID;
	/*
	 * Various flags - used internally by the alarm object
	 */
	TBitFlags16 iFlags2;
	TUint16 iTASShdAlarm_2;
	TAny* iTASShdAlarm_3;
	};


///////////////////////////////////////////////////////////////////////////////////////
// ----> TASShdAlarm (inline)
///////////////////////////////////////////////////////////////////////////////////////


/** Tests whether the alarm has any associated data. 
	
@return True if the alarm has associated data. */
inline TBool TASShdAlarm::HasAssociatedData() const

	{
	return iFlags.IsSet(EASShdAlarmFlagsHasAssociatedData);
	}


/** Tests whether the alarm has an active owning session.

@return True if the alarm has an active owning session. */
inline TBool TASShdAlarm::HasOwningSession() const

	{
	return iFlags.IsSet(EASShdAlarmFlagsHasOwningSession);
	}

inline TBool TASShdAlarm::HasBecomeOrphaned() const
/** Tests whether the alarm is orphaned. 

An alarm is ophaned if it used to have an owning session, but no longer does. 
If an alarm is owned by a session, it is removed from the queue when the session 
disconnects. However, orphaned alarms stay in the queue.
	
@return True if the alarm has becomed orphaned. */
	{
	return iFlags.IsSet(EASShdAlarmFlagsHasBecomeOrphaned);
	}



#endif // #ifndef __ASSHDALARM_H__
