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

#ifndef __TZ_CONVERTER_H__
#define __TZ_CONVERTER_H__

#include <e32base.h>
#include <tz.h>
#include <tzdefines.h>

class CTzChangeNotifier;
class CVTzActualisedRules;
class CTzRuleHolder;

/**
Converts between time expressed in UTC and local time. 

@publishedAll
@released

@see RTz
@since 9.1
*/
class CTzConverter : public CBase
	{
public:

	IMPORT_C static CTzConverter* NewL(RTz& aTzServer);
	IMPORT_C ~CTzConverter();
	IMPORT_C TInt ConvertToLocalTime(TTime& aTime);
	IMPORT_C TInt ConvertToLocalTime(TTime& aTime, const CTzId& aZone);
	IMPORT_C TInt ConvertToUniversalTime(TTime& aTime);
	IMPORT_C TInt ConvertToUniversalTime(TTime& aTime, const CTzId& aZone);
	IMPORT_C TUint16 CurrentTzId();

	void NotifyTimeZoneChangeL(RTz::TTzChanges aChange);
	const RTz& Server() const; 
private:
	CTzConverter(RTz& aTzServer);
	void ConstructL();


private:
	RTz& iTzServer;

	TAny* iReserved; 
	TAny* iReserved2; 
	};

#endif
