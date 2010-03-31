/*
* Copyright (c) 2004-2006 Nokia Corporation and/or its subsidiary(-ies).
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
* Description:  Contains Central Repository keys needed in logging GPRS/WLAN
*                counters.
*
*/

#ifndef DCLCRKEYS_H
#define DCLCRKEYS_H

const TUid KCRUidDCLLogs = {0x101F4CD5};

// Amount of total sent bytes using GPRS.
const TUint32 KLogsGPRSSentCounter     = 0x0000000C;

// Amount of total received bytes using GPRS.
const TUint32 KLogsGPRSReceivedCounter = 0x0000000D;

// Amount of total sent bytes using WLAN.
const TUint32 KLogsWLANSentCounter     = 0x00000014;

// Amount of total received bytes using WLAN.
const TUint32 KLogsWLANReceivedCounter = 0x00000015;

#endif // DCLCRKEYS_H

// End of File
