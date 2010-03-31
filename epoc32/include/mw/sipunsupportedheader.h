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
* Name        : sipunsupportedheader.h
* Part of     : SIP Codec
* Interface   : SDK API, SIP Codec API
* Version     : SIP/4.0 
*
*/




#ifndef CSIPUNSUPPORTEDHEADER_H
#define CSIPUNSUPPORTEDHEADER_H

//  INCLUDES
#include "siptokenheaderbase.h"
#include "_sipcodecdefs.h"

// CLASS DECLARATION
/**
* @publishedAll
* @released
*
* Class provides functions for setting and getting SIP "Unsupported" header.
*
* @lib sipcodec.lib
*/
class CSIPUnsupportedHeader : public CSIPTokenHeaderBase
	{
	public:	// Constructors and destructor

		/**
		* Constructs a CSIPUnsupportedHeader from textual representation 
		* of the header's value part.
		* @param aValue a value part of a "Unsupported"-header
		* @return an array containing 1..n instances of CSIPUnsupportedHeader 
		*/
		IMPORT_C static RPointerArray<CSIPUnsupportedHeader> 
			DecodeL(const TDesC8& aValue);

		/**
		* Creates a new instance of CSIPUnsupportedHeader
		* @param aValue a tag value 
		* @return a new instance of CSIPUnsupportedHeader
		*/
		IMPORT_C static CSIPUnsupportedHeader* NewL (RStringF aValue);

		/**
		* Creates a new instance of CSIPUnsupportedHeader 
		* and puts it to CleanupStack
		* @param aValue a tag value   
		* @return a new instance of CSIPUnsupportedHeader
		*/
		IMPORT_C static CSIPUnsupportedHeader* NewLC(RStringF aValue);

		/**
		* Destructor, deletes the resources of CSIPUnsupportedHeader.
		*/
		IMPORT_C ~CSIPUnsupportedHeader();


	public: // New functions

		/**
		* Constructs an instance of a CSIPUnsupportedHeader from a RReadStream
		* @param aReadStream a stream containing the value of the
		*        externalized object (header name not included). 
		* @return an instance of a CSIPUnsupportedHeader
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

	private: // Constructors

		CSIPUnsupportedHeader();
		CSIPUnsupportedHeader(const CSIPUnsupportedHeader& aHeader);
	};

#endif // CSIPUNSUPPORTEDHEADER_H

// End of File
