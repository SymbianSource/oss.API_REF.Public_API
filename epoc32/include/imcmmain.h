
// Copyright (c) 1999-2009 Nokia Corporation and/or its subsidiary(-ies).
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
//



/**
 @file
 @publishedAll
 @release
*/

#if !defined (__IMCMMAIN_H__)
#define __IMCMMAIN_H__

#if !defined (__E32STD_H__)
#include <e32std.h>
#endif

#if !defined (__BARSC_H__)
#include <barsc.h>		// RResourceFile
#endif


GLREF_C void OpenResourceFileL(RResourceFile& aFile, RFs& anFs);
GLDEF_C void CloseResourceFile( TAny* aResourceFile );


#endif
