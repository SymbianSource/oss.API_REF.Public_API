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
// ExifUtilty.h
// 
//

#ifndef __EXIFUTILITY_H__
#define __EXIFUTILITY_H__

class MExifMetadataReader;
class MExifMetadataWriter;


/**
@publishedAll
@released

This class offers a friendly interface to read the metadata in exif encoded image files

Note: Unless otherwise stated in a method's documentation, TInt& arguments represent unsigned quantities and will be updated with unsigned values, even though TInt is a signed type.
In such cases, proper typecasting should be used to ensure that the values are correctly treated as unsigned.

Note: Get method arguments will only be updated if the method is returning KErrNone.

*/
class TExifReaderUtility 
	{
public:
	// Construction and destruction
	IMPORT_C TExifReaderUtility(MExifMetadataReader* aExifMetadataReader);
	
public:
	// Getters
	IMPORT_C TInt GetMake(HBufC8*& aParam) const;
	IMPORT_C TInt GetModel(HBufC8*& aParam) const;
	IMPORT_C TInt GetDateTime(HBufC8*& aParam) const;
	IMPORT_C TInt GetDateTimeOriginal(HBufC8*& aParam) const;
	IMPORT_C TInt GetDateTimeDigitized(HBufC8*& aParam) const;
	IMPORT_C TInt GetInteroperabilityIndex(HBufC8*& aParam) const;
	IMPORT_C TInt GetInteroperabilityVersion(HBufC8*& aParam) const;

	IMPORT_C TInt GetExifVersion(HBufC8*& aParam) const;
	IMPORT_C TInt GetComponentsConfiguration(HBufC8*& aParam) const;
	IMPORT_C TInt GetFlashPixVersion(HBufC8*& aParam) const;

	IMPORT_C TInt GetXResolution(TInt& aNumerator, TInt& aDenominator) const;
	IMPORT_C TInt GetYResolution(TInt& aNumerator, TInt& aDenominator) const;
	IMPORT_C TInt GetThumbXResolution(TInt& aNumerator, TInt& aDenominator) const;
	IMPORT_C TInt GetThumbYResolution(TInt& aNumerator, TInt& aDenominator) const;

	IMPORT_C TInt GetResolutionUnit(TUint16& aParam) const;
	IMPORT_C TInt GetYCbCrPositioning(TUint16& aParam) const;
	IMPORT_C TInt GetOrientation(TUint16& aParam) const;
	IMPORT_C TInt GetColorSpace(TUint16& aParam) const;
	IMPORT_C TInt GetPixelXDimension(TInt& aParam) const;
	IMPORT_C TInt GetPixelYDimension(TInt& aParam) const;

	IMPORT_C TInt GetThumbCompression(TUint16& aParam) const;
	IMPORT_C TInt GetThumbResolutionUnit(TUint16& aParam) const;
	IMPORT_C TInt GetThumbOrientation(TUint16& aParam) const;
	
	IMPORT_C TInt GetImageDescription(HBufC8*& aParam) const;
	IMPORT_C TInt GetCopyright(HBufC8*& aParam) const;
	IMPORT_C TInt GetMakerNote(HBufC8*& aParam) const;
	IMPORT_C TInt GetUserComment(HBufC8*& aParam) const;
	IMPORT_C TInt GetFlash(TUint16& aParam) const;
	IMPORT_C TInt GetFocalLength(TInt& aNumerator, TInt& aDenominator) const;
	IMPORT_C TInt GetShutterSpeedValue(TInt& aNumerator, TInt& aDenominator) const;
	IMPORT_C TInt GetJpegInterchangeFormatLength(TInt& aParam) const;
	IMPORT_C TInt GetJpegInterchangeFormatLength(TUint& aParam) const;

	IMPORT_C TInt GetGpsVersionId(HBufC8*& aParam) const;
	IMPORT_C TInt GetGpsLatitudeRef(HBufC8*& aParam) const;
	IMPORT_C TInt GetGpsLatitude(TInt& aDegNumerator, TInt& aDegDenominator, TInt& aMinNumerator, TInt& aMinDenominator, TInt& aSecNumerator, TInt& aSecDenominator) const;
	IMPORT_C TInt GetGpsLongitudeRef(HBufC8*& aParam) const;
	IMPORT_C TInt GetGpsLongitude(TInt& aDegNumerator, TInt& aDegDenominator, TInt& aMinNumerator, TInt& aMinDenominator, TInt& aSecNumerator, TInt& aSecDenominator) const;
	IMPORT_C TInt GetGpsAltitudeRef(TUint8& aParam) const;
	IMPORT_C TInt GetGpsAltitude(TInt& aNumerator, TInt& aDenominator) const;
	IMPORT_C TInt GetGpsTimeStamp(TInt& aHourNumerator, TInt& aHourDenominator, TInt& aMinNumerator, TInt& aMinDenominator, TInt& aSecNumerator, TInt& aSecDenominator) const;
	IMPORT_C TInt GetGpsSatellites(HBufC8*& aParam) const;
	IMPORT_C TInt GetGpsStatus(HBufC8*& aParam) const;
	IMPORT_C TInt GetGpsMeasureMode(HBufC8*& aParam) const;
	IMPORT_C TInt GetGpsDop(TInt& aNumerator, TInt& aDenominator) const;
	IMPORT_C TInt GetGpsSpeedRef(HBufC8*& aParam) const;
	IMPORT_C TInt GetGpsSpeed(TInt& aNumerator, TInt& aDenominator) const;
	IMPORT_C TInt GetGpsTrackRef(HBufC8*& aParam) const;
	IMPORT_C TInt GetGpsTrack(TInt& aNumerator, TInt& aDenominator) const;
	IMPORT_C TInt GetGpsImgDirectionRef(HBufC8*& aParam) const;
	IMPORT_C TInt GetGpsImgDirection(TInt& aNumerator, TInt& aDenominator) const;
	IMPORT_C TInt GetGpsMapDatum(HBufC8*& aParam) const;
	IMPORT_C TInt GetGpsDestLatitudeRef(HBufC8*& aParam) const;
	IMPORT_C TInt GetGpsDestLatitude(TInt& aDegNumerator, TInt& aDegDenominator, TInt& aMinNumerator, TInt& aMinDenominator, TInt& aSecNumerator, TInt& aSecDenominator) const;
	IMPORT_C TInt GetGpsDestLongitudeRef(HBufC8*& aParam) const;
	IMPORT_C TInt GetGpsDestLongitude(TInt& aDegNumerator, TInt& aDegDenominator, TInt& aMinNumerator, TInt& aMinDenominator, TInt& aSecNumerator, TInt& aSecDenominator) const;
	IMPORT_C TInt GetGpsDestBearingRef(HBufC8*& aParam) const;
	IMPORT_C TInt GetGpsDestBearing(TInt& aNumerator, TInt& aDenominator) const;
	IMPORT_C TInt GetGpsDestDistanceRef(HBufC8*& aParam) const;
	IMPORT_C TInt GetGpsDestDistance(TInt& aNumerator, TInt& aDenominator) const;
	IMPORT_C TInt GetGpsProcessingMethod(HBufC8*& aParam) const;
	IMPORT_C TInt GetGpsAreaInformation(HBufC8*& aParam) const;
	IMPORT_C TInt GetGpsDateStamp(HBufC8*& aParam) const;
	IMPORT_C TInt GetGpsDifferential(TUint16& aParam) const;
private:
	MExifMetadataReader* iExifRead;
	};


/**
@publishedAll
@released

This class offers a friendly interface to write the metadata in exif encoded image files

Note: Unless otherwise stated in a method's documentation, it should be assumed that TInt arguments are representing unsigned quantities, even though TInt is a signed type.
So unless otherwise stated, these parameters should be given unsigned values only.
*/
class TExifWriterUtility
	{	
public:
	// Construction and destruction
	IMPORT_C TExifWriterUtility(MExifMetadataWriter* aExifMetadata);
	
public:
	// Setters
	IMPORT_C TInt SetMake(HBufC8* aMake);
	IMPORT_C TInt SetModel(HBufC8* aModel);
	IMPORT_C TInt SetDateTime(HBufC8* aDateTime);
	IMPORT_C TInt SetDateTimeOriginal(HBufC8* aDateTime);
	IMPORT_C TInt SetDateTimeDigitized(HBufC8* aDateTime);
	IMPORT_C TInt SetInteroperabilityIndex(HBufC8* aIdx);
	IMPORT_C TInt SetInteroperabilityVersion(HBufC8* aIdx);

	IMPORT_C TInt SetExifVersion(HBufC8* aExifVersion);
	IMPORT_C TInt SetComponentsConfiguration(HBufC8* aComponentsConfig);
	IMPORT_C TInt SetFlashPixVersion(HBufC8* aFlashPixVer);

	IMPORT_C TInt SetXResolution(TInt aNumerator, TInt aDenominator);
	IMPORT_C TInt SetYResolution(TInt aNumerator, TInt aDenominator);
	IMPORT_C TInt SetThumbXResolution(TInt aNumerator, TInt aDenominator);
	IMPORT_C TInt SetThumbYResolution(TInt aNumerator, TInt aDenominator);

	IMPORT_C TInt SetResolutionUnit(TInt aResUnit);
	IMPORT_C TInt SetYCbCrPositioning(TInt aPositioning);
	IMPORT_C TInt SetOrientation(TInt aOrientation);
	IMPORT_C TInt SetColorSpace(TInt aColorSpace);
	IMPORT_C TInt SetPixelXDimension(TInt aPixelXDim);
	IMPORT_C TInt SetPixelYDimension(TInt aPixelYDim); 

	IMPORT_C TInt SetThumbCompression(TInt aCompression);
	IMPORT_C TInt SetThumbResolutionUnit(TInt aResUnit);
	IMPORT_C TInt SetThumbOrientation(TInt aOrientation);
	
	IMPORT_C TInt SetImageDescription(HBufC8* aImageDescription);
	IMPORT_C TInt SetCopyright(HBufC8* aCopyright);
	IMPORT_C TInt SetMakerNote(HBufC8* aMakerNote);
	IMPORT_C TInt SetUserComment(HBufC8* aUserComment);
	IMPORT_C TInt SetFlash(TUint16 aFlash);
	IMPORT_C TInt SetFocalLength(TInt aNumerator, TInt aDenominator);
	IMPORT_C TInt SetShutterSpeedValue(TInt aNumerator, TInt aDenominator);
	
	IMPORT_C TInt SetGpsVersionId(HBufC8* aGpsVersionId);
	IMPORT_C TInt SetGpsLatitudeRef(HBufC8* aGpsLatitudeRef);
	IMPORT_C TInt SetGpsLatitude(TInt aDegNumerator, TInt aDegDenominator, TInt aMinNumerator, TInt aMinDenominator, TInt aSecNumerator, TInt aSecDenominator);
	IMPORT_C TInt SetGpsLongitudeRef(HBufC8* aGpsLongitudeRef);
	IMPORT_C TInt SetGpsLongitude(TInt aDegNumerator, TInt aDegDenominator, TInt aMinNumerator, TInt aMinDenominator, TInt aSecNumerator, TInt aSecDenominator);
	IMPORT_C TInt SetGpsAltitudeRef(TUint8 aGpsAltitudeRef);
	IMPORT_C TInt SetGpsAltitude(TInt aNumerator, TInt aDenominator);
	IMPORT_C TInt SetGpsTimeStamp(TInt aHourNumerator, TInt aHourDenominator, TInt aMinNumerator, TInt aMinDenominator, TInt aSecNumerator, TInt aSecDenominator);
	IMPORT_C TInt SetGpsSatellites(HBufC8* aGpsSatellites);
	IMPORT_C TInt SetGpsStatus(HBufC8* aGpsStatus);
	IMPORT_C TInt SetGpsMeasureMode(HBufC8* aGpsMeasureMode);
	IMPORT_C TInt SetGpsDop(TInt aNumerator, TInt aDenominator);
	IMPORT_C TInt SetGpsSpeedRef(HBufC8* aGpsSpeedRef);
	IMPORT_C TInt SetGpsSpeed(TInt aNumerator, TInt aDenominator);
	IMPORT_C TInt SetGpsTrackRef(HBufC8* aGpsTrackRef);
	IMPORT_C TInt SetGpsTrack(TInt aNumerator, TInt aDenominator);
	IMPORT_C TInt SetGpsImgDirectionRef(HBufC8* aGpsImgDirectionRef);
	IMPORT_C TInt SetGpsImgDirection(TInt aNumerator, TInt aDenominator);
	IMPORT_C TInt SetGpsMapDatum(HBufC8* aGpsMapDatum);
	IMPORT_C TInt SetGpsDestLatitudeRef(HBufC8* aGpsDestLatitudeRef);
	IMPORT_C TInt SetGpsDestLatitude(TInt aDegNumerator, TInt aDegDenominator, TInt aMinNumerator, TInt aMinDenominator, TInt aSecNumerator, TInt aSecDenominator);
	IMPORT_C TInt SetGpsDestLongitudeRef(HBufC8* aGpsDestLongitudeRef);
	IMPORT_C TInt SetGpsDestLongitude(TInt aDegNumerator, TInt aDegDenominator, TInt aMinNumerator, TInt aMinDenominator, TInt aSecNumerator, TInt aSecDenominator);
	IMPORT_C TInt SetGpsDestBearingRef(HBufC8* aGpsDestBearingRef);
	IMPORT_C TInt SetGpsDestBearing(TInt aNumerator, TInt aDenominator);
	IMPORT_C TInt SetGpsDestDistanceRef(HBufC8* aGpsDestDistanceRef);
	IMPORT_C TInt SetGpsDestDistance(TInt aNumerator, TInt aDenominator);
	IMPORT_C TInt SetGpsProcessingMethod(HBufC8* aGpsProcessingMethod);
	IMPORT_C TInt SetGpsAreaInformation(HBufC8* aGpsAreaInformation);
	IMPORT_C TInt SetGpsDateStamp(HBufC8* aDateStamp);
	IMPORT_C TInt SetGpsDifferential(TUint16 aGpsDifferential);

private: // Member
	
	MExifMetadataWriter* iExifWrite;
	
	};


#endif	// __EXIFUTILITY_H__
