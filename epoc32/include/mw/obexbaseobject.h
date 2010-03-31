// Copyright (c) 2003-2009 Nokia Corporation and/or its subsidiary(-ies).
// All rights reserved.
// This component and the accompanying materials are made available
// under the terms of "Eclipse Public License v1.0"
// which accompanies this distribution, and is available
// at the URL "http://www.eclipse.org/legal/epl-v10.html".
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
 @publishedAll
 @released
*/

#ifndef __OBEXBASEOBJECT_H
#define __OBEXBASEOBJECT_H

#include <obextypes.h>
#include <f32file.h>

const TUint32 KConnIDInvalid = 0xffffffff;

/**
Objects of this class are used to describe the objects to be transferred and
those received via Obex.
Consists of a number of attributes describing the object, along with
methods to set them. CObexBaseObject is an abstract base class, which defines
attribute setting and transferring functionality, but does not specify the
storage mechanism for the data part (called the object body) of the object.
This body part is defined in derived classes.

Object description attributes are tracked for validity automatically, so
that only valid attributes are sent to the remote machine. Also has the
concept of "header masks". This selects which of the various attributes
will actually be sent out/read in when the object is used in an operation
with the remote machine. Objects default to transferring all valid
attributes, use the header mask if restriction is required on the headers
exchanged.

See the various derived classes for description of object body
representation.

The common attributes are defined to be as close to the underlying OBEX
headers as usefully possible, hence any OBEX header specified as a Unicode
string (e.g. Name) translate to TDes (variant) EPOC descriptors, "byte
sequences" (e.g. Type) are TDes8 (or ASCII invariant), and byte and 32 bit
integers (e.g. Length) are TUint32s.

This class is not designed for user derivation (ie. outside of this dll).

@see CObexHeader
@publishedAll
@released
*/
NONSHARABLE_CLASS(CObexBaseObject) : public CBase
	{
// required for access to iValidHeaders in CObexServer::CheckForConnectionID
friend class CObexServer;

public:
	virtual ~CObexBaseObject();
	IMPORT_C void SetHeaderMask(const TObexHeaderMask aHeaderMask);
	IMPORT_C void SetNameL(const TDesC& aDesc);
	IMPORT_C void SetTypeL(const TDesC8& aDesc);
	IMPORT_C void SetLengthL(const TUint32 aLength);
	IMPORT_C void SetTimeL(const TTime aLocalTime);
	IMPORT_C void SetDescriptionL(const TDesC& aDesc);
	IMPORT_C void SetTargetL(const TDesC8& aDesc);
	IMPORT_C void AddHttpL(const TDesC8& aDesc);
	IMPORT_C void SetAppParamL(const TDesC8& aDesc);
	
	IMPORT_C void AddHeaderL(CObexHeader& aHeader);
	IMPORT_C TInt BytesSent();
	IMPORT_C TInt BytesReceived();
	IMPORT_C TObexHeaderMask HeaderMask();
	IMPORT_C TObexHeaderMask ValidHeaders();
	IMPORT_C const TDesC& Name();
	IMPORT_C const TDesC8& Type();
	IMPORT_C TUint32 Length();
	IMPORT_C const TTime Time();
	IMPORT_C const TDesC& Description();
	IMPORT_C const TDesC8& Target();
	IMPORT_C const RPointerArray<HBufC8>* Http() const;
	IMPORT_C const TDesC8& AppParam() const;
	IMPORT_C void Reset();
	IMPORT_C const CObexHeaderSet& HeaderSet() const;
	IMPORT_C CObexHeaderSet& HeaderSet();

	// Public unexported functions used by CObexServer, CObexClient, etc
	enum TProgress { EContinue,EComplete,EError,ELastPacket };
	TInt InitSend(TObexOpcode aOpcode);
	TProgress PrepareNextSendPacket(CObexPacket& aPacket);
	TInt InitReceive();
	TProgress ParseNextReceivePacket(CObexPacket& aPacket);
	void PrepareConnectionHeader( CObexPacket& aPacket );
	void SetConnectionIdL(TUint32 aFourByte);
	TUint32 ConnectionID();
	TObexResponse GetLastError() const;

protected:
	CObexBaseObject();
	void GuessTypeFromExtL(const TDesC& aExt);
	void ResetHeaders();
	// Pure virtuals that all derived objects must implement
	virtual void GetData(TInt aPos, TDes8& aDes) =0;
	virtual void NewData(TInt aPos, TDes8& aDes) =0;
	virtual TInt DataSize() =0;
	virtual void ResetData() =0;
	void CreateHeaderStorageDataL();
	void SetTimeHeaderL(const TDesC8& aTimeDes);
	void SetUtcTimeL(const TTime aUtcTime);
	
// Data
private:
	TObexHeaderMask iHeaderMask;
	TObexHeaderMask iValidHeaders;

	mutable RPointerArray<HBufC8>* iHttp;

	CObexHeaderSet* iHeaderSet;
	
	TProgress iSendProgress;
	TProgress iRecvProgress;
	TObexOpcode iSendOpcode;

	// This data item is used to store a CObexHeader which is used as a temporary
	// store when finding headers
	CObexHeader* iObexHeader;
	
	TObexHeaderMask iSendHeaders; 
	TInt iSendBytes;
	TInt iRecvBytes;
	
	TObexResponse iLastError;
	
	};

#endif // __OBEXBASEOBJECT_H
