// Copyright (c) 2007-2009 Nokia Corporation and/or its subsidiary(-ies).
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
// Base class for Class 0 SMS plugin
// 
//



/**
 @publishedAll
 @released
*/

#ifndef __CSMSCLASS0BASE_H_
#define __CSMSCLASS0BASE_H_

#include <e32base.h>

class CSmsClass0Base : public CBase
	{

public:
	virtual void DisplayMessageHandler(TDesC8& aSmsMessage, TBool aComplete);
	~CSmsClass0Base();

protected:
	CSmsClass0Base();
	
	};

#endif
