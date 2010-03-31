/*
* Copyright (c) 2004-2009 Nokia Corporation and/or its subsidiary(-ies).
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
* Name        : siprouteheader.h
* Part of     : SIP Codec
* Interface   : SDK API, SIP Codec API
* Version     : SIP/4.0 
*
*/




#ifndef CSIPROUTEHEADER_H
#define CSIPROUTEHEADER_H

//  INCLUDES
#include "siprouteheaderbase.h"

// CLASS DECLARATION
/**
* @publishedAll
* @released
*
* Class for SIP "Route"-header manipulation.
*
*  @lib sipcodec.lib
*/
class CSIPRouteHeader : public CSIPRouteHeaderBase
	{
	public:	// Constructors and destructor

		/**
		* Constructs a CSIPRouteHeader from textual representation 
		* of the header's value part.
		* @param aValue a value part of a "Route"-header
		* @return an array containing one to many instances of CSIPRouteHeader
		*/
		IMPORT_C static RPointerArray<CSIPRouteHeader> 
			DecodeL(const TDesC8& aValue);

		/**
		* Creates a new instance of CSIPRouteHeader
		* @pre aSIPAddress != 0
		* @param aSIPAddress a name-address, the ownership is transferred 
		* @return a new instance of CSIPRouteHeader
		*/
		IMPORT_C static CSIPRouteHeader* NewL(CSIPAddress* aSIPAddress);

		/**
		* Creates a new instance of CSIPRouteHeader and puts it to CleanupStack
		* @pre aSIPAddress != 0
		* @pre aSIPAddress->Address().HostPort().HasHost() == ETrue
		* @param aSIPAddress a name-address, the ownership is transferred 
		* @return a new instance of CSIPRouteHeader
		*/
		IMPORT_C static CSIPRouteHeader* NewLC(CSIPAddress* aSIPAddress);

		/**
		* Destructor, deletes the resources of CSIPRouteHeader.
		*/
		IMPORT_C ~CSIPRouteHeader();


	public: // New functions

		/**
		* Constructs an instance of a CCSIPRouteHeader from a RReadStream
		* @param aReadStream a stream containing the value of the
		*        externalized object (header name not included). 
		* @return an instance of a CSIPRouteHeader
		*/
		IMPORT_C static CSIPHeaderBase* 
			InternalizeValueL(RReadStream& aReadStream);


	public: // From CSIPHeaderBase
		
		/**
		* From CSIPHeaderBase CloneL
		*/
		IMPORT_C CSIPHeaderBase* CloneL() const;

		/**
		* From CSIPHeaderBase Name
		*/
		IMPORT_C RStringF Name() const;


	public: // New functions, for internal use

		static RPointerArray<CSIPHeaderBase> BaseDecodeL(const TDesC8& aValue);
		static CSIPRouteHeader* NewL(const CSIPRouteHeaderBase& aHeader);		

	private: // From CSIPHeaderbase

		void ExternalizeValueL(RWriteStream& aWriteStream) const;

	private: // Constructors

		CSIPRouteHeader();

	private: // New functions

		void DoInternalizeValueL(RReadStream& aReadStream);
	};

#endif // CSIPROUTEHEADER_H

// End of File
