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
* Name        : sipextensionheader.h
* Part of     : SIP Codec
* Interface   : SDK API, SIP Codec API
* Version     : SIP/4.0 
*
*/




#ifndef CSIPEXTENSIONHEADER_H
#define CSIPEXTENSIONHEADER_H

//  INCLUDES
#include "sipheaderbase.h"
#include "_sipcodecdefs.h"


// CLASS DECLARATION
/**
* @publishedAll
* @released
*
* The class stores unknown and extension headers that are either not 
* supported by the current SIP codec implementation or not specified in
* current SIP RFC or both.
*
*  @lib sipcodec.lib
*/
class CSIPExtensionHeader : public CSIPHeaderBase
	{
	public:	// Constructors and destructor

		/**
		* Creates a new instance of CSIPExtensionHeader
		* @param aName the full or compact name of the header
		* @param aValue the value of the header
		* @return a new instance of CSIPExtensionHeader
		*/
		IMPORT_C static CSIPExtensionHeader* 
			NewL(const TDesC8& aName, const TDesC8& aValue);

		/**
		* Creates a new instance of CSIPExtensionHeader 
		* and puts it to CleanupStack
		* @param aName the full or compact name of the header
		* @param aValue the value of the header
		* @return a new instance of CSIPExtensionHeader
		*/
		IMPORT_C static CSIPExtensionHeader* 
			NewLC(const TDesC8& aName, const TDesC8& aValue);

		/**
		* Destructor, deletes the resources of CSIPExtensionHeader.
		*/
		IMPORT_C ~CSIPExtensionHeader();


	public: // New functions

		/**
		* Sets the header value
		* @param aValue the header value to be set
		*/
		IMPORT_C void SetValueL(const TDesC8& aValue);

		/**
		* Gets the header value
		* @return the header value
		*/
		IMPORT_C const TDesC8& Value() const;

		/**
		* Constructs an instance of a CSIPExtensionHeader from a RReadStream
		* @param aReadStream a stream containing the value of the
		*        externalized header object (header name not included).
		* @return an instance of a CSIPExtensionHeader
		*/

		IMPORT_C static CSIPExtensionHeader* 
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

		/**
		* From CSIPHeaderBase ToTextValueL
		*/
		IMPORT_C HBufC8* ToTextValueL() const;

		/**
		* From CSIPHeaderBase ExternalizeSupported
		*/
		IMPORT_C TBool ExternalizeSupported() const;


	public: // New functions, for internal use

		void SetNameL(const TDesC8& aName);

	public: // From CSIPHeaderBase, for internal use

        /**
        * @internalComponent
        */	
		TBool IsExtensionHeader() const;
		
        /**
        * @internalComponent
        */		
		TBool EncodeMultipleToOneLine() const;
		
        /**
        * @internalComponent
        */		
		TBool MoreThanOneAllowed() const;
		
        /**
        * @internalComponent
        */		
		TBool HasCompactName() const;
		
        /**
        * @internalComponent
        */		
		RStringF CompactName() const;
		
        /**
        * @internalComponent
        */		
		TPreferredPlace PreferredPlaceInMessage() const;

	private: // From CSIPHeaderBase

		void ExternalizeValueL(RWriteStream& aWriteStream) const;

	private: // Constructors

		CSIPExtensionHeader();
		void ConstructL(const TDesC8& aName, const TDesC8& aValue);
		void ConstructL(const CSIPExtensionHeader& aExtensionHeader);
		void DoInternalizeValueL(RReadStream& aReadStream);

	private: // New functions

		TBool CheckValue (const TDesC8& aValue);
	
	private: // Data

		// data
		RStringF iName;
		HBufC8* iValue;

	private: // For testing purposes
	
		UNIT_TEST(CSIPExtensionHeaderTest)
		UNIT_TEST(CSIPHeaderLookupTest)
	};

#endif // CSIPEXTENSIONHEADER_H

// End of File
