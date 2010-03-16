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














#ifndef _PTI_KEY_MAPPINGS_H
#define _PTI_KEY_MAPPINGS_H

#include <e32base.h>
#include "PtiDefs.h"


const TInt KPtiKeyDataDeadKeySeparator = 0xffff;
const TInt KPtiPinyinMarker = 0x2460;
const TInt KPtiStrokeMarker = 0x2461;
const TInt KPtiZhuyinMarker = 0x2462;
const TInt KPtiCangjieMarker = 0x2463;
const TInt KPtiGetAllMarker = 0x2464;

// FORWARD DECLARATIONS
class CPtiKeyMapData;

// 
// CPtiQwertyKeymappingsExtension
//

NONSHARABLE_CLASS(CPtiQwertyKeymappingsExtension) : public CBase
	{
	public:
		static CPtiQwertyKeymappingsExtension* NewL();
		~CPtiQwertyKeymappingsExtension();		
	
	private:
		CPtiQwertyKeymappingsExtension();
	
	public:
		TUint16 iLastChar;	       // for Vietnamese 			
		TInt16 iLastTone;          // for Vietnamese
		TUint16 iReplaced;	       // for Vietnamese
		TPtiTextCase iVowelCase;   // for Vietnamese
		TPtiKey iLastToneKey;      // for Vietnamese			
	};


//
// TPtiKeyMapping
//

class TPtiKeyMapping  
	{
	public:	
		TInt iIndex;
		TInt iNumChars;
	};
	

//
// TPtiReplacedMapping
//
	
const TInt KMaxReplacedMappingCharacters = 5;		
class TPtiReplacedMapping
	{
	public:
		TPtiKey iKey;
		TPtiTextCase iCase;	
		TPtiEngineInputMode iMode;
		TPtiKeyboardType iKeyboardType;
		TInt iNumChars;
		TUint16 iChrs[KMaxReplacedMappingCharacters];
	};	


/**
* MPtiKeyMappings
*
* Interface class for PtiEngine keymapping functionality.
*/
class MPtiKeyMappings
	{
	public:
		virtual ~MPtiKeyMappings() {}
		
		/**
		* Starts mapping new key. Will return first character bound to given
		* key in given text case. 		
		*
		* @param aKey   A key to be mapped.
		* @param aCase  Text case for mapping operation.
		* @param aMode  Input mode for mapping. This is needed if keymapping data contains
		*               characters for several input modes (used mainly with Chinese
		*               modes). This value will be matched to possible input mode control
		*               characters in keymapping data.
		* @return       First character bound to requested key.
		*/
		virtual TUint16 StartMapping(TPtiKey aKey,
			                         TPtiTextCase aCase,
									 TPtiEngineInputMode aMode = EPtiEngineInputModeNone) = 0;
							 
		/**
		* Continues keymapping sequence. This method should be called when key event
		* comes in while multitapping timer is active. Takes care of cycling through
		* multitapping candidates associated for given key. 
		*
		* @since 2.6
		* @param aKey A key to be mapped.
		* @param aAppend Refernce to boolen variable. This will be set to ETrue if current character in
		*                editor should be replaced (new multitapping candidate was found) and
		*                to EFalse if new character should inserted instead.
		* @param aCase Text case for mapping operation.
		* @return Next character assosiated to given key or the first character if aKey
		*              was different key than previous key press.
		*/									 
		virtual TUint16 NextKey(TPtiKey aKey, TBool &aAppend, TPtiTextCase aCase) = 0;
		
		/**
		* Returns PtiEngine key code for last StartMapping() call.		
		*
		* @since 2.6
		* @return PtiEngine key code for last StartMapping() call.
		*/
		virtual TPtiKey CurrentKey() = 0;
		
		/**
		* Replaces keymapping data for given key and case. 
		*
		* @since 2.6
		* @param aKey A key to be replaced.
		* @param aMap New keymapping data for aKey,
		* @param aCase Text case for replaced data.
		* @return KErrNone or system wide error code.
		*/
		virtual TInt ReplaceKeyMapL(TPtiKey aKey, TDesC& aMap, TPtiTextCase aCase) = 0;
		
		/**
		* Returns key code for key which produces given unicode character (if found).
		*
		* @since 2.6
		* @param aChar A character to be queried.
		* @return Key code for aChar. EPtiKeyNone, if not found.
		*/				
		virtual TPtiKey KeyForCharacter(TUint16 aChar) = 0;
		
		/**
		* Returns all keymapping data for current key, excluding first character
		* (which is expected to be "get all"-control character).
		* 
		* @param aCase  Text case for which data will be returned.
		* @return Constant descriptor pointing to keymap data.
		* @since 3.0
		*/		
		virtual TPtrC GetAll(TPtiTextCase aCase) = 0;					
	};


/**
* CPtiMappings
*
* Base class for keymapping implementation classes.
* Handles locally replaced keymappings.
*/
class CPtiMappings : public CBase
	{
	public:
		CPtiMappings();
		CPtiMappings(CPtiKeyMapData* aData);
		~CPtiMappings();
		inline CPtiKeyMapData* KeyMapData() const;
		
		// DEPRECATED
		virtual TInt WriteData(TInt16*);   
		// DEPRECATED		     
		virtual TInt ChunkDataSize() const;
		
		IMPORT_C TPtiKeyboardType KeyboardType() const;				
		
	protected:	
		TInt FindReplacedMapping(TPtiKey aKey, TPtiTextCase aCase, TPtiEngineInputMode aMode) const;
		void ReplaceKeyMapLocalL(TPtiKey aKey, TDesC& aMap, TPtiTextCase aCase, TPtiEngineInputMode aMode);
		
    public:		
		TPtrC DataForKeyLocal(TPtiKey aKey, TPtiTextCase aCase, TPtiEngineInputMode aMode) const;	
						
	protected:
		TPtiKey iCurrentKey;	
		TPtiEngineInputMode iCurrentMode;
		TInt iCurrentChar;
		RArray<TPtiReplacedMapping> iReplacedMappings;
		CPtiKeyMapData* iKeyMapData;          // Not owned
		TPtiKeyboardType iKeyboardType;
	};


/**
* CPtiKeyMappings
* 
* Keymappings implementation class for itu-t keyboard 
*/
NONSHARABLE_CLASS(CPtiKeyMappings) : public CPtiMappings, public MPtiKeyMappings
	{
	public:	
		/**
		* DEPRECATED. Leaves with KErrNotSupported.
		*/
		IMPORT_C static CPtiKeyMappings* NewL(TDesC& aData);
		
		/**
		* DEPRECATED. Leaves with KErrNotSupported.
		*/
		IMPORT_C static CPtiKeyMappings* NewL(TInt16* aData);		
		
		/**
		* Constructor.
		*/
		IMPORT_C static CPtiKeyMappings* NewL(CPtiKeyMapData* aData);
		
		IMPORT_C ~CPtiKeyMappings();
		
		/**
		* Start mapping for given key.
		*
		* @param aKey  Key code for key.
		* @param aCase Cuurrent text case.
		* @param aMode Current input mode. Default value works for most cases.
		* @return First character for given key. 
		*/
		IMPORT_C virtual TUint16 StartMapping(TPtiKey aKey,
			                         TPtiTextCase aCase,
									 TPtiEngineInputMode aMode = EPtiEngineInputModeNone);										 
									 
		/**
		* Continues keymapping sequence. This method should be called when key event
		* comes in while multitapping timer is active. Takes care of cycling through
		* multitapping candidates associated for given key. 
		*
		* @since S60 V2.6
		* @param aKey A key to be mapped.
		* @param Refernce to boolen variable. This will be set to ETrue if current character in
		*        editor should be replaced (new multitapping candidate was found) and
		*        to EFalse if new character should inserted instead.
		* @param aCase Text case for mapping operation.
		* @return Next character assosiated to given key or the first character if aKey
		*              was different key than previous key press.
		*/									 								 
		IMPORT_C TUint16 NextKey(TPtiKey aKey, TBool &aAppend, TPtiTextCase aCase);
		
		/**
		* Returns key code for key currently being mapped (relates to StartMapping and NextKey).
		*
		* @return Key code for key currently being mapped.
		*/
		inline TPtiKey CurrentKey();
		
		/**
		* Replaces keymapping data for given key.
		*		
		* @param  aKey  Key code for key to be replaced.
		* @param  aMap  New keymapping data for aKey.
		* @param  aCase Text case.
		* @return KErrNone if succesfull
		*         Otherwise system wide error code.
		*/
		IMPORT_C TInt ReplaceKeyMapL(TPtiKey aKey, TDesC& aMap, TPtiTextCase aCase);
		
		/**
		* Scans through keymapping data and returns key code for given character.
		*
		* @param  aChar A character to be queried.
		* @return Key code for mtaching key.
		*         EPtiKeyNone if no matching keys found.
		*/
		IMPORT_C TPtiKey KeyForCharacter(TUint16 aChar);
		
		/**
		* Returns keymapping data for given key.
		*
		* @param aKey    A key to be queried.
		* @param aResult Descritor where resulting data is stored.
		* @param aCase   Text case		 
		*/
		IMPORT_C void GetDataForKey(TPtiKey aKey, TDes& aResult, TPtiTextCase aCase);
								
		/**
		* Returns all keymapping data for current key, excluding first character
		* (which is expected to be "get all"-control character).
		* 
		* @param aCase  Text case for which data will be returned.
		* @return Constant descriptor pointing to keymap data.
		* @since S60 V3.0
		*/		
		TPtrC GetAll(TPtiTextCase aCase);							

	protected:		
		CPtiKeyMappings();
		CPtiKeyMappings(CPtiKeyMapData* aData);
		TUint16 NextChar(TPtiTextCase aCase);
		inline void KeyCodeToInternal(TPtiKey aKey);
		inline void DeQwertyfyCaseValue(TPtiTextCase& aCase);		
	};


/**
* CPtiQwertyKeyMappings
* 
* Keymappings implementation class for qwerty keyboard.
*/
NONSHARABLE_CLASS(CPtiQwertyKeyMappings) : public CPtiMappings, public MPtiKeyMappings
	{
	public:	 
		/**
		* DEPRECATED. Will leave with KErrNotSupported.
		*/
		IMPORT_C static CPtiQwertyKeyMappings* NewL(TDesC& aData);
		
		/**
		* DEPRECATED. Will leave with KErrNotSupported.
		*/
		IMPORT_C static CPtiQwertyKeyMappings* NewL(TInt16* aData);
		
		/**
		* Constructor.
		*/
		IMPORT_C static CPtiQwertyKeyMappings* NewL(CPtiKeyMapData* aData);				
		
		IMPORT_C ~CPtiQwertyKeyMappings();
		
		/**
		* Start mapping for given key.
		*
		* @param aKey  Key code for key.
		* @param aCase Cuurrent text case.
		* @param aMode Current input mode. Default value works for most cases.
		* @return First character for given key. 
		*/		
		IMPORT_C TUint16 StartMapping(TPtiKey aKey,
			                          TPtiTextCase aCase,
									  TPtiEngineInputMode aMode = EPtiEngineInputModeNone);
									  
		/**
		* Continues keymapping sequence. This method should be called when key event
		* comes in while multitapping timer is active. Takes care of cycling through
		* multitapping candidates associated for given key. 
		*
		* @since S60 V2.6
		* @param aKey A key to be mapped.
		* @param aAppend Refernce to boolen variable. This will be set to ETrue if current character in
		*                editor should be replaced (new chr-case character was found) and
		*                to EFalse if new character should inserted instead.
		* @param aCase Text case for mapping operation.
		* @return Next character assosiated to given key or the first character if aKey
		*              was different key than previous key press.
		*/									 					  
		IMPORT_C TUint16 NextKey(TPtiKey aKey, TBool &aAppend, TPtiTextCase aCase);
		
		/**
		* Returns key code for key currently being mapped (relates to StartMapping and NextKey).
		*
		* @return Key code for key currently being mapped.
		*/		
		inline TPtiKey CurrentKey();
		
		/**
		* Replaces keymapping data for given key.
		*		
		* @param  aKey  Key code for key to be replaced.
		* @param  aMap  New keymapping data for aKey.
		* @param  aCase Text case.
		* @return KErrNone if succesfull
		*         Otherwise system wide error code.
		*/		
		IMPORT_C TInt ReplaceKeyMapL(TPtiKey aKey, TDesC& aMap, TPtiTextCase aCase);
		
		/**
		* Scans through keymapping data and returns key code for given character.
		*
		* @param  aChar A character to be queried.
		* @return Key code for mtaching key.
		*         EPtiKeyNone if no matching keys found.
		*/		
		IMPORT_C TPtiKey KeyForCharacter(TUint16 aChar);
		
		/**
		* Returns keymapping data for given key.
		*
		* @param aKey    A key to be queried.
		* @param aResult Descritor where resulting data is stored.
		* @param aCase   Text case		 
		*/		
		IMPORT_C void GetDataForKey(TPtiKey aKey, TDes& aResult, TPtiTextCase aCase);
		
		/** DEPRECATED */
		TInt WriteData(TInt16* aDest);
		
		/** DEPRECATED */
		TInt ChunkDataSize() const;
		
		/** Internal */		
		inline TBool DeadKeyRootFlag() const;
		
		/** Internal */				
		inline TUint16 DeadKeyRootChar() const;
		
		/** Internal */				
		inline TBool VowelSequenceFlag() const;
		
		/** Internal */				
		inline TUint16 VowelSequenceResult() const;
		
		/** Internal */				
		inline void ClearVowelSequence();
		
		/** Internal */				
		inline TInt16 DeadKey() const;
		
		/** Internal */				
		inline void ClearDeadKey();
		
		/** Internal */				
		inline void ClearLastChar();
		
		/** Internal */					
		inline void SetLastChar(TInt aLastChar);
		
		/** Internal */				
		inline TInt GetLastChar() const;
		
		/** Internal */				
		inline TUint16 ReplacedCharacter();
		
		/** Internal */				
		inline void SetLastKey(TPtiKey aKey);
		
		/** Internal */				
		inline TPtiTextCase VowelCase() const;
		
		/** Internal */				
		inline void ResetVietnameseVowelSequenceAndToneMarks();
		
		/** Internal */				
		inline TPtiKey LastKey() const;

		/**
		* Returns all keymapping data for current key, excluding first character
		* (which is expected to be "get all"-control character).
		* 
		* @param aCase  Text case for which data will be returned.
		* @return Constant descriptor pointing to keymap data.
		* @since S60 V3.0
		*/		
		TPtrC GetAll(TPtiTextCase aCase);							
		
		/** Internal */	
		inline void SetFlag(TInt aFlag);
		
		/** Internal */			
		inline void ResetFlag(TInt aFlag);	
		
		/**
		* Fills given array with numeric mode mappings defined in keymap data file.
		* Resultin array contains those mappings that are given with "numeric_mode_key"
		* tag in keymap data file.
		*
		* @since S60 V3.2
		* @param aResult An array to be filled with numeric mode mappings.
		*/
		void GetNumericModeKeysFromDataL(RArray<TPtiNumericKeyBinding>& aResult);
		
		/**
		* Set keyboard type to be used with qwerty keymappings. Default
		* type is EPtiKeyboardStandard4x12 (Nokia E70 style).
		*
		* @param aKeyboardType Keyboard type to be set.
		* @return KErrNone if keyboard type was set.
		*         EErrNotSupported if mapping data does not have block for given keyboard type.
		*/				
		IMPORT_C TInt SetKeyboardType(TPtiKeyboardType aKeyboardType);	
		
		/**
		* Returns a boolean value indicating whether there is data block available for
		* given keyboard type.
		*
		* @param  aKeyboardType Keyboard type.
		* @return ETrue if there is data block for given keyboard type.
		*         EFalse otherwise
		*/
		IMPORT_C TBool HasDataBlockForKeyboardType(TPtiKeyboardType aKeyboardType) const;			

	public:
		enum
			{
			EDeadKeyRootFlag = 0x01,
			EVowelSeqFlag    = 0x02,
			EPrevKeyInUpperCase = 0x04,
			ETrackVietnameseToneMarksAndVowels = 0x08
			};
						
	private:			
		CPtiQwertyKeyMappings();	
		CPtiQwertyKeyMappings(CPtiKeyMapData* aData);
		void ConstructL();
	
		TUint16 NextChar(TPtiTextCase aCase);
		void KeyCodeToInternal(TPtiKey aKey);
		TUint16 GetDeadKeyChar(TPtiKey aKey, TPtiTextCase aCase);
		inline TInt DeadKeyIndex(TUint16 aDeadKeyUnicode);
		inline TBool IsDeadKeyCode(TUint16 aChar) const;
		inline TBool IsModeControlChar(TUint16 aChar) const;
        TUint16 GetCharForMode(TPtiEngineInputMode aMode, TPtrC aChars, TBool aSkipFirst);
		TBool DoesModeCharMatchToInputMode(TUint16 aChar, TPtiEngineInputMode aMode) const;
		TUint16 VowelSequence(TPtiKey aKey1, TPtiKey aKey2, TPtiTextCase aCase) const;	
		TUint16 VietnameseToneMark(TUint16 aPrevChar, TPtiKey aKey);
		TUint16 RepeatingVowelSequence(TPtiKey aKey);
		TPtiKey VowelSeqRootKey(TUint16 aChar);
		inline TBool ChineseChrModeConversionNeeded(TPtiTextCase aCase, TPtiEngineInputMode aMode) const;
		inline TBool IsChnSpecialCharKey(TPtiKey aKey) const;

	private:
		RArray<TPtiKeyMapping> iReservedArray;  		
		TAny* iReservedPtr;
		TUint16 iDeadKey;
		TUint16 iDeadKeyRootChar;
		TUint16 iVowelSeqResult;
		TPtiKey iLastKey;
		TInt iFlags;
		CPtiQwertyKeymappingsExtension* iExtension;
	};


/**
* CPtiHalfQwertyKeyMappings
* 
* Keymappings implementation class for half qwerty keyboard 
*/

NONSHARABLE_CLASS(CPtiHalfQwertyKeyMappings) : public CPtiKeyMappings
    {
    public:
	    IMPORT_C static CPtiHalfQwertyKeyMappings* NewL(CPtiKeyMapData* aData);
        IMPORT_C ~CPtiHalfQwertyKeyMappings();	    
        
    public: // From MPtiKeyMappings
		IMPORT_C TInt ReplaceKeyMapL(TPtiKey aKey, TDesC& aMap, TPtiTextCase aCase);
		IMPORT_C TPtiKey KeyForCharacter(TUint16 aChar);
		IMPORT_C TPtrC GetAll(TPtiTextCase aCase);	  
		
        /**
		* Fills given array with numeric mode mappings defined in keymap data file.
		* Resultin array contains those mappings that are given with "numeric_mode_key"
		* tag in keymap data file.
		*
		* @since S60 V5.0
		* @param aResult An array to be filled with numeric mode mappings.
		*/
		void GetNumericModeKeysFromDataL(RArray<TPtiNumericKeyBinding>& aResult);
		
	    /**
		* Returns keymapping data for given key.
		*
		* @since S60 V5.0		
		* @param aKey    A key to be queried.
		* @param aResult Descritor where resulting data is stored.
		* @param aCase   Text case		 
		*/		
		IMPORT_C void GetDataForKey(TPtiKey aKey, TDes& aResult, TPtiTextCase aCase);				
		/**
		* Starts mapping new key. Will return first character bound to given
		* key in given text case. 		
		*
		* @param aKey   A key to be mapped.
		* @param aCase  Text case for mapping operation.
		* @param aMode  Input mode for mapping. This is needed if keymapping data contains
		*               characters for several input modes (used mainly with Chinese
		*               modes). This value will be matched to possible input mode control
		*               characters in keymapping data.
		* @return       First character bound to requested key.
		*/
		IMPORT_C TUint16 StartMapping(TPtiKey aKey, TPtiTextCase aCase,
                                               TPtiEngineInputMode aMode = EPtiEngineInputModeNone);

        /**
		* Continues keymapping sequence. This method should be called when key event
		* comes in while multitapping timer is active. Takes care of cycling through
		* multitapping candidates associated for given key. 
		*
		* @since S60 V5.0
		* @param aKey A key to be mapped.
		* @param aAppend Refernce to boolen variable. This will be set to ETrue if current character in
		*                editor should be replaced (new chr-case character was found) and
		*                to EFalse if new character should inserted instead.
		* @param aCase Text case for mapping operation.
		* @return Next character assosiated to given key or the first character if aKey
		*              was different key than previous key press.
		*/									 					  
		IMPORT_C TUint16 NextKey(TPtiKey aKey, TBool &aAppend, TPtiTextCase aCase);
	protected:	
		TUint16 NextChar(TPtiTextCase aCase);

    private:
        CPtiHalfQwertyKeyMappings(CPtiKeyMapData* aData);		  
    };

// ---------------------------------------------------------------------------
// CPtiKeyMappings::CurrentKey
// 
// ---------------------------------------------------------------------------
// 
inline TPtiKey CPtiKeyMappings::CurrentKey()
	{
	return iCurrentKey;
	}

// ---------------------------------------------------------------------------
// CPtiQwertyKeyMappings::CurrentKey
// 
// ---------------------------------------------------------------------------
// 
inline TPtiKey CPtiQwertyKeyMappings::CurrentKey()
	{
	return iCurrentKey;
	}

// ---------------------------------------------------------------------------
// CPtiQwertyKeyMappings::DeadKeyIndex
// 
// ---------------------------------------------------------------------------
// 
inline TInt CPtiQwertyKeyMappings::DeadKeyIndex(TUint16 aDeadKeyUnicode)
	{
	return (aDeadKeyUnicode & 0x00ff);
	}

// ---------------------------------------------------------------------------
// CPtiQwertyKeyMappings::IsDeadKeyCode
// 
// ---------------------------------------------------------------------------
// 
inline TBool CPtiQwertyKeyMappings::IsDeadKeyCode(TUint16 aChar) const
	{
	if (((aChar & 0xff00) == 0xf000) &&
	    ((aChar & 0xff) <= 5))
		{
		return ETrue;	
		}
		
	return EFalse;	
	}

// ---------------------------------------------------------------------------
// CPtiQwertyKeyMappings::DeadKeyRootFlag
// 
// ---------------------------------------------------------------------------
// 
inline TBool CPtiQwertyKeyMappings::DeadKeyRootFlag() const
	{
	return (iFlags & EDeadKeyRootFlag) != 0;		
	}

// ---------------------------------------------------------------------------
// CPtiQwertyKeyMappings::IsModeControlChar
// 
// ---------------------------------------------------------------------------
// 
inline TBool CPtiQwertyKeyMappings::IsModeControlChar(TUint16 aChar) const
	{
	if ((aChar == KPtiPinyinMarker) ||
		(aChar == KPtiStrokeMarker) ||
		(aChar == KPtiZhuyinMarker) ||
		(aChar == KPtiCangjieMarker))
		{	
		return ETrue;
		}

	return EFalse;
	}

// ---------------------------------------------------------------------------
// CPtiQwertyKeyMappings::VowelSequenceFlag
// 
// ---------------------------------------------------------------------------
// 
inline TBool CPtiQwertyKeyMappings::VowelSequenceFlag() const
	{
	return (iFlags & EVowelSeqFlag) != 0;
	}

// ---------------------------------------------------------------------------
// CPtiQwertyKeyMappings::SetFlag
// 
// ---------------------------------------------------------------------------
// 
inline void CPtiQwertyKeyMappings::SetFlag(TInt aFlag)
	{
	iFlags |= aFlag;	
	}

// ---------------------------------------------------------------------------
// CPtiQwertyKeyMappings::ResertFlag
// 
// ---------------------------------------------------------------------------
// 
inline void CPtiQwertyKeyMappings::ResetFlag(TInt aFlag)
	{	
	iFlags &= ~aFlag;	
	}

// ---------------------------------------------------------------------------
// CPtiQwertyKeyMappings::VowelSequenceResult
// 
// ---------------------------------------------------------------------------
// 
inline TUint16 CPtiQwertyKeyMappings::VowelSequenceResult() const
	{
	return iVowelSeqResult;
	}

// ---------------------------------------------------------------------------
// CPtiQwertyKeyMappings::ClearVowelSequence
// 
// ---------------------------------------------------------------------------
// 
inline void CPtiQwertyKeyMappings::ClearVowelSequence()
	{
	iLastKey = EPtiKeyNone;
	}
	
// ---------------------------------------------------------------------------
// CPtiQwertyKeyMappings::DeadKeyRootChar
// 
// ---------------------------------------------------------------------------
// 		
inline TUint16 CPtiQwertyKeyMappings::DeadKeyRootChar() const
	{
	return iDeadKeyRootChar;	
	}
		
// ---------------------------------------------------------------------------
// CPtiQwertyKeyMappings::DeadKey
// 
// ---------------------------------------------------------------------------
// 	
inline TInt16 CPtiQwertyKeyMappings::DeadKey() const
	{
	return iDeadKey;	
	}	

// ---------------------------------------------------------------------------
// CPtiQwertyKeyMappings::ClearDeadKey
// 
// ---------------------------------------------------------------------------
// 
inline void CPtiQwertyKeyMappings::ClearDeadKey()
	{
	iDeadKey = 0;
	}
		
// ---------------------------------------------------------------------------
// CPtiQwertyKeyMappings::ClearLastChar
// 
// ---------------------------------------------------------------------------
// 	
inline void CPtiQwertyKeyMappings::ClearLastChar()
	{
	iExtension->iLastChar = 0;
	}

// ---------------------------------------------------------------------------
// CPtiQwertyKeyMappings::SetLastChar
// 
// ---------------------------------------------------------------------------
// 	
inline void CPtiQwertyKeyMappings::SetLastChar(TInt aLastChar)
	{
	iExtension->iLastChar = (TUint16)aLastChar;
	}
	
// ---------------------------------------------------------------------------
// CPtiQwertyKeyMappings::GetLastChar
// 
// ---------------------------------------------------------------------------
// 	
inline TInt CPtiQwertyKeyMappings::GetLastChar() const
	{
	return iExtension->iLastChar;
	}
		
// ---------------------------------------------------------------------------
// CPtiQwertyKeyMappings::ReplacedCharacter
// 
// ---------------------------------------------------------------------------
// 	
inline TUint16 CPtiQwertyKeyMappings::ReplacedCharacter()
	{	
	return iExtension->iReplaced;
	}

// ---------------------------------------------------------------------------
// CPtiQwertyKeyMappings::SetLastKey
// 
// ---------------------------------------------------------------------------
// 		
inline void CPtiQwertyKeyMappings::SetLastKey(TPtiKey aKey)
	{
	iLastKey = aKey;	
	}
		
// ---------------------------------------------------------------------------
// CPtiQwertyKeyMappings::KeyCodeToInternal
// 
// ---------------------------------------------------------------------------
// 				
inline void CPtiKeyMappings::KeyCodeToInternal(TPtiKey aKey)
	{
	iCurrentKey = aKey;
	}

// ---------------------------------------------------------------------------
// CPtiQwertyKeyMappings::VowelCase
// 
// ---------------------------------------------------------------------------
// 
inline TPtiTextCase CPtiQwertyKeyMappings::VowelCase() const
	{
	return iExtension->iVowelCase;
	}

// ---------------------------------------------------------------------------
// CPtiQwertyKeyMappings::ResetVietnameseVowelSequenceAndToneMarks
// 
// ---------------------------------------------------------------------------
// 
inline void CPtiQwertyKeyMappings::ResetVietnameseVowelSequenceAndToneMarks()
	{
	iExtension->iLastChar = 0;
	iExtension->iReplaced = 0;
	iExtension->iLastTone = 0;
	iVowelSeqResult = 0;
	iLastKey = EPtiKeyNone;
	ResetFlag(EVowelSeqFlag);
	}
	
// ---------------------------------------------------------------------------
// CPtiQwertyKeyMappings::LastKey
// 
// ---------------------------------------------------------------------------
// 
inline TPtiKey CPtiQwertyKeyMappings::LastKey() const
	{
	return iLastKey;
	}
	
// ---------------------------------------------------------------------------
// CPtiQwertyKeyMappings::ChineseChrModeConversionNeeded
// 
// ---------------------------------------------------------------------------
// 
inline TBool CPtiQwertyKeyMappings::ChineseChrModeConversionNeeded(TPtiTextCase aCase, 
                                                         TPtiEngineInputMode aMode) const
	{
	if (aCase == EPtiCaseChrLower &&
       (aMode == EPtiEnginePinyinQwerty  || aMode ==  EPtiEnginePinyinPhraseQwerty ||
        aMode == EPtiEngineStrokeQwerty  || aMode ==EPtiEngineNormalCangjieQwerty  ||
        aMode == EPtiEngineZhuyinQwerty  || aMode == EPtiEngineZhuyinPhraseQwerty  ||
        aMode == EPtiEngineStrokePhraseQwerty))
		{
		return ETrue;
		}
	
	return EFalse;
	}
	
// ---------------------------------------------------------------------------
// CPtiKeyMappings::DeQwertyfyCaseValue
// 
// ---------------------------------------------------------------------------
// 	
inline void CPtiKeyMappings::DeQwertyfyCaseValue(TPtiTextCase& aCase)
	{
	if (aCase == EPtiCaseChrLower)
		{
		aCase = EPtiCaseLower;
		}
	else if (aCase == EPtiCaseChrUpper)
		{
		aCase = EPtiCaseUpper;
		}		
	}
	
// ---------------------------------------------------------------------------
// CPtiKeyMappings::KeyMapData
// 
// ---------------------------------------------------------------------------
// 		
inline CPtiKeyMapData* CPtiMappings::KeyMapData() const
	{
	return iKeyMapData;
	}
	
// ---------------------------------------------------------------------------
// CPtiKeyMappings::IsChnSpecialCharKey
// 
// ---------------------------------------------------------------------------
// 		
inline TBool CPtiQwertyKeyMappings::IsChnSpecialCharKey(TPtiKey aKey) const
	{
	if (aKey == EPtiKeyQwertyPlus  ||
    	aKey == EPtiKeyQwertyMinus ||
        aKey == EPtiKeyQwertyComma ||
        aKey == EPtiKeyQwertySemicolon ||
    	aKey == EPtiKeyQwertyFullstop ||
    	aKey == EPtiKeyQwertyHash     ||
    	aKey == EPtiKeyQwertySlash    ||
        aKey == EPtiKeyQwertyApostrophe)
		{
		return ETrue;
		}
		
	return EFalse;	
	}
			
#endif // _PTI_KEY_MAPPINGS_H

// End of file
