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
* Name        : sipacceptheader.h
* Part of     : SIP Codec
* Interface   : SDK API, SIP Codec API
* Version     : SIP/4.0 
*
*/




#ifndef CSIPACCEPTHEADER_H
#define CSIPACCEPTHEADER_H

//  INCLUDES
#include "sipparameterheaderbase.h"
#include "_sipcodecdefs.h"

// FORWARD DECLARATIONS
class CSIPAcceptHeaderParams;


// CLASS DECLARATION
/**
* @publishedAll
* @released
*
* Class provides functions for setting and getting media types and
* parameters in SIP "Accept" header.
*
*  @lib sipcodec.lib
*/
class CSIPAcceptHeader : public CSIPParameterHeaderBase
	{
	public:	// Constructors and destructor

		/**
		* Constructs a CSIPAcceptHeader from textual representation 
		* of the header's value part.
		* An empty Accept-header can be created using this function
		* by passing a KNullDesC8 as a parameter.
		* @param aValue a value part of a "Accept"-header
		* @return an array containing one to many instances of CSIPAcceptHeader.
		*/
		IMPORT_C static RPointerArray<CSIPAcceptHeader> 
			DecodeL(const TDesC8& aValue);

		/**
		* Creates a new instance of CSIPAcceptHeader
		* @param aMediaType a media type to set. For example "application"
		* @param aMediaSubtype a media subtype to set. For example "sdp"
		* @return a new instance of CSIPAcceptHeader
		*/
		IMPORT_C static CSIPAcceptHeader* NewL(const TDesC8& aMediaType,
		                                       const TDesC8& aMediaSubtype);

		/**
		* Creates a new instance of CSIPAcceptHeader and puts it into 
		* the cleanup stack
		* @param aMediaType a media type to set. For example "application"
		* @param aMediaSubtype a media subtype to set. For example "sdp"
		* @return a new instance of CSIPAcceptHeader
		*/
		IMPORT_C static CSIPAcceptHeader* NewLC(const TDesC8& aMediaType,
		                                        const TDesC8& aMediaSubtype);

		/**
		* Destructor, deletes the resources of CSIPAcceptHeader.
		*/
		IMPORT_C ~CSIPAcceptHeader();


	public: // New functions

		/**
		* Check if the header is empty. If so, 
		* the other getters will not return a meaningful value.
		* @return ETrue if empty, EFalse otherwise.
		*/
		IMPORT_C TBool IsEmpty() const;
    
		/**
		* Gets the media type from the "Accept" header
		* @return a media type
		*/
		IMPORT_C const TDesC8& MediaType() const;

		/**
		* Sets the media type in the "Accept" header
		* @pre IsEmpty() == EFalse
		* @param aMediaType a media type
		*/
		IMPORT_C void SetMediaTypeL(const TDesC8& aMediaType);

		/**
		* Gets the media subtype from the "Accept" header
		* @return a media subtype
		*/
		IMPORT_C const TDesC8& MediaSubtype() const;
		/**
		* Sets the media subtype in the "Accept" header
		* @pre IsEmpty() == EFalse
		* @param aMediaSubtype a media subtype
		*/
		IMPORT_C void SetMediaSubtypeL(const TDesC8& aMediaSubtype);

		/**
		* Gets the value of "q"-parameter
		* @return the "q"-parameter value
		*/
		IMPORT_C TReal QParameter() const;

		/**
		* Sets the "q"-parameter value
		* @param aQValue a "q"-parameter value to set
		*/
		IMPORT_C void SetQParameterL(TReal aQValue);

		/**
		* Constructs an instance of a CSIPAcceptHeader from a RReadStream
		* @param aReadStream a stream containing the value of the
		*        externalized header object (header name not included).
		* @return An instance of a CSIPAcceptHeader
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

		CSIPAcceptHeader(TBool aEmpty=EFalse);
		void ConstructL();
		void ConstructL(const TDesC8& aMediaType, const TDesC8& aMediaSubtype);
		void ConstructL(const CSIPAcceptHeader& aAcceptHeader);

	private: // New functions

		void DoInternalizeValueL(RReadStream& aReadStream);

	private: // Data

		TBool iEmpty;
		HBufC8* iMediaType;
		HBufC8* iMediaSubtype;
		CSIPAcceptHeaderParams* iParams;

	private: // For testing purposes
	
		UNIT_TEST(CSIPAcceptHeaderTest)
	};

#endif // CSIPACCEPTHEADER_H

// End of File
