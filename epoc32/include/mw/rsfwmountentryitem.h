/*
* Copyright (c) 2002-2004 Nokia Corporation and/or its subsidiary(-ies).
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
* Description:  Mount entry item definitions
*
*/


#ifndef RSFWMOUNTENTRYITEM_H
#define RSFWMOUNTENTRYITEM_H

// DATA TYPES
enum TMountEntryItemIndex
    {
    EMountEntryItemIndex, // used for positioning the entry
    EMountEntryItemName,
    EMountEntryItemDrive,
    EMountEntryItemUri,
    EMountEntryItemUserName,
    EMountEntryItemPassword,
    EMountEntryItemIap,
    EMountEntryItemInactivityTimeout,
    EMountEntryItemReserved,
    EMountEntryItemCount
    };

#endif // RSFWMOUNTENTRYITEM_H

// End of File
