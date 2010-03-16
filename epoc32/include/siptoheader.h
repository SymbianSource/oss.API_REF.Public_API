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
* Name        : siptoheader.h
* Part of     : SIP Codec
* Interface   : SDK API, SIP Codec API
* Version     : SIP/4.0 
*
*/




#ifndef CSIPTOHEADER_H
#define CSIPTOHEADER_H

//  INCLUDES
#include "sipfromtoheaderbase.h"
#include "_sipcodecdefs.h"

// CLASS DECLARATION
/**
* @publishedAll
* @released
*
* Class provides functions for setting and getting SIP "To" header fields.
*
* @lib sipcodec.lib
*/
class CSIPToHeader : public CSIPFromToHeaderBase
	{
	public:	// Constructors and destructor

		/**
		* Constructs a CSIPToHeader from textual representation 
		* of the header's value part.
		* @param aValue a value part of a "To"-header (e.g. "User <user@host>")
		* @return a new instance of CSIPToHeader 
		*/
		IMPORT_C static CSIPToHeader* DecodeL(const TDesC8& aValue);

		/**
		* Creates a new instance of CSIPToHeader
		* @pre aSIPAddress != 0
		* @param aSIPAddress a name-address, the ownership is transferred,
		* @return a new instance of CSIPToHeader
		*/
		IMPORT_C static CSIPToHeader* NewL(CSIPAddress* aSIPAddress);

		/**
		* Creates a new instance of CSIPToHeader and puts it to CleanupStack
		* @pre aSIPAddress != 0
		* @param aSIPAddress a name-address, the ownership is transferred,
		* @return a new instance of CSIPToHeader
		*/
		IMPORT_C static CSIPToHeader* NewLC(CSIPAddress* aSIPAddress);

		/**
		* Creates a deep-copy of a CSIPFromToHeaderBase
		* Note that this function can be used for creating a To-header
		* using an existing From-header.
		* @param aHeader CSIPFromToHeaderBase to be copied
		* @return a new instance of CSIPToHeader
		*/

		IMPORT_C static CSIPToHeader* 
			NewL(const CSIPFromToHeaderBase& aHeader);

		/**
		* Creates a deep-copy of a CSIPFromToHeaderBase and 
		* puts it to CleanupStack
		* Note that this function can be used for creating a To-header
		* using an existing From-header.
		* @param aHeader CSIPFromToHeaderBaseto to be copied
		* @return a new instance of CSIPToHeader
		*/
		IMPORT_C static CSIPToHeader* 
			NewLC(const CSIPFromToHeaderBase& aHeader);

		/**
		* Destructor, deletes the resources of CSIPToHeader.
		*/
		IMPORT_C ~CSIPToHeader();


	public: // New functions

		/**
		* Constructs an instance of a CSIPToHeader from a RReadStream
		* @param aReadStream a stream containing the value of the
		*        externalized object (header name not included). 
		* @return an instance of a CSIPToHeader
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

		CSIPToHeader();
	};

#endif // CSIPTOHEADER_H

// End of File
