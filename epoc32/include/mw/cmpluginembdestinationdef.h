/*
* Copyright (c) 2006 Nokia Corporation and/or its subsidiary(-ies). 
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
* Description:  Embedded destination attribute descriptor header.
*
*/

#ifndef CMEMBEDDEDDESTINATION_H
#define CMEMBEDDEDDESTINATION_H

// Bearer type of the embedded destination
/**  ECOM interface UID */
const TUint KUidEmbeddedDestination  = 0x10207379;

// Embedded destination plugin has no special attribute. Call ::Destination()
// function of interface class to get destination object.
// The following common attribute are supported:
// - ECmBearerType  (read-only)
// - ECmName,       (read/write)
// - ECmIapId       (returns destination Id! read-only)
// - ECmCoverage    (always return EFalse. read-only)
// - ECmProtected   (read/write)
// - ECmDestination (always return ETrue. read-only)
// - ECmHidden      (read/write)
// - ECmDefaultPriority (read-only)

#endif // CMEMBEDDEDDESTINATION_H
