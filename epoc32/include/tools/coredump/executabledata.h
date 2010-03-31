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
// Defines target-executable classes used across the Core Dump client/server interface 
//



/**
 @file
 @publishedPartner 
 @released
*/

#ifndef EXECUTABLEDATA_H
#define EXECUTABLEDATA_H

#include <streamelement.h>


/**
@publishedPartner 
@released

Class that represents a target executable file from which a process can launched. 
It is based on CStreamElementBase so it can be streamed between client and server.
@see CServerCrashDataSource::GetExecutableListL
*/
class CExecutableInfo : public CStreamElementBase
{

public:

	IMPORT_C static CExecutableInfo* NewL( const TDesC		& aName,
										   const TBool  	  aActivelyDebugged,
										   const TBool  	  aPassivelyDebugged );

	IMPORT_C static CExecutableInfo* NewL( const TDesC8 & aStreamData );

	IMPORT_C ~CExecutableInfo();

public:
	// Methods specific to CExecutableInfo

	IMPORT_C void NameL( const TDesC & aName );
	IMPORT_C const TDesC & Name() const;

	IMPORT_C TBool ActivelyDebugged( ) const;
	IMPORT_C void  ActivelyDebugged( TBool aActivelyDebugged );

	IMPORT_C TBool PassivelyDebugged( ) const;
	IMPORT_C void PassivelyDebugged( TBool aPassivelyDebugged );

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

	CExecutableInfo( const TBool aActivelyDebugged,
					 const TBool aPassivelyDebugged );

	CExecutableInfo();

	void ConstructL( const TDesC & aName );

private:

	/** Symbian kernel executable name */
	HBufC  *			iName;

    /** Actively debugged by client of Debug Security Server */
	TBool				iActivelyDebugged;

    /** Passively debugged by client of Debug Security Server */
	TBool				iPassivelyDebugged;

    /** Observed by core dump server */
	TBool				iObserved;

	/** Externalized size */
	TUint				iSize;

	// These are not internalised/externalised since they are spare
	TUint32				iSpare1;
	TUint32				iSpare2;
	TUint32				iSpare3;
	};


/**
@publishedPartner 
@released

List of CExecutableInfo object pointers
@see CExecutableInfo
@see RPointerArray
*/
typedef RPointerArray<CExecutableInfo>	RExecutablePointerList;

#endif
