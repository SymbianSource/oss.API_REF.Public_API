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
* Description:  Top Contact manager
*
*/


#ifndef VPBKTOPCONTACTMANAGER_H
#define VPBKTOPCONTACTMANAGER_H

// INCLUDES
#include <e32base.h>

// FORWARD DECLARATIONS
class MVPbkContactLink;
class MVPbkContactLinkArray;
class CVPbkContactLinkArray;
class CVPbkContactManager;
class MVPbkContactViewBase;
class MVPbkContactOperationBase;
class MVPbkBaseContact;
class MVPbkOperationObserver;
template<typename T>
class MVPbkOperationResultObserver;
class MVPbkOperationErrorObserver;

class CVPbkTopContactManagerImpl; 

// CLASS DECLARATION

/**
 * A class for managing Top Contact properties of contacts.
 * All main operations are asynchronous and accept two observers.
 * One used to signal completion and return result if necessary.
 * Another one used to signal an error if operation fails.
 *
 * @example
 * A client that re-orders the existing top contacts in the phone
 *
 * class CTopContactManagerClient :
 *   public CActive,
 *   public MVPbkOperationObserver,   
 *   public MVPbkOperationErrorObserver,
 *   public MVPbkOperationResultObserver<MVPbkContactViewBase*>
 *	  ...
 *
 * // MVPbkOperationObserver	  
 * void CTopContactManagerClient::VPbkOperationCompleted(
 *       MVPbkContactOperationBase*)
 *   {
 *   FinishCommand( KErrNone );
 *   }
 *
 * //From MVPbkOperationErrorObserver
 * void CTopContactManagerClient::VPbkOperationFailed(
 *       MVPbkContactOperationBase*,
 *       TInt aError )
 *   {
 *   FinishCommand( aError );
 *   }
 *
 * // From MVPbkOperationResultObserver
 * void CTopContactManagerClient::VPbkOperationResultCompleted(
 *       MVPbkContactOperationBase*,
 *       MVPbkContactViewBase* aView )
 *   {
 *   iView = aView;
 *   delete iTopContactOperation;
 *   iTopContactOperation = NULL;
 *   IssueRequest(EShowMoveDlg);
 *   }
 *  // --------------------------------------------------------------------------
 * // CTopContactManagerClient::RunL
 * // State Machine using TopContactManager
 * // --------------------------------------------------------------------------
 * //
 * void CTopContactManagerClient::RunL()
 *   {
 *   switch(iState)
 *   	{
 *   	case ELoadingTopContacts:
 *   		{
 *   		// This async call will fall into VPbkOperationResultCompleted on success with
 *   		// MVPbkContactOperationBase object as a result
 *   		// Otherwise, it will fall into VPbkOperationFailed callback
 *   		iTopContactOperation = iVPbkTopContactManager->GetTopContactsViewL(
 *   		        *this,
 *   		        *this );
 *   		break;
 *   		}
 *   	case EShowMoveDlg:
 *   		{
 *   		ShowDlgL(); // confirm re-ordering top contacts with user
 *   		break;
 *   		}
 *   	case ESavingTopContacts:
 *   		{
 *   		// Do re-ordering via Top Manager
 * 			// This async call will fall into VPbkOperationResultCompleted on success with
 *   		// MVPbkContactOperationBase object as a result
 *   		// Otherwise, it will fall into VPbkOperationFailed callback    		
 *   		iTopContactOperation = iVPbkTopContactManager->SetTopOrderL(
 *   		        *iTopContacts,
 *   		        *this,
 *   		        *this );
 *   		CleanupStack::PopAndDestroy(); //topContacts
 *   		break;
 *   		}
 *	  
 *     ...
 *    }
 * }     
 *
*/
NONSHARABLE_CLASS( CVPbkTopContactManager ) : public CBase
    {
    public:

    	/**
         * Creates the top contact manager.
    	 * @param aContactManager Contact manager which already has its stores opened.
    	 */
        IMPORT_C static CVPbkTopContactManager* NewL( CVPbkContactManager& aContactManager );

        /**
         * Creates the top contact manager.
         * Holds its own CVPbkContactManager instance.
         * 
         */
        IMPORT_C static CVPbkTopContactManager* NewL();
        
        IMPORT_C ~CVPbkTopContactManager();

    public:
        
        /**
         * Get top contacts as contact view.
         * 
         * If CVPbkTopContactManager was created without giving an external
         * contact manager as reference, then calling GetTopContactsViewL()
         * will open the default store if it is not already open.
         *
         * @param aResultObserver The observer that gets ready contacts view.
         * @param aErrorObserver The observer for error notification. 
         */
        IMPORT_C MVPbkContactOperationBase* GetTopContactsViewL(
                MVPbkOperationResultObserver<MVPbkContactViewBase*>& aResultObserver,
                MVPbkOperationErrorObserver& aErrorObserver);

        /**
         * Get NON-top contacts as contact view.
         * 
         * If CVPbkTopContactManager was created without giving an external
         * contact manager as reference, then calling GetNonTopContactsViewL()
         * will open the default store if it is not already open.
         *
         * @param aResultObserver The observer that gets ready contacts view.
         * @param aErrorObserver The observer for error notification. 
         */
        IMPORT_C MVPbkContactOperationBase* GetNonTopContactsViewL(
                MVPbkOperationResultObserver<MVPbkContactViewBase*>& aResultObserver,
                MVPbkOperationErrorObserver& aErrorObserver );

        /**
         * Get top contacts as contact link array.
         * 
         * @param aResultObserver The observer that gets top contact links array.
         * @param aErrorObserver The observer for error notification. 
         */        
        IMPORT_C MVPbkContactOperationBase* GetTopContactLinksL(
                MVPbkOperationResultObserver<MVPbkContactLinkArray*>&  aResultObserver,
                MVPbkOperationErrorObserver& aErrorObserver );

        /**
         * Get NON-top contacts as contact link array.
         * 
         * @param aResultObserver The observer that gets non-top contact links array.
         * @param aErrorObserver The observer for error notification. 
         */        
        IMPORT_C MVPbkContactOperationBase* GetNonTopContactLinksL(
                MVPbkOperationResultObserver<MVPbkContactLinkArray*>&  aResultObserver,
                MVPbkOperationErrorObserver& aErrorObserver );
        
        /**
         * Sets a contact as Top Contact. It will become the last top contact.
         * If a contact manager was not given during
         * construction, then a contact manager is created and the store which
         * is defined in the first link will be opened.
         * The stores used to create aContactLink should be loaded.
         * 
         * If the contact already is a Top Contact, then the Top order of that
         * contact is not modified. 
         * 
         * @param aContactLink The contact link.
         * @param aObserver The observer that gets the completion event.
         * @param aErrorObserver The observer for error notification. 
         */
        IMPORT_C MVPbkContactOperationBase* AddToTopL(
                const MVPbkContactLink& aContactLink,
                MVPbkOperationObserver& aObserver,
                MVPbkOperationErrorObserver& aErrorObserver );

        /**
         * Sets contacts as Top Contacts.
         * The Top ordering will be according to the arrays order.
         * If a contact manager was not given during
         * construction, then a contact manager is created and the store which
         * is defined in the first link will be opened.
         * The store used to create aContactLinks should be loaded.
         * 
         * If the contact already is a Top Contact, then the Top order of that
         * contact is not modified.
         * 
         * A zero length array is valid input and produces no changes. 
         * aObserver will be notified asynchronously.
         *
         * @param aContactLinks The contact links.
         * @param aObserver The observer that gets the completion event.
         * @param aErrorObserver The observer for error notification. 
         */
        IMPORT_C MVPbkContactOperationBase* AddToTopL(
                const MVPbkContactLinkArray& aContactLinks,
                MVPbkOperationObserver& aObserver,
                MVPbkOperationErrorObserver& aErrorObserver );

        /**
         * Sets contacts as Top Contacts. Accepts a packed link array.
         * The Top ordering will be according to the arrays order.
         * If a contact manager was not given during
         * construction, then a contact manager is created and the store which
         * is defined in the first link will be opened.
         * 
         * If the contact already is a Top Contact, then the Top order of that
         * contact is not modified.
         * 
         * A zero length array is valid input and produces no changes. 
         * aObserver will be notified asynchronously.
         *
         * @param aPackedLinks A contact link array in packed form.
         * @param aObserver The observer that gets the completion event.
         * @param aErrorObserver The observer for error notification. 
         */
        IMPORT_C MVPbkContactOperationBase* AddToTopL(
                const TDesC8& aPackedLinks,
                MVPbkOperationObserver& aObserver,
                MVPbkOperationErrorObserver& aErrorObserver );

        /**
         * Removes a contact from the Top.
         * If a contact manager was not given during
         * construction, then a contact manager is created and the store which
         * is defined in the link will be opened.
         * The stores used to create aContactLink should be loaded.
         * 
         * @param aContactLink The contact link.
         * @param aObserver The observer that gets the completion event.
         * @param aErrorObserver The observer for error notification. 
         */
        IMPORT_C MVPbkContactOperationBase* RemoveFromTopL(
        	const MVPbkContactLink& aContactLink,
        	MVPbkOperationObserver& aObserver,
        	MVPbkOperationErrorObserver& aErrorObserver );

        /**
         * Removes contacts from the Top.¨
         * If a contact manager was not given during
         * construction, then a contact manager is created and the store which
         * is defined in the first link will be opened.
         * The store used to create aContactLinks should be loaded.
         * 
         * A zero length array is valid input and produces no changes. 
         * aObserver will be notified asynchronously.
         *
         * @param aContactLinks The contact links.
         * @param aObserver The observer that gets the completion event.
         * @param aErrorObserver The observer for error notification. 
         */
        IMPORT_C MVPbkContactOperationBase* RemoveFromTopL(
        	const MVPbkContactLinkArray& aContactLinks,
        	MVPbkOperationObserver& aObserver,
        	MVPbkOperationErrorObserver& aErrorObserver );

        /**
         * Removes contacts from the Top. Accepts a packed link array.
         * If a contact manager was not given during
         * construction, then a contact manager is created and the store which
         * is defined in the first link will be opened.
         * 
         * A zero length array is valid input and produces no changes. 
         * aObserver will be notified asynchronously.
         *
         * @param aPackedLinks A contact link array in packed form.
         * @param aObserver The observer that gets the completion event.
         * @param aErrorObserver The observer for error notification. 
         */
        IMPORT_C MVPbkContactOperationBase* RemoveFromTopL(
        	const TDesC8& aPackedLinks,
        	MVPbkOperationObserver& aObserver,
        	MVPbkOperationErrorObserver& aErrorObserver );

        /**
         * Sets the new order of top contacts.
         * Ordering is done within the subset of contacts that were given.
         * Ignores contacts that are not already Top.
         * The store used to create aContactLinks should be loaded.
         * 
         * A zero length array is valid input and produces no changes. 
         * aObserver will be notified asynchronously.
         * 
         * @param aContactLinks The contacts to be reordered. Order is
         * 		  determined by the array order, ie. first is top.
         * @param aObserver The observer that gets the completion event.
         * @param aErrorObserver The observer for error notification. 
         */
        IMPORT_C MVPbkContactOperationBase* SetTopOrderL(
	    	const MVPbkContactLinkArray& aContactLinks,
	    	MVPbkOperationObserver& aObserver,
	    	MVPbkOperationErrorObserver& aErrorObserver );

    public: // helper methods related to top contacts.

        /**
         * Checks whether a contact is top contact.
         *
         * @param aContact A contact.
         * @return ETrue if aContact it top contact, otherwise EFalse 
         */
        IMPORT_C static TBool IsTopContact( const MVPbkBaseContact& aContact );

    private: // construction
        CVPbkTopContactManager();

    private: // data
        CVPbkTopContactManagerImpl* iImpl;
    };

#endif //VPBKTOPCONTACTMANAGER_H
//End of file
