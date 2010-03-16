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
//



/**
 @file
 @internalTechnology
 @released
*/

#ifndef CS_API_EXT_H
#define CS_API_EXT_H

#include <es_sock.h>
#include <comms-infras/api_ext_list.h>
#include <comms-infras/trbuf.h>

class CCommsApiExtReqMsg;
class CCommsApiExtRespMsg;

class RCommsApiExtensionBase
/**
Base class for Comms API extensions.

@internalTechnology
@released
*/
	{
protected:
	IMPORT_C explicit RCommsApiExtensionBase();
	IMPORT_C TInt Open(RCommsSubSession& aExtensionProvider, TSupportedCommsApiExt aInterfaceId);
	IMPORT_C void Close();
	IMPORT_C void SendRequest(CCommsApiExtReqMsg& aRequestMsg, TDes8& aResponseBuf, TRequestStatus& aStatus);
	IMPORT_C void SendMessage(CCommsApiExtReqMsg& aRequestMsg);

protected:
	RCommsSubSession iSubSession;
	TSupportedCommsApiExt iInterfaceId;

private:
	RPointerArray<Elements::TRBuf8> iBuffers;
	};

template<TSupportedCommsApiExt T>
class RCommsApiExtension : public RCommsApiExtensionBase
/**
Comms API extensions template. New extension APIs may derive from this template.

@internalTechnology
@released
*/
	{
public:
	inline TInt Open(RCommsSubSession& aExtensionProvider);
	};

template<TSupportedCommsApiExt T>
TInt RCommsApiExtension<T>::Open(RCommsSubSession& aExtensionProvider)
	{
	return RCommsApiExtensionBase::Open(aExtensionProvider,T);
	}

#endif // CS_API_EXT_H
