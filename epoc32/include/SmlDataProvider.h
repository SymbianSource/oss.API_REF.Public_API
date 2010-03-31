/*
* Copyright (c) 2002-2004 Nokia Corporation and/or its subsidiary(-ies). 
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
* Description: For adding content to be synchronized.
*
*/


#ifndef __SMLDATAPROVIDER_H__
#define __SMLDATAPROVIDER_H__
//
#include <SyncMLDef.h>
#include <SyncMLDataFilter.h>
#include <syncml/SmlDataSyncDefs.h>
#include <SmlDataFormat.h>
//
/**
@publishedPartner

Plug-in Data Provider API.
*/

/** The parent uid to be used for the root */
const TSmlDbItemUid KDbItemUidRoot = -1;

/*
UIDs for use with CSmlDataProvider::SupportsOperation.
Other optional features are specified in the CSmlDataStoreFormat object
obtained from the Data Provider.
*/
/**
This UID identifies optional support for transaction operations.
For a DBA implementation to support this operation, it must be possible to add, change, and delete items within an atomic transaction.
*/
const TUid KUidSmlSupportTransaction = { 0x10009FC6 };
/**
This UID identifies optional support for suspend and resume operations.
For a DBA implementation to support this operation, it must be possible to to mark individual items as being 'in-sync', while other
items remain 'out-of-sync'.
*/
const TUid KUidSmlSupportSuspendResume = { 0x10009FC7 };
const TUid KUidSmlSupportBatch = { 0x10009FC8 };
const TUid KUidSmlSupportMultipleStores = { 0x10009FC9 };
const TUid KUidSmlSupportsUserSelectableMatchType = { 0x10009FCA };

/**
Set of Data Item LUIDs.
*/
class MSmlDataItemUidSet
	{
public:
	/**
	Returns the number of items in the set.
	*/
	IMPORT_C TInt ItemCount() const;
	/**
	Returns the index of the specified item UID in the set, or -1 if the item UID is not present.
	*/
	IMPORT_C TInt ItemIndex(TSmlDbItemUid aItemId) const;
	/**
	Retuns the item UID at the specified index in the set.
	*/
	IMPORT_C TSmlDbItemUid ItemAt(TInt aIndex) const;
public:
	IMPORT_C void ExternalizeL(RWriteStream& aStream) const;
protected:
	// hide the virtual methods from the public interface to enable future extension without breaking BC
	virtual TInt DoItemCount() const = 0;
	virtual TInt DoItemIndex(TSmlDbItemUid aItemId) const = 0;
	virtual TSmlDbItemUid DoItemAt(TInt aIndex) const = 0;
	virtual void DoExternalizeL(RWriteStream& aStream) const = 0;
	};


/**
Data Store interface.
*/
class CSmlDataStore : public CBase
	{
public:
	/**
	Opens the data store specified by aStoreName asynchronously.
	@param		aStoreName			The name of the data store to open.
	@param		aContext				Identifies the specific synchronisation relationship to use for the synchronisation.
	@param		aStatus					On completion of the open, contains the result code.
	*/
	IMPORT_C void OpenL(const TDesC& aStoreName, MSmlSyncRelationship& aContext, TRequestStatus& aStatus);
	/**
	Cancel the current asynchronous request, including open. Only one asynchronous request may be outstanding at any one time.
	*/
	IMPORT_C void CancelRequest();
public:
	/**
	Returns the name of the open data store.
	*/
	IMPORT_C const TDesC& StoreName() const;
public:
	/**
	BeginTransactionL() starts the transaction mode. During this mode calls to CreateItemL, ReplaceItemL,
	WriteItemL, CommitItemL, MoveItemL, DeleteItemL and SoftDeleteItemL will be part of this transaction.
	Their RequestStatus must be completed, even if the change is not yet really executed in the Data Store.
	If a RequestStatus is completed with an error code, the transaction has failed and a rollback must be
	done. In this case RevertTransaction will be called.
	*/
	IMPORT_C void BeginTransactionL();
	/**
	CommitTransactionL() will be called at the end of a successful transaction. At this point in time the
	operations within the transaction are applied to the Data Store in an atomic way. If all operations
	succeed, the RequestStatus must be completed with KErrNone. If an operation fails, a rollback must be
	done and the RequestStatus must be completed with an appropriate error code.
	*/
	IMPORT_C void CommitTransactionL(TRequestStatus& aStatus);
	/**
	RevertTransaction() will be called to abort an ongoing transaction. None of the operations already
	submitted may be applied to the Data Store. The RequestStatus must be completed with KErrNone as a revert
	cannot fail.
	*/
	IMPORT_C void RevertTransaction(TRequestStatus& aStatus);

public:
	/**
	BeginBatchL() starts the batch mode. During this mode calls to CreateItemL, ReplaceItemL,
	WriteItemL, CommitItemL, MoveItemL, DeleteItemL and SoftDeleteItemL will be part of this batch.
	Their RequestStatus must be completed with KErrNone, which only signals acceptance of the operation
	for batch processing.
	*/
	IMPORT_C void BeginBatchL();
	/**
	CommitBatchL() will be called at the end of the batch mode. This tells the Data Store to
	process the batched operations (in the order they were submitted), and to append the error code
	for each operation to aResultArray.
	The error codes in aResultArray are only valid if the RequestStatus is completed with KErrNone.
	If the RequestStatus is completed with an error code none of the operations in the batch mode
	were applied to the Data Store.
	*/
	IMPORT_C void CommitBatchL(RArray<TInt>& aResultArray, TRequestStatus& aStatus);
	/**
	CancelBatch() will be called to abort an ongoing batch mode. None of the operations already
	submitted may be applied to the Data Store.
	*/
	IMPORT_C void CancelBatch();

public:
	/**
	Sets the SyncML server Data Format - this may optionally be used by the Data Provider to filter out
	properties that the server does not support, and should be used to avoid deleting these properties
	in case the server sends a changed item to the Data Provider
	*/
	IMPORT_C void SetRemoteStoreFormatL(const CSmlDataStoreFormat& aServerDataStoreFormat);
	/**
	Sets the SyncML server maximum object size - this may optionally be used by the Data Provider to not send
	items to the server exceeding its maximum size. 0 means there is no limit.
	*/
	IMPORT_C void SetRemoteMaxObjectSize(TInt aServerMaxObjectSize);
	/**
	Gets the Data Store maximum object size which is reported to the SyncML server. 0 means there is no limit.
	*/
	IMPORT_C TInt MaxObjectSize() const;

	IMPORT_C void OpenItemL(TSmlDbItemUid aUid, TBool& aFieldChange, TInt& aSize, TSmlDbItemUid& aParent, TDes8& aMimeType, TDes8& aMimeVer, TRequestStatus& aStatus);
	IMPORT_C void CreateItemL(TSmlDbItemUid& aUid, TInt aSize, TSmlDbItemUid aParent, const TDesC8& aMimeType, const TDesC8& aMimeVer, TRequestStatus& aStatus);
	IMPORT_C void ReplaceItemL(TSmlDbItemUid aUid, TInt aSize, TSmlDbItemUid aParent, TBool aFieldChange, TRequestStatus& aStatus);
	IMPORT_C void ReadItemL(TDes8& aBuffer);
	IMPORT_C void WriteItemL(const TDesC8& aData);
	IMPORT_C void CommitItemL(TRequestStatus& aStatus);
	IMPORT_C void CloseItem();
	IMPORT_C void MoveItemL(TSmlDbItemUid aUid, TSmlDbItemUid aNewParent, TRequestStatus& aStatus);
	IMPORT_C void DeleteItemL(TSmlDbItemUid aUid, TRequestStatus& aStatus);
	IMPORT_C void SoftDeleteItemL(TSmlDbItemUid aUid, TRequestStatus& aStatus);
	IMPORT_C void DeleteAllItemsL(TRequestStatus& aStatus);
public:
	IMPORT_C TBool HasSyncHistory() const;
	IMPORT_C const MSmlDataItemUidSet& AddedItems() const;
	IMPORT_C const MSmlDataItemUidSet& DeletedItems() const;
	IMPORT_C const MSmlDataItemUidSet& SoftDeletedItems() const;
	IMPORT_C const MSmlDataItemUidSet& ModifiedItems() const;
	IMPORT_C const MSmlDataItemUidSet& MovedItems() const;
	IMPORT_C void ResetChangeInfoL(TRequestStatus& aStatus);
	IMPORT_C void CommitChangeInfoL(TRequestStatus& aStatus, const MSmlDataItemUidSet& aItems);
	IMPORT_C void CommitChangeInfoL(TRequestStatus& aStatus);

protected:
	// hide the virtual methods from the public interface to enable future extension without breaking BC
	virtual void DoOpenL(const TDesC& aStoreName, MSmlSyncRelationship& aContext, TRequestStatus& aStatus) = 0;
	virtual void DoCancelRequest() = 0;
	virtual const TDesC& DoStoreName() const = 0;
	virtual void DoBeginTransactionL() = 0;
	virtual void DoCommitTransactionL(TRequestStatus& aStatus) = 0;
	virtual void DoRevertTransaction(TRequestStatus& aStatus) = 0;
	virtual void DoBeginBatchL() = 0;
	virtual void DoCommitBatchL(RArray<TInt>& aResultArray, TRequestStatus& aStatus) = 0;
	virtual void DoCancelBatch() = 0;
	virtual void DoSetRemoteStoreFormatL(const CSmlDataStoreFormat& aServerDataStoreFormat) = 0;
	virtual void DoSetRemoteMaxObjectSize(TInt aServerMaxObjectSize) = 0;
	virtual TInt DoMaxObjectSize() const = 0;

	virtual void DoOpenItemL(TSmlDbItemUid aUid, TBool& aFieldChange, TInt& aSize, TSmlDbItemUid& aParent, TDes8& aMimeType, TDes8& aMimeVer, TRequestStatus& aStatus) = 0;
	virtual void DoCreateItemL(TSmlDbItemUid& aUid, TInt aSize, TSmlDbItemUid aParent, const TDesC8& aMimeType, const TDesC8& aMimeVer, TRequestStatus& aStatus) = 0;
	virtual void DoReplaceItemL(TSmlDbItemUid aUid, TInt aSize, TSmlDbItemUid aParent, TBool aFieldChange, TRequestStatus& aStatus) = 0;
	virtual void DoReadItemL(TDes8& aBuffer) = 0;
	virtual void DoWriteItemL(const TDesC8& aData) = 0;
	virtual void DoCommitItemL(TRequestStatus& aStatus) = 0;
	virtual void DoCloseItem() = 0;
	virtual void DoMoveItemL(TSmlDbItemUid aUid, TSmlDbItemUid aNewParent, TRequestStatus& aStatus) = 0;
	virtual void DoDeleteItemL(TSmlDbItemUid aUid, TRequestStatus& aStatus) = 0;
	virtual void DoSoftDeleteItemL(TSmlDbItemUid aUid, TRequestStatus& aStatus) = 0;
	virtual void DoDeleteAllItemsL(TRequestStatus& aStatus) = 0;

	virtual TBool DoHasSyncHistory() const = 0;
	virtual const MSmlDataItemUidSet& DoAddedItems() const = 0;
	virtual const MSmlDataItemUidSet& DoDeletedItems() const = 0;
	virtual const MSmlDataItemUidSet& DoSoftDeletedItems() const = 0;
	virtual const MSmlDataItemUidSet& DoModifiedItems() const = 0;
	virtual const MSmlDataItemUidSet& DoMovedItems() const = 0;
	virtual void DoResetChangeInfoL(TRequestStatus& aStatus) = 0;
	virtual void DoCommitChangeInfoL(TRequestStatus& aStatus, const MSmlDataItemUidSet& aItems) = 0;
	virtual void DoCommitChangeInfoL(TRequestStatus& aStatus) = 0;
	};


enum TSmlFrameworkEvent
	{
	ESmlFrameworkTaskDeleted
	};


/**
ECom Data Provider interface.
*/
class CSmlDataProvider : public CBase
	{
public:
	IMPORT_C static CSmlDataProvider* NewL(TSmlDataProviderId aId);
	IMPORT_C virtual ~CSmlDataProvider();
	IMPORT_C TSmlDataProviderId Identifier() const;
public:
	IMPORT_C void OnFrameworkEvent(TSmlFrameworkEvent, TInt aParam1, TInt aParam2);
	IMPORT_C TBool SupportsOperation(TUid aOpId) const;
	IMPORT_C const CSmlDataStoreFormat& StoreFormatL();
	IMPORT_C CDesCArray* ListStoresLC();
	IMPORT_C const TDesC& DefaultStoreL();
	IMPORT_C CSmlDataStore* NewStoreInstanceLC();
public:
	/**
	This method returns the set of filters that can be used to send to the SyncML server.
	*/
	IMPORT_C const RPointerArray<CSyncMLFilter>& SupportedServerFiltersL();
	
	/**
	This method checks what filters are supported by server.
	@param	aServerDataStoreFormat	The store format of server
	@param	aFilters				The array that includes filters
	@param	aChangeInfo				The change information about changes that data provider did
	*/
	IMPORT_C void CheckSupportedServerFiltersL(const CSmlDataStoreFormat& aServerDataStoreFormat, RPointerArray<CSyncMLFilter>& aFilters, TSyncMLFilterChangeInfo& aChangeInfo);
	
	/**
	This method updates dynamic filters up-to-date.
	@param	aFilters				The array that includes filters
	@param	aChangeInfo				The change information about changes that data provider did
	*/
	IMPORT_C void CheckServerFiltersL(RPointerArray<CSyncMLFilter>& aFilters, TSyncMLFilterChangeInfo& aChangeInfo);
	
	/**
	This method generates a record filter query to be sent to the SyncML server for the provided filters.
	@param	aFilters			The filters to be used for the query generation
	@param	aMatch				The filter match type to be used
	@param	aFilterMimeType		The mime type of the returned filter query
	@param	TSyncMLFilterType 	The filter type of the returned filter query
	@param  aStoreName			The name of used store
	@return						The record filter query to be sent to the SyncML server - empty if no record filter involved
								for this specific filter
	*/
	IMPORT_C HBufC* GenerateRecordFilterQueryLC(const RPointerArray<CSyncMLFilter>& aFilters, TSyncMLFilterMatchType aMatch, TDes& aFilterMimeType, TSyncMLFilterType& aFilterType, TDesC& aStoreName);
	
	/**
	This method generates a field filter query to be sent to the SyncML server for the provided filters.
	NOTE: this method isn't finalised - still thinking of a way to make it SyncML DS 1.2 independent
	@param	aFilters		The filters to be used for the query generation
	@param	aFilterMimeType		The mime type of the returned filter query
	@param	aProperties		The field filter query to be sent to the SyncML server - empty if no field filter involved
							for this specific filter
	@param  aStoreName		The name of used store
	*/
	IMPORT_C void GenerateFieldFilterQueryL(const RPointerArray<CSyncMLFilter>& aFilters, TDes& aFilterMimeType, RPointerArray<CSmlDataProperty>& aProperties, TDesC& aStoreName);

protected:
	// hide the virtual methods from the public interface to enable future extension without breaking BC
	virtual void DoOnFrameworkEvent(TSmlFrameworkEvent, TInt aParam1, TInt aParam2) = 0;
	virtual TBool DoSupportsOperation(TUid aOpId) const = 0;
	virtual const CSmlDataStoreFormat& DoStoreFormatL() = 0;
	virtual CDesCArray* DoListStoresLC() = 0;
	virtual const TDesC& DoDefaultStoreL() = 0;
	virtual CSmlDataStore* DoNewStoreInstanceLC() = 0;

	virtual const RPointerArray<CSyncMLFilter>& DoSupportedServerFiltersL() = 0;
	virtual void DoCheckSupportedServerFiltersL(const CSmlDataStoreFormat& aServerDataStoreFormat, RPointerArray<CSyncMLFilter>& aFilters, TSyncMLFilterChangeInfo& aChangeInfo) = 0;
	virtual void DoCheckServerFiltersL(RPointerArray<CSyncMLFilter>& aFilters, TSyncMLFilterChangeInfo& aChangeInfo) = 0;
	virtual HBufC* DoGenerateRecordFilterQueryLC(const RPointerArray<CSyncMLFilter>& aFilters, TSyncMLFilterMatchType aMatch, TDes& aFilterMimeType, TSyncMLFilterType& aFilterType, TDesC& aStoreName) = 0;
	virtual void DoGenerateFieldFilterQueryL(const RPointerArray<CSyncMLFilter>& aFilters, TDes& aFilterMimeType, RPointerArray<CSmlDataProperty>& aProperties, TDesC& aStoreName) = 0;

private:
	TUid iEComTag;
	TSmlDataProviderId iDPId;
	};


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
#endif
