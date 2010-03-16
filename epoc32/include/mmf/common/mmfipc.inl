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
// include\mmf\common\mmfipc.inl
// 
//

#ifdef __MMF_USE_IPC_V2__

//
// CMmfIpcSession
//

inline void CMmfIpcSession::CreateL(const CMmfIpcServer& /*aServer*/)
	{
	// default does nothing
	} 
	
inline void CMmfIpcSession::CreateL() 
	{ 
	const CMmfIpcServer* server = static_cast<const CMmfIpcServer*>(Server());
	CreateL(*server); // simulate CSession::CreateL() call
	}

//
// CMmfIcpServer
//

inline CMmfIpcServer::CMmfIpcServer(TInt aPriority,TServerType aType):
	CServer2(aPriority,aType)
	{
	}

inline CSession2* CMmfIpcServer::NewSessionL(const TVersion& aVersion, const RMessage2& /*aMessage*/) const
	{
	return NewSessionL(aVersion);
	}

#endif //__MMF_USE_IPC_V2__

//
// RMmfSessionBase
//

inline TInt RMmfSessionBase::SendReceive(TInt aFunction) const
	{
	return RSessionBase::SendReceive(aFunction);
	}

inline void RMmfSessionBase::SendReceive(TInt aFunction, TRequestStatus& aStatus) const
	{
	RSessionBase::SendReceive(aFunction,aStatus);
	}

// Integer Send calls

inline TInt RMmfSessionBase::SendReceive(TInt aFunction, TInt aParam0) const
	{
#ifdef __MMF_USE_IPC_V2__
	return RSessionBase::SendReceive(aFunction, TIpcArgs(aParam0));
#else
	TInt p[KMaxMessageArguments];
	p[0] = aParam0;
	p[1] = 0;
	p[2] = 0;
	p[3] = 0;
	return RSessionBase::SendReceive(aFunction, p);
#endif //__MMF_USE_IPC_V2__
	}

inline TInt RMmfSessionBase::SendReceive(TInt aFunction, TInt aParam0, TInt aParam1) const
	{
#ifdef __MMF_USE_IPC_V2__
	return RSessionBase::SendReceive(aFunction, TIpcArgs(aParam0,aParam1));
#else
	TInt p[KMaxMessageArguments];
	p[0] = aParam0;
	p[1] = aParam1;
	p[2] = 0;
	p[3] = 0;
	return RSessionBase::SendReceive(aFunction, p);
#endif //__MMF_USE_IPC_V2__
	}

inline void RMmfSessionBase::SendReceive(TInt aFunction, TInt aParam0, TRequestStatus& aStatus) const
	{
#ifdef __MMF_USE_IPC_V2__
	RSessionBase::SendReceive(aFunction, TIpcArgs(aParam0), aStatus);
#else
	TInt p[KMaxMessageArguments];
	p[0] = aParam0;
	p[1] = 0;
	p[2] = 0;
	p[3] = 0;
	RSessionBase::SendReceive(aFunction, p, aStatus);
#endif //__MMF_USE_IPC_V2__
	}

inline void RMmfSessionBase::SendReceive(TInt aFunction, TInt aParam0, TInt aParam1, TRequestStatus& aStatus) const
	{
#ifdef __MMF_USE_IPC_V2__
	RSessionBase::SendReceive(aFunction, TIpcArgs(aParam0,aParam1), aStatus);
#else
	TInt p[KMaxMessageArguments];
	p[0] = aParam0;
	p[1] = aParam1;
	p[2] = 0;
	p[3] = 0;
	RSessionBase::SendReceive(aFunction, p, aStatus);
#endif //__MMF_USE_IPC_V2__
	}

// Descriptor Send calls....

inline TInt RMmfSessionBase::SendReceive(TInt aFunction, const TDesC8& aParam0) const
	{
#ifdef __MMF_USE_IPC_V2__
	return RSessionBase::SendReceive(aFunction, TIpcArgs(&aParam0));
#else
	TAny* p[KMaxMessageArguments];
	p[0] = static_cast<TAny*>(const_cast<TDesC8*>(&aParam0));
	p[1] = NULL;
	p[2] = NULL;
	p[3] = NULL;
	return RSessionBase::SendReceive(aFunction, p);
#endif //__MMF_USE_IPC_V2__
	}

inline TInt RMmfSessionBase::SendReceive(TInt aFunction, const TDesC8& aParam0, const TDesC8& aParam1) const
	{
#ifdef __MMF_USE_IPC_V2__
	return RSessionBase::SendReceive(aFunction, TIpcArgs(&aParam0,&aParam1));
#else
	TAny* p[KMaxMessageArguments];
	p[0] = static_cast<TAny*>(const_cast<TDesC8*>(&aParam0));
	p[1] = static_cast<TAny*>(const_cast<TDesC8*>(&aParam1));
	p[2] = NULL;
	p[3] = NULL;
	return RSessionBase::SendReceive(aFunction, p);
#endif //__MMF_USE_IPC_V2__
	}

inline TInt RMmfSessionBase::SendReceive(TInt aFunction, const TDesC8& aParam0, const TDesC8& aParam1, const TDesC8& aParam2) const
	{
#ifdef __MMF_USE_IPC_V2__
	return RSessionBase::SendReceive(aFunction, TIpcArgs(&aParam0,&aParam1,&aParam2));
#else
	TAny* p[KMaxMessageArguments];
	p[0] = static_cast<TAny*>(const_cast<TDesC8*>(&aParam0));
	p[1] = static_cast<TAny*>(const_cast<TDesC8*>(&aParam1));
	p[2] = static_cast<TAny*>(const_cast<TDesC8*>(&aParam2));
	p[3] = NULL;
	return RSessionBase::SendReceive(aFunction, p);
#endif //__MMF_USE_IPC_V2__
	}

inline void RMmfSessionBase::SendReceive(TInt aFunction, const TDesC8& aParam0, TRequestStatus& aStatus) const
	{
#ifdef __MMF_USE_IPC_V2__
	RSessionBase::SendReceive(aFunction, TIpcArgs(&aParam0), aStatus);
#else
	TAny* p[KMaxMessageArguments];
	p[0] = static_cast<TAny*>(const_cast<TDesC8*>(&aParam0));
	p[1] = NULL;
	p[2] = NULL;
	p[3] = NULL;
	RSessionBase::SendReceive(aFunction, p, aStatus);
#endif //__MMF_USE_IPC_V2__
	}

inline void RMmfSessionBase::SendReceive(TInt aFunction, const TDesC8& aParam0, const TDesC8& aParam1, TRequestStatus& aStatus) const
	{
#ifdef __MMF_USE_IPC_V2__
	RSessionBase::SendReceive(aFunction, TIpcArgs(&aParam0,&aParam1), aStatus);
#else
	TAny* p[KMaxMessageArguments];
	p[0] = static_cast<TAny*>(const_cast<TDesC8*>(&aParam0));
	p[1] = static_cast<TAny*>(const_cast<TDesC8*>(&aParam1));
	p[2] = NULL;
	p[3] = NULL;
	RSessionBase::SendReceive(aFunction, p, aStatus);
#endif //__MMF_USE_IPC_V2__
	}

inline void RMmfSessionBase::SendReceive(TInt aFunction, const TDesC8& aParam0, const TDesC8& aParam1, const TDesC8& aParam2, TRequestStatus& aStatus) const
	{
#ifdef __MMF_USE_IPC_V2__
	RSessionBase::SendReceive(aFunction, TIpcArgs(&aParam0,&aParam1,&aParam2), aStatus);
#else
	TAny* p[KMaxMessageArguments];
	p[0] = static_cast<TAny*>(const_cast<TDesC8*>(&aParam0));
	p[1] = static_cast<TAny*>(const_cast<TDesC8*>(&aParam1));
	p[2] = static_cast<TAny*>(const_cast<TDesC8*>(&aParam2));
	p[3] = NULL;
	RSessionBase::SendReceive(aFunction, p, aStatus);
#endif //__MMF_USE_IPC_V2__
	}

// Descriptor Send&Result calls

inline TInt RMmfSessionBase::SendReceiveResult(TInt aFunction, TDes8& aResult) const
	{
#ifdef __MMF_USE_IPC_V2__
	return RSessionBase::SendReceive(aFunction, TIpcArgs(&aResult));
#else
	TAny* p[KMaxMessageArguments];
	p[0] = static_cast<TAny*>(&aResult);
	p[1] = NULL;
	p[2] = NULL;
	p[3] = NULL;
	return RSessionBase::SendReceive(aFunction, p);
#endif //__MMF_USE_IPC_V2__
	}

inline TInt RMmfSessionBase::SendReceiveResult(TInt aFunction, const TDesC8& aParam0, const TDesC8& aParam1, TDes8& aResult) const
	{
#ifdef __MMF_USE_IPC_V2__
	return RSessionBase::SendReceive(aFunction, TIpcArgs(&aParam0,&aParam1,&aResult));
#else
	TAny* p[KMaxMessageArguments];
	p[0] = static_cast<TAny*>(const_cast<TDesC8*>(&aParam0));
	p[1] = static_cast<TAny*>(const_cast<TDesC8*>(&aParam1));
	p[2] = static_cast<TAny*>(&aResult);
	p[3] = NULL;
	return RSessionBase::SendReceive(aFunction, p);
#endif //__MMF_USE_IPC_V2__
	}

inline TInt RMmfSessionBase::SendReceiveResult(TInt aFunction, const TDesC8& aParam0, const TDesC8& aParam1, const TDesC8& aParam2, TDes8& aResult) const
	{
#ifdef __MMF_USE_IPC_V2__
	return RSessionBase::SendReceive(aFunction, TIpcArgs(&aParam0,&aParam1,&aParam2,&aResult));
#else
	TAny* p[KMaxMessageArguments];
	p[0] = static_cast<TAny*>(const_cast<TDesC8*>(&aParam0));
	p[1] = static_cast<TAny*>(const_cast<TDesC8*>(&aParam1));
	p[2] = static_cast<TAny*>(const_cast<TDesC8*>(&aParam2));
	p[3] = static_cast<TAny*>(&aResult);
	return RSessionBase::SendReceive(aFunction, p);
#endif //__MMF_USE_IPC_V2__
	}

inline void RMmfSessionBase::SendReceiveResult(TInt aFunction, TDes8& aResult, TRequestStatus& aStatus) const
	{
#ifdef __MMF_USE_IPC_V2__
	RSessionBase::SendReceive(aFunction, TIpcArgs(&aResult), aStatus);
#else
	TAny* p[KMaxMessageArguments];
	p[0] = static_cast<TAny*>(&aResult);
	p[1] = NULL;
	p[2] = NULL;
	p[3] = NULL;
	RSessionBase::SendReceive(aFunction, p, aStatus);
#endif //__MMF_USE_IPC_V2__
	}

inline void RMmfSessionBase::SendReceiveResult(TInt aFunction, const TDesC8& aParam0, const TDesC8& aParam1, TDes8& aResult, TRequestStatus& aStatus) const
	{
#ifdef __MMF_USE_IPC_V2__
	RSessionBase::SendReceive(aFunction, TIpcArgs(&aParam0,&aParam1,&aResult), aStatus);
#else
	TAny* p[KMaxMessageArguments];
	p[0] = static_cast<TAny*>(const_cast<TDesC8*>(&aParam0));
	p[1] = static_cast<TAny*>(const_cast<TDesC8*>(&aParam1));
	p[2] = static_cast<TAny*>(&aResult);
	p[3] = NULL;
	RSessionBase::SendReceive(aFunction, p, aStatus);
#endif //__MMF_USE_IPC_V2__
	}

inline void RMmfSessionBase::SendReceiveResult(TInt aFunction, const TDesC8& aParam0, const TDesC8& aParam1, const TDesC8& aParam2, TDes8& aResult, TRequestStatus& aStatus) const
	{
#ifdef __MMF_USE_IPC_V2__
	RSessionBase::SendReceive(aFunction, TIpcArgs(&aParam0,&aParam1,&aParam2,&aResult), aStatus);
#else
	TAny* p[KMaxMessageArguments];
	p[0] = static_cast<TAny*>(const_cast<TDesC8*>(&aParam0));
	p[1] = static_cast<TAny*>(const_cast<TDesC8*>(&aParam1));
	p[2] = static_cast<TAny*>(const_cast<TDesC8*>(&aParam2));
	p[3] = static_cast<TAny*>(&aResult);
	RSessionBase::SendReceive(aFunction, p, aStatus);
#endif //__MMF_USE_IPC_V2__
	}
	
//
// MmfMessageUtil
//

inline void MmfMessageUtil::ReadL(const RMmfIpcMessage& aMessage, TInt aParam, TDes8& aResult)
	{
#ifdef __MMF_USE_IPC_V2__
	User::LeaveIfError(aMessage.Read(aParam, aResult));
#else
	// expect aParam to be a literal - so this code should optimise out
	if (aParam==0)
		aMessage.ReadL(aMessage.Ptr0(), aResult);
	else if (aParam==1)
		aMessage.ReadL(aMessage.Ptr1(), aResult);
	else if (aParam==2)
		aMessage.ReadL(aMessage.Ptr2(), aResult);
	else if (aParam==3)
		aMessage.ReadL(aMessage.Ptr3(), aResult);
	else
		User::Leave(KErrArgument);
#endif //__MMF_USE_IPC_V2__
	}

inline void MmfMessageUtil::WriteL(const RMmfIpcMessage& aMessage, TInt aParam, const TDesC8& aValue)
	{
#ifdef __MMF_USE_IPC_V2__
	User::LeaveIfError(aMessage.Write(aParam, aValue));
#else
	// expect aParam to be a literal - so this code should optimise out
	if (aParam==0)
		aMessage.WriteL(aMessage.Ptr0(), aValue);
	else if (aParam==1)
		aMessage.WriteL(aMessage.Ptr1(), aValue);
	else if (aParam==2)
		aMessage.WriteL(aMessage.Ptr2(), aValue);
	else if (aParam==3)
		aMessage.WriteL(aMessage.Ptr3(), aValue);
	else
		User::Leave(KErrArgument);
#endif //__MMF_USE_IPC_V2__
	}

inline TInt MmfMessageUtil::Read(const RMmfIpcMessage& aMessage, TInt aParam, TDes8& aResult)
	{
#ifdef __MMF_USE_IPC_V2__
	return aMessage.Read(aParam, aResult);
#else
	TRAPD(error, ReadL(aMessage, aParam, aResult));
	return error;
#endif //__MMF_USE_IPC_V2__
	}

inline TInt MmfMessageUtil::Write(const RMmfIpcMessage& aMessage, TInt aParam, const TDesC8& aValue)
	{
#ifdef __MMF_USE_IPC_V2__
	return aMessage.Write(aParam, aValue);
#else
	TRAPD(error, WriteL(aMessage, aParam, aValue));
	return error;
#endif //__MMF_USE_IPC_V2__
}

//TDesC versions

inline void RMmfSessionBase::SendReceive(TInt aFunction, const TDesC& aParam0, TRequestStatus& aStatus) const
	{
#ifdef __MMF_USE_IPC_V2__
	RSessionBase::SendReceive(aFunction, TIpcArgs(&aParam0), aStatus);
#else
	TAny* p[KMaxMessageArguments];
	p[0] = static_cast<TAny*>(const_cast<TDesC8*>(&aParam0));
	p[1] = NULL;
	p[2] = NULL;
	p[3] = NULL;
	RSessionBase::SendReceive(aFunction, p, aStatus);
#endif //__MMF_USE_IPC_V2__
	}

inline TInt RMmfSessionBase::SendReceive(TInt aFunction, const TDesC& aParam0) const
	{
#ifdef __MMF_USE_IPC_V2__
	return RSessionBase::SendReceive(aFunction, TIpcArgs(&aParam0));
#else
	TAny* p[KMaxMessageArguments];
	p[0] = static_cast<TAny*>(const_cast<TDesC8*>(&aParam0));
	p[1] = NULL;
	p[2] = NULL;
	p[3] = NULL;
	return RSessionBase::SendReceive(aFunction, p);
#endif //__MMF_USE_IPC_V2__
	}

inline TInt RMmfSessionBase::SendReceiveResult(TInt aFunction, const TDesC8& aParam0, const TDesC8& aParam1, TDes& aResult) const
	{
#ifdef __MMF_USE_IPC_V2__
	return RSessionBase::SendReceive(aFunction, TIpcArgs(&aParam0,&aParam1,&aResult));
#else
	TAny* p[KMaxMessageArguments];
	p[0] = static_cast<TAny*>(const_cast<TDesC8*>(&aParam0));
	p[1] = static_cast<TAny*>(const_cast<TDesC8*>(&aParam1));
	p[2] = static_cast<TAny*>(&aResult);
	p[3] = NULL;
	return RSessionBase::SendReceive(aFunction, p);
#endif //__MMF_USE_IPC_V2__
	}

// assuming IPC_V2
inline TInt RMmfSessionBase::SendReceive(TInt aFunction, TInt aParam0, const TDesC8& aParam1, const TDesC8& aParam2) const
	{
	return RSessionBase::SendReceive(aFunction, TIpcArgs(aParam0, &aParam1, &aParam2));
	}

inline TInt RMmfSessionBase::SendReceiveResult(TInt aFunction, TInt aParam0, const TDesC8& aParam1, const TDesC8& aParam2, TDes8& aResult) const
	{
	return RSessionBase::SendReceive(aFunction, TIpcArgs(aParam0, &aParam1, &aParam2, &aResult));
	}

inline void RMmfSessionBase::SendReceive(TInt aFunction, TInt aParam0, const TDesC8& aParam1, const TDesC8& aParam2, TRequestStatus& aStatus) const
	{
	return RSessionBase::SendReceive(aFunction, TIpcArgs(aParam0, &aParam1, &aParam2), aStatus);
	}

inline void RMmfSessionBase::SendReceiveResult(TInt aFunction, TInt aParam0, const TDesC8& aParam1, const TDesC8& aParam2, TDes8& aResult, TRequestStatus& aStatus) const
	{
	return RSessionBase::SendReceive(aFunction, TIpcArgs(aParam0, &aParam1, &aParam2, &aResult), aStatus);
	}
