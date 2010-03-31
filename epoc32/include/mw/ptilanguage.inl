/*
* Copyright (c) 2003-2007 Nokia Corporation and/or its subsidiary(-ies). 
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
