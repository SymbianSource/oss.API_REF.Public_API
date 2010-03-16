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
* Description:               Inline methods for PtiLanguage class.
*
*/















// ---------------------------------------------------------------------------
// CPtiCoreLanguage::LanguageCode
// 
// ---------------------------------------------------------------------------
//
inline TInt CPtiCoreLanguage::LanguageCode() const
	{
	return iLanguageCode;
	}

// ---------------------------------------------------------------------------
// CPtiCoreLanguage::LocalizedName
// 
// ---------------------------------------------------------------------------
//
inline TPtrC CPtiCoreLanguage::LocalizedName() const
	{
	return TPtrC(iLocalizedName);
	}

// End of file
