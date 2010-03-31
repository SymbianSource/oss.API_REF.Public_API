// Copyright (c) 2004-2009 Nokia Corporation and/or its subsidiary(-ies).
// All rights reserved.
// This component and the accompanying materials are made available
// under the terms of "Eclipse Public License v1.0"
// which accompanies this distribution, and is available
// at the URL "http://www.eclipse.org/legal/epl-v10.html".
//
// Initial Contributors:
// Nokia Corporation - initial contribution.
//
// Contributors:
//
// Description:
//

#ifndef __TZUPDATE_H__
#define __TZUPDATE_H__

#include <e32cmn.h> // TUid.
#include <e32std.h>

/** UTC Offset update notification constants. When the UTC offset is automatically
adjusted for Daylight Saving then it is possible to receive
notification using the Publish and Subscribe API with the
values defined here. Note that this property is updated by the Time Zone Server
as this is the only component that can modify the UTC Offset.

@see RProperty in e32property.h
*/
namespace NTzUpdate
    {
	/** Time zone services publish and subscribe property category.
	@publishedAll
	@released
	*/
    const TUid KPropertyCategory = { 0x1020383E };

	/** Time zone services publish and subscribe property keys.
	@publishedAll
	@released
	*/
    enum TPropertyKeys
        {
        EUtcOffsetChangeNotification,
        ECurrentTimeZoneId,
        EHomeTimeZoneId,
        ENextDSTChange,
		ETzRulesChange, 
	    ETzNamesChange, 
        };

	/** Structure used to return the value for ECurrentTimeZoneId or 
	EHomeTimeZoneId property.
	@see RTz::NotifyHomeTimeZoneChangedL
	@publishedAll
	@released
	*/
	struct TTimeZoneChange
		{
		TInt iNewTimeZoneId;
		TInt iOldTimeZoneId;
		};
		
	/** This struct is used to publish DST Change info in an RProperty.
	Subscribers to the ENextDSTChange property will define a copy of this struct
	so that they are not dependant on the tz component.
	If this struct changes then the copies must also be changed.
	@publishedAll
	@released
	*/
	struct TDSTChangeInfo
		{
		/** The version of the struct. Currently always 1 */
		TUint8 iVersion;

		/** The time of the next offset change in UTC */
		TTime iNextDSTChangeUTC;
		/** The offset from UTC (in minutes) after the next DST change will take place.*/
		TInt iNextUTCOffset;
		
		/** The time of the previous offset change in UTC. This member is only valid if the version is 2 or above. */
		TTime iPreviousDSTChangeUTC;

		/** The offset from UTC (in minutes) before the previous DST change took place. This member is only valid
		if the version is 2 or above.*/
		TInt iPreviousUTCOffset;
	private:
		/** Reserved for future use. 
		*/
		TInt iReserved[12];
		};
	/** Structure used to return the value for ETzRulesChange property.
	This property covers changes to the system TZ database, the current/system
	TZ rules or user-defined TZ rules.
	@publishedAll
	@released
	*/
	struct TTzRulesChange
    	{
    	TTime iUTCTimeOfRulesChange;
    	};
    	
	/** Structure used to return the value for ETzNamesChange property.
	This property covers changes to either the localized system TZ names
	or non-localized user-defined TZ names.
	@publishedAll
	@released
	*/
    struct TTzNamesChange
    	{
    	TTime iUTCTimeOfNamesChange;
    	};
     }

#endif  // __TZUPDATE_H__
