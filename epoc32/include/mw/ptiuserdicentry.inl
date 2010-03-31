/*
* Copyright (c) 2003 Nokia Corporation and/or its subsidiary(-ies). 
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
* Description:               Inline methods for user dictionary interface.
*
*/















// ---------------------------------------------------------------------------
// CPtiUserDictionaryEntry::TPtiUserDictionaryEntry
// 
// ---------------------------------------------------------------------------
//
inline TPtiUserDictionaryEntry::TPtiUserDictionaryEntry()
	{
	}

// ---------------------------------------------------------------------------
// CPtiUserDictionaryEntry::TPtiUserDictionaryEntry
// 
// ---------------------------------------------------------------------------
//
inline TPtiUserDictionaryEntry::TPtiUserDictionaryEntry(const TDesC& aWord) : iEntry(aWord)
	{
	}

// ---------------------------------------------------------------------------
// CPtiUserDictionaryEntry::Word
// 
// ---------------------------------------------------------------------------
//
inline TPtrC TPtiUserDictionaryEntry::Word() const
	{
	return TPtrC(iEntry);
	}

// ---------------------------------------------------------------------------
// CPtiUserDictionaryEntry::Reading
// 
// ---------------------------------------------------------------------------
//
inline TPtrC TPtiUserDictionaryEntry::Reading() const
	{
	return TPtrC(iEntry);
	}

// ---------------------------------------------------------------------------
// CPtiUserDictionaryEntry::SetWord
// 
// ---------------------------------------------------------------------------
//
inline void TPtiUserDictionaryEntry::SetWord(TDesC& aWord, TDesC& /*aReading*/)
	{
	iEntry.Copy(aWord);
	}

// ---------------------------------------------------------------------------
// CPtiUserDictionaryEntry::SetWord
// 
// ---------------------------------------------------------------------------
//
inline void TPtiUserDictionaryEntry::SetWord(TDesC& aWord)
	{
	iEntry.Copy(aWord);
	}

// End of file
