// Copyright (c) 2005-2009 Nokia Corporation and/or its subsidiary(-ies).
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

#ifndef __CALCOMMON_H__
#define __CALCOMMON_H__

#include <caltime.h>

/** This system-wide #define is for version 2 of the Calendar component. 
V1 is the CalInterimAPI. V2 is the refactored Calendar component which includes 
support for Attachments, GEO, TRANSP, instance iterator, extended text searching.
@publishedAll
@released
*/
#define SYMBIAN_CALENDAR_V2

/** Calendar local entry ID. 
This entry ID is assigned by the calendar server when an entry is created. 
It will remain unchanged for the lifetime of that entry.
@publishedAll
@released
*/
typedef TUint32 TCalLocalUid;

/** Calendar file ID.
@publishedAll
@released
*/
typedef TInt64 TCalFileId;

/** Utility class containing common calendar-related enums.

@publishedAll
@released
*/
class CalCommon
	{
public:

	/** Entry filter used in the entry view and instance view, filter flags are defined by TCalViewFilterFlags
	@publishedAll
	@released
	*/
	typedef TUint TCalViewFilter;
	
	/** Entry filter flags used in the entry view and instance view. 
	@publishedAll
	@released
	*/
	enum TCalViewFilterFlags	
		{
		/** Include appointments. */
		EIncludeAppts=0x01,				
		/** Include reminders. */	
		EIncludeReminder=0x02,				
		/** Include all-day events. */
		EIncludeEvents=0x04,				
		/** Include anniversaries. */
		EIncludeAnnivs=0x08,				
		/** Include completed todos. */
		EIncludeCompletedTodos=0x10,					
		/** Include incompleted todos. */
		EIncludeIncompletedTodos=0x20,	
		/** Remove non-alarmed entries. This flag cannot be used by itself. */
		EIncludeAlarmedOnly=0x40,
		/** Include next only instance of a repeat entry. */
		EIncludeRptsNextInstanceOnly=0x80,
		
		/** By default all instances which overlap the time range are found. Use the EInstanceStartTimeWithinRange
		flag to only include instances whose start time is inside the search time range. 
		
		Note that setting both the EInstanceStartTimeWithinRange and EInstanceEndTimeWithinRange flags will 
		only include instances which are completely within the search time range. */
		EInstanceStartTimeWithinRange=0x100,

		/** By default all instances which overlap the time range are found. Use the EInstanceEndTimeWithinRange
		flag to only include instances whose end time is inside the search time range. 
		
		Note that setting both the EInstanceStartTimeWithinRange and EInstanceEndTimeWithinRange flags will 
		only include instances which are completely within the search time range.
		*/
		EInstanceEndTimeWithinRange=0x200,
		
		/** By default all instances which adjoin the search range are found. Use the EExcludeInstanceAdjoiningRange
		flag to exclude instances that are outside, but adjoin the search range.
		
		Instances that are outside, but adjoin the search start or end time are excluded.
		Instances that both start and end on the search start time are included.
		Instances that both start and end on the search end time are excluded.
		*/
		EExcludeInstanceAdjoiningRange=0x400,
		
		/** Include all entries (appointments, day events, reminders, anniversaries and todos). */
		EIncludeAll=EIncludeAppts|EIncludeReminder|EIncludeEvents|EIncludeAnnivs|
		EIncludeCompletedTodos|EIncludeIncompletedTodos,
		};
		
	/** The range of instances referred to in a recurrence ID or instance view. 
	@publishedAll
	@released
	*/
	enum TRecurrenceRange
		{
		/** Only this instance is referenced. 
		If the user set EThisOnly when a repeating child entry is created and stored to the file, only the parent instance
		referred to by the child's recurrence ID will be replaced. */
		EThisOnly,
		/** This and all other instances are referenced. */
		EThisAndAll,
		/** This and all future instances are referenced. */
		EThisAndFuture,
		/** This and all previous instances are referenced. */
		EThisAndPrior
		};
		
	
	/** Search filter for use in the CCalInstanceView::FindInstanceL() function.
	Note that a folded text search is used if exact text search is not specified.
	The summary text field is always searched. It is possible to specify additional text fields to be 
	searched as well.
	@publishedAll
	@released
	*/
	enum TCalSearchBehaviour
		{
		/** Search for folded text. */
		EFoldedTextSearch=0x0,

		/** Search for the exact text. */
		EExactTextSearch=0x1,
		
		/** Search location during a text search. 
		@publishedPartner
		@released
		*/
		ESearchEntryLocation=0x2,
		
		/** Search description during a text search. 
		@publishedPartner
		@released
		*/
		ESearchEntryDescription=0x4,
		
		/** Search attendee addresses during a text search.
		@publishedPartner
		@released
		*/
		ESearchAttendeeAddress=0x8,
		
		/** Search attendee sent by addresses during a text search.
		@publishedPartner
		@released
		*/
		ESearchAttendeeSentByAddress=0x10,
		
		/** Search attendee common names during a text search. 
		@publishedPartner
		@released
		*/
		ESearchAttendeeCommonName=0x20,
		
		/** Search organizer's address during a text search. 
		@publishedPartner
		@released
		*/
		ESearchOrganizerAddress=0x40,
		
		/** Search organizer's sent by address during a text search. 
		@publishedPartner
		@released
		*/
		ESearchOrganizerSentByAddress=0x80,
		
		/** Search organizer's common name during a text search. 
		@publishedPartner
		@released
		*/
		ESearchOrganizerCommonName=0x100,
		
		/** Include all possible text fields during a text search. */
		ESearchAllTextFields=ESearchEntryLocation|ESearchEntryDescription|
			ESearchAttendeeAddress|ESearchAttendeeSentByAddress|ESearchAttendeeCommonName|
			ESearchOrganizerAddress|ESearchOrganizerSentByAddress|ESearchOrganizerCommonName,
		};
		
	/** Class to implement a time range in the Instance view and Entry view.
	@publishedAll
	@released
	*/	
	class TCalTimeRange
		{
	public:
		IMPORT_C TCalTimeRange(TCalTime aStartTime, TCalTime aEndTime);		
			
		IMPORT_C TCalTime StartTime() const;
		IMPORT_C TCalTime EndTime() const;
		
	private:
		TCalTime iStartTime;
		TCalTime iEndTime;
		};
		
	/** Enumeration returned when opening a file to indicate whether the file is the current version, 
	needs converting, or is unsupported.
	@publishedPartner
	@released
	*/
	enum TCalFileVersionSupport
		{
		/** The file is the current version and can be loaded immediately. */
		EFileIsCurrentVersion,
		/** The file is an older version and will be converted when it is used. */
		EFileNeedsConverting,
		/** The file is an old version that is not supported. */
		EUnsupportedFileVersion
		};
	};
#endif // __CALCOMMON_H__
