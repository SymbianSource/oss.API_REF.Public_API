/*
* Copyright (c) 2003-2009 Nokia Corporation and/or its subsidiary(-ies).
* All rights reserved.
* This component and the accompanying materials are made available
* under the terms of "Eclipse Public License v1.0"
* which accompanies this distribution, and is available
* at the URL "http://www.eclipse.org/legal/epl-v10.html".
*
* Initial Contributors:
* Nokia Corporation - initial contribution.
*
* Contributors:
*
* Description:
* Name          : SdpCodecStringPool.h
* Part of       : SDP Codec
* Interface     : SDK API, SDP Codec API
* Version       : 1.0
*
*/



#ifndef SDPCODECSTRINGPOOL_H
#define SDPCODECSTRINGPOOL_H

//  INCLUDES
#include <e32base.h>
#include <stringpool.h>

class CSdpCodecStringPool;

// CLASS DECLARATION
/**
* @publishedAll
* @released
*
* This class defines string pool for SDP Codec.
* The client of SDP Codec must call OpenL() before 
* invoking any function of SDP Codec classes.
* The client must close the string pool when finished using
* SDP Codec classes.
*
* Note: the client must not close the string pool while
*       using SDP Codec classes.
* 
* @lib sdpcodec.lib
*/
class SdpCodecStringPool
	{
public: // Constructors and destructor
 		
	/**
	* Opens SDP Codec string pool.
	*
    * @leave KErrAlreadyExists if pool already exists in TLS.
	*/
	IMPORT_C static void OpenL();

	/**
	* Closes SDP Codec string pool.
	*
	*/
	IMPORT_C static void Close(); 

public: 
	
	/**
	* Gets the string pool used by SDP Codec.
	*
	* @return RStringPool: A handle to a string pool
	* @leave KErrSdpCodecStringPool if the pool is not opened.
	*
	*/
	IMPORT_C static RStringPool StringPoolL();

	/**
	* Gets the string table used by SDP Codec.
	*
	* @return TStringTable&: The string pool table
	* @leave KErrSdpCodecStringPool if the pool is not opened.
	*
	*/
	IMPORT_C static const TStringTable& StringTableL();
	};

#endif
