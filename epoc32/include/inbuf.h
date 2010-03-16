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

#if !defined(__INBUF_H__)
#define __INBUF_H__

#if !defined(__F32FILE_H__)
#include <f32file.h>
#endif

#if !defined(__S32STOR_H__)
#include <s32stor.h>
#endif

const TInt KErrEndOfInput = -1000;


class CImportBufferBase : public CBase
/**
The purpose of this class is to provide a method of
abstracting the source of an input through a buffer
The class is intended to be used for a single input then destroyed
@publishedPartner
@deprecated>
*/
	{
public:
	IMPORT_C CImportBufferBase(TInt aMaxSize);
	IMPORT_C ~CImportBufferBase();
	IMPORT_C void ConstructL();
	IMPORT_C TInt ReadL(TText8& aByte);
	// !! Descriptor versions of ReadL useful?
	IMPORT_C virtual TInt SeekL(TSeek aSeekMode, TInt anOffset);
	IMPORT_C void ResetImportBuffer();
	IMPORT_C void ResetReadPtr();
protected:
	virtual TInt FillImportBuf()=0;
	IMPORT_C TInt MaxSize();
	IMPORT_C void SetLength(TInt aLength);
protected:
	TInt iImportBufferLength; 
	HBufC8* iImportBuffer;
private:
	TText8* iReadPtr;
	TText8* iEndBuf;
	TText8* iTBase;
	TInt iMaxSize;
	};


class CFileImportBuffer : public CImportBufferBase
/**
Buffered import from a file
@publishedPartner
@deprecated
*/
	{
	// Buffered import from a file
public:
	IMPORT_C CFileImportBuffer(RFile aSource, TInt aMaxSize);
	IMPORT_C TInt SeekL(TSeek aSeekMode, TInt anOffset);
protected:
	IMPORT_C TInt FillImportBuf();
private:
	RFile iSource;
	};

#endif // __INBUF_H__
