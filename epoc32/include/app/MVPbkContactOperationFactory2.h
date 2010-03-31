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


#ifndef MVPBKCONTACTOPERATIONFACTORY2_H
#define MVPBKCONTACTOPERATIONFACTORY2_H

// INCLUDES
#include <e32cmn.h>
#include <bamdesca.h>
#include <BADESCA.H> 
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
const TUid KMVPbkContactOperationFactory2Uid = { 2 };

// CLASS DECLARATIONS

/**
 * A factory interface for asynchronous contact operations.
 * This interface is used to create contact operations.
 * This interface allows specific store operations.
 */
class MVPbkContactOperationFactory2
    {
    public:  // Factories
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
         * @param aStoreEntriesArray an array that lists the store entries.
         * @return A handle to the operation or NULL
         */
             virtual MVPbkContactOperation* CreateFindOperationL(
                const MDesC16Array& aSearchStrings, 
                const MVPbkFieldTypeList& aFieldTypes, 
                MVPbkContactFindFromStoresObserver& aObserver, 
                const TCallBack& aWordParserCallBack,
                const CDesC16ArrayFlat& aStoreEntriesArray ) = 0;    
  	};
#endif // MVPBKCONTACTOPERATIONFACTORY2_H

// End of File
