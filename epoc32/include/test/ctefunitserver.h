/*
* Copyright (c) 2005-2009 Nokia Corporation and/or its subsidiary(-ies). 
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


/**
 @file CTEFUnitServer.h
*/

#ifndef __TEF_UNIT_SERVER_H__
#define __TEF_UNIT_SERVER_H__

#include <test/testexecuteserverbase.h>
#include <test/tefunit.h>
const TInt KMinTEFUnitStepNameSize=8;

class CTEFUnitServer : public CTestServer
	{
/**
@internalComponent
@test
*/
public:
	virtual ~CTEFUnitServer();
	static CTEFUnitServer* NewL();
	virtual CTestStep* CreateTestStep(const TDesC& aStepName);
	RFs& Fs(){return iFs;};

private:
	RFs iFs;
	CTestSuite*	iSuite;
	};

#endif // __TEF_UNIT_SERVER_H__
