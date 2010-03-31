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
* Name          : siptimestampheader.h
* Part of       : SIP Codec
* Version       : SIP/4.0 
*
*/




#ifndef CSIPTIMESTAMPHEADER_H
#define CSIPTIMESTAMPHEADER_H

//  INCLUDES
#include "sipheaderbase.h"
#include "_sipcodecdefs.h"

// CLASS DECLARATION
/**
* @publishedAll
* @released
*
* Class for a SIP Timestamp header.
*
* @lib sipcodec.lib
*/
class CSIPTimestampHeader : public CSIPHeaderBase
	{
	public:	// Constructors and destructor

		/**
		* Constructs a CSIPTimestampHeader from textual representation 
		* of the header's value part.
		* @param aValue a value part of a "Timestamp"-header (e.g. "12 3.4")
		* @returns a new instance of CSIPTimestampHeader
		*/
		IMPORT_C static CSIPTimestampHeader* DecodeL(const TDesC8& aValue);

        /**
		* Constructor
        * @param aTimestamp a timestamp value to set.
        * @param aDealy a delay value to set.
		*/
		IMPORT_C CSIPTimestampHeader(TReal aTimestamp);

        /**
		* Destructor
		*/
		IMPORT_C ~CSIPTimestampHeader ();


	public: // New functions

        /**
        * Set the timestamp from the "Timestamp" header.
        * @param aTimestamp a timestamp to set.
        */
        IMPORT_C void SetTimestamp(TReal aTimestamp);

        /**
        * Gets the timestamp from the "Timestamp" header.
        * @return a timestamp value.
        */
        IMPORT_C TReal Timestamp() const;

        /**
        * Check if the delay-part is present
        * @return a delay value.
        */
        IMPORT_C TBool HasDelay() const;

        /**
        * Set the delay-part of the "Timestamp" header.
        * @param aDelay a delay to set.
        */
        IMPORT_C void SetDelay(TReal aDelay);

        /**
        * Gets the delay-part of the "Timestamp" header, 
        * if delay-part is present
        * @return a delay value or zero if HasDelay() == EFalse
        */
        IMPORT_C TReal Delay() const;

		/**
		* Constructs an instance of a CSIPTimestampHeader from a RReadStream
		* @param aReadStream a stream containing the value of the
		*	     externalized object (header name not included). 
		* @return an instance of a CSIPTimestampHeader
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


	public: // From CSIPHeaderBase, for internal use

        /**
        * @internalComponent
        */	
		TPreferredPlace PreferredPlaceInMessage() const;

	public: // New functions, for internal use

		static RPointerArray<CSIPHeaderBase> BaseDecodeL(const TDesC8& aValue);

	private: // From CSIPHeaderBase

		void ExternalizeValueL (RWriteStream& aWriteStream) const;

	private: // New functions

		void ParseL(const TDesC8& aValue);
        void DoInternalizeValueL(RReadStream& aReadStream);

	private: // Data

		TReal iTimestamp;
        TBool iHasDelay;
        TReal iDelay;

	private: // For testing purposes
	
		UNIT_TEST(CSIPTimestampHeaderTest)
	};


#endif // end of CSIPTIMESTAMPHEADER_H

// End of File
