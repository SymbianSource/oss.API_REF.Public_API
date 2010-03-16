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
//

#include <ecom/ecom.h>

CSendAsEditUtils* CSendAsEditUtils::NewL(TUid aUid)
	{
	// Get the instantiation specified by the UID.
	TAny* ptr = REComSession::CreateImplementationL(aUid, _FOFF(CSendAsEditUtils, iDtor_ID_Key));
	CSendAsEditUtils* utils = reinterpret_cast<CSendAsEditUtils*>(ptr);
	return utils;
	}
	
CSendAsEditUtils::CSendAsEditUtils()
: CBase()
	{
	}
	
CSendAsEditUtils::~CSendAsEditUtils()
	{
	REComSession::DestroyedImplementation(iDtor_ID_Key);
	}
