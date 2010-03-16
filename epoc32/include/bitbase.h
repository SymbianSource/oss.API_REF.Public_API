// Copyright (c) 1997-2009 Nokia Corporation and/or its subsidiary(-ies).
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

#ifndef __BITBASE_H__
#define __BITBASE_H__

#include <gdi.h>

/**
@internalComponent
*/
class TSpriteBase
	{
public:
	virtual void Hide(const TRect& aRect,const TRegion* aRegion)=0;
	virtual void Reveal(const TRect& aRect,const TRegion* aRegion)=0;
	};

#endif
