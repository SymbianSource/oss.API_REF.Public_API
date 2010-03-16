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
//

#ifndef __TZUPDATE_H__
#define __TZUPDATE_H__

#include <e32cmn.h> // TUid.

/** UTC Offset update notification constants. When the UTC offset is automatically
adjusted for Daylight Saving then it is possible to receive
notification using the Publish and Subscribe API with the
values defined here. Note that this property is updated by the Time Zone Server
as this is the only component that can modify the UTC Offset.

@see RProperty in e32property.h
@publishedAll
@released
@since 9.1
*/
namespace NTzUpdate
    {
    const TUid KPropertyCategory = { 0x1020383E };

    enum TPropertyKeys
        {
        EUtcOffsetChangeNotification,
        ECurrentTimeZoneId,
        EHomeTimeZoneId,
        ENextDSTChange
        };

	struct TTimeZoneChange
		{
		TInt iNewTimeZoneId;
		TInt iOldTimeZoneId;
		};
		
	/** This struct is used to publish DST Change info in an RProperty.
	Subscribers to the property will define a copy of this struct
	so that they are not dependant on the tz component.
	If this struct changes then the copies must also be changed.
	@internalTechnology
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

		/** Reserved for future use. */
		TInt iReserved[12];
		};
    }

#endif  // __TZUPDATE_H__
