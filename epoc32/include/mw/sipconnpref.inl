// Copyright (c) 2005-2009 Nokia Corporation and/or its subsidiary(-ies).
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
// SIP extension events definition
// 
//

/**
 @file
 @publishedAll
 @released
*/


inline TSipConnPref::TSipConnPref() 
	: TConnPref(TConnPref::EConnPrefSip)
	{
	SetProfileId(0);
	}

inline void TSipConnPref::SetProfileId(TUint32 aProfileId)
	{
	PrefPtr()->iProfileId = aProfileId;
	}
	
inline TUint32 TSipConnPref::GetProfileId() const
	{
	return PrefPtr()->iProfileId;
	}
	
inline TSipConnPref& TSipConnPref::Cast(const TConnPref& aPref)
	{
	return (TSipConnPref&)aPref;
	}

inline SSipConnPref* TSipConnPref::PrefPtr() const
	{
	return (SSipConnPref*)UserPtr();
	}
	
