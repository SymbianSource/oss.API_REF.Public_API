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

#if !defined(__JISX0212_H__)
#define __JISX0212_H__

#if !defined(__E32STD_H__)
#include <e32std.h>
#endif

#if !defined(__CHARCONV_H__)
#include <charconv.h>
#endif

class CnvJisX0212 
/**
only to be used by CHARCONV plug-in DLLs
@internalComponent
*/
	{
public:
	IMPORT_C static const SCnvConversionData& ConversionData();
	};

#endif
