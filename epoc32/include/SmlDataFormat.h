/*
* Copyright (c) 2002-2004 Nokia Corporation and/or its subsidiary(-ies). 
* All rights reserved.
* This component and the accompanying materials are made available
* under the terms of "Eclipse Public License v1.0"
* which accompanies this distribution, and is available
* at the URL "http://www.eclipse.org/legal/epl-v10.html".
*
* Initial Contributors:
* Nokia Corporation - initial contribution.
*
* Contributors:
*
* Description: For adding content to be synchronized.
*
*/


#ifndef __SMLDATAFORMAT_H__
#define __SMLDATAFORMAT_H__
//
#include <e32base.h>
#include <s32strm.h>
#include <barsread.h>
#include <stringpool.h>
#include <SyncMLDef.h>
//

/**
@publishedPartner

Data Store Format.
Used by Data Provider implementations to specify the format and capabilities of their Data Stores.
See also SmlDataFormat.rh and SmlDataFormat.hrh for resource definitions.

Used by the Sync Engine to generate SyncML DevInf.
*/



/**
A bitmask of sync types. Used to specify sync types supported by a Data Store.
*/
class TSmlSyncTypeMask
	{
public:
	inline TSmlSyncTypeMask()                           : iMask(0U) {}
	inline void SetSupported(TSmlSyncType aType)        { iMask |= TypeMask(aType); }
	inline void SetNotSupported(TSmlSyncType aType)     { iMask &= ~TypeMask(aType); }
	inline TBool IsSupported(TSmlSyncType aType) const  { return iMask & TypeMask(aType); }
private:
	inline TUint16 TypeMask(TSmlSyncType aType) const   { return TUint16(1 << TInt(aType)); }
private:
	TUint16 iMask;
	};


/**
Holds data defining a property value or property parameter value.
This includes Name, display name, and data type - including any enumerations.
*/
class CSmlDataField : public CBase
	{
public:
	IMPORT_C static CSmlDataField* NewLC();
	IMPORT_C static CSmlDataField* NewLC(const RStringPool& aStringPool, TResourceReader& aReader);
	IMPORT_C static CSmlDataField* NewLC(const RStringPool& aStringPool, RReadStream& aStream);
	IMPORT_C virtual ~CSmlDataField();
	IMPORT_C void ExternalizeL(RWriteStream& aStream) const;

	IMPORT_C RString Name() const;
	// Method takes ownership of parameter and closes it 
	IMPORT_C void SetNameL(RString& aName);
	IMPORT_C const TDesC& DisplayName() const;
	// Method takes ownership of parameter and closes it 
	IMPORT_C void SetDisplayNameL(TDesC& aDisplayName);
	IMPORT_C RString DataType() const;
	// Method takes ownership of parameter and closes it 
	IMPORT_C void SetDataTypeL(RString& aDataType);
	IMPORT_C TInt EnumValueCount() const;
	IMPORT_C RString EnumValue(TInt aIndex) const;
	// Method takes ownership of parameter and closes it 
	IMPORT_C void SetEnumValuesL(RArray<RString>& aEnumValues);
	
protected:
	HBufC* iDisplayName;
	RString iName;
	RString iDataType;
	RArray<RString> iEnumValues;
	};


/**
Property Parameter.
Sub-type of property.
*/
class CSmlDataPropertyParam : public CBase
	{
public:
	IMPORT_C static CSmlDataPropertyParam* NewLC();
	IMPORT_C static CSmlDataPropertyParam* NewLC(const RStringPool& aStringPool, TResourceReader& aReader);
	IMPORT_C static CSmlDataPropertyParam* NewLC(const RStringPool& aStringPool, RReadStream& aStream);
	IMPORT_C virtual ~CSmlDataPropertyParam();
	IMPORT_C void ExternalizeL(RWriteStream& aStream) const;

	IMPORT_C const CSmlDataField& Field() const;
	// Method takes ownership of data field
	IMPORT_C void SetDataFieldL(CSmlDataField& aDataField);

protected:
	CSmlDataField* iField;
	};


/**
Property.
A field in the Data Store.
*/
class CSmlDataProperty : public CBase
	{
public:
	enum TOption
		{
		EOptionHasMaxSize,
		EOptionHasMaxOccur,
		EOptionNoTruncate
		};
public:
	IMPORT_C static CSmlDataProperty* NewLC();
	IMPORT_C static CSmlDataProperty* NewLC(const RStringPool& aStringPool, TResourceReader& aReader);
	IMPORT_C static CSmlDataProperty* NewLC(const RStringPool& aStringPool, RReadStream& aStream);
	IMPORT_C virtual ~CSmlDataProperty();
	IMPORT_C void ExternalizeL(RWriteStream& aStream) const;

	IMPORT_C const CSmlDataField& Field() const;
	// Method takes ownership of data field
	IMPORT_C void SetDataFieldL(CSmlDataField& aDataField);

	IMPORT_C TInt ParamCount() const;
	IMPORT_C const CSmlDataPropertyParam& Param(TInt aIndex) const;
	// Method takes ownership of params
	IMPORT_C void SetPropertyParamsL(RPointerArray<CSmlDataPropertyParam>& aParams);

	IMPORT_C TBool IsSupported(TOption aOption) const;
	IMPORT_C void SetSupportedOptions(TUint32 aFlags);

	IMPORT_C TBool HasMaxSize() const;
	IMPORT_C TBool HasMaxOccur() const;
	IMPORT_C TInt MaxSize() const;
	IMPORT_C TInt MaxOccur() const;
	IMPORT_C void SetMaxSize(TUint16 aMaxSize);
	IMPORT_C void SetMaxOccur(TUint16 aMaxOccur);

protected:
	CSmlDataField* iField;
	RPointerArray<CSmlDataPropertyParam> iParams;
	TUint16 iMaxSize;
	TUint16 iMaxOccur;
	TUint32 iFlags;
	};


/**
Filter Capability
*/
class CSmlFilterCapability : public CBase
	{
public:
	IMPORT_C static CSmlFilterCapability* NewLC();
	IMPORT_C static CSmlFilterCapability* NewLC(const RStringPool& aStringPool, TResourceReader& aReader);
	IMPORT_C static CSmlFilterCapability* NewLC(const RStringPool& aStringPool, RReadStream& aStream);
	IMPORT_C virtual ~CSmlFilterCapability();
	IMPORT_C void ExternalizeL(RWriteStream& aStream) const;

	IMPORT_C RStringF MimeType() const;
	// Method takes ownership of parameter and closes it 
	IMPORT_C void SetMimeTypeL(RStringF& aMimeType);
	IMPORT_C RStringF MimeVersion() const;
	// Method takes ownership of parameter and closes it
	IMPORT_C void SetMimeVersionL(RStringF& aMimeVersion);

	IMPORT_C TInt KeywordCount() const;
	IMPORT_C RString Keyword(TInt aIndex) const;
	// Method takes ownership of keywords
	IMPORT_C void SetKeyWordListL(RArray<RString>& aKeywordList);

	IMPORT_C TInt PropertyCount() const;
	IMPORT_C RString PropertyName(TInt aIndex) const;
	// Method takes ownership of properties and closes them
	IMPORT_C void SetPropertiesListL(RArray<RString>& aPropertyList);
	
protected:
	RStringF iMimeType;
	RStringF iMimeVersion;
	RArray<RString> iKeywordList;
	RArray<RString> iPropertyList;
	};



/**
The format of a specific mime type.
*/
class CSmlMimeFormat : public CBase
	{
public:
	IMPORT_C static CSmlMimeFormat* NewLC();
	IMPORT_C static CSmlMimeFormat* NewLC(const RStringPool& aStringPool, TResourceReader& aReader);
	IMPORT_C static CSmlMimeFormat* NewLC(const RStringPool& aStringPool, RReadStream& aStream);
	IMPORT_C virtual ~CSmlMimeFormat();
	IMPORT_C void ExternalizeL(RWriteStream& aStream) const;

	IMPORT_C RStringF MimeType() const;
	// Method takes ownership of parameter and closes it
	IMPORT_C void SetMimeTypeL(RStringF& aMimeType);
	IMPORT_C RStringF MimeVersion() const;
	// Method takes ownership of parameter and closes it
	IMPORT_C void SetMimeVersionL(RStringF& aMimeVersion);

	IMPORT_C TInt PropertyCount() const;
	IMPORT_C const CSmlDataProperty& Property(TInt aIndex) const;
	// Method takes ownership of properties
	IMPORT_C void SetDataPropertiesL(RPointerArray<CSmlDataProperty>& aProperties);

	IMPORT_C TBool FieldLevel() const;
	IMPORT_C void SetFieldLevel(TBool aFieldLevel);

protected:
	RStringF iMimeType;
	RStringF iMimeVersion;
	RPointerArray<CSmlDataProperty> iProperties;
	TBool iFieldLevel;
	};



/**
The format and capabilities of Data Stores of a specific type.
*/
class CSmlDataStoreFormat : public CBase
	{
public:
	enum TOption
		{
		EOptionHasMaxSize,
		EOptionHasMaxItems,
		EOptionHierarchial
		};
public:
	IMPORT_C static CSmlDataStoreFormat* NewLC();
	IMPORT_C static CSmlDataStoreFormat* NewLC(const RStringPool& aStringPool, TResourceReader& aReader);
	IMPORT_C static CSmlDataStoreFormat* NewLC(const RStringPool& aStringPool, RReadStream& aStream);
	IMPORT_C virtual ~CSmlDataStoreFormat();
	IMPORT_C void ExternalizeL(RWriteStream& aStream) const;

	IMPORT_C const TDesC& DisplayName() const;
	IMPORT_C void SetDisplayNameL(TDesC& aDisplayName);

	IMPORT_C TSmlSyncTypeMask SyncTypes() const;
	IMPORT_C void SetSyncTypeMask(TSmlSyncTypeMask aSyncTypeMask);

	IMPORT_C TInt MimeFormatCount() const;
	IMPORT_C const CSmlMimeFormat& MimeFormat(TInt aIndex) const;
	// Method takes ownership of mime formats
	IMPORT_C void SetMimeFormatsL(RPointerArray<CSmlMimeFormat>& aMimeFormats);
	IMPORT_C TInt MimeFormatRxPref() const;
	IMPORT_C void SetMimeFormatRxPref(TInt aRxPref);
	IMPORT_C TInt MimeFormatTxPref() const;
	IMPORT_C void SetMimeFormatTxPref(TInt aTxPref);

	IMPORT_C TBool IsSupported(TOption aOption) const;
	IMPORT_C void SetSupportedOptions(TUint32 aFlags);

	IMPORT_C TInt FolderPropertyCount() const;
	IMPORT_C const CSmlDataProperty& FolderProperty(TInt aIndex) const;
	// Method takes ownership of folder properties
	IMPORT_C void SetFolderPropertiesL(RPointerArray<CSmlDataProperty>& aFolderProperties);

	IMPORT_C TInt FilterCapabilityCount() const;
	IMPORT_C const CSmlFilterCapability& FilterCapability(TInt aIndex) const;
	// Method takes ownership of filter capabilities
	IMPORT_C void SetFilterCapabilitiesL(RPointerArray<CSmlFilterCapability>& aFilterCapabilities);

	IMPORT_C TBool HasMaxSize() const;
	IMPORT_C TBool HasMaxItems() const;
	IMPORT_C TInt MaxSize() const;
	IMPORT_C TInt MaxItems() const;
	IMPORT_C void SetMaxSize(TUint16 aMaxSize);
	IMPORT_C void SetMaxItems(TUint16 aMaxItems);

protected:
	HBufC* iDisplayName;
	TSmlSyncTypeMask iSyncTypeMask;
	RPointerArray<CSmlDataProperty> iFolderProperties;
	RPointerArray<CSmlFilterCapability> iFilterCapabilities;
	TUint16 iMaxSize;
	TUint16 iMaxItems;
	TUint32 iFlags;
  RPointerArray<CSmlMimeFormat> iMimeFormats;
  TInt iRxPref;
  TInt iTxPref;
	};


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
#endif
