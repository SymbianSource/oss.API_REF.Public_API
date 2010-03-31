/*
* Copyright (c) 2009 Nokia Corporation and/or its subsidiary(-ies). 
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
* Description: Information about an alert notification.
*
*/
///////////////////////////////////////////////////////////////////////////////
// SyncMLAlertInfo.h
//
// v09
//
///////////////////////////////////////////////////////////////////////////////
#ifndef __SYNCMLALERTINFO_H__
#define __SYNCMLALERTINFO_H__
//
#include <e32base.h>
#include <SyncMLDef.h>
//
class RReadStream;
class RWriteStream;
//

class CSmlAlertInfo : public CBase
/**
@publishedAll
@released

	Information about an alert notification.

	Push message parsers are responsible for generating one (or more) of these objects
	as a result of parsing a message, whether the parse is successful or not.

	Not all details will be applicable to all alerts.

	If parsing is successful, and a profile ID is specified, the Agent uses
	this information to generate a job (based upon the 'job control' value specified),
	prompting the user first if neccessary
	.
	If parsing fails, parsers should try to fill in as much information
	as they can.

	@see KUidSyncMLPushMsgConfirmNotifier
	@see KUidSyncMLPushMsgInformNotifier 
*/
	{
public:
	enum TJobControl
	/**
		Specifies whether a job should be created for an alert.
	*/
		{
		/** Do not create a job. */
		EDoNotCreateJob,
		/** Create a job. */
		ECreateJob,
		/** Inform the user that a job is being created. */
		EInformJob,
		/** Get confirmation from the user that a job should be created. */
		EConfirmJob
		};
public:
	IMPORT_C static CSmlAlertInfo* NewLC();
	IMPORT_C CSmlAlertInfo();
	IMPORT_C virtual ~CSmlAlertInfo();
	IMPORT_C void InternalizeL(RReadStream&);
	IMPORT_C void ExternalizeL(RWriteStream&) const;
public:
	IMPORT_C TInt ErrorCode() const;
	IMPORT_C TJobControl JobControl() const;
	IMPORT_C TSmlUsageType Protocol() const;
	IMPORT_C TInt SessionId() const;
	IMPORT_C TSmlProfileId Profile() const;
	IMPORT_C TSmlTransportId Transport() const;
	IMPORT_C TSmlConnectionId Connection() const;
	IMPORT_C const RArray<TInt>& TaskIds() const;
	IMPORT_C const RArray<TSmlSyncType>& TaskSyncTypes() const;
	IMPORT_C const TDesC8& VendorSpecificInfo() const;
	IMPORT_C TBool CreateSession() const;
public:
	IMPORT_C void Reset();
	IMPORT_C void SetErrorCode(TInt aError);
	IMPORT_C void SetJobControl(TJobControl);
	IMPORT_C void SetProtocolType(TSmlUsageType);
	IMPORT_C void SetSessionId(TInt aId);
	IMPORT_C void SetProfileId(TSmlProfileId);
	IMPORT_C void SetTransportId(TSmlTransportId);
	IMPORT_C void SetConnectionId(TSmlConnectionId);
	IMPORT_C RArray<TInt>& TaskIds();
	IMPORT_C RArray<TSmlSyncType>& TaskSyncTypes();
	IMPORT_C void SetVendorSpecificInfoL(const TDesC8&);
	IMPORT_C void SetConfirmation(TBool);
    IMPORT_C void SetUimode(TInt aUimode);
    IMPORT_C TInt GetUimode();
private:
	TInt iErrorCode;
	TJobControl iJobControl;
	TSmlUsageType iProtocol;
	TInt iSessionId;
	TSmlProfileId iProfile;
	TSmlTransportId iTransport;
	TSmlConnectionId iConnection;
	RArray<TInt> iTaskIds;
	RArray<TSmlSyncType> iTaskSyncTypes;
	HBufC8* iVendorSpecificInfo;
	TUint iFlags;
	TInt iUimode;
	};

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
#endif
