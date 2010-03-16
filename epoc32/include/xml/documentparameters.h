// Copyright (c) 2003-2009 Nokia Corporation and/or its subsidiary(-ies).
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

#ifndef __DOCUMENTPARAMETERS_H__
#define __DOCUMENTPARAMETERS_H__


#include <stringpool.h>

namespace Xml
{

class RDocumentParameters
/**
The RDocumentParameters class contains information about the document to be passed to the client.

@publishedAll
@released
*/
	{
public:

/**
@publishedPartner
@released
*/
	IMPORT_C RDocumentParameters();

/**
@publishedPartner
@released
*/
	IMPORT_C void Close();

/**
@publishedPartner
@released
*/
	IMPORT_C void Open(const RString& aCharacterSetName);

	IMPORT_C const RString& CharacterSetName() const;

private:


/**
@publishedPartner
@released
*/
	RDocumentParameters(const RDocumentParameters& aOriginal);

/**
@publishedPartner
@released
*/
	RDocumentParameters &operator=(const RDocumentParameters& aRhs);

private:

/**
The character encoding of the document.
The Internet-standard name of a character set, which is identified in Symbian OS by its UID
*/
	RString	iCharacterSetName;

	};

}

#endif
