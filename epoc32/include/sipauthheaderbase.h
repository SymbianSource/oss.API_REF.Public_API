/*
* Copyright (c) 2006-2009 Nokia Corporation and/or its subsidiary(-ies).
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
* Name          : sipauthheaderbase.h
* Part of       : SIP Codec
* Version       : SIP/5.0 
*
*/



#ifndef CSIPAUTHHEADERBASE_H
#define CSIPAUTHHEADERBASE_H

//  INCLUDES
#include "sipheaderbase.h"
#include "_sipcodecdefs.h"

// FORWARD DECLARATIONS
class CSIPParamContainerBase;

// CLASS DECLARATION
/**
* @publishedAll
* @released
*
* A base class for SIP Authorization-, Proxy-Authenticate-, 
* Proxy-Authorization- and WWW-Authenticate-headers
*
* @lib sipcodec.lib
*/
class CSIPAuthHeaderBase : public CSIPHeaderBase
	{
	public: // Constructors and destructor

		/**
		* Destructor.
		*/
		IMPORT_C virtual ~CSIPAuthHeaderBase();


	public:	// New functions

		/**
		* @return the value of the auth-scheme
		*/
		IMPORT_C RStringF AuthScheme() const;

		/**
		* Checks if a parameter is present
		* @param aName the name of the parameter
		* @return ETrue if present, otherwise EFalse
		*/
		IMPORT_C TBool HasParam(RStringF aName) const;

		/**
		* Gets a parameter value
		* @pre HasParam(aName) == ETrue
		* @param aName the name of the parameter
		* @return the parameter value if present,
		*         otherwise a zero-length length value.
		*/
		IMPORT_C RStringF ParamValue(RStringF aName) const;

		/**
		* Gets a parameter value stored as a descriptor
		* @pre HasParam(aName) == ETrue
		* @param aName the name of the parameter
		* @return the parameter value if present,
		*         otherwise a zero-length length value.
		*/
		IMPORT_C const TDesC8& DesParamValue(RStringF aName) const;

		/**
		* Sets a parameter with a value. 
		* Takes copies of the name and value,
		* so if the RStringFs have been dynamically allocated,
		* they can be closed if necessary after the function returns.
		* @pre HasParam(aName) == EFalse
		* @param aName the name of the parameter
		* @param aValue the parameter value to set
		*/
		IMPORT_C void SetParamL(RStringF aName, RStringF aValue);

		/**
		* Sets a parameter with a value. 
		* Takes copies of the name 
		* so if the RStringF have been dynamically allocated,
		* they can be closed if necessary after the function returns.
		* Stores the parameter value as a descriptor, so that the 
		* case-sensitivity is not lost in RStringF-descriptor conversions. 
		* @pre HasParam(aName) == EFalse
		* @param aName the name of the parameter
		* @param aValue the parameter value to set
		*/
		IMPORT_C void SetDesParamL(RStringF aName, const TDesC8& aValue);

		/**
		* Sets a parameter with a value and adds double quotes 
		* as the first and the last character in the value.
		* Takes copy of the name,
		* so if the RStringF has been dynamically allocated,
		* it can be closed if necessary after the function returns.
		* @pre HasParam(aName) == EFalse
		* @param aName the name of the parameter
		* @param aValue the parameter value 
		*        to which the double quotes will be added
		*/
		IMPORT_C void SetParamAndAddQuotesL(RStringF aName,
			                                const TDesC8& aValue);

		/**
		* Deletes a parameter
		* @param aName the parameter name to delete
		*/
		IMPORT_C void DeleteParam(RStringF aName);


	public: // From CSIPHeaderBase

		/**
		* From CSIPHeaderBase ExternalizeSupported
		*/
		IMPORT_C virtual TBool ExternalizeSupported() const;


	public: // From CSIPHeaderBase, for internal use

		TBool EncodeMultipleToOneLine() const;
		TBool MoreThanOneAllowed() const;
		TPreferredPlace PreferredPlaceInMessage() const;
        virtual HBufC8* ToTextValueL() const;

	protected: // Constructors

		CSIPAuthHeaderBase();
		void ConstructL(RStringF aAuthScheme);

	protected: // New functions

		void SetAuthSchemeL(const TDesC8& aAuthScheme);
        void ParseL(const TDesC8& aValue);
        virtual const CSIPParamContainerBase& Params() const = 0;
        virtual CSIPParamContainerBase& Params() = 0;

	private: // Data

		RStringF iAuthScheme;
        TChar iSeparator;
	};

#endif // CSIPAUTHHEADERBASE_H

// End of File
