/*
* Copyright (c) 2007 Nokia Corporation and/or its subsidiary(-ies). 
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
* Description:               Inline methods for PtiDefs.h files
*
*/















// ---------------------------------------------------------------------------
// PtiCoreInfo::WordCompletion
// 
// ---------------------------------------------------------------------------
//
inline TBool TPtiCoreInfo::WordCompletion() const
	{
	return ((iCapsBits & EWordCompletion) != 0);
	}

// ---------------------------------------------------------------------------
// PtiCoreInfo::Reordering
// 
// ---------------------------------------------------------------------------
//
inline TBool TPtiCoreInfo::Reordering() const
	{
	return ((iCapsBits & EReordering) != 0);
	}

// ---------------------------------------------------------------------------
// PtiCoreInfo::MaximumWordLength
// 
// ---------------------------------------------------------------------------
//
inline TInt TPtiCoreInfo::MaximumWordLength() const
	{
	return iMaxWordLength;  
	}

// ---------------------------------------------------------------------------
// PtiCoreInfo::NextWordPrediction
// 
// ---------------------------------------------------------------------------
//
inline TBool TPtiCoreInfo::NextWordPrediction() const
	{
	return ((iCapsBits & ENextWordPrediction) != 0);
	}

// ---------------------------------------------------------------------------
// PtiCoreInfo::VendorString
// 
// ---------------------------------------------------------------------------
//
inline TPtrC TPtiCoreInfo::VendorString() const
	{
	return iVendorIdStr;
	}

// ---------------------------------------------------------------------------
// PtiCoreInfo::CapsBits
// 
// ---------------------------------------------------------------------------
//
inline TUint32 TPtiCoreInfo::CapsBits() const
	{
	return iCapsBits;
	}

// ---------------------------------------------------------------------------
// PtiCoreInfo::SetCapsBits
// 
// ---------------------------------------------------------------------------
//
inline void TPtiCoreInfo::SetCapsBits(TUint32 aBits)
	{
	iCapsBits |= aBits;
	}

// ---------------------------------------------------------------------------
// PtiCoreInfo::SetVendorString
// 
// ---------------------------------------------------------------------------
//
inline void TPtiCoreInfo::SetVendorString(const TDesC& aStr)
	{
	iVendorIdStr.Set(aStr);
	}

// ---------------------------------------------------------------------------
// PtiCoreInfo::SetMaxWordLength
// 
// ---------------------------------------------------------------------------
//
inline void TPtiCoreInfo::SetMaxWordLength(TInt aMaxLen) 
	{
	iMaxWordLength = aMaxLen;
	}
	
// ---------------------------------------------------------------------------
// PtiCoreInfo::Uid
// 
// ---------------------------------------------------------------------------
//
inline TInt32 TPtiCoreInfo::Uid() const
	{
	return iUid;
	}

// ---------------------------------------------------------------------------
// PtiCoreInfo::SetUid
// 
// ---------------------------------------------------------------------------
//
inline void TPtiCoreInfo::SetUid(TInt32 aUid)
	{
	iUid = aUid;
	}

// ---------------------------------------------------------------------------
// PtiCoreInfo::MaximumNumberOfCandidates
// 
// ---------------------------------------------------------------------------
//	
inline TInt TPtiCoreInfo::MaximumNumberOfCandidates() const
	{
	return iMaxNumberOfCandidates;
	}

// ---------------------------------------------------------------------------
// PtiCoreInfo::SetMaxNumberOfCandidates
// 
// ---------------------------------------------------------------------------
//
inline void TPtiCoreInfo::SetMaxNumberOfCandidates(TInt aMax)
	{
	iMaxNumberOfCandidates = aMax;
	}

// ---------------------------------------------------------------------------
// PtiCoreInfo::CharConversions
// 
// ---------------------------------------------------------------------------
//
inline TUint32 TPtiCoreInfo::CharConversions() const
	{
	return iCharConversions;
	}

// ---------------------------------------------------------------------------
// PtiCoreInfo::SetCharConversions
// 
// ---------------------------------------------------------------------------
//
inline void TPtiCoreInfo::SetCharConversions(TUint32 aConvs)
	{
	iCharConversions = aConvs;
	}

// ---------------------------------------------------------------------------
// PtiCoreInfo::SetSpellings
// 
// ---------------------------------------------------------------------------
//
inline void TPtiCoreInfo::SetSpellings(TUint32 aSpellings)
	{
	iSpellings = aSpellings;
	}

// ---------------------------------------------------------------------------
// PtiCoreInfo::Spellings
// 
// ---------------------------------------------------------------------------
//
inline TUint32 TPtiCoreInfo::Spellings() const
	{
	return iSpellings;
	}

// End of file
