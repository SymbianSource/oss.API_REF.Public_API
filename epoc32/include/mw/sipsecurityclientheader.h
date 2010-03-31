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
* Name        : sipsecurityclientheader.h
* Part of     : SIP Codec
* Interface   : SDK API, SIP Codec API
* Version     : SIP/4.0 
*
*/




#ifndef CSIPSECURITYCLIENTHEADER_H
#define CSIPSECURITYCLIENTHEADER_H

//  INCLUDES
#include "sipsecurityheaderbase.h"
#include "_sipcodecdefs.h"

// CLASS DECLARATION
/**
* @publishedAll
* @released
*
* Class provides functions for setting and getting SIP "Security-Client"
* header fields.
*
*  @lib sipcodec.lib
*/
class CSIPSecurityClientHeader : public CSIPSecurityHeaderBase
	{
	public:	// Constructors and destructor

		/**
		* Constructs a CSIPSecurityClientHeader from textual representation
		* of the header's value part.
		* @param aValue a value part of a "Security-Client"-header
		* @return an array containing 1..n instances of CSIPSecurityClientHeader
		*/
		IMPORT_C static RPointerArray<CSIPSecurityClientHeader> 
			DecodeL(const TDesC8& aValue);

		/**
		* Creates a new instance of CSIPSecurityClientHeader
		* @param aMechanism a Mechanism-Name parameter 
		*        in the "Security-Client" header
		* @return a new instance of CSIPSecurityClientHeader
		*/
		IMPORT_C static CSIPSecurityClientHeader* 
			NewL(const TDesC8& aMechanism);

		/**
		* Creates a new instance of CSIPSecurityClientHeader 
		* and puts it to CleanupStack
		* @param aMechanism a Mechanism-Name parameter 
		* in the "Security-Client" header
		* @return a new instance of CSIPSecurityClientHeader
		*/
		IMPORT_C static CSIPSecurityClientHeader* 
			NewLC(const TDesC8& aMechanism);

		/**
		* Destructor, deletes the resources of CSIPSecurityClientHeader.
		*/
		IMPORT_C ~CSIPSecurityClientHeader();


	public: // New functions

		/**
		* Constructs an instance of a CSIPSecurityClientHeader 
		* from a RReadStream
		* @param aReadStream a stream containing the value of the
		*        externalized object (header name not included). 
		* @return an instance of a CSIPSecurityClientHeader
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

	private: // New functions

		CSIPSecurityClientHeader() ;

	private: // For testing purposes
	
		UNIT_TEST(CSIPSecurityHeaderBaseTest)
    };

#endif // CSIPSECURITYCLIENTHEADER_H

// End of File
