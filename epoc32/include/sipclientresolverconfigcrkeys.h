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
* Name        : sipclientresolverconfigcrkeys.h
* Part of     : SIP / SIP Client Resolver
* Interface   : SIP Client Resolver API
* Version     : 1.0
*
*/



#ifndef SIPCLIENTRESOLVERCONFIGCRKEYS_H
#define SIPCLIENTRESOLVERCONFIGCRKEYS_H

// INCLUDES
#include <e32def.h>

/**
* @file
* @publishedAll
* @released
*/

/// Defines configuration parameters used by SIP Client Resolver
const TUid KCRUidSIPClientResolverConfig = { 0x10282EE7 };

/// Mask for the less significant bits in setting keys.
/// These bits are reserved for field type information.
const TUint32 KSIPClientResolverFieldTypeMask = 0xf0000000;

/// Mask for the most significant bits in setting keys.
/// These bits are reserved for the actual key part.
const TUint32 KSIPClientResolverKeyMask = 0x0fffffff;

/** 
* Mask for username field.
* Field type is TDesC8.
*/
const TUint32 KSIPClientResolverUserNameMask = 0x10000000;

/** 
* Mask for plug-in implementation UID field.
* Field type is TInt32.
*/
const TUint32 KSIPClientResolverPluginUIDMask = 0x20000000;

/** 
* Mask for client UID field.
* Field type is TInt32.
*/
const TUint32 KSIPClientResolverClientUIDMask = 0x30000000;

#endif // SIPCLIENTRESOLVERCONFIGCRKEYS_H

// End of File
