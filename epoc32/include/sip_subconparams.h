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
// SIPSCPR_subconparams.h
// SIP extension parameters definition
// 
//



/**
 @file
 @publishedAll
 @released since v9.2
*/

#ifndef SIP_SUBCONPARAMS_H
#define SIP_SUBCONPARAMS_H

#include <es_sock.h>
#include <comms-infras/metabuffer.h>

/** The numeric value of ECOM plugin identifier for this SubConnection parameter extension.See the assisting *.rss file. */
const TInt KSubConSIPParametersUid = 0x10274C18;

/** The numeric value of Invite identifier for SIP extension parameter set  */
const TInt KSubConSIPInviteParamsType = 1;

/** The numeric value of Subscribe identifier for SIP extension parameter set  */
const TInt KSubConSIPSubscribeParamsType = 2;

/** The numeric value of Authentication of SIP extension parameter set  */
const TInt KSubConSIPAuthenticateParamsType = 3;

class CSubConSIPInviteParamSet : public CSubConExtensionParameterSet
/** 
This contains the SIP Invite parameters that will be passed via subconnection
to the SIP stack
@publishedAll
@released since v9.2 
*/
{
public:
     /**
	 Creates a new SubConSIPInvite parameter set object.  
	 @param     aFamily ,contains family related info 
	 @param		aType contains parameter Type such as (Requested, Acceptable and Granted)
	 @return    A pointer to the newly allocated object.
	 @leave 	KErrArgument if the data is not of type TParameterSetType.
	 */   
	inline static CSubConSIPInviteParamSet* NewL(CSubConParameterFamily& aFamily, CSubConParameterFamily::TParameterSetType aType);
	inline static CSubConSIPInviteParamSet* NewL();
	
	/** Constructor. */
	inline CSubConSIPInviteParamSet();
	/** Destructor. */
	virtual ~CSubConSIPInviteParamSet();
	
	/** Getters for SIP header. */
	/** Gets Request URI field of the SIP header. **/
	inline const TPtrC8 GetRequestUri() const;
	/** Gets From field of the SIP header. **/	
	inline const TPtrC8 GetFrom() const;
	/** Gets To field of the SIP header. **/	
	inline const TPtrC8 GetTo() const;
	/** Gets Contact field of the SIP header. **/	
	inline const TPtrC8 GetContact() const;
	/** Gets ContentType field of the SIP header. **/	
	inline const TPtrC8 GetContentType() const;
	/** Gets ContentSubType field of the SIP header. **/	
	inline const TPtrC8 GetContentSubType() const;
	/** Gets Content field of the SIP header. **/
	inline const TPtrC8 GetContent() const;
	
	/** Setters for SIP header. 
	/** Sets Request URI field of the SIP header. **/
	inline void   SetRequestUriL(const TPtrC8 & aReqUri);
	/** Sets From field of the SIP header. **/	
	inline void   SetFromL(const TPtrC8 & aFrom);
	/** Sets To field of the SIP header. **/	
	inline void   SetToL(const TPtrC8 & aTo);
	/** Sets Contact field of the SIP header. **/	
	inline void   SetContactL(const TPtrC8 & aContact);
	/** Sets Content Type field of the SIP header. **/		
	inline void   SetContentTypeL(const TPtrC8 & aContentType);
	/** Sets Content Sub Type field of the SIP header. **/	
	inline void   SetContentSubTypeL(const TPtrC8 & aContentSubType);
	/** Sets Content field of the SIP header. **/		
	inline void	  SetContentL(const TPtrC8 & aContent);
	
	DATA_VTABLE
protected:

	/** The Request URI field of the SIP header. */
	RBuf8	iReqUri;
	/** The From field of the SIP header. */
	RBuf8	iFrom;
	/** The To field of the SIP header. */
	RBuf8	iTo;
	/** The Contact field of the SIP header. */
	RBuf8	iContact;
	/** The Content Type field of the SIP header. */
	RBuf8	iContentType;
	/** The Content Sub Type field of the SIP header. */
	RBuf8	iContentSubType;
	/** The Content field of the SIP header. */
	RBuf8	iContent;
	};
	
	
	
class CSubConSIPSubscribeParamSet : public CSubConExtensionParameterSet
/** 
This contains the SIP Subscribe parameters that will be passed via subconnection
to the SIP stack
@publishedAll
@released since v9.2 
*/
{
public:
    /**
	 Creates a new SubConSIPSubscribe parameter set object.  
	 @param     aFamily ,contains family related info 
	 @param		aType contains parameter Type such as (Requested, Acceptable and Granted)
	 @return    A pointer to the newly allocated object.
	 @leave 	KErrArgument if the data is not of type TParameterSetType.
	 */    
	inline static CSubConSIPSubscribeParamSet* NewL(CSubConParameterFamily& aFamily, CSubConParameterFamily::TParameterSetType aType);
	inline static CSubConSIPSubscribeParamSet* NewL();
	
	/** Constructor. */
	inline CSubConSIPSubscribeParamSet();
	
	/** Destructor. */
    virtual ~CSubConSIPSubscribeParamSet();
    
	/** Getters for SIP header. */
	/** Gets Request URI field of the SIP header. **/
	inline const TPtrC8 GetRequestUri() const;	
	/** Gets From field of the SIP header. **/
	inline const TPtrC8 GetFrom() const;
	/** Gets To field of the SIP header. **/	
	inline const TPtrC8 GetTo() const;
	/** Gets Contact field of the SIP header. **/
	inline const TPtrC8 GetContact() const;
	/** Gets Event Type field of the SIP header. **/
	inline const TPtrC8 GetEventType() const;
	/** Gets Accept Type field of the SIP header. **/
	inline const TPtrC8 GetAcceptType() const;
	/** Gets Accept Sub Type field of the SIP header. **/
	inline const TPtrC8 GetAcceptSubType() const;
	/** Gets Expires field of the SIP header. **/
	inline const TInt   GetExpires() const;
	/** Gets Auto Refresh field of the SIP header. **/
	inline const TBool  GetAutoRefresh() const;
	
	/** Setters for SIP header. */
	/** Sets Request URI field of the SIP header. **/
	inline void  SetRequestUriL(const TPtrC8 & aReqUri);
	/** Sets From field of the SIP header. **/	
	inline void  SetFromL(const TPtrC8 & aFrom);
	/** Sets To field of the SIP header. **/	
	inline void  SetToL(const TPtrC8 & aTo);
	/** Sets Contact field of the SIP header. **/
	inline void  SetContactL(const TPtrC8 & aContact);
	/** Sets Event Type field of the SIP header. **/
	inline void  SetEventTypeL(const TPtrC8 & aEventType);
	/** Sets Accept Type field of the SIP header. **/
	inline void  SetAcceptTypeL(const TPtrC8 & aAcceptType);
	/** Sets Accept Sub Type field of the SIP header. **/
	inline void  SetAcceptSubTypeL(const TPtrC8 & aAcceptSubType);
	/** Sets Expires Sub Type field of the SIP header. **/
	inline void  SetExpires(TInt aExpires);
	/** Sets AutoRfresh field of the SIP header. **/
	inline void  SetAutoRefresh(TBool aAutoRefresh);
	
	
	DATA_VTABLE
protected:
	
	/** The Request URI field of the SIP header. */
	RBuf8	iReqUri;
	/** The From field of the SIP header. */
	RBuf8	iFrom;
	/** The To field of the SIP header. */
	RBuf8	iTo;
	/** The Contact field of the SIP header. */
	RBuf8	iContact;
	/** The Event Type field of the SIP header. */
	RBuf8	iEventType;
	/** The Accept Type field of the SIP header. */
	RBuf8	iAcceptType;
	/** The Accept Sub Type field of the SIP header. */
	RBuf8	iAcceptSubType;
	/** The Expires field of the SIP header. */
	TInt	iExpires;
	/** The AutoRefresh field of the SIP header. */
	TBool   iAutoRefresh;
};
	
class CSubConSIPAuthenticateParamSet : public CSubConExtensionParameterSet
/** 
This contains the SIP Authenticate parameters that will be passed via subconnection
to the SIP stack
@publishedAll
@released since v9.2 
*/
{
public:
    /**
	 Creates a new SubConSIPAuthenticate parameter set object.  
	 @param     aFamily ,contains family related info 
	 @param		aType contains parameter Type such as (Requested, Acceptable and Granted)
	 @return    A pointer to the newly allocated object.
	 @leave 	KErrArgument if the data is not of type TParameterSetType.
	 */    
	inline static CSubConSIPAuthenticateParamSet* NewL(CSubConParameterFamily& aFamily, CSubConParameterFamily::TParameterSetType aType);
	inline static CSubConSIPAuthenticateParamSet* NewL();
	
	/** Constructor. */
	inline CSubConSIPAuthenticateParamSet();
	
	/** Destructor. */
	virtual ~CSubConSIPAuthenticateParamSet();
	
	/** Getters for SIP header. */
	/** Gets Username field of the SIP header. **/
	inline const TPtrC8 GetUserName() const;
	/** Gets Password field of the SIP header. **/	
	inline const TPtrC8 GetPassword() const;
	/** Gets Realm field of the SIP header. **/		
	inline const TPtrC8 GetRealm() const;
	
	/** Setters for SIP header. */
	/** Sets Username field of the SIP header. **/
	inline void  SetUserNameL(const TPtrC8 & aUserName);
	/** Sets Password field of the SIP header. **/	
	inline void  SetPasswordL(const TPtrC8 & aPassword);
	/** Sets Realm field of the SIP header. **/	
	inline void  SetRealmL(const TPtrC8 & aRealm);
	
	DATA_VTABLE
protected:

	/** The Username entry of Authenticate field in a SIP header. */
	RBuf8	iUserName;
	/** The Password entry of Authenticate field in a SIP header. */
	RBuf8	iPassword;
	/** The Realm entry of Authenticate field in a SIP header. */
	RBuf8	iRealm;	
};



class CSIPSubConnExtensionParamsFactory : public CBase
/** Factory used to create instances of the SIP SubConnection Parameter Extension Sets.

@publishedAll
@released since v9.2 
*/
	{
public:
	static CSubConExtensionParameterSet* NewL(TAny* aConstructionParameters);
	};

#include <sip_subconparams.inl>

#endif // SIP_SUBCONPARAMS_H
