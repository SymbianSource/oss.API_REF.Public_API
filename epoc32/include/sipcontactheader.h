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
* Name        : sipcontactheader.h
* Part of     : SIP Codec
* Interface   : SDK API, SIP Codec API
* Version     : SIP/4.0 
*
*/




#ifndef CSIPCONTACTHEADER_H
#define CSIPCONTACTHEADER_H

//  INCLUDES
#include "sipparameterheaderbase.h"
#include "_sipcodecdefs.h"

// FORWARD DECLARATIONS
class CSIPAddress;
class CSIPContactHeaderParams;

// CLASS DECLARATION
/**
* @publishedAll
* @released
*
* Class provides functions for setting and getting SIP "Contact"
* header fields.
*
*  @lib sipcodec.lib
*/
class CSIPContactHeader : public CSIPParameterHeaderBase
	{
	public: // Constructors and destructor

		/**
		* Constructs a CSIPContactHeader from textual representation 
		* of the header's value part.
		* Note that "Contact: *" can be only created using this function.
		* @param aValue a value part of a "Contact"-header
		* @return an array containing 1..n instances of CSIPContactHeader
		*/
		IMPORT_C static RPointerArray<CSIPContactHeader> 
			DecodeL(const TDesC8& aValue);

		/**
		* Creates a new instance of CSIPContactHeader
		* @pre aSIPAddress != 0
		* @param aSIPAddress a name-address, the ownership is transferred 
		* @return a new instance of CSIPContactHeader
		*/
		IMPORT_C static CSIPContactHeader* NewL(CSIPAddress* aSIPAddress);

		/**
		* Creates a new instance of CSIPContactHeader and puts it to CleanupStack
		* @pre aSIPAddress != 0
		* @param aSIPAddress a name-address, the ownership is transferred 
		* @return a new instance of CSIPContactHeader
		*/
		IMPORT_C static CSIPContactHeader* NewLC(CSIPAddress* aSIPAddress);

		/**
		* Destructor, deletes the resources of CSIPContactHeader.
		*/
		IMPORT_C ~CSIPContactHeader();

	
	public: // New functions

		/**
		* Compares this object to another instance of CSIPContactHeader
		* @param aHeader a CSIPContactHeader header to compare to
		* @return ETrue if the objects are equal otherwise EFalse
		*/
		IMPORT_C TBool operator==(const CSIPContactHeader& aHeader) const;

		/**
		* Checks if the address is set to a STAR ("*")
		* @return ETrue, if the address is a "*" otherwise EFalse
		*/
		IMPORT_C TBool Star() const;

		/**
		* Gets the value of the "expires"-parameter
		* @return the "expires"-parameter, or 
		*         KErrNotFound if the parameter is not present.
		*/
		IMPORT_C TInt ExpiresParameter() const;

		/**
		* Sets the "expires"-parameter
		* @pre aExpiresParam >= 0
		* @param aExpiresParam a "expires"-parameter value to set
		*/
		IMPORT_C void SetExpiresParameterL(TInt aExpiresParam);

		/**
		* Gets the value of "q"-parameter
		* @pre Star() == EFalse
		* @return the "q"-parameter value, 
		*         or zero if the parameter is not present.
		*/
		IMPORT_C TReal QParameter() const;

		/**
		* Sets the "q"-parameter value in the "Contact" header
		* @pre Star() == EFalse
		* @param aQValue a "q"-parameter value to set
		*/
		IMPORT_C void SetQParameterL(TReal aQValue);

		/**
		* Gets the name-address as const
		* @return name-address or 0 if not present
		*         The ownership is NOT transferred.
		*/
		IMPORT_C const CSIPAddress* SIPAddress() const;

		/**
		* Gets the name-address
		* @return name-address or 0 if not present
		*         The ownership is NOT transferred.
		*/
		IMPORT_C CSIPAddress* SIPAddress();

		/**
		* Sets the name-address
		* @pre Star() == EFalse
		* @pre aSIPAddress != 0
		* @param aSIPAddress a name-address to set, the ownership is transferred
		*/
		IMPORT_C void SetSIPAddressL(CSIPAddress* aSIPAddress);

		/**
		* Constructs an instance of a CSIPContactHeader from a RReadStream
		* @param aReadStream a stream containing the value of the
		*        externalized object (header name not included). 
		* @return an instance of a CSIPContactHeader
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
		TBool HasCompactName() const;
		
        /**
        * @internalComponent
        */		
		RStringF CompactName() const;
		
        /**
        * @internalComponent
        */		
		TPreferredPlace PreferredPlaceInMessage() const;

	public: // New functions, for internal use

		static RPointerArray<CSIPHeaderBase> BaseDecodeL(const TDesC8& aValue);

	private: // From CSIPHeaderBase

		void ExternalizeValueL(RWriteStream& aWriteStream) const;

	private: // From CSIPParameterHeaderBase

		TBool ParamInsertionAllowed() const;
		HBufC8* ToTextMandatoryPartLC() const;
		void ParseMandatoryPartL(const TDesC8& aMandatoryPart);
		const CSIPParamContainerBase& Params() const;
		CSIPParamContainerBase& Params();

	private: // Constructors

		CSIPContactHeader(TBool aIsStar=EFalse);
		void ConstructL();
		void ConstructL(CSIPAddress* aSIPAddress);
		void ConstructL(const CSIPContactHeader& aContactHeader);

	private: // New functions 

		void DoInternalizeValueL(RReadStream& aReadStream);

	private: // Data

		CSIPAddress* iSIPAddress;
		CSIPContactHeaderParams* iParams;
		TBool iIsStar;

	private: // For testing purposes
	
		UNIT_TEST(CSIPContactHeaderTest)
	};

#endif // CSIPCONTACTHEADER_H

// End of File
