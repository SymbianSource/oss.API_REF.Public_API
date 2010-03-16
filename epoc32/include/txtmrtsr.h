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

#ifndef __TXTMRTSR_H__
#define __TXTMRTSR_H__

#include <e32std.h>

class CStreamStore;

class MRichTextStoreResolver
/**
A call back for determining a store as a function of the document position.
In practice, used in the potentially defered restoring of new pictures from a store.
The store might not actually vary with document position, in which case the function is
guaranteed not to leave.
@internalAll 
*/
	{
public:
	virtual const CStreamStore& StreamStoreL(TInt aPos)const=0;
	};

#endif
