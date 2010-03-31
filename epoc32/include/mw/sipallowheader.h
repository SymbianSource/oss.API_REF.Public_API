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
* Name        : sipallowheader.h
* Part of     : SIP Codec
* Interface   : SDK API, SIP Codec API
* Version     : SIP/4.0 
*
*/




#ifndef CSIPALLOWHEADER_H
#define CSIPALLOWHEADER_H

//  INCLUDES
#include "siptokenheaderbase.h"

// CLASS DECLARATION
/**
* @publishedAll
* @released
*
* Class provides functions for setting and getting parameters 
* in SIP "Allow" header.
*
*  @lib sipcodec.lib
*/
class CSIPAllowHeader : public CSIPTokenHeaderBase
	{
	public:	// Constructors and destructor

		/**
		* Constructs a CSIPAllowHeader from textual representation 
		* of the header's value part.
		* @param aValue a value part of a "Allow"-header
		* @return an array containing one to many instances of CSIPAllowHeader
		*/
		IMPORT_C static RPointerArray<CSIPAllowHeader> 
			DecodeL(const TDesC8& aValue);

		/**
		* Creates a new instance of CSIPAllowHeader
		* @param aValue a value 
		* @return a new instance of CSIPAllowHeader
		*/
		IMPORT_C static CSIPAllowHeader* NewL(RStringF aValue);

		/**
		* Creates a new instance of CSIPAllowHeader and puts it to CleanupStack
		* @param aValue a value   
		* @return a new instance of CSIPAllowHeader
		*/
		IMPORT_C static CSIPAllowHeader* NewLC(RStringF aValue);

		/**
		* Destructor, deletes the resources of CSIPAllowHeader.
		*/
		IMPORT_C ~CSIPAllowHeader();


	public: // New functions

		/**
		* Constructs an instance of a CSIPAllowHeader from a RReadStream
		* @param aReadStream a stream containing the value of the
		*        externalized object (header name not included). 
		* @return an instance of a CSIPAllowHeader
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

	private: // Constructors

		CSIPAllowHeader();
		CSIPAllowHeader(const CSIPAllowHeader& aHeader);
	};

#endif // CSIPALLOWHEADER_H

// End of File
