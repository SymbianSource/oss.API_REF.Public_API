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
* Name        : siprefresh.h
* Part of     : SIP Client
* Interface   : SDK API, SIP Client API
* Version     : 1.0
*
*/




#ifndef CSIPREFRESH_H
#define CSIPREFRESH_H

// INCLUDES
#include <e32base.h>
#include <stringpool.h>
#include "_sipcodecdefs.h"

// FORWARD DECLARATIONS
class CSIPClientTransaction;
class CSIPMessageElements;
class MSIPRefreshAssociation;

// CLASS DECLARATION

/**
*  @publishedAll
*  @released
*
*  Class for managing SIP refresh.
*  It provides functions for getting associated sip transaction
*  and state. Class also provides functions for updating and terminating 
*  stand-alone refreshes.
*
*  Note that only stand-alone refreshes (i.e. refreshes that are not associated
*  with registration binding or dialog associations) can be terminated or
*  updated using functions defined in this class.
*
*  @lib sipclient.lib
*/
class CSIPRefresh: public CBase
	{
	public:

		/** SIP refresh states */
		enum TState
			{
			/** SIP refresh is inactive */
			EInactive,
			/** SIP refresh active */
			EActive,
			/** SIP refresh is terminated */
			ETerminated,
			/** Object is being constructed and is not yet ready for use */
			EConstructing
			};

	public: // Constructors and destructor

		/**
		* Two-phased constructor
        * @return New object. Ownership is transferred.
		*/
		IMPORT_C static CSIPRefresh* NewL();

		/**
		* Two-phased constructor
        * @return New object. Ownership is transferred.
		*/
		IMPORT_C static CSIPRefresh* NewLC();

		/**
		* Destructor
		*/
		IMPORT_C ~CSIPRefresh();

	public: // New functions

		/**
		* Gets the state of the refresh
		* @return refresh state
		*/
        IMPORT_C CSIPRefresh::TState State() const;

		/**
		* Tests if the refresh is a stand-alone refresh
		* @return ETrue if refresh is a stand-alone; EFalse otherwise
		*/
		IMPORT_C TBool IsStandAlone() const;
		
		/**
		* Gets the associated SIP transaction with this refresh.
        *
		* @return Associated SIP transaction or 0-pointer. Ownership is not
        *   transferred.
		*/
		IMPORT_C const CSIPClientTransaction* SIPTransaction() const;

		/**
		* Terminates the refresh by sending SIP request to the remote
        * destination. The new client transactation will be of the same type
        * as the first transaction associated with this request.
		* @pre State()==EActive
		* @pre IsStandAlone()==ETrue
		* @param aElements contains optional SIP message headers and body.
        *   Ownership is transferred.
		* @return SIP client transaction. Ownership is transferred.
		* @leave KErrSIPInvalidTransactionState if State() is not EActive
		*		 KErrNotFound if the CSIPRefresh is no longer associated to
        *        anything
        *        KSIPErrInvalidRegistrationState if trying to terminate a
        *        REGISTER refresh.
        *        KErrSIPInvalidDialogState if trying to terminate a dialog
        *		 association being refreshed. 
        * @capability NetworkServices
		*/
		IMPORT_C CSIPClientTransaction*
            TerminateL(CSIPMessageElements* aElements=0);

		/**
		* Updates the refresh by sending SIP request to the remote destination.
        * The new client transactation will be of the same type as the first
        * transaction associated with this request.
		* @pre State()==EActive
		* @pre IsStandAlone()==ETrue
		* @param aElements contains optional SIP message headers and body.
        *   Ownership is transferred.
		* @return SIP client transaction. Ownership is transferred.
        * @leave KErrSIPInvalidTransactionState if State() is not EActive
		*		 KErrNotFound if the CSIPRefresh is no longer associated to
        *        anything
        *        KErrSIPInvalidRegistrationState if trying to update a
        *        REGISTER refresh. 
        *        KSIPErrInvalidDialogState if trying to update a
        *        dialog association being refreshed. 
        * @capability NetworkServices
		*/
		IMPORT_C CSIPClientTransaction*
            UpdateL(CSIPMessageElements* aElements=0);

		/**
		* Compares this object to another object 
		* @param aRefresh a CSIPRefresh type object to compare
		* @return ETrue if the objects are equal otherwise EFalse
		*/
	    IMPORT_C TBool operator==(const CSIPRefresh& aRefresh) const;

		/**
		* Gets current refresh interval
		* @pre State()==CSIPRefresh::EActive
		* @return current refresh interval in seconds
		* @leave KErrSIPInvalidTransactionState if State() is not EActive
		* @leave KErrSIPResourceNotAvailable if SIP server can't be contacted
		*	because a required resource has been deleted.		
		*/
		IMPORT_C TUint IntervalL() const;

		/**
		* Sets refresh interval. 
		* Note that SIP server choses the refresh interval. This function should
		* be used only if SIP server has indicated new refresh interval using
		* SIP messages that are not associated to the refresh needing the update.
		* @pre State()==CSIPRefresh::EActive
		* @pre aInterval > 0
		* @param aInterval a new interval in seconds
		* @leave KErrArgument if aInterval == 0
		* @leave KErrSIPInvalidTransactionState if State() is not EActive
		* @leave KErrSIPResourceNotAvailable if SIP server can't be contacted
		*	because a required resource has been deleted.
		*/
		IMPORT_C void SetIntervalL(TUint aInterval);

	public: // New functions, for internal use

	    TBool DoesMatch(TUint32 aRefreshId) const;

        /**
		* Associate the CSIPRefresh with another object.
		* @param aAssoc Object associated with the CSIPRefresh
		* @return ETrue if the objects are equal otherwise EFalse
		*/
        void SetRefreshOwner(MSIPRefreshAssociation& aAssoc);

        void RemoveRefreshOwner(const MSIPRefreshAssociation& aAssoc);

        void ChangeState(CSIPRefresh::TState aNextState);

        void UpdateRefreshState(TUint aStatusCode);

        TUint32 RefreshId() const;

        void SetRefreshIdIfEmpty(TUint32 aRefreshId);        

        RStringF RequestType() const;

        void SetRequestType(RStringF aType);

        void AddTransaction(CSIPClientTransaction& aTransaction);

        void RemoveTransaction();

        CSIPClientTransaction* Transaction();

	private: // Constructors

		CSIPRefresh();

		void ConstructL();

	private:

		void CheckStateL() const;
		
	private: // Data

        MSIPRefreshAssociation* iOwner;

        //Client transaction which is refreshed, not owned by CSIPRefresh.        
        CSIPClientTransaction* iClientTransaction;

		//Current state of the refresh
        TState iState;

        //RefreshId received from SIP client        
        TUint32 iRefreshId;

        //Identifies the request method which is being refreshed
        RStringF iRequestType;

	private: // For testing purposes

	    UNIT_TEST(CSIP_Test)
        UNIT_TEST(CSIPConnection_Test)
	};

#endif
