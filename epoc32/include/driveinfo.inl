/*
* Copyright (c) 2007 Nokia Corporation and/or its subsidiary(-ies). 
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
* Description:  Interface for quering the drive information of the system.
*
*/



// -----------------------------------------------------------------------------
// DriveInfo::TDriveArray::TDriveArray
// -----------------------------------------------------------------------------
//
inline DriveInfo::TDriveArray::TDriveArray()
    {
    }

// -----------------------------------------------------------------------------
// DriveInfo::TDriveArray::TDriveArray
// -----------------------------------------------------------------------------
//
inline DriveInfo::TDriveArray::TDriveArray( const TDriveList& aDriveList )
    {
    Set( aDriveList );
    }

// -----------------------------------------------------------------------------
// DriveInfo::TDriveArray::Reset
// -----------------------------------------------------------------------------
//
inline void DriveInfo::TDriveArray::Reset()
    {
    iArray.Zero();
    }

// -----------------------------------------------------------------------------
// DriveInfo::TDriveArray::Count
// -----------------------------------------------------------------------------
//
inline TInt DriveInfo::TDriveArray::Count() const
    {
    return iArray.Length();
    }

// -----------------------------------------------------------------------------
// DriveInfo::TDriveArray::operator[]
// -----------------------------------------------------------------------------
//
inline TDriveNumber DriveInfo::TDriveArray::operator[]( TInt aIndex ) const
    {
    return static_cast< TDriveNumber >( iArray[ aIndex ] );
    }

// End of File
