// Copyright (c) 1999-2009 Nokia Corporation and/or its subsidiary(-ies).
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

#ifndef __SMUTSIMPARAM_H__
#define __SMUTSIMPARAM_H__

#include <msvapi.h>
#include <smcmmain.h>

/**
The UID for the stream into which the SIM parameters are stored.

@internalComponent
@deprecated
Should be moved to the cpp file for this class.
*/
const TUid KUidMsvSimSmsParams = {0x100081BC};

class CMobilePhoneSmspList;
class TSmsProgress;

/**
A packaged TInt value.

This is used by CSmsSimParamOperation.

@see CSmsSimParamOperation::ProgressL()

@internalComponent
@released
*/
typedef TPckgBuf<TInt> TIntBuf;

/**
Encapsulates an operation to read/write an array of SMS parameters from a SIM.

An operation of this type if returned by the SMS client MTM for the read and
write SIM paramter operations.

These operations are generated from calling the SMS client MTM APIs 
CSmsClientMtm::ReadSimParamsL and CSmsClientMtm::WriteSimParamsL. The 
CSmsClientMtm::InvokeAsyncFunctionL API should not be used for these operations.

@see	CSmsClientMtm::ReadSimParamsL
@see	CSmsClientMtm::WriteSimParamsL

@publishedAll
@released
*/
class CSmsSimParamOperation : public CMsvOperation
	{
public:

	static CSmsSimParamOperation* ReadSimParamsL(TUid aMtm, TMsvId aService, CMsvSession& aMsvSession, TRequestStatus& aObserverRequestStatus);
	static CSmsSimParamOperation* WriteSimParamsL(const CMobilePhoneSmspList& aList, TUid aMtm, TMsvId aService, CMsvSession& aMsvSession, TRequestStatus& aObserverRequestStatus);
	virtual ~CSmsSimParamOperation();

	inline const CMobilePhoneSmspList& SmspList() const;

	IMPORT_C CMobilePhoneSmspList* ServiceCentersLC() const;
	IMPORT_C const TDesC8& ProgressL();

	IMPORT_C static void RestoreSimParamsL(CMsvStore& aStore, CMobilePhoneSmspList& aList);
	IMPORT_C static void StoreSimParamsL(CMsvStore& aStore, const CMobilePhoneSmspList& aList);

private:	// methods from CActive

	virtual void RunL();
	virtual void DoCancel();
	virtual TInt RunError(TInt aError);

private:

	CSmsSimParamOperation(TUid aMtm, TMsvId aService, CMsvSession& aMsvSession, TRequestStatus& aObserverRequestStatus);

	void DoReadSimParamsL();
	void DoRunReadSimParamsL(/*TSmsProgress aProgress*/);
	void DoWriteSimParamsL(const CMobilePhoneSmspList& aList);

	void TransferCommandL(TInt aCommandId);
	void Complete();

private:

/**
This defines the state machine.
*/
	enum TReadSimParamsState
		{
/**
Specifies waiting state
*/
		EStateWaiting,
/**
Specifies reading state
*/
		EStateReadingSimParams,	 
/**
Specifies writing state
*/
		EStateWritingSimParams
		} iState;

/**
A list containing the SMS parameters
*/
	CMobilePhoneSmspList* iSimParams;	
	TInt iError;
	TIntBuf iProgressBuf;
	CMsvOperation* iOperation;
	};

/**
Gets the list of SMS parameters on the SIM, after a successfully completed 
read operation.

If the operation has not successfully completed, this function returns an 
empty list.

This function should ot be used with a write SIM parameters operation.

@return
The list of SMS parameters read from the SIM.

@panic	SMCM	3
This operation was not reading the SIM parameters. The operation was not returned
from CSmsClientMtm::ReadSimParamsL (debug only).
*/
inline const CMobilePhoneSmspList& CSmsSimParamOperation::SmspList() const
	{
	__ASSERT_DEBUG(iState == EStateReadingSimParams, Panic(ESmscPanicUnexpectedCommand));
	return *iSimParams;
	}

#endif // __SMUTSIMPARAM_H__
