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

#ifndef __IMAGE_PROCESSOR_PREVIEW_H__
#define __IMAGE_PROCESSOR_PREVIEW_H__

#include <e32base.h>
#include <gdi.h>
#include <imageframe.h>

class CFbsBitmap;
class CImageFrame;

namespace ImageProcessor
	{

class CImageProcessorImpl;

namespace Plugin
	{
	class MPreview;
	}

/**
A preview representation of the rendered image after effects and geometric operations have been applied. Has the ability to zoom and pan the output image in the 
supplied pixel buffer. Typically this is a low resolution representation of the image which allows effects and operations
to be applied quickly to the image without needing to process the whole image.

@publishedAll
@released
*/
class TPreview
	{
public:
	/**
	The state of the preview screen
	*/
	enum TState 
		{
		/** State means the preview has not been initialized, need to call InitializeL() to initialize*/
		EUninitialized,
		/** State means the preview is being initialized by async call of InitializeL()*/
		EInitializing,
		/** State means the initialize process has finished and preview is available to be rendered*/
		EInitialized,
		/** State means the preview is being rendered by async call of RenderL()*/
		ERendering,

        /** Count of valid preview states (boundary marker - not a true state). */
		EStatesCount
		};

public:
	IMPORT_C void SupportedImageFrameFormatsL(RArray<TUid>& aFormats) const;
	IMPORT_C void SupportedOutputDisplayModesL(RArray<TDisplayMode>& aDisplayModes) const;
	
	IMPORT_C void SetOutputL(CFbsBitmap& aBitmap);
	IMPORT_C void SetOutputL(CImageFrame& aPixelBuffer);
	
	IMPORT_C CImageFrame* CreateOutputL(const TSize &aFrameSize, const TFrameFormatBase &aFrameFormat, const TFrameLayoutBase &aFrameLayout);

	IMPORT_C void InitializeL();
	IMPORT_C void UninitializeL();

	IMPORT_C void RenderL();
	IMPORT_C void ResetL();
	IMPORT_C void Cancel();
		
	IMPORT_C void SetZoomL(TReal32 aZoom);
	IMPORT_C void SetPanL(TReal32 aPanX, TReal32 aPanY);
	IMPORT_C void SetPreviewId(TInt aPreviewId);
	IMPORT_C void GetZoomLevelSettings(TReal32& aMinimumLevel, TReal32& aMaximumLevel);
	IMPORT_C void GetPanLevelSettings(TReal32& aMinimumLevel, TReal32& aMaximumLevel);
		
	IMPORT_C TReal32 ZoomL() const;
	IMPORT_C void PanL(TReal32& aPanX, TReal32& aPanY) const;
	IMPORT_C TSize SizeL() const;
	IMPORT_C TRect CanvasAreaL() const;
	IMPORT_C TInt PreviewId() const;
	
	IMPORT_C void PreviewToCurrentCoordL(const TPoint& aPreviewPoint, TPoint& aCurrentPoint) const;
	IMPORT_C void CanvasToCurrentCoordL(const TPoint& aCanvasPoint, TPoint& aCurrentPoint) const;

	IMPORT_C TPreview::TState State() const;

private:
	friend class CImageProcessorImpl;
	CImageProcessorImpl& iImageProcessorImpl;
	TPreview(Plugin::MPreview& aPreviewImpl, CImageProcessorImpl& aImageProcessorImpl);

	void SetStateL(TPreview::TState aState);

	static const TBool iValidStates[TPreview::EStatesCount][TPreview::EStatesCount];
	Plugin::MPreview& iPreviewImpl;
	
	TPreview::TState iState;
	TBool iIsOutputSet;
	TInt iReserved; // future proof
	};

	} //namespace ImageProcessor

#endif //__IMAGE_PROCESSOR_PREVIEW_H__
