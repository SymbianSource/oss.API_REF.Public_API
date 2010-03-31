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
* Name        : sipheaderbase.h
* Part of     : SIP Codec
* Interface   : SDK API, SIP Codec API
* Version     : SIP/4.0 
*
*/




#ifndef CSIPHEADERBASE_H
#define CSIPHEADERBASE_H

//  INCLUDES
#include <e32base.h>
#include <s32mem.h>
#include <stringpool.h>

// CLASS DECLARATION
/**
* @publishedAll
* @released
*
* Class provides a generic interface for all the SIP headers.
*
*  @lib sipcodec.lib
*/
class CSIPHeaderBase : public CBase
	{
	public: // Constructors and destructors

		/**
		* Destructor, deletes the resources of CSIPHeaderBase.
		*/
		IMPORT_C virtual ~CSIPHeaderBase();

	
	public: // New functions
	
		/**
		* Creates a deep-copy of this CSIPHeaderBase object. 
		* The function has to be implemented in each of the sub-classes.
		* @return the deep-copied object, the ownership is transferred.
		*/
		IMPORT_C virtual CSIPHeaderBase* CloneL() const = 0;

		/**
		* Gets the full name of the header
		* The function is implemented in each of the sub-classes.
		* @return the full name of the header for example "From"
		*/
		IMPORT_C virtual RStringF Name() const = 0;

		/**
		* Encodes the header (name and value) into its textual representation.
		* @return a textual representation of the complete header,
		*         the ownership is transferred
		*/
		IMPORT_C HBufC8* ToTextL() const;

		/**
		* Encodes the header (name and value) into its textual representation
		* and pushes it to the CleanupStack.
		* @return a textual representation of the complete header,
		*         the ownership is transferred
		*/
		IMPORT_C HBufC8* ToTextLC() const;

		/**
		* Encodes the header's value into its textual representation.
		* @return a textual representation of the header's value,
		*         the ownership is transferred
		*/
		IMPORT_C virtual HBufC8* ToTextValueL() const = 0;

		/**
		* Encodes the header's value into its textual representation
		* and pushes it to the CleanupStack.
		* @return a textual representation of the header's value,
		*         the ownership is transferred
		*/
		IMPORT_C HBufC8* ToTextValueLC() const;

		/**
		* Writes the object to a RWriteStream
		* @param aWriteStream a stream where the object is to be externalized
		* @param aAddName if ETrue the name of the header is 
		*        also written to the stream
		*/
		IMPORT_C void ExternalizeL(RWriteStream& aWriteStream,
                                   TBool aAddName=ETrue) const;

		/**
		* Checks, if the header supports serialization.
		* In practice all the headers part of the API support it.
		* @return ETrue, if the header supports serialization, 
		*         otherwise EFalse
		*/
		IMPORT_C virtual TBool ExternalizeSupported() const;

		/**
		* Can be used when a RPointerArray<CSIPHeaderBase> needs to be pushed
		* to the CleanupStack for ResetAndDestroy.
		* @param aArray an array of CSIPHeaderBase pointers, 
		*        the ownership of the array is transferred
		*/
		IMPORT_C static void PushLC(RPointerArray<CSIPHeaderBase>* aArray);


	public: // For internal use

        /**
        * @internalComponent
        */
		enum TPreferredPlace
			{
			ETop,
			EMiddleTop,
			EMiddle,
			EMiddleBottom,
			EBottom
			};

        /**
        * @internalComponent
        */	
		TSglQueLink iLink;

        /**
        * @internalComponent
        */
		virtual TBool EncodeMultipleToOneLine() const;
		
        /**
        * @internalComponent
        */		
		virtual TBool MoreThanOneAllowed() const;
		
        /**
        * @internalComponent
        */		
		virtual TBool IsExtensionHeader() const;
		
        /**
        * @internalComponent
        */		
		virtual TBool HasCompactName() const;
		
        /**
        * @internalComponent
        */		
		virtual RStringF CompactName() const;
		
        /**
        * @internalComponent
        */		
		virtual TPreferredPlace PreferredPlaceInMessage() const = 0;

	protected: // Constructors

		CSIPHeaderBase();

	protected: // New functions

		void ExternalizeNameL(RWriteStream& aWriteStream) const;
		
        /**
        * @internalComponent
        */		
		virtual void ExternalizeValueL(RWriteStream& aWriteStream) const;
		
		// Needed for cleanup of a RPointerArray<CSIPHeaderBase>:
		static void ResetAndDestroy(TAny* anArray);
	};

#endif // CSIPHEADERBASE_H

// End of File
