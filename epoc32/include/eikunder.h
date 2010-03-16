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

#ifndef __EIKUNDER_H__
#define __EIKUNDER_H__

#include <e32base.h>	// class CActive

class RThread;

/**
@publishedAll
@released 
*/
class MEikUndertakerObserver
	{
public:
	virtual void HandleThreadExitL(RThread& aThread) = 0;
	};

/**
@publishedAll
@released 
*/
class CEikUndertaker : public CActive
	{
public:
	IMPORT_C static CEikUndertaker* NewL(MEikUndertakerObserver& aObserver);
	IMPORT_C ~CEikUndertaker();
private:
	CEikUndertaker(MEikUndertakerObserver& aObserver);
	void ConstructL();
	void Request();
private: // from CActive
	void DoCancel();
	void RunL();
private:
	MEikUndertakerObserver& iObserver;
	RUndertaker iUndertaker;
	TInt iThreadHandle;
	};

#endif	// __EIKUNDER_H__
