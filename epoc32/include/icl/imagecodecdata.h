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
// ImageCodecData.h - data used by standard codecs
// 
//

/**
@file
@publishedAll
@released
*/


#ifndef __IMAGECODECDATA_H__
#define __IMAGECODECDATA_H__

#include <gdi.h>
#include <ezcompressor.h>
#include <icl/imagedata.h>

class CFrameImageData;


// Identification UIDs for TFrameDataBlock-derived classes

/** GIF image descriptor.
*/
const TUid KGIFImageDescriptorUid = { 0x101F45E4 };
/** GIF colour table
*/
const TUid KGIFColorTableUid = { 0x101F7C0A };
/** GIF compression type LZW information.
*/
const TUid KGIFLZWInfoUid = { 0x101F45E5 };
/** GIF image controller.
*/
const TUid KGIFImageControlUid = { 0x101F45E6 };
/** GIF loop iterations.
*/
const TUid KGIFLoopIterationsUid = { 0x102834A6 };
/** MBM decode data.
*/
const TUid KMBMDecodeDataUid = { 0x101F45E0 };
/** MBM encode data.
*/
const TUid KMBMEncodeDataUid = { 0x101F45E9 };
/** PNG encode data.
*/
const TUid KPNGEncodeDataUid = { 0x101F460A };
/** TIFF image data.
*/
const TUid KTIFFImageDataUid = { 0x101F45E8 };



//Identification UIDs for TImageDataBlock-derived classes

/** BMP image data.
*/
const TUid KBMPImageDataUid = { 0x101F45BF };
/** BMP compression.
*/
const TUid KBMPCompressionUid = { 0x101F45E3 };
/** JPG image data.
*/
const TUid KJPGImageDataUid = { 0x101F45DA };
/** JPG Q table.
*/
const TUid KJPGQTableUid = { 0x101F45E1 };
/** JPG comment.
*/
const TUid KJPGCommentUid = { 0x101F45E2 };
/** GIF background colour.
*/
const TUid KGIFBackgroundColorUid = { 0x101F45DE };
/** GIF comment.
*/
const TUid KGIFCommentUid = { 0x101F45E7 };

/** Max number of GIF palatte entries
*/
const TInt KGifColorTableMaxEntries = 256;

/**
@publishedAll
@released

BMP specific image data variant which holds bits per pixel info.
It is only used when configuring the BMP encoder.
If the Symbian bitmap encoder (0x101F45AE) is supplied then encoder specific defaults 
are used if this object is not presented to the conversion process.
The default bitmap colour depth is 24-bit.
@see CImageEncoder
@see CFrameImageData
*/
class TBmpImageData : public TImageDataBlock
	{
public:
	IMPORT_C TBmpImageData();

public:
	/** The number of bits/pixel.
	*/
	TInt iBitsPerPixel;

private:
	TImageDataBlock* DuplicateL(CFrameImageData& aFrameImageData) const;
	};

/**
@publishedAll
@released

BMP specific image data variant which holds compression info.
It is only used when extracting info from the BMP decoder.
*/
class TBmpCompression : public TImageDataBlock
	{
public:
	IMPORT_C TBmpCompression();

public:
	/**
	Flag reflecting the compression type.
	*/
	enum TCompression
	{
	/** No compression used.
	*/
	ENone,

	/** Eight bits per pixel run length encoding.
	*/
	EEightBppRLE,

	/** Four bits per pixel run length encoding.
	*/
	EFourBppRLE,

	/** Compression using bit fields.
	*/
	EBitFields
	};

public:
	/**
	@see enum TCompression

	The type of compression used
	*/
	TCompression iCompression;

private:
	TImageDataBlock* DuplicateL(CFrameImageData& aFrameImageData) const;
	};


/**
@publishedAll
@released

JPEG specific image data variant which holds color sampling and quality
factor information.

It can be used with both the JPEG decoder and encoder.
*/
class TJpegImageData : public TImageDataBlock
	{
public:
	/**
	Flag reflecting the color sampling type.
	*/
	enum TColorSampling
		{
		/** Monochrome.
		*/
		EMonochrome,

		/** Horizontal and vertical chrominance decimation.
		*/
		EColor420,

		/** Horizontal chrominance decimation.
		*/
		EColor422,

		/** No chrominance decimation.
		*/
		EColor444
		};
public:
	IMPORT_C TJpegImageData(); // Defaults to EColor420 and 75

public:
	/**
	@see enum TColorSampling

	The color sampling scheme to use.
	*/
	TColorSampling iSampleScheme;

	/** The quality factor. 
	
	This represents the current allowable percentage level of degradation when compressing the image 
	data.

	The range is 0 to 100 inclusive.
	*/
	TInt iQualityFactor; 

private:
	TImageDataBlock* DuplicateL(CFrameImageData& aFrameImageData) const;
	};

/** The number of JPEG Q table entries.

@see class TJpegQTable
*/
const TInt KJpgQTableEntries = 64;

/**
@publishedAll
@released

JPEG specific image data variant which holds QTable info.

It can be used with both the JPEG decoder and encoder.
*/
class TJpegQTable : public TImageDataBlock
	{
public:
	/**
	Flag reflecting the type of Q or quantization table.
	*/
	enum TQTableIndex
		{
		/** Luminance table.
		*/
		ELumaTable = 0,

		/** Chrominance table.
		*/
		EChromaTable = 1
		};
public:
	IMPORT_C TJpegQTable();

public:
	/** The type of Q table. */
	TInt iTableIndex;

	/** The number of entries in the Q table. */
	TBuf8<KJpgQTableEntries> iEntries;

private:
	TImageDataBlock* DuplicateL(CFrameImageData& aFrameImageData) const;
	};

/**
@publishedAll
@released

JPEG specific image data variant which holds JPEG comment information.

It can be used with both the JPEG decoder and encoder.
*/
class TJpegComment : public TImageDataBlock
	{
public:
	IMPORT_C TJpegComment();

public:
	/** The JPEG comment associated with the JPEG image.
	*/
	HBufC8* iComment;

private:
	TImageDataBlock* DuplicateL(CFrameImageData& aFrameImageData) const;
	};


/**
@publishedAll
@released

GIF specific image data variant which holds background color info.

It can only be used with the GIF decoder (the encoder is not configurable).
*/
class TGifBackgroundColor : public TImageDataBlock
	{
public:
	IMPORT_C TGifBackgroundColor();

public:
	/** The background colour as an index.
	*/
	TInt iBackgroundColorIndex;

	/** The background colour as an RGB value.
	*/
	TRgb iBackgroundColor;

private:
	TImageDataBlock* DuplicateL(CFrameImageData& aFrameImageData) const;
	};

/**
GIF specific frame data variant which holds image descriptor information.

It can only be used with the GIF decoder (the encoder is not configurable).

@publishedAll
@released
*/
class TGifImageDescriptor : public TFrameDataBlock
	{
public:
	IMPORT_C TGifImageDescriptor();

public:
	/** A boolean indicating if the frame has its own local colour map. ETrue if it does, otherwise
    EFalse.
	*/
	TBool iLocalColorMap;

	/** A boolean indicating if the frame's local colour map is sorted in priority order. ETrue if
    it is, otherwise EFalse.
	*/
	TBool iSortedLocalMap;

	/** A boolean indicating if the image is interlaced. ETrue if the image is interlaced.
	*/
	TBool iInterlaced;

private:
	TFrameDataBlock* DuplicateL(CFrameImageData& aFrameImageData) const;
	};

/**
@publishedAll
@released

GIF specific frame data for saving a frame local color map (palette).
*/
class TGifColorTable : public TFrameDataBlock
	{
public:
	IMPORT_C TGifColorTable();
   
public:
    /** The palette */
	TRgb iPalette[KGifColorTableMaxEntries];

private:
	TFrameDataBlock* DuplicateL(CFrameImageData& aFrameImageData) const;
	};

/**
@publishedAll
@released

GIF specific frame data variant which holds LZW compression information.

It can only be used with the GIF decoder (the encoder is not configurable).
*/
class TGifLZWInfo : public TFrameDataBlock
	{
public:
	IMPORT_C TGifLZWInfo();

public:
	/** The initial number of bits used in LZW compression. 
	*/
	TInt iInitialCodeLength;

	/** The size of compressed frame.
	*/
	TInt iCompressedBytes;

private:
	TFrameDataBlock* DuplicateL(CFrameImageData& aFrameImageData) const;
	};

/**
@publishedAll
@released

GIF specific frame data variant which holds GIF image control information.

It can only be used with the GIF decoder (the encoder is not configurable).
*/
class TGifImageControl : public TFrameDataBlock
	{
public:
	/**
	Flag reflecting how the previous frame is handled when the next frame is drawn.
	*/
	enum TDisposalMethod
		{
		/** No method set.
		*/
		ENone = 0,

		/** Leave the previous frame in place.
		*/
		ELeaveInPlace = 1,

		/** Restore to the backgound colour.
		*/
		ERestoreToBackground = 2,

		/** Restore the previous frame.
		*/
		ERestoreToPrevious = 3
		};

public:
	IMPORT_C TGifImageControl();

public:
	/** The interval between display of successive frames in units of 1/100 second.
	*/
	TInt iDelayTimeInCentiseconds;

	/** The colour index to be used for transparency.
	*/
	TInt iTransparentColorIndex;

	/** A flag indicating if user input is required before display of next frame.
	*/
	TBool iUserInputFlag;

	/** The frame disposal method for multiframe images.
	*/
	TDisposalMethod iDisposalMethod;

private:
	TFrameDataBlock* DuplicateL(CFrameImageData& aFrameImageData) const;
	};

/**
@publishedAll
@released

GIF specific image data variant which holds GIF comment info.

It can only be used with the GIF decoder (the encoder is not configurable).
*/
class TGifComment : public TImageDataBlock
	{
public:
	IMPORT_C TGifComment();

public:
	/** The comment associated with the GIF image. 
	*/
	HBufC8* iComment;

private:
	TImageDataBlock* DuplicateL(CFrameImageData& aFrameImageData) const;
	};

/**
@publishedAll
@released

GIF specific image data variant which holds Netscape 2.0 Application Extension block loop iterations value

It can only be used with the GIF decoder (the encoder is not configurable).
*/
class TGifLoopIterations : public TImageDataBlock
    {
public:
    IMPORT_C TGifLoopIterations();

public:
    /** The number of times to loop an animated GIF
    */
    TInt iLoopIterations;

private:
    TImageDataBlock* DuplicateL(CFrameImageData& aFrameImageData) const;
    };

// Mbm compression data. (Decoder only)
/**
@publishedAll
@released

MBM specific frame data variant which holds frame data information.

It can only be used with the MBM decoder.
*/
class TMbmDecodeData : public TFrameDataBlock
	{
public:
	IMPORT_C TMbmDecodeData();

public:
	/** A flag indicating if RLE compression is used. 
	*/
	TBool iCompressed;

	/** The uncompressed frame size in bytes.
	*/
	TInt iImageDataSizeInBytes;

private:
	TFrameDataBlock* DuplicateL(CFrameImageData& aFrameImageData) const;
	};


// Mbm display mode. (Encoder only)
/**
@publishedAll
@released

MBM specific image data variant which holds frame data information.

It can only be used with the MBM encoder.
*/
class TMbmEncodeData : public TFrameDataBlock
	{
public:
	IMPORT_C TMbmEncodeData();

public:
	/** The display mode.
	*/
	TDisplayMode iDisplayMode;

private:
	TFrameDataBlock* DuplicateL(CFrameImageData& aFrameImageData) const;
	};


/**
@publishedAll
@released

PNG specific frame data variant which holds PNG encoding information.

It can only be used with the PNG encoder.
*/
class TPngEncodeData : public TFrameDataBlock
	{
public:
	// Same values as CEZCompressor
	/**
	A flag reflecting the level of compression used.
	*/
	enum TPngCompressLevel
		{
		/**
		Default level of compression used.
		*/
		EDefaultCompression = Z_DEFAULT_COMPRESSION,

		/** No compression used.
		*/
		ENoCompression = Z_NO_COMPRESSION,

		/** Optimise compression for speed.
		*/
		EBestSpeed = Z_BEST_SPEED,

		/** Optimise compression for size.
		*/
		EBestCompression = Z_BEST_COMPRESSION
		};
public:
	IMPORT_C TPngEncodeData();

public:
	/** The number of bits per pixel.
	*/
	TInt iBitsPerPixel;

	/** A flag indicating if the image is color or grayscale.
	*/
	TBool iColor;

	/** A flag indicating use of a palette or RGB.
	*/
	TBool iPaletted;

	/** The level of compression to apply.
	*/
	TPngCompressLevel iLevel;

private:
	TFrameDataBlock* DuplicateL(CFrameImageData& aFrameImageData) const;
	};

/**
@publishedAll
@released

TIFF specific frame data variant. Holds colour sampling and quality factor information.

It can only be used with the TIFF decoder.
*/
class TTiffImageData : public TFrameDataBlock
	{
public:
	IMPORT_C TTiffImageData();

public:
	/** The new subfile type.
	*/
	TUint32				iNewSubfileType;

	/** The frame size in pixels.
	*/
	TSize				iSizeInPixels;

	/** The number of bits per sample.
	*/
	TInt				iBitsPerSample;

	/** The number of samples per pixel.
	*/
	TInt				iSamplesPerPixel;

	/** The compression setting.
	*/
	TInt				iCompression;

	/** T4 options as per the "Standardization of Group 3 facsimile apparatus for document 
	transmission, Recommendation T.4, Volume VII, Fascicle VII.3".
	*/
	TInt				iT4Options;

	/** T6 options as per the "Facsimile Coding Schemes and Coding Control Functions for Group 4 
	Facsimile Apparatus, Recommendation T.6, Volume VII, Fascicle VII.3".
	*/
	TInt				iT6Options;

	/** The photometric interpretation setting.
	*/
	TInt				iPhotometricInterpretation;

	/** The fill order.
	*/
	TInt				iFillOrder;

	/** The frame width in twips.
	*/
	TReal				iWidthInTwips;

	/** The frame height in twips.
	*/
	TReal				iHeightInTwips;

	/** The number of rows per strip.
	*/
	TInt				iRowsPerStrip;

	/** The number of TTiffImageStrips.
	*/
	TInt				iNumStrips;

	/** An array of TTiffImageStrips.
	*/
	HBufC8*				iStripInfo;

private:
	TFrameDataBlock* DuplicateL(CFrameImageData& aFrameImageData) const;
	};

// Identification UIDs for image types.

/** Image type BMP.
*/
const TUid KImageTypeBMPUid = {0x101F45B0};
/** Image type GIF.
*/
const TUid KImageTypeGIFUid = {0x101F45B3};
/** Image type WMF.
*/
const TUid KImageTypeWMFUid = {0x101F45BA};
/** Image type WMF subtype Std.
*/
const TUid KImageTypeWMFSubTypeStdUid = {0x101F45BB};
/** Image type WMF subtype Apm.
*/
const TUid KImageTypeWMFSubTypeApmUid = {0x101F45BC};
/** Image type WMF subtype Clp.
*/
const TUid KImageTypeWMFSubTypeClpUid = {0x101F45BD};
/** Image type TIFF.
*/
const TUid KImageTypeTIFFUid = {0x101F45C4};
/** Image type TIFF subtype LittleEndian.
*/
const TUid KImageTypeTIFFSubTypeLittleEndianUid = {0x101F45C5};
/** Image type TIFF subtype BigEndian.
*/
const TUid KImageTypeTIFFSubTypeBigEndianUid = {0x101F45C6};
/** Image type PNG.
*/
const TUid KImageTypePNGUid = {0x101F45C9};
/** Image type MBM.
*/
const TUid KImageTypeMBMUid = {0x101F45CC};
/** Image type WBMP.
*/
const TUid KImageTypeWBMPUid = {0x101F45CF};
/** Image type OTA.
*/
const TUid KImageTypeOTAUid = {0x101F45D2};
/** Image type ICO.
*/
const TUid KImageTypeICOUid = {0x101F45D5};
/** Image type JPG.
*/
const TUid KImageTypeJPGUid = {0x101F45D8};

#endif // __IMAGECODECDATA_H__
