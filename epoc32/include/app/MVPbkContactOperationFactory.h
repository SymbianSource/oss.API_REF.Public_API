/*
* Copyright (c) 2004-2007 Nokia Corporation and/or its subsidiary(-ies).
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
* Description:  Virtual Phonebook factory interface for asynchronous 
*                contact operations.
*
*/

// 

#ifndef MVPBKCONTACTOPERATIONFACTORY_H
#define MVPBKCONTACTOPERATIONFACTORY_H

// INCLUDES
#include <e32cmn.h>
#include <bamdesca.h>

// FORWARD DECLARATIONS
class MVPbkContactOperation;
class MVPbkContactLink;
class MVPbkContactLinkArray;
class MVPbkStoreContact;
class MVPbkSingleContactOperationObserver;
class MVPbkBatchOperationObserver;
class MVPbkContactFindObserver;
class MVPbkFieldTypeList;
class MVPbkContactFindFromStoresObserver;

// CLASS DECLARATIONS

/**
 * A factory interface for asynchronous contact operations.
 * This interface is used to create contact operations.
 */
class MVPbkContactOperationFactory
    {
    public:  // Factories
        /**
         * Creates an operation for contact retrieval.
         *
         * @param aLink A link to the contact
         * @param aObserver An observer for the operation.
         * @return A handle to the operation or NULL if the factory
         *         doesn't have reference to the store of the link.
         */
        virtual MVPbkContactOperation* CreateContactRetrieverL(
                const MVPbkContactLink& aLink,
                MVPbkSingleContactOperationObserver& aObserver) =0;

        /**
         * Creates an operation for deleting multiple contacts.
         *
         * @param aContactLinks An array of contact links that specify 
         *                      the contacts.
         * @param aObserver An observer for the operation.
         * @return A handle to the operation or NULL
         */
        virtual MVPbkContactOperation* CreateDeleteContactsOperationL(
                const MVPbkContactLinkArray& aContactLinks, 
                MVPbkBatchOperationObserver& aObserver ) =0;

        /**
         * Creates an operation for committing multiple contacts.
         *
         * @param aContacts An array of contact links that specify
         *                  the contacts
         * @param aObserver An observer for the operation.
         * @return A handle to the operation or NULL
         */
        virtual MVPbkContactOperation* CreateCommitContactsOperationL(
                const TArray<MVPbkStoreContact*>& aContacts,
                MVPbkBatchOperationObserver& aObserver) =0;

        /**
         * Creates an operation for asynchronous phone number matching.
         * 
         * @param aPhoneNumber  A phone number to search for.
         * @param aMaxMatchDigits   Maximum number of digits to match from 
         *                          the end of the number.
         * @param aObserver Observer for the find process.
         * @return A handle to the operation or NULL
         */
        virtual MVPbkContactOperation* CreateMatchPhoneNumberOperationL(
                const TDesC& aPhoneNumber, 
                TInt aMaxMatchDigits,
                MVPbkContactFindObserver& aObserver) =0;

        /**
         * Creates an operation for asynchronous contact finding.
         *
         * @param aSearchString String to search for.
         * @param aFieldTypes   List of field types that the search will include.
         * @param aObserver Observer for the find process.
         * @return A handle to the operation or NULL
         */
        virtual MVPbkContactOperation* CreateFindOperationL(
                const TDesC& aSearchString,
                const MVPbkFieldTypeList& aFieldTypes,
                MVPbkContactFindObserver& aObserver) =0;
        
        /**
         * Creates an operation for asynchronous contact finding.
         * Finds a string containing text that is stored in one or more fields.
         * Client can give multiple find words. All the words must match to separated
         * data. E.g if there are two find words: "Jo" and "Jo" then field data
         * "John Johnson" matches but "John Doe" doesn't if the word parser uses
         * white space as a word separator.
         *
         * NOTE: The accuracy of the results depends on the ability of the store
         *       implementation to implement the find. The performance can vary
         *       too depending on the store. 
         *
         * @param aSearchStrings    Words that are compared to field data.
         * @param aFieldTypes   Types of the fields that are used.
         * @param aObserver An observer for asynchronous operation.
         * @param aWordParserCallBack a client implementation of word parser 
         *                            function that separates the field data 
         *                            into words. Parameter to function is 
         *                            TVPbkWordParserParam.
         * @return A handle to the operation or NULL
         */
        virtual MVPbkContactOperation* CreateFindOperationL(
                const MDesC16Array& aSearchStrings, 
                const MVPbkFieldTypeList& aFieldTypes, 
                MVPbkContactFindFromStoresObserver& aObserver, 
                const TCallBack& aWordParserCallBack ) =0;
            
        /**
         * Creates an operation for compressing the store.
         *
         * @param aObserver An observer for the compress operation.
         * @return A handle to the operation or NULL
         */
        virtual MVPbkContactOperation* CreateCompressStoresOperationL(
        		MVPbkBatchOperationObserver& aObserver) = 0;

        /**
         * Returns an extension point for this interface or NULL.
         * @param aExtensionUid Uid of extension.
         * @return Extension point or NULL.
         */
        virtual TAny* ContactOperationFactoryExtension(
                TUid /*aExtensionUid*/) { return NULL; }
    };

#endif // MVPBKCONTACTOPERATIONFACTORY_H

// End of File
