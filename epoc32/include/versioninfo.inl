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
* Description:  Interface for quering system version information.
*
*/



// -----------------------------------------------------------------------------
// VersionInfo::TVersionBase::TVersionBase
// -----------------------------------------------------------------------------
//
inline VersionInfo::TVersionBase::TVersionBase( TInt aType ) :
        iType( aType )
    {
    }

// -----------------------------------------------------------------------------
// VersionInfo::TPlatformVersion::TPlatformVersion
// -----------------------------------------------------------------------------
//
inline VersionInfo::TPlatformVersion::TPlatformVersion() :
        TVersionBase( VersionInfo::EPlatformVersion )
    {
    }

// End of File
