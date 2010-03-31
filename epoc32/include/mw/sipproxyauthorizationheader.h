/*
* Copyright (c) 2007-2009 Nokia Corporation and/or its subsidiary(-ies).
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
* Name          : sipproxyauthorizationheader.h
* Part of       : SIP Codec
* Version       : SIP/6.0 
*
*/



#ifndef CSIPPROXYAUTHORIZATIONHEADER_H
#define CSIPPROXYAUTHORIZATIONHEADER_H

//  INCLUDES
#include "sipauthorizationheaderbase.h"
#include "_sipcodecdefs.h"

// CLASS DECLARATION
/**
* @publishedAll
* @released
*
* Class for SIP Proxy-Authorization-header manipulation.
*
* @lib sipcodec.lib
*/
class CSIPProxyAuthorizationHeader : public CSIPAuthorizationHeaderBase
	{
	public:	// Constructors and destructor

		/**
		* Constructs a CSIPProxyAuthorizationHeader 
		* from textual representation of the header's value part.
		* @param aValue a value part of a "Proxy-Authenticate"-header 
		* @return a new instance of CSIPProxyAuthorizationHeader
		*/
		IMPORT_C static CSIPProxyAuthorizationHeader* 
			DecodeL(const TDesC8& aValue);

		/**
		* Creates a new instance of CSIPProxyAuthorizationHeader
		* @return a new instance of CSIPProxyAuthorizationHeader
		*/
		IMPORT_C static CSIPProxyAuthorizationHeader* 
			NewL(RStringF aAuthScheme);

		/**
		* Creates a new instance of CSIPProxyAuthorizationHeader
		* @return a new instance of CSIPProxyAuthorizationHeader
		*/
		IMPORT_C static CSIPProxyAuthorizationHeader* 
			NewLC(RStringF aAuthScheme);

		/**
		* Creates a deep-copy of a CSIPAuthorizationHeaderBase
		* @param aAuthenticateHeaderBase to be copied
		* @return a new instance of CSIPProxyAuthorizationHeader
		*/
		IMPORT_C static CSIPProxyAuthorizationHeader* 
			NewL(const CSIPAuthorizationHeaderBase& aHeader);

		/**
		* Creates a deep-copy of a CSIPAuthorizationHeaderBase
		* @param aAuthenticateHeaderBase to be copied
		* @return a new instance of CSIPProxyAuthorizationHeader
		*/
		IMPORT_C static CSIPProxyAuthorizationHeader* 
			NewLC(const CSIPAuthorizationHeaderBase& aHeader);

		/**
		* Destructor
		*/
		IMPORT_C ~CSIPProxyAuthorizationHeader();

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

		CSIPProxyAuthorizationHeader();

	private: // From CSIPHeaderBase

		void ExternalizeValueL(RWriteStream& aWriteStream) const;

    private: // For testing purposes

        UNIT_TEST(CSIPProxyAuthorizationHeaderTest)
	};

#endif // CSIPPROXYAUTHORIZATIONHEADER_H

// End of File
