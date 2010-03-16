// Copyright (c) 2005-2009 Nokia Corporation and/or its subsidiary(-ies).
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
