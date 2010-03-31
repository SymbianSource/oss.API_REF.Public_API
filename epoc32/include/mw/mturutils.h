// Copyright (c) 2000-2009 Nokia Corporation and/or its subsidiary(-ies).
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

#ifndef __MTURUTILS_H__
#define __MTURUTILS_H__

#include <msvstd.h>

class MturUtils
/** Utility class that is used to start an application to 
edit a specified message.

@publishedAll
@released
*/
{
public:
	IMPORT_C static void LaunchEditorL(TMsvId aId);
	IMPORT_C static void LaunchEditorAndWaitL(TMsvId aId);
	IMPORT_C static void LaunchEditorL(TMsvId aId, RThread& aThread, TRequestStatus& aStatus);
};

#endif
