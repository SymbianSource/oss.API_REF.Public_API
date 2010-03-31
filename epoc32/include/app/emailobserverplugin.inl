/*
* Copyright (c) 2009 - 2009 Nokia Corporation and/or its subsidiary(-ies).
* All rights reserved.
* This component and the accompanying materials are made available
* under the terms of "Eclipse Public License v1.0"
* which accompanies this distribution, and is available
* at the URL "http://www.eclipse.org/legal/epl-v10.html".
*
* Initial Contributors:
* Nokia Corporation - initial contribution.
*
* Contributors:
*
* Description:  Ininline definitions for Email Observer Plugin API.
*
*/

#include <ecom/ecom.h>

// ----------------------------------------------------------------------------
// CEmailObserverPlugin::NewL
// ----------------------------------------------------------------------------
//
inline CEmailObserverPlugin* CEmailObserverPlugin::NewL(
    TUid aImplUid,
    MEmailObserverListener* aListener )
    {
    TAny* interface = REComSession::CreateImplementationL( aImplUid,
        _FOFF( CEmailObserverPlugin, iDtor_ID_Key ), aListener );
    return reinterpret_cast<CEmailObserverPlugin*>( interface );
    }

// ----------------------------------------------------------------------------
// CEmailObserverPlugin::~CEmailObserverPlugin
// ----------------------------------------------------------------------------
//
inline CEmailObserverPlugin::~CEmailObserverPlugin()
    {
    REComSession::DestroyedImplementation( iDtor_ID_Key );
    }
