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
* Name        : sipcontentdispositionheader.h
* Part of     : SIP Codec
* Interface   : SDK API, SIP Codec API
* Version     : SIP/4.0 
*
*/




#ifndef CSIPCONTENTDISPOSITIONHEADER_H
#define CSIPCONTENTDISPOSITIONHEADER_H

//  INCLUDES
#include "sipparameterheaderbase.h"
#include "_sipcodecdefs.h"

// FORWARD DECLARATIONS
class CSIPHeaderGenericParams;

// CLASS DECLARATION
/**
* @publishedAll
* @released
*
* Class provides functions for setting and getting parameters in 
* SIP "Content-Disposition" header.
*
*  @lib sipcodec.lib
*/
class CSIPContentDispositionHeader : public CSIPParameterHeaderBase
	{
	public:	// Constructors and destructor
	
		/**
		* Constructs a CSIPContentDispositionHeader from textual representation 
		* of the header's value part.
		* @param aValue a value part of a "Content-Disposition"-header
		* @return a new instance of CSIPContentDispositionHeader
		*/
		IMPORT_C static CSIPContentDispositionHeader* 
			DecodeL (const TDesC8& aValue);

		/**
		* Creates a new instance of CSIPContentDispositionHeader
		* @param aDispType a Disp-Type value
		* @return a new instance of CSIPContentDispositionHeader
		*/
		IMPORT_C static CSIPContentDispositionHeader* 
			NewL(const TDesC8& aDispType);

		/**
		* Creates a new instance of CSIPContentDispositionHeader 
		* and puts it to CleanupStack
		* @param aDispType a Disp-Type value
		* @return a new instance of CSIPContentDispositionHeader
		*/
		IMPORT_C static CSIPContentDispositionHeader* 
			NewLC(const TDesC8& aDispType);

		/**
		* Destructor. deletes the resources of CSIPContentDispositionHeader.
		*/
		IMPORT_C ~CSIPContentDispositionHeader();


	public: // New functions

		/**
		* Gets the disp-type parameter from the "Content-Disposition" header
		* @return the disp-type parameter
		*/
		IMPORT_C const TDesC8& DispType() const;

		/**
		* Sets the disp-type parameter in the "Content-Disposition" header; 
		* @param aTag a disp-type parameter to set
		*/
		IMPORT_C void SetDispTypeL(const TDesC8& aDispType);
	
		/**
		* Constructs an instance of a CSIPContentDispositionHeader 
		* from a RReadStream
		* @param aReadStream a stream containing the value of the
		*        externalized object (header name not included). 
		* @return an instance of a CSIPContentDispositionHeader
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

		CSIPContentDispositionHeader();
		void ConstructL();
		void ConstructL(const TDesC8& aDispType);
		void ConstructL(const TDesC8& aDispType, const TDesC8& aHandlingParam);
		void ConstructL(const CSIPContentDispositionHeader& aHeader);

	private: // New functions

		void DoInternalizeValueL(RReadStream& aReadStream);

	private: // Data

		HBufC8* iDispType;
		CSIPHeaderGenericParams* iParams;

	private: // For testing purposes
	
		UNIT_TEST(CSIPContentDispositionHeaderTest)
	};

#endif // CSIPCONTENTDISPOSITIONHEADER_H

// End of File
