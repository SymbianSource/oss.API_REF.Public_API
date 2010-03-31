/*
* ============================================================================
*  Name         : SimLockUIKeys.h
*  Part of      : Sim Lock UI Application
*  Description  : SimLock P&S keys
*  Version      : 
*  
* Copyright (c) 2005-2010 Nokia Corporation and/or its subsidiary(-ies).
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
* Description:   Build info file for Ado domain appinstall 
* ============================================================================
*/

#ifndef __SIMLOCKUI_KEYS_H__
#define __SIMLOCKUI_KEYS_H__

// System includes
#include <aknappui.h>
#include <aknnotedialog.h>  // CAknNoteDialog::TTone
#include <e32property.h>    // RProperty.


// FORWARD DECLARATIONS
class RProperty;
const TUid KSimLockProperty={0x10003b21};


enum TSimLockPropertyKeys  { ESimLockProperty, ESimLockActiveStatus };

/**
 *0: Default value
 *1: Indicates that "function" is done 
*/
enum TSimLockActiveStatus
  {
   KSimLockStatusUnknown = 0,
   KSimLockStatusDone
   };

#endif // __SIMLOCKUI_KEYS_H__

// End of file.
