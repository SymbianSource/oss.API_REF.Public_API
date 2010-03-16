/*
* Copyright (c) 2002 Nokia Corporation and/or its subsidiary(-ies).
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
*      A class to convert Phonebook items to vCard stream and vice versa
*
*/


#ifndef __BCARDENG_H__
#define __BCARDENG_H__


// INCLUDES
#include <badesca.h>        // CDesCArrayFlat
#include "PbkFields.hrh"    // TPbkFieldId


// CONSTANTS
_LIT(KPbkvCardFileExtension, ".vcf");

// FORWARD DECLARATIONS
class CPbkContactEngine;
class CPbkContactItem;
class RWriteStream;
class CBCardFieldUidMapping;
class CBCardExportProperty;
class CParserVCard;

// CLASS DECLARATION

/**
 * The business card engine is able to import and export vCards and Compact 
 * Business Cards to and from Phonebook.
 */
class CBCardEngine : public CBase
	{
    public: // Constructors and destructor
        /**
         * Creates a new instance of this class.
		 * @param aEngine An open Phonebook Engine object which CBCardEngine
		 *        uses to import and export vCard data.
         */
		IMPORT_C static CBCardEngine* NewL(CPbkContactEngine* aEngine);

        /**
         * Destructor
         */
		IMPORT_C ~CBCardEngine();

	public: // The main public interface
        /**
         * Reads a vCard record from a stream into a Phonebook contact
		 * item.
		 * @param aDestItem Phonebook contact item where the information
		 *        should be written to. The item should be writable. The
		 *        caller should commit the changes.
		 * @param aSourceStream A stream where the vCard data is read from
         */
		IMPORT_C void ImportBusinessCardL(CPbkContactItem& aDestItem,
			RReadStream &aSourceStream);

        /**
         * Writes a vCard record with information from a Phonebook contact
		 * item.
		 * @param aDestStream A stream where the vCard data is written to.
		 *        The data written to the stream is not Committed by this method.
		 * @param aSourceItem Phonebook contact item where the information
		 *        should be read from
         */
        IMPORT_C void ExportBusinessCardL(RWriteStream& aDestStream,
			CPbkContactItem& aSourceItem);

        /**
         * Reads a Compact Business Card record from a stream into a Phonebook
		 * contact item.
		 * @param aDestItem Phonebook contact item where the information
		 *        must be written to. The item must be writable.
		 *        The caller should commit the changes.
		 * @param aSourceStream A stream where the Compact Business Card
		 *        is read from
		 * @return ETrue on success
         */
        IMPORT_C TBool ImportCompactBusinessCardL(CPbkContactItem& aDestItem,
			RReadStream &aSourceStream);

        /**
         * Checks if given field is supported by the vCard format
         * @param aFieldId Field id type
         * @return ETrue if given field is supported, EFalse otherwise
         */
        IMPORT_C TBool SupportsFieldType(TPbkFieldId aFieldId);

    private:  // Constructors
		CBCardEngine();
		void ConstructL(CPbkContactEngine* aEngine);

    private:    // Private utility methods
        void ProcessExportPropertyL(
            CParserVCard& aParser,
            CPbkContactItem& aSourceItem,
            const CBCardExportProperty& aExportProperty);
        TInt GetLineFromStreamL(TDes& aBuf, RReadStream& aSourceStream);
        TInt GetByteFromStream(TUint8& aByte, RReadStream& aSourceStream);
		class CBCardFieldAction;

    private:
        /// Own: Filename for picture
        HBufC* iPictureFileName;
		/// Own: Filename for thumbnail
		HBufC* iThumbnailFileName;
        /// Own: Instance for property name-Uid mapping
        CBCardFieldUidMapping* iNameUidMap;
        /// Own: Instance for contact field handling
        CBCardFieldAction* iFieldAction;
        /// Ref: Phonebook engine
        CPbkContactEngine* iEngine;
        /// Own: Array of CBCardExportProperty instances for exporting contact
        RPointerArray<CBCardExportProperty> iExportProperties;
	};

#endif // __BCARDENG_H__

// End of File
