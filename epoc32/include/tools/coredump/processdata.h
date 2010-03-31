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

#ifndef PROCESSDATA_H
#define PROCESSDATA_H

#include <streamelement.h>


/**
@publishedPartner 
@released

Class that represents a process on the target. It is based on CStreamElementBase so
it can be streamed between client and server.
It is used by the Core Dump server, its clients and the plugins.
@see CServerCrashDataSource::GetProcessListL()
*/
class CProcessInfo : public CStreamElementBase
{

public:

	IMPORT_C static CProcessInfo* NewL( const TUint64	  aId,
										const TDesC		& aName );

	IMPORT_C static CProcessInfo* NewL( const TDesC8 & aStreamData );

	IMPORT_C ~CProcessInfo();

public:
	// Methods specific to CProcessInfo

	IMPORT_C const TUint64 & Id( ) const;

	IMPORT_C void NameL( const TDesC & aName );
	IMPORT_C const TDesC & Name() const;

	IMPORT_C TBool Observed( ) const;
	IMPORT_C void  Observed( TBool aFlag );

public:
	// Methods required by streaming interface 

	IMPORT_C TInt static MaxSize();

	IMPORT_C TInt Size() const;

	// Initializes ’this’ from stream
	IMPORT_C void InternalizeL( RReadStream & aStream );

	// Writes ’this’ to the stream
	IMPORT_C void ExternalizeL( RWriteStream & aStream, CBufFlat* buf );


private:

	CProcessInfo(	const TUint64	  aId );

	CProcessInfo();

	void ConstructL( const TDesC & aName );

private:

	/** Symbian kernel process id */
	TUint64				iId;

	/** Symbian kernel process name */
	HBufC  *			iName;

    /** Observed by core dump server */
	TBool				iObserved;

	/** Externalized size */
	TUint				iSize;

	// These are not internalised/externalised since they are spare
	TUint32				iSpare0;
	TUint32				iSpare1;
	TUint32				iSpare2;

	};


/**
@publishedPartner 
@released

List of CProcessInfo object pointers
@see CProcessInfo
@see RPointerArray
*/
typedef RPointerArray<CProcessInfo>	RProcessPointerList;

#endif
