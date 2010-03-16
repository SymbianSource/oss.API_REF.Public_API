/*
* Copyright (c) 2007-2009 Nokia Corporation and/or its subsidiary(-ies).
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
* Name          : sipresolvedclient2.inl
* Part of       : SIP Client Resolver
* Version       : 2.0
*
*/



#ifndef SIPRESOLVEDCLIENT2_INL
#define SIPRESOLVEDCLIENT2_INL

#include <ecom/ecom.h>

// ---------------------------------------------------------------------------
// CSIPResolvedClient2::CSIPResolvedClient2 
// ---------------------------------------------------------------------------
//
inline CSIPResolvedClient2::CSIPResolvedClient2()
	{
	}

// ---------------------------------------------------------------------------
// CSIPResolvedClient2::~CSIPResolvedClient2 
// ---------------------------------------------------------------------------
//
inline CSIPResolvedClient2::~CSIPResolvedClient2()
	{
	REComSession::DestroyedImplementation( iInstanceKey );
	}	

#endif // SIPRESOLVEDCLIENT2_INL

// End of File
