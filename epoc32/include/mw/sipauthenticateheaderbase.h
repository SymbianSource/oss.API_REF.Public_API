/*
* Copyright (c) 2006-2009 Nokia Corporation and/or its subsidiary(-ies).
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
* Name          : sipauthenticateheaderbase.h
* Part of       : SIP Codec
* Version       : SIP/5.0 
*
*/



#ifndef CSIPAUTHENTICATEHEADERBASE_H
#define CSIPAUTHENTICATEHEADERBASE_H

//  INCLUDES
#include "sipauthheaderbase.h"
#include "_sipcodecdefs.h"

// FORWARD DECLARATIONS
class CSIPAuthenticateHeaderParams;

// CLASS DECLARATION
/**
* @publishedAll
* @released
*
* A base class for SIP Proxy-Authenticate- and WWW-Authenticate-headers
*
* @lib sipcodec.lib
*/
class CSIPAuthenticateHeaderBase : public CSIPAuthHeaderBase
	{
	public: // Constructors and destructor

		/**
		* Destructor.
		*/
		IMPORT_C virtual ~CSIPAuthenticateHeaderBase();


	public: // New functions

		/**
		* Check whether a qop-value in qop-options is present. 
		* @param aQopValue the qop-value
		* @return ETrue if present, otherwise EFalse. 
		*/
		IMPORT_C TBool HasQopValueL(const TDesC8& aQopValue) const;

	public: // From CSIPHeaderBase

		/**
		* From CSIPHeaderBase ExternalizeSupported
		*/
		IMPORT_C virtual TBool ExternalizeSupported() const;
		
	protected: // Constructors

		CSIPAuthenticateHeaderBase();
		void ConstructL();
		void ConstructL(const CSIPAuthenticateHeaderBase& aHeader);

	protected: // From CSIPHeaderBase

		void ExternalizeValueL(RWriteStream& aWriteStream) const;

	protected: // From CSIPAuthBase

		const CSIPParamContainerBase& Params() const;
		CSIPParamContainerBase& Params();

	protected: // New functions

		void DoInternalizeValueL(RReadStream& aReadStream);

	protected: // Data

		CSIPAuthenticateHeaderParams* iParams;
	};

#endif // CSIPAUTHENTICATEHEADERBASE_H

// End of File
