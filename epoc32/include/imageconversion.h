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
// This is the public client API for the Image Conversion Library
// 
//

#ifndef IMAGECONVERSION_H
#define IMAGECONVERSION_H

#include <fbs.h>
#include <bitdev.h>
#include <badesca.h>
#include <ecom/implementationinformation.h>
#include <mm/mmcaf.h>

#include <icl/imagecodecdata.h>
#include <icl/imagedata.h>
#include <icl/icl_uids.hrh>
#include <icl/imageconversionextension.h>

#ifndef SYMBIAN_ENABLE_SPLIT_HEADERS
#include <iclrecognizerutil.h>
#endif

class MImageDecoderRelay;
class MImageEncoderRelay;
class CImageDecoderPlugin;
class CImageEncoderPlugin;
class CImageDecodeConstruct;
class CImageEncodeConstruct;

/**
@publishedAll
@released

Container type to manage lists of UIDs.
*/
typedef RArray<TUid> RUidDataArray;	

/**
@publishedAll
@released

Class used to manage the mapping between an image's type, sub-type and description.
*/
class CImageTypeDescription : public CBase
	{
public:
	/**
	@internalComponent
	*/
	static CImageTypeDescription* NewL(const TDesC& aDescription, const TUid aImageType, const TUid aSubType);
	/**
	@internalComponent
	*/
	static CImageTypeDescription* NewLC(const TDesC& aDescription, const TUid aImageType, const TUid aSubType);
	
	IMPORT_C ~CImageTypeDescription();
	IMPORT_C const TDesC& Description() const;
	IMPORT_C TUid ImageType() const;
	IMPORT_C TUid SubType() const;
private:
	CImageTypeDescription(const TUid aImageType, const TUid aSubType);
	void ConstructL(const TDesC& aDescription);
private:
	HBufC* iDescription;
	const TUid iImageType;
	const TUid iSubType;
	};

/**
Container type to manage lists of pointers to CImageTypeDescription objects.

@publishedAll
@released
*/
typedef RPointerArray<CImageTypeDescription> RImageTypeDescriptionArray;

/**
Class used to manage the mapping between an image's MIME type & file extension.

@publishedAll
@released
*/
class CFileExtensionMIMEType : public CBase
	{
public:
	/**
	@internalComponent
	*/
	static CFileExtensionMIMEType* NewL(const TDesC8& aExtn, const TDesC8& aMIMEType, const TDesC& aDisplayName, TUid aImageType, TUid aImageSubType, TUid aImplementationUid);
	IMPORT_C static CFileExtensionMIMEType* NewLC(const TDesC8& aExtn, const TDesC8& aMIMEType, const TDesC& aDisplayName, TUid aImageType, TUid aImageSubType, TUid aImplementationUid);
	IMPORT_C ~CFileExtensionMIMEType();

	IMPORT_C const TDesC& FileExtension() const;
	IMPORT_C const TDesC8& MIMEType() const;
	IMPORT_C const TDesC& DisplayName() const;
	IMPORT_C TUid ImageType() const;
	IMPORT_C TUid ImageSubType() const;
	IMPORT_C TUid ImplementationUid() const;
private:
	CFileExtensionMIMEType();
	void ConstructL(const TDesC8& aExtn, const TDesC8& aMIMEType, const TDesC& aDisplayName, TUid aImageType, TUid aImageSubType, TUid aImplementationUid);
private:
	HBufC* iFileExtension;
	HBufC8* iMIMEType;
	HBufC* iDisplayName;
	TUid iImageTypeUid;
	TUid iImageSubTypeUid;
	TUid iImplementationUid;
	};

/**
Container type to manage lists of pointers to CFileExtensionMIMEType objects.

@publishedAll
@released
*/
typedef RPointerArray<CFileExtensionMIMEType> RFileExtensionMIMETypeArray;

/**
@publishedAll
@released

Class used to manage various information about an implementation
which is stored in resource files.

@see CImplementationInformation
*/
class CImplementationInformationType : public CBase
	{
public:
	/**
	@internalComponent
	*/
	static CImplementationInformationType* NewL();
	/**
	@internalComponent
	*/
	static CImplementationInformationType* NewLC();

	IMPORT_C ~CImplementationInformationType();
	
	/**
	@internalComponent
	*/
	void SetDataL(TUid aImplementationUid, TInt aVersion, const TDesC& aDisplayName, const TDesC8& aDataType, const TDesC8& aOpaqueData, TDriveUnit aDrive);

	IMPORT_C TUid ImplementationUid() const;
	IMPORT_C TInt Version() const;
	IMPORT_C const TDesC& DisplayName() const;
	IMPORT_C const TDesC8& DataType() const;
	IMPORT_C const TDesC8& OpaqueData() const;

	IMPORT_C TDriveUnit Drive();

private:
	CImplementationInformationType();

private:
	TUid iImplementationUid;
	TInt iVersion;
	HBufC* iDisplayName;
	HBufC8* iDataType;
	HBufC8* iOpaqueData;
	TDriveUnit iDrive;
	};

//The public API for clients to call the Image Conversion Library decoders

/**
@publishedAll
@released

Provides access to the Image Conversion Library decoders.

This class provides functions to decode images held in files or descriptors. To decode buffered
images use the buffered version of this class CBufferedImageDecoder.

Regarding DRM: Note that intent is evaluated when a CImageDecoder instance is being constructed by one of the FileNewL() methods.
It is executed after at least one frame of the image has been successfully decoded.  Subsequent converts using the same CImageDecoder instance will not execute intent.
*/
class CImageDecoder : public CBase
	{
public:

	/**
	Flags to control how the image is decoded.
	These can be combined using an OR operation.
	*/
	enum TOptions
		{
		/** No flag set 
		*/
		EOptionNone = 0x00,

		/** Do not dither the decoded image 
		*/
		EOptionNoDither	= 0x01,

		/** Perform the decoding in a separate thread
		*/
		EOptionAlwaysThread = 0x02,

		/**
		Allow Opens to complete with no error if there is less
		than one frame available. This should be set for streaming.
		*/
		EOptionAllowZeroFrameOpen = 0x04,

		/**
		Setting this flag requests that the plugin generate a mask during decoding.

		Note:
		
		This option is only relevant to image formats
		that do not already contain mask information.

		The client must check that TFrameInfo::ETransparencyPossible is set
		before attempting to obtain the mask, because not all plugins support mask generation.
		*/
		EAllowGeneratedMask = 0x08,
		
		/**
		Use the highest possible image decoding speed; this may result in lower image quality. 
		This flag is more applicable to formats which use "lossy" compression algorithms, such as JPEG. 
		Decoders that do not support fast decoding will ignore it.
		*/
		EPreferFastDecode = 0x10,
		
		/**
		@publishedPartner
		@released
		
		Prevent MNG ImageDecoder from unwinding all the loops
		*/
		EOptionMngSubframesNoLoops = 0x20,
		
		/**
		@publishedPartner
		@released
		
		Setting this flag requests that the plugin use the frame size rather than the
		overall size when calculating its reduction factor
		*/
		EOptionUseFrameSizeInPixels = 0x40,
		
		/**
		When specified, this flag indicates that the decoder must ignore the EXIF meta-data, if present. 
		In this case, the ExifMetaData() should return NULL.
		This option value is also used to indicate the requirement to ignore the EXIF meta-data when doing the 
		image transformation.
		*/
		EOptionIgnoreExifMetaData = 0x80,

		/**
		@publishedAll
		@released
				
		Codec must support crop.
		 */
		EOptionExtCrop = 0x0100,
		
		/**
		@publishedAll
		@released
			
		Codec must support block streaming extension.
		 */
		EOptionExtStream = 0x0200,
		
		/**
		@publishedAll
		@released
			
		Codec must support rotation through the operation extension.
		 */
		EOptionExtRotation = 0x0400,

		/**
		@publishedAll
		@released
				
		Codec must support horizontal mirror through the operation extension.
		 */
		EOptionExtMirrorHorizontalAxis = 0x0800,

		/**
		@publishedAll
		@released
				
		Codec must support vertical mirror through the operation extension.
		 */
		EOptionExtMirrorVerticalAxis = 0x1000,

		/**
		@publishedAll
		@released
				
		Codec must support the scaling extension.
		 */
		EOptionExtScaling = 0x2000,
		
		/** Reserved.
		 */
		EOptionExtReserved7 = 0x4000,

		/** Reserved.
		 */
		EOptionExtReserved8 = 0x8000,
		/**
		@internalTechnology
		Requests that decode always fails for Png images without an iEND chunk.
		*/
		EOptionPngMissingiENDFail = 0x010000,
		
		/**
		@publishedAll
		@released
		
		Allows WMF codec to ignore any SETVIEWPORTORG, SETVIEWPORTEXT, SCALEVIEWPORTEXT 
		or OFFSETVIEWPORTORG commands in the metafile and allows scaling to destination bitmap.
		*/
		EOptionWmfIgnoreViewportMetaData = 0x020000,

		/**
		@publishedPartner
		@prototype
		
		Requests that codec applies the auto rotation when decoding according to the orientation tag in the image Exif header.
		*/
		EOptionAutoRotate = 0x040000
		};

	/**
	Flags to control which image is decoded.
	This can be used when the source file or descriptor 
	contains multiple distinct image sources.
	*/	
	enum TImageType
		{
		/** Use the thumbnail as source image
		*/
		EImageTypeThumbnail = 0x01,
		/** Use the main image
		*/
		EImageTypeMain = 0x02
		};
		
public:
	IMPORT_C static void GetImageTypesL(RImageTypeDescriptionArray& aImageTypeArray);
	IMPORT_C static void GetImageSubTypesL(const TUid aImageType, RImageTypeDescriptionArray& aSubTypeArray);
	IMPORT_C static void GetFileTypesL(RFileExtensionMIMETypeArray& aFileExtensionArray);
	IMPORT_C static void GetMimeTypeFileL(RFs& aFs, const TDesC& aFileName, TDes8& aMimeType);
	IMPORT_C static void GetMimeTypeDataL(const TDesC8& aImageData, TDes8& aMimeType);

	IMPORT_C static CImplementationInformationType* GetImplementationInformationL(TUid aImplementationUid);

	IMPORT_C static CImageDecoder* FileNewL(RFs& aFs, const TDesC& aSourceFilename, const TDesC8& aMIMEType, const TOptions aOptions = EOptionNone);
	IMPORT_C static CImageDecoder* FileNewL(RFs& aFs, const TDesC& aSourceFilename, const TOptions aOptions = EOptionNone, const TUid aImageType = KNullUid, const TUid aImageSubType = KNullUid, const TUid aDecoderUid = KNullUid);

	IMPORT_C static CImageDecoder* FileNewL(RFs& aFs, const TDesC& aSourceFilename, const TDesC8& aMIMEType, ContentAccess::TIntent aIntent, const TOptions aOptions = EOptionNone);
	IMPORT_C static CImageDecoder* FileNewL(RFs& aFs, const TDesC& aSourceFilename, ContentAccess::TIntent aIntent, const TOptions aOptions = EOptionNone, const TUid aImageType = KNullUid, const TUid aImageSubType = KNullUid, const TUid aDecoderUid = KNullUid);
	IMPORT_C static CImageDecoder* FileNewL(RFile& aFile, const TDesC8& aMIMEType, ContentAccess::TIntent aIntent, const TOptions aOptions = EOptionNone);
	IMPORT_C static CImageDecoder* FileNewL(RFile& aFile, ContentAccess::TIntent aIntent, const TOptions aOptions = EOptionNone, const TUid aImageType = KNullUid, const TUid aImageSubType = KNullUid, const TUid aDecoderUid = KNullUid);

	IMPORT_C static CImageDecoder* FileNewL(RFs& aFs, const TMMSource& aFileSource, const TDesC8& aMIMEType, const TOptions aOptions = EOptionNone);
	IMPORT_C static CImageDecoder* FileNewL(RFs& aFs, const TMMSource& aFileSource, const TOptions aOptions = EOptionNone, const TUid aImageType = KNullUid, const TUid aImageSubType = KNullUid, const TUid aDecoderUid = KNullUid);
	
	IMPORT_C static CImageDecoder* DataNewL(RFs& aFs, const TDesC8& aSourceData, const TDesC8& aMIMEType, const TOptions aOptions = EOptionNone);
	IMPORT_C static CImageDecoder* DataNewL(RFs& aFs, const TDesC8& aSourceData, const TOptions aOptions = EOptionNone, const TUid aImageType  = KNullUid, const TUid aImageSubType = KNullUid, const TUid aDecoderUid = KNullUid);
	IMPORT_C virtual ~CImageDecoder();

	IMPORT_C virtual void Convert(TRequestStatus* aRequestStatus, CFbsBitmap& aDestination, TInt aFrameNumber = 0);
	IMPORT_C virtual void Convert(TRequestStatus* aRequestStatus, CFbsBitmap& aDestination, CFbsBitmap& aDestinationMask, TInt aFrameNumber = 0);
	IMPORT_C virtual void ContinueConvert(TRequestStatus* aRequestStatus);
	IMPORT_C void Cancel();

	IMPORT_C TInt FrameCount() const;
	IMPORT_C TBool IsImageHeaderProcessingComplete() const;
	IMPORT_C void ContinueProcessingHeaderL();

	IMPORT_C const TFrameInfo& FrameInfo(TInt aFrameNumber = 0) const;
	IMPORT_C const CFrameImageData& FrameData(TInt aFrameNumber = 0) const;

	IMPORT_C TInt NumberOfImageComments() const;
	IMPORT_C HBufC* ImageCommentL(TInt aCommentNumber) const;
	IMPORT_C TInt NumberOfFrameComments(TInt aFrameNumber) const;
	IMPORT_C HBufC* FrameCommentL(TInt aFrameNumber, TInt aCommentNumber) const;

	IMPORT_C CFrameInfoStrings* FrameInfoStringsLC(TInt aFrameNumber = 0);
	IMPORT_C CFrameInfoStrings* FrameInfoStringsL(TInt aFrameNumber = 0);
	IMPORT_C TUid ImplementationUid() const;

	IMPORT_C void ImageType(TInt aFrameNumber, TUid& aImageType, TUid& aImageSubType) const;

	IMPORT_C TInt SetAgentProperty(ContentAccess::TAgentProperty aProperty, TInt aValue);
	IMPORT_C void SetImageTypeL(TInt aImageType);
	
	IMPORT_C TInt ReductionFactor(const TSize& aOriginalSize, const TSize& aReducedSize) const;
	IMPORT_C TInt ReducedSize(const TSize& aOriginalSize,  TInt aReductionFactor, TSize& aReducedSize) const;
	IMPORT_C TInt SetDecoderThreadPriority(TThreadPriority aPriority);

	IMPORT_C static void GetPluginPropertiesL(const TUid aImplementationUid, RUidDataArray& aPropertiesArray);
	IMPORT_C static void GetInterfaceImplementationsL(const RUidDataArray& aRequiredUids, RUidDataArray& aImplArray);
	IMPORT_C static void GetInterfaceImplementationsL(const TUid* aRequiredUids, const TInt aLength, RUidDataArray& aImplArray);

	IMPORT_C TImageConvOperation* OperationL();
	IMPORT_C TImageConvScaler* ScalerL();
	IMPORT_C TImageConvStreamedDecode* BlockStreamerL();

	IMPORT_C void SetClippingRectL(const TRect* aClipRect);
	IMPORT_C TInt GetDestinationSize(TSize& aSize, TInt aFrameNumber = 0);
	
	IMPORT_C void Prepare(TRequestStatus* aRequestStatus);

protected:
	IMPORT_C CImageDecoder();

	// custom commands - for extended decoders
	IMPORT_C void CustomSyncL(TInt aParam);
	IMPORT_C void CustomAsync(TRequestStatus* aRequestStatus, TInt aParam);
	IMPORT_C CImageDecoderPlugin* Plugin() const;

private:
	static void MimeTypeGetDecoderListL(RImplInfoPtrArray& aDecoderList, const TDesC8& aMIMEType, const TOptions aOptions = EOptionNone);
	static void ImageTypeGetDecoderListL(RImplInfoPtrArray& aDecoderList, const TDesC8& aImageHeader, const TUid aImageType, const TUid aImageSubType, const TUid aDecoderUid, const TOptions aOptions = EOptionNone);
	static void SuffixTypeGetDecoderListL(RImplInfoPtrArray& aDecoderList, const TDesC& aFileName, const TOptions aOptions = EOptionNone);

	static CImageDecoder* FileFindDecoderNewL(const RImplInfoPtrArray& aDecoderList, RFs& aFs, const TDesC& aSourceFilename, const TOptions aOptions, const TDesC& aUniqueId);
	static CImageDecoder* FileDecoderNewL(const CImplementationInformation& aDecoderInfo, RFs& aFs, const TDesC& aSourceFilename, const TOptions aOptions, const TDesC& aUniqueId);
	
	static CImageDecoder* DataFindDecoderNewL(const RImplInfoPtrArray& aDecoderList, RFs& aFs, const TDesC8& aSourceData, const TOptions aOptions);
	static CImageDecoder* DataDecoderNewL(const CImplementationInformation& aDecoderInfo, RFs& aFs, const TDesC8& aSourceData, const TOptions aOptions);

	static CImageDecodeConstruct* NewDecodeConstructL(const CImplementationInformation& aDecoderInfo, const TOptions aOptions = EOptionNone);

	static void DoGetMimeTypeL(const TDesC& aFileName, const TDesC8& aMatchString, TDes8& aMimeType);

	static CImageDecoder* NewL(CImageDecodeConstruct* aConstruct, TOptions aOptions);
	static CImageDecoder* NewL();

	static CImageDecoder* FileNewImplL(RFs& aFs, const TDesC& aSourceFilename, const TDesC8& aMIMEType, const TDesC& aUniqueId, const ContentAccess::TIntent aIntent, const TOptions aOptions = EOptionNone);
	static CImageDecoder* FileNewImplL(RFs& aFs, const TDesC& aSourceFilename, const TDesC& aUniqueId, const ContentAccess::TIntent aIntent, const TOptions aOptions = EOptionNone, const TUid aImageType = KNullUid, const TUid aImageSubType = KNullUid, const TUid aDecoderUid = KNullUid);
	static CImageDecoder* FileFindDecoderNewL(const RImplInfoPtrArray& aDecoderList, RFile& aFile, const TOptions aOptions, const TDesC& aUniqueId);
	static CImageDecoder* FileDecoderNewL(const CImplementationInformation& aDecoderInfo, RFile& aFile, const TOptions aOptions, const TDesC& aUniqueId);
	static CImageDecoder* FileNewImplL(RFile& aFile, const TDesC8& aMIMEType, const TDesC& aUniqueId, const ContentAccess::TIntent aIntent, const TOptions aOptions = EOptionNone);
	static CImageDecoder* FileNewImplL(RFile& aFile, const TDesC& aUniqueId, const ContentAccess::TIntent aIntent, const TOptions aOptions = EOptionNone, const TUid aImageType = KNullUid, const TUid aImageSubType = KNullUid, const TUid aDecoderUid = KNullUid);
    static ContentAccess::CContent* GetContentLC(const TDesC& aSourceFilename);

	inline TBool ValidProperties() const;

	// Future proofing
	IMPORT_C virtual void ReservedVirtual1();
	IMPORT_C virtual void ReservedVirtual2();
	IMPORT_C virtual void ReservedVirtual3();
	IMPORT_C virtual void ReservedVirtual4();

private:
	MImageDecoderRelay* iRelay;

friend class CImageDecodeConstruct;	
	};


/**
@publishedAll
@released

Buffered image conversion library.

Provides a wrapper arround CImageDecoder that enables you to decode multiple images without
having to recreate the CBufferedImageDecoder object each time. One of the key features of this
class is the ability to append image data to the decoder object as it becomes available; this
is done using AppendDataL().
*/

//The public API for clients to call the Buffered Image Conversion Library decoders
class CBufferedImageDecoder : public CBase
	{
private:
	enum TState
		{
		EStateCreated,
		EStateOpening,
		EStateOpen,
		EStateConverting
		};

public:
	IMPORT_C static CBufferedImageDecoder* NewL(RFs& aFs);
	IMPORT_C virtual ~CBufferedImageDecoder();

	IMPORT_C void OpenL(const TDesC8& aSourceData, const TDesC8& aMIMEType, const CImageDecoder::TOptions aOptions = CImageDecoder::EOptionNone);
	IMPORT_C void OpenL(const TDesC8& aSourceData, const CImageDecoder::TOptions aOptions = CImageDecoder::EOptionNone, const TUid aImageType  = KNullUid, const TUid aImageSubType = KNullUid, const TUid aDecoderUid = KNullUid);
	IMPORT_C void ContinueOpenL();
	IMPORT_C void ContinueProcessingHeaderL();
	IMPORT_C TBool IsImageHeaderProcessingComplete() const;

	IMPORT_C void Convert(TRequestStatus* aRequestStatus, CFbsBitmap& aDestination, TInt aFrameNumber = 0);
	IMPORT_C void Convert(TRequestStatus* aRequestStatus, CFbsBitmap& aDestination, CFbsBitmap& aDestinationMask, TInt aFrameNumber = 0);
	IMPORT_C void ContinueConvert(TRequestStatus* aRequestStatus);

	IMPORT_C void Cancel();
	IMPORT_C void Reset();

	IMPORT_C void AppendDataL(const TDesC8& aData);

	IMPORT_C TInt FrameCount() const;
	IMPORT_C const TFrameInfo& FrameInfo(TInt aFrameNumber = 0) const;
	IMPORT_C const CFrameImageData& FrameData(TInt aFrameNumber = 0) const;

	IMPORT_C TInt NumberOfImageComments() const;
	IMPORT_C HBufC* ImageCommentL(TInt aCommentNumber) const;
	IMPORT_C TInt NumberOfFrameComments(TInt aFrameNumber) const;
	IMPORT_C HBufC* FrameCommentL(TInt aFrameNumber, TInt aCommentNumber) const;

	IMPORT_C CFrameInfoStrings* FrameInfoStringsLC(TInt aFrameNumber = 0);
	IMPORT_C CFrameInfoStrings* FrameInfoStringsL(TInt aFrameNumber = 0);
	IMPORT_C TUid ImplementationUid() const;

	IMPORT_C TBool ValidDecoder () const;

private:
	CBufferedImageDecoder(RFs& aFs);

private:
	RFs iFileSession;
	CImageDecoder::TOptions iOptions;
	TUid iImageType;
	TUid iImageSubType;
	TUid iDecoderUid;
	TPtr8 iBuffer;
	TPtr8 iMimeType;	

	CImageDecoder* iDecoder;

	TBool iImageTypeOpen; // Object was opened using image type	
	TState iState;

friend class RBufferedDecoderTest;
	};


// The public API for clients to call the Image Conversion Library encoders

/**
@publishedAll
@released

Provides access to the ICL (image conversion library) encoders.

This class provides functions that convert image data held in CFbsBitmap objects 
into well know formats and store the results in either files of descriptors.
*/
class CImageEncoder : public CBase
	{
public:

	/**
	Flags to control how the image is encoded.
	These can be combined using an OR operation.
	*/
	enum TOptions
		{
		/** No flag set
		*/
		EOptionNone = 0x00,

		/** Perform the encoding in a separate thread 
		*/
		EOptionAlwaysThread = 0x01,
		
		/** If the codec supports it, generate a palette based on the colors present in the image data, rather than using the default palette
		*/
		EOptionGenerateAdaptivePalette = 0x02,

		/**
		Use the highest possible image encoding speed; this may result in lower image quality. 
		This flag is more applicable to formats which use "lossy" compression algorithms, such as JPEG. 
		Decoders that do not support fast encoding will ignore it.
		*/
		EPreferFastEncode = 0x04,

		/**
		@publishedAll
		@released
				
		Codec must support block streaming extension.
		 */
		EOptionExtStream = 0x0100,
		
		/**
		@publishedAll
		@released
				
		Codec must support rotation through the operation extension.
		 */
		EOptionExtRotation = 0x0200,

		/**
		@publishedAll
		@released
				
		Codec must support horizontal mirror through the operation extension.
		 */
		EOptionExtMirrorHorizontalAxis = 0x0400,

		/**
		@publishedAll
		@released
				
		Codec must support vertical mirror through the operation extension.
		 */
		EOptionExtMirrorVerticalAxis = 0x0800,

		/**
		@publishedAll
		@released
				
		Codec must support setting thumbnail when using the other extensions (e.g. thumbnail rotation)
		 */
		EOptionExtUseWithSetThumbnail = 0x1000,
		
		/** Reserved.
		 */
		EOptionExtReserved1 = 0x2000,

		/** Reserved.
		 */
		EOptionExtReserved2 = 0x4000,
		
		/** Reserved.
		 */
		EOptionExtReserved3 = 0x8000
		};

public:
	IMPORT_C static void GetImageTypesL(RImageTypeDescriptionArray& aImageTypeArray);
	IMPORT_C static void GetImageSubTypesL(const TUid aImageType, RImageTypeDescriptionArray& aSubTypeArray);
	IMPORT_C static void GetFileTypesL(RFileExtensionMIMETypeArray& aFileExtensionArray);
	IMPORT_C static CImageEncoder* FileNewL(RFs& aFs, const TDesC& aDestinationFilename, const TDesC8& aMIMEType, const TOptions aOptions = EOptionNone);
	IMPORT_C static CImageEncoder* FileNewL(RFs& aFs, const TDesC& aDestinationFilename, const TOptions aOptions = EOptionNone, const TUid aImageType = KNullUid, const TUid aImageSubType = KNullUid, const TUid aEncoderUid = KNullUid);

	IMPORT_C static CImageEncoder* FileNewL(RFile& aFile, const TDesC8& aMIMEType, const TOptions aOptions = EOptionNone);
	IMPORT_C static CImageEncoder* FileNewL(RFile& aFile, const TOptions aOptions = EOptionNone, const TUid aImageType = KNullUid, const TUid aImageSubType = KNullUid, const TUid aEncoderUid = KNullUid);

	IMPORT_C static CImageEncoder* DataNewL(HBufC8*& aDestinationData, const TDesC8& aMIMEType, const TOptions aOptions = EOptionNone);
	IMPORT_C static CImageEncoder* DataNewL(HBufC8*& aDestinationData, const TOptions aOptions = EOptionNone, const TUid aImageType = KNullUid, const TUid aImageSubType = KNullUid, const TUid aEncoderUid = KNullUid);

	IMPORT_C void Convert(TRequestStatus* aRequestStatus, const CFbsBitmap& aSource, const CFrameImageData* aFrameImageData = NULL);

	IMPORT_C virtual ~CImageEncoder();
	IMPORT_C void Cancel();

	IMPORT_C TUid ImplementationUid() const;

	IMPORT_C void SetThumbnail(TBool aDoGenerateThumbnail);
	IMPORT_C TInt SetEncoderThreadPriority(TThreadPriority aPriority);

	IMPORT_C static void GetPluginPropertiesL(const TUid aImplementationUid, RUidDataArray& aPropertiesArray);
	IMPORT_C static void GetInterfaceImplementationsL(const RUidDataArray& aRequiredUids, RUidDataArray& aImplArray);
	IMPORT_C static void GetInterfaceImplementationsL(const TUid* aRequiredUids, const TInt aLength, RUidDataArray& aImplArray);

	IMPORT_C TImageConvOperation* OperationL();
	IMPORT_C TImageConvStreamedEncode* BlockStreamerL();

	IMPORT_C void Prepare(TRequestStatus* aRequestStatus);

protected:
	IMPORT_C CImageEncoder();

	// custom commands - for extended encoders
	IMPORT_C void CustomSyncL(TInt aParam);
	IMPORT_C void CustomAsync(TRequestStatus* aRequestStatus, TInt aParam);
	IMPORT_C CImageEncoderPlugin* Plugin() const;

private:
	static void MimeTypeGetEncoderListL(RImplInfoPtrArray& aEncoderList, const TDesC8& aMIMEType, const TOptions aOptions = EOptionNone);
	static void ImageTypeGetEncoderListL(RImplInfoPtrArray& aEncoderList, const TUid aImageType, const TUid aImageSubType, const TUid aEncoderUid, const TOptions aOptions = EOptionNone);

   	static CImageEncodeConstruct* NewEncodeConstructL(const CImplementationInformation& aEncoderInfo, const TOptions aOptions = EOptionNone);

	static CImageEncoder* NewL(CImageEncodeConstruct* aConstruct, TOptions aOptions);
	static CImageEncoder* NewL();

	inline TBool ValidProperties() const;

	// Future proofing
	IMPORT_C virtual void ReservedVirtual1();
	IMPORT_C virtual void ReservedVirtual2();
	IMPORT_C virtual void ReservedVirtual3();
	IMPORT_C virtual void ReservedVirtual4();

private:
	MImageEncoderRelay* iRelay;

friend class CImageEncodeConstruct;
	};

#endif // IMAGECONVERSION_H

