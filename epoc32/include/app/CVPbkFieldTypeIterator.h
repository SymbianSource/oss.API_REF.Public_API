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
* Description:  Virtual Phonebook field type iterator.
*
*/


#ifndef CVPBKFIELDTYPEITERATOR_H
#define CVPBKFIELDTYPEITERATOR_H

// INCLUDES
#include <e32base.h>

// FORWARD DECLARATIONS
class MVPbkFieldType;
class CVPbkFieldTypeSelector;
class MVPbkFieldTypeList;

/**
 * Virtual Phonebook Field type iterator interface.
 */
class MVPbkFieldTypeIterator
    {
    public: // Construction
        /**
         * Destructor.
         */
        virtual ~MVPbkFieldTypeIterator() { }

    public: // interface
        /**
         * Returns the next field type, otherwise NULL.
         */
        virtual const MVPbkFieldType* Next() =0;

        /**
         * Returns ETrue if there exists a next field type, else EFalse.
         */
        virtual TBool HasNext() const =0;

    };

/**
 * Virtual Phonebook field type iterator.
 * Iterates the field types according to the field type selector criteria.
 */
class CVPbkFieldTypeIterator :
        public CBase,
        public MVPbkFieldTypeIterator
    {
    public: // construction
        /**
         * Constructor.
         * @param aIterationCriteria    Field type iteration criteria.
         * @param aFieldTypeList        Field types to iterate.
         */
        IMPORT_C static CVPbkFieldTypeIterator* NewLC(
                const CVPbkFieldTypeSelector& aIterationCriteria, 
                const MVPbkFieldTypeList& aFieldTypeList);

        /**
         * Destructor.
         */
        ~CVPbkFieldTypeIterator();
    
    public: // from MVPbkFieldTypeIterator
        virtual const MVPbkFieldType* Next();
        virtual TBool HasNext() const;
        
    private: // implementation
        CVPbkFieldTypeIterator(
                const CVPbkFieldTypeSelector& aIterationCriteria, 
                const MVPbkFieldTypeList& aFieldTypeList);

    private: // Data
        ///Ref: Field type selection criteria
        const CVPbkFieldTypeSelector& iIterationCriteria;
        ///Ref: Field types that are iterated
        const MVPbkFieldTypeList& iFieldTypeList;
        ///Own: Current index in the field type array
        TInt iIteratorIndex;
    };

#endif // CVPBKFIELDTYPEITERATOR_H

// End of File
