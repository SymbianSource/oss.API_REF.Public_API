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
* CIdAndString class declaration
*
*/


/**
 @file 
 @publishedAll
 @released
*/

#ifndef IDANDSTRING_H
#define IDANDSTRING_H

#include <s32strm.h>
#include <ct/rcpointerarray.h>
#include "authserver/authtypes.h"

namespace AuthServer
{
/**
 * CIdAndString is an client side class of the authentication server. 
 * It contains the relevant identity and corresponding displayable
 * text associated with this identity.
 * 
 */
NONSHARABLE_CLASS(CIdAndString) : public CBase
	{
public:

	IMPORT_C static CIdAndString* NewLC(TIdentityId aId, const TDesC& aString);
	IMPORT_C static CIdAndString* NewLC(RReadStream& aStream);

	IMPORT_C void ConstructL(TIdentityId aId, const TDesC& aString);
	
	IMPORT_C ~CIdAndString(); 

	IMPORT_C void ExternalizeL(RWriteStream& aStream) const;
	void InternalizeL(RReadStream& aStream);
	
	IMPORT_C TIdentityId   Id()     const;
	IMPORT_C HBufC*        String() const;
	
private:
	TIdentityId iId;
	HBufC*      iString;
	};

typedef RCPointerArray<CIdAndString> RIdAndStringArray;

}   

#endif // IDANDSTRING_H
