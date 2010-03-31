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
* Name        : sipacceptencodingheader.h
* Part of     : SIP Codec
* Interface   : SDK API, SIP Codec API
* Version     : SIP/4.0 
*
*/




#ifndef CSIPACCEPTENCODINGHEADER_H
#define CSIPACCEPTENCODINGHEADER_H

//  INCLUDES
#include "sipparameterheaderbase.h"

// FORWARD DECLARATIONS
class CSIPAcceptHeaderParams;

// CLASS DECLARATION
/**
* @publishedAll
* @released
*
* Class provides functions for setting and getting media types and
* parameters in SIP "Accept-Encoding" header.
*
*  @lib sipcodec.lib
*/
class CSIPAcceptEncodingHeader : public CSIPParameterHeaderBase
	{
	public:	// Constructors and destructor

		/**
		* Constructs a CSIPAcceptEncodingHeader from textual representation 
		* of the header's value part.
		* @param aValue a value part of a "Accept-Encoding"-header
		* @return An array containing one to many CSIPAcceptEncodingHeader
		*         instances
		*/
		IMPORT_C static RPointerArray<CSIPAcceptEncodingHeader> 
			DecodeL(const TDesC8& aValue);

		/**
		* Creates a new instance of CSIPAcceptEncodingHeader
		* @param aCodings a codings to set.
		* @return a new instance of CSIPAcceptEncodingHeader
		*/
		IMPORT_C static CSIPAcceptEncodingHeader* NewL(const TDesC8& aCodings);

		/**
		* Creates a new instance of CSIPAcceptEncodingHeader 
		* and puts it onto the cleanup stack
		* @param aCodings a codings to set.
		* @return a new instance of CSIPAcceptEncodingHeader
		*/
		IMPORT_C static CSIPAcceptEncodingHeader* NewLC(const TDesC8& aCodings);

		/**
		* Destructor, deletes the resources of CSIPAcceptEncodingHeader.
		*/
		IMPORT_C ~CSIPAcceptEncodingHeader();

	
	public:	// New functions  

		/**
		* Gets the codings from the "Accept-Encoding" header
		* @return codings
		*/
		IMPORT_C const TDesC8& Codings() const;

		/**
		* Sets the codings in the "Accept-Encoding" header
		* @param aCodings the codings
		*/
		IMPORT_C void SetCodingsL(const TDesC8& aCodings);

		/**
		* Gets the value of "q"-parameter
		* @return the "q"-parameter value
		*/
		IMPORT_C TReal QParameter() const;

		/**
		* Sets the "q"-parameter value
		* @param aQValue a "q"-parameter value to set´
		*/
		IMPORT_C void SetQParameterL(TReal aQValue);

		/**
		* Constructs an instance of a CSIPAcceptEncodingHeader from a RReadStream
		* @param aReadStream a stream containing the value of the
		*        externalized header object (header name not included).
		* @return An instance of a CSIPAcceptEncodingHeader
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
		TBool MoreThanOneAllowed() const;
		
        /**
		* @internalComponent
		*/		
		TPreferredPlace PreferredPlaceInMessage() const;

	public: // New functions, for internal use

		static RPointerArray<CSIPHeaderBase> BaseDecodeL(const TDesC8& aValue);

	private: // From CSIPHeaderBase

		void ExternalizeValueL(RWriteStream& aWriteStream) const;

	private: // From CSIPParameterHeaderBase

		HBufC8* ToTextMandatoryPartLC() const;
		void ParseMandatoryPartL(const TDesC8& aMandatoryPart);
		const CSIPParamContainerBase& Params() const;
		CSIPParamContainerBase& Params();
	
	private: // Constructors

		CSIPAcceptEncodingHeader();
		void ConstructL();
		void ConstructL(const TDesC8& aCodings);
		void ConstructL(const CSIPAcceptEncodingHeader& aAcceptEncodingHeader);

	private: // New functions

		void DoInternalizeValueL(RReadStream& aReadStream);

	private: // Data

		HBufC8* iCodings;
		CSIPAcceptHeaderParams* iParams;

	private: // For testing purposes
#ifdef CPPUNIT_TEST	
		friend class CSIPAcceptEncodingHeaderTest;
#endif
	};

#endif // CSIPACCEPTENCODINGHEADER_H

// End of File
