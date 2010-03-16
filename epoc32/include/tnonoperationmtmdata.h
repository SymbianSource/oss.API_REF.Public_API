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

#ifndef __TNONOPERATIONMTMDATATYPE_H__
#define __TNONOPERATIONMTMDATATYPE_H__

#include <e32std.h>

/**
UID used by the Extension_ method for CBaseServerMtm to identify that the
non operation MTM data has been requested.

@internalComponent
@published
*/
const TUint KUidMsgNonOperationMtmData = 0x1028368e;

/**
Defines the types of non operation MTM data that can be requested from a
server MTM.

@internalComponent
@published
*/
enum TNonOperationMtmDataType
	{
	EMtmDataAccessPointId = 0
	};

/**
Structure to store IAP value for non operation MTM data IAP request

@internalComponent
@published
*/
struct TNonOperationMtmDataAccessPointId
	{
	TUint32 iAccessPointId;
	};

/**
Package to store result for non operation MTM data IAP request

@internalComponent
@published
*/
typedef TPckgBuf<TNonOperationMtmDataAccessPointId> TNonOperationMtmDataAccessPointIdBuffer;

#endif // #define __TNONOPERATIONMTMDATATYPE_H__
