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
* CIdentity declaration
*
*/


/**
 @file 
 @publishedAll
 @released
*/

#ifndef IDENTITY_H
#define IDENTITY_H

#include "authserver/authtypes.h"
#include "authserver/protectionkey.h"

namespace AuthServer
{
/**
 * CIdentity is an client side class of the authentication server. 
 * CIdentity is returned as the result of an authentication.
 * 
 */
class CIdentity : public CBase
	{
public:

    IMPORT_C static CIdentity* NewL(TIdentityId aId,
									CProtectionKey* aKey,
									HBufC* aString);
	
    IMPORT_C static CIdentity* NewLC(TIdentityId aId,
									 CProtectionKey* aKey,
									 HBufC* aString);
	
    IMPORT_C static CIdentity* NewL(RReadStream& aStream);
    IMPORT_C static CIdentity* NewLC(RReadStream& aStream);
    
	virtual ~CIdentity();

	IMPORT_C TIdentityId Id() const;

	IMPORT_C const CProtectionKey& Key() const;

	IMPORT_C TDesC& String() const;
	
	IMPORT_C void ExternalizeL(RWriteStream& s) const;
	IMPORT_C static CIdentity* InternalizeL(RReadStream& s);

private:
	void ConstructL(CProtectionKey* aKey,
					HBufC* aString);
	
	CIdentity(TIdentityId aId);

private:
    TIdentityId           iId;
    CProtectionKey* iKey;
	HBufC*                iString;
	};
}

#endif // IDENTITY_H
