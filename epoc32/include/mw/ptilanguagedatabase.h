/*
* Copyright (c) 2005-2007 Nokia Corporation and/or its subsidiary(-ies). 
* All rights reserved.
* This component and the accompanying materials are made available
* under the terms of "Eclipse Public License v1.0""
* which accompanies this distribution, and is available
* at the URL "http://www.eclipse.org/legal/epl-v10.html".
*
* Initial Contributors:
* Nokia Corporation - initial contribution.
*
* Contributors:
*
* Description:               Language database class declaration.
*
*/














#ifndef _PTI_LANGUAGE_DATABASE_H
#define _PTI_LANGUAGE_DATABASE_H

// INCLUDES
#include <badesca.h> 
#include "PtiDefs.h"

// For accessing keyboard data through LangData() method. If aIndex
// parameter is higher than KKdbThreshold client is accessing 
// keyboard data instead of ldb data.
const TInt KKdbThreshold = 500;

// For accessing key bindings through LangData() method. If aIndex
// parameter is higher than KKdbThreshold client is accessing 
// key bindings data instead of ldb or kdb data.
const TInt KKdbBindingThreshold = 2500;

const TInt KOpaqueDataLen = 8;


//
// TPtiLangDatabaseMapping
//
class TPtiLangDatabaseMapping
	{
	public:
		TInt iUid;
		TInt iLangCode;
	};	

//
// TPtiLangDatabaseMappingOpaque
//
class TPtiLangDatabaseMappingOpaque
	{
	public:
		TInt iUid;
		TInt iLangCode;
		TBuf8<KOpaqueDataLen> iOpaque;
	};
	
	
//
// TPtiLangDatabaseOpaqueBinding
//		
class TPtiLangDatabaseOpaqueBinding
    {
    public:
        TInt iUid;
       	TBuf8<KOpaqueDataLen> iOpaque;    
    };	
	
	
/**
* An interface class for wrapping language data. Core object may use this
* interface for accessing language data (but it is also ok to use any other
* way, since it is part of core object's internal implementation).
*/	
class MPtiLanguageDatabase
	{
	public:
		/**
		* Implementation UID for core object owning this data.
		*
		* @since S60 V3.0
		* @return Implementation Uid value of owning core object.
		*/	
		virtual TInt CoreUID() const = 0;
		
		/**
		* Number on languages implemented in this database.
		* 
		* @since S60 V3.0
		* return Number languages implemented in this database.
		*/
		virtual TInt NumLanguages() const = 0;
		
		/**
		* Symbian OS language code for language data.
		*
		* @since S60 V3.0
		* @param aIndex Index of language implementation (in case one database holds data
		*                for several languages).
		* @return Symbian OS language code for language data identified by aIndex. 
		*         0, if aIndex is greater than number of languages in this database.
		*/ 
		virtual TInt LanguageCode(TInt aIndex) const = 0;
		
		/**
		* Returns sub-language code. The meaning of this value depends on core object
		* implementation. Ususally this value is needed for enumerating several dialects
		* that are related to one Symbian OS language constant.
		*
		* @since S60 V3.0
		* @return Sub-language id. 
		*/ 
		virtual TInt SubLanguageCode(TInt aIndex) const = 0;
		
		/**
		* Returns pointer to raw language data. 
		* on the core object implementation.
		*
		* @since S60 V3.0
		* @param aIndex Index of language implementation.
		* @return Pointer to language data array.
		*/
		virtual TInt8* LangData(TInt aIndex) const = 0;
		
		/**
		* Returns pointer to language data. The meaning of the data in array depends
		* on the core object implementation.
		*
		* @since S60 V3.0
		* @param aIndex Index of language implementation.		
		* @param aNativeParams Core object related extra parameters.
		* @return Pointer to language data array.
		*/
		virtual TInt8* LangData(TInt aIndex, TAny* aNativeParams) const = 0;
				
		/**
		* Returns pointer to PinYin phrase input related data.
		*		
		* @since S60 V3.0
		* @return Pointer to PinYin phrase input data.
		*/
		virtual TInt8* PinyinPhraseData() const = 0;
		
		/**
		* Returns pointer to ZhuYin phrase input related data.
		*		
		* @since S60 V3.0
		* @return Pointer to ZhuYin phrase input data.
		*/
		virtual TInt8* ZhuyinPhraseData() const = 0;
		
		/**
		* Returns core object's internal language id value. The meaning of this
		* value depends on core object implementation.
		*
		* @since S60 V3.0
		* @return Core object internal language id.
		*/		
		virtual TInt NativeId(TInt aIndex) const = 0;
	};


/**
* Default implementation for MPtiLanguageDatabase interface.
*/
class CPtiLanguageDatabase : public CBase, public MPtiLanguageDatabase
	{
	public: 
		/**
		* Creates a language database instance for given implemenation UID.
		* 
		* @since S60 V3.0
		* @return Pointer to language database instance.
		*         NULL if not found. 
		*/
		IMPORT_C static CPtiLanguageDatabase* CreateDatabaseL(TUid aImplUid);
		
		/**
		* Returns a list of all the availbale language databases related to given core object.
		* List will be the topmost item in cleanup stack.
		*
		* @since S60 V3.0
		* @param aCoreUid Implementation uid for core object.
		* @return Pointer to a list containing implemention uids of language databases.
		*/
		IMPORT_C static CArrayFix<TInt>* ListDatabasesLC(TInt aCoreUid);
		
		/**
		* Returns Symbian OS language code for the first language in given language database.
		*
		* @since S60 V3.0
		* @param aUid An implementation uid for language database.
		* @return Symbian OS language constant.
		*         0, if not found.
		*/		
		IMPORT_C static TInt LanguageCodeForUid(TInt aUid);
		
		/**
		* Fills given array with TPtiLangDatabaseMapping bindings for given core object. 
		* Items in list bind Symbian OS language code to language database implemantion
		* uid.
		*
		* @since S60 V3.0
		* @param aCoreUid Core object implemenation uid.
		* @param aResult Resulting list.
		* @return Number of items in aResult.
		*/
		IMPORT_C static TInt CreateMappingTableL(TInt aCoreUid, RArray<TPtiLangDatabaseMapping>& aResult);
		IMPORT_C static TInt CreateMappingTableWithOpaqueL(TInt aCoreUid, RArray<TPtiLangDatabaseMappingOpaque>& aResult);

	public: 
		IMPORT_C ~CPtiLanguageDatabase();
			
	public: // Empty default implementations.
		IMPORT_C TInt CoreUID() const;
		IMPORT_C TInt NumLanguages() const;
		IMPORT_C TInt LanguageCode(TInt aIndex) const;
		IMPORT_C TInt SubLanguageCode(TInt aIndex) const;
		IMPORT_C TInt8* LangData(TInt aIndex) const;
		IMPORT_C TInt8* LangData(TInt aIndex, TAny* aNativeParams) const;
		IMPORT_C TInt8* PinyinPhraseData() const;
		IMPORT_C TInt8* ZhuyinPhraseData() const;
		IMPORT_C TInt NativeId(TInt aIndex) const;

	public:
		inline void SetDestructorKeyId(TInt aDtorKeyId);

	private:
		TInt iDtorKeyId;
		TInt Reserved_1;
	};


// ---------------------------------------------------------------------------
// CPtiLanguageDatabase::SetDestructorKeyId
// 
// ---------------------------------------------------------------------------
// 	
inline void CPtiLanguageDatabase::SetDestructorKeyId(TInt aDtorKeyId)
	{
	iDtorKeyId = aDtorKeyId;
	}

#endif // _PTI_LANGUAGE_DATABASE_H

// End of file


