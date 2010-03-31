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
//

#ifndef __EIKSTART_H__
#define __EIKSTART_H__

#include <e32std.h>
#include <apparc.h>

class CApaCommandLine;

/**
This is the API to initialise and run the application architecture for applications built as exes.
It is not intended to be used for generally running applications from other code. Use RApaLsSession for that.

@publishedAll
@released
*/
NONSHARABLE_CLASS(EikStart)
	{
public:
	IMPORT_C static TInt RunApplication(TApaApplicationFactory aApplicationFactory);
private:
	EikStart();
	};

#endif	// __EIKSTART_H__
