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
* This is all somewhat tortured because ANSI C says that stdio.h is not supposed 
* to define va_list: it needs to have access to that data type, but must not use that name.
* Instead stdio.h should use an __ name, which is safe because it is reserved for 
* the implementation.  Hence __e32_va_list.
* 
*
*/






#ifndef _STDARG_E_H
#define _STDARG_E_H

/**
EPOC32 definitions, extracted from E32DEFS.H
*/
typedef char* __e32_va_list;

#define va_start(ap,pn) (ap=(__e32_va_list)&pn+((sizeof(pn)+sizeof(int)-1)&~(sizeof(int)-1)),(void)0)
#define va_arg(ap,type) (ap+=((sizeof(type)+sizeof(int)-1)&~(sizeof(int)-1)),(*(type *)(ap-((sizeof(type)+sizeof(int)-1)&~(sizeof(int)-1)))))
#define va_end(ap) (ap=0,(void)0)

#endif
