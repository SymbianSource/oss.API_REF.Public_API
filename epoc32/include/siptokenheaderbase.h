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
* Name        : siptokenheaderbase.h
* Part of     : SIP Codec
* Interface   : SDK API, SIP Codec API
* Version     : SIP/4.0 
*
*/




#ifndef CSIPTOKENHEADERBASE_H
#define CSIPTOKENHEADERBASE_H

//  INCLUDES
#include "sipheaderbase.h"
#include "_sipcodecdefs.h"

// CLASS DECLARATION
/**
* @publishedAll
* @released
*
* A base class for SIP headers having form "Name: token *(COMMA token)"
*
* @lib sipcodec.lib
*/
class CSIPTokenHeaderBase : public CSIPHeaderBase
	{
	public:	// Constructors and destructor

		/**
		* Destructor, deletes the resources of CSIPTokenHeaderBase.
		*/
		IMPORT_C virtual ~CSIPTokenHeaderBase();


	public: // New functions

		/**
		* Sets the header value as a token 
		* @param aValue a value to set
		*/
		IMPORT_C void SetValueL(RStringF aValue);
	
		/**
		* Gets the header value as a token 
		* @return the header value
		*/
		IMPORT_C RStringF Value() const;


	public: // From CSIPHeaderBase

		/**
		* From CSIPHeaderBase ToTextValueL
		*/
		IMPORT_C HBufC8* ToTextValueL() const;


	public: // From CSIPHeaderBase, for internal use

        /**
        * @internalComponent
        */
		virtual TBool MoreThanOneAllowed() const;

	protected: // Constructors

		CSIPTokenHeaderBase();
	    CSIPTokenHeaderBase(const CSIPTokenHeaderBase& aHeader);
		void ConstructL(const TDesC8& aValue, TBool aEmptyValueAllowed=EFalse);
		void ConstructL(RStringF aValue, TBool aEmptyValueAllowed=EFalse);
		
	protected: // New functions		
		
		void DoInternalizeValueL(RReadStream& aReadStream);

	protected: // Data	
	
        /**
        * @internalComponent
        */	
		RStringF iValue;

	private: // From CSIPHeaderBase

		void ExternalizeValueL(RWriteStream& aWriteStream) const;

	private: // New functions

		void SetValueL(const TDesC8& aValue);	

	private: // For testing purposes
	
		UNIT_TEST(CSIPTokenHeaderBaseTest)
	};

#endif // CSIPTOKENHEADERBASE_H

// End of File
