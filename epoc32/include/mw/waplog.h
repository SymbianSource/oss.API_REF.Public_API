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
// WAP Logging public header, defines the name of the 
// file to use for WAP activity logging messages
// 
//

#if !defined(__WAPLOG_H__)
#define __WAPLOG_H__

#if !defined(__E32STD_H__)
#include <e32std.h>
#endif

#ifdef _DEBUG
/**
@publishedAll
@deprecated
*/
_LIT(KWapLogFileName,"WAPLog.html");
#define __LOG_WAP_FILE_NAME KWapLogFileName
#else
#define __LOG_WAP_FILE_NAME
#endif

#endif
