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

#ifndef __TZLOCAL_DATATYPES_H__
#define __TZLOCAL_DATATYPES_H__

#include <e32base.h>

/**
The resource structure LOCALIZED_TIMEZONE (defined in TimeZoneLocalization.rh) is used
to represent a time zone item in a resource file. One of the members of this structure is
WORD time_zone_id which stores the id of the time zone.

This class stores a time zone id (iTzId) and its associated resource id (iResourceId). This
facilitates fast finding of resources in the resource file.  For internal use only.

For instance for a time zone defined as follow in the resource file, iTzId would be 2728 and 
iResourceId would be r_tz_europe_tirane (more precisely the resource id assigned to r_tz_europe_tirane
by the resource compiler).

RESOURCE LOCALIZED_TIMEZONE r_tz_europe_tirane
	{
	time_zone_id = 2728;
	standard_name = 2728_standard_name;
	daylight_name = 2728_daylight_name;
	short_standard_name = 2728_short_standard_name;
	short_daylight_name = 2728_short_daylight_name;
	cities = 
		{
		TIMEZONE_CITY
			{
			city_group_id = 5;
			city_name = 2728_tirane_name;
			}
		};
	}

@internalTechnology
*/
class TTzLocalizedId
	{
	public:
		explicit TTzLocalizedId(const TUint16 aTzId, const TUint aResourceId);

		//Accessor methods
		inline TUint16 TimeZoneId() const;
		inline TUint ResourceId() const;
		
	private:
		TUint16 iTzId;
		TUint iResourceId;
	};

/**
Encapsulates a localized (exemplar) city.

@publishedAll
@released
*/
class CTzLocalizedCity : public CBase
	{
	public:
		static CTzLocalizedCity* NewL(
			const TDesC& aName,
			const TTzLocalizedId& aTzLocalizedId,
			const TUint8 aGroupId =0);
		static CTzLocalizedCity* NewLC(
			const TDesC& aName,
			const TTzLocalizedId& aTzLocalizedId,
			const TUint8 aGroupId =0);
		~CTzLocalizedCity();

		//Accessor methods
		IMPORT_C TPtrC Name() const;
		IMPORT_C TUint16 TimeZoneId() const;
		IMPORT_C TUint8 GroupId() const;
		TTzLocalizedId TzLocalizedId() const;
		TInt UTCOffset() const;
		void SetUTCOffset(TInt aUTCoffset);
        void SetCityIndex(TInt aIndex);
       	TInt CityIndex() const;

	private:
		void ConstructL(const TDesC& aName);
		CTzLocalizedCity(const TUint8 aGroupId, const TTzLocalizedId& aTzLocalizedId);

	private:
		HBufC* iName;
		TUint8 iGroupId;
		TTzLocalizedId iTzLocalizedId;
        TInt iCityIndex;
        /**
        When sorting arrays in UTC order the UTC offset is stored here. It is expressed in minutes.
        This value should only be used for this purpose.
        */
        TInt iUTCOffset;
	};

/**
Encapsulates a localized group of (exemplar) cities.

@publishedAll
@released
*/
class CTzLocalizedCityGroup : public CBase
	{
	public:
		static CTzLocalizedCityGroup* NewL(const TDesC& aName, const TUint8 aGroupId);
		static CTzLocalizedCityGroup* NewLC(const TDesC& aName, const TUint8 aGroupId);
		~CTzLocalizedCityGroup();

		//Accessor methods
		IMPORT_C TPtrC Name() const;
		IMPORT_C TUint8 Id() const;

	private:
		void ConstructL(const TDesC& aName);
		CTzLocalizedCityGroup(const TUint8 aGroupId);

	private:
		HBufC* iName;
		TUint8 iGroupId;
	};

/**
Encapsulates a group of LDML localized timezone names.
LDML stands for Locale Data Markup Language. For details, see 
http://www.openi18n.org/specs/ldml/1.0/ldml-spec.htm

@publishedAll
@released
*/
class CTzLocalizedTimeZone : public CBase
	{
	public: //enums
		/**
		Flags to identify a cached zone.
		@publishedAll
		@released
		*/
		enum TTzFrequentlyUsedZone
			{
			/** The current zone. */
			ECurrentZone,
			/** The home zone. */
			EHomeZone,
			/** The zone of interest. */
			EInterestZone,
			/** The first recently-used zone. */
			ERecentZone1,
			/** The second recently-used zone. */
			ERecentZone2,
			/** Specifies the number of cached zones. Not to be used as an API argument. */
			ECachedTimeZones	// If new items are added to this enum, this must 
								// left as last item, because it is used to keep 
								// count of the number of cached zones
			};

	public:
		static CTzLocalizedTimeZone* NewL(
			const TTzLocalizedId& aTzLocalizedId,
			const TDesC& aStandardName,
			const TDesC& aDaylightName,
			const TDesC& aShortStandardName,
			const TDesC& aShortDaylightName);

		static CTzLocalizedTimeZone* NewLC(
			const TTzLocalizedId& aTzLocalizedId,
			const TDesC& aStandardName,
			const TDesC& aDaylightName,
			const TDesC& aShortStandardName,
			const TDesC& aShortDaylightName);

		~CTzLocalizedTimeZone();

		//Accessor methods
		IMPORT_C TUint16 TimeZoneId() const;
		IMPORT_C TPtrC StandardName() const;
		IMPORT_C TPtrC DaylightName() const;
		IMPORT_C TPtrC ShortStandardName() const;
		IMPORT_C TPtrC ShortDaylightName() const;
		TTzLocalizedId TzLocalizedId() const;
		TInt UTCOffset() const;
		void SetUTCOffset(TInt aUTCoffset);

	private:
		void ConstructL(
			const TDesC& aStandardName,
			const TDesC& aDaylightName,
			const TDesC& aShortStandardName,
			const TDesC& aShortDaylightName);
		CTzLocalizedTimeZone(const TTzLocalizedId& aTzLocalizedId);

	private:
		TTzLocalizedId iTzLocalizedId;
		HBufC* iStandardName;
		HBufC* iDaylightName;
		HBufC* iShortStandardName;
		HBufC* iShortDaylightName;
		/**
        When sorting arrays in UTC order the UTC offset is stored here. It is expressed in minutes.
        This value should only be used for this purpose.
        */
		TInt iUTCOffset;
	};

/**
Template for arrays of localized objects. Implemented using a thin template. 
All functions are inline.

@publishedAll
@released
*/
template <class T>
class CTzLocalizedArray : public CBase
	{
	protected:
		inline ~CTzLocalizedArray();

		inline T& At(TInt aIndex) const;
		inline TInt Count() const;
		inline void AppendL(T* aElement);
		inline void Remove(TInt aIndex);
		inline void Sort(TLinearOrder<T> aOrder);
		inline TInt Find(T* aEntry,TIdentityRelation<T> aIdentityRelation);
		inline void ReserveL(TInt aCount);

		inline CTzLocalizedArray();

	private:
		RPointerArray<T> iArray;
	};

// Assign concrete classes for each of the arrays that will be used
// This guards against future BC problems

/**
An array of cities. This just passes function calls on to its templated base
class, CTzLocalizedArray.

@publishedAll
@released
*/
class CTzLocalizedCityArray : public CTzLocalizedArray<CTzLocalizedCity>
	{
	public:
		IMPORT_C static CTzLocalizedCityArray* NewL();
		IMPORT_C static CTzLocalizedCityArray* NewLC();

		IMPORT_C CTzLocalizedCity& At(TInt aIndex) const;
		IMPORT_C TInt Count() const;
		IMPORT_C void AppendL(CTzLocalizedCity* aCity);
		IMPORT_C void Remove(TInt aIndex);
		IMPORT_C void Sort(TLinearOrder<CTzLocalizedCity> anOrder);
		IMPORT_C TInt Find(CTzLocalizedCity* anEntry,TIdentityRelation<CTzLocalizedCity> aIdentityRelation);
		void ReserveL(TInt aCount);
	};
	
/**
An array of city groups. This just passes function calls on to its templated base
class, CTzLocalizedArray.

@publishedAll
@released
*/
class CTzLocalizedCityGroupArray : public CTzLocalizedArray<CTzLocalizedCityGroup>
	{
	public:
		IMPORT_C static CTzLocalizedCityGroupArray* NewL();
		IMPORT_C static CTzLocalizedCityGroupArray* NewLC();

		IMPORT_C CTzLocalizedCityGroup& At(TInt aIndex) const;
		IMPORT_C TInt Count() const;
		IMPORT_C void AppendL(CTzLocalizedCityGroup* aGroup);
		IMPORT_C void Remove(TInt aIndex);
		IMPORT_C void Sort(TLinearOrder<CTzLocalizedCityGroup> anOrder);
		IMPORT_C TInt Find(CTzLocalizedCityGroup* anEntry,TIdentityRelation<CTzLocalizedCityGroup> aIdentityRelation);
		void ReserveL(TInt aCount);
	};

/**
An array of time zones. This just passes function calls on to its templated base
class, CTzLocalizedArray.

@publishedAll
@released
*/
class CTzLocalizedTimeZoneArray : public CTzLocalizedArray<CTzLocalizedTimeZone>
	{
	public:
		IMPORT_C static CTzLocalizedTimeZoneArray* NewL();
		IMPORT_C static CTzLocalizedTimeZoneArray* NewLC();

		IMPORT_C CTzLocalizedTimeZone& At(TInt aIndex) const;
		IMPORT_C TInt Count() const;
		IMPORT_C void AppendL(CTzLocalizedTimeZone* aElement);
		IMPORT_C void Remove(TInt aIndex);
		IMPORT_C void Sort(TLinearOrder<CTzLocalizedTimeZone> anOrder);
		IMPORT_C TInt Find(CTzLocalizedTimeZone* anEntry,TIdentityRelation<CTzLocalizedTimeZone> aIdentityRelation);
		void ReserveL(TInt aCount);
	};

#include <tzlocalizationdatatypes.inl>

#endif //__TZLOCAL_DATATYPES_H__
