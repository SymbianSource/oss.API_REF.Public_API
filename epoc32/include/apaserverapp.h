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

#ifndef APASERVERAPP_H
#define APASERVERAPP_H

#include <e32base.h>


//
// Server application client support
//



class RApaAppServiceBase : public RSessionBase
/** Server app connection and lifetime monitoring functionality.

This is the base class for all server application service client
support implementations.

The class is derived from by the UI framework and is further derived from 
by service implementations.

Clients of these server application services will use these derived classes as
the interface to the server application implementations of the services.

@publishedPartner
@released
@see REikAppServiceBase */
	{
public:

	/** Constants defining the base IPC command ids usable by the system GUI and services. */
	enum TApaAppServiceBaseCmdConstants
		{
		/** System GUI server app command IDs must start from this base. */
		KSystemGuiCmdBase = 0x100,
		/** Service specific command IDs must start from this base. */
		KServiceCmdBase = 0x200
		};

public:
	IMPORT_C void ConnectExistingAppL(const RApaAppServiceBase& aClient);
	IMPORT_C void ConnectExistingAppL(const RApaAppServiceBase& aClient, const TSecurityPolicy& aSecurityPolicy);
	IMPORT_C void ConnectExistingByNameL(const TDesC& aName);
	IMPORT_C void ConnectExistingByNameL(const TDesC& aServerName, const TSecurityPolicy& aSecurityPolicy);
	IMPORT_C void TransferExistingSessionL(RApaAppServiceBase& aClient);
	IMPORT_C void Close(); //lint !e1511 Member hides non-virtual member

	IMPORT_C void NotifyServerExit(TRequestStatus& aStatus) const;
	IMPORT_C void CancelNotifyServerExit() const;
	
	IMPORT_C TPtrC ServerName() const;

protected:
	IMPORT_C RApaAppServiceBase();

private:
	IMPORT_C virtual void RApaAppServiceBase_Reserved1();
	IMPORT_C virtual void RApaAppServiceBase_Reserved2();
	
	/** Returns the UID of the service that this session provides an interface for.
	Client side service implementations must implement this function to return
	the UID for the service that they implement.
	@return The UID of the service implemented by the derived class.*/
	virtual TUid ServiceUid() const = 0;

private:
	void ConnectL();
	void ConnectL(const TSecurityPolicy& aSecurityPolicy);

private:
	IMPORT_C virtual void ExtensionInterface(TUid aInterfaceId, TAny*& aImplementaion);
	
private:
	HBufC* iServerName;		// owned
	TInt iApaReserved1;
	TInt iApaReserved2;
	};


class MApaServerAppExitObserver
/** Interface for a class that wants to receive exit notification from
a server application.

@publishedPartner
@released
@see CApaServerAppExitMonitor*/
	{
public:
	/** Receives server exit notification.
	Implementers of this interface must override this function to
	receive notification of server app exit reasons.
	@param aReason The reason that the server app exited, this may be
	a command ID from the UI if exit was triggered from the UI, or an error code
	if the server app exited unexpectedly. */
	virtual void HandleServerAppExit(TInt aReason) = 0;
protected:
	IMPORT_C MApaServerAppExitObserver();
private:
	IMPORT_C virtual void MApaServerAppExitObserver_Reserved1();
	IMPORT_C virtual void MApaServerAppExitObserver_Reserved2();
private:
	TInt iMApaServerAppExitObserver_Reserved1;
	};


class CApaServerAppExitMonitor : public CActive
/** Helper class that monitors the lifetime of a server app
through a connected RApaAppServiceBase and reports server app exits
to a MApaServerAppExitObserver derived class.

@publishedPartner
@released
@see RApaAppServiceBase
@see MApaServerAppExitObserver */
	{
public:
	IMPORT_C static CApaServerAppExitMonitor* NewL(RApaAppServiceBase& aClient, MApaServerAppExitObserver& aObserver, TInt aPriority);
	IMPORT_C static CApaServerAppExitMonitor* NewLC(RApaAppServiceBase& aClient, MApaServerAppExitObserver& aObserver, TInt aPriority);
	IMPORT_C ~CApaServerAppExitMonitor();

private:
	CApaServerAppExitMonitor(RApaAppServiceBase& aClient, MApaServerAppExitObserver& aObserver, TInt aPriority);

private:	// from CActive
	void RunL();
	void DoCancel();
	TInt RunError(TInt aError);

private:
	RApaAppServiceBase& iClient;
	MApaServerAppExitObserver& iObserver;
	};

	
//
// Server application server support
//

/** Panic codes that the server application framework can generate.
@internalComponent */
enum TApaAppServerPanic
	{
	/** The IPC message ID used by the client is not recognised. */
	EApaAppServerPanicIllegalFunction,
	/** The client already has an active notification of server exit. */
	EApaAppServerPanicNotifyExitActive,
	/** The client has tried to connect an already connected session. */
	EApaAppServerPanicClientAlreadyConnected
	};


class CApaAppServiceBase : public CSession2
/** Base class for all service implementations.
Provides the basic IPC and security framework that server applications
can use to receive messages from their clients.
In a typical service implementation, a service support class
will be derived from this class, and the service implementation
will then be derived from the service support class.

Instances of this class are created by the server application
in its override of CApaAppServer::CreateServiceL().

@publishedPartner 
@released
@see CApaAppServer
@see CPolicyServer */
	{
public:
	IMPORT_C CApaAppServiceBase();
	IMPORT_C ~CApaAppServiceBase();

	IMPORT_C virtual CPolicyServer::TCustomResult SecurityCheckL(const RMessage2& aMsg, TInt& aAction, TSecurityInfo& aMissing);

public: // internal
	void SendAppServerExitNotification(TInt aExitReason);

protected: // from CSession2
	IMPORT_C void CreateL();
	IMPORT_C void ServiceL(const RMessage2& aMessage);
	IMPORT_C void ServiceError(const RMessage2& aMessage,TInt aError);
	IMPORT_C virtual TInt CountResources();
	IMPORT_C virtual void Disconnect(const RMessage2& aMessage);

private: // Server exit notification handlers
	void NotifyServerExit(const RMessage2& aMessage);
	void CancelNotifyServerExit(const RMessage2& aMessage) const;

private:
	IMPORT_C virtual void ExtensionInterface(TUid aInterfaceId, TAny*& aImplementaion);
	IMPORT_C virtual void CApaAppServiceBase_Reserved1();
	IMPORT_C virtual void CApaAppServiceBase_Reserved2();
	
private:
	RMessagePtr2 iNotifyExitMsg;
	TInt iExitReason;
	TInt iApaReserved2;
	};

class CApaAppServer : public CPolicyServer
/** Base class for all server application's servers.
Server applications must derive from this class to implement their
servers. These must be instantiated in an override of
CApaApplication::NewAppServerL().
The main task of this class is to create service implementations
that clients of a server app may connect to.

@publishedPartner 
@released
@see CEikAppServer
@see CPolicyServer */
	{
public:
	IMPORT_C ~CApaAppServer();
	IMPORT_C virtual void ConstructL(const TDesC& aFixedServerName);
	
	IMPORT_C void NotifyServerExit(TInt aReason);
	
	IMPORT_C virtual CApaAppServiceBase* CreateServiceL(TUid aServiceType) const;
	IMPORT_C virtual TCustomResult CreateServiceSecurityCheckL(TUid aServiceType, const RMessage2& aMsg, TInt& aAction, TSecurityInfo& aMissing);

protected:
	IMPORT_C CApaAppServer();
	
	// From CPolicyServer
	IMPORT_C TCustomResult CustomSecurityCheckL(const RMessage2& aMsg, TInt& aAction, TSecurityInfo& aMissing);
	// From CServer2
	IMPORT_C virtual void DoConnect(const RMessage2& aMessage);
	
private:
	IMPORT_C CSession2* NewSessionL(const TVersion& aVersion, const RMessage2& aMessage) const;
	
private:
	TUid ConnectMessageServiceUid(const RMessage2& aMsg) const;
	
private:
	IMPORT_C virtual void ExtensionInterface(TUid aInterfaceId, TAny*& aImplementaion);
	// Extensions
	IMPORT_C virtual void CApaAppServer_Reserved1();
	IMPORT_C virtual void CApaAppServer_Reserved2();
	
private:
	TInt iApaReserved1;
	TInt iApaReserved2;
	};


#endif
