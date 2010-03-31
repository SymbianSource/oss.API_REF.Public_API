// Copyright (c) 2007-2009 Nokia Corporation and/or its subsidiary(-ies).
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
 @publishedPartner 
 @released
*/

#ifndef THREADDATA_H
#define THREADDATA_H

#include <streamelement.h>


/**
@publishedPartner 
@released

Class that represents a thread on the target. It is based on CStreamElementBase, so
it can be streamed between client and server.
It is used by the Core Dump server, its clients and the plugins.
*/
class CThreadInfo : public CStreamElementBase
{

public:

	IMPORT_C static CThreadInfo* NewL(  const TUint64	& aId,
										const TDesC		& aName, 
										const TUint64	& aProcessId,
										const TUint		& aPriority,
										const TLinAddr	& aSvcStackPtr,
										const TLinAddr	& aSvcStackAddr,
										const TUint		& aSvcStackSize,
										const TLinAddr	& aUsrStackAddr,
										const TUint		& aUsrStackSize );

	IMPORT_C static CThreadInfo* NewL( const TDesC8 & aStreamData );

	IMPORT_C ~CThreadInfo();

public:

	// Methods specific to CThreadInfo

	IMPORT_C const TUint64 & Id( ) const;

	IMPORT_C void NameL( const TDesC & aName );
	IMPORT_C const TDesC & Name() const;
	
	IMPORT_C const TUint64 & ProcessId( ) const;

	IMPORT_C TUint Priority( ) const;
	IMPORT_C TUint SvcStackPtr( ) const;
	IMPORT_C TUint SvcStackAddr( ) const;
	IMPORT_C TUint SvcStackSize( ) const;
	IMPORT_C TUint UsrStackAddr( ) const;
	IMPORT_C TUint UsrStackSize( ) const;

	IMPORT_C TBool Observed( ) const;
	IMPORT_C void Observed( TBool aFlag );

public:
	// Methods required by streaming interface 

	IMPORT_C TInt static MaxSize();

	IMPORT_C TInt Size() const;

	IMPORT_C void InternalizeL( RReadStream & aStream );

	IMPORT_C void ExternalizeL( RWriteStream & aStream, CBufFlat* buf );


private:

	CThreadInfo(	const TUint64	& aId,
					const TUint64	& aProcessId,
					const TUint		& aPriority,
					const TLinAddr	& aSvcStackPtr,
					const TLinAddr	& aSvcStackAddr,
					const TUint		& aSvcStackSize,
					const TLinAddr	& aUsrStackAddr,
					const TUint		& aUsrStackSize );

	CThreadInfo();

	void ConstructL( const TDesC & aName );

private:

	/** Symbian kernel thread id */
	TUint64				iId;

	/** Symbian kernel thread name */
	HBufC  *			iName;

	/** Symbian kernel process id of owning process */
	TUint64				iProcessId;

	/** Symbian kernel thread priority TThreadPriority */
	TUint				iPriority;

	/** Thread supervisor stack pointer */
	TLinAddr			iSvcStackPtr;

	/** Thread supervisor mode stack base address */
	TLinAddr			iSvcStackAddr;

	/** Thread supervisor mode stack size in bytes */
	TUint				iSvcStackSize;

	/** Thread user mode stack base address */
	TLinAddr			iUsrStackAddr;

	/** Thread user mode stack base size in bytes */
	TUint				iUsrStackSize;

	/** Set to ETrue if the thread is being explicitly observed for crashes 
	by the Core Dump Server. If only the owning process is being observed, 
	this should be EFalse. */
	TBool				iObserved;

	/** Externalized size */
	TUint				iSize;

	// These are not internalised/externalised since they are spare
	TUint32 iSpare0;
	TUint32 iSpare1;
	TUint32 iSpare2;

	};


/**
@publishedPartner 
@released

List of CThreadInfo object pointers.
@see CThreadInfo
@see RPointerArray
*/
typedef RPointerArray<CThreadInfo>	RThreadPointerList;


#endif // THREADDATA_H
