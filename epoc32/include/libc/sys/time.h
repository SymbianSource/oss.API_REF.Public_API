/*
* Copyright (c) 1997-2009 Nokia Corporation and/or its subsidiary(-ies).
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
*
*/





#ifndef _SYS_TIME_H_
#define _SYS_TIME_H_
#ifdef __cplusplus
extern "C" {
#endif
#include <_ansi.h>
/**
@publishedAll
@released
*/
struct timeval {
  long tv_sec;
  long tv_usec;
};
/**
@publishedAll
@released
*/
struct timezone {
  int tz_minuteswest;
  int tz_dsttime;
};

IMPORT_C int gettimeofday (struct timeval *tp, struct timezone *tzp);

#ifdef __cplusplus
}
#endif
#endif
