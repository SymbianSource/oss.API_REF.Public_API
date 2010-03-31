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
* Name        : sipunsignedintheaderbase.h
* Part of     : SIP Codec
* Interface   : SDK API, SIP Codec API
* Version     : SIP/4.0 
*
*/




#ifndef CSIPUNSIGNEDINTHEADERBASE_H
#define CSIPUNSIGNEDINTHEADERBASE_H

//  INCLUDES
#include "sipheaderbase.h"
#include "_sipcodecdefs.h"


// CLASS DECLARATION
/**
* @publishedAll
* @released
*
* A base class for SIP headers having form: "Name: 1*DIGIT"
*
* @lib sipcodec.lib
*/
class CSIPUnsignedIntHeaderBase : public CSIPHeaderBase
	{
	public:	// Constructors and destructor

		/**
		* Destructor, deletes the resources of CSIPUnsignedIntHeaderBase.
		*/
		IMPORT_C virtual ~CSIPUnsignedIntHeaderBase();


	public: // New functions

		/**
		* Sets the header value as an unsigned integer 
		* @param aValue a value to set
		*/
		IMPORT_C void SetValue(TUint aValue);
	
		/**
		* Gets the header value as an unsigned integer 
		* @return the header value
		*/
		IMPORT_C TUint Value() const;


	public: // From CSIPHeaderBase

		/**
		* From CSIPHeaderBase ToTextValueL
		*/
		IMPORT_C HBufC8* ToTextValueL() const;


	protected: // Constructors

		CSIPUnsignedIntHeaderBase();
		CSIPUnsignedIntHeaderBase(TUint aValue);

	protected: // New functions

		void ParseL(const TDesC8& aValue, TInt aErrorIfParsingFails);
		void DoInternalizeValueL(RReadStream& aReadStream);

	protected: // From CSIPHeaderBase

        /**
        * @internalComponent
        */
		void ExternalizeValueL (RWriteStream& aWriteStream) const;

	protected: // Data

        /**
        * @internalComponent
        */	
		TUint iValue;
	};

#endif // CSIPUNSIGNEDINTHEADERBASE_H

// End of File
