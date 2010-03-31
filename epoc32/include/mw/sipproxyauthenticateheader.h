/*
* Copyright (c) 2006-2009 Nokia Corporation and/or its subsidiary(-ies).
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
* Name          : sipproxyauthenticateheader.h
* Part of       : SIP Codec
* Version       : SIP/5.0 
*
*/



#ifndef CSIPPROXYAUTHENTICATEHEADER_H
#define CSIPPROXYAUTHENTICATEHEADER_H

//  INCLUDES
#include "sipauthenticateheaderbase.h"

// CLASS DECLARATION
/**
* @publishedAll
* @released
*
* Class for SIP Proxy-Authenticate-header manipulation.
*
* @lib sipcodec.lib
*/
class CSIPProxyAuthenticateHeader : public CSIPAuthenticateHeaderBase
	{
	public:	// Constructors and destructor

		/**
		* Constructs a CSIPProxyAuthenticateHeader from textual representation
		* of the header's value part.
		* @param aValue a value part of a "Proxy-Authenticate"-header 
		* @return a new instance of CSIPProxyAuthenticateHeader
		*/
		IMPORT_C static CSIPProxyAuthenticateHeader* 
			DecodeL(const TDesC8& aValue);

		/**
		* Creates a new instance of CSIPProxyAuthenticateHeader
		* @return a new instance of CSIPProxyAuthenticateHeader
		*/
		IMPORT_C static CSIPProxyAuthenticateHeader* 
			NewL(RStringF aAuthScheme);

		/**
		* Creates a new instance of CSIPProxyAuthenticateHeader
		* @return a new instance of CSIPProxyAuthenticateHeader
		*/
		IMPORT_C static CSIPProxyAuthenticateHeader* 
			NewLC(RStringF aAuthScheme);

		/**
		* Destructor
		*/
		IMPORT_C ~CSIPProxyAuthenticateHeader();

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
		static CSIPHeaderBase* InternalizeValueL(RReadStream& aReadStream);

	private: // Constructors

		CSIPProxyAuthenticateHeader();

    private: // For testing purposes
#ifdef CPPUNIT_TEST
        friend class CSIPProxyAuthenticateHeaderTest;
#endif
	};

#endif // CSIPPROXYAUTHENTICATEHEADER_H

// End of File
