// Copyright (c) 2002-2009 Nokia Corporation and/or its subsidiary(-ies).
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

#ifndef __MMFSUBTHREADBASE_H__
#define __MMFSUBTHREADBASE_H__

#include <e32base.h>
#include <e32std.h>
#include <mmf/common/mmfpaniccodes.h>
#include <mmf/common/mmfcontroller.h>

/**
@publishedAll
@released

Defines the maximum number of event messages that will be held server-side
while waiting for the client to request the next message in the queue.
*/
static const TInt KMMFSubThreadMaxCachedMessages = 4;

/**
@publishedAll
@released

Defines the maximum heap size paramater used when creating the datapath subthread.
*/
static const TInt KMMFSubThreadMaxHeapSize = 0x100000;//1MB


/**
@publishedAll
@released

ITC message ID's used by the client to send commands to the datapath subthread server.
*/
enum TMMFSubThreadMessageIds
	{
  	/**
	Message ID for message to request next event from the sub thread server.
	*/
	EMMFSubThreadReceiveEvents,
	/**
	Message ID for message to cancel a previous request to receive an event from the sub thread server.
	*/
	EMMFSubThreadCancelReceiveEvents,
	/**
	Message ID for message to request that the sub thread shuts itself down.
	*/
	EMMFSubThreadShutdown,
	/**
	Message ID for message to request the datapath subthread load a datapath.
	*/
	EMMFDataPathProxyLoadDataPathBy,
	/**
	Message ID for message to request the datapath subthread load a datapath with a specified 
	media ID.
	*/
	EMMFDataPathProxyLoadDataPathByMediaId,
	/**
	Message ID for message to request the datapath subthread load a datapath with a specified codec.
	*/
	EMMFDataPathProxyLoadDataPathByCodecUid,
	/**
	Message ID for message to request the datapath subthread load a datapath with a specified media 
	ID and codec.
	*/
	EMMFDataPathProxyLoadDataPathByMediaIdCodecUid,
	/**
    Message ID for message to add a data source to the datapath.
	*/
	EMMFDataPathProxyAddDataSource,
	/**
	Message ID for message to add a data sink to the datapath.
	*/
	EMMFDataPathProxyAddDataSink,
	/**
	Message ID for message to prime the datapath.
	*/
	EMMFDataPathProxyPrime,
	/**
	Message ID for message to start the datapath playing.
	*/
	EMMFDataPathProxyPlay,
	/**
	Message ID for message to pause the datapath.
	*/
	EMMFDataPathProxyPause,
	/**
	Message ID for message to stop the datapath.
	*/
	EMMFDataPathProxyStop,
	/**
	Message ID for message to get the datapath's position.
	*/
	EMMFDataPathProxyGetPosition,
	/**
	Message ID for message to set the datapath's position.
	*/
	EMMFDataPathProxySetPosition,
	/**
	Message ID for message to set the datapath's play window.
	*/
	EMMFDataPathProxySetPlayWindow,
	/**
	Message ID for message to clear the datapath's play window.
	*/
	EMMFDataPathProxyClearPlayWindow,
	/**
	Message ID for message to get the datapath's current state.
	*/
	EMMFDataPathProxyState,
	/**
	Unused.
	*/
	EMMFAudioPolicyProxyGetAudioPolicy
	};


class RMMFSubThreadBase; // declared here.
/**
@internalTechnology

Base class for clients to MMF sub threads.
Provides functionality to start the sub thread and transmit events from subthread to main thread.
*/
NONSHARABLE_CLASS( RMMFSubThreadBase ): public RMmfSessionBase
	{
public:
	RMMFSubThreadBase(TTimeIntervalMicroSeconds32 aShutdownTimeout) : iShutdownTimeout(aShutdownTimeout) {};
	/**
	Returns the id of the subthread, allowing a client to logon to the thread to receive notification of its death.
	*/
	TThreadId SubThreadId() {return iSubThread.Id();};
	/**
	Allows a client to receive events from the subthread.
	*/
	IMPORT_C void ReceiveEvents(TMMFEventPckg& aEventPckg, TRequestStatus& aStatus);
	IMPORT_C TInt CancelReceiveEvents();
	/**
	Signal to the subthread to exit.
	Note: This function will not return until the subthread has exited, or a timeout has occurred.
	*/
	IMPORT_C void Shutdown();
protected:
	/**
	Should be called by derived classes to start the subthread.
	*/
	TInt DoCreateSubThread(const TDesC& aName, TThreadFunction aFunction, TBool aUseNewHeap = EFalse);
	void Panic(TMMFSubThreadPanicCode aPanicCode);
protected:
	RThread iSubThread;
	TTimeIntervalMicroSeconds32 iShutdownTimeout;
private:
	/**
	Used to determine the success of a logon.  If the status is not pending, the logon has failed
	and the thread should be closed.
	*/
	TRequestStatus iLogonStatus;
	/**
	This member is internal and not intended for use.
	*/
	TInt iReserved1;
	TInt iReserved2;
	TInt iReserved3;
	};

/**
@internalTechnology

Used to Kill the subthread either immediately or after a timeout.
Used by the subthread on startup to prevent orphaning if no sessions are created to it.
*/
class CMMFSubThreadShutdown : public CTimer
	{
	enum {EMMFSubThreadShutdownDelay=1000000};	// 1s
public:
	static CMMFSubThreadShutdown* NewL();
	CMMFSubThreadShutdown();
	void ConstructL();
	void Start();
	void ShutdownNow();
private:
	void RunL();
	};

/**
@internalTechnology

Subthread server base class.
Provides session counting and will kill the subthread immediately when the session count reaches zero.
Starts the shutdown timer on construction to prevent orphaning if no sessions are created.
*/
class CMMFSubThreadServer : public CMmfIpcServer
	{
public:
	virtual ~CMMFSubThreadServer();
	virtual void SessionCreated();
	virtual TInt RunError(TInt aError);
	virtual void ShutdownNow();
protected:
	virtual CMmfIpcSession* NewSessionL(const TVersion& aVersion) const = 0;
	CMMFSubThreadServer(TInt aPriority);
	void ConstructL();
private:
	CMMFSubThreadShutdown* iShutdownTimer;
	};

/**
@internalTechnology

Used to hold on to an RMessage so we can complete it asynchronously to send an event to the main thread.
*/
class CMMFSubThreadEventReceiver : public CBase
	{
public:
	static CMMFSubThreadEventReceiver* NewL(const RMmfIpcMessage& aMessage);
	~CMMFSubThreadEventReceiver();
	void SendEvent(const TMMFEvent& aEvent);
private:
	CMMFSubThreadEventReceiver(const RMmfIpcMessage& aMessage);
private:
	RMmfIpcMessage iMessage;
	TBool iNeedToCompleteMessage;
	};

/**
@internalTechnology

Subthread session base class.
Derived classes must implement the ServiceL() method.
*/
class CMMFSubThreadSession : public CMmfIpcSession, public MAsyncEventHandler
	{
public:
	virtual ~CMMFSubThreadSession();
	void CreateL(const CMmfIpcServer& aServer);
	virtual void ServiceL(const RMmfIpcMessage& aMessage) = 0;
	//from MAsyncEventHandler
	TInt SendEventToClient(const TMMFEvent& aEvent);
protected:
	CMMFSubThreadSession() {};
	TBool ReceiveEventsL(const RMmfIpcMessage& aMessage);
	TBool CancelReceiveEvents();
	TBool ShutDown();
protected:
	CMMFSubThreadServer* iServer;
private:
	CMMFSubThreadEventReceiver* iEventReceiver;
	RArray<TMMFEvent> iEvents;
	};



#endif
