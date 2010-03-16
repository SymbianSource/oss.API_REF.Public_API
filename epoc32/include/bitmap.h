// Copyright (c) 1995-2009 Nokia Corporation and/or its subsidiary(-ies).
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

#if !defined(__BITMAP_H__)
#define __BITMAP_H__
#if !defined(__E32STD_H__)
#include <e32std.h>
#endif
#if !defined(__F32FILE_H__)
#include <f32file.h>
#endif
#if !defined(__GDI_H__)
#include <gdi.h>
#endif

#ifdef _DEBUG
	#define SYMBIAN_DEBUG_FBS_LOCKHEAP
#endif

/**
@internalComponent
*/
const TUid KCBitwiseBitmapUid={268435520};
const TUid KCBitwiseBitmapHardwareUid={0x10009a3d};
const TUid KMultiBitmapFileImageUid={268435522};
const TInt KCompressionBookMarkThreshold=0x2000;
const TInt KNumBytesPerBitmapHandle = sizeof(TInt); 						// Bitmap handle is the size of a TInt
const TInt KMaxBitmapHandleBufferSize = KNumBytesPerBitmapHandle * 2000; 	// Maximum size of buffer to store all bitmap handles. 

//Forward declarations
class CChunkPile;
class TCompressionBookMark;

/** 
Defines the types of file compression. 
@publishedAll
@released
*/
enum TBitmapfileCompression
	{
	/** Bitmap file is not compressed. */
	ENoBitmapCompression,
	/** File is compressed using run-length encoding compression. */
	EByteRLECompression,
	/** File is compressed using twelve bit run-length encoding compression. */
	ETwelveBitRLECompression,
	/** File is compressed using sixteen bit run-length encoding compression. */
	ESixteenBitRLECompression,
	/** File is compressed using twenty four bit run-length encoding compression. */
	ETwentyFourBitRLECompression,
	/** File is compressed using twenty four bit run-length encoding compression from 32-bit bitmap buffer. */
	EThirtyTwoUBitRLECompression,
	/** File is compressed using thirty two bit run-length encoding compression from 32-bit bitmap buffer. */
	EThirtyTwoABitRLECompression,
	/** File is compressed as a palette plus reduced bit-per-pixel.  Only applicable to bitmaps already loaded in RAM. */
	EGenericPaletteCompression,
	//Insert new enum items here!
	ERLECompressionLast = 255
	};

/** 
Defines the available file compression schemes. 
@publishedAll
@released
*/
enum TBitmapfileCompressionScheme
	{
	/** File is compressed using run-length encoding compression. */
	ERLECompression,
	/** File is compressed as a palette plus reduced bit-per-pixel. */
	EPaletteCompression,
	/** File is compressed as a palette plus reduced bit-per-pixel, with automatic fallback to RLE if bitmap is not suitable*/
	EPaletteCompressionWithRLEFallback
	};

/**
@internalTechnology
*/
typedef void (*TAssignFunction)(TUint8*& aDestPtr, TUint32 aColor);

/**
@internalTechnology
*/
typedef void (*TDecodeFunction)(TUint8* aDataPtr, TUint32* aPalettePtr, TUint8*& aDestPtr, TAssignFunction aAssignFunction);

class TRgb24bit
/**
@internalComponent
*/
	{
public:
	TUint8 iRed;
	TUint8 iGreen;
	TUint8 iBlue;
	};

/** 
Contains information about the bitmap when streaming bitmaps to stores. 
@publishedAll
@released
*/
class SEpocBitmapHeader
	{
public:
	inline SEpocBitmapHeader() :
		iBitmapSize(sizeof(SEpocBitmapHeader)),
		iStructSize(sizeof(SEpocBitmapHeader)),
		iSizeInPixels(0, 0),
		iSizeInTwips(0, 0),
		iBitsPerPixel(0),
		iColor(0),
		iPaletteEntries(0),
		iCompression(ENoBitmapCompression)
		{
		}
public:
	/** Defines whether bitmap is colour and if it comprises an alpha channel. */ 
	enum TColor 
		{
		/** Bitmap doesn't comprise color */
		ENoColor=0, 
		/** Bitmap comprises color */
		EColor=1, 
		/** Bitmap comprises color with alpha channel */
		EColorAlpha=2, 
		/** Bitmap comprises pre-multiplied colors with alpha channel */
		EColorAlphaPM=3,
		/** Unknown format */
		EColorUndefined=8
		};
public:
	/** The size of the bitmap data, in bytes. */
	TInt iBitmapSize;
	/** The size of the structure in which the bitmap data is stored. */
	TInt iStructSize;
	/** The size of the bitmap, in pixels. */
	TSize iSizeInPixels;
	/** The size of the bitmap, in twips. */
	TSize iSizeInTwips;
	/** The bitmap's number of bits per pixel */
	TInt iBitsPerPixel;
	/** Whether or not the bitmap is colour and comprises an alpha value. */
	TInt iColor;
	/** The number of entries in the bitmap's palette. */
	TInt iPaletteEntries;
	/** The type of compression used to store the bitmap. */
	TBitmapfileCompression iCompression;
	};

class TLineScanningPosition
/**
@internalTechnology
*/
	{
public:
	TLineScanningPosition(TUint32* aSrcDataPtr): iSrcDataPtr((TUint8*)aSrcDataPtr), iCursorPos(0), iScanLineBuffer(NULL) {}
public:
	TUint8* iSrcDataPtr;
	TInt iCursorPos;
	HBufC8* iScanLineBuffer;
	};

class CShiftedFileStore;
/**
BitGdi bitmap class (pseudo-CXxx class).
@internalComponent
@released
*/
class CBitwiseBitmap
	{
	friend class CFbTop;
	friend class CFbClient;
	friend class CFbsBitmap;
	friend class CBitmapObject;
	friend class CFbsBitmapAsyncStreamer;
	friend class CFbsBackgroundCompression;
	friend class CleanupDelete<CBitwiseBitmap>;
public:
	IMPORT_C TUid Uid() const;
	IMPORT_C void ExternalizeL(RWriteStream& aStream,const CFbsBitmap& aHandleBitmap) const;
	IMPORT_C void ExternalizeRectangleL(RWriteStream& aStream,const TRect& aRect,const CFbsBitmap& aHandleBitmap) const;
	IMPORT_C void InternalizeL(RReadStream& aStream);
	IMPORT_C static void InternalizeHeaderL(RReadStream& aStream,SEpocBitmapHeader& aHeader);
	IMPORT_C TSize SizeInPixels() const;
	IMPORT_C TSize SizeInTwips() const;
	IMPORT_C TDisplayMode DisplayMode() const;
	IMPORT_C TInt HorizontalTwipsToPixels(TInt aTwips) const;
	IMPORT_C TInt VerticalTwipsToPixels(TInt aTwips) const;
	IMPORT_C TInt HorizontalPixelsToTwips(TInt aPixels) const;
	IMPORT_C TInt VerticalPixelsToTwips(TInt aPixels) const;
	IMPORT_C void GetPixel(TRgb& aColor,const TPoint& aPos,TUint32* aBase) const;
	IMPORT_C TInt GetScanLinePtr(TUint32*& aSlptr, TPoint& aPixel,TInt aLength, TUint32* aBase, TLineScanningPosition& aLineScanningPosition) const;
	IMPORT_C TInt GetScanLinePtr(TUint32*& aSlptr, TInt& aLength, TPoint& aPixel,TUint32* aBase, TLineScanningPosition& aLineScanningPosition) const;
	IMPORT_C void GetScanLine(TDes8& aBuf,const TPoint& aPixel,TInt aLength,TBool aDither,const TPoint& aDitherOffset,TDisplayMode aDispMode,TUint32* aBase, TLineScanningPosition& aLineScanningPosition) const;
	IMPORT_C void GetScanLine(TUint32*& aSlptr, TDes8& aBuf,const TPoint& aPixel,TInt aLength,TBool aDither,const TPoint& aDitherOffset,TDisplayMode aDispMode) const;
	IMPORT_C void GetScanLine(TDes8& aBuf,const TPoint& aPixel,TInt aLength,TBool aDither,const TPoint& aDitherOffset,TDisplayMode aDispMode,TUint32* aBase) const;
	IMPORT_C void GetVerticalScanLine(TDes8& aBuf,TInt aX,TBool aDither,const TPoint& aDitherOffset,TDisplayMode aDispMode,TUint32* aBase) const;
	IMPORT_C void StretchScanLine(TDes8& aBuf,const TPoint& aPixel,TInt aClipStrchX,TInt aClipStrchLen,TInt aStretchLength,TInt aOrgX,TInt aOrgLen,const TPoint& aDitherOffset,TDisplayMode aDispMode,TUint32* aBase) const;
	IMPORT_C void StretchScanLine(TDes8& aBuf,const TPoint& aPixel,TInt aClipStrchX,TInt aClipStrchLen,TInt aStretchLength,TInt aOrgX,TInt aOrgLen,const TPoint& aDitherOffset,TDisplayMode aDispMode,TUint32* aBase, TLineScanningPosition& aLineScanningPosition) const;
	IMPORT_C TUint32* ScanLineAddress(TUint32* aBase,TUint aY) const;
	IMPORT_C TBool IsMonochrome(TUint32* aBase) const;
	IMPORT_C TBool IsLargeBitmap() const;
	IMPORT_C TInt CompressData();
	IMPORT_C TInt CompressData(TBitmapfileCompressionScheme aScheme);
	IMPORT_C TInt CheckBackgroundCompressData();
	IMPORT_C void SetCompressionBookmark(TLineScanningPosition& aLineScanningPosition, TUint32* aBase, const CFbsBitmap* aFbsBitmap);
	IMPORT_C TInt HardwareBitmapHandle() const;
	IMPORT_C TBool IsCompressedInRAM() const;
	IMPORT_C TBool IsCompressed() const;
	IMPORT_C TInt DataStride() const;
	IMPORT_C SEpocBitmapHeader Header() const;
private:
	IMPORT_C void operator delete(TAny*);
	void operator delete(TAny*, TAny*) {}     // This function exists only to prevent a compiler warning
	IMPORT_C CBitwiseBitmap(RHeap* aHeap,CChunkPile* aPile);
	IMPORT_C ~CBitwiseBitmap();
	IMPORT_C void Reset();
	IMPORT_C TInt Construct(const TSize& aSize,TDisplayMode aDispMode,TUid aCreatorUid);
	IMPORT_C void ConstructL(RFs& aFs,const TDesC& aFilename,TInt32 aId,TUint aFileOffset);
	IMPORT_C void ConstructL(RFile& aFile,TInt32 aId,TUint aFileOffset);
	IMPORT_C void ConstructL(CShiftedFileStore* aFileStore,TStreamId aStreamId);
	IMPORT_C TInt CopyData(const CBitwiseBitmap& aSourceBitmap);
private:
	void GenerateLineFromCompressedTwelveBitData(TUint8* aDestBuffer, const TPoint& aPixel,TInt aLength,TUint32* aBase, TLineScanningPosition& aLineScanningPosition) const;
	void GenerateLineFromCompressedEightBitData(TUint8* aDestBuffer, const TPoint& aPixel,TInt aLength,TUint32* aBase, TLineScanningPosition& aLineScanningPosition) const;
	TUint8 GetGrayPixelEx(TInt aX,TUint32* aScanLineAddress) const;
	TRgb GetRgbPixelEx(TInt aX,TUint32* aScanLineAddress) const;
	void GetRgbPixelExMany(TInt aX,TUint32* aScanlinePtr,TUint32* aDest,TInt aLength) const;
    void GetRgbPixelExMany16M(TInt aX,TUint32* aScanlinePtr,TUint8* aDest,TInt aLength) const;
    void GetRgbPixelExMany16MAP(TInt aX,TUint32* aScanlinePtr,TUint32* aDest,TInt aLength) const;
	void GetScanLineGray2(TDes8& aBuf,const TPoint& aPixel,TInt aLength,TBool aDither,const TPoint& aDitherOffset,TUint32* aScanlinePtr) const;
	void GetScanLineGray4(TDes8& aBuf,const TPoint& aPixel,TInt aLength,TBool aDither,const TPoint& aDitherOffset,TUint32* aScanlinePtr) const;
	void GetScanLineGray16(TDes8& aBuf,const TPoint& aPixel,TInt aLength,TUint32* aScanlinePtr) const;
	void GetScanLineGray256(TDes8& aBuf,const TPoint& aPixel,TInt aLength,TUint32* aScanlinePtr) const;
	void GetScanLineColor16(TDes8& aBuf,const TPoint& aPixel,TInt aLength,TUint32* aScanlinePtr) const;
	void GetScanLineColor256(TDes8& aBuf,const TPoint& aPixel,TInt aLength,TUint32* aScanlinePtr) const;
	void GetScanLineColor4K(TDes8& aBuf,const TPoint& aPixel,TInt aLength,TUint32* aScanlinePtr) const;
	void GetScanLineColor64K(TDes8& aBuf,const TPoint& aPixel,TInt aLength,TUint32* aScanlinePtr) const;
	void GetScanLineColor16M(TDes8& aBuf,const TPoint& aPixel,TInt aLength,TUint32* aScanlinePtr) const;
	void GetScanLineColor16MU(TDes8& aBuf,const TPoint& aPixel,TInt aLength,TUint32* aScanlinePtr) const;
	void GetScanLineColorRgb(TDes8& aBuf,const TPoint& aPixel,TInt aLength,TUint32* aScanlinePtr) const;
	void GetScanLineExBits(TDes8& aBuf,TInt aX,TInt aLength,TUint32* aScanlinePtr) const;
	void GetScanLineExBytes(TDes8& aBuf,TInt aX,TInt aLength,TUint32* aScanlinePtr) const;
	void DoExternalizeDataCompressedL(RWriteStream& aStream,TUint8* aData,TInt aSizeInBytes) const;
	void DoExternalizeByteDataCompressedL(RWriteStream& aStream,TUint8* aData,TInt aSizeInBytes) const;
	void DoExternalizeTwelveBitDataCompressedL(RWriteStream& aStream,TUint8* aData,TInt aSizeInBytes) const;
	void DoExternalizeSixteenBitDataCompressedL(RWriteStream& aStream,TUint8* aData,TInt aSizeInBytes) const;
	void DoExternalizeTwentyFourBitDataCompressedL(RWriteStream& aStream,TUint8* aData,TInt aSizeInBytes) const;
	void DoExternalizeThirtyTwoUBitDataCompressedL(RWriteStream& aStream,TUint8* aData,TInt aSizeInBytes) const;
	void DoExternalizeThirtyTwoABitDataCompressedL(RWriteStream& aStream,TUint8* aData,TInt aSizeInBytes) const;
	TInt SizeOfDataCompressed(TUint8* aData,TInt aSizeInBytes) const;
	TInt SizeOfByteDataCompressed(TUint8* aData,TInt aSizeInBytes) const;
	TInt SizeOfTwelveBitDataCompressed(TUint8* aData,TInt aSizeInBytes) const;
	TInt SizeOfSixteenBitDataCompressed(TUint8* aData,TInt aSizeInBytes) const;
	TInt SizeOfTwentyFourBitDataCompressed(TUint8* aData,TInt aSizeInBytes) const;
	TInt SizeOfThirtyTwoUBitDataCompressed(TUint8* aData,TInt aSizeInBytes) const;
	TInt SizeOfThirtyTwoABitDataCompressed(TUint8* aData,TInt aSizeInBytes) const;
	TBool TrueColorPointerCompare(TUint8* aColorPointer,TUint8 aComponent1,TUint8 aComponent2,TUint8 aComponent3) const;
	TBool ColorAlphaPointerCompare(TUint8* aColorPointer,TUint8 aComponent1,TUint8 aComponent2,TUint8 aComponent3,TUint8 aComponent4) const;
	void DoInternalizeL(RReadStream& aStream,TInt aSrceSize,TUint32* aBase);
	void DoInternalizeCompressedDataL(RReadStream& aStream,TInt aSrceSize,TUint32* aBase,TBitmapfileCompression aCompression);
	void DoDecompressByteData(TUint8* aDestBuffer,TInt aDestSize,TUint8* aSrceBuffer,TInt aSrceSize);

	void DoDecompressByteDataAltL(RReadStream& aStream,TInt aSrceSizeInBytes,TUint32* aBase);
	void DoDecompressTwelveBitData(TUint8* aDestBuffer,TInt aDestSize,TUint8* aSrceBuffer,TInt aSrceSize);
	void DoDecompressTwelveBitDataAltL(RReadStream& aStream,TInt aSrceSizeInBytes,TUint32* aBase);
	void DoDecompressSixteenBitData(TUint8* aDestBuffer,TInt aDestSize,TUint8* aSrceBuffer,TInt aSrceSize);
	void DoDecompressSixteenBitDataAltL(RReadStream& aStream,TInt aSrceSizeInBytes,TUint32* aBase);
	void DoDecompressTwentyFourBitData(TUint8* aDestBuffer,TInt aDestSize,TUint8* aSrceBuffer,TInt aSrceSize);
	void DoDecompressTwentyFourBitDataAltL(RReadStream& aStream,TInt aSrceSizeInBytes,TUint32* aBase);
	void DoDecompressThirtyTwoUBitData(TUint8* aDestBuffer,TInt aDestSize,TUint8* aSrceBuffer,TInt aSrceSize);
	void DoDecompressThirtyTwoUBitDataAltL(RReadStream& aStream,TInt aSrceSizeInBytes,TUint32* aBase);
	void DoDecompressThirtyTwoABitData(TUint8* aDestBuffer,TInt aDestSize,TUint8* aSrceBuffer,TInt aSrceSize);
	void DoDecompressThirtyTwoABitDataAltL(RReadStream& aStream,TInt aSrceSizeInBytes,TUint32* aBase);
	void DoStretchScanLine(TDes8& aBuf,TInt x,TInt y,TInt aClipStrchX,TInt aClipStrchLen,TInt aStretchLength,TInt aOrgX,TInt aOrgLen,const TPoint& aDitherOffset,TDisplayMode aDispMode,TUint32* aBase,TLineScanningPosition& aLineScanningPosition) const;
	void DoCompressScanLine(TDes8& aBuf,TInt x,TInt y,TInt aClipStrchX,TInt aClipStrchLen,TInt aStretchLength,TInt aOrgX,TInt aOrgLen,const TPoint& aDitherOffset,TDisplayMode aDispMode,TUint32* aBase,TLineScanningPosition& aLineScanningPosition) const;
	TUint32 HashTo1bpp(TUint32 aGray256,TBool aOddX,TBool aOddY) const;
	TUint32 HashTo2bpp(TUint32 aGray256,TInt aDitherIndex) const;
	TBool IsWordMonochrome(TUint32 aWord) const;
	TUint32* DataAddress() const;
	static void WhiteFill(TUint8* aData,TInt aDataSize,TDisplayMode aDispMode);
	static TInt ByteWidth(TInt aPixelWidth,TDisplayMode aDispMode);
	static TInt Bpp(TDisplayMode aDispMode);
	static TInt IsColor(TDisplayMode aDispMode);
	static TDisplayMode DisplayMode(TInt aBpp,TInt aColor);
	static TBitmapfileCompression CompressionType(TInt aBpp, TInt aColor);
	TInt DoGetScanLinePtr(TUint32*& aSlptr, TPoint& aPixel,TInt aLength, TUint32* aBase, TLineScanningPosition& aLineScanningPosition) const;
	void GenerateLineFromCompressedSixteenBitData(TUint8* aDestBuffer, const TPoint& aPixel,TInt aLength, TUint32* aBase, TLineScanningPosition& aLineScanningPosition) const;
	TDisplayMode InitialDisplayMode() const;
	TInt SetDisplayMode(TDisplayMode aDisplayMode, TUint32* aDataAddress);
	TInt DisplayModeArgCheck(TDisplayMode aDisplayMode, TUint32* aDataAddress) const;
	void ChangeDisplayMode( TDisplayMode aNewDisplayMode,
							TInt aScanLineWidthNew,
							TUint8* aDataAddrNew,
							TUint32* aDataAddress,
							TInt aYStart,
							TInt aYInc,
							TInt aYEnd);
	void UpdateBitmapProperties(TDisplayMode aNewDisplayMode);
	TInt SwapWidthAndHeight(TUint32* aDataAddress);	
	void GenerateLineFromCompressed24BitData(TUint8* aDestBuffer, const TPoint& aPixel,TInt aLength, TUint32* aBase, TLineScanningPosition& aLineScanningPosition) const;
	void GenerateLineFromCompressed32UBitData(TUint8* aDestBuffer, const TPoint& aPixel,TInt aLength, TUint32* aBase, TLineScanningPosition& aLineScanningPosition) const;
	void GenerateLineFromCompressed32ABitData(TUint8* aDestBuffer, const TPoint& aPixel,TInt aLength, TUint32* aBase, TLineScanningPosition& aLineScanningPosition) const;
	void AdjustXCoord(TInt& aX) const;
	void GetLineScanPos(TLineScanningPosition& aLineScanPos, 
						const TCompressionBookMark*& aComprBookMark, 
						const TUint8* aBase) const;
	void UpdateBookMark(const TLineScanningPosition& aLineScanPos, 
						TCompressionBookMark* aComprBookMark, 
						const TUint8* aBase) const;
	void GetScanLineColor16MA(TDes8& aBuf,const TPoint& aPixel,TInt aLength,TUint32* aScanlinePtr) const;
	void GetScanLineColor16MAP(TDes8& aBuf,const TPoint& aPixel,TInt aLength,TUint32* aScanlinePtr) const;
	TInt PaletteCompress();
	void GenerateLineFromPaletteCompressedData(TUint8* aDestBuffer, const TPoint& aPixel,TInt aLength, TUint32* aBase, TLineScanningPosition& aLineScanningPosition) const;
	TUint PaletteBitsPerPixel(TInt aNumColors) const;
	TUint PaletteBytesPerPixel(TInt aBitsPerPixel) const;
	void PaletteDecodeAndAssignGeneric(TUint8* aDataPtr, TUint32* aPalettePtr, TUint8*& aDestPtr, TUint aStartPixel, TUint aEndPixel, TUint aCompressedPixelsPerByte, TUint aCompressedBitsPerPixel) const;
	static void PaletteDecode1PixelPerByte(TUint8* aDataPtr, TUint32* aPalettePtr, TUint8*& aDestPtr, TAssignFunction aAssignFunction);
	static void PaletteDecode2PixelPerByte(TUint8* aDataPtr, TUint32* aPalettePtr, TUint8*& aDestPtr, TAssignFunction aAssignFunction);
	static void PaletteDecode4PixelPerByte(TUint8* aDataPtr, TUint32* aPalettePtr, TUint8*& aDestPtr, TAssignFunction aAssignFunction);
	static void PaletteDecode8PixelPerByte(TUint8* aDataPtr, TUint32* aPalettePtr, TUint8*& aDestPtr, TAssignFunction aAssignFunction);
	static void PaletteAssign16BitColor(TUint8*& aDestPtr, TUint32 aColor);
	static void PaletteAssign24BitColor(TUint8*& aDestPtr, TUint32 aColor);
	static void PaletteAssign32BitColor(TUint8*& aDestPtr, TUint32 aColor);
	void UpdatePaddingData(TUint32* aData);
	static void CheckHeaderIsValidL(const SEpocBitmapHeader& aHeader);
	static TInt CompressedFormatInfo(TDisplayMode aDispMode, TInt& aBytesPerPack, TInt& aBytesPerCompressed);
	static void BitmapFill32(TUint32* aDestPtr32, TInt aCount, TUint32 aValue32);
	static inline void BitmapFill16(TUint16* aDestPtr16, TInt aCount, TUint16 aValue16);
private:
	TUid iUid;
	struct TSettings
		{
		TSettings(TDisplayMode aDisplayMode);
		void SetDisplayModes(TDisplayMode aDisplayMode);
		void SetCurrentDisplayMode(TDisplayMode aDisplayMode);
		TDisplayMode CurrentDisplayMode() const;
		TDisplayMode InitialDisplayMode() const;
		inline void SetDirtyBitmap();
		inline TBool IsDirtyBitmap() const;
		enum
			{
			EBitmapFlagDirty = 0x10000 // set in the old bitmap when a re-allocating operation has created a new bitmap
			};
		TUint32 iData;
		} iSettings;
	RHeap* iHeap;
	CChunkPile* iPile;
	TInt iByteWidth;
	SEpocBitmapHeader iHeader;
	struct TExtra // used only in builds with SYMBIAN_DEBUG_FBS_LOCKHEAP defined
		{
		TInt iLockCount; // number of calls to CFbsBitmap::LockHeap() not balanced by calls to CFbsBitmap::UnlockHeap()
		TThreadId iThreadId; // id of thread that called CFbsBitmap::LockHeap() if any
		}
		*iExtra; // only for bitmaps created in RAM, set to 0xFFFFFFFF for ROM bitmaps by the tool chain
	TInt iDataOffset; // offset in bytes from "this" or from base of bitmap chunk, or hardware bitmap handle
	TBool iIsCompressedInRAM; //flag indicating whether CompressData has been called
	};

#endif
