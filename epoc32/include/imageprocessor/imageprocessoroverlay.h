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

#ifndef __IMAGE_PROCESSOR_OVERLAY_H__
#define __IMAGE_PROCESSOR_OVERLAY_H__

#include <e32base.h>
#include <gdi.h>

class CFbsBitmap;
class CImageFrame;
class RFile;
class TMMSource;

namespace ImageProcessor
	{

class CImageProcessorImpl;
class CImageProcessorDrmInput;
	
namespace Plugin
	{
	class MOverlay;
	}

/**
This class provides image overlay functionality.

Before overlay effects are applied, SetInputL should be called to specify the input overlay image.

The overlay effect can be applied by:

-# Begin overlay by calling BeginL(). 
-# Adjust overlay parameters (optional) by calling SetL(aSize, aPosition, aAngle), possibly several times.
-# Signal final placement of overlay by calling EndL(). 
	.

Between step 1 and 3, no other effects or operations may be carried out i.e. the overlay has to be 
concluded/ended before proceeding to apply other effects.

@publishedAll
@released
*/
class TOverlay
	{
public:
	IMPORT_C void SupportedInputFormatsL(RArray<TUid>& aFormats) const;
	IMPORT_C void SupportedInputSubFormatsL(TUid aFormat, RArray<TUid>& aSubFormats) const;
	IMPORT_C void SupportedInputImageFrameFormatsL(RArray<TUid>& aFormats) const;
	IMPORT_C void SupportedInputDisplayModesL(RArray<TDisplayMode>& aDisplayModes) const;
	
	IMPORT_C void SetInputL(const TDesC& aFilename, const TUid& aFormat = KNullUid, const TUid& aSubFormat = KNullUid);
	IMPORT_C void SetInputL(RFile& aFile, const TUid& aFormat = KNullUid, const TUid& aSubFormat = KNullUid);
	IMPORT_C void SetInputL(TMMSource& aDrmFile, const TUid& aFormat = KNullUid, const TUid& aSubFormat = KNullUid);
	IMPORT_C void SetInputL(const TDesC8& aBuffer, const TUid& aFormat = KNullUid, const TUid& aSubFormat = KNullUid);
	IMPORT_C void SetInputL(const CFbsBitmap& aBitmap, const CFbsBitmap* aMask = NULL);
	IMPORT_C void SetInputL(const CImageFrame& aPixelBuffer);

	IMPORT_C void BeginL();
	IMPORT_C void SetL(const TSize &aSize, const TPoint &aPosition = TPoint(0,0), TReal32 aAngle = 0);
	IMPORT_C void SetL(TReal32 aScaleX = 1.0, TReal32 aScaleY = 1.0, const TPoint &aPosition = TPoint(0,0), TReal32 aAngle = 0);
	IMPORT_C void EndL();
	IMPORT_C void ResetL();
	
	IMPORT_C TPoint	PositionL() const;
	IMPORT_C TSize	SizeL() const;
	IMPORT_C TReal32 AngleL() const;
	IMPORT_C void GetScaleL(TReal32& aScaleX, TReal32& aScaleY) const;
		
private:
	friend class CImageProcessorImpl;
	TOverlay(Plugin::MOverlay& aOverlayImpl, CImageProcessorImpl& aImageProcessorImpl);
	
	TBool iIsActive;
	TBool iIsInputSet;

	CImageProcessorImpl& iImageProcessorImpl;
	Plugin::MOverlay& iOverlayImpl;
	TInt iReserved; // future proof
	};

	}

#endif //__IMAGE_PROCESSOR_PREVIEW_H__
