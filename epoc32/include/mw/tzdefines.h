// Copyright (c) 1997-2009 Nokia Corporation and/or its subsidiary(-ies).
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

#ifndef __TZDEFINES_H__
#define __TZDEFINES_H__

/** Time Zone Rule Day Rules.
@publishedAll
@released
*/
enum TTzRuleDay
	{
	ETzFixedDate			= 0,	// e.g. 11th October
	ETzDayAfterDate,				// e.g. first Sunday after 8th October
	ETzDayBeforeDate,				// e.g. Sunday before 7th October
	ETzDayInLastWeekOfMonth			// e.g. last Sunday in October
	};

/**
this const must match the last TTzRuleDay enumeration;
'int' is deliberately used because this file is shared with non Symbian C++ environments 
@internalComponent
*/
const int KValidatedLastDayRule = ETzDayInLastWeekOfMonth;

/** Time reference.
@publishedAll
@released
*/
enum TTzTimeReference
	{
	ETzUtcTimeReference	= 0,
	ETzStdTimeReference,
	ETzWallTimeReference	// Local time
	};

/**
this const must match the last TTzTimeReference enumeration 
'int' is deliberately used because this file is shared with non Symbian C++ environments 
@internalComponent
*/
const int KValidatedLastTimeReference = ETzWallTimeReference;
#endif
