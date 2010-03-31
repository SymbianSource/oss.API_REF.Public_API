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

#if !defined(__CONLIST_H__)
#define __CONLIST_H__

#if !defined(__E32BASE_H__)
#include <e32base.h>
#endif

#if !defined(__F32FILE_H__)
#include <f32file.h>
#endif

#if !defined(__CONARC_H__)
#include <conarc.h>
#endif

#if !defined(__CONCNF_H__)
#include <concnf.h>
#endif

#if !defined(__IMPLEMENTATION_INFORMATION_H__)
#include <ecom/implementationinformation.h>
#endif
#if !defined(__ECOM_H__)
#include <ecom/ecom.h>
#endif


/** Creates a converter dll's factory interface object.

@publishedAll
@deprecated
*/
typedef CConverterLibrary* (*CreateCConverterLibrary)(); 

struct SConverterInfo
/** Describes a converter, as obtained from a converter list (CCnaConverterList).

@publishedAll
@released
@see CCnaConverterList */
	{
	/** Localised name of the data type. */
	TTranslation iTranslation;
	/** Converter UID. */
	TUid iUid;
	/** Position of the converter in the list. */
	TInt iIndex;
	};

class CCnaConverterList : public CBase
/** Provides a list of available converters, allowing clients to search for and 
obtain converters for specific source and target data types. 

@publishedAll
@released */
	{
public:
	IMPORT_C static CCnaConverterList* NewL();
	IMPORT_C static CCnaConverterList* NewLC();
	IMPORT_C void Release();
	IMPORT_C ~CCnaConverterList();
//
	IMPORT_C TInt CountL();
	inline TInt Count();
	IMPORT_C CConverterBase* NewConverterL(TUid aUid);
	IMPORT_C void UpdateL();
	IMPORT_C TUid ConvFromL(const TDataType& aMimeType); // searches for a particular converter
	IMPORT_C TUid ConvToL(const TDataType& aMimeType);
	IMPORT_C TUid ConverterL(const TDataType& aFrom,const TDataType& aTo);
	IMPORT_C void ConvFromListL(const TDataType& aMimeType,CArrayFix<SConverterInfo>* aSConverterInfoArray);
	IMPORT_C void ConvToListL(const TDataType& aMimeType,CArrayFix<SConverterInfo>* aSConverterInfoArray);
	IMPORT_C TInt MimeTypeFrom(TDataType& aDataType,const SConverterInfo& aConverterInfo) const;
	IMPORT_C TInt MimeTypeTo(TDataType& aDataType,const SConverterInfo& aConverterInfo) const;
private:
	CCnaConverterList();
	void ConstructL();
	CConverterBase* LoadConverterL(TUid aImplUid);
private:
	TBool iDoneScan;
	CArrayPtr<CCnaConverter>* iConverters;
	RImplInfoPtrArray iImplementationArray;
	};

class ConverterListUtil
/** @internalComponent */
	{
public:
	static CConverterBase* UtilityConverterL(TUid aUid);
	static TInt CountUtilityConverters();
	};

inline TInt CCnaConverterList::Count()
/** @deprecated

Deprecated - Use CCnaConverterList::CountL instead. 
Rescan of the disk to refresh the list of converters could leave. */
	{
	return CountL();
	}

#endif
