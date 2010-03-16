// Copyright (c) 1999-2009 Nokia Corporation and/or its subsidiary(-ies).
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

#ifndef __MPARSER_H__
#define __MPARSER_H__

#include <e32base.h>
#include <e32std.h>

class CRichText;
class TCharFormat;

/**
 * @internalTechnology
 * Internal to Symbian
 */
class MParser
	{
public:
	virtual TBool ParseThisText(const CRichText& aTextObj,
								TBool aAllowBack,
								TInt aStartScan,
								TInt aScanLength,
								TInt& aStartTag,
								TInt& aTagLength) = 0;

	virtual const TDesC& CreateDoItText(const CRichText& aTextObj,
										TInt aStartText,
										TInt aLength) = 0;

	virtual void ActivateThisTextL(const CRichText& aTextObj,
								   TInt aStartText,
								   TInt aLength) = 0;

	IMPORT_C virtual TBool ReformatOnRecognise() const;

	IMPORT_C virtual TBool ReformatOnRollover() const;

	IMPORT_C virtual void GetRecogniseFormat(TCharFormat& aFormat);

	IMPORT_C virtual void GetRolloverFormat(TCharFormat& aFormat);

	IMPORT_C virtual TBool ConfirmCursorOverTag(const CRichText& aTextObj,
												TInt aTagStart,
												TInt aTagLen,
												TInt aCurPos);

	IMPORT_C virtual void MParser_Reserved_2();

	//++ ADD COMMENT HERE (poss. provide default implement that panics)
	virtual void Release() = 0;
	};

#endif
