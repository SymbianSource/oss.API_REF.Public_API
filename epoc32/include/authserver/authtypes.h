/*
* Copyright (c) 2005-2009 Nokia Corporation and/or its subsidiary(-ies).
* All rights reserved.
* This component and the accompanying materials are made available
* under the terms of the License "Eclipse Public License v1.0"
* which accompanies this distribution, and is available
* at the URL "http://www.eclipse.org/legal/epl-v10.html".
*
* Initial Contributors:
* Nokia Corporation - initial contribution.
*
* Contributors:
*
* Description: 
* Basic typedefs used by the Authentication Server
*
*/


/**
 @file 
 @publishedAll
 @released
*/

#ifndef AUTHTYPES_H
#define AUTHTYPES_H

#include <e32cmn.h>

namespace AuthServer
{
typedef TUint32 TIdentityId;
typedef TUint32 TPluginId;

typedef TUint32 TEntropy;
typedef TUint32 TPercentage;

/////////////
// constants and enums 
/////////////

const TUint32 KUnknownPluginId = 0;
const TUint32 KUnknownIdentity = 0;
const TUid KAuthServerSecureId = { 0x102740FC };
const TInt KMaxDescLen = 255;

enum TAuthPluginType
    {
	EAuthDefault   = 0,
    EAuthBiometric = 1,
    EAuthKnowledge = 64,
    EAuthToken     = 128,
	EAuthPerformance = 192
    };
    
enum TAuthTrainingStatus
    {
    EAuthUntrained    = 1,
    EAuthTrained      = 64,
    EAuthFullyTrained = 128,
    };

/// Array types used by clients and server
typedef RArray<TIdentityId>              RIdentityIdArray;
typedef RArray<TPluginId>                RPluginIdArray;


}   

#endif // AUTHTYPES_H
