// Copyright (c) 2004-2009 Nokia Corporation and/or its subsidiary(-ies).
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
// Various T-classes for client input to scheduler, scheduler output to client	
// These classes comprise part of the interface (the rest is defined in RScheduler)
// 
//

#if !defined (__SCHINFO_H__)
#define __SCHINFO_H__

#if !defined (__SCHTIME_H__)
#include <schtime.h>
#endif

#if !defined(__E32BASE_H__)
#include <e32base.h>
#endif

#include <s32strm.h>



/** 
Contains detailed information for a single task.

A schedule can have any number of tasks. An object of this type is passed 
to RScheduler::ScheduleTask(). Objects of this type are also returned by functions 
within RScheduler that retrieve information about tasks.

@see RScheduler::ScheduleTask()
@see RScheduler::GetScheduleL()
@see RScheduler::GetTaskInfoL() 
@publishedAll
@released
*/
class TTaskInfo
	{
public:
	//ctors
	IMPORT_C TTaskInfo (TInt aTaskId, TName& aName, TInt aPriority, TInt aRepeat);
	IMPORT_C TTaskInfo();//
	//assignment
	IMPORT_C TTaskInfo& operator=(const TTaskInfo& aTaskInfo);
	IMPORT_C void ExternalizeL(RWriteStream& aStream) const;
	IMPORT_C void InternalizeL(RReadStream& aStream);
	//needs a copy ctor
	//TTaskInfo (TTaskInfo& aTaskInfo);
	
	//data
	/** Specifies how often the task is to be repeated.
	
	This is defined by the client.
	
	A value of 1 means once, a value of 2 means twice etc.
	
	Note that zero is interpreted to mean once, and a negative value is interpreted 
	to mean that the task will be repeated until it is explicitly deleted. */
	TInt iRepeat;
	
	/** The unique Id for the task.
	
	This is generated by the Task Scheduler. Clients should use the generated 
	Id to refer to the task in future transactions. */
	TInt iTaskId;
	
	/** The name of the task.
	
	This is defined by the client.
	
	@see TName */
	TName iName;
	
	/** The priority of the task.
	
	This is defined by the client.
	
	Determines the order in which a client's tasks are executed. Where a client 
	has two tasks with different priorities, the task with the higher priority 
	will be executed first. */
	TInt iPriority;
	};

/** 
Defines a filter to be used when listing tasks scheduled in a call to RScheduler::GetTaskRefsL().

@see RScheduler::GetTaskRefsL()
@publishedAll
@released
*/
enum TTaskFilter
	{
	/** Indicates that all tasks are to be selected. */
	EAllTasks,
	/** Indicates those tasks associated with the executing program with which the 
	calling client is associated, are to be selected. */
	EMyTasks
	};


/** 
Defines a filter to be used when listing schedules in a call to RScheduler::GetScheduleRefsL(), 
and when listing tasks in a call to RScheduler::GetTaskRefsL().

@see RScheduler::GetScheduleRefsL()
@see RScheduler::GetTaskRefsL() 
@publishedAll
@released
*/
enum TScheduleFilter
	{
	/** Indicates that all schedules are to be selected. */
	EAllSchedules,
	/** Indicates that only pending schedules are to be selected.
	
	Note that pending schedules are those that are enabled and have tasks associated 
	with them. */
	EPendingSchedules
	};

/** 
Defines the type of interval used by a schedule entry.

@see TScheduleEntryInfo
@publishedAll
@released
*/
enum TIntervalType
	{
	/** The interval is based on hours. */
	EHourly,
	/** The interval is based on days. */
	EDaily,
	/** The interval is based on months. */
	EMonthly,
	/** The interval is based on years. */
	EYearly
	};


/**
Defines the types of schedules supported by the task scheduler API
@internalAll
*/
// Not for Client use , only to be used internally 
enum TScheduleType
	{
	/** Indicates a time based schedule. */
	ETimeSchedule,
	/** Indicates a conditon based schedule. */
	EConditionSchedule
	};

	
/** 
Defines, and uniquely identifies a schedule.

@see RScheduler::CreatePersistentSchedule()
@see RScheduler::ScheduleTask()
@see RScheduler::GetScheduleRefsL()
@see RScheduler::GetTaskRefsL()
@see RScheduler::GetTaskInfoL()
@publishedAll
@released
*/
class TSchedulerItemRef
	{
public:
	/** The unique Id for the schedule.
	
	This is generated by the Task Scheduler when the schedule is created. Clients 
	should use this Id to refer to the schedule in future transactions. */
	TInt iHandle;
	
	/** The name of the schedule.
	
	This is defined by the client. */
	TName iName;
	};

/** 
Contains detailed information for a single schedule entry.

A schedule can have any number of schedule entries. A client passes one or 
more of these objects, contained within an array, to the RScheduler functions 
that create or amend a schedule.

@see RScheduler::CreatePersistentSchedule()
@see RScheduler::EditSchedule()
@see RScheduler::ScheduleTask()
@see RScheduler::GetScheduleL() 
@publishedAll
@deprecated and replaced by TScheduleEntryInfo2
*/
class TScheduleEntryInfo
	{
public:
	void ExternalizeL(RWriteStream& aStream) const;
	void InternalizeL(RReadStream& aStream);

	/** Defines the type of time-frame relative to which execution of tasks is timed; 
	for example, EHourly implies relative to the current hour, EDaily implies 
	relative to the current day.
	
	@see TIntervalType */
	TIntervalType iIntervalType;
	
	/** The first time that the entry will cause execution of tasks. */
	TTime iStartTime;
	
	/** The interval between execution of tasks.
	
	The way that this value is interpreted depends on the value of iIntervalType. 
	For example, if the interval is 2 and iIntervalType has a value of EMonthly, 
	then the interval is 2 months.
	
	The interval must have a minimum value of 1.
	
	@see TIntervalType
	@see iIntervalType */
	TInt iInterval;
	
	/** The period for which the entry is valid.
	
	After the validity period has expired, tasks associated with the entry will 
	not be eligible for execution.
	
	@see TTimeIntervalMinutes */
	TTimeIntervalMinutes iValidityPeriod;
	};
	
	
	
/** 
Contains detailed information for a single schedule entry.

A schedule can have any number of schedule entries. A client passes one or 
more of these objects, contained within an array, to the RScheduler functions 
that create or amend a schedule.

@see RScheduler::CreatePersistentSchedule()
@see RScheduler::EditSchedule()
@see RScheduler::ScheduleTask()
@see RScheduler::GetScheduleL() 
@publishedAll
@released
*/
class TScheduleEntryInfo2
	{
public:
	//constructors
	IMPORT_C TScheduleEntryInfo2();
	IMPORT_C TScheduleEntryInfo2(const TScheduleEntryInfo2& aEntryInfo);
	IMPORT_C TScheduleEntryInfo2(const TTsTime& aStartTime, TIntervalType aIntervalType, TInt aInterval, TTimeIntervalMinutes aValidityPeriod);
	 
	//utility Get and Set methods
	IMPORT_C TIntervalType IntervalType() const;
	IMPORT_C void SetIntervalType(TIntervalType aIntervalType);

	IMPORT_C const TTsTime& StartTime() const;
	IMPORT_C void SetStartTime(const TTsTime& aStartTime);

	IMPORT_C TInt Interval() const;
	IMPORT_C void SetInterval(TInt aInterval);

	IMPORT_C TTimeIntervalMinutes ValidityPeriod() const;
	IMPORT_C void SetValidityPeriod(TTimeIntervalMinutes aValidityPeriod);

	//assignment operator	
	IMPORT_C TScheduleEntryInfo2& operator=(const TScheduleEntryInfo2& aEntryInfo);


public:
	// APIs for use within the Task Scheduler server
	TScheduleEntryInfo2(const TScheduleEntryInfo& aEntryInfo);
	void ProcessOffsetEvent();

	void ExternalizeL(RWriteStream& aStream) const;
	void InternalizeL(RReadStream& aStream);

private:
	/** The interval between execution of tasks.
	The way that this value is interpreted depends on the value of iIntervalType. 
	For example, if the interval is 2 and iIntervalType has a value of EMonthly, 
	then the interval is 2 months.
	The interval must have a minimum value of 1.
	 */
	TInt iInterval;
	
	/** Defines the type of interval between the execution of tasks. 
	May be EHourly, EDaily, EMonthly or EYearly.
	 */
	TIntervalType iIntervalType;
	
	/** The first time that the entry will cause execution of tasks. */
	TTsTime iStartTime;
	
	/** The period for which the entry is valid.
	After the validity period has expired, tasks associated with the entry will 
	not be eligible for execution.
	*/
	TTimeIntervalMinutes iValidityPeriod;

	/** For future use
	*/
	TAny* iReserved;	
	
	// Declare the test accessor as a friend
	friend class TScheduleEntryInfo2_StateAccessor;
	};


/** 
Defines the state of a schedule.

An object of this type is passed to, and populated by, a call to RScheduler::GetScheduleL().

@see RScheduler::GetScheduleL()
@publishedAll
@released
*/
class TScheduleState2
	{
public:

	//constructors
	IMPORT_C TScheduleState2();
	IMPORT_C TScheduleState2(const TScheduleState2& aScheduleState);
	IMPORT_C TScheduleState2(const TName& aName, const TTsTime& aDueTime, TBool aPersists, TBool aEnabled);
		
	//get, set methods
	IMPORT_C const TName& Name() const;
	IMPORT_C void SetName(const TName& aName);

	IMPORT_C const TTsTime& DueTime() const;
	IMPORT_C void SetDueTime(const TTsTime& aDueTime);

	IMPORT_C TBool Persists() const;
	IMPORT_C void SetPersists(TBool aPersists);

	IMPORT_C TBool Enabled() const;
	IMPORT_C void SetEnabled(TBool aEnabled);
	
	IMPORT_C TScheduleState2& operator=(const TScheduleState2& aScheduleState);

private:
	/** The name of the schedule. */
	TName iName;
	
	/** The time when the schedule is next due.
	This only has meaning if the schedule is pending, i.e. it is enabled and has 
	tasks associated with it. */
	TTsTime iDueTime;
	
	/** Flags used to indicate:
	1.  Whether the schedule is enabled or not. (bit 0)
	2.	Whether the schedule is persistent or not. (bit 1)
		If a schedule is persistent, its lifetime is not limited to the lifetime of 
		the tasks associated with it .
		If a schedule is transient, it is created together with a new scheduled task, 
		and is destroyed when the task is destroyed.
		
		Bits 2-31 reserved for future use
	*/
	TUint32 iFlags;
	
	/** For future use
	*/
	TAny* iReserved;
	
	// Declare the test accessor as a friend
	friend class TScheduleState2_StateAccessor;
	};

/** 
Defines the state of a schedule.

An object of this type is passed to, and populated by, a call to RScheduler::GetScheduleL().

@see RScheduler::GetScheduleL()
@publishedAll
@deprecated and replaced by TScheduleState2.
*/
class TScheduleState
	{
public:
	//constructor for use with the deprecated APIs
	TScheduleState(const TScheduleState2& aScheduleState2);
	TScheduleState()
		{		
		}
	
	/** The name of the schedule. */
	TName iName;
	
	/** The time when the schedule is next due.
	
	This only has meaning if the schedule is pending, i.e. it is enabled and has 
	tasks associated with it. */
	TTime iDueTime;
	
	/** Indicates whether the schedule is persistent or not.
	
	If a schedule is persistent, its lifetime is not limited to the lifetime of 
	the tasks associated with it .
	
	If a schedule is transient, it is created together with a new scheduled task, 
	and is destroyed when the task is destroyed. */
	TBool iPersists;
	
	/** Indicates whether the schedule is enabled or not. */
	TBool iEnabled;
	};

#ifndef SYMBIAN_ENABLE_SPLIT_HEADERS
#include <schinfointernal.h>

#endif

#endif
