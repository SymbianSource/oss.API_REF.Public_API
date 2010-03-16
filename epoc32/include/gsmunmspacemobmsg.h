// Copyright (c) 2004-2009 Nokia Corporation and/or its subsidiary(-ies).
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
// Multimode SMS common API header file.
// Describes common Telephony interface types for SMS messaging.
// The types are duplicated from ETELMM.h in an effort to separate SMS from ETEL.
// Correspondent ETEL types could be found in ETELMM.h, class RMobileSmsMessaging.
// 
//



/**
 @file
 @publishedAll
 @released
*/


#ifndef __GSMUNMSPACEMOBMSG_H__
#define __GSMUNMSPACEMOBMSG_H__

/**
 *  PDU types.
 *  
 *  Modes: Common
 *  
 *  @see class class RMobileSmsMessaging
 */
namespace NMobileSmsMessaging
	{
	// Definitions for sizes of TPDU and User Data fields
	enum
		{
		KGsmTpduSize = 165,		// 140 bytes user data + 25 bytes TPDU header
		KCdmaTpduSize  = 256	// Max size of Bearer Data in Transport Layer message
		};

	/** A typedef'd buffer for GSM or WCDMA message data.*/
	typedef TBuf8<KGsmTpduSize>	TMobileSmsGsmTpdu;
	/** A typedef'd buffer for CDMA message data.*/
	typedef TBuf8<KCdmaTpduSize> TMobileSmsCdmaTpdu;
	}

#endif // __GSMUNMSPACEMOBMSG_H__
