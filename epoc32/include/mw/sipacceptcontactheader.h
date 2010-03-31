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
* Name        : sipacceptcontactheader.h
* Part of     : SIP Codec
* Interface   : SDK API, SIP Codec API
* Version     : SIP/4.0 
*
*/




#ifndef CSIPACCEPTCONTACTHEADER_H
#define CSIPACCEPTCONTACTHEADER_H

//  INCLUDES
#include "sipparameterheaderbase.h"

// FORWARD DECLARATIONS
class CSIPAcceptContactHeaderParams;

// CLASS DECLARATION
/**
* @publishedAll
* @released
*
* Class provides functions for setting and getting parameters in SIP 
* "Accept-Contact" header.
*
*  @lib sipcodec.lib
*/
class CSIPAcceptContactHeader : public CSIPParameterHeaderBase
	{
	public:	// Constructors and destructor

		/**
		* Constructs a CSIPAcceptContactHeader from textual representation 
		* of the header's value part.
		* @param aValue a value part of a "Accept-Contact"-header 
		*        (e.g. "*;param=value")
		* @return an array containing one to many instances 
        *         of CSIPAcceptContactHeader   
		*/
		IMPORT_C static RPointerArray<CSIPAcceptContactHeader>
            DecodeL(const TDesC8& aValue);

		/**
		* Creates a new instance of CSIPAcceptContactHeader
		* @return a new instance of CSIPAcceptContactHeader
		*/
        IMPORT_C static CSIPAcceptContactHeader* NewL();

		/**
		* Creates a new instance of CSIPAcceptContactHeader
        * On return the new instance has left to the CleanupStack.
		* @return a new instance of CSIPAcceptContactHeader
		*/
        IMPORT_C static CSIPAcceptContactHeader* NewLC();

        /**
		* Destructor, deletes the resources of CSIPAcceptContactHeader.
		*/
		IMPORT_C virtual ~CSIPAcceptContactHeader();


	public: // New functions

		/**
		* Compares this instance to another "Accept-Contact" header object.
		* Two Accept-Contact-headers are equal, 
		* if both contain exactly the same parameters. 
		* The order of the parameters is not sufficient.
		* @param aHeader a header to compare to
		* @return ETrue, if the objects are equal otherwise EFalse
		*/
		IMPORT_C TBool operator==(const CSIPAcceptContactHeader& aHeader) const;

        /**
		* Constructs an instance of a CSIPAcceptContactHeader from a RReadStream
		* @param aReadStream a stream containing the value of the
		*        externalized object (header name not included). 
		* @return an instance of a CSIPAcceptContactHeader
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
        TBool HasCompactName() const;
        
        /**
		* @internalComponent
		*/        
        RStringF CompactName() const;
        
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

        CSIPAcceptContactHeader();
        void ConstructL();
		void ConstructL(const CSIPAcceptContactHeader& aAcceptContactHeader);

	private: // New functions

		void DoInternalizeValueL(RReadStream& aReadStream);

	private: // Data

		CSIPAcceptContactHeaderParams* iParams;

	private: // For testing purposes
#ifdef CPPUNIT_TEST	
		friend class CSIPAcceptContactHeaderTest;
#endif
	};

#endif // CSIPACCEPTCONTACTHEADER_H

// End of File
