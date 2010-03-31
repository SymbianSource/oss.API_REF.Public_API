// Copyright (c) 1997-2009 Nokia Corporation and/or its subsidiary(-ies).
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

#ifndef __TIMEZONE_H__
#define __TIMEZONE_H__


#include <e32base.h>
#include <s32std.h>
#include <s32strm.h>
#include <tzdefines.h>
#include <tzid.h>
#include <tzupdate.h>
#ifndef SYMBIAN_ENABLE_SPLIT_HEADERS
#include <tzlocalizedcityrecord.h> //This should be be included as it is internalTechnology.
#include <tzlocalizedtimezonerecord.h> // Same as above and probably should not be exported to the epoc include
#endif


// Forward class references.
class CTzRules;
class CTzRuleHolder;
class CTzLocalizedCityRecord;
#ifdef SYMBIAN_ENABLE_SPLIT_HEADERS // This can be forward declared i.e. it should not be included as it is internal.
class CTzLocalizedTimeZoneRecord;
#endif

#ifndef SYMBIAN_ENABLE_SPLIT_HEADERS
/**
The CTzUserNames class is used to encapsulate the names for a user-defined
time zone.

When creating an instance of this class the client can specify the following
names:

- Long standard time name, for example "Mountain Standard Time"
- Short standard time name, for example "MST"
- Long daylight saving time name, for example "Mountain Daylight Time"
- Short daylight saving time name, for example "MDT"
- City name, for example "Shiprock"
- Region name, for example "America"

The client can also read these names.  

@publishedPartner
@released
*/ 
class CTzUserNames : public CBase
    {
public:
    IMPORT_C static CTzUserNames* NewL(const TDesC& aStandardName,
    	const TDesC& aShortStandardName, const TDesC& aDaylightSaveName,
    	const TDesC& aShortDaylightSaveName, const TDesC& aCityName,
    	const TDesC& aRegionName);
    IMPORT_C static CTzUserNames* NewLC(const TDesC& aStandardName,
    	const TDesC& aShortStandardName, const TDesC& aDayLightSaveName,
    	const TDesC& aShortDaylightSaveName, const TDesC& aCityName,
    	const TDesC& aRegionName);
	IMPORT_C ~CTzUserNames();
	
	IMPORT_C const TDesC& StandardName() const;
	IMPORT_C const TDesC& ShortStandardName() const;
	IMPORT_C const TDesC& DaylightSaveName() const;
	IMPORT_C const TDesC& ShortDaylightSaveName() const;
	IMPORT_C const TDesC& CityName() const;
	IMPORT_C const TDesC& RegionName() const;
	
	IMPORT_C static CTzUserNames* NewL(RReadStream& aStream);
	IMPORT_C void ExternalizeL(RWriteStream& aStream) const;
	IMPORT_C void InternalizeL(RReadStream& aStream);
	IMPORT_C TInt SizeOfObject() const;

private:
    CTzUserNames();
	void ConstructL(const TDesC& aStandardName, const TDesC& aShortStandardName,
		const TDesC& aDayLightSaveName, const TDesC& aShortDayLightSaveName,
		const TDesC& aCityName, const TDesC& aRegionName);
	
private:
    HBufC* iStandardName;
    HBufC* iShortStandardName;
    HBufC* iDaylightName;
    HBufC* iShortDaylightName;	
    HBufC* iCityName;
    HBufC* iRegionName;
    };
#else
class CTzUserNames;
#endif //SYMBIAN_ENABLE_SPLIT_HEADERS
/** 
The client interface to the time zone server. 

This class performs two basic functions:

1. Converts between UTC time and local time.
2. Sets the current local time zone.

NOTE: The presence of a time zone server will alter the behaviour of the 
time zone related function calls User::SetUTCOffset() and 
User::SetUTCTimeAndOffset().  The time zone server is shutdown when the last
session (RTz) is closed.  Therefore, to maintain consistent time related
behaviour, licensees may want to keep a system level time zone server session
open at all times.

Exceptional cases occur when a user requests conversion for a non-existent local
time or a double local time. 

Non-existent local times occur when the local time changes from winter to summer
for DST.

For example, 01:59 local time is non-existent on the day of a change to BST in
Europe/London since the time changes directly from 12:59:59 to 2:00.

A double local time occurs when the local time changes from summer to winter. 

For example, if the time changes at 02:00 AM BST to 01:00 AM GMT then local
times between 01:00 and 01:59 occur twice.

The conversion applies the DST offset if the local time value is double and
applies the standard UTC offset if the local time does not exists.

This decision makes the conversion process asymmetrical around the discontinuity
in the local time when there is a DST change.

An example conversion from a double local time to UTC and from UTC to a double
local time is:

	01:59 AM BST => 00:59 AM UTC
	01:59 AM UTC => 01:59 AM GMT
	
An example conversion from a non-existent local time to UTC 
and from UTC to local time is:

    01:59 AM GMT => 01:59 AM UTC
    01:59 AM UTC => 02:59 AM BST 	
	
@publishedAll
@released
@since 9.1
*/
class RTz : public RSessionBase
	{
public:
	/**
	Automatic DST update mode.
	*/
	enum TTzAutoDSTUpdateModes
		{
		/** No auto update notification when a DST event occurs. */
		ETZAutoDSTUpdateOff = 0,

		/** Automatic time update will occur and the client app will be
			notified. */
		ETZAutoDSTUpdateOn,

		/** Client app needs to confirm that the time should be updated whenever
			a DST event occurs. */
		ETZAutoDSTNotificationOnly,
		};

	/**
	Time zone server change events.
	*/
	enum TTzChanges
		{
		/** Used for notifying that the timezone database has changed.*/
		ETZDatabaseChanged = 1,
		/** Used for notifying that the system timezone has changed.*/
		ETZSystemTimeZoneChanged,
		/** Used for notifying that the DST rule has changed. */
		ETZDSTRuleChanged,
		/** Used for notifying that an automatic time update has taken place. */
		ETZAutomaticTimeUpdate,
		/** Used for notifying that a change in localization resources has taken
			place. */
		ETZLocalizationDataChanged
		};

	/**
	Time zone server panic codes.
	*/
	enum TPanic
		{
		/** This panic indicates that the time zone server has not been found.*/
		EPanicServerNotFound = 1,
		/** This panic indicates that the server has died.*/
		EPanicServerDead,
		/** This panic indicates that the time zone ID is not set.*/
		EPanicTimeZoneNameIdNotSet,
		/** This panic indicates that an out of range index was accessed.*/
		EPanicRulesIndexOutofRange,
		/** This panic indicates that there are no rules present for this time
			zone.*/
		EPanicTimeNotCoveredByRules,
		/** This panic indicates that the time zone rules are unusable.*/
		EPanicBadTimeZoneRules,
		/** This panic indicates  that an unsupported time reference has been
			accessed.*/
		EPanicUnsupportedTimeReference,
		/** This panic indicates that the time zone ID is not supported.*/
		EPanicUnsupportedTimeZoneNoId,
		/** This panic indicates that a request for notification is already
			pending from the client.*/
		EPanicNotificationRequestPending,
		/** This panic indicates that an incorrect data has been sent to the
			server.*/
		EPanicInvalidArgument,
		/** This panic indicates that a table in the user-defined time zone
			database has not conformed to the declared schema. */
		EPanicBadSchema
		};
	
	/**
	The software install observer plugin can distinguish between changes to the
	resource files or the rules database.  This enumeration indicates the filter
	index that is used for the resource files and rules database filters.
	This enum should not be used externally.
	*/
	enum TSWIObserverFilterIndex
		{
		/** The index of the Tz private directory filter. */
		EFilterTzPrivate=0,
		/** The index of the resources filter. */
		EFilterResourceTimezonelocalization
		};
		
public:
	/** 
	This should not be used externally.
	*/
	IMPORT_C static void Panic(TPanic aPanic);
	
	/** 
	This should not be used externally.
	*/
	IMPORT_C CTzId* GetTimeZoneIdL() const;
	
	/** 
	This should not be used externally.
	*/
	IMPORT_C void SetTimeZoneL(CTzId& aZone) const;

	IMPORT_C void Close();
	IMPORT_C TInt Connect();

	IMPORT_C ~RTz();
	IMPORT_C RTz();
	
	IMPORT_C TInt ConvertToLocalTime(TTime& aTime) const;
	IMPORT_C TInt ConvertToLocalTime(TTime& aTime, const CTzId& aZone) const;
	IMPORT_C TInt ConvertToUniversalTime(TTime& aTime) const;
	IMPORT_C TInt ConvertToUniversalTime(TTime& aTime, const CTzId& aZone) const;
	
	IMPORT_C void GetOffsetsForTimeZoneIdsL(const RArray<TInt>& aTzNumericIds,
		RArray<TInt>& aOffsets) const; 
	
	IMPORT_C TInt AutoUpdateSettingL();
    IMPORT_C void SetAutoUpdateBehaviorL(TTzAutoDSTUpdateModes aUpdateEnabled);
    
    // Methods for setting the system time.
    IMPORT_C TInt SetHomeTime(const TTime& aLocalTime) const;

    IMPORT_C TBool IsDaylightSavingOnL(CTzId& aZone) const;
    IMPORT_C TBool IsDaylightSavingOnL(CTzId& aZone, const TTime& aUTCTime) const;

 	// Get Encoded Rules for Current Local Time Zone
	IMPORT_C CTzRules* GetTimeZoneRulesL(const TTime& aStartTime,
		const TTime& aEndTime, TTzTimeReference aTimeRef) const;
	IMPORT_C CTzRules* GetTimeZoneRulesL(const CTzId& aZone,
		const TTime& aStartTime, const TTime& aEndTime,
		TTzTimeReference aTimeRef) const;
	
	void RegisterTzChangeNotifier(TRequestStatus& aStatus) const;
	TInt CancelRequestForNotice() const;
	TVersion Version() const;
	
	IMPORT_C void NotifyHomeTimeZoneChangedL(const NTzUpdate::TTimeZoneChange&
		aChange) const;
	
	IMPORT_C void SetUnknownZoneTimeL(const TTime& aUTCTime,
		const TInt aUTCOffset);
	IMPORT_C void SetUnknownZoneTimeL(const TTime& aUTCTime,
		const TInt aUTCOffset, TBool aPersistInCenRep);
	
	IMPORT_C void LocalizationReadCitiesL(RPointerArray<CTzLocalizedCityRecord>&
		aCities);
	IMPORT_C void LocalizationReadCitiesL(RPointerArray<CTzLocalizedCityRecord>&
		aCities, TInt aTimeZoneId);
	IMPORT_C void LocalizationReadCitiesInGroupL(RPointerArray<CTzLocalizedCityRecord>&
		aCities, TUint8 aGroupId);
	IMPORT_C CTzLocalizedTimeZoneRecord* LocalizationReadFrequentlyUsedZoneL(
		TInt aFrequentlyUsedZone);
	IMPORT_C CTzLocalizedCityRecord* LocalizationReadCachedTimeZoneCityL(
		TInt aFrequentlyUsedZone);
	IMPORT_C void LocalizationCloseDbL();
	IMPORT_C void LocalizationOpenDbL();
	IMPORT_C void LocalizationWriteCityL(const TDesC& aCityName, TInt aCityTzId,
		TUint8 aCityGroupId, TUint aCityTzResourceId);
	IMPORT_C void LocalizationDeleteCityL(const TDesC& aCityName,
		TInt aCityTzId);
	IMPORT_C void LocalizationWriteFrequentlyUsedZoneL(const CTzLocalizedTimeZoneRecord&
		aTimeZone, const CTzLocalizedCityRecord& aCity,
		TInt aFrequentlyUsedZone);
	IMPORT_C void LocalizationWriteAllFrequentlyUsedZonesL(const RPointerArray<CTzLocalizedTimeZoneRecord>& aTimeZones,
		const RPointerArray<CTzLocalizedCityRecord>& aCities);
	
	// Debug only methods.
	IMPORT_C void SwiObsBeginL();
	IMPORT_C void SwiObsFileChangedL(TSWIObserverFilterIndex aType);
	IMPORT_C void SwiObsEndL();

	// Debug only methods.
	IMPORT_C void __dbgClearCacheL(TBool aRestartCaching);
	IMPORT_C TInt __dbgRequestAllocatedCellsL(TInt aHeapSizeInBytes);
	IMPORT_C void __dbgSetHeapFailL(RAllocator::TAllocFail aType, TInt aRate);
	IMPORT_C void __dbgResetHeapL();

    TBool StartCachingL();
    TUint16 CurrentCachedTzId();

	// User-defined time zone access.
    CTzId* CreateUserTimeZoneL(const CTzRules& aTzUserRules, const CTzUserNames& aTzUserNames);
    CTzUserNames* GetUserTimeZoneNamesL(const CTzId& aTzId) const;
    void UpdateUserTimeZoneL(const CTzId& aTzId, const CTzRules& aTzUserRules, const CTzUserNames& aTzUserNames);
    void DeleteUserTimeZoneL(const CTzId& aTzId);
	void GetUserTimeZoneIdsL(RPointerArray<CTzId>& aTzIds) const;
	
private:
	static TInt StartServer();
	TInt DoConnect();
	void doConvertL(const CTzId& aZone, TTime& aTime,
					TTzTimeReference aTimerRef) const;
	void doConvertL(TTime& aTime, 
					TTzTimeReference aTimerRef) const;
					
	

private:
	CTzRuleHolder* iRulesHolder;
	};


/**
Encapsulates a TTime and a TTzTimeReference.

@publishedAll
@released
*/
class TTimeWithReference
	{
public:
	static inline TTimeWithReference Max();

	inline TTimeWithReference();
	inline TTimeWithReference(TTime aTime, TTzTimeReference aTimeReference=ETzUtcTimeReference);
	inline TTimeWithReference(TDateTime aTime, TTzTimeReference aTimeReference=ETzUtcTimeReference);

	inline bool operator==(const TTimeWithReference& aTime) const;
	inline bool operator!=(const TTimeWithReference& aTime) const;

	TTime iTime;
	TTzTimeReference iTimeReference;
	};


inline TTimeWithReference TTimeWithReference::Max()
	{
	return TTimeWithReference(
		TDateTime(9999,EDecember,30,23,59,59,0), 
		ETzUtcTimeReference);
	}


inline TTimeWithReference::TTimeWithReference() 
	: iTime(0), iTimeReference(ETzUtcTimeReference)
	{
	}


inline TTimeWithReference::TTimeWithReference(TTime aTime, TTzTimeReference aTimeReference)
	: iTime(aTime), iTimeReference(aTimeReference)
	{
	}


inline TTimeWithReference::TTimeWithReference(TDateTime aTime, TTzTimeReference aTimeReference)
	: iTime(aTime), iTimeReference(aTimeReference)
	{
	}


inline bool TTimeWithReference::operator==(const TTimeWithReference& aTime) const
	{
	return(aTime.iTime == iTime && aTime.iTimeReference == iTimeReference);
	}


inline bool TTimeWithReference::operator!=(const TTimeWithReference& aTime) const
	{
	return(!(*this == aTime));
	}

#ifndef SYMBIAN_ENABLE_SPLIT_HEADERS
/**
The CTzUserData class allows the client to create, read, update or delete
user-defined time zones. 

A user-defined time zone is comprised of time zone rules (encapsulated in a
CTzRules object) and time zone names (encapsulated in a CTzUserNames object).

A time zone identifier (encapsulated in a CTzId object) is used to uniquely
identify a user-defined time zone.

The CTzUserData class also allows the time zone identifiers for all existing
user-defined time zones to be determined. 

@publishedPartner
@released
*/
class CTzUserData : public CBase
    {
public:
    IMPORT_C static CTzUserData* NewL(RTz& aTzServer);
    IMPORT_C ~CTzUserData();

    IMPORT_C CTzId* CreateL(const CTzRules& aTzUserRules, const CTzUserNames&
    	aTzUserNames);
    IMPORT_C CTzRules* ReadRulesL(const CTzId& aTzId) const;
	IMPORT_C CTzUserNames* ReadNamesL(const CTzId& aTzId) const;
    IMPORT_C void UpdateL(const CTzId& aTzId, const CTzRules& aTzUserRules,
    	const CTzUserNames& aTzUserNames);
    IMPORT_C void DeleteL(const CTzId& aTzId);
    IMPORT_C void GetTzIdsL(RPointerArray<CTzId>& aTzIds) const;

private:
    CTzUserData(RTz& aTzServer);
	
private:
    RTz& iTzServer;
	};
	
#endif // SYMBIAN_ENABLE_SPLIT_HEADERS

#endif
