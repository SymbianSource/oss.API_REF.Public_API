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
* CUCCSDeviceProtocol Class
*
*/


#ifndef _CUCCSDeviceProtocol_H
#define _CUCCSDeviceProtocol_H


/*****************************************************************************
 *
 * System Includes 
 *
 ****************************************************************************/
#include <e32cons.h>


/*****************************************************************************
 *
 * Local Includes
 *
 ****************************************************************************/
//#include "MUCCTransport.h"
//#include "CProtocolTypes.h"

#include <mucctransport.h>
#include <cprotocoltypes.h>


/*****************************************************************************
 *
 *  Types
 *
 ****************************************************************************/
typedef enum {
	TDP_SUCCESS,
	TDP_INVALIDCMDID,
	TDP_SENDERROR,
	TDP_RECVERROR,
	TDP_ERRINTIALISING,
	TDP_UIDMISMATCH,
} TDPError;

typedef enum {
	TDP_IDLE,
	TDP_CONNECTED
} TDPStatus;


typedef enum 
{
	TDP_NONE,
	TDP_SERIAL,
	TDP_TCP
} TDPTransport;

/*****************************************************************************
 *
 * Class Definition
 *
 ****************************************************************************/
class CUCCSDeviceProtocol : public CBase
{
public:
	CUCCSDeviceProtocol();
	~CUCCSDeviceProtocol();

	TDPError initialise(TBufC16<40> aRemoteHost, TDPTransport aTransportType = TDP_SERIAL );
	TDPError disconnect();
	
	TDPError sendMessage(TPCommand aCmd, int aDataLength, void *aData);
	TDPError receiveMessage(TPCommand* aCmd, int* aDataLength, void* aData);

private:
	bool isValidCMDID(TPCommand aCommand);

	int iRand_UID;
	MUCCTransport* iTransport;
	TBufC16<40> iRemoteHost;
	TInt64 iRandomSeed;
	TDPStatus iStatus;

};

#endif
