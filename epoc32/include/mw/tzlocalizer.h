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
//

#ifndef __TzLocalizer_H__
#define __TzLocalizer_H__

#include <e32base.h>
#include <tz.h>
#include <tzlocalizationdatatypes.h>

class CTzLocalizationResourceReader;
class CTzLocalizationUserDataReader;

const TInt KTzCityNotInGroupId = 0;
/**
Retrieves localized time zone information based on a time zone identifier.

Time zone information is available in the following forms:

- Standard time name, for example "Greenwich Mean Time"
- Short standard time name, for instance "GMT"
- Daylight saving time name, for instance "British Summer Time"
- Short daylight saving time name, for instance "BST"

This information is encapsulated in a CTzLocalizedTimeZone object.

A collection of localized cities for a specific time zone is returned as a
CTzLocalizedCityArray object.  An individual localized city is returned as a
CTzLocalizedCity object.

A collection of localized city groups for a specific time zone is returned as a
CTzLocalizedCityGroupArray.  An individual localized city group is returned as a
CTzLocalizedCityGroup object.

New non-localized cities can be added to an existing time zone.  A new city may
also be added to a city group, but a city may only be a member of one city
group.

User-defined time zone names can also be retrieved through this class,
encapsulated as follows:

- In a CTzLocalizedTimeZone object for long/short standard time and long/short
daylight saving time user-defined time zone names.
- In a CTzLocalizedCityArray object or CTzLocalizedCity object for user-defined
time zone city names.
- In a CTzLocalizedCityGroupArray object or CTzLocalizedCityGroup object for
user-defined time zone region names.

All user-defined time zones names’ use the same city group identifier of
KTzCityNotInGroupId to indicate that they do not belong to a specific group.

For methods that return a single city or single city group, if the given group
identifier is KTzCityNotInGroupId the methods leave with KErrArgument since it
is not possible to determine which region name should be used to identify the
single city group.

For methods that return an array of cities or city groups, if the given group
identifier is KTzCityNotInGroupId the methods shall return all user-defined city
names or region names.

The array object forms can contain a combination of system time zone
localization information and user-defined time zone names.  The client can
control the combination of data using the SetDataSource() method.

@publishedAll
@released
*/
class CTzLocalizer : public CBase
	{
	public:
		/** Panic reasons for the time zone localization component. */
		enum TTzLocalizerPanics
			{
			/** The time zone server was not found. */
			ETzLocalizerPanicTimeZoneServerNotFound,
			/** A resource file was not found. */
			ETzLocalizerPanicResourceFileNotFound
			};

		/** Used to specify the sort order of localized time zone information. */
		enum TTzSortOrder
			{
			/** Unsorted. This is the fastest way to get localized data. */
			ETzUnsorted,
			/** Sort by UTC offset starting with the lowest. */
			ETzUTCAscending,
			/** Sort by UTC offset starting with the highest. */
			ETzUTCDescending,
			/** Sort by name (city name/group name/standard time zone name), from A-Z. */
			ETzAlphaNameAscending,
			/** Sort by name (city name/group name/standard time zone name), from Z-A. */
			ETzAlphaNameDescending,
			/** Sort by standard name from A-Z. */
			ETzAlphaStandardNameAscending,
			/** Sort by daylight savings name from A-Z. */
			ETzAlphaDaylightNameAscending,
			/** Sort by short standard name from A-Z. */
			ETzAlphaShortStandardNameAscending,
			/** Sort by short daylight savings name from A-Z. */
			ETzAlphaShortDaylightNameAscending,
			/** Sort by standard name from Z-A. */
			ETzAlphaStandardNameDescending,
			/** Sort by daylight savings name from Z-A. */
			ETzAlphaDaylightNameDescending,
			/** Sort by short standard name from Z-A. */
			ETzAlphaShortStandardNameDescending,
			/** Sort by short daylight savings name from Z-A. */
			ETzAlphaShortDaylightNameDescending
			};

	    /**
	    This enumeration indicates the data source(s) to use for CTzLocalizer
	    methods that return a combination of system time zone localization
	    information and user-defined time zone names.  The enumeration values
	    are bit flags which can be combined using the logical OR operator.
	    */
		enum TTzLocalizerDataSource
	        {
	        /** Use system time zone localization information. */
	        ETzDataSourceSystem = 0x1,
	        /** Use non-localized user time zone names. */
	        ETzDataSourceUser   = 0x2
	        };

	public:
		//Construction / Destruction
		IMPORT_C static CTzLocalizer* NewL();
		IMPORT_C static CTzLocalizer* NewLC();
		IMPORT_C ~CTzLocalizer();

	private:
		CTzLocalizer();
		void ConstructL();
        TBool DbNeedsUpdatingL() const;
        void UpgradeDbVersionL();
        void FetchCityToUpgradeL(CTzLocalizedTimeZoneArray& aTimeZoneArray, CTzLocalizedCityArray& aCityArray, CTzLocalizedTimeZone::TTzFrequentlyUsedZone aCachedZone);
        void RecreateDbL();

	public:
		//Time zones
		IMPORT_C CTzLocalizedTimeZone* GetLocalizedTimeZoneL(TInt aTimeZoneId) const;
		IMPORT_C CTzLocalizedTimeZone* GetLocalizedTimeZoneL(const CTzLocalizedCity& aCity) const;
		IMPORT_C CTzLocalizedTimeZoneArray* GetAllTimeZonesL(const TTzSortOrder aSortOrder = ETzUnsorted);

		IMPORT_C void SetTimeZoneL(TInt aTimeZoneId);

		//City Management
		IMPORT_C CTzLocalizedCity* GetDefaultCityL(TInt aTimeZoneId) const;
		IMPORT_C CTzLocalizedCity* GetDefaultCityL(const CTzLocalizedCity& aCity) const;
		IMPORT_C CTzLocalizedCity* GetDefaultCityL(const CTzLocalizedTimeZone& aTimeZone) const;

		IMPORT_C CTzLocalizedCityArray* GetCitiesL(const TTzSortOrder aSortOrder = ETzUnsorted);
		IMPORT_C CTzLocalizedCityArray* GetCitiesL(TInt aTimeZoneId,const TTzSortOrder aSortOrder = ETzUnsorted);
		IMPORT_C CTzLocalizedCityArray* GetCitiesL(const CTzLocalizedTimeZone& aTimeZone,const TTzSortOrder aSortOrder = ETzUnsorted);
		IMPORT_C CTzLocalizedCityArray* GetCitiesL(const CTzLocalizedCity& aCity,const TTzSortOrder aSortOrder = ETzUnsorted);

		IMPORT_C CTzLocalizedCity* AddCityL(TInt aTimeZoneId,const TDesC& aCityName, TInt aGroupId = 0);
		IMPORT_C void RemoveCityL(CTzLocalizedCity* aCity);

		//City Groups
		IMPORT_C CTzLocalizedCityGroupArray* GetAllCityGroupsL(const TTzSortOrder aSortOrder = ETzUnsorted) const;
		IMPORT_C CTzLocalizedCityGroup* GetCityGroupL(TInt aGroupId) const;
		IMPORT_C CTzLocalizedCityGroup* GetCityGroupL(const CTzLocalizedCity& aCity) const ;

		IMPORT_C CTzLocalizedCityArray* GetCitiesInGroupL(TInt aGroupId,const TTzSortOrder aSortOrder = ETzUnsorted);
		IMPORT_C CTzLocalizedCityArray* GetCitiesInGroupL(const CTzLocalizedCity& aCity,const TTzSortOrder aSortOrder = ETzUnsorted);
		IMPORT_C CTzLocalizedCityArray* GetCitiesInGroupL(const CTzLocalizedCityGroup& aCityGroup,const TTzSortOrder aSortOrder = ETzUnsorted);

		//Frequently Used Zones
		IMPORT_C CTzLocalizedTimeZone* GetFrequentlyUsedZoneL(const CTzLocalizedTimeZone::TTzFrequentlyUsedZone aFrequentlyUsedZone);
		IMPORT_C CTzLocalizedCity* GetFrequentlyUsedZoneCityL(const CTzLocalizedTimeZone::TTzFrequentlyUsedZone aFrequentlyUsedZone);
		IMPORT_C void SetFrequentlyUsedZoneL(TInt aTimeZoneId,const CTzLocalizedTimeZone::TTzFrequentlyUsedZone aFrequentlyUsedZone);
		IMPORT_C void SetFrequentlyUsedZoneL(const CTzLocalizedTimeZone& aTimeZone,const CTzLocalizedTimeZone::TTzFrequentlyUsedZone aFrequentlyUsedZone);
		IMPORT_C void SetFrequentlyUsedZoneL(const CTzLocalizedCity& aCity,const CTzLocalizedTimeZone::TTzFrequentlyUsedZone aFrequentlyUsedZone);

		//Find functions
		IMPORT_C CTzLocalizedCity* FindCityByNameL(const TDesC& aCityName, const TInt aTimeZoneId = 0);
		IMPORT_C CTzLocalizedTimeZone* FindTimeZoneByNameL(const TDesC& aTimeZoneName);
		IMPORT_C CTzLocalizedCityGroup* FindCityGroupByNameL(const TDesC& aCityGroupName);

		IMPORT_C TBool CheckLanguage();

		//Cities and Time Zones with a specified UTC offset
		IMPORT_C CTzLocalizedCityArray* GetCitiesWithUTCOffsetL(TInt aUTCOffsetInMinutes, const TTzSortOrder aSortOrder = ETzUnsorted);
		IMPORT_C CTzLocalizedTimeZoneArray* GetTimeZonesWithUTCOffsetL(TInt aUTCOffsetInMinutes, const TTzSortOrder aSortOrder = ETzUnsorted);

		IMPORT_C void SetDataSource(TUint aDataSource);

	private:
		TBool PrepareFrequentlyUsedZonesL();
		void UpdateFrequentlyUsedZonesL();
		CTzLocalizedTimeZone* GetFrequentlyUsedDefaultZoneL(CTzLocalizedTimeZone::TTzFrequentlyUsedZone aFreqUsedZone);
		TUint32 GetFrequentlyUsedDefaultZoneCenRepKeyL(CTzLocalizedTimeZone::TTzFrequentlyUsedZone aFreqUsedZone);
		void GetCitiesL(CTzLocalizedCityArray& aCities, const TTzLocalizedId& aLocalizedId,
			TBool aUseDataSource, const TTzSortOrder aSortOrder = ETzUnsorted);
		TLinearOrder<CTzLocalizedCity> CitySortOrderL(const TTzSortOrder aSortOrder);
		TLinearOrder<CTzLocalizedTimeZone> TimeZoneSortOrderL(const TTzSortOrder aSortOrder);
		template <class T> void PrepareForUTCSortL(T& aArray);
		TInt GetTimeZoneIdFromTzServerL();
		void DoSetTimeZoneL(TInt aTimeZoneId);
		void ChangeHomeTimeZoneL(TInt aNewId);
        TBool FindCityAndSetCityIndexL(CTzLocalizedCity& aLocalizedCity, TTzLocalizerDataSource aDataSource);
        TBool IsOperateOnUserDbL(TInt aTimeZoneId, TBool aUseDataSource) const;
        void ReadCitiesL(CTzLocalizedCityArray& aCityArray, TInt aTimeZoneId, TBool aUseDataSource) const;
        CTzLocalizedCity* ReadDefaultCityL(TInt aTimeZoneId, TBool aUseDataSource) const;
        void WriteAllFrequentlyUsedZonesL(const CTzLocalizedTimeZoneArray& aTimeZones, const CTzLocalizedCityArray& aCities);
        void SetFrequentlyUsedZoneL(const CTzLocalizedTimeZone& aTimeZone, const CTzLocalizedCity& aCity,
        	const CTzLocalizedTimeZone::TTzFrequentlyUsedZone aFrequentlyUsedZone);
        CTzLocalizedTimeZone* GetLocalizedTimeZoneL(TInt aTimeZoneId, TBool aUseDataSource) const;
        CTzLocalizedTimeZone* GetLocalizedTimeZoneL(const CTzLocalizedCity& aCity, TBool aUseDataSource) const;
        static void PopulateCityArrayL(const RPointerArray<CTzLocalizedCityRecord>& aCityRecords,
        	CTzLocalizedCityArray& aCities);
        static CTzLocalizedTimeZoneRecord* CreateTimeZoneRecordL(const CTzLocalizedTimeZone& aTimeZone);
        static CTzLocalizedTimeZoneRecord* CreateTimeZoneRecordLC(const CTzLocalizedTimeZone& aTimeZone);
        static CTzLocalizedCityRecord* CreateCityRecordL(const CTzLocalizedCity& aCity);
        static CTzLocalizedCityRecord* CreateCityRecordLC(const CTzLocalizedCity& aCity);
        static CTzLocalizedTimeZone* CreateTimeZoneL(const CTzLocalizedTimeZoneRecord& aTimeZoneRecord);
        static CTzLocalizedCity* CreateCityL(const CTzLocalizedCityRecord& aCityRecord);
        static void CleanupTimeZonePointerArray(TAny* aArray);
        static void CleanupCityPointerArray(TAny* aArray);

private:
		CTzLocalizationResourceReader* iStaticDataReader;
		CTzLocalizationUserDataReader* iUserDataReader;

		TLanguage iLanguage;
		TUint iDataSource;
		RTz iTzSession;
	};

#endif//__TzLocalizer_H__
