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
* Name        : sipservertransaction.h
* Part of     : SIP Client
* Interface   : SDK API, SIP API
* Version     : 1.0
*
*/



#ifndef CSIPSERVERTRANSACTION_H
#define CSIPSERVERTRANSACTION_H

// INCLUDES
#include "siptransactionbase.h"

// FORWARD DECLARATIONS
class CSIPRequestElements;
class MSIPResponseSender;
class CSIPConnection;
class CSIPDialogImplementation;

// CLASS DECLARATION

/**
*  @publishedAll
*  @released
*
*  Class for managing SIP server transactions.
*  It provides services for creating, ending
*  and getting SIP transaction parameters.
*  Client cannot instantiate this class.
*  
*  @lib sipclient
*/
class CSIPServerTransaction: public CSIPTransactionBase
	{
	public: // Destructor
    
        /**
        * Destructor
		*/
		IMPORT_C ~CSIPServerTransaction();

	public: // New functions
	
        /**
		* Sends response and ends the transaction;
		* The user must not send 100 Trying response. Leaves on failure.
        * @pre aElements!=0
        * @pre State()==ETrying || State()==EProceeding
		* @pre CSIPConnection::State()==EActive
		* @pre ResponseAllowed()==ETrue		
		* @param aElements contains Status Code, optional Reason Phrase and
        *   optional SIP message headers and body. Ownership is transferred.
		* @leave KErrArgument if aElements == NULL
		* @leave KErrGeneral if ResponseAllowed() == EFalse
		* @leave KErrSIPInvalidTransactionState if State()!=ETrying and
		*	State()!=EProceeding
		* @leave KErrSIPInvalidDialogState if sending response to a request
		*	within dialog, and the dialog is in terminated state.
		* @leave KErrSIPResourceNotAvailable if a required SIP Client API
		*	object has been deleted
		* @capability NetworkServices
		*/
		IMPORT_C void SendResponseL(CSIPResponseElements *aElements);

	    /**
		* Gets the request elements
		* @return Request elements. Ownership is not transferred.
		*/
		IMPORT_C const CSIPRequestElements* RequestElements() const;

        /**
		* Checks if the response sending is allowed for this server
        * transaction. For instance response is not allowed in ACK transaction.
		* @return ETrue if response sending is allowed, EFalse otherwise
		*/
		IMPORT_C TBool ResponseAllowed() const;
        
	public: // New functions, for internal use
	
        /**
		* Sets a new respose sender, replacing the current sender.
		*
        * @param aSender Response sender to be used from now on. Ownership is
        *   	 transferred.		
		*/
        void SetResponseSender(MSIPResponseSender* aSender);

		/**
		* If the request was received inside a dialog, returns the dialog.		
		*
        * @return CSIPDialogImplementation* The dialog inside which the request
        *	was received, or NULL. Ownership is not transferred.
		*/
		CSIPDialogImplementation* Dialog() const;

        /**
	    * Obtains the associated CSIPConnection instance. If connection can't
        * be accessed anymore, this function leaves.
        *	
	    * @return CSIPConnection
	    */
        CSIPConnection& SIPConnectionL();

        /**
		* Update the MTransactionAssociation to point to aAssociation.
		*
        * @param aAssociation Associated object		
		*/
        void ReAssociateL(MTransactionAssociation& aAssociation);

        /**
		* Removes, but does not delete, request elements from
        * aServerTransaction.
        *
		* @param aServerTransaction Server transaction from which response
        *   elements are removed. Ownership is not transferred.
		*/
        static void DetachRequestElements(TAny* aServerTransaction);

	public: // Constructors, for internal use
        /**
		* Creates a server transaction.
		*
        * @param aRequestId RequestId for the transaction to use
        * @param aAssociation Object with which the transaction is associated
        * @param aElements Request elements. Ownership is transferred.
        * @return New object. Ownership is transferred.
		*/
		static CSIPServerTransaction*
            NewL(TUint32 aRequestId,
                 MTransactionAssociation& aAssociation,
                 CSIPRequestElements* aElements);

        /**
		* Creates a server transaction and pushes it to cleanup stack.
		*
        * @param aRequestId RequestId for the transaction to use
        * @param aAssociation Object with which the transaction is associated
        * @param aElements Request elements. Ownership is transferred.
        * @return New object. Ownership is transferred.
		*/
		static CSIPServerTransaction*
            NewLC(TUint32 aRequestId,
                  MTransactionAssociation& aAssociation,
                  CSIPRequestElements* aElements);

	private: // Constructors
		CSIPServerTransaction(TUint32 aRequestId,
                              MTransactionAssociation& aAssociation);

        /**
		* Second phase constructor.
		*
		* @pre aElements!=0
        * @param aElements Request elements. Ownership is transferred.        
		*/
        void ConstructL(CSIPRequestElements* aElements);

	private: // Data
        CSIPRequestElements* iRequestElements;

        //This interface is used for sending the response.
        //CSIPServerTransaction owns iResponseSender.
        MSIPResponseSender* iResponseSender;

	private: // For testing purposes        

	    UNIT_TEST(CSIPServerTransaction_Test)
        UNIT_TEST(CSIP_Test)

		__DECLARE_TEST;
	};

#endif
