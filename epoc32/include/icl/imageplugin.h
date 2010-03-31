// Copyright (c) 2001-2009 Nokia Corporation and/or its subsidiary(-ies).
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

#ifndef ImageConversionPlugin_h
#define ImageConversionPlugin_h

#include <icl/imagedata.h>
#include <icl/imagecodec.h>
#include <imageconversion.h>
#include <icl/imageconversionextension.h>

class CImageDecoderPriv;
class CImageEncoderPriv;
class CImageReadCodec;
class CImageWriteCodec;
class TBufPtr8;

/**
@publishedAll
@released

The PluginAPI for Image Converter Library decoder plugins. 

Intended for use by plugin writers only.
*/
class CImageDecoderPlugin : public CBase
	{
friend class CImageDecoderPriv;

public:
	IMPORT_C ~CImageDecoderPlugin();

	IMPORT_C virtual TInt NumberOfImageComments() const;
	IMPORT_C virtual HBufC* ImageCommentL(TInt aCommentNumber) const;
	IMPORT_C virtual TInt NumberOfFrameComments(TInt aFrameNumber) const;
	IMPORT_C virtual HBufC* FrameCommentL(TInt aFrameNumber, TInt aCommentNumber) const;

	/**
	Returns the image type and sub-type for a given frame of the image that
	has just been opened.

	This is a virtual function that each individual plugin must implement.

	@param  aFrameNumber
	        The frame index for type and sub-type information should be returned.
	@param  aImageType
	        On return contains the image type UID for the specified frame.
	@param  aImageSubType
	        On return contains the image sub-type UID for the specified frame. If the sub-type does
			not exist KNullUid is returned.
	*/
	virtual void ImageType(TInt aFrameNumber, TUid& aImageType, TUid& aImageSubType) const = 0;

protected:
	IMPORT_C CImageDecoderPlugin();
	IMPORT_C virtual void Cleanup();
	IMPORT_C virtual void ReadFrameHeadersL();

	/**
	Invokes the ReadFrameHeadersL() method of the supplied plugin.

	The plugin's version of ReadFrameHeadersL() should read the image header information, create
	the required codec and read the frame headers.

	This is a virtual function that each individual plugin must implement.
	*/
	virtual void ScanDataL() = 0;


	IMPORT_C virtual TInt FrameHeaderBlockSize(TInt aFrameNumber) const;
	IMPORT_C virtual TInt FrameBlockSize(TInt aFrameNumber) const;

	/**
	Returns the codec specific frame information stored in resource files.

	This is a virtual function that each individual plugin must implement.

	@param  aFs
	        A handle to a file server session.
	@param  aFrameNumber
	        The frame number to which the codec specific frame information
	        applies (optional, defaults to zero).

	@return A pointer to a newly allocated CFrameInfoStrings object.
	        Ownership is transferred to the caller.
	*/
	IMPORT_C virtual CFrameInfoStrings* FrameInfoStringsL(RFs& aFs, TInt aFrameNumber = 0) = 0;

	IMPORT_C void OpenExtraResourceFileLC(RFs& aFs, const TUid aUid, RResourceFile& aResourceFile) const;
	IMPORT_C void ReadDataL(TInt aPosition, TPtrC8& aReadBuffer, TInt aLength);
	IMPORT_C virtual void InitConvertL();

	IMPORT_C void RequestInitL(TInt aFrameNumber);

	IMPORT_C virtual void DoConvert();
	IMPORT_C void PrepareForProcessFrameL();
	IMPORT_C void HandleProcessFrameResult(TInt aErrCode, TFrameState aCodecState);
	IMPORT_C TBufPtr8& SourceData();

	IMPORT_C void RequestComplete(TInt aReason);
	IMPORT_C void SelfComplete(TInt aReason);
	IMPORT_C void SetSelfPending();

	IMPORT_C TBool IsImageHeaderProcessingComplete() const;

	IMPORT_C CImageReadCodec* ImageReadCodec() const;
	IMPORT_C void SetImageReadCodec(CImageReadCodec* aImageReadCodec);

	IMPORT_C const TFrameInfo& ImageInfo() const;
	IMPORT_C void SetImageInfo(const TFrameInfo& aImageInfo);

	IMPORT_C TInt NumberOfFrames() const;

	IMPORT_C const TImageDataBlock* ImageData(TInt aIndex) const;
	IMPORT_C TInt InsertImageData(const TImageDataBlock* aEntry, TInt aPos);
	IMPORT_C TInt AppendImageData(const TImageDataBlock* aEntry);
	IMPORT_C void RemoveImageData(TInt aPos);
	IMPORT_C TInt ImageDataCount() const;
	IMPORT_C TInt AppendImageDataBuffer(const HBufC8* aImageBuffer);

	IMPORT_C TInt DataLength() const;
	IMPORT_C void SetDataLength(TInt aDataLength);
	IMPORT_C TInt Position() const;
	IMPORT_C void SetPosition(const TInt aPosition);
	IMPORT_C TInt StartPosition() const;
	IMPORT_C void SetStartPosition(TInt aDataLength);

	IMPORT_C const CFbsBitmap& Destination() const;
	IMPORT_C TBool ValidDestination() const;
	IMPORT_C const CFbsBitmap& DestinationMask() const;
	IMPORT_C TBool ValidDestinationMask() const;

	IMPORT_C const TFrameInfo& FrameInfo(TInt aFrameNumber = 0) const;
	IMPORT_C const CFrameImageData& FrameData(TInt aFrameNumber = 0) const;

	IMPORT_C TInt SourceLength() const;

	IMPORT_C virtual void HandleCustomSyncL(TInt aParam);
	IMPORT_C virtual void InitCustomAsyncL(TInt aParam);
	IMPORT_C virtual void NotifyComplete();
	IMPORT_C TBool AmInThread() const;
	IMPORT_C TBool ShouldAbort() const;
	IMPORT_C void SetThumbnailData(HBufC8* aThumbnailData);
	
	IMPORT_C CImageDecoder::TOptions DecoderOptions() const;
	
private:
	TBool ValidProperties() const;

	IMPORT_C virtual void EnableMaskGeneration();
	IMPORT_C virtual void NotifyImageTypeChangeL(TInt aImageType);
	
	// Future proofing
	IMPORT_C virtual void ReservedVirtual1();

public:
	/**
	@publishedAll
	@released
	
	Called by the framework to obtain a pointer to a codec implemented extension.

	@param aExtUid Extension UID normally prefixed KUidImageConv. @see icl_uids.hrh .
	@param aExtPtr Returns a ptr to the extension implemented by the codec plugin.
	*/
	IMPORT_C virtual void GetExtensionL(TUid aExtUid, MImageConvExtension*& aExtPtr);
	/**
	@publishedAll
	@released
	
	Called by the framework on the plugin to apply a clipping rectangle to the image.

	Sets the area of interest of the image to be decoded.

	@param aClipRect	A pointer to a TRect that specifies the
						location and size of the region to be decoded.  This
						rectangle must have positive width and height values as
						per TRect::IsNormalized() and TRect::Normalize().
						Passing in a NULL value will clear the clipping rectangle.
						Note that a clipping rectangle may not be valid for all frames of an image.
						
	@leave  KErrNotSupported if clipping is not supported by the codec plugin.
	@leave  Other system-wide error codes.
	*/
	IMPORT_C virtual void SetClippingRectL(const TRect* aClipRect);
	/**
	@publishedAll
	@released
	
	Called by framework on plugin to get the size of decoded image.

	Get the size of the decoded image for the given frame. The calculation will account for any clipping rectangle set,
	scaling applied through the TImageConvScaler extension and any operation applied through TImageConvOperation.
	If TImageConvScaler::SetScalingL(.. has been called then the size of the bitmap passed to CImageDecoder::Convert must match the size returned from
	this function.

	@param aSize 
		   Returns the size of the decoded image.
	@param aFrameNumber
		   The frame number.
		   
	@return KErrArgument if an error in calculation is detected e.g. if clipping rectangle is outside of the overall frame boundary.
	@return Other system wide errors.
	*/
	IMPORT_C virtual TInt GetDestinationSize(TSize& aSize, TInt aFrameNumber = 0);

private:
	CImageDecoderPriv* iProperties; // not owned

friend class RCImageDecoderPrivTestBase;
	};

/**
@publishedAll
@released

The plugin API for Image Converter Library encoder plugins.

Intended for use by plugin writers only.
*/
class CImageEncoderPlugin : public CBase
	{
friend class CImageEncoderPriv;

public:
	IMPORT_C ~CImageEncoderPlugin();

protected:
	IMPORT_C CImageEncoderPlugin();
	IMPORT_C virtual void Cleanup();
	IMPORT_C virtual void InitConvertL();
	IMPORT_C void RequestInitL();
	IMPORT_C virtual void DoConvert();
	IMPORT_C void HandleProcessFrameResult(TInt aErrCode, TFrameState aCodecState);
	IMPORT_C TBufPtr8& DestinationData();
	IMPORT_C void FinishConvertL();
	IMPORT_C void WriteDataL(TInt aPosition,const TDesC8& aDes);
	IMPORT_C void WriteDataPositionIncL(TInt aPosition,const TDesC8& aDes);
	IMPORT_C const CFbsBitmap& Source() const;
	IMPORT_C TBool ValidSource() const;

	IMPORT_C CImageWriteCodec* ImageWriteCodec() const;
	IMPORT_C void SetImageWriteCodec(CImageWriteCodec* aImageWriteCodec) const;
	IMPORT_C TInt& StartPosition() const;
	IMPORT_C TInt& Position() const;
	IMPORT_C const TSize& FrameInfoOverallSizeInPixels() const;

	/**
	Allocates the specific codec used for the encoding and passes
	ownership to the plugin.

	This is a pure virtual function that each individual plugin must implement.

	@param  aFrameImageData
	        The parameters which can be passed on to the encoding algorithm.
	        This data might be used to determine the exact codec created.

	@return An error code indicating if the function call was successful. KErrNone on success, otherwise
	        another of the system-wide error codes.
	*/
	virtual void PrepareEncoderL(const CFrameImageData* aFrameImageData) = 0;

	/**
	May be used to fill in additional fields at the end of the encoding
	process, which it may not have been possible to do earlier.

	This is a pure virtual function that each individual plugin must implement.
	*/
	virtual void UpdateHeaderL() = 0;

	IMPORT_C TInt CurrentImageSizeL() const;

	IMPORT_C void RequestComplete(TInt aReason);
	IMPORT_C void SelfComplete(TInt aReason);
	IMPORT_C void SetSelfPending();

	IMPORT_C virtual void HandleCustomSyncL(TInt aParam);
	IMPORT_C virtual void InitCustomAsyncL(TInt aParam);
	IMPORT_C virtual void NotifyComplete();
	IMPORT_C TBool AmInThread() const;
	IMPORT_C TBool ShouldAbort() const;

	IMPORT_C CImageEncoder::TOptions EncoderOptions() const;

private:
	TBool ValidProperties() const;

	IMPORT_C virtual void WriteThumbnailL();
	
	/**
	Originally only used by the jpeg codec, but now in use as a generic pre-convert async step
	*/	
	IMPORT_C virtual void WriteExifDataL(TRequestStatus*& aScaleCompletionStatus);
	
	IMPORT_C virtual void SetThumbnail(TBool aDoGenerateThumbnail);
	IMPORT_C virtual void ReservedVirtual1();
	IMPORT_C virtual void ReservedVirtual2();
	IMPORT_C virtual void ReservedVirtual3();
	
public:
	/**
	@publishedAll
	@released
	
	Called by the framework to obtain a pointer to a codec implemented extension.

	@param aExtUid Extension UID normally prefixed KUidImageConv. @see icl_uids.hrh .
	@param aExtPtr. Returns a ptr to the extension implemented by the codec plugin.
	*/
	IMPORT_C virtual void GetExtensionL(TUid aExtUid, MImageConvExtension*& aExtPtr);

private:
	CImageEncoderPriv* iProperties; // not owned
	};


#endif //ImageConversionPlugin_h

