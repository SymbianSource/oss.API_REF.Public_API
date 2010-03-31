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
* Name        : sipeventheader.h
* Part of     : SIP Codec
* Interface   : SDK API, SIP Codec API
* Version     : SIP/4.0 
*
*/




#ifndef CSIPEVENTHEADER_H
#define CSIPEVENTHEADER_H

//  INCLUDES
#include <bamdesca.h>
#include <badesca.h>
#include "sipparameterheaderbase.h"

// FORWARD DECLARATIONS
class CSIPEventHeaderParams;

// CLASS DECLARATION
/**
* @publishedAll
* @released
*
* Class provides functions for setting and getting parameters in 
* SIP "Event" header.
*
*  @lib sipcodec.lib
*/
class CSIPEventHeader : public CSIPParameterHeaderBase
	{
	public:	// Constructors and destructor
	
		/**
		* Constructs a CSIPEventHeader from textual representation 
		* of the header's value part.
		* @param aValue a value part of a "Event"-header
		* @return a new instance of CSIPEventHeader
		*/
		IMPORT_C static CSIPEventHeader* DecodeL(const TDesC8& aValue);

		/**
		* Creates a new instance of CSIPEventHeader
		* @param aEventPackage a Event-Package value
		* @return a new instance of CSIPEventHeader
		*/
		IMPORT_C static CSIPEventHeader* NewL(const TDesC8& aEventPackage);

		/**
		* Creates a new instance of CSIPEventHeader and puts it to CleanupStack
		* @param aEventPackage a Event-Package value
		* @return a new instance of CSIPEventHeader
		*/

		IMPORT_C static CSIPEventHeader* NewLC(const TDesC8& aEventPackage);

		/**
		* Destructor, deletes the resources of CSIPEventHeader.
		*/
		IMPORT_C ~CSIPEventHeader();


	public:	// New functions

		/**
		* Compares this instance to another CSIPEventHeader instance
		* @param aHeader a header to compare to
		* @return ETrue if the objects are equal otherwise EFalse
		*/
		IMPORT_C TBool operator==(const CSIPEventHeader& aHeader) const;

		/**
		* Gets the Event-Package parameter from the "Event" header
		* @return the Event-Package parameter
		*/
		IMPORT_C const TDesC8& EventPackage() const;

		/**
		* Sets the Event-Package parameter in the "Event" header; 
		* @param aEventPackage a Event-Package parameter to set
		*/
		IMPORT_C void SetEventPackageL(const TDesC8& aEventPackage);

		/**
		* Sets the event templates overwriting all the existing ones.
		* @param aEventTemplates an array of event templates
		*/
		IMPORT_C void SetEventTemplatesL(const MDesC8Array& aEventTemplates);

		/**
		* Gets the event templates.
		* @return a reference to the currently set event templates.
		*/
		IMPORT_C const MDesC8Array& EventTemplates() const;
	
		/**
		* Constructs an instance of a CSIPEventHeader from a RReadStream
		* @param aReadStream a stream containing the value of the
		*        externalized object (header name not included).
		* @return an instance of a CSIPEventHeader 
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

		CSIPEventHeader();
		void ConstructL();
		void ConstructL(const TDesC8& aEventPackage);
		void ConstructL(const CSIPEventHeader& aSIPEventHeader);

	private: // New functions

		void DoInternalizeValueL(RReadStream& aReadStream);
		void CheckTemplateL(const TDesC8& aParam) const;
		// Needed for cleanup of a RPointerArray<HBufC8>:
		static void ResetAndDestroy(TAny* anArray);

	private: // Data

		HBufC8* iEventPackage;
		CSIPEventHeaderParams* iParams;
		CDesC8ArraySeg* iEventTemplates;

	private: // For testing purposes
#ifdef CPPUNIT_TEST	
		friend class CSIPEventHeaderTest;
#endif
	};

#endif // CSIPEVENTHEADER_H

// End of File
