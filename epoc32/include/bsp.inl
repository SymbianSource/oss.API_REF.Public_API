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

inline void TMsvBIOEntry::SetBIOParserUid(const TUid aId)
/** Sets the BIO parser UID.

@param aId BIO parser UID */
	{
	iBioType = aId.iUid;
	}
	
inline const TUid TMsvBIOEntry::BIOParserUid() const
/** Gets the BIO parser UID.

@return BIO parser UID */
	{
	return TUid::Uid(iBioType);
	}

inline void TMsvBIOEntry::SetLocationOfData(const TMsvBIODataLocation aLocation)
/** Sets the BIO data location flag.

@param aLocation BIO data location flag */
	{
	iLocationOfData = aLocation;
	}

inline const TMsvBIODataLocation TMsvBIOEntry::LocationOfData() const
/** Gets the BIO data location flag.

@return BIO data location flag */
	{
	return iLocationOfData;
	}
