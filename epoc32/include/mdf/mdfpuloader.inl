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

CMdfPuLoader* CMdfPuLoader::NewL(TUid aImplementationUid)
	{
	TAny* interface = REComSession::CreateImplementationL(aImplementationUid, _FOFF(CMdfPuLoader, iDtor_ID_Key));
	return reinterpret_cast<CMdfPuLoader*>(interface);
	}

CMdfPuLoader::~CMdfPuLoader()
	{
	// Destroy any instance variables and then inform ecom that this specific
	// instance of the interface has been destroyed.
	REComSession::DestroyedImplementation(iDtor_ID_Key);
	}
