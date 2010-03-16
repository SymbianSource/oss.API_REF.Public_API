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
// f32\inc\f32plugin.inl
// 
//


inline void CFsPluginFactory::IncrementMounted() 
			{iMountedPlugins++;}

inline void CFsPluginFactory::DecrementMounted() 
			{iMountedPlugins--;}

inline TInt CFsPluginFactory::MountedPlugins() 
			{return(iMountedPlugins);}


inline TInt CFsPlugin::Drive()
			{return(iDrive);}
inline void CFsPlugin::SetDrive(TInt aDrive)
			{iDrive=aDrive;}
inline TInt CFsPlugin::SessionDisconnect(CSessionFs* /*aSession*/)
			{return KErrNone;}



inline TInt CFsPluginConnRequest::Function() const
	{
	return iFunction;
	}

inline TDes8* CFsPluginConnRequest::Param1() const
	{
	return iParam1;
	}

inline TDes8* CFsPluginConnRequest::Param2() const
	{
	return iParam2;
	}

inline const RMessagePtr2& CFsPluginConnRequest::Message() const 
	{
	return(iMessage);
	}

inline void CFsPluginConnRequest::WriteParam1L(const TDesC8& aDes) const
	{
	iMessage.WriteL(1,aDes);
	}

inline void CFsPluginConnRequest::WriteParam2L(const TDesC8& aDes) const
	{
	iMessage.WriteL(2,aDes);
	}

inline void CFsPluginConnRequest::ReadParam1L(TDes8& aDes) const
	{
	iMessage.ReadL(1,aDes);
	}
	
inline void CFsPluginConnRequest::ReadParam2L(TDes8& aDes) const
	{
	iMessage.ReadL(2,aDes);
	}
	


//inline TRequestStatus* CFsPluginConnRequest::ReqStat() const
//	{
//	return iStatus;
//	}

inline void CFsPluginConnRequest::Complete(TInt aError)
	{
	iLink.Deque();
	iMessage.Complete(aError);
	delete this;
	}

inline CFsPlugin* CFsPluginConn::Plugin() const
	{
	return iPluginP;
	}

inline TThreadId CFsPluginConn::ClientId() const
	{
	return iClientId;
	}
