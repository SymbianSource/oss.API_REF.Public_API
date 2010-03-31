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
// SIPSCPR_subconevents.inl
// SIP extension events definition
// 
//

/**
 @file
 @publishedAll
 @released
*/


inline CSubConSIPResponseEvent::CSubConSIPResponseEvent()
:iResponse(EInvalidResponse)
    {
    }


inline void CSubConSIPResponseEvent::SetResponse(TInt aResponse)
    {
    iResponse = aResponse;
    }

inline TInt CSubConSIPResponseEvent::GetResponse() const
    {
    return iResponse;
    }
	
inline CSubConSIPResponseEvent* CSubConSIPResponseEvent::NewL()
	{
	STypeId typeId = STypeId::CreateSTypeId(KSubConSIPEventsUid, KSubConSIPResponseEventType);
	return static_cast<CSubConSIPResponseEvent*>(CSubConNotificationEvent::NewL(typeId));
	}

        
inline CSubConSIPAuthenticationRequiredEvent* CSubConSIPAuthenticationRequiredEvent::NewL()
	{
	STypeId typeId = STypeId::CreateSTypeId(KSubConSIPEventsUid, KSubConSIPAuthenticationRequiredEventType);
	return static_cast<CSubConSIPAuthenticationRequiredEvent*>(CSubConNotificationEvent::NewL(typeId));
	}

inline CSubConSIPAuthenticationRequiredEvent::CSubConSIPAuthenticationRequiredEvent()
    {
    }

inline void CSubConSIPAuthenticationRequiredEvent::SetRealmL(const TPtrC8& aRealm)
    {
    iRealm.Close();
    iRealm.CreateL(aRealm);
    }

inline const TPtrC8& CSubConSIPAuthenticationRequiredEvent::GetRealm() const
    {
	return iRealm.LeftTPtr(iRealm.Length());    
    }


inline CSubConSIPNotificationEvent::CSubConSIPNotificationEvent()
    {
    }

inline void CSubConSIPNotificationEvent::SetNotificationL(const TPtrC8 & aNotification)
    {
    iNotification.Close();
    iNotification.CreateL(aNotification); 
    }

inline const TPtrC8& CSubConSIPNotificationEvent::GetNotification() const
    {
    return iNotification.LeftTPtr(iNotification.Length());
    }
	
inline CSubConSIPNotificationEvent* CSubConSIPNotificationEvent::NewL()
	{
	STypeId typeId = STypeId::CreateSTypeId(KSubConSIPEventsUid, KSubConSIPNotificationEventType);
	return static_cast<CSubConSIPNotificationEvent*>(CSubConNotificationEvent::NewL(typeId));
	}

