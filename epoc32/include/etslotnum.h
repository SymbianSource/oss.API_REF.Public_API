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



/**
 @file
 @publishedAll
 @released 
*/

#if !defined(__ET_SLOTNUM_H__)
#define __ET_SLOTNUM_H__

//
//	Number of server-side slots for each notification (greater than 1)
//  These are suggested sizes and can be over-ridden by TSY by setting a different
//  number in the NumberOfSlotsL method
//

//
// RMobilePhone
//
/**
@internalTechnology
*/
const TUint KSlotNotifyModeChange = 2;
/**
@internalComponent
*/
const TUint KSlotNotifyBatteryInfoChange = 2;
const TUint KSlotNotifySignalStrengthChange = 2;
const TUint KSlotNotifyCurrentNetworkChange = 2;
const TUint KSlotNotifyNetworkRegistrationStatusChange = 3;
const TUint KSlotNotifyNITZInfoChange = 2;
const TUint KSlotNotifyCallServiceCapsChange = 2;
const TUint KSlotNotifyCostInfoChange = 3;
const TUint KSlotNotifySecurityEvent = 2;
const TUint KSlotNotifyMessageWaiting = 2;

//
// RMobilePhoneStore
//
/**
@internalComponent
*/
const TUint KSlotNotifyStoreEvent = 3;

//
// RMobileCall
//
/**
@internalComponent
*/
const TUint KSlotNotifyHscsdInfoChange = 2;
const TUint KSlotNotifyMobileCallCapsChange = 3;
const TUint KSlotNotifyCallEvent = 2;
const TUint KSlotNotifyMobileCallStatusChange = 3;
const TUint KSlotNotifyUUSCapsChange = 2;

//
// RMobileLine
//
/**
@internalComponent
*/
const TUint KSlotNotifyMobileLineStatusChange = 3;

//
// RMobileConferenceCall
//
/**
@internalComponent
*/
const TUint KSlotNotifyConferenceCapsChange = 2;
const TUint KSlotNotifyConferenceStatusChange = 2;
const TUint KSlotNotifyConferenceEvent = 2;

//
// RMobileSmsMessaging
//
/**
@internalComponent
*/
const TUint KSlotReceiveSmsMessage = 5;

//
// RMobileBroadcastMessaging
//
/**
@internalComponent
*/
const TUint KSlotReceiveBroadcastMessage = 3;

//
// RMobileUssdMessaging
//
/**
@internalComponent
*/
const TUint KSlotReceiveUssdMessage = 5;



#endif	  
