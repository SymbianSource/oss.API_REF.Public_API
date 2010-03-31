/*
* Copyright (c) 2005-2007 Nokia Corporation and/or its subsidiary(-ies).
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
* Description:  VPbk store contact analyzer.
*
*/


#ifndef TVPBKStORECONTACTANALYZER_H
#define TVPBKStORECONTACTANALYZER_H

//  INCLUDES
#include <e32def.h>

//  VPbk includes
#include <VPbkFieldTypeSelectorFactory.h>

// FORWARD DECLARATIONS
class CVPbkContactManager;
class MVPbkStoreContact;
class MVPbkContactFieldSelector;
class MVPbkFieldTypeList;
class MVPbkBaseContactFieldCollection;
class MVPbkBaseContactField;
class CVPbkFieldTypeSelector;
class MVPbkFieldTypeSelector;
class MVPbkFieldType;
class TVPbkFieldTypeSelector;

// CLASS DECLARATION

/**
 * VPbk store contact analyzer.
 */
class TVPbkStoreContactAnalyzer
    {
    public: // Constructors and destructor

        /**
         * Constructor.
         *
         * @param aContactManager   Virtual Phonebook contact manager.
         * @param aContact          Store contact.
         */
        IMPORT_C TVPbkStoreContactAnalyzer(
                const CVPbkContactManager& aContactManager,
                const MVPbkStoreContact* aContact );

    public: // Interface

        /**
         * Analyses if the contact has a field with type specified
         * in aFieldTypeSelector.
         *
         * @param aFieldTypeSelector    Predefined field type selector.
         * @param aStartIndex   Starts looking up the specified field from
         *                      this field index.
         * @param aContact      The contact to analyze. If NULL the contact
         *                      got from the constructor is used.
         * @return  Field index if contact has field specified in aResId,
         *          otherwise KErrNotFound.
         */
        IMPORT_C TInt HasFieldL(
                VPbkFieldTypeSelectorFactory::TVPbkFieldTypeSelector aFieldTypeSelector,
                TInt aStartIndex = 0,
                const MVPbkStoreContact* aContact = NULL ) const;
        
        /**
         * Analyses if the contact has a action type with type specified
         * in aActionTypeSelector.
         *
         * @param aActionTypeSelector   Predefined contact action type selector.
         * @param aStartIndex   Starts looking up the specified field from
         *                      this field index.
         * @param aContact      The contact to analyze. If NULL the contact
         *                      got from the constructor is used.
         * @return  Field index if contact has field specified in aResId,
         *          otherwise KErrNotFound.
         */
        IMPORT_C TInt HasFieldL(
                VPbkFieldTypeSelectorFactory::TVPbkContactActionTypeSelector aActionTypeSelector,
                TInt aStartIndex = 0,
                const MVPbkStoreContact* aContact = NULL ) const;

        /**
         * Analyses if the contact supports field with type specified
         * in aFieldTypeSelector.
         *
         * @param aFieldTypeSelector    Predefined field type selector.
         * @param aContact      The contact to analyze. If NULL the
         *                      contact got from constructor is used.
         * @return  ETrue if the field type is supported by the contact,
         *          otherwise EFalse.
         */
        IMPORT_C TBool IsFieldTypeSupportedL(
                VPbkFieldTypeSelectorFactory::TVPbkFieldTypeSelector aFieldTypeSelector,
                const MVPbkStoreContact* aContact = NULL ) const;

        /**
         * Analyses if the contact supports action types with type specified
         * in aActionTypeSelector.
         *
         * @param aActionTypeSelector    Predefined contact action type selector.
         * @param aContact      The contact to analyze. If NULL the
         *                      contact got from constructor is used.
         * @return  ETrue if the action type is supported by the contact,
         *          otherwise EFalse.
         */
        IMPORT_C TBool IsFieldTypeSupportedL(
                VPbkFieldTypeSelectorFactory::TVPbkContactActionTypeSelector aActionTypeSelector,
                const MVPbkStoreContact* aContact = NULL ) const;

        /**
         * Checks if the aFieldType is same as specified in aFieldTypeSelector.
         * Returns ETrue is same, otherwise EFalse.
         *
         * @param aFieldType   The field type to check.
         * @param aFieldTypeSelector   Predefined field type selector.
         * @return  ETrue if the field type is included.
         */
        IMPORT_C TBool IsFieldTypeIncludedL(
                const MVPbkFieldType& aFieldType,
                VPbkFieldTypeSelectorFactory::TVPbkFieldTypeSelector aFieldTypeSelector ) const;

        /**
         * Checks if the aFieldType is same as specified in aActionTypeSelector.
         * Returns ETrue is same, otherwise EFalse.
         *
         * @param aFieldType   The field type to check.
         * @param aActionTypeSelector   Predefined field type selector.
         * @return  ETrue if the field type is included.
         */
        IMPORT_C TBool IsFieldTypeIncludedL(
                const MVPbkFieldType& aFieldType,
                VPbkFieldTypeSelectorFactory::TVPbkContactActionTypeSelector aActionTypeSelector ) const;

        /**
         * Checks if the aField's field type is same as specified in
         * aFieldTypeSelector. Returns ETrue is same, otherwise EFalse.
         *
         * @param aField       The field whose type to check.
         * @param aFieldTypeSelector       Selector's resource id.
         * @return  ETrue if the field type is included.
         */
        IMPORT_C TBool IsFieldTypeIncludedL(
                const MVPbkBaseContactField& aField,
                VPbkFieldTypeSelectorFactory::TVPbkFieldTypeSelector aFieldTypeSelector ) const;

        /**
         * Checks if the aField's field type is same as specified in
         * aActionTypeSelector. Returns ETrue is same, otherwise EFalse.
         *
         * @param aField       The field whose type to check.
         * @param aActionTypeSelector       Selector's resource id.
         * @return  ETrue if the field type is included.
         */
        IMPORT_C TBool IsFieldTypeIncludedL(
                const MVPbkBaseContactField& aField,
                VPbkFieldTypeSelectorFactory::TVPbkContactActionTypeSelector aActionTypeSelector ) const;

    private: // Implementation
        TVPbkStoreContactAnalyzer();

    private: // Data
        /// Ref: Virtual Phonebook contact manager
        const CVPbkContactManager& iContactManager;
        /// Ref: The contact to analyze
        const MVPbkStoreContact* iContact;
    };

#endif // TVPBKStORECONTACTANALYZER_H

// End of File
