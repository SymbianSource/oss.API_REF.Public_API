/*
* Copyright (c) 2009 Nokia Corporation and/or its subsidiary(-ies). 
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
* Description: History Log info
*
*/
///////////////////////////////////////////////////////////////////////////////
// SyncMLHistory.h
//
// v05
//
///////////////////////////////////////////////////////////////////////////////
#ifndef __SYNCMLHISTORY_H__
#define __SYNCMLHISTORY_H__
//
#include <e32base.h>
#include <s32strm.h>
#include <hash.h>
//
#include <syncmldef.h>
//
class CSmlAlertInfo;
class CSmlHistoryEntrySet;
//
/** Unique ID for Sync Job entry type. */
const TInt KSmlHistoryEntryJobTypeValue = 0x10009FA9;
const TUid KUidSmlHistoryEntryJob = { KSmlHistoryEntryJobTypeValue };
//
/** Unique ID for Push Msg entry type. */
const TInt KSmlHistoryEntryPushMsgTypeValue = 0x10009FAA;
const TUid KUidSmlHistoryEntryPushMsg = { KSmlHistoryEntryPushMsgTypeValue };
//
/** Panic codes for shared History Log classes. */
enum TSmlPanicHistoryShared
	{
	ESmlPanicHistoryShared_BadTaskId,
	ESmlPanicHistoryShared_BadSortOrdering
	};
//

///////////////////////////////////////////////////////////////////////////////
// CSyncMLHistoryEntry
///////////////////////////////////////////////////////////////////////////////
class CSyncMLHistoryEntry : public CBase
/**
	Base class for a history log entry.

	Not intended for user derivation. Derived classes: 
	@see CSyncMLHistoryJob 

	@publishedAll
	@released
  */
	{
public:
	/** An ordering of History Entries. */
	enum TSortOrder
		{
		/** Ordered by Time Stamp. */
		ESortByTime,
		/** Ordered by Entry Type. */
		ESortByType
		};
public:
	// Factory methods based upon entry type.
	IMPORT_C static CSyncMLHistoryEntry* NewL(TUid aEntryType);
	IMPORT_C static CSyncMLHistoryEntry* NewL(RReadStream&);
	IMPORT_C static CSyncMLHistoryEntry* NewL(const CSyncMLHistoryEntry&);
public:
	IMPORT_C virtual ~CSyncMLHistoryEntry();
	IMPORT_C virtual void ExternalizeL(RWriteStream&) const;
	IMPORT_C TUid EntryType() const;
	IMPORT_C TInt EntryId() const;
	virtual TSmlProfileId Profile() const = 0;
	virtual TTime TimeStamp() const = 0;
	virtual TInt ResultCode() const = 0;

protected:
	CSyncMLHistoryEntry(TUid);
	/** @internalTechnology */
	IMPORT_C static CSyncMLHistoryEntry* DoDynamicCast(TUid aEntryType, CSyncMLHistoryEntry*);
	/** @internalTechnology */
	IMPORT_C static const CSyncMLHistoryEntry* DoDynamicCast(TUid aEntryType, const CSyncMLHistoryEntry*);
	virtual void InternalizeL(RReadStream&);
private:
	friend class CEntrySet;
	IMPORT_C void SetEntryId(TInt);
	IMPORT_C virtual TAny* Reserved(TUid);
private:
	TUid iEntryType;
	TInt iEntryId;
	TInt iSpare;
	};

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// CSyncMLHistoryJob
///////////////////////////////////////////////////////////////////////////////
class CSyncMLHistoryJob : public CSyncMLHistoryEntry
/**
	This class holds the result of a session with a server.
	@publishedAll
	@released
*/
	{
public:
	class TTaskInfo
	/**
		This class identifies a sync task within the profile,
		and the result of the attempt to synchronise it.
	*/
		{
	public:
		IMPORT_C TTaskInfo();
		IMPORT_C void InternalizeL(RReadStream&);
		IMPORT_C void ExternalizeL(RWriteStream&) const;
	public:
		/** Identifies the profile sync task */
		TSmlTaskId iTaskId;
		/** Indicates the synchronisation result */
		TInt iError;
		/** Indicates the number of items added to the db */
		TInt iItemsAdded;
		/** Indicates the number of items modified in the db */
		TInt iItemsChanged;
		/** Indicates the number of items deleted from the db */
		TInt iItemsDeleted;
		/** Indicates the number of items moved in the db */
		TInt iItemsMoved;
		/** Indicates the number of items failed to modify the db */
		TInt iItemsFailed;
		/** Indicates the number of items added to the server's db */
		TInt iServerItemsAdded;
		/** Indicates the number of items modified in the server's db */
		TInt iServerItemsChanged;
		/** Indicates the number of items deleted from the server's db */
		TInt iServerItemsDeleted;
		/** Indicates the number of items moved in the server's db */
		TInt iServerItemsMoved;
		/** Indicates the number of items failed to modify the server's db */
		TInt iServerItemsFailed;
		/** Indicates the actual SyncType used for the synchronisation */
		TSmlSyncType iSyncType;
		};
public:
	inline static CSyncMLHistoryJob* DynamicCast(CSyncMLHistoryEntry*);
	inline static const CSyncMLHistoryJob* DynamicCast(const CSyncMLHistoryEntry*);
	IMPORT_C static CSyncMLHistoryJob* NewL();
	IMPORT_C static CSyncMLHistoryJob* NewL(TSmlProfileId, const RArray<TSmlTaskId>&);
	IMPORT_C virtual ~CSyncMLHistoryJob();
	IMPORT_C virtual void ExternalizeL(RWriteStream&) const;
public:
	IMPORT_C virtual TSmlProfileId Profile() const;
	IMPORT_C virtual TTime TimeStamp() const;
	IMPORT_C TTime LastSuccessSyncTime() const; 
	IMPORT_C virtual TInt ResultCode() const;
	IMPORT_C TTime FinishTime() const;
	IMPORT_C TInt TaskCount() const;
	IMPORT_C const TTaskInfo& TaskAt(TInt) const;
public:
	IMPORT_C TTaskInfo& TaskById(TSmlTaskId);
	IMPORT_C void SetResult(TTime aFinishTime, TInt aResultCode);
	IMPORT_C void SetLastSyncResult(TTime aSuccessSyncTime );
private:
	CSyncMLHistoryJob();
	void ConstructL(TSmlProfileId, const RArray<TSmlTaskId>&);
	virtual void InternalizeL(RReadStream&);
private:
	TTime iStartTime;
	TTime iFinishTime;
	TInt iResultCode;
	TSmlProfileId iProfileId;
	RArray<TTaskInfo> iTaskInfo;
	TTime iLastSuccessSync;
	};

///////////////////////////////////////////////////////////////////////////////
inline CSyncMLHistoryJob* CSyncMLHistoryJob::DynamicCast(CSyncMLHistoryEntry* aEntry)
	{
	return static_cast<CSyncMLHistoryJob*>(CSyncMLHistoryEntry::DoDynamicCast(KUidSmlHistoryEntryJob, aEntry));
	}

inline const CSyncMLHistoryJob* CSyncMLHistoryJob::DynamicCast(const CSyncMLHistoryEntry* aEntry)
	{
	return static_cast<const CSyncMLHistoryJob*>(CSyncMLHistoryEntry::DoDynamicCast(KUidSmlHistoryEntryJob, aEntry));
	}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// CSyncMLHistoryPushMsg
///////////////////////////////////////////////////////////////////////////////
class CSyncMLHistoryPushMsg : public CSyncMLHistoryEntry
/**
	This class holds the result of a parsing a push msg.
	This class contains a counter that stores how many times the same message has been received.
	@publishedAll
	@released
*/
	{
public:
	inline static CSyncMLHistoryPushMsg* DynamicCast(CSyncMLHistoryEntry*);
	inline static const CSyncMLHistoryPushMsg* DynamicCast(const CSyncMLHistoryEntry*);
	IMPORT_C static CSyncMLHistoryPushMsg* NewL();
	IMPORT_C virtual ~CSyncMLHistoryPushMsg();
	IMPORT_C virtual void ExternalizeL(RWriteStream&) const;
public:
	IMPORT_C virtual TSmlProfileId Profile() const;
	IMPORT_C virtual TTime TimeStamp() const;
	IMPORT_C virtual TInt ResultCode() const;
	IMPORT_C TInt ReceivedCount() const;
	IMPORT_C const TDesC8& MsgDigest() const;
	IMPORT_C TInt AlertCount() const;
	IMPORT_C const CSmlAlertInfo& Alert(TInt aIndex) const;
public:
	IMPORT_C void IncReceivedCount();
	IMPORT_C void SetMsgDigest(const TDesC8&);
	IMPORT_C void AddAlertsL(RPointerArray<CSmlAlertInfo>&); // Ownership of CSmlAlertInfo objects is transferred.
	IMPORT_C void ResetAlerts();
	IMPORT_C void SetResultCode(TInt aResultCode);

private:
	CSyncMLHistoryPushMsg();
	virtual void InternalizeL(RReadStream&);
private:
	TTime iTimeStamp;
	TInt iResultCode;
	TInt iRcvCount;
	TBuf8<MD5_HASH> iDigest;
	RPointerArray<CSmlAlertInfo> iAlerts;
	};

///////////////////////////////////////////////////////////////////////////////
inline CSyncMLHistoryPushMsg* CSyncMLHistoryPushMsg::DynamicCast(CSyncMLHistoryEntry* aEntry)
	{
	return static_cast<CSyncMLHistoryPushMsg*>(CSyncMLHistoryEntry::DoDynamicCast(KUidSmlHistoryEntryPushMsg, aEntry));
	}

inline const CSyncMLHistoryPushMsg* CSyncMLHistoryPushMsg::DynamicCast(const CSyncMLHistoryEntry* aEntry)
	{
	return static_cast<const CSyncMLHistoryPushMsg*>(CSyncMLHistoryEntry::DoDynamicCast(KUidSmlHistoryEntryPushMsg, aEntry));
	}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
#endif


