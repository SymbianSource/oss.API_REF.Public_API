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
* CUCCSDeviceControl Class
*
*/


#ifndef _CUCCSDeviceControl_H
#define _CUCCSDeviceControl_H


/*****************************************************************************
 *
 * System Includes 
 *
 ****************************************************************************/
#include <e32cons.h>
#include <e32def.h>

#include <cuccsdeviceprotocol.h>

/*****************************************************************************
 *
 * Local Includes
 *
 ****************************************************************************/


/*****************************************************************************
 *
 *  Types
 *
 ****************************************************************************/
typedef enum {
	TDC_SUCCESS,
	TDC_ERRINTIALISING,
	TDC_ERRSENDING,
	TDC_ERRRECV,
	TDC_INVALIDREPLY,
	TDC_VARNAMETOOLONG,
	TDC_VARVALTOOLONG,
	TDC_COMMDBERR,
	TDC_RECORDIDNOTSPECIFIED,
	TDC_COMMANDLINETOOLONG
} TDCError;


/*****************************************************************************
 *
 * CUCCSDeviceControl
 *
 ****************************************************************************/
class CUCCSDeviceControl : CBase
{
public:
	// Construction / Destruction						
	IMPORT_C static CUCCSDeviceControl* New(); 
	IMPORT_C ~CUCCSDeviceControl();

	// External interface
	IMPORT_C TUint connectL( TDesC *aRemoteHost, TDPTransport aTransportType = TDP_SERIAL );
	IMPORT_C TUint startUseCase( TUint aData, int *aErrorCode );  
	IMPORT_C TUint signal( TUint aData, int *aErrorCode );
	IMPORT_C TUint waitfor( TUint aData, int *aErrorCode );
	IMPORT_C TUint rendezvous( TUint aData, int *aErrorCode );
	IMPORT_C TUint endUseCase( TUint aUseCaseData, TUint aResult, int *aErrorCode );
	IMPORT_C TUint getVariableName( char* aVariableName, char* aOutputBuffer, int aOutputBufferSize, int *aErrorCode );
	IMPORT_C TUint runCommandL( char* aCommandLine, int *aErrorCode );

private:
	CUCCSDeviceControl();
	void ConstructL();

private:
	CUCCSDeviceProtocol *iProtocol;
};

#endif





