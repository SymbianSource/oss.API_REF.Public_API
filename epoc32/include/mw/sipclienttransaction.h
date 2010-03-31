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
* Name        : sipclienttransaction.h
* Part of     : SIP Client
* Interface   :
* Version     : 1.0
*
*/




#ifndef CSIPCLIENTTRANSACTION_H
#define CSIPCLIENTTRANSACTION_H

// INCLUDES
#include "siptransactionbase.h"

// FORWARD DECLARATIONS
class CSIPRefresh;

// CLASS DECLARATION

/**
*  @publishedAll
*  @released
*
*  Class for managing SIP client transactions.
*  It provides services for ending and getting the SIP client transaction
*  parameters. Some client transactions can also be canceled.
*
*  The user of the class cannot instante this class.
*  @lib sipclient
*/
class CSIPClientTransaction: public CSIPTransactionBase
	{
	public: // Destructor

        /**
        * Destructor
		*/
		IMPORT_C ~CSIPClientTransaction();

	public: // New functions

        /**
        * Gets response elements of the most recent response.
        * @return Response elements. Ownership isn't transferred.
        */
		IMPORT_C const CSIPResponseElements* ResponseElements() const;

        /**
		* Cancels client transaction i.e. creates a CANCEL request and sends it
		* to the remote UA.		
		* @pre State()==EProceeding
		* @pre CancelAllowed()==ETrue
		* @pre Connection().State()==EActive
		* @return SIP CANCEL transaction, ownership is transferred.		
		* @leave KErrSIPInvalidTransactionState if canceling is not possible
		*	at all, or because the transaction is not in a proper state or the
        *   transaction is not related to a dialog.
		* @leave KErrSIPResourceNotAvailable if a required SIP Client API
		*	object has been deleted
		* @capability NetworkServices
		*/
		IMPORT_C CSIPClientTransaction* CancelL();

		/**
		* Gets the associated refresh with the transaction.
		* If the refresh is associated with the transaction,
		* transaction will be refreshed at defined interval.
		* @return associated refresh or 0-pointer if there's no
		*         associated refresh. Ownership isn't transferred.
		*/
		IMPORT_C const CSIPRefresh* Refresh() const;

        /**
		* Checks if the client transaction is such that it can be cancelled.
        * This does no check whether the transaction is currently in such a
        * state that the canceling can be done now.
        *
		* @return ETrue if client transaction can be cancelled;
		*         EFalse otherwise
		*/
		IMPORT_C virtual TBool CancelAllowed() const;

	public: // Constructors, for internal use

        /**
		* Instantiates a CSIPClientTransaction object, leaves on failure.
        *
        * @param aType Identifies the transaction type        
        * @param aAssociation Object to which the transaction is associated
        *   with.
        * @param aRefresh If transaction is refreshed, this points to a
        *   CSIPRefresh, otherwise this is NULL. Ownership is not transferred.
		* @return SIP client transaction, ownership is transferred.
		*/
		static CSIPClientTransaction*
            NewL(RStringF aType,
                 MTransactionAssociation& aAssociation,
                 CSIPRefresh* aRefresh=0);

        /**
		* Instantiates a CSIPClientTransaction object and pushes it into
        * CleanupStack, leaves on failure.
        *
        * @param aType Identifies the transaction type        
        * @param aAssociation Object to which the transaction is associated
        *   with.
        * @param aRefresh If transaction is refreshed, this points to a
        *   CSIPRefresh, otherwise this is NULL. Ownership is not transferred.
		* @return SIP client transaction, ownership is transferred.
		*/
		static CSIPClientTransaction*
            NewLC(RStringF aType,
                  MTransactionAssociation& aAssociation,
                  CSIPRefresh* aRefresh=0);

	public: // New functions, for internal use

        /**
		* Sets the RequestId.
        *
        * @pre iRequestId == 0
        * @pre aRequestId != 0
		* @param aRequestId RequestId obtained from SIP client
		*/
		void SetRequestId(TUint32 aRequestId);

        /**
		* Gets the associated refresh with the transaction and allows
        * modification fo the refresh. This method is for internal use only.
        *
		* @return associated refresh or 0-pointer if there's no
		*         associated refresh. Ownership isn't transferred.
		*/
        CSIPRefresh* Refresh();

        /**
	    * Clears the association from ClientTransaction to CSIPRefresh
	    */
        void RemoveRefresh();	

    protected: // Constructor

		CSIPClientTransaction(MTransactionAssociation& aAssociation,
                              CSIPRefresh* aRefresh);

    private: // Data

        //Points to the refresh object if this transaction is refreshed.
        //NULL if not refreshed. Not owned.
        CSIPRefresh* iRefresh;

	private: // For testing purposes
#ifdef CPPUNIT_TEST
	    friend class CSIP_Test;
#endif
	};

#endif
