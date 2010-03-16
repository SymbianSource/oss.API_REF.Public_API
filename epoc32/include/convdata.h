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

#if !defined(__CONVDATA_H__)
#define __CONVDATA_H__

/**
@internalComponent
*/
struct SCnvConversionData
	{
/** Specifies the default endian-ness of the current character set. Used by SetDefaultEndiannessOfForeignCharacters(). */
	enum TEndianness // the values of these *must not* change they are used hard-coded in CNVTOOL.PL
		{
		EUnspecified		=0,
		EFixedLittleEndian	=1,
		EFixedBigEndian		=2
		};
	struct SVariableByteData
		{
		struct SRange
			{
			TUint8 iFirstInitialByteValueInRange;
			TUint8 iLastInitialByteValueInRange;
			TUint8 iNumberOfSubsequentBytes;
			TUint8 iSpare;
			};
		TInt iNumberOfRanges;
		const SRange* iRangeArray;
		};
	struct SOneDirectionData
		{
		struct SRange
			{
			enum TAlgorithm
				{
				// each of these, with the exception of EDirect, has a corresponding member of UData
				EDirect,
				EOffset,
				EIndexedTable16,
				EKeyedTable1616,
				EKeyedTable16OfIndexedTables16
				};
			union UData
				{
				struct SIndexedTable16
					{
					struct SEntry
						{
						TUint16 iOutputCharacterCode;
						};
					const SEntry* iEntryArray;
					};
				struct SKeyedTable1616
					{
					struct SEntry
						{
						TUint16 iKey;
						TUint16 iOutputCharacterCode;
						};
					TInt iNumberOfEntries;
					const SEntry* iEntryArray;
					};
				struct SKeyedTable16OfIndexedTables16
					{
					struct SKeyedEntry
						{
						TUint16 iFirstInputCharacterCodeInIndexedTable;
						TUint16 iLastInputCharacterCodeInIndexedTable;
						const TUint16* iIndexedEntryArray;
						};
					TInt iNumberOfKeyedEntries;
					const SKeyedEntry* iKeyedEntryArray;
					};
				TInt iOffset;
				SIndexedTable16 iIndexedTable16;
				SKeyedTable1616 iKeyedTable1616;
				SKeyedTable16OfIndexedTables16 iKeyedTable16OfIndexedTables16;
				};
			TUint iFirstInputCharacterCodeInRange;
			TUint iLastInputCharacterCodeInRange;
			TUint8 iAlgorithm; // one of the TAlgorithm values
			TUint8 iSizeOfOutputCharacterCodeInBytesIfForeign; // only used in SCnvConversionData::iUnicodeToForeignData
			TUint16 iSpare;
#if defined(CONST_STATIC_UNIONS_ARE_POSSIBLE)
			UData iData;
#else
			struct
				{
				TUint iWord1;
				TUint iWord2;
				} iData;
#endif
			};
		TInt iNumberOfRanges;
		const SRange* iRangeArray;
		};
	TEndianness iEndiannessOfForeignCharacters;
	SVariableByteData iForeignVariableByteData;
	SOneDirectionData iForeignToUnicodeData;
	SOneDirectionData iUnicodeToForeignData;
	TAny* iSpareForFutureUse_1;
	TAny* iSpareForFutureUse_2;
	};

/**
@internalComponent
*/
#define UData_SIndexedTable16(a) \
	reinterpret_cast<TUint>(const_cast<SCnvConversionData::SOneDirectionData::SRange::UData::SIndexedTable16::SEntry*>(a)) 
/**
@internalComponent
*/
#define UData_SKeyedTable1616(a) \
	static_cast<TUint>ARRAY_LENGTH(a), \
	reinterpret_cast<TUint>(const_cast<SCnvConversionData::SOneDirectionData::SRange::UData::SKeyedTable1616::SEntry*>(a))
/**
@internalComponent
*/
#define UData_SKeyedTable16OfIndexedTables16(a)	\
	static_cast<TUint>ARRAY_LENGTH(a), \
	reinterpret_cast<TUint>(const_cast<SCnvConversionData::SOneDirectionData::SRange::UData::SKeyedTable16OfIndexedTables16::SKeyedEntry *>(a)) 

#endif
