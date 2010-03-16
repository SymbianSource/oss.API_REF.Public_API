/*
* Copyright (c) 2004-2009 Nokia Corporation and/or its subsidiary(-ies).
* All rights reserved.
* This component and the accompanying materials are made available
* under the terms of the License "Symbian Foundation License v1.0" to Symbian Foundation members and "Symbian Foundation End User License Agreement v1.0" to non-members
* which accompanies this distribution, and is available
* at the URL "http://www.symbianfoundation.org/legal/licencesv10.html".
*
* Initial Contributors:
* Nokia Corporation - initial contribution.
*
* Contributors:
*
* Description:
* Name          : SipResolvedClient.inl
* Part of       : SIP Client Resolver
* Version       : 1.0
*
*/



#ifndef SIPRESOLVEDCLIENT_INL
#define SIPRESOLVEDCLIENT_INL


// ---------------------------------------------------------------------------
// CSIPResolvedClient::CSIPResolvedClient 
// ---------------------------------------------------------------------------
//
inline CSIPResolvedClient::CSIPResolvedClient()
	{
	}

// ---------------------------------------------------------------------------
// CSIPResolvedClient::~CSIPResolvedClient 
// ---------------------------------------------------------------------------
//
inline CSIPResolvedClient::~CSIPResolvedClient()
	{
	REComSession::DestroyedImplementation( iInstanceKey );
	}
	
// ---------------------------------------------------------------------------
// CSIPResolvedClient::Capabilities
// ---------------------------------------------------------------------------
//
inline const TDesC8& CSIPResolvedClient::Capabilities() 
	{
	return KNullDesC8;
	}	

#endif // SIPRESOLVEDCLIENT_INL

// End of File
