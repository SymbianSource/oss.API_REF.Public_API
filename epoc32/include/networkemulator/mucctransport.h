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
*
*/


/**
 @file MUCCTransport.h
*/

#ifndef __MUCCTRANSPORT_H__
#define __MUCCTRANSPORT_H__

class MUCCTransport
{
public:
	virtual ~MUCCTransport() {}
	virtual TInt InitialiseL() = 0;
	virtual TInt ConnectL( TDesC *aRemoteHost ) = 0;
	virtual TInt RequestSend( TDesC8 *aData, const TUint aLength ) = 0;
	virtual TInt RequestReceive( TPtr8 *aRecvBufferPtr, TUint aByteCount ) = 0;
	virtual TInt Disconnect( void ) = 0;
	virtual TInt Release( void ) = 0;
	virtual TText8 *Error( void ) = 0;
};

#endif // __MUCCTRANSPORT_H__
