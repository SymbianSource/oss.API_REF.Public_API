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
* Name        : siprouteheaderbase.h
* Part of     : SIP Codec
* Interface   : SDK API, SIP Codec API
* Version     : SIP/4.0 
*
*/




#ifndef CSIPROUTEHEADERBASE_H
#define CSIPROUTEHEADERBASE_H

//  INCLUDES
#include "sipparameterheaderbase.h"

// FORWARD DECLARATIONS
class CSIPAddress;
class CSIPHeaderGenericParams;

// CLASS DECLARATION
/**
* @publishedAll
* @released
*
* A base class for "Route"-, "Record-Route"- and "Service-Route"-headers.
*
*  @lib sipcodec.lib
*/
class CSIPRouteHeaderBase : public CSIPParameterHeaderBase
	{
	public:	// Constructors and destructor

		/**
		* Destructor, deletes the resources of CSIPRouteHeaderBase.
		*/
		IMPORT_C virtual ~CSIPRouteHeaderBase();


	public:	// New functions
		
		/**
		* Sets the name-address
		* @pre aSIPAddress != 0
		* @param aSIPAddress a name-address, the ownership is transferred
		*/
		IMPORT_C void SetSIPAddressL(CSIPAddress* aSIPAddress);
	
		/**
		* Gets the name-address as const
		* @return name-address
		*/
		IMPORT_C const CSIPAddress& SIPAddress() const;

		/**
		* Gets the name-address
		* @return name-address
		*/
		IMPORT_C CSIPAddress& SIPAddress();


	public: // From CSIPHeaderBase, for internal use

        /**
        * @internalComponent
        */	
		TBool MoreThanOneAllowed() const;
		
        /**
        * @internalComponent
        */		
		TPreferredPlace PreferredPlaceInMessage() const;

	protected: // Contructors

		CSIPRouteHeaderBase();
		void ConstructL();
		void ConstructL(CSIPAddress* aSIPAddress);
		void ConstructL(const CSIPRouteHeaderBase& aRouteHeaderBase);

	protected: // Data

        /**
        * @internalComponent
        */
		CSIPAddress* iSIPAddress;
		
        /**
        * @internalComponent
        */		
		CSIPHeaderGenericParams* iParams;

	private: // From CSIPParameterHeaderBase

		HBufC8* ToTextMandatoryPartLC() const;
		void ParseMandatoryPartL(const TDesC8& aMandatoryPart);
		const CSIPParamContainerBase& Params() const;
		CSIPParamContainerBase& Params();

	private: // For testing purposes
#ifdef CPPUNIT_TEST	
		friend class CSIPRouteHeaderBaseTest;
#endif
	};

#endif // CSIPROUTEHEADERBASE_H

// End of File
