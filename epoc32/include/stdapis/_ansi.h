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
* To get a strict ANSI C environment, define macro _STRICT_ANSI.  This will
* "comment out" the non-ANSI parts of the ANSI header files (non-ANSI header
* files aren't affected).
* 
*
*/






#ifndef	_ANSIDECL_H_
#define	_ANSIDECL_H_

/** 
Epoc32 STDLIB is an ANSI environment and expects an ANSI C compiler 
MSVC is however an environment which doesn't define __STDC__, so
we fix it up in here...
*/

#ifndef __STDC__
#define __STDC__	1
#endif

#define _STRICT_ANSI

/**
From GCC 2.5 onwards it is possible to tell the compiler that functions
don't return, which would stop some warnings while building STDLIB
*/
#if 0
#define _ATTRIBUTE(attrs) __attribute__ (attrs)
#else
#define _ATTRIBUTE(attrs)
#endif

/*

*/
 
#ifndef EXPORT_C
/**
It is needed to annotate the functions which will be exported from the ESTLIB DLL,
but mustn't conflict with the definitions in <e32std.h>
*/
#ifdef __VC32__
#define IMPORT_C __declspec(dllexport)
#define EXPORT_C __declspec(dllexport)
#endif

#ifdef __CW32__
#define IMPORT_C __declspec(dllexport)
#define EXPORT_C __declspec(dllexport)
#endif

#ifdef __GCC32__
#define IMPORT_C
#define EXPORT_C __declspec(dllexport)
#endif

#ifdef __SYMBIAN32__
#ifdef __cplusplus
#include <e32def.h>
#endif
#else
#define IMPORT_C
#define EXPORT_C
#endif

#endif /* EXPORT_C */
#endif /* _ANSIDECL_H_ */
