/*
* Copyright (c) 2005-2009 Nokia Corporation and/or its subsidiary(-ies).
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
* Name        : sipaccessnetworkinfo.inl
* Part of     : SIP NetworkMonitor
* Implementation
* Version     : SIP/4.0
*
*/



#ifndef TSIPACCESSNETWORKINFO_INL
#define TSIPACCESSNETWORKINFO_INL

// -----------------------------------------------------------------------------
// TSIPAccessNetworkInfo::TSIPAccessNetworkInfo
// -----------------------------------------------------------------------------
//
inline TSIPAccessNetworkInfo::TSIPAccessNetworkInfo() :
	iNetworkMode( RMobilePhone::ENetworkModeUnknown ),	
	iMobileCountryCode( KNullDesC ),
	iMobileNetworkCode( KNullDesC ),
	iAreaKnown( EFalse ),
	iLocationAreaCode( 0 ),
	iCellId( 0 )
	{	
	}

// -----------------------------------------------------------------------------
// TSIPAccessNetworkInfo::TSIPAccessNetworkInfo
// -----------------------------------------------------------------------------
//
inline TSIPAccessNetworkInfo::TSIPAccessNetworkInfo(
	TPckgBuf<RMobilePhone::TMobilePhoneNetworkInfoV2>& aNetworkInfoPckg,
	RMobilePhone::TMobilePhoneLocationAreaV1& aLocationArea ) :
	iNetworkMode( RMobilePhone::ENetworkModeUnknown ),
	iMobileCountryCode( KNullDesC ),
	iMobileNetworkCode( KNullDesC ),
	iAreaKnown( aLocationArea.iAreaKnown ),
	iLocationAreaCode( aLocationArea.iLocationAreaCode ),
	iCellId( aLocationArea.iCellId )
	{
	iNetworkMode = aNetworkInfoPckg().iMode;
	iMobileCountryCode = aNetworkInfoPckg().iCountryCode;
	iMobileNetworkCode = aNetworkInfoPckg().iNetworkId;
	}

// -----------------------------------------------------------------------------
// TSIPAccessNetworkInfo::~TSIPAccessNetworkInfo
// -----------------------------------------------------------------------------
//
inline TSIPAccessNetworkInfo::~TSIPAccessNetworkInfo()
	{
	}

// -----------------------------------------------------------------------------
// TSIPAccessNetworkInfo::operator==
// -----------------------------------------------------------------------------
//
inline TBool TSIPAccessNetworkInfo::operator==( 
    const TSIPAccessNetworkInfo& aNetInfo ) const
	{
	return ( iNetworkMode == aNetInfo.iNetworkMode &&
			 iMobileCountryCode == aNetInfo.iMobileCountryCode &&
			 iMobileNetworkCode == aNetInfo.iMobileNetworkCode &&
			 iAreaKnown == aNetInfo.iAreaKnown &&
			 iLocationAreaCode == aNetInfo.iLocationAreaCode &&
			 iCellId == aNetInfo.iCellId );
	}

#endif // TSIPACCESSNETWORKINFO_INL
