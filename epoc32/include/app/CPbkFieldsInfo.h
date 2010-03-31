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
*     Phonebook field types collection class
*
*/



#ifndef __CPbkFieldsInfo_H__
#define __CPbkFieldsInfo_H__

//  INCLUDES
#include <e32base.h>
// This include is not absolutely needed,  but this class is very rarely used 
// without class CPbkFieldInfo.
#include "CPbkFieldInfo.h"

//  FORWARD DECLARATIONS
class CContactItem;
class CContactItemField;
class CContactItemViewDef;
class RResourceFile;
class CPbkUidMap;
class CPbkFieldInfo;
class CPbkFieldInfoGroup;
class MPbkVcardProperty;
class TPbkMatchPriorityLevel;


//  CLASS DECLARATION 

/**
 * Phonebook field types collection class. The collection contains 
 * CPbkFieldInfo objects that contain Phonebook specific field type
 * information. Each field Phonebook recognizes is associated with 
 * field info object. The field info objects are references to elements
 * in this array.
 */
class CPbkFieldsInfo : 
        public CBase
	{
	public: // interface
        /**
         * Creates and returns an instance of this class intialised from 
         * resources.
         * 
         * @param aPbkResFile       Phonebook's resource file.
         * @param aCntModelResFile  Contact Model's resource file.
         */
        static CPbkFieldsInfo* NewL
            (RResourceFile& aPbkResFile, RResourceFile& aCntModelResFile);

        /**
         * Destructor.
         */
        ~CPbkFieldsInfo();

        /**
         * Search field info by Phonebook field id.
         *
         * @param aFieldId  Phonebook field id to search from the array
         * @return  The <it>first</it> (there may be several that match) field 
         *          info object in the field UI presentation order matching 
         *          aFieldId. Returns NULL if no match is found.
         */
        IMPORT_C CPbkFieldInfo* Find(TPbkFieldId aFieldId) const;

        /**
         * Search field info by Phonebook field id and location
         *
         * @param aFieldId   Phonebook field id to search from the array
         * @param aLocation  Field location (home/work/none) to search from the array
         * @return  The field info object (there should be only one) matching 
         *          aFieldId and aLocation. NULL if no match found.
         */
        IMPORT_C CPbkFieldInfo* Find
			(TPbkFieldId aFieldId, TPbkFieldLocation aLocation) const;

        /**
         * Search a field info matching contact model field.
         *
         * @param aContactItemField Contact item field whose match is searched
         *                          from all field info objects.
         * @return  The field info object matching aContactItemField. NULL if 
         *          no match is found.
         */
        IMPORT_C CPbkFieldInfo* Find
			(const CContactItemField& aContactItemField) const;

        /**
         * @internal Only Phonebook internal use is supported!
         * Creates and returns an initialized matching priority level object.
         * @deprecated
         */
        IMPORT_C TPbkMatchPriorityLevel CreateMatchPriority() const;

        /**
         * @internal Only Phonebook internal use is supported!
         * Searches a match for a contact model field.
         *
         * @param aContactItemField Contact item field whose match is searched
         *                          from all field info objects.
         * @param aMatchPriority    Priority to match against. Only import
         *                          types of this priority are checked.
         * @return  A match information object.
         * @deprecated
         */
        CPbkFieldInfo* Match
            (const CContactItemField& aContactItemField,
            const TPbkMatchPriorityLevel& aMatchPriority) const;

        /**
         * @internal Only Phonebook internal use is supported!
         * Searches a match for a vCard property.
         *
         * @param aVcardProperty    vCard property to search for a match from 
         *                          all field info objects.
         * @param aMatchPriority    Priority to match against. Only import
         *                          types of this priority are checked.
         * @return  A match information object.
         * @deprecated
         */
        IMPORT_C CPbkFieldInfo* Match
            (const MPbkVcardProperty& aVcardProperty,
            const TPbkMatchPriorityLevel& aMatchPriority) const;
        
        /**
         * Returns the count of field infos.
         * @return The count of field information elements in this container.
         */
        IMPORT_C TInt Count() const;

        /**
         * Returns the aIndex:th field info. Field info objects are sorted by
         * the field presentation ordering.
         * @param aIndex    The indexed element in this array.
         * @return The element in the indexed position in the array.
         */
        IMPORT_C CPbkFieldInfo* operator[](TInt aIndex) const;

        /**
         * Returns the count of field info groups.
         * @return The count of field info groups.
         */
        IMPORT_C TInt GroupCount() const;

        /**
         * Returns the field info group at aIndex.
         * @return The field info group at aIndex.
         */
        IMPORT_C const CPbkFieldInfoGroup& GroupAt(TInt aIndex) const;

        /**
         * Creates a contact item view definition from an array of Phonebook 
         * field ids.
         *
         * @param aFieldTypes   Array of Phonebook field types.
         * @return A new contact item view definition.
         */
        IMPORT_C CContactItemViewDef* CreateContactItemViewDefLC
            (const CPbkFieldIdArray& aFieldTypes) const;

        /**
         * Creates contact item field definition from an array of Phonebook 
         * field ids.
         *
         * @param aFieldTypes   Phonebook field types to add into the returned
         *                      array. If NULL an array matching all fields is
         *                      returned.
         * @return  A field def array matching <it>at least fields</it> in 
         *          aFieldTypes. Please note that the returned field definition
         *          may also match other fields than those specified.
         */
        IMPORT_C CContactItemFieldDef* CreateContactItemFieldDefLC
            (const CPbkFieldIdArray* aFieldTypes) const;

        /**
         * Adds fields from resource readers. Doesn't read or link group
         * information.
         * @param aPbkResReader Initialized resource buffer 
         *                      to PHONEBOOK_FIELD_ARRAY
         * @param aCntModelResReader Initialized resource buffer to 
         *                           ARRAY or FIELDs
         * @param aAddedFieldTypes  If not null the field types that were 
         *                          added are appended to this array. The field
         *                          types are in the order they were defined in
         *                          resources.
         */
        void AddFieldTypesFromResourceL
            (TResourceReader& aPbkResReader, 
            TResourceReader& aCntModelResReader,
            RArray<const CPbkFieldInfo*>* aAddedFieldTypes);

    private:  // Implementation
        CPbkFieldsInfo();
        CPbkFieldInfoGroup* FindGroup(TPbkFieldGroupId aGroupId);
        void LinkGroupsL();
        void ReadGroupsInfoL(RResourceFile& aResFile);
        void ConstructFromResourceL
            (RResourceFile& aPbkResFile, RResourceFile& aCntModelResFile);
        void ReadFieldInfoParamsL();

    private: // data
        /// Own: array of field infos
        RPointerArray<CPbkFieldInfo> iEntries;
        /// Own: field info groups
        RPointerArray<CPbkFieldInfoGroup> iGroups;
        /// Own: UID map for field content type matching
        CPbkUidMap* iTypeUidMap;
        /// Own: highest field matching priority level
        TInt iHighestMatchPriorityLevel;
        /// Own: configuration data for field infos
        CPbkFieldInfo::TPbkFieldInfoParams* iPbkFieldInfoParams;
    };

#endif // __CPbkFieldsInfo_H__

// End of File
