/*
* Copyright (c) 2005-2009 Nokia Corporation and/or its subsidiary(-ies).
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
* Description:
* Name        : sipconnectionobserver.h
* Part of     : SIP Client
* Interface   : SDK API, SIP Client API
* Version     : 1.0
*
*/



#ifndef MSIPCONNECTIONOBSERVER_H
#define MSIPCONNECTIONOBSERVER_H

//  INCLUDES
#include "sipconnection.h"

// FORWARD DECLARATIONS
class CSIPDialogAssocBase;
class CSIPInviteDialogAssoc;
class CSIPRegistrationBinding;
class CSIPDialog;
class CSIPTransactionBase;
class CSIPServerTransaction;

// CLASS DECLARATION

/**
*  @publishedAll
*  @released
*
*  An interface to be implemented by users of CSIPConnection.
*  Interface allows to be able to receive requests, responses, connection state
*  notifications and error notifications from sip stack.
*
*  Note: The client must not delete related CSIPConnection object 
*  during the execution of the interface function.
*
*  @lib n/a
*/

class MSIPConnectionObserver
	{    	
    public:
		/**
		* A SIP request outside a dialog has been received from the network.
        *
        * @pre aTransaction != 0
		* @param aTransaction SIP server transaction. The ownership is
        *   transferred.
        */
		virtual void IncomingRequest (CSIPServerTransaction*
									  aTransaction) = 0;

		/**
		* A SIP request within a dialog has been received from the network.
		* The client must resolve the actual dialog association to which
		* this request belongs.
		*
        * @pre aTransaction != 0
		* @param aTransaction SIP server transaction. The ownership is
        *   transferred.
		* @param aDialog the dialog that this transaction belongs to.        
		*/
		virtual void IncomingRequest (CSIPServerTransaction* aTransaction,
					                  CSIPDialog& aDialog) = 0;

		/**
		* A SIP response received from the network.
		*
		* @param aTransaction contains response elements.
		*/
		virtual void IncomingResponse (CSIPClientTransaction&
                                       aTransaction) = 0;

		/**
		* A SIP response received from the network that is within a dialog
		* association or creates a dialog association.
		*
		* @param aTransaction contains response elements.
		* @param aDialogAssoc a dialog association.        
		*/		
		virtual void IncomingResponse (
					CSIPClientTransaction& aTransaction,
					CSIPDialogAssocBase& aDialogAssoc) = 0;

        /**
		* Multiple SIP responses have been received to the single INVITE due
		* to the forking proxy. Note that each response creates a separate
		* INVITE dialog association.
        * Multiple responses can arrive until SIP stack completes UAC core
		* INVITE transaction.
        * If clients deletes INVITE transaction after first SIP response
		* other possible responses will be consumed by the implementation.
		* 
		* @param aTransaction contains response elements
		* @param aDialogAssoc INVITE dialog association; the ownership is 
		*        transferred
		*/
		virtual void IncomingResponse (
					CSIPClientTransaction& aTransaction,
					CSIPInviteDialogAssoc* aDialogAssoc) = 0;

		/**
		* A SIP response related a registration binding or an error response
		* that is related to registration binding has been received
        * from the network.
        *
		* @param aTransaction contains response elements
		* @param aRegistration registration binding this transaction belongs to
		*/
		virtual void
			IncomingResponse (CSIPClientTransaction& aTransaction,
                              CSIPRegistrationBinding& aRegistration) = 0;

 		/**
		* An asynchronous error has occurred in the stack related to the
		* request indicated by the given transaction.
		*
		* @param aError system wide or SIP error code
		* @param aTransaction failed transaction
		* @param aSIPConnection a SIP connection        
		*/
		virtual void ErrorOccured (TInt aError,
                                   CSIPTransactionBase& aTransaction) = 0;

		/**
		* An asynchronous error has occurred in the stack related
		* to the request indicated by the given transaction.
        *
		* @param aError system wide or SIP error code
		* @param aTransaction the failed transaction
		* @param aRegistration the failed registration binding
		*/
		virtual void ErrorOccured (TInt aError,
				                   CSIPClientTransaction& aTransaction,
					               CSIPRegistrationBinding& aRegistration) = 0;

		/**
		* An asynchronous error has occured related to a request within
		* an existing dialog.
        *
		* @param aError system wide or SIP error code
		* @param aTransaction the failed transaction.
		* @param aDialogAssoc the failed dialog associoation.        
		*/
		virtual void ErrorOccured (
					TInt aError,
				    CSIPTransactionBase& aTransaction,
					CSIPDialogAssocBase& aDialogAssoc) = 0;

		/**
		* An asynchronous error has occured related to a refresh 
        *
		* @param aError system wide or SIP error code
		* @param aSIPRefresh original refresh object.        
		*/
		virtual void ErrorOccured (TInt aError, CSIPRefresh& aSIPRefresh) = 0;

		/**
		* An asynchronous error has occured related to a periodical refresh
        * that relates to a registration.
        *
		* @param aError system wide or SIP error code; 
		*		 KErrCouldNotConnect if the refresh has failed
		*		 due to the suspended connection.
		* @param aRegistration associated registration binding
		*/
		virtual void ErrorOccured (TInt aError,					
					               CSIPRegistrationBinding& aRegistration) = 0;

		/**
		* An asynchronous error has occured related to a periodical refresh
        * that belongs to SIP dialog association.
        *
		* @param aError system wide or SIP error code; 
		*        KErrCouldNotConnect if the refresh has failed
		*		 due to the suspended connection.
		* @param aDialogAssoc SIP dialog association.        
		*/
		virtual void ErrorOccured (TInt aError,			
					               CSIPDialogAssocBase& aDialogAssoc) = 0;

        /**
		* SIP stack has completed UAC core INVITE transaction 64*T1 seconds
        * after the reception of the first 2xx response. No more 2xx responses
        * can be received to the issued single INVITE.
        *
        * If the INVITE transaction does not create a dialog, or the INVITE
        * transaction encounters an error, this event will not be sent.
        *
		* @param aTransaction a complete UAC core INVITE transaction
		*/
        virtual void InviteCompleted (CSIPClientTransaction& aTransaction) = 0;

		/**
        * Invite was canceled with the CANCEL
        * @param aTransaction a canceled INVITE UAS transaction
        */
        virtual void InviteCanceled (CSIPServerTransaction& aTransaction) = 0;
                
		/**
		* Connection state has changed.
        * If connection state has changed to EInactive or EUnavailable,
		* SIP stack has removed all stand-alone SIP refreshes, registrations 
		* and dialog associations that client requested to refresh. Client may
		* re-issue refresh requests (stand-alone, registration or dialog 
		* association related) when connection becomes EActive again.
		* SIP stack also terminates all pending SIP client transactions and no
        * errors are reported back to the client about the terminated
        * transactions nor about removed refreshes in order to avoid event
        * flood.
		* 
		* @param aState indicates the current connection state        
		*/
		virtual void ConnectionStateChanged (CSIPConnection::TState aState) = 0;
	};

#endif
