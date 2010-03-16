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
 @publishedAll
 @released
*/

#ifndef REMCONABSVOLTARGETOBSERVER_H
#define REMCONABSVOLTARGETOBSERVER_H

#include <e32base.h>

/**
Client-implemented mixin- notifies the client of incoming AbsVol commands.
*/
class MRemConAbsVolTargetObserver
	{
public:
	/** 
	A 'get absolute volume' command has been received.
	*/
	virtual void MrcavtoGetAbsoluteVolume();

	/**
	A 'set absolute volume' command has been received.
	@param aAbsVol The volume on a scale of 0 to aMaxVol.
	@param aMaxVol The volume aAbsVol is relative to.
	*/
	virtual void MrcavtoSetAbsoluteVolume(TUint aAbsVol, TUint aMaxVol);
	};

#endif // REMCONABSVOLTARGETOBSERVER_H
