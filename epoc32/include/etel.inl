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



/**
 @file
*/
inline TVersion RTelServer::Version() const
/** Gets the version number of the ETel server.
	
@return The server version and build numbers.
@publishedPartner
@released
*/
	{
	return(TVersion(KEtelMajorVersionNumber,
					KEtelMinorVersionNumber,
					KEtelBuildVersionNumber));
	}

//
// RTelSubSessionBase
//
inline RSessionBase& RTelSubSessionBase::SessionHandle() const
/**
@publishedPartner
@released
*/
	{ 
	return *iTelSession;
	}

inline void RTelSubSessionBase::SetSessionHandle(RSessionBase& aTelSession)
/**
@publishedPartner
@released
*/
	{ 
	iTelSession=&aTelSession;
	}

inline void RTelSubSessionBase::ResetSessionHandle()
/**
@publishedPartner
@released
*/
	{ 
	iTelSession=NULL;
	}

inline TInt RTelSubSessionBase::SubSessionHandle()
/**
@publishedPartner
@released
*/
	{
	return(RSubSessionBase::SubSessionHandle());
	}
