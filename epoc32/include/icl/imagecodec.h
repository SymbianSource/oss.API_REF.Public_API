// Copyright (c) 2002-2009 Nokia Corporation and/or its subsidiary(-ies).
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

#ifndef __IMAGECODEC_H__
#define __IMAGECODEC_H__

#include <e32std.h>
#include <fbs.h>

#ifndef SYMBIAN_ENABLE_SPLIT_HEADERS
#include <icl/imagecodecdef.h>
#endif

// Pre-definitions needed to make sure everything always defined in the right order
class TFrameInfo;
class TImageDataBlock;
class CFrameImageData;

class CImageDecoder;
class CImageEncoder;
class CImageProcessor; 
class CImageProcessorReadCodecBody;
class CImageMaskProcessorReadCodecBody;

/**
@publishedAll
@released

Indicates what processing has so far been completed on the frame.
*/
enum TFrameState
	{
	/** Processing incomplete.
	*/
	EFrameIncomplete,
	/** Processing complete.
	*/
	EFrameComplete,
	/** Unexpected end of frame data.
	*/
	EUnexpectedEndOfData,
	/** Same as EFrameIncomplete but also requests a call to CImageReadCodec::GetNewDataPosition().
	*/
	EFrameIncompleteRepositionRequest,
	/** Processing of streaming block is complete.
	*/
	EBlockComplete
	};

/**
@publishedAll
@released

Utility class to allow forward iteration through the data contained in
an 8 bit descriptor.

@see TPtr8
@see TPtrC8
@see TDes8
@see TDesC8
*/
class TBufPtr8 : public TPtr8
	{
public:
	/**
	Default constructor.
	*/
	TBufPtr8()
		: TPtr8(0, 0, 0) {};
	inline void Set(const TDes8& aDes);
	inline void SetLengthOnly(const TDes8& aDes);
	inline void Set(const TPtrC8& aDes);
	inline void Shift(TInt aOffset);
	};

/**
Produces a shallow copy of the argument descriptor.

@param  aDes
        A reference to the descriptor containing the relevant data.
*/
inline void TBufPtr8::Set(const TDes8& aDes)
	{
	TPtr8::Set(CONST_CAST(TUint8*,aDes.Ptr()), aDes.Length(), aDes.MaxLength());
	}

/**
Produces a shallow copy of the argument descriptor, but also restricts
pointer access to the current actual size of the argument descriptor.

@param  aDes
        A reference to the descriptor containing the relevant data.
*/
inline void TBufPtr8::SetLengthOnly(const TDes8& aDes)
	{
	TPtr8::Set(CONST_CAST(TUint8*,aDes.Ptr()), aDes.Length(), aDes.Length());
	}
/**
Produces a shallow copy of the argument descriptor, but restricts
pointer access to the size of the const argument descriptor.

@param  aDes
        A reference to the descriptor containing the relevant data.
*/
inline void TBufPtr8::Set(const TPtrC8& aDes)
	{
	TPtr8::Set(CONST_CAST(TUint8*,aDes.Ptr()), aDes.Length(), aDes.Length());
	}
/**
Seeks the current data pointer aOffset bytes from the current position.

@param  aOffset
        The number of bytes by which to seek.
*/
inline void TBufPtr8::Shift(TInt aOffset)
	{
	SetLength(Length() - aOffset); iMaxLength -= aOffset; iPtr += aOffset;
	}

/**
@publishedAll
@released

Provides read related processing functions for bitmaps.

Note: For use by plugin writers only.
*/
class CImageReadCodec : public CBase
	{
public:
	IMPORT_C ~CImageReadCodec();

	/**
	Performs initial processing of image data and mask bitmaps.

	This function processes the image frame using data supplied in
	aFrameInfo, aFrameImageData and using the flag aDisableErrorDiffusion. Not all codecs
	are expected to make use of all fields.

	This is a virtual function that each derived class must implement.

	@param	aFrameInfo
	        A reference to a TFrameInfo object.
	@param	aFrameImageData
	        A reference to a CFrameImageData object.
	@param	aDisableErrorDiffusion
	        A flag indicating whether error diffusion should be disabled.
	@param	aDestination
	        The destination bitmap.
	@param	aDestinationMask
	        The destination mask bitmap.
	*/
	virtual void InitFrameL(TFrameInfo& aFrameInfo, CFrameImageData& aFrameImageData, TBool aDisableErrorDiffusion, CFbsBitmap& aDestination, CFbsBitmap* aDestinationMask) = 0;

	IMPORT_C virtual void InitFrameHeader(TFrameInfo& aFrameInfo, CFrameImageData& aFrameData);
	IMPORT_C virtual TFrameState ProcessFrameHeaderL(TBufPtr8& aData);
	IMPORT_C virtual void Complete(); // Called on frame completion and on underflow
	IMPORT_C virtual void GetNewDataPosition(TInt& aPosition, TInt& aLength); // Returns a new position for the data stream, (also length of data required)

	/**
	Processes the frame data contained in aSrc.

	This is a pure virtual function that each derived class must implement.

	@param  aSrc
	        A reference to the buffer containing the frame data.

	@return	The current frame state after processing.
	*/
	virtual TFrameState ProcessFrameL(TBufPtr8& aSrc) = 0;
	void SetCurrentFrame(TInt aFrameNumber);
	
	IMPORT_C virtual TInt ReductionFactor(const TSize& aOriginalSize, const TSize& aReducedSize) const;
	IMPORT_C virtual TInt ReducedSize(const TSize& aOriginalSize,TInt aReductionFactor, TSize& aReducedSize) const;
	
protected:
	IMPORT_C CImageReadCodec();
	IMPORT_C void ConstructL();

	IMPORT_C void ClearBitmapL(CFbsBitmap& aBitmap, TRgb aColor);
	IMPORT_C TInt CurrentFrame() const;

private:
	// Future proofing
	IMPORT_C virtual void ReservedVirtual1();
	IMPORT_C virtual void ReservedVirtual2();
	IMPORT_C virtual void ReservedVirtual3();
	IMPORT_C virtual void ReservedVirtual4();

private:
	TInt iCurrentFrame; //make handle to body if additional properties are needed
	};

/**
@publishedAll
@released 

Provides functions to determine or set features of the codec's CImageProcessor.

Note: 
For use by plugin writers only.
*/
class CImageProcessorReadCodec : public CImageReadCodec
	{
public:
	IMPORT_C ~CImageProcessorReadCodec();
protected:
	IMPORT_C CImageProcessorReadCodec();
	IMPORT_C void ConstructL();

	IMPORT_C CImageProcessor* ImageProcessor() const;
	IMPORT_C void SetImageProcessor(CImageProcessor* aImageProc);

	IMPORT_C const TPoint& Pos() const;
	IMPORT_C TPoint& Pos();
	IMPORT_C void SetPos(const TPoint& aPos);
private:
	CImageProcessorReadCodecBody* iBody;
	};

/**
@publishedAll
@released

Provides functions to determine or set features of the codec's CImageProcessor for a bitmap mask.

Note: For use by plugin writers only.
*/
class CImageMaskProcessorReadCodec : public CImageProcessorReadCodec
	{
public:
	IMPORT_C ~CImageMaskProcessorReadCodec();
protected:
	IMPORT_C CImageMaskProcessorReadCodec();
	IMPORT_C void ConstructL();

	IMPORT_C CImageProcessor* MaskProcessor() const;
	IMPORT_C void SetMaskProcessor(CImageProcessor* aMaskProc);

private:
	CImageMaskProcessorReadCodecBody* iBody;
	};


/**
@publishedAll
@released

Interface to be used by read codec implementations in conjunction with framework extension.
*/
class MReadCodecExtension
	{
public:
	/**
	Obtains the scaling coefficient 
	@param 	aOriginalSize	A reference to the original size of an image.
	@param 	aDesiredSize	A reference to the desired size of an image.
	@return	The scaling coefficient, for example:
			Original size = 1 or -1,
			Half original size = -2,
			Quarter original size = -3 etc.
	*/
	virtual TInt ScalingCoefficient(const TSize& aOriginalSize, const TSize& aDesiredSize) const = 0;
	
	/**
	Obtains the reduced size of the decoded bitmap based on the input parameters
	and updates aReducedSize with this value.

	@param  aOriginalSize		A reference to the original size of an image.
	@param  aScalingCoeff		The scaling coefficient to be applied.
	@param  aReducedSize		A reference to the new size of an image.
	@return KErrNone			If the function call was successful.
	@return 					A range of system wide error values.
	*/
	virtual TInt GetReducedSize(const TSize& aOriginalSize, TInt aScalingCoeff, TSize& aReducedSize) const = 0;	
	};

/**
@publishedAll
@released

Provides functions to determine or set features of the codec's CImageProcessor plus
provide extra functionality for Framework Extensions.

Note: 
For use by plugin writers only.
*/
class CImageProcessorReadCodecExtension : public CImageProcessorReadCodec,
										  public MReadCodecExtension											
	{
public:
	IMPORT_C ~CImageProcessorReadCodecExtension();
protected:
	IMPORT_C CImageProcessorReadCodecExtension();
	IMPORT_C void ConstructL();
	
	// From MReadCodecExtension
	IMPORT_C TInt ScalingCoefficient(const TSize& aOriginalSize, const TSize& aDesiredSize) const;
	IMPORT_C TInt GetReducedSize(const TSize& aOriginalSize, TInt aScalingCoeff, TSize& aReducedSize) const;
	};

/**
@publishedAll
@released


Provides functions to determine or set features of the codec's CImageProcessor plus
provide extra functionality for Framework Extensions.

Note: 
For use by plugin writers only.
*/
class CImageMaskProcessorReadCodecExtension : public CImageMaskProcessorReadCodec,
										  	  public MReadCodecExtension											
	{
public:
	IMPORT_C ~CImageMaskProcessorReadCodecExtension();
protected:
	IMPORT_C CImageMaskProcessorReadCodecExtension();
	IMPORT_C void ConstructL();
	
	// From MReadCodecExtension
	IMPORT_C TInt ScalingCoefficient(const TSize& aOriginalSize, const TSize& aDesiredSize) const;
	IMPORT_C TInt GetReducedSize(const TSize& aOriginalSize, TInt aScalingCoeff, TSize& aReducedSize) const;

	};

/**
@publishedAll
@released

Provides read related processing functions for bitmaps.

Note:
For use by plugin writers only.
*/
class CImageWriteCodec : public CBase
	{
public:
	IMPORT_C ~CImageWriteCodec();
	IMPORT_C virtual void InitFrameL(TBufPtr8& aDst, const CFbsBitmap& aSource);

	/**
	Processes the frame data contained in aDst.

	The internally held buffer must have been previously set, either by InitFrameL() or by a 
	SetSource().

	This is a pure virtual function that each derived class must implement.

	@param  aDst
	        A reference to the buffer containing the frame data.

	@return The current frame state after processing.
	*/
	virtual TFrameState ProcessFrameL(TBufPtr8& aDst) = 0;

	IMPORT_C const CFbsBitmap* Source() const;
	IMPORT_C void SetSource(const CFbsBitmap* aSource);
protected:
	IMPORT_C void ConstructL();
	IMPORT_C CImageWriteCodec();
private:
	// Future proofing
	IMPORT_C virtual void ReservedVirtual1();
	IMPORT_C virtual void ReservedVirtual2();
	IMPORT_C virtual void ReservedVirtual3();
	IMPORT_C virtual void ReservedVirtual4();
private:
	const CFbsBitmap* iSource; // linked object
	};

/**
@internalComponent

Max size of strings in extra resource files
*/
const TInt KCodecResourceStringMax=128;

#endif // __IMAGECODEC_H__
