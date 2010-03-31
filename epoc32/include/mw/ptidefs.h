/*
* Copyright (c) 2003-2006 Nokia Corporation and/or its subsidiary(-ies). 
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
* Description:               Global PtiEngine definitions
*
*/














#ifndef _PTI_DEFS_H
#define _PTI_DEFS_H

#include <e32keys.h>

#ifdef RD_HINDI_PHONETIC_INPUT
/* Indic Phonetic input */

/*
* Defines the state of the syllable. This is used by FEP for either committing 
* the inline text or updating the inline text.
*/

enum TSyllableState
{
    EIndicSyllableStateFirst,
    EIndicSyllableStateInsideSyllable,
    EIndicSyllableStateSyllableBroken,
    EIndicSyllableStateLast
};


/*
* This is a structure that abstracts the phonetic argument and the response
* from the Indic phonetic core in a structure.
*/

typedef struct
{
    TChar iChar;
    TDes *iDest;
    TSyllableState iState;
}TPhoneticArg;

#endif
const TInt KMaxLanguageNameLength = 50;
const TInt KMaxAutoSubstStringLength = 32;

const TInt KErrPtiEngineBase = (-1000); //based on the value of leave in PtiEngine


enum TPtiError
    {
    KErrNoActiveLanguage = KErrPtiEngineBase-1,   
    KErrLanguageNotFound = KErrPtiEngineBase-2,
    KErrNoSuitableCore = KErrPtiEngineBase-3,
    KErrNotAllowed = KErrPtiEngineBase-4,
    KErrTooLongWord = KErrPtiEngineBase-5,
    KErrInvalidWord = KErrPtiEngineBase-6,
    KErrTooLongReading = KErrPtiEngineBase-7,
    KErrInvalidReading = KErrPtiEngineBase-8,
    KErrUserDic = KErrPtiEngineBase-9,
    KErrInternalCoreError = KErrPtiEngineBase-10,
    KErrLengthMismatch = KErrPtiEngineBase-11
    };


/**
* Enumerations for all the possible input modes supported by PtiEngine. 
* The modes actually available in the device depend on core object, resource 
* and keyboard configuration.
* Here are short descriptions:
*
* EPtiEngineMultitapping 
*        Traditional text input method for latin-like languages, where 
*        a list of characters is associated to each keypad keys
*        and user cycles through associated characters by consecutive key presses.
*
* EPtiEnginePredictive 
*        Predictive text input mode, where user presses only one key press per
*        character and the prediction engine provides a list of candidate words
*        associated top that key sequence.
* 
* EPtiEngineWordCompletion
*        This is same as EPtiEnginePredictive, except that prediction engine
*        will include also complete words containing more characters than
*        the number of key presses in current key sequence.
*
* EPtiEngineNumeric 
*        This is numeric input mode. All the languages suppor it, since it uses
*        static keymappings built directly into PtiEngine. It works in same way
*        as EPtiEngineMultitapping, except that keymapping data contains
*        only number mode characters. 
*
* EPtiEngineQwerty
*        Standard qwerty-keyboard input mode for latin-like languages.
*
* EPtiEnginePinyin
*        Chinese PinYin input mode for ITU-T keypad.
*
* EPtiEngineStroke
*        Chinese Strokes input mode for ITU-T keypad.       
*
* EPtiEngineStroke
*        Chinese ZhuYin input mode for ITU-T keypad.       
*
* EPtiEngineHirakanaKanji
*        Japanese Hiragana/Kanji input mode.       
*
* EPtiEngineHirakanaKanjiPredictive
*        Predictive Japanese Hiragana/Kanji input mode.       
*
* EPtiEngineKatakana
*        Japanese Katakana input mode.   
*
* EPtiEngineFullWitdthKatakana
*        Japanese full width Katakana input mode. 
*
* EPtiEngineFullWitdthKatakana
*        Japanese full width numeric input mode. 
*
* EPtiEngineFullWitdthAlphabet
*        Japanese full width alphabet input mode. 
*
* EPtiEngineHiragana
*        Japanese Hiragana input mode. 
*
* EPtiEnginePinyinByPhrase
*        Chinese Pinyin phrase input. This is same as EPtiEnginePinyin, execpt that
*        input string may contain pinyin words for several chinese characters.
*
* EPtiEngineZhuyinByPhrase
*        Chinese Zinyin phrase input. This is same as EPtiEngineZhuyin, execpt that
*        input string may contain zhuyin sequences for several chinese characters.
*
* EPtiEngineZhuyinQwerty
*        Chinese Zhuyin input for qwerty keyboard.
*
* EPtiEngineZhuyinPhraseQwerty
*        Chinese Zinyin phrase input for qwerty keyboard. This is same as EPtiEngineZhuyinQwerty,
*        execpt that input string may contain zhuyin sequences for several chinese characters.
*
* EPtiEnginePinyinQwerty
*        Chinese Pinyin input for qwerty keyboard.
*
* PtiEnginePinyinPhraseQwerty
*        Same as EPtiEnginePinyinByPhrase but for qwerty keyboard
*
* EPtiEngineStrokeQwerty
*        Same as EPtiEngineStroke but for qwerty keyboard
*
* EPtiEngineNormalCangjieQwerty
*        Normal Chinese CangJie input for qwerty keyboard
*        (CangJie is available only for qwerty).
*
* EPtiEngineEasyCangjieQwerty
*        Easy Chinese CangJie input for qwerty keyboard
*        (CangJie is available only for qwerty).
*
* EPtiEngineAdvCangjieQwerty       
*        Advanced Chinese CangJie input for qwerty keyboard
*        (CangJie is available only for qwerty).
*
* EPtiEngineHiraganaKanjiQwerty
*       Japanese Hiragana/Kanji input for qwerty keyboard.
*
* EPtiEngineHiraganaKanjiPredictiveQwerty  
*       Japanese predictive Hiragana/Kanji input for qwerty keyboard
*
* EPtiEngineKatakanaQwerty            
*       Japanese Half-width Katakana input for qwerty keyboard.
*
* EPtiEngineFullWidthKatakanaQwerty  
*       Japanese Full-width Katakana input for qwerty keyboard.
*
* EPtiEngineFullWidthNumericQwerty
*       Japanese Full-width Alphabet input for qwerty keyboard.
*
* EPtiEngineFullWidthAlphabetQwerty
*       Japanese Full-width Alphabet input for qwerty keyboard.
*        
* EPtiEngineHiraganaQwerty          
*       Japanese Hiragana input for qwerty keyboard. 
*
* EPtiEngineStrokeByPhrase,             // Stroke phrase input.
*       Chinese Stroke input for ITU-T keypad. Phrasal version.
*
* EPtiEngineStrokePhraseQwerty
*       Chinese Stroke input for qwerty keyboard. Phrasal version.
*
* EPtiEngineQwertyPredictive,           // "Sloppy type" input for qwerty keyboard.
*       Intelligent qwerty input. Used for word completion and spell
*       correction features for qwerty keyboard.
*
* EPtiEngineHalfQwerty
*       Basic multitaping style text input for half-qwerty keyboard. The functionality
*       of half-qwerty keyboard is same as conventional itu-t phone keypad, except that
*       each key is associated with two basic characters (instead of three or four
*       as in itu-t keypad). Character mapping is also organized to follow qwerty
*       layout (instead of alphabetical order as in itu-t keypad).
* 
* EPtiEngineHalfQwertyPredictive,
*       Predictive text input for half-qwerty keyboard. The functionality
*       of half-qwerty keyboard is same as conventional itu-t phone keypad, except that
*       each key is associated with two basic characters(instead of three or four
*       as in itu-t keypad). . Character mapping is also organized to follow qwerty
*       layout (instead of alphabetical order as in itu-t keypad). This input mode 
*       is essentially same as EPtiEngineWordCompletion but uses half-qwerty keyboard. 
*
* EPtiEngineInputModeIndicPhoneticMultitap
*       Hindi phonetic input for itu-t keypad.
*
* EPtiEngineInputModeIndicPhoneticQwerty
*       Hindi phonetic input for qwerty keyboard.
*
* EPtiEngineInputModeZhuyinMiniQwertyFind
*       Zhuyin multitap input method for mini qwerty symbol find.
*
*/
enum TPtiEngineInputMode
    {
    EPtiEngineInputModeNone = 0,
    EPtiEngineMultitapping,             // Basic multitapping input for latin languages.
    EPtiEnginePredictive,               // Predictive input for latin languages.
    EPtiEngineWordCompletion,           // Predictive input with word completion for latin languages.
    EPtiEngineNumeric,                  // Latin numeric input mode.  
    EPtiEngineQwerty,                   // Basic qwerty input mode.
    EPtiEnginePinyin,                   // Chinese pinyin mode.        
    EPtiEngineStroke,                   // Chinese stroke mode.
    EPtiEngineZhuyin,                   // Chinese zhuyin mode. 
    EPtiEngineHiraganaKanji,            // Hiragana/Kanji mode.
    EPtiEngineHiraganaKanjiPredictive,  // Predictive Hiragana/Kanji mode.
    EPtiEngineKatakana,                 // Half-width Katakana mode. 
    EPtiEngineFullWidthKatakana,        // Full-width Katakana mode.
    EPtiEngineFullWidthNumeric,         // Full-width Alphabet mode (for Japanese input).
    EPtiEngineFullWidthAlphabet,        // Full-width Alphabet mode (for Japanese input).
    EPtiEngineHiragana,                 // Hiragana only mode. 
    EPtiEnginePinyinByPhrase,           // Pinyin phrase input.         
    EPtiEngineZhuyinByPhrase,           // Zhuyin phrase input.
    EPtiEngineZhuyinQwerty,             // Zhuyin qwerty input. 
    EPtiEngineZhuyinPhraseQwerty,       // Zhuyin phrase qwerty input. 
    EPtiEnginePinyinQwerty,             // Pinyin qwerty input.
    EPtiEnginePinyinPhraseQwerty,       // Pinyin phrase qwerty input. 
    EPtiEngineStrokeQwerty,             // Stroke qwerty input.
    EPtiEngineNormalCangjieQwerty,      // Normal Cangjie qwerty input
    EPtiEngineEasyCangjieQwerty,        // Easy Cangjie qwerty input
    EPtiEngineAdvCangjieQwerty,         // Advanced Cangjie qwerty input
    EPtiEngineHiraganaKanjiQwerty,      // Hiragana/Kanji qwerty input mode.
    EPtiEngineHiraganaKanjiPredictiveQwerty,  // Predictive Hiragana/Kanji qwerty input mode.
    EPtiEngineKatakanaQwerty,           // Half-width Katakana qwerty input mode. 
    EPtiEngineFullWidthKatakanaQwerty,  // Full-width Katakana qwerty input mode.
    EPtiEngineFullWidthNumericQwerty,   // Full-width Alphabet qwerty input mode (for Japanese input).
    EPtiEngineFullWidthAlphabetQwerty,  // Full-width Alphabet qwerty input mode (for Japanese input).
    EPtiEngineHiraganaQwerty,           // Hiragana only qwerty input mode.   
    EPtiEnginePinyinVkb,                  // Chinese pinyin mode.        
    EPtiEngineStrokeVkb,                  // Chinese stroke mode.
    EPtiEngineZhuyinVkb,                  // Chinese zhuyin mode. 
	  EPtiEngineStrokeByPhrase,             // Stroke phrase input.
    EPtiEngineStrokePhraseQwerty,         // Stroke phrase qwerty input.
    EPtiEngineHiraganaKanjiVkb,           // Hiragana/Kanji mode for VKB.
    EPtiEngineHiraganaKanjiPredictiveVkb, // Predictive Hiragana/Kanji mode for VKB.
    EPtiEngineHiraganaKanjiHwr,           // Hiragana/Kanji mode for HWR.
    EPtiEngineHiraganaKanjiPredictiveHwr, // Predictive Hiragana/Kanji mode for HWR.
    EPtiEngineKatakanaVkb,                // Half-width Katakana mode for VKB.
    EPtiEngineFullWidthKatakanaVkb,       // Full-width Katakana mode for VKB.
    EPtiEngineHiraganaVkb,                // Hiragana only qwerty input mode for VKB.
    EPtiEngineNormalCangjieVkb,  
    EPtiEngineEasyCangjieVkb,    
    EPtiEngineAdvCangjieVkb,     
    EPtiEngineInputModeIndicPhoneticMultitap,
    EPtiEngineInputModeIndicPhoneticQwerty,
    EPtiEngineHiraganaKanjiVkbRomaji,           // Hiragana/Kanji mode for VKB/FSQ Romaji input.
    EPtiEngineHiraganaKanjiPredictiveVkbRomaji, // Predictive Hiragana/Kanji mode for VKB/FSQ Romaji input.
    EPtiEngineQwertyPredictive,           // "Sloppy type" input for qwerty keyboard.
    EPtiEngineHalfQwerty,
    EPtiEngineHalfQwertyPredictive,
    EPtiEngineInputModeQwertyPredictive ,
	EPtiEngineInputModeZhuyinMiniQwertyFind,
    EPtiEnginePinyinPhraseHalfQwerty,
    EPtiEngineStrokePhraseHalfQwerty,
    EPtiEngineZhuyinPhraseHalfQwerty,
    EPtiEngineMultitappingKorean,       // Basic multitapping input for korean language.
    EPtiEngineQwertyKorean,    
    EPtiEngineMaxInputModes = EPtiEngineQwertyKorean  
    };


/*
* Predictive qwerty error correction levels. 
*/
enum TPtiErrorCorrectionLevel
    {
    EPtiErrorCorrectionLevelOff  = 0,
    EPtiErrorCorrectionLevelLow  = 1,
    EPtiErrorCorrectionLevelHigh = 2
    };


/**
* Key enumerations for conventional (ITU-T) and qwerty keyboards.
* Constant names for qwerty keypad keys are named after scan code
* values of a device using English language keymappings. The
* actual character that will be inserted into editor buffer depends on
* keymappings of currently selected input language and may be something else
* than what enum name suggests. For example
* non-shifted EPtiKeyQwertyHash produces '#'-character if input language is
* English, but will produce '+'-character if
* input language is Danish, Norwegian, Swedish or Finnish.
* The key coordinates on standard 4x12 qwerty keypad are given in
* comments.
*/
enum TPtiKey
    {
    EPtiKeyNone = 0,
    
    EPtiKey1    = '1',
    EPtiKey2    = '2',
    EPtiKey3    = '3',
    EPtiKey4    = '4',
    EPtiKey5    = '5',
    EPtiKey6    = '6',
    EPtiKey7    = '7',
    EPtiKey8    = '8',
    EPtiKey9    = '9',
    EPtiKeyStar = '*',
    EPtiKey0    = '0',
    EPtiKeyHash = '#',

    // alternate names
    EPtiKeyPunct = EPtiKey1,
    EPtiKeyABC   = EPtiKey2,
    EPtiKeyDEF   = EPtiKey3,
    EPtiKeyGHI   = EPtiKey4,
    EPtiKeyJKL   = EPtiKey5,
    EPtiKeyMNO   = EPtiKey6,
    EPtiKeyPQRS  = EPtiKey7,
    EPtiKeyTUV   = EPtiKey8,
    EPtiKeyWXYZ  = EPtiKey9,

    // qwerty keys
    EPtiKeyQwerty1     = 0x31,   
    EPtiKeyQwerty2     = 0x32,   
    EPtiKeyQwerty3     = 0x33,   
    EPtiKeyQwerty4     = 0x34,   
    EPtiKeyQwerty5     = 0x35,   
    EPtiKeyQwerty6     = 0x36,   
    EPtiKeyQwerty7     = 0x37,   
    EPtiKeyQwerty8     = 0x38,   
    EPtiKeyQwerty9     = 0x39,   
    EPtiKeyQwerty0     = 0x30,   

    EPtiKeyQwertyPlus        = 0x2b,                    
    EPtiKeyQwertyMinus       = EStdKeyMinus,            
    EPtiKeyQwertyComma       = EStdKeyComma,            
    EPtiKeyQwertySemicolon   = EStdKeySemiColon,        
    EPtiKeyQwertyFullstop    = EStdKeyFullStop,         
    EPtiKeyQwertyHash        = EStdKeyHash,             
    EPtiKeyQwertySlash       = EStdKeyForwardSlash,     
    EPtiKeyQwertyApostrophe  = EStdKeySingleQuote,      
    EPtiKeyQwertySpace       = EStdKeySpace,  
    EPtiKeyQwertyAtCharacter = EStdKeySquareBracketRight,
    EPtiKeyQwertyLeftShift   = EStdKeyLeftShift,           // Needed only for special cases.

    EPtiKeyQwertyA = 0x41,     
    EPtiKeyQwertyB = 0x42,     
    EPtiKeyQwertyC = 0x43,     
    EPtiKeyQwertyD = 0x44,     
    EPtiKeyQwertyE = 0x45,     
    EPtiKeyQwertyF = 0x46,     
    EPtiKeyQwertyG = 0x47,     
    EPtiKeyQwertyH = 0x48,     
    EPtiKeyQwertyI = 0x49,      
    EPtiKeyQwertyJ = 0x4a,      
    EPtiKeyQwertyK = 0x4b,      
    EPtiKeyQwertyL = 0x4c,     
    EPtiKeyQwertyM = 0x4d,     
    EPtiKeyQwertyN = 0x4e,     
    EPtiKeyQwertyO = 0x4f,      
    EPtiKeyQwertyP = 0x50,     
    EPtiKeyQwertyQ = 0x51,      
    EPtiKeyQwertyR = 0x52,     
    EPtiKeyQwertyS = 0x53,     
    EPtiKeyQwertyT = 0x54,      
    EPtiKeyQwertyU = 0x55,     
    EPtiKeyQwertyV = 0x56,     
    EPtiKeyQwertyW = 0x57,     
    EPtiKeyQwertyX = 0x58,       
    EPtiKeyQwertyY = 0x59,     
    EPtiKeyQwertyZ = 0x5a      
    
    // ----> Half Qwerty
    , EPtiKeyQwertyChr = EStdKeyLeftFunc 	// key (4, 4) 
    // Half Qwerty <----
    };



/**
* Enumerations for PtiCore capabilities. These can be queries through
* MPtiCoreInfo::CapsBits(). 
* Here are descriptions:
*
* EWordCompletion
*      The core object supports word completion -feature.
*
* EReordering
*      The core object supports user dictionary reordering. This feature means that
*      most commonly used words are moved up in prediction candidate
*      list.
*
* ENextWordPrediction
*      The core supports next word prediction feature. When this feature is
*      enabled, prediction engine tries to guess next word based on previous word(s).
*
* ESupportUserDictionaries
*      The core supports supports user dictionaries. 
*
* ESupportSCTToneMarks
*        
* ESupportCangjieInput 
*      The core object supports Chinese CangJie input.
*
* ESupportDualLanguage
*      The core object supports dual language preditcion.
* 
* ESupportAutoSubstitution
*      The core object supports auto-substitution feature. This feature
*      automatically expands predefined string to longer string.
*      ie. "l8r" -> "later"
*/
enum TPtiEngineCapsBits
    {
    EWordCompletion          = 0x01,
    EReordering              = 0x02,
    ENextWordPrediction      = 0x04,
    ESupportUserDictionaries = 0x08,
    ESupportSCTToneMarks     = 0x10,
    ESupportCangjieInput     = 0x20,
    EPreferedSpelling        = 0x40,
    ESupportDualLanguage     = 0x80,
    ESupportAutoSubstitution = 0x100
    };


/**
* Text case defintions.
*/
enum TPtiTextCase
    {
    EPtiCaseLower = 0,    // Normal lower case input
    EPtiCaseUpper,        // Normal upper case input.
    EPtiCaseChrLower,     // Qwerty chr-key lower case input.
    EPtiCaseChrUpper,     // Qwerty chr-key upper case input.
    EPtiCaseFnLower,      // Qwerty fn-key lower case input.    
    EPtiCaseFnUpper,       // Qwerty fn-key upper case input.
    EPtiCaseMax
    };


enum TPtiCharConversion
    {
    EPtiSimplifiedToComplex = 0x01,  // Chinese simplified to Chinese complex
    EPtiUcs2ToUtf8 = 0x02,           // Unicode to utf8
    EPtiUcs2ToBig5 = 0x04,           // Unicode to big5
    EPtiUcs2ToGB = 0x08,             // Unicode to Guo-Biao 
    EPtiUtf8ToUcs2 = 0x10,           // Utf8 to Unicode
    EPtiKo2ToWc = 0x20,              // KSC5601 to Hangul Syllable
    EPtiWcToKo2 = 0x30,              // Hangul Syllable to KSC5601
    EPtiBig5ToUcs2 = 0x40,           // Big5 to Unicode
    EPtiComplexToSimplified = 0x80   // Chinese complex to Chinese simplified
    };

/**
* Enumerates supported spelling types for CPtiEngine::GetSpelling method.
*/
enum TPtiSpelling   
    {
    EPtiStrokes  = 0x01,
    EPtiPinyin   = 0x02,
    EPtiBopomofo = 0x04,
    EPtiZhuyin   = 0x08,
    EPtiCangJie  = 0x16,
    EPtiEasyCangjie = 0x20,
    EPtiAdvCangjie = 0x40
    };

/**
* Enumerates different Chinese variants.
*/
enum TPtiChineseVariant
    {
    EPtiChineseVariantPrc = 0,
    EPtiChineseVariantHk, 
    EPtiChineseVariantTw 
    };

/**
* Command definitions for CPtiEngine::HandleCommandL api methods. Many of these
* are for internal communication between PtiEngine framework and a specific
* core object and there for not documented.
*/
enum TPtiEngineCommand
    {
    EPtiCommandNone,
    EPtiCommandUserActionLeft,
    EPtiCommandUserActionRight,
    EPtiCommandUserActionConvert,
    EPtiCommandUserActionPrevious,
    EPtiCommandUserActionLengthen,
    EPtiCommandUserActionShorten,
    EPtiCommandUserActionCancel,
    EPtiCommandUserActionComplete,
    EPtiCommandUserActionAllComplete,
    EPtiCommandUserActionGetCurrentIndexOfCandidates,
    EPtiCommandUserActionCompleteCandidate,
    EPtiCommandUserActionCompleteFull0,
    EPtiCommandUserActionCompleteFull1,
    EPtiCommandUserActionCompleteFull2,
    EPtiCommandUserActionCompleteFull3,
    EPtiCommandUserActionCompleteFull4,
    EPtiCommandUserActionCompleteFull5,
    EPtiCommandUserActionCompleteFull6,
    EPtiCommandUserActionCompleteFull7,
    EPtiCommandUserActionCompleteFull8,
    EPtiCommandUserActionCompleteFull9,
    EPtiCommandUserActionCompleteHalf0,
    EPtiCommandUserActionCompleteHalf1,
    EPtiCommandUserActionCompleteHalf2,
    EPtiCommandUserActionCompleteHalf3,
    EPtiCommandUserActionCompleteHalf4,
    EPtiCommandUserActionCompleteHalf5,
    EPtiCommandUserActionCompleteHalf6,
    EPtiCommandUserActionCompleteHalf7,
    EPtiCommandUserActionCompleteHalf8,
    EPtiCommandUserActionCompleteHalf9,
    EPtiCommandEnableToneMarks,
    EPtiCommandDisableToneMarks,
    EPtiCommandResetToneMark,
    EPtiCommandIncrementToneMark,
    EPtiCommandIncrementToneMarkOverrideInvalid,
    EPtiCommandReloadLearningInfo,
    EPtiCommandUserDictionaryDelaySaving,
    EPtiCommandUserDictionarySaveNow,
    EPtiCommandUserActionSetCurrentIndexOfCandidates,  
    EPtiCommandUseLatinDefaultKeyMap,       
    EPtiCommandUseLatinCaseUpperOnlyKeyMap, 
    EPtiCommandUseLatinCaseLowerOnlyKeyMap,
	  EPtiCommandResetLearningInfo,
	  EPtiCommandPollQwertyDeadKeyRootFlag,       // Indicates that dead key root char was added to buffer.
	  EPtiCommandGetAndClearDeadKeyRootChar,
	  EPtiCommandDeadKeyWaiting,
	  EPtiCommandQueryAndClearGetAllFlag,
	  EPtiCommandGetAndClearVowelSequence,			 
    EPtiCommandSetMultitapTimer,                // Set multitap timer for japanese varint only
    EPtiCommandVowelSeqFlag,
    EPtiCommandClearVowelSeq,
    EPtiCommandSetJapaneseQwertyFlags,          // Set Japanese Qwerty flags for japanese varint only
    EPtiCommandGetAndClearLastVietnameseChar,
    EPtiCommandSetVietnameseLastChar,
    EPtiCommandQueryReplacePrevious,  
    EPtiCommandSetLastKeyForVietnamese,
    EPtiCommandResetVietnameseVowelSeqAndToneMark,
    EPtiCommandGetVietnameseLastKey,
    EPtiCommandDoubleWideEntry,
    EPtiCommandSetClearFunction,                // Set the behavior of clear key for japanese varint only
    EPtiCommandUserActionRetroActiveCandidateHalf,
    EPtiCommandUserActionRetroActiveCandidateFull,
    EPtiCommandUserActionRetroActiveClear,
    EPtiCommandUserActionRetroActiveCommit,
    EPtiCommandAppendCharacter,          // Append a character for Japanese varint only
    EPtiCommandBackSpaceByForce,          // BackSpace by force for Japanese varint only
    EPtiCommandGetPhoneticText,
    EPtiCommandClearPhoneticBuffer,
    EPtiCommandBreakSyllable,
    EPtiCommandAllowPictographCandidate,    // Allow the candidates with pictograph cahracter for Japanese variant only
    EPtiCommandLoopback,  // Loop back input character (Loop back: c->b->a)
    EPtiCommandSetAutoSubstitution,
    EPtiCommandAddAutoSubstEntry,           // TPtiAutoSubstBinding passed in aParams.
    EPtiCommandDeleteAutoSubstEntry,        // TPtiAutoSubstBinding passed in aParams.
    EPtiCommandNumberOfAutoSubstEntries,
    EPtiCommandGetAutoSubstEntry,           // TPtiAutoSubstBinding passed in aParams.
    EPtiCommandFindAutoSubstEntry,          // TPtiAutoSubstBinding* passed in aParams.   
    EPtiCommandUncommitWord,
    EPtiCommandEnableAutoCompletion,
    EPtiCommandDisableAutoCompletion,
    EPtiCommandSetCorrectionLevel,          // TErrorCorrectionLevel* passed in aParams.
    EPtiCommandGetAutoCompletionTailLength, // TInt* passed in aParams for output.
    EPtiCommandLockCurrentCandidate,
    EPtiCommandSetProactiveCorrection,      // TBool passed in aParams
    EPtiCommandIsExactKnownWord,
    EPtiCommandSetAutoCompletion,
	EPtiCommandSetNumberCandidateStatus,    // 
    EPtiCommandSetAutoCompletionMaxLength,  // Param is integer. Sets maximum lenght of ato completed word. Zero == no limit.
    EPtiCommandMarkAutoCapitalized,          // No parameters.
    EPtiCommandUserActionGetIndexOfSecondaryCandidate, // index of secondary candidate, TInt* passed in param
    EPtiCommandAddPhrase,                   // Add new phrase for next word prediction. const TDesC* passed in param. 
    EPtiCommandSetSecondaryInputLanguage,
    EPtiCommandSetFlagToUpdateCandidates,
    EPtiCommandSetCursorCrossedMaxLength,   // sets when cursor crosses max words length in editor
    EPtiCommandResetCursorCrossedMaxLength,
    EPtiCommandUserActionSetIndexOfActiveCandidate,
    EPtiCommandAddWordToUDBWithoutPunctMark,
    EPtiCommandGetSecondaryCandidate,   
    EPtiCommandAutoCompletionOnToOff        //to signify that autocompletion is set from on to off in between typing  
    };

/**
* A convinience class for auto substitution related EPtiCommands. Needed
* only in core object and framework code.
*/ 
class TPtiAutoSubstBinding
    {
    public:    
        TInt iIndex;
        TBuf<KMaxAutoSubstStringLength> iShortcut;
        TBuf<KMaxAutoSubstStringLength> iSubstitution;    
    };


/**
* A structure for binding language name and language code.
* only in core object and framework code.
*/ 
class TPtiLangName
    {
    public:
        TInt iLanguageCode;
        TBuf<KMaxLanguageNameLength> iName;
    };


/**
* This is language code for 'numeric' language.
* It is langugae object which is always available and
* has only numeric input mode.
*/
#define ELangNumeric 0x5000

/**
* An interface class for accessing core info attributes.
*/
class MPtiCoreInfo 
    {
    public: 
    	/**	
    	* Returns a boolean value indicating whether the word completion
    	* feature is supported by the core object in question
    	* 
    	* @since S60 V2.6
    	* @return ETrue if core object supports word completion feature.
    	*         EFalse otherwise.
    	*/
        virtual TBool WordCompletion() const = 0;
        
        /**
        * Returns a boolean value indicating whether the user dictionary 
        * re-ordering feature is supported by the core object in question.
        *
        * @since S60 V2.6
        * @return ETrue if core object supports re-ordering feature.
        *         EFalse otherwise.
        */
        virtual TBool Reordering() const = 0;
        
        /**
        * Returns maximum length of single word this core object is able to produce.
        * 
        * @since S60 V2.6
        * @return The maximum word length.
        */
        virtual TInt MaximumWordLength() const = 0;
        
        /**
        * Returns the maximum number of prediction candidates the core object
        * is able to produce for any input sequence. Doesn't apply for
        * Chinese and Japanese modes.
        *
        * @since S60 V2.6
        * @return The maximum number of candidates.
        */
        virtual TInt MaximumNumberOfCandidates() const = 0;
        
        /**
        * Returns a boolean value indicating whether the next word prediction feature
        * supported by the core object in question.
        *
        * @since S60 V2.6
        * @return ETrue if next wrod prediction is supported.
        *         EFalse otherwise.
        */
        virtual TBool NextWordPrediction() const = 0;
        
        /**
        * Returns core object vendor specific id string.
        *
        * @since S60 V2.6
        * @return Vendor specific id string.  
        */
        virtual TPtrC VendorString() const = 0;
        
        /**
        * Returns a bit vector containing flags for various core object features.
        * See TPtiEngineCapsBits for list of specified bits. 
        *
        * @since S60 V2.6
        * @return A bit vector containing flags for various core object features.
        */
        virtual TUint32 CapsBits() const = 0;
        
        /**
        * Returns uid value for core object.
        * 
        * @since S60 V2.6
        * @return Core object uid as an integer value.
        */
        virtual TInt32 Uid() const = 0;
        
        /**
        * Returns a bitvector containing flags for available character conversion
        * methods. See TPtiCharConversion for list of specified bits.
        *
        * @since S60 V2.6
        * @return A bit vector containing flags for available character conversions.
        */
        virtual TUint32 CharConversions() const = 0;
        
 		/**
        * Returns a bitvector containing flags for available spelling conversion
        * methods. See TPtiSpelling for list of specified bits.
        *
        * @since S60 V2.6
        * @return A bit vector containing flags for available spelling conversions.
        */        
        virtual TUint32 Spellings() const = 0;
    };


class TPtiCoreInfo : public MPtiCoreInfo
    {
    public:
        inline TBool WordCompletion() const;
        inline TBool Reordering() const;
        inline TInt MaximumWordLength() const;
        inline TInt MaximumNumberOfCandidates() const;
        inline TBool NextWordPrediction() const;
        inline TPtrC VendorString() const;
        inline TInt32 Uid() const;
        inline TUint32 CharConversions() const;
        inline TUint32 Spellings() const;

        inline TUint32 CapsBits() const;
        inline void SetCapsBits(TUint32 aBits);
        inline void SetVendorString(const TDesC& aStr);
        inline void SetMaxWordLength(TInt aMaxLen);
        inline void SetUid(TInt32 aUid);
        inline void SetSpellings(TUint32 aSpellings);
        inline void SetMaxNumberOfCandidates(TInt aMax);
        inline void SetCharConversions(TUint32 aConvs);

	private:
		TUint32 iCapsBits;
		TPtrC iVendorIdStr;
		TInt iMaxWordLength;
		TInt iMaxNumberOfCandidates;
		TInt32 iUid;
		TUint32 iCharConversions;
		TUint32 iSpellings;
	};


#define KPtiEngineChineseSeparator 0x0027

// Tone marks for pinyin input
enum
    {
    KPtiPinyinTone0 = 0x02C9,
    KPtiPinyinTone1 = 0x02CA,
    KPtiPinyinTone2 = 0x02C7,
    KPtiPinyinTone3 = 0x02CB,
    KPtiPinyinTone4 = 0x02D9
    };

// Tone marks for zhuyin input
enum
    {
    KPtiZhuyinTone0 = 0x0020,
    KPtiZhuyinTone1 = 0x02CA,
    KPtiZhuyinTone2 = 0x02C7,
    KPtiZhuyinTone3 = 0x02CB,
    KPtiZhuyinTone4 = 0x02D9
    };


class TPtiNumericKeyBinding
	{
	public:
		TUint16 iChar;	
		TPtiKey iKey;
		TPtiTextCase iCase;		
	};


// type definition for HWR
typedef struct TRecognitionRangeTag
    {
    TLanguage iLanguage;
    TUint     iSubRange;
    } TRecognitionRange;


enum TRecognitionSubRanges
    {
    EPtiRangePRCChinese,
    EPtiRangeHKChinese,
    EPtiRangeTWChinese,
    EPtiRangeLatin,
    EPtiRangeSymbol,
    EPtiRangeNumber,
    EPtiRangeNative, // native text of a language, EPtiRangeLatin also belong to it
    EPtiRangeHiraganaKanji,
    EPtiRangeKatakana,
    EPtiRangeFullWidthKatakana,
    EPtiRangeFullWidthEnglish,
    EPtiRangeFullWidthNumeric,
    EPtiRangeHiraganaOnly,
    EPtiRangeNativeNumber,
    EPtiRangeNone
    };
    
    
enum TLatinLetterOrder
    {
    EUpperFirst,
    ELowerFirst	
    };
       
/*
* List of supported keyboard types. Each of these keyboard types
* may have own data block in keyboard data file. 
*/        
enum TPtiKeyboardType
    {
    EPtiKeyboardNone,
     
    /**
    * Conventional 12 phone keypad
    */
    EPtiKeyboard12Key,     
    
    /**
    * 4x12 Qwerty keyboard.
    */
    EPtiKeyboardQwerty4x12,
    
    /**
    * 4x10 Qwerty keyboard.
    */
    EPtiKeyboardQwerty4x10, 

    /**
    * 3x11 Qwerty keyboard.
    */
    EPtiKeyboardQwerty3x11, 
    
    /**
    * Half qwerty.
    */    
    EPtiKeyboardHalfQwerty,
    
    /** 
    * Custom qwerty keyboard.
    * Bound to [KEYBOARD BLOCK QWERTY CUSTOM] in keymapping
    * definition files. 
    */           
    EPtiKeyboardCustomQwerty,
    
    EPtiKeyboardMaxLayout
    };    

#include "PtiDefs.inl"

#endif // _PTI_DEFS_H

// End od file
