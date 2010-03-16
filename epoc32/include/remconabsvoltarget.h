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

#ifndef REMCONABSVOLTARGET_H
#define REMCONABSVOLTARGET_H

#include <e32base.h>
#include <remcon/remconinterfacebase.h>
#include <remcon/remconinterfaceif.h>

class MRemConAbsVolTargetObserver;
class CRemConInterfaceSelector;

/**
Client-instantiable type supporting sending AbsVol API responses.
*/
NONSHARABLE_CLASS(CRemConAbsVolTarget) : public CRemConInterfaceBase, 
								         public MRemConInterfaceIf
	{
public:
	/**
	Factory function.
	@param aInterfaceSelector The interface selector. The client must have 
	created one of these first.
	@param aObserver The observer of this interface.
	@return A new CRemConAbsVolTarget, owned by the interface selector.
	*/
	IMPORT_C static CRemConAbsVolTarget* NewL(CRemConInterfaceSelector& aInterfaceSelector, 
		MRemConAbsVolTargetObserver& aObserver);
	
	/** Destructor. */
	IMPORT_C ~CRemConAbsVolTarget();

public:
	/**
	Sends a response to a 'get absolute volume' command.
	Only one response per target session can be outstanding at any one time.
	@param aStatus Used by RemCon to indicate completion of the send request.
	@param aAbsVol The volume, on a scale of 0 to aMaxVol.
	@param aMaxVol The maximum volume, to which aAbsVol is relative.
	@param aError The response error.
	*/
	IMPORT_C void GetAbsoluteVolumeResponse(TRequestStatus& aStatus, 
		TUint aAbsVol, 
		TUint aMaxVol, 
		TInt aError);

	/**
	Sends a response to a 'set absolute volume' command.
	Only one response per target session can be outstanding at any one time.
	@param aStatus Used by RemCon to indicate completion of the request.
	@param aError The response error.
	*/
	IMPORT_C void SetAbsoluteVolumeResponse(TRequestStatus& aStatus, 
		TInt aError);

private:
	/** 
	Constructor.
	@param aInterfaceSelector The interface selector.
	@param aObserver The observer of this interface.
	*/
	CRemConAbsVolTarget(CRemConInterfaceSelector& aInterfaceSelector, 
		MRemConAbsVolTargetObserver& aObserver);

private: // from CRemConInterfaceBase
	TAny* GetInterfaceIf(TUid aUid);

private: // from MRemConInterfaceIf
	void MrcibNewMessage(TUint aOperationId, const TDesC8& aData);

private: // unowned
	MRemConAbsVolTargetObserver& iObserver;

private: // owned
	// For operation-specific data.
	static const TUint KMaxOperationDataSize = 0x20;
	TBuf8<KMaxOperationDataSize> iOutData;
	
	// not used by this class, but required for calling RRemCon::Send ...
	TUint iNumRemotes;
	
	};

#endif // REMCONABSVOLTARGET_H
