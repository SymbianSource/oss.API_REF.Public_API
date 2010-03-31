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
// Definition of the package list/remove error codes
// 
//



/**
 @file 
 @publishedAll
 @released
*/

#ifndef __PKGREMOVERERRORS_H__
#define __PKGREMOVERERRORS_H__

#include <e32std.h>

/**
*
* A non-removable drive was passed.
*
*/
const TInt KErrNotRemovable = -10280;
/**
*
* No uninstalled packages were found.
*
*/
const TInt KErrNoUninstalledPackages = -10281;
/**
*
* The package being attempted to remove is installed on the device.
*
*/
const TInt KErrPackageIsInstalled = -10282;
/**
*
* The package being attempted to list/remove is corrupted.
*
*/
const TInt KErrPackageFileCorrupt = -10283;

#endif
