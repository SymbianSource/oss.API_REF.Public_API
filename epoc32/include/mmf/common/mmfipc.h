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
// include\mmf\common\mmfipc.h
// Thin interface layer to use either V1 or V2 IPC calls as appropriate
// 
//

#ifndef __MMF_COMMON_MMFIPC_H__
#define __MMF_COMMON_MMFIPC_H__

#include <e32base.h>

#ifdef __IPC_V2_PRESENT__
// if V2 code present than use it
#define __MMF_USE_IPC_V2__
#endif //__IPC_V2_PRESENT__


// The following declarations are used instead of the native ones on the particular system variant:
//    RMmfIpcMessage replaces RMessage or RMessage2
//    CMmfIpcServer replaces CServer or CServer2
//    CMmfIpcSession replaces CSharableSession or CSession2
// They are used internally to the MMF component to provide configurability for the particular subsystem

#ifdef __MMF_USE_IPC_V2__

typedef RMessage2 RMmfIpcMessage;

class CMmfIpcServer; // forward declaration

/**
 * derive CMmfIpcSession from CSession2 so we can bridge the differences to old CSharableSession
 *
 * @internalTechnology
 */
 
class CMmfIpcSession : public CSession2
	{
protected:
	virtual void CreateL(const CMmfIpcServer& aServer);
	CMmfIpcSession() {}
	// from CSession2
	void CreateL();
	};

/*
 * derive CMmfIpcServer from CServer2 so we can bridge difference to old CServer
 *
 * @internalTechnology
 */
 
class CMmfIpcServer : public CServer2
	{
protected:
	virtual CMmfIpcSession* NewSessionL(const TVersion& aVersion) const=0;
	CMmfIpcServer(TInt aPriority,TServerType aType=EUnsharableSessions);
private:
	// derived from CServer2
	CSession2* NewSessionL(const TVersion& aVersion,const RMessage2& aMessage) const;
	};

#else // __MMF_USE_IPC_V2__

// otherwise always use V1
typedef RMessage RMmfIpcMessage;
typedef CServer CMmfIpcServer;
typedef CSharableSession CMmfIpcSession;

#endif // __MMF_USE_IPC_V2__

#if defined(__VC32__)
#pragma warning( disable : 4097 )	// typedef-name used as synonym for class-name 
#endif


/**
 * RSessionBase adaptor layer 
 * Provides typechecking for client-side calls. 
 *
 * @internalTechnology
 */

class RMmfSessionBase : public RSessionBase
	{
protected:
	// no parameter variants
	TInt SendReceive(TInt aFunction) const;
	void SendReceive(TInt aFunction, TRequestStatus& aStatus) const;
	// send number of parameters - no "result" parameter, just error/status 
	TInt SendReceive(TInt aFunction, TInt aParam0) const;
	TInt SendReceive(TInt aFunction, TInt aParam0, TInt aParam1) const;
	void SendReceive(TInt aFunction, TInt aParam0, TRequestStatus& aStatus) const;
	void SendReceive(TInt aFunction, TInt aParam0, TInt aParam1, TRequestStatus& aStatus) const;
	TInt SendReceive(TInt aFunction, const TDesC8& aParam0) const;
	TInt SendReceive(TInt aFunction, const TDesC8& aParam0, const TDesC8& aParam1) const;
	TInt SendReceive(TInt aFunction, const TDesC8& aParam0, const TDesC8& aParam1, const TDesC8& aParam2) const;
	void SendReceive(TInt aFunction, const TDesC8& aParam0, TRequestStatus& aStatus) const;
	void SendReceive(TInt aFunction, const TDesC8& aParam0, const TDesC8& aParam1, TRequestStatus& aStatus) const;
	void SendReceive(TInt aFunction, const TDesC8& aParam0, const TDesC8& aParam1, const TDesC8& aParam2, TRequestStatus& aStatus) const;
	// "last" parameter is result, so is passed as TDes8&
	TInt SendReceiveResult(TInt aFunction, TDes8& aResult) const;
	TInt SendReceiveResult(TInt aFunction, const TDesC8& aParam0, const TDesC8& aParam1, TDes8& aResult) const;
	TInt SendReceiveResult(TInt aFunction, const TDesC8& aParam0, const TDesC8& aParam1, const TDesC8& aParam2, TDes8& aResult) const;
	void SendReceiveResult(TInt aFunction, TDes8& aResult, TRequestStatus& aStatus) const;
	void SendReceiveResult(TInt aFunction, const TDesC8& aParam0, const TDesC8& aParam1, TDes8& aResult, TRequestStatus& aStatus) const;
	void SendReceiveResult(TInt aFunction, const TDesC8& aParam0, const TDesC8& aParam1, const TDesC8& aParam2, TDes8& aResult, TRequestStatus& aStatus) const;

	//TDesC versions
	void SendReceive(TInt aFunction, const TDesC& aParam0, TRequestStatus& aStatus) const;
	TInt SendReceive(TInt aFunction, const TDesC& aParam0) const;
	TInt SendReceiveResult(TInt aFunction, const TDesC8& aParam0, const TDesC8& aParam1, TDes& aResult) const;

	// custom command versions for non-UID commands
	TInt SendReceive(TInt aFunction, TInt aParam0, const TDesC8& aParam1, const TDesC8& aParam2) const;
	TInt SendReceiveResult(TInt aFunction, TInt aParam0, const TDesC8& aParam1, const TDesC8& aParam2, TDes8& aResult) const;
	void SendReceive(TInt aFunction, TInt aParam0, const TDesC8& aParam1, const TDesC8& aParam2, TRequestStatus& aStatus) const;
	void SendReceiveResult(TInt aFunction, TInt aParam0, const TDesC8& aParam1, const TDesC8& aParam2, TDes8& aResult, TRequestStatus& aStatus) const;
	};


/**
 * Adapt RMessage calls between IPC variants
 *
 * @internalTechnology
 */

class MmfMessageUtil 
	{
public:
	static TInt Read(const RMmfIpcMessage& aMessage, TInt aParam, TDes8& aResult);
	static TInt Write(const RMmfIpcMessage& aMessage, TInt aParam, const TDesC8& aValue);
	static void ReadL(const RMmfIpcMessage& aMessage, TInt aParam, TDes8& aResult);
	static void WriteL(const RMmfIpcMessage& aMessage, TInt aParam, const TDesC8& aValue);
	};
	
#include <mmf/common/mmfipc.inl>

#endif // __MMF_COMMON_MMFIPC_H__
