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

#if !defined(__BAFINDF_H__)
#define __BAFINDF_H__

#include <e32base.h>
#include <f32file.h>

class CFindFileByType : public CBase
/**
@publishedAll
@released
*/
	{
public:
	IMPORT_C CFindFileByType(RFs& aFs);
	IMPORT_C ~CFindFileByType();
	IMPORT_C TInt FindFirst(const TDesC& aName,const TDesC& aDir,const TUidType& aType);
	IMPORT_C TInt FindNext();
	IMPORT_C const TEntry& Entry() const;
	inline const TParse& File() const;
private:
	void CloseDir();
private:
	TUidType iType;
	CDir* iDir;
	TInt iCurrentFile;
	TParse iFile;
	TFindFile iFind;
	};

inline const TParse& CFindFileByType::File() const
	{return iFile;}

#endif
