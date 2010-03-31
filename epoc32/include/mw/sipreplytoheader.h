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
* Name        : sipreplytoheader.h
* Part of     : SIP Codec
* Interface   : SDK API, SIP Codec API
* Version     : SIP/4.0 
*
*/




#ifndef CSIPREPLYTOHEADER_H
#define CSIPREPLYTOHEADER_H

//  INCLUDES
#include "sipaddressheaderbase.h"

// FORWARD DECLARATIONS
class CSIPAddress;
class CSIPHeaderGenericParams;

// CLASS DECLARATION
/**
* @publishedAll
* @released
*
* Class provides functions for setting and getting parameters in SIP 
* "Reply-To" header.
*
*  @lib sipcodec.lib
*/
class CSIPReplyToHeader : public CSIPAddressHeaderBase
	{
	public:	// Constructors and destructor

		/**
		* Constructs a CSIPReplyToHeader from textual representation 
		* of the header's value part.
		* @param aValue a value part of a "Refer-To"-header 
		*        (e.g. "User <user@host>")
		* @return a new instance of CSIPReplyToHeader   
		*/
		IMPORT_C static CSIPReplyToHeader* DecodeL(const TDesC8& aValue);

		/**
		* Creates a new instance of CSIPReplyToHeader
		* @pre aSIPAddress != 0
		* @param aSIPAddress a name-address, the ownership is transferred.
		* @return a new instance of CSIPReplyToHeader
		*/
		IMPORT_C static CSIPReplyToHeader* NewL(CSIPAddress* aSIPAddress);

		/**
		* Creates a new instance of CSIPReplyToHeader and puts it to CleanupStack
		* @pre aSIPAddress != 0
		* @param aSIPAddress a name-address, the ownership is transferred,
		* @return a new instance of CSIPReplyToHeader
		*/
		IMPORT_C static CSIPReplyToHeader* NewLC(CSIPAddress* aSIPAddress);

		/**
		* Destructor, deletes the resources of CSIPReplyToHeader.
		*/
		IMPORT_C virtual ~CSIPReplyToHeader();


	public: // New functions

		/**
		* Constructs an instance of a CSIPReplyToHeader from a RReadStream
		* @param aReadStream a stream containing the value of the
		*        externalized object (header name not included). 
		* @return an instance of a CSIPReplyToHeader
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

		CSIPReplyToHeader();

	private: // For testing purposes
#ifdef CPPUNIT_TEST	
		friend class CSIPReplyToHeaderTest;
#endif
	};

#endif // end of CSIPREPLYTOHEADER_H

// End of File
