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
// SIPSCPR_subconparams.inl
// SIP extension parameters inline implementation
// / CSubConSIPInviteParamSet
// 
//




/**
 @file
 @publishedAll
*/

inline CSubConSIPInviteParamSet* CSubConSIPInviteParamSet::NewL(CSubConParameterFamily& aFamily, CSubConParameterFamily::TParameterSetType aType)
	{
	CSubConSIPInviteParamSet* obj = NewL();
	CleanupStack::PushL(obj);
	aFamily.AddExtensionSetL(*obj, aType);
	CleanupStack::Pop(obj);
	return obj;
	}

inline CSubConSIPInviteParamSet* CSubConSIPInviteParamSet::NewL()
	{
	STypeId typeId(KSubConSIPParametersUid, KSubConSIPInviteParamsType);
	return static_cast<CSubConSIPInviteParamSet*>(CSubConParameterSet::NewL(typeId));
	}

inline CSubConSIPInviteParamSet::CSubConSIPInviteParamSet()
:CSubConExtensionParameterSet()
	{
	}	
	
inline const TPtrC8 CSubConSIPInviteParamSet::GetRequestUri() const
	{
	return iReqUri.LeftTPtr(iReqUri.Length());	
	}
	
inline const TPtrC8 CSubConSIPInviteParamSet::GetFrom() const
	{
	return iFrom.LeftTPtr(iFrom.Length());	
	}
	
inline const TPtrC8 CSubConSIPInviteParamSet::GetTo() const
	{
	return iTo.LeftTPtr(iTo.Length());	
	}
	
inline const TPtrC8 CSubConSIPInviteParamSet::GetContact() const
	{
	return iContact.LeftTPtr(iContact.Length());		
	}
	
inline const TPtrC8 CSubConSIPInviteParamSet::GetContentType() const
	{
	return iContentType.LeftTPtr(iContentType.Length());		
	}
	
inline const TPtrC8 CSubConSIPInviteParamSet::GetContentSubType() const
	{
	return iContentSubType.LeftTPtr(iContentSubType.Length());			
	}
	
inline const TPtrC8 CSubConSIPInviteParamSet::GetContent() const
	{
	return iContent.LeftTPtr(iContent.Length());
	}
	
// Setters
inline void CSubConSIPInviteParamSet::SetRequestUriL(const TPtrC8& aReqUri)
	{
    iReqUri.Close();
   	iReqUri.CreateL(aReqUri);
	}
	
inline void CSubConSIPInviteParamSet::SetFromL(const TPtrC8& aFrom) 
	{
    iFrom.Close();
	iFrom.CreateL(aFrom);
	}
	
inline void CSubConSIPInviteParamSet::SetToL(const TPtrC8& aTo)
	{
    iTo.Close();
	iTo.CreateL(aTo);
	}
	
inline void CSubConSIPInviteParamSet::SetContactL(const TPtrC8& aContact)
	{
    iContact.Close();
	iContact.CreateL(aContact);
	}
	
inline void CSubConSIPInviteParamSet::SetContentTypeL(const TPtrC8& aContentType)
	{
    iContentType.Close();
	iContentType.CreateL(aContentType);
	}
	
inline void CSubConSIPInviteParamSet::SetContentSubTypeL(const TPtrC8& aContentSubType)
	{
    iContentSubType.Close();
	iContentSubType.CreateL(aContentSubType);
	}
	
inline void	CSubConSIPInviteParamSet::SetContentL(const TPtrC8& aContent)
	{
    iContent.Close();	
	iContent.CreateL(aContent);
	}
	
	
	
	
	
	

/*-===========================================================
/
/ CSubConSIPSubscribeParamSet
/
/*-=========================================================*/
inline CSubConSIPSubscribeParamSet* CSubConSIPSubscribeParamSet::NewL(CSubConParameterFamily& aFamily, CSubConParameterFamily::TParameterSetType aType)
	{
	CSubConSIPSubscribeParamSet* obj = NewL();
	CleanupStack::PushL(obj);
	aFamily.AddExtensionSetL(*obj, aType);
	CleanupStack::Pop(obj);
	return obj;
	}

inline CSubConSIPSubscribeParamSet* CSubConSIPSubscribeParamSet::NewL()
	{
	STypeId typeId(KSubConSIPParametersUid, KSubConSIPSubscribeParamsType);
	return static_cast<CSubConSIPSubscribeParamSet*>(CSubConParameterSet::NewL(typeId));
	}

// Constructor
inline CSubConSIPSubscribeParamSet::CSubConSIPSubscribeParamSet()
:CSubConExtensionParameterSet()
    {
    }
    
// Getters
inline const TPtrC8 CSubConSIPSubscribeParamSet::GetRequestUri() const
    {
    return iReqUri.LeftTPtr(iReqUri.Length());	
    }
	
inline const TPtrC8 CSubConSIPSubscribeParamSet::GetFrom() const
    {
    return iFrom.LeftTPtr(iFrom.Length());	
    }

inline const TPtrC8 CSubConSIPSubscribeParamSet::GetTo() const
    {
    return iTo.LeftTPtr(iTo.Length());	
    }

inline const TPtrC8 CSubConSIPSubscribeParamSet::GetContact() const
    {
    return iContact.LeftTPtr(iContact.Length());	
    }

inline const TPtrC8 CSubConSIPSubscribeParamSet::GetEventType() const
    {
    return iEventType.LeftTPtr(iEventType.Length());	
    }

inline const TPtrC8 CSubConSIPSubscribeParamSet::GetAcceptType() const
    {
    return iAcceptType.LeftTPtr(iAcceptType.Length());	
    }

inline const TPtrC8 CSubConSIPSubscribeParamSet::GetAcceptSubType() const
    {
    return iAcceptSubType.LeftTPtr(iAcceptSubType.Length());	
    }

inline const TInt CSubConSIPSubscribeParamSet::GetExpires() const
    {
    return iExpires;
    }
    
inline const TBool CSubConSIPSubscribeParamSet::GetAutoRefresh() const
    {
    return iAutoRefresh;
    }   
    

// Setters
inline void  CSubConSIPSubscribeParamSet::SetRequestUriL(const TPtrC8& aReqUri)
	{
    iReqUri.Close();
	iReqUri.CreateL(aReqUri);
	}
	
inline void  CSubConSIPSubscribeParamSet::SetFromL(const TPtrC8& aFrom)
    {
    iFrom.Close();
	iFrom.CreateL(aFrom);
    }

inline void  CSubConSIPSubscribeParamSet::SetToL(const TPtrC8& aTo)
    {
    iTo.Close();
	iTo.CreateL(aTo);
    }

inline void  CSubConSIPSubscribeParamSet::SetContactL(const TPtrC8& aContact)
    {
    iContact.Close();
	iContact.CreateL(aContact);
    }

inline void  CSubConSIPSubscribeParamSet::SetEventTypeL(const TPtrC8& aEventType)
    {
    iEventType.Close();
	iEventType.CreateL(aEventType);
    }

inline void  CSubConSIPSubscribeParamSet::SetAcceptTypeL(const TPtrC8& aAcceptType)
    {
    iAcceptType.Close();
	iAcceptType.CreateL(aAcceptType);
    }

inline void  CSubConSIPSubscribeParamSet::SetAcceptSubTypeL(const TPtrC8& aAcceptSubType)
    {
    iAcceptSubType.Close();
	iAcceptSubType.CreateL(aAcceptSubType);
    }

inline void  CSubConSIPSubscribeParamSet::SetExpires(TInt aExpires)
    {
    iExpires = aExpires;
    }

inline void CSubConSIPSubscribeParamSet::SetAutoRefresh(TBool aAutoRefresh)
    {
    iAutoRefresh = aAutoRefresh;
    }
	
	
	
	
	
/*-===========================================================
/
/ CSubConSIPAuthenticateParamSet
/
/*-=========================================================*/
inline CSubConSIPAuthenticateParamSet* CSubConSIPAuthenticateParamSet::NewL(CSubConParameterFamily& aFamily, CSubConParameterFamily::TParameterSetType aType)
	{
	CSubConSIPAuthenticateParamSet* obj = NewL();
	CleanupStack::PushL(obj);
	aFamily.AddExtensionSetL(*obj, aType);
	CleanupStack::Pop(obj);
	return obj;
	}

inline CSubConSIPAuthenticateParamSet* CSubConSIPAuthenticateParamSet::NewL()
	{
	STypeId typeId(KSubConSIPParametersUid, KSubConSIPAuthenticateParamsType);
	return static_cast<CSubConSIPAuthenticateParamSet*>(CSubConParameterSet::NewL(typeId));
	}

// Constructor
inline CSubConSIPAuthenticateParamSet::CSubConSIPAuthenticateParamSet()
:CSubConExtensionParameterSet()
	{
	}

// Getters
inline const TPtrC8 CSubConSIPAuthenticateParamSet::GetUserName() const
    {
    return iUserName.LeftTPtr(iUserName.Length());
    }
	
inline const TPtrC8 CSubConSIPAuthenticateParamSet::GetPassword() const	
    {
    return iPassword.LeftTPtr(iPassword.Length());
    }

inline const TPtrC8 CSubConSIPAuthenticateParamSet::GetRealm() const
    {
    return iRealm.LeftTPtr(iRealm.Length());
    }

// Setters
inline void CSubConSIPAuthenticateParamSet::SetUserNameL(const TPtrC8 & aUserName)
    {
    iUserName.Close();
	iUserName.CreateL(aUserName);
    }

inline void CSubConSIPAuthenticateParamSet::SetPasswordL(const TPtrC8 & aPassword)
    {
    iPassword.Close();    
	iPassword.CreateL(aPassword);
    }

inline void CSubConSIPAuthenticateParamSet::SetRealmL(const TPtrC8 & aRealm)
    {
    iRealm.Close();
    iRealm.CreateL(aRealm);
    }
