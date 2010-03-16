// Copyright (c) 1997-2009 Nokia Corporation and/or its subsidiary(-ies).
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

#ifndef __APGICNFL_H__
#define __APGICNFL_H__

#include <apadef.h>
#include <apaid.h>
#include <bitdev.h>
#include <apmstd.h>
#include <badesca.h>

class CFbsBitmap;
class CPersistentStore;
class RReadStream;
class RWriteStream;

class CApaMaskedBitmap : public CFbsBitmap
/** An application icon.

This is a bitmap and a mask, managed by the Font and Bitmap server.

An object of this type is passed to RApaLsSession::GetAppIcon() to fetch a 
suitable application icon.

@publishedAll
@released
@see RApaLsSession::GetAppIcon() */
	{
public:
	IMPORT_C static CApaMaskedBitmap* NewLC();
	IMPORT_C static CApaMaskedBitmap* NewL(const CApaMaskedBitmap* aSourceIcon);
	//
	IMPORT_C CFbsBitmap* Mask() const;
	IMPORT_C void InternalizeL(RReadStream& aStream); 		//lint !e1511 Member hides non-virtual member - CFbsBitmap not primary intended for derivation
	IMPORT_C void ExternalizeL(RWriteStream& aStream) const;//lint !e1511 Member hides non-virtual member - CFbsBitmap not primary intended for derivation
	//
	IMPORT_C ~CApaMaskedBitmap();
	void SetRomBitmapL(TUint8* aRomPointer);				//lint !e1511 Member hides non-virtual member - CFbsBitmap not primary intended for derivation
	IMPORT_C void SetMaskBitmap(CFbsBitmap* aMask);
private:
	CApaMaskedBitmap();
	void ConstructL();
private:
	CFbsBitmap* iMask;
	};

/**
@internalComponent
*/
class CApaResourceFileWriterBase : public CBase
	{
protected:
	class RBufferSink;
	class MDataSink
		{
	public:
		void WriteBufferL(const TDesC8& aBuffer);
		void WriteCompressedUnicodeRunL(TInt aNumberOfBytesWhenUncompressed, const TDesC8& aTextAsCompressedUnicode);
		void WriteInCompressedUnicodeFormatL(TInt aNumberOfBytesWhenUncompressed, const TDesC8& aData, TBool aInCompressedUnicodeRun);
		TInt NumberOfBytesWhenUncompressed() const;
		inline TBool CompressedUnicodeFormat() const {return (iBufferSinkForCompressedUnicodeFormat!=NULL);}
	protected:
		MDataSink(RBufferSink* aBufferSinkForCompressedUnicodeFormat);
		void FlushL(TBool aFinalFlush);
		void Reset(TInt& aNumberOfBytesWhenUncompressed);
	private:
		void WriteRunLengthL(TInt aRunLength);
	private:
		enum
			{
			EFlag_InCompressedUnicodeRun	=0x00000001
			};
	private:
		// new virtual functions
		virtual void DoWriteBufferL(const TDesC8& aBuffer)=0;
	private:
		TInt iNumberOfBytesWhenUncompressed;
		TUint iFlags;
		RBufferSink* iBufferSinkForCompressedUnicodeFormat; // does not own what it points to
		};
	class RBufferSink : public MDataSink
		{
	public:
		RBufferSink(RBufferSink* aBufferSinkForCompressedUnicodeFormat);
		void ConstructLC();
		void Close();
		void FlushAndGetAndResetL(TInt& aNumberOfBytesWhenUncompressed, RBuf8& aBuffer);
	private:
		// from MDataSink
		virtual void DoWriteBufferL(const TDesC8& aBuffer);
	private:
		RBuf8 iBuffer;
		};
protected:
	CApaResourceFileWriterBase();
	void DoGenerateFileContentsL(RBuf8& aBuffer, TUid aUid2, TUid aUid3) const;
	void WriteUidTypeL(MDataSink& aDataSink, TUid aUid2, TUid aUid3) const;
	void WriteTextL(MDataSink& aDataSink, const TDesC& aText) const;
	void WriteText8L(MDataSink& aDataSink, const TDesC8& aText8) const;
	void WriteUint8L(MDataSink& aDataSink, TUint aUint8) const;
	void WriteLittleEndianUint16L(MDataSink& aDataSink, TUint aUint16) const;
	void WriteLittleEndianUint32L(MDataSink& aDataSink, TUint aUint32) const;
	void WriteBufferL(MDataSink& aDataSink, const TDesC8& aBuffer) const;
private:
	static HBufC8* AsCompressedUnicodeLC(const TDesC& aUncompressedUnicode);
	void MainResourceInCompiledFormatLC(TInt& aMainResourceSizeInBytesWhenUncompressed, RBuf8& aBuffer, TBool aCompressedUnicodeFormat) const;
private:
	// new virtual functions
	virtual void MainResourceInCompiledFormatL(MDataSink& aDataSink) const=0;
	virtual const TDesC8* SecondResourceL(TBool& aSecondResourceInCompressedUnicodeFormat) const=0;
	};

/**
Used to support the registration of non-native applications.

The task of this class is to generate the resource files expected by the Apparc server. Applications 
that register other applications can use functions of this class to customise the generated resource files.

@publishedPartner
@released
*/
class CApaRegistrationResourceFileWriter : public CApaResourceFileWriterBase
	{
public:
	IMPORT_C static CApaRegistrationResourceFileWriter* NewL(TUid aAppUid, const TDesC& aAppFile, TUint aAttributes);
	IMPORT_C virtual ~CApaRegistrationResourceFileWriter();
	TUid AppUid() const;
	void GenerateFileContentsL(RBuf8& aBuffer) const;
	void SetLocalisableResourceFileL(const TDesC& aLocalisableResourceFile);
	IMPORT_C void SetAppIsHiddenL(TBool aAppIsHidden);
	IMPORT_C void SetEmbeddabilityL(TApaAppCapability::TEmbeddability aEmbeddability);
	IMPORT_C void SetSupportsNewFileL(TBool aSupportsNewFile);
	IMPORT_C void SetLaunchInBackgroundL(TBool aLaunchInBackground);
	IMPORT_C void SetGroupNameL(const TDesC& aGroupName);
	IMPORT_C void SetDefaultScreenNumberL(TInt aDefaultScreenNumber);
	IMPORT_C void SetOpaqueDataL(const TDesC8& aOpaqueData);
	IMPORT_C void AddDataTypeL(TInt aPriority, const TDesC8& aType);
	IMPORT_C void AddFileOwnershipInfoL(const TDesC& aFileName);
// Not needing to be supported for the foreseeable future:
//	IMPORT_C void AddServiceInfoL(TUid aServiceUid, const TDesC8* aOpaqueData);
//	IMPORT_C void AddServiceInfoDataTypeL(TUid aServiceUid, TInt aPriority, const TDesC8& aType);
private:
	struct SDataType // DATATYPE
		{
		TInt iPriority;
		HBufC8* iType;
		};
	struct SFileOwnershipInfo // FILE_OWNERSHIP_INFO
		{
		HBufC* iFileName;
		};
private:
	CApaRegistrationResourceFileWriter(TUid aAppUid, TUint aAttributes);
	void ConstructL(const TDesC& aAppFile);
	void WriteDataTypeL(MDataSink& aDataSink, const SDataType& aDataType) const;
	void WriteFileOwnershipInfoL(MDataSink& aDataSink, const SFileOwnershipInfo& aFileOwnershipInfo) const;
	// from CApaResourceFileWriterBase
	virtual void MainResourceInCompiledFormatL(MDataSink& aDataSink) const;
	virtual const TDesC8* SecondResourceL(TBool& aSecondResourceInCompressedUnicodeFormat) const;
private:
	TUid iAppUid;
	HBufC* iAppFile;
	TUint iAttributes;
	HBufC* iLocalisableResourceFile;
	TBool iAppIsHidden;
	TApaAppCapability::TEmbeddability iEmbeddability;
	TBool iSupportsNewFile;
	TBool iLaunchInBackground;
	HBufC* iGroupName;
	TInt iDefaultScreenNumber;
	HBufC8* iOpaqueData;
	RArray<SDataType> iDataTypeList;
	RArray<SFileOwnershipInfo> iFileOwnershipList;
	};

/**
@internalAll
*/
class CApaLocalisableResourceFileWriter : public CApaResourceFileWriterBase
	{
public:
	IMPORT_C static CApaLocalisableResourceFileWriter* NewL(const TDesC& aShortCaption, const TDesC& aCaption, TInt aNumberOfIcons, const TDesC& aGroupName);
	IMPORT_C virtual ~CApaLocalisableResourceFileWriter();
	void GenerateFileContentsL(RBuf8& aBuffer) const;
	void SetIconFileL(const TDesC& aIconFile);
// Not needing to be supported for the foreseeable future:
//	IMPORT_C void AddViewDataL(TUid aViewUid, TInt aScreenMode, const TDesC& aCaption, TInt aNumberOfIcons, const TDesC& aIconFile);
private:
	struct SCaptionAndIconInfo // CAPTION_AND_ICON_INFO
		{
		HBufC* iCaption;
		TInt iNumberOfIcons;
		HBufC* iIconFile;
		};
private:
	CApaLocalisableResourceFileWriter(TInt aNumberOfIcons);
	void ConstructL(const TDesC& aShortCaption, const TDesC& aCaption, const TDesC& aGroupName);
	void WriteCaptionAndIconInfoL(MDataSink& aDataSink, const SCaptionAndIconInfo& aCaptionAndIcon) const;
	// from CApaResourceFileWriterBase
	virtual void MainResourceInCompiledFormatL(MDataSink& aDataSink) const;
	virtual const TDesC8* SecondResourceL(TBool& aSecondResourceInCompressedUnicodeFormat) const;
private:
	HBufC* iShortCaption;
	SCaptionAndIconInfo iCaptionAndIcon;
	HBufC* iGroupName;
	};

#if defined(UI_FRAMEWORKS_V1_REMNANT_FOR_JAVA_MIDLET_INSTALLER)

class CApaAppInfoFileWriter;

/**
@internalAll
*/
const TUid KUidInterimFormatFileForJavaMIDletInstaller={0x10208182};

/**
@internalAll
*/
class ForJavaMIDletInstaller
	{
public:
	IMPORT_C static void CheckInterimFormatFileNotCorruptL(RFile& aInterimFormatFile);
	IMPORT_C static void GetJavaMIDletInfoL(RFs& aFs, const TDesC& aFileName,TUint32& aJavaMIDletInfo_AmsAuthId,TUint32& aJavaMIDletInfo_MIDlet);
	IMPORT_C static CApaAppInfoFileWriter* NewInterimFormatFileWriterLC(RFs& aFs,const TDesC& aFileName,TUid aApplicationUid,TUint32 aJavaMIDletInfo_AmsAuthId,TInt aJavaMIDletInfo_MIDlet);
	};

#endif // UI_FRAMEWORKS_V1_REMNANT_FOR_JAVA_MIDLET_INSTALLER

#if (((defined(SYMBIAN_SUPPORT_UI_FRAMEWORKS_V1) || !defined(SYMBIAN_HIDE_UI_FRAMEWORKS_V1)) && !defined(SYMBIAN_REMOVE_UI_FRAMEWORKS_V1)) || defined(UI_FRAMEWORKS_V1_REMNANT_FOR_JAVA_MIDLET_INSTALLER))

#if !defined(IMPORT_C_NOT_NEEDED_FOR_JAVA_MIDLET_INSTALLER)
// we're compiling a source file that doesn't define IMPORT_C_NOT_NEEDED_FOR_JAVA_MIDLET_INSTALLER, so give it it's default "value" of "IMPORT_C"
#define IMPORT_C_NOT_NEEDED_FOR_JAVA_MIDLET_INSTALLER IMPORT_C
#endif

/**
@publishedAll
@deprecated
*/
#ifdef _UNICODE
#define KUidAppInfoFile KUidAppInfoFile16
#else
#define KUidAppInfoFile KUidAppInfoFile8
#endif

/**
@publishedAll
@deprecated
*/
const TUid KUidAppInfoFile8={268435562};

/**
@publishedAll
@deprecated
*/
const TUid KUidAppInfoFile16={0x10003A38};

/**
@internalComponent
*/
const TUid KUidAppInfoFileVersion2={0x101fb032};

/**
@internalComponent
*/
enum TAifVersion
// The order here is important, only ever APPEND to the list
	{
	EAifVersionOriginal,
	EAifVersionAddsDataType,
	EAifVersionAddsViewData,
	EAifVersionAddsFileOwnershipInfo
#if defined(UI_FRAMEWORKS_V1_REMNANT_FOR_JAVA_MIDLET_INSTALLER)
	,EAifVersionAddsJavaMIDletInfo
#endif
	};

class CApaAIFCaption : public CBase
//
// Represents a caption in an AIF during reading and writing of the file.
/**
@internalComponent
*/
	{
public:
	~CApaAIFCaption();
	CApaAIFCaption();
	void ConstructL(TLanguage aLanguage,const TDesC& aCaption);
	static CApaAIFCaption* NewLC(TLanguage aLanguage,const TDesC& aCaption);
	void InternalizeL(RReadStream& aStream);
	void ExternalizeL(RWriteStream& aStream) const;
	TLanguage Language() const;
	TApaAppCaption Caption() const;
public:
	HBufC* iCaption;
	TLanguage iLanguage;
	};

class CApaAIFViewData : public CBase
//
// Represents the data associated with an application view described in an AIF
// during reading and writing of the file.
// implementation class
/**
@internalComponent
*/
	{
public:
	IMPORT_C_NOT_NEEDED_FOR_JAVA_MIDLET_INSTALLER TApaAppCaption CaptionL(TLanguage aLanguage) const;
	IMPORT_C_NOT_NEEDED_FOR_JAVA_MIDLET_INSTALLER CApaMaskedBitmap* IconByIndexL(TInt aIndex) const;
	IMPORT_C_NOT_NEEDED_FOR_JAVA_MIDLET_INSTALLER TInt NumberOfIcons() const;
	IMPORT_C_NOT_NEEDED_FOR_JAVA_MIDLET_INSTALLER TUid ViewUid() const;
	IMPORT_C_NOT_NEEDED_FOR_JAVA_MIDLET_INSTALLER TInt ScreenMode() const;
public:
	~CApaAIFViewData();
	static CApaAIFViewData* NewLC();
	static CApaAIFViewData* NewLC(const CApaAIFViewData& aSourceData);
	void InternalizeL(RReadStream& aStream);		
	void ExternalizeL(RWriteStream& aStream) const;
	void SetScreenMode(TInt aScreenMode);
	void AddCaptionL(TLanguage aLanguage,const TDesC& aCaption);
	void AddIconL(CApaMaskedBitmap& aIcon);
	void AddIconIndexL(TInt aIndex);
	void SetViewUid(TUid aUid);
	void LoadIconsL(const TDesC& aFileName, TUint aMbmOffset);
private:
	CApaAIFViewData();
	void ConstructL();
	void ConstructL(const CApaAIFViewData& aSourceData);
private:
	TInt iScreenMode;
	CArrayPtr<CApaMaskedBitmap>* iIconArray;
	CArrayPtr<CApaAIFCaption>* iCaptionArray;
	TUid iViewUid;
	CArrayFixFlat<TInt>* iIconIndexArray;		// used for AIF version 2 format
	};

class CApaAppInfoFile : public CBase
/**
@internalComponent
*/
	{
#if defined(UI_FRAMEWORKS_V1_REMNANT_FOR_JAVA_MIDLET_INSTALLER)
	friend class ForJavaMIDletInstaller;
#endif
public:
	~CApaAppInfoFile();
	//
protected:
	CApaAppInfoFile(RFs& aFs);
	void ConstructL();
protected:

	class TCaptionHeader
		{
	public:
		void InternalizeL(RReadStream& aStream);			// internalizes the header info only
		void ExternalizeL(RWriteStream& aStream) const;		// externalizes the header info only
	public:
		TSwizzle<HBufC> iCaption;
		TLanguage iLanguage;
		};
	class TIconHeader
		{
	public:
		void InternalizeL(RReadStream& aStream);			// internalizes the header info only
		void ExternalizeL(RWriteStream& aStream) const;		// externalizes the header info only
	public:
		TSwizzle<CApaMaskedBitmap> iIcon;	// Used for old AIF format Internalize
		TInt iIconSideInPixels;
		TSwizzle<CFbsBitmap> iIconMain;		// Used for new AIF format
		TSwizzle<CFbsBitmap> iIconMask;		// Used for new AIF format
		};
	class TDataTypeHeader
		{
	public:
		// header info only
		void InternalizeL(RReadStream& aStream); 			// internalizes the header info only
		void ExternalizeL(RWriteStream& aStream) const;		// externalizes the header info only
	public:
		TSwizzle<TDataType> iDataType;
		TDataTypePriority iPriority;
		};
	class TViewDataHeader
		{
	public:
		void InternalizeL(RReadStream& aStream);			// internalizes the header info only
		void ExternalizeL(RWriteStream& aStream) const;		// externalizes the header info only
	public:
		TSwizzle<CApaAIFViewData> iViewData;
		};
	class TFileOwnershipInfoHeader
		{
	public:
		void InternalizeL(RReadStream& aStream);			// internalizes the header info only
		void ExternalizeL(RWriteStream& aStream) const;		// externalizes the header info only
	public:
		TSwizzle<HBufC> iOwnedFileName;
		};
protected:
	RFs& iFs;
	CPersistentStore* iStore;
	CArrayFix<TCaptionHeader>* iCaptionHeaderArray;
	CArrayFix<TIconHeader>* iIconHeaderArray;
	CArrayFix<TDataTypeHeader>* iDataTypeHeaderArray;
	CArrayFix<TViewDataHeader>* iViewDataHeaderArray;
	CArrayFix<TFileOwnershipInfoHeader>* iFileOwnershipInfoHeaderArray;
	TApaAppCapability iCapability;
	};

class CApaAppInfoFileReader : public CApaAppInfoFile
/** Aif file reader.

Aif files contain information about an application, including its icons and 
captions.

An application can get a reader for its own aif file by calling CEikApplication::OpenAppInfoFileLC(). 

@publishedAll
@deprecated */
	{
#if defined(UI_FRAMEWORKS_V1_REMNANT_FOR_JAVA_MIDLET_INSTALLER)
	friend class ForJavaMIDletInstaller;
#endif
public:
	IMPORT_C_NOT_NEEDED_FOR_JAVA_MIDLET_INSTALLER static CApaAppInfoFileReader* NewLC(RFs& aFs, const TDesC& aFileName,TUid aApplicationUid=KNullUid);
	IMPORT_C_NOT_NEEDED_FOR_JAVA_MIDLET_INSTALLER static CApaAppInfoFileReader* NewL(RFs& aFs, const TDesC& aFileName,TUid aApplicationUid=KNullUid);
	//
	IMPORT_C_NOT_NEEDED_FOR_JAVA_MIDLET_INSTALLER void Capability(TDes8& aInfo) const;
	IMPORT_C_NOT_NEEDED_FOR_JAVA_MIDLET_INSTALLER TApaAppCaption CaptionL(TLanguage aLanguage);
	
	IMPORT_C_NOT_NEEDED_FOR_JAVA_MIDLET_INSTALLER CApaMaskedBitmap* CreateMaskedBitmapL(TInt aIconSideInPixels); // If there are no bitmaps in the file this method leaves with KErrNotFound
	// Not available until ER6
	IMPORT_C_NOT_NEEDED_FOR_JAVA_MIDLET_INSTALLER CApaMaskedBitmap* CreateMaskedBitmapByIndexLC(TInt aIndex); // If there are no bitmaps in the file this method leaves with KErrNotFound
	IMPORT_C_NOT_NEEDED_FOR_JAVA_MIDLET_INSTALLER TInt NumberOfBitmaps() const;

	// Not available till ER5
	IMPORT_C_NOT_NEEDED_FOR_JAVA_MIDLET_INSTALLER void DataTypesSupportedL(CArrayFix<TDataTypeWithPriority>& aTypeList) const;
	//

	// Not available till ER6.1
	IMPORT_C_NOT_NEEDED_FOR_JAVA_MIDLET_INSTALLER void GetViewsL(CArrayPtr<CApaAIFViewData>& aViewList) const;
	IMPORT_C_NOT_NEEDED_FOR_JAVA_MIDLET_INSTALLER void GetOwnedFilesL(CDesCArray& aOwnedFilesList) const;
	//	

	// utility function
	IMPORT_C_NOT_NEEDED_FOR_JAVA_MIDLET_INSTALLER static void StretchDrawL(CFbsBitmap* aSource,CFbsBitmap* aTarget,TSize aSizeInPixels);
	//
	IMPORT_C_NOT_NEEDED_FOR_JAVA_MIDLET_INSTALLER ~CApaAppInfoFileReader();
public:
	static void GetAifFileNameL(const TDesC& aFullName,TDes& aAifName);
private:
	CApaAppInfoFileReader(RFs& aFs);
	void InternalizeL(RReadStream& aStream);
	void ConstructL(const TDesC& aFileName,TUid aUid);
	void LoadAifFileVersionTwoL(const TDesC& aFileName, TUid aMostDerivedUid);
	void AddIconHeadersL(const TDesC& aFileName, TInt32 aFileOffset, TInt aNumIcons);
private:
	HBufC* iDefaultCaption;
	TUint8* iRomPointer;
	TInt iMbmOffset;
	HBufC* iAifFileName;
#if defined(UI_FRAMEWORKS_V1_REMNANT_FOR_JAVA_MIDLET_INSTALLER)
	TUint32 iJavaMIDletInfo_AmsAuthId;
	TInt iJavaMIDletInfo_MIDlet;
#endif
	};

class CApaAppInfoFileWriter : public CApaAppInfoFile
/**
Aif file writer.

This class writes application information, including icons and captions into the aif file.

@publishedAll
@deprecated */
	{
#if defined(UI_FRAMEWORKS_V1_REMNANT_FOR_JAVA_MIDLET_INSTALLER)
	friend class ForJavaMIDletInstaller;
#endif
public:
	IMPORT_C_NOT_NEEDED_FOR_JAVA_MIDLET_INSTALLER static CApaAppInfoFileWriter* NewLC(RFs& aFs, const TDesC& aFileName,TUid aApplicationUid);
	//
	IMPORT_C TInt SetCapability(const TDesC8& aInfo);
	IMPORT_C void AddCaptionL(TLanguage aLanguage,const TDesC& aCaption);
	IMPORT_C_NOT_NEEDED_FOR_JAVA_MIDLET_INSTALLER void AddIconL(const TDesC& aIconFileName);
	IMPORT_C void AddIconL(CApaMaskedBitmap& aIcon);
	
	// Not available till ER5
	IMPORT_C void AddDataTypeL(const TDataTypeWithPriority& aTypePriority);
	//

	// Not available till ER6.1
	IMPORT_C_NOT_NEEDED_FOR_JAVA_MIDLET_INSTALLER void AddViewL(TUid aViewUid);
	IMPORT_C_NOT_NEEDED_FOR_JAVA_MIDLET_INSTALLER void AddViewL(TUid aViewUid,TInt aScreenMode);
	IMPORT_C_NOT_NEEDED_FOR_JAVA_MIDLET_INSTALLER void AddViewCaptionL(TLanguage aLanguage,const TDesC& aCaption,TUid aViewUid);
	IMPORT_C_NOT_NEEDED_FOR_JAVA_MIDLET_INSTALLER void AddViewIconL(CApaMaskedBitmap& aIcon,TUid aViewUid);
	IMPORT_C_NOT_NEEDED_FOR_JAVA_MIDLET_INSTALLER void StoreViewL(TUid aViewId);
	IMPORT_C_NOT_NEEDED_FOR_JAVA_MIDLET_INSTALLER void AddOwnedFileL(const TDesC& aOwnedFileName);
	//
	
	IMPORT_C void StoreL();
	//
	IMPORT_C ~CApaAppInfoFileWriter();
private:
	CApaAppInfoFileWriter(RFs& aFs);
	void ExternalizeL(RWriteStream& aStream) const;
	void ConstructL(const TDesC& aFileName,TUid aUid
#if defined(UI_FRAMEWORKS_V1_REMNANT_FOR_JAVA_MIDLET_INSTALLER)
					,TUid aMiddleUid=KUidAppInfoFile,TUint32 aJavaMIDletInfo_AmsAuthId=0,TInt aJavaMIDletInfo_MIDlet=0
#endif
					);
private:
	CStoreMap* iMap;
#if defined(UI_FRAMEWORKS_V1_REMNANT_FOR_JAVA_MIDLET_INSTALLER)
	TUint32 iJavaMIDletInfo_AmsAuthId;
	TInt iJavaMIDletInfo_MIDlet;
#endif
	};

class CApaAppCaptionFileReader : public CBase
/**
@internalComponent
*/
	{
public:
	CApaAppCaptionFileReader(RFs& aFs,const TDesC& iAppFileName);
	void GetCaptionsL(TApaAppCaption& aCaption,TApaAppCaption& aShortCaption);
private:	
	RFs& iFs;
	TFileName iCaptionFileName;
	};

class AppInfoFileUtils
// Internal utilities providing helper functions for non-ROM localisation
/**
@internalComponent
*/
	{
public: // For internal use only
	IMPORT_C_NOT_NEEDED_FOR_JAVA_MIDLET_INSTALLER static void GetAifFileName(const RFs& aFs,TDes& aAifName);
public:
	static void GetAifFileNameL(const RFs& aFs,const TDesC& aFullName,TDes& aAifName);
	};
#endif // #if (defined(SYMBIAN_SUPPORT_UI_FRAMEWORKS_V1) || !defined(SYMBIAN_HIDE_UI_FRAMEWORKS_V1)) && !defined(SYMBIAN_REMOVE_UI_FRAMEWORKS_V1)

#endif
