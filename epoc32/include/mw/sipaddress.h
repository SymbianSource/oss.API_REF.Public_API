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
* Name        : sipaddress.h
* Part of     : SIP Codec
* Interface   : SDK API, SIP Codec API
* Version     : SIP/4.0 
*
*/




#ifndef CSIPADDRESS_H
#define CSIPADDRESS_H

//  INCLUDES
#include <e32base.h>
#include <s32mem.h>
#include <uri8.h>
#include "_sipcodecdefs.h"

// FORWARD DECLARATIONS
class CURIContainer;

// CLASS DECLARATION
/**
* @publishedAll
* @released
*
* Class provides functions for setting and getting parameters in SIP 
* name-addr structure
*
* @lib sipcodec.lib
*/
class CSIPAddress : public CBase
	{
	public:	// Constructors and destructor

		/**
		* Constructs a CSIPAddress from textual representation 
		* @param aValue SIP name-addr as text
		* @return a new instance of CSIPAddress
		*/
		IMPORT_C static CSIPAddress* DecodeL(const TDesC8& aValue);

		/**
		* Creates a new instance of CSIPAddress
		* @pre aUri != 0
		* @param aUri the ownership is transferred.
		* @return a new instance of CSIPAddress
		*/
		IMPORT_C static CSIPAddress* NewL(CUri8* aUri8);

		/**
		* Creates a new instance of CSIPAddress and puts it to CleanupStack
		* @pre aUri != 0 
		* @param aUri the ownership is transferred.
		* @return a new instance of CSIPAddress
		*/
		IMPORT_C static CSIPAddress* NewLC(CUri8* aUri8);

		/**
		* Creates a new instance of CSIPAddress
		* @pre aUri != 0
		* @param aDisplayName a SIP token or a SIP quoted-string
		* @param aUri the ownership is transferred.
		* @return a new instance of CSIPAddress
		*/
		IMPORT_C static CSIPAddress* NewL(const TDesC8& aDisplayName, 
		                                  CUri8* aUri8);

		/**
		* Creates a new instance of CSIPAddress and puts it to CleanupStack
		* @pre aUri != 0
		* @param aDisplayName a SIP token or a SIP quoted-string
		* @param aUri the ownership is transferred.
		* @return a new instance of CSIPAddress
		*/
		IMPORT_C static CSIPAddress* NewLC(const TDesC8& aDisplayName,
									       CUri8* aUri8);

		/**
		* Creates a deep-copy of a CSIPAddress
		* @param aSIPAddress the address to be copied
		* @return a new instance of CSIPAddress
		*/
		IMPORT_C static CSIPAddress* NewL(const CSIPAddress& aSIPAddress);

		/**
		* Creates a deep-copy of a CSIPAddress and puts it to CleanupStack
		* @param aSIPAddress the address to be copied
		* @return a new instance of CSIPAddress
		*/
		IMPORT_C static CSIPAddress* NewLC(const CSIPAddress& aSIPAddress);

		/**
		* Destructor, deletes the resources of CSIPAddress.
		*/
		IMPORT_C ~CSIPAddress();


	public: // New functions

		/**
		* Compares this object to another instance of CSIPAddress
		* @param aSIPAddress a CSIPAddress to compare to
		* @return ETrue if the objects are equal otherwise EFalse
		*/
		IMPORT_C TBool operator==(const CSIPAddress& aSIPAddress) const;
	
		/**
		* Gets the display name
		* @return the display name if present, 
		* 		   otherwise a zero-length descriptor 
		*/
		IMPORT_C const TDesC8& DisplayName() const;
	
		/**
		* Sets the display name
		* @param aDisplayName a SIP token or a SIP quoted-string
		*/
		IMPORT_C void SetDisplayNameL(const TDesC8& aDisplayName);

		/**
		* Gets the URI part of the address as const
		* @return a reference to the URI object
		*/
		IMPORT_C const CUri8& Uri8() const;
	
		/**
		* Sets the URI part of the address
		* @pre aUri!= 0
		* @param aUri a pointer to the URI object, the ownership is transferred
		*/
		IMPORT_C void SetUri8L(CUri8* aUri8);

		/**
		* Creates a textual representation and pushes it to CleanupStack
		* @param aUseAngleBrackets if ETrue, sets the anglebrackets
		* @return a textual representation of the object,
		*          the ownership is transferred
		*/
		IMPORT_C HBufC8* ToTextLC(TBool aUseAngleBrackets=EFalse) const;

		/**
		* Constructs an instance of a CSIPAddress from a RReadStream
		* @param aReadStream a stream containing the externalized object
		* @return an instance of a CSIPAddress
		*/
		IMPORT_C static CSIPAddress* InternalizeL(RReadStream& aReadStream);
	
		/**
		* Writes the object to a RWriteStream
		* @param aWriteStream a stream where the object is to be externalized
		*/
		IMPORT_C void ExternalizeL(RWriteStream& aWriteStream);


	public: // For internal use:

		IMPORT_C CURIContainer& URI();
		IMPORT_C const CURIContainer& URI() const;
		static CSIPAddress* NewLC(CURIContainer* aURI);
		

	private: // Constructors
	
		CSIPAddress();
		void ConstructL();
		void ConstructL(CUri8* aUri);
		void ConstructL(const TDesC8& aDisplayName, CUri8* aUri);
		void ConstructL(const CSIPAddress& aSIPAddress);
		void ConstructL(CURIContainer* aURI);

	private: // New functions

		void DoInternalizeL(RReadStream& aReadStream);
		TInt QuotedStringLength(const TDesC8& aValue);
		TBool CheckDisplayName(const TDesC8& aValue);
		void ParseURIInAngleBracketsL(const TDesC8& aValue);
		void ParseURIL(const TDesC8& aValue);
		TBool ContainsSeparators(const TDesC8& aValue) const;
		TBool HasDisplayName() const;

	private: // Data

		HBufC8* iDisplayName;
		CURIContainer* iURI;

	private: // For testing purposes
	
		UNIT_TEST(CSIPAddressTest)
    };

#endif // end of __SIP_ADDRESS_H__

// End of File
