// Copyright (c) 2007-2009 Nokia Corporation and/or its subsidiary(-ies).
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

#ifndef IMAGECONVERSIONEXTENSIONINTF_H
#define IMAGECONVERSIONEXTENSIONINTF_H

#include <icl/imageconversionextension.h>

class CImageFrame;
class CFrameImageData;

/**
@file
@publishedAll
@released
*/

/**
 Image Conversion Library extensions. When applied together there is an implicit order for operations:
 	1. Crop or clip.
 	2. Scale
 	3. Rotate / flip.

In order to support an extension the codec plugin must implement the interface and return this interface 
through a call to CImageDecoderPlugin::GetExtensionL.
*/
 
/**
Extension base class
*/
class MImageConvExtension
	{
public:
	/** 
	Uid of extension interface.
	*/
	virtual TUid Uid() const = 0; 

	/**
	Increment the reference count.
	*/
	virtual void IncrementRef() = 0;
	
	/**
	Called when the client has finished with this interface allowing the codec to clean up.
	*/
	virtual void Release() = 0; 
	};

/**
Operation extension for Image Conversion Library. Allows rotation and mirror/flip. 
*/
class MImageConvOperation : public MImageConvExtension
	{
public:	
	/**
	 Capabilities of the code plugin.
	 
	 @return Bitmask combination of TOperation. Bit is set if decoder plugin supports the operation.
	 */
	virtual TUint Capabilities() const = 0;
	
	/**
	 Set up an operation be applied to the source. May be called more than once 
	 to set up a stack of operations, but it is not possible to add more than one
	 operation in a single call.
	 
	 @param aOperation An operation to be added to the current operation stack.
	 
	 @leave if more than one TOperation enum is passed for each individual call
	 */
	virtual void AddOperationL(TImageConvOperation::TOperation aOperation) = 0;
	
	/**
	 Remove all operations previously set. 
	*/
	virtual void ClearOperationStack() = 0;
	};

/**
Scaling extension for Image Conversion Library
*/
class MImageConvScaler : public MImageConvExtension
	{
public:
	/**
	 Gets the scaling capabilities.
	 
	 @param aCaps Returns scaling capabilities of the codec plugin.
	 */
	virtual void GetCapabilities(TScalerCaps& aCaps) const = 0;

    /** 
     Request scaling to the desired size using the quality specified and specifying if the aspect ratio is to
     be preserved.
	 @param aDesiredSize  Proposed size of the scaled image.
	 @param aQuality Desired quality of the image. Allows codec to lower quality targets to
     improve performance.
	 @param aLockAspectRatio Set to ETrue if the aspect ratio of the original image is to be preserved.
	 @leave KErrNotSupported if an invalid size is passed.
	 @leave KErrNotSupported if aLockAspectRatio is EFalse and codec only supports preservation of aspect ratio.
	 */ 
	virtual void SetScalingL(const TSize& aDesiredSize, TImageConvScaler::TScalerQuality aQuality, TBool aLockAspectRatio) = 0;

	/**
	 Define the scaling to be applied to the image according to the given coefficient at the requested quality.
	 
	 @param aScalingCoeff Scale to apply to the source. 2 means twice the original size, -2 half the size. 
	                      Do not confuse this with ReductionFactor where 2 indicates 1/2 size.
     @param aScalingQuality Desired quality of the image. Allows codec to lower quality targets to
     improve performance.
	 @leave KErrNotSupported if codec cannot perform the requested scale.
	 */
	virtual void SetScalingL(TInt aScalingCoeff, TImageConvScaler::TScalerQuality aScalingQuality) = 0;
	};

/**
Block Streaming extension for decoder plugins.
*/
class MImageConvStreamedDecode : public MImageConvExtension
	{	
public:
    /**
     Returns a list of supported formats and the optimal format to be used. @see imageframeconst.h
     for a list of format uids.
     @param aFormats Returns an array of format uids 
     @param aOptimalFormat The 'best' uid to use. 
     */
	virtual void GetSupportedFormatsL(RArray<TUid>& aFormats, TUid& aOptimalFormat) const = 0;

	/**
	 Returns the capabilities of the codec plugin for a specific format.
	 @param aFormat The format.
	 @param aFrameNumber frame to stream
	 @param aCaps The capabilities for the format given.
	 */     
	virtual void GetCapabilities(TUid aFormat, TInt aFrameNumber, TDecodeStreamCaps& aCaps) const = 0;
	
	/**
	 Get the size of the memory buffer to hold the returned data.
	 
	 @param aFormat the required format
	 @param aBlockSizeInPixels size of a single block to be returned
	 @param aNumBlocks the number of blocks of size TDecodeStreamCaps::MinBlockSizeInPixels() to be returned by one request
	 @return The memory buffer size in bytes to hold the requested blocks.
	 */
	virtual TInt GetBufferSize(TUid aFormat, TSize& aBlockSizeInPixels, TInt aNumBlocks) const = 0;

	/**
	 Initialise the stream.
	 @param aFormat the format to use
	 @param aFrameNumber frame to stream
	 @param aNavigation indication to stream of the way that the stream will be navigated. Allows 
	 codec to optimise it's behaviour.
	 
	 @note TO DO Do we need to specify where the source is held e.g. in memory, on flash card etc?
	 
	 @note must call InitFrameL before GetBlocks or GetNextBlocks. Failure to do so completes request with
	 KErrNotReady
	 */
	virtual void InitFrameL(TUid aFormat, TInt aFrameNumber, TDecodeStreamCaps::TNavigation aNavigation) = 0;

	/**
	 Start asynchronous call to return random blocks from the stream
	 
	 @param aStatus request status
	 @param aFrame An image frame wrapper a memory buffer to hold the returned block(s) of 
	 pixel data. This can be 'uninitialised' or given specific format which must match that
	 specified in the InitFrameL call.
	 @param aSeqPosition block number starting at 0 ...
	 @param aNumBlocksToGet number of blocks requested
	 @param aNumBlocksRead number of blocks which will be returned when the request completes
	 
     @note use CImageDecoder::Cancel() to cancel this request.
	 */
	virtual void GetBlocks(TRequestStatus* aStatus, CImageFrame* aFrame, TInt aSeqPosition, TInt aNumBlocksToGet, TInt* aNumBlocksRead) = 0;

	/**
	 Start asynchronous call to return blocks sequentially from the stream. Blocks are returned 
	 from the first block until the last in the stream.
	 
	 @param aStatus request status
	 @param aFrame An image frame wrapper a memory buffer to hold the returned block(s) of 
	 pixel data. This can be 'uninitialised' or given specific format which must match that
	 specified in the InitFrameL call.
	 @param aNumBlocksToGet number of blocks requested
	 @param aNumBlocksRead number of blocks which will be returned when the request completes
	 
     @note use CImageDecoder::Cancel() to cancel this request.
	 */
	virtual void GetNextBlocks(TRequestStatus* aStatus, CImageFrame* aFrame, TInt aNumBlocksToGet, TInt* aNumBlocksRead, TBool* aHaveMoreBlocks) = 0;
	};

/**
Block Streaming extension for encoder plugins.
*/
class MImageConvStreamedEncode : public MImageConvExtension
	{
public:
    /**
     Returns a list of supported formats and the optimal format to be used. @see imageframeconst.h
     for a list of format uids.
     @param aFormats Returns an array of format uids 
     @param aOptimalFormat The 'best' uid to use. 
     */
	virtual void GetSupportedFormatsL(RArray<TUid>& aFormats, TUid& aOptimalFormat) const = 0;

	/**
	 Returns the capabilities of the codec plugin for a specific format.
	 @param aFormat The format.
	 @param aCaps The capabilities for the format given.
	 */     
	virtual void GetCapabilities(TUid aFormat, TEncodeStreamCaps& aCaps) const = 0;

	/**
	 Initialise the stream.
	 @param aFormat the format to use
	 @param aFrameNumber frame to stream
	 @param aFrameSizeInPixels Size of this frame in pixels
	 @param aBlockSizeInPixels Size of block to be added / appended. ??? do we want to support multiple blocks being added
	 in which case InitFrameL needs an extra parameter
	 @param aNavigation indication to stream of the way that the stream will be navigated. Allows 
	 codec to optimise it's behaviour.
	 @param aFrameImageData The frame image data. Optional.
	 There exists format-specific image data variants that are used by 
	 encoders to obtain image specific data. This behaviour is invoked by specifying 
	 aFrameImageData. Otherwise, if set to NULL, encoder specific defaults are invoked. @see TJpegImageData
	 
	 @note TO DO Do we need to specify where the destination is held e.g. in memory, on flash card etc?
	 
	 @note must call InitFrameL before AppendBlocks or AddBlocks. Failure to do so completes request with
	 KErrNotReady

	 @note can either specify format through aFormat or aImageFrameData. Conflicts should leave with KErrArgument. 
	 */
	virtual void InitFrameL(TUid aFormat, TInt aFrameNumber, const TSize& aFrameSizeInPixels, const TSize& aBlockSizeInPixels, TEncodeStreamCaps::TNavigation aNavigation, const CFrameImageData* aFrameImageData) = 0;
	
	/** Append blocks to the stream.
	 @param aStatus request status	
	 @param aBlocks wraps a memory buffer containing the pixel data to be added to the stream
	 @param aNumBlocksToAdd number of blocks of size TEncodeStreamCaps::MinBlockSizeInPixels to add to the stream
	 */
	virtual void AppendBlocks(TRequestStatus* aStatus, const CImageFrame& aBlocks, TInt aNumBlocksToAdd) = 0 ;
	
	/** Add blocks to the stream at a random position.
	 @param aStatus request status	
	 @param aBlocks wraps a memory buffer containing the pixel data to be added to the stream
	 @param aSeqPosition position of block in stream starting at 0
	 */
	virtual void AddBlocks(TRequestStatus* aStatus, const CImageFrame& aBlocks, const TInt& aSeqPosition) = 0;
	
	/** Signal completion of writing the stream
	 @param aStatus request status	
	*/
	virtual void Complete(TRequestStatus* aStatus) = 0; 
private:
	TInt iReserved; // future proof
	};


/**
Extension for Prepare (analyse image in advance of conversion)
*/
class MImageConvPrepare : public MImageConvExtension
	{
public:
	/**
	Call to allow analysis of image prior to calling Convert.

	@param	aStatus
			Request status. On completion this contains an error code. This is KErrNone if the frame
			was analyzed successfully, KErrNotSupported if the codec does not support analysis, or a 
			system-wide error code.
	*/
	virtual void Prepare(TRequestStatus* aStatus) = 0;

private:
	TInt iReserved; // future proof
	};
	


#endif // IMAGECONVERSIONEXTENSIONINF_H
