// Copyright (c) 1998-2009 Nokia Corporation and/or its subsidiary(-ies).
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

#include <msvstd.h>

#if !defined(__MSVUTILS_H__)
#define __MSVUTILS_H__

_LIT(KMsvUtilsNewExtension,".new");

class MsvUtils
/**
@internalAll
@released
*/
	{
public:
/**
@internalAll
@released
*/
	enum TNameMode {EStore, EFolder, EPath};
	IMPORT_C static TBool ValidEntry(const TMsvEntry& aEntry);
	IMPORT_C static void ConstructEntryName(TMsvId aService, TMsvId aEntry, TDes& aName, TNameMode aMode);
	IMPORT_C static TInt HasDirectory(const RFs& aFs, const TDesC& aMessageFolder, TMsvId aService, TMsvId aEntry);
	IMPORT_C static TInt HasStore(const RFs& aFs, const TDesC& aMessageFolder, TMsvId aService, TMsvId aEntry);
	static TBool ValidEntry(const TMsvEntry& aEntry, TBool aCreate);
	IMPORT_C static void AddPathAndExtensionToResFileL(TFileName& aFileName);
	};

#endif
