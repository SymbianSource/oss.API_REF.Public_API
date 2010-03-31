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
* Description:  Virtual Phonebook base interface for contact field data. 
*                Sub classes have static Cast functions for safe casting.
*
*/


#ifndef MVPBKCONTACTFIELDDATA_H
#define MVPBKCONTACTFIELDDATA_H


// INCLUDES
#include <e32cmn.h>
#include <e32std.h>
#include <vpbkfieldtype.hrh>

// CONSTANTS

/// Constant indicating that field length is unlimited.
const TInt KVPbkUnlimitedFieldLength = -1;


// CLASS DECLARATIONS

/**
 * Virtual Phonebook field data interface.
 * Interface for contact field data. Different data type interfaces
 * are derived from this interface, which have data manipulation 
 * functionality.
 */
class MVPbkContactFieldData
    {
    public:  // Destructor
        /**
         * Destructor.
         */
        virtual ~MVPbkContactFieldData() { }

    public:  // New functions
        /**
         * Returns the derived data type id.
         * @return Contact field storage type.
         */
        virtual TVPbkFieldStorageType DataType() const =0;

        /**
         * Returns true if the storage is empty.
         * @return ETrue if the data field is empty.
         */
        virtual TBool IsEmpty() const =0;

        /**
         * Copies data from given field data.
         * @param aFieldData    Data that is copied to this object.
         * @precond aFieldData.DataType() == this->DataType()
         */
        virtual void CopyL(const MVPbkContactFieldData& aFieldData) =0;

        /**
         * Returns an extension point for this interface or NULL.
         * @param aExtensionUid Uid of extension.
         * @return Extension point or NULL.
         */
        virtual TAny* ContactFieldDataExtension(
                TUid /*aExtensionUid*/) { return NULL; }
    };

#endif  // MVPBKCONTACTFIELDDATA_H

// End of File
