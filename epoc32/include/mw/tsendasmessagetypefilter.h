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

#ifndef __TSENDASMESSAGETYPEFILTER_H__
#define __TSENDASMESSAGETYPEFILTER_H__


#include <rsendas.h>

/**
This class encapsulates filter information for available message type modules
(MTMs) held by the SendAs session.

@publishedAll
@released
*/
class TSendAsMessageTypeFilter
	{
public:
	IMPORT_C TSendAsMessageTypeFilter();
	IMPORT_C TSendAsMessageTypeFilter(TUid aMsgCap);
	IMPORT_C TSendAsMessageTypeFilter(TUid aMsgCap, TInt aVal, RSendAs::TSendAsConditionType aCond);
	IMPORT_C void Reset();
public:
	TUid iMessageCapability;
	TInt iValue;
	RSendAs::TSendAsConditionType iCondition;
	};


#endif	// __TSENDASMESSAGETYPEFILTER_H__
