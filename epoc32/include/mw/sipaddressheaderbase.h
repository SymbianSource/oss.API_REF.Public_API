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
* Name        : sipaddressheaderbase.h
* Part of     : SIP Codec
* Interface   : SDK API, SIP Codec API
* Version     : SIP/4.0 
*
*/




#ifndef CSIPADDRESSHEADERBASE_H
#define CSIPADDRESSHEADERBASE_H

//  INCLUDES
#include "sipparameterheaderbase.h"
#include "_sipcodecdefs.h"

// FORWARD DECLARATIONS
class CSIPAddress;
class CSIPHeaderGenericParams;

// CLASS DECLARATION
/**
* @publishedAll
* @released
*
* A base class for SIP headers having syntax
* ( name-addr/ addr-spec ) *(generic-param)
*
*  @lib sipcodec.lib
*/
class CSIPAddressHeaderBase : public CSIPParameterHeaderBase
	{
	public:	// Constructors and destructor

		/**
		* Destructor, deletes the resources of CSIPAddressHeaderBase.
		*/
        IMPORT_C virtual ~CSIPAddressHeaderBase();


	public: // New functions

		/**
		* Sets the name-address
		* @pre aSIPAddress != 0
		* @param aSIPAddress a name-address to set, the ownership is transferred
		*/
		IMPORT_C void SetSIPAddressL(CSIPAddress* aSIPAddress);

		/**
		* Gets the name-address as const
		* @return name-address object
		*/
		IMPORT_C const CSIPAddress& SIPAddress() const;

		/**
		* Gets the name-address
		* @return name-address object
		*/
		IMPORT_C CSIPAddress& SIPAddress();


	protected: // Constructors

		CSIPAddressHeaderBase();
        void ConstructL();
		void ConstructL(CSIPAddress* aSIPAddress);
        void ConstructL(const CSIPAddressHeaderBase& aHeader);

	protected: // Data

        /**
        * @internalComponent
        */
		CSIPAddress* iSIPAddress;
		
        /**
        * @internalComponent
        */		
		CSIPHeaderGenericParams* iParams;

	protected: // New functions

		void DoInternalizeValueL(RReadStream& aReadStream);

	protected: // From CSIPHeaderBase

        /**
        * @internalComponent
        */
		void ExternalizeValueL(RWriteStream& aWriteStream) const;

	private: // From CSIPParameterHeaderBase

		HBufC8* ToTextMandatoryPartLC() const;
		void ParseMandatoryPartL(const TDesC8& aMandatoryPart);
		const CSIPParamContainerBase& Params() const;
		CSIPParamContainerBase& Params();
	};

#endif // end of CSIPADDRESSHEADERBASE_H

// End of File
