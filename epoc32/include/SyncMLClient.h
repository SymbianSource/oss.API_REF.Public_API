/*
* Copyright (c) 2009 Nokia Corporation and/or its subsidiary(-ies). 
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
* Description: API for clients of the Data Synchronization and Device Management. Used to start, stop and observe synchronization/device management session, and modify data synchronization/device management settings.
*
*/
///////////////////////////////////////////////////////////////////////////////
// SyncMLClient.h
// v09
//
///////////////////////////////////////////////////////////////////////////////
#ifndef __SYNCMLCLIENT_H__
#define __SYNCMLCLIENT_H__
//
#include <e32std.h>
#include <badesca.h>
#include <SyncMLDef.h>
#include <SyncMLHistory.h>
//
class CClientSessionData;
class CSmlActiveCallback;
class CSyncMLTransportPropertiesArray;
class MSyncMLEventObserver;
class MSyncMLProgressObserver;
//


///////////////////////////////////////////////////////////////////////////////
// RSyncMLSession
///////////////////////////////////////////////////////////////////////////////
class RSyncMLSession : public RSessionBase
/**
	A client handle to a SyncML Sync Agent session.

	An instance of this class must be created in order to instantiate any of 
	the other client-side classes.

	Accessor methods are provided to enable clients to retrieve identifiers 
	of current and queued jobs, and of available profiles, transports, and 
	data providers. These IDs can be used to open handles on these objects 
	in order to manipulate them.

	Clients can request notifications of events related to jobs, profiles, transports,
	and the SyncML Agent, and can request progress for the currently running job.
	@publishedAll
	@released
*/
	{
public:
	IMPORT_C RSyncMLSession();
	IMPORT_C void OpenL();

	IMPORT_C void RequestEventL(MSyncMLEventObserver&);
	IMPORT_C void CancelEvent();

	IMPORT_C void RequestProgressL(MSyncMLProgressObserver&);
	IMPORT_C void CancelProgress();

	IMPORT_C void CurrentJobL(TSmlJobId&, TSmlUsageType&) const;
	IMPORT_C void ListQueuedJobsL(RArray<TSmlJobId>&, TSmlUsageType) const;

	IMPORT_C void ListProfilesL(RArray<TSmlProfileId>&, TSmlUsageType) const;
	IMPORT_C void ListTransportsL(RArray<TSmlTransportId>&) const;
	IMPORT_C void ListDataProvidersL(RArray<TSmlDataProviderId>&) const;

	IMPORT_C void DeleteProfileL(TSmlProfileId);

	IMPORT_C TSmlProtocolVersion ListProtocolVersionsL(TSmlUsageType, RArray<TSmlProtocolVersion>&) const;

	IMPORT_C void Close();
    /**@internalTechnology*/
	IMPORT_C void _DbgTestSettingL(TInt aSetting, TInt aParam);

private:
	void ReceiveArrayL(RArray<TInt>&, TInt, TInt, TInt) const;
private:
	mutable CClientSessionData* iData;
	friend class CSmlActiveCallback;
	CSmlActiveCallback* iEventCallback;
private:
	// Prohibited.
	RSyncMLSession& operator=(const RSyncMLSession&);
	RSyncMLSession(const RSyncMLSession&);
	};

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
// RSyncMLSettings
///////////////////////////////////////////////////////////////////////////////
class RSyncMLSettings : public RSubSessionBase
/**
	Handle to global settings for SyncML sync behaviour.

	@publishedAll
	@released
	@see TSmlGlobalSetting
*/
	{
public:
	IMPORT_C void OpenL(RSyncMLSession&);

	IMPORT_C TInt GetValueL(TSmlGlobalSetting) const;
	IMPORT_C void SetValueL(TSmlGlobalSetting, TInt aValue);

	IMPORT_C void Close();
	};

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// RSyncMLHistoryLog
///////////////////////////////////////////////////////////////////////////////
class RSyncMLHistoryLog : public RSubSessionBase
/**
	Snapshot of history for a profile.
	@publishedAll
	@released
*/
	{
public:
	IMPORT_C RSyncMLHistoryLog();
	IMPORT_C void OpenL(RSyncMLSession&, TSmlProfileId);
	IMPORT_C void SortEntries(CSyncMLHistoryEntry::TSortOrder);
	IMPORT_C void DeleteAllEntriesL();
	IMPORT_C TSmlProfileId Profile() const;
	IMPORT_C TInt Count() const;
	IMPORT_C const CSyncMLHistoryEntry& Entry(TInt aIndex) const;
	inline const CSyncMLHistoryEntry& operator[](TInt aIndex) const;
	IMPORT_C void Close();

private:
	mutable CClientSessionData* iData;
private:
	// Prohibited.
	RSyncMLHistoryLog& operator=(const RSyncMLHistoryLog&);
	RSyncMLHistoryLog(const RSyncMLHistoryLog&);
	};

///////////////////////////////////////////////////////////////////////////////
inline const CSyncMLHistoryEntry& RSyncMLHistoryLog::operator[](TInt aIndex) const
/**
	Returns the entry at the specified index.
@return				The entry at the specified index.
@param				aIndex The index of the entry to retrieve.
@publishedAll
@released
@pre				The handle is open.
*/
	{
	return Entry(aIndex);
	}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
// RSyncMLJobBase
///////////////////////////////////////////////////////////////////////////////
class RSyncMLJobBase : public RSubSessionBase
/**
	Base class for a handle to a job.

	Data synchronisation and device management job handles are implemented
	by derived classes.

	Not intended for user derivation. Public derived classes: 
	@see RSyncMLDataSyncJob 
	@see RSyncMLDevManJob

	@publishedAll
	@released
*/
	{
public:
	IMPORT_C TSmlJobId Identifier() const;
	IMPORT_C TSmlProfileId Profile() const;
	IMPORT_C void Close();
protected:
	RSyncMLJobBase();
	void GetJobL(TInt, TBool);
protected:
	/** @internalTechnology */
	mutable CClientSessionData* iData;
private:
	// Prohibited.
	RSyncMLJobBase& operator=(const RSyncMLJobBase&);
	RSyncMLJobBase(const RSyncMLJobBase&);
	};

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
// RSyncMLProfileBase
///////////////////////////////////////////////////////////////////////////////
class RSyncMLProfileBase : public RSubSessionBase
/**
	Base class for a handle to a SyncML profile. 
	
	A profile encapsulates a relationship with a single SyncML remote server for 
	either Device Management or Data Synchronisation.

	Not intended for user derivation. Derived classes: 
	@see RSyncMLDataSyncProfile 
	@see RSyncMLDevManProfile 

	@publishedAll
	@released
*/
	{
public:
	IMPORT_C void SetCreatorId(TSmlCreatorId);
	IMPORT_C void SetDisplayNameL(const TDesC&);
	IMPORT_C void SetUserNameL(const TDesC8&);
	IMPORT_C void SetPasswordL(const TDesC8&);
	IMPORT_C void SetServerIdL(const TDesC8&);
	IMPORT_C void SetServerPasswordL(const TDesC8&);
	IMPORT_C void SetSanUserInteractionL(TSmlServerAlertedAction);
	IMPORT_C void SetProtocolVersionL(TSmlProtocolVersion);

	IMPORT_C void DeleteConnectionL(TSmlTransportId);
	IMPORT_C void DeleteConnectionByConnectionIdL(TSmlConnectionId);

	IMPORT_C TSmlProfileId Identifier() const;
	IMPORT_C TSmlUsageType Type() const;
	IMPORT_C TSmlCreatorId CreatorId() const;
	IMPORT_C const TDesC& DisplayName() const;
	IMPORT_C const TDesC8& UserName() const;
	IMPORT_C const TDesC8& Password() const;
	IMPORT_C const TDesC8& ServerId() const;
	IMPORT_C const TDesC8& ServerPassword() const;
	IMPORT_C TSmlServerAlertedAction SanUserInteraction() const;
	IMPORT_C TSmlProtocolVersion ProtocolVersion() const;

	IMPORT_C void ListConnectionsL(RArray<TSmlTransportId>&) const;
	IMPORT_C void ListConnectionsByConnectionIdL(RArray<TSmlConnectionId>&) const;

	IMPORT_C TBool IsReadOnly() const;
	IMPORT_C TBool DeleteAllowed() const;
	/**
	 
   * Set Reset Profile lock Not supported for DS profiles
   * @since 3.23
   * @param  
   * aReadWriteValue  EFalse for reading ETrue for writing
   * aLockValue       EFalse for Unloacking ETrue for Locking the profile
   * @return  TInt 
   */
	
	
  IMPORT_C TInt ProfileLocked(TBool aReadWriteValue, TBool aLockValue) const;
	IMPORT_C void UpdateL();

	IMPORT_C void Close();

	const RSessionBase Session();
protected:
	RSyncMLProfileBase();
	void GetProfileL(TInt aSize);
	void ReceiveArrayL(RArray<TInt>&, TInt, TInt) const;
protected:
	/** @internalTechnology */
	mutable CClientSessionData* iData;
private:
	// Prohibited.
	RSyncMLProfileBase& operator=(const RSyncMLProfileBase&);
	RSyncMLProfileBase(const RSyncMLProfileBase&);
	};

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
// RSyncMLConnection
///////////////////////////////////////////////////////////////////////////////
class RSyncMLConnection : public RSubSessionBase
/**
	Handle to data defining a connection to a remote SyncML server in the context of a profile.

	@publishedAll
	@released
*/
	{
public:
	IMPORT_C RSyncMLConnection();
	IMPORT_C void CreateL(RSyncMLProfileBase&, TSmlTransportId);
	IMPORT_C void OpenL(RSyncMLProfileBase&, TSmlTransportId);
	IMPORT_C void OpenByConnectionIdL(RSyncMLProfileBase&, TSmlConnectionId);

	IMPORT_C TSmlTransportId Identifier() const;
	IMPORT_C TSmlProfileId Profile() const;
	IMPORT_C TSmlConnectionId ConnectionId() const;

	IMPORT_C TUint Priority() const;
	IMPORT_C TUint RetryCount() const;
	IMPORT_C const TDesC8& ServerURI() const;
	IMPORT_C const TDesC8& GetPropertyL(const TDesC8& aName) const;

	IMPORT_C void SetPriority(TUint);
	IMPORT_C void SetRetryCount(TUint);
	IMPORT_C void SetServerURIL(const TDesC8&);
	IMPORT_C void SetPropertyL(const TDesC8& aName, const TDesC8& aValue);

	IMPORT_C TBool IsReadOnly() const;
	IMPORT_C void UpdateL();
	IMPORT_C void Close();

private:
	mutable CClientSessionData* iData;
private:
	// Prohibited.
	RSyncMLConnection& operator=(const RSyncMLConnection&);
	RSyncMLConnection(const RSyncMLConnection&);
	};

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
// RSyncMLTransport
///////////////////////////////////////////////////////////////////////////////
class RSyncMLTransport : public RSubSessionBase
/**
	Handle to information about an available SyncML transport.

	@publishedAll
	@released
*/
	{
public:
	IMPORT_C RSyncMLTransport();
	IMPORT_C void OpenL(RSyncMLSession&, TSmlTransportId);

	IMPORT_C TSmlTransportId Identifier() const;
	IMPORT_C const TDesC& DisplayName() const;

	IMPORT_C TBool SupportsCapability(TSmlTransportCap) const;
	IMPORT_C const CSyncMLTransportPropertiesArray& Properties() const;

	IMPORT_C void StartListeningL() const; // Check ESmlCapCanListen supported first.
	IMPORT_C void StopListeningL() const;

	IMPORT_C void Close();

private:
	mutable CClientSessionData* iData;
private:
	// Prohibited.
	RSyncMLTransport& operator=(const RSyncMLTransport&);
	RSyncMLTransport(const RSyncMLTransport&);
	};

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// TSmlOpenMode
///////////////////////////////////////////////////////////////////////////////
enum TSmlOpenMode
/**
	Defines the access mode for opening a handle to a SyncML profile.
*/
	{
	/** 
	Open for read-only access to data. 
	
	@capability ReadDeviceData
	@Ref void RSyncMLDataSyncProfile::OpenL(RSyncMLSession& aSession, TSmlProfileId aId, TSmlOpenMode aMode)
	*/
	ESmlOpenRead,
	
	/** 
	Open for read and write access to data.
	
	@capability ReadDeviceData
	@capability WriteDeviceData
	@Ref void RSyncMLDataSyncProfile::OpenL(RSyncMLSession& aSession, TSmlProfileId aId, TSmlOpenMode aMode)
	*/
	ESmlOpenReadWrite
	};

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// Panic codes.
///////////////////////////////////////////////////////////////////////////////
enum TSyncMLClientPanic
	{
	ESmlClientPanicSessionNotOpen,
	ESmlClientPanicSessionAlreadyOpen,
	ESmlClientPanicEventAlreadyRequested
	};

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
#endif
