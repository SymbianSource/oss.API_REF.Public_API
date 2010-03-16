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
//

#ifndef __APGTASK_H__
#define __APGTASK_H__

#include <e32base.h>
#include <w32std.h>

class RWsSession;
struct TKeyEvent;

/** @internalTechnology */
static const TInt KApaSystemEventsWithPowerMgmtCapabilityStart = 100;
/** @internalTechnology */
static const TInt KApaSystemEventsWithPowerMgmtCapabilityEnd = 199;

/** Defines the event types that a TApaTask object can send to its window group.

The events are sent by TApaTask::SendSystemEvent() and are handled by CEikAppUi::HandleSystemEventL().

@publishedAll
@released
@see TApaTask::SendSystemEvent()
@see CEikAppUi
@see CCoeAppUi::HandleSystemEventL() */
enum TApaSystemEvent
	{
	/** The task is being closed. */
	EApaSystemEventShutdown=1,
	/** Reserved for future use. */
	EApaSystemEventBackupStarting,
	/** Reserved for future use. */
	EApaSystemEventBackupComplete,
	/** The task is being brought to the foreground. */
	EApaSystemEventBroughtToForeground,
	/** Close any tasks including system tasks. 
	Events in the range @c KApaSystemEventsWithPowerMgmtCapabilityStart to 
	@c KApaSystemEventsWithPowerMgmtCapabilityEnd requires capability PowerMgmt*/
	EApaSystemEventSecureShutdown = KApaSystemEventsWithPowerMgmtCapabilityStart
	};

#ifdef _UNICODE
/**
@publishedAll
@released
*/
#define KUidApaMessageSwitchOpenFile KUidApaMessageSwitchOpenFile16

/**
@publishedAll
@released
*/
#define KUidApaMessageSwitchCreateFile KUidApaMessageSwitchCreateFile16

/**
@publishedAll
@released
*/
#define KUidApaMessageSwitchOpenFileValue KUidApaMessageSwitchOpenFileValue16

/**
@publishedAll
@released
*/
#define KUidApaMessageSwitchCreateFileValue KUidApaMessageSwitchCreateFileValue16
#else
#define KUidApaMessageSwitchOpenFile KUidApaMessageSwitchOpenFile8
#define KUidApaMessageSwitchCreateFile KUidApaMessageSwitchCreateFile8
#define KUidApaMessageSwitchOpenFileValue KUidApaMessageSwitchOpenFileValue8
#define KUidApaMessageSwitchCreateFileValue KUidApaMessageSwitchCreateFileValue8
#endif

/**
@internalComponent
*/
const TInt KUidApaMessageSwitchOpenFileValue16=0x10003A39;

/**
@internalComponent
*/
const TUid KUidApaMessageSwitchOpenFile16={KUidApaMessageSwitchOpenFileValue16};

/**
@internalComponent
*/
const TInt KUidApaMessageSwitchCreateFileValue16=0x10003A3A;

/**
@internalComponent
*/
const TUid KUidApaMessageSwitchCreateFile16={KUidApaMessageSwitchCreateFileValue16};

class TApaTask
/** Application task.

A task is a running application. At any one time, for any given application, 
there may be zero, one, or more tasks running on a device.

A task is identified by its association with the running application's window 
group.

An instance of the TApaTaskList class is used to find and access specific 
tasks.

@publishedAll
@released
@see TApaTaskList
@see RWindowGroup
@see RWsSession */
	{
public:

	IMPORT_C TApaTask(RWsSession& aWsSession);
	IMPORT_C void SetWgId(TInt aWgId);
	IMPORT_C TInt WgId() const;
	IMPORT_C TBool Exists() const;
	IMPORT_C TThreadId ThreadId() const;
	IMPORT_C void BringToForeground();
	IMPORT_C void SendToBackground();
	IMPORT_C void EndTask();
	IMPORT_C void KillTask();
	IMPORT_C void SendKey(TInt aKeyCode,TInt aModifiers);
	IMPORT_C void SendKey(const TKeyEvent& aKey);
	IMPORT_C void SendSystemEvent(TApaSystemEvent aEvent);
	IMPORT_C TInt SwitchOpenFile(const TDesC& aFilename);
	IMPORT_C TInt SwitchCreateFile(const TDesC& aFilename);
	IMPORT_C TInt SendMessage(TUid aUid, const TDesC8& aParams);

private:
	TInt CheckSwitchFile() const;
	void SendSystemEvent(TApaSystemEvent aEvent, TEventCode aType);
private:
	RWsSession& iWsSession;
	TInt iWgId;
	TInt iTApaTask_Reserved1;
	};

class TApaTaskList
/** Accesses tasks running on a device.

Tasks can be identified by document, application specific UID or by caption 
name.

Users of this class can also cycle through a set of tasks running a specific 
application, bringing each one, in turn, into the foreground.

@publishedAll
@released
@see TApaTask */
	{
public:	
	/** Defines the direction in which tasks are cycled to the foreground. This is used 
	by the CycleTasks() function.

	@see TApaTaskList::CycleTasks() */
	enum TCycleDirection
		{
		/** Cycles the task list forwards, i.e. the foreground task is moved to background, 
		bringing the next foremost task to the foreground. */
		EForwards,
		/** Cycles the list backwards, i.e. the task furthest from the foreground is brought 
		to the foreground, pushing what was the foremost task to the next ordinal 
		position. */
		EBackwards
		};
public:
	IMPORT_C TApaTaskList(RWsSession& aWsSession);
	IMPORT_C TApaTask FindApp(const TDesC& aAppName);
	IMPORT_C TApaTask FindDoc(const TDesC& aDocName);
	IMPORT_C TApaTask FindByPos(TInt aPos);
	IMPORT_C TApaTask FindApp(TUid aAppUid);
	IMPORT_C TInt CycleTasks(TUid aAppUid,TCycleDirection aDirection=EForwards);

private:
	void FindByPosL(TApaTask& aTask,TInt aPos);
private:
	RWsSession& iWsSession;
	TInt iTApaTaskList_Reserved1;
	};


#endif
