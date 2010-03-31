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
// This is the plugin API for the Image Display framework
// 
//

#ifndef __IMAGEDISPLAYPLUGIN_H__
#define __IMAGEDISPLAYPLUGIN_H__

#include <imagedisplay.h>
#include <icl/imagedisplaypluginext.h>

// fwd ref
class CImageDisplayFramework;
class CImageDisplayPluginBody;

/**
This is the plugin API for the Image Display framework
Intended for use by plugin writers only.

@publishedAll
@released
*/
class CImageDisplayPlugin : public CBase
	{
	friend class CImageDisplayFramework;
	friend class CImageDisplayPluginBody;

public:
	/**
	Data source type definitions for plug-ins
	*/
	enum TImageSourceType 
		{
		/** Undefined. Plug-in won't be given this value */
		EImgSrcNotDefined	=0,
		/** The datasource is a file name */
		EImgSrcFileName,
		/** The datasource is a file handle */
		EImgSrcFileHandle,
		/** The datasource is a descriptor */
		EImgSrcDescriptor,
		};

	/**
	Defines an ImageDisplay plug-in status flag values
	*/
	enum TPluginStatus
		{
		/** A plug-in has nothing more to decode; also must be set also on fatal error contidition */
		EStatusNoMoreToDecode				=0x00000001,
		/** The next frame is not ready yet, bitmap may contain distorted image */
		EStatusBusy							=0x00000002,
		/** Image decoding is paused i.e. call Play() to continue (if EStatusNoMoreToDecode is not set) */
		EStatusPaused						=0x00000004,
		/** The next frame has been already decoded*/
		EStatusFrameReady					=0x00000008,
		/** May be set after image decode completion i.e. when EStatusNoMoreToDecode is set */
		EStatusDisplayThisFrameIndefinetely	=0x00000010,
		/** May be set if the image format supports progressive decoding; indicates that a bitmap contains roughtly decoded image */
		EStatusPartialFrame                	=0x00000020,
		/** May be set in case when a plug-in asks to invalidate previous frame contents */
		EStatusEraseOutputContents         	=0x00000040,
		};
	/**
		Virtual destructor. Current implementation will call the REComSession::DestroyedImplementation() to finalize destruction
		of the ECom plugin
	*/
	IMPORT_C ~CImageDisplayPlugin();

protected:
	/**
	Initialise the plugin and check the image display settings.

	This is called by the ImageDisplay framework when the client app calls
	CImageDisplay::SetupL(). 
	
	The plugin should check the validity of the source image and all other settings
	set by the client API. If any of these is unsupported then it should leave with 
	KErrArgument

	A plugin implementing CImageDisplayPluginExtension to allow extension of the 
	client API should initialise it here.

	This is a virtual function that each individual plugin must implement.

	@leave  KErrArgument
	Some of the configuration parameters are invalid
	*/
	virtual void OpenL() = 0;

	/**
	Initiate the image display operation

	This is a virtual function that each individual plugin must implement.

	*/
	virtual void Play() = 0;

	/**
	Pause image decoding

	This is a virtual function that each individual plugin must implement.
	*/
	virtual void Pause() = 0;

	/**
	Cancel the image display operation
	May be called by the framework even when there is no outstanding request.

	This is a virtual function that each individual plugin must implement.
	*/
	virtual void StopPlay() = 0;

	/**
	Should return an array of recommended image sizes i.e. sizes which would be processed faster 
	@return a reference to the array of recommended image sizes

	This is a virtual function that each individual plugin must implement.
	*/	
	virtual const CImageDisplay::RImageSizeArray& RecommendedImageSizes() const=0;
	
	/**
		Exported default constructor
	*/
	IMPORT_C CImageDisplayPlugin();

	// getters
	/**
	   returns an image datasource type
	   @return TImageSourceType 
	*/
	IMPORT_C TImageSourceType SourceType() const;
	/**
	   returns an image source file name
	   @return const TDesC& a reference to read-only descriptor
	   @panic ImageDisplay 4 EImageWrongType if image data source is of type other than the file name
	*/
	IMPORT_C const TDesC& SourceFilename() const;
	/**
	   returns an image source file handle
	   @return const RFile& a reference to a file handle 
	   @panic ImageDisplay 4 EImageWrongType if image data source is of type other than the file handle
	*/
	IMPORT_C RFile& SourceFileHandle() const;
	/**
	   returns an image source descriptor
	   @return const TDesC8& a reference to a 8 bit descriptor
	   @panic ImageDisplay 4 EImageWrongType if image data source is of type other than the descriptor
	*/
	IMPORT_C const TDesC8& SourceData() const;

	/**
	   returns an intent that is requested by client for opening the image source
	   @return ContentAccess::TIntent a desired intent value
	*/
	IMPORT_C ContentAccess::TIntent SourceDataIntent() const;

	/**
	   returns requested content data Id that should be used to open content
	   @return const TDesC& a desired data unique Id
	*/
	IMPORT_C const TDesC& SourceDataId() const;

	/**
	   returns an image source MIME type or KNullDesC8 if not defined
	   @return const TDesC8& a reference to a 8 bit descriptor
	*/
	IMPORT_C const TDesC8& SourceMimeType() const;
	/**
	   returns a global image type 
	   @return const TUid an image type Uid
	*/
	IMPORT_C const TUid SourceImageType() const;
	/**
	   returns a global image subtype or KNullUid if not defined
	   @return const TUid an image subtype Uid
	*/
	IMPORT_C const TUid SourceImageSubType() const;
	/**
	   returns a requested by an API client source clipping rect
	   @param aRect a reference to source clipping rect which is valid only if return value is ETrue
	   @return ETrue if clipping rect was defined by client
	*/
	IMPORT_C TBool SourceRect(TRect& aRect) const;
	/**
	   returns a requested by an API client destination image size
	   @return const TSize - requested image size in pixels
	*/
	IMPORT_C const TSize& DestinationSizeInPixels() const;
	/**
	   returns a requested by an API client image options e.g. combination of the TImageOptions
	   @return TUint - requested image option set
	*/
	IMPORT_C TUint Options() const;
	/**
	   returns ETrue if an API client requested to preserve source image aspect ratio
	   @return TBool - requested aspect ratio flag 
	*/
	IMPORT_C TBool MaintainAspectRatio() const;
	/**
	   returns a requested by an API client display mode for an image being decoded
	   @return TDisplayMode - requested display mode
	*/
	IMPORT_C TDisplayMode DisplayMode() const;
	/**
	   A plug-in that supports an extension interface has to override this function 
	   @param aIFaceUid
				a request extension Uid
	   @param aIFacePtr
				a reference to the pointer that should be given extension interface pointer on success
	   @return KErrNotSupported if requested extension is not supported otherwise KErrNone
	*/
	IMPORT_C virtual TInt ExtensionInterface(TUid aIFaceUid, TAny*& aIFacePtr);
	/**
	   A plug-in that supports image mask getting has to override this function
	   @param aBitmap
				a reference to bitmap pointer
	   @param aMask
				a reference to bitmap pointer, a plug-in may return NULL if no mask is available
	*/
	IMPORT_C virtual void GetBitmap(const CFbsBitmap*& aBitmap, const CFbsBitmap*& aMask) const;
	/**
	   A plug-in that supports target bitmap status checkig has to override this function 
	   @return TBool - ETrue if subsequent call to the GetBitmap() able to return valid bitmaps
	*/
	IMPORT_C virtual TBool ValidBitmap() const;
	/**
	   A plug-in that supports source image status checking has to override this function
	   @return TUint - set of the TImageStatus flags
	*/
	IMPORT_C virtual TUint ImageStatus() const;
	/**
	   A plug-in that supports getting of source image number of frames has to override this function
	   @param aNumFrames 
				Number of frames in the source image
	   @return TInt - KErrNone if aNumFrames contains a valid number of frames
	*/
	IMPORT_C virtual TInt NumFrames(TInt& aNumFrames) const;
	
	// callback methods - used to pass data to the clieant throught the CImageDisplayFramework
	/**
	   A plug-in may use this function to determine if a previuos callback function to an API client has been completed
	   @return ETrue if callback has not been completed yet
	*/
	IMPORT_C TBool CallbackIsRunning() const;
	/**
	   A plug-in should use this function to pass information asinchronously to an API client. This function is asinchronous.
	   @param aBitmap
				a pointer to the bitmap that contains decoding result

	   @param aStatus
				the plugin status that should be combination of the TPluginStatus set

	   @param aUpdatedArea
				a rectangle within the aBitmap that was updated during the latest operation

	   @param aError
				error code of latest operation

	*/
	IMPORT_C void AsyncCallbackImageReady(const CFbsBitmap* aBitmap, TUint aStatus, const TRect& aUpdatedArea, TInt aError);

	/**
	 A plug-in should use this function to cancel callback to a client if it is stil pending
	*/
	IMPORT_C void CancelCallback();

protected:
	/**
	An array containing the sizes of the images.
	*/	
	CImageDisplay::RImageSizeArray iImageSizes;

private:
	/**
	  not for public use
	*/
	IMPORT_C static CImageDisplayPlugin* NewL(TUid aImplementationUid, CImageDisplayFramework& aFramework);
	void ConstructL(CImageDisplayFramework& aFramework, TUid aInstanceUid);
		
	static TInt AsyncCbGate(TAny* aPtr);
	TInt AsyncCbGate();

	/** Reserved. Not for public use */
	IMPORT_C virtual void ReservedVirtual1();
	/** Reserved. Not for public use */
	IMPORT_C virtual void ReservedVirtual2();
	/** Reserved. Not for public use */
	IMPORT_C virtual void ReservedVirtual3();
	/** Reserved. Not for public use */
	IMPORT_C virtual void ReservedVirtual4();

private:
	CImageDisplayFramework*		iFramework;
	CImageDisplayPluginBody*	iBody;
	TUid						iInstanceUid;
	/**
	  Future proofing not for public use
	*/
	TAny*	iReserved1;
	};

#endif // __IMAGEDISPLAYPLUGIN_H__

