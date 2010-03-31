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
* Description:  Field Type selection utility used to enter the selection
*                criteria.
*
*/


#ifndef CVPBKFIELDTYPESELECTOR_H
#define CVPBKFIELDTYPESELECTOR_H

// INCLUDES
#include <e32base.h>
#include <mvpbkcontactfieldselector.h>
#include <mvpbkfieldtypeselector.h>
#include <vpbkfieldtype.hrh>
#include <tvpbkfieldtypeparameters.h>

// FORWARD DECLARATIONS
class TVPbkFieldVersitProperty;
class MVPbkFieldType;
class MVPbkFieldTypeList;
class TResourceReader;
class RWriteStream;
class MVPbkStoreContactFieldCollection;
namespace VPbkEngUtils { class CTextStore; }

/**
 * Virtual Phonebook field type selector. Responsible for creating
 * a field or field type selection object. Clients can create a 
 * selector and then use e.g. IsFieldIncluded to detect whether
 * the field matches the set criteria.
 */
class CVPbkFieldTypeSelector : public CBase,
                               public MVPbkContactFieldSelector,
                               public MVPbkFieldTypeSelector
    {
    public: // Construction and destruction
        /**
         * Constructs this object from a VPBK_FIELD_TYPE_SELECTOR 
         * ( VPbkFieldType.rh ) resource.
         *
         * @param aReader           Resource reader initialized to the
         *                          VPBK_FIELD_TYPE_SELECTOR resource
         *                          structure.
         * @param aFieldTypeList    Field type list used to search
         *                          for the field.
         * @return A new instance of this class.
         */
        IMPORT_C static CVPbkFieldTypeSelector* NewL(
                TResourceReader& aReader,
                const MVPbkFieldTypeList& aFieldTypeList );

        /**
         * Constructs an empty selector. Can be used in combination
         * with InternalizeL or AppendL to create a selector.
         *
         * @param aFieldTypeList    Field type list used to search
         *                          for the field.
         * @return A new instance of this class.
         */
        IMPORT_C static CVPbkFieldTypeSelector* NewL(
                const MVPbkFieldTypeList& aFieldTypeList );

        /**
         * Copy constructs this object.
         *
         * @param aSelector         The object to copy construct from.
         * @return A new instance of this class.
         */
        IMPORT_C static CVPbkFieldTypeSelector* NewL(
                const CVPbkFieldTypeSelector& aSelector );
        
        /**
         * Destructor.
         */
        ~CVPbkFieldTypeSelector();

    public: // Interface
        /**
         * Outputs this objects state to a buffer.
         *
         * @return Buffer containg this object.
         */
        IMPORT_C HBufC8* ExternalizeLC() const;

        /**
         * Initializes the instance from the buffer.
         *
         * @param aBuffer Buffer containing externalized object.
         */
        IMPORT_C void InternalizeL(
                const TDesC8& aBuffer );

        /**
         * Returns the matching Versit property or NULL.
         *
         * @param aFieldType    The field type to test.
         */
        IMPORT_C const TVPbkFieldVersitProperty* MatchingVersitProperty(
                const MVPbkFieldType& aFieldType ) const;

        /**
         * Returns the matching non-Versit type or EVPbkNonVersitTypeNone.
         *
         * @param aFieldType    The field type to test.
         */
        IMPORT_C TVPbkNonVersitFieldType MatchingNonVersitType(
                const MVPbkFieldType& aFieldType ) const;

        /**
         * Calculates the number of addresses
         *
         * @param aFields	A field collection to test. 
         * @return	Calculated number of addresses.
        */
        IMPORT_C TInt AddressFieldsIncluded(
           		const MVPbkStoreContactFieldCollection& aFields ) const;

        /**
         * Returns the field type list with which this object
         * was initialized with.
         *
         * @return Field type list.
         */
        const MVPbkFieldTypeList& FieldTypeList() const;

        /**
         * Appends a VPBK_FIELD_TYPE_SELECTOR resource to this
         * selector.
         *
         * @param aReader           Resource reader initialized to the
         *                          VPBK_FIELD_TYPE_SELECTOR resource
         *                          structure.
         */
        void AppendL(
                TResourceReader& aReader );

        /**
         * Sets contact action type. Contact action type is used to filter
         * xsp id fields according to data and service type.
         * 
         * @param aContactActionType contact action type
         */
        void SetContactActionType(TInt aContactActionType);

    public: // From MVPbkContactFieldSelector
        TBool IsFieldIncluded(
                const MVPbkBaseContactField& aField ) const;

    public: // From MVPbkFieldTypeSelector
        TBool IsFieldTypeIncluded(
                const MVPbkFieldType& aFieldType ) const;        

    private: // Implementation
        CVPbkFieldTypeSelector(
                const MVPbkFieldTypeList& aFieldTypeList );
        void CommonConstructL();
        void ConstructL(
                TResourceReader& aReader );
        void ConstructL(
                const CVPbkFieldTypeSelector& aSelector );
        void DoAppendL(
                TResourceReader& aReader );
        TInt CalculateBufferSize() const;
        void DoFillBufferL(
                RWriteStream& aWriteStream ) const;
        void SelectionPropertyReset();
        TBool IsFieldDataIncluded(
                const MVPbkBaseContactField& aField) const;
        TBool DoIsFieldDataIncludedL(
                const MVPbkBaseContactField& aField) const;        

    private: // Data
        /// Ref: Field type list to search for the field
        const MVPbkFieldTypeList& iFieldTypeList;
        
        /// Selection Property struct to associate
        /// excludes for versit properties
        struct TSelectionProperty;

        /// Own: selection properties
        RArray<TSelectionProperty> iSelectionProperties;

        /// Own: contact action type
        TInt iContactActionType;
    };

#endif // CVPBKFIELDTYPESELECTOR_H

// End of File

