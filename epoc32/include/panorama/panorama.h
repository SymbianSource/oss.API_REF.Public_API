// Copyright (c) 2008-2009 Nokia Corporation and/or its subsidiary(-ies).
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

/**
 @file
 @publishedAll
 @released
*/

#ifndef PANORAMA_H
#define PANORAMA_H

#include <icl/imagecodecdata.h>

const TInt KPanoramaDefaultOverlap = 63; //Default overlap value in percent.
const TInt KPanoramaDefaultDirectionTrigger = 10; //Default direction value in percent.
const TInt KPanLensIndex = 2; //Focal length and principal point index value
const TInt KPanLensDist = 5; //Distortion index value

//fwd ref
class CImagePanoramaImpl;
class CVFTrackerImpl;
class CPanoramaTransformImpl;
class CImageFrame;

/**
Defines the direction
*/
enum TDirection
	{
	EPanoramaDirectionUnknown = 0,
	EPanoramaDirectionRight,
	EPanoramaDirectionLeft,
	EPanoramaDirectionUp,
	EPanoramaDirectionDown
	};
	
/**
This class provides the lens parameters that describe the internal camera characteristics.
*/
class TPanoramaLens
	{
public:
	IMPORT_C TPanoramaLens();
	IMPORT_C TPanoramaLens(TReal32* aFocalLength, TReal32* aPrincipalPoint, TReal32 aSkew, TReal32* aDist, TUint32 aWidth, TUint32 aHeight);
	
public:
	TReal32 iFocalLength[KPanLensIndex]; //Focal length coordinates
	TReal32 iPrincipalPoint[KPanLensIndex]; //Principal point coordinates
	TReal32 iSkew; //Skew coefficient. @remark 0.0f means no skew
	TReal32 iDist[KPanLensDist];// Distortion coefficients. If there are fewer parameter values available, fill the last values with zeros
	TUint32 iWidth; // Image width when the camera was calibrated
	TUint32 iHeight; // Image height when the camera was calibrated

private:	
	// Future proof
	TAny* iPad1;
	TAny* iPad2;
	TAny* iPad3;
	TAny* iPad4;
	};

/**
This class provides help functions for handling the result of the viewfinder tracking.
It contains getters and setters.
*/
class CPanoramaTransform : public CBase
	{
public:
	IMPORT_C static CPanoramaTransform* NewL();
	
	IMPORT_C void GetTranslation(TPoint& aDxDy, TSize& aDims) const;
	IMPORT_C void SetTranslationL(const TPoint& aDxDy, const TSize& aDims);
	IMPORT_C void GetDirection(TDirection& aDirection);
	IMPORT_C void GetDirection(TDirection& aDirection, TInt& aMinimumDelta);
	IMPORT_C void SetDirection(TDirection& aDirection);
	IMPORT_C void SetDirection(TDirection& aDirection, TInt aMinDelta);
	
	IMPORT_C ~CPanoramaTransform();
	
private:
	CPanoramaTransform();
	void ConstructL();
	
private:
	CPanoramaTransformImpl* iPanTransImpl;
	};

/**
This class provides functions to register the image that has got from viewfinder
and checks the appropriate time to capture that image.
*/
class CVFTracker : public CBase
	{
public:
	IMPORT_C static CVFTracker* NewL();
	
	IMPORT_C void RegisterImageL(const CFbsBitmap& aBitmap, CPanoramaTransform& aPanTrans);
	IMPORT_C void RegisterImageL(const CImageFrame& aImageFrame, CPanoramaTransform& aPanTrans);
	IMPORT_C TBool IsTimeToCapture(TDirection& aDirection) const;
	IMPORT_C TBool IsTimeToCapture(TDirection& aDirection, TInt aOverlap) const;
	IMPORT_C void Reset();
	IMPORT_C void InitializeL(const TSize& aSize);		

	IMPORT_C TAny* Extension(TUid aExtension);
	
	IMPORT_C ~CVFTracker();

private:
	CVFTracker();
	void ConstructL();

private:
	CVFTrackerImpl* iVFTrackImpl;
	};
	
/**
This class provides functions to get basic stitching. Input can be a file,
descriptor, bitmap, imageframe.
*/
class CImagePanorama : public CBase
	{
public:
	IMPORT_C static CImagePanorama* NewL();
	
	IMPORT_C void AddFileL(const TDesC& aFilename, CPanoramaTransform& aPanTrans);
	IMPORT_C void AddBufferL(const TDesC8& aData, CPanoramaTransform& aPanTrans);
	IMPORT_C void AddImageL(const CFbsBitmap& aBitmap, CPanoramaTransform& aPanTrans);
	IMPORT_C void AddImageL(const CImageFrame& aImageFrame, CPanoramaTransform& aPanTrans);

	IMPORT_C void CurrentImageSizeL(TSize& aSize);
	
	IMPORT_C void RenderL(const TDesC& aFilename); 
	IMPORT_C void RenderL(const TDesC& aFilename, const TSize& aSize, const TBool aMaintainAspectRatio, const TUid& aImageTypeUid); 

	IMPORT_C void RenderL(RFile& aFile); 
	IMPORT_C void RenderL(RFile& aFile, const TSize& aSize, const TBool aMaintainAspectRatio, const TUid& aImageTypeUid);
	
	IMPORT_C void RenderL(HBufC8*& aDestData);
	IMPORT_C void RenderL(HBufC8*& aDestData, TUint32 aMaxBufferSize, const TSize& aSize, const TBool aMaintainAspectRatio, const TUid& aImageTypeUid);
	
	IMPORT_C void RenderL(const CFbsBitmap& aBitmap);
	IMPORT_C void RenderL(const CFbsBitmap& aBitmap, const TBool aMaintainAspectRatio);
	
	IMPORT_C void RenderL(const CImageFrame& aImageFrame);
	IMPORT_C void RenderL(const CImageFrame& aImageFrame, const TBool aMaintainAspectRatio);
	
	IMPORT_C void InitializeL(const TSize & aSize, const TPanoramaLens& aPanoramaLens, const TDirection& aDirection);
	
	IMPORT_C TAny* Extension(TUid aExtension);
	
	IMPORT_C ~CImagePanorama();
	
private:
	CImagePanorama();
	void ConstructL();

private:
	CImagePanoramaImpl* iImgPanImpl;
	};
	
#endif //PANORAMA_H
