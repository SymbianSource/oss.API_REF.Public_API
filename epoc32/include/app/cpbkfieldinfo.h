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
*     Phonebook constant field type information
*
*/


#ifndef __CPbkFieldInfo_H__
#define __CPbkFieldInfo_H__

//  INCLUDES
#include    <e32std.h>
#include    <cntdef.h>
#include    "PbkFields.hrh"
#include    "PbkIconId.hrh"

// FORWARD DECLARATIONS
class CContentType;
class CContactItemField;
class CContactItemViewDef;
class CContactItemFieldDef;
class CPbkFieldsInfo;
class TResourceReader;
class CPbkFieldInfoGroup;
class CPbkFieldImportType;
class TPbkContactItemFieldType;
class TPbkVcardFieldType;
class CPbkUidMap;
class TPbkMatchPriorityLevel;

// CLASS DECLARATION

/**
 * Phonebook constant field type information. Loaded from resources into
 * CPbkFieldsInfo array. The corresponding resource structure is PHONEBOOK_FIELD
 * in PbkFieldInfo.rh.
 *
 * @see CPbkFieldsInfo
 * @see PHONEBOOK_FIELD
 * @see FIELD
 */
class CPbkFieldInfo :
        public CBase
	{
    public: // Interface
        /**
         * Returns the unique Phonebook field id for this field type.
         * @return The unique Phonebook field id for this field type.
         */
        IMPORT_C TPbkFieldId FieldId() const;

        /**
         * Returns the storage type of this field type.
         * @return The storage type of this field type.
         */
        IMPORT_C TStorageType FieldStorageType() const;

        /**
         * Returns the content type of this field type.
         * @return The content type of this field type.
         * @see CContentType
         */
        IMPORT_C const CContentType& ContentType() const;

        /**
         * Returns the category of this field type.
         * @return The category of this field type
         */
        IMPORT_C TInt Category() const;

        /**
         * Returns this field type's default label.
         * @return The field type's default label.
         */
        IMPORT_C const TDesC& FieldName() const;

        /**
         * Returns Symbian Contacts Model field flags of this field type.
         * @return Symbian Contacts model field flags for this field type.
         */
        IMPORT_C TUint Flags() const;

        /**
         * Returns the multiplicity allowed for this field type.
         * @return The multiplicity allowed for this field type.
         */
        IMPORT_C TPbkFieldMultiplicity Multiplicity() const;

        /**
         * Returns the maximum data length that Phonebook UI spec specifies
         * for this field type.
         * @return The maximum data length that Phonebook UI spec specifies
         *         for this field type.
         */
        IMPORT_C TInt MaxLength() const;

        /**
         * Returns the default editing mode for this field type.
         * @return The default editing mode for this field type.
         */
        IMPORT_C TPbkFieldEditMode EditMode() const;

        /**
         * Returns the default character case for this field type.
         * @return The default character case for this field type.
         */
        IMPORT_C TPbkFieldDefaultCase DefaultCase() const;

        /**
         * Returns the icon id for this field type.
         * @return The icon id for this field type.
         */
        IMPORT_C TPbkIconId IconId() const;

        /**
         * Returns the UI control type required to edit this field.
         * @return The UI control type required to edit this field.
         */
        IMPORT_C TPbkFieldCtrlType CtrlType() const;

        /**
         * Returns additional flags of this field type.
         * @return The additional flags of this field type.
         */
        IMPORT_C TUint AddFlags() const;

        /**
         * @deprecated  This function is no longer supported.
         *
         * Returns the UI ordering for adding a field.
         * @return The UI ordering for adding a field.
         */
        IMPORT_C TPbkAddItemOrdering AddItemOrdering() const;

        /**
         * Returns ETrue if this field is hidden.
         * @return ETrue if this field is hidden, EFalse otherwise.
         */
        IMPORT_C TBool IsHidden() const;

        /**
         * Returns ETrue if this field is read only.
         * @return ETrue if this field is read only, EFalse otherwise.
         */
        IMPORT_C TBool IsReadOnly() const;

        /**
         * Returns ETrue if this field is synchronized.
         * @return ETrue if this field is synchronized, EFalse otherwise.
         */
        IMPORT_C TBool DoSynchronize() const;

        /**
         * Returns ETrue if this field is disabled.
         * @return ETrue if this field is disabled, EFalse otherwise.
         */
        IMPORT_C TBool IsDisabled() const;

        /**
         * Returns ETrue if this is a name field type.
         * @return ETrue if this is a name field type, EFalse otherwise.
         */
        IMPORT_C TBool NameField() const;

        /**
         * Returns ETrue if this field type is part of the default template.
         * @return ETrue if this is part of the default template, 
         *         EFalse otherwise.
         */
        IMPORT_C TBool TemplateField() const;

        /**
         * Returns ETrue if this field type can be added by the user.
         * @return ETrue if this field type can be added by the user, 
         *         EFalse otherwise.
         */
        IMPORT_C TBool UserCanAddField() const;

        /**
         * Returns ETrue if the field type can be edited in Phonebook's contact
         * editor.
         * @return ETrue if this field type can be edited in phonebook's contact 
         *         editor, EFalse otherwise.
         */
        IMPORT_C TBool IsEditable() const;

        /**
         * Returns ETrue if this is a numeric field type.
         * @return ETrue if this is a numeric field type, EFalse otherwise.
         */
        IMPORT_C TBool NumericField() const;

        /**
         * Returns ETrue if this is a phone number field type.
         * @return ETrue if this is a phone number field type, EFalse otherwise.
         */
        IMPORT_C TBool IsPhoneNumberField() const;

        /**
         * Returns ETrue if this is an EmailOverSms address field type.
         * @return ETrue if this field type is a EmailOverSms address 
         *         field, EFalse otherwise.
         */
        IMPORT_C TBool IsEmailOverSmsField() const;

        /**
         * Returns ETrue if this is an Email address field type.
         * @return ETrue if this is a EMail address field type, EFalse otherwise.
         */
        IMPORT_C TBool IsEmailField() const;

        /**
         * Returns ETrue if this is a MMS address field type.
         * @return ETrue if this is a MMS address field type, EFalse otherwise.
         */
        IMPORT_C TBool IsMmsField() const;

        /**
         * Returns ETrue if this is an image field type.
         * @return ETrue if this is a image field type, EFalse otherwise.
         */
        IMPORT_C TBool IsImageField() const;

        /**
		 * Returns ETrue if this is a POC address field type.
         * @return ETrue if this is a POC address field type, EFalse otherwise.
		 */
        IMPORT_C TBool IsPocField() const;
        
        /**
		 * Returns ETrue if this is a VOIP address field type.
         * @return ETrue if this is a VOIP address field type, EFalse otherwise.
		 */
        IMPORT_C TBool IsVoipField() const;

        /**
         * Returns ETrue if aFieldInfo is same as this.
         * @param aFieldInfo Field info to compare to this field type.
         * @return ETrue if aField Is same as this field type, EFalse otherwise.
         */
        IMPORT_C TBool IsSame(const CPbkFieldInfo& aFieldInfo) const;

        /**
         * Returns ETrue if this field info matches aFieldId.
         * @param aFieldId  The field type id to compare to this field type.
         * @return ETrue if this field info matched aFieldId, EFalse otherwise.
         */
        IMPORT_C TBool Match(TPbkFieldId aFieldId) const;

        /**
         * Returns ETrue if this field info matches aFieldType at any import
         * type priority level.
         * @param aFieldType    Field type to match to this field type.
         * @return ETrue if this field info matches aFieldType at any import
         * type priority level, EFalse otherwise.
         */
        TBool Match(const TPbkContactItemFieldType& aFieldType) const;

        /**
         * Returns ETrue if this field info matches aFieldType at import
         * type priority level defined by aMatchPriority.
         * @param aFieldType    Field type to compare.
         * @param aMatchPriority    Matching priority.
         * @return ETrue if this field info matches aFieldType at import
         *         type priority level defined by aMatchPriority.
         */
        TBool Match
            (const TPbkContactItemFieldType& aFieldType,
            const TPbkMatchPriorityLevel& aMatchPriority) const;

        /**
         * Returns ETrue if this field info matches aVcardType at import
         * type priority level defined by aMatchPriority.
         * @param aVcardType        vCard field type to match to this field type.
         * @param aMatchPriority    Matching priority.
         * @return ETrue if this field info matches aVcardType at import
         *         type priority level defined by aMatchPriority.
         */
        TBool Match
            (const TPbkVcardFieldType& aVcardType,
            const TPbkMatchPriorityLevel& aMatchPriority) const;

        /**
         * @deprecated  This function is no longer supported. If you want to
         *              find the CPbkFieldInfo instance matching a
         *              CContactItemField use
         *              CPbkFieldsInfo::Match(const CContactItemField&) const.
         *              That function works correctly and uses <it>a lot</it>
         *              faster algorithm than this function.
         * @param aField    Symbian Contacts model contact item to match to this field type.
         * Returns ETrue if this field info matches aField.
         * @return ETrue is field matches, EFalse otherwise.
         */
        IMPORT_C TBool Match(const CContactItemField& aField) const;

        /**
         * Creates a Symbian Contacts model field of this field type. Ownership of the field
         * is passed to the client.
         * @return Symbian Contacts model field of this field type.
         */
        IMPORT_C CContactItemField* CreateFieldL() const;

        /**
         * Returns ETrue if aField's label is equal to this field info objects.
         * @param aField    Symbian Contacts model field to compare to this field types label.
         * @return ETrue if aField's label is equal to this field info object.
         */
        TBool IsEqualLabel(const CContactItemField& aField) const;

        /**
         * Returns ETrue if aField's type is equal to this field info object.
         * @param aField Symbian Contacts model field to compare.
         * @return ETrue if Symbian Contacts model aField's type is equal 
         *         to this field info object.
         */
        TBool IsEqualType(const CContactItemField& aField) const;

        /**
         * Returns ETrue if aField's type and labels are equal to this field
         * info object.
         * @param aField    Symbian Contacts model field to compare
         * @return ETrue if aField's type and labels are equal to this field
         * info object.
         */
        IMPORT_C TBool IsEqualTo(const CContactItemField& aField) const;

        /**
         * Compares the field ordering of this and aOther.
         *
         * @param   aOther  The other object this is compared against.
         * @return  0, if this and aOther are equal in field ordering<br>
         *          negative, if this is less than aOther in field ordering<br>
         *          positive, if this is greater than aOther in field ordering.
         */
        IMPORT_C TInt CompareOrdering(const CPbkFieldInfo& aOther) const;

        /**
         * Returns the field info group this field info belongs to or NULL.
         * @return The field info group this field info belongs to or NULL.
         */
        IMPORT_C const CPbkFieldInfoGroup* Group() const;

        /**
         * Returns the location information of the field.
         * @return The location information of the field.
         */
        IMPORT_C TPbkFieldLocation Location() const;

        /**
         * Returns the versit storage type of the field.
         * @return The versit storage type of the field.
         */
        IMPORT_C TPbkVersitStorageType VersitStorageType() const;

        /**
         * Add this field's type information to a contact item view definition.
         *
         * @param aViewDef  View definition to add types to.
         */
        IMPORT_C void AddToViewDefL(CContactItemViewDef& aViewDef) const;

        /**
         * Add this field's type information to a contact item field definition.
         *
         * @param aFieldDef Field definition to add types to.
         */
        IMPORT_C void AddToFieldDefL(CContactItemFieldDef& aFieldDef) const;

        /**
         * Returns the Add item label text of the field.
         * @return The Add item label text of the field.
         */
        IMPORT_C const TDesC& AddItemText() const;

        /**
         * Returns ETrue if this field is a reading field type (japanese).
         * @return ETrue if this field is a reading field type (japanese).
         */
        IMPORT_C TBool IsReadingField() const;

    private: // Forward declaration of internal class
        class TPbkFieldInfoParams;

    private: // Constructors and destructor
        CPbkFieldInfo();

        static CPbkFieldInfo* NewLC(TResourceReader& aReaderStd, TResourceReader& aReaderAdd, 
            TPbkFieldInfoParams& aPbkFieldInfoParams);

        ~CPbkFieldInfo();
        void ReadCntModelFieldsL(TResourceReader& aReaderStd);
        void ReadAdditionalFieldsL(TResourceReader& aReaderAdd, 
            TPbkFieldInfoParams& aPbkFieldInfoParams);
        void ReadImportPropertiesL(TResourceReader& aReaderAdd);
        void ConstructFromResourceL
            (TResourceReader& aReaderStd, TResourceReader& aReaderAdd,
             TPbkFieldInfoParams& aPbkFieldInfoParams);
        TInt ImportPropertyCount() const;
        void UpdateTypeUidMapL(CPbkUidMap& aTypeUidMap) const;
        void CalculateTypeSignatures(const CPbkUidMap& aTypeUidMap);
        TBool IsEqualFlags(const CContactItemField& aField) const;
    
    private: // Structure

        struct TPbkFieldInfoParams
	        {
	        /// Own: Max number length in editor
	        TInt iEditorMaxNumberLength;
	        };
	        
    private:  // Data
        /**
		 * Contacts Model attributes			
		 * Attribute in resource struct FIELD
		 */
        /// Own: storage type (Text,Date,...)
        TStorageType iFieldStorageType;		// LONG fieldStorageType
		/// Own: content type
        CContentType* iContentType;			// LONG contactFieldType,
											// LONG vCardMapping,
											// STRUCT extraMapping[]
		/// Own: category (Home/Work)
        TInt iCategory;						// LONG category
		/// Own: field's default name and label
        HBufC* iFieldName;					// LTEXT fieldName
		/// Own: special flags
        TUint iFlags;						// LONG flags

		/**
         * Additional attributes
		 * Attributes in resource struct PHONEBOOK_FIELD
		 */
        /// Own: entry Add item labeltext
        HBufC* iAddItemText;				// LTEXT AddItemText
        /// Own: assorted flags for the field type
        TUint iAddFlags;					// LONG Flags
        /// Own: maximum length in characters
        TInt16 iMaxLength;					// WORD MaxLength
        /// Own: index of an icon
        TInt8 iIconId;					    // BYTE IconId
        /// Own: The unique field type id
        TInt8 iFieldId;                     // BYTE Id
        /// Own: allowed multiplicity (one/many).
        TInt8 iMultiplicity;                // BYTE Multiplicity
        /// Own: default editing mode
        TInt8 iEditMode;		            // BYTE EditMode
        /// Own: default character case
        TInt8 iDefaultCase;                 // BYTE DefaultCase
        /// Own: editor UI control type
        TInt8 iCtrlType;                    // BYTE CtrlType
        /// Own: entry item grouping
        TInt8 iOrderingGroup;	            // BYTE OrderingGroup
        /// Own: entry item group item ordering
        TInt8 iOrderingItem;		        // BYTE OrderingItem
        /// Own: entry Add Item ordering
        TInt8 iAddItemOrdering;             // BYTE AddItemOrdering
        /// Own: entry item location (none/home/work)
        TInt8 iLocation;		            // BYTE Location
        // Own: data storage type in versit
        TInt8 iVersitStorageType;           // BYTE VersitStorageType

		/// Own: field import type
        CPbkFieldImportType* iImportType;

        union
            {
            /// Own: group id before groups are loaded
            TPbkFieldGroupId iGroupId;
            /// Ref: field info group this contact info belongs to
            const CPbkFieldInfoGroup* iGroup;
            } iGroupLink;
        
    private: // Friend declarations
        friend class CPbkFieldsInfo;
        friend class PbkFieldInfoWrite;
	};

#endif // __CPbkFieldInfo_H__

// End of File
