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
