/*
* Copyright (c) 2007-2009 Nokia Corporation and/or its subsidiary(-ies).
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
* Name          : sipauthorizationheader.h
* Part of       : SIP Codec
* Version       : SIP/6.0 
*
*/



#ifndef CSIPAUTHORIZATIONHEADER_H
#define CSIPAUTHORIZATIONHEADER_H

//  INCLUDES
#include "sipauthorizationheaderbase.h"

// CLASS DECLARATION
/**
* @publishedAll
* @released
*
* Class for SIP Authorization-header manipulation.
* @lib sipcodec.lib
*/
class CSIPAuthorizationHeader : public CSIPAuthorizationHeaderBase
	{
	public:	// Constructors and destructor

		/**
		* Constructs a CSIPAuthorizationHeader 
		* from textual representation of the header's value part.
		* @param aValue a value part of a "Proxy-Authenticate"-header 
		* @return a new instance of CSIPAuthorizationHeader
		*/
		IMPORT_C static CSIPAuthorizationHeader* 
			DecodeL(const TDesC8& aValue);

		/**
		* Creates a new instance of CSIPAuthorizationHeader
		* @return a new instance of CSIPAuthorizationHeader
		*/
		IMPORT_C static CSIPAuthorizationHeader* 
			NewL(RStringF aAuthScheme);

		/**
		* Creates a new instance of CSIPAuthorizationHeader
		* @return a new instance of CSIPAuthorizationHeader
		*/
		IMPORT_C static CSIPAuthorizationHeader* 
			NewLC(RStringF aAuthScheme);

		/**
		* Creates a deep-copy of a CSIPAuthorizationHeaderBase
		* @param aAuthenticateHeaderBase to be copied
		* @return a new instance of CSIPAuthorizationHeader
		*/
		IMPORT_C static CSIPAuthorizationHeader* 
			NewL(const CSIPAuthorizationHeaderBase& aHeader);

		/**
		* Creates a deep-copy of a CSIPAuthorizationHeaderBase
		* @param aAuthenticateHeaderBase to be copied
		* @return a new instance of CSIPAuthorizationHeader
		*/
		IMPORT_C static CSIPAuthorizationHeader* 
			NewLC(const CSIPAuthorizationHeaderBase& aHeader);

		/**
		* Destructor
		*/
		IMPORT_C ~CSIPAuthorizationHeader();

	public: // From CSIPHeaderBase

		/**
		* From CSIPHeaderBase ExternalizeSupported
		*/
		IMPORT_C TBool ExternalizeSupported() const;

		/**
		* From CSIPHeaderBase CloneL
		*/
		IMPORT_C CSIPHeaderBase* CloneL() const;
		
		/**
		* From CSIPHeaderBase Name
		*/		
		IMPORT_C RStringF Name() const;


	public: // New functions, for internal use

        /**
        * @internalComponent
        */
		static RPointerArray<CSIPHeaderBase> BaseDecodeL(const TDesC8& aValue);
		
        /**
        * @internalComponent
        */		
		static CSIPHeaderBase* InternalizeValueL(RReadStream& aReadStream);

	private: // Constructors

		CSIPAuthorizationHeader();

	private: // From CSIPHeaderBase

		void ExternalizeValueL(RWriteStream& aWriteStream) const;

    private: // For testing purposes
#ifdef CPPUNIT_TEST
        friend class CSIPAuthorizationHeaderTest;
#endif
	};

#endif // CSIPAUTHORIZATIONHEADER_H

// End of File
