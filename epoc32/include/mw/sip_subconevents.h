// Copyright (c) 2005-2009 Nokia Corporation and/or its subsidiary(-ies).
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
// SIPSCPR_subconevents.h
// SIP extension events definition
// 
//

/**
 @file
 @publishedAll
 @released since v9.2
*/
 
#ifndef SIPSCPR_SUBCONEVENTS_H
#define SIPSCPR_SUBCONEVENTS_H

#include <es_sock.h>

/** The numeric value of ECOM plugin identifier for this SubConnection SIP event parameter.See the assisting *.rss file. */
const TInt KSubConSIPEventsUid = 0x10274CAE;

/** The numeric value of Response event type identifier for SIP extension parameter set  */
const TInt KSubConSIPResponseEventType = 1;

/** The numeric value of AuthenticationRequired event type identifier for SIP extension parameter set  */
const TInt KSubConSIPAuthenticationRequiredEventType = 2;

/** The numeric value of Notification event type identifier for SIP extension parameter set  */
const TInt KSubConSIPNotificationEventType = 3;


class CSubConSIPResponseEvent : public CSubConNotificationEvent
/** CSubConSIPResponseEvent is used to get and set the response elements of the most recent response  

@publishedAll
@released since v9.2 */
	{
public:
	/**
	 Identifies the  predefined type of Response 		 .
	 */
    enum PredefinedResponses
        {
        /** The numeric value of Invalid Response */
        EInvalidResponse = 0
        };
        
	inline static CSubConSIPResponseEvent* NewL();
	/** Constructor. */
	inline CSubConSIPResponseEvent();
	/** Destructor. */
	virtual ~CSubConSIPResponseEvent();
	/** Sets Response Code of the SIP Response. **/	
	inline void SetResponse(TInt aResponse);
	/** Gets Response Code of the SIP Response. **/	
	inline TInt GetResponse() const;

protected:
	/** The Response Code of the SIP reasponse. */
    TInt iResponse;
	DATA_VTABLE
	};
	

class CSubConSIPAuthenticationRequiredEvent : public CSubConNotificationEvent
/** CSubConSIPAuthenticationRequiredEvent is used  when SIP authentication is required

@publishedAll
@released since v9.2 */
	{
public:
        
	inline static CSubConSIPAuthenticationRequiredEvent* NewL();
	/** Constructor. */
	inline CSubConSIPAuthenticationRequiredEvent();
	/** Destructor. */
	virtual ~CSubConSIPAuthenticationRequiredEvent();
	/** Sets Realm field of the SIP header. **/	
	inline void SetRealmL(const TPtrC8& aRealm);
	/** Gets Realm field of the SIP header. **/	
	inline const TPtrC8& GetRealm() const;

protected:
	/** The Realm entry of Authenticate field in a SIP header. */
	RBuf8	iRealm;
	DATA_VTABLE
	};


class CSubConSIPNotificationEvent : public CSubConNotificationEvent
/** CSubConSIPNotificationEvent is used for receiving SIP event notifications 

@publishedAll
@released since v9.2 */
	{
public:
  	inline static CSubConSIPNotificationEvent* NewL();
  	/** Constructor. */
	inline CSubConSIPNotificationEvent();
	/** Destructor. */
	virtual ~CSubConSIPNotificationEvent();
	/** Sets Notification for an event. **/	
	inline void SetNotificationL(const TPtrC8 & aNotification);
	/** Gets Notification for an event. **/	
	inline const TPtrC8& GetNotification() const;

protected:
	/** The Notification entry. */
    RBuf8 iNotification;
	DATA_VTABLE
	};	
	

class CSIPSubConnExtensionEventsFactory : public CBase
/** Factory used to create instances of the SIP SubConnection Extension Events

@publishedAll
@released since v9.2 
*/
	{
public:
	static CSubConNotificationEvent* NewL(TAny* aConstructionParameters);
	};

#include "SIP_subconevents.inl"

#endif // SIPSCPR_SUBCONEVENTS_H
