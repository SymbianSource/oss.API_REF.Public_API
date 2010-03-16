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
* Description: Definition of Constants. This is part of remotemgmt_plat
*
*/
///////////////////////////////////////////////////////////////////////////////
// SyncMLDef.h
//
// v09
//
///////////////////////////////////////////////////////////////////////////////
#ifndef __SYNCMLDEF_H__
#define __SYNCMLDEF_H__

#include <e32std.h>

/**
	Maximum length of a transport property name.
*/
const TInt KSmlMaxTransportPropertyNameLen = 32;

/** Profile ID typedef. */
typedef TInt TSmlProfileId;
/** Task ID typedef. */
typedef TInt TSmlTaskId;
/** Transport ID typedef. */
typedef TInt TSmlTransportId;
/** Connection ID typedef. */
typedef TInt TSmlConnectionId;
/** Data provider ID typedef. */
typedef TInt TSmlDataProviderId;
/** Profile creator ID typedef. */
typedef TInt TSmlCreatorId;
/** Job ID typedef. */
typedef TInt TSmlJobId;

/**
	Invalid (null) identifier.
*/
const TInt KSmlNullId = 0;

/**
	Unused parameter from a session event
*/
const TInt32 KUnusedAdditionalData = -1;

/**
	Setting for action to take as a result of a SyncML push message, (e.g. a server-alerted synchronisation request).
	Note that certain types of push message, (e.g. DevMan Bootstrap), will override this setting.
*/
enum TSmlServerAlertedAction
	{
	/** Allow the push message parser plugin to specify user interaction type. */
	ESmlUseSANRequestedSetting,
	/** Automatically run the synchronisation without user intervention. */
	ESmlEnableSync,
	/** Prevent the synchronisation. */
	ESmlDisableSync,
	/** Inform the user of the synchronisation. */
	ESmlInformSync,
	/** Get confirmation of the synchronisation from the user. */
	ESmlConfirmSync,
	/** Use the global user interaction type (only allowed for the profile setting) */
	ESmlUseGlobalSetting,
	};

/**
	Flags for synchronisation types.
*/
enum TSmlSyncType
	{
	/** Two-way sync.
	
	A normal sync type in which the client and the server exchange information about modified data in these devices. 
	The client sends the modifications first.
	*/
	ESmlTwoWay,
	/** One-way sync from server.
	
	A sync type in which the client gets all modifications from the server, but the client does not send 
	its modifications to the server. */
	ESmlOneWayFromServer,
	/** One-way sync from client.
	
	A sync type in which the client sends its modifications to the server, but the server does not send 
	its modifications back to the client. */
	ESmlOneWayFromClient,
	/** Slow sync.
	
	A form of two-way sync in which the client sends all its data to the server, and the server does 
	the sync analysis for this data and the data in the server. The server may undertake a field by field analysis. */
	ESmlSlowSync,
	/** Refresh sync from server.
	
	A sync type in which the client exports all its data to the server. The server replaces all data in 
	the target database with the data sent by the client. */
	ESmlRefreshFromServer,
	/** Refresh sync from client.
	
	A sync type in which the client exports all its data to the server. The server replaces all data in 
	the target database with the data sent by the client.*/
	ESmlRefreshFromClient,
	};

/**
	Protocol types.
*/
enum TSmlUsageType
	{
	/** Data synchronisation. */
	ESmlDataSync,
	/** Device management. */
	ESmlDevMan,
	};


/**
	Protocol versions.
*/
enum TSmlProtocolVersion
	{
	/** Version 1.1.2 */
	ESmlVersion1_1_2,
	/** Version 1.2 */
	ESmlVersion1_2,
	};


/**
	Transport capabilities.
*/
enum TSmlTransportCap
	{
	/** Transport can listen for incoming connections. */
	ESmlCapCanListen,
	/** Transport can make outgoing connections. */
	ESmlCapCanConnect,
	};

/**
	Flags specifying how background synchronisation results are displayed to the user.
*/
enum TSmlDisplayResult
	{
	/** Do not display results. */
	ESmlDisplayNoResults,
	/** Display all results. */
	ESmlDisplayAllResults,
	/** Display errors only. */
	ESmlDisplayErrorsOnly,
	};

/**
	Flags specifying how background synchronisation progress is displayed to the user.
*/
enum TSmlDisplayProgress
	{
	/** Never display the progress notifier. */
	ESmlDisplayNoProgress,
	/** Display progress notifier if a job is in progress, but only if no clients are observing the progress. */
	ESmlDisplayUnObservedProgress,
	/** Always display the progress notifier when a job is in progress. */
	ESmlDisplayAllProgress,
	};

/**
	Global settings supported by the RSyncMLSettings class.
	@see RSyncMLSettings
*/
enum TSmlGlobalSetting
	{
	/**
		Specifies how users are notified of synchronisations completing.
		Value is one of TSmlDisplayResult.
	*/
	ESmlSettingDisplayBgResult,
	/**
		Specifies whether progress should be displayed in a notifier.
		Value is one of TSmlDisplayProgress.
	*/
	ESmlSettingDisplayBgProgress,
	/**
		Specifies the default action to take in response to a server alert.
		Value is one of TSmlServerAlertedAction.
	*/
	ESmlSettingDefaultSAAction,
	};

#endif // __SYNCMLDEF_H__
