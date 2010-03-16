// Copyright (c) 1998-2009 Nokia Corporation and/or its subsidiary(-ies).
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
// BSP.H (Base Script Parser)
// Abstract class for different Parsers.
// 
//


#if !defined(__BSP_H__)
#define __BSP_H__

#if !defined(__MTCLREG_H__)
#include <mtclreg.h>
#endif

#if !defined(__MTCLBASE_H__)
#include <mtclbase.h>
#endif

#include <e32base.h>
#if !defined(__S32STRM_H__)
#include <s32strm.h>
#endif

#include <msvstd.h>
// CRichText etc. includes
#include <txtrich.h>
#include <txtfmlyr.h>

#include <bif.h>



// Symbols:
/** Space character. */
#define KCharSpace          ' '
/** Tab character. */
#define KCharTab            '\t'
/** Line feed character. */
#define KCharLineFeed       '\n'


// Define some generic error codes:
/** BIO error code base. */
const TInt KBspBaseError					= (-500);

/** Invalid BIO message error code. */
const TInt KBspInvalidMessage				= (KBspBaseError);
/** Invalid smart message token error code. */
const TInt KBspSmartMessageInvalidToken		= (KBspBaseError-1);
/** No smart message parser defined error code. */
const TInt KBspSmartMessageNoParserDefined	= (KBspBaseError-2);

// Parsed field class for use by parsers.
class CParsedField : public CBase
/** Represents a single token-value pair for a given field in a BIO/smart message 
grammar. 
@publishedAll
@released
*/
{
public:
	IMPORT_C CParsedField();
	IMPORT_C ~CParsedField();

	IMPORT_C TPtrC FieldName() const;
	IMPORT_C void SetFieldNameL( const TDesC& aFieldName);
	IMPORT_C TPtrC FieldValue() const;
	IMPORT_C void SetFieldValueL( const TDesC& aFieldValue);
	IMPORT_C TBool MandatoryField() const;
	IMPORT_C void SetMandatoryField(TBool aMandatoryField);

	IMPORT_C void InternalizeL(RReadStream& aStream);
	IMPORT_C void ExternalizeL(RWriteStream& aStream) const;
private:
	void Reset();
private:
	HBufC* iFieldName;
	HBufC* iFieldValue;
	TBool  iMandatoryField;
};

// Forward declarations:
class CMsvServerEntry;
class CMsvEntry;
class CRegisteredParserDll;
class RMsvReadStream;
class RMsvWriteStream;
class CMsvStore;
class CSmsMessage;



/** Base class for BIO message parsers V2.

Concrete derived classes are implemented in parser DLL's to parse particular 
types of BIO message.

On receiving an appropriate command (see TBioOperation), the BIO server MTM 
loads the appropriate parser and passes the message body to it for interpretation. 
In fact, the parser interface expects the parser to divide its operation into 
two stages: 

1. parsing: which involves extracting information from the raw message body and 
storing it in a structured format. The parsing stage can also alter the message 
body, and create files in the directory associated with the message (e.g. 
parsing a ring tones message will generate a ring tone file).

2. processing: which involves using the extracted information to achieve the 
purpose of the BIO message (e.g. setting some phone configuration setttings).

This separation allows, for example, a UI to display the parsed information 
to the user for confirmation, before it is acted upon. For some parsers, however, 
this two stage division is not sensible, in which case they implement only 
the first.

The base class provides a pointer iSettings to reference the raw message data, 
and an array of token-value pairs, iParsedFieldArray, for storing parsed information 
(if this is appropriate). 
@publishedAll
@released
*/
class CBaseScriptParser2: public CActive
	{
public:
	IMPORT_C CBaseScriptParser2(CRegisteredParserDll& aRegisteredParserDll, CMsvEntry& aEntry, RFs& aFs);
	IMPORT_C ~CBaseScriptParser2();

	/** Called by the BIO server MTM to asynchronously parse message body data.
	
	When parsing is complete, the function should indicate this by setting the 
	message's index field iMtmData3 to 1.
	
	The function should leave if the buffer cannot be parsed successfully.
	
	@param aStatus Asynchronous status word
	@param aSms Buffer to parse */
	virtual void ParseL(TRequestStatus& aStatus, const TDesC& aSms)=0; //parses sms data into CParsedField
	/** Called by the BIO server MTM to asynchronously process the parsed data.
	
	The function takes appropriate parser-specific action on the results of a 
	previous call to ParseL().
	
	When processing is complete, the function should indicate this by setting 
	the message's index field iMtmData3 to 2.
	
	The function should leave if processing is not successful.
	
	@param aStatus Asynchronous status word */
	virtual void ProcessL(TRequestStatus& aStatus)=0; //stores parsed data into streams and data base

	IMPORT_C TUid ParserUid();
	IMPORT_C void RestoreL(CMsvStore& aMessageStore);
	IMPORT_C void StoreL(CMsvStore& aMsvStore) const;
	IMPORT_C void RestoreL(const TFileName& aFileName);
	IMPORT_C void StoreL(const TFileName& aFileName) const;
	IMPORT_C void ResetL();
	
protected:
//	Parsing:
	IMPORT_C void UnfoldMessageL();

//	Streaming operations:
	void InternalizeL(RMsvReadStream& aStream);
	void ExternalizeL(RMsvWriteStream& aStream) const;

protected:
	/** Object that loaded the parser. It contains a reference counter of the use of 
	the parser. */
	CRegisteredParserDll&		iRegisteredParserDll;
	/** The message entry the parser should parse. */
	CMsvEntry&					iEntry;
	/** Connected file server handle. */
	RFs&						iFs;

	/** Lexer intended for Smart Message use.
	
	This is not used by the base class. */
	TLex						iSms;
	/** Array of token-value pairs.
	
	Derived classes can use this for storing parsed information (if this is appropriate). */
	CArrayPtrSeg<CParsedField>* iParsedFieldArray;

	/** Flag intended for Smart Message use.
	
	This is not used by the base class. */
	TBool						iSmsParsed;
	/** ID of iEntry. */
	TMsvId						iEntryId;
	
	/** Pointer to message data.
	
	This is not set by the base class. */
	HBufC*						iSettings;
	/** Pointer to SMS data (intended for Smart Message use).
	
	This is not set by the base class. */
    HBufC*						iSmsBuf;                // Local copy of buffer passed to ParseL()
	/** Temporary pointer used by RestoreL(). */
	HBufC8*						iReadBuffer;			// used to restore data from file
	};

 
/** BIO data location flag values.

@see TMsvBIOEntry */
enum TMsvBIODataLocation
	{
	/** Unknown. */
	EUnknown,
	/** Parser wrote data into the body text. */
	EBodyText,		// parser wrote data back into richText
	/** Parser wrote data into the parsed fields data stream. */
	EBIODataStream,	// parser wrote data into KUIDMsvBioStream
	/** Parser wrote data into an attachment file. */
	EFile			// parser wrote data into attachment file
	};


/** Bearer Independent Object entry.
Specialises the TMsvEntry message entry class to store additional BIO message-specific 
information. 
@internalTechnology
@released
*/
class TMsvBIOEntry : public TMsvEntry
	{
public:
	/** Constructor. */
	TMsvBIOEntry() : TMsvEntry() {};
	void SetBIOParserUid(const TUid aId);
	const TUid BIOParserUid() const;
	void SetLocationOfData(const TMsvBIODataLocation aLocation);
	const TMsvBIODataLocation LocationOfData() const;

private:
	TMsvBIODataLocation	iLocationOfData;
	};

#include <bsp.inl>

#endif
