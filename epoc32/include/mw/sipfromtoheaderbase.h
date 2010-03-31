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
* Name        : sipfromtoheaderbase.h
* Part of     : SIP Codec
* Interface   : SDK API, SIP Codec API
* Version     : SIP/4.0 
*
*/




#ifndef CSIPFROMTOHEADERBASE_H
#define CSIPFROMTOHEADERBASE_H

//  INCLUDES
#include "sipparameterheaderbase.h"

// FORWARD DECLARATIONS
class CSIPAddress;
class CSIPFromToHeaderParams;

// CLASS DECLARATION
/**
* @publishedAll
* @released
*
* Class provides functions for setting and getting parameters in SIP "From"
* and "To" header.
*
* This is an abstract class and cannot be instantiated.
*
* @lib sipcodec.lib
*/
class CSIPFromToHeaderBase : public CSIPParameterHeaderBase
	{
	public: // Constructors and destructor

		/**
		* Destructor, deletes the resources of CSIPFromToHeaderBase.
		*/
		IMPORT_C virtual ~CSIPFromToHeaderBase();


	public: // New functions

		/**
		* Compares this instance to another "From" or "To" header object
		* @param aHeader a header to compare to
		* @return ETrue, if the objects are equal otherwise EFalse
		*/
		IMPORT_C TBool operator==(const CSIPFromToHeaderBase& aHeader) const;

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


	public: // From CSIPHeaderBase, for internal use

        /**
        * @internalComponent
        */
		TBool HasCompactName() const;
		
        /**
        * @internalComponent
        */		
		TPreferredPlace PreferredPlaceInMessage() const;

	protected: // Constructors

		CSIPFromToHeaderBase();
		void ConstructL();
		void ConstructL(CSIPAddress* aSIPAddress);
		void ConstructL(CSIPAddress* aSIPAddress, const TDesC8& aTag);
		void ConstructL(const CSIPFromToHeaderBase& aSIPFromToHeaderBase);

	protected: // New functions

		void DoInternalizeValueL(RReadStream& aReadStream);

	private: // From CSIPHeaderBase

		void ExternalizeValueL(RWriteStream& aWriteStream) const;

	private: // From CSIPParameterHeaderBase

		HBufC8* ToTextMandatoryPartLC() const;
		void ParseMandatoryPartL(const TDesC8& aMandatoryPart);
		const CSIPParamContainerBase& Params() const;
		CSIPParamContainerBase& Params();

	private: // Data

		CSIPAddress* iSIPAddress;
		CSIPFromToHeaderParams* iParams;

	private: // For testing purposes
#ifdef CPPUNIT_TEST
		friend class CSIPFromToHeaderTest;
#endif
	};


#endif // CSIPFROMTOHEADERBASE_H

// End of File
