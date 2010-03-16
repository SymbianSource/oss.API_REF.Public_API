/*
* Copyright (c) 2003-2006 Nokia Corporation and/or its subsidiary(-ies). 
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
* Description:               PtiLanguage class definitions.
*
*/














#ifndef _PTI_LANGUAGE_H
#define _PTI_LANGUAGE_H	

// INCLUDES
#include <e32base.h>
#include <f32file.h>
#include <barsc.h>
#include <barsread.h>
#include "PtiDefs.h"

const TInt KMaxMultitapResourceFileName = 20;
const TInt KMaxQwertyResourceFileName = 32;

// FORWARD DECLARATIONS
class MPtiKeyMappings;
class MPtiCore;
class CPtiCore;
class CPtiKeyMapData;
class CPtiKeyMapDataFactory;

/**
* An item in list used for binding a core object to input mode.
*/
class TPtiCoreBinding
	{
	public:
		TInt iInputMode;
		MPtiCore* iCore;
	};


/*
* Helper class for storing keymapping pointers.
*/
class TPtiKeyMappingsHolder
    {
    public:
        TPtiKeyMappingsHolder();
        ~TPtiKeyMappingsHolder();
        
        void Clear();
    
        MPtiKeyMappings* iKeyMappings;
	    MPtiKeyMappings* iQwertyKeyMappings;
        MPtiKeyMappings* iHalfQwertyMappings;   
    };


/**
* Client side interface for querying PtiEngine language related attributes. 
* All PtiEngine client side API methods related to handling languages access
* languages through this interface class. 
*/
class MPtiLanguage
	{
	public:
		/**
		* Returns a boolean value indicating whether this language supports
		* requested input mode. 
		*
		* @param aMode A input mode to be queried.
		* @return ETrue if this language supports requested input mode.
		*         EFalse otherwise.
		*/
		virtual TBool HasInputMode(TPtiEngineInputMode aMode) const = 0;
		
		/**
		* Returns list of all inputmodes currently supported by this language.
		*
		* @param aResult List of supported input modes will be stored here.
		*/		
		virtual void GetAvailableInputModesL(CArrayFix<TInt>* aResult) = 0;
		
		/**
		* Returns Symbian OS language code for this language.
		*
		* @return Symbian OS language code.
		*/		
		virtual TInt  LanguageCode() const = 0;
		
		/**
		* Returns localized name for this language.
		*
		* @return A constant pointer to localized language name.
		*/		
		virtual TPtrC LocalizedName() const = 0;
	};



/**
* Implementation class for a PtiEngine language. This class is used
* mainly in PtiEngine and core objects code and it implements clients side 
* language interface class.
* PtiEngine maintains language list containing instances of this class. 
* CPtiCoreLanguage class also maintains list of <core <-> input mode> bindings. 
*/ 
NONSHARABLE_CLASS(CPtiCoreLanguage) : public CBase, public MPtiLanguage
	{
	public:
		IMPORT_C static CPtiCoreLanguage* NewL();
		IMPORT_C ~CPtiCoreLanguage();
		
		/**
		* Sets multitapping keymappings.
		*
		* @param aMappings Pointer to keymappings object to be set.
		*/	
		IMPORT_C void SetKeyMappings(MPtiKeyMappings* aMappings);
		
		/**
		* Sets qwerty keymappings.
		*
		* @param aMappings Pointer to keymappings object to be set.
		*/			
		IMPORT_C void SetQwertyKeyMappings(MPtiKeyMappings* aMappings);
		
		/**
		* Sets Symbian OS language code for this language.
		*
		* @param aCode Language code to be set.
		*/
		IMPORT_C void SetLanguageCode(TInt aCode);
		
		/**
		* Returns pointer to multitapping keymappings object. 
		*
		* @return Pointer to current multitapping keymappings.
		*         NULL if no multitapping keymappings available.		
		*/
		IMPORT_C MPtiKeyMappings* GetKeymappings() const;
		
		/**
		* Returns pointer to qwerty keymappings object. 
		*
		* @return Pointer to current qwerty keymappings.
		*         NULL if no qwerty keymappings available.
		*/
		IMPORT_C MPtiKeyMappings* GetQwertyKeymappings() const;
		
		/**
		* Resets current multitapping keymappings.		
		*/
		IMPORT_C void ClearMultitapping();
		
		/**
		* Resets current qwerty keymappings.		
		*/		
		IMPORT_C void ClearQwerty();
		
		/**
		* Sets localized language name.
		*
		* @param aName Language name to be set.
		*/
		IMPORT_C void SetLocalizedName(const TDesC& aName);
		
		/**
		* Returns descriptor pointing to localized language name.
		*
		* @return Localoized language name descriptor.
		*/
		IMPORT_C TDes& LocalizedNameDes();
		
		/**
		* Returns core object for given input mode.
		*
		* @aMode  Input mode to be queried. 
		* @return Pointer to core object.
		*         NULL if no core object is asigned to given input mode.
		*/		
		IMPORT_C MPtiCore* GetCore(TPtiEngineInputMode aMode);
		
		/**
		* Sets core object for given input mode. If input mode already
		* has a core object asigned to it, it will be replaced.
		* 
		* @param aCore Pointer to core object 
		* @param aMode Input mode for core object.
		*/
		IMPORT_C void SetCore(MPtiCore *aCore, TPtiEngineInputMode aMode);

		/**
		* Returns an array of available input modes for this language object. 
		*
		* @param  aResult   Resulting input mode list. 
		*/
		IMPORT_C void GetAvailableInputModesL(CArrayFix<TInt>* aResult);

		/**
		* Returns an array of available input modes for this language object. 
		*
		* @param  aResult   Resulting input mode list. 
		* @since  3.0
		*/
		IMPORT_C void GetAvailableInputModesL(RArray<TInt>& aResult);

		/**
		* Returns a boolean value indicating whether this language
		* supports given input mode.
		*
		* @param   aMode  Input mode to be queried.
		* @return  ETrue  if input mode is supported.
		*          EFalse otherwise.
		*/
		IMPORT_C TBool HasInputMode(TPtiEngineInputMode aMode) const;
				
		/**
		* Returns Symbian OS language code for this language object.
		*
		* @return Language code			
		*/		
		inline TInt  LanguageCode() const;
		
		/**
		* Returns constant descriptor pointing to localized name for
		* this language.
		*
		* @return Localized language name.
		*/ 
		inline TPtrC LocalizedName() const;
		
		/**
		* Returns a boolean value indicating whether given core object is
		* already asigned to some input mode for this language.
		* 
		* @param  aCore A core object to be queried.
		* @return ETrue if given core object is asigned to any input mode.
		*         EFalse otherwise.
		*/
		IMPORT_C TBool HasCore(MPtiCore* aCore) const;
		
		/**
		* Removes detachs given core object from all input modes it is attached to.
		*
		* @param aCore A core object to be detached.
		*/
		IMPORT_C void RemoveCore(MPtiCore* aCore);
		
        /**
		* Returns pointer to half qwerty keymappings object. 
		*
		* @return Pointer to half qwerty keymappings.
		*         NULL if no half qwerty keymappings available.
		*/
		IMPORT_C MPtiKeyMappings* GetHalfQwertyKeymappings() const;				
		
		/**
		* Sets half qwerty keymappings.
		*
		* @param aMappings Pointer to keymappings object to be set.
		*/			
		IMPORT_C void SetHalfQwertyKeyMappings(MPtiKeyMappings* aMappings);		
		
	    /**
		* Resets current half qwerty keymappings.		
		*/		
		IMPORT_C void ClearHalfQwerty();
		
		/**
		* Sets keymap data factory class.
		* 
		* @since S60 5.0 
		* @param aFactory A keymap data factory to be used.
		*/
        void SetKeyMapDataFactory(CPtiKeyMapDataFactory* aFactory);
        
        /**
        * Returns active data factory. 
        * 
        * @since S60 5.0
        * @return A pointer to active data factory.
        */
        IMPORT_C CPtiKeyMapDataFactory* DataFactory() const;				
        
        /**
        * Returns raw keymap data object.
        * 
        * @since S60 5.0
        * @return A pointer to raw keymap data object.
        */
        IMPORT_C CPtiKeyMapData* RawKeyMapData() const;		
        
	private:
		CPtiCoreLanguage();
		void ConstructL();
		void Clear();
		void LoadKeymappingsL() const;
		CPtiCore* GetCoreForNumericMode() const;
		void SetCoreLocal(MPtiCore *aCore, TPtiEngineInputMode aMode) const;
										
	private:
		TInt iLanguageCode;
		TPtiKeyMappingsHolder* iHolder;
		CPtiKeyMapDataFactory* iDataFactory;    // Not owned
		TBuf<KMaxLanguageNameLength> iLocalizedName;
		mutable RArray<TPtiCoreBinding> iCores;		
		mutable CPtiKeyMapData* iKeyMapData;    // Owns
	};

#include <PtiLanguage.inl>

#endif // _PTI_LANGUAGE_H

// End of file

