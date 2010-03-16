/*
* Copyright (c) 2004-2009 Nokia Corporation and/or its subsidiary(-ies).
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
* Name        : sipfromheader.h
* Part of     : SIP Codec
* Interface   : SDK API, SIP Codec API
* Version     : SIP/4.0 
*
*/




#ifndef CSIPFROMHEADER_H
#define CSIPFROMHEADER_H

//  INCLUDES
#include "sipfromtoheaderbase.h"
#include "_sipcodecdefs.h"

// CLASS DECLARATION
/**
* @publishedAll
* @released
*
* Class provides functions for setting and getting SIP "From" header.
*
*  @lib sipcodec.lib
*/
class CSIPFromHeader : public CSIPFromToHeaderBase
	{
	public:	// Constructors and destructor

		/**
		* Constructs a CSIPFromHeader from textual representation 
		* of the header's value part.
		* @param aValue a value part of a "From"-header (e.g. "<user@host>...")
		* @return a new instance of CSIPFromHeader    
		*/
		IMPORT_C static CSIPFromHeader* DecodeL(const TDesC8& aValue);

		/**
		* Creates a new instance of CSIPFromHeader
		* @pre aSIPAddress != 0
		* @param aSIPAddress a name-address, the ownership is transferred.
		* @return a new instance of CSIPFromHeader
		*/
		IMPORT_C static CSIPFromHeader* NewL(CSIPAddress* aSIPAddress);

		/**
		* Creates a new instance of CSIPFromHeader and puts it to CleanupStack
		* @pre aSIPAddress != 0
		* @param aSIPAddress a name-address, the ownership is transferred,
		* @return a new instance of CSIPFromHeader
		*/
		IMPORT_C static CSIPFromHeader* NewLC(CSIPAddress* aSIPAddress);

		/**
		* Creates a deep-copy of a CSIPFromToHeaderBase
		* Note that this function can be used for creating a From-header
		* using an existing To-header.
		* @param aHeader CSIPFromToHeaderBase to be copied
		* @return a new instance of CSIPFromHeader
		*/
		IMPORT_C static CSIPFromHeader* 
			NewL(const CSIPFromToHeaderBase& aHeader);

		/**
		* Creates a deep-copy of a CSIPFromToHeaderBase and 
		* puts it to CleanupStack
		* Note that this function can be used for creating a From-header
		* using an existing To-header.
		* @param aHeader CSIPFromToHeaderBase to be copied
		* @return a new instance of CSIPFromHeader
		*/
		IMPORT_C static CSIPFromHeader* 
			NewLC(const CSIPFromToHeaderBase& aHeader);

		/**
		* Destructor, deletes the resources of CSIPFromHeader.
		*/
		IMPORT_C ~CSIPFromHeader();


	public: // New functions

		/**
		* Constructs an instance of a CSIPFromHeader from a RReadStream
		* @param aReadStream a stream containing the value of the
		*        externalized object (header name not included). 
		* @return an instance of a CSIPFromHeader
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
		RStringF CompactName() const;

	public: // New functions, for internal use

		static RPointerArray<CSIPHeaderBase> BaseDecodeL(const TDesC8& aValue);

	private: // Constructors

		CSIPFromHeader();
	};

#endif // CSIPFROMHEADER_H

// End of File
