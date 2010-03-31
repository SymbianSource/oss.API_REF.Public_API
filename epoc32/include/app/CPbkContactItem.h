/*
* Copyright (c) 2002 Nokia Corporation and/or its subsidiary(-ies).
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
*     Phonebook Contact item class.
*
*/


#ifndef __CPbkContactItem_H__
#define __CPbkContactItem_H__

//  INCLUDES
#include <e32base.h>        // CBase, CArrayFixFlat
#include "MPbkFieldData.h"  // MPbkFieldDataArray
#include "PbkFields.hrh"    // TPbkFieldId
#include "TPbkContactItemField.h"

// FORWARD DECLARATIONS
class CPbkFieldsInfo;
class CPbkFieldInfo;
class CContactItemField;
class CContactItem;
class MPbkContactNameFormat;


// CLASS DECLARATION

/**
 * Array of TPbkContactItemField instances.
 */
class CPbkFieldArray : public CArrayFixFlat<TPbkContactItemField>
    {
    public:
        enum
            {
            /// Default array reallocation granularity
            KDefaultGranularity = 8
            };

        /** 
         * Constructor.
         */
        inline CPbkFieldArray() 
            : CArrayFixFlat<TPbkContactItemField>(KDefaultGranularity)
            {
            }

        /**
         * Constructor.
         * @param aGranularity  Reallocation granularity of this array.
         */
        inline CPbkFieldArray(TInt aGranurality) 
            : CArrayFixFlat<TPbkContactItemField>(aGranurality)
            {
            }
    };


/**
 * Phonebook Contact item class. Contact items can be read from the contact
 * database by using the Phonebook engine, @see CPbkContactEngine.
 * This class extends Symbian Contacts model class CContactItem capabilities 
 * to better suit Phonebook application's needs.
 */
class CPbkContactItem : 
        public CBase, public MPbkFieldDataArray
    {
    public:  // Constructor and destructor
        /**
         * Creates an instance of this class.
         *
         * @param aItem         Contact item this object wraps. This object 
         *                      takes ownership of aItem. If this function 
         *                      leaves, ownership is not taken.
         * @param aFieldsInfo   Collection of Phonebook field types.
         * @param aNameFormat   Contact name formatter.
         * @return  A new instance of this class.
         */
        IMPORT_C static CPbkContactItem* NewL(
                CContactItem* aItem, 
                const CPbkFieldsInfo& aFieldsInfo, 
                MPbkContactNameFormat& aNameFormat);

        /**
         * Destructor.
         */
        ~CPbkContactItem();

    public: // CContactItem functions
        /**
         * Returns this contact item's id.
         * @see CContactItem::Id()
         */
        IMPORT_C TContactItemId Id() const;
        
        /**
         * Returns type of this contact item. The contact types are documented in
         * the Symbian Contacts model CContactItem::Type().
         * @return Contact type.
         * @see CContactItem::Type()
         */
        IMPORT_C TUid Type() const;

        /**
         * Gets the groups this contact belongs to.
         * @return Array of group ids. Caller owns the array.
         * @see CContactItem::GroupsJoinedLC()
         */
        IMPORT_C CContactIdArray* GroupsJoinedLC() const;

        /**
         * Converts this object to a CContactItem. Use only if this class's API
         * is not enough.
         * @return  The underlying Symbian Contacts model contact item object.
         */
        IMPORT_C CContactItem& ContactItem();

        /**
         * Converts this object to a const CContactItem. Use only if this 
         * class's API is not enough.
         * @return  The underlying Symbian Contacts model contact item object.
         */
        IMPORT_C const CContactItem& ContactItem() const;

    public:  // Field set operations
        /**
         * Returns the field set of this contact item.
         * @return  Field array of this contact item.
         */
        IMPORT_C CPbkFieldArray& CardFields() const;

        /**
         * Creates a new field based on aFieldInfo and adds it to this contact.
         *
         * @param aFieldInfo    Type of field to create.
         * @return The created field.
         */
      	IMPORT_C TPbkContactItemField& AddFieldL(CPbkFieldInfo& aFieldInfo);

        /**
         * Returns ETrue if data of type aFieldInfo can be added to this 
         * contact.
         * @param aFieldInfo    The field type that we are trying to add.
         * @return  ETrue if the contact can accept this type of data, EFalse
         *          otherwise.
         */
        IMPORT_C TBool CanAcceptDataOfType(CPbkFieldInfo& aFieldInfo) const;

        /**
         * Finds an unused or creates a new field based on aFieldInfo. An 
         * unused field is a field that is in the contact template, but
         * doesnt contain any data, in other words it is empty. So a unused 
         * field is preferred ad the next field to add user data before 
         * adding a new field to the contact.
         *
         * @param aFieldInfo    Type of field to search or create.
         * @return  Pointer to the found or created field. NULL only if<br>
         *          field exists AND <br>
         *          field is nonempty AND <br>
         *          aFieldInfo.Multiplicity()==EPbkFieldMultiplicityOne.
         */
      	IMPORT_C TPbkContactItemField* AddOrReturnUnusedFieldL
            (CPbkFieldInfo& aFieldInfo);

        /**
         * Deletes field at aIndex.
         * @param aIndex    Field index to delete from the contact item.
         */
        IMPORT_C void RemoveField(TInt aIndex);

        /**
         * Updates this contacts field set to match the field set of
         * the owned CContactItem. No need to call unless contact item's
         * field set has been manipulated directly. In other words 
         * remaps the field types of this contact item from the underlying
         * Symbian Contacts model contact item.
         * @param aFieldsInfo   The new fields set for this contact.
         */
        IMPORT_C void UpdateFieldSetL(const CPbkFieldsInfo& aFieldsInfo);

    public:  // Field searching
        /**
         * Returns first field matching aFieldId.
         *
         * @param aFieldId  Field id to search.
         * @return First field matching aFieldId, NULL if none found.
         */
        IMPORT_C TPbkContactItemField* FindField(TPbkFieldId aFieldId) const;

        /**
         * Returns first field matching aFieldId starting from aIndex.
         *
         * @param aFieldId  Field id to search.
         * @param aIndex    Input: field index where to start the search from,
         *                  output: index of the found field or -1 if not found.
         * @return Field matching aFieldId, NULL if none found.
         */
        IMPORT_C TPbkContactItemField* FindField
            (TPbkFieldId aFieldId, TInt& aIndex) const;

        /**
         * Returns first field matching aFieldInfo.
         *
         * @param aFieldInfo    Field type to find from the contact.
         * @return First field matching aFieldInfo, NULL if none found.
         */
        IMPORT_C TPbkContactItemField* FindField(const CPbkFieldInfo& aFieldInfo) const;

        /**
         * Returns first field matching aFieldInfo starting from aIndex.
         *
         * @param aFieldInfo    Field type to find from the contact.
         * @param aIndex    Input: field index where to start the search from,
         *                  output: index of the found field or -1 if not found.
         * @return Field matching aFieldInfo, NULL if none found.
         */
        IMPORT_C TPbkContactItemField* FindField
            (const CPbkFieldInfo& aFieldInfo, TInt& aIndex) const;

        /**
         * Returns aField's index from this contact item.
         *
         * @param aField    Field to search for. Field is matched with 
         *                  TPbkContactItemField::IsSame -function.
         * @return  Index of aField in this contact item's field set, 
         *          KErrNotFound if not found.
         * @see TPbkContactItemField::IsSame
         */
        IMPORT_C TInt FindFieldIndex(const TPbkContactItemField& aField) const;

        /**
         * Returns aField's index from ContactItem()'s CardFields() or 
         * KErrNotFound if not found.
         * @param aField    The field which index we are querying.
         * @return The fields index in this contact item, KErrNotFound is not found.
         */
        IMPORT_C TInt FindContactItemFieldIndex(const CContactItemField& aField) const;

        /**
         * Searches phone number fields of this contact for a match.
         * Uses PbkEngUtils::ContainSameDigits to perform the matching.
         *
         * @param aNumber   Phone number to match to.
         * @param aNumberOfDigits   Number of digits to compare from the end 
         *                          of the phone numbers. Full comparison
         *                          performed if 0.
         * @param aIndex    Input: field index where to start the search from,
         *                  output: index of the found field or KErrNotFound if not found.
         * @return The matching field, NULL if not found.
         * @see PbkEngUtils::ContainSameDigits
         */
        IMPORT_C TPbkContactItemField* FindNextFieldWithPhoneNumber
            (const TDesC& aNumber,
            TInt aNumberOfDigits,
            TInt &aIndex) const;

        /**
         * Searches for a text in this contact's fields. Uses TDesC::FindF()
         * search the text from the fields.
         *
         * @param aIndex    Input: field index from where to start the search,
         *                  Output: index of the found field or KErrNotFound 
         *                  if not found.
         * @return The matching field, NULL if not found.
         * @see TDesC::FindF
         */
        IMPORT_C TPbkContactItemField* FindNextFieldWithText
            (const TDesC& aText,
            TInt& aIndex) const;

        /**
         * Returns field matching aField from this contact item's field set, NULL if
         * not found.
         * @param aField    The field that we a mathing.
         * @return  Matching field or NULL if not found.
         * @postcond !FindSameField(field) || FindSameField(field)->IsSame(field)
         */
        IMPORT_C TPbkContactItemField* FindSameField
            (const TPbkContactItemField& aField) const;

    public: // Contact presentation
        /**
         * Gets a title text for this contact or localized unnamed text.
         *
         * @return  A buffer containing the title or localized unnamed text if no
         *          title can be generated. Caller is responsible for deleting 
         *          the returned buffer.
         */
        IMPORT_C HBufC* GetContactTitleL() const;

        /**
         * Gets a title text for this contact.
         *
         * @return  A buffer containing the title text, NULL if title is empty.
         *          Caller is responsible for deleting the returned buffer.
         */
        IMPORT_C HBufC* GetContactTitleOrNullL() const;

        /**
         * Returns an Phonebook icon id for a contact. This icon id is the icon
         * of the field that is set as the default number to call.
         *
         * @return  Icon index for this contact, EPbkNullIconId for no icon.
         */
        IMPORT_C TPbkIconId ContactIconIdL() const;

    public:  // Defaults
        /**
         * Returns the default phone number field of this contact.
         *
         * @return  Default phone number field of this contact, 
         *          NULL if no default set.
         */
        IMPORT_C TPbkContactItemField* DefaultPhoneNumberField() const;

        /**
         * Sets this contact's default phone number field to aField.
         *
         * @param aField    Field to set as default, if NULL phone number
         *                  default is removed. Guaranteed not to leave if
         *                  aField is NULL.
         * @exception KErrNotFound  If aField is not this contact's field.
         * @exception KErrNotSupported  If aField is not a phone number field.
         */
        IMPORT_C void SetDefaultPhoneNumberFieldL
            (TPbkContactItemField* aField);

        /**
         * Removes phone number default from this contact.
         *
         * @postcond DefaultPhoneNumberField()==NULL.
         */
        IMPORT_C void RemoveDefaultPhoneNumberField();

        /**
         * Returns the default video number field of this contact.
         *
         * @return  Default video number field of this contact, 
         *          NULL if no default set.
         */
        IMPORT_C TPbkContactItemField* DefaultVideoNumberField() const;

        /**
         * Sets this contact's default video number field to aField.
         *
         * @param aField    Field to set as default, if NULL video number
         *                  default is removed. Guaranteed not to leave if
         *                  aField is NULL.
         * @exception KErrNotFound  if aField is not this contact's field.
         * @exception KErrNotSupported  if aField is not a phone number field.
         */
        IMPORT_C void SetDefaultVideoNumberFieldL
            (TPbkContactItemField* aField);

        /**
         * Removes video number default from this contact.
         *
         * @postcond DefaultVideoNumberField()==NULL.
         */
        IMPORT_C void RemoveDefaultVideoNumberField();

        /**
         * Returns the default SMS field of this contact.
         *
         * @return  Default SMS field of this contact, 
         *          NULL if no default set.
         */
        IMPORT_C TPbkContactItemField* DefaultSmsField() const;

        /**
         * Sets this contact's default SMS field to aField.
         *
         * @param aField    Field to set as default, if NULL SMS
         *                  default is removed. Guaranteed not to leave if
         *                  aField is NULL.
         * @exception KErrNotFound  if aField is not this contact's field.
         * @exception KErrNotSupported  if aField is not a phone number field.
         */
        IMPORT_C void SetDefaultSmsFieldL(TPbkContactItemField* aField);

        /**
         * Removes SMS field default from this contact.
         *
         * @postcond DefaultSmsField()==NULL.
         */
        IMPORT_C void RemoveDefaultSmsField();

        /**
         * Returns the default email field of this contact.
         *
         * @return  Default email field of this contact, 
         *          NULL if no default set.
         */
        IMPORT_C TPbkContactItemField* DefaultEmailField() const;

        /**
         * Sets this contact's default email address field to aField.
         *
         * @param aField    Field to set as default, if NULL email 
         *                  default is removed. Guaranteed not to leave if
         *                  aField is NULL.
         * @exception KErrNotFound  If aField is not this contact's field.
         * @exception KErrNotSupported  If aField is not an email field.
         */
        IMPORT_C void SetDefaultEmailFieldL(TPbkContactItemField* aField);

        /**
         * Removes email field default from this contact.
         *
         * @postcond DefaultEmailField()==NULL.
         */
        IMPORT_C void RemoveDefaultEmailField();

        /**
         * Returns the default Mms field of this contact.
         *
         * @return  Default Mms field of this contact, 
         *          NULL if no default set.
         */
        IMPORT_C TPbkContactItemField* DefaultMmsField() const;

        /**
         * Sets this contact's default MMS address field to aField.
         *
         * @param aField    Field to set as default, if NULL MMS 
         *                  default is removed. Guaranteed not to leave if
         *                  aField is NULL.
         * @exception KErrNotFound  If aField is not this contact's field.
         * @exception KErrNotSupported  If aField is not an email field.
         */
        IMPORT_C void SetDefaultMmsFieldL(TPbkContactItemField* aField);

        /**
         * Removes MMS field default from this contact.
         *
         * @postcond DefaultMmsField()==NULL.
         */
        IMPORT_C void RemoveDefaultMmsField();

        /**
         * Returns the default Poc field of this contact.
         *
         * @return  Default Poc field of this contact, 
         *          NULL if no default set.
         */
        IMPORT_C TPbkContactItemField* DefaultPocField() const;

        /**
         * Sets this contact's default POC address field to aField.
         *
         * @param aField    Field to set as default, if NULL POC 
         *                  default is removed. Guaranteed not to leave if
         *                  aField is NULL.
         * @exception KErrNotFound  If aField is not this contact's field.
         * @exception KErrNotSupported  If aField is not an email field.
         */
        IMPORT_C void SetDefaultPocFieldL(TPbkContactItemField* aField);

        /**
         * Removes POC field default from this contact.
         *
         * @postcond DefaultPocField()==NULL.
         */
        IMPORT_C void RemoveDefaultPocField();
        
        /**
         * Returns the default VOIP field of this contact.
         *
         * @return  Default VOIP field of this contact, 
         *          NULL if no default set.
         */
        IMPORT_C TPbkContactItemField* DefaultVoipField() const;

        /**
         * Sets this contact's default VOIP address field to aField.
         *
         * @param aField    Field to set as default, if NULL VOIP 
         *                  default is removed. Guaranteed not to leave if
         *                  aField is NULL.
         * @exception KErrNotFound  If aField is not this contact's field.
         * @exception KErrNotSupported  If aField is not an email field.
         */
        IMPORT_C void SetDefaultVoipFieldL(TPbkContactItemField* aField);

        /**
         * Removes VOIP field default from this contact.
         *
         * @postcond DefaultVoipField()==NULL.
         */
        IMPORT_C void RemoveDefaultVoipField();
        
        /**
         * Returns the default EmailOverSms field of this contact.
         *
         * @return  Default EmailOverSms field of this contact, 
         *          NULL if no default set.
         */
        IMPORT_C TPbkContactItemField* DefaultEmailOverSmsField() const;
        
        /**
         * Sets this contact's default Sms With Email address field to aField.
         *
         * @param aField    Field to set as default, if NULL Sms With Email 
         *                  default is removed. Guaranteed not to leave if
         *                  aField is NULL.
         * @exception KErrNotFound  If aField is not this contact's field.
         * @exception KErrNotSupported  If aField is not an email field.
         */
        IMPORT_C void SetDefaultEmailOverSmsFieldL(TPbkContactItemField* aField);
        
        /**
         * Removes EmailOverSms field default from this contact.
         *
         * @postcond DefaultEmailOverSmsField()==NULL.
         */
        IMPORT_C void RemoveDefaultEmailOverSmsField();

    public:  // Voice tags
        /**
         * Returns the voice tag field of this contact.
         * NOTE: If this function is unable to make a connection to 
         * the voice tag handling system for some reason, this function will 
         * return null.
         *
         * @return  Voice tag field of this contact, 
         *          NULL if no voice tag set.
         * @deprecated
         */
        IMPORT_C TPbkContactItemField* VoiceTagField() const;

        /**
         * Sets this contact's voice tag field to aField.
         *
         * @param aField    Field to set as default, if NULL voice tag mark
         *                  is removed. Guaranteed not to leave if
         *                  aField is NULL.
         * @exception KErrNotFound  If aField is not this contact's field.
         * @exception KErrNotSupported  If aField is not a phone number field.
         * @postcond (aField && VoiceTagField()->IsSame(*aField)) || (!aField && !VoiceTagField())
         * @deprecated
         */
        IMPORT_C void SetVoiceTagFieldL(TPbkContactItemField* aField);

        /**
         * Removes any voice tag mark from this contact.
         *
         * @postcond VoiceTagField()==NULL.
         * @deprecated
         */
        IMPORT_C void RemoveVoiceTagField();

    public:  // from MPbkFieldDataArray
        TInt PbkFieldCount() const;
        MPbkFieldData& PbkFieldAt(TInt aIndex);
        const MPbkFieldData& PbkFieldAt(TInt aIndex) const;

    public: // Phonebook internal functions, do not call
        /**
         * @internal
         * Prepares this contact for saving into the contact database.
         * @see PrepareAfterLoad
         * @deprecated
         */
        void PrepareForSaveL();

        /**
         * @internal
         * Prepares this contact after loading it from the contact database.
         * @see PrepareForSaveL
         * @deprecated
         */
        void PrepareAfterLoadL();
        
    private: // Implementation
        CPbkContactItem(MPbkContactNameFormat& aNameFormat);
        void ConstructL(CContactItem* aItem, const CPbkFieldsInfo& aFieldsInfo);
        void CreateFieldArrayL(CContactItem& aContactItem, const CPbkFieldsInfo& aFieldsInfo);
        TInt InsertionPos(const TPbkContactItemField& aField) const;
        __DECLARE_TEST;
        typedef CPbkContactItem SelfType;

    private:    // Data
        /// Own: Embedded contact item.
        CContactItem* iItem;
        /// Own: array of phonebook contact item fields
        CPbkFieldArray iFields;
        /// Ref: Contact name formatting API
        MPbkContactNameFormat& iNameFormat;

    private:  // Friend declarations
        friend IMPORT_C TBool operator==
            (const CPbkContactItem& aLeft, const CPbkContactItem& aRight);
    };


// FUNCTION DECLARATIONS

/**
 * Returns ETrue if aLeft and aRight contents are the same.
 */
IMPORT_C TBool operator==
    (const CPbkContactItem& aLeft, const CPbkContactItem& aRight);

/**
 * Returns ETrue if aLeft and aRight contents differ.
 */
inline TBool operator!=
    (const CPbkContactItem& aLeft, const CPbkContactItem& aRight)
    {
    return !(aLeft==aRight);
    }


#endif // __CPbkContactItem_H__
            
// End of File
