/**
* Copyright (c) 2004-2009 Nokia Corporation and/or its subsidiary(-ies).
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





/**
 @file MetaData.inl
 @internalTechnology
*/

#ifndef __METADATA_INL__
#define __METADATA_INL__

namespace Meta
{


STypeId::STypeId()
/**
 * Constructor
 */
	{
	iUid.iUid = 0;
	iType = 0;
	}

STypeId::STypeId(TUint32 aUid, TUint32 aTypeId)
/**
 * Constructor
 */
	{
	iUid.iUid = aUid;
	iType = aTypeId;
	}

}	// namespace Meta
#endif	// __METADATA_INL__
