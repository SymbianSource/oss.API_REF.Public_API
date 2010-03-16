/*
* Copyright (c) 2005 Nokia Corporation and/or its subsidiary(-ies). 
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
* Description: SyncML APIs for data synchronization client.
*
*/


#ifndef __SYNCMLCLIENTDS_H__
#define __SYNCMLCLIENTDS_H__
//
#include <SyncMLClient.h>
#include <SyncMLDataFilter.h>
//
class CClientSessionData;
//

///////////////////////////////////////////////////////////////////////////////
// RSyncMLDataSyncJob
///////////////////////////////////////////////////////////////////////////////
class RSyncMLDataSyncJob : public RSyncMLJobBase
/**
	Handle to a data synchronisation job.
	
	A job synchronises the data in one or more data stores, as defined by the list 
	of tasks.
	@publishedAll
	@released
*/
	{
public:
	IMPORT_C RSyncMLDataSyncJob();
	IMPORT_C void CreateL(RSyncMLSession&, TSmlProfileId);
	IMPORT_C void CreateL(RSyncMLSession&, TSmlProfileId, TSmlConnectionId);
	IMPORT_C void CreateL(RSyncMLSession&, TSmlProfileId, TSmlSyncType);
	IMPORT_C void CreateL(RSyncMLSession&, TSmlProfileId, TSmlConnectionId, TSmlSyncType);
	IMPORT_C void CreateL(RSyncMLSession&, TSmlProfileId, const RArray<TSmlTaskId>&);
	IMPORT_C void CreateL(RSyncMLSession&, TSmlProfileId, TSmlConnectionId, const RArray<TSmlTaskId>&);
	IMPORT_C void CreateL(RSyncMLSession&, TSmlProfileId, TSmlSyncType, const RArray<TSmlTaskId>&);
	IMPORT_C void CreateL(RSyncMLSession&, TSmlProfileId, TSmlConnectionId, TSmlSyncType, const RArray<TSmlTaskId>&);
	IMPORT_C void OpenL(RSyncMLSession&, TSmlJobId);
	IMPORT_C void StopL();
	IMPORT_C const RArray<TSmlTaskId>& TaskIDs() const;
	};

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
// RSyncMLDataSyncProfile
///////////////////////////////////////////////////////////////////////////////
class RSyncMLDataSyncProfile : public RSyncMLProfileBase
/**
	Handle to a SyncML Data Synchronisation profile. 
	
	A profile encapsulates a relationship with a single SyncML remote server, 
	and contains a number of 'tasks' and 'connections'.
	@publishedAll
	@released
*/
	{
public:
	IMPORT_C RSyncMLDataSyncProfile();
	IMPORT_C void CreateL(RSyncMLSession&);
	IMPORT_C void OpenL(RSyncMLSession&, TSmlProfileId, TSmlOpenMode);

	IMPORT_C void SetCreatorId(TSmlCreatorId);
	IMPORT_C void SetDisplayNameL(const TDesC&);
	IMPORT_C void SetUserNameL(const TDesC8&);
	IMPORT_C void SetPasswordL(const TDesC8&);

	IMPORT_C void DeleteConnectionL(TSmlTransportId);

	IMPORT_C void ListTasksL(RArray<TSmlTaskId>&) const;
	IMPORT_C void DeleteTaskL(TSmlTaskId);

	IMPORT_C void UpdateL();
	};

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
// RSyncMLTask
///////////////////////////////////////////////////////////////////////////////
class RSyncMLTask : public RSubSessionBase
/**
	Represents a mapping between a local data store and a remote
	data store on a SyncML server in the context of a profile.
	@publishedAll
	@released
*/
	{
public:
	IMPORT_C RSyncMLTask();
	IMPORT_C void CreateL(RSyncMLDataSyncProfile&, TSmlDataProviderId,
		const TDesC& aServerDataSource, const TDesC& aClientDataSource);
	IMPORT_C void CreateL(RSyncMLDataSyncProfile&, TSmlDataProviderId,
		const TDesC& aServerDataSource, const TDesC& aClientDataSource, RPointerArray<CSyncMLFilter>& aArray);
	IMPORT_C void OpenL(RSyncMLDataSyncProfile&, TSmlTaskId);

	IMPORT_C TSmlTaskId Identifier() const;
	IMPORT_C TSmlProfileId Profile() const;
	IMPORT_C TSmlCreatorId CreatorId() const;
	IMPORT_C const TDesC& DisplayName() const;
	IMPORT_C const TDesC& ServerDataSource() const;
	IMPORT_C const TDesC& ClientDataSource() const;
	IMPORT_C TSmlDataProviderId DataProvider() const;
	IMPORT_C TSmlSyncType DefaultSyncType() const;
	
	//IMPORT_C TInt ServerFilterCount() const;
	//IMPORT_C const CSyncMLFilter& ServerFilterL(TInt aIndex) const; // Get the server filter at the specified index
	IMPORT_C TSyncMLFilterMatchType FilterMatchType() const;
	IMPORT_C TBool Enabled() const;

	IMPORT_C void SetCreatorId(TSmlCreatorId);
	IMPORT_C void SetDisplayNameL(const TDesC&);
	IMPORT_C void SetDefaultSyncTypeL(TSmlSyncType);
	//IMPORT_C void ReplaceServerFilterL(TInt aIndex, const CSyncMLFilter& aFilter); // Replaces the server filter at the specified index
	//IMPORT_C TInt AddServerFilterL(const CSyncMLFilter& aFilter); // Adds the server filter, returns the index at which it was added
	//IMPORT_C void DeleteServerFilterL(TInt aIndex); // Deletes the server filter at the specified index
	//IMPORT_C void DeleteAllServerFiltersL(); // Deletes all server filters
	//IMPORT_C void SetServerFilterEnabledL(TInt aIndex, TBool aEnable); // Changes the enabled flag for the server filter at the specified index
	IMPORT_C void SetFilterMatchTypeL(TSyncMLFilterMatchType) const;
	IMPORT_C void SetEnabledL(TBool);

	/* Return the set of filters that can be used to send to the SyncML server. This will only contain filters which are
	supported by the server, unless
	1) no previous synchronisation with the server was done, or
	2) the underlying Data Provider does not support this feature. In both cases the full list of filters supported by
	the Data Provider will be returned. */
	IMPORT_C RPointerArray<CSyncMLFilter>& SupportedServerFiltersL( TSyncMLFilterChangeInfo& aChangeInfo ) const;
	IMPORT_C TBool SupportsUserSelectableMatchType() const;

	IMPORT_C TBool IsReadOnly() const;
	IMPORT_C void UpdateL();
	IMPORT_C void Close();

private:
	mutable CClientSessionData* iData;
private:
	// Prohibited.
	RSyncMLTask& operator=(const RSyncMLTask&);
	RSyncMLTask(const RSyncMLTask&);
	};

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
// RSyncMLDataProvider
///////////////////////////////////////////////////////////////////////////////
class RSyncMLDataProvider : public RSubSessionBase
/**
	Handle to information about an available SyncML data provider.
	@publishedAll
	@released
*/
	{
public:
	IMPORT_C RSyncMLDataProvider();
	IMPORT_C void OpenL(RSyncMLSession&, TSmlDataProviderId);

	IMPORT_C TSmlDataProviderId Identifier() const;
	IMPORT_C TVersion Version() const;
	IMPORT_C const TDesC& DisplayName() const;
  
  IMPORT_C TInt MimeTypeCount() const;
	IMPORT_C const TDesC& MimeType(TInt aIndex) const;
	IMPORT_C const TDesC& MimeVersion(TInt aIndex) const;

	IMPORT_C const TDesC& DefaultDataStoreName() const;
	IMPORT_C TBool AllowsMultipleDataStores() const;
	IMPORT_C void GetDataStoreNamesL(CDesCArray&) const;

	/* Return the set of filters that can be used to send to the SyncML server */
	//IMPORT_C const RPointerArray<CSyncMLFilterDef>& SupportedServerFiltersL() const;

	IMPORT_C TSmlProtocolVersion RequiredProtocolVersionL() const;

	IMPORT_C void Close();

private:
	mutable CClientSessionData* iData;
private:
	// Prohibited.
	RSyncMLDataProvider& operator=(const RSyncMLDataProvider&);
	RSyncMLDataProvider(const RSyncMLDataProvider&);
	};

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
#endif
