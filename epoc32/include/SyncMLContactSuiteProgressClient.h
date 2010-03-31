/*
* Copyright (c) 2002-2004 Nokia Corporation and/or its subsidiary(-ies). 
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
* Description: Sync session progress notification.
*
*/

#ifndef __SYNCMLCONTACTSUITEPROGRESSCLIENT_H__
#define __SYNCMLCONTACTSUITEPROGRESSCLIENT_H__
//
#include <e32std.h>
#include <badesca.h>
#include <SyncMLDef.h>
#include <SyncMLHistory.h>
#include <SyncMLClient.h>
//
class MSyncMLProgressObserver;
class CSmlContactSuiteActiveCallback;
//

///////////////////////////////////////////////////////////////////////////////
// RContactSuiteSyncMLSession
///////////////////////////////////////////////////////////////////////////////
/**
	A client handle to a SyncML Sync Agent session and to listen the sync 
	progress notifications.

	An instance of this class must be created in order to instantiate any of 
	the other client-side classes.

	Accessor methods are provided to enable clients to retrieve identifiers 
	of current and queued jobs, and of available profiles, transports, and 
	data providers. These IDs can be used to open handles on these objects 
	in order to manipulate them.

	Clients can request notifications of events related to jobs, profiles, transports,
	and the SyncML Agent, and can request progress for the currently running job.
	@publishedAll
	@released
*/
class RContactSuiteSyncMLSession:public RSyncMLSession
    {    
public:    
    IMPORT_C void CloseContactSuiteSession();
    IMPORT_C void RequestContactSuiteProgressL(  TInt aProfileId, MSyncMLProgressObserver& aProgressObserver );    

private:
    CSmlContactSuiteActiveCallback *iContactSuiteCallBack;    
    };

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
#endif
