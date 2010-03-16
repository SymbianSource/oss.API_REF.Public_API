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
// Interface class for listing/removing uninstalled packages from a removable drive
// 
//



/**
 @file 
 @publishedAll
 @released
*/

#ifndef __PKGREMOVER_H__
#define __PKGREMOVER_H__

#include <e32base.h>
#include <f32fsys.h>
#include <s32mem.h>

namespace Swi
{

class CUninstalledPackageEntry;


/**
 * This class provides static methods for managing uninstalled native packages
 * (SIS files) that are taking up space on removable drives.
 *
 * @publishedAll
 * @released
 */

NONSHARABLE_CLASS(UninstalledSisPackages)
{
public:

	/**
	 * Get the list of uninstalled packages on a specified removable drive. In
	 * this context uninstalled means 'not known by this phone'. This will list
	 * uninstalled PA & PP files found in the SWI Daemon's private directory, and
	 * will also search the sis registry files on the drive for uninstalled
	 * applications.
	 *
	 * @param aDrive    		Removable drive number (@see TDriveNumber)
	 * @param aPackageList      Array of pointers to the uninstalled packages
	 *							found on the specified drive (@see
	 *                          CUninstalledPackageEntry). This array is assumed to be empty.
	 *							The caller takes ownership of the elements added to the array.
	 * @leave					One of the system-wide error codes.
	 * @leave                   KErrNotRemovable If the drive is not removable or is substed
	 * @leave					KErrPackageFileCorrupt If an error occurs during the processing of files
	 * @capability              ReadDeviceData Required to access protected directories during listing operation
	 * @capability              ProtServ Required to access services of software installer
	 * @capability             	TrustedUI Required to access services of software installer
	 */
	IMPORT_C static void ListL(TDriveNumber aDrive, RPointerArray<CUninstalledPackageEntry>& aPackageList);

	/**
	 * Remove the specified uninstalled package. The following restrictions apply to the files that will be removed:
	 * <ul>
	 * <li> For security reasons only files on the same drive as the package controller will be removed. Files on other drives will be orphaned.
	 * <li> Files belonging to other packages will not be removed.
	 * </ul>
	 *
	 * @param aPackage			The uninstalled package to remove (@see CUninstalledPackageEntry)
	 * @leave					One of the system-wide error codes.
	 * @leave                   KErrNotRemovable If the drive is not removable or is substed
	 * @leave					KErrPackageIsInstalled If the specified package is installed on the device
	 * @leave					KErrPackageFileCorrupt If an error occurs during the processing of files
	 * @capability				WriteDeviceData Required to write to protected directories during remove operation
	 * @capability				ProtServ Required to access services of software installer
	 * @capability				TrustedUI Required to access services of software installer
	 */
	IMPORT_C static void RemoveL(const CUninstalledPackageEntry& aPackage);
};


/**
 * Uninstalled application entry class.
 *
 * This class is not externally instantiable. It is returned as a result of 
 * querying for a list of uninstalled packages present on a removable drive. 
 * Each object of this type represents one uninstalled package. Methods can 
 * be called on this object to retrieve the package details such as 
 * Package UID, Name, Vendor, Version and Type.
 *
 * @publishedAll
 * @released
 */

NONSHARABLE_CLASS(CUninstalledPackageEntry) : public CBase
{
public:
	enum TPackageType
	{
	    ESaPackage,       ///< Standard Application
		ESpPackage,       ///< Standard Patch (augmentation)
		EPuPackage,       ///< Partial Upgrade
		EPaPackage,       ///< Preinstalled Application
		EPpPackage        ///< Preinstalled Patch
	};

	/**
	 * Get the package Uid
	 *
	 * @return The Uid of this package
	 */
	IMPORT_C const TUid& Uid() const;

	/**
	 * Get the package name
	 *
	 * @return The name of this package as reference to TDesC
	 */
	IMPORT_C const TDesC& Name() const;

	/**
	 * Get the package unique vendor name
	 *
	 * @return The unique vendor name of this package as reference to TDesC
	 */
	IMPORT_C const TDesC& Vendor() const;

	/**
	 * Get the package version
	 *
	 * @return The version number of this package
	 */
	IMPORT_C const TVersion& Version() const;

	/**
	 * Get the package type
	 *
	 * @return The package type of this package
	 */
	IMPORT_C const TPackageType& PackageType() const;

	/**
	* Destructor
	*/
	virtual ~CUninstalledPackageEntry();

private:
	static CUninstalledPackageEntry* NewLC(const TUid& aUid, const TDesC& aPackageName,
		const TDesC& aVendorName, const TVersion& aVersion, const TPackageType aPackageType,
		const TDesC& aPackageFile, const TDesC& aAssocStubSisFile);

private:
	CUninstalledPackageEntry();

private:
	void ConstructL(const TUid& aUid, const TDesC& aPackageName, const TDesC& aVendorName, 
		const TVersion& aVersion, const TPackageType aPackageType, const TDesC& aPackageFile,
		const TDesC& aAssocStubSisFile);

	const TDesC& PackageFile() const;
	const TDesC& AssociatedStubSisFile() const;

private:
	/// The package Uid
	TUid iUid;

    /// The package name
	HBufC* iPackageName;

    /// The package unique vendor name
	HBufC* iVendorName;

    /// The package version
	TVersion iVersion; 

	/// The package type
	TPackageType iType;

	// The sis/controller file name with full path
	HBufC* iPackageFile;

	// The stub sis file name with full path (if the package file is a controller file)
	HBufC* iAssocStubSisFile;
private:
	friend class UninstalledSisPackages;
};

} // namespace Swi

#endif // __PKGREMOVER_H__
