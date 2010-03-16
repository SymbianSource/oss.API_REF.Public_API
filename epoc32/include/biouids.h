// Copyright (c) 1999-2009 Nokia Corporation and/or its subsidiary(-ies).
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
// BIOUUIDS.H
// Contains the TUid defines for the Bio Messaging 
// 
//



/**
 @file
 @publishedAll
 @released
*/

#if !defined(__BIOUTILS_H__)
#define __BIOUTILS_H__

//forward declarations
/**
* @publishedAll
* @released
*/
class TUid;
/**
*UID of the Smart Message Parser DLL.
* @publishedPartner
* @released
*/
const TUid KUidSmartMessageParserDll    = { 0x10001251};
/**
* BIO specific error/panic code base. 
* @publishedPartner
* @released
*/
const TInt KBIOMessageBaseError				= -505;
/**
* BIO message not found error. 
* @publishedPartner
* @released
*/
const TInt KBIOMessageNotFound				= KBIOMessageBaseError;
/**
* BIO server MTM already active error. 
* @publishedPartner
* @released
*/
const TInt KBIOMessageSvrMtmNotInactive		= KBIOMessageBaseError-1;
/**
* No BIO parser error. 
* @publishedPartner
* @released
*/
const TInt KBIOMessageNoParserCreated		= KBIOMessageBaseError-2;  
/** 
* BIO parser in use error. 
* @publishedPartner
* @released
*/
const TInt KBIOMessageParserDllStillInUse	= KBIOMessageBaseError-3;  
/**    
* BIO operation already active error. 
* @publishedPartner
* @released
*/
const TInt KBIOMessageOperationNotInactive	= KBIOMessageBaseError-4;
/**
* BIO server MTM operation not supported. 
* @publishedPartner
* @released
*/
const TInt KBIOMessageSvrNotSupported		= KBIOMessageBaseError-5;
/**
* Unused. 
* @internalComponent
* @removed
*/
const TUid KUidMsvNbsEditor={0x10001264};

//  New BIO Messaging TUids
/**
* Stream ID used for storing parsed BIO data.
* @internalAll
* @released
*/
const TUid KUidMsvBIODataStream			= {0x10005268}; // stream used for storing parsed data

//  BIO Mtm components

/**
* BIO message type UID. 
* @publishedAll
* @released
*/
const TUid KUidBIOMessageTypeMtm		= {0x10001262};
/**
* BIO client MTM UID. 
* @internalTechnology
* @released
*/
const TUid KUidBIOMessageClientMtmDll	= {0x1000125A}; //previously NBSC, now BIOC
/**
* BIO server MTM UID. 
* @internalTechnology
* @released
*/
const TUid KUidBIOMessageServerMtmDll	= {0x1000125C}; //previously NBSS, now BIOS
/**
* BIO UI MTM UID. 
* @internalTechnology
* @released
*/
const TUid KUidBIOMessageUiLayerMtmDll	= {0x10001265}; //previously NBUM, now BIUM
/**
* BIO message viewer UID. 
* @internalTechnology
* @released
*/
const TUid KUidBIOMessageViewerApp		= {0x10001264}; //previously NBED,now BIED

#endif *__BIOUTILS_H__
