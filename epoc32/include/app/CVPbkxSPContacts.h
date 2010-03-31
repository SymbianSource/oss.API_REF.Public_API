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
* Description:  xSP contacts
 *
*/


#ifndef VPBKXSPCONTACTS_H
#define VPBKXSPCONTACTS_H

// INCLUDES
#include <e32base.h>

// FORWARD DECLARATIONS
class MVPbkContactLinkArray;
class CVPbkContactManager;
class MVPbkContactOperationBase;
class MVPbkStoreContact;
template<typename T> class MVPbkOperationResultObserver;
class MVPbkOperationErrorObserver;

class CVPbkxSPContactsImpl;

// CLASS DECLARATION

/**
 * A class for fetching xSP Contacts.
 * Operations are asynchronous and accept two observers.
 * One used to signal completion and return result.
 * Another one used to signal an error if operation fails.
 *
 * @example
 * A client fetch xSP contactlinks for given contact.
 *
 * class CxSPContactsClient :
 *   public CActive, 
 *   public MVPbkOperationErrorObserver,
 *   public MVPbkOperationResultObserver<MVPbkContactLinkArray*>
 *    ...
 *
 * void CxSPContactsClient::FetchxSPLinksL()
 *   {
 *   ixSPManager = CVPbkxSPContacts::NewL( iContactManager );                                                              
 *   ixSPContactOperation = ixSPManager->GetxSPContactLinksL(*iContact, *this, *this);
 *   }
 * 
 * 
 * //From MVPbkOperationErrorObserver
 * void CxSPContactsClient::VPbkOperationFailed(
 *       MVPbkContactOperationBase*,
 *       TInt aError )
 *   {
 *   ...
 *   }
 *
 * // From MVPbkOperationResultObserver
 * void CxSPContactsClient::VPbkOperationResultCompleted(
 *       MVPbkContactOperationBase*,
 *       MVPbkContactLinkArray* aArray )
 *   {
 *   TInt count = aArray->Count(); 
 *   for(TInt a = 0; a < count; a++)
 *       {
 *       const MVPbkContactLink& link = aArray->At(a);
 *       ... do something
 *       } 
 *   }
 */

NONSHARABLE_CLASS( CVPbkxSPContacts ) : public CBase
    {
public:

    /**
     * Creates the xsp contacts fetcher.
     * @param aContactManager Contact manager which already has its stores opened.
     */
    IMPORT_C static CVPbkxSPContacts* NewL( CVPbkContactManager& aContactManager );
    IMPORT_C ~CVPbkxSPContacts();

public:

    /**
     * Get xSP contacts as contact link array for given contact.
     * If contact doesn't have any xSP contactlinks, 
     * empty contact link array will be returned.
     * If aContact is NULL, KErrArgument is notified via MVPbkOperationErrorObserver.
     * 
     * @param aContact The contact
     * @param aResultObserver The observer that gets xsp contact links array.
     * @param aErrorObserver The observer for error notification. 
     */
    IMPORT_C MVPbkContactOperationBase* GetxSPContactLinksL(
            const MVPbkStoreContact& aContact,
            MVPbkOperationResultObserver<MVPbkContactLinkArray*>& aResultObserver,
            MVPbkOperationErrorObserver& aErrorObserver );

private: // construction
    CVPbkxSPContacts();

private: // data
    CVPbkxSPContactsImpl* iImpl;
    };

#endif //VPBKXSPCONTACTS_H
//End of file
