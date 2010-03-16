// Copyright (c) 2002-2009 Nokia Corporation and/or its subsidiary(-ies).
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
// MMSSettingProxyBase.inl
// Base MMS Settings Proxy
// 
//

#include <mmssettingsproxybase.h>

CMMSSettingsProxyBase* CMMSSettingsProxyBase::NewL(TUid aInterfaceImplUid)
	{
	TAny* ptr = NULL;
	ptr = REComSession::CreateImplementationL(aInterfaceImplUid, _FOFF(CMMSSettingsProxyBase, iDtor_ID_Key));
	return REINTERPRET_CAST(CMMSSettingsProxyBase*, ptr);
	}

CMMSSettingsProxyBase::~CMMSSettingsProxyBase()
	{
	REComSession::DestroyedImplementation(iDtor_ID_Key);
	}
