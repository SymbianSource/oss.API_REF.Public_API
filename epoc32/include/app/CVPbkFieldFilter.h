/*
* Copyright (c) 2002-2007 Nokia Corporation and/or its subsidiary(-ies).
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
* Description:  A filtered and sorted collection of contact fields.
*
*/


#ifndef CVPBKFIELDFILTER_H
#define CVPBKFIELDFILTER_H

// INCLUDES
#include <e32base.h>
#include <mvpbkstorecontactfieldcollection.h>

// FORWARD DECLARATIONS
class MVPbkContactFieldSelector;
class MVPbkContactFieldOrdering;


/**
 * A filtered and sorted collection of Virtual Phonebook contact fields.
 */
class CVPbkFieldFilter : 
        public CBase,
        public MVPbkStoreContactFieldCollection
    {
    public:  // Types
        /**
         * CVPbkFieldFilter configuration. This configuration class is
         * used to configure the field filter. 
         */
        class TConfig
            {
            public:
	            /**
	             * Constructor.
	             *
	             * @param aBaseFields	Mandatory base field set to filter.
	             * @param aFieldSelector	Optional field selector instance.
	             * @param aFieldOrdering	Optional field ordering instance.
	             */
	            inline TConfig (
	            		MVPbkStoreContactFieldCollection& aBaseFields,
	                	MVPbkContactFieldSelector* aFieldSelector = NULL,
	                	MVPbkContactFieldOrdering* aFieldOrdering = NULL);

			public:
	            ///Ref: Base field collection that is filtered
	            MVPbkStoreContactFieldCollection& iBaseFields;
	            ///Ref: A field selector
	            MVPbkContactFieldSelector* iFieldSelector;
	            ///Ref: Field sorter
	            MVPbkContactFieldOrdering* iFieldOrdering;
	            ///Ref: Spare for future extension
	            TAny* iSpare;
            };

    public:  // Constructor and Destructor
        /**
         * Creates and returns a new instance of this class.
         *
         * @param aConfig   Field filtering configuration.
         */
        IMPORT_C static CVPbkFieldFilter* NewL(const TConfig& aConfig);
		
		/**
		 * Destructor.
		 */
        ~CVPbkFieldFilter();

    public:  // Interface
        /**
         * Reset the contents of this filtered field collection according 
         * to a new configuration.
         *
         * @param aConfig	Filtering configuration to rest to.
         */
        IMPORT_C void ResetL(const TConfig& aConfig);

        /**
         * Finds given field from the set of filtered fields
         * @param aContactField	Field to search for.
         * @return Index of the given field, or KErrNotFound if field is not found.
         */
        IMPORT_C TInt FindField(const MVPbkBaseContactField& aContactField) const;

    public:  // from MVPbkStoreContactFieldCollection
        MVPbkBaseContact& ParentContact() const;
        TInt FieldCount() const;
        const MVPbkStoreContactField& FieldAt(TInt aIndex) const;
        MVPbkStoreContactField& FieldAt(TInt aIndex);
        MVPbkStoreContactField* FieldAtLC(TInt aIndex) const;
        MVPbkStoreContact& ParentStoreContact() const;
        MVPbkStoreContactField* RetrieveField(
                const MVPbkContactLink& aContactLink) const;
            
    private:  // Implementation
        CVPbkFieldFilter();

    private:  // Data
        ///Ref: base fields
        MVPbkStoreContactFieldCollection* iBaseFields;
        ///Own: field mapping 
        RArray<TInt> iFieldMapping;
    };


// INLINE FUNCTIONS

inline CVPbkFieldFilter::TConfig::TConfig
        (MVPbkStoreContactFieldCollection& aBaseFields,
        MVPbkContactFieldSelector* aFieldSelector /*= NULL*/,
        MVPbkContactFieldOrdering* aFieldOrdering /*= NULL*/) :
    iBaseFields(aBaseFields),
    iFieldSelector(aFieldSelector),
    iFieldOrdering(aFieldOrdering)
    {
    }

#endif  // CVPBKFIELDFILTER_H

// End of file
