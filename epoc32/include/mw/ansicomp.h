// Copyright (c) 1997-2009 Nokia Corporation and/or its subsidiary(-ies).
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
// Enforce ANSI compliance on Microsoft compilers in 'For loop' behaviour
// 
//


#if !defined(__ANSICOMP_H__)
#define __ANSICOMP_H__

#if defined(__VC32__) && _MSC_VER>=1100
#pragma warning(disable : 4127)		// warning C4127 : conditional expression is constant

#define for if(false);else for		// Enforce the definition of a loop variable to local scope

#endif

#endif    // __ANSICOMP_H__
