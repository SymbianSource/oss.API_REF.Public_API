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

#ifndef __CENTRALREPOSITORY_H__
#define __CENTRALREPOSITORY_H__

#include <e32base.h>


namespace NCentralRepositoryConstants
/** Namespace encapsulating the CentralRepository constants.
@publishedAll
@released
*/
{
	
/** The maximum number of unicode characters that can be stored in a setting
@publishedAll
@released
*/
const TInt KMaxUnicodeStringLength = 1024;

/** The maximum number of bytes that can be stored in a setting
@publishedAll
@released
*/
const TInt KMaxBinaryLength = KMaxUnicodeStringLength*2;

/** Error key returned by CommitTransaction in case of an error that cannot be
attributed to any single or partial key. Also notify value for spurious 
notifications (eg when a notification is cancelled or several values change at once )
@internalAll
@released
*/
const TUint32 KUnspecifiedKey = 0xffffffffUL;

/** Initial buffer size for Find~ API. Initial buffer is used to cut on the number
of IPC calls required for each Find~ API call. If the number of settings found is 
less than or equal to KCentRepFindBufSize then all the settings can be retrieved with
a single IPC.
@internalAll
*/
const TInt KCentRepFindBufSize = 16;

/** Use KUnspecifiedKey instead of this value.
@publishedAll
@deprecated
*/
const TUint32 KInvalidNotificationId = KUnspecifiedKey;

/** The 8 most significant bits of a setting's meta-data are reserved for internal use.
Clients should not make use of the reserved bits (unless it is specifically stated
otherwise in Symbian developer documentation).  Clients should not rely on the value
of the reserved bits.  Reserved bits are not guaranteed to be 0 or 1 and are not
guaranteed to stay constant from one GetMeta call to the next.
@publishedPartner
@released
@see CRepository::GetMeta
@see KMetaUnreserved
*/
const TUint32 KMetaSymbianReserved = 0xFF000000; 

/** The 24 least significant bits of a setting's meta-data are available for use. Clients
should make use of KMetaUnreserved to mask out the reserved bits following a call
to GetMeta.  Clients should not rely on the value of the reserved bits.  Reserved bits
are not guaranteed to be 0 or 1 and are not guaranteed to stay constant from one
GetMeta call to the next.
@publishedPartner
@released
@see CRepository::GetMeta
@see KMetaSymbianReserved 
*/
const TUint32 KMetaUnreserved = 0x00FFFFFF; 

} // namespace NCentralRepositoryConstants

/** Provides access to a repository.

There are potentially 2^32 repositories, each identified by a UID. Within each
repository up to 2^32 settings can be stored. Settings within a repository are
identified by a 32-bit key and may be of the types integer, real or descriptor.
@publishedAll
@released
*/
class CRepository : public CBase
	{
public:

	/**	Transaction mode chosen with StartTransaction.
	@publishedPartner
	@released */
	enum TTransactionMode
		{
		/** Standard optimistic non-serialised transaction. Can be started at any time
		Commit fails with KErrLocked if another client interrupts it by first committing
		changes: transaction should be repeated until KErrLocked is not returned. */
		EConcurrentReadWriteTransaction = 2,
		/** Pessimistic locking transaction intended for reading consistent values.
		Can only be started if EReadWriteTransaction is not in progress.
		Automatically promoted to EReadWriteTransaction on first write operation
		if no other read transaction is in progress (or fails if not attainable).
		Use ONLY if all clients can agree not to use EConcurrentReadWriteTransaction,
		and only make changes in an EReadWriteTransaction. */
		EReadTransaction = 1,
		/** Pessimistic locking transaction intended for writing values. Can only be
		started if no EReadTransaction or EReadWriteTransactions are in progress.
		Use ONLY if all clients can agree not to use EConcurrentReadWriteTransaction,
		and only make changes in an EReadWriteTransaction. */
		EReadWriteTransaction = 3
		};

	/** Buffer type for aKeyInfo parameter to asynchronous CommitTransaction.
	@see CRepository::CommitTransaction(TDes8& aKeyInfo, TRequestStatus& aStatus)
	@publishedPartner
	@released
	*/
	typedef TPckgBuf<TUint32> TTransactionKeyInfoBuf;

	IMPORT_C static CRepository* NewL(TUid aRepositoryUid);
	IMPORT_C static CRepository* NewLC(TUid aRepositoryUid);

	IMPORT_C virtual ~CRepository();
	IMPORT_C TInt Create(TUint32 aKey, TInt aValue);
	IMPORT_C TInt Create(TUint32 aKey, const TReal& aValue);
	IMPORT_C TInt Create(TUint32 aKey, const TDesC8& aValue);
	IMPORT_C TInt Create(TUint32 aKey, const TDesC16& aValue);

	IMPORT_C TInt Delete(TUint32 aKey);
	IMPORT_C TInt Delete(TUint32 aPartialKey, TUint32 aMask, TUint32 &aErrorKey) ;

	IMPORT_C TInt Get(TUint32 aKey, TInt& aValue);
	IMPORT_C TInt Set(TUint32 aKey, TInt aValue);
	
	IMPORT_C TInt Get(TUint32 aKey, TReal& aValue);
	IMPORT_C TInt Set(TUint32 aKey, const TReal& aValue);

	IMPORT_C TInt Get(TUint32 aKey, TDes8& aValue);
	IMPORT_C TInt Get(TUint32 aId, TDes8& aValue, TInt& aActualLength);
	IMPORT_C TInt Set(TUint32 aKey, const TDesC8& aValue);

	IMPORT_C TInt Get(TUint32 aKey, TDes16& aValue);
	IMPORT_C TInt Get(TUint32 aId, TDes16& aValue, TInt& aActualLength);
	IMPORT_C TInt Set(TUint32 aKey, const TDesC16& aValue);

	IMPORT_C TInt GetMeta(TUint32 aKey, TUint32& aMeta);

	IMPORT_C TInt Move (TUint32 aSourcePartialKey, TUint32 aTargetPartialKey, 
	                    TUint32 aMask, TUint32 &aErrorKey) ;

	IMPORT_C TInt FindL(TUint32 aPartialKey, TUint32 aMask,
		RArray<TUint32>& aFoundKeys);

	IMPORT_C TInt FindEqL(TUint32 aPartialKey, TUint32 aMask,
		TInt aValue, RArray<TUint32>& aFoundKeys);
	IMPORT_C TInt FindEqL(TUint32 aPartialKey, TUint32 aMask,
		const TReal& aValue, RArray<TUint32>& aFoundKeys);
	IMPORT_C TInt FindEqL(TUint32 aPartialKey, TUint32 aMask,
		const TDesC8& aValue, RArray<TUint32>& aFoundKeys);
	IMPORT_C TInt FindEqL(TUint32 aPartialKey, TUint32 aMask,
		const TDesC16& aValue, RArray<TUint32>& aFoundKeys);

	IMPORT_C TInt FindNeqL(TUint32 aPartialKey, TUint32 aMask,
		TInt aValue, RArray<TUint32>& aFoundKeys);
	IMPORT_C TInt FindNeqL(TUint32 aPartialKey, TUint32 aMask,
		const TReal& aValue, RArray<TUint32>& aFoundKeys);
	IMPORT_C TInt FindNeqL(TUint32 aPartialKey, TUint32 aMask,
		const TDesC8& aValue, RArray<TUint32>& aFoundKeys);
	IMPORT_C TInt FindNeqL(TUint32 aPartialKey, TUint32 aMask,
		const TDesC16& aValue, RArray<TUint32>& aFoundKeys);

	IMPORT_C TInt NotifyRequest(TUint32 aKey, TRequestStatus& aStatus);
	IMPORT_C TInt NotifyRequest(TUint32 aPartialKey, TUint32 aMask,
		TRequestStatus& aStatus);

	IMPORT_C TInt NotifyCancel(TUint32 aKey);
	IMPORT_C TInt NotifyCancel(TUint32 aPartialKey, TUint32 aMask);
	IMPORT_C TInt NotifyCancelAll();

	IMPORT_C TInt Reset();
	IMPORT_C TInt Reset(TUint32 aKey);

	IMPORT_C TInt StartTransaction(TTransactionMode aMode);
	IMPORT_C void StartTransaction(TTransactionMode aMode, TRequestStatus& aStatus);
	IMPORT_C TInt CommitTransaction(TUint32& aKeyInfo);
	IMPORT_C void CommitTransaction(TDes8& aKeyInfo, TRequestStatus& aStatus);
	IMPORT_C void CancelTransaction();
	IMPORT_C void CleanupCancelTransactionPushL();
	IMPORT_C void FailTransaction();
	IMPORT_C void CleanupFailTransactionPushL();

	/** Same as CancelTransaction.
	@publishedPartner
	@released
	@see CancelTransaction */
	inline void RollbackTransaction() 
		{
		CancelTransaction();
		}

	/** Same as CleanupCancelTransactionPushL.
	@publishedPartner
	@released
	@see CleanupCancelTransactionPushL */
	inline void CleanupRollbackTransactionPushL()
		{
		CleanupCancelTransactionPushL();
		}

	IMPORT_C TInt TransactionState();

	/** This API is for internal use only and for testing purposes.
	@internalAll
	*/
	IMPORT_C static TInt SetGetParameters(const TIpcArgs& aArgs);
	};

#endif // __CENTRALREPOSITORY_H__
