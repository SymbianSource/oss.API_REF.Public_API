// Copyright (c) 1997-2009 Nokia Corporation and/or its subsidiary(-ies).
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
// CSocketServer
// 
//

inline CWorkerThread& CSocketServer::WorkerThread() const 
	{
	return *iOwnerThread;
	};

inline TWorkerId CSocketServer::WorkerId() const
	{
	return WorkerThread().WorkerId();
	}

//
// CSockSession
//

inline const CDealer& CSockSession::Dealer() const 
	{ 
	// NB: this is really only a static_cast<> but the Gordian knot of class dependencies results in a forward
	// declaration
	return *reinterpret_cast<const CDealer*>(Server());	
	}

inline CSubSessionIx& CSockSession::SubSessions()
	{
	return iSubSessions;
	}

inline const CSubSessionIx& CSockSession::SubSessions() const
	{
	return iSubSessions;
	}

inline TSockManData* CSockSession::SockManGlobals() const
    {
        return WorkerThread().SockManGlobals();
    }

//
// CSockSubSession
//

inline void CSockSubSession::Open()
	{
	iAccessCount++;
	}

inline void CSockSubSession::Close()
	{
	iAccessCount--;
	ASSERT(iAccessCount >= 0);
	if(iAccessCount == 0)
		{
		RemoveAndDestroy();
		}
	}

inline TInt CSockSubSession::AccessCount() const
	{
	return iAccessCount;
	}

inline CSockSession* CSockSubSession::Session()
	{ 
	ASSERT(iSession); 
	return iSession;
	}

inline CPlayer& CSockSubSession::Player() const 
	{ 
	ASSERT(iPlayer); 
	return *iPlayer; 
	}

#ifdef SYMBIAN_NETWORKING_PERFMETRICS
inline void CSockSubSession::IncludePerformanceData(TInt aDeltaClientRxBytes, TInt aDeltaClientRxBuffBytes, TInt aDeltaClientTxBytes)
	{
	iSession->IncludePerformanceData(aDeltaClientRxBytes, aDeltaClientRxBuffBytes, aDeltaClientTxBytes);
	}
#endif


inline const RMessage2& CSockSession::Message() const
	{ 
	return *iOurMessage; 
	}
	
inline void CSockSession::CompleteDisconnect()
	{
	RMessage2 dm = iDisconnectMessage;
	inherited::Disconnect(dm);
	}


inline void CSocketScheduler::SetGlobals(TSockManData* aGlobals)
    { 
	static_cast<CSocketScheduler*>(CActiveScheduler::Current())->iGlobals = aGlobals; 
	}

//inline void CSocketScheduler::SetWaitHook(TCallBack* aCall)
//	{ ((CSocketScheduler*)CActiveScheduler::Current())->iWaitHook=aCall; }

inline TSockManData* CSocketScheduler::Globals()
	{ 
	return static_cast<CSocketScheduler*>(CActiveScheduler::Current())->iGlobals; 
	}

//
// CSubSessionIx
// 

/**
Optional locking. When accessing any of the public methods of this class in a multithreaded 
environment, locking is often necessary. This lock does not allow for lock nesting.
*/
inline void CSubSessionIx::Lock() const
	{ 
	iLock.Wait(); 
	}

/**
Unlocking.
@see Lock()
*/
inline void CSubSessionIx::Unlock() const
	{ 
	iLock.Signal(); 
	}

/**
@return the number of active sub-sessions in the container.
*/
inline TInt CSubSessionIx::ActiveCount() const
	{
	return iActiveCount;
	}
