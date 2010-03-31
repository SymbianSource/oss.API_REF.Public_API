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

#ifndef __TZID_H__
#define __TZID_H__

#include <e32base.h>
#include <s32strm.h>

/**
Represents an invalid time zone numeric identifier.

@internalTechnology
*/
const TUint KInvalidTzId = 0xffffffff;

/**
Encapsulates a time zone identifier.

The identifier may be either a name or a number.

@publishedAll
@released
@since 9.1
*/
class CTzId : public CBase
	{
public:
	IMPORT_C ~CTzId();
	
	/** 
	This should not be used. For internal use only. 
	*/
	IMPORT_C CTzId* CloneL() const;
	
	IMPORT_C static CTzId* NewL(TUint aNumericId);
	IMPORT_C static CTzId* NewL(const TDesC8& aNameIdentity);
	
	/** 
	This should not be used. For internal use only.
	*/
	IMPORT_C static CTzId* NewL(RReadStream& aStream);
	
	/** 
	This should not be used. For internal use only. 
	*/
	IMPORT_C void SetId(TUint aNumericId);
	
	/** 
	This should not be used. For internal use only. 
	*/
	IMPORT_C void SetIdL(const TDesC8& aNameIdentity);
	
	/** 
	This should not be used. For internal use only. 
	*/
	IMPORT_C void InternalizeL(RReadStream& aStream);
	
	/** 
	This should not be used. For internal use only.
	*/
	IMPORT_C void ExternalizeL(RWriteStream& aStream) const;

	IMPORT_C const TDesC8& TimeZoneNameID() const;
	IMPORT_C TUint TimeZoneNumericID() const;

	IMPORT_C TBool IsUserTzId() const;
	IMPORT_C static TBool IsUserTzId(TUint aTzId);

	IMPORT_C TBool operator==(const CTzId& aTZId) const;
	inline TBool operator!=(const CTzId& aTZId) const;

public:
	void SetIdL(TUint aNumRefId, const TDesC8& aZoneIdentity);

private:
	void ConstructL();
	CTzId();
	CTzId(TUint aNumericId);

private:
	HBufC8* iZoneId;
	TUint32 iReferenceId;
	};

#include <tzid.inl>

#endif
