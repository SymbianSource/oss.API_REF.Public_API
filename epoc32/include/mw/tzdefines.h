// Copyright (c) 1997-2009 Nokia Corporation and/or its subsidiary(-ies).
// All rights reserved.
// This component and the accompanying materials are made available
// under the terms of "Eclipse Public License v1.0"
// which accompanies this distribution, and is available
// at the URL "http://www.eclipse.org/legal/epl-v10.html".
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
	}; //There is an internal dependency on the KValidatedLastDayRule constant which should be equal to the last TTzRuleDay enumeration.


/** Time reference.
@publishedAll
@released
*/
enum TTzTimeReference
	{
	ETzUtcTimeReference	= 0,
	ETzStdTimeReference,
	ETzWallTimeReference	// Local time
	}; //There is an internal dependency on the KValidatedLastTimeReference constant which should be equal to the last TTzTimeReference enumeration.

#endif
