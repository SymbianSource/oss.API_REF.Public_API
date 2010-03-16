// Copyright (c) 1997-2009 Nokia Corporation and/or its subsidiary(-ies).
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

#ifndef __T32WLD_H__
#define __T32WLD_H__

#include <e32base.h>
#include <dial_consts.h>


//
//
// Literal constants
_LIT(KWorldServerName, "!WorldServer");

_LIT(KWorldServerImageName, "WorldServer");
//
/**
@internalComponent
@released
*/
const TUid KWorldServerUid = { 0x101F5025 };
//

/**
@internalComponent
@released
*/
const TInt KWorldServerMajorVN=1;

/**
@internalComponent
@released
*/
const TInt KWorldServerMinorVN=0;

/**
@internalComponent
@released
*/
const TInt KWorldServerBuildVN=105;
//
/**
@internalComponent
@released
*/
const TInt KMaxZoneName=3;

/** Maximum length for TCityName. 
@internalComponent
@released
*/
const TInt KMaxCityName=25;  

/** Maximum length for TCountryName. 
@internalComponent
@released
*/
const TInt KMaxCountryName=25;

/**
@internalComponent
@released
*/
const TInt KMaxWorldRomTitle=32;

/**
@internalComponent
@released
*/
const TInt KMaxWorldLatitudeMinutes=90*60;

/**
@internalComponent
@released
*/
const TInt KMaxWorldLongitudeMinutes=180*60;

/**
@internalComponent
@released
*/
const TInt KMaxWorldUniversalTimeOffsetMinutes=17*60;

/**
@internalComponent
@released
*/
const TInt KISOCountryCodeLength=2;
//

/** A buffer for a city name. 
@publishedAll
@released
*/
typedef TBuf<KMaxCityName> TCityName;

/** A buffer for a country name. 
@publishedAll
@released
*/
typedef TBuf<KMaxCountryName> TCountryName;

/**
@publishedAll
@released
*/
typedef TBuf<KISOCountryCodeLength> TISOCountryCode;
//

/** Defines the distance units which can be used by the world server. 
@publishedAll
@released
*/
enum TWldDistanceUnits 
	{
	/** Miles. */
	EWldMiles,
	/** Kilometres. */
	EWldKilometers,
	/** Nautical miles. */
	EWldNauticalMiles
	};

/** City search mode flags. These define whether a search for a city involves the 
whole of the world database, or just a single country. 
For example, the RWorldServer::NextCity() function returns either the next 
city in the country, or the next city in the world, depending on which of these two 
values is set in the TWorldId. 
@publishedAll
@released
*/
enum TWldSelect 
	{
	/** The search is within the whole world database. */
	EWithinWorld,
	/** The search is within the current country only. */
	EWithinCountry
	};

/** Flags which indicate the reasons why the server cannot delete a  
city or country. Bitmasks of these flags are returned by the RWorldServer 
functions IsCityDeletable() and IsCountryDeletable(). 
@publishedAll
@released
*/
enum TWldDeleteDeniedFlags
	{
	/** The specified TWorldId is not found. */
	EWldDelNotFound=0x01,
	/** The specified TWorldId is in a read-only file. */
	EWldDelDerivedFromRom=0x02,
	/** The specified TWorldId is the home city or country. */
	EWldDelHomeCityCountry=0x04,
	/** The specified TWorldId is a capital city. */
	EWldDelCapitalCity=0x08,
	/** The specified TWorldId is the default country. */
	EWldDelDefaultCountry=0x10,
	/** The specified TWorldId cannot be deleted for all of the above reasons. */
	EWldDelAll=0xff
	};
//
class TLatLong
/**
@publishedAll
@deprecated Interface is deprecated and is available for backward compatibility reasons only
*/
    {
public:
	inline TInt MinutesLat() const; // North is +ve, South is -ve
	inline TInt MinutesLong() const; // West is +ve, East is -ve
	IMPORT_C void SetMinutesL(TInt aLat,TInt aLong); // North and West are +ve, South and East are -ve
	IMPORT_C void SetMinutesCorrectingErrors(TInt aLat,TInt aLong); // North and West are +ve, South and East are -ve
private:
    TInt16 iLat;
    TInt16 iLong;
    };
//
class TCityData
/** City information.

This class stores information about a city, including its name, country, 
area code, daylight savings zone, latitude and longitude, map position and 
UTC offset. 
@publishedAll
@released
*/
    {
public:
	/** The city name. */
    TCityName iCity;
	/** The country name. */
    TCountryName iCountry;
	/** The position of the city in pixels on a map on the screen. */
    TPoint iMapPos;
	/** The city's latitude and longitude. This is used to calculate the distance 
	between cities, and the sunrise and sunset time. */
    TLatLong iLatLong;
	/** The local area code. */
    TAreaCode iAreaCode;
	/** The UTC offset in minutes. */
    TInt iUniversalTimeOffset;
	/** The daylight savings zone. */
    TDaylightSavingZone iDaylightSavingZone;
    };
//
class TCountryData  
/** Country information.

This class stores information about a country. 
@publishedAll
@released
*/
    {
public:
	/** The country's name. */
    TCountryName iCountry;
	/** The country's national dialling code. */
    TNatCode iNatCode;
	/** The country's capital city. */
    TCityName iCapital;
	/** The national dialling prefix. */
    TNatPrefCode iNatPref;
	/** The country's international dialling prefix. */
    TIntlPrefCode iIntlPref;
    };
//
//
class TWorldId
/** World ID.

This class stores the world ID for a city/country. This consists of the city 
and country names. Unique IDs of this type are used to identify every city 
in the world database.

It also defines a field for setting whether city searches span the 
whole database, or just the current country. 
@publishedAll
@deprecated Interface is deprecated and is available for backward compatibility reasons only
*/
    {
public:
    IMPORT_C TWorldId();
    inline const TCityName& City() const;
    inline const TCountryName& Country() const;
    inline TWldSelect Select() const;
	inline void SetSelect(TWldSelect aSelector);
private:
    TCityName iCity;
    TWldSelect iSelect;
    TCountryName iCountry;
	friend class RWorldServer;
    };
//
class RWorldServer : public RSessionBase
/** Defines the client side API to the world server.

Clients can use this API to connect to the server, add, update and delete 
cities/countries, retrieve city/country information, navigate and search the 
world database, set the home city, default country, and the units used in 
distance comparisons. In addition, clients can use the file handling functions 
to import and export database data files. 
@publishedAll
@deprecated Interface is deprecated and is available for backward compatibility reasons only
*/
    {
public:
    IMPORT_C TInt Connect();
	IMPORT_C TVersion Version() const;
	IMPORT_C void RomTitle(TDes& aText) const;
	IMPORT_C TInt NumberCities() const;
	IMPORT_C TInt NumberCountries() const;
	//
    IMPORT_C void NotifyOnChange(TRequestStatus& aStatus);
    IMPORT_C void NotifyOnChangeCancel();
	//
	IMPORT_C TInt ResetAllData();
	IMPORT_C TInt DataFileSave();
	IMPORT_C TInt DataFileRevertToSaved();
	//
    IMPORT_C TInt DefaultCountry(TWorldId& aCountry) const;
    IMPORT_C TInt SetDefaultCountry(const TWorldId& aId);
    IMPORT_C TInt Home(TWorldId& aHome) const;
    IMPORT_C TInt SetHome(const TWorldId& aId);
	//
    IMPORT_C TInt AddCity(const TCityData& aCity);
    IMPORT_C TInt AddCountry(const TCountryData& aCountry,const TCityData& aCapital);
    IMPORT_C TInt CityData(TCityData& aCity,const TWorldId& aId) const;
    IMPORT_C TInt CountryData(TCountryData& aCountry,const TWorldId& aId) const;
	IMPORT_C TInt CalculateDistance(TInt& aDistance,const TWorldId& aLeft,const TWorldId& aRight) const;
	IMPORT_C TInt CalculateSunlight(TTime& aSunrise,TTime& aSunset,const TWorldId& aId,const TTime& aDate=Time::NullTTime()) const;
    IMPORT_C TInt DeleteCity(TWorldId& aId);
    IMPORT_C TInt DeleteCountry(TWorldId& aId);
    IMPORT_C TInt DistanceUnits(TWldDistanceUnits& aDistanceUnit) const;
    IMPORT_C TInt SetDistanceUnits(TWldDistanceUnits aUnit);
    IMPORT_C TInt Find(TWorldId& aId,const TDesC& aCity,const TDesC& aCountry) const;
    IMPORT_C TInt FindCity(TWorldId& aCity,const TDesC& aPartialCity) const;
    IMPORT_C TInt FindCountry(TWorldId& aCountry,const TDesC& aPartialCountry) const;
	IMPORT_C TInt FirstCity(TWorldId& aId) const;
	IMPORT_C TInt FirstCountry(TWorldId& aId) const;
	IMPORT_C TInt IsCityDeletable(TInt& aDeleteDeniedFlags,const TWorldId& aId) const;
	IMPORT_C TInt IsCountryDeletable(TInt& aDeleteDeniedFlags,const TWorldId& aId) const;
	IMPORT_C TInt LastCity(TWorldId& aId) const;
	IMPORT_C TInt LastCountry(TWorldId& aId) const;
    IMPORT_C TInt NearestCity(const TPoint& aMapCoord,const TWorldId* aCityToBeat=NULL);
    IMPORT_C TInt NextNearestCity(TWorldId& aId,TInt aMaxNumberToCompare=KMaxTInt);
    IMPORT_C TInt NextCity(TWorldId& aId) const;
    IMPORT_C TInt NextCountry(TWorldId& aId) const;
    IMPORT_C TInt PrevCity(TWorldId& aId) const;
    IMPORT_C TInt PrevCountry(TWorldId& aId) const;
    IMPORT_C TInt UpdateCity(TWorldId& aId,const TCityData& aCity);
    IMPORT_C TInt UpdateCountry(TWorldId& aId,const TCountryData& aCountry);
	IMPORT_C TInt GetCountryNameByISOCode(const TDesC& aCode, TDes& aCountry) const;
	IMPORT_C TInt SetCollationLevelForFind(TInt aCollationLevel); // this is a per-client setting
public: 
	IMPORT_C void __DbgFailAlloc(TInt aCount);
	IMPORT_C void __DbgMarkEnd();
	IMPORT_C void __DbgMarkHeap();
	IMPORT_C TInt SetRomDatabaseToUse(const TDesC& aRomDatabaseToUse);
	IMPORT_C TBool ReadOnlyDataIsInRAM() const;
    };
//
// TWorldId
inline TWldSelect TWorldId::Select() const
/** Gets the current city search mode. Clients can search for cities by country, 
or over the whole world database.

@return The current city search mode. */
	{
	return(iSelect);
	}
inline const TCityName& TWorldId::City() const
/** Gets the city name in the current TWorldId.

@return A reference to the city name. */
	{
	return(iCity);
	}
inline const TCountryName& TWorldId::Country() const
/** Gets the country name in the current TWorldId.

@return A reference to the country name. */
	{
	return(iCountry);
	}
inline void TWorldId::SetSelect(TWldSelect aSelector)
/** Sets the city search mode. Clients can search for cities by country, or over 
the whole world database.

@param aSelector The city search mode. */
	{
	iSelect=aSelector;
	}
//
// TLatLong
inline TInt TLatLong::MinutesLat() const
	{
	return(iLat);
	}
inline TInt TLatLong::MinutesLong() const
	{
	return(iLong);
	}
#endif
