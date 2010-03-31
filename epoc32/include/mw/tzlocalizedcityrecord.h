// Copyright (c) 2008-2009 Nokia Corporation and/or its subsidiary(-ies).
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

#ifndef __TZLOCALIZEDCITYRECORD_H__
#define __TZLOCALIZEDCITYRECORD_H__

#include <e32base.h>
#include <s32std.h>

/**
Class used instead of CTzLocalizedCity which we can't use in TZ. 

@internalTechnology
*/
class CTzLocalizedCityRecord : public CBase
	{
public:
	IMPORT_C static CTzLocalizedCityRecord* NewL(const TDesC& aName, TUint8 aGroupId, TInt aIndex,
		TInt aTzId, TUint aTzResourceId);
	IMPORT_C static CTzLocalizedCityRecord* NewLC(const TDesC& aName, TUint8 aGroupId, TInt aIndex,
		TInt aTzId, TUint aTzResourceId);
	IMPORT_C static CTzLocalizedCityRecord* NewL(RReadStream& aStream);
	IMPORT_C static CTzLocalizedCityRecord* NewLC(RReadStream& aStream);
	IMPORT_C ~CTzLocalizedCityRecord();
	IMPORT_C static void CleanupArray(TAny* aArray);
	
private:
	CTzLocalizedCityRecord();
	CTzLocalizedCityRecord(TUint8 aGroupId, TInt aIndex, TUint aTzResourceId);
	void ConstructL(const TDesC& aName, TInt aTzId);
	void ConstructL(RReadStream& aStream);
	
public:
	inline const TDesC& Name() const;
	inline TUint8 GroupId() const;
	inline TInt Index() const;
	inline TUint16 TzId() const;
	inline TUint TzResourceId() const;
	
public:
	IMPORT_C TInt ExternalizeSize() const;
	IMPORT_C void ExternalizeL(RWriteStream& aStream) const;
	IMPORT_C static TInt ExternalizeSize(const RPointerArray<CTzLocalizedCityRecord>& aCities);
	IMPORT_C static void ExternalizeL(const RPointerArray<CTzLocalizedCityRecord>& aCities, 
		RWriteStream& aStream);
	IMPORT_C static void InternalizeL(RReadStream& aStream, RPointerArray<CTzLocalizedCityRecord>& aCities);
	
private:
	HBufC* iName;
	TUint8 iGroupId;
	TInt iIndex;
	TUint16 iTzId;
	TUint iTzResourceId;
	};
	
#include "tzlocalizedcityrecord.inl"
	
#endif
