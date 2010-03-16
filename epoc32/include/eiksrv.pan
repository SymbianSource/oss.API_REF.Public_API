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

#ifndef __EIKSRV_PAN__
#define __EIKSRV_PAN__

/**
@publishedPartner
@released
*/
#define __EIKON_SERVER _L("Eikon server")

/**
@internalComponent
*/
enum TEikServPanic
	{
	EEikServPanicNotifyBadDescriptor,
	EEikServPanicAlarmAlertServiceNotSupported,
	EEikServPanicNoTaskListDialog,
	EEikServPanicTaskNull,
	EEsPanicAlarmAlert,
	EEikServPanicAlarmAlertServerAlreadyConnected,
	EEikServEnvPanicNullAppUi,
	EEikServPanicNoSuchLabelInAlarm,
	EEikServPanicDriveIndexOutOfRange,
	EEikServPanicNotiferArrayNotNull,
	EEikServPanicChannelIndexOutOfRange,
	EEikServPanicNullObservedList,
	EEikServPanicQueueIndexOutOfRange,
	EEikServPanicNotifyAlertQueueEmpty,
	EEikSrvClientPanicInconsistentMessageParameters,
	};

/**
@internalComponent
*/
GLREF_C void Panic(TEikServPanic aPanic);

#endif	// __EIKSRV_PAN__
