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

#if !defined(SAVEPRIV_H)
#define SAVEPRIV_H


_LIT(__SHUTDOWN_SERVER_NAME,"!ShutdownServer");

/**
@internalTechnology
*/
const TInt KShutdownMajorVN			=6;
const TInt KShutdownMinorVN			=0;
const TInt KShutdownBuildVN			=1;
const TInt KShutdownMessageSlots	=1;

/**
@internalTechnology
*/
enum TSaveNotifierOpCode
	{
	TSaveOpCodeNotify,
	TSaveOpCodeNotifyCancel,
	TSaveOpCodeHandleError,
	TSaveOpCodePowerOff,        //Supported only in special test debug build.
	TSaveOpCodeQueryPowerState  //Supported only in special test debug build.
	};

/**
@internalTechnology
*/
struct TErrorAndClientId
	{
	TInt iError;
	TUint iClientId;
	};

//
// TShutdownServerStart
//
/**
@internalTechnology
*/
class TShutdownServerStart
	{
public:
	TShutdownServerStart(TRequestStatus& aStatus);
	TPtrC AsCommand() const;
//
	TShutdownServerStart();
	TInt GetCommand();
	void SignalL();
private:
	TThreadId iId;
	TRequestStatus* iStatus;
	};


#endif
