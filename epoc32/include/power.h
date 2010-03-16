// Copyright (c) 2001-2009 Nokia Corporation and/or its subsidiary(-ies).
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

#ifndef __POWER_H__
#define __POWER_H__

#include <e32std.h>


/**
Client power manager

This class gives applications and servers access to
UIKON's machine specific power management functionality
as defined in LafPowerMan
@internalComponent
*/
class PowerManager
	{
public:
	IMPORT_C static void SwitchOn();
	};

/**
@internalComponent
*/
enum TPowerManagerPanic { EPowerManagerCantGetDisplayState };

#endif
