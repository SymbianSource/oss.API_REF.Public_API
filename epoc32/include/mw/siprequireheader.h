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
* Name        : siprequireheader.h
* Part of     : SIP Codec
* Interface   : SDK API, SIP Codec API
* Version     : SIP/4.0 
*
*/




#ifndef CSIPREQUIREHEADER_H
#define CSIPREQUIREHEADER_H

//  INCLUDES
#include "siptokenheaderbase.h"
#include "_sipcodecdefs.h"

// CLASS DECLARATION
/**
* @publishedAll
* @released
*
* Class provides functions for setting and getting parameters in 
* SIP "Require" header.
*
*  @lib sipcodec.lib
*/
class CSIPRequireHeader : public CSIPTokenHeaderBase
	{
	public:	// Constructors and destructor

		/**
		* Constructs a CSIPRequireHeader from textual representation 
		* of the header's value part.
		* @param aValue a value part of a "Require"-header
		* @return an array containing 1..n instances of CSIPRequireHeader   
		*/
		IMPORT_C static RPointerArray<CSIPRequireHeader> 
			DecodeL(const TDesC8& aValue);

		/**
		* Creates a new instance of CSIPRequireHeader
		* @param aValue a tag value 
		* @return a new instance of CSIPRequireHeader
		*/
		IMPORT_C static CSIPRequireHeader* NewL(RStringF aValue);

		/**
		* Creates a new instance of CSIPRequireHeader 
		* and puts it to CleanupStack
		* @param aValue a tag value   
		* @return a new instance of CSIPRequireHeader 
		*/
		IMPORT_C static CSIPRequireHeader* NewLC(RStringF aValue);

		/**
		* Destructor, deletes the resources of CSIPRequireHeader.
		*/
		IMPORT_C ~CSIPRequireHeader();


	public: // New functions

		/**
		* Constructs an instance of a CSIPRequireHeader from a RReadStream
		* @param aReadStream a stream containing the value of the
		*        externalized object (header name not included).
		* @return an instance of a CSIPRequireHeader 
		*/
		IMPORT_C static CSIPHeaderBase* InternalizeValueL(RReadStream& aReadStream);


	public: // From CSIPHeaderBase

		/**
		* From CSIPHeaderBase CloneL
		*/
		IMPORT_C CSIPHeaderBase* CloneL() const;

		/**
		* From CSIPHeaderBase Name
		*/
		IMPORT_C RStringF Name() const;


	public: // From CSIPHeaderBase, For internal use

        /**
        * @internalComponent
        */	
		TPreferredPlace PreferredPlaceInMessage() const;

	public: // New functions, for internal use

		static RPointerArray<CSIPHeaderBase> BaseDecodeL(const TDesC8& aValue);

	private: // Constructors

		CSIPRequireHeader();
		CSIPRequireHeader(const CSIPRequireHeader& aHeader);		
	};

#endif // end of CSIPREQUIREHEADER_H

// End of File
