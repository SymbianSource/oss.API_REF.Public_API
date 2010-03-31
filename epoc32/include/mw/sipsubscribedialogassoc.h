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
* Name        : sipsubscribedialogassoc.h
* Part of     : SIP Client
* Interface   : SDK API, SIP Client API
* Version     : 1.0
*
*/



#ifndef CSIPSUBSCRIBEDIALOGASSOC_H
#define CSIPSUBSCRIBEDIALOGASSOC_H

// INCLUDES
#include "sipdialogassocbase.h"

// CONSTANTS

// FORWARD DECLARATIONS
class CUri8;
class CSIPToHeader;
class CSIPFromHeader;
class CSIPContactHeader;
class CSIPEventHeader;
class CSIPMessageElements;
class MSIPRegistrationContext;
class CSIPConnection;

// CLASS DECLARATION

/** 
* @publishedAll
* @released
*
* Class for managing SIP SUBSCRIBE dialog associations.
* It provides services for creating, using and terminating SIP SUBSCRIBE
* dialog associations. The client can have multiple SUBSRIBE dialog 
* associations per same SIP dialog.
* Implementation handles SUBSCRIBE on the dialog level defined by Call-Id,
* local and remote tags; "Event" header semantics are client's responsibility
* 
* @lib sipclient.lib
*/
class CSIPSubscribeDialogAssoc : public CSIPDialogAssocBase    
	{
	public: // Constructors and destructor
		/**
		* Two-phased constructor.
		* Should be used if response to the SIP request to be sent
		* will create a SIP dialog association.
		* @pre aEvent != 0
		* @param aDialog a dialog to be associated with
		* @param aEvent an event to subscribe to; the ownership is transferred
        * @return New object; the ownership is transferred
        * @leave KErrArgument if aEvent == 0
        * @leave KErrSIPResourceNotAvailable if a required SIP Client API
		*	object has been deleted
		*/
		IMPORT_C static CSIPSubscribeDialogAssoc*
			NewL(CSIPDialog& aDialog,
				 CSIPEventHeader* aEvent);

		/**
		* Two-phased constructor.
		* Must be used if response to the SIP request to be sent
		* will create a SIP dialog association.
		* @param aDialog a dialog to be associated with
		* @param aEvent an event to subscribe to; the ownership is transferred
        * @return New object, ownership is transferred
        * @leave KErrArgument if aEvent == 0
        * @leave KErrSIPResourceNotAvailable if a required SIP Client API
		*	object has been deleted
		*/
		IMPORT_C static CSIPSubscribeDialogAssoc*
			NewLC(CSIPDialog& aDialog,
				  CSIPEventHeader* aEvent);

        /**
        * Two-phased constructor
        * @pre aFrom != 0 
		* @pre aRemoteUri != 0
		* @pre aEvent != 0
		* The user of the class must not define tags in From-header and
		* To-header.
        * @param aConnection a SIP connection to be used with
        *        dialog association
        * @param aFrom originator's address; the ownership is transfered
        * @param aRemoteUri a remote target URI that identifies a resource that
        *		 the request is addressed to.
		* @param aEvent an event to subscribe to; the ownership is transferred
        * @param aTo logical recipient's address; if not defined
        *        the remote target uri will be used for To-header
        *        construction; the ownership is transfered
        * @param aContact a contact to be used in dialog creation. Must be
        *        given only if user intends to re-direct future requests; 
        *        the ownership is transfered
        * @return New object; the ownership is transferred.
        * @leave KErrArgument if aFrom == 0, aRemoteUri == 0 or aEvent == 0
        * @leave KErrSIPResourceNotAvailable if a required SIP Client API
		*	object has been deleted
        */
        IMPORT_C static CSIPSubscribeDialogAssoc*
            NewL(CSIPConnection& aConnection,
                 CSIPFromHeader* aFrom,
				 CUri8* aRemoteUri,
				 CSIPEventHeader* aEvent,
                 CSIPToHeader* aTo=0,
                 CSIPContactHeader* aContact=0);

        /**
        * Two-phased constructor
        * @pre aFrom != 0 
		* @pre aRemoteUri != 0
		* @pre aEvent != 0
		* The user of the class must not define tags in From-header and
		* To-header.
        * @param aConnection a SIP connection to be used with
        *        dialog association
        * @param aFrom originator's address; the ownership is transfered
        * @param aRemoteUri a remote target URI that identifies a resource that
        *		 the request is addressed to.
		* @param aEvent an event to subscribe to; the ownership is transferred
        * @param aTo logical recipient's address; if not defined
        *        the remote target uri will be used for To-header
        *        construction; the ownership is transfered
        * @param aContact a contact to be used in dialog creation. Must be
        *        given only if user intends to re-direct future requests; 
        *        the ownership is transfered
        * @return New object; the ownership is transferred.
        * @leave KErrArgument if aFrom == 0, aRemoteUri == 0 or aEvent == 0
        * @leave KErrSIPResourceNotAvailable if a required SIP Client API
		*	object has been deleted
        */
        IMPORT_C static CSIPSubscribeDialogAssoc*
            NewLC(CSIPConnection& aConnection,
                  CSIPFromHeader* aFrom,
				  CUri8* aRemoteUri,
				  CSIPEventHeader* aEvent,
                  CSIPToHeader* aTo =0,                 
                  CSIPContactHeader* aContact=0);
        
        /**
        * Two-phased constructor
		* @pre aRemoteUri != 0
		* @pre aEvent != 0
		* The user of the class must not define tags in From-header
		* and To-header.
        * @pre aContext.IsContextActive()==ETrue
        * @param aConnection a SIP connection to be used with
        *        dialog association 
        * @param aRemoteUri a remote target URI that identifies a resource that
        *		 the request is targeted to.
        * @param aContext used for selecting outbound 
        *        proxy and originator's address (AOR) and contact		
        * @param aEvent an event to subscribe to; the ownership is transferred
        * @param aFrom originator's address. If not defined it will be
        *        constructed using registration context (User's AOR);
        *        the ownership is transfered
        * @param aTo logical recipient's address; if not defined
        *        the remote target uri will be used for To-header
        *        construction; the ownership is transfered
        * @param aContact a contact to be used in dialog creation. Must be
        *        given only if user intends to re-direct future requests; 
        *        the ownership is transfered
        * @return New object; the ownership is transferred.
        * @leave KErrArgument if aRemoteUri == 0 or aEvent == 0
        * @leave KErrSIPInvalidRegistrationState
        *        if aContext.IsContextActive()==EFalse
        * @leave KErrSIPResourceNotAvailable if a required SIP Client API
		*	object has been deleted
        */
        IMPORT_C static CSIPSubscribeDialogAssoc*
            NewL(CSIPConnection& aConnection,                                    
                 CUri8* aRemoteUri,
                 const MSIPRegistrationContext& aContext,
                 CSIPEventHeader* aEvent,
                 CSIPFromHeader* aFrom = 0,
	             CSIPToHeader* aTo = 0,
	             CSIPContactHeader* aContact = 0);

       /**
        * Two-phased constructor        
		* @pre aRemoteUri != 0
		* @pre aEvent != 0
		* The user of the class must not define tags in From-header
		* and To-header.
        * @pre aContext.IsContextActive()==ETrue
        * @param aConnection a SIP connection to be used with
        *        dialog association 
        * @param aRemoteUri a remote target URI that identifies a resource that
        *		 the request is targeted to.
        * @param aContext used for selecting outbound 
        *        proxy and originator's address (AOR) and contact
        * @param aEvent an event to subscribe to; the ownership is transferred
        * @param aFrom originator's address. If not defined it will be
        *        constructed using registration context (User's AOR);
        *        the ownership is transfered
        * @param aTo logical recipient's address; if not defined
        *        the remote target uri will be used for To-header
        *        construction; the ownership is transfered
        * @param aContact a contact to be used in dialog creation. Must be
        *        given only if user intends to re-direct future requests; 
        *        the ownership is transfered
        * @return New object; the ownership is transferred.
        * @leave KErrArgument if aRemoteUri == 0 or aEvent == 0
        * @leave KErrSIPInvalidRegistrationState
        *        if aContext.IsContextActive()==EFalse
        * @leave KErrSIPResourceNotAvailable if a required SIP Client API
		*	object has been deleted
        */
        IMPORT_C static CSIPSubscribeDialogAssoc*
            NewLC(CSIPConnection& aConnection,                                    
                  CUri8* aRemoteUri,
                  const MSIPRegistrationContext& aContext,
                  CSIPEventHeader* aEvent,
                  CSIPFromHeader* aFrom = 0,
	              CSIPToHeader* aTo = 0,
	              CSIPContactHeader* aContact = 0);

		/**
		* Destructor
		*/
		IMPORT_C ~CSIPSubscribeDialogAssoc();

	public: //New functions
		/**
		* Creates SUBSCRIBE and sends it to the remote target.		
		* 101-199 or 2xx response to SUBSCRIBE will create a dialog association
		* in case of the first SUBSCRIBE request within this dialog.
		* Client must not provide Event-header in the optional message headers.
        *
		* @pre Dialog().Connection().State()==EActive
		* @pre Dialog().State()==CSIPDialog::EInit ||
		*      Dialog().State()==CSIPDialog::EConfirmed
		* @param aElements optional SIP message headers and body. Ownership is
        *   transferred.
		* @param aRefresh if set the transaction will be refreshed at given
		*                 interval. Interval must be defined by including
		*                 Expires-header. Ownership is transferred.
		* @return SUBSCRIBE SIP transaction. Ownership is transferred.
		* @leave KErrSIPInvalidDialogState if Dialog().State() is incorrect
		* @capability NetworkServices
		*/
		IMPORT_C CSIPClientTransaction*
            SendSubscribeL(CSIPMessageElements* aElements=0,
						   CSIPRefresh* aRefresh=0);

		/**
        * Updates the subscription. Note that update can be done when 2xx
        * response is received to the initial SUBSCRIBE or to update.
        * Client must not provide Event-header in the optional message headers.
        * @pre aElements != 0
 		* @pre Dialog().Connection().State()==EActive
		*      Dialog().State()==CSIPDialog::EConfirmed       
        * @param aElements contains user SIP headers and content; the ownership
        *		 is transferred
        * @return SUBSCRIBE SIP client transaction; the ownership is transferred
        * @leave KErrArgument if aElements == 0 or aElements contain
        *	Event-header
        * @leave KErrSIPInvalidDialogState if Dialog().State() is incorrect
        * @capability NetworkServices
        */            			   
        IMPORT_C CSIPClientTransaction* UpdateL(CSIPMessageElements* aElements);
        
		/**
		* Creates (un)SUBSCRIBE and sends it to the remote target.
		* Possible associated refresh will be terminated as well.
		* Client must not provide Event-header in the optional message headers.
		* @pre Dialog().Connection().State()==EActive
		* @pre Dialog().State()==CSIPDialog::EConfirmed
		* @param aElements optional SIP message headers and body. Ownership is
        *   transferred.
		* @return SUBSCRIBE SIP transaction. Ownership is transferred.
		* @leave KErrSIPInvalidDialogState if Dialog().State() is incorrect
		* @capability NetworkServices
		*/
		IMPORT_C CSIPClientTransaction*
            SendUnsubscribeL(CSIPMessageElements* aElements=0);

		/**
		* Gets associated refresh in case the user has requested
		* the refresh of the SIP subscription.
		* Note that refreshed SUBSCRIBE dialog association cannot be
		* terminated nor updated using the returned object.
		* @return Associated refresh or 0 pointer if the user has not requested
        *   a refresh. Ownership is not transferred.
		*/
		IMPORT_C const CSIPRefresh* SIPRefresh() const;

		/**
		* Gets an event to which the subscription is done
		* @return an event
		*/
		IMPORT_C const CSIPEventHeader& Event() const;    

	public: // New functions, for internal use
        
        /**
        * @internalComponent
        */        
        CSIPRefresh* FindRefresh(TUint32 aRefreshId);
        
        static CSIPSubscribeDialogAssoc* NewLC(CSIPConnection& aConnection,
								CUri8* aRemoteUri,
								CSIPEventHeader* aEvent,
                                CSIPFromHeader* aFrom,
                                CSIPToHeader* aTo,
			                    CSIPContactHeader* aContact,
			                    const MSIPRegistrationContext* aContext);

        void ConnectionLost();

        CSIPClientTransaction*
            DoSendSubscribeL(CSIPMessageElements* aElements,
                             CSIPRefresh* aRefresh,
                             TBool aWithinDialog);        

        CSIPClientTransaction* 
            DoSendUnsubscribeL(CSIPMessageElements* aElements);

        /**
        * @internalComponent
        */            
        void DeletingRefresh(CSIPRefresh& aRefresh, TUint32 aRefreshId);

 	private: // Constructors
        CSIPSubscribeDialogAssoc();

    private: // Data
        //If the subscription is refreshed, this is the used CSIPRefresh
        //instance, otherwise this is NULL. CSIPSubscribeDialogAssoc owns this.
        CSIPRefresh* iRefresh;

        CSIPEventHeader* iEvent;

	private: // For testing purposes
#ifdef CPPUNIT_TEST
        friend class CSIP_Test;
        friend class CSIPSubscribeDialogAssoc_Test;
#endif
	};

#endif
