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
* Name        : sipsecurityheaderbase.h
* Part of     : SIP Codec
* Interface   : SDK API, SIP Codec API
* Version     : SIP/4.0 
*
*/




#ifndef CSIPSECURITYHEADERBASE_H
#define CSIPSECURITYHEADERBASE_H

//  INCLUDES
#include "sipparameterheaderbase.h"

// FORWARD DECLARATIONS
class CSIPSecurityHeaderBaseParams;

// CLASS DECLARATION
/**
* @publishedAll
* @released
*
* A base class for Security-Client, Security-Server and Security-Verify.
*
*  @lib sipcodec.lib
*/
class CSIPSecurityHeaderBase : public CSIPParameterHeaderBase
	{
	public:	// Constructors and destructor

		/**
		* Destructor, deletes the resources of CSIPSecurityHeaderBase.
		*/
		IMPORT_C virtual ~CSIPSecurityHeaderBase();

	public: // New functions

		/**
		* Gets the value of "q"-parameter
		* @return the "q"-parameter value, zero if not present 
		*/
		IMPORT_C TReal PreferenceParam() const;

		/**
		* Sets the "q"-parameter value
		* @param aPreferenceValue a "q"-parameter value to set
		*/
		IMPORT_C void SetPreferenceParamL(TReal aPreferenceValue);

		/**
		* Gets the Mechanism-Name from the Security header
		* @return a Mechanism-Name
		*/
		IMPORT_C const TDesC8& MechanismName() const;

		/**
		* Sets the Mechanism-Name in the Security header
		* @param aMechanismName a Mechanism-Name
		*/
		IMPORT_C void SetMechanismNameL(const TDesC8& aMechanismName);

	public: // From CSIPHeaderBase, for internal use

        /**
        * @internalComponent
        */
		TBool MoreThanOneAllowed() const;
		
        /**
        * @internalComponent
        */		
		TPreferredPlace PreferredPlaceInMessage() const;

	protected: // Constructors

		CSIPSecurityHeaderBase();
		void ConstructL();
		void ConstructL(const TDesC8& aMechanismName);
		void ConstructL(const CSIPSecurityHeaderBase& aSecurityHeaderBase);
	
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

		HBufC8* iMechanismName;
		CSIPSecurityHeaderBaseParams* iParams;

	private: // For testing purposes
#ifdef CPPUNIT_TEST	
		friend class CSIPSecurityHeaderBaseTest;
#endif
	};

#endif // CSIPSECURITYHEADERBASE_H

// End of File
