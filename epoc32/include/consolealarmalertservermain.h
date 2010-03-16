/**
* Copyright (c) 1999-2009 Nokia Corporation and/or its subsidiary(-ies).
* All rights reserved.
* This component and the accompanying materials are made available
* under the terms of the License "Symbian Foundation License v1.0" to Symbian Foundation members and "Symbian Foundation End User License Agreement v1.0" to non-members
* which accompanies this distribution, and is available
* at the URL "http://www.symbianfoundation.org/legal/licencesv10.html".
*
* Initial Contributors:
* Nokia Corporation - initial contribution.
*
* Contributors:
*
* Description:
*
*/



#ifndef __CONSOLEALARMALERTSERVERMAIN_H__
#define __CONSOLEALARMALERTSERVERMAIN_H__

#include <e32base.h>

/**
@internalAll
*/

class ConsoleAlarmAlertServer
	{
public:
   	static TInt StartServerThreadFunction(TAny* instructionSet = NULL);

private:
	static void	StartServerL(TAny* instructionSet = NULL);
	};

#endif
