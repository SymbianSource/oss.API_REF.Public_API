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
* Name        : sipacceptlanguageheader.h
* Part of     : SIP Codec
* Interface   : SDK API, SIP Codec API
* Version     : SIP/4.0 
*
*/




#ifndef CSIPACCEPTLANGUAGEHEADER_H
#define CSIPACCEPTLANGUAGEHEADER_H

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
* parameters in SIP "Accept-Language" header.
*
* @lib sipcodec.lib
*/
class CSIPAcceptLanguageHeader : public CSIPParameterHeaderBase
	{
	public: // Constructors and destructor

		/**
		* Constructs a CSIPAcceptLanguageHeader from textual representation 
		* of the header's value part.
		* @param aValue a value part of a "Accept-Language"-header
		* @return an array containing one to many instances of 
		* 		   CSIPAcceptLanguageHeader. 
		*/
		IMPORT_C static RPointerArray<CSIPAcceptLanguageHeader> 
			DecodeL(const TDesC8& aValue);

		/**
		* Creates a new instance of CSIPAcceptLanguageHeader
		* @param aLanguageRange a language-range to set
		* @return a new instance of CSIPAcceptLanguageHeader
		*/
		IMPORT_C static CSIPAcceptLanguageHeader* 
			NewL(const TDesC8& aLanguageRange);

		/**
		* Creates a new instance of CSIPAcceptLanguageHeader and puts it onto
		* the cleanup stack
		* @param aLanguageRange a language-range to set
		* @return a new instance of CSIPAcceptLanguageHeader
		*/
		IMPORT_C static CSIPAcceptLanguageHeader* 
			NewLC(const TDesC8& aLanguageRange);

		/**
		* Destructor, deletes the resources of CSIPAcceptLanguageHeader.
		*/
		IMPORT_C ~CSIPAcceptLanguageHeader();


	public: // New functions

		/**
		* Gets the language-range from the "Accept-Language" header
		* @return a language-range
		*/
		IMPORT_C const TDesC8& LanguageRange() const;

		/**
		* Sets the language-range in the "Accept-Language" header
		* @param aLanguageRange a language-range
		*/
		IMPORT_C void SetLanguageRangeL(const TDesC8& aLanguageRange);

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
		* Constructs an instance of a CSIPAcceptLanguageHeader from a RReadStream
		* @param aReadStream a stream containing the value of the
		*        externalized header object (header name not included).
		* @return an instance of a CSIPAcceptLanguageHeader
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

	private: // New functions

		CSIPAcceptLanguageHeader();
		void ConstructL();
		void ConstructL(const TDesC8& aLanguageRange);
		void ConstructL(const CSIPAcceptLanguageHeader& aAcceptLanguageHeader);
		void DoInternalizeValueL(RReadStream& aReadStream);

	private: // Data

		HBufC8* iLanguageRange;
		CSIPAcceptHeaderParams* iParams;

	private: // For testing purposes
	
		UNIT_TEST(CSIPAcceptLanguageHeaderTest)
	};

#endif // CSIPACCEPTLANGUAGEHEADER_H

// End of File
