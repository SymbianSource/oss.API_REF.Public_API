// Copyright (c) 2001-2009 Nokia Corporation and/or its subsidiary(-ies).
// All rights reserved.
// This component and the accompanying materials are made available
// under the terms of the License "Symbian Foundation License v1.0" to Symbian Foundation members and "Symbian Foundation End User License Agreement v1.0" to non-members
// which accompanies this distribution, and is available
// at the URL "http://www.symbianfoundation.org/legal/licencesv10.html".
//
// Initial Contributors:
// Nokia Corporation - initial contribution.
//
// Contributors:
//
// Description:
// 
// 
//



/**
 @file DelimitedParserCommon.h
 @publishedAll
 @released	
*/

#ifndef __DELIMITEDPARSERCOMMON_H__
#define __DELIMITEDPARSERCOMMON_H__

// System includes
//
#include <e32base.h>

/**
enum TDelimitedDataParseMode
Enum defining the modes for the delimited data parser.
@publishedAll
@released
@since			6.0	
*/
enum TDelimitedDataParseMode
	{
	/** 
		Unparsed soecifier 
	*/
	EDelimitedDataNotParsed = 0,
	/** 
		Specifier for parsing from left to right  
	*/
	EDelimitedDataForward,
	/** 
		Specifier for parsing from right to left  
	*/
	EDelimitedDataReverse
	};

#endif	// __DELIMITEDPARSERCOMMON_H__
