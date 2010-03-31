// Copyright (c) 1997-2009 Nokia Corporation and/or its subsidiary(-ies).
// All rights reserved.
// This component and the accompanying materials are made available
// under the terms of "Eclipse Public License v1.0"
// which accompanies this distribution, and is available
// at the URL "http://www.eclipse.org/legal/epl-v10.html".
//
// Initial Contributors:
// Nokia Corporation - initial contribution.
//
// Contributors:
//
// Description:
//

#ifndef __TZID_INL__
#define __TZID_INL__

/**
Inequality operator.

@param aTZId The time zone ID to compare with this one.

@return ETrue if the two IDs are different, EFalse if they are the same.
*/
inline TBool CTzId::operator!=(const CTzId& aTZId) const
	{
	return (!operator==(aTZId));
	}

#endif
