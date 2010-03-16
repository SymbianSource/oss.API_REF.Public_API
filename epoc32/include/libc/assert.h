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






#ifdef __cplusplus
extern "C" {
#endif

#include "_ansi.h"

#undef assert
/**
@publishedAll
@released
*/
#ifdef NDEBUG           /* required by ANSI standard */
#define assert(p)  	((void)0)
#else
#define assert(e)       ((e) ? (void)0 : __assert(__FILE__, __LINE__, #e))
#endif /* NDEBUG */
/**
@publishedAll
@released
*/
IMPORT_C void __assert(const char *, int, const char *);

#ifdef __cplusplus
}
#endif
