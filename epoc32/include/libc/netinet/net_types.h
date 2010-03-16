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
*
*/

#ifndef _NET_TYPES_H
#define _NET_TYPES_H




/**
 @file
 @publishedAll
 @released
*/

// This file defines various typedefs needed by header files in 'netinet' directory. 
#include <sys/types.h>

typedef unsigned short 	u_int16_t;
typedef unsigned int 	u_int32_t;

typedef u_int16_t n_short;
typedef u_int32_t n_long;
typedef u_int32_t n_time;

struct ether_addr
	{
   	u_char  ether_addr_octet[6];
	};
#endif //#define _NET_TYPES_H
