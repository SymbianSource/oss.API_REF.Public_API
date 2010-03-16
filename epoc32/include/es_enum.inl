// Copyright (c) 2002-2009 Nokia Corporation and/or its subsidiary(-ies).
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

inline TConnArgBase::TConnArgBase()
: iVersion(0)
/**
Default Constructor

*/
	{}

inline TConnArgBase::TConnArgBase(TUint8 aVersion)
: iVersion(aVersion)
/**
Constructor

@param aVersion, Version number of the connection arguemt.
*/
	{
	iReserved[0]=0;
	iReserved[1]=0;
	iReserved[2]=0;
	}

inline TUint8 TConnArgBase::Version() const
/**
Responsible for retrieving the version number for the Socket Connection argument.

@return version number of the connection arguemt.
*/
	{
	return iVersion;
	}

inline TConnectionInfo::TConnectionInfo()
: TConnArgBase(KConnArgVersion1), iIapId(0), iNetId(0)
/**
Default Constructor

*/
	{}

inline TConnectionInfo::TConnectionInfo(TUint32 aIapId, TUint32 aNetId)
: TConnArgBase(KConnArgVersion1), iIapId(aIapId), iNetId(aNetId)
/**
Constructor

*/
	{}

inline TConnectionInfo::TConnectionInfo(TUint8 aVersion, TUint32 aIapId, TUint32 aNetId)
: TConnArgBase(aVersion), iIapId(aIapId), iNetId(aNetId)
/**
Constructor

*/
	{}

inline TConnectionInfoV2::TConnectionInfoV2()
: TConnectionInfo(KConnArgVersion2, 0, 0)
/**
Default Constructor

*/
	{
	}

inline TConnectionInfoV2::TConnectionInfoV2(TUint32 aIapId, TUint32 aNetId, TConnectionType aConnectionType)
: TConnectionInfo(KConnArgVersion2, aIapId, aNetId), iConnectionType(aConnectionType)
/**
Constructor

@param aIapId
@param aNetId
@param aConnectionType
*/
	{
	}

inline TConnectionInfoV2::TConnectionInfoV2(TUint8 aVersion, TUint32 aIapId, TUint32 aNetId, TConnectionType aConnectionType)
: TConnectionInfo(aVersion, aIapId, aNetId), iConnectionType(aConnectionType)
/**
Constructor

@param aVersion
@param aIapId
@param aNetId
@param aConnectionType
*/
	{
	}

inline TConnectionType TConnectionInfoV2::ConnectionType()
/**
Retrieve the type of socket connection.(version 2)

@return type of connection.
*/
	{
	return iConnectionType;
	}

inline TSubConnectionInfo::TSubConnectionInfo()
: TConnArgBase(KConnArgVersion2), iSubConnectionUniqueId(0), iConnectionType(EConnectionGeneric), iTimeStarted(0)
/**
Default Constructor
*/
	{
	}

inline TConnectionClientInfo::TConnectionClientInfo()
: iProcessId(), iUid(TUid::Null()), iThreadId()
	{}

inline  TConnectionClientInfo::TConnectionClientInfo(TUint aProcId, TUint aUid, TUint aThreadId)
: iProcessId(aProcId), iUid(TUid::Uid(aUid)), iThreadId(aThreadId)
	{}

inline TConnectionSocketInfo::TConnectionSocketInfo()
: iAddressFamily(KAFUnspec), iProtocol(0), iSourceAddress(), iDestinationAddress()
	{}

inline TConnectionEnumArg::TConnectionEnumArg()
: TConnArgBase(KConnArgVersion1), iIndex(0), iCount(0)
	{}

inline TConnectionGetClientInfoArg::TConnectionGetClientInfoArg()
: TConnArgBase(KConnArgVersion1), iIndex(0), iClientInfo()
	{}

inline TConnectionGetSocketInfoArg::TConnectionGetSocketInfoArg()
: TConnArgBase(KConnArgVersion1), iIndex(0), iSocketInfo()
	{}
