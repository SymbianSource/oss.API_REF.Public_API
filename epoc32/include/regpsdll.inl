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

inline TUidType CRegisteredParserDll::UidType() const
/** Gets the parser UID.

@return Parser UID */
	{
	return iUidType;
	}

inline void CRegisteredParserDll::SetUidType(const TUidType& aUidType)
/** Sets the parser UID.

@param aUidType Parser UID */
	{
	iUidType= aUidType;
	}

inline TInt CRegisteredParserDll::DllRefCount() const
/** Gets the parser reference count.

@return Parser reference count */
	{
	return iDllRefCount;
	}
