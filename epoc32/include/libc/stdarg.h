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
* This is all somewhat tortured because ANSI C says that stdio.h is not supposed 
* to define va_list. stdarg_e.h defines something suitable for stdio.h, and
* this file sorts out va_list.
* 
*
*/






#ifndef _STDARG_H
#define _STDARG_H

#include <stdarg_e.h>
/**
@publishedAll
@released
*/
#define va_list __e32_va_list

#endif
