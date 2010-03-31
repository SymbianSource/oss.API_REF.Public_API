// Copyright (c) 1998-2009 Nokia Corporation and/or its subsidiary(-ies).
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
//



/**
 @file
 @publishedAll
 @released
*/
#if !defined(__MSVREGUD_H__)
#define __MSVREGUD_H__

#include <e32base.h>
#include <msvstd.hrh>

/**
* @internalAll
* @released
*/
const TInt KMsvNumMtmDllTypes=4;
/**
* @internalAll
* @released
*/
const TUid KUidMsvDataComponent     ={0x10003C69};
// Server-side MTM 
/**
* @publishedAll
* @released
*/
const TUid KUidMtmServerComponent	={KUidMtmServerComponentVal};
// Client-side MTM 
/**
* @publishedAll
* @released
*/
const TUid KUidMtmClientComponent	={KUidMtmClientComponentVal};
// User Interface MTM
/**
* @internalAll
* @released
*/
const TUid KUidMtmUiComponent		={KUidMtmUiComponentVal};
// UI Data MTM 
/**
* @internalAll
* @released
*/
const TUid KUidMtmUiDataComponent	={KUidMtmUiDataComponentVal};
/**
* @internalTechnology
* @released
*/
const TUid KMsvDllType1Uid={0x10003C62}; 
/**
* @internalTechnology
* @released
*/
const TUid KMsvDllType2Uid={0x10003C63};
/**
* @internalTechnology
* @released
*/
const TUid KMsvDllType3Uid={0x10003C64};
/**
* @internalTechnology
* @released
*/
const TUid KMsvDllType4Uid={0x10003C65};
/**
* @internalTechnology
* @released
*/
const TUid KMsvDllType5Uid={0x10003C66};
/**
* @internalTechnology
* @released
*/
const TUid KMsvDllType6Uid={0x10003C67};
/**
* @internalComponent
* @released
*/
const TUid KUidMtmMultipleComponent	={0x10004845}; 

#endif
