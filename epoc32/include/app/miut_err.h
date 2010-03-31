// Copyright (c) 1998-2009 Nokia Corporation and/or its subsidiary(-ies).
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

#ifndef __MIUT_ERR_H__
#define __MIUT_ERR_H__

// Minimum value for an MTM-specific error
/**
@publishedAll
@released
*/
const TInt KMiutErrorBase						= (-170);

// POP3-specific error codes

/**
@publishedAll
@released
*/
const TInt KPop3ErrorBase						= KMiutErrorBase;

/**
@publishedAll
@released
*/
const TInt KPop3CannotConnect					= KPop3ErrorBase;

/**
@publishedAll
@released
*/
const TInt KPop3InvalidUser						= KPop3ErrorBase-1;

/**
@publishedAll
@released
*/
const TInt KPop3InvalidLogin					= KPop3ErrorBase-2;

/**
@publishedAll
@released
*/
const TInt KPop3CannotCreateApopLogonString		= KPop3ErrorBase-3;

/**
@publishedAll
@released
*/
const TInt KPop3ProblemWithRemotePopServer		= KPop3ErrorBase-4;

/**
@publishedAll
@released
*/
const TInt KPop3CannotOpenServiceEntry			= KPop3ErrorBase-5;

/**
@publishedAll
@released
*/
const TInt KPop3CannotSetRequiredFolderContext	= KPop3ErrorBase-6;

/**
@publishedAll
@released
*/
const TInt KPop3InvalidApopLogin				= KPop3ErrorBase-7;

/**
@publishedAll
@released
*/
const TInt KPopTopError							= (-179);

// IMSK-specific error code
/**
@publishedAll
@released
*/
const TInt KImskBaseError						= (-180);

/**
@publishedAll
@released
*/
const TInt KImskErrorDNSNotFound				= KImskBaseError;

/**
@publishedAll
@released
*/
const TInt KImskErrorControlPanelLocked			= KImskBaseError-1;

/**
@publishedAll
@released
*/
const TInt KImskErrorISPOrIAPRecordNotFound		= KImskBaseError-2;

/**
@publishedAll
@released
*/
const TInt KImskErrorActiveSettingIsDifferent	= KImskBaseError-3;

/**
@publishedAll
@released
*/
const TInt KImskSecuritySettingsFailed			= KImskBaseError-4;

/**
@publishedAll
@released
*/
const TInt KImskSSLTLSNegotiateFailed			= KImskBaseError-5;

/**
@publishedAll
@released
*/
const TInt KImskTopError						= (-190);

// error codes -190 to -199 are used by Sockets

// IMAP-specific error codes
/**
@publishedAll
@released
*/
const TInt KImapBaseError						= (-200);

/**
@publishedAll
@released
*/
const TInt KErrImapConnectFail					= KImapBaseError;

/**
@publishedAll
@released
*/
const TInt KErrImapServerFail					= KImapBaseError-1;

/**
@publishedAll
@released
*/
const TInt KErrImapServerParse					= KImapBaseError-2;

/**
@publishedAll
@released
*/
const TInt KErrImapServerBusy					= KImapBaseError-3;

/**
@publishedAll
@released
*/
const TInt KErrImapServerVersion				= KImapBaseError-4;

/**
@publishedAll
@released
*/
const TInt KErrImapSendFail						= KImapBaseError-5;

/**
@publishedAll
@released
*/
const TInt KErrImapBadLogon						= KImapBaseError-6;

/**
@publishedAll
@released
*/
const TInt KErrImapSelectFail					= KImapBaseError-7;

/**
@publishedAll
@released
*/
const TInt KErrImapWrongFolder					= KImapBaseError-8;

/**
@publishedAll
@released
*/
const TInt KErrImapServerNoSecurity				= KImapBaseError-9;

/**
@publishedAll
@released
*/
const TInt KErrImapServerLoginDisabled			= KImapBaseError-10;

/**
@publishedAll
@released
*/
const TInt KErrImapTLSNegotiateFailed  			= KImapBaseError-11;

/**
@publishedAll
@released
*/
const TInt KErrImapCantDeleteFolder  			= KImapBaseError-12;

/**
@publishedAll
@released
*/
const TInt KErrImapInvalidServerResponse  		= KImapBaseError-13;

/**
@publishedAll
@released
*/
//This POP error declared in IMAP error range, 
//since there is no scope to declare the error within pop range. 
const TInt KErrPop3ServerAlreadyConnected 		= KImapBaseError-14;

/**
@publishedAll
@released
*/
const TInt KImapTopError						= (-219);

// DMSS-specific error codes
/**
@publishedAll
@released
*/
const TInt KDmssBaseError						= (-220);

/**
@publishedAll
@released
*/
const TInt KDmssUnknownErr						= (KDmssBaseError-1);

/**
@publishedAll
@released
*/
const TInt KDmssMailboxUnavailableErr			= (KDmssBaseError-2);

/**
@publishedAll
@released
*/
const TInt KDmssActionAbortedErr				= (KDmssBaseError-3);

/**
@publishedAll
@released
*/
const TInt KDmssActionNotTakenErr				= (KDmssBaseError-4);

/**
@publishedAll
@released
*/
const TInt KDmssCmdUnrecognisedErr				= (KDmssBaseError-5);

/**
@publishedAll
@released
*/
const TInt KDmssSyntaxErrorErr					= (KDmssBaseError-6);

/**
@publishedAll
@released
*/
const TInt KDmssCmdNotImplementedErr			= (KDmssBaseError-7);

/**
@publishedAll
@released
*/
const TInt KDmssBadSequenceErr					= (KDmssBaseError-8);

/**
@publishedAll
@released
*/
const TInt KDmssParamNotImplementedErr			= (KDmssBaseError-9);

/**
@publishedAll
@released
*/
const TInt KDmssMailboxNoAccessErr				= (KDmssBaseError-10);

/**
@publishedAll
@released
*/
const TInt KDmssExceededStorageErr				= (KDmssBaseError-11);

/**
@publishedAll
@released
*/
const TInt KDmssMailboxNameErr					= (KDmssBaseError-12);

/**
@publishedAll
@released
*/
const TInt KDmssTransactionFailedErr			= (KDmssBaseError-13);

/**
@publishedAll
@released
*/
const TInt KDmssTimeOutErr						= (KDmssBaseError-14);

/**
@publishedAll
@released
*/
const TInt KDmssTopError						= (-239);

// SMTP client-specific error codes
/**
@publishedAll
@released
*/
const TInt KSmtpBaseError						= (-240);

/**
@publishedAll
@released
*/
const TInt KSmtpNoMailFromErr					=  KSmtpBaseError;

/**
@publishedAll
@released
*/
const TInt KSmtpUnknownErr						= (KSmtpBaseError-1);

/**
@publishedAll
@released
*/
const TInt KSmtpBadMailFromAddress				= (KSmtpBaseError-2);

/**
@publishedAll
@released
*/
const TInt KSmtpBadRcptToAddress				= (KSmtpBaseError-3);

/**
@publishedAll
@released
*/
const TInt KSmtpLoginRefused					= (KSmtpBaseError-4);

/**
@publishedAll
@released
*/
const TInt KSmtpNoMsgsToSendWithActiveSettings	= (KSmtpBaseError-5);

/**
@publishedAll
@released
*/
const TInt KErrSmtpTLSNegotiateFailed 			= (KSmtpBaseError-6);

/**
@publishedAll
@released
*/
const TInt KErrSmtpBufferOverFlow 			    = (KSmtpBaseError-7);

/**
@publishedAll
@released
*/
const TInt KSmtpTopError					    = (-249);
 
// IMCM error codes
/**
@publishedAll
@released
*/
const TInt KImcmBaseError						= (-250);

/**
@publishedAll
@released
*/
const TInt KImcmHTMLPartNotPopulated			=  KImcmBaseError;

/**
@publishedAll
@released
*/
const TInt KImcmInvalidMessageStructure			= (KImcmBaseError-1);

// POPS error codes
/**
@publishedAll
@released
*/
const TInt KPop3BaseError						= (-260);

/**
@publishedAll
@released
*/
const TInt KErrPop3TLSNegotiateFailed			=  KPop3BaseError;

/**
@internalComponent
@released
*/
enum TImcmPanic
	{
	EOffOpNoBodyText = 0,
	EOffOpBadMtmTypeUid = 1,
	EOffOpNoCMsvEntrySet = 2,
	EOffOpEntryShouldBeFolder = 3,
	EOffOpTwoSameLinesNotAllowed = 4,
	EOffOpNoMemory = 5,
	EOffOpInvalidConstruction = 6,
	EOffOpListOutOfSync = 7,
	EOffOpNoMtmParameters = 8,
	EMiutBadStreamVersion = 9,
	EEntryIsNotMessage = 10,
	EMiutArrayHasOddNumberOfElements = 11,		// ie there should be even number of entries in array
	EMiutLocalServiceIdSet = 12,				// iServiceId should not be set to Local
	EPopcMTMNoBodyText = 13,
	EPopcMTMBadMtmTypeUid = 14,
	EPopcMTMNoCMsvEntrySet = 15,
	EPopcMTMOperationNULL = 16,
	EPopcMTMNotAServiceEntry = 17,
	EPopcUnknownNewEmailType = 18,
	EPopcUnknownSyncFunction = 19,
	ESmtcMTMNoBodyText = 20,
	ESmtcMTMBadMtmTypeUid = 21,
	ESmtcMTMNoCMsvEntrySet = 22,
	ESmtcMTMOperationNULL = 23,
	ESmtcMTMNotAServiceEntry = 24,
	ESmtcUnknownNewEmailType = 25,
	ESmtcUnknownSyncFunction = 26,
	ESmtcMTMStoringBadEntryType = 27,
	ESmtcMTMRestoringBadEntryType = 28,
	ESmtcMTMNotAMessageEntry = 29,
	EMiutActiveInFinalProgress = 30,
	EImpcNoBodyText = 31,
	EImpcBadMtmTypeUid = 32,
	EImpcNoCMsvEntrySet = 33,
	EImpcEntryShouldBeFolder = 34,
	EImpcTwoSameLinesNotAllowed = 35,
	EImpcNoMemory = 36,
	EImpcInvalidConstruction = 37,
	EImpcBadServiceEntry = 38,
	EImpcNoBaseMtm = 39,
	EImpcNoAddresseeList = 40,
	EImpcInvalidProgress = 41,
	EImpcNotSupported = 42,
	EImpcMTMNotAMessageEntry = 43,
	EImpcMTMNotAServiceEntry = 44,
	EImcmMessageEntryHasMoreThanOneFolder = 45,
	EImcmUnknownState = 46,
	EImcmFinalProgressFailed = 47,
	EImcmNoEikonEnvironment = 48,
	EImcmSetVersionNotSupported = 49,
	EImcmSystemDefaultCharsetNotSupported = 50,
 	EImcmHtmlConverterNotFound = 51,
	EImcmUnknownMtm = 52,
	EImEmailOpUnknownAttachmentType = 53,
	EImcmNonIdleRetrievalState = 54,
	EImcmIdleRetrievalState = 55,
	EImcmSyncDownloadRulesInvalidPos1 = 56,
	EImcmSyncDownloadRulesInvalidPos2 = 57,
	EImcmSyncDownloadRulesInvalidPos3 = 58,
	EImcmSyncDownloadRulesInvalidBearerTypes1 = 59,
	EImcmSyncDownloadRulesInvalidBearerTypes2 = 60,
	EImcmSyncDownloadRulesInvalidBearerTypes3 = 61,
	EImcmTransportBufferSizesInvalidPos1 = 62,
	EImcmTransportBufferSizesInvalidPos2 = 63,
	EImcmTransportBufferSizesInvalidPos3 = 64,
	EImcmTransportBufferSizesInvalidBearerTypes1 = 65,
	EImcmTransportBufferSizesInvalidBearerTypes2 = 66,
	EImcmTransportBufferSizesInvalidBearerTypes3 = 67,
	EImcmTransportBufferSizesInvalidFetchRequestSize = 68,
	EImcmTransportBufferSizesInvalidMaxOutstandingFetchResponses = 69,
	EImcmMobilityAccountsListInvalidPos1 = 70,
	EImcmMobilityAccountsListInvalidPos2 = 71,
	EImcmMobilityAccountsListInvalidPos3 = 72,
	EImcmMobilityAccountsListInvalidIAPListCount = 73
	};

/**
@internalComponent
*/
GLREF_C void gPanic(TImcmPanic aPanic);

#endif // __MIUT_ERR_H__
