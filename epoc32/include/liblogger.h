/*
* Copyright (c) 2006-2009 Nokia Corporation and/or its subsidiary(-ies).
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
* Name        : LibLogger.h
* Part of     : LIBC/logger
* Contained MRT library code tracing macros and class definition.
* Version     : 1.0
* All rights reserved.
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
* Redistributions of source code must retain the above copyright notice, this
* list of conditions and the following disclaimer.
* Redistributions in binary form must reproduce the above copyright notice,
* this list of conditions and the following disclaimer in the documentation
* and/or other materials provided with the distribution.
* Neither the name of the <ORGANIZATION> nor the names of its contributors
* may be used to endorse or promote products derived from this software
* without specific prior written permission.
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
* DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE
* FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
* DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
* SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
* CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
* OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
* OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
*/



#ifndef LIB_LOGGER_H
#define LIB_LOGGER_H

//  INCLUDES

#include <e32def.h>

// DATA TYPES

/* Log message type (Info/Minor/Major/Critical) */
typedef enum TLibTraceMessageType
{
	ELibTraceTypeInfo = 1,
	ELibTraceTypeMinor = 2,
	ELibTraceTypeMajor = 4,
	ELibTraceTypeCritical = 8
}TLibTraceMessageType;

// MACROS

// only logging for critical/major
//#define LOG_BITS ( ELibTraceTypeCritical | ELibTraceTypeMajor | ELibTraceTypeInfo )
#define LOG_BITS ( ELibTraceTypeCritical | ELibTraceTypeMajor )

/* this macro will be used for file and line no.
 */
#define LOG_FILE_NAME_LINE __FILE__, __LINE__

#ifdef __cplusplus
extern "C" {
#endif
/*
 * Message logging interface
 */
IMPORT_C int LibTracer(TLibTraceMessageType aLogMessageType,
							char *aFileName,
							int aLine,
							char *aFormat,
							...);

/*
 * Message logging interface
 */
IMPORT_C int LibTracerMarkerList(TLibTraceMessageType aLogMessageType,
							char *aFileName,
							int aLine,
							char *aFormat,
							VA_LIST* aMarkerList);

/*
 * dumping the message in hex format of specific length
 */
IMPORT_C int LibTracerPartialHexDump(TLibTraceMessageType aLogMessageType,
                            char *aFileName,
							int aLine,
							char *aMessage,
							char *aStr,
							int aStrLen);

/*
 * dumping the message in hex format
 */
IMPORT_C int LibTracerHexDump(TLibTraceMessageType aLogMessageType,
                            char *aFileName,
							int aLine,
							char *aMessage,
							char *aFormat,
							...);

/*
 * dumping the message in hex format
 */
IMPORT_C int LibTracerHexDumpMarkerList(TLibTraceMessageType aLogMessageType,
                            char *aFileName,
							int aLine,
							char *aMessage,
							char *aFormat,
							VA_LIST* aMarkerList);

/*
 * Only logs filename and line no with timestamp
 */
IMPORT_C int LibLineExecTracer(char *aFileName, int aLine);

/*
 * Only logging/trace message without timestamp
 */
IMPORT_C int LibMessageTracer(TLibTraceMessageType aLogMessageType,
							char *aFormat,
							VA_LIST* aMarkerList);

/*
 * Only logging/trace message without timestamp
 */
IMPORT_C int LibHexDumpMessagePartTracer(TLibTraceMessageType aLogMessageType,
							char* aMessage,
							char *aFormat,
							VA_LIST* aMarkerList);


#ifdef __cplusplus
}
#endif

// We are unable to compile the component using non-variadic macros from command line.
// throwing error "badly punctuated parameter list in `#define'"


#if defined(_DEBUG)
//#pragma message("LibC Trace - ENABLE.")

#ifdef __cplusplus
// C++ source code
class CLogger
    {
    public:
    CLogger(char* aFileName, int aLine) : iFileName ( aFileName ), iLine ( aLine) {}
    inline int Tracer(TLibTraceMessageType aLogMessageType, char* aFormat, ...)
        {
        int len = 0;
        if ( LOG_BITS & aLogMessageType )
            {
            VA_LIST marker;
            VA_START(marker, aFormat);
            len = LibTracerMarkerList(aLogMessageType, iFileName, iLine, aFormat, &marker);
            VA_END(marker);
            }
        return len;
        }
    inline int Dump(TLibTraceMessageType aLogMessageType, char* aMessage, char* aFormat, ...)
        {
        int len = 0;
        if ( LOG_BITS & aLogMessageType )
            {
            VA_LIST marker;
            VA_START(marker, aFormat);
            len = LibTracerHexDumpMarkerList(aLogMessageType, iFileName, iLine, aMessage, aFormat, &marker);
            VA_END(marker);
            }
        return len;
        }

    private:
    char* iFileName;
    int iLine;
    };

#else // __cplusplus
// C souce code.
static int LibcTracer(TLibTraceMessageType aLogMessageType, char* aFormat, ...)
    {
    int len = 0;
    if ( LOG_BITS & aLogMessageType )
        {
        VA_LIST marker;
        VA_START(marker, aFormat);
        len = LibMessageTracer(aLogMessageType, aFormat, &marker);
        VA_END(marker);
        }
    return len;
    }

static int LibHexTracer(TLibTraceMessageType aLogMessageType, char* aMessage, char* aFormat, ...)
    {
    int len = 0;
    if ( LOG_BITS & aLogMessageType )
        {
        VA_LIST marker;
        VA_START(marker, aFormat);
        len = LibHexDumpMessagePartTracer(aLogMessageType, aMessage, aFormat, &marker);
        VA_END(marker);
        }
    return len;
    }
#endif // __cplusplus

/*
 * usage : LIB_TRACE(
 *          <messagetype>{ELibTraceTypeInfo|ELibTraceTypeMinor|ELibTraceTypeMajor|ELibTraceTypeCritical},
 *          format,
 *          args);
 * Remark : Similar to printf except the first additional parameter for message type.
 */

#ifdef __cplusplus
#define LIB_TRACE CLogger(LOG_FILE_NAME_LINE).Tracer
#else
#define LIB_TRACE LibLineExecTracer(LOG_FILE_NAME_LINE); \
                   LibcTracer
#endif


/*
 * usage : LIB_TRACE_DUMP(
 *          <messagetype>{ELibTraceTypeInfo|ELibTraceTypeMinor|ELibTraceTypeMajor|ELibTraceTypeCritical},
 *          message, // user wants to add any message before dump, (i.e. TCP message)
 *          format,
 *          args);
 */

#ifdef __cplusplus
#define LIB_TRACE_DUMP CLogger(LOG_FILE_NAME_LINE).Dump
#else
#define LIB_TRACE_DUMP LibLineExecTracer(LOG_FILE_NAME_LINE); \
                    LibHexTracer
#endif


/*
 * usage : LIB_TRACE_DUMP_LEN(
 *          <messagetype>{ELibTraceTypeInfo|ELibTraceTypeMinor|ELibTraceTypeMajor|ELibTraceTypeCritical},
 *          message, // user wants to add any message before dump, (i.e. TCP message)
 *          dumpstring,
 *          stringlength);
 */


#define LIB_TRACE_DUMP_LEN(messageType, message, dumpString, dumpStringLen) \
    { \
    if ( LOG_BITS & messageType ) \
        { \
	    LibTracerPartialHexDump(messageType, \
	                    LOG_FILE_NAME_LINE, \
					    message, \
						dumpString, \
						dumpStringLen); \
        } \
    }

#else
// compilation message
//#pragma message("LibC Trace - DISABLE.")
// Release mode, nothing.

/* Release */

#ifdef __cplusplus
inline TInt LibTracerDummy(...)
        {
        return 0;
        }
#else
static TInt LibTracerDummy(TLibTraceMessageType aLogMessageType, ...)
        {
        return 0;
        }
#endif

#define LIB_TRACE        0 & LibTracerDummy

#define LIB_TRACE_DUMP 0 & LibTracerDummy

#define LIB_TRACE_DUMP_LEN 0 & LibTracerDummy

#endif // _DEBUG


#endif //LIB_LOGGER_H


// End of file
