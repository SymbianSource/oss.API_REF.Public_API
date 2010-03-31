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
// CParserPropertyValueAlarm
// 
//

inline CVersitAlarm* CParserPropertyValueAlarm::Value() const
/** Gets a pointer to the alarm property value.

@return Pointer to the alarm property value. */
	{return iValue;}

//
// CParserPropertyValueExtendedAlarm
//
inline CVersitExtendedAlarm* CParserPropertyValueExtendedAlarm::Value() const
/** Gets a pointer to the extended alarm property value.

@return Pointer to the extended alarm property value. */
	{return iValue;}
