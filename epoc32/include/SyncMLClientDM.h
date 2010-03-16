/*
* Copyright (c) 2009 Nokia Corporation and/or its subsidiary(-ies). 
* All rights reserved.
* This component and the accompanying materials are made available
* under the terms of the License "Symbian Foundation License v1.0" to Symbian Foundation members and "Symbian Foundation End User License Agreement v1.0" to non-members
* which accompanies this distribution, and is available
* at the URL "http://www.symbianfoundation.org/legal/licencesv10.html".
*
* Initial Contributors:
* Nokia Corporation - initial contribution.
*
* Contributors:
*
* Description: SyncML APIs for device management client.
*
*/
///////////////////////////////////////////////////////////////////////////////
// SyncMLClientDM.h
//
//
// SyncML Device Management Client API v04.
//
///////////////////////////////////////////////////////////////////////////////
#ifndef __SYNCMLCLIENTDM_H__
#define __SYNCMLCLIENTDM_H__
//
#include <SyncMLClient.h>
//


///////////////////////////////////////////////////////////////////////////////
// RSyncMLDevManJob
///////////////////////////////////////////////////////////////////////////////
class RSyncMLDevManJob : public RSyncMLJobBase
/**
	Handle to a device management job.

	A device management job is used to create, access, modify or remove device settings stored in the device repository.
	@publishedAll
	@released
*/
	{
public:
	IMPORT_C RSyncMLDevManJob();
	IMPORT_C void CreateL(RSyncMLSession&, TSmlProfileId);
	IMPORT_C void CreateL(RSyncMLSession&, TSmlProfileId, TSmlConnectionId);
	IMPORT_C void OpenL(RSyncMLSession&, TSmlJobId);
	IMPORT_C void StopL();
	};

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
// RSyncMLDevManProfile
///////////////////////////////////////////////////////////////////////////////
class RSyncMLDevManProfile : public RSyncMLProfileBase
/**
	Handle to a SyncML Device Management profile. 

	A profile encapsulates a relationship with a single SyncML remote server.
	@publishedAll
	@released
*/
	{
public:
	IMPORT_C RSyncMLDevManProfile();
	IMPORT_C void OpenL(RSyncMLSession&, TSmlProfileId);
	IMPORT_C void OpenL(RSyncMLSession&, TSmlProfileId, TSmlOpenMode);
	IMPORT_C void CreateL(RSyncMLSession&);
	};

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////
// RSyncMLDevMan
///////////////////////////////////////////////////////////////////////////////
class RSyncMLDevMan : public RSubSessionBase
/**
	Handle to a RSyncMLDevMan session.
	@publishedAll
	@released
*/
	{
public:
	IMPORT_C RSyncMLDevMan();
	IMPORT_C void OpenL(RSyncMLSession&);

	IMPORT_C void ClearRootAclL();

	IMPORT_C void SetUserInteractionNotifierTimeoutL(TUint aSeconds); // use default if set to 0
	IMPORT_C TUint UserInteractionNotifierTimeout() const;

	IMPORT_C void Close();
	};

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////




///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
#endif
