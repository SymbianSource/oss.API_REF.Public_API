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
* Description:  The vcard engine for importing/exporting vcards and compact
*                business cards.
*
*/


#ifndef CVPBKVCARDENG_H
#define CVPBKVCARDENG_H


// INCLUDES
#include <e32base.h>
#include <f32file.h>
#include <s32file.h>

// FORWARD DECLARATIONS
class MVPbkFieldTypeList;
class CVPbkContactManager;
class MVPbkStoreContact;
class MVPbkFieldType;
class MVPbkContactOperationBase;
class MVPbkSingleContactOperationObserver;
class MVPbkContactCopyObserver;
class MVPbkContactLink;
class MVPbkContactStore;
class CVPbkVCardData;

// CLASS DECLARATIONS

/**
 * The vcard engine for importing/exporting vcards and compact business cards.
 * 
 * @lib VPbkVCardEng.lib
 */
class CVPbkVCardEng : public CBase
    {
    public:  // Constructors and destructor
        /**
         * Creates VCard engine instance.
         * @param aContactManager The Contact manager.
         * @return A new instance of the CVPbkVCardEng.
         */
        IMPORT_C static CVPbkVCardEng* NewL(
                CVPbkContactManager& aContactManager);

        /**
         * Destructor.
         */
        ~CVPbkVCardEng();

    public: // New methods

        /**
         * Reads vCard records from a stream and saves contacts to the store
         * asynchronously. 
         * 
         * A client receives links to the created contacts in a call back.
         *
         * @param aTargetStore The Virtual Phonebook store in which the 
         *                     information is copied to. The store must be 
         *                     writable.
         * @param aSourceStream A stream where the vCard data is read from
         * @param aObserver The observer who is notified when the import
         *                  completes. Failed cases:
         *                  -KErrNotFound if the card contained fields that
         *                  cannot be saved to the target store i.e. 
         *                  the operation didn't find any fields to copy.
         * @return A new operation handle owned by the client.
         * @exception KErrNotFound if the engine didn't find a copy policy
         *                         for the target store.
         * @asynchronous
         */
        IMPORT_C MVPbkContactOperationBase* ImportVCardL(
                MVPbkContactStore& aTargetStore, 
                RReadStream &aSourceStream,
                MVPbkContactCopyObserver& aObserver);
                
        /**
         * Reads vCard records from a stream and saves contacts to the store
         * asynchronously. 
         * 
         * A client receives links to the created contacts in a call back.
         * NOTE: This API is introduced for performance improvements in sync.
         *       When imported for Sync the duplicate policy checks are ignored.
         *
         * @param aTargetStore The Virtual Phonebook store in which the 
         *                     information is copied to. The store must be 
         *                     writable.
         * @param aSourceStream A stream where the vCard data is read from
         * @param aObserver The observer who is notified when the import
         *                  completes. Failed cases:
         *                  -KErrNotFound if the card contained fields that
         *                  cannot be saved to the target store i.e. 
         *                  the operation didn't find any fields to copy.
         * @return A new operation handle owned by the client.
         * @exception KErrNotFound if the engine didn't find a copy policy
         *                         for the target store.
         * @asynchronous
         */        
        IMPORT_C MVPbkContactOperationBase* ImportVCardForSyncL(
                MVPbkContactStore& aTargetStore, 
                RReadStream &aSourceStream,
                MVPbkContactCopyObserver& aObserver);                
                
        /**
         * Reads vCard records from a stream and creates contacts
         * asynchronously. 
         *
         * A client handles commiting the contact(s). Otherwise contacts
         * are not saved to the store.
		 *
		 * @param aImportedContact An array for imported contacts from
		 *                         the client. Contains results after
		 *                         asynchronous import operation has completed.
		 * @param aTargetStore The Virtual Phonebook Store in which the 
		 *                     information is copied to. The store must be 
		 *                     writable.
         * @param aSourceStream A stream where the vCard data is read from.
         * @param aObserver An observer for asynchronous import.
         *                  The aContact in the call back is always NULL.
         * @return A new operation handle owned by the client.
         * @asynchronous
         */
        IMPORT_C MVPbkContactOperationBase* ImportVCardL(
                RPointerArray<MVPbkStoreContact>& aImportedContacts,
                MVPbkContactStore& aTargetStore, 
                RReadStream &aSourceStream,
                MVPbkSingleContactOperationObserver& aObserver );
            
              
        /**
         * Reads Compact Business Card records from a stream and saves
         * contacts to the store asynchronously. 
         *
         * A client receives links to the created contacts in a call back.
		 *
		 * @param aTargetStore The Virtual Phonebook Store in which the 
		 *                     information is copied to. The store must be 
		 *                     writable.
         * @param aSourceStream A stream where the card data is read from.
         * @param aObserver An observer for asynchronous import.
         *                  If successful there is one or more contact
         *                  links in the array. Failed cases:
         *                  -KErrNotSupported if the card is not compact 
         *                  business card
         *                  -KErrCorrupted if the data is corrupted
         *                  -KErrNotFound if there were no supported fields
         *                  in the card.
         * @return A new operation handle owned by the client.
         * @exception KErrNotFound if the engine didn't find a copy policy
         *                         for the target store.
         * @asynchronous
         */
        IMPORT_C MVPbkContactOperationBase* ImportCompactBusinessCardL(
            MVPbkContactStore& aTargetStore,
			RReadStream &aSourceStream,
            MVPbkContactCopyObserver& aObserver );
        
        /**
         * Reads Compact Business Card records from a stream and creates
         * contacts asynchronously. 
         *
         * A client handles commiting the contact(s). Otherwise contacts
         * are not saved to the store.
		 *
		 * @param aImportedContact An array for imported contacts from
		 *                         the client. Contains results after
		 *                         asynchronous import operation has completed. 
		 * @param aTargetStore The Virtual Phonebook Store in which the 
		 *                     contacts are created from. The store must be 
		 *                     writable.
         * @param aSourceStream A stream where the card data is read from.
         * @param aObserver An observer for asynchronous import.
         *                  aContact is always NULL in call back.
         *                  If successful there is one or more contact
         *                  links in the array. Failed cases:
         *                  -KErrNotSupported if the card is not compact 
         *                  business card
         *                  -KErrCorrupted if the data is corrupted
         *                  -KErrNotFound if there were no supported fields
         *                  in the card.
         * @return A new operation handle owned by the client.
         * @exception KErrNotFound if the engine didn't find a copy policy
         *                         for the target store.
         * @asynchronous
         */
        IMPORT_C MVPbkContactOperationBase* ImportCompactBusinessCardL(
            RPointerArray<MVPbkStoreContact>& aImportedContacts,
            MVPbkContactStore& aTargetStore,
			RReadStream &aSourceStream,
            MVPbkSingleContactOperationObserver& aObserver );

        /**
         * Exports contact information asynchronously to a vCard record.
		 *
		 * The client gives the contact whose information is exported.
		 *
		 * @param aDestStream A stream where the vCard data is written to.
		 *        The data written to the stream is not Committed by this method.
		 * @param aSourceItem A contact whose information is exported.
         * @param aObserver An observer that is notified when the export completes.
         *          A store contact returned when operation has completed is
         *          always NULL.
         * @param aBeamed If ETrue, then select fields are masked while exporting VCard
         * @return A new operation handle owned by the client.
         * @asynchronous
         */
        IMPORT_C MVPbkContactOperationBase* ExportVCardL( 
            RWriteStream& aDestStream, 
            const MVPbkStoreContact& aSourceItem,
            MVPbkSingleContactOperationObserver& aObserver);

        /**
         * Exports contact information asynchronously to a vCard record.
         * 
         * The client gives the identifier of the contact that is first loaded
         * and then exported.
         *
         * @param aDestStream A stream where the vCard data is written to.
         *        The data written to the stream is not Commited by this method.
         * @param aContactLink An identifier of the contact that is exported.
         * @param aObserver An observer that is notified when the export completes.
         *          A store contact returned when operation has completed is
         *          always NULL.
         * @param aBeamed If ETrue, then select fields are masked while exporting VCard
         * @return A new operation handle owned by the client.
         * @asynchronous
         */
        IMPORT_C MVPbkContactOperationBase* ExportVCardL(
            RWriteStream& aDestStream, 
            const MVPbkContactLink& aContactLink,
            MVPbkSingleContactOperationObserver& aObserver);
            
        /**
        * Exports contact information asynchronously to a vCard record.
         * Note: Includes the fields, X-FAVORITE and X-SELF, during export
         *
         * The client gives the contact whose information is exported.
         *
         * @param aDestStream A stream where the vCard data is written to.
         *        The data written to the stream is not Committed by this method.
         * @param aSourceItem A contact whose information is exported.
        * @param aObserver An observer that is notified when the export completes.
        *          A store contact returned when operation has completed is
        *          always NULL.
        * @return A new operation handle owned by the client.
        * @asynchronous
        */
        IMPORT_C MVPbkContactOperationBase* ExportVCardForSyncL( 
            RWriteStream& aDestStream, 
            const MVPbkStoreContact& aSourceItem,
            MVPbkSingleContactOperationObserver& aObserver);

        /**
         * Exports contact information asynchronously to a vCard record.
         * Note: Includes the fields, X-FAVORITE and X-SELF, during export
         * 
         * The client gives the identifier of the contact that is first loaded
         * and then exported.
         *
         * @param aDestStream A stream where the vCard data is written to.
         *        The data written to the stream is not Commited by this method.
         * @param aContactLink An identifier of the contact that is exported.
         * @param aObserver An observer that is notified when the export completes.
         *          A store contact returned when operation has completed is
         *          always NULL.
         * @return A new operation handle owned by the client.
         * @asynchronous
         */
        IMPORT_C MVPbkContactOperationBase* ExportVCardForSyncL(
            RWriteStream& aDestStream, 
            const MVPbkContactLink& aContactLink,
            MVPbkSingleContactOperationObserver& aObserver);
            
                    
        /** 
         * Returns true for those field types that are supported by the vCard
         * format and this engine.
         *
         * @param aFieldType A field type that is looked for.
         * @return ETrue if given field is supported, EFalse otherwise
         */
        IMPORT_C TBool SupportsFieldType(const MVPbkFieldType& aFieldType);


        /**
         * Returns field types that are supported by vCard engine.
         *
         * @return Field types that are supported by vCard engine.
         */
        IMPORT_C const MVPbkFieldTypeList& SupportedFieldTypes();
        
        /**
         * Reads vCard records from a stream and replaces contacts
         * asynchronously. 
         *
         * A client handles commiting the contact(s). Otherwise contacts
         * are not saved to the store.
		 *
		 * @param aReplaceContact Current contact which needs to replaced with
		 *                         the contact recevied from server as VcardBuffer. Contains results after
		 *                         asynchronous import operation has completed.
		 * @param aTargetStore The Virtual Phonebook Store in which the 
		 *                     information is copied to. The store must be 
		 *                     writable.
         * @param aSourceStream A stream where the vCard data is read from.
         * @param aObserver An observer for asynchronous import.
         *                  The aContact in the call back is always NULL.
         * @return A new operation handle owned by the client.
         * @asynchronous
         */   
        IMPORT_C MVPbkContactOperationBase* CVPbkVCardEng::ImportVCardMergeL(
            const MVPbkContactLink& aReplaceContact,
            MVPbkContactStore& aTargetStore, 
            RReadStream& aSourceStream,
            MVPbkSingleContactOperationObserver& aObserver );

    private: // Implementation
        CVPbkVCardEng(CVPbkContactManager& aContactManager);
        void ConstructL();

    private: // Data
        /// Ref: Contact manager reference
        CVPbkContactManager&                        iContactManager;
        /// Own: Data for vCard handling
        CVPbkVCardData*                             iData;
    };


#endif  // CVPBKVCARDENG_H

// End of file
