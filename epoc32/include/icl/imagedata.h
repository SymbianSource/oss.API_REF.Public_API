// Copyright (c) 2001-2009 Nokia Corporation and/or its subsidiary(-ies).
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

#ifndef __ImageData_h__
#define __ImageData_h__

#include <e32base.h>
#include <badesca.h>
#include <gdi.h>
#include <mm/mmcaf.h>

class CFrameImageData;

/**
@publishedAll
@released

The abstract base class for all format-specific frame data variants.
*/
class TFrameDataBlock
	{
public:
	IMPORT_C TUid DataType() const;

protected:
	IMPORT_C TFrameDataBlock(TUid aDataType);
	/**
	Provides a copy of an object that manages a list of frame and image block data,
	but not a bitwise copy. It provides a new reference to the object.
	@param aFrameImageData An object that manages a list of frame and image block data
	*/
	virtual TFrameDataBlock* DuplicateL(CFrameImageData& aFrameImageData) const = 0;

private:
	TUid iDataType;
	TInt iReserved1;
	TInt iReserved2;
	TInt iReserved3;

friend class CFrameImageData;
friend class RTImageDataTest;
	};

/**
@publishedAll
@released

The abstract base class for all format-specific image data variants.
*/
class TImageDataBlock
	{
public:
	IMPORT_C TUid DataType() const;

protected:
	IMPORT_C TImageDataBlock(TUid aDataType);

private:
	virtual TImageDataBlock* DuplicateL(CFrameImageData& aFrameImageData) const = 0;

private:
	TUid iDataType;
	TInt iReserved1;
	TInt iReserved2;
	TInt iReserved3;

friend class CFrameImageData;
friend class RTImageDataTest;
	};


class CImageDataArray;

/**
@publishedAll
@released

Class to manage lists of frame and image block data.
*/
class CFrameImageData : public CBase
	{
public:
	IMPORT_C static CFrameImageData* NewL();
	IMPORT_C static CFrameImageData* NewL(CImageDataArray& aImageData, TBool aImageDataOwner = EFalse);
	IMPORT_C CFrameImageData* AllocL() const;
	IMPORT_C ~CFrameImageData();

	// Access fns.
	// Append/insert/delete
	IMPORT_C TInt InsertImageData(const TImageDataBlock* aEntry, TInt aPos);
	IMPORT_C TInt AppendImageData(const TImageDataBlock* aEntry);
	IMPORT_C void RemoveImageData(TInt aIndex);

	IMPORT_C TInt InsertFrameData(const TFrameDataBlock* aEntry, TInt aPos);
	IMPORT_C TInt AppendFrameData(const TFrameDataBlock* aEntry);
	IMPORT_C void RemoveFrameData(TInt aIndex);

	// Get local image data.
	IMPORT_C const TImageDataBlock* GetImageData(TInt aIndex) const;
	IMPORT_C TImageDataBlock* GetImageData(TInt aIndex);

	IMPORT_C const TFrameDataBlock* GetFrameData(TInt aIndex) const;
	IMPORT_C TFrameDataBlock* GetFrameData(TInt aIndex);

	// Get num entries.
	IMPORT_C TInt ImageDataCount() const;
	IMPORT_C TInt FrameDataCount() const;

	// Append image buffers.
	IMPORT_C TInt AppendImageBuffer(const HBufC8* aImageBuffer);

private:
	IMPORT_C CFrameImageData(CImageDataArray& aImageData, TBool aImageDataOwner = EFalse);
	IMPORT_C virtual void Reserved_1();
	IMPORT_C virtual void Reserved_2();
	IMPORT_C virtual void Reserved_3();
	IMPORT_C virtual void Reserved_4();

private:
	// Image data for the frame. (Single frame formats)
	// Image data that is the same for all frames. (Multi frame formats)
	CImageDataArray& iImageData;
	TBool iImageDataOwner;
	
	// Image data that is for this frame only. (Multi frame formats only)
	RPointerArray<TFrameDataBlock> iFrameData;

	TAny* iReserved;
	};

/**
@publishedAll
@released

Class used to maintain frame information stored in
codec specific resource files.
*/
class CFrameInfoStrings : public CBase
	{
public:
	IMPORT_C static CFrameInfoStrings* NewL();
	IMPORT_C static CFrameInfoStrings* NewLC();
	IMPORT_C ~CFrameInfoStrings();

	IMPORT_C const TPtrC String(TInt aIndex) const;
	IMPORT_C TInt Count() const;

	IMPORT_C const TPtrC Decoder() const;
	IMPORT_C void SetDecoderL(const TDesC& aString);
	IMPORT_C const TPtrC Format() const;
	IMPORT_C void SetFormatL(const TDesC& aString);
	IMPORT_C const TPtrC Dimensions() const;
	IMPORT_C void SetDimensionsL(const TDesC& aString);
	IMPORT_C const TPtrC Depth() const;
	IMPORT_C void SetDepthL(const TDesC& aString);
	IMPORT_C const TPtrC Details() const;
	IMPORT_C void SetDetailsL(const TDesC& aString);

private:
	CFrameInfoStrings();
	void ConstructL();

	void SetStringL(TInt aIndex, const TDesC& aString);

private:

	enum TFrameInfoStringIndex
		{
		EDecoder	= 0,
		EFormat		= 1,
		EDimensions = 2,
		EDepth		= 3,
		EDetails	= 4
		};

	CDesCArray* iFrameInfoStrings;
	};

/**
@publishedAll
@released

General frame info provided by all plugins.
*/
class TFrameInfo
	{
public:
	/**
	Flags that define the attributes of a frame. These can be combined using an OR operation.
	*/
	enum TFrameInfoFlags
		{
		/** Indicates whether or not the frame is colour.
		*/
		EColor					= 0x00000001,

		/** Indicates if any part of the frame is transparent.
		*/
		ETransparencyPossible	= 0x00000002,

		/** Indicates whether or not the frame can be scaled.
		*/
		EFullyScaleable			= 0x00000004,

		/** Indicates whether or not the frame's aspect ratio must be maintained during scaling. If not
		set, the frame can be stretched.
		*/
		EConstantAspectRatio	= 0x00000008,

		/** Indicates if the frame can be decoded and drawn dithered. If this is not set, the bitmap
		must use the recommended display mode. 
		*/
		ECanDither				= 0x00000010,

		/** Indicates if the frame contains alpha-blending information. This setting is only valid if
		ETransparencyPossible is set.
		*/
		EAlphaChannel			= 0x00000020,

		/** Mutually exclusive image disposal method 1, no disposal specified. Image is not disposed
		of and graphic is left in place.
		*/
		ELeaveInPlace			= 0x00000040,

		/** Mutually exclusive image disposal method 2, restore to background colour. The area used
		by the graphic must be restored to the background colour.
		*/
		ERestoreToBackground	= 0x00000080,

		/** Mutually exclusive image disposal method 3, restore to previous. The decoder is required
		to restore the area overwritten by the graphic with what was there prior to rendering the
		graphic.
		*/
		ERestoreToPrevious		= 0x00000100,

		/** If this flag is set and an image convert operation returns KErrUnderFlow, the partially
		decoded bitmap is not suitable for display.
		*/
		EPartialDecodeInvalid   = 0x00000200,

		/** This flag is used by Mng decoder to indicate that there are more frames to decode
		*/
		EMngMoreFramesToDecode   = 0x00000400,
		
		/** This flag is used to indicate that the code sets iFrameSizeInPixels
		*/
		EUsesFrameSizeInPixels = 0x00000800
		};

	/**
	Indicates the current status of frame processing.
	*/
	enum TFrameInfoState
		{
		/** The frame information has not been initialised.
		*/
		EFrameInfoUninitialised,

		/** The frame header is being processed.
		*/
		EFrameInfoProcessingFrameHeader,

		/** The frame is being processed.
		*/
		EFrameInfoProcessingFrame,

		/** The frame has been processed.
		*/
		EFrameInfoProcessingComplete
		};
public:
	IMPORT_C TFrameInfoState CurrentFrameState() const;
	IMPORT_C void SetCurrentFrameState(TFrameInfoState aFrameInfoState);
	IMPORT_C TInt CurrentDataOffset() const;
	IMPORT_C void SetCurrentDataOffset(TInt aOffset);
	IMPORT_C TInt FrameDataOffset() const;
	IMPORT_C void SetFrameDataOffset(TInt aOffset);
public:
	/**
	The coordinates of the frame within the screen in pixels.
	*/
	TRect iFrameCoordsInPixels;

	/**
	The size of the frame in twips.
	*/
	TSize iFrameSizeInTwips;

	/**
	The number of bits per pixel for the frame.
	*/
	TInt iBitsPerPixel;

	/**
	The delay in microseconds before displaying the next frame.
	*/
	TTimeIntervalMicroSeconds iDelay;

	/**
	Frame information flags. A combination of the values contained in the TFrameInfoFlags enum.
	*/
	TUint32 iFlags;

	/**
	The size of the frame. A frame can occupy a rectangle within the overall image. In this case, 
	the frame size is less than the overall image size.
	For a GIF image, the following applies:
	For the first frame of the image, iOverallSizeInPixels will be the greater of the logical screen size 
	and the size of the first frame. The logical screen size is defined in the logical screen descriptor 
	block of the GIF image. If the GIF is animated it will contain a set of frames. The first frame will 
	be full size but subsequent frames are sub-frames and iOverallSizeInPixels may differ for each sub-frame.
	*/
	TSize iOverallSizeInPixels;

	/**
	The display mode for the frame.
	*/
	TDisplayMode iFrameDisplayMode;

	/**
	The background color for the frame.
	*/
	TRgb iBackgroundColor;

private:	
	TInt iFrameDataOffset;
	TInt iCurrentDataOffset;
	TFrameInfoState iCurrentFrameState;
	
public:
	/**
	The size of frame in pixels
	*/
	TSize iFrameSizeInPixels;

private:
	TInt iReserved_1;

friend class CImageDecoderPriv;
	};

#endif //__ImageData_h__
