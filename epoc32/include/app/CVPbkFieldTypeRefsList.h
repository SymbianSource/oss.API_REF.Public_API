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
* Description:  An list for field type references. Implements 
*                MVPbkFieldTypeList so can be used e.g. as parameter to Find
*                operation.
*
*/


#ifndef CVPBKFIELDTYPEREFSLIST_H
#define CVPBKFIELDTYPEREFSLIST_H

// INCLUDES
#include <e32base.h>
#include <mvpbkfieldtype.h>

// CLASS DECLARATIONS

/**
 * A collection of referenced Virtual Phonebook field types.
 */
class CVPbkFieldTypeRefsList : public CBase, public MVPbkFieldTypeList
    {
    public:  // Constructors and destructor
        /**
         * Creates a new instance of this class.
         */
        IMPORT_C static CVPbkFieldTypeRefsList* NewL();

        /**
         * Destructor.
         */        
        ~CVPbkFieldTypeRefsList();

        /**
         * Append a referenced field type.
         *
         * @param aFieldType    Virtual Phonebook field type.
         */
        IMPORT_C void AppendL(const MVPbkFieldType& aFieldType);

        /**
         * Remove aFieldType from this reference list.
         *
         * @param aFieldType    The type to be removed
         */
        IMPORT_C void Remove(const MVPbkFieldType& aFieldType);
        
        /**
         * Resets the array.
         */
        IMPORT_C void Reset();


    public: // from MVPbkFieldTypeList
        TInt FieldTypeCount() const;
        const MVPbkFieldType& FieldTypeAt(TInt aIndex) const;
        TBool ContainsSame(const MVPbkFieldType& aFieldType) const;
        TInt MaxMatchPriority() const;
        const MVPbkFieldType* FindMatch
            (const TVPbkFieldVersitProperty& aMatchProperty,
            TInt aMatchPriority) const;
        const MVPbkFieldType* FindMatch
            (TVPbkNonVersitFieldType aNonVersitType) const;
        const MVPbkFieldType* Find(TInt aFieldTypeResId) const;

    private:  // Implementation
        CVPbkFieldTypeRefsList();

    private: // Data
        ///Ref: reference to virtual phonebook field types
        RPointerArray<MVPbkFieldType> iFieldTypes;
        ///Own: max match priority
        TInt iMaxMatchPriority;
    };

#endif // CVPBKFIELDTYPEREFSLIST_H

//End of file
