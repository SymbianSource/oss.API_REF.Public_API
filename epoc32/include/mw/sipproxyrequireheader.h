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
* Name        : sipproxyrequireheader.h
* Part of     : SIP Codec
* Interface   : SDK API, SIP Codec API
* Version     : SIP/4.0 
*
*/




#ifndef CSIPPROXYREQUIREHEADER_H
#define CSIPPROXYREQUIREHEADER_H

//  INCLUDES
#include "siptokenheaderbase.h"

// CLASS DECLARATION
/**
* @publishedAll
* @released
*
* Class provides functions for setting and getting parameters in 
* SIP "Proxy-Require" header.
*
*  @lib sipcodec.lib
*/
class CSIPProxyRequireHeader : public CSIPTokenHeaderBase
	{
	public:	// Constructors and destructor

		/**
		* Constructs a CSIPProxyRequireHeader from textual representation 
		* of the header's value part.
		* @param aValue a value part of a "Proxy-Require"-header
		* @return an array containing 1..n instances of CSIPProxyRequireHeader   
		*/
		IMPORT_C static RPointerArray<CSIPProxyRequireHeader> 
			DecodeL(const TDesC8& aValue);

		/**
		* Creates a new instance of CSIPProxyRequireHeader
		* @param aValue a tag value 
		* @return a new instance of CSIPProxyRequireHeader
		*/
		IMPORT_C static CSIPProxyRequireHeader* NewL(RStringF aValue);

		/**
		* Creates a new instance of CSIPProxyRequireHeader 
		* and puts it to CleanupStack
		* @param aValue a tag value   
		* @return a new instance of CSIPProxyRequireHeader 
		*/
		IMPORT_C static CSIPProxyRequireHeader* NewLC(RStringF aValue);

		/**
		* Destructor, deletes the resources of CSIPProxyRequireHeader.
		*/
		IMPORT_C ~CSIPProxyRequireHeader();


	public: // New functions

		/**
		* Constructs an instance of a CSIPProxyRequireHeader from a RReadStream
		* @param aReadStream a stream containing the value of the
		*        externalized object (header name not included).
		* @return an instance of a CSIPProxyRequireHeader 
		*/
		IMPORT_C static CSIPHeaderBase* InternalizeValueL(RReadStream& aReadStream);


	public: // From CSIPHeaderBase

		/**
		* From CSIPHeaderBase CloneL
		*/
		IMPORT_C CSIPHeaderBase* CloneL() const;

		/**
		* From CSIPHeaderBase Name
		*/
		IMPORT_C RStringF Name() const;


	public: // From CSIPHeaderBase, For internal use
	
        /**
        * @internalComponent
        */	
		TPreferredPlace PreferredPlaceInMessage() const;

	public: // New functions, for internal use

		static RPointerArray<CSIPHeaderBase> BaseDecodeL(const TDesC8& aValue);

	private: // Constructors

		CSIPProxyRequireHeader();
		CSIPProxyRequireHeader(const CSIPProxyRequireHeader& aHeader);
	};

#endif // end of CSIPPROXYREQUIREHEADER_H

// End of File
