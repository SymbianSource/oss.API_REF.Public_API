/*
* Copyright (c) 1997-1999 Nokia Corporation and/or its subsidiary(-ies).
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
* Description:
*
*/


#if !defined(__EIKKEYS_H__)
#define __EIKKEYS_H__

#if !defined(__E32KEYS_H__)
#include <e32keys.h>
#endif

enum TEikSidebarKeys
	{
	EEikSidebarMenuKey=ESpecialKeyBase,
	EEikSidebarClipKey,
	EEikSidebarIrdaKey,
	EEikSidebarZoomInKey,
	EEikSidebarZoomOutKey
	};


enum TEikAppbarKeys
	{
	EEikAppbarSystemKey=ESpecialKeyBase+0x40,
	EEikAppbarApp1Key,
	EEikAppbarApp2Key,
	EEikAppbarApp3Key,
	EEikAppbarApp4Key,
	EEikAppbarApp5Key,
	EEikAppbarApp6Key,
	EEikAppbarApp7Key,
	EEikAppbarApp8Key
	};


#endif
