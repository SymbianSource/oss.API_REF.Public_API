// Copyright (c) 2005-2009 Nokia Corporation and/or its subsidiary(-ies).
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

#ifndef __OBEXBTTRANSPORTINFO_H__
#define __OBEXBTTRANSPORTINFO_H__

#include <bt_sock.h>
#include <obextransportinfo.h>

/**
Concrete transport info type for use when using RFCOMM transport controller.
@publishedAll
@released
*/
NONSHARABLE_CLASS(TObexBtTransportInfo) : public TObexTransportInfo
	{
public:
	/**
	The BT device address of the remote party.
	*/
	TBTSockAddr iAddr;
	};

#endif // __OBEXBTTRANSPORTINFO_H__
