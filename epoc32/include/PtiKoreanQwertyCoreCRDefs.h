/*
* Copyright (c) 2009 Nokia Corporation and/or its subsidiary(-ies).
* All rights reserved.
* This component and the accompanying materials are made available
* under the terms of "Eclipse Public License v1.0"
* which accompanies this distribution, and is available
* at the URL "http://www.eclipse.org/legal/epl-v10.html".
*
* Initial Contributors:
* Nokia Corporation - initial contribution.
*
* Contributors:
*
* Description: 
*
*/

#ifndef _PTIKOREANQWERTYCORECRDEFS_H_
#define _PTIKOREANQWERTYCORECRDEFS_H_

#include <e32std.h>

const TUint32 KCRUidPtiKoreanQwertyCoreValue=0xEB339F5E;
const TUid KCRUidPtiKoreanQwertyCore={KCRUidPtiKoreanQwertyCoreValue};

enum TPeninputCRKeys
    {
    EVersion,
    EDblConsonentSsangKiyeok,
    EDblConsonentSsangTikeut,
    EDblConsonentSsangPieup,
    EDblConsonentSsangSios,
    EDblConsonentSsangCieuc,
    EDblConsonentYaPlusI,
    EDblConsonentYuPlusI,
    EDblConsonentOnSetting
    };

#endif // _PTIKOREANQWERTYCORECRDEFS_H_
