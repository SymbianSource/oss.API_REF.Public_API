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
* Description:  Virtual Phonebook interface for text data of the contact field.
*
*/


#ifndef MVPBKCONTACTFIELDTEXTDATA_H
#define MVPBKCONTACTFIELDTEXTDATA_H


// INCLUDES
#include <mvpbkcontactfielddata.h>

// CLASS DECLARATIONS

/**
 * Virtual Phonebook Contact field text data.
 * This interface is used to manipulate text contact field data.
 */
class MVPbkContactFieldTextData : public MVPbkContactFieldData
    {
    public:  // Destructor
        /**
         * Destructor.
         */
        virtual ~MVPbkContactFieldTextData() { }

    public:  // from MVPbkContactFieldData
        TVPbkFieldStorageType DataType() const
            {
            return EVPbkFieldStorageTypeText;
            }

    public:  // Interface
        /**
         * Casts MVPbkContactFieldData to this interface.
         *
         * @precond aFieldData.DataType() == EVPbkFieldStorageTypeText
         *          VPbkError::Panic(VPbkError::EFieldDataTypeMismatch)
         *          is raised if the precondition does not hold.
         * @param aFieldData    Data of the field.
         * @return Casted inteface for the text field data.
         */
        IMPORT_C static MVPbkContactFieldTextData& Cast(
                MVPbkContactFieldData& aFieldData);

        /**
         * Casts const MVPbkContactFieldData to this interface.
         *
         * @precond aFieldData.DataType() == EVPbkFieldStorageTypeText
         *          VPbkError::Panic(VPbkError::EFieldDataTypeMismatch)
         *          is raised if the precondition does not hold.
         * @param aFieldData    Data of the field.
         * @return Casted inteface for the text field data.
         */
        IMPORT_C static const MVPbkContactFieldTextData& Cast(
                const MVPbkContactFieldData& aFieldData);

        /**
         * Returns the string data.
         * @return Pointer to the text data.
         */
        virtual TPtrC Text() const = 0;

        /**
         * Sets the string data.
         * @exception KErrOverflow if (aText.Length() > MaxLength())
         */
        virtual void SetTextL( const TDesC& aText ) = 0;

        /**
         * Returns maximum length of the field.
         * @return Maximum length of the field or KVPbkUnlimitedFieldLength 
         *         if length is only limited by available memory.
         */
        virtual TInt MaxLength() const = 0;

        /**
         * Returns an extension point for this interface or NULL.
         * @param aExtensionUid Uid of extension.
         * @return Extension point or NULL.
         */
        virtual TAny* ContactFieldTextDataExtension(TUid /*aExtensionUid*/) { return NULL; }
    };

#endif  // MVPBKCONTACTFIELDTEXTDATA_H

// End of File
