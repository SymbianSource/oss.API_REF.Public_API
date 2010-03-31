// Copyright (c) 2007-2009 Nokia Corporation and/or its subsidiary(-ies).
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
// Logging macros for use in debug subsystem
//



/**
 @file
 @internalTechnology
 @released
*/

#ifndef DEBUG_LOGGING_H
#define DEBUG_LOGGING_H

/* 
 * Debug messages are only generated for debug builds.
 */

#ifdef CDSDEBUG

    #include <e32debug.h>
    #define LOG_DES(des) {if(des.Length() > 0) {RBuf buf; buf.CreateL(des); char *ptr = (char*)buf.Collapse().PtrZ(); LOG_MSG2("\n(%s)\n", ptr); buf.Close();} }

    #define LOG_MSG( a )              RDebug::Printf( a )
    #define LOG_MSG2( a, b )          RDebug::Printf( a, b )
    #define LOG_MSG3( a, b, c )       RDebug::Printf( a, b, c )
    #define LOG_MSG4( a, b, c, d )    RDebug::Printf( a, b, c, d )
    #define LOG_MSG5( a, b, c, d, e ) RDebug::Printf( a, b, c, d, e )

#else

    #define LOG_DES(des)
    #define LOG_MSG( a )
    #define LOG_MSG2( a, b )
    #define LOG_MSG3( a, b, c )
    #define LOG_MSG4( a, b, c, d )
    #define LOG_MSG5( a, b, c, d, e )

#endif

#endif //DEBUG_LOGGING_H
