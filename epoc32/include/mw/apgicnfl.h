// Copyright (c) 1997-2009 Nokia Corporation and/or its subsidiary(-ies).
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
// apgicnfl.h
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

/** An application icon.

This is a bitmap and a mask, managed by the Font and Bitmap server.

An object of this type is passed to RApaLsSession::GetAppIcon() to fetch a 
suitable application icon.

@publishedAll
@released
@see RApaLsSession::GetAppIcon() */
class CApaMaskedBitmap : public CFbsBitmap
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

#ifndef SYMBIAN_ENABLE_SPLIT_HEADERS
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

#endif //SYMBIAN_ENABLE_SPLIT_HEADERS

#endif

