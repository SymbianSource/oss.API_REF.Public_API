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
//

#if !defined(__APGWGNAM_H__)
#define __APGWGNAM_H__

#if !defined(__W32STD_H__)
#include <w32std.h>
#endif

class CApaWindowGroupName : public CBase
/** Gives access to the name of a window group and the information encoded by that 
name.

A window group is associated with a task, i.e. a running application. The 
window group's name encodes four pieces of information for that task:

the name of the document that the task is handling,

the task's caption,

the application specific UID, as eight hexadecimal characters,

status information for the task, as two hexadecimal characters.

@publishedAll
@released */
	{
public:
	enum { EMaxLength=13+2*KMaxFileName };
public:
	IMPORT_C ~CApaWindowGroupName();
	IMPORT_C static CApaWindowGroupName* NewL(const RWsSession& aWsSession);
	IMPORT_C static CApaWindowGroupName* NewLC(const RWsSession& aWsSession);
	IMPORT_C static CApaWindowGroupName* NewL(const RWsSession& aWsSession, TInt aWgId);
	IMPORT_C static CApaWindowGroupName* NewLC(const RWsSession& aWsSession, TInt aWgId);
	IMPORT_C static CApaWindowGroupName* New(const RWsSession& aWsSession, HBufC* aWgName);
	IMPORT_C static CApaWindowGroupName* NewL(const RWsSession& aWsSession, const TDesC& aWgName);
	IMPORT_C static CApaWindowGroupName* NewLC(const RWsSession& aWsSession, const TDesC& aWgName);
	IMPORT_C void ConstructFromWgIdL(TInt aWgId);
	//
	IMPORT_C void SetWindowGroupNameL(const TDesC& aWgName);
	IMPORT_C void SetWindowGroupName(HBufC* aWgName);
	//
	IMPORT_C static void FindByAppUid(TUid aAppUid, RWsSession& aWsSession, TInt& aPrevWgId);
	IMPORT_C static void FindByCaption(const TDesC& aCaption, RWsSession& aWsSession, TInt& aPrevWgId);
	IMPORT_C static void FindByDocName(const TDesC& aDocName, RWsSession& aWsSession, TInt& aPrevWgId);
	//
	IMPORT_C void SetBusy(TBool aBusy);
	IMPORT_C TBool IsBusy() const;
	IMPORT_C void SetSystem(TBool aSystem);
	IMPORT_C TBool IsSystem() const;
	IMPORT_C void SetDocNameIsAFile(TBool aDocNameIsAFile);
	IMPORT_C TBool DocNameIsAFile() const;
	IMPORT_C void SetRespondsToShutdownEvent(TBool aRespondsToShutdownEvent);
	IMPORT_C TBool RespondsToShutdownEvent() const;
	IMPORT_C void SetRespondsToSwitchFilesEvent(TBool aRespondsToSwitchFilesEvent);
	IMPORT_C TBool RespondsToSwitchFilesEvent() const;
	IMPORT_C void SetHidden(TBool aIsHidden);
	IMPORT_C TBool Hidden() const;
	IMPORT_C void SetAppReady(TBool aIsReady);
	IMPORT_C TBool IsAppReady() const;
	//
	IMPORT_C void SetAppUid(TUid aAppUid);
	IMPORT_C TUid AppUid() const;
	//
	IMPORT_C void SetCaptionL(const TDesC& aCaption);
	IMPORT_C TPtrC Caption() const;
	//
	IMPORT_C void SetDocNameL(const TDesC& aDocName);
	IMPORT_C TPtrC DocName() const;
	//
	IMPORT_C TInt SetWindowGroupName(RWindowGroup& aGroupWin) const;
	IMPORT_C TPtrC WindowGroupName() const;
private: //enums
	enum TApaStatus { ESystem =0x01, EBusy =0x02, EDocNameNotAFile =0x04
					 ,EDoesNotRespondToShutdownEvent=0x08, EDoesNotRespondToSwitchFilesEvent=0x10
					 ,EIsHidden=0x20, EAppReady=0x40 };
	enum TApaDelimiter { EEndStatus=1, EEndUid, EEndCaption, ELast=EEndCaption }; // ELast must be last and same as predecessor
private:
	CApaWindowGroupName(const RWsSession& aWsSession);
	//
	void DefaultConstructL();
	void WriteStatusToName();
	void GetStatusFromName();
	TInt FindDelimiter(TApaDelimiter aDelim) const;
	void ReAllocIfNecessaryL(TInt aExtraLengthReqd);
private:
	HBufC* iBuf;
	TUint iStatus;
	const RWsSession& iWsSession;
	};

#endif
