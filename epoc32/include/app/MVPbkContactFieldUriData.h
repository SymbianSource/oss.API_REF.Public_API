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
* Description:  Virtual Phonebook interface for URI data of the contact field.
*
*/


#ifndef MVPBKCONTACTFIELDURIDATA_H
#define MVPBKCONTACTFIELDURIDATA_H


// INCLUDES
#include <mvpbkcontactfielddata.h>

// CLASS DECLARATIONS

/**
 * Virtual Phonebook Contact field URI data.
 * This interface is used to manipulate URI contact field data.
 */
class MVPbkContactFieldUriData : public MVPbkContactFieldData
    {
    public:  // Destructor
        /**
         * Destructor.
         */
        virtual ~MVPbkContactFieldUriData() { }

    public:  // from MVPbkContactFieldData
        TVPbkFieldStorageType DataType() const
            {
            return EVPbkFieldStorageTypeUri;
            }

    public:  // Interface
        /**
         * Casts MVPbkContactFieldData to this interface.
         *
         * @precond aFieldData.DataType() == EVPbkFieldStorageTypeUri
         *          VPbkError::Panic(VPbkError::EFieldDataTypeMismatch)
         *          is raised if the precondition does not hold.
         * @param aFieldData    Data of the field.
         * @return Casted inteface for the text field data.
         */
        IMPORT_C static MVPbkContactFieldUriData& Cast(
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
        IMPORT_C static const MVPbkContactFieldUriData& Cast(
                const MVPbkContactFieldData& aFieldData);

        /**
         * Returns the URI scheme.
         * @return Pointer to the URI scheme.
         */
        virtual TPtrC Scheme() const = 0;

        /**
         * Returns the URI .
         * @return Pointer to the URI text.
         */
        virtual TPtrC Text() const = 0;

        /**
         * Returns the string data.
         * @return Pointer to the whole URI.
         */
        virtual TPtrC Uri() const = 0;

        /**
         * Sets the URI data.
         * @exception KErrOverflow if (aUri.Length() > MaxLength())
         */
        virtual void SetUriL(const TDesC& aUri) = 0;

        /**
         * Sets the URI data.
         * @exception KErrOverflow if (aScheme.Length() + aText.Length()
         *              + 1 > MaxLength())
         */
        virtual void SetUriL(const TDesC& aScheme, const TDesC& aText) = 0;

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

#endif  // MVPBKCONTACTFIELDURIDATA_H

// End of File
