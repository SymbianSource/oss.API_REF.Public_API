/*
* Copyright (c) 2005-2009 Nokia Corporation and/or its subsidiary(-ies).
* All rights reserved.
* This component and the accompanying materials are made available
* under the terms of the License "Symbian Foundation License v1.0" to Symbian Foundation members and "Symbian Foundation End User License Agreement v1.0" to non-members
* which accompanies this distribution, and is available
* at the URL "http://www.symbianfoundation.org/legal/licencesv10.html".
*
* Initial Contributors:
* Nokia Corporation - initial contribution.
*
* Contributors:
*
* Description:
* Name        : sipreferdialogassoc.h
* Part of     : SIP Client
* Interface   : SDK API, SIP Client API
* Version     : 1.0
*
*/



#ifndef CSIPREFERDIALOGASSOC_H
#define CSIPREFERDIALOGASSOC_H

// INCLUDES
#include "sipdialogassocbase.h"

// CONSTANTS

// FORWARD DECLARATIONS
class CUri8;
class CSIPToHeader;
class CSIPFromHeader;
class CSIPContactHeader;
class CSIPReferToHeader;
class MSIPRegistrationContext;
class CSIPConnection;

// CLASS DECLARATION

/**
* @publishedAll
* @released
*
* Class for managing SIP REFER dialog associations.
* It provides services for creating, using and terminating SIP REFER
* dialog associations. User can have multiple REFER dialog associations
* per same SIP dialog.
* Implementation handles SUBSCRIBE on the dialog level defined by Call-Id,
* local and remote tags;
* User is responsible for "Refer-to" header semantics.
* @lib sipclient.lib
*/
class CSIPReferDialogAssoc: public CSIPDialogAssocBase
	{
	public: // Constructors and destructor

		/**
		* Two-phased constructor.
		* Should be used if response to the SIP request to be sent
		* will create a SIP dialog association.
		* @pre aReferTo != 0
		* @param aDialog a dialog to be associated with
		* @param aReferTo referred-to resource
        * @return New object; the ownership is transferred
        * @leave KErrArgument if aReferTo == 0
		*/
		IMPORT_C static CSIPReferDialogAssoc*
			NewL(CSIPDialog& aDialog,
				 CSIPReferToHeader* aReferTo);

		/**
		* Two-phased constructor.
		* Must be used if response to the SIP request to be sent
		* will create a SIP dialog association.
		* @pre aReferTo != 0
		* @param aDialog a dialog to be associated with
		* @param aReferTo referred-to resource
        * @return New object; the ownership is transferred
        * @leave KErrArgument if aReferTo == 0
		*/
		IMPORT_C static CSIPReferDialogAssoc*
			NewLC(CSIPDialog& aDialog,
				  CSIPReferToHeader* aReferTo);

       /**
        * Two-phased constructor
        * @pre aFrom != 0 
        * @pre aReferTo != 0
		* @pre aRemoteUri != 0
		* The user of the class must not define tags in From-header
		* and To-header.
        * @param aConnection a SIP connection to be used with
        *        dialog association
        * @param aFrom originator's address; the ownership is transfered
        * @param aRemoteUri a remote target URI that identifies a resource that
        *		 the request is addressed to.
		* @param aReferTo referred-to resource
        * @param aTo logical recipient's address; if not defined
        *        the remote target uri will be used for To-header
        *        construction; the ownership is transfered
        * @param aContact a contact to be used in dialog creation. Must be
        *        given only if user intends to re-direct future requests; 
        *        the ownership is transfered
        * @return New object; the ownership is transferred.
        * @leave KErrArgument if aFrom == 0 or aRemoteuri == 0 or aReferTo == 0
        */
        IMPORT_C static CSIPReferDialogAssoc*
            NewL(CSIPConnection& aConnection,
                 CSIPFromHeader* aFrom,
				 CUri8* aRemoteUri,
				 CSIPReferToHeader* aReferTo,
                 CSIPToHeader* aTo=0,                 
                 CSIPContactHeader* aContact=0);

       /**
        * Two-phased constructor
        * @pre aFrom != 0
        * @pre aReferTo != 0
		* @pre aRemoteUri != 0
		* The user of the class must not define tags in From-header
		* and To-header.
        * @param aConnection a SIP connection to be used with
        *        dialog association
        * @param aFrom originator's address; the ownership is transfered
        * @param aRemoteUri a remote target URI that identifies a resource that
        *		 the request is addressed to.
		* @param aReferTo referred-to resource
        * @param aTo logical recipient's address; if not defined
        *        the remote target uri will be used for To-header
        *        construction; the ownership is transfered
        * @param aContact a contact to be used in dialog creation. Must be
        *        given only if user intends to re-direct future requests; 
        *        the ownership is transfered
        * @return New object; the ownership is transferred.
        * @leave KErrArgument if aFrom == 0 or aRemoteuri == 0 or aReferTo == 0
        */
        IMPORT_C static CSIPReferDialogAssoc*
            NewLC(CSIPConnection& aConnection,
                  CSIPFromHeader* aFrom,
				  CUri8* aRemoteUri,
				  CSIPReferToHeader* aReferTo,
                  CSIPToHeader* aTo=0,                 
                  CSIPContactHeader* aContact=0);

       /**
        * Two-phased constructor
        * @pre aReferTo != 0
		* @pre aRemoteUri != 0
		* The user of the class must not define tags in From-header
		* and To-header.
        * @pre aContext.IsContextActive() == ETrue
        * @param aConnection a SIP connection to be used with
        *        dialog association 
        * @param aRemoteUri a remote target URI that identifies a resource that
        *		 the request is targeted to.
        * @param aContext used for selecting outbound 
        *        proxy and originator's address (AOR) and contact
        * @param aReferTo referred-to resource
        * @param aFrom originator's address. If not defined it will
        *        constructed using registration context (User's AOR);
        *        the ownership is transfered
        * @param aTo logical recipient's address; if not defined
        *        the remote target uri will be used for To-header
        *        construction; the ownership is transfered
        * @param aContact a contact to be used in dialog creation. Must be
        *        given only if user intends to re-direct future requests; 
        *        the ownership is transfered
        * @return New object: the ownership is transferred.
        * @leave KErrArgument if aRemoteuri == 0 or aReferTo == 0
        * @leave KErrSIPInvalidRegistrationState
        *		 if aContext.IsContextActive() == EFalse
        */
        IMPORT_C static CSIPReferDialogAssoc*
            NewL(CSIPConnection& aConnection,                                    
                 CUri8* aRemoteUri,
                 const MSIPRegistrationContext& aContext,
                 CSIPReferToHeader* aReferTo,
                 CSIPFromHeader* aFrom=0,
	             CSIPToHeader* aTo=0,
	             CSIPContactHeader* aContact=0);

       /**
        * Two-phased constructor        
        * @pre aReferTo != 0
		* @pre aRemoteUri != 0
		* The user of the class must not define tags in From-header
		* and To-header.
        * @pre aContext.IsContextActive()==ETrue
        * @param aConnection a SIP connection to be used with
        *        dialog association 
        * @param aRemoteUri a remote target URI that identifies a resource that
        *		 the request is targeted to.
        * @param aContext used for selecting outbound 
        *        proxy and originator's address (AOR) and contact
        * @param aReferTo referred-to resource
        * @param aFrom originator's address. If not defined it will
        *        constructed using registration context (User's AOR);
        *        the ownership is transfered
        * @param aTo logical recipient's address; if not defined
        *        the remote target uri will be used for To-header
        *        construction; the ownership is transfered
        * @param aContact a contact to be used in dialog creation. Must be
        *        given only if user intends to re-direct future requests; 
        *        the ownership is transfered
        * @return New object; the ownership is transferred.
        * @leave KErrArgument if aRemoteuri == 0 or aReferTo == 0
        * @leave KErrSIPInvalidRegistrationState
        *		 if aContext.IsContextActive() == EFalse
        */
        IMPORT_C static CSIPReferDialogAssoc*
            NewLC(CSIPConnection& aConnection,                                    
                 CUri8* aRemoteUri,
                 const MSIPRegistrationContext& aContext,
                 CSIPReferToHeader* aReferTo,
                 CSIPFromHeader* aFrom=0,
	             CSIPToHeader* aTo=0,
	             CSIPContactHeader* aContact=0);

		/**
		* Destructor
		*/
		IMPORT_C ~CSIPReferDialogAssoc();

	public: //New functions

		/**
		* Creates REFER and sends it to the remote target.
		* leaves on failure.
		* 101-199 or 2xx response will create REFER dialog 
		* association in case of first REFER request within
		* this dialog association.
		* @pre Dialog().Connection().State()==EActive
		* @pre Dialog().State()==CSIPDialog::EInit ||
		*      Dialog().State()==CSIPDialog::EConfirmed
		* @param aElements optional SIP message headers and body. Ownership is
        *   transferred.
		* @return REFER SIP transaction. Ownership is transferred.
		* @leave KErrSIPInvalidDialogState if dialog is in wrong state
		* @leave KErrSIPResourceNotAvailable if a required SIP Client API
		*	object has been deleted.
		* @capability NetworkServices
		*/
		IMPORT_C CSIPClientTransaction*
            SendReferL(CSIPMessageElements* aElements=0);
        
        /**
        * Gets referred-to resouce
        * @return referred-to resource
        */
        IMPORT_C const CSIPReferToHeader& ReferTo() const;

	public: // New functions, for internal use
	
		/**
		* Sends a REFER request.
		*
		* @pre Dialog().Connection().State()==EActive
		* @param aElements optional SIP message headers and body.
		*	Ownership is transferred.
		* @param aWithinDialog ETrue if REFER is sent within dialog,
		*	EFalse if REFER creates the dialog.
		* @return REFER SIP transaction. Ownership is transferred.
		*/
		CSIPClientTransaction* DoSendReferL(CSIPMessageElements* aElements,
								   			TBool aWithinDialog);

 	private: // Constructors

        CSIPReferDialogAssoc();
        
        static CSIPReferDialogAssoc* NewLC(CSIPConnection& aConnection,
								CUri8* aRemoteUri,
								CSIPReferToHeader* aReferTo,
								CSIPFromHeader* aFrom,
                                CSIPToHeader* aTo,
			                    CSIPContactHeader* aContact,
			                    const MSIPRegistrationContext* aContext);

    private: // Data

        CSIPReferToHeader* iReferTo;
	};

#endif
