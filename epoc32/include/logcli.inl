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
// CLogEventType
// 
//

inline TUid CLogEventType::Uid() const
/** Gets the UID identifying the event type.

@return The UID. */
	{
	return iUid;
	}

inline void CLogEventType::SetUid(TUid aUid)
/** Sets the UID identifying the event type.

@param aUid The Uid. */
	{
	iUid = aUid;
	}

inline const TDesC& CLogEventType::Description() const
/** Gets the human readable and localised name of the event type.

@return A non-modifiable descriptor containing the name. */
	{
	return *iDescription;
	}

inline void CLogEventType::SetDescription(const TDesC& aDescription)
/** Sets the human readable and localised name of the event type.

For example, Email.

@param aDescription The name. */
	{
	iDescription->Des().Copy(aDescription);
	}

inline TBool CLogEventType::LoggingEnabled() const
/** Determines whether logging for this event type is enabled.

@return ETrue, if logging is enabled. EFalse, if logging is disabled. */
	{
	return iLoggingEnabled;
	}

inline void CLogEventType::SetLoggingEnabled(TBool aEnable)
/** Enables or disables logging for this event type.

Note that disabling the logging of an event type causes a CLogClient::AddEventL() 
request for an event of that type to complete with an appropriate error.

@param aEnable ETrue, to enable logging for this event type.EFalse, to disable 
logging for this event type.
@see CLogClient::AddEvent() */
	{
	iLoggingEnabled = aEnable;
	}

//**********************************
// CLogFilter
//**********************************

inline TUid CLogFilter::EventType() const
/** Gets the event type used by the filter.

@return The event type UID.
@see CLogEvent::EventType() */
	{
	return iEventType;
	}

inline void CLogFilter::SetEventType(TUid aType)
/** Sets the event type to be used by the filter.

@param aType The event type UID.
@see CLogEvent::SetEventType() */
	{
	iEventType = aType;
	}

inline const TDesC& CLogFilter::RemoteParty() const
/** Gets the remote party string used by the filter.

@return A non-modifiable descriptor containing the remote party string.
@see CLogEvent::RemoteParty() */
	{
	return *iRemoteParty;
	}

inline void CLogFilter::SetRemoteParty(const TDesC& aRemote)
/** Sets the remote party string to be used by the filter.

@param aRemote The remote party string.
@see CLogEvent::SetRemoteParty() */
	{
	iRemoteParty->Des().Copy(aRemote);
	}

inline const TDesC& CLogFilter::Direction() const
/** Gets the direction string used by the filter.

@return A non-modifiable descriptor containing the direction string.
@see CLogEvent::Direction() */
	{
	return *iDirection;
	}

inline void CLogFilter::SetDirection(const TDesC& aDirection)
/** Sets the direction string to be used by the filter.

@param aDirection The direction string.
@see CLogEvent::SetDirection() */
	{
	iDirection->Des().Copy(aDirection);
	}

inline TLogDurationType CLogFilter::DurationType() const
/** Gets the duration type used by the filter.

@return The duration type.
@see CLogEvent::DurationType() */
	{
	return iDurationType;
	}

inline void CLogFilter::SetDurationType(TLogDurationType aType)
/** Sets the duration type to be used by the filter.

@param aType The duration type.
@see CLogEvent::SetDurationType() */
	{
	iDurationType = aType;
	}

inline const TDesC& CLogFilter::Status() const
/** Gets the delivery status used by the filter.

@return A non-modifiable descriptor containing the delivery status.
@see CLogEvent::Status() */
	{
	return *iStatus;
	}

inline void CLogFilter::SetStatus(const TDesC& aStatus)
/** Sets the delivery status to be used by the filter.

@param aStatus The delivery status.
@see CLogEvent::SetStatus() */
	{
	iStatus->Des().Copy(aStatus);
	}

inline TLogContactItemId  CLogFilter::Contact() const
/** Gets the contact ID used by the filter.

@return The contact ID.
@see CLogEvent::Contact() */
	{
	return iContact;
	}

inline void CLogFilter::SetContact(TLogContactItemId  aContact)
/** Sets the contact ID to be used by the filter.

@param aContact The contact ID.
@see CLogEvent::SetContact() */
	{
	iContact = aContact;
	}

inline const TDesC& CLogFilter::Number() const
/** Gets the phone number used by the filter.

@return A non-modifiable descriptor containing the phone number.
@see CLogEvent::Number() */
	{
	return *iNumber;
	}

inline void CLogFilter::SetNumber(const TDesC& aNumber)
/** Sets the phone number to be used by the filter.

@param aNumber The phone number.
@see CLogEvent::SetNumber() */
	{
	iNumber->Des().Copy(aNumber);
	}

inline TUint32 CLogFilter::NullFields() const
/** Identifies the fields defined as NULL in the filter. These are the fields that 
the filter expects to be NULL in the database. A NULL field is one that has 
no value.

@return Bit values defining the null fields.
@see SetNullFields() */
	{
	return iNullFields;
	}

inline void CLogFilter::SetNullFields(TUint32 aFields)
/** Defines NULL fields to the filter. These are the fields that the filter expects 
to be NULL in the database. A NULL field is one that has no value.

Each field is identified by a bit value. The bit values may be ORd together 
in any combination.
 
Note that setting a flag and explicitly setting a value for the corresponding 
field generates an OR condition in the SQL WHERE clause.

@param aFields Bit values defining the null fields. These are one or more 
of the following values defined in logwrap.hrh: ELogContactField, ELogDirectionField, 
ELogDurationTypeField, ELogEventTypeField, ELogNumberField, ELogRemotePartyField, 
ELogStatusField, ELogFlagsField, ELogSubjectField, ELogLinkField and ELogDataField. */
	{
	iNullFields = aFields;
	}

inline const TTime& CLogFilter::StartTime() const
/** Gets the UTC start time used by the filter.

@since 7.0s
@return The UTC start time. */
	{
	return iStartTime;
	}

inline void CLogFilter::SetStartTime(const TTime& aStartTime)
/** Sets the specified UTC start time to be used by the filter.

@since 7.0s
@param aStartTime The UTC start time to be set. */
	{
	iStartTime = aStartTime; 
	}
	
inline const TTime& CLogFilter::EndTime() const
/** Gets the UTC end time used by the filter.

@since 7.0s
@return The UTC end time. */
	{
	return iEndTime;
	}

inline void CLogFilter::SetEndTime(const TTime& aEndTime)
/** Sets the specified UTC end time to be used by the filter.

@since 7.0s
@param aEndTime The UTC end time to be set. */
	{
	iEndTime = aEndTime;
	}

inline TLogFlags CLogFilter::Flags() const
/** Gets the flags used by the filter.

@return The flags. */
	{
	return iFlags;
	}

inline void CLogFilter::SetFlags(TLogFlags aFlags)
/** Sets the specified flags to be used by the filter.

@param aFlags The flags to be set. */
	{
	__ASSERT_DEBUG(aFlags <= KLogFlagsMask, User::Invariant());
	iFlags = (TLogFlags)(iFlags | aFlags);
	}

inline void CLogFilter::ClearFlags(TLogFlags aFlags)
/** Clears the specified flags to be used by the filter. 

The constant KLogFlagsMask can be used to clear all the flags.

@param aFlags The flags to be cleared */
	{
	__ASSERT_DEBUG(aFlags <= KLogFlagsMask, User::Invariant());
	iFlags = (TLogFlags)(iFlags & ~aFlags);
	}
