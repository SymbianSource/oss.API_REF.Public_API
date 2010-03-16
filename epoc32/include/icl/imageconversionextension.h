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

#ifndef IMAGECONVERSIONEXTENSION_H
#define IMAGECONVERSIONEXTENSION_H

#include <e32base.h>
class MImageConvExtension;
class MImageConvOperation;
class MImageConvScaler;
class MImageConvStreamedDecode;
class MImageConvStreamedEncode;
class TFrameLayout;
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
 	3. Rotate / mirror over axis.
 */
 
/**
Operation extension for Image Conversion Library. Allows rotation and mirror over axis.
*/
class TImageConvOperation
	{
friend class CImageDecoder;
friend class CImageEncoder;

public:


	/**
	Operations or transforms on an image.
	*/
	enum TOperation
		{
		/** Rotate source 90 degrees clockwise.
		*/
		ERotation90DegreesClockwise		= 0x01,
		/** Rotate source 180 degrees clockwise.
		*/
		ERotation180DegreesClockwise 	= 0x02,
		/** Rotate source 270 degrees clockwise.
		*/
		ERotation270DegreesClockwise	= 0x04,
		/** Mirror source about the horizontal axis.
		*/
		EMirrorHorizontalAxis			= 0x08,
		/** Mirror source about the vertical axis.
		*/
		EMirrorVerticalAxis 			= 0x10
		};

	/**
	Get the codec plugin's capabilities.
	
	@return Bitmask combination of TOperation. Bit is set if decoder plugin supports the operation.
	*/
	IMPORT_C TUint Capabilities() const;
	
	/**
	Set up an operation be applied to the source. May be called more than once 
	to set up a stack of operations, but it is not possible to add more than one
	operation in a single call.
	The operations are applied to the image in the same order as they are added.
	
	@param aOperation The operation to add to the current stack of operations.
		
	@leave if more than one TOperation enum is passed for each individual call
	*/
	IMPORT_C void AddOperationL(TOperation aOperation);
	
	/**
	Remove all operations previously set. 
	*/
	IMPORT_C void ClearOperationStack();
	
private:

	IMPORT_C TImageConvOperation();  
	void SetExtension(MImageConvExtension* aExtension);
	
private:
	MImageConvOperation* iExtension;
	TInt iReserved; // future proof
	};


/**
Represents scaling capabilities of the code plugin.
*/
class TScalerCaps
	{
public:
	/**
	Constructor
	*/
	IMPORT_C TScalerCaps();

	/**
	Constructor
	
	@param aMaxUpscaleLimit Maximum upscaling possible.
	@param aMaxDownscaleLimit Maximum downscaling possible.
	@param aPreserveAspectRatioIsNeeded ETrue if only support preservation of aspect ratio.
	*/
	IMPORT_C TScalerCaps(TInt aMaxUpscaleLimit,TInt aMaxDownscaleLimit,TBool aPreserveAspectRatioIsNeeded);

	/**
	Maximum upscaling possible.
	@return value >= 1 : 1 means cannot upscale, 2 means twice original size
	*/
	IMPORT_C TInt MaxUpscaleLimit() const;
	
	/**
	Maximum downscaling possible.
	@return value <= -1 : -1 means cannot downscale, -2 means half original size
	*/
	IMPORT_C TInt MaxDownscaleLimit() const;
	
	/**
	Type of scaling which is supported.

	@return ETrue if can only do 1/2, 1/4, 1/8 etc downscale (limit depends on iMaxDownscaleLimit)
	     2, 4, 8 etc upscale (limit depends on iMaxUpscaleLimit)
	     EFalse if can do arbitrary scaling between iMaxDownscaleLimit and iMaxUpscaleLimit
	*/
	IMPORT_C TBool PowerOfTwoScalingOnly() const;
	
	/**
	Returns ETrue if the codec must preserve aspect ratio during scaling.
	
	@return ETrue if scaling is only possible if preservation of aspect ratio is requested.
		    EFalse if scaling without preserving aspect ratio is possible.
	*/
	IMPORT_C TBool MustPreserveAspectRatio() const;
	
	/**
	Compatibility - internal use only
	@internalComponent
	*/
	IMPORT_C TUint Size() const;

	/**
	Compatibility - internal use only
	@internalComponent
	*/
	IMPORT_C TUint Version() const;
	
private:
	TInt  iMaxUpscaleLimit;   // >= 1 : 2 means twice original size
	TBool iMustPreserveAspectRatio;  // If ETrue then can only do scaling whilst preserving aspect ratio
	TInt  iMaxDownscaleLimit; // <= -1 : -2 means 1/2 original size
	TBool iPowerOfTwoScalingOnly;
	TUint iSizeVersion; // bits 31 to 8 size, 7 to 0 contain version
	TInt  iReserved; // future proof
	};


/**
Scaling extension for Image Conversion Library. Supports both arbitrary or 'power of two' 1/2, 1/4, 1/8 scaling
*/
class TImageConvScaler
	{
friend class CImageDecoder;

public:

	/** 
	Quality used during scaling.
	*/
	enum TScalerQuality
		{
		EMinimumQuality, // = 0
		EMediumQuality,
		EMaximumQuality
		};

	/**
	Get the codec plugin's capabilities.

	@param aCaps Returns scaling capabilities of the codec plugin.
	*/
	IMPORT_C void GetCapabilities(TScalerCaps& aCaps) const;

    /**
    Request scaling to the desired size using the quality specified and specifying if the aspect ratio is to
	be preserved. 
	Ensure that CImageDecoder::GetDestinationSize is used to obtain the size of destination bitmap passed
	to CImageDecoder::Convert if scaling is set up by calling this method.
	
	@param aDesiredSize  Proposed size of the scaled image. Note that this may not necessarily be the size
	returned by a subsequent call to CImageDecoder::GetDestinationSize and is dependant upon the operations 
	(such as scaling, cropping and rotation) requested and also the capabilities of the plugin (which can be
	queried using TImageConvScaler::GetCapabilities).
	
	Example: If a plugin is only capable of power of two scaling, with an original image size of 600x400,
	then calling this SetScalingL function with a desired size of 500x300 will result in a subsequent call to 
	CImageDecoder::GetDestinationSize returning a size of 300x200 (that is, a scaling coefficient of -2).
	
	@param aQuality Desired quality of the image. Allows codec to lower quality targets to
	improve performance.
	
	@param aLockAspectRatio Set to ETrue if the aspect ratio of the original image is to be preserved.
	
	@leave KErrNotSupported if an invalid size is passed.
	@leave KErrNotSupported if aLockAspectRatio is EFalse and codec only supports preservation of aspect ratio.

	@see CImageDecoder::Convert
	@see CImageDecoder::GetDestinationSize
	@see TImageConvScaler::GetCapabilities
	*/ 
	IMPORT_C void SetScalingL(const TSize& aDesiredSize, TImageConvScaler::TScalerQuality aQuality, TBool aLockAspectRatio);

	/**
	Define the scaling to be applied to the image according to the given coefficient at the requested quality.
	Ensure that CImageDecoder::GetDestinationSize is used to obtain the size of destination bitmap to be passed
	to CImageDecoder::Convert.
	
	@param aScalingCoeff Scale to apply to the source. 2 means twice the original size, -2 half the size. 
	Do not confuse this with ReductionFactor where 2 indicates 1/2 size.
	
	@param aScalingQuality Desired quality of the image. Allows codec to lower quality targets to
	improve performance.
	
	@leave KErrNotSupported if codec cannot perform the requested scale.
	
	@see CImageDecoder::Convert
	*/
	IMPORT_C void SetScalingL(TInt aScalingCoeff, TImageConvScaler::TScalerQuality aScalingQuality);
	
private:
	IMPORT_C TImageConvScaler(); 
	void SetExtension(MImageConvExtension* aExtension);

private:
	MImageConvScaler* iExtension;
	TInt iReserved; // future proof
	};

/** 
'Block' streaming extension capabilities.
*/
class TDecodeStreamCaps
	{
public:
	/** Navigation possibilities within stream. 
	 */
	enum TNavigation
		{
		/** Blocks are returned from first to last */
		ENavigationSequentialForward = 0x01,
		
		/** Blocks are returned in a random order but moving only from first to last e.g. 1, 5, 18...*/
		ENavigationRandomForward     = 0x02,

		/** Blocks are returned in a random order but moving only from last to first e.g. 18, 5, 1...*/
		ENavigationRandomBackwards   = 0x04,

		/** Blocks are returned randomly e.g. 18, 5, 20, ...*/
		ENavigationRandom = 0x08,

		/** Blocks are returned from last to first  */
		ENavigationSequentialBackwards = 0x10
		};
		
	/**
	Constructor.
	*/
	IMPORT_C TDecodeStreamCaps();
	
	/**
	Constructor.
	
	@param aMaxBlocksPerRequest Maximum number of blocks that can be returned from the stream to client in a
	single request.
	@param aMinBlockSizeInPixels Minimum size in pixels of a block returned from the stream to the client in
	a single request.
	@param aOptimalBlocksPerRequest Optimum number of blocks returned from the stream to the client in
	a single request to get maximum performance benefit.
	@param aStreamSizeInBlocks Number of blocks of size MinBlockSizeInPixels() in the stream.
	@param aNavigation Navigation capabilities.
	*/
	IMPORT_C TDecodeStreamCaps(TInt aMaxBlocksPerRequest, const TSize& aMinBlockSizeInPixels, 
							TInt aOptimalBlocksPerRequest, TInt aStreamSizeInBlocks,
							TDecodeStreamCaps::TNavigation aNavigation);
	 
    /**
    The maximum number of blocks that can be returned from the stream to client in a
	single request.
	
	@return Maximum number of blocks that can be returned from the stream to client in a
	single request.
	*/ 
	IMPORT_C TInt MaxBlocksPerRequest() const;
	
	/** 
	The Minimum size in pixels of a block returned from the stream to the client in
	a single request.
	
	@return Minimum size in pixels of a block returned from the stream to the client in
	a single request. Sequence numbers and StreamSizeInBlocks() refer to this size of block.
	*/
	IMPORT_C const TSize& MinBlockSizeInPixels() const;
	
	/** 
	Optimum number of blocks returned from the stream to the client in
	a single request to get maximum performance benefit.
	
	@return Optimum number of blocks returned from the stream to the client in
	a single request to get maximum performance benefit.
	This can be used to determine the optimum value of the number of blocks of min block size per request.
	*/
	IMPORT_C TInt OptimalBlocksPerRequest() const;

	/** 
	Number of blocks of size MinBlockSizeInPixels() in the stream.
	
	@return Number of blocks of size MinBlockSizeInPixels() in the stream.
	*/
	IMPORT_C TInt StreamSizeInBlocks() const;
	
	/**
	Navigation capabilities.
	
	@return Navigation capabilities.

	Full random access to the stream if Navigation() returns 
	ENavigationSequentialForward | ENavigationRandomForward | ENavigationRandomBackwards
	*/
	IMPORT_C TDecodeStreamCaps::TNavigation Navigation() const;
	
	/**
	Compatibility - internal use only
	@internalComponent
	*/
	IMPORT_C TUint Size() const;

	/**
	Compatibility - internal use only
	@internalComponent
	*/
	IMPORT_C TUint Version() const;
	
private:
	TInt  iMaxBlocksPerRequest;
	TSize iMinBlockSizeInPixels;
	TInt iOptimalBlocksPerRequest;
	TInt  iStreamSizeInBlocks;
	TNavigation iNavigation;
	TUint  iSizeVersion;  // bits 31 to 8 size, 7 to 0 contain version
	TInt  iReserved; // future proof
	};		

/**
 'Block' streaming extension for Image Conversion Library decoder.
 */
class TImageConvStreamedDecode
	{
friend class CImageDecoder;
	
public:
    /**
	Returns a list of supported formats and the optimal format to be used. @see imageframeconst.h
	for a list of format uids.
	@param aFormats Returns an array of format uids 
	@param aOptimalFormat The 'best' uid to use. 
	*/
	IMPORT_C void GetSupportedFormatsL(RArray<TUid>& aFormats, TUid& aOptimalFormat) const;

	/**
	Returns the capabilities of the codec plugin for a specific format and for a specific frame.
	@param aFormat The format.
	@param aFrameNumber frame to stream
	@param aCaps The capabilities for the format given.
	*/     
	IMPORT_C void GetCapabilities(TUid aFormat, TInt aFrameNumber, TDecodeStreamCaps& aCaps) const;
	
	/**
	Get the size of the memory buffer to hold the returned data.

	@param aFormat the required format
	@param aBlockSizeInPixels returns the size in pixels of the block returned from the stream when aNumBlocks of minimum block size are requested.
	@param aNumBlocks the number of blocks of size TDecodeStreamCaps::MinBlockSizeInPixels() to be returned by one request

	@return The memory buffer size in bytes to hold the requested blocks. System wide error if for example 
	the format is not supported.
	*/
	IMPORT_C TInt GetBufferSize(TUid aFormat, TSize& aBlockSizeInPixels, TInt aNumBlocks)  const;


	/**
	Initialise the stream.
	
	@param aFormat the format to use
	@param aFrameNumber frame to stream
	@param aNavigation indication to stream of the way that the stream will be navigated. Allows 
	codec to optimise it's behaviour.
	@leave System wide error if for example the format is not supported.

	@note must call InitFrameL before GetBlocks or GetNextBlocks. Failure to do so completes request with
	KErrNotReady
	*/
	IMPORT_C void InitFrameL(TUid aFormat, TInt aFrameNumber, TDecodeStreamCaps::TNavigation aNavigation);

	/**
	Start asynchronous call to return random blocks from the stream

	@param aStatus request status
	@param aFrame An image frame wrapper a memory buffer to hold the returned block(s) of 
	pixel data. This can be 'uninitialised' or given specific format which must match that
	specified in the InitFrameL call.
	@param aSeqPosition block number starting at top left 0 ... TDecodeStreamCaps::StreamSizeInBlocks()
	@param aNumBlocksToGet number of blocks requested
	@param aNumBlocksRead number of blocks which will be returned when the request completes

	@note use CImageDecoder::Cancel() to cancel this request.
	*/
	IMPORT_C void GetBlocks(TRequestStatus& aStatus, CImageFrame& aFrame, TInt aSeqPosition, TInt aNumBlocksToGet, TInt& aNumBlocksRead);

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
	IMPORT_C void GetNextBlocks(TRequestStatus& aStatus, CImageFrame& aFrame, TInt aNumBlocksToGet, TInt& aNumBlocksRead, TBool& aHaveMoreBlocks);

private:
	IMPORT_C TImageConvStreamedDecode(); 
	void SetExtension(MImageConvExtension* aExtension);

private:
	MImageConvStreamedDecode* iExtension;
	TInt iReserved; // future proof
	};

/**
 'Block' streaming extension for Image Conversion Library encoder.
 */
/**
 'Block' streaming extension for Image Conversion Library encoder.
 */
class TEncodeStreamCaps
	{
public:
	/** Navigation possibilities within the stream. 
	 */
	enum TNavigation
		{
		/** Blocks can be returned from first to last */
		ENavigationSequentialForward = 0x01,
		
		/** Blocks can be returned in a random order but moving only from first to last e.g. 1, 5, 18...*/
		ENavigationRandomForward     = 0x02,

		/** Blocks can be returned in a random order but moving only from last to first e.g. 1, 5, 18...*/
		ENavigationRandomBackwards   = 0x04     
		};

	/**
	Constructor.
	*/
	IMPORT_C TEncodeStreamCaps();
	
	/**
	Constructor.
	
	@param aMaxBlocksPerRequest Maximum number of blocks that can be sent from the stream to client in a
	single request.
	@param aMinBlockSizeInPixels Minimum size in pixels of a block sent to the stream from the client in
	a single request.
	@param aOptimalBlocksPerRequest Optimum number of blocks sent to the stream from the client in
	a single request to get maximum performance benefit.
	@param aNavigation Navigation capabilities.
	*/
	IMPORT_C TEncodeStreamCaps(TInt aMaxBlocksPerRequest, const TSize& aMinBlockSizeInPixels,
					  			TInt aOptimalBlocksPerRequest,
					  			TEncodeStreamCaps::TNavigation aNavigation);
    /**
	Maximum number of blocks that can be sent from the stream to client in a
	single request.
	
	@return Maximum number of blocks that can be sent from the stream to client in a
	single request.
	*/ 
	IMPORT_C TInt MaxBlocksPerRequest() const;

	/** 
	Minimum size in pixels of a block sent to the stream from the client in
	a single request.
	
	@return Minimum size in pixels of a block sent to the stream from the client in
	a single request.
	*/
	IMPORT_C const TSize& MinBlockSizeInPixels() const;

	/** 
	Optimum number of blocks sent to the stream from the client in
	a single request to get maximum performance benefit.
	
	@return Optimum number of blocks sent to the stream from the client in
	a single request to get maximum performance benefit.
	*/
	IMPORT_C TInt OptimalBlocksPerRequest() const;


	/**
	Navigation capabilities.
	
	@return navigation capabilities.

	Full random access to the stream if Navigation() returns 
	ENavigationSequentialForward | ENavigationRandomForward |ENavigationRandomBackwards
	*/
	IMPORT_C TEncodeStreamCaps::TNavigation Navigation() const;
	
	/**
	Compatibility - internal use only
	@internalComponent
	*/
	IMPORT_C TUint Size() const;

	/**
	Compatibility - internal use only
	@internalComponent
	*/
	IMPORT_C TUint Version() const;

private:
	TInt  iMaxBlocksPerRequest;
	TSize iMinBlockSizeInPixels;
	TInt iOptimalBlocksPerRequest;
	TNavigation iNavigation;
	TUint  iSizeVersion;  // bits 31 to 8 size, 7 to 0 contain version
	TInt  iReserved; // future proof
	};

class TImageConvStreamedEncode
	{
friend class CImageEncoder;	
	
public:
    /**
	Returns a list of supported formats and the optimal format to be used. @see imageframeconst.h
	for a list of format uids.
	@param aFormats Returns an array of format uids 
	@param aOptimalFormat The 'best' uid to use. 
	*/
	IMPORT_C void GetSupportedFormatsL(RArray<TUid>& aFormats, TUid& aOptimalFormat) const;

	/**
	Returns the capabilities of the codec plugin for a specific format.
	@param aFormat The format.
	@param aCaps The capabilities for the format given.
	*/     
	IMPORT_C void GetCapabilities(TUid aFormat, TEncodeStreamCaps& aCaps) const;

	/**
	Initialise the stream.
	
	@param aFormat the format to use
	@param aFrameNumber frame to stream
	@param aFrameSizeInPixels Size of this frame in pixels
	@param aBlockSizeInPixels Size of block to be added / appended.
	@param aNavigation indication to stream of the way that the stream will be navigated. Allows 
	codec to optimise it's behaviour.
	@param aFrameImageData The frame image data (optional pass NULL if not required).
	There are format-specific image data variants that are used by encoders to obtain image specific 
	data. This behaviour is invoked by specifying aFrameImageData. Otherwise, encoder specific defaults 
	are invoked. @see TJpegImageData

	@leave System wide error if for example the format is not supported.
	
	@note must call InitFrameL before AppendBlocks or AddBlocks. Failure to do so completes request with
	KErrNotReady

	@note can either specify format through aFormat or aImageFrameData. Conflicts cause a leave with KErrArgument. 
	*/
	IMPORT_C void InitFrameL(TUid aFormat, TInt aFrameNumber, const TSize& aFrameSizeInPixels, const TSize& aBlockSizeInPixels, TEncodeStreamCaps::TNavigation aNavigation, const CFrameImageData* aFrameImageData);
	
	/**
	Append blocks to the stream.
	@param aStatus request status	
	@param aBlocks wraps a memory buffer containing the pixel data to be added to the stream
	@param aNumBlocksToAdd number of blocks of size TEncodeStreamCaps::MinBlockSizeInPixels to add to the stream
	*/
	IMPORT_C void AppendBlocks(TRequestStatus& aStatus, const CImageFrame& aBlocks, TInt aNumBlocksToAdd);
	
	/**
	Add blocks to the stream at a random position.
	@param aStatus request status	
	@param aBlocks wraps a memory buffer containing the pixel data to be added to the stream
	@param aSeqPosition position of block in stream starting at 0
	*/
	IMPORT_C void AddBlocks(TRequestStatus& aStatus, const CImageFrame& aBlocks, const TInt& aSeqPosition);

	/**
	Signal completion of writing the stream
	@param aStatus request status	
	*/
	IMPORT_C void Complete(TRequestStatus& aStatus); 

private:

	IMPORT_C TImageConvStreamedEncode();
	void SetExtension(MImageConvExtension* aExtension);

	MImageConvStreamedEncode* iExtension;
	TInt iReserved; // future proof
	};

#endif // IMAGECONVERSIONEXTENSION_H
