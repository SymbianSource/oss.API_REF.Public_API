/*
* Copyright (c) 2001 Nokia Corporation and/or its subsidiary(-ies).
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
* Description:
*
*/


#ifndef __EIKLAY_H__
#define __EIKLAY_H__

#include <frmtlay.h>

class TAvkonEditorCustomWrap : public MFormCustomWrap
	{
public:
	enum
		{
		EAvkSpaceLineBreakClass=MTmCustom::ELineBreakClasses, // 29
		EAvkLineBreakClasses
		};

public:
	// overrides of line break functions from MFormCustomWrap
	TUint LineBreakClass(TUint aCode,TUint& aRangeStart,TUint& aRangeEnd) const;
	TBool LineBreakPossible(TUint aPrevClass,TUint aNextClass,TBool aHaveSpaces) const;
	};

#endif // __EIKLAY_H__
