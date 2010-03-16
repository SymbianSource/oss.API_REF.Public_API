// Copyright (c) 2003-2009 Nokia Corporation and/or its subsidiary(-ies).
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

#ifndef __OBEXBASE_H
#define __OBEXBASE_H

#include <obextypes.h>
#include <mobexnotify.h>

class CObexTransportControllerBase;
class TObexTransportInfo;
class CObexPacket;
class CObexNotifyHandlerBase;

/**
@publishedAll
@released

This class is the common base class for any object which wishes
to use the Obex Server or Client.
The class which owns a CObexClient or CObexServer must be provide an object
derived from this class to handle the call from the Server/Client for a request
for a Password.
@see CObex::SetCallBack
*/
class MObexAuthChallengeHandler
	{
public:
	/**
	Indicates that the server/client has received an Authentication challenge. The challenge
	can only be responded to once a password has been retrieved by some means and passed
	back to the calling class. The password is passed back via CObex::UserPasswordL
	@param aRealm This will contain the Realm specified by the unit forcing the
	Authentication, if no UserID was supplied then this parameter will be of zero length. 
	*/
	virtual void GetUserPasswordL(const TDesC& aRealm) = 0;
		
	/**
 	Returns a null aObject if the extension is not implemented, or a pointer to another interface if it is.
	@param aInterface UID of the interface to return
	@param aObject the container for another interface as specified by aInterface
	*/
	IMPORT_C virtual void MOACH_ExtensionInterfaceL(TUid aInterface, void*& aObject);
	};

/**
This class is the common base class for CObexClient and CObexServer. It is 
an abstract class and cannot be instantiated in itself. However, it does 
contain user functionality common to both client and server connections.

Provides the basic OBEX transport functionality (sending and receiving 
files)
Client and server provide the more specialied APIs for
- initiation or response to puts & gets
- (possible) handling of more generalised 'objects' (prob. with data buffered through a file).

This class is not designed for user derivation

@publishedAll
@released
*/
NONSHARABLE_CLASS(CObex) : public CBase, protected MObexNotify
	{
public:
	/**
	Describes the information set or received in a SETPATH command.
	
	The first bit of iFlags, 0, can be set to indicate to the receiver of SETPATH to backup a level before applying the path name.
	The second bit of iFlags, 1, can be set to indicate to the receiver of SETPATH to NOT create the directory if it doesn't exist.
	The iConstants variable is always set to zero as it is reserved. 
	The iName variable indicates the directory to create or go to, and does not include the root directory of the receiver (i.e. 
	if the directory to be set is C:\notes then iName is set to "notes").
	 If  a name is not set then set CObex::TSetPathInfo::iNamePresent to false. 
	*/
	NONSHARABLE_CLASS(TSetPathInfo)
		{
	public:
		IMPORT_C TSetPathInfo();
		TSetPathInfo(const TObexSetPathData& aData);
		IMPORT_C TBool Parent() const;
		TUint8 iFlags;
		TUint8 iConstants;
		TBuf<KObexObjectDescriptionSize> iName;
		/** Whether iName is present in this SETPATH info */	
		TBool iNamePresent;	
	private:
		// This data padding has been added to help prevent future binary compatibility breaks	
		// Neither iPadding1 nor iPadding2 have been zero'd because they are currently not used
		TUint32     iPadding1; 
		TUint32     iPadding2; 				
		};
		
	/**
	Current obex connection state
	In general, the further through the enum the values are,
	the further through the connection process the state machine
	will be.
	*/
	enum TConnectState 
		{ 
		EConnIdle,					/** Nothing is happening */
		EConnTransport,				/** Transport Link connected not yet established true Link */
		EConnObex,					/** full connection established */
		ESimpleConnRequest,			/** Connect without Auth has been sent by ClientReceived by Server */
		EConnChallRxed,				/**  Server has issued a challenge, to a Client cionnect */
		ESimpleConnChallIssued,		/** Server, received Simple Connect but Server Challenge issued */
		EChallConnRequested,		/** Connect with Auth has been sent by Client/Received by Server */
		EChallConnChallIssued,		/** Server has sent a Challenge & Resp to a Client EChallConnRequest */
		EWaitForFinalResponse,		/** Client, waiting for final success/fail not chall-response expected
									    Server, Waiting for final Resp fromm Client to Challenge */
		EFinalResponseReceived,		/** Server, the final response has been received */
		EFinalChallRxed,			/** Server, Client connect with challenge, Server responds with challenge, Client re-issued original/new challenge */
		EWaitForUserInput,			/** waiting for the user */
		EDropLink					/** drop the link */
		};

	/**
	The Obex operation currently being performed.
	*/
	enum TOperation 
		{ 
		EOpConnect		= 0x00, /** Connect */
		EOpDisconnect	= 0x01, /** Disconnect */
		EOpPut			= 0x02, /** Put */
		EOpGet			= 0x03, /** Get */
		EOpSetPath		= 0x05, /** SetPath */
		EOpAbort		= 0xFF,	/** Abort - must fit in one pkt so final bit is always set */
		EOpAbortNoFBit	= 0x7F, /** Abort (internal, never transmitted) */
		EOpGetResponse  = 0xFD,	/** Internal - not actually an obex operation. */
		EOpIdle			= 0xFE,	/** Internal - not actually an obex operation. */
		};
		
	/**
	Flags to suppress the authentication elements of the authentication challenge header.
	*/
	enum TObexSuppressedAuthElements
	{
	EObexNoSuppressedAuthElements				= 0x00,
	EObexSuppressChallengeOptionsAuthElement	= 0x01,
	EObexSuppressRealmAuthElement				= 0x02,
	EObexSuppressAllAuthElements				= EObexSuppressChallengeOptionsAuthElement | EObexSuppressRealmAuthElement // Must be last
	};		
		
	virtual ~CObex();
	IMPORT_C void SetCallBack(MObexAuthChallengeHandler& aCallBack);
	IMPORT_C TBool IsConnected() const;
	IMPORT_C TBool IsStrictPeer() const;
	IMPORT_C const TObexConnectInfo& LocalInfo() const;
	IMPORT_C TInt SetLocalWho(const TDesC8& aInfo); 
    IMPORT_C const TObexConnectInfo& RemoteInfo() const;
   	IMPORT_C void SuppressAuthenticationHeaderElements(TObexSuppressedAuthElements aSuppressedObexAuthElements);
	    
	// Implementation of MObexNotify Interface
	/**
	@internalTechnology
	*/
	virtual void Process(CObexPacket& aPacket);
	/**
	@internalTechnology
	*/
	virtual void Error(TInt aError) ;
	/** Call back to start the obex session
	@internalTechnology
	*/
	virtual void TransportUp();
	/**
	@internalTechnology
	*/
	virtual void TransportDown(TBool aForceTransportDeletion);
	
	virtual void UserPasswordL( const TDesC& aPassword) = 0; 
	IMPORT_C void RemoteAddr(TSockAddr& anAddr); 

	TConnectState GetConnectState() const;

	IMPORT_C TBool IsAuthenticating() const;
	
protected:
	CObex();
	virtual void ConstructL(TObexTransportInfo& aObexTransportInfo);
	virtual TInt ParseConnectPacket(CObexPacket& aPacket) = 0;	
	void SetConnectState(TConnectState aNewState);
	IMPORT_C TConnectState ConnectState() const;	// same as GetConnectState - has to be maintained here for BC
	virtual void OnPacketReceive(CObexPacket& aPacket) =0;
	virtual void OnError(TInt aError) =0;
	virtual void OnTransportUp() =0;
	virtual void OnTransportDown() =0;
	void ProcessChallengeL(const TObexInternalHeader& hdr);			//process the received challenge
	void ProcessChallResponseL(const TObexInternalHeader& hdr);		//process the response to challenge
	TInt GenerateChallenge(CObexPacket& aPacket);					//generate a challenge 
	void PrepareChallResponseL(const TDesC& aPassword);			//generate a response a respose to challenge
															//after user Password input
	void ForcedTransportDown();
	void ControlledTransportDown();
	void RemoteInfoCleanup();
	void CObex::CancelObexConnection();
protected:
	TConnectState iConnectState;
	CObexTransportControllerBase* iTransportController;
	TObexConnectInfo iLocalInfo;
	TObexConnectInfo iRemoteInfo;
	MObexAuthChallengeHandler* iCallBack;
	TNonce iOutgoingNonce; //nonce used when challenging
	TNonce iIncomingNonce; //nonce used when receiving a challenge
	HBufC8* iChallPassword; //password used when challenging
	HBufC8* iRespPassword; //password used when responding to a challenge
	HBufC8* iRxChallenge;
	TBuf8<KChallResponseSize> iOutgoingChallResp;//response to the previously issued challenge
								//16 nonce, 16 digest resp, 20 UserID, 3*(tag+size)
	TBuf8<KChallResponseSize> iIncomingChallResp;//response received from previous challenge
	TBuf8<KObexRespSize> iIncomingRequestDigest;
	HBufC* iRemoteUID; //UID of remote device
	HBufC* iRemoteRealm;//Realm of remote device
	CObexAuthenticator* iAuthEngine;
	TBool iChallenge; //to challenge or not to challenge?
	TBool iUserIDRequested; //does the challenge insist that a UserID is returned
	TBool iReserved; //released boolean now available for future use
	TOperation iCurrentOperation;
	CObexNotifyHandlerBase* iNotifyHandler;
	TUint iSuppressedObexAuthElements;
	};

#endif // __OBEXBASE_H
