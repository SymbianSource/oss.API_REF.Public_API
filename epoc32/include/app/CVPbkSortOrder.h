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
* Description:  Virtual Phonebook sort order that is needed in view creation.
*
*/


#ifndef CVPBKSORTORDER_H
#define CVPBKSORTORDER_H

// INCLUDES
#include <e32base.h>
#include <mvpbkfieldtype.h>

// FORWARD DECLARATIONS
class TResourceReader;

/**
 * Virtual Phonebook sort order.
 * This class can be used to create a sort order, which is needed
 * when creating Virtual Phonebook views. The sort order determines
 * how the view is sorted by setting a field type priority list.
 */
class CVPbkSortOrder : 
        public CBase,
        public MVPbkFieldTypeList
    {
    public:
        /**
         * Constructs new sort order from a 
         * VPBK_FIELD_TYPE_MAPPING_LIST resource.
         *
         * @param aReader   Resource reader pointing to a 
         *                  VPBK_FIELD_TYPE_MAPPING_LIST resource.
         * @param aMasterFieldTypeList  Master field type list types from 
         *                              the resource are mapped against.
         * @exception   KErrNotFound if a matching field type is not 
         *              found from aFieldTypeList.
         */
        IMPORT_C static CVPbkSortOrder* NewL(
                TResourceReader& aReader, 
                const MVPbkFieldTypeList& aMasterFieldTypeList);

        /**
         * Creates a new sort order from an existing one.
         *
         * @param aSortOrder    The sort order to duplicate.
         */
        IMPORT_C static CVPbkSortOrder* NewL(
                const MVPbkFieldTypeList& aSortOrder);

        /**
         * Destructor.
         */
        ~CVPbkSortOrder();

    public: // Interface
        /**
         * Reserves aSortOrderLength items for the sort order length.
         * This quarantees that following Set() call will not leave because of
         * memory allocation failure. If more than aSortOrderLength items are
         * provided in following Set() calls, rest of the field types are ignored.
         *
         * @param aSortOrderLength  Number of field types to reserve space for.
         * @exception Panics if aSortOrderLength <= 0
         */
        IMPORT_C void SetReserveL(TInt aSortOrderLength);

        /**
         * Sets new fields types for this sort order from the list.
         * This will not leave because SetReserveL has to be called in advance to
         * reserve space for sort order field types.
         *
         * @param aSortOrder    Priority ordered list of field types 
         *                      used as the sort order.
         * @precond SetReserveL called with a proper sort order length.
         */
        IMPORT_C void Set(const MVPbkFieldTypeList& aSortOrder);

    public: // From MVPbkFieldTypeList
        TInt FieldTypeCount() const;
        const MVPbkFieldType& FieldTypeAt(TInt aIndex) const;
        TBool ContainsSame(const MVPbkFieldType& aFieldType) const;
        TInt MaxMatchPriority() const;
        const MVPbkFieldType* FindMatch(const TVPbkFieldVersitProperty& aMatchProperty,
                TInt aMatchPriority) const;
        const MVPbkFieldType* FindMatch(
                TVPbkNonVersitFieldType aNonVersitType) const;
        const MVPbkFieldType* Find(TInt aFieldTypeResId) const;

    private: // Implementation
        CVPbkSortOrder();
        void ConstructL(TResourceReader& aReader, 
                const MVPbkFieldTypeList& aMasterFieldTypeList);
        void ConstructL(const MVPbkFieldTypeList& aSortOrder);

    private:
        ///Own: Maximum sort order length
        TInt iMaxSortOrderLength;
        ///Ref: Sort order array
        RPointerArray<MVPbkFieldType> iSortOrder;
        ///Own: Max match priority
        TInt iMaxMatchPriority;
    };

#endif // CVPBKSORTORDER_H

// End of file
