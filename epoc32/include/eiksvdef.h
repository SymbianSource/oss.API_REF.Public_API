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

#ifndef __EIKSVDEF_H__
#define __EIKSVDEF_H__

/**
@publishedPartner
@released
*/
enum
	{
	KExternalKeyModifier=0,
	KExternalKey1=EKeyDictaphoneStop,
	KExternalKey2=EKeyDictaphonePlay,
	KExternalKey3=EKeyDictaphoneRecord,
	KExternalKeyModifierMask=EAllStdModifiers|EModifierFunc
	};

/**
@publishedPartner
@released
*/
const TUid KUidExternalKeyHandlerAppStream={0x10000117};

/**
@publishedPartner
@deprecated
*/
const TUid KUidDictaphoneFileStream={0x100001CF};

/**
@internalComponent
*/
_LIT(__EIKON_SERVER_NAME,"EikonServer");

/**
@publishedPartner
@released
*/
enum TEikServEvent
	{
	EEikServExit,
	EEikServChangePasswordMode,
	EEikServShowTaskList,
	EEikServHideTaskList,
	};

/**
@publishedPartner
@released
*/
enum { KNumOfSideButtons=5, KNumOfAppButtons=9 };

/**
@publishedPartner
@released
*/
_LIT(EIKON_SERVER_BACKDROP_WINDOW_GROUP_NAME,"EiksrvBackdrop");

#endif	// __EIKSVDEF_H__
