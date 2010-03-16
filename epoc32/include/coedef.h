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

#ifndef __COEDEF_H__
#define __COEDEF_H__

#include <e32std.h> 
#include <guldef.h> // only requried for limited source compatability with releases prior to 250

const TInt KCoeCustomColorsArrayValue=0x100057C2;
const TInt KCoeColorGray4=0x19bd6002;
const TInt KCoeColorColor16=0x19bd6003;
const TInt ECoeResourceSignatureValue=4;

/** Event handling flags. 

These should be returned by CCoeControl::OfferKeyEventL() to indicate whether 
or not a key event was processed by the control. 

@publishedAll
@released */
enum TKeyResponse
	{
	/** The key event was not handled. */
	EKeyWasNotConsumed,
	/** The key event was handled. */
	EKeyWasConsumed
	};

/** Control redraw flags. 

Passed to CCoeControl::SetFocus() to indicate the requirements for control 
redrawing. 

@publishedAll
@released */
enum TDrawNow
	{
	/** Redraw of the control is not required immediately. */
	ENoDrawNow,
	/** Redraw control immediately. */
	EDrawNow
	};

/** Window priority values. 

These are passed in the aOrdinalPriority argument to RWindowTreeNode::SetOrdinalPosition(). 

@publishedAll
@released */
enum TCoeWinPriority
	{
	/** -1000 */
	ECoeWinPriorityNeverAtFront		=-1000,
	/** -750 */
	ECoeWinPriorityLow				=-750,
	/** 0 */
	ECoeWinPriorityNormal			=0,
	/** 500 */
	ECoeWinPriorityMedium			=500,
	/** 750 */
	ECoeWinPriorityHigh				=750,
	/** 900 */
	ECoeWinPriorityFep				=900,
	/** 1000 */
	ECoeWinPriorityAlwaysAtFront	=1000
	};

/** The message UID sent when a colour scheme change event occurs.

@internalTechnology */
const TInt KUidValueCoeColorSchemeChangeEvent	=0x100056C4;
const TInt KUidValueCoeZoomChangeEvent          =0x100057C3;
const TInt KUidValueCoeFontChangeEvent          =0x100057C4;

/** @internalTechnology */
const TUint KUidFepFrameworkRepository=0x10272618;

/** @internalTechnology */
enum // key-masks and keys for the "KUidFepFrameworkRepository" repository
	{
	ERepositoryKeyMask_DefaultSetting	=0x00001000,
	ERepositoryKeyMask_DynamicSetting	=0x00002000,

	ERepositoryKeyMask_FepId			=0x00000001,
	ERepositoryKeyMask_OnState			=0x00000002,
	ERepositoryKeyMask_OnKeyData		=0x00000004,
	ERepositoryKeyMask_OffKeyData		=0x00000008,

	ERepositoryKey_DefaultFepId			=ERepositoryKeyMask_DefaultSetting|ERepositoryKeyMask_FepId,
	ERepositoryKey_DefaultOnState		=ERepositoryKeyMask_DefaultSetting|ERepositoryKeyMask_OnState,
	ERepositoryKey_DefaultOnKeyData		=ERepositoryKeyMask_DefaultSetting|ERepositoryKeyMask_OnKeyData,
	ERepositoryKey_DefaultOffKeyData	=ERepositoryKeyMask_DefaultSetting|ERepositoryKeyMask_OffKeyData,

	ERepositoryKey_DynamicFepId			=ERepositoryKeyMask_DynamicSetting|ERepositoryKeyMask_FepId,
	ERepositoryKey_DynamicOnState		=ERepositoryKeyMask_DynamicSetting|ERepositoryKeyMask_OnState,
	ERepositoryKey_DynamicOnKeyData		=ERepositoryKeyMask_DynamicSetting|ERepositoryKeyMask_OnKeyData,
	ERepositoryKey_DynamicOffKeyData	=ERepositoryKeyMask_DynamicSetting|ERepositoryKeyMask_OffKeyData
	};

/** @internalTechnology */
#if defined(_DEBUG)
#define __DEBUG_CHECK_HEAP_INTEGRITY User::Heap().Check()
#else
#define __DEBUG_CHECK_HEAP_INTEGRITY
#endif

/** Control key modifier.

Key codes get changed when the Ctrl key modifier is pressed at the same time as the key . 
The CTRL macro is used to shift the key character appropriately.

Note: this is not an inline function since that can't be used as the case of a switch 
statement.
 
@publishedAll
@released */
#define CTRL(x) ((x)-'a'+1)

/** Constant that represents all standard keyboard modifier keys.

@publishedAll
@released */
#define EAllStdModifiers (EModifierFunc|EModifierCtrl|EModifierShift)

#endif	// __COEDEF_H__
