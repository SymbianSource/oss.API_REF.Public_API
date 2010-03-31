/*
* Copyright (c) 2010 Sun Microsystems, Inc. and/or its subsidiary(-ies).
* All rights reserved.
* This component and the accompanying materials are made available
* under the terms of "Eclipse Public License v1.0"
* which accompanies this distribution, and is available
* at the URL "http://www.eclipse.org/legal/epl-v10.html".
*
* Initial Contributor:
* Maximilian Odendahl
*
* Contributors:
* 
* Description: 	Client API to connect to Caldav server
*				Wrapper around RCalDavServer
*/

#ifndef CCALDAVSESSION_H
#define CCALDAVSESSION_H

// INCLUDES
#include <e32std.h>
#include <e32base.h>

class CCalDavSessionImpl;

/**
 * @class CCalenCustomisation 
 * @brief Client API to connect to the CalDAV server.
 */
NONSHARABLE_CLASS( CCalDavSession ) : public CBase
	{
public:
	/** Allocates and constructs a session to the Calendar server.
	 * @return Pointer to the newly created session.
	 */
	IMPORT_C static CCalDavSession* NewL();
	/** 	Allocates and constructs a session to the Calendar server.
	 @return Pointer to the newly created session.
	 */
	IMPORT_C static CCalDavSession* NewLC();
	
	/**
	 * 	standard destructor, close session with CalDavServer
	 */
	IMPORT_C ~CCalDavSession();

	/**
	 Enable access to a remote CalDAV server. At least url, 
	 username and password need to be set first.
	 
	 @param aCalendar calendar to enable, must be internal filename in the form c:calendar
	 */
	IMPORT_C TInt Enable(const TDesC &aCalendar);
	/**
	 Disable access to a remote CalDAV server.
	 
	 @param aCalendar calendar to disable, must be internal filename in the form c:calendar
	 */
	IMPORT_C TInt Disable(const TDesC &aCalendar);

	/**
	 On demand syncing of an enabled connection of one calendar file
	 
	 @param aCalendar calendar to enable, must be internal filename in the form c:calendar
	 */
	IMPORT_C TInt SyncL(const TDesC &aCalendar);
	/**
	 On demand syncing of all enabled connections 
	 */
	IMPORT_C TInt SyncAllL();

	/**
	 Retrieve connection url
	 
	 @param aCalendar calendar for sync, must be internal filename in the form c:calendar
	 @param aUrl url for the connection
	 */
	IMPORT_C TInt Url(const TDesC &aCalendar, TDes8 &aUrl);
	/**
	 Set connection url
	 
	 @param aCalendar calendar for sync, must be internal filename in the form c:calendar
	 @param aUrl url for the url
	 */
	IMPORT_C TInt SetUrl(const TDesC &aCalendar, const TDesC8 &aUrl);

	/**
	 Retrieve connection username
	 
	 @param aCalendar calendar for sync, must be internal filename in the form c:calendar
	 @param aUsername username for the connection
	 */

	IMPORT_C TInt Username(const TDesC &aCalendar, TDes8 &aUsername);
	/**
	 Set connection username
	 
	 @param aCalendar calendar for sync, must be internal filename in the form c:calendar
	 @param aUsername username for the connection
	 */
	IMPORT_C TInt SetUsername(const TDesC &aCalendar, const TDesC8 &aUsername);

	/**
	 Retrieve connection password
	 
	 @param aCalendar calendar for sync, must be internal filename in the form c:calendar
	 @param aPassword password for the connection
	 */

	IMPORT_C TInt Password(const TDesC &aCalendar, TDes8 &aPassword);
	/**
	 Set connection password
	 
	 @param aCalendar calendar for sync, must be internal filename in the form c:calendar
	 @param aPassword password for the connection
	 */
	IMPORT_C TInt SetPassword(const TDesC &aCalendar, const TDesC8 &aPassword);
	/**
	 Retrieve synchonization interval
	 
	 @param aCalendar calendar for sync, must be internal filename in the form c:calendar
	 @param aSyncInterval sync interval for the connection
	 */

	IMPORT_C TInt SyncInterval(const TDesC &aCalendar,
			TTimeIntervalMinutes& aSyncInterval);
	/**
	 Set synchonization interval
	 
	 @param aCalendar calendar for sync, must be internal filename in the form c:calendar
	 @param aSyncInterval sync interval for the connection, value of zero minutes meaning 
	 continuous connection
	 */
	IMPORT_C TInt SetSyncInterval(const TDesC &aCalendar,
			TTimeIntervalMinutes aSyncInterval);

	/**
	 Retrieve time range into past for synchronization
	 
	 @param aCalendar calendar for sync, must be internal filename in the form c:calendar
	 @param aDays number of days into the past for the connection
	 */
	IMPORT_C TInt PastDays(const TDesC &aCalendar, TTimeIntervalDays &aDays);
	/**
	 Set time range into past for synchronization
	 
	 @param aCalendar calendar for sync, must be internal filename in the form c:calendar
	 @param aDays number of days into the past for the connection
	 */
	IMPORT_C TInt SetPastDays(const TDesC &aCalendar, TTimeIntervalDays aDays);

	/**
	 Retrieve immediate push of client changes
	 
	 @param aCalendar calendar for sync, must be internal filename in the form c:calendar
	 @param aImmediateSync push client changes immediatly
	 */
	IMPORT_C TInt ImmediateSync(const TDesC &aCalendar, TBool &aImmediateSyc);
	/**
	 Set immediate push of client changes
	 
	 @param aCalendar calendar for sync, must be internal filename in the form c:calendar
	 @param aImmediateSync push client changes immediatly
	 */
	IMPORT_C TInt SetImmediateSync(const TDesC &aCalendar, TBool aImmediateSyc);

	/**
	 During a synchronisation conflict, either the server or client needs to win, default is the server
	 
	 @param aCalendar calendar for sync, must be internal filename in the form c:calendar
	 @param aKeepServerEntry server or client wins during synchronisation
	 */
	IMPORT_C TInt KeepServerEntry(const TDesC &aCalendar,
			TBool &aKeepServerEntry);
	/**
	 During a synchronisation conflict, either the server or client needs to win, which can be set here
	 
	 @param aCalendar calendar for sync, must be internal filename in the form c:calendar
	 @param aKeepServerEntry server or client wins during synchronisation
	 */
	IMPORT_C TInt SetKeepServerEntry(const TDesC &aCalendar,
			TBool aKeepServerEntry);

	/**
	 Retrieve connection status
	 
	 @param aCalendar calendar for sync, must be internal filename in the form c:calendar
	 @param aEnabledSync connection status
	 */
	IMPORT_C TInt EnabledSync(const TDesC &aCalendar, TBool &aEnabledSync);

private:

	CCalDavSession();
	void ConstructL();

	CCalDavSessionImpl* iImpl;

	};

#endif // CCALDAVSESSION_H
