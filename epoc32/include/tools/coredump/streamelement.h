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
//


#ifndef STREAMELEMENT_H
#define STREAMELEMENT_H

#include <e32base.h>
#include <s32mem.h>

#include <rm_debug_api.h>
#include <debuglogging.h>

/**
@internalTechnology 
@released

Pure virtual base class for streamable classes. 
Used when a class must be passed accross a client server interface
*/
class CStreamElementBase : public CBase
{

public:
	
	virtual ~CStreamElementBase()
		{
		}

	/** 
	Creates HBufC8 with a representation of ’this’ object
	*/
	IMPORT_C  HBufC8* MarshalDataL();


	TInt static MaxSize()
		{
		return 0;
		}

	virtual TInt Size() const = 0;

	// Initializes ’this’ from stream
	virtual void InternalizeL( RReadStream & aStream ) = 0;

	// Writes ’this’ to the stream
	virtual void ExternalizeL( RWriteStream & aStream, CBufFlat* buf ) = 0;

	TUint32 iSpare1;
	TUint32 iSpare2;
};

#endif // STREAMELEMENT_H
