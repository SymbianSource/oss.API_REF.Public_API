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

#ifndef __LBS_H__
#define __LBS_H__

#include <lbspositioninfo.h>
#include <lbsipc.h>
#include <lbscommon.h>
#include <lbsrequestor.h>
#include <lbscriteria.h>

// Forward declarations
class CPositioningPtrHolder;
class CServerPositioningPtrHolder;
class RPositionServer : public RSessionBase

/**
This is generally the first interface class used by all client applications.
It is used to make the primary connection to the location server. After the
primary connection has been established, its handle is passed as a parameter
of the Open methods of RPositioner to create a "sub-session".

The RPositionServer class can also be used to discover what position
technology "modules" are available. However, this is only required if a
client application actually needs to use a particular module.

@publishedAll
@released
 */
	{
public:
	IMPORT_C RPositionServer();

	IMPORT_C TInt Connect();
	IMPORT_C void Close();

	IMPORT_C TInt CancelRequest(TInt aRequestId);
	IMPORT_C TVersion Version() const;

	IMPORT_C TInt GetDefaultModuleId(TPositionModuleId& aModuleId) const;
	IMPORT_C TInt GetNumModules(TUint& aNumModules) const;
	IMPORT_C TInt GetModuleInfoByIndex(TInt aModuleIndex,
	                                   TPositionModuleInfoBase& aModuleInfo) const;
	IMPORT_C TInt GetModuleInfoById(TPositionModuleId aModuleId,
	                                TPositionModuleInfoBase& aModuleInfo) const;

	IMPORT_C TInt GetModuleStatus(TPositionModuleStatusBase& aPosModuleStatus,
	                              TPositionModuleId aModuleId) const;

	IMPORT_C void NotifyModuleStatusEvent(TPositionModuleStatusEventBase& aStatusEvent,
	                                      TRequestStatus& aStatus,
	                                      const TPositionModuleId aModuleId = KPositionNullModuleId) const;

private:
	void ConstructL();
	void Destruct();
	static TInt StartServer();

private:
	/** A pointer to a container that holds pointer descriptors, needed to point
	to the clients request data during asynchronous requests */
	CServerPositioningPtrHolder* iPtrHolder;
	
	/** Variable for future expansion. */
	TAny* iReserved;
	};


class RPositionerSubSessionBase : public RSubSessionBase
/**
Abstract base class for all positioning sub-sessions, including RPositioner.

@see RPositioner
@publishedAll
@released
 */
	{
public:
	IMPORT_C TInt CancelRequest(TInt aRequestId);

	IMPORT_C TInt CompleteRequest(TInt aRequestId);

protected:
	IMPORT_C RPositionerSubSessionBase();
	
	IMPORT_C virtual TAny* ExtendedInterface(TInt aFunctionNumber, TAny* aPtr1, TAny* aPtr2);

private:
	/** Unused variable for future expansion. */
	TAny* iReserved;
	};


class RPositioner : public RPositionerSubSessionBase
/**
This class is used to create a sub-session with the server for the
purpose of obtaining the current position. In addition to actually
obtaining position information, this class also provides mechanisms
for obtaining the last known position, the general status of the
positioning module, changing how often it wishes to receive position
updates, as well as identifying itself to the location framework. 

Before using the class, a primary connection must have already been
established with the server.

@see RPositionServer
@publishedAll
@released
 */
	{
public:
	IMPORT_C RPositioner();

	IMPORT_C TInt Open(RPositionServer& aPosServer);
	IMPORT_C TInt Open(RPositionServer& aPosServer,
	                   TPositionModuleId aModuleId);
	IMPORT_C TInt Open(RPositionServer& aPosServer,
	                   const TPositionCriteriaBase& aCriteria);
	IMPORT_C void Close();

	IMPORT_C TInt SetRequestor(CRequestor::TRequestorType aType,
	                           CRequestor::TRequestorFormat aFormat,
	                           const TDesC& aData);
	IMPORT_C TInt SetRequestor(const RRequestorStack& aRequestorStack);

	IMPORT_C TInt SetUpdateOptions(const TPositionUpdateOptionsBase& aPosOption);
	IMPORT_C TInt GetUpdateOptions(TPositionUpdateOptionsBase& aPosOption) const;

	IMPORT_C void GetLastKnownPosition(TPositionInfoBase& aPosInfo,
	                                   TRequestStatus& aStatus) const;
	IMPORT_C void NotifyPositionUpdate(TPositionInfoBase& aPosInfo,
	                                   TRequestStatus& aStatus) const;

protected:
	IMPORT_C virtual void ConstructL();
	IMPORT_C virtual void Destruct();
    IMPORT_C virtual TAny* ExtendedInterface(TInt aFunctionNumber, TAny* aPtr1, TAny* aPtr2);

private:
	void SetRequestorImplL(const RRequestorStack& aRequestorStack) const;
	
public:
	TInt OpenImpl(RPositionServer& aPosServer, TPositionModuleId aModuleId, const TPositionCriteriaBase& aCriteria, TBool aOpenedUsingModuleId);
private:
	/** A pointer to a container that holds pointer descriptors, needed to point
	to the clients request data during asynchronous requests */
	CPositioningPtrHolder* iPtrHolder;
	/** Unused variable for future expansion. */
	TAny* iReserved;
	};


#include <lbs.inl>

#endif // __LBS_H__
