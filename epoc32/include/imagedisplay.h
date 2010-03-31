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
// This is the public client API for the Image Display Library
// 
//

#ifndef __IMAGEDISPLAY_H__
#define __IMAGEDISPLAY_H__
	
#include <fbs.h>
#include <mm/mmcaf.h>

// fwd refs
class CImageDisplayFramework;
/**
Uid value for the TDescriptorDataSource data source
*/
const TInt KUidDescDataSourceValue=0x10207087;
/**
Uid for the TDescriptorDataSource data source
*/
const TUid KUidDescDataSource={KUidDescDataSourceValue};

/**
	Descriptor-based image datasource.
	
	@publishedAll
	@released
*/
class TDescriptorDataSource: public TMMSource
	{
public:
	IMPORT_C TDescriptorDataSource(const TPtrC8& aData);
	IMPORT_C const TPtrC8& DataBuf() const;
   
private:
	TPtrC8   iData;
	};


/**
	Observer class for image display.
	
	@publishedAll
	@released
*/
class MIclImageDisplayObserver
	{
public:
	/**	
		Called when the image is ready to display 
	    A plug-in should use this function to pass information asynchronously to an API client. This function is asynchronous.
	@param aBitmap
				a pointer to the bitmap that contains decoding result (may be NULL on error condition)

	@param aStatus
				the plugin status that should be combination of the TPluginStatus set

	@param aUpdatedArea
				a rectangle within the aBitmap that was updated during the latest operation

	@param aError
				error code of latest operation

	*/
	virtual void MiidoImageReady(const CFbsBitmap* aBitmap, TUint aStatus, const TRect& aUpdatedArea, TInt aError) = 0;
	};


/**
The public API for clients to call the Image Display library.
This class provides functions to convert images stored in descriptors or
files to bitmaps ready for display.

@publishedAll
@released
*/
class CImageDisplay : public CBase
	{
public:

	/**
	Flags to control how the image is handled
	These can be combined using an OR operation.
	Note that the rotate and mirror options have
	to be set together with EOptionThumbnail or 
	EOptionMainImage.
	*/
	enum TImageOptions
		{
		/** No options defined */
		EOptionsUndefined		= 0x00000000,
		/** Use the thumbnail image as source */
		EOptionThumbnail		= 0x00000001,
		/** Use the main image as source */
		EOptionMainImage		= 0x00000002,
		/** Rotate the image by 90 degrees clockwise */
		EOptionRotateCw90		= 0x00000004,
		/** Rotate the image by 180 degrees clockwise */
		EOptionRotateCw180		= 0x00000008,
		/** Rotate the image by 270 degrees clockwise */
		EOptionRotateCw270		= 0x00000010,
		/** Mirror an image about the horizontal axis */
		EOptionMirrorHorizontal = 0x00000020,
		/** Mirror an image about the vertical axis */
		EOptionMirrorVertical	= 0x00000040,
		/** Rotate the image automatically (if necessary) */
		EOptionAutoRotate		= 0x00000080
		};

	/**
	Return flags from ImageStatus()
	*/
	enum TImageStatus
		{
		/** ImageStatus is unknown */
		EImageTypeUnknown	= 0x00000000,	
		/** Image is single frame */
		EImageSingleFrame	= 0x00000001,	
		/** Image is multiframe */
		EImageMultiFrame	= 0x00000002,
		/** Image is animated */
		EImageAnimated		= 0x00000004,
		/** Image has got a mask/alpha channel */
		EImageMasked		= 0x00000008,
		/** Image has got a thumbnail */
		EImageHasThumbnail	= 0x00000010,
		/** Image is fully scalable i.e. arbitrary scaling can be perofmed quite quickly */
		EImageIsFullyScalable= 0x00000020
		};
	
	/**
	An array containing the sizes of images.
	*/
	typedef RArray<TSize> RImageSizeArray;

public:
	IMPORT_C static CImageDisplay* NewL(MIclImageDisplayObserver& aCallback, RFs& aFs);
	IMPORT_C ~CImageDisplay();
	IMPORT_C void SetPluginUid(TUid aPluginUid);
	IMPORT_C TInt SetImageSource(const TMMSource& aSource);
	
	IMPORT_C void SetSourceMimeType(const TDesC8& aMIMEType);
	IMPORT_C void SetSourceImageType(TUid aImageType, TUid aImageSubType = KNullUid);	

	IMPORT_C void SetSourceRect(const TRect& aRect);
	IMPORT_C void ResetSourceRect();
	
	IMPORT_C void SetSizeInPixels(const TSize& aSize, TBool aMaintainAspectRatio = ETrue);
	IMPORT_C void SetDisplayMode(TDisplayMode aDisplayMode);

	IMPORT_C TInt SetOptions(TUint aOptions);

	IMPORT_C void SetupL();	

	IMPORT_C void Play();
	IMPORT_C void Pause();
	IMPORT_C void StopPlay();
	IMPORT_C void Reset();

	// getters
	IMPORT_C TInt ExtensionInterface(TUid aIFaceUid, TAny*& aIFacePtr);
	IMPORT_C TBool ValidBitmap() const;
	IMPORT_C const RImageSizeArray& RecommendedImageSizes() const;
	IMPORT_C void GetBitmap(const CFbsBitmap*& aBitmap, const CFbsBitmap*& aMask) const;
	IMPORT_C TUint ImageStatus() const;
	IMPORT_C TInt NumFrames(TInt& aNumFrames) const;

private:
	CImageDisplay();
	void ConstructL(MIclImageDisplayObserver& aCallback, RFs& aFs);

private:
	CImageDisplayFramework* iBody;
	};

#endif // __IMAGEDISPLAY_H__
