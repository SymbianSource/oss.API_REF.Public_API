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
* Name        : sipexpiresheader.h
* Part of     : SIP Codec
* Interface   : SDK API, SIP Codec API
* Version     : SIP/4.0 
*
*/




#ifndef CSIPEXPIRESHEADER_H
#define CSIPEXPIRESHEADER_H

//  INCLUDES
#include "sipunsignedintheaderbase.h"

// CLASS DECLARATION
/**
* @publishedAll
* @released
*
* Class encapsulates a "Expires" header value.
*
*  @lib sipcodec.lib
*/
class CSIPExpiresHeader : public CSIPUnsignedIntHeaderBase
	{
	public:	// Constructors and destructor

		/**
		* Constructs a CSIPExpiresHeader from textual representation 
		* of the header's value part.
		* @param aValue a value part of a "Expires"-header (e.g. "3600")
		* @return a new instance of CSIPExpiresHeader
		*/
		IMPORT_C static CSIPExpiresHeader* DecodeL(const TDesC8& aValue);
	
		/**
		* Constructor
		* @param aValue the value to set
		*/
		IMPORT_C CSIPExpiresHeader(TUint aValue);
	
		/**
		* Destructor, deletes the resources of CSIPExpiresHeader.
		*/
		IMPORT_C ~CSIPExpiresHeader();


	public: // New functions

		/**
		* Constructs an instance of a CSIPExpiresHeader from a RReadStream
		* @param aReadStream a stream containing the value of the
		*        externalized header object (header name not included).
		* @return an instance of a CSIPExpiresHeader
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


	public: // From CSIPHeaderBase, for internal use

        /**
        * @internalComponent
        */
		TPreferredPlace PreferredPlaceInMessage() const;

	public: // New functions, for internal use

		static RPointerArray<CSIPHeaderBase> BaseDecodeL(const TDesC8& aValue);

	private: // For testing purposes
#ifdef CPPUNIT_TEST	
		friend class CSIPExpiresHeaderTest;
#endif
	};

#endif // CSIPEXPIRESHEADER_H

// End of File
