/*
* Copyright (c) 2007-2009 Nokia Corporation and/or its subsidiary(-ies).
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
* Name          : sipcrkeys.h
* Part of       : SIP API
* Version       : SIP/6.0
*
*/



#ifndef SIPCRKEYS_H
#define SIPCRKEYS_H

// INCLUDES
#include <e32def.h>

/**
* @file
* @publishedAll
* @released
*/

/**
* Defines configuration parameters used by the SIP stack.
*/
const TUid KCRUidSIP = { 0x101FED88 };

/**
* Defines SIP transaction timer T1 in milliseconds as per RFC3261.
*/
const TUint32 KSIPTransactionTimerT1 = 0x01;

/**
* Defines SIP transaction timer T2 in milliseconds as per RFC3261.
*/
const TUint32 KSIPTransactionTimerT2 = 0x02;

/**
* Defines SIP transaction timer T4 in milliseconds as per RFC3261.
*/
const TUint32 KSIPTransactionTimerT4 = 0x03;	

/**
* Defines SIP transaction timer T1 for LAN Bearer in milliseconds as per RFC3261.
*/
const TUint32 KSIPTransactionTimerLANT1 = 0x0b;

/**
* Defines SIP transaction timer T2 for LAN Bearer in milliseconds as per RFC3261.
*/
const TUint32 KSIPTransactionTimerLANT2 = 0x0c;

/**
* Defines SIP transaction timer T4 for LAN Bearer in milliseconds as per RFC3261.
*/
const TUint32 KSIPTransactionTimerLANT4 = 0x0d;

#endif // SIPCRKEYS_H

// End of File
