/*
* Copyright (c) 2006 Nokia Corporation and/or its subsidiary(-ies). 
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
