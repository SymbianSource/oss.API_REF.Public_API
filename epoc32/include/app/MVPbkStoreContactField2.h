/*
* Copyright (c) 2009 Nokia Corporation and/or its subsidiary(-ies).
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
* Description:  An interface for the field of the store contact
*
*/

#ifndef MVPBKSTORECONTACTFIELD2_H
#define MVPBKSTORECONTACTFIELD2_H

// INCLUDES
#include <e32base.h>

// CONSTANTS

// Use this UID to access store contact field extension 2.
// Used as a parameter to StoreContactFieldExtension() method.
const TUid KMVPbkStoreContactFieldExtension2Uid = { 2 };

// FORWARD DECLARATIONS

class CVPbkContactManager;

// CLASS DECLARATIONS

/**
 * This class is an extension to MVPbkStoreContactField.
 * See documentation of MVPbkStoreContactField from header
 * MVPbkStoreContactField.h
 *
 *
 * @see MVPbkStoreContactField
 *
 */
class MVPbkStoreContactField2
    {
    public:  // Interface

        /**
         * Get the speed dial indexes of contact field.
         *
         * @param aContactManager Contact manager.
         * @return Array of indexes or NULL. Caller takes ownership of
         * the returned object.
         */
        virtual CArrayFix<TInt>* SpeedDialIndexesL() = 0;

    protected: // Protected destructor

        ~MVPbkStoreContactField2() { }

    };


#endif  // MVPBKSTORECONTACTFIELD_H

// End of file

