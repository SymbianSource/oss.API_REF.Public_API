// Copyright (c) 2004-2009 Nokia Corporation and/or its subsidiary(-ies).
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

#ifndef __TzLocalizer_H__
#define __TzLocalizer_H__

#include <e32base.h> //CBase

#include <tzlocalizationdatatypes.h> 	//CTzLocalizedCity, CTzLocalizedCityGroup etc

// Forward Declarations
class MTzLocalizationReader;
class MTzLocalizationWriter;

/**
Retrieves localized time zone information based on a time zone ID.

Time zone information is available in the following forms:
- Standard Name, for instance Greenwich Mean Time,
- Short Standard Name, for instance GMT,
- Daylight Savings Name, for instance British Summer Time,
- Short Daylight Savings Name, for instance BST.

This information is encapsulated in a CTzLocalizedTimeZone object.

A collection of localizable cities for a specific time zone can also be returned.
New cities can be added to a time zone.  Cities may also be added to groups, but 
a city may only be a member of one group.

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

	public:
		//Construction / Destruction
		IMPORT_C static CTzLocalizer* NewL();
		IMPORT_C static CTzLocalizer* NewLC();
		IMPORT_C ~CTzLocalizer();

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
		
	private:
		void ConstructL();
		CTzLocalizer();
		
		TBool PrepareFrequentlyUsedZonesL();
		void UpdateFrequentlyUsedZonesL();
		CTzLocalizedTimeZone* GetFrequentlyUsedDefaultZoneL(CTzLocalizedTimeZone::TTzFrequentlyUsedZone aFreqUsedZone);
		TUint32 GetFrequentlyUsedDefaultZoneCenRepKeyL(CTzLocalizedTimeZone::TTzFrequentlyUsedZone aFreqUsedZone);
		
		void GetCitiesL(CTzLocalizedCityArray& aCities, const TTzLocalizedId& aLocalizedId, const TTzSortOrder aSortOrder = ETzUnsorted);
		
		TLinearOrder<CTzLocalizedCity> CitySortOrderL(const TTzSortOrder aSortOrder);
		TLinearOrder<CTzLocalizedTimeZone> TimeZoneSortOrderL(const TTzSortOrder aSortOrder);
		template <class T> void PrepareForUTCSortL(T& aArray);
		
		TInt GetTimeZoneIdFromTzServerL();
		void DoSetTimeZoneL(TInt aTimeZoneId);
		void ChangeHomeTimeZoneL(TInt aNewId);
		
		void ValidateDbL();
        void RecreateDbL();
        TBool DbNeedsUpdatingL() const;
		TBool DbIsInvalidL() const;
        void UpgradeDbVersionL();
        void FetchCityToUpgradeL(CTzLocalizedTimeZoneArray& aTimeZoneArray, CTzLocalizedCityArray& aCityArray, CTzLocalizedTimeZone::TTzFrequentlyUsedZone aCachedZone);

	private:
		//Member data
		MTzLocalizationReader* iStaticDataReader;
		MTzLocalizationReader* iPersistedDataReader;
		MTzLocalizationWriter* iPersistedDataWriter;
		TLanguage iLanguage;
	};

#endif//__TzLocalizer_H__
