/*
* Copyright (c) 2004 Nokia Corporation and/or its subsidiary(-ies).
* All rights reserved.
* This component and the accompanying materials are made available
* under the terms of the License "Eclipse Public License v1.0"
* which accompanies this distribution, and is available
* at the URL "http://www.eclipse.org/legal/epl-v10.html".
*
* Initial Contributors:
* Nokia Corporation - initial contribution.
*
* Contributors:
*
* Description:  Declaration of the constants 
*
*/


#ifndef FAVOURITES_LIMITS_H
#define FAVOURITES_LIMITS_H

// CONSTANTS

//========== Favourites attribute limits ==========//

/// Max. length of an item name.
LOCAL_C const TInt KFavouritesMaxName = 50;
/// Max. length of an item URL.
LOCAL_C const TInt KFavouritesMaxUrl = 1024;
/// Max. length of an username.
LOCAL_C const TInt KFavouritesMaxUserName = 40;
/// Max. length of a password.
LOCAL_C const TInt KFavouritesMaxPassword = 40;

//========== Fixed Uid values ==========//

/// Null Uid; never assigned.
LOCAL_C const TInt KFavouritesNullUid = 0;
/// Uid of the root folder.
LOCAL_C const TInt KFavouritesRootUid = -1;
/// Uid of the Homepage.
LOCAL_C const TInt KFavouritesHomepageUid = -2;
/// Uid of the Last Visited Page.
LOCAL_C const TInt KFavouritesLastVisitedUid = -3;
/**
* Support for Start Page bookmark in the Browser. That bookmark is created
* in memory dynamically, and never exists in the database.
*/
LOCAL_C const TInt KFavouritesStartPageUid = -4;
/**
* Support for Adaptive Bookmarks Folder in the Browser. That folder is
* created in memory dynamically, and never exists in the database.
*/
LOCAL_C const TInt KFavouritesAdaptiveItemsFolderUid = -5;
/**
* Support for RSS Item in the Browser. That item is
* created in memory dynamically, and never exists in the database.
*/
LOCAL_C const TInt KFavouritesRSSItemUid = -6;
/**
* Support for Saved Deck Item in the Browser. That item is
* created in memory dynamically, and never exists in the database.
*/
LOCAL_C const TInt KFavouritesSavedDeckItemUid = -7;

//========== Unique name support ==========//

/**
* Maximum length of the postfix that is generated for unique names.
* (Unique names are created by appending a (32 bit) number in parenthesis. The
* longest postfix therefore reads "(4294967296)" (12 characters).
*/
LOCAL_C const TInt KFavouritesMaxPostfix = 13;

//========== Context Id values ==========//

/// Null context id; keep this unused.
LOCAL_C const TInt32 KFavouritesNullContextId = 0x00000000;
/// Context id for applications.
LOCAL_C const TInt32 KFavouritesApplicationContextId = 0x00000001;
/// Context id for images.
LOCAL_C const TInt32 KFavouritesImageContextId = 0x00000002;
/// Context id for audio.
LOCAL_C const TInt32 KFavouritesAudioContextId = 0x00000003;
/// Context id for video.
LOCAL_C const TInt32 KFavouritesVideoContextId = 0x00000004;
/// Context id for game data.
LOCAL_C const TInt32 KFavouritesGameDataContextId = 0x00000005;
/// Context id for ringing tones.
LOCAL_C const TInt32 KFavouritesRingingToneContextId = 0x00000006;
/// Context id for skins.
LOCAL_C const TInt32 KFavouritesSkinContextId = 0x00000007;
/// Context id for Music Shop music.
LOCAL_C const TInt32 KFavouritesMusicContextId = 0x00000008;

// Context id for Service.
LOCAL_C const TInt32 KFavouritesServiceContextId = 0x00000009;

/// Special context IDs for launching into these.
LOCAL_C const TInt32 KFavouritesFeedsContextId = 0x00000000A;


//========== Database names ==========//

/// Browser bookmarks database name.
_LIT( KBrowserBookmarks, "BrowserBookmarks" );
/// Browser saved pages database name.
_LIT( KBrowserSavedPages, "BrowserSavedPages" );

#endif
            
// End of File
