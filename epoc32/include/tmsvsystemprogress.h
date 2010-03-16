// Copyright (c) 1998-2009 Nokia Corporation and/or its subsidiary(-ies).
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
// TMSVSYSTEMPROGRES.H
// 
//

#ifndef __TMSVSYSTEMPROGRESS_H__
#define __TMSVSYSTEMPROGRESS_H__

#include <msvstd.h>

const TUint KUIDMsgMsvSystemProgress = 0x1028308F;

/**
Progress information that is defined by and understood by the system as well as client MTM's

@publishedAll
@released
*/
class TMsvSystemProgress
	{
public:
	IMPORT_C TMsvSystemProgress();
	IMPORT_C TMsvSystemProgress(const TMsvSystemProgress& aSysProg);
	IMPORT_C TMsvSystemProgress& operator=(const TMsvSystemProgress& aSysProg);
	
public:
	/** the version number of class */
	const TInt			iVersion;
	/** Operation error code.*/
	TInt				iErrorCode; 
	/** the id of an entry in an operation*/
	TMsvId				iId;	
	};

#endif // #define __TMSVSYSTEMPROGRESS_H__
