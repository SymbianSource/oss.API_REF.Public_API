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
* Name        : sipnotifydialogassoc.h
* Part of     : SIP Client
* Interface   : SDK API, SIP Client API
* Version     : 1.0
*
*/




#ifndef CSIPNOTIFYDIALOGASSOC_H
#define CSIPNOTIFYDIALOGASSOC_H

// INCLUDES
#include <e32base.h>
#include "sipdialogassocbase.h"

// CONSTANTS

// FORWARD DECLARATIONS
class CSIPEventHeader;
class CSIPSubscriptionStateHeader;
class MSIPRegistrationContext;

// CLASS DECLARATION

/**
* @publishedAll
* @released
*
* Class for managing SIP NOTIFY dialog associations.
* It provides services for creating, using and
* terminating SIP NOTIFY dialog associations. The user can have multiple
* NOTIFY dialog associations per same SIP dialog.
* Implementation handles SUBSCRIBE on the dialog level defined by Call-Id,
* local and remote tags; user is responsible for "Event" and
* "Subscription-State" header semantics.
* @lib sipclient.lib
*/
class CSIPNotifyDialogAssoc: public CSIPDialogAssocBase
	{
	public: // Constructors and destructor

        /**
		* Two-phased constructor.
		* The response to the received SIP request will create a SIP NOTIFY
		* dialog association that will be correlated with the SIP dialog in
		* which SIP server transaction was received. If the server transaction
		* was not received within a SIP dialog, a new SIP dialog is created.
		* The server transaction must be either SUBSCRIBE or REFER transaction.
		* @pre aTransaction.State()==ETrying || EProceeding
		* @pre aTransaction.Type() == 
		*      SipStrConsts::ESubscribe || SipStrConsts::ERefer	
        * @pre aEvent != 0 && aState != 0
		* @param aTransaction a SIP server transaction 
		* @param aEvent an event to send a notification about; the ownership
		*        is transferred.
		* @param aState a subscription state; the ownership is transferred.
		* @return New object; the ownership is transferred
		* @leave KErrArgument if aTransaction is not a SUBSCRIBE or REFER
		*	transaction, or aEvent == 0 or aState == 0.
		* @leave KErrSIPInvalidTransactionState if aTransaction is in a wrong
		*	state
		*/
		IMPORT_C static CSIPNotifyDialogAssoc*
			NewL(CSIPServerTransaction& aTransaction,
			     CSIPEventHeader* aEvent,
				 CSIPSubscriptionStateHeader* aState);

		/**
		* Two-phased constructor.
		* The response to the received SIP request will create a SIP NOTIFY
		* dialog association that will be correlated with the SIP dialog in
		* which SIP server transaction was received. If the server transaction
		* was not received within a SIP dialog, a new SIP dialog is created.
		* The server transaction must be either SUBSCRIBE or REFER transaction.
		* @pre aTransaction.State()==ETrying || EProceeding
		* @pre aTransaction.Type() == 
		*      SipStrConsts::ESubscribe || SipStrConsts::ERefer	
        * @pre aEvent != 0 && aState != 0
		* @param aTransaction a SIP server transaction
		* @param aEvent an event to send a notification about; the ownership
		*        is transferred.
		* @param aState a subscription state; the ownership is transferred.
		* @return New object; the ownership is transferred
		* @leave KErrArgument if aTransaction is not a SUBSCRIBE or REFER
		*	transaction, or aEvent == 0 or aState == 0.
		* @leave KErrSIPInvalidTransactionState if aTransaction is in a wrong
		*	state
		*/
		IMPORT_C static CSIPNotifyDialogAssoc*
			NewLC(CSIPServerTransaction& aTransaction,
			      CSIPEventHeader* aEvent,
				  CSIPSubscriptionStateHeader* aState);
				  
        /**
		* Two-phased constructor.
		* The response to the received SIP request will create a SIP NOTIFY
		* dialog association that will be correlated with the SIP dialog in
		* which SIP server transaction was received. If the server transaction
		* was not received within a SIP dialog, a new SIP dialog is created.
		* The server transaction must be either SUBSCRIBE or REFER transaction.
		* @pre aTransaction.State()==ETrying || EProceeding
		* @pre aTransaction.Type() == 
		*      SipStrConsts::ESubscribe || SipStrConsts::ERefer
		* @pre aContext.IsContextActive() == ETrue	
        * @pre aEvent != 0 && aState != 0
		* @param aTransaction a SIP server transaction
        * @param aContext that will be used for populating 
        *        the Contact-header of the response to aTransaction		
		* @param aEvent an event to send a notification about; the ownership
		*        is transferred.
		* @param aState a subscription state; the ownership is transferred.
		* @return New object; the ownership is transferred
		* @leave KErrArgument if aTransaction is not a SUBSCRIBE or REFER
		*	transaction, or aEvent == 0 or aState == 0.
		* @leave KErrSIPInvalidTransactionState if aTransaction is in a wrong
		*	state
		*/
		IMPORT_C static CSIPNotifyDialogAssoc*
			NewL(CSIPServerTransaction& aTransaction,
                 const MSIPRegistrationContext& aContext,			
			     CSIPEventHeader* aEvent,
				 CSIPSubscriptionStateHeader* aState);

		/**
		* Two-phased constructor.
		* The response to the received SIP request will create a SIP NOTIFY
		* dialog association that will be correlated with the SIP dialog in
		* which SIP server transaction was received. If the server transaction
		* was not received within a SIP dialog, a new SIP dialog is created.
		* The server transaction must be either SUBSCRIBE or REFER transaction.
		* @pre aTransaction.State()==ETrying || EProceeding
		* @pre aTransaction.Type() == 
		*      SipStrConsts::ESubscribe || SipStrConsts::ERefer
		* @pre aContext.IsContextActive() == ETrue	
        * @pre aEvent != 0 && aState != 0
		* @param aTransaction a SIP server transaction
        * @param aContext that will be used for populating 
        *        the Contact-header of the response to aTransaction		
		* @param aEvent an event to send a notification about; the ownership
		*        is transferred.
		* @param aState a subscription state; the ownership is transferred.
		* @return New object; the ownership is transferred
		* @leave KErrArgument if aTransaction is not a SUBSCRIBE or REFER
		*	transaction, or aEvent == 0 or aState == 0.
		* @leave KErrSIPInvalidTransactionState if aTransaction is in a wrong
		*	state
		*/
		IMPORT_C static CSIPNotifyDialogAssoc*
			NewLC(CSIPServerTransaction& aTransaction,
                  const MSIPRegistrationContext& aContext,
			      CSIPEventHeader* aEvent,
				  CSIPSubscriptionStateHeader* aState);				  

		/**
		* Destructor
		*/
		IMPORT_C ~CSIPNotifyDialogAssoc();
			                                  
	public: // New functions

        /**
		* Creates NOTIFY and sends it to the remote target.		
		* If client provides optional SIP headers they must
		* not contain Event and Subscription-State headers.		
		* @pre Dialog().Connection().State()==EActive
		* @pre Dialog().State()==CSIPDialog::TState::EConfirmed		
		* @param aElements optional SIP message headers and body.
		*	Ownership is transferred.
		* @return NOTIFY SIP UAC transaction
		* @leave KErrSIPInvalidDialogState if dialog's state is incorrect
		* @leave KErrSIPResourceNotAvailable if a required SIP Client API
		*	object has been deleted.
		* @capability NetworkServices
		*/
		IMPORT_C CSIPClientTransaction*
            SendNotifyL(CSIPMessageElements* aElements=0);

		/**
		* Gets an event about which the notification is done
		* @return an event
		*/
		IMPORT_C const CSIPEventHeader& Event() const;

		/**
		* Gets subscription state
		* @return subscription state
		*/
		IMPORT_C CSIPSubscriptionStateHeader& SubscriptionState();
		
		/**
		* Gets subscription state
		* @return subscription state
		*/
		IMPORT_C const CSIPSubscriptionStateHeader& SubscriptionState() const;

	public: // New functions, for internal use

		CSIPClientTransaction*
			DoSendNotifyWithinDialogL(CSIPMessageElements* aElements);

	private: // Constructors

		CSIPNotifyDialogAssoc();

        void ConstructL(CSIPServerTransaction& aTransaction,
                        const MSIPRegistrationContext* aContext,
                        CSIPEventHeader* aEvent,
                        CSIPSubscriptionStateHeader* aState);

	private: // Data

		CSIPEventHeader* iEvent;
		CSIPSubscriptionStateHeader* iSubscriptionState;
	};

#endif
