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
// CParserPropertyValueAgent
// 
//

inline CParserVCard* CParserPropertyValueAgent::Value() const
/** Gets the agent object owned by the property value.

@return A pointer to the agent property value. */
	{return iValue;}

inline void CParserGroupedProperty::SetGroups(CDesC8Array* aArrayOfGroups)
/** Sets the list of groups to which the property belongs, replacing any existing 
list.

@param aArrayOfGroups Array of descriptors; each of which specifies 
a group name. The grouped property takes ownership of the array. */
	{iArrayOfGroups=aArrayOfGroups;}

inline const CDesC8Array* CParserGroupedProperty::Groups()
/** Gets the groups to which the property belongs.

@return Pointer to an array of descriptors. Each one specifies a group name. */
	{return iArrayOfGroups;}
