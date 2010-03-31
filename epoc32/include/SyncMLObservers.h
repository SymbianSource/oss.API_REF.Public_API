/*
* Copyright (c) 2005 Nokia Corporation and/or its subsidiary(-ies). 
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
* Description: Interface to receive notifications of SyncML session and synchronization progress events.
*
*/

#ifndef __SYNCMLOBSERVERS_H__
#define __SYNCMLOBSERVERS_H__
#define SYNCML_V3
//
#include <e32std.h>
//

///////////////////////////////////////////////////////////////////////////////
// MSyncMLEventObserver
//  Observer of session events.
///////////////////////////////////////////////////////////////////////////////
class MSyncMLEventObserver
/** 
	Interface to receive notifications of SyncML session events. 
	
	Notifications are requested through RSyncMLSession::RequestEventL().
	@publishedAll 
	@released 
*/
	{
public:
	enum TEvent
	/** SyncML session event types.	*/
		{
		/** Job has started. */
		EJobStart,
		/** Job has failed to start. */
		EJobStartFailed,
		/** Job has stopped. */
		EJobStop,
		/** Job could not be parsed, and will not be processed. */
		EJobRejected,
		/** A profile has been created. */
		EProfileCreated,
		/** A profile has been changed. */
		EProfileChanged,
		/** A profile has been deleted. */
		EProfileDeleted,
		/** A transport has timed-out. */
		ETransportTimeout,
		/** The SyncML Agent is suspended. This can occur when processing pauses in order to perform a back-up. */
		EServerSuspended,
		/** The SyncML Agent has shutdown. */
		EServerTerminated
		};
public:
/**
Receives a SyncML session event. 

The following table lists the meaning of the identifier and error parameters for the various event types.
@code
TEvent				aIdentifier		aError		aAdditionalData	
EJobStart			ID of the new job.	KErrNone.	KUnusedAdditionalData.
EJobStartFailed			Unused.			Reason for fail.	KUnusedAdditionalData.
EJobStop			ID of the job.		Completion code.	KUnusedAdditionalData.
EJobRejected			Unused.			Reason for rejection.	KUnusedAdditionalData.
EProfileCreated			ID of the profile.	Unused.	The usage type( either ESmlDataSync or ESmlDevMan) or an error code.
EProfileChanged			ID of the profile.	Unused.	The usage type( either ESmlDataSync or ESmlDevMan) or an error code.
EProfileDeleted			ID of the profile.	Unused.	KUnusedAdditionalData.
ETransportTimeout		ID of the transport.	KErrTimedOut.	KUnusedAdditionalData.
EServerSuspended		Non-zero if the server	KErrNone when entering. When exiting,  
				is entering suspended 	any error encountered when reloading data.	KUnusedAdditionalData.
				state, zero on exiting.			
EServerTerminated		Unused.			KErrServerTerminated.	KUnusedAdditionalData.
@endcode

@param				 aEvent				 Event type.
@param				 aIdentifier		 When the event relates to an object with an ID (job or profile), the ID.
@param				 aError				 When the event relates to an error, the error code.
@param				 aAdditionalData	 The value of this parameter can be:
										 KUnusedAdditionalData if additional data are unavailable,
										 ESmlDataSync if the event is generated during a Data Sync session,
										 ESmlDevMan if the event is generated during a Device Management session
*/
	virtual void OnSyncMLSessionEvent(TEvent aEvent, TInt aIdentifier, TInt aError, TInt aAdditionalData) = 0;
	};

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// MSyncMLProgressObserver
///////////////////////////////////////////////////////////////////////////////
/** 
	Interface to receive notifications of SyncML synchronisation progress events. 
	
	Notifications are requested through RSyncMLSession::RequestProgressL().
	@publishedAll
	@released
*/
class MSyncMLProgressObserver
	{
public:
	/** SyncML synchronisation progress events. */
	enum TStatus
		{
		/** Connecting to a SyncML server. */
		ESmlConnecting,
		/** Connected to a SyncML server. */
		ESmlConnected,
		/** Logging on to a SyncML server. */
		ESmlLoggingOn,
		/** Logged on to a SyncML server. */
		ESmlLoggedOn,
		/** Disconnected from a SyncML server. */
		ESmlDisconnected,
		/** Synchronisation has completed. */
		ESmlCompleted,
#ifdef SYNCML_V3
		/** Sending modifications to a SyncML server. DS only */
		ESmlSendingModificationsToServer,
		/** Receiving modifications from a SyncML server. DS only */
		ESmlReceivingModificationsFromServer,
		/** Sending mappings to a SyncML server. DS only */
		ESmlSendingMappingsToServer,
		/** Processing commands from a SyncML server. DM only*/
		ESmlProcessingServerCommands,
		/** Receiving commands from a SyncML server. DM only*/
		ESmlReceivingServerCommands,
#else // SYNCML_V3
		/** Sending data to a SyncML server.  */
		ESmlSendingData,
		/** Receiving data from a SyncML server. */
		ESmlReceivingData
#endif // SYNCML_V3
		};
	/** SyncML error levels. */
	enum TErrorLevel
		{
		/** Warning. A non-fatal error has occurred. Synchronisation continues.*/
		ESmlWarning,
		/** Fatal error. A fatal error has occurred. The synchronisation is stopped. */
		ESmlFatalError
		};

#ifdef SYNCML_V3
	/** Container class for number of items added, replaced, moved, deleted and failed. */
	class TSyncMLDataSyncModifications
		{
	public:
		TInt iNumAdded;
		TInt iNumReplaced;
		TInt iNumMoved;
		TInt iNumDeleted;
		TInt iNumFailed;
		};
#endif // SYNCML_V3

public:

	/**
	Receives notification of a synchronisation error.

	@param aErrorLevel	The error level.
	@param aError		The type of error. This is one of the SyncMLError error values.	
	@param aTaskId		The ID of the task for which the error occurred.
	@param aInfo1		An integer that can contain additional information about the error. Normally 0.
	@param aInfo2		An integer that can contain additional information about the error. Normally 0.
	*/
	virtual void OnSyncMLSyncError(TErrorLevel aErrorLevel, TInt aError, TInt aTaskId, TInt aInfo1, TInt aInfo2)= 0 ;

	/**
	Receives notification of synchronisation progress.
	
	@param aStatus	The current status, e.g. 'Connecting'.	
	@param aInfo1	An integer that can contain additional information about the progress.
	@param aInfo2	An integer that can contain additional information about the progress.
	*/
	virtual void OnSyncMLSyncProgress(TStatus aStatus, TInt aInfo1, TInt aInfo2)= 0;
#ifdef SYNCML_V3
	/**
	Receives notification of modifications to synchronisation tasks.

	@param aTaskId					The ID of the task.
	@param aClientModifications		Modifications made on the clients Data Store.
	@param aServerModifications		Modifications made on the server Data Store.
	*/
	virtual void OnSyncMLDataSyncModifications(TInt aTaskId,
									const TSyncMLDataSyncModifications& aClientModifications,
									const TSyncMLDataSyncModifications& aServerModifications)= 0;
#else // SYNCML_V3
	/**
	Receives notification of modifications to synchronisation tasks.

	@param aTaskId			The ID of the task.
	@param aNumAdded		Number of items added.
	@param aNumReplaced		Number of items replaced.
	@param aNumDeleted		Number of items deleted.
	*/
	virtual void OnSyncMLDataSyncModifications(TInt aTaskId, TInt aNumAdded, TInt aNumReplaced, TInt aNumDeleted)= 0;
#endif // SYNCML_V3

	};


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
#endif
