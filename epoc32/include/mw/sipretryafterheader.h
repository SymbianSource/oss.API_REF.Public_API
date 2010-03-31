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
* Name        : sipretryafterheader.h
* Part of     : SIP Codec
* Interface   : SDK API, SIP Codec API
* Version     : SIP/4.0 
*
*/




#ifndef CSIPRETRYAFTERHEADER_H
#define CSIPRETRYAFTERHEADER_H

//  INCLUDES
#include "sipparameterheaderbase.h"

// FORWARD DECLARATIONS
class CSIPRetryAfterHeaderParams;

// CLASS DECLARATION
/**
* @publishedAll
* @released
*
* Class provides functions for setting and getting parameters in SIP 
* "Retry-After" header.
*
*  @lib sipcodec.lib
*/
class CSIPRetryAfterHeader : public CSIPParameterHeaderBase
	{
	public:	// Constructors and destructor

		/**
		* Constructs a CSIPRetryAfterHeader from textual representation 
		* of the header's value part.
		* @param aValue a value part of a "Retry-After"-header 
		*        (e.g. "18000;duration=3600")
		* @return a new instance of CSIPRetryAfterHeader   
		*/
		IMPORT_C static CSIPRetryAfterHeader* DecodeL(const TDesC8& aValue);

		/**
		* Creates a new instance of CSIPRetryAfterHeader
		* @param aRetryAfter a retry after value.
		* @return a new instance of CSIPRetryAfterHeader
		*/
        IMPORT_C static CSIPRetryAfterHeader* NewL(TUint aRetryAfter);

		/**
		* Creates a new instance of CSIPRetryAfterHeader
        * On return the new instance has left to the CleanupStack.
		* @param aRetryAfter a retry after value.
		* @return a new instance of CSIPRetryAfterHeader
		*/
        IMPORT_C static CSIPRetryAfterHeader* NewLC(TUint aRetryAfter);

        /**
		* Destructor, deletes the resources of CSIPRetryAfterHeader.
		*/
		IMPORT_C virtual ~CSIPRetryAfterHeader();


	public: // New functions

		/**
		* Sets the retry after value
		* @param aValue a new retry after value to set.
		*/
		IMPORT_C void SetRetryAfter(TUint aValue);

		/**
		* Gets the retry after value
		* @return a retry after value
		*/
		IMPORT_C TUint RetryAfter() const;

		/**
		* Gets the comment value
		* @return a comment value or KNullDesC8
		*/
		IMPORT_C const TDesC8& Comment() const;

		/**
		* Gets the value of the "duration"-parameter
		* @return the "duration"-parameter, or 
		*         KErrNotFound if the parameter is not present.
		*/
		IMPORT_C TInt DurationParam() const;

		/**
		* Sets the "duration"-parameter
		* @pre aDurationParam >= 0
		* @param aDurationParam a "duration"-parameter value to set
		*/
		IMPORT_C void SetDurationParamL(TInt aDurationParam);

        /**
		* Constructs an instance of a CSIPRetryAfterHeader from a RReadStream
		* @param aReadStream a stream containing the value of the
		*        externalized object (header name not included). 
		* @return an instance of a CSIPRetryAfterHeader
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

        CSIPRetryAfterHeader();
		CSIPRetryAfterHeader(TUint aRetryAfter);
        void ConstructL();
		void ConstructL(const CSIPRetryAfterHeader& aRetryAfterHeader);

	private: // New functions

		void DoInternalizeValueL(RReadStream& aReadStream);

	private: // Data

		TUint iRetryAfter;
        HBufC8* iComment;
		CSIPRetryAfterHeaderParams* iParams;

	private: // For testing purposes
#ifdef CPPUNIT_TEST	
		friend class CSIPRetryAfterHeaderTest;
#endif
	};

#endif // end of CSIPRETRYAFTERHEADER_H

// End of File
