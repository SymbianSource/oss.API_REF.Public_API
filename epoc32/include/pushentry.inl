// Copyright (c) 2000-2009 Nokia Corporation and/or its subsidiary(-ies).
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
// WAP Push Message Inline functions  File for the Utility class
// 
//



/**
 @file
 @publishedPartner
 @released
*/

#include <msvapi.h>

inline const TMsvEntry& CPushMsgEntryBase::Entry() const
/** 
Gets the object's current message server index entry.

@return 
Message server index entry 
*/
	{
	return iEntry;
	}


inline TInt CPushMsgEntryBase::Status() const
/** 
Gets the Status value for the Push Message entry.

@return 
Status value: a TPushMsgStatus value 
*/
	{
	//The status value is one from an enumerated set. It is used to set Bits 0-3 
	//of the iMtmData1 member of TMsvEntry. A bitwise AND is performed with iMtmData1 
	//and a mask with value 0x000F to extract the status value.

	return iEntry.MtmData1() & KPushMaskOnlyStatus;//bitwise & to get Bits 0-3
	}
