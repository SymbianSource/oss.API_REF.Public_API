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
// This is the public client API for the Image Processor Library
// 
//

/**
 @file
 @publishedAll 
 @released 
*/

#ifndef __IMAGE_PROCESSOR_H__
#define __IMAGE_PROCESSOR_H__

#include <e32base.h>
#include <gdi.h>
#include <icl/imagecodecdata.h>

class RFs;
class RFile;
class TMMSource;
class CFbsBitmap;
class CImageFrame;
class TSize;
class TRgb;
class CImagePanorama;

/**
@publishedAll 
@released
Image processor namespace for image manipulation and processing.
*/
namespace ImageProcessor
	{
	class MImgProcessorObserver;
	class CImageProcessorImpl;
	
	class TEffect;
	class TPreview;
	class TOverlay;
	class TProgressInfo;
	class TInputInfo;
	class TOutputInfo;

/**
@publishedAll 
@released

This class provides functions to process images. Those operations can be divided in two groups:
- effects.
- geometrical operations.

Good examples of effects could be the Sepia effect applying shades of brown to an image, or the solarize effect 
that consists in reversing the tones of a picture and make it look like a negative.
Good examples of geometrical operations could be Rotation or Flip.

The image processor will decode and render an image:

Inputs can be
- compressed images (JPEG, GIF, PNG etc)
- uncompressed images (CFbsBitmap and general pixel buffers e.g. YUV 4:2:0 Interleaved etc)

Outputs can be 
- compressed images (JPEG, GIF, PNG etc)
- uncompressed images (CFbsBitmap and general pixel buffers e.g. YUV 4:2:0 Interleaved etc)

An intermediate generally low resolution uncompressed image providing a preview representation of the 
output of the processing is provided allowing applications to display the results of the operations 
applied without needing to fully render the image. Multiple previews are allowed.

Images may be overlaid onto the main source image.

The source image can be changed and the current effects and geometric oprations will be re-applied to the
new image. The previews will be updated.
*/
class CImgProcessor : public CBase
	{
public:   
	/**
	Flags to control how the image is processed.
	*/
	enum TOptions
		{
		/** No flag set 
		*/
		EOptionNone = 0x00,
		/** Effects, geometric operations and rendering are applied synchronously. 
		The default is asynchronously.
		*/
		EOptionSyncProcessing = 0x01,
		/** The Exif data from the source image is parsed and transferred to the 
		destination image.
        */
		EOptionExifMetadataProcessing = 0x02
		};

	/**
	Flags to control the operations or transforms on an image.
	*/
	enum TOperation
		{
		/** No operation.
		*/
		EOperationNone = 0x0,

        /** Rotate 90 degrees clockwise.
        */
        EOperationRotate90 = 0x1,

        /** Rotate 180 degrees clockwise.
        */
        EOperationRotate180 = 0x2,

        /** Rotate 270 degrees clockwise.
        */
        EOperationRotate270 = 0x4,

        /** Horizontal flip (mirror over horizontal axis).
        */
        EOperationMirrorHorizontalAxis = 0x8,

        /** Horizontal flip (mirror over horizontal axis) then rotate 90 degrees clockwise.
        */
        EOperationMirrorHorizontalAxisRotate90 = 0x10,

        /** Vertical flip (mirror over vertical axis).
        */
        EOperationMirrorVerticalAxis     = 0x20,

        /** Vertical flip (mirror over vertical axis) then rotate 90 degrees clockwise.
        */
        EOperationMirrorVerticalAxisRotate90 = 0x40
		};
      
	/**
	Possible states for the image processor. 
	*/
	enum TState
		{
        /** Image processor not initalized.
        */
		EUninitialized = 0,
        /** Image processor initalizing.
        */
		EInitializing,
        /** Image processor initalized.
        */
		EInitialized,
        /** Effect active.
        */
		EEffectActive,
        /** Image processor processing an image.
        */
		EProcessing,
        /** Preview initializing.
        */
		EPreviewInitializing,
        /** Preview Rendering.
        */
		EPreviewRendering,
        /** Count of valid states (boundary marker - not a true state).
        */
		EStatesCount
		};

	/**
	Events occurring during processing. 
	*/
	enum TEvent
		{
        /** The image processor is initializing.
        */
		EEventInitializing = 0, 
        /** The image processor has finished initializing.
        */
		EEventInitializingComplete,
        /** Processing is in progress.
        */
		EEventProcessing,	
        /** Processing is complete.
        */
		EEventProcessingComplete,
        /** Rendering is in progress.
        */
		EEventRendering,
        /** Event rendering is complete.
        */
		EEventRenderingComplete,
        /** The preview is initializing.
        */
		EEventPreviewInitializing,
        /** The preview has finished initializing.
        */
		EEventPreviewInitializingComplete,
        /** The preview rendering is in progress.
        */
		EEventPreviewRendering,
        /** The preview rendering is complete.
        */
		EEventPreviewRenderingComplete
		};
   
public:   
	IMPORT_C static CImgProcessor* NewL(RFs& aFileServerSession, MImgProcessorObserver& aObserver, TUid aImageProcessorPluginUid=KNullUid);
	
	IMPORT_C void SupportedEffectsL(RArray<TUid>& aEffects) const;
	
	IMPORT_C void SupportedInputFormatsL(RArray<TUid>& aFormats) const;
	IMPORT_C void SupportedInputSubFormatsL(TUid aFormat, RArray<TUid>& aSubFormats) const;
	IMPORT_C void SupportedInputImageFrameFormatsL(RArray<TUid>& aFormats) const;
	IMPORT_C void SupportedInputDisplayModesL(RArray<TDisplayMode>& aDisplayModes) const;
	
	IMPORT_C void SupportedOutputFormatsL(RArray<TUid>& aFormats) const;
	IMPORT_C void SupportedOutputSubFormatsL(TUid aFormat, RArray<TUid>& aSubFormats) const;
	IMPORT_C void SupportedOutputImageFrameFormatsL(RArray<TUid>& aFormats) const;
	IMPORT_C void SupportedOutputDisplayModesL(RArray<TDisplayMode>& aDisplayModes) const;

	IMPORT_C TUint64 SupportedOptions() const;
	IMPORT_C TUint SupportedOperations() const;

	IMPORT_C TUint64 Options() const;
	IMPORT_C TState State() const;
	IMPORT_C TSize CurrentSizeL() const;
	IMPORT_C TRgb BackgroundColorL() const;

	IMPORT_C TProgressInfo* ProgressInfoL();
	IMPORT_C TInputInfo* InputInfoL();
	IMPORT_C TOutputInfo* OutputInfoL();
	
	IMPORT_C TInt CalculatePixelBufferSizeL(TSize aSizeInPixels, TDisplayMode aDisplayMode, TUint32 aScanLineLength = 0) const;
	IMPORT_C TInt CalculatePixelBufferSizeL(TSize aSizeInPixels, const TUid& aFormat, TUint32 aScanLineLength = 0) const;

	IMPORT_C void CreateInputL(CFbsBitmap& aBitmap);
	IMPORT_C void CreateInputL(CImageFrame& aPixelBuffer);
	IMPORT_C void CreateInputL(const TSize& aSize, const TRgb& aColor);

	IMPORT_C void SetBackgroundColorL(const TRgb& aColor);
	
	IMPORT_C void SetInputRectL(const TRect& aRect);
	
	IMPORT_C void SetInputL(const TDesC& aFilename, const TUid& aFormat = KNullUid, const TUid& aSubFormat = KNullUid);
	IMPORT_C void SetInputL(RFile& aFile, const TUid& aFormat = KNullUid, const TUid& aSubFormat = KNullUid);
	IMPORT_C void SetInputL(TMMSource& aDrmFile, const TUid& aFormat = KNullUid, const TUid& aSubFormat = KNullUid);
	IMPORT_C void SetInputL(const TDesC8& aBuffer, const TUid& aFormat = KNullUid, const TUid& aSubFormat = KNullUid);
	IMPORT_C void SetInputL(const CFbsBitmap& aBitmap, const CFbsBitmap* aMask = NULL);
	IMPORT_C void SetInputL(const CImageFrame& aPixelBuffer);
	IMPORT_C void SetInputL(CImagePanorama& aPanorama);

	IMPORT_C void SetOptionsL(TUint64 aOptions);
	IMPORT_C void ApplyOperationL(CImgProcessor::TOperation aOperation);

	IMPORT_C void InputUpdatedL();
	
	IMPORT_C void ResetL();

	IMPORT_C void InitializeL();
	IMPORT_C void InitializeL(TUint64 aOptions);
   
	IMPORT_C void ProcessL();
	IMPORT_C void ProcessL(const TSize& aSize, TBool aMaintainAspectRatio);
	IMPORT_C void Cancel();

	IMPORT_C TEffect* EffectL(TUid aEffect);

	IMPORT_C TBool CanUndoL() const;
	IMPORT_C void UndoL();
	IMPORT_C void UndoAllL();
	
	IMPORT_C TBool CanRedoL() const;
	IMPORT_C void RedoL();
	IMPORT_C void RedoAllL();

	IMPORT_C TPreview* PreviewL(TInt aPreviewId);

	IMPORT_C TOverlay* OverlayL();
	
	IMPORT_C void SetOutputL(const TDesC& aFilename, const TUid& aFormat = KImageTypeJPGUid, const TUid& aSubFormat = KNullUid);
	IMPORT_C void SetOutputL(RFile& aFile, const TUid& aFormat = KImageTypeJPGUid, const TUid& aSubFormat = KNullUid);
	IMPORT_C void SetOutputL(RBuf8& aBuffer, const TUid& aFormat = KImageTypeJPGUid, const TUid& aSubFormat = KNullUid);
	IMPORT_C void SetOutputL(CImageFrame& aPixelBuffer);
	IMPORT_C void SetOutputL(CFbsBitmap& aBitmap, CFbsBitmap* aMask = NULL);

	IMPORT_C TAny* Extension(TUid aExtension);

	// framework utility functions
	IMPORT_C void ConvertMimeTypeToUidL(const TDesC8& aMimeType, TUid& aFormat, TUid& aSubFormat) const;
	IMPORT_C void ConvertFileExtensionToUidL(const TDesC& aFileExtension, TUid& aFormat, TUid& aSubFormat) const;
	IMPORT_C void ConvertUidToMimeTypeL(TDes8& aMimeType, const TUid& aFormat, const TUid& aSubFormat) const;
	IMPORT_C void ConvertUidToFileExtensionL(TDes& aFileExtension, const TUid& aFormat, const TUid& aSubFormat) const;

	IMPORT_C ~CImgProcessor();

private:
	CImgProcessor();
	void ConstructL(RFs& aFileServerSession,MImgProcessorObserver& aObserver, TUid aPluginUid);

private:
	CImageProcessorImpl* iImplementation;
	};

	} // ImageProcessor

#endif //__IMAGE_PROCESSOR_H__
