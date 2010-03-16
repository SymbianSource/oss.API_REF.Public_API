// Copyright (c) 2004-2009 Nokia Corporation and/or its subsidiary(-ies).
// All rights reserved.
// This component and the accompanying materials are made available
// under the terms of the License "Symbian Foundation License v1.0" to Symbian Foundation members and "Symbian Foundation End User License Agreement v1.0" to non-members
// which accompanies this distribution, and is available
// at the URL "http://www.symbianfoundation.org/legal/licencesv10.html".
//
// Initial Contributors:
// Nokia Corporation - initial contribution.
//
// Contributors:
//
// Description:
//



/**
 @file
 @publishedAll
 @released
*/

#ifndef REMCONINTERFACESELECTOR_H
#define REMCONINTERFACESELECTOR_H

#include <e32base.h>
#include <remcon/messagetype.h>
#include <remcon/clienttype.h>
#include <remcon/remconclient.h>
#include <remcon/remconinterfaceif.h>
#include <remconaddress.h>

class CRemConInterfaceBase;
class CReceiver;
class MRemConErrorObserver;

// Panic information
_LIT(KRemConIfSelPanicCat, "RemConIfSel");
enum 
	{
	/** The client has given a bad message type. */
	ERemConIfSelBadMessageType = 0,

	/** The client has already called OpenTargetL successfully.
		
	This is no longer an illegal condition and so the panic will never
	be raised.
	*/
	ERemConIfSelTargetSessionAlreadyExists = 1,

	/** The client has already called OpenControllerL successfully.
		
	This is no longer an illegal condition and so the panic will never
	be raised.
	*/
	ERemConIfSelControllerSessionAlreadyExists = 2,

	/** The client has created (and registered) an outer layer interface of a 
	type which is already registered. */
	ERemConIfSelInterfaceOfThatTypeAlreadyRegistered = 3,
	
	/** The client has not offended- there is a defect in some layer of the 
	Remote Control system. */
	ERemConIfSelInternalError = 4,

	/** An outer-layer interface has been instantiated (and registered with 
	the intermediate layer) after OpenControllerL or OpenTargetL has been 
	successfully called. */
	ERemConIfSelTardyInterfaceRegistration = 5,

	/** OpenControllerL has not successfully been called before using an API 
	which expects a controller session to have been created. */
	ERemConIfSelNoControllerSession = 6,

	/** OpenTargetL has not successfully been called before using an API which 
	expects a target session to have been created. */
	ERemConIfSelNoTargetSession = 7,

	/** Neither OpenControllerL not OpenTargetL has been successfully called 
	before using an API which expects either a controller or a target session 
	to have been created. */
	ERemConIfSelNoSession = 8,

	/** An outer layer DLL has instantiated CRemConInterfaceBase with an 
	illegal client type. */
	ERemConIfSelUndefinedClientType = 9,

	/** An implementation of CRemConInterfaceBase::GetInterface does not 
	provide an implementation of MRemConInterfaceIf. */
	ERemConIfSelNoInterfaceImplementation = 10,
	};

/**
CRemConInterfaceSelector is only instantiable via its NewL function. It is not 
derivable.
*/
NONSHARABLE_CLASS(CRemConInterfaceSelector) : public CBase
	{
public: 
	/**
	Factory method.
	@return Ownership of a new CRemConInterfaceSelector.
	*/
	IMPORT_C static CRemConInterfaceSelector* NewL();

	/** Destructor. */
	IMPORT_C ~CRemConInterfaceSelector();

public:
	/**
	Register the interface with the selector. This is called by the 
	interface's BaseConstructL. Takes ownership of aInterface.
	 This function is not to be called outside of remconinterfacebase.dll. It is available for compatibility with previous
	 versions, but it is intended to be called only by CRemConInterfaceBase::BaseConstructL.
	 CRemConInterfaceBase-derived classes should indirectly perform a RegisterInterfaceL, by calling
	 CRemConInterfaceBase::BaseConstructL from their construction functions.
	@param aInterface The interface.
	*/
	IMPORT_C void RegisterInterfaceL(CRemConInterfaceBase& aInterface);
	
	/** 
	Register an error observer.  This is provided to allow the client to
	discover when an error has occurred passively.
	
	@param aObserver An error observer to be notified on a passive error.
					 NULL to stop receiving notifications.
	*/
	IMPORT_C void RegisterErrorObserver(MRemConErrorObserver* aObserver);

	/**
	Opens a controller session to RemCon. The session is connectionless until 
	such time as GoConnectionOriented may be called.
	@leave KErrInUse If a controller session is already open.
	*/
	IMPORT_C void OpenControllerL();

	/**
	Makes the controller session (which must already exist- use 
	OpenControllerL) connection-oriented.
	@param aConnection The remote to talk to. 
	*/
	IMPORT_C void GoConnectionOrientedL(const TRemConAddress& aConnection);

	/**
	Makes the controller session (which must already exist- use 
	OpenControllerL) connectionless.
	*/
	IMPORT_C void GoConnectionlessL();

	/**
	Brings up a bearer-level connection.
	The controller session must already exist (use OpenControllerL) and 
	be connection-oriented.
	@param aStatus TRequestStatus for asynchronous completion.
	*/
	IMPORT_C void ConnectBearer(TRequestStatus& aStatus);

	/**
	Cancels interest in the completion of a ConnectBearer request.
	@return KErrNone.
	*/
	IMPORT_C TInt ConnectBearerCancel();

	/**
	Destroys a bearer-level connection. 
	The controller session must already exist (use OpenControllerL) and be 
	connection-oriented.
	@param aStatus TRequestStatus for asynchronous completion.
	*/
	IMPORT_C void DisconnectBearer(TRequestStatus& aStat);

	/**
	Cancels interest in the completion of a DisconnectBearer request.
	@return KErrNone.
	*/
	IMPORT_C TInt DisconnectBearerCancel();

	/**
	Opens a target session to RemCon.
	@leave KErrInUse If a target session is already open.
	*/
	IMPORT_C void OpenTargetL();

	/**
	Sends a message to the remote device(s).
	There should be only one command and response outstanding at any one time.
	Send cannot be called again until aStatus is completed.
	@panic RemConClient 4 If a send is already outstanding
	@param aStatus TRequestStatus for asynchronous completion.
	@param aInterfaceUid The UID of the concrete (outer-layer) interface 
	sending the message.
	@param aOperationId The interface-specific operation identifier.
	@param aNumRemotes On success, the number of remotes the message was 
	successfully sent to.
	@param aMsgType Whether the message is a command or a response.
	@param aData Any associated message data in interface-specific format.
	*/
	IMPORT_C void Send(TRequestStatus& aStatus, 
		TUid aInterfaceUid,
		TUint aOperationId, 
		TUint& aNumRemotes,
		TRemConMessageType aMsgType,
		const TDesC8& aData = KNullDesC8());

	/**
	Sends a message to the remote device(s).
	@param aStatus TRequestStatus for asynchronous completion.
	@param aInterfaceUid The UID of the concrete (outer-layer) interface 
	sending the message.
	@param aOperationId The interface-specific operation identifier.
	@param aNumRemotes On success, the number of remotes the message was 
	successfully sent to.
	@param aMsgType Whether the message is a command or a response.
	@param aMsgSubType The subtype of the command of response
	@param aData Any associated message data in interface-specific format.
	*/
	IMPORT_C void Send(TRequestStatus& aStatus, 
		TUid aInterfaceUid,
		TUint aOperationId, 
		TUint& aNumRemotes,
		TRemConMessageType aMsgType,
		TRemConMessageSubType aMsgSubType,
		const TDesC8& aData = KNullDesC8());

	
	/**
	@internalTechnology
	Sends a message to the remote device(s), without waiting for the send to complete
	@param aInterfaceUid The UID of the concrete (outer-layer) interface 
	sending the message.
	@param aOperationId The interface-specific operation identifier.
	@param aMsgType Whether the message is a command or a response.
	@param aData Any associated message data in interface-specific format.
	*/
	IMPORT_C TInt SendUnreliable(
		TUid aInterfaceUid,
		TUint aOperationId, 
		TRemConMessageType aMsgType,
		const TDesC8& aData = KNullDesC8());
	
	/**
	@internalTechnology
	Sends a message to the remote device(s), without waiting for the send to complete
	@param aInterfaceUid The UID of the concrete (outer-layer) interface 
	sending the message.
	@param aOperationId The interface-specific operation identifier.
	@param aMsgType Whether the message is a command or a response.
	@param aMsgSubType The subtype of the command of response
	@param aData Any associated message data in interface-specific format.
	*/
	IMPORT_C TInt SendUnreliable(
		TUid aInterfaceUid,
		TUint aOperationId, 
		TRemConMessageType aMsgType,
		TRemConMessageSubType aMsgSubType,
		const TDesC8& aData = KNullDesC8());
	
	/**
	Cancels interest in the completion of a Send request.
	@param aMsgType The type of the message, the completion of the send of 
	which we are not interested in. This is needed because a single 
	CRemConInterfaceSelector may have two sends outstanding at once, one on 
	a controller session and another on a target session.
	@return KErrNone.
	*/
	IMPORT_C TInt SendCancel(TRemConMessageType aMsgType);

	/**
	Only called internally, by the Active Object which sucks messages out of 
	RemCon. Note that the message type is not given- it is interpolated from 
	the type of the session doing the receiving.
	@param aInterfaceUid Interface UID of the new message.
	@param aOperationId Operation ID of the new message.
	@param aData Data associated with the new message.
	@param aType The type of session which received the message (from which 
	the type of the message can be interpolated).
	*/
	void ReceiveComplete(TUid aInterfaceUid, 
		TUint aOperationId, 
		TRemConMessageSubType aMsgSubType,
		const TDesC8& aData,
		TRemConClientType aType);

	/**
	Only called internally, by the Active Object which sucks messages out of 
	RemCon.  This is called in the case of a session error.
	
	@param The error that has occurred.  If this is KErrServerTerminated, the
		   error is fatal and the session must be restarted before any new 
		   messages can be received.
	*/
	void Error(TInt aError);

	/**
	Getter for the current set of connections in the system (not just those 
	associated with this session). The client is responsible for cleaning up 
	aConnections- the addresses will be on the heap.
	@param aConnections A collection of remote addresses, representing all the 
	currently extant connections.
	@return Error.
	*/
	IMPORT_C TInt GetConnections(TSglQue<TRemConAddress>& aConnections);

	/**
	Notification for changes in the set of connections.
	@param aStatus TRequestStatus for asynchronous completion.
	*/
	IMPORT_C void NotifyConnectionsChange(TRequestStatus& aStatus);

	/**
	Cancels interest in the completion of an outstanding 
	NotifyConnectionsChange operation.
	@return KErrNone.
	*/
	IMPORT_C TInt NotifyConnectionsChangeCancel();
	
	/**
	To determine if a target session has been opened.
	@return EFalse if no session has been opened, ETrue otherwise.
	*/
	IMPORT_C TBool TargetOpened() const;

	/**
	To determine if a controller session has been opened.
	@return EFalse if no session has been opened, ETrue otherwise.
	*/	
	IMPORT_C TBool ControllerOpened() const;

private:
	CRemConInterfaceSelector();

private: // utility
	void AssertSession(RRemCon* aSess, TInt aPanicCode) const;
	TInt TryToReconnect();

private: // owned
	RPointerArray<CRemConInterfaceBase> iInterfaces;

	RRemConController iControllerSession;
	RRemConTarget iTargetSession;

	CReceiver* iTargetReceiver;
	CReceiver* iControllerReceiver;

	/** For all registered interfaces, this is the size of the biggest 
	operation-associated data lump. */
	TUint iMaxDataLength;

	// The session to use for NotifyConnectionsChange and 
	// NotifyConnectionsChangeCancel. It doesn't matter which we use- just one 
	// that's connected will do. The only interesting bit is that the session 
	// we called NotifyConnectionsChange on should be the one we call 
	// NotifyConnectionsChangeCancel on, but as sessions are only closed when 
	// 'this' comes down that's not a complication.
	RRemCon* iNotificationSession;
	
	TRemConAddress iAddress;

private: // unowned	
	MRemConErrorObserver* iErrorObserver;
	};

#endif // REMCONINTERFACESELECTOR_H
