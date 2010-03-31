// Copyright (c) 2008-2009 Nokia Corporation and/or its subsidiary(-ies).
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

#ifndef __TZLOCALIZEDCITYRECORD_INL__
#define __TZLOCALIZEDCITYRECORD_INL__

inline const TDesC& CTzLocalizedCityRecord::Name() const
	{
	return *iName; 
	}
	
inline TUint8 CTzLocalizedCityRecord::GroupId() const
	{
	return iGroupId; 
	}

inline TInt CTzLocalizedCityRecord::Index() const
	{
	return iIndex; 
	}

inline TUint16 CTzLocalizedCityRecord::TzId() const
	{
	return iTzId;
	}

inline TUint CTzLocalizedCityRecord::TzResourceId() const
	{
	return iTzResourceId;
	}
	
#endif
