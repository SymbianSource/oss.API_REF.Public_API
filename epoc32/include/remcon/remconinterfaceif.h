// Copyright (c) 2004-2009 Nokia Corporation and/or its subsidiary(-ies).
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



/**
 @file
 @publishedPartner
 @released
*/

#ifndef REMCONINTERFACEIF_H
#define REMCONINTERFACEIF_H

#include <e32base.h>
#include <remcon/messagetype.h>

/** 
The UID of the interface between the interface selector and the outer layer 
API. Currently this consists of a single 'new message' method. If in future it 
changes (more methods are added) then a new M class and UID can be defined. 
New outer layer APIs can implement that M class and be used by the interface 
selector, without breaking existing outer layer APIs which still only 
implement this version of the interface.
*/
const TInt KRemConInterfaceIf1 = 0x1020D409;
const TInt KRemConInterfaceIf2 = 0x10285A37;

/**
Mixin for outer layer interfaces to be notified of incoming messages (commands and responses).
Having received a command, the client is obliged to send a response.
A client can only have one send outstanding at any time.
If commands come in quickly, the client is responsible for queueing its responses to them.
Note that each command delivered to a target involves memory allocated in the server�s heap,
which is only released on client closure or when a response is sent.
*/
class MRemConInterfaceIf
	{
public: 
	/**
	Called when a message comes in for this interface.
	@param aOperationId The interface-specific operation id.
	@param aData Any operation-specific data.
	*/
	virtual void MrcibNewMessage(TUint aOperationId, const TDesC8& aData) = 0;
	};

/**
Mixin for outer layer interfaces to be notified of incoming messages. 
*/
class MRemConInterfaceIf2
	{
public: 
	/**
	Called when a message comes in for this interface.
	@param aOperationId The interface-specific operation id.
	@param aData Any operation-specific data.
	*/
	virtual void MrcibNewMessage(TUint aOperationId, const TDesC8& aData, TRemConMessageSubType aMessageSubType) = 0;
	};

	
#endif // REMCONINTERFACEIF_H
