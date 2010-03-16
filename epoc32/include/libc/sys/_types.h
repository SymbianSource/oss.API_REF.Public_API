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
* This file defines various typedefs needed by the system calls that support
* the C library.  Basically, they're just the POSIX versions with an '_'
* prepended.  This file lives in the `sys' directory so targets can provide
* their own if desired (or they can put target dependant conditionals here).
* 
*
*/







/**
 @file
 @publishedAll
 @released
*/

#ifndef	_SYS__TYPES_H
#define _SYS__TYPES_H

typedef long _off_t;
typedef long _ssize_t;

#endif	/* _SYS__TYPES_H */
