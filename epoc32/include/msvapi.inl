// Copyright (c) 1998-2009 Nokia Corporation and/or its subsidiary(-ies).
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
// CMsvSession
// CMsvEntry
// 
//

inline TMsvId CMsvEntry::EntryId() const
/** Gets the ID of the context.

@return Current context's entry ID */
	{
	return iEntryPtr->Id();
	}

inline const TMsvEntry& CMsvEntry::Entry() const
/** Gets the index entry for the context.

@return Current context's index entry */
	{
	return *iEntryPtr;
	}

inline CMsvSession& CMsvEntry::Session()
/** Gets the Message Server session used by this object. This is the same session 
passed by the client in NewL(). 

@return The session used by the object */
	{
	return iMsvSession;
	}

inline const TMsvSelectionOrdering& CMsvEntry::SortType() const
/** Gets the current sort order of children of the entry. The sort order is initially 
set through NewL().

@return Current sort order */
	{
	return iOrdering;
	}

inline TInt CMsvEntry::Count() const
/** Gets the number of children of the context.

@return Count of the child entries for the current context */
	{
	return iSortedChildren->Count();
	}

inline TMsvId CMsvEntry::OwningService() const
/** Gets the ID of the service entry that owns the context. 

Local entries are considered as being members of the local service: 

@return ID of the service entry that the context is under. */
	{
	return iOwningService;
	}


//**********************************
// CMsvOperation
//**********************************

inline TMsvOp CMsvOperation::Id() const
/** Gets the operation ID. 

This ID is unique within a Message Server session. The ID allows the client 
to keep track of different operations. 

@return The ID of the operation */
	{
	return iId;
	}

inline TMsvId CMsvOperation::Service() const
/** Gets the ID of the service that is associated with this operation.

If the operation is not associated with a service, the function returns KMsvLocalServiceIndexEntryId.

@return ID of the service associated with the operation */
	{
	return iService;
	}
