/*
* Copyright (c) 2005 Nokia Corporation and/or its subsidiary(-ies). 
* All rights reserved.
* This component and the accompanying materials are made available
* under the terms of "Eclipse Public License v1.0"
* which accompanies this distribution, and is available
* at the URL "http://www.eclipse.org/legal/epl-v10.html".
*
* Initial Contributors:
* Nokia Corporation - initial contribution.
*
* Contributors:
*
* Description:  SDK Central Repository definitions of the
*                Core Application UIs subsystem
*
*/


#ifndef COREAPPLICATIONUISSDKCRKEYS_H
#define COREAPPLICATIONUISSDKCRKEYS_H

// INCLUDES
#include <centralrepository.h>

const TUid KCRUidCoreApplicationUIs = { 0x101F876C };

// =============================================================================
// Network Status API 
// =============================================================================

/**
* This key indicates whether network connections are allowed. E.g. is Offline Mode
* active.
*
* @see TCoreAppUIsNetworkConnectionAllowed
*/
const TUint32 KCoreAppUIsNetworkConnectionAllowed  = 0x00000001;
enum TCoreAppUIsNetworkConnectionAllowed
    {
    ECoreAppUIsNetworkConnectionNotAllowed = 0,   ///< Network connection not allowed
    ECoreAppUIsNetworkConnectionAllowed           ///< Network connection allowed
    };

#endif      // COREAPPLICATIONUISSDKCRKEYS_H

// End of File

