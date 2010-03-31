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
* Name        : sipdialog.h
* Part of     : SIP Client
* Interface   : SDK API, SIP Client API
* Version     : 1.0
*
*/




#ifndef CSIPDIALOG_H
#define CSIPDIALOG_H

// INCLUDES
#include <e32base.h>
#include <stringpool.h>

// FORWARD DECLARATIONS
class CSIPConnection;
class CSIPConnectionImplementation;
class MSIPRegistrationContext;
class CSIPDialogAssocBase;
class CSIPFromHeader;
class CSIPToHeader;
class CSIPCallIDHeader;
class CUri8;
class CSIPDialogImplementation;

// CLASS DECLARATION

/**
*  @publishedAll
*  @released
*
*  Class for managing SIP dialogs.
*  It provides services querying dialog state, obtaining the dialog related
*  SIP headers and getting all dialog associations.
*
*  The user of the class cannot instantiate this class.
*  @lib sipclient
*/

class CSIPDialog: public CBase
	{
	public:
		/** Dialog states */
		enum TState
			{
			/** Initiliazed state */
			EInit,
			/** Early state */
			EEarly,
			/** Confirmed state */
			EConfirmed,
			/** Terminated state */
			ETerminated
			};

	public: //New functions
		/**
		* Gets dialog state		
		* @return dialog state
		*/
        IMPORT_C CSIPDialog::TState State() const;

		/**
		* Gets all dialog associations. 		
		* @return All dialog associations. Ownership of the array or the items
        *   inside it, is not transferred.
		*/
		IMPORT_C const RPointerArray<CSIPDialogAssocBase>&
					   SIPDialogAssociations() const;

        /**
        * Gets used registration context for this dialog
        * @return associated registration or 0-pointer otherwise.
        *   Ownership is not transferred.
        */
        IMPORT_C const MSIPRegistrationContext* RegistrationContext() const;
	
        /**
		* Checks if the dialog association belongs to this dialog
		* @param aDialogAssoc a dialog association
		* @return ETrue if belongs, EFalse otherwise
		*/
		IMPORT_C TBool
            IsAssociated(const CSIPDialogAssocBase& aDialogAssoc) const;

        /**
		* Gets the SIP connection used for this dialog
		* @return SIP connection used for the dialog, or 0-pointer if the
        *   connection has been deleted. Ownership isn't transferred.
		*/
        IMPORT_C CSIPConnection* Connection();

        /**
		* Gets the SIP connection used for this dialog.
		* @return SIP connection used for the dialog, or 0-pointer if the
        *   connection has been deleted. Ownership isn't transferred.
		*/
        IMPORT_C const CSIPConnection* Connection() const;

        /**
		* Gets originator's address
		* @return originator's address (From-header)
		*/
		IMPORT_C const CSIPFromHeader& FromHeader() const;

		/**
		* Gets recipient's address
		* @return recipient's address (To-header)
		*/
		IMPORT_C const CSIPToHeader& ToHeader() const;

		/**
		* Gets remote-uri used during dialog creation
		* @return Remote target uri
		*/
		IMPORT_C const CUri8& RemoteURI() const;

		/**
		* Gets Call-ID of SIP dialog
		* @pre State()==CSIPDialog::EEarly || State()==CSIPDialog::EConfirmed
		* @return Call-ID of SIP dialog
		* @leave KErrSIPInvalidDialogState if dialog doesn't yet have a Call-ID
		*/
		IMPORT_C const CSIPCallIDHeader& CallIdL() const;

        /**
		* Compares this object to another object
		* @param aDialog CSIPDialog object to compare
		* @returns ETrue if the objects are equal, otherwise EFalse
		*/
        IMPORT_C TBool operator==(const CSIPDialog& aDialog) const;
        
        /**
        * Sets the dialog to state to CSIPDialog::EInit.
        * The local dialog identifier data 
        * (Call-ID, CSeq and From-header's tag) will be reused. 
        * After calling this function, the dialog that was already terminated 
        * can be used for sending the dialog initiating request such as 
        * INVITE or SUBSCRIBE reusing the stored Call-ID and From-header's tag
        * and the stored CSeq incremented by one.
        * @pre State()==CSIPDialog::ETerminated
        * @returns KErrNone if succesful and KErrNoMemory if the memory is low.
        */
        IMPORT_C TInt ReuseInitialRequestData();

	public: //Constructors and destructor, for internal use
		/**
		* Two-phased constructor. 
		* This constructor should be used if the user has received
		* SIP request that creates a SIP dialog association.
        *
        * @param aConnImplementation Implementation of the used SIP connection
        * @return New object, ownership is transferred.
        */
		static CSIPDialog*
			NewL(CSIPConnectionImplementation& aConnImplementation);

		/**
		* Two-phased constructor
		* This constructor should be used if the user has received
		* SIP request that creates a SIP dialog association.
        *
		* @param aConnImplementation Implementation of the used SIP connection
        * @return New object, ownership is transferred.
       	*/
		static CSIPDialog*
			NewLC(CSIPConnectionImplementation& aConnImplementation);

		/**
		* Two-phased constructor
		* This constructor should be used if the user has received
		* SIP request that creates a SIP dialog association.
        *
        * @param aConnImplementation Implementation of the used SIP connection
		* @param aContext Registration context whose outbound proxy and other
		*        parameters are to be used.
        * @return New object, ownership is transferred.
       	*/
		static CSIPDialog*
			NewL(CSIPConnectionImplementation& aConnImplementation,
                 const MSIPRegistrationContext& aContext);

		/**
		* Two-phased constructor
		* This constructor should be used if the user has received
		* SIP request that creates a SIP dialog association.
        *
        * @param aConnImplementation Implementation of the used SIP connection
		* @param aContext Registration context whose outbound proxy and other
		*        parameters are to be used.
        * @return New object, ownership is transferred.
        */
		static CSIPDialog*
			NewLC(CSIPConnectionImplementation& aConnImplementation,
                  const MSIPRegistrationContext& aContext);

		/**
		* Destructor
		*/
		~CSIPDialog();

	public: // New functions, for internal use

		/**
		* Returns the CSIPDialogImplementation.
 		* @return CSIPDialogImplementation
 		*/
		CSIPDialogImplementation& Implementation();

    private: // Constructors

        CSIPDialog();        

        void ConstructL(CSIPConnectionImplementation& aConnImplementation);
        
        void ConstructL(CSIPConnectionImplementation& aConnImplementation,
                   		const MSIPRegistrationContext& aContext);

private: // Data

		//Implementation instance, CSIPDialog doesn't own it
		CSIPDialogImplementation* iImplementation;

private: // For testing purposes
#ifdef CPPUNIT_TEST
	    friend class CSIP_Test;
        friend class CSIPInviteDialogAssoc_Test;
        friend class CSIPSubscribeDialogAssoc_Test;
        friend class CSIPReferDialogAssoc_Test;
#endif
	void __DbgTestInvariant() const;

	};

#endif
