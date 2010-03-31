/*
* Copyright (c) 2009 Nokia Corporation and/or its subsidiary(-ies).
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
* Description: Constants defined for Coustom Commands
*
*/

#ifndef __MMFROPCUSTOMCOMMANDCONSTANTS_H
#define __MMFROPCUSTOMCOMMANDCONSTANTS_H
#include <e32std.h>
/**
 * @publishedAll
 *
 * Interface UID and messages for the ROP Controller API.
 */
const TUid KUidInterfaceMMFROPController = {0x101F855D};
/**
 *  Function constants
 */
enum TMMFROPControllerMessage
{
    EMMFROPControllerGetApplicationConfig,
    EMMFROPControllerSetApplicationConfig,
    EMMFROPControllerGetErrorLog,
    EMMFROPControllerClearErrorLog,

    EMMFROPControllerSetDownloadID,

    EMMFROPControllerSetDownloadComplete,
    EMMFROPControllerSetDownloadSize
};
/**
 *  Constants describing the config version to query
 */
enum TMMFROPControllerConfigVersion
{
    KMMFAudioVideoConfigDefault,   // Configuration created on installation
    KMMFAudioVideoConfigOperator,  // Configuration created on operator setup
    KMMFAudioVideoConfigUser       // Last Configuration saved by the application
};
/**
 *  Constants describing ErrorLog error classes.
 *  XXX  This enumeration must match the EErrorLogClass enumeration located
 *  XXX  in errorlog_sink.h.
 */
enum TMMFROPErrorLogClass
{
    KMMFROPErrorLogRTSP,           // RTSP error (must be first enum)
    KMMFROPErrorLogSendEvents,     // Error Send Events
    KMMFROPErrorLogECXlat,         // Error code translation.
    KMMFROPErrorLogNumClasses      // Number of error log classes (not a class)
};
#endif __MMFROPCUSTOMCOMMANDCONSTANTS_H
