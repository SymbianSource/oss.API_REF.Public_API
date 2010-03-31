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
* Description:  Virtual Phonebook interface for binary contact field data.
*
*/


#ifndef MVPBKCONTACTFIELDBINARYDATA_H
#define MVPBKCONTACTFIELDBINARYDATA_H

// INCLUDES
#include <mvpbkcontactfielddata.h>


// CLASS DECLARATIONS

/**
 * Virtual Phonebook binary field data.
 * This interface is used to manipulate binary contact field data.
 */
class MVPbkContactFieldBinaryData : public MVPbkContactFieldData
    {
    public:  // Destructor
        /**
         * Destructor.
         */
        virtual ~MVPbkContactFieldBinaryData() { }


    public:  // from MVPbkContactFieldData
        TVPbkFieldStorageType DataType() const
            {
            return EVPbkFieldStorageTypeBinary;
            }

    public:  // Interface
        /**
         * Casts MVPbkContactFieldData to this interface.
         *
         * @precond aFieldData.DataType() == EVPbkFieldStorageTypeBinary
         *          VPbkError::Panic(VPbkError::EFieldDataTypeMismatch)
         *          is raised if the precondition does not hold.
         * @param aFieldData    Data of the field.
         * @return Casted inteface for the binary field data.
         */
        IMPORT_C static MVPbkContactFieldBinaryData& Cast(
                MVPbkContactFieldData& aFieldData );

        /**
         * Casts const MVPbkContactFieldData to this interface.
         *
         * @precond aFieldData.DataType() == EVPbkFieldStorageTypeBinary
         *          VPbkError::Panic(VPbkError::EFieldDataTypeMismatch)
         *          is raised if the precondition does not hold.
         * @param aFieldData    Data of the field.
         * @return Casted inteface for the binary field data.
         */
        IMPORT_C static const MVPbkContactFieldBinaryData& Cast(
                const MVPbkContactFieldData& aFieldData );

        /**
         * Returns the binary data pointer.
         * @return Pointer to binary data.
         */
        virtual TPtrC8 BinaryData() const =0;

        /**
         * Sets the binary data.
         * @exception KErrOverflow if (aBinaryData.Length() > MaxLength())
         * @param aBinaryData   Binary data to be set.
         */
        virtual void SetBinaryDataL( const TDesC8& aBinaryData ) = 0;

        /**
         * Returns maximum length of the field.
         * @return Maximum length of the field or KVPbkUnlimitedFieldLength 
         *         if length is only limited by available memory.
         */
        virtual TInt MaxLength() const { return KVPbkUnlimitedFieldLength; }        

        /**
         * Returns an extension point for this interface or NULL.
         * @param aExtensionUid Uid of extension.
         * @return Extension point or NULL.
         */
        virtual TAny* ContactFieldBinaryDataExtension( 
                TUid /*aExtensionUid*/ ) { return NULL; }

    };

#endif  // MVPBKCONTACTFIELDBINARYDATA_H

// End of File
