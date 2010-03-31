/*
* Copyright (c) 2004-2007 Nokia Corporation and/or its subsidiary(-ies).
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
* Description:  Constants for synchronization fields of contacts.
*                If store plugin implementation supports a synchronization
*                field R_VPBK_FIELD_TYPE_SYNCCLASS then these constants must be
*                used as a data.
*
*/


#ifndef VPBKSYNCCONSTANTS_H
#define VPBKSYNCCONSTANTS_H

//  INCLUDES
#include <e32def.h>

/**
 * A data for Private class.
 */
_LIT(KVPbkContactSyncPrivate, "private");

/**
 * A data for Public class.
 */
_LIT(KVPbkContactSyncPublic, "public");

/**
 * A data for non-defined synchronization field.
 */
_LIT(KVPbkContactSyncNoSync, "none");


#endif // VPBKSYNCCONSTANTS_H
            
// End of File
