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


inline TInt CProtocolBase::RefCount() const
/**
Reference counting by protocols created by protocol families.

@return number of protocols
*/
	{ return iRefCount; }

inline TInt CProtocolFamilyBase::RefCount() const
	{
	return iRefCount;
	}

inline void CResolverProvdBase::SetNotify(MResolverNotify * aNotifier)
	{ iNotify=aNotifier; }
