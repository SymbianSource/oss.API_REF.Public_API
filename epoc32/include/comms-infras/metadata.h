/**
* Copyright (c) 2004-2009 Nokia Corporation and/or its subsidiary(-ies).
* All rights reserved.
* This component and the accompanying materials are made available
* under the terms of the License "Symbian Foundation License v1.0" to Symbian Foundation members and "Symbian Foundation End User License Agreement v1.0" to non-members
* which accompanies this distribution, and is available
* at the URL "http://www.symbianfoundation.org/legal/licencesv10.html".
*
* Initial Contributors:
* Nokia Corporation - initial contribution.
*
* Contributors:
*
* Description:
*
*/





/**
 @file MetaData.h
 @internalTechnology
*/

#if (!defined METADATA_H)
#define METADATA_H

#include <e32base.h>
#include <e32std.h>
#include "comms-infras/cftransportmacro.h"

/**
Macro used to declare virtual functions from MMetaData interface and the virtual data table
*/
#define TYPEID_TABLE \
 static inline const Meta::STypeId TypeId() { const Meta::SVDataTableEntry* entry = GetVDataTableStatic(); return Meta::STypeId(entry->iOffset,reinterpret_cast<TInt32>(entry->iMetaNewL)); } \
 static const Meta::SVDataTableEntry* GetVDataTableStatic(); \
 static const Meta::SVDataTableEntry iVDataTable[];

#define EXPORT_TYPEID_TABLE \
 static inline const Meta::STypeId TypeId() { const Meta::SVDataTableEntry* entry = GetVDataTableStatic(); return Meta::STypeId(entry->iOffset,reinterpret_cast<TInt32>(entry->iMetaNewL)); } \
 IMPORT_C static const Meta::SVDataTableEntry* GetVDataTableStatic(); \
 static const Meta::SVDataTableEntry iVDataTable[];

#define DATA_VTABLE \
 static inline const Meta::STypeId TypeId() { const Meta::SVDataTableEntry* entry = GetVDataTableStatic(); return Meta::STypeId(entry->iOffset,reinterpret_cast<TInt32>(entry->iMetaNewL)); } \
 virtual Meta::SVDataTableEntry const* GetVDataTable() const;	\
 virtual TUint8* GetAttribPtr(const TInt aOffset) const;	\
 static const Meta::SVDataTableEntry* GetVDataTableStatic(); \
 static const Meta::SVDataTableEntry iVDataTable[];

#define EXPORT_DATA_VTABLE \
 static inline const Meta::STypeId TypeId() { const Meta::SVDataTableEntry* entry = GetVDataTableStatic(); return Meta::STypeId(entry->iOffset,reinterpret_cast<TInt32>(entry->iMetaNewL)); } \
 virtual Meta::SVDataTableEntry const* GetVDataTable() const;	\
 virtual TUint8* GetAttribPtr(const TInt aOffset) const;	\
 IMPORT_C static const Meta::SVDataTableEntry* GetVDataTableStatic(); \
 static const Meta::SVDataTableEntry iVDataTable[];

#define EXPORT_DATA_VTABLE_AND_FN \
 static inline const Meta::STypeId TypeId() { const Meta::SVDataTableEntry* entry = GetVDataTableStatic(); return Meta::STypeId(entry->iOffset,reinterpret_cast<TInt32>(entry->iMetaNewL)); } \
 IMPORT_C virtual Meta::SVDataTableEntry const* GetVDataTable() const;	\
 IMPORT_C virtual TUint8* GetAttribPtr(const TInt aOffset) const;	\
 IMPORT_C static const Meta::SVDataTableEntry* GetVDataTableStatic(); \
 static const Meta::SVDataTableEntry iVDataTable[];

/**
Macros used to implement virtual functions from MMetaData interface and construct the v data table
*/
#define START_ATTRIBUTE_TABLE( thisMetaClass, uid, typeId ) \
 Meta::SVDataTableEntry const* thisMetaClass::GetVDataTable() const { return &iVDataTable[0]; };	\
 TUint8* thisMetaClass::GetAttribPtr(const TInt aOffset) const { return (TUint8*)this + aOffset; };	\
 const Meta::SVDataTableEntry* thisMetaClass::GetVDataTableStatic() { return &iVDataTable[0]; }; \
 const Meta::SVDataTableEntry thisMetaClass::iVDataTable[] = { \
 { uid, reinterpret_cast<Meta::TMetaTypeNewL>(typeId) },

#define EXPORT_START_ATTRIBUTE_TABLE( thisMetaClass, uid, typeId ) \
 Meta::SVDataTableEntry const* thisMetaClass::GetVDataTable() const { return &iVDataTable[0]; };	\
 TUint8* thisMetaClass::GetAttribPtr(const TInt aOffset) const { return (TUint8*)this + aOffset; };	\
 EXPORT_C const Meta::SVDataTableEntry* thisMetaClass::GetVDataTableStatic() { return &iVDataTable[0]; }; \
 const Meta::SVDataTableEntry thisMetaClass::iVDataTable[] = { \
 { uid, reinterpret_cast<Meta::TMetaTypeNewL>(typeId) },

#define EXPORT_START_ATTRIBUTE_TABLE_AND_FN( thisMetaClass, uid, typeId ) \
 EXPORT_C Meta::SVDataTableEntry const* thisMetaClass::GetVDataTable() const { return &iVDataTable[0]; };	\
 EXPORT_C TUint8* thisMetaClass::GetAttribPtr(const TInt aOffset) const { return (TUint8*)this + aOffset; };	\
 EXPORT_C const Meta::SVDataTableEntry* thisMetaClass::GetVDataTableStatic() { return &iVDataTable[0]; }; \
 const Meta::SVDataTableEntry thisMetaClass::iVDataTable[] = { \
 { uid, reinterpret_cast<Meta::TMetaTypeNewL>(typeId) },

#define REGISTER_ATTRIBUTE( thisMetaClass, var, metaType ) \
 { _FOFF( thisMetaClass, var ), Meta::metaType::NewL },

#define END_ATTRIBUTE_TABLE() \
 { 0, NULL }};

#define END_ATTRIBUTE_TABLE_BASE( baseMetaClass, baseId ) \
 { (TInt)((TAny*)(baseMetaClass::GetVDataTableStatic)), NULL }};

#define REGISTER_TYPEID( thisMetaClass, uid, typeId ) \
 const Meta::SVDataTableEntry* thisMetaClass::GetVDataTableStatic() { return &iVDataTable[0]; }; \
 const Meta::SVDataTableEntry thisMetaClass::iVDataTable[] = { \
 { uid, reinterpret_cast<Meta::TMetaTypeNewL>(typeId) }, \
 { 0, NULL }};

#define EXPORT_REGISTER_TYPEID( thisMetaClass, uid, typeId ) \
 EXPORT_C const Meta::SVDataTableEntry* thisMetaClass::GetVDataTableStatic() { return &iVDataTable[0]; }; \
 const Meta::SVDataTableEntry thisMetaClass::iVDataTable[] = { \
 { uid, reinterpret_cast<Meta::TMetaTypeNewL>(typeId) }, \
 { 0, NULL }};

#define EXPORT_START_ATTRIBUTE_TABLE_NO_FN( thisMetaClass, uid, typeId ) \
 EXPORT_C const Meta::SVDataTableEntry* thisMetaClass::GetVDataTableStatic() { return &iVDataTable[0]; }; \
 const Meta::SVDataTableEntry thisMetaClass::iVDataTable[] = { \
 { uid, reinterpret_cast<Meta::TMetaTypeNewL>(typeId) },


namespace Meta
{

class MMetaType;
typedef MMetaType* (*TMetaTypeNewL)(const TAny*, const TAny*);

struct SVDataTableEntry
/**

Single entry of a virtual data table

@internalComponent
@released since v9.0 */
    {
    TInt iOffset;
    TMetaTypeNewL iMetaNewL;
    };

const TInt32 KNetMetaTypeAny = 0;

struct STypeId
/**

Used to uniquely identify the type of a (meta).object.

@internalComponent
@released since v9.0 */
	{
	TUid iUid;
	TInt32 iType;
	inline TBool operator==(const STypeId& obj) const { return iUid==obj.iUid && iType==obj.iType; };
	inline STypeId();
	inline STypeId(TUint32 aUid, TUint32 aTypeId);
	IMPORT_C STypeId(TPtrC8& aStore);
	IMPORT_C TInt Check( TPtrC8& aDes ) const;
	};

class MMetaData
/**

MetaData interface

@internalComponent
@released since v9.0 */
	{
public:
	virtual SVDataTableEntry const* GetVDataTable() const = 0;
	virtual TUint8* GetAttribPtr(const TInt aOffset) const = 0;
	};

struct SMetaData : public MMetaData
/**

Meta object's base type

Partially implements the MMetaData interface's pure virtual functions

@internalComponent
@released since v9.0 */
   {
public:
	IMPORT_C virtual ~SMetaData();

	IMPORT_C TInt CheckTypeOf( TPtrC8& aDes ) const;
	IMPORT_C STypeId GetTypeId() const;
	IMPORT_C TInt IsTypeOf( const STypeId& aTypeId ) const;

	IMPORT_C void Copy(const SMetaData& aSource);
	IMPORT_C TInt Store(TDes8& aDes) const;
	IMPORT_C TInt Load(TPtrC8& aDes);

	IMPORT_C TInt Length() const;

protected:
	IMPORT_C explicit SMetaData();
   };

const TInt KUidEComMetaDataFactoryInterface = 0x101F7700;

struct SMetaDataECom : public SMetaData
/**

Meta object based on ECom factory base type

Implements static LoadL(TPtrC8& aDes) required by templated

@internalTechnology
@released since v9.0 */
	{
public:
	IMPORT_C static SMetaDataECom* LoadL(TPtrC8& aDes);
    IMPORT_C static SMetaDataECom* NewInstanceL(const STypeId& aTypeId);
	IMPORT_C virtual ~SMetaDataECom();

protected:
    IMPORT_C explicit SMetaDataECom();

private:
	TUid iDestroyUid;
	};

} //namespace Meta

#include <comms-infras/metadata.inl>

#endif //METADATA_H
