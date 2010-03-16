// Copyright (c) 2004-2009 Nokia Corporation and/or its subsidiary(-ies).
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



/**
 @file
 @publishedAll
 @released
*/

#ifndef REMCONSTATUSAPICONTROLLER_H
#define REMCONSTATUSAPICONTROLLER_H

#include <e32base.h>
#include <remcon/remconinterfacebase.h>
#include <remcon/remconinterfaceif.h>
#include <remconstatusapi.h>

_LIT(KStatusApiPanicName, "Status Api Panic");

class MRemConStatusApiControllerObserver;
class CRemConInterfaceSelector;

/**
A controller which sends Status API commands.
@publishedAll
@released
*/
NONSHARABLE_CLASS(CRemConStatusApiController) : public CRemConInterfaceBase,
								                public MRemConInterfaceIf
	{
private:
	enum TStatusApiPanic
		{
		EStatusApiCommandDataSectionTooLong,
		};

public:
	IMPORT_C static CRemConStatusApiController* NewL(CRemConInterfaceSelector& aInterfaceSelector, 
		MRemConStatusApiControllerObserver& aObserver);
	IMPORT_C ~CRemConStatusApiController();

	// Commands
	IMPORT_C void UnitInfo(TRequestStatus& aStatus, TUint& aNumRemotes);
	IMPORT_C void SubunitInfo(TRequestStatus& aStatus, TUint& aNumRemotes);

private:
	CRemConStatusApiController(CRemConInterfaceSelector& aInterfaceSelector, 
		MRemConStatusApiControllerObserver& aObserver);

	// from CRemConInterfaceBase
	void MrcibNewMessage(TUint aOperationId, const TDesC8& aData);
	TAny* GetInterfaceIf(TUid aUid);
	
	// Utility functions
	void SetUnitInfoResponseData(const TDesC8& aCommandData,
		TInt& aVendorId, 
		TInt& aUnit, 
		TInt& aUnitType, 
		TInt& aExtendedUnitType);
		
	void SetSubunitInfoResponseData(const TDesC8& aCommandData,
		TInt& aPage, 
		TInt& aExtension, 
		TPtrC8& aPageData);
		
	void ReadCommandDataToInt(const TDesC8& aCommandData, 
		TInt aOffset, 
		TInt aLength, 
		TInt& aValue);
		
	static void Panic(TStatusApiPanic aPanic);

private:
	MRemConStatusApiControllerObserver& iObserver;
	TBuf8<KRemConStatusApiMaxOperationSpecificDataSize> iOutData;
	};

#endif // REMCONSTATUSAPICONTROLLER_H
