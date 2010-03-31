/*
* Copyright (c) 2005-2009 Nokia Corporation and/or its subsidiary(-ies).
* All rights reserved.
* This component and the accompanying materials are made available
* under the terms of the License "Eclipse Public License v1.0"
* which accompanies this distribution, and is available
* at the URL "http://www.eclipse.org/legal/epl-v10.html".
*
* Initial Contributors:
* Nokia Corporation - initial contribution.
*
* Contributors:
*
* Description: 
*
*/


#ifndef AUTHSERVER_PLUGINDESC_INL
#define AUTHSERVER_PLUGINDESC_INL

#include <authserver/plugindesc.h>

AuthServer::CPluginDesc::CPluginDesc()
/**
	This constructor is used by NewL to allocate
	a CPluginDesc object when it restores one from
	a stream.
	
	It does nothing, and is only defined because
	this class has another, non-default, constructor.
 */
	{
	// empty.
	}

#endif	// #ifndef AUTHSERVER_PLUGINDESC_INL

