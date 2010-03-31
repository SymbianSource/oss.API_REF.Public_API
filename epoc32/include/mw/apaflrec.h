// Copyright (c) 1997-2009 Nokia Corporation and/or its subsidiary(-ies).
// All rights reserved.
// This component and the accompanying materials are made available
// under the terms of "Eclipse Public License v1.0"
// which accompanies this distribution, and is available
// at the URL "http://www.eclipse.org/legal/epl-v10.html".
//
// Initial Contributors:
// Nokia Corporation - initial contribution.
//
// Contributors:
//
// Description:
// apaflrec.h
//

#ifndef __APAFLREC_H__
#define __APAFLREC_H__

#include <apadef.h>
#include <apaid.h>

class TApaAppEntry;
class CApaCommandLine;
class RFs;

/** An interface used by the Application Architecture server to start applications.

CEikonEnv is derived from this class.

@publishedPartner
@released
@see CEikonEnv */
class MApaAppStarter
	{
public:
	virtual TThreadId StartAppL(const CApaCommandLine& aCommandLine)=0;
protected:
	IMPORT_C MApaAppStarter(); 
private:
	IMPORT_C virtual void MApaAppStarter_Reserved1();
	IMPORT_C virtual void MApaAppStarter_Reserved2();
private:
	TInt iMApaAppStarter_Reserved1;
	};

#endif	// __APAFLREC_H__
