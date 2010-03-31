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
* Name        : siprackheader.h
* Part of     : SIP Codec
* Interface   : SDK API, SIP Codec API
* Version     : SIP/4.0 
*
*/




#ifndef CSIPRACKHEADER_H
#define CSIPRACKHEADER_H

//  INCLUDES
#include "sipheaderbase.h"

// CLASS DECLARATION
/**
* @publishedAll
* @released
*
* Class provides functions for setting and getting sequence number and
* method in SIP "RAck"-header.
*
*  @lib sipcodec.lib
*/
class CSIPRAckHeader : public CSIPHeaderBase
	{
	public: // Constructors and destructor

		/**
		* Constructs a CSIPRAckHeader from textual representation 
		* of the header's value part.
		* @param aValue a value part of a "RAck"-header (e.g. "1 2 INVITE")
		* @return a new instance of CSIPRAckHeader.  
		*/
		IMPORT_C static CSIPRAckHeader* DecodeL(const TDesC8& aValue);

		/**
		* Creates a new instance of CSIPRAckHeader
		* @param aSeq a sequence number to set
        * @param aCSeqNum a sequence number from CSeq-header
		* @param aMethod a method to set. For example "REGISTER"
		* @return a new instance of CSIPRAckHeader
		*/
		IMPORT_C static CSIPRAckHeader* NewL(TUint aSeq,
                                             TUint aCSeqNum,
                                             RStringF aMethod);


		/**
		* Creates a new instance of CSIPRAckHeader and puts it to CleanupStack
		* @param aSeq a sequence number to set
        * @param aCSeqNum a sequence number from CSeq-header
		* @param aMethod a method to set. For example "REGISTER"
		* @return a new instance of CSIPRAckHeader
		*/
		IMPORT_C static CSIPRAckHeader* NewLC(TUint aSeq,
                                              TUint aCSeqNum,
                                              RStringF aMethod);

		/**
		* Destructor, deletes the resources of CSIPRAckHeader.
		*/
		IMPORT_C ~CSIPRAckHeader();


	public: // New functions

		/**
		* Gets the sequence number from the "RAck" header
		* @return the current sequence number
		*/
		IMPORT_C TUint Seq() const;

		/**
		* Sets the sequence number in the "RAck" header
		* @param aSeq a sequence number to set
		*/
		IMPORT_C void SetSeq(TUint aSeq);

		/**
		* Gets the sequence number from the "RAck" header
		* @return the current sequence number
		*/
		IMPORT_C TUint CSeqNum() const;

		/**
		* Sets the sequence number in the "RAck" header
		* @param aCSeqNum a sequence number to set
		*/
		IMPORT_C void SetCSeqNum(TUint aCSeqNum);

		/**
		* Gets the method from the "RAck" header
		* @return the method 
		*/
		IMPORT_C RStringF Method() const;

		/**
		* Sets the method in the "RAck" header
		* @param aMethod a method to set
		*/
		IMPORT_C void SetMethodL(RStringF aMethod);

		/**
		* Constructs an instance of a CSIPRAckHeader from a RReadStream
		* @param aReadStream a stream containing the value of the
		*	     externalized object (header name not included). 
		* @return an instance of a CSIPRAckHeader
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

	private: // Constructors

        CSIPRAckHeader();
		CSIPRAckHeader(TUint aSeq, TUint aCSeqNum);
		void ConstructL(RStringF aMethod);
		void ConstructL(const CSIPRAckHeader& aRAckHeader);
	
	private: // New functions
		
		void DoInternalizeValueL(RReadStream& aReadStream);
		void ParseL(const TDesC8& aValue);
		void SetMethodL(const TDesC8& aMethod);

	private: // Data

		TUint iSeq;
        TUint iCSeqNum;
		RStringF iMethod;

	private: // For testing purposes
#ifdef CPPUNIT_TEST	
		friend class CSIPRAckHeaderTest;
#endif
	};

#endif // CSIPRACKHEADER_H

// End of File
