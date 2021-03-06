// Copyright (c) 2008-2009 Nokia Corporation and/or its subsidiary(-ies).
// All rights reserved.
// This component and the accompanying materials are made available
// under the terms of "Eclipse Public License v1.0"
// which accompanies this distribution, and is available
// at the URL "http://www.eclipse.org/legal/epl-v10.html".
//
// Initial Contributors:
// Nokia Corporation - initial contribution.
//
// Contributors:
//
// Description:
//



/**
 @file
 @publishedAll
 @released
*/

#ifndef REMCONDATABASEUNAWARENOWPLAYINGTARGETOBSERVER_H
#define REMCONDATABASEUNAWARENOWPLAYINGTARGETOBSERVER_H

#include <remconmediabrowsetypes.h>

/**
It is intended for the client which is database aware.
Clients must implement this interface in order to instantiate objects of type 
CRemConDatabaseUnawareNowPlayingTarget. This interface passes incoming 
commands from RemCon to the client. 

@see CRemConDatabaseUnawareNowPlayingTarget
*/
NONSHARABLE_CLASS(MRemConDatabaseUnawareNowPlayingTargetObserver) 
	{
public:
	/**
	Requests to play an item.
	
	@param aItem The item requested to play. 
	     - If it does not refer to any valid item, the client must call 
	       CRemConNowPlayingTargetBase::PlayItemResponse() with the error 
	       KErrInvalidUid;	
	     - If it refers to a directory which can not be handled by this media 
	       player, the client must call 
	       CRemConNowPlayingTargetBase::PlayItemResponse() 
	       with the error KErrNowPlayingUidIsADirectory;
	     - If it is in use and can not be played, the client must call 
	       CRemConNowPlayingTargetBase::PlayItemResponse() 
	       with the error KErrNowPlayingMediaInUse;
	
	@param aScope The scope in which the item was requested to play. 
	
    @see CRemConNowPlayingTargetBase::PlayItemResponse().
	*/
	virtual void MrcdunptoPlayItem(const TRemConItemUid& aItem, 
			TRemConFolderScope aScope) = 0;

	/**
	Requests to add an item to now playing list.
	
	@param aItem The item requested to play.
	     - If it does not refer to any valid item, the client must call 
	       CRemConNowPlayingTargetBase::AddToNowPlayingResponse() 
	       with the error KErrInvalidUid;
	     - If it refers to a directory which can not be handled by this media 
	       player, the client must call 
	       CRemConNowPlayingTargetBase::AddToNowPlayingResponse() 
	       with the error KErrNowPlayingUidIsADirectory;
	     - If it is in use and can not be added to now playing list, the 
	       client must call 
	       CRemConNowPlayingTargetBase::AddToNowPlayingResponse() 
	       with the error KErrNowPlayingMediaInUse;
	
	@param aScope The scope in which the item was requested to play. 
	
    @see CRemConNowPlayingTargetBase::AddToNowPlayingResponse().
	*/
	virtual void MrcdunptoAddToNowPlaying(const TRemConItemUid& aItem, 
			TRemConFolderScope aScope) = 0;
	};

#endif //REMCONDATABASEUNAWARENOWPLAYINGTARGETOBSERVER_H
