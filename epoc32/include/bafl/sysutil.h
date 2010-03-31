/*
* Copyright (c) 2000-2006 Nokia Corporation and/or its subsidiary(-ies). 
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
* Description:  SysUtil API provides functions for applications to retrieve
*                SW and language package versions and check whether there is
*                free space on a disk drive.
*
*/


#ifndef SYSUTIL_H
#define SYSUTIL_H

#include <e32base.h>

/**
* Helper constant to allocate buffers for GetSWVersion, GetLangSWVersion,
* GetLangVersion.
*/
const TInt KSysUtilVersionTextLength = 64;

class RFs;

/**
 *  SysUtil provides various utility methods for applications.
 *
 *  SysUtil API provides functions for applications to retrieve SW and language
 *  package versions and check whether there is free space on a disk drive.
 *
 *  @lib sysutil.lib
 *  @since S60 v2.0
 */
class SysUtil
    {

public:

    /**
     * Obtains the software version string.
     *
     * @since S60 v2.0
     *
     * Usage example:
     * @code
     * TBuf<KSysUtilVersionTextLength> version;
     * if ( SysUtil::GetSWVersion( version ) == KErrNone )
     *     {
     *     // Use the version string.
     *     ...
     *     }
     * @endcode
     *
     * @param aValue On return, contains the software version string.
     *               The buffer should have space for KSysUtilVersionTextLength
     *               characters.
     *
     * @return KErrNone on success, or one of the Symbian error codes if reading
     *         the version string fails.
     */
    IMPORT_C static TInt GetSWVersion( TDes& aValue );

    /**
     * Returns software version which the currently installed language package
     * is compatible with.
     *
     * @since S60 v2.0
     *
     * @param aValue On return, contains the version string.
     *               The buffer should have space for KSysUtilVersionTextLength
     *               characters.
     *
     * @return KErrNone on success, or one of the Symbian error codes if reading
     *         the version string fails.
     */
    IMPORT_C static TInt GetLangSWVersion( TDes& aValue );

    /**
     * Obtains the version of the currently installed language package.
     *
     * @since S60 v2.0
     *
     * @param aValue On return, contains the language package version string.
     *               The buffer should have space for KSysUtilVersionTextLength
     *               characters.
     *
     * @return KErrNone on success, or one of the Symbian error codes if reading
     *         the version string fails.
     */
    IMPORT_C static TInt GetLangVersion( TDes& aValue );

    /**
     * Checks if free FFS (internal flash file system) storage space is or will
     * fall below critical level. Static configuration value stored in Central
     * Repository is used to determine the critical level for the FFS drive.
     *
     * @since S60 v2.0
     *
     * @param aFs File server session. Must be given if available, e.g. from
     *            EIKON environment. If NULL, this method will create a
     *            temporary session, which causes the method to consume more
     *            time and system resources.
     * @param aBytesToWrite Number of bytes the caller is about to write to
     *                      FFS. If value 0 is given, this method checks
     *                      if the current FFS space is already below critical
     *                      level.
     *
     * @return ETrue if FFS space would go below critical level after writing
     *         aBytesToWrite more data, EFalse otherwise.
     *
     * @leave Leaves with one of the Symbian error codes if checking the FFS
     *        space fails, for instance if there is not enough free memory to
     *        create a temporary connection to file server.
     */
    IMPORT_C static TBool FFSSpaceBelowCriticalLevelL(
        RFs* aFs,
        TInt aBytesToWrite = 0 );


    /**
     * Checks if free MMC storage space is or will fall below critical
     * level. Static configuration value stored in Central Repository is
     * used to determine the critical level for the MMC drive.
     * PathInfo API is used to determine the drive letter for the MMC drive.
     *
     * @since S60 v2.0
     *
     * @param aFs File server session. Must be given if available, e.g. from
     *            EIKON environment. If NULL, this method will create a
     *            temporary session, which causes the method to consume more
     *            time and system resources.
     * @param aBytesToWrite Number of bytes the caller is about to write to
     *                      MMC. If value 0 is given, this method checks
     *                      if the current MMC space is already below critical
     *                      level.
     *
     * @return ETrue if MMC space would go below critical level after writing
     *         aBytesToWrite more data, EFalse otherwise.
     *         EFalse if the system has no MMC drive support.
     *
     * @leave Leaves with one of the Symbian error codes if checking the MMC
     *        space fails, for instance if the MMC drive contains no media or
     *        there is not enough free memory to create a temporary connection to
     *        file server.
     */
    IMPORT_C static TBool MMCSpaceBelowCriticalLevelL(
        RFs* aFs,
        TInt aBytesToWrite = 0 );

    /**
     * Checks if free disk drive storage space is or will fall below critical
     * level. Static configuration values stored in Central Repository are
     * used to determine a critical level for each drive.
     *
     * Usage example:
     * @code
     * TInt dataSize = 500;
     * if ( SysUtil::DiskSpaceBelowCriticalLevelL( &iFsSession, dataSize, EDriveC ) )
     *     {
     *     // Can not write the data, there's not enough free space on disk.
     *     ...
     *     }
     * else
     *     {
     *     // It's ok to actually write the data.
     *     ...
     *     }
     * @endcode
     *
     * @since S60 v2.0
     *
     * @param aFs File server session. Must be given if available, e.g. from
     *            EIKON environment. If NULL, this method will create a
     *            temporary session, which causes the method to consume more
     *            time and system resources.
     * @param aBytesToWrite Number of bytes the caller is about to write to
     *                      disk. If value 0 is given, this method checks
     *                      if the current disk space is already below critical
     *                      level.
     * @param aDrive Identifies the disk drive to be checked. Numeric values
     *               for identifying disk drives are defined in TDriveNumber
     *               enumeration.
     *
     * @see TDriveNumber in f32file.h.
     *
     * @return ETrue if disk space would go below critical level after writing
     *         aBytesToWrite more data, EFalse otherwise.
     *
     * @leave Leaves with one of the Symbian error codes if checking the disk
     *        space fails, for instance if the drive contains no media or there
     *        is not enough free memory to create a temporary connection to
     *        file server.
     */
    IMPORT_C static TBool DiskSpaceBelowCriticalLevelL(
        RFs* aFs,
        TInt aBytesToWrite,
        TInt aDrive );

    };

#endif // SYSUTIL_H
