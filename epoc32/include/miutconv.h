// Copyright (c) 1999-2009 Nokia Corporation and/or its subsidiary(-ies).
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

#ifndef __MIUTCONV_H__
#define __MIUTCONV_H__

#include <e32base.h>


#if !defined (__CHARCONV_H_)
#include <charconv.h>
#endif

#if !defined (__MIUTHDR_H__)
#include <miuthdr.h>		
#endif

#if !defined (__UTF_H_)
#include <utf.h>
#endif

// IMail-specific stream type within an IMail file store for TImEmailTransformingInfo
//
const TUint KUidMsvCharsetNone				= {0x10003C7F};		// 268450943
const TUid KUidMsgFileTransformingInfo		= {0x100094A5};		// 268473509
const TUid KUidMsgEmailGeneralCenRep		= {0x10285A25};		// 271079973

// No longer used as the charset information retrieved from resource file.
// Might possibly needed in the future ? maybe
// const TUid KUidMiutSystemDefaultCharset		= {0x10009418};		// 268473368
// const TUid KUidMiutOverrideCharset			= {0x10009419};		// 268473369

_LIT8(KMiutUndisplayableChar, "?");

/** SMTP send methods. 
@publishedAll
@released
*/
enum TImSendMethod
	{ 
	/** Simple email. */
	ESendAsSimpleEmail,
	/** MIME email. */
	ESendAsMimeEmail
	};	


// Information to be used when sending an email message.
// Relating to how parts are encoded and converted.
//
class TImEmailTransformingInfo
/** Encapsulates character conversion and encoding settings for sending SMTP email.

The default outcomes for header, body, HTML, and attachment parts respectively 
for each of the listed categories are given below:

Plain Charset: ISO-8859-1,ISO-8859-1,N/A,N/A

Plain Encoding:None,None,N/A,UU

MIME Charset:UTF8,UTF8,UTF8*,N/A

MIME Encoding:B,QP,Base64,Base64

*: the UTF8 value set in the header field, but no conversion is done. The 
HTML converter converts to UTF8. 
@publishedAll
@released
*/
	{
public:
    IMPORT_C TImEmailTransformingInfo& operator=(const TImEmailTransformingInfo& aInfo);
    IMPORT_C TBool operator==(const TImEmailTransformingInfo& aInfo);
	
	// streaming operations
	IMPORT_C void ExternalizeL( RWriteStream& aWriteStream ) const;
	IMPORT_C void InternalizeL( RReadStream& aReadStream );
	IMPORT_C void StoreL( CMsvStore& aStore ) const;
	IMPORT_C void RestoreL( CMsvStore& aStore );

	// Setting functions
	IMPORT_C void SetToDefault(const TImSendMethod aMethod);
	IMPORT_C void SetSendMethod(const TImSendMethod aMethod);
	IMPORT_C TImSendMethod SendMethod() const;

	IMPORT_C void SetHeaderEncodingQ();
	IMPORT_C void SetHeaderEncodingB();
	IMPORT_C void SetBodyTextEncoding(TImEncodingType aType);
	IMPORT_C void SetHTMLEncoding(TImEncodingType aType);
	IMPORT_C void SetAttachmentEncoding(TImEncodingType aType);
	
	IMPORT_C void SetHeaderAndBodyCharset(TUint aCharset);
	IMPORT_C void SetHeaderCharset(TUint aCharset);
	IMPORT_C void SetBodyTextCharset(TUint aCharset);
	IMPORT_C void SetHTMLCharset(TUint aCharset);

	// Accessor functions
	IMPORT_C TImEncodingType HeaderEncoding() const;
	IMPORT_C TImEncodingType BodyTextEncoding() const;
	IMPORT_C TImEncodingType HTMLEncoding() const;
	IMPORT_C TImEncodingType AttachmentEncoding() const;
	
	IMPORT_C TUint HeaderCharset() const;
	IMPORT_C TUint BodyTextCharset() const;
	IMPORT_C TUint HTMLCharset() const;

private:
	void SetHeaderEncoding(TImEncodingType aType);

private:
	TImEncodingType	iHeaderEncoding;	
	TImEncodingType	iBodyEncoding;	
	TImEncodingType	iHTMLEncoding;	
	TImEncodingType	iAttachmentEncoding;	

	TUint	iHeaderCharset;	
	TUint	iBodyCharset;	
	TUint	iHTMLCharset;	
	TUint	iTextAttachmentCharset;	

	TImSendMethod iSendMethod;
	};


// Default Sending Charset/Encoding Values
const TImEncodingType KDefaultMIMEHeaderEncoding	=	EEncodingTypeBASE64;		// MIME
const TImEncodingType KDefaultMIMEBodyTextEncoding	=	EEncodingTypeQP;
const TImEncodingType KDefaultMIMEHTMLEncoding		=	EEncodingTypeBASE64;
const TImEncodingType KDefaultMIMEAttachmentEncoding=	EEncodingTypeBASE64;

#define KDefaultPlainCharset		KCharacterSetIdentifierIso88591

const TImEncodingType	KDefaultPlainHeaderEncoding		=	EEncodingTypeNone;	// Non-MIME or Plain
const TImEncodingType	KDefaultPlainBodyTextEncoding	=	EEncodingTypeNone;
const TImEncodingType KDefaultPlainAttachmentEncoding	=	EEncodingTypeUU;




// Wrapper class for CHARCONV.
// 'Our' charset dependant on build, UNICODE or CodePage 1252.
//
class CImConvertCharconv : public CBase
/**
@internalTechnology
@released
*/
	{
public:	
	IMPORT_C static CImConvertCharconv* NewL(CCnvCharacterSetConverter& aConverter, RFs& anFs);
	~CImConvertCharconv();

	// MUST call prepare function first.
	IMPORT_C TInt ConvertToOurCharsetL( const TDesC8& aBufIn, TDes& rBufOut, 
										TInt& rNumUnconvertedChars, 
										TInt& rIndexOfFirstUnconvertedChar);
	IMPORT_C TInt ConvertFromOurCharsetL(const TDesC& aBufIn, TDes8& rBufOut, 
										 TInt& rNumUnconvertedChars,
										 TInt& rIndexOfFirstUnconvertedChar);

	// MUST be called prior to calling above two functions.
	IMPORT_C TInt PrepareToConvertToFromOurCharsetL(const TUint aUid);

	IMPORT_C TUint GetMimeCharsetUidL(const TDesC8& aBufIn) const;
	IMPORT_C HBufC8* GetMimeCharsetTextStringL(const TUint& aUid) const;
	IMPORT_C TUint DefaultCharset() const;
	IMPORT_C TUint SystemDefaultCharset() const;

	static TInt StraightCopy( const TDesC8& aBufIn, TDes& rBufOut);
	static TInt StraightCopy( const TDesC& aBufIn, TDes8& rBufOut);
private:
	void ConstructL();
	CImConvertCharconv(CCnvCharacterSetConverter& aConverter, RFs& anFs);
	TBool CharsetAvailable(const TUint aUid);
	void SetSystemDefaultCharsetL();

	TInt GetSystemCharsetFromCenRepL(TDes8& aMimeCharSet);

	enum TEmailGeneralSettingsCenRepId
		{
		EEmailGeneralCharSetId				= 0x00000000
		};

private:
	CCnvCharacterSetConverter& iConverter;
	CArrayFix<CCnvCharacterSetConverter::SCharacterSet>* iCharsetsAvailable; 

	RFs& iFs;
	TUint iCharsetUid;
	TUint iSystemDefaultCharset;		// Value obtained from .ini file
	TInt  iCharconvState;
	};

#endif
