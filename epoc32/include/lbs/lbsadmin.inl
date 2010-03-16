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
//



/**
 Sets one of the settings defined by the CLbsAdmin class.
 @param aSetting The setting to be changed.
 @param aValue   The new value of the setting.
 @return KErrNone if successful, KErrArgument if the value is out of range, KErrNotSupported if the value is not supported and one of the system wide error codes otherwise. 
 @capability WriteDeviceData
 @see TLbsAdminSetting
 @prototype 
*/
template <typename T>
	inline TInt CLbsAdmin::Set(const TLbsAdminSetting& aSetting, const T&  aValue)	
		{
		return DoSet(aSetting, aValue);
		}


/** Gets one of the settings defined by the CLbsAdmin class.
@param aSetting The setting to be retrieved.
@param aValue   The value of the setting.
@return KErrNone if successful, one of the system wide error codes otherwise.
@see TLbsAdminSetting
@prototype */
template <typename T>
	inline TInt CLbsAdmin::Get(const TLbsAdminSetting& aSetting, T&  aValue) const
		{
		return DoGet(aSetting, aValue);		
		}
