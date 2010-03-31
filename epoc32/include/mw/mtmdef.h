// Copyright (c) 1998-2009 Nokia Corporation and/or its subsidiary(-ies).
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



/**
 @file
 @publishedAll
 @released
*/

#if !defined(__MTMDEF_H__)
#define __MTMDEF_H__
#if !defined(__MTCLBASE_H__)
#include <mtclbase.h>
#endif
#if !defined(__MTMDEF_HRH__)
#include <mtmdef.hrh>
#endif

// no matching message parts

const TMsvPartList KMsvMessagePartNone			= 0x00000000;
// message parts

// Message body 
const TMsvPartList KMsvMessagePartBody			= 0x00000001;

// Message recipients 

const TMsvPartList KMsvMessagePartRecipient		= 0x00000002;

// Message originator 

const TMsvPartList KMsvMessagePartOriginator	= 0x00000004;
// Message description 
const TMsvPartList KMsvMessagePartDescription	= 0x00000008;
// Message date 

const TMsvPartList KMsvMessagePartDate			= 0x00000010;
// Message attachments 

const TMsvPartList KMsvMessagePartAttachments	= 0x00000020;

// find attributes
//Flag to specify case-sensitive search. 

const TMsvPartList KMsvFindCaseSensitive		= 0x80000000;
// Flag to specify search for whole words. 

const TMsvPartList KMsvFindWholeWord			= 0x40000000;

// Maximum length (in characters) of find text. 

const TInt KMsvMaxFindTextLength = 500;

#endif
