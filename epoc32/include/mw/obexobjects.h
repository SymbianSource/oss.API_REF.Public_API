// Copyright (c) 2003-2009 Nokia Corporation and/or its subsidiary(-ies).
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

/**
 @file
 @publishedAll
 @released
*/

#ifndef __OBEXOBJECTS_H
#define __OBEXOBJECTS_H

#include <obextypes.h>
#include <obexbaseobject.h>
#include <f32file.h>

class MObexFileWriter;
class TObexBufferingDetails;

/**
This class is a concrete derivation of the CObexBaseObject class. Use it to 
store and transfer OBEX objects with the body part stored in an EPOC file. 
Hence this class is particularly suited to OBEX "file" beaming applications 
(c.f. arbitrary object beaming), although there is in reality no 
restriction in what it is used to transfer. Access to the body is acheived 
through an additional attribute to the object; the data file. This is the 
file-system name of the file used to store the body of the object. Note 
that there is no explicit relation between this and the Name of the object, 
although it is expected that most applications would attempt to relate the 
two.

When ever a valid data file is set (i.e. DataFile().Length > 0), this file 
is effectively open, hence stopping any other application from opening it 
with exclusive rights. Therefore, it is recommended that Reset () be called 
on the object as soon as it is no longer required, and definitely before 
(conceptually) passing ownership of the data file to any other object or 
user.

CObexFileObject is also suited to situations where an object is expected to 
be received, but no information about the purpose of this object is known. 
This is due to CObexFileObject’s ability to create temporary files "on the 
fly" to store received data into, when a specific file is not provided by 
the application.

This class is not designed for user derivation.

@publishedAll
@released
*/
NONSHARABLE_CLASS(CObexFileObject) : public CObexBaseObject
	{
public:
	static IMPORT_C CObexFileObject* NewL();
	static IMPORT_C CObexFileObject* NewL(const TDesC &aDataFile);
	virtual IMPORT_C ~CObexFileObject();
	IMPORT_C void InitFromFileL(const TDesC& aFile);

private:
	void ConstructL(const TDesC &aDataFile);
	void SetDataFileL(const TDesC& aDesc);
	const TDesC& DataFile();
	TBool RenameFile(const TDesC& aDesC);
	void SetTempFilePath(const TDesC& aPath);
	void QueryTempFilePath(TDes& aPath);
	// From CObexBaseObject
	virtual void GetData(TInt aPos, TDes8& aDes);
	virtual void NewData(TInt aPos, TDes8& aDes);
	virtual TInt DataSize();
	virtual void ResetData();
// Data
private:
	RFs iFs;
	TParse iDataFile;
	RFile iFile;
	TBuf<KObexObjectDescriptionSize> iTempFilePath;
	};



/**
Use this class to hold objects where the body part is stored in a CBufFlat
object. Please note that although parameters are supplied as CBufBase objects,
non-CBufFlat parameters are not supported and will have unpredictable results.
At no point does the CObexBufObject create, or take ownership of any CBaseBuf
object it uses - it is always the responsibility of the creator/owner of the
CBaseBuf to free it when no longer required.

As this class does not take ownership of the buffers it uses, it equally can
not create its own buffers ad-hoc for storing new data into. Hence at no 
time is it valid for a CObexBufObject to exist with out it having a valid 
data buffer set. If such a situation arises, where it is required that 
received information should be discarded, consider using a CObexNullObject.

It is also posible to supply a file instead of a memory buffer, or to supply
both.  This functionality is due to the MObexServerNotify class expecting to
work only on CObexBufObjects, so CObexFileObjects cannot be returned from the
upcalls.
To use a file for body storage, call NewL() passing in a NULL pointer, then
call SetDataBufL() manually afterwards.  There are three overloads---to allow
purely memory based objects, purely file based, or a hybrid.  The hybrid object
buffers into a memory buffer (which is not allowed to grow), then writes data
to the file when the buffer is full.  The buffering behaviour can therefore be
tuned to the application by setting the size of the buffer prior to use.

This class is not designed for user derivation.

@publishedAll
@released
*/
NONSHARABLE_CLASS(CObexBufObject) : public CObexBaseObject
	{
public:
	/**
	Obex file buffering method.
	
	@publishedAll
	@released
	*/
	enum TFileBuffering
		{
		/** Only the supplied buffer will be used to buffer file writes. */
		ESingleBuffering,
		/** The object will create a second buffer and perform double buffering. */
		EDoubleBuffering
		};

public:
	static IMPORT_C CObexBufObject* NewL(CBufBase* aDataBuf);
	virtual IMPORT_C ~CObexBufObject();
	IMPORT_C TInt WriteToFile(const TPtrC& aFileName);
	
	IMPORT_C void SetDataBufL(TObexBufferingDetails& aDetails);
	IMPORT_C void SetDataBufL(CBufBase* aDataBuf);
	IMPORT_C void SetDataBufL(const TPtrC& aFilename);
	IMPORT_C void SetDataBufL(const TPtrC& aFilename, CBufBase* aDataBuf);
	IMPORT_C void SetDataBufL(const TPtrC& aFilename, CBufBase& aDataBuf, const TFileBuffering aBufferingStrategy);
	IMPORT_C CBufBase* DataBuf();
	HBufC* FileName();

private:
	CObexBufObject();
	void ConstructL(CBufBase* aDataBuf);
	
	void PrepareToSetBufferL();

	void CopyFileL(const TDesC& aFilename);
	TInt NewFileData(TInt aPos, TDes8& aDes);
	void GetFileData(TInt aPos, TDes8& aDes);

	// From CObexBaseObject
	virtual void GetData(TInt aPos, TDes8& aDes);
	virtual void NewData(TInt aPos, TDes8& aDes);
	virtual TInt DataSize();
	virtual void ResetData();

	void CloseDataFile();
	TInt OpenDataFile(const TDesC& aFilename);
	void CloseFileServer();
	TInt OpenFileServer();
	TInt WriteBufferToFile(TBool aFinal);

// Data
private:
	CBufBase* iBuf;
	HBufC* iFilename;
	RFs* iFileServ;
	RFile* iFile;
	TInt iBufOffset;
	TInt iBuffered;
	TInt iBufSegSize;

// Added for double-buffering
private:
	// Owned
	MObexFileWriter*	iWriter;
	CBufBase*			iDoubleBuf;
	};



/**
Wraps parameters which can affect the buffering method used by the
CObexBufObject.
This version provides a single memory buffer which holds the entire object.
Subclasses will always use a memory buffer, but can override the way that
Obex uses it.

@publishedAll
@released
*/
NONSHARABLE_CLASS(TObexBufferingDetails)
	{
public:
	/**
	Versions (subclasses) of the buffering style object.
	This enum should not be used outside the dll.
	@internalComponent
	*/
	enum TVersion
		{
		EBasicBuffer,
		EPureFile,
		EFilenameBackedBuffer,
		ERFileBackedBuffer,
		ELastVersion
		};
	
	IMPORT_C TObexBufferingDetails(CBufBase& aBuffer);
	
	TVersion Version();	// Return the version of this object
	CBufBase* Buffer();

protected:
	TObexBufferingDetails(TVersion aVersion, CBufBase* aBuffer);

private:
	TVersion iVersion;
	CBufBase* iBuffer;

	// This data padding has been added to help prevent future binary compatibility breaks	
	// Neither iPadding1 nor iPadding2 have been zero'd because they are currently not used
	TUint32     iPadding1; 
	TUint32     iPadding2; 	
	};


/**
Provides alternate behaviour for a CObexBufObject, allowing use of a file
to hold the object in its entirety.  No memory buffer is used.  This is a
special case option provided to cater for the MObexServerNotify interface
which requires the use of CObexBufObject objects.  It is generally better to
use a buffered variant.

@publishedAll
@released
*/
NONSHARABLE_CLASS(TObexPureFileBuffer) : public TObexBufferingDetails
	{
public:
	IMPORT_C TObexPureFileBuffer(const TPtrC& aFilename);
	const TPtrC& Filename();

private:
	const TPtrC& iFilename;

	// This data padding has been added to help prevent future binary compatibility breaks	
	// Neither iPadding1 nor iPadding2 have been zero'd because they are currently not used
	TUint32     iPadding1; 
	TUint32     iPadding2; 
	};

/**
Provides alternate behaviour for a CObexBufObject, allowing use of a file
to hold the object in its entirety.  Writes to this object are buffered through
the supplied CBufBase derived object, which is never enlarged.  Once
it is full, the data is flushed to the file.

@publishedAll
@released
*/
NONSHARABLE_CLASS(TObexFilenameBackedBuffer) : public TObexBufferingDetails
	{
public:
	IMPORT_C TObexFilenameBackedBuffer(CBufBase& aBuffer, const TPtrC& aFilename, CObexBufObject::TFileBuffering aBufferingStrategy);
	const TPtrC& Filename();
	CObexBufObject::TFileBuffering Strategy();
	
private:
	const TPtrC& iFilename;
	CObexBufObject::TFileBuffering iBufferingStrategy;

	// This data padding has been added to help prevent future binary compatibility breaks	
	// Neither iPadding1 nor iPadding2 have been zero'd because they are currently not used
	TUint32     iPadding1; 
	TUint32     iPadding2; 	
	};



/**
Provides alternate behaviour for a CObexBufObject, allowing use of a file
to hold the object in its entirety.  Writes to this object are buffered through
the supplied CBufBase derived object, which is never enlarged.  Once
it is full, the data is flushed to the file.

@publishedAll
@released
*/
NONSHARABLE_CLASS(TObexRFileBackedBuffer) : public TObexBufferingDetails
	{
public:
	IMPORT_C TObexRFileBackedBuffer(CBufBase& aBuffer, RFile aFile, CObexBufObject::TFileBuffering aBufferingStrategy);
	RFile File();
	CObexBufObject::TFileBuffering Strategy();
	
private:
	RFile iFile;
	CObexBufObject::TFileBuffering iBufferingStrategy;

	// This data padding has been added to help prevent future binary compatibility breaks	
	// Neither iPadding1 nor iPadding2 have been zero'd because they are currently not used
	TUint32     iPadding1; 
	TUint32     iPadding2; 
	};



/**
Concrete OBEX object with NULL data representation. Use when only the 
headers of an object are required, and the data (if any) can safely be 
discarded.

@publishedAll
@released
*/
NONSHARABLE_CLASS(CObexNullObject) : public CObexBaseObject
	{
public:
	IMPORT_C static CObexNullObject* NewL ();
private:
	// From CObexBaseObject
	void ConstructL();
	virtual void GetData (TInt aPos, TDes8& aDes);
	virtual void NewData (TInt aPos, TDes8& aDes);
	virtual TInt DataSize ();
	virtual void ResetData ();
	};

#endif // __OBEXOBJECTS_H
