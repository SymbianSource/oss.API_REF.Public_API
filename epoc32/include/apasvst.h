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
// Starting of AppArc server
// 
//

#ifndef __APASVST_H__
#define __APASCST_H__

#include <e32std.h>

// classes referenced
class MApaAppStarter;


IMPORT_C TPtrC NameApaServStartSemaphore();

IMPORT_C TPtrC NameApaServServerThread();

IMPORT_C TInt StartupApaServer(MApaAppStarter& aAppStarter);

IMPORT_C TInt StartupApaServerProcess();

IMPORT_C TInt ApaServThreadStart(TAny* aAppStarter);


#endif
