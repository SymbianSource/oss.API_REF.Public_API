// Copyright (c) 2008-2009 Nokia Corporation and/or its subsidiary(-ies).
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

#ifndef REMCONGROUPNAVIGATIONTARGETOBSERVER_H
#define REMCONGROUPNAVIGATIONTARGETOBSERVER_H

#include <e32base.h>
#include <remconcoreapi.h>

/**
Clients must implement this interface in order to instantiate objects of type 
CRemConGroupNavigation. This interface passes incoming commands from RemCon to 
the client. 
*/
class MRemConGroupNavigationTargetObserver
	{
public:
	/** 
	A 'Next Group' has been received.
	@see TRemConCoreApiButtonAction
	@param aButtonAct The button action associated with the command.
	*/
	virtual void MrcgntoNextGroup(TRemConCoreApiButtonAction aButtonAct) = 0;
	
	/** 
	A 'Previous Group' has been received.
	@see TRemConCoreApiButtonAction
	@param aButtonAct The button action associated with the command.
	*/
	virtual void MrcgntoPreviousGroup(TRemConCoreApiButtonAction aButtonAct) =0;

	};

#endif // REMCONGROUPNAVIGATIONTARGETOBSERVER_H
