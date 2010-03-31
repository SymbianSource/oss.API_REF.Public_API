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

#ifndef __OBEXHEADERS_H
#define __OBEXHEADERS_H

#include <obextypes.h>

/**
Encapsulates an Obex header.

This class provides the ability to hold a header of any of the Obex
supported types as a native Symbian OS type.

A header may also have one or more attributes set.  These are used by
the object which owns the header collection so that it can keep track
of which headers should be sent (!(ESuppressed || EDeleted)), which have
been sent (ESent), and whether the header should be deleted (EDeleted).
Deletion is a special case---any operation on the Object which causes
a scan of the headers will trigger deletion of any marked headers.
This is required as they are owned by the Object, but can be accessed
seperately (including through the creator keeping a pointer to the
header).

@see CObexBaseObject
@publishedAll
@released
*/
NONSHARABLE_CLASS(CObexHeader) : public CBase
	{
public:
	// Requires friendship with CObexBaseObject to support some aspects of the
	// legacy API (specifically the HTTP accessor method).
	friend class CObexBaseObject;

	enum THeaderType
		{
		EUnicode  = 0x00,
		EByteSeq  = 0x01,
		EByte     = 0x02,
		EFourByte = 0x03
		};
	
	enum THeaderAttr
		{
		ESuppressed = 0x01,
		ESent       = 0x02,
		EDeleted    = 0x04,
		};
		
	IMPORT_C static CObexHeader* NewL();
	virtual ~CObexHeader();
	IMPORT_C CObexHeader* CopyL() const;
	
	//Sets this object to use the same underlying header as the parameter.
	IMPORT_C void Set(CObexHeader* aHeader);
	//Resets the contents of this header, discarding the underlying data.
	IMPORT_C void Reset();
	
	//Resets and destroys all header attributes.
	IMPORT_C void ResetContents();
	
	IMPORT_C void SetAttributes(TUint16 aAttr);
	IMPORT_C TUint16 Attributes() const;
	
	IMPORT_C THeaderType Type() const;
	
	IMPORT_C TUint8   HI() const;
	IMPORT_C TUint8   AsByte() const;
	IMPORT_C TUint32  AsFourByte() const;
	IMPORT_C const TDesC8&  AsByteSeq() const;
	IMPORT_C const TDesC16& AsUnicode() const;

	IMPORT_C void SetByte(const TUint8 aHI, const TUint8 aByte);
	IMPORT_C void SetFourByte(const TUint8 aHI, const TUint32 aFourByte);
	IMPORT_C void SetByteSeqL(const TUint8 aHI, const TDesC8& aByteSeq);
	IMPORT_C void SetUnicodeL(const TUint8 aHI, const TDesC16& aUnicode);

	IMPORT_C TInt EncodedSize() const;
	
private:
	CObexHeader();
	CObexHeader(CObexUnderlyingHeader* aHeader);
	void ConstructL();
	
private:
	CObexUnderlyingHeader* iHeader;
	};

/**
Used to allow the iterator to decide whether to present a header to
the user, by passing in a possible header HI value.  Headers present
in the object will be presented to the Interested() function in the 
object in which they are held (if received from a remote device
this will be the order in which they were received, otherwise this will
be the order in which they were set).
The function can implement any desired behaviour, including relying on
the order in which the headers are presented.

In case any state is held, the object also provides a Reset() function.
Reset() provides a default empty implementation.

Note: there is no destructor. 
 
@publishedAll
@released
*/
class MObexHeaderCheck 
	{
public:
	/**
	Called to discover is the user is interested in the contents of
	this header.
	
	@param aHI The identifier of the header, including type bits.
	@return ETrue if the user is interested in the contents of this
	header.
	@publishedAll
	@released
	*/
	IMPORT_C virtual TBool Interested(TUint8 aHI) =0;
	
	/**
	Called in response to First() being called on the iterator object.
	The default implementation does nothing---some implementations may
	wish to reset state variables.
	
	@publishedAll
	@released
	*/
	IMPORT_C virtual void Reset();
	
	/**
 	Returns a null aObject if the extension is not implemented, or a pointer to another interface if it is.
	@param aInterface UID of the interface to return
	@param aObject the container for another interface as specified by aInterface
	@publishedAll
	*/
	IMPORT_C virtual void MOHC_ExtensionInterfaceL(TUid aInterface, void*& aObject);
	};

/**
A collection of headers.  Includes code to filter based on the header HI
value, iterate through the set of interesting headers, and extract headers
with specific HI values.
 
@publishedAll
@released
*/
NONSHARABLE_CLASS(CObexHeaderSet) : public CBase
	{
public:
	IMPORT_C static CObexHeaderSet* NewL();
	IMPORT_C CObexHeaderSet* CopyL();
	IMPORT_C CObexHeaderSet* CopyL(MObexHeaderCheck& aHeaderCheck);
	~CObexHeaderSet();

	IMPORT_C TInt AddHeader(CObexHeader* aHeader);
	IMPORT_C void DeleteCurrentHeader();

	IMPORT_C void SetMask(MObexHeaderCheck* aMask);
	IMPORT_C void DeleteMasked();
	
	IMPORT_C void First() const;
	IMPORT_C TInt This(CObexHeader* aHeader) const;
	IMPORT_C TInt Next() const;
	IMPORT_C TInt Next(TInt aSkip) const;
	IMPORT_C TInt Count() const;
	
	IMPORT_C TInt Find(TUint8 aHI, CObexHeader& aHeader) const;
	
private:
	CObexHeaderSet();

private:
	RPointerArray<CObexHeader> iHeaders;
	mutable MObexHeaderCheck* iMask;
	mutable TInt iPos;
	};

/** 
@publishedAll
@released
*/
NONSHARABLE_CLASS(TObexMatchHeader) : public MObexHeaderCheck
	{
public:
	virtual EXPORT_C TBool Interested(TUint8 aHI);
	IMPORT_C void SetHeader(TUint8 aHI);

private:
	TUint8 iHI;
	
private:
	// This data padding has been added to help prevent future binary compatibility breaks	
	// Neither iPadding1 nor iPadding2 have been zero'd because they are currently not used
	TUint32     iPadding1; 
	TUint32     iPadding2; 	
	};

/** 
@publishedAll
@released
*/
NONSHARABLE_CLASS(TObexMatchHeaderType) : public MObexHeaderCheck
{
public:
	virtual EXPORT_C TBool Interested(TUint8 aHI);
	IMPORT_C void SetType(CObexHeader::THeaderType aType);

private:
	TInt iType;

private:
	// This data padding has been added to help prevent future binary compatibility breaks	
	// Neither iPadding1 nor iPadding2 have been zero'd because they are currently not used
	TUint32     iPadding1; 
	TUint32     iPadding2; 	
	};

#endif // __OBEXHEADERS_H
