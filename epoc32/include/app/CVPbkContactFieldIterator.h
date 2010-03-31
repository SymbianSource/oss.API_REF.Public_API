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
* Description:  Virtual Phonebook contact field iterator interface.
*
*/


#ifndef CVPBKCONTACTFIELDITERATOR_H
#define CVPBKCONTACTFIELDITERATOR_H

// INCLUDES
#include <e32base.h>
#include <mvpbkstorecontactfield.h>

// FORWARD DECLARATIONS
class MVPbkStoreContactFieldCollection;
class MVPbkBaseContactFieldCollection;
class MVPbkFieldType;
class MVPbkFieldTypeList;
class MVPbkStoreContactField;
class CStoreFieldByTypeIterator;
class CBaseFieldByTypeIterator;
class CBaseFieldByTypeListIterator;
class MVPbkBaseContactField;

/**
 * Virtual Phonebook contact field iterator interface.
 */
class MVPbkBaseContactFieldIterator
    {
    public: // Construction
	    /**
    	 * Destructor.
    	 */ 
        virtual ~MVPbkBaseContactFieldIterator() { }

    public: // Interface
        /**
         * Returns the next field, otherwise NULL.
         *
         * @return The next field, otherwise NULL.
         */
        virtual const MVPbkBaseContactField* Next() const =0;

        /**
         * Returns ETrue if there exists a next field, else EFalse.
         */
        virtual TBool HasNext() const =0;

    };

/**
 * Virtual Phonebook contact field iterator interface.
 */
class MVPbkContactFieldIterator : public MVPbkBaseContactFieldIterator
    {
    public: // Construction
    	/**
    	 * Destructor.
    	 */
        virtual ~MVPbkContactFieldIterator() { }

    public: // Interface
        // From MVPbkBaseContactFieldIterator (covariant return types))
        const MVPbkStoreContactField* Next() const =0;

        /**
         * Returns the next field, otherwise NULL.
         *
         * @return The next field, otherwise NULL. Ownership doesn't change.
         */
        virtual MVPbkStoreContactField* Next() =0;
    };

/**
 * Virtual Phonebook contact field type iterator.
 * Iterates the contact fields according to the field type specified.
 */
class CVPbkBaseContactFieldTypeIterator :
        public CBase,
        public MVPbkBaseContactFieldIterator
    {
    public: // Construction
        /**
         * Constructor for iterating store contact fields.
         *.
         * @param aFieldType    Field type which is iterated.
         * @param aFields       Contact fields to iterate.
         * @return A new instance of this class
         */
        IMPORT_C static CVPbkBaseContactFieldTypeIterator* NewLC(
                const MVPbkFieldType& aFieldType,
                const MVPbkBaseContactFieldCollection& aFields);

        /**
         * Destructor.
         */
        ~CVPbkBaseContactFieldTypeIterator();

    public: // from MVPbkContactFieldIterator
        const MVPbkBaseContactField* Next() const;
        TBool HasNext() const;

    private: // implementation
        void ConstructL(
            const MVPbkFieldType& aFieldType,
            const MVPbkBaseContactFieldCollection& aFields );

    private: // Data
        /// Own: the iterator implementation
        CBaseFieldByTypeIterator* iIterator;
    };

/**
 * Virtual Phonebook contact field type list iterator.
 * Iterates the contact fields according to the field types specified.
 */
class CVPbkBaseContactFieldTypeListIterator :
        public CBase,
        public MVPbkBaseContactFieldIterator
    {
    public: // Construction
        /**
         * Constructor for iterating store contact fields.
         *.
         * @param aFieldTypeList    Field type list which is iterated.
         * @param aFields       Contact fields to iterate.
         * @return A new instance of this class
         */
        IMPORT_C static CVPbkBaseContactFieldTypeListIterator* NewLC(
                const MVPbkFieldTypeList& aFieldTypeList,
                const MVPbkBaseContactFieldCollection& aFields);

        /**
         * Destructor.
         */
        ~CVPbkBaseContactFieldTypeListIterator();

    public: // from MVPbkContactFieldIterator
        const MVPbkBaseContactField* Next() const;
        TBool HasNext() const;

    private: // implementation
        void ConstructL(
            const MVPbkFieldTypeList& aFieldTypeList,
            const MVPbkBaseContactFieldCollection& aFields );

    private: // Data
        /// Own: the iterator implementation
        CBaseFieldByTypeListIterator* iIterator;
    };

/**
 * Virtual Phonebook contact field type iterator.
 * Iterates the store contact fields according to the 
 * field type specified.
 */
class CVPbkContactFieldTypeIterator :
        public CBase,
        public MVPbkContactFieldIterator
    {
    public: // Construction
        /**
         * Constructor for iterating store contact fields.
         *.
         * @param aFieldType    Field type which is iterated.
         * @param aFields       Contact fields to iterate.
         * @return A new instance of this class
         */
        IMPORT_C static CVPbkContactFieldTypeIterator* NewLC(
                const MVPbkFieldType& aFieldType,
                MVPbkStoreContactFieldCollection& aFields);

        /**
         * Destructor.
         */
        ~CVPbkContactFieldTypeIterator();

    public: // from MVPbkContactFieldIterator
        const MVPbkStoreContactField* Next() const;
        TBool HasNext() const;
        MVPbkStoreContactField* Next();

    private: // implementation
        void ConstructL(
            const MVPbkFieldType& aFieldType,
            MVPbkStoreContactFieldCollection& aStoreFields );

    private: // Data
        /// Own: the iterator implementation
        CStoreFieldByTypeIterator* iIterator;
    };

#endif // CVPBKCONTACTFIELDITERATOR_H

// End of file
