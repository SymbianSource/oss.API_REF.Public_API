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

#ifndef __MOBEXNOTIFY_H__
#define __MOBEXNOTIFY_H__

#include <e32std.h>

class CObexPacket;

/**
@internalComponent

This class is only for internal use.

Originally it provided the call back interface for anything owned by CObex.
Note:  This is an internal class which is not intended for use outside of
the Transport<->Obex interface.  Even where access rules allow it, external
users should not call these functions as their implementation may change.
*/
NONSHARABLE_CLASS(MObexNotify)

	{
public:
	virtual void Process(CObexPacket &aPacket) =0;
	virtual void Error(TInt aError) =0;
	virtual void TransportUp() =0;
	virtual void TransportDown(TBool aForceTransportDeletion) =0;
	};

#endif // __MOBEXNOTIFY_H__
