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
// This file contains the API definition for the classes TDelimitedParserBase16
// and CDelimitedData16.
// 
//

/**
 @file DelimitedParser16.h
 @publishedAll
 @released	
*/

#ifndef __DELIMITEDPARSER16_H__
#define __DELIMITEDPARSER16_H__

// System includes
//
#include <e32base.h>
#include <delimitedparsercommon.h>


/**
Comments : Provides non-modifying functionality for parsing data delimited by
a single character. The data is delimited into segments. Uses 16-bit descriptors.

The object contains a descriptor with the data which can be parsed from left
to right, or right to left. It is non-owning. The current segment can be extracted,
which then parses the string for the next segment.

This is a base class and an object of this type cannot be instantiated. It should
be derived. The derived class should ensure that the data iDataDes is set before
calling one of the protected parsing functions. The derived class should also ensure
that the delimiting character has been set.

If the data iDataDes has not been parsed, then calling any functionality that
requires the data to have been parsed will result in a panic
KDelimitedParserErrNotParsed. The data can only be parsed by calling one of the
protected parsing functions from the derived class.

If the delimiting character iDelimiter has not been set, then calling the protected
parsing functions and some of the other public functionality that requires the
delimiter to be set will result in a panic KDelimitingParserErrNoDelimiter.
@publishedAll
@released
@since 6.0
*/
class TDelimitedParserBase16
	{
public:	// Methods

	IMPORT_C void Reset() const;
	
	IMPORT_C TInt GetNext(TPtrC16& aSegment) const;

	IMPORT_C TInt Inc() const;

	IMPORT_C TInt Dec() const;

	IMPORT_C TInt Peek(TPtrC16& aSegment) const;

	IMPORT_C TBool Eos() const;

	IMPORT_C TBool FrontDelimiter() const;

	IMPORT_C TBool BackDelimiter() const;

	IMPORT_C const TDesC16& Des() const;

	IMPORT_C TInt Remainder(TPtrC16& aRemainder) const;

protected:	// Methods

	IMPORT_C TDelimitedParserBase16();

	IMPORT_C void Parse(const TDesC16& aData);

	IMPORT_C void ParseReverse(const TDesC16& aData);

	IMPORT_C void SetDelimiter(TChar aDelimiter);

private:	// Methods

	void DoParse(const TDesC16& aData);

	TInt FindNextSegment(TInt aStartPos) const;

	TInt FindPrevSegment(TInt aStartPos) const;

private:	// Attributes

	/** Descriptor with the string
	 */
	TPtrC16						iDataDes;

	/** Descriptor with the current segment.
	 */
	mutable TPtrC16				iCurrentSegment;

	/** Position of next segment.
	 */
	mutable TInt				iNextSegmentPos;

	/** Direction of parsing.
	 */
	TDelimitedDataParseMode		iMode;

	/** Delimiting character
	*/
	TInt						iDelimiter;

/**
	A friend class.
	@see		CDelimitedDataBase16
	@since		6.0
 */
	friend class CDelimitedDataBase16;

	};

/**
typedef 
@publishedAll
@released
*/
typedef TDelimitedParserBase16 TDelimitedParserBase;

/**
Dependencies : CBase, TDelimitedParserBase16
Comments : Provides functionality for creating and editing a delimited data object.
Uses 16-bit descriptors

The object contains a descriptor buffer with the data. Functionality is provided
to allow segments to be added or removed from the data. There is access to the
internal delimited data parser to provide parsing functionality to be excercised
on the created data.

This a base class that cannot be instantiated. It should be derived. The derived
class must set the delimited data parser, which is an object derived from
TDelimitedParserBase. This helper class must set the delimiting object

If the delimiting character has not been set, then calling any of the functionality
will cause a panic KDelimitedParserErrNoDelimiter.
@publishedAll
@released
@since 6.0
*/
class CDelimitedDataBase16 : public CBase
	{
public: // Methods


	IMPORT_C ~CDelimitedDataBase16();

	IMPORT_C void InsertCurrentL(const TDesC16& aSegment);

	IMPORT_C void RemoveCurrentL();

	IMPORT_C void PushBackL(const TDesC16& aSegment);

	IMPORT_C void PopBackL();

	IMPORT_C void PushFrontL(const TDesC16& aSegment);

	IMPORT_C void PopFrontL();

	IMPORT_C void TrimFrontDelimiterL();

	IMPORT_C void AddFrontDelimiterL();

	IMPORT_C void TrimBackDelimiterL();

	IMPORT_C void AddBackDelimiterL();

	IMPORT_C void Parse();

	IMPORT_C void ParseReverse();

	IMPORT_C const TDelimitedParserBase16& Parser() const;

protected:	// Methods

	IMPORT_C CDelimitedDataBase16();

	IMPORT_C void ConstructL(const TDesC16& aData);

	IMPORT_C void SetDelimiter(TChar aDelimiter);

private:	// Methods

	void SetDataL(const TDesC16& aData);

	void SetData(HBufC16* aDataBuf);

	void DoInsertL(const TDesC16& aSegment);

	void DoRemoveL();

private:	// Attributes

	/** Descriptor buffer.
	 */
	HBufC16*				iDataBuf;

	/** Parser object
	 */
	TDelimitedParserBase16	iParser;

	};

/**
typedef 
@publishedAll
@released
*/
typedef CDelimitedDataBase16 CDelimitedDataBase;

#endif	// __DELIMITEDPARSER16_H__
