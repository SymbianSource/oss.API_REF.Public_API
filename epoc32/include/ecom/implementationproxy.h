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
// This file contains the definition for the
// TImplementationProxy structure.
// 
//



#ifndef __IMPLEMENTATIONPROXY_H__
#define __IMPLEMENTATIONPROXY_H__

#include <e32std.h>

/**
Pre-defined function pointer type used in TImplementationProxy

@publishedAll
@released
*/
typedef TAny* (*TFuncPtr)();

/**
Typedef used to cover the difference between EABI and older handling
of the instantiation method pointer.

@publishedAll
@released
*/
#if  defined(__EABI__) || defined(__GCCXML__)
typedef TFuncPtr TProxyNewLPtr;
#else
typedef TAny* TProxyNewLPtr;
#endif

/**
The structure that defines the pairing required by the ECOM framework
to correctly identify the instantiation method pointer to provide
to a client's resolution request.

@publishedAll
@released
*/
typedef struct
	{
	/** The unique UID for an Interface Implementation */
	TUid	iImplementationUid;
	/** The pointer to the instantiation method for the Interface Implementation identified by the UID.*/
	TProxyNewLPtr iNewLFuncPtr;
	} TImplementationProxy;

/**
Macro to initialise an element of a static array of TImplementationProxy objects.
This macro deals with casting the function pointer to the type used in the structure.

@publishedAll
@released
*/
#define IMPLEMENTATION_PROXY_ENTRY(aUid, aFuncPtr)	{{aUid},(TProxyNewLPtr)(aFuncPtr)}

#endif	// __IMPLEMENTATIONPROXY_H__
