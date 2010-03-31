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
* Description: SyncML error codes
*
*/

#ifndef __SYNCMLERR_H__
#define __SYNCMLERR_H__

#include <e32std.h>

namespace SyncMLError
/** SyncML-specific error codes. 
	@publishedAll
	@released
*/
	{
	/** Base value for transport-related errors. */
	const TInt KErrTransportErrorBase					= -8321;
	/** Error with the request.

    The transport cannot send data as created. */
	const TInt KErrTransportRequest						= KErrTransportErrorBase;
	/** Error in the provided headers.

    The transport has not been suitably configured. */
	const TInt KErrTransportHeader						= KErrTransportErrorBase - 1;
	/** The URI does not exist. */
	const TInt KErrTransportSvrNoUri					= KErrTransportErrorBase - 2;
	/** There was a transport server error. */
	const TInt KErrTransportSvrError					= KErrTransportErrorBase - 3;
	/** Transport Authentification failure. */ 
	const TInt KErrTransportAuthenticationFailure		= KErrTransportErrorBase - 4;
	/** Transport disconnected the session. */
	const TInt KErrTransportDisconnected				= KErrTransportErrorBase - 5; 
	/** Base value for engine-related errors. */
	const TInt KErrSyncEngineErrorBase					= -8050;
	/** Transports could not connect to the server. */
	const TInt KErrConnectionError						= KErrSyncEngineErrorBase;
	/** Could not communicate with the server: possibly a time-out occurred. */
	const TInt KErrCannotCommunicateWithServer			= KErrSyncEngineErrorBase - 1;
	/** Database adapter failed to create an item. */
	const TInt KErrDatabaseAdapterIndexError			= KErrSyncEngineErrorBase - 2;
	/** Currently unused. */
	const TInt KErrParseCallbackError					= KErrSyncEngineErrorBase - 3;
	/** Currently unused. */
	const TInt KErrCommandInvalid						= KErrSyncEngineErrorBase - 4;
	/** Invalid session ID. */
	const TInt KErrSessionIdNotValid					= KErrSyncEngineErrorBase - 5;
	/** SyncML message did not specify a DTD version. */
	const TInt KErrVerDTDMissing						= KErrSyncEngineErrorBase - 6;
	/** SyncML message did not specify a protocol. */
	const TInt KErrProtoMissing							= KErrSyncEngineErrorBase - 7;
	/** Currently unused. */
	const TInt KErrSyncHdrMissing						= KErrSyncEngineErrorBase - 8;
	/** SyncML message did not specify a target location. */
	const TInt KErrTargetLocMissing						= KErrSyncEngineErrorBase - 9;
	/** SyncML message did not specify a source location. */
	const TInt KErrSourceLocMissing						= KErrSyncEngineErrorBase - 10;
	/** Currently unused. */	
	const TInt KErrTargetLocNameMissing					= KErrSyncEngineErrorBase - 11;
	/** Currently unused. */
	const TInt KErrSourceLocNameMissing					= KErrSyncEngineErrorBase - 12;
	/** Mapping of added item could not created. */
	const TInt KErrMappingInfoMissing					= KErrSyncEngineErrorBase - 13;
	/** Mapping has not been acknowledged by the server. */
	const TInt KErrMappingInfoNotAcked					= KErrSyncEngineErrorBase - 14;
	/** SyncML message specified an unsupported DTD version. */
	const TInt KErrVersionDTDNotSupported				= KErrSyncEngineErrorBase - 15;
	/** SyncML message specified an unsupported protocol. */
	const TInt KErrProtoNotSupported					= KErrSyncEngineErrorBase - 16;
	/** A status was received for a cmdId, but this cmdId was not sent. */
	const TInt KErrStatusCommandForCommandNotSent		= KErrSyncEngineErrorBase - 17;	
	/** A status was received but the command string does not matched the received one. */
	const TInt KErrStatusCommandNotTheSame				= KErrSyncEngineErrorBase - 18;
	/** Status command(s) were expected but are missing. */			
	const TInt KErrMissingStatusCommands				= KErrSyncEngineErrorBase - 19;
	/** Failed to add record in database. */
	const TInt KErrFailedToAddRecord					= KErrSyncEngineErrorBase - 20;
	/** Failed to replace record in database. */
	const TInt KErrFailedToReplaceRecord				= KErrSyncEngineErrorBase - 21;
	/** Failed to delete record in database. */
	const TInt KErrFailedToDeleteRecord					= KErrSyncEngineErrorBase - 22;
	/** XML parsing error. */
	const TInt KErrXmlParsingError						= KErrSyncEngineErrorBase - 23;
	/** There was an error reported in the reference toolkit. */
	const TInt KErrReferenceToolkitError				= KErrSyncEngineErrorBase - 24;
	/** No suitable database was found on the client device. */
	const TInt KErrClientDatabaseNotFound				= KErrSyncEngineErrorBase - 83;
	/** No suitable database was found on the server. */
	const TInt KErrServerDatabaseNotFound				= KErrSyncEngineErrorBase - 84;
	/** Currently unused. */
	const TInt KErrDevInfFileNotFound					= KErrSyncEngineErrorBase - 85;
	/** Object is too large to send to server. */
	const TInt KErrObjectTooLargeToSendToServer			= KErrSyncEngineErrorBase - 86;
	/** Sync is going to be slow. */
	const TInt KErrSlowSync								= KErrSyncEngineErrorBase - 87;
	/** Failed to get record from DevMan. */
	const TInt KErrFailedToGetRecord					= KErrSyncEngineErrorBase - 88;
	/** User interaction failed. */
	const TInt KErrUserInteractionFailed				= KErrSyncEngineErrorBase - 89;
	/** Large object size mismatch. */
	const TInt KErrStatusSizeMismatch					= KErrSyncEngineErrorBase - 90;
	/** Data Provider close failed. */
	const TInt KErrFailedToCloseDatabase				= KErrSyncEngineErrorBase - 91;

    const TInt KErrPhoneOnOfflineMode                   = KErrSyncEngineErrorBase - 92;

    const TInt KErrAuthenticationFailure                = KErrSyncEngineErrorBase - 93;

    const TInt KErrGeneral                              = KErrSyncEngineErrorBase - 94;

	/** Base value for push message parser-related errors. */
	const TInt KErrPushMessageParserErrorBase					= -8451;		// 8451 - 8480
	/** Push message is too short. */
	const TInt KErrMessageTooShort					= KErrPushMessageParserErrorBase;
	/** Push message is corrupt. */
	const TInt KErrMessageIsCorrupt					= KErrPushMessageParserErrorBase - 1;
	/** Profile has no Transport ID. */
	const TInt KErrBadTransportId					= KErrPushMessageParserErrorBase - 2;
	/** Push message has no body. */
	const TInt KErrNoNotificationBody				= KErrPushMessageParserErrorBase - 3;
	/** Push message specifies an unsupported version. */
	const TInt KErrWrongVersion						= KErrPushMessageParserErrorBase - 4;
	/** Push message specifies an unsupported version. */
	const TInt KErrUnsupportedMimeType				= KErrPushMessageParserErrorBase - 5;		
	/** Currently unused. */
	const TInt KErrNoSuchTask						= KErrPushMessageParserErrorBase - 6;
	/** Push message specifies an unknown type of sync. */
	const TInt KErrUnknownSyncType					= KErrPushMessageParserErrorBase - 7;
	/** Push message specifies an unknown profile. */
	const TInt KErrUnknownProfile					= KErrPushMessageParserErrorBase - 8;
	/** Currently unused. */
	const TInt KErrInvalidProfile					= KErrPushMessageParserErrorBase - 9;
	/** Unsupported (USERNETWPIN or USERPIN) security mechanism specified. */
	const TInt KErrInvalidCredentials				= KErrPushMessageParserErrorBase - 10;
	/** Currently unused. */
	const TInt KErrNoCredentials					= KErrPushMessageParserErrorBase - 11;
	/** Failed to verify the generated HMAC value. */
	const TInt KErrIntegrityFailureHMAC				= KErrPushMessageParserErrorBase - 12;
	/** Currently unused. */
	const TInt KErrMustUsageUriNotComplete			= KErrPushMessageParserErrorBase - 13;
	/** Push message has invalid DM account URI. */
	const TInt KErrDMAccUriIsCorrupt				= KErrPushMessageParserErrorBase - 14;
	/** Push message has invalid DM connection URI. */
	const TInt KErrDMConUriIsCorrupt				= KErrPushMessageParserErrorBase - 15;
	/** Push message has missing characteristic. */
	const TInt KErrParmNameNotInProvDoc				= KErrPushMessageParserErrorBase - 17;
	/** Push message has missing or invalid App Id. */
	const TInt KErrInvalidAppIdValue				= KErrPushMessageParserErrorBase - 18;
	/** Push message has missing or invalid TO-NAPID. */
	const TInt KErrInvalidToNapIdValue				= KErrPushMessageParserErrorBase - 19;
	/** Push message has missing or invalid Provider-ID. */
	const TInt KErrInvalidProviderIdValue			= KErrPushMessageParserErrorBase - 20;
	/** Push message has missing or invalid AAUTHLEVEL. */
	const TInt KErrEmptyAauthLevelValue				= KErrPushMessageParserErrorBase - 21;
	/** Push message has missing or invalid APPSRV */
	const TInt KErrAppSrvAAuthLevelNotFound			= KErrPushMessageParserErrorBase - 22;
	/** Push message has missing or invalid AppAuth Client */
	const TInt KErrClientAAuthLevelNotFound			= KErrPushMessageParserErrorBase - 23;
	/** Currently unused. */
	const TInt KErrInvalidAppAuth					= KErrPushMessageParserErrorBase - 24;
	/** Push message has missing or invalid APPLICATION characteristic */
	const TInt KErrNoApplicationCharac				= KErrPushMessageParserErrorBase - 25;
	/** Push message has missing or invalid APPAUTH characteristic. */
	const TInt KErrNoAppAuthCharac	 				= KErrPushMessageParserErrorBase - 27;
	/** Currently unused. */
	const TInt KErrMissingRequiredParmInSvr			= KErrPushMessageParserErrorBase - 29;
	/** Currently unused. */
	const TInt KErrMissingRequiredParmInClient	    = KErrPushMessageParserErrorBase - 30;
	/** Missing APPADDR characteristic or sub characteristic */
	const TInt KErrAppAddrCharacNotFound			= KErrPushMessageParserErrorBase - 33;
	/** Unsupported WBXML version */
	const TInt KErrUnsupportedVersion				= KErrPushMessageParserErrorBase - 34;
	/** Prov Document identifier not WAP Provisoning version 1.0 */
	const TInt KErrWrongProvPublicDocId				= KErrPushMessageParserErrorBase - 35;

	/** Base value for client API-related errors. */
	const TInt KErrClientAPIBase					= -8501;		// -8501 -> -8700
	/** The requested profile does not exist. */
	const TInt KErrProfileNotFound					= KErrClientAPIBase;
	/** The requested connection does not exist within the profile. */
	const TInt KErrConnectionNotFound				= KErrClientAPIBase - 1;
	/** The requested task does not exist within the profile. */
	const TInt KErrTaskNotFound						= KErrClientAPIBase - 2;
	/** The requested transport adaptor does not exist. */
	const TInt KErrTransportNotFound				= KErrClientAPIBase - 3;
	/** The requested data provider does not exist. */
	const TInt KErrDataProviderNotFound				= KErrClientAPIBase - 4;
	/** The requested job has completed. */
	const TInt KErrJobNotFound						= KErrClientAPIBase - 5;
	/** The requested object is pending deletion. */
	const TInt KErrObjectPendingDelete				= KErrClientAPIBase - 6;
	/** The object to modify or delete is currently in use. */
	const TInt KErrObjectInUse						= KErrClientAPIBase - 7;
	/** The specified profile is not available for edit,
	    e.g. a Device Management profile, or open for edit by another client. */
	const TInt KErrProfileAccessDenied				= KErrClientAPIBase - 8;
	/** The requested data stream cannot be found in the Data Store. */
	const TInt KErrSuspended						= KErrClientAPIBase - 9;
	/** The requested data stream cannot be found in the Data Store. */
	const TInt KErrDataDepotStreamNotFound			= KErrClientAPIBase - 10;

    /** Server id from profile does not match with id from syncML server. */
    const TInt KErrServerIdNotMatching              = KErrClientAPIBase - 11;
    
    /** Server certificate is invalid or not in Store. */
    const TInt KErrInvalidCert			= -8702;

	}

#endif // __SYNCMLERR_H__
