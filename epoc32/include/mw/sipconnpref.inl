// Copyright (c) 2005-2009 Nokia Corporation and/or its subsidiary(-ies).
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
// SIP extension events definition
// 
//



/**
 @file
 @publishedAll
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
	
