// Copyright (c) 2007-2009 Nokia Corporation and/or its subsidiary(-ies).
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

#ifndef REMCONBATTERYTARGETOBSERVER_H
#define REMCONBATTERYTARGETOBSERVER_H

#include <e32base.h>
#include <remcon/remconbattery.h>

/**
Clients must implement this interface in order to instantiate objects of type 
CRemConBatteryTarget. This interface passes incoming commands from RemCon to 
the client. 
*/
class MRemConBatteryTargetObserver
	{
public:
	/** 
	A 'InformBatteryStatusOfCT' has been received.
	@param aBatteryStatus The current battery status.
	*/
	virtual void MrcbstoBatteryStatus(TControllerBatteryStatus& aBatteryStatus) = 0;

	};

#endif // REMCONBATTERYSTATUSTARGETOBSERVER_H
