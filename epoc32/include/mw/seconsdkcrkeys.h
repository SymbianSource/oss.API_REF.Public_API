/*
* Copyright (c) 2007 Nokia Corporation and/or its subsidiary(-ies). 
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
* Description:  A CenRep interface for last used sync solutions
*
*/


/*! \file seconsdkcrkeys.h  
      \brief A CenRep interface for last used sync solutions
*
* \b  Purpose:
*
*	Calendar/contact data easily gets corrupted if a user is using several remote synchronization solutions at the same time. 
*         The purpose of this API is to provide the synchronization  solution vendors a way to 
*		- Indicate that they’re active synchronization solution for some  content type
*		- Detect that other synchronization solutions may be in use in the device.
*		.
* \b  API \b Description:
*
* 	Synchronizing content over several mechanisms from the device causes easily difficult problems, as the different protocols
*	 and systems are not aware of each other. 
*
*	For example, a synchronization solution using standard OMA DS technology is not aware of the
 * 	simultaneous existence of some proprietary synchronization (aka. mobile PIM) solution,
 * 	and vice versa. This is likely to cause problems, as the users may not be aware of the side
 *	 effects that may occur from using several such solutions at the same time. Currently the
 *	 problem is recognized by the vendors, and device applications do their best to warn user
 * 	from using any other synchronization solution than the one being installed.
 * 	
 *	This API intends to enhance the warning mechanism in two ways:
 *   		-  Provide the way for different solutions to know about each other, and
 *		-  Offer a standard procedure how different solutions should behave when several solutions are used by the user
 *		.
 *	 This is achieved with a simple setting API utilizing Symbian OS Central Repository.
 
 * \b Use \b cases:
 *
 * 	The use cases supported by this API are:
 *  		-# Detect currently active synchronization solution
*			- When a synchronization solution is about to take some supported content type into use,
 *        		 it should check whether there is some other Uid already present in the setting. If
 *         		there isn’t, the solution should put it’s own Uid into the setting value. If there is
 *        		 some unknown Uid, the setting should be aware that it’s changelog for that particular
 *         		content may be out-of-date, and a full re-sync should be issued. It’s up to the solution
 *        		 vendor to decide, whether the user should be notified about this. The user readable name
 *         		of the active solution is readable using Symbian AppArc API method  \code RApaLsSession::GetAppInfo() \endcode
*			.
*		-# Activate a synchronization solution for certain content type
 *		        - This use case allows the synchronization solution to register it’s Uid into the Central
 *         		Repository. This information is used by other compliant solutions to find out the active
 *         		solution for all supported content types
*			.			
*		.
*\b Using \b the \b Synchronization \b Capability \b API:
 *  	-#  Detect currently active synchronization solution
 *     		- Before activating itself as the active solution, the client of this API should check
 *     		whether some other client has registered itself as the preferred solution for certain
 *     		content type synchronization. An example of the check is:
 *     		\code
*		CRepository* repository = CRepository::NewL( KCRUidSecon );
 *     		TInt someSolutionInt; //Active solution UID
 *     		// Get last used calendar sync solution..
 *     		TInt ret = repository->Get( KSeconCalendarUid, someSolutionInt );
 *     		TUid someSolutionUid = TUid::Uid(someSolutionInt)
 *     		TUid mySolutionUid={0xf1f2f3f4}; //Application’s UID
 *     		if(someSolutionUid != mySolutionUid)
 *     		{
 *         		...//Solution specific actions
 *     		}		
 *    		\endcode
 *		.
 *     		- If some other synchronization solution is active for the intended content type, the
 *     		solution can still rewrite the old value, but it should note that a full resync may be
 *     		needed in order to maintain system wide data consistency. It is up to the solution UI
 *     		to decide, what kind of notification, if any, is given to the user.
 *		.
 *	-# Activate a solution for the content type
 *     		- This use case is executed either during solution installation/commissioning, or at least
 *     		before first synchronization. The activation is simple:	
 *    		\code
 *     		CRepository* repository = CRepository::NewL( KCRUidSecon );
 *     		TUid mySolutionUid={0xf1f2f3f4}; //Application’s UID
 *     		// Set mySolutionUid to last used calendar sync solution..
 *     		TInt ret = repository->Set( KSeconCalendarUid, (TInt) mySolutionUid.iUid );
 *		\endcode
*		.
 *     		- Howto store also timestamp
 *		\code
 *     		// Timeformat is YYYYMMDDTHHMMSSZ (universal time),
 *     		// where MM=1..12, DD=1..number of days in month, HH=0..23, MM=0..59, SS=0..59
 *     		_LIT( KFormatDate, "%04d%02d%02dT%02d%02d%02dZ" );
 *     		TTime timeNow;
 *     		timeNow.UniversalTime(); // Store always universal time
 *     		TDateTime now = timeNow.DateTime();
 *     		TBuf<16> dateBuf;
 *     		dateBuf.Format( KFormatDate, now.Year(), now.Month() + 1,
 *     		now.Day() + 1, now.Hour(), now.Minute(), now.Second() );
 *     		repository->Set( KSeconCalendarTime, dateBuf );
 *     		\endcode
 *		.
 * 	-#  Error handling
 *     		- As defined in the Central Repository API.
 *		.
*/     

#ifndef SECONSDKCRKEYS_H
#define SECONSDKCRKEYS_H

//! Repository Uid
/*! Contains settings for the supported 
 * content types. Each setting is integer, which is to hold either the Application Uid or the
 * package Uid of the active solution. 
*/
const TUid KCRUidSecon = {0x2000F83D};

//! Calendar Uid Setting Integer
const TUint32 KSeconCalendarUid = 0x00000001;

//! Calendar Time Setting Integer
const TUint32 KSeconCalendarTime = 0x00000002;

//! Contacts Uid Setting Integer
const TUint32 KSeconContactsUid = 0x00000003;

//! Contacts Time Setting Integer
const TUint32 KSeconContactsTime = 0x00000004;

//! Sms Uid Setting Integer
const TUint32 KSeconSmsUid = 0x00000005;

//! Sms Time Setting Integer
const TUint32 KSeconSmsTime = 0x00000006;

//! Bookmark Uid Setting Integer
const TUint32 KSeconBookmarkUid = 0x00000007;

//! Bookmark Time Setting Integer
const TUint32 KSeconBookmarkTime = 0x00000008;

#endif // SECONSDKCRKEYS_H