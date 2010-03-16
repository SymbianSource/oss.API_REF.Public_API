// Copyright (c) 2005-2009 Nokia Corporation and/or its subsidiary(-ies).
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

#ifndef __CALNOTIFICATION_H__
#define __CALNOTIFICATION_H__

/** The calendar publish and subscribe category
@publishedAll

@released
*/
const TUid KCalPubSubCategory = { 0x10003a5b };

/** Used for subcribing to either todos or event changes
@publishedAll
@released
*/
enum TCalPubSubValues
	{
	/** subscribe to todo notifications */
	ECalPubSubTodoNotification,
	/** subscribe to event notifications */
	ECalPubSubEventNotification,
	};
	
/** The publish and subscribe data 
@publishedAll
@released
*/
struct TCalPubSubData
	{
	/** The time that the calendar change took place, in universal (UTC) time */
	TTime iTimeOfChangeUtc;
	/** The filename hashed into a 4-byte integer. CalInterimAPI provides a method to find the filename from this value. */
	TUint32 iFileNameHash;
	};

#endif // __CALNOTIFICATION_H__
