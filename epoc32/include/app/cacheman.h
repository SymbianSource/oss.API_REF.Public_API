// Copyright (c) 1999-2009 Nokia Corporation and/or its subsidiary(-ies).
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

#if !defined (__CACHEMAN_H__)
#define __CACHEMAN_H__

#include <mentact.h>
#include <msvstd.h>
#include <msvapi.h>

_LIT(KMiutWildCard, "*.*");

class CImFinder : public CMsgActive
/**
@internalComponent
@released
*/
	{
public:
	IMPORT_C void FindFirstL(TMsvId aRootEntry, TRequestStatus &aStatus);
	IMPORT_C ~CImFinder();
	IMPORT_C virtual void FindNextL(TRequestStatus &aStatus);
	void FindFirstL(const CMsvEntrySelection& aInitialSelection, TRequestStatus &aStatus);

	class CImEntryStack : public CBase
		{
	public:
		static CImEntryStack* NewL();
		~CImEntryStack();
		inline void PushL(TMsvId aId);
		inline TMsvId PopL();
		inline TBool Empty() const;
		inline void Reset();

	private:
		void ConstructL();

		CMsvEntrySelection* iFolders;
		};

protected:
	void ConstructL();
	CImFinder(CMsvEntry& aEntry);

private:
	void DoRunL();

	virtual void AddChildEntriesL() = 0;
	virtual TBool IsRequiredEntryType(TUid aEntryType) const = 0;

protected:
	CImEntryStack* iEntryStack;
	CMsvEntry& iCurrentEntry;

private:
	enum TImmfState
		{
		EImmfEntryFound,
		EImmfFindingEntry,
		EImmfNothingFound
		};

	TImmfState iState;
	};


class CImMessageFinder : public CImFinder
/**
@internalComponent
@released
*/
	{
public:
	IMPORT_C static CImMessageFinder* NewL(CMsvEntry& aEntry);
	IMPORT_C static CImMessageFinder* NewLC(CMsvEntry& aEntry);
	
protected:
	virtual void AddChildEntriesL();
	virtual TBool IsRequiredEntryType(TUid aEntryType) const;

	CImMessageFinder(CMsvEntry& aEntry);
	};


class CImEntryFinder : public CImFinder
/**
@internalComponent
@released
*/
	{
public:
	IMPORT_C static CImEntryFinder* NewL(CMsvEntry& aEntry);
	IMPORT_C static CImEntryFinder* NewLC(CMsvEntry& aEntry);
	
protected:
	virtual void AddChildEntriesL();
	virtual TBool IsRequiredEntryType(TUid aEntryType) const;

	CImEntryFinder(CMsvEntry& aEntry);
	};


class CImMessageCounter : public CImFinder
/**
@internalComponent
@released
*/
	{
public:
	IMPORT_C static CImMessageCounter* NewL(CMsvEntry& aEntry);
	IMPORT_C static CImMessageCounter* NewLC(CMsvEntry& aEntry);
	IMPORT_C TInt Count();
	
protected:
	virtual void AddChildEntriesL();
	virtual TBool IsRequiredEntryType(TUid aEntryType) const;

	CImMessageCounter(CMsvEntry& aEntry);

private:
	TInt iCount;
	};


class CImPruneMessage : public CMsgActive
/** Deletes the body text and attachment data from an individually specified message. 

Example uses of this class are:

1. to cleanup after a populating operation has failed

2. to remove body text and attachment data from remote messages, while preserving 
the message structure 
@publishedPartner 
@released
*/
	{
public:
	IMPORT_C static CImPruneMessage* NewL(CMsvEntry& aEntry, RFs& aFs);
	IMPORT_C static CImPruneMessage* NewLC(CMsvEntry& aEntry, RFs& aFs);

	IMPORT_C void StartL(TMsvId aMessageEntry, TRequestStatus &aStatus);
	~CImPruneMessage();
	
private:
	CImPruneMessage(CMsvEntry& aEntry, RFs& aFs);
	void ConstructL();
	void DoRunL();
	void DoComplete(TInt& );
	void DoCancel();
	void PruneEntryL();
	void ResetStoreL();

private:
	enum TImPruningState
		{
		EImPruneUpdatingEntry,
		EImPruneUpdatingFirstEntry,
		EImPruneFindingEntry,
		EImPruneFindFirstEntry,
		EImPruneFindNextEntry
		};

	TImPruningState iState;

	CMsvEntry& iCurrentEntry;
	RFs& iFs;
	CImEntryFinder* iEntryFinder;
	CFileMan* iFileManager;
	TMsvId iRootEntryId;
	CMsvOperation* iChangeOperation;
	CMsvStore* iStore;
	};

struct TImCacheManagerProgress
/** Holds progress of a cache management cleanup operation.

@see CImCacheManager::ProgressL() 
@publishedAll
@released
*/
	{
public:
	/** Total number of messages to process.
	
	Note that, immediately after a CImCacheManager object is started, the progress 
	operation may return 1 for iTotalMessages and 0 for iMessagesProcessed, regardless 
	of the total number of messages. This is because the counter for the iTotalMessages 
	operates asynchronously and may not have counted all of the messages at that 
	time. */
	TInt iTotalMessages;
	/** Number of messages processed so far. */
	TInt iMessagesProcessed;
	};

class CImCacheManager : public CMsvOperation
/** Provides management of the local cache of messages in remote mailboxes.

A mailbox that is being used in disconnected mode allows the user access to 
message data by opening the message directly from the remote mailbox. If the 
required message has been downloaded previously, then it will not necessarily 
need to be downloaded again. This functionality is achieved by preserving 
the message data locally, under the remote service entry. The preserved message 
data acts as a cache to allow the user access to the message without the need 
for it to be downloaded every time. 

The cache management functionality is required to reduce the amount of memory 
that is consumed by the message cache. CImCacheManager provides a mechanism 
for asynchronously traversing a message tree and for removing text and attachment 
data from messages. Deleting more message data will free up more memory but 
there is a higher chance that a user will need to download a message for a 
second time. 

CImCacheManager is an abstract base class, which can be specialised to implement 
a filter (Filter()) that decides if data for a message shoulded be deleted: 
for example, deletion could be restricted to 'all read messages over a week 
old,' or, 'all read messages, over 20K in size which are also over a day old.' 
@publishedAll
@released
*/
	{
public:
	IMPORT_C void StartL(TMsvId aRootEntry, TRequestStatus &aStatus);
	IMPORT_C void StartL(const CMsvEntrySelection& aSelection, TRequestStatus &aStatus);
	IMPORT_C ~CImCacheManager();
	IMPORT_C const TDesC8& ProgressL();
	IMPORT_C void DoCancel();

protected:
	IMPORT_C void ConstructL();
	IMPORT_C CImCacheManager(CMsvSession& aSession, TRequestStatus& aObserverRequestStatus);

	IMPORT_C void RunL();

private:
	// Override this function to filter the currently selected message (iCurrentEntry).
	// Return TRUE if the current entry is to be pruned.
	/** Tests if cache cleanup should be performed on a message entry.
	
	After StartL() has been called, this is called once for each message entry. 
	It should return true if the body text and attachment data belonging to the 
	current message, as held in iCurrentEntry, should be deleted, or false if 
	the message should be left unchanged.
	
	This function must be implemented in any classes derived from CImCacheManager.
	
	@return True to clean the entry, false to leave it unchanged */
	virtual TBool Filter() const = 0;

	void DoRunL();

	// Remove the store from the currently selected entry
	inline void PruneMessageL();
	
protected:
	/** Message entry currently being processed. */
	CMsvEntry* iCurrentEntry;

private:
	CMsvSession& iSession;
	CImMessageFinder* iMessageFinder;
	CImMessageCounter* iMessageCounter;
	CMsvOperation* iDeleteOperation;

	TImCacheManagerProgress iProgress;
	TRequestStatus* iReport;

	enum TImcmState
		{
		EImcmLookingForMessage,
		EImcmPruningMessages,
		EImcmCountingMessages,
		EImcmSkippingPrune
		};

	TMsvId iRootEntry;
	TImcmState iState;
	TPckgBuf<TImCacheManagerProgress> iProgressBuf;

	CMsvEntrySelection* iMessagesToPrune;
	};

#endif
