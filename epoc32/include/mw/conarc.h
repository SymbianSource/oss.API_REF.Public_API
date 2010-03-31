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

#if !defined(__CONARC_H__)
#define __CONARC_H__

#if !defined(__E32BASE_H__)
#include <e32base.h>
#endif
#if !defined(__APMSTD_H__)
#include <apmstd.h>
#endif

//
// base interface for converters
//

/**
@publishedAll
@released
*/
const TInt KUidConverterToBase64=0x10000721;
/**
@publishedAll
@released
*/
const TInt KUidConverterFromBase64=0x100011C5;
/**
@publishedAll
@released
*/
const TInt KUidPlainTextToQuotedPrintableConverter=0x10001826;
/**
@publishedAll
@released
*/
const TInt KUidQuotedPrintableToPlainTextConverter=0x10001825;
/**
@publishedAll
@released
*/
const TInt KUidETextToPlainTextConverter=
#if defined(ETEXT_CONVERTER_UIDS_CORRECTED)
	0x100040c8;
#else
	0x100040c7;
#endif
 
/**
@publishedAll
@released
*/
const TInt KUidPlainTextToETextConverter=
#if defined(ETEXT_CONVERTER_UIDS_CORRECTED)
	0x100040c7;
#else
	0x100040c8;
#endif
 
/**
@publishedAll
@released
*/
#ifdef _UNICODE
#define KUidConverterDll KUidConverterDll16
#else
#define KUidConverterDll KUidConverterDll8
#endif

/**
@internalComponent
@deprecated
*/
const TInt KUidConverterDllValue8=0x10000C61;

/**
@internalComponent
@deprecated
*/
const TUid KUidConverterDll8={KUidConverterDllValue8};

/**
@internalComponent
*/
const TInt KUidConverterInfoFileValue=0x10000C62;

/**
@publishedAll
@released
*/
const TUid KUidConverterInfoFile={KUidConverterInfoFileValue};

/**
@internalComponent
*/
const TInt KUidConverterInfoStreamValue=0x10000CD0;

/**
@internalComponent
*/
const TUid KUidConverterInfoStream={KUidConverterInfoStreamValue};

/**
The UID2 of converter-type DLLs.
@publishedAll
@released
*/
const TUid KUidConverterDll16={0x10003A30};

/**
The extension of converter information files.
@publishedAll
@released
*/
_LIT(KConverterInfoFileExtension,".CNF");
/**
The extension of converter DLLs.
@publishedAll
@released
*/
_LIT(KConverterDllExtension,".CNV");


class MConverterUiObserver
/**
Interface implemented by the client of a conversion operation to observe conversion 
progress.

@see CConverterBase2
@publishedAll 
@released
*/
	{
public:
	/** Describes the result of a conversion operation. */
	enum TResult
		{
		/** Conversion succeeded. */
		ESuccess,
		/** Conversion partially succeeded. */
		EPartialSuccess,
		/** Conversion failed. */
		EFailure
		};
	/** Describes the actions that the converter should take. */
	enum TAction
		{
		/** Keep already converted data. */
		ERetain,
		/** Delete converted data. */
		ERemove,
		/** Reconvert data. */
		ERepeat
		}; 
public:
	/** Gets the maximum number of steps that the conversion operation can take. 
	
	The conversion may complete in less than this number of steps (for example 
	if an error occurs or the action is cancelled). 
	
	Each step is a call to CConverterBase2::DoConvert(), although during synchronous 
	conversions this is transparent to the client code.
	
	@param aMax Maximum number of conversion steps.
	@param aObject Index that identifies an embedded object when one is being converted. */
	virtual void MaxSteps(TInt aMax, TInt aObject)=0;
	/** Alerts the client to an error in conversion.
	
	@param aResult A TResult value indicating the conversion state.
	@param aObject Index that identifies an embedded object when one is being converted.
	@return A TAction value that indicates what action the converter should take. */
	virtual TInt Result(TInt aResult, TInt aObject)=0;
	/** Queries the client for a password in order to access the data.
	
	@param aClue Data with a meaning that is specific to each converter: it could for 
	example indicate where the password is stored.
	@return The password entered. */
	virtual HBufC* QueryPasswordL(const TDesC& aClue)=0;
	IMPORT_C virtual void Reserved1_Conv_Obs();
	};


class CConverterBase : public CBase
/** For Ecom Style Converters i.e.,for v9.1 and above CConverterBase2 should be used.

Polymorphic interface for converters from one data format to another.

Clients use this interface to access data converters. The implementator of 
a data converter derives a class from this in which to implement the appropriate 
conversion functionality.

The interface offers conversions between files, and between objects that support 
the stream interfaces, e.g. stream stores.

There are two flavours of conversion methods:

the synchronous interfaces, ConvertL() and ConvertObjectL(), which perform 
the specified conversion and then return

the asynchronous interfaces, ConvertAL() and ConvertObjectAL(), which initialise 
the converter object, and allow the client code to call DoConvertL() a number 
of times until the conversion is complete or abandoned.

@see CConverterBase2
@publishedAll
@released  */
	{
public:
	/** Bitmask values that describe the capabilities of the converter. */
	enum TCapability
		{
		/** The converter can convert files. */
		EConvertsFiles=0x01,
		/** The converter can convert stream objects. */
		EConvertsObjects=0x02,
		/** The converter can extract embedded objects. */
		EConvertsExtract=0x04
		};
public:
	IMPORT_C virtual void ConvertL(const TFileName& aSourceFile, const TFileName& aTargetFile, MConverterUiObserver* aObserver=NULL); // These default to calling the async versions in a loop
	IMPORT_C virtual void ConvertObjectL(RReadStream& aReadStream, RWriteStream& aWriteStream, MConverterUiObserver* aObserver=NULL);
	IMPORT_C virtual void ConvertAL(const TFileName& aSourceFile, const TFileName& aTargetFile, MConverterUiObserver* aObserver=NULL); // these default to leaving with KErrNotSupported
	IMPORT_C virtual void ConvertObjectAL(RReadStream& aReadStream, RWriteStream& aWriteStream, MConverterUiObserver* aObserver=NULL); // these default to leaving with KErrNotSupported
	IMPORT_C virtual TBool DoConvertL(); // these default to leaving with KErrNotSupported
	/** Gets the converter's UID.
	
	@return Converter's UID */
	virtual TUid Uid() =0;
	IMPORT_C virtual TInt Capabilities(); // defaults to "everything"
	IMPORT_C virtual void CancelConvert(); // for any cleanup
	IMPORT_C virtual CConverterBase* EmbeddedObjectL(TDataType& aType);
	IMPORT_C virtual TBool GetEmbeddedFileName(TFileName& aFileName);
	IMPORT_C virtual void ExtendedInterfaceL(TUid aInterfaceUid, CBase*& aInterface); 
	};


class CConverterLibrary : public CBase
/** A converter DLL's factory for individual CConverterBase-derived objects.

The implementor of a converter DLL should implement this class. 

@publishedAll 
@deprecated */
	{
public:
	/** Creates and returns an instance of the converter with the specified UID.
	
	This class should not allocate any resources that are not returned to the 
	caller.
	
	@param aUid UID of the converter to create
	@return The specified converter. If the converter does not implement a converter 
	associated with the UID, then it should return NULL. */
	virtual CConverterBase* Converter(TUid aUid)=0;	// passes ownership
	};

class CConverterBase2 : public CConverterBase
/** Base Class for Ecom Style Converters
The methods in CConverterBase2 are inherited from CConverterBase

There are two flavours of conversion methods:

the synchronous interfaces, ConvertL() and ConvertObjectL(), which perform 
the specified conversion and then return

the asynchronous interfaces, ConvertAL() and ConvertObjectAL(), which initialise 
the converter object, and allow the client code to call DoConvertL() a number 
of times until the conversion is complete or abandoned.

@publishedAll
@released  */
	{
public:
	static CConverterBase2* CreateConverterL(TUid aImplUid);
	IMPORT_C virtual ~CConverterBase2(); 
	IMPORT_C virtual void ConvertL(const TFileName& aSourceFile, const TFileName& aTargetFile, MConverterUiObserver* aObserver=NULL); // These default to calling the async versions in a loop
	IMPORT_C virtual void ConvertObjectL(RReadStream& aReadStream, RWriteStream& aWriteStream, MConverterUiObserver* aObserver=NULL);
	IMPORT_C virtual void ConvertAL(const TFileName& aSourceFile, const TFileName& aTargetFile, MConverterUiObserver* aObserver=NULL); // these default to leaving with KErrNotSupported
	IMPORT_C virtual void ConvertObjectAL(RReadStream& aReadStream, RWriteStream& aWriteStream, MConverterUiObserver* aObserver=NULL); // these default to leaving with KErrNotSupported
	IMPORT_C virtual TBool DoConvertL(); // these default to leaving with KErrNotSupported
	virtual  TUid Uid()=0;
	IMPORT_C virtual TInt Capabilities(); // defaults to "everything"
	IMPORT_C virtual void CancelConvert(); // for any cleanup
	IMPORT_C virtual CConverterBase* EmbeddedObjectL(TDataType& aType);
	IMPORT_C virtual TBool GetEmbeddedFileName(TFileName& aFileName);
	IMPORT_C virtual void ExtendedInterfaceL(TUid aInterfaceUid, CBase*& aInterface);
	IMPORT_C virtual void Reserved_1();
	IMPORT_C virtual void Reserved_2();
private:
	TUid iDestructionKey;
	TInt iSpare;
	};
#endif
