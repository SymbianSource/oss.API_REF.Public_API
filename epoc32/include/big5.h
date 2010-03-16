// Copyright (c) 2000-2009 Nokia Corporation and/or its subsidiary(-ies).
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

#if !defined(__BIG5_H__)
#define __BIG5_H__

#if !defined(__E32STD_H__)
#include <e32std.h>
#endif

#if !defined(__CHARCONV_H__)
#include <charconv.h>
#endif

class CnvBig5 
/**
only to be used by CHARCONV plug-in DLLs and by locale-DLLs (Locl::FatUtilityFunctions)
@internalComponent
*/
	{
public:
	IMPORT_C static const TDesC8& ReplacementForUnconvertibleUnicodeCharacters();
	IMPORT_C static const SCnvConversionData& ConversionData();
	};

#endif
