/*
* Copyright (c) 2003-2007 Nokia Corporation and/or its subsidiary(-ies). 
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
* Description:               User dictionary interface
*
*/















#ifndef _PTI_USERDICENTRY_H
#define _PTI_USERDICENTRY_H

// INCLUDES
#include <e32base.h>

// CONSTANTS
const TInt KMaxUserDictionaryEntrySize = 100;

/**
* An interface class for accessing items in user dictionary.
*/
class MPtiUserDictionaryEntry
    {
    public:
        /**
        * Returns a pointer to the word held by this user dictionary entry.
        * 
        * @since S60 V2.6
        * @return A pointer to user dictionary word.
        */    
        virtual TPtrC Word() const = 0;
        
        /**
        * Returns a pointer to latin alphabet "reading" version for this user
        * dictionary entry. Needed for Japanese input.
        * 
        * @since S60 V2.6
        * @return A pointer to reading word
        */            
        virtual TPtrC Reading() const = 0;  // Needed for Japanese input.
        
        /**
        * Sets word for this user dictionary entry. This version also
        * sets reading text.
        *
        * @param aWord    A descriptor containing word to be set.
        * @param aReading A descriptor containing reading text for aWord.
        * @since S60 V2.6
        */            
        virtual void SetWord(TDesC& aWord, TDesC& aReading) = 0;
        
        /**
        * Sets word for this user dictionary entry. This version
        * sets reading text to same value as "word":
        *
        * @param aWord    A descriptor containing word to be set.        
        * @since S60 V2.6
        */            
		virtual void SetWord(TDesC& aWord) = 0;
    };


/**
* This is implementation of MPtiUserDictionaryEntry interface
* for latin languages (or any other language, which needs
* only one component (=word) for user dictionary entry).
* Implementation of Reading() method is same as implementation of
* Word() method.
*/
class TPtiUserDictionaryEntry : public MPtiUserDictionaryEntry
	{
	public:		
		inline TPtiUserDictionaryEntry();
		inline TPtiUserDictionaryEntry(const TDesC& aWord);

	    inline TPtrC Word() const;
        inline TPtrC Reading() const;
        inline void SetWord(TDesC& aWord, TDesC& aReading);
		inline void SetWord(TDesC& aWord);

	private:
		TBuf<KMaxUserDictionaryEntrySize> iEntry;
	};

#include "PtiUserDicEntry.inl"

#endif

// End of file
 
