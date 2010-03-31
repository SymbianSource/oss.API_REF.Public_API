/*
* Copyright (c) 2003 Nokia Corporation and/or its subsidiary(-ies). 
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

#ifndef __SMLDATASYNCDEFS_H__
#define __SMLDATASYNCDEFS_H__
//
#include <e32std.h>
//
class RReadStream;
class RWriteStream;
//

/**
TSmlDbItemUid is the unique ID of an item in a data store

@publishedPartner
@released
*/
typedef TInt TSmlDbItemUid;

/**
KNullDataItemId is a null value of a Data Item ID, no item may have this ID.

@publishedPartner
@released
*/
const TSmlDbItemUid KNullDataItemId = KMinTInt;

/**
TSmlSyncTaskKey uniquely identifies a sync relationship between a local and remote data store.
It should be used by Data Providers to resolve change information for a sync.

@publishedPartner
@released
*/
typedef TUint32 TSmlSyncTaskKey;


class MSmlSyncRelationship
	/**
	SyncML store interface exposed to Database Adaptor implementations.
	This interface may be used by a DBA to store change information for a Data Store, in the context
	of a sync relationship with a remote Data Store.
	It is vital for correct synchronisation behaviour that change information is stored separately for
	different remote Data Stores. This interface facilitates this by providing streams that are stored
	against specific Sync Tasks, and a unique key that identifies the sync relationship.

	@publishedPartner
	@released
	*/
	{
	public:
		/**
		Returns the unique identifier for the synchronisation relationship.

		@return				A unique identifier for the sync relationship.
		*/
		virtual TSmlSyncTaskKey SyncTaskKey() const = 0;
		/**
		Opens a specified stream for reading, and places an item on the cleanup stack to close it.

		@param				 aReadStream	On return, an open read stream
		@param				 aStreamUid		The UID of the stream to open for reading.
		*/
		virtual void OpenReadStreamLC(RReadStream& aReadStream, TUid aStreamUid) = 0;
		/**
		Opens the specified stream, or creates a new one if it does not exist, and places an item on the cleanup stack to close it.

		@param				aWriteStream	On return, an open write stream
		@param				aStreamUid		The UID of the stream to open or create
		*/
		virtual void OpenWriteStreamLC(RWriteStream& aWriteStream, TUid aStreamUid) = 0;
		/**
		Tests if the specified stream identified exists in the store.

		@param				aStreamUid The stream UID
		@return				Non-zero if the stream exists, otherwise EFalse.
		*/
		virtual TBool IsStreamPresentL(TUid aStreamUid) const = 0 ;
	};





///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
#endif
