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
* Name        : sipsupportedheader.h
* Part of     : SIP Codec
* Interface   : SDK API, SIP Codec API
* Version     : SIP/4.0 
*
*/




#ifndef CSIPSUPPORTEDHEADER_H
#define CSIPSUPPORTEDHEADER_H

//  INCLUDES
#include "siptokenheaderbase.h"
#include "_sipcodecdefs.h"

// CLASS DECLARATION
/**
* @publishedAll
* @released
*
* Class provides functions for setting and getting SIP "Supported" header.
*
* @lib sipcodec.lib
*/
class CSIPSupportedHeader : public CSIPTokenHeaderBase
	{
	public:	// Constructors and destructor

		/**
		* Constructs a CSIPSupportedHeader from textual representation 
		* of the header's value part.
		* @param aValue a value part of a "Supported"-header
		* @return an array containing 1..n instances of CSIPSupportedHeader  
		*/
		IMPORT_C static RPointerArray<CSIPSupportedHeader> 
			DecodeL(const TDesC8& aValue);

		/**
		* Creates a new instance of CSIPSupportedHeader
		* @param aValue a tag value 
		* @return a new instance of CSIPSupportedHeader
		*/
		IMPORT_C static CSIPSupportedHeader* NewL(RStringF aValue);

		/**
		* Creates a new instance of CSIPSupportedHeader 
		* and puts it to CleanupStack
		* @param aValue a tag value   
		* @return a new instance of CSIPSupportedHeader
		*/
		IMPORT_C static CSIPSupportedHeader* NewLC(RStringF aValue);

		/**
		* Destructor, deletes the resources of CSIPSupportedHeader.
		*/
		IMPORT_C ~CSIPSupportedHeader();


	public: // New functions

		/**
		* Constructs an instance of a CSIPSupportedHeader from a RReadStream
		* @param aReadStream a stream containing the value of the
		*        externalized object (header name not included). 
		* @return an instance of a CSIPSupportedHeader
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
		TBool HasCompactName() const;
		
        /**
        * @internalComponent
        */		
		RStringF CompactName() const;
		
        /**
        * @internalComponent
        */		
		TPreferredPlace PreferredPlaceInMessage() const;

	public: // New functions, for internal use

		static RPointerArray<CSIPHeaderBase> BaseDecodeL(const TDesC8& aValue);

	private: // New functions

		CSIPSupportedHeader();
		CSIPSupportedHeader(const CSIPSupportedHeader& aHeader);

	private: // For testing purposes
	
		UNIT_TEST(CSIPSupportedHeaderTest)
	};

#endif // CSIPSUPPORTEDHEADER_H

// End of File
