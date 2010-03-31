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

#ifndef OBEXFINALPACKETOBSERVER_H
#define OBEXFINALPACKETOBSERVER_H

#include <e32std.h>

/**
This mixin class must be inherited by any class interested in final packet notifications. 

@publishedAll
@released
*/

class MObexFinalPacketObserver
	{
public:

	/** Indicates start of final packet.
	@publishedAll
	@released
	*/
	virtual void MofpoFinalPacketStarted() {};

	/** Indicates end of final packet.
	@publishedAll
	@released
	*/
	virtual void MofpoFinalPacketFinished() {};
	};

#endif // OBEXFINALPACKETOBSERVER_H

