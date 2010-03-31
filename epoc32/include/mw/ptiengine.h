/*
* Copyright (c) 2003-2008 Nokia Corporation and/or its subsidiary(-ies). 
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
* Description:               Predective text input engine API header
*
*/















#ifndef _PTI_ENGINE_H
#define _PTI_ENGINE_H

// INCLUDES
#include <e32base.h>
#include <badesca.h> 
#include "PtiDefs.h"
#include "PtiObserver.h"
#include "PtiLanguage.h"

// FORWARD DECLARATIONS
class CPtiUserDictionary;
class MPtiUserDictionary;
class MPtiEngineCompositionDataInterface;
class MPtiUserDictionaryEntry;
class CPtiEngineImpl;
class MPtiHwrRecognizer;

/**
* CPtiEngine class. 
*
* This is the main client side API for PtiEngine. The purpose of PtiEngine API is
* to provide a single calling point for low level (below UI) text input functionality.
* The API provides methods for querying and activating installed input languages, changing 
* input modes and text cases and performing text input operations. The API contains 
* set of methods for latin based, Chinese and Japanese text input. Some of the methods
* are common to all of those variants. PtiEngine also provides access to predictive
* text input functionality, in case there is need to use it directly without
* standard CEikEdwin / FEP chain (hence the name 'predictive text input engine')
* Predictive text engine integration is hidden behind PtiCore plugin API and is used
* through PtiEngine main API. 
*
*  Usage:
*          PtiEngine is created by calling CPtiEngine::NewL method. In typical use case
*          there is no need to pass core uid parameter to NewL method.
*          Constructor will load and set up available core objects.
*
*  Typical use cases:
* 
*     Entering text in latin multitapping mode
*     ----------------------------------------
* 
*                 CPtiEngine* aEngine = CPtiEngine::NewL(); 
*                 aEngine->ActivateLanguageL(ELangEnglish, EPtiEngineMultitapping);
*                 aEngine->AppendKeyPress(EPtiKey3);
*                 aEngine->AppendKeyPress(EPtiKey6);
*                 aEngine->AppendKeyPress(EPtiKey6);
*                 aEngine->AppendKeyPress(EPtiKey6);
*                 aEngine->AppendKeyPress(EPtiKey4);
*                 TBuf<100> temp;
*                 temp.Copy(aEngine->CurrentWord());  // At this point temp would contain 
*                                                     // word "dog".
*
*     Entering text in latin predictive mode 
*     --------------------------------------
*
*                 CPtiEngine* aEngine = CPtiEngine::NewL(); 
*                 aEngine->ActivateLanguageL(ELangEnglish, EPtiEnginePredicitve);
*                 aEngine->AppendKeyPress(EPtiKey8);
*                 aEngine->AppendKeyPress(EPtiKey4);
*                 aEngine->AppendKeyPress(EPtiKey4);
*                 aEngine->AppendKeyPress(EPtiKey7);
*                 TBuf<100> temp;
*                 temp.Copy(aEngine->CurrentWord());   // At this point temp would contain 
*                                                      // (depending on the underlying engine)
*                                                      // word "this".
*                 temp.Copy(aEngine->NextCandidate()); // Move on to next candidate.
*                 aEngine->CommitCurrentWord();        // Tell engine that current word was accepted,
*                                                      // so that the underlyinbg engine keeps
*                                                      // frequency information up-to-date.   
*     Entering text in latin qwerty mode
*     ----------------------------------
*
*                 CPtiEngine* aEngine = CPtiEngine::NewL(); 
*                 aEngine->ActivateLanguageL(ELangEnglish, EPtiEngineQwerty);
*                 aEngine->AppendKeyPress(EPtiKeyQwertyQ);
*                 aEngine->AppendKeyPress(EPtiKeyQwertyW);
*                 aEngine->AppendKeyPress(EPtiKeyQwertyE);
*                 aEngine->AppendKeyPress(EPtiKeyQwertyR);
*                 aEngine->AppendKeyPress(EPtiKeyQwertyT);
*                 aEngine->AppendKeyPress(EPtiKeyQwertyY);
*                 TBuf<100> temp;
*                 temp.Copy(aEngine->CurrentWord());  // At this point temp would contain 
*                                                     // word "qwerty".
*                 // Next line requires that French key mappings are available in device.				 		
*                 aEngine->ActivateLanguageL(ELangFrench, EPtiEngineQwerty);
*                 aEngine->SetCase(EPtiCaseUpper);
*                 aEngine->ClearCurrentWord();
*                 aEngine->AppendKeyPress(EPtiKeyQwertyQ);
*                 aEngine->AppendKeyPress(EPtiKeyQwertyW);
*                 aEngine->AppendKeyPress(EPtiKeyQwertyE);
*                 aEngine->AppendKeyPress(EPtiKeyQwertyR);
*                 aEngine->AppendKeyPress(EPtiKeyQwertyT);
*                 aEngine->AppendKeyPress(EPtiKeyQwertyY);
*                 temp.Copy(aEngine->CurrentWord());  // At this point temp would contain 
*                                                     // word "AZERTY".
*   
*     Entering text in preditcive latin qwerty mode
*     ---------------------------------------------
*                 CPtiEngine* aEngine = CPtiEngine::NewL(); 
*                 aEngine->ActivateLanguageL(ELangEnglish, EPtiEngineQwertyPredictive);
*                 aEngine->AppendKeyPress(EPtiKeyQwertyE);
*                 aEngine->AppendKeyPress(EPtiKeyQwertyN);
*                 aEngine->AppendKeyPress(EPtiKeyQwertyT);
*                 aEngine->AppendKeyPress(EPtiKeyQwertyE);
*                 aEngine->AppendKeyPress(EPtiKeyQwertyR);
*                 aEngine->AppendKeyPress(EPtiKeyQwertyT);
*                 aEngine->AppendKeyPress(EPtiKeyQwertyA);
*                 TBuf<100> temp;
*                 temp.Copy(aEngine->CurrentWord());  // At this point temp would contain 
*                                                     // for example word "entertainment", assuming the.
*                                                     // underlying prediction engine supports word completion.
*               
*/
NONSHARABLE_CLASS(CPtiEngine) : public CBase
    {
    public:
        /**
        * Two phase constructor.
        *
        * @param  aUseDefaultUserDictionary
        * @return 
        */
        IMPORT_C static CPtiEngine* NewL(TBool aUseDefaultUserDictionary = EFalse);

        /**
        * Two phase constructor.
        *
        * NOTE: THIS METHOD IS DEPRECATED AND WILL LEAVE WHEN CALLED.        
        */
        IMPORT_C static CPtiEngine* NewL(const TDesC& aCoreName, TBool aUseDefaultUserDictionary = EFalse);

        /**
        * Two phase constructor.
        *
        * @param  aCoreUid
        * @param  aUseDefaultUserDictionary
        * @return 
        */
        IMPORT_C static CPtiEngine* NewL(const TUid aCoreUid, TBool aUseDefaultUserDictionary = EFalse);

        /**
        * Destructor.
        */
        IMPORT_C ~CPtiEngine();

        /**
        * Activates language in requested input mode. After calling this method
        * language is ready to be used with all input modes it supports.
        *
        * @since S60 V2.6                
        * @param  aEpocLanguageID    Language to be activated.
        * @param  aMode              Input mode after activation. If thise is left to default
        *                             value, then default input mode is activated.
        * @return KErrNone if success or system wide error code.
        */
        IMPORT_C TInt ActivateLanguageL(TInt aEpocLanguageID, TPtiEngineInputMode aMode = EPtiEngineInputModeNone);

        /**
        * Closes active language. After calling this method there
        * won't be active language and most PtiEngine API methods
        * will return error until ActivateLanguageL is called again. 
        * Core objects for active language are asked to release
        * related resources.
        *
        * @since S60 V2.6                
        */
        IMPORT_C void CloseCurrentLanguageL();
        
        /**
        * Returns core info structure for given input mode.  
        * 
        * @since S60 V2.6                
        * @return  Pointer to core info object.
        *          NULL if core for given input mode was not found.   
        */
        IMPORT_C MPtiCoreInfo* CoreInfo(TPtiEngineInputMode aMode) const;

        /**
        * Returns pointer to currently active language.
        *
        * @since S60 V2.6                
        * @return Pointer to currently active language object.
        */
        IMPORT_C MPtiLanguage* CurrentLanguage();

        /**
        * Returns pointer to requested language. 
        *
        * @since S60 V2.6                
        * @param   aCode  Language code for requested language.
        * @return  Pointer to requested language object.
        *          NULL if no language for given code. 
        */
        IMPORT_C MPtiLanguage* GetLanguage(TInt aCode) const;

        /**
        * Returns number of candidate words for current
        * input sequence. 
        *
        * @since S60 V2.6                
        * @return number of cadidate words.
        */
        IMPORT_C TInt NumberOfCandidates();

        /**
        * This method handles key press and forwards it to
        * correct core object depending on active language and 
        * input mode. The current word buffer is updated accordingly. 
        * If input sequence buffer has reached its maximum length
        * then nothing will be done.
        *
        * @since S60 V2.6                
        * @param aKey    Key code.
        * @return        Pointer to current word buffer.
        */
        IMPORT_C TPtrC AppendKeyPress(TPtiKey aKey);

        /**
        * Deletes last character in current word buffer and updates
        * candidate list accordingly.
        *
        * @since S60 V2.6                
        * @return        Pointer to current word buffer.
        */
        IMPORT_C TPtrC DeleteKeyPress();

        /**
        * DEPRECATED (will leave if called). 
        */
        IMPORT_C TInt AddCoreL(const TDesC& aFileName, TBool aUseDefaultUserDictionary = EFalse);

        /**
        * Loads and constructs new core object. Core object is added
        * to the list of available cores and is ready to be used
        * after that.
        *
        * @since S60 V2.6                
        * @param aCoreUid   Uid for core plugin.
        * @param aUseDefaultUserDictionary  ....
        * @return KErrNone  if operation was successful or system
        *                   wide error code. 
        */
        IMPORT_C TInt AddCoreL(const TUid aCoreUid, TBool aUseDefaultUserDictionary = EFalse);

        /**
        * Returns list of candidate words for current input sequence. 
        * If word completion feature is on, then words accepted to
        * result list may contain more letters than the number 
        * of key presses in current input sequence.
        * 
        * @since S60 V2.6                
        * @param  aList  a list to be filled with candidate words.
        * @return KErrNone if success, otherwise system wide error
        *                  code.
        */ 
        IMPORT_C TInt GetCandidateListL(CDesCArray& aList);

        /**
        * Returns next word candidate list. This method requires that
        * current core object supports next word prediction feature
        * and it is turned on.
        *
        * @since S60 V2.6                
        * @param aList  A List to be filled with next word cadidates.
        * @return       KErrNone if list was successfully filled.
        *               KErrNotSupported if current predictive core doesn't
        *                                support next word prediction or
        *                                the feature is not turned on.
        */
        IMPORT_C TInt GetNextWordCandidateListL(CDesCArray& aList);

        /**
        * Returns pointer to first word in candidate list.
        * If there isn't any candidate words the returned pointer
        * will point to empty descriptor.
        *
        * @since S60 V2.6                
        * @return  Pointer to first word in candidate list.
        */
        IMPORT_C TPtrC FirstCandidate();        

        /**
        * Returns pointer to next word in candidate list.
        * FirstCandidate() must be called before calling
        * this method. Returns pointer to empty descriptor if there 
        * isn't more candidates available.
        *
        * @since S60 V2.6                
        * @return Pointer to next word in candidate list.
        */
        IMPORT_C TPtrC NextCandidate();

        /**
        * Returns pointer to previous word in candidate list.
        * If there isn't previous candidate available 
        * (NextCandidate() wasn't succesfully called) then the
        * return value will point to an empty string.
        *
        * @since S60 V2.6                
        * @return Pointer to previous word in candidate list.
        */
        IMPORT_C TPtrC PreviousCandidate();

        /**
        * Activates requested input mode for active language. 
        *
        * @since S60 V2.6                
        * @param    aMode             requested input mode.
        * @return   KErrNone          if input mode was activated.
        *           KErrNotSupported  if current language doesn't
        *                             support requested input mode. 
        */
        IMPORT_C TInt SetInputMode(TPtiEngineInputMode aMode);

        /**
        * Returns active input mode.
        *
        * @since S60 V2.6                
        * @return   Current input mode. 
        */
        IMPORT_C TPtiEngineInputMode InputMode() const;

        /**
        * Turns reordering feature on or off. This method can be used only
        * if active core object supports reordering feature.
        * It is also possible that core object supports reordering feature,
        * but it can't be turned off. Reordeing feature keeps track
        * of usage frequency for entered words and promotes most frequently
        * used words in the candidate list. Details depend on underlying
        * prediction engine.
        *
        * @since S60 V2.6                
        * @param  aStatus  New status for reordering feature.
        * @return KErrNone if success, otherwise an error code.
        */
        IMPORT_C TInt SetReordering(TBool aStatus);

        /**
        * Fills text buffer with given word, refreshes
        * current input sequence and asks current core object
        * to update candidate list accordingly.
        *
        * @since S60 V2.6                
        * @param  aWord a word to be set as current word.
        * @return KErrNone if success, otherwise system wide error code.
        */
        IMPORT_C TInt SetCurrentWord(TPtrC aWord);
        
        /**
        * Returns pointer to current word buffer.
        *
        * @since S60 V2.6                
        * @return  Pointer to current word buffer.
        */
        IMPORT_C TPtrC CurrentWord();

        /**
        * Clears current word buffer. Calling this method means
        * that current word was reject and will not be part of edited 
        * text. Either this method or CommitCurrentWord() must be called
        * before starting a new word.
        *
        * @since S60 V2.6                
        */
        IMPORT_C void ClearCurrentWord();

        /**
        * Sets text case. 
        *
        * @since S60 V2.6                
        * @param aCase   Text case to be set. Possible values are:
        *
        *   EPtiCaseLower     Normal lower text case             
        *   EPtiCaseUpper     Normal capitalized text case 
        *   EPtiCaseChrLower  Lower text case when Chr key is being held
        *   EPtiCaseChrUpper  Upper text case when Chr key is being held
        *   EPtiCaseFnLower   Lower text case when Fn key is being held
        *   EPtiCaseFnUpper   Upper text case when Fn key is being held
        */
        IMPORT_C void SetCase(TPtiTextCase aCase);

        /**
        * Returns active text case.
        *
        * @since S60 V2.6                
        * @return    Current text case.
        */
        IMPORT_C TPtiTextCase Case() const;
        
        /**
        * Returns list of available input languages.
        *
        * @since S60 V2.6                
        * @param aResult  List to be filled with language codes.
        */  
        IMPORT_C void GetAvailableLanguagesL(CArrayFix<TInt>* aResult);
                
        /**
        * Returns list of available input languages.
        *
        * @since S60 V2.6                
        * @param aResult  List to be filled with language codes.
        */  
        IMPORT_C void GetAvailableLanguagesL(RArray<TInt>& aResult);
        
        /**
        * Returns number of available input languages.
        *
        * @since S60 V2.6                
        * @return  Number of available languages.
        */
        IMPORT_C TInt NumberOfLanguages() const;

        /**
        * Creates new user dictionary file, inserts given list of 
        * words into it and attaches it to active core
        * object for requested input mode. Active language must
        * support requested input mode.
        *
        * @since S60 V2.6                
        * @param   aFileName File name for new user dictionary.
        * @param   aWords    A list of words to be inserted to new
        *                    user dictionary. 
        * @param   aMode     Input mode for core object.
        * @return  KErrNone  if success, otherwise system wide error 
        *                    code.
        */
        IMPORT_C TInt CreateUserDictionaryL(TDesC& aFileName, CDesCArrayFlat* aWords, TPtiEngineInputMode aMode); 

        /**
        * Attach user dictionary in given file to core for requested
        * input mode.  
        * 
        * @since S60 V2.6                
        * @param   aFileName  User dictionary file name.         
        * @return  Pointer to user dictionary object. NULL if failure.
        */
        IMPORT_C MPtiUserDictionary* AttachUserDictionaryL(TDesC& aFileName);
        
        /**
        * Attach default user dictionary.  
        * 
        * @since S60 V2.6                
        * @param   aCoreUid  Uid for owner core object.      
        * @param   aSymbolClass Symbol class for udb data.
        * @return  Pointer to user dictionary object. NULL if failure.
        */
        IMPORT_C MPtiUserDictionary* AttachDefaultUserDictionaryL(TUid aCoreUid, TInt aSymbolClass);        

        /**
        * Detaches currently attached user dictionary.
        *
        * @since S60 V2.6                
        * @param   aFileName    User dictionary file name.
        * @return  KErrNone if success, otherwise system wide error code.
        */
        IMPORT_C TInt DetachUserDictionary(TDesC& aFileName);

        /**
        * Detaches currently attached user dictionary.
        *
        * @since S60 V2.6                
        * @param   aId      User dictionary id.
        * @return  KErrNone if success, otherwise system wide error code.
        */
        IMPORT_C TInt DetachUserDictionary(TInt aId);

        /**
        * Returns localized language name for given language. This method
        * is quite inefficient (always reads name table from resource file),
        * when possible use Getlanguage()->LocalizedName() instead.
        * This method can be used also when requested language is
        * not among available input languages.
        *
        * @since S60 V2.6                
        * @param   Epoc language code.
        * @return  Localized language name.
        */
        IMPORT_C void GetLocalizedLanguageName(TInt aLangCode, TDes& aResult);

        /**
        * Commits current word. Commiting means that core object is isntructed
        * to end inline editing operation and accepted active word as part of edited 
        * text. Core object may then update frequency information, add unrecognized
        * word to user dictioary or perform any other operation related to commiting a word.
        * Word buffer is cleared. Either this method or ClearCurrentWord() must
        * be called before starting a new word.
        *
        * @since S60 V2.6                
        * @return KErrNone             if success.
        *         KErrNoActiveLanguage if no active language.
        */
        IMPORT_C TInt CommitCurrentWord();

        /**
        * Converts given string of characters to one coding
        * system to another. See definition of TPtiCharConversion
        * for list of supported conversion types. It is possible
        * that only a small subset of supported conversion types
        * is actually available at run time (that depends on
        * available core objects). AvailableCharConversions()
        * method can be used for querying available conversion
        * types before using this method. 
        *
        * @since S60 V2.6                
        * @param aType         Requested conversion type. 
        * @param aInput        Input string. This parameter may point to
        *                      either 8-bit or 16-bit data depending
        *                      on conversion type.
        * @param aInputLength  Number of characters in input string.
        * @param aOutput       Output string. This parameter may pint to
        *                      either 8-bit or 16-bit data depending
        *                      on conversion type.
        */
        IMPORT_C TInt CharConversion(TPtiCharConversion aType,
                                     TAny* aInput,
                                     TInt aInputLength,
                                     TAny* aOutput);

        /**
        * Returns value indicating currently available 
        * character conversions. 
        *
        * @since S60 V2.6                
        * @return Currently available character conversions. There
        *         is a bit set for each available char conversion. 
        *         See definition of TPtiCharConversion.
        */
        IMPORT_C TUint32 AvailableCharConversions() const;

        /**
        * Replaces key map for single key. 
        *
        * @since S60 V2.6                
        * @param  aMode   Input mode of key map.
        * @param  aKey    Key to be replaced.
        * @param  aKeyMap New key sequence for aKey.
        * @return KErrNone if success, otherwise system wide error code.
        */
        IMPORT_C TInt SetExternalKeyMapL(TPtiEngineInputMode aMode,
                                         TPtiKey aKey,
                                         TDesC& aKeyMap,
                                         TPtiTextCase aCase);

        /**
        * Returns last entered key press.
        *
        * @since S60 V2.6                
        * @return last entered key press.
        */
        IMPORT_C TPtiKey LastEnteredKey() const;

        /**
        * Returns current input sequence (a list of key presses).
        * Bytes in returned descriptor are TPtiKey enum values.
        *
        * @since S60 V2.6                
        * @return  a descriptor containing current input sequence.
        */
        IMPORT_C TPtrC8 CurrentInputSequence() const;

        /**
        * Returns alternate spelling for given character.
        *
        * @since S60 V2.6                
        * @param  aInput  a character to be converted to requested spelling.
        * @param  aOutput output will be stored to this descriptor.
        * @param  aType   spelling type
        * @return KErrNone if operation was successful,
        *         KErrNotSupported if requested spelling type is not supported. 
        */
        IMPORT_C TInt GetSpelling(TUint16 aInput, TDes& aOutput, TPtiSpelling aType);

        /**
        * Front end processeor uses this method for indicating 
        * PtiEngine that all key press related timers should be
        * canceled.
        *
        * @since S60 V2.6                
        * @return  KErrNone      if timers were successfully canceled.
        *          KErrNotFound  if no active timers were found.
        */
        IMPORT_C TInt CancelTimerActivity();

        /**
        * Returns key for given character. Returned key
        * depends on current language and input mode.
        *
        * @since S60 V2.6                
        * @param aChar  Requested character.
        * @return Key for requested character. EPtiKeyNone if
        *         no key was found for given character.
        */
        IMPORT_C TPtiKey CharacterToKey(TUint16 aChar);

        /**
        * Adds new entry (in most cases a word) to default user dictionary of
        * currently active core object.
        *
        * @since S60 V2.6                
        * @param  aEntry  An entry to be added to dictionary.
        * @return KErrNone if success, otherwise system wide error code.
        */
        IMPORT_C TInt AddUserDictionaryEntry(MPtiUserDictionaryEntry& aEntry);

        /**
        * Adds entry to specific user dictionary.
        *
        * @since S60 V2.6                
        * @param aEntry  An entry to be added to dictionary.
        * @param aId    User dictionary id.
        * @return       KErrNone if success, otherwise system wide error code.
        */
        IMPORT_C TInt AddUserDictionaryEntry(MPtiUserDictionaryEntry& aEntry, TInt aId);

        /**
        * Removes entry from default user dictionary of currently active core
        * object.
        *
        * @since S60 V2.6                
        * @param  aEntry  an entry to be removed from default dictionary.
        * @return KErrNone if success, otherwise system wide error code.
        */
        IMPORT_C TInt RemoveEntryFromUserDictionary(MPtiUserDictionaryEntry& aEntry);

        /**
        * Removes word from specific user dictionary.
        *
        * @since S60 V2.6                
        * @param aEntry  an entry to be removed from default dictionary.
        * @param aId    User dictionary id.
        * @return       KErrNone if success, otherwise system wide error code.
        */
        IMPORT_C TInt RemoveEntryFromUserDictionary(MPtiUserDictionaryEntry& aEntry, TInt aId);

        /**
        * Returns number of entries in default user dictionary.
        * 
        * @since S60 V2.6                
        * @return Number of entries in default user dictionary.
        *         KErrNotSupported if core can't return requested value.     
        */
        IMPORT_C TInt NumberOfEntriesInUserDictionary();

        /**
        * Returns entry for given index in default user dictionary.
        *
        * @since S60 V2.6                
        * @param  aIndex  An index for requested entry.
        * @param  aResult Result will be stored here.
        * @return KErrNone if success, otherwise system wide error code.
        */
        IMPORT_C TInt GetUserDictionaryEntry(TInt aIndex, MPtiUserDictionaryEntry& aResult);

        /**
        * Returns default user dictionary for given input mode.
        *
        * @since S60 V2.6                
        * @return User dictionary for given input mode.
        *         NULL if wasn't found.  
        */  
        IMPORT_C MPtiUserDictionary* DefaultUserDictionary(TPtiEngineInputMode aMode);

        /**
        * Sets observer. See PtiObserver.h for observer API details.
        *
        * @since S60 V2.6                        
        * @param aObserver A observer to be set.
        */
        IMPORT_C void SetObserver(MPtiObserver* aObserver);

        /**
        * Returns current observer.
        *
        * @since S60 V2.6                
        * @return Pointer to current observer object.
        */
        IMPORT_C MPtiObserver* Observer();

        /**
        * General command handling method. This method can be used for 
        * controlling core objects that require more information than
        * just sequence of key presses. 
        *
        * @since S60 V2.6                
        * @param  aCommand    A command to be handled. 
        * @param  aParams     Possible input data or parameters for command.
        * @return KErrNone    if success, otherwise an error code. 
        */
        IMPORT_C TInt HandleCommandL(TPtiEngineCommand aCommand, TAny* aParams = NULL);

        /**
        * Returns pointer to current Chinese candidate page.
        *
        * @since S60 V2.6                        
        * @return Pointer to current Chinese candidate page.
        */
        IMPORT_C TPtrC CandidatePage();

        /**
        * Changes to next Chinese candidate page.
        *
        * @since S60 V2.6                
        * @return ETrue  if success.
        *         EFalse if there are no more candidate pages.
        */
        IMPORT_C TBool NextCandidatePage();

        /**
        * Changes to previous Chinese candidate page.
        *
        * @since S60 V2.6                
        * @return ETrue  if success.
        *         EFalse if current candidate page is first.
        */
        IMPORT_C TBool PreviousCandidatePage();

        /**
        * Returns a boolean value indicating whether there are more
        * candidate pages available.
        *
        * @since S60 V2.6                
        * @return ETrue  if there are more candidate pages available.
        *         EFalse otherwise.
        */
        IMPORT_C TBool MoreCandidatePages();

        /**
        * Sets length of Chinese candidate page.
        *
        * @since S60 V2.6                
        * @param aLength Length of Chinese candidate page.
        */
        IMPORT_C void SetCandidatePageLength(TInt aLength);

        /**
        * Returns phonetic spelling for current input.
        * 
        * @since S60 V2.6                
        * @param aIndex  Index of requested phonetic spelling.
        * @return Pointer to phonetic spelling.
        */
        IMPORT_C TPtrC GetPhoneticSpelling(TInt aIndex) const; 

        /**
        * Returns a value specifying how many phonetic spellings
        * there is available for current input.
        * 
        * @since S60 V2.6                        
        * @return Number of phonetic spellings available for
        *         current input.
        */
        IMPORT_C TInt PhoneticSpellingCount() const;    

        /**
        * Selects given phonetic spelling for current input.
        * 
        * @since S60 V2.6                
        * @param aIndex Index of requested phonetic spelling.
        */
        IMPORT_C TBool SelectPhoneticSpelling(TInt aIndex);

        /**
        * Returns the index of currently selected phonetic spelling.
        *
        * @since S60 V2.6                        
        * @return The index of currently selected phonetic spelling.
        *         Returned value is negative if there isn't phonetic
        *         spelling available.
        */
        IMPORT_C TInt SelectedPhoneticSpelling() const; 

        /**
        * Enables or disables tone marks.
        *
        * @since S60 V2.6                
        * @param aValue A boolean value specifying whether tone marks
        *               will be on or off.
        */
        IMPORT_C void EnableToneMarks(TBool aValue);

        /**
        * Resets tone mark.
        *
        * @since S60 V2.6                
        */      
        IMPORT_C void ResetToneMark();

        /**
        * Returns unicode value for current tone mark.
        * 
        * @since S60 V2.6                
        * @param  aToneMark resulting tone mark is store here.
        * @return ETrue if tone mark was available.
        *         EFalse otherwise.
        */
        IMPORT_C TBool ToneMark(TText& aToneMark) const;

        /**
        * Returns boolean value indicating whether current tone mark
        * is valid for spelling.
        *
        * @since S60 V2.6                
        * @return ETrue   if tone mark is valid for spelling.
        *         EFalse  otherwise
        */
        IMPORT_C TBool IsToneMarkValidForSpelling() const;

        /**
        * Cycles to next tone mark in core related tone mark list.
        * 
        * @since S60 V2.6                
        * @param aOverrideInvalid Indicates whether invalid tone marks
        *                         should be skipped.
        * @return ETrue  If new tone mark was found and set.
        *         EFalse Otherwise.
        */
        IMPORT_C TBool IncrementToneMark(TBool aOverrideInvalid);

        /**
        * Selects Chinese character (meaning that user has accepted character to be
        * inserted into editor). Predictive candidate lists will be updated with
        * Chinese characters associated to selected character. Associated charcaters
        * can be accessed via ...CandidatePage() -methods. Return value can be
        * ignored in current implementation.
        *
        * @since S60 V2.6                                
        * @param aChar A character to be selected.
        * @return Please ignore the return value. 
        */
        IMPORT_C TBool SetPredictiveChineseChar(const TDesC& aChar);

        /**
        * Returns pointer to composition data interface (used with Japanese input).
        *
        * @since S60 V2.6                
        * @return Pointer to composition data interface.
        */
        IMPORT_C MPtiEngineCompositionDataInterface* CompositionData();

        /**
        * Returns reading text for Japanese input.
        * 
        * @since S60 V2.6                
        * @return Reading text for Japanese input.
        */
        IMPORT_C TPtrC ReadingTextL();

        /**
        * Returns mode name index table for given Chinese variant.
        *
        * @since S60 V2.6                
        * @param aVariant Chinese variant to be queried.
        * @param aResult  Resulting index table. 
        */
        IMPORT_C void GetModeNameIndexL(TPtiChineseVariant aVariant, RArray<TInt>& aResult);

        /**
        * Fills list with all the phonetic spellings for current
        * input sequence.
        *
        * @since S60 V2.6                
        * @param aList  A descriptor list to be filled with 
        *               phonetic spellings. Any previous items in aList are cleared.
        * @return       Number of items in list.
        */
        IMPORT_C TInt GetPhoneticSpellingsL(CDesCArray& aList);

        /**
        * Fills list with phrase candidates for currently
        * selected phonetic spelling.
        *
        * @since S60 V2.6        
        * @param aList  A descriptor list to be filled with 
        *               phrase candidates. Any previous items in aList are cleared.
        * @return       Number of items in list.
        */
        IMPORT_C TInt GetChinesePhraseCandidatesL(CDesCArray& aList);

        /**
        * Sets tone mark directly. This method is used if client wants
        * to override default core dependant tone mark set or traditional 
        * cycle-through tone mark system doesn't suit its porposes.
        *
        * @since S60 V2.8
        * @param aToneMark  Tone mark to be set.
        * @return ETrue     if tone mark was legal, ie. produced candidates.
        *         EFalse    otherwise.          
        */
        IMPORT_C TBool SetToneMark(TInt aToneMark);
                           
        /**
        * A convinience method for cheking qwerty based input mode.
        *
        * @since S60 V3.0
        * @param aMode  Input mode to be checked.
        * @return ETrue If aMode is qwerty based input mode.
        *         EFalse Otherwise. 
        */      
        IMPORT_C TBool IsQwertyBasedMode(TPtiEngineInputMode aMode) const;
        
        /**
        * Creates empty user default dictionary file for given core object
        * and initializes it to PtiEngine user dictionary format. If file already
        * exists, then this method does nothing. Normally this method is 
        * only used by core objects.
        *
        * @since S60 V3.0        
        * @param aCoreUid     Uid for requesting core object. 
        * @param aSymbolClass Symbol class for udb data.
        */
        IMPORT_C void CreateDefaultUserDictionaryFileL(TUid aCoreUid, TInt aSymbolClass);
        
        /**
        * Creates secondary data file for given core object. Existing file will be overwritten.
        * This data file may contain any additional data that the core object needs to store
        * between sessions (for example used word dictionary, if the engine keeps reordering data in
        * separate memory area).
        *
        * @since S60 V3.0        
        * @param aCoreUid     Uid number for requesting core object.
        * @param aIndexNumber Index number. Core object may use this parameter for numerating data files
        *                     if it needs more than one of then. Otherwise zero.  
        */
        IMPORT_C void WriteSecondaryDataFileL(TUid aCoreUid, TInt aIndexNumber, HBufC8* aData);
        
        /**
        * Returns a heap buffer containing data from given secondary data file. 
        * Returns null if file is not found.
        *
        * @since S60 V3.0        
        * @param aCoreUid     Uid number for requesting core object.
        * @param aIndexNumber Index number (see CreateDefaultUserDictionaryFileL).
        * @return A heap buffer conataining requested data. 
        *         NULL if file not found. 
        */
        IMPORT_C HBufC8* ReadSecondaryDataFileL(TUid aCoreUid, TInt aIndexNumber);
        
        /**
        * Returns keymapping data for given key. Returned data depends on active
        * language and input mode. Result string will be empty if there isn't 
        * key mapping adta available.
        *
        * @since S60 V3.0
        * @param aKey     A key to be queried.
        * @param aResult  Resulting mapping data.
        */      
        IMPORT_C void MappingDataForKey(TPtiKey aKey, TDes& aResult, TPtiTextCase aCase);
                        
		/**
		* Qwerty input mode has different keymapping layout for each language. Therefore
		* the characters for numeric input mode may be mapped to different keys depending
		* on language. There are several situations where client application needs to know
		* which key and case combination produce numeric characters for given language. 
		* This convinience method can be used for extracting that information easily
		* (it is also possible to achieve same result directly via CPtiCoreLanguage object).
		* Result array will be left empty if requested language is not available or it doesn't
		* support qwerty input mode. 
		* Returned list includes key bindings for characters: "0123456789pw+#*"
		* (Not necessarily in this order).
		* See also ExtendedNumericModeKeysForQwertyL.
		*
		* This version first tries to return mappings according to currently
		* active physical keyboard. It current keyboard is not qwerty based,
		* it searches data for the first qwerty based keyboard type it can find.
		* That is done in same order as keyboard types are defined in PtiDefs.h.
		* There is also another version this method, which gets keyboard type as a
		* parameter.
		*
		* @since S60 V3.1
		* @param aLanguage Language id for requested mappings.
		* @param aResult   Array for storing resulting mappings.		 
		*/                                             
		IMPORT_C void GetNumericModeKeysForQwertyL(TInt aLanguage, RArray<TPtiNumericKeyBinding>& aResult);                        
		
        IMPORT_C HBufC* GetCandidatesByInputString(const TDesC& aInputString, 
                                                         RPointerArray<HBufC>& aList, 
                                                         const TBool aIsPredictive);		
        /**
        * Get first hwr implementation support the specified language
        *
        * @since S60 V4.0
        * @param aLanguage The language that hwr implementation supported
        * @return The pointer points to hwr implementation instance
        */      
        IMPORT_C MPtiHwrRecognizer* GetHwrRecognizerL(TLanguage aLanguage);
		
        /**
        * Get hwr implementation by give implementation uid
        *
        * @since S60 V4.0
        * @param aImpId Given specific implementation uid
        * @return The pointer points to hwr implementation instance
        */      
        IMPORT_C MPtiHwrRecognizer* GetHwrRecognizerL(TInt aImpId);
		
        /**
        * Get hwr implementation uid list which support given language
        *  
        * @since S60 V4.0
        * @param aLanguage The language that hwr implementation supported
        * @return The array of implementation uid list
        */      
        IMPORT_C RArray<TUid>& ListHwrRecognizerL(TLanguage aLanguage);

        /**
        * Get hwr available languages list
        *
        * @since S60 V4.0
        * @param aResult Carry the hwr available languages list on return
        * @return None
        */      
        IMPORT_C void GetHwrAvailableLanguagesL(RArray<TInt>& aResult);
        
        /**
        * Returns a list containing keyboard type values for all available 
        * physical keyboards connected to the device. Keyboard doesn't have to be
        * active at calling time to be included in the output list.
        *
        * @since S60 V5.0
        * @param aResult An array to be filled with available keyboard types.                                     
        */                                                                             
        IMPORT_C static void ListAvailablePhysicalKeyboardsL(RArray<TPtiKeyboardType>& aResult);        
        
        /**
        * This method is same as GetNumericModeKeysForQwertyL, expect that instead of returning
        * strict list of key bindings used in phone number editor, it returns list of all
        * possible characters used in any of the "number only" editor variations. 
   	    * Returned list includes key bindings for characters: "*+pw#1234567890;.,-E?/"
   	    * (Not necessarily in this order).
	    * See also GetNumericModeKeysForQwertyL. 
       	*
        * This version first tries to return mappings according to currently
        * active physical keyboard. It current keyboard is not qwerty based,
        * it searches data for the first qwerty based keyboard type it can find.
        * That is done in same order as keyboard types are defined in PtiDefs.h.
        * There is also another version this method, which gets keyboard type as a
        * parameter.
        *
        * @since S60 V3.2
  	    * @param aLanguage Language id for requested mappings.
        * @param aResult   Array for storing resulting mappings.
        */
        IMPORT_C const RArray<TPtiNumericKeyBinding>& ExtendedNumericModeKeysForQwertyL(TInt aLanguage);
    
        /**
        * Turns auto substitution feature on or off. Auto substitution
        * feature replaces predefined strings with other strings. For example,
        * if user types xmas, it could be auto substituted with Christmas.
        *
        * @since S60 V5.0
        * @param aStatus New status for auto substituiton feature
        * @return KErrNone or system wide error code.
        */      
        IMPORT_C TInt SetAutoSubstitution(TBool aStatus);
     
        /**
        * Adds new auto substitution entry to database. If entry for given shorcut
        * already exists, then the old entry will be automatically deleted.
        *
        * @since S60 V5.0     
        * @param aShortcut Shortcut part for new entry.
        * @param aSubstitution Substitution part for new entry.
        * @return KErrNone or system wide error code.              
        */
        IMPORT_C TInt AddAutoSubstitutionEntry(const TDesC& aShortcut,
                                               const TDesC& aSubstituition);
     
        /**
        * Remove auto substitution entry.
        *
        * @since S60 V5.0               
        * @param aShortcut Shortcut for auto substitution entry to be removed.
        * @return KErrNone or system wide error code.
        *         KErrNotFound if given shortcut was nout found.              
        */          
        IMPORT_C TInt DeleteAutoSubstitutionEntry(const TDesC& aShortcut);
     
        /**
        * Returns the number of auto substitution entries in auto subst db.
        *
        * @since S60 V5.0     
        * @return Number of entries in auto substitution db. Zero if the
        *         feature is not supported or is not activated.         
        */                    
        IMPORT_C TInt NumberOfAutoSubstitutionEntries() const;
     
        /**
        * Return auto substitution entry for given index.
        *
        * @since S60 V5.0     
        * @param aIndex Index for entry to be returned.
        * @param aShortcut Shortcut part of the result entry will be stored here.
        * @param aSubstitution Substitution part of result entry will be stored here.
        * @return KErrNone or system wide error code.
        */
        IMPORT_C TInt GetAutoSubstitutionEntry(TInt aIndex, TDes& aShortcut,
                                               TDes& aSubstitution);
        /**
        * Returns currently selected qwerty keyboard type. 
        *
        * @since S60 V5.0
        * @return Currently selected keyboard type.
        */                                                                                       
        IMPORT_C TPtiKeyboardType KeyboardType() const;
     
        /**
        * Sets keyboard type for non-virtual keyboard. Keyboard type specifies which
        * set of key mapping data is used. 
        *
        * @since S60 V5.0
        * @param aType New keyboard type.
        * @return KErrNone if successful
        *         KErrNotSupported if currently selected language/input mode combination
        *                          does not allow given keyboard type, or mapping
        *                          data doesn't contain block for it.
        */                                           
        IMPORT_C TInt SetKeyboardType(TPtiKeyboardType aType);     
     
        /**
        * Lists keyboard blocks available in keymapping data for given language.
        *
        * @since S60 V5.0
        * @param aLanguage  A language to be queried.
        * @param aResult    Resulting list of keyboard types will we stored here.
        */
        IMPORT_C void KeyboardTypesSupportedByLanguageL(TInt aLanguage,
                                                     RArray<TPtiKeyboardType>& aResult);                                                     
        /**
        * Same as previous version of GetNumericModeKeysForQwertyL (see description above) but 
        * keyboard type is given as a parameter and mappings are return only for given keyboard
        * type.
        *
        * @since S60 V5.0
        * @param aLanguage Language id for requested mappings.
        * @param aResult   Array for storing resulting mappings.
        * @param aKeyboardType keyboard type.		 
        */                                                                                                  
        IMPORT_C void GetNumericModeKeysForQwertyL(TInt aLanguage,
 	                                               RArray<TPtiNumericKeyBinding>& aResult,
 	                                               TPtiKeyboardType aKeyboardType); 	                                                                                                                         
        /**
        * Same as previous version of ExtendedNumericModeKeysForQwertyL (see description above), but
        * keyboard type is given as a parameter and mappings are return only for given keyboard
        * type.
        *
        * @since S60 V5.0
  	    * @param aLanguage Language id for requested mappings.
	    * @param aKeyboardType keyboard type.		   	 
	    * @param aResult   Array for storing resulting mappings.
        */
        IMPORT_C const RArray<TPtiNumericKeyBinding>& ExtendedNumericModeKeysForQwertyL(TInt aLanguage,
                                                                                     TPtiKeyboardType aKeyboardType);                                                                                                           		
                                                                                     
        /**
        * Sets a boolean value indicating whether number candidates are included to
        * predictive candidate list. Number candidates are strings containing only digits.
        * Number candidate feature must be supported by active prediction engine,
        * otherwise this setting will be ignored.
        *
        * @since S60 V5.0
  	    * @param aStatus  A boolean value indicating whether number candidates
  	    *                 are included to cadidate list.
	    * @return KErrNone or a system wide error code.
        */                                                                                                                                                                                            		                                                                                                                                
        IMPORT_C TInt SetNumberCandidateStatus(TBool aStatus);     

        /**
        * Returns a boolean value indicating whether given scan code is allowed for
        * current input mode. 
        *
        * @since S60 V5.0
  	    * @param aKey A key to be queried.
  	    * @return ETrue if given scan code is allowed fore currently active input mode.
  	    *         EFalse otherwise.
  	    */  
        IMPORT_C TBool IsValidKey(TPtiKey aKey) const;                                                                                                              

        /**
        * Sets the maximum length for auto completed words. This method can be used when the
        * client needs to be sure that all provided word completions will fit into remaining
        * editor buffer. When the number of key presses in an input sequence exceeds the value
        * given in aMaxLength, core will automatically reset this value to "no limit". 
        *
        * @since S60 V5.0
  	    * @param aMaxLength The maximum length fo auto completed candinates. 
        *                   Value 0 means no limit.
  	    * @return KErrNone If the operation succeeded.
        *         Otherwise system wide error code. 
  	    */  
        IMPORT_C TInt SetMaxLengthForAutoCompletedCandidates(TInt aMaxLength);
                
        /**
        * Some core objects may provide different set of results depending on whether
        * the auto captitalization feature was used for entering the word or not. There is
        * now way to tell on core level whether the word was auto-capitalizedby FEP or
        * capitalized normally by the user. This method can be used to incicate
        * core object that auto-capitalization was used for current input sequence.
        * Clearing or commiting the word will cancel the effect of this method.
        *    
        * @since S60 V5.0  
        */             
        IMPORT_C void MarkAutoCapitalized();    

        /**
        * Returns text case buffer. Case buffer contains shift state
        * for each key press used for producing active word, ie. it remembers
        * case values for each AppendKeyPress call. Case buffer is 
        * cleared when active word is commited or cleared. Return
        * value is TPtrC8 containing string of EPtiTextCase values.
        *
        * @since S60 V5.0
        * @return A string of EPtiTextCase values.
        */        
        IMPORT_C TPtrC8 CaseSequence();

        /**
        * Some prediction engines support next word prediction feature but
        * require database to be pre-filled with suitable phrase data.
        * This method adds one new phrase or sentence to phrase dictionary.
        * Active core object needs to support phrase based next word prediction,
        * otherwise an error code is returned. 
        *
        * @since S60 V5.0
        * @param aNewPhrase New phrase to be added to phrase dictionary.
        * @return KErrNone or system wide error code.
        */
        IMPORT_C TInt AddPhrase(const TDesC& aNewPhrase);
        
#ifdef FF_DUAL_LANGUAGE_SUPPORT
        /**
        * Activates specified secondary input language in current input mode.
        *
        * @since S60 V5.0
        * @param  aEpocLanguageID    Language to be activated.
        * @return KErrNone if success or system wide error code.
        */
        IMPORT_C TInt SetSecondaryInputL(TInt aEpocLanguageID);
#endif //FF_DUAL_LANGUAGE_SUPPORT
    private:
        CPtiEngine();
        void ConstructL(TBool aUseDefaultUserDictionary);
        void ConstructL(const TUid aCoreUid, TBool aUseDefaultUserDictionary);
    
    private:        
        CPtiEngineImpl* iImpl;
        };
               
#endif  _PTI_ENGINE_H

// End of file
