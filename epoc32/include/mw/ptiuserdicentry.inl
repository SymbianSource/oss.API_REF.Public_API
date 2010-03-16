/*
* Copyright (c) 2003 Nokia Corporation and/or its subsidiary(-ies). 
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
