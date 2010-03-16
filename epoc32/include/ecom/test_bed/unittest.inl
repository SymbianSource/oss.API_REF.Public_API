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


inline CUnitTest::CUnitTest(const TDesC&		 aName, 
							CDataLogger&		 aDataLogger, 
							MUnitTestObserver&	 aUnitTestObserver) :
CTimer(CActive::EPriorityStandard),
iUnitTestName(aName),
iDataLogger(aDataLogger),
iUnitTestObserver(aUnitTestObserver)
	{
	CActiveScheduler::Add(this);
	}


inline const TDesC& CUnitTest::UnitTestName() const
	{
	return iUnitTestName;
	}

inline void CUnitTest::PrepareUnitTestL()
	{
	// Do nothing in the default implementation
	}

inline void CUnitTest::SetRTest(RTest* aRTest)
	{
	// Record a handle on the RTest object to use in decoding the result 
	// of a unit test run in RunL().
	iRTest = aRTest;
	}
