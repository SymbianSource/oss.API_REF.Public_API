// Copyright (c) 2003-2009 Nokia Corporation and/or its subsidiary(-ies).
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

#ifndef __OBEXCLIENT_H
#define __OBEXCLIENT_H

#include <obextypes.h>
#include <obex/internal/obextransportconstants.h>
#include <obexbase.h>

class CObexPacket;
class MObexFinalPacketObserver;
class CObexPacketSignaller;
class CObexPacketTimer;
class CObexErrorEngine;

/**
Client side functionality. Connection based.
Supports ...
- Opening IrDA TTP sockets for the OBEX session.
- Opening an OBEX session over a connected socket
- Standard OBEX (spec. version 1.2) operations.
 
This class is not designed for user derivation.

@publishedAll
@released
*/
NONSHARABLE_CLASS(CObexClient) : public CObex
	{
public:
	IMPORT_C ~CObexClient();
	IMPORT_C static CObexClient* NewL(TObexProtocolInfo& aObexProtocolInfoPtr);
	IMPORT_C static CObexClient* NewL(TObexProtocolInfo& aObexProtocolInfoPtr, TObexProtocolPolicy& aObexProtocolPolicy);
	IMPORT_C static CObexClient* NewL(TObexTransportInfo& aObexTransportInfo);
	IMPORT_C void Connect(TRequestStatus& aStatus);
	IMPORT_C void Connect(CObexBaseObject& aObject, TRequestStatus& aStatus);	
	IMPORT_C void ConnectL(CObexBaseObject& aObject, const TDesC& aPassword, 
													TRequestStatus& aStatus);
	IMPORT_C void ConnectL(const TDesC& aPassword, TRequestStatus& aStatus);
	IMPORT_C void Disconnect(TRequestStatus& aStatus);						
	IMPORT_C void Put(CObexBaseObject& aObject, TRequestStatus& aStatus);
	IMPORT_C void Get(CObexBaseObject& aObject, TRequestStatus& aStatus);		
	IMPORT_C void SetPath(TSetPathInfo& aPathInfo, TRequestStatus& aStatus);
	IMPORT_C void Abort();					
	IMPORT_C void UserPasswordL( const TDesC& aPassword);
	IMPORT_C const CObexHeaderSet& GetPutFinalResponseHeaders();
	IMPORT_C void SetFinalPacketObserver(MObexFinalPacketObserver* aObserver);
	IMPORT_C TObexResponse LastServerResponseCode() const;
	IMPORT_C void SetCommandTimeOut(TTimeIntervalMicroSeconds32 aTimeOut);
	IMPORT_C TAny* ExtensionInterface(TUid aUid);

public:	// Called from CObexNotifyExtendClient
	void SignalPacketProcessEvent(TObexPacketProcessEvent aEvent);
	void TimeOutCompletion();
	
private:
	CObexClient();
	void ConstructL(TObexTransportInfo& aObexTransportInfo);
	TBool AlreadyActive(TRequestStatus& aStatus);
	void ClientCommandL(TOperation aOp, TAny* aParam, TRequestStatus& aStatus);
	// Implementation of CObex Events
	virtual void OnPacketReceive(CObexPacket& aPacket);
	virtual void OnError(TInt aError);
	virtual void OnTransportUp();
	virtual void OnTransportDown();
	void SetRequest(TRequestStatus& aStatus, TOperation aOperation);
	void CompleteRequest(const TInt aCompletion);
	TInt PrepareConnectPacket(CObexPacket& aPacket);	// Should be members of TConnectInfo
	TInt ParseConnectPacket(CObexPacket& aPacket);	
	void ResetConnectionID();
	void SetConnectionID(TUint32 aConnectionID);
	void EmptyHeaderSet();
	void SendRequestPacket();
	void SendRequestPacket(TObexOpcode aObexOpcode);

private: 
	TRequestStatus* iPendingRequest;
	CObexBaseObject* iCurrentObject;
	TUint32 iConnectionID; 
	TBool iConnectionIdSet;
	CObexHeaderSet* iHeaderSet;
	CObexHeader* iHeader;
	CObexPacketSignaller* iPacketProcessSignaller;
	TObexResponse iLastReceivedResponseOpcode;
	CObexErrorEngine* iErrorEngine;
	TBool iIsLastErrorSet;
	TTimeIntervalMicroSeconds32 iCmdTimeOutDuration;
	CObexPacketTimer* iPacketTimer;
	};

#endif // __OBEXCLIENT_H
