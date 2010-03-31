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
* Name        : sipalloweventsheader.h
* Part of     : SIP Codec
* Interface   : SDK API, SIP Codec API
* Version     : SIP/4.0 
*
*/




#ifndef CSIPALLOWEVENTSHEADER_H
#define CSIPALLOWEVENTSHEADER_H

//  INCLUDES
#include <badesca.h>
#include "sipheaderbase.h"
#include "_sipcodecdefs.h"

// CLASS DECLARATION
/**
* @publishedAll
* @released
*
* Class provides functions for setting and getting parameters in 
* SIP "Allow-Events" header.
*
*  @lib sipcodec.lib
*/
class CSIPAllowEventsHeader : public CSIPHeaderBase
	{
	public: // Constructors and destructor
	
		/**
		* Constructs a CSIPAllowEventsHeader from textual representation 
		* of the header's value part.
		* @param aValue a value part of a "Allow-Events"-header
		* @return An array containing one to many instances of 
		*         CSIPAllowEventsHeader  
		*/
		IMPORT_C static RPointerArray<CSIPAllowEventsHeader> 
			DecodeL(const TDesC8& aValue);

		/**
		* Creates a new instance of CSIPAllowEventsHeader
		* @param aEventPackage a Event-Package value
		* @return a new instance of CSIPAllowEventsHeader
		*/
		IMPORT_C static CSIPAllowEventsHeader* 
			NewL(const TDesC8& aEventPackage);

		/**
		* Creates a new instance of CSIPAllowEventsHeader and 
		* puts it to CleanupStack
		* @param aEventPackage a Event-Package value
		* @return a new instance of CSIPAllowEventsHeader
		*/
		IMPORT_C static CSIPAllowEventsHeader* NewLC(const TDesC8& aEventPackage);

		/**
		* Destructor. deletes the resources of CSIPAllowEventsHeader.
		*/
		IMPORT_C ~CSIPAllowEventsHeader();

	public: // New functions

		/**
		* Gets the Event-Package parameter from the "Allow-Events" header
		* @return the Event-Package parameter
		*/
		IMPORT_C const TDesC8& EventPackage() const;

		/**
		* Sets the Event-Package parameter in the "Allow-Events" header; 
		* @param aEventPackage a Event-Package parameter to set
		*/
		IMPORT_C void SetEventPackageL(const TDesC8& aEventPackage);

		/**
		* Sets the event templates overwriting all the existing ones.
		* @param aEventTemplates
		*/
		IMPORT_C void SetEventTemplatesL(const MDesC8Array& aEventTemplates);
	
		/**
		* Gets the event templates.
		* @return a reference to the currently set event templates.
		*/

		IMPORT_C const MDesC8Array& EventTemplates() const;

		/**
		* Constructs an instance of a CSIPAllowEventsHeader from a RReadStream
		* @param aReadStream a stream containing the value of the
		*        externalized object (header name not included). 
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

		/**
		* From CSIPHeaderBase ToTextValueL
		*/
		IMPORT_C HBufC8* ToTextValueL() const;


	public: // New functions, for internal use

		static RPointerArray<CSIPHeaderBase> BaseDecodeL(const TDesC8& aValue);

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

	private: // From CSIPHeaderBase

		void ExternalizeValueL(RWriteStream& aWriteStream) const;

	private: // Contructors

		CSIPAllowEventsHeader();
		void ConstructL();
		void ConstructL(const TDesC8& aEventPackage);
		void ConstructL (const CSIPAllowEventsHeader& aSIPAllowEventsHeader);

	private: // New functions

		void DoInternalizeValueL(RReadStream& aReadStream);
		void ParseL(const TDesC8& aValue);
		void CheckTemplateL(const TDesC8& aParam) const;
		// Needed for cleanup of a RPointerArray<HBufC8>:
		static void ResetAndDestroy(TAny* anArray);

	private: // Data

		HBufC8* iEventPackage;
		CDesC8ArraySeg* iEventTemplates;

	private: // For testing purposes
	
		UNIT_TEST(CSIPAllowEventsHeaderTest)
	};

#endif // CSIPALLOWEVENTSHEADER_H

// End of File
