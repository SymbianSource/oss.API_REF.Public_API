/*
* Copyright (c) 2008-2009 Nokia Corporation and/or its subsidiary(-ies).
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
* Name          : sipprofileservercrkeys.h
* Part of       : SIP ProfileAgent API
*
*/



#ifndef PROFILESERVERCRKEYS_H_
#define PROFILESERVERCRKEYS_H_

// INCLUDES
#include <e32def.h>

/**
* @file
* @publishedAll
* @released
*/

/**
* Key space configuration used by the SIP ProfileAgent.
*/
const TUid KCRUidProfileSrv = { 0x2001F889 };

#define KSIPProfileTableMask 0xFF000000
#define KSIPProfileTableShift 24

#define KSIPProfileTypeMask  0x00FF0000
#define KSIPProfileTypeShift  16

#define KSIPProfilePropertyMask  0x0000FFFF
#define KSIPProfilePropertyShift  0

#define KSIPProfilePropertiesTable 0x01000000

#endif /*PROFILESERVERCRKEYS_H_*/
