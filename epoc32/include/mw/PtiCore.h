/*
* Copyright (c) 2003-2005 Nokia Corporation and/or its subsidiary(-ies). 
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
* Description:               Predective text input engine core interface.
*
*/














#ifndef _PTI_CORE_H
#define _PTI_CORE_H

// INCLUDES
#include <badesca.h> 
#include "PtiDefs.h"
#include "PtiLanguage.h"
#include "PtiUserDictionary.h"

// FORWARD DECLARATIONS
class CPtiEngine;
class MPtiEngineCompositionDataInterface;
class MPtiUserDictionaryEntry;

// CONSTANTS
const TInt KDefaultCoresGran = 3;

/**
* This is abstract base class of all PtiEngine core objects. A PtiEngine core object implements set of
* input modes and input related services for a set of languages. This class defines core side
* PtiEngine API.
*/
class MPtiCore
	{
	//
	// General API
	//
	public:
		/**
		* Initialized core object. This method is called by PtiEngine framework when core object
		* is loaded.		
		*
		* @since 2.6
		* @param aOwner Pointer to onwing PtiEngine framework instance.
		* @param aTextBuffer A pointer to PtiEngine main text buffer.
		* @param aLanguageList A language list to be filled with language bindings to this core
		*                      onbject
		* @param aUseDefautUserDictionary A boolean value indicating whether default user dictionary shoulkd be used
		*                                 (in case this core object supports user dictionaries).
		*/	
		virtual void InitializeL(CPtiEngine* aOwner, TDes* aTextBuffer, CArrayPtrFlat<CPtiCoreLanguage>* aLanguageList, TBool aUseDefautUserDictionary) = 0;
		
		/**
		* Removes languages associated to this core object from given language list. Languages
		* not associated to this core abject are not touched.
		* 
		* @since 2.6
		* @param aLanguageList A language list to be cleaned.
		*/
		virtual void DropLanguages(CArrayPtrFlat<CPtiCoreLanguage>* aLanguageList) = 0;
		
		/**
		* Opens resources for given language and itinialized them.
		*
		* @since 2.6
		* @param aLanguage Symbian OS language code a language to be initialized.
		* @return KErrNone or a system wide error code.
		*/
		virtual TInt OpenLanguageL(CPtiCoreLanguage *aLanguage) = 0;
		
		/**
		* Closes currently activate language and frees resources associated to it.
		*
		* @since 2.6
		* @return KErrNone of system wide error ocde.
		*/
		virtual TInt CloseLanguageL() = 0;
		
		/**
		* Returns the contents of text buffer.
		* 
		* @since 2.6
		* @return A constant pointer to text buffer.
		*/	
		virtual TPtrC GetCurrentWord() const = 0;
		
		/**
		* Commits current word. Commiting means that user has added current
		* word as part of text. Frequency information and other related attributes
		* can then be updated.
		*
		* @since 2.6
		* @return KErrNone or a system wide error code.
		*/
		virtual TInt CommitCurrentWord() = 0;		
		
		/**
		* Returns a pointer core info structure. Core info struct contains useful 
		* information about core object and its features.
		*
		*/				
		virtual MPtiCoreInfo* GetCoreInfo() = 0;
				
		/**
		* Turns reoreding feature on or off. Reordering means that prediction engine
		* maintains frequency information for used words and modifys the order of candidate list
		* based on that information. This feature may not be supported by all prediction engines.
		* 
		* @since 2.6
		* @param aStatus New status for reorderinf feature.
		* @return KErrNone or a system wide error code.
		*/
		virtual TInt SetReordering(TBool aStatus) = 0;
		
		/**
		* This is the single most important core API method, most of the text input functionality
		* will be utilize this method. Call to this method indicates core object that a key was
		* pressed and it should act accordingly and fill the output buffer.
		* 
		* @since 2.6
		* @param aKey Enum value for pressed key.
		*/
		virtual void AppendKeyPress(TPtiKey aKey) = 0;
		
		/**
		* Indicates core object that it should perform 'delete key press'-operation.
		*
		* @since 2.6
		*/
		virtual void DeleteKeyPress() = 0;
		
		/**
		* Call to this method notifys core object that input buffer was cleared.
		*
		* @since 2.6
		*/
		virtual void ClearBuffer() = 0;
		
		/**
		* Sets current input sequence. The end result of this operation must be same as 
		* if user had entered keys in input array as individual key presses.
		*
		* @since 2.6
		* @param aInput An array containing sequence of key presses (type TPtiKey).
		* @return KErrNone or a system wide error code.
		*/
		virtual TInt SetCurrentInputSequence(TPtrC8 aInput) = 0;
		
		/**
		* Converts given string from one character set to another. Possible conversion types
		* are defined in PtiDefs.h
		*
		* @since 2.6
		* @param aType        Conversion type.
		* @param aInput       Pointer to input string to be converted.
		* @param aInputLength Length of input buffer.
		* @param aOutput      pointer to output buffer.
		* @return KErrNone or a system wide error code.
		*/
		virtual TInt Convert(TPtiCharConversion aType,
							 TAny* aInput,
							 TInt aInputLength,
							 TAny* aOutput) = 0;

		/**
		* Re-defines keymappings for given key / input mode / case combination. Previous 
		* keymapping will be deleted and new mappings will be used instead.
		*
		* @since 2.6
		* @param aMode Input mode for new key mapping.
		* @param aKey  A key to be replaced.
		* @param aKeyMap New keymapping data for aKey.
		* @param aCase   Text case to be replaced.
		* @return KErrNone or system wide error code.
		*/
		virtual TInt SetExternalKeyMapL(TPtiEngineInputMode aMode,
			                            TPtiKey aKey,
									    TDesC& aKeyMap,
										TPtiTextCase aCase) = 0;
		/**
		* Returns alternate spelling for given unicode characters. Possible conversion
		* types are defined in header PtiDefs.h.
		*										
		* @sinec 2.6
		* @aInput A character to be converted.
		* @aOutput Resulting alternate spelling will be stored here.
		* @aType   Spelling conversion type.
		* @return  KErrNone or system wide error code.
		*/								
		virtual TInt GetSpelling(TUint16 aInput, TDes& aOutput, TPtiSpelling aType) = 0;
		
		/**
		* Cancels all on-going core obejct timner activity.
		*
		* @since 2.6
		* @return KErrNone or system wide error code.
		*/
		virtual TInt CancelTimerActivity() = 0;
		
		/**
		* A generic command handling method for extending PtiEngine API without adding
		* new base class methods. It is recommended to use this only in force major
		* situations, where there is no other way.
		* 
		* @since 2.6
		* @param aCommand A Command id value. Platform wide command ids are defined in PtiDefs.h.
		* @param aParams  TAny pointer for passing any required parameters.
		* @return An integer containing possible return value related to command.
		*/
		virtual TInt HandleCommandL(TPtiEngineCommand aCommand, TAny* aParams) = 0;

	//
	// Predictive latin API
	//  
	public:    
	    /**
	    * Returns number of candidates for currently entered key sequence.
	    *
	    * @since 2.6
	    * @return Number of prediction candidates for currently entered key sequence.
	    */
		virtual TInt NumberOfCandidates() = 0;
		
		/**		
		* Returns a list of candidate words for currently entered key sequence.
		*
		* @since 2.6
		* @param aList A list to be filled with candidate words.
		* @return Number of candidate works in aList.
		*/
		virtual TInt GetCandidateListL(CDesCArray& aList) = 0;
		
		/**
		* Returns next word candidate list. Next word candidates are words
		* potentially related to currently selected candidate. Next word prediction
		* feature must supported by the engine and turned on.
		*
		* @since 2.6
		*/
		virtual TInt GetNextWordCandidateListL(CDesCArray& aList) = 0;
		
		/**
		* Returns first word in list of candidate words for current input sequence.
		* 
		* @since 2.6
		* @param aResult A descriptor where resulting word will be stored.
		* @return KErrnNone or system wide error code.
		*/		
		virtual TInt GetFirstCandidate(TDes& aResult) = 0;
		
		/**
		* Returns next word in list of candidate words for current input sequence.
		* 
		* @since 2.6
		* @param aResult A descriptor where resulting word will be stored.
		* @return KErrnNone or system wide error code.
		*/						
		virtual TInt GetNextCandidate(TDes& aResult) = 0;
		
		/**
		* Returns previous word in list of candidate words for current input sequence.
		* 
		* @since 2.6
		* @param aResult A descriptor where resulting word will be stored.
		* @return KErrnNone or system wide error code.
		*/								
		virtual TInt GetPreviousCandidate(TDes& aResult) = 0;
	
	//
	// User dictionary API
	//
	public:
		virtual TInt AddUserDictionaryEntry(MPtiUserDictionaryEntry& aEntry, CPtiUserDictionary* aDict) = 0;
		virtual TInt RemoveUserDictionaryEntry(MPtiUserDictionaryEntry& aEntry, CPtiUserDictionary* aDict) = 0;
        virtual TInt NumberOfEntriesInUserDictionary(CPtiUserDictionary* aDict) = 0;
		virtual TInt GetUserDictionaryEntry(TInt aIndex, MPtiUserDictionaryEntry& aResult, CPtiUserDictionary* aDict) = 0;
		virtual CPtiUserDictionary* CreateEmptyUserDictionaryL(TInt aMaxSize) = 0;
		virtual TInt AttachUserDictionary(CPtiUserDictionary* aDict) = 0;
		virtual TBool DetachUserDictionary(CPtiUserDictionary* aDict) = 0;		

	//
	// Chinese API
	//
	public:
		virtual TPtrC GetCandidatePage() = 0;
		virtual TBool NextCandidatePage() = 0;
		virtual TBool PreviousCandidatePage() = 0;
		virtual TBool MoreCandidatePages() = 0;
		virtual void SetCandidatePageLength(TInt aLength) = 0;
		virtual TPtrC GetPhoneticSpelling(TInt aIndex) const = 0; 
		virtual TInt PhoneticSpellingCount() const = 0;	
	    virtual TBool SelectPhoneticSpelling(TInt aIndex) = 0;
	    virtual TInt SelectedPhoneticSpelling() const = 0; 
		virtual TBool ToneMark(TText& aToneMark) const = 0;
		virtual TBool IsToneMarkValidForSpelling() = 0;
		virtual TBool SetPredictiveChineseChar(const TDesC& aChar) = 0;
		virtual TBool SetToneMark(TInt aToneMark) = 0;


   	//
	// Japanese API
	//
	public:
		virtual TPtrC ReadingTextL() = 0;
		virtual MPtiEngineCompositionDataInterface* CompositionData() = 0;

	//
	// Chinese API
	//
	public:
	        virtual HBufC* GetCandidatesByInputString(const TDesC& aInputString, 
                                                        RPointerArray<HBufC>& aList, 
                                                        const TBool aIsPredictive) = 0;
	};
	

/**
* This class is a base class implementation for MPtiCore. It contains empty base implemenations
* for core API methods and static methods for creating and listing PtiEngine core objects.
*/
class CPtiCore : public CBase, public MPtiCore
	{
	//
	// Plugin household methods
	//
	public:
 		/**
		* Creates in instance of core object for given implemenation uid.
		*
		* @param aCoreUid An ecom implementation uid for core object to be created.
		* @return Pointer to new core object instance.
		*/
		IMPORT_C static CPtiCore* CreateCoreL(TUid aCoreUid);
		
		/**
		* Lists all the available PtiEngine core onject implemenatations.
		*
		* @return Pointer to a list cantaining implementation uids for available core plugins.
		*/
		IMPORT_C static CArrayFix<TInt>* ListCoresLC();

	public: 
		IMPORT_C ~CPtiCore();

	//
	// 	General methods.
	//
	public:
		IMPORT_C TInt SetCurrentInputSequence(TPtrC8 aInput);
		IMPORT_C TInt Convert(TPtiCharConversion aType,
							  TAny* aInput,
							  TInt aInputLength,
							  TAny* aOutput);
		IMPORT_C TInt GetSpelling(TUint16 aInput,
			                      TDes& aOutput,
								  TPtiSpelling aType);
		IMPORT_C TInt SetExternalKeyMapL(TPtiEngineInputMode aMode,
			                             TPtiKey aKey,
									     TDesC& aKeyMap,
										 TPtiTextCase aCase);
		IMPORT_C TInt CommitCurrentWord();		
		IMPORT_C TPtrC GetCurrentWord() const;

	//
	// Predictive latin API
	//
	public:
		IMPORT_C TInt NumberOfCandidates();
		IMPORT_C TInt GetCandidateListL(CDesCArray& aList);
		IMPORT_C TInt GetNextWordCandidateListL(CDesCArray& aList);
		IMPORT_C TInt GetFirstCandidate(TDes& aResult);
		IMPORT_C TInt GetNextCandidate(TDes& aResult);
		IMPORT_C TInt GetPreviousCandidate(TDes& aResult);
	
	//
	// User dictionary API
	//
	public:
		IMPORT_C TInt AddUserDictionaryEntry(MPtiUserDictionaryEntry& aEntry, CPtiUserDictionary* aDict);
		IMPORT_C TInt RemoveUserDictionaryEntry(MPtiUserDictionaryEntry& aEntry, CPtiUserDictionary* aDict);
                IMPORT_C TInt NumberOfEntriesInUserDictionary(CPtiUserDictionary* aDict);
		IMPORT_C TInt GetUserDictionaryEntry(TInt aIndex, MPtiUserDictionaryEntry& aResult, CPtiUserDictionary* aDict);
		IMPORT_C CPtiUserDictionary* CreateEmptyUserDictionaryL(TInt aMaxSize);
		IMPORT_C TInt AttachUserDictionary(CPtiUserDictionary* aDict);
		IMPORT_C TBool DetachUserDictionary(CPtiUserDictionary* aDict);		

	//
	// Chinese API
	//
	public:
		IMPORT_C TPtrC GetCandidatePage();
		IMPORT_C TBool NextCandidatePage();
		IMPORT_C TBool PreviousCandidatePage();
		IMPORT_C TBool MoreCandidatePages();
		IMPORT_C void SetCandidatePageLength(TInt aLength);
		IMPORT_C TPtrC GetPhoneticSpelling(TInt aIndex) const; 
		IMPORT_C TInt PhoneticSpellingCount() const;	
	        IMPORT_C TBool SelectPhoneticSpelling(TInt aIndex);
	        IMPORT_C TInt SelectedPhoneticSpelling() const; 
		IMPORT_C TBool ToneMark(TText& aToneMark) const;
		IMPORT_C TBool IsToneMarkValidForSpelling();
		IMPORT_C TBool SetPredictiveChineseChar(const TDesC& aChar);
		IMPORT_C TBool SetToneMark(TInt aToneMark);
 
	//
	// Japanese API
	//
	public:
		IMPORT_C TPtrC ReadingTextL();
		IMPORT_C MPtiEngineCompositionDataInterface* CompositionData();

	//
	// Chinese API
	//			
	public:	
                IMPORT_C HBufC* GetCandidatesByInputString(const TDesC& aInputString, 
                                                         RPointerArray<HBufC>& aList, 
                                                         const TBool aIsPredictive);			

	private:
		inline void SetDestructorKeyId(TInt aDtorKeyId);

	private:
		TInt iDtorKeyId;
		TInt Reserved_1;
	};


inline void CPtiCore::SetDestructorKeyId(TInt aDtorKeyId)
	{
	iDtorKeyId = aDtorKeyId;
	}

#endif _PTI_CORE_H

// End of file


