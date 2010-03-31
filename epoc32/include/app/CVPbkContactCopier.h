/*
* Copyright (c) 2006-2007 Nokia Corporation and/or its subsidiary(-ies).
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
* Description:  Virtual Phonebook contact copier
*
*/


#ifndef CVPBKCONTACTCOPIER_H
#define CVPBKCONTACTCOPIER_H

#include <e32base.h>

class MVPbkContactOperationBase;
class MVPbkContactLinkArray;
class MVPbkContactStore;
class MVPbkBatchOperationObserver;
class CVPbkContactManager;
class CVPbkContactLinkArray;

/**
 * Virtual Phonebook contact copier. Copies source
 * contacts to the target store according to copying rules.
 *
 * @lib VPbkEng.lib
 */
class CVPbkContactCopier : public CBase
    {
    public:
        /**
         * A set of flags for copying. Fastest copy is EVPbkSimpleContactCopy.
         */
        enum TVPbkContactCopyFlags
            {
            /// Copies a field if the target store supports the field type.
            /// Does not perform additional checks. 
            EVPbkSimpleContactCopy                      = 0,
            /// Uses a store specific copy policy if found for the target store.
            /// Can do e.g field type conversion between source and target field
            /// types. Falls back to simple copy if the copy policy was not found
            /// for the store.
            EVPbkUseStoreSpecificCopyPolicy             = 0x01,
            /// Finds duplicates before saving a contact if there is a copy policy
            /// for the store that can handle the possible merge of
            /// new and existing contact data. Falls back to simple copy if
            /// the copy policy was not found for the store.
            EVPbkUsePlatformSpecificDuplicatePolicy     = 0x02
            };

        /**
         * Creates a new copier instance. Remember to open the stores first
         * before starting any copy operation.
         *
         * @param aContactManager   The contact manager for getting stores.
         * @return A new instance of this class
         */        
        IMPORT_C static CVPbkContactCopier* NewL( 
            CVPbkContactManager& aContactManager );
        
        /**
         * Destructor.
         */
        ~CVPbkContactCopier();

        /**
         * Copies a set of contacts to the target store.
         *
         * @param aContactCopyFlags     A set of TVPbkContactCopyFlags
         * @param aSourceContactLinks   Source contact links
         * @param aTargetStore          Target of the copy operation.
         *                              If NULL this behaves like duplicate.
         * @param aCopiedContactLinks   The results of the copy. Copied contacts
         *                              are added to this array.
         * @param aObserver             An observer for asynchronous operation
         * @return A copy contact operation
         */
        IMPORT_C MVPbkContactOperationBase* CopyContactsL(
            TUint32 aContactCopyFlags,
            const MVPbkContactLinkArray& aSourceContactLinks,
            MVPbkContactStore* aTargetStore,
            CVPbkContactLinkArray& aCopiedContactLinks,
            MVPbkBatchOperationObserver& aObserver );

    private:

        CVPbkContactCopier( CVPbkContactManager& aContactManager );
    
    private: // data
        /// Ref: The contact manager for accessing stores
        CVPbkContactManager& iContactManager;
    };

#endif // CVPBKCONTACTCOPIER_H
