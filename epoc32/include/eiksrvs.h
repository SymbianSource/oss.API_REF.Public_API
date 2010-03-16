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

#ifndef __EIKSRVS_H__
#define __EIKSRVS_H__

#include <eikappui.h>
#include <eikenv.h>
#include <eiksrv.pan>
#include <apgtask.h>
#include <eiksrv.h>

class CDictionaryFileStore;

/**
@publishedPartner
@released
*/
_LIT(EIKAPPUI_SERVER_NAME,"!EikAppUiServer");

/**
@publishedPartner
@released
*/
_LIT(EIKAPPUI_SERVER_THREAD_NAME,"EikAppUiServerThread");

/**
@publishedPartner
@released
*/
_LIT(EIKAPPUI_SERVER_SEMAPHORE,"EikAppUiServerStartSemaphore");

/**
@internalComponent
*/
const TInt KEikSrvDefaultHeapSize=0x10000;

/**
@internalComponent
*/
const TInt KEikSrvDefaultMaxHeapSize=0x100000;

enum TEikAppUiRanges
	{
	EFirstUnrestrictedOpcodeInEikAppUi
	};

/**
@internalComponent
*/
enum TEikUiOpCode
	{
	// No Capability requirement
	EEikAppUiFirst=EFirstUnrestrictedOpcodeInEikAppUi,
	EEikAppUiLaunchTaskList,
	EEikAppUiCycleTasks,
	EEikAppUiSetStatusPaneFlags,
	EEikAppUiSetStatusPaneLayout,
	EEikAppUiBlankScreen,
	EEikAppUiUnblankScreen,
	EEikAppUiResolveError,
	EEikAppUiExtension,
	EEikAppUiEnableTaskList,
	EEikAppUiGetDebugPreferences,	
	EEikAppUiResolveErrorWithTitleText,
	// End Marker no Capability
	EEikAppUiFirstUnusedOpcode,
	};

/**
function to panic the server

@internalComponent
*/
GLREF_C void PanicServer(TEikAppUiServPanic aPanic);

#endif	// __EIKSRVS_H__
