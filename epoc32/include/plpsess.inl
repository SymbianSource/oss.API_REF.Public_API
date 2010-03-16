/**
* Copyright (c) 1997-2009 Nokia Corporation and/or its subsidiary(-ies).
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
* TRemoteLinkStatus
* 
*
*/





/**
 @file
 @deprecated Obselete
*/

inline TRemoteLinkStatus::TRemoteLinkStatus()
/**
C++ constructor
*/
    { iStatus=EDisabled; iRemoteVersion=0; }

//////////////////////////////////////////////////////////////////////////////
//
// RRemoteLink Deprecated methods
//
//////////////////////////////////////////////////////////////////////////////

inline TInt RRemoteLink::Enable(TBps aBaud, const TDesC& aPort, const TDesC& aModule, TBool /*aLowPowerMode*/)
/**
Set up the RRemoteLink configuration parameters and initiate a connection

@param aBaud  The baud rate
@param aPort  The port number
@param aModule  The module name
@param aLowPowerMode  Boolean representing low power mode
@return  KErrNone on success, standard error code on failure
*/
	{

	TPlpConfigPkgSerial pkg(aBaud,aPort,aModule);
	TInt ret = SetConfig(pkg);
	return ret;
	}

inline TInt RRemoteLink::Disable()
/**
Disable the remote link

@return  KErrNone on success, standard error code on failure
*/
	{

	TInt ret = Disconnect();
	return ret;
	}

inline TInt RRemoteLink::Config(TBps* aBaud /*=NULL*/, TDesC* aPort /*=NULL*/, TDesC* aModule /*=NULL*/, TBool* /*aLowPowerMode*/)
/**
Read the current RRemoteLink configuration

@param aBaud  The bard rate
@param aPort  The port number
@param aModule  The module name
@param aLowPowerMode  Boolean representing if low power mode is enabled
@return  KErrNone on success, standard error code on failure
*/
	{

	TPlpConfigPkgSerial pkg;
	TInt ret = Config(pkg);
	if (ret!=KErrNone)
		return ret;

	if (aBaud)
		*aBaud = pkg.Baud();
	if (aPort)
		*(TDes*)aPort = pkg.PortName();
	if (aModule)
		*(TDes*)aModule = pkg.ModuleName();
	return KErrNone;
	}

inline TInt RRemoteLink::LoadLocalServer(TPlpServiceName& aResult, const TDesC& aFileName, const TDesC& aArgs /*=TPtrC()*/, TInt aReserved /*=0*/)
/**
Load a local server

@param aResult  The service name
@param aFileName  The file name
@param aArgs  Arguments 
@param aReserved  The reserved flag
@return  KErrNone on success, standard error code on failure
*///
// 
//
	{

	TRequestStatus status;
	LoadLocalServer(status,aResult,aFileName,aArgs,aReserved);
	User::WaitForRequest(status);
	return status.Int();
	}

inline TInt RRemoteLink::UnloadLocalServer(const TDesC& aFileName)
/**
Unload the local server

@param aFileName  The local server file name
@return  KErrNone on success, standard error code on failure
*/
	{

	TRequestStatus status;
	UnloadLocalServer(status,aFileName);
	User::WaitForRequest(status);
	return status.Int();
	}

inline TInt RRemoteLink::EnableFileAccess(TBool /*aEnable=ETrue*/)
/**
Dummy implementation

@param aEnable  Enable file access boolean flag
@return  KErrNone on success, standard error code on failure
*/
	{

	return KErrNone;
	}

inline void RRemoteLink::WaitForConnect(TRequestStatus& aStatus, TRemoteLinkStatusBuf& aBuf)
/**
Wait for connection to complete

@param aStatus  The request status
@param aBuf  The remote link status buffer
*/
	{

	Connect(aStatus,aBuf);
	}
