// Copyright (c) 1999-2009 Nokia Corporation and/or its subsidiary(-ies).
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
// EPOC Server for redirecting stdin/stdout/stderr to a stream-like object 
// (console, file or serial port)
// 
//

#ifndef _REDIRCLI_H_
#define _REDIRCLI_H_

#include <e32std.h>
#include <e32base.h>
#include <redirstr.h>

// The following functions are defined to replace previous exports so def file 
// does not need reordering.
IMPORT_C void DummyReserved1();
IMPORT_C void DummyReserved2();
IMPORT_C void DummyReserved3();
IMPORT_C void DummyReserved4();
IMPORT_C void DummyReserved5();
IMPORT_C void DummyReserved6();
IMPORT_C void DummyReserved7();
IMPORT_C void DummyReserved8();

class CStreamFactoryBase2;
class CStreamBase2;

/** 
Redirection server class.
 
This class represents the Redir server itself. It is created through the 
factory function NewL. It is not intended for user derivation.

@publishedPartner
@released
*/
class CRedirServer2 : public CServer2
	{
private:
	/**Priority flag
	*/
	enum {
	//mpt - need to explain the magic here!
	EPriority=950
	};
public:
	IMPORT_C static CRedirServer2* NewL(CStreamFactoryBase2* aStreamFactory);
	IMPORT_C void SetStreamFactory(CStreamFactoryBase2* aStreamFactory);
	virtual ~CRedirServer2();
private:
	CRedirServer2(CStreamFactoryBase2* aStreamFactory);
	virtual	CSession2* NewSessionL(const TVersion& aVersion, const RMessage2& aMessage) const;
private:
	CStreamFactoryBase2* iStreamFactory;
	};

/**
Client side session for Redirection server

@internalAll
*/
class RRedirSession2 : public RSessionBase
	{
public:
	IMPORT_C TInt Connect();
	IMPORT_C void Read(TRequestStatus& aStatus, TDes8& aDes);
	IMPORT_C void Read(TRequestStatus& aStatus, TDes8& aDes, TInt aLength);
	IMPORT_C void Write(TRequestStatus& aStatus, const TDesC8& aDes);
	IMPORT_C void Write(TRequestStatus& aStatus, const TDesC8& aDes, TInt aLength);
	IMPORT_C void Flush(TRequestStatus& aStatus);
private:
//TO DO: do we really need this function??
	TInt CheckEOF(TRequestStatus& aStatus);
	};


#endif
