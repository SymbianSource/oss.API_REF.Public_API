// Copyright (c) 2006-2009 Nokia Corporation and/or its subsidiary(-ies).
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

#ifndef __LOGCNTDEF_H__
#define __LOGCNTDEF_H__

#include <e32def.h>

/** Contact item ID. These are used to uniquely identify contact items within a contacts database.
@internalAll */
typedef TInt32 TLogContactItemId;

/** NULL contact item ID. Indicates that no contact item is present.	
@internalAll */
const TLogContactItemId KLogNullContactId=-1;

/** Format for Given name, Family name string.
  -  Western format is Given followed by Family
  -  Chinese format is Family followed by Given
   	
@internalAll */
enum TLogContactNameFormat {ELogWesternFormat, ELogChineseFormat} ;

#endif
