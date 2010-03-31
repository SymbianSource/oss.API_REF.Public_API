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
* Name        : sipinvitedialogassoc.h
* Part of     : SIP Client
* Interface   : SDK API, SIP Client API
* Version     : 1.0
*
*/




#ifndef CSIPINVITEDIALOGASSOC_H
#define CSIPINVITEDIALOGASSOC_H

// INCLUDES
#include "sipdialogassocbase.h"

// CONSTANTS

// FORWARD DECLARATIONS
class CUri8;
class CSIPConnection;
class CSIPServerTransaction;
class CSIPFromHeader;
class CSIPToHeader;
class CSIPContactHeader;
class MSIPRegistrationContext;

// CLASS DECLARATION

/**
*  @publishedAll
*  @released
*
*  Class for managing SIP dialog association created with INVITE.
*  It provides services for creating, using and
*  terminating SIP INVITE dialog association.
*
*  The user can have only one INVITE dialog association per dialog.
* 
*  @lib sipclient.lib
*/
class CSIPInviteDialogAssoc : public CSIPDialogAssocBase
	{
	public: // Constructors and destructor

		/**
		* Two-phased constructor.
		* @param aDialog a dialog to be associated with
        * @return New object, ownership is transferred.
		*/
		IMPORT_C static CSIPInviteDialogAssoc* NewL(CSIPDialog& aDialog);

        /**
		* Two-phased constructor.
		* @param aDialog a dialog to be associated with
        * @return New object, ownership is transferred.
		*/
		IMPORT_C static CSIPInviteDialogAssoc* NewLC(CSIPDialog& aDialog);

        /**
        * Two-phased constructor.
        * Should be used if response to the received SIP request will create
        * a SIP dialog association.
        * The server transaction must be a INVITE transaction.
        * If SIP server transaction was received within an existing SIP dialog
        * the created SIP dialog association will be correlated to that SIP
        * dialog. Otherwise a new SIP dialog is created.
        * @pre aTransaction.State() == CSIPTransactionBase::EProceeding
        * @pre aTransaction.Type() == SipStrConsts::EInvite
        * @param aTransaction a SIP server transaction 
        * @return New object, ownership is transferred.
        * @leave KErrArgument if aTransaction.Type() != SipStrConsts::EInvite
        * @leave KErrSIPInvalidTransactionState if aTransaction.State() !=
        *	CSIPTransactionBase::EProceeding
        * @leave KErrSIPResourceNotAvailable if a required SIP Client API
		*	object has been deleted
        */
        IMPORT_C static CSIPInviteDialogAssoc*
            NewL(CSIPServerTransaction& aTransaction);

        /**
        * Two-phased constructor.
        * Should be used if response to the received SIP request will create a
        * SIP dialog association.
        * The server transaction must be a INVITE transaction.
        * If SIP server transaction was received within the existing SIP dialog
        * the created SIP dialog association will be correlated to that
        * SIP dialog.  Otherwise a new SIP dialog is created.
		* @pre aTransaction.State() == CSIPTransactionBase::EProceeding
		* @pre aTransaction.Type() == SipStrConsts::EInvite
        * @param aTransaction a SIP server transaction
        * @return New object, ownership is transferred.
        * @leave KErrArgument if aTransaction.Type() != SipStrConsts::EInvite
        * @leave KErrSIPInvalidTransactionState if aTransaction.State() !=
        *	CSIPTransactionBase::EProceeding
        * @leave KErrSIPResourceNotAvailable if a required SIP Client API
		*	object has been deleted
        */
        IMPORT_C static CSIPInviteDialogAssoc*
            NewLC(CSIPServerTransaction& aTransaction);

        /**
        * Two-phased constructor.
        * Should be used if response to the received SIP request will create
        * a SIP dialog association.
        * The server transaction must be a INVITE transaction.
        * If SIP server transaction was received within an existing SIP dialog
        * the created SIP dialog association will be correlated to that SIP
        * dialog. Otherwise a new SIP dialog is created.
        * @pre aTransaction.State() == CSIPTransactionBase::EProceeding
        * @pre aTransaction.Type() == SipStrConsts::EInvite
		* @pre aContext.IsContextActive() == ETrue        
        * @param aTransaction a SIP server transaction 
        * @param aContext that will be used for populating 
        *        the Contact-header of the response to aTransaction
        * @return New object, ownership is transferred.
        * @leave KErrArgument if aTransaction.Type() != SipStrConsts::EInvite
        * @leave KErrSIPInvalidTransactionState if aTransaction.State() !=
        *	CSIPTransactionBase::EProceeding
        * @leave KErrSIPResourceNotAvailable if a required SIP Client API
		*	object has been deleted
        */
        IMPORT_C static CSIPInviteDialogAssoc*
            NewL(CSIPServerTransaction& aTransaction,
                 const MSIPRegistrationContext& aContext);

        /**
        * Two-phased constructor.
        * Should be used if response to the received SIP request will create a
        * SIP dialog association.
        * The server transaction must be a INVITE transaction.
        * If SIP server transaction was received within the existing SIP dialog
        * the created SIP dialog association will be correlated to that
        * SIP dialog.  Otherwise a new SIP dialog is created.
		* @pre aTransaction.State() == CSIPTransactionBase::EProceeding
		* @pre aTransaction.Type() == SipStrConsts::EInvite
		* @pre aContext.IsContextActive() == ETrue 
        * @param aTransaction a SIP server transaction
        * @param aContext that will be used for populating 
        *        the Contact-header of the response to aTransaction        
        * @return New object, ownership is transferred.
        * @leave KErrArgument if aTransaction.Type() != SipStrConsts::EInvite
        * @leave KErrSIPInvalidTransactionState if aTransaction.State() !=
        *	CSIPTransactionBase::EProceeding
        * @leave KErrSIPResourceNotAvailable if a required SIP Client API
		*	object has been deleted
        */
        IMPORT_C static CSIPInviteDialogAssoc*
            NewLC(CSIPServerTransaction& aTransaction,
                  const MSIPRegistrationContext& aContext);

        /**
        * Two-phased constructor
        * @pre aFrom != 0
        * @pre aRemoteUri != 0
		* The user of the class must not define tags in From-header
		* and To-header.        
        * @param aConnection a SIP connection to be used with
        *        dialog association
        * @param aFrom originator's address; the ownership is transfered
        * @param aRemoteUri a remote target URI that identifies a resource that
        *		 the request is addressed to. The ownership is transferred.
        * @param aTo logical recipient's address; if not defined
        *        the remote target uri will be used for To-header
        *        construction; the ownership is transfered
        * @param aContact a contact to be used in dialog creation. Must be
        *        given only if user intends to re-direct future requests; 
        *        the ownership is transfered        
        * @return New object, ownership is transferred.
        * @leave KErrArgument if aFrom == 0 or aRemoteUri == 0
        */
        IMPORT_C static CSIPInviteDialogAssoc*
            NewL(CSIPConnection& aConnection,
                 CSIPFromHeader* aFrom,
                 CUri8* aRemoteUri,
                 CSIPToHeader* aTo=0,
                 CSIPContactHeader* aContact=0);

        /**
        * Two-phased constructor
        * @pre aFrom != 0
        * @pre aRemoteUri != 0
		* The user of the class must not define tags in From-header
		* and To-header.
        * @param aSIPConnection a SIP connection to be used with
        *        dialog association
        * @param aFrom originator's address; the ownership is transfered
        * @param aRemoteUri a remote target URI that identifies a resource that
        *		 the request is addressed to. The ownership is transferred.
        * @param aTo logical recipient's address; if not defined
        *        the remote target uri will be used for To-header
        *        construction; the ownership is transfered
        * @param aContact a contact to be used in dialog creation. Must be
        *        given only if user intends to re-direct future requests; 
        *        the ownership is transfered
        * @return New object, ownership is transferred.
        * @leave KErrArgument if aFrom == 0 or aRemoteUri == 0
        */
        IMPORT_C static CSIPInviteDialogAssoc*
            NewLC(CSIPConnection& aConnection,
                  CSIPFromHeader* aFrom,
                  CUri8* aRemoteUri,
                  CSIPToHeader* aTo=0,
                  CSIPContactHeader* aContact=0);

        /**
        * Two-phased constructor
		* @pre aRemoteUri != 0
		* The user of the class must not define tags in From-header
		* and To-header.
        * @pre aContext.IsContextActive() == ETrue
        * @param aConnection a SIP connection to be used with
        *        dialog association        
        * @param aRemoteUri a remote target URI that identifies a resource
        *		 that the request is targeted to. The ownership is transferred.
        * @param aContext used for selecting outbound 
        *        proxy and originator's address (AOR) and contact
        * @param aFrom originator's address. If not defined it will
        *        constructed using registration context (User's AOR);
        *        the ownership is transfered
        * @param aTo logical recipient's address; if not defined
        *        the remote target uri will be used for To-header
        *        construction; the ownership is transfered
        * @param aContact a contact to be used in dialog creation. Must be
        *        given only if user intends to re-direct future requests; 
        *        the ownership is transfered
        * @return New object, ownership is transferred.
        * @leave KErrArgument if aRemoteUri == 0
        * @leave KErrSIPInvalidRegistrationState
        *		 if aContext.IsContextActive() == EFalse
        */
        IMPORT_C static CSIPInviteDialogAssoc*
            NewL(CSIPConnection& aConnection,                                    
                 CUri8* aRemoteUri,
                 const MSIPRegistrationContext& aContext,
                 CSIPFromHeader* aFrom=0,
	             CSIPToHeader* aTo=0,
	             CSIPContactHeader* aContact=0);

        /**
		* Two-phased constructor		
		* @pre aRemoteUri != 0
		* The user of the class must not define tags in From-header
		* and To-header.
		* @pre aContext.IsContextActive() == ETrue
		* @param aConnection a SIP connection to be used with
		*        dialog association		
		* @param aRemoteUri a remote target URI that identifies a resource
		*		 that the request is targeted to. The ownership is transferred.
        * @param aContext used for selecting outbound 
        *        proxy and originator's address (AOR) and contact
        * @param aFrom originator's address. If not defined it will
        *        constructed using registration context (User's AOR);
        *        the ownership is transfered
        * @param aTo logical recipient's address; if not defined
        *        the remote target uri will be used for To-header
        *        construction; the ownership is transfered
        * @param aContact a contact to be used in dialog creation. Must be
        *        given only if user intends to re-direct future requests; 
        *        the ownership is transfered
        * @return New object, ownership is transferred.
        * @leave KErrArgument if aRemoteUri == 0
        * @leave KErrSIPInvalidRegistrationState
        *		 if aContext.IsContextActive() == EFalse
		*/
        IMPORT_C static CSIPInviteDialogAssoc*
            NewLC(CSIPConnection& aConnection,			                        
			      CUri8* aRemoteUri,
                  const MSIPRegistrationContext& aContext,
                  CSIPFromHeader* aFrom=0,
	              CSIPToHeader* aTo=0,
	              CSIPContactHeader* aContact=0);

		/**
		* Destructor
		*/
		IMPORT_C ~CSIPInviteDialogAssoc();
			                                  
	public: // New functions

		/**
		* Creates INVITE and sends it to the remote target.
		* 101-199 or 2xx response will create INVITE dialog association in case
		* of first INVITE within this dialog association. Subsequent INVITE
		* requests are re-INVITEs.
		* @pre Dialog().Connection().State()==EActive
		* @pre Dialog().State()==CSIPDialog::EInit ||
		*      Dialog().State()==CSIPDialog::EConfirmed
		* @param aElements contains user SIP headers and content. Ownership is
        *   transferred.
		* @return INVITE SIP transaction. Ownership is transferred.
		* @leave KErrSIPInvalidDialogState if dialog is not in a correct state
		* @leave KErrSIPResourceNotAvailable if a required SIP Client API
		*	object has been deleted
		* @capability NetworkServices
		*/
		IMPORT_C CSIPClientTransaction*
            SendInviteL(CSIPMessageElements* aElements=0);

        /**
		* Creates PRACK and sends it to the remote target.		
		* @pre Dialog().Connection().State()==EActive
		* @pre Dialog().State()==CSIPDialog::EEarly || 
		*      Dialog().State()==CSIPDialog::EConfirmed
        * @pre aElements must not contain Contact headers
		* @param aElements contains user SIP headers and content. Ownership is
        *   transferred.
		* @return PRACK SIP transaction. Ownership is transferred.
		* @leave KErrSIPInvalidDialogState if dialog is not in a correct state
		* @leave KErrSIPResourceNotAvailable if a required SIP Client API
		*	object has been deleted
		* @capability NetworkServices
		*/
		IMPORT_C CSIPClientTransaction*
            SendPrackL(CSIPMessageElements* aElements=0);

	    /**
		* Creates UPDATE and sends it to the remote target.
		* @pre Dialog().Connection().State()==EActive
		* @pre Dialog().State()==CSIPDialog::EEarly || 
		*      Dialog().State()==CSIPDialog::EConfirmed
		* @param aElements contains user SIP headers and content. Ownership is
        *   transferred.
		* @return UPDATE SIP transaction. Ownership is transferred.
		* @leave KErrSIPInvalidDialogState if dialog is not in a correct state
		* @leave KErrSIPResourceNotAvailable if a required SIP Client API
		*	object has been deleted
		* @capability NetworkServices
		*/
		IMPORT_C CSIPClientTransaction*
            SendUpdateL(CSIPMessageElements* aElements=0);

		/**
		* Creates SIP ACK request and sends it to the remote target.
		* The client transaction must be an INVITE transaction.
		* @pre Dialog().Connection().State()==EActive
		* @pre Dialog().State()==CSIPDialog::EConfirmed
		* @param aTransaction a SIP INVITE client transaction to acknowledge
		* @param aElements optional SIP message headers and body. Ownership is
        *   transferred.
        * @leave KErrArgument if aTransaction is not an INVITE transaction.
        * @leave KErrSIPInvalidDialogState if ACK can't be sent in the current
		*	dialog state
        * @leave KErrSIPResourceNotAvailable if a required SIP Client API
		*	object has been deleted
		* @capability NetworkServices
		*/
		IMPORT_C void SendAckL(const CSIPClientTransaction& aTransaction,
			                   CSIPMessageElements* aElements=0);

	    /**
		* Creates SIP BYE request and sends it to the remote target.		
		* @pre Dialog().Connection().State()==EActive
		* @pre Dialog().State()==CSIPDialog::EEarly || 
		*      Dialog().State()==CSIPDialog::EConfirmed
		* @param aElements contains user SIP headers and content. Ownership is
        *   transferred.
		* @return SIP BYE transaction. Ownership is transferred.
		* @leave KErrSIPInvalidDialogState if BYE can't be sent in the current
		*	dialog state
		* @leave KErrSIPResourceNotAvailable if a required SIP Client API
		*	object has been deleted
		* @capability NetworkServices
		*/		
		IMPORT_C CSIPClientTransaction*
            SendByeL(CSIPMessageElements* aElements=0);

	public: // New functions, for internal use
	
        /**
		* Sends initial INVITE creating a dialog and creates a transaction for
        * it.
		* @param aElements contains user SIP headers and content. Ownership is
        *   transferred.
		* @return INVITE SIP transaction. Ownership is transferred.
		*/
        CSIPClientTransaction* DoSendInviteL(CSIPMessageElements* aElements);

        /**
		* Sends ACK		
		* @param aTransaction a SIP INVITE client transaction to acknowledge
		* @param aElements optional SIP message headers and body. Ownership is
        *   transferred.
		*/
        void DoSendAckL(const CSIPClientTransaction& aTransaction,
                        CSIPMessageElements* aElements);

		CSIPClientTransaction*
			DoSendRequestWithinDialogL(RStringF aMethod,
									   CSIPMessageElements* aElements);

        CSIPClientTransaction* DoSendCancelL(TUint32 aRequestId);

   	private: // Constructors
   	   	
		static CSIPInviteDialogAssoc* NewLC(CSIPConnection& aConnection,
								 CUri8* aRemoteUri,
	                             CSIPFromHeader* aFrom,
	                             CSIPToHeader* aTo,
		                         CSIPContactHeader* aContact,
		                         const MSIPRegistrationContext* aContext);

		CSIPInviteDialogAssoc();
		
		void ConstructL(CSIPServerTransaction& aTransaction,
                        const MSIPRegistrationContext* aContext);
	};

#endif
