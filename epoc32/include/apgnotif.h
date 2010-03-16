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

#ifndef __APGNOTIF_H__
#define __APGNOTIF_H__

#include <apgcli.h>


class MApaAppListServObserver
/**
MApaAppListServObserver

@publishedPartner
@released
*/
	{
public:
	enum TApaAppListEvent
		{
		EAppListChanged=1
		};
	virtual void HandleAppListEvent(TInt aEvent)=0;
protected:
	IMPORT_C MApaAppListServObserver();
private:
	IMPORT_C virtual void MApaAppListServObserver_Reserved1();
	IMPORT_C virtual void MApaAppListServObserver_Reserved2();
private:
	TInt iMApaAppListServObserver_Reserved1;
	};


class CApaAppListNotifier : public CActive
/** An application list change notifier. 

It provides notification whenever an application is added or deleted.

@publishedPartner
@released */
	{
public:
	IMPORT_C ~CApaAppListNotifier();
	IMPORT_C static CApaAppListNotifier* NewL(MApaAppListServObserver* aObserver, TPriority aPriority);
private: // from CActive
	void DoCancel();
	void RunL();
private:
	CApaAppListNotifier(MApaAppListServObserver& aObserver, TPriority aPriority);
	void ConstructL();
private:
	MApaAppListServObserver& iObserver;
	RApaLsSession iLsSession;
	};

#endif
