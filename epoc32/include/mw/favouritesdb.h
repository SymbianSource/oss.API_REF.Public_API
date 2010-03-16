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
* Description:  Declaration of RFavouritesDb.
*
*/


#ifndef FAVOURITES_DB_H
#define FAVOURITES_DB_H

//  INCLUDES

#include <e32base.h>
#include <d32dbms.h>
#include <FavouritesItem.h>
#include <FavouritesLimits.h>
#include <FavouritesSession.h>
#include <FavouritesHandle.h>

// FORWARD DECLARATIONS

class CFavouritesItemList;
class MFavouritesItemData;
class MRfsApMapper;

// CLASS DECLARATION

/**
* RFavouritesDb is the representation of the favourites database.
* This class encapsulates a session with bookmark database server.
* It provides a way to access the database, do administration
* (recovery, compaction) and explicit transaction support. 
*/
class RFavouritesDb: public RFavouritesHandle
    {

    public:     // New methods

        /**
        * Open the database. Created if does not exist.
        * @since 0.9 
        * @param aSess Session to be used.
        * @param aName Database name.
        * @return Error code.
        */
        IMPORT_C TInt Open( RFavouritesSession& aSess, const TDesC& aName );

    public:     // Adminstration
        
        /**
        * Get version information.
        * @since 0.9 
        * @return Version object of this CFavouritesDb.
        */
        IMPORT_C TVersion Version() const;

        /**
        * Check if the database to be recovered is fully functional.
        * @since 0.9 
        * @param aIsDamaged Result is returned here.
        * @return Error code.
        */
        IMPORT_C TInt IsDamaged( TBool& aIsDamaged );

        /**
        * Perform database synchronous recovery. This function requires exclusive access 
        * to the database.
        * @since 0.9 
        * @return Error code.
        */
        IMPORT_C TInt Recover();

        /**
        * Perform databas synchronous compaction. This function requires exclusive access 
        * to the database.
        * @since 0.9 
        * @return Error code.
        */
        IMPORT_C TInt Compact();

        /**
        * Get available database size.
        * @since 0.9 
        * @param aSize Database size returned here.
        * @return Error code.
        */
        IMPORT_C TInt Size( RDbDatabase::TSize& aSize ) const;

        /**
        * Update database statistics.
        * @since 0.9 
        * @return Error code.
        */
        IMPORT_C TInt UpdateStats();

    public:     // Transaction support

        /**
        * Explicitly begin a transaction.
        * @since 0.9 
        * @param aWrite Access mode.
        * @return Error code.
        */
        IMPORT_C TInt Begin( TBool aWrite = EFalse );

        /**
        * Commit the transaction.
        * @since 0.9 
        * @return Error code.
        */
        IMPORT_C TInt Commit();

        /**
        * Roll back the transaction.
        * @since 0.9 
        * @return void
        */
        IMPORT_C void Rollback();

        /**
        * Push a rollback on the cleanup stack. Call this after Begin() call,
        * to make the transaction leave-safe.
        * @since 0.9 
        * @return void
        */
        IMPORT_C void CleanupRollbackPushL();

    public:     // Data access / update / delete

        /**
        * Get the item with this Uid.
        * @since 0.9 
        * @param aUid Uid or item to get.
        * @param aItem placeholder for the returned item data.
        * @return Error code.
        */
        IMPORT_C TInt Get( TInt aUid, CFavouritesItem& aItem );

        /**
        * Get all items matching the supplied criteria.
        * @since 0.9 
        * @param aItemList placeholder for the returned item data. Existing
        * items remain (new ones appended).
        * @param aParentFolderFilter Uid value to filter. KFavouritesNullUid
        * clears (all accepted); this is the default.
        * @param aTypeFilter EItem or EFolder to use filter; ENone to clear
        * filter (all accepted); this is the default.
        * @param aNameFilter wildcard pattern to be used for name matching.
        * NULL clears (all accepted); this is the default.
        * @param aContextIdFilter ContextId value to filter.
        * KFavouritesNullContextId clears (all accepted); this is the default.
        * @return Error code.
        */
        IMPORT_C TInt GetAll
            (
            CFavouritesItemList& aItemList,
            TInt aParentFolderFilter = KFavouritesNullUid,
            CFavouritesItem::TType aTypeFilter = CFavouritesItem::ENone,
            const TDesC* aNameFilter = NULL,
            TInt32 aContextIdFilter = KFavouritesNullContextId
            );

        /**
        * Get uids of all items matching the supplied criteria.
        * @since 0.9 
        * @param aUids placeholder for the returned item data. Existing
        * items remain (new ones appended).
        * @param aParentFolderFilter Uid value to filter. KFavouritesNullUid
        * clears (all accepted); this is the default.
        * @param aTypeFilter EItem or EFolder to use filter; ENone to clear
        * filter (all accepted); this is the default.
        * @param aNameFilter wildcard pattern to be used for name matching.
        * NULL clears (all accepted); this is the default.
        * @param aContextIdFilter ContextId value to filter.
        * KFavouritesNullContextId clears (all accepted); this is the default.
        * @return Error code.
        */
        IMPORT_C TInt GetUids
            (
            CArrayFix<TInt>& aUids,
            TInt aParentFolderFilter = KFavouritesNullUid,
            CFavouritesItem::TType aTypeFilter = CFavouritesItem::ENone,
            const TDesC* aNameFilter = NULL,
            TInt32 aContextIdFilter = KFavouritesNullContextId
            );

        /**
        * Get preferred Uid for a folder.
        * @since 0.9 
        * @param aFolder Folder Uid.
        * @param aPreferredUid Uid of preferred item is returned here.
        * @return Error code.
        */
        IMPORT_C TInt PreferredUid( TInt aFolder, TInt& aPreferredUid );

        /**
        * Delete item by Uid. If this is a folder, all descendants and the contents
        * of them are deleted. Homepage or root cannot be deleted.
        * @since 0.9 
        * @param aUid Uid of item to delete.
        * @return Error code, including:
        *   - KErrNotFound if the item is not found.
        *   - KErrAccessDenied if the item's cannot be deleted.
        */
        IMPORT_C TInt Delete( TInt aUid );

        /**
        * Update an item. Remember Homapage or Last Visited Page cannot be updated using
        * this method.
        * @since 0.9 
        * @param aItem Contents from this item (except Uid) will be used to
        * update the item.
        * If successful, its Uid, Last-Mod-Time (and possibly its name) is
        * updated on return.
        * @param aUid Update this item.
        * @param aAutoRename If this is ETrue, and the name already exists,
        * the item will be renamed to a non-conflicting name.
        * @return Error code, including:
        *   - KErrNotFound if the item is not found.
        *   - KErrArgument if the item's data is invalid (bad name, no URL,
        *     parent folder does not exist etc.).
        *   - KErrAlreadyExists if the name is already in use in that folder.
        *   - KErrAccessDenied for read-only items.
        */
        IMPORT_C TInt Update
            ( CFavouritesItem& aItem, TInt aUid, TBool aAutoRename );

        /**
        * Add a new item to the database.
        * If successful, its Uid, Last-Mod-Time (and possibly its name) is
        * updated on return.
        * @since 0.9 
        * @param aItem The item to add.
        * @param aAutoRename If this is ETrue, and the name already exists,
        * the item will be renamed to a non-conflicting name.
        * @return Error code, including:
        *   - KErrArgument if the item's data is invalid (bad name, no URL,
        *     parent folder does not exist etc.).
        *   - KErrAlreadyExists if the name is already in use in that folder.
        */
        IMPORT_C TInt Add( CFavouritesItem& aItem, TBool aAutoRename );

        /**
        * Update the Homepage item. If does not exist, it is now
        * created. The old Homepage, if any, is overwritten.
        * If successful, its Uid and Last-Mod-Time is updated on return.
        * Name needs not be unique.
        * @since 0.9 
        * @param aItem Contents from this item (except Uid) will
        * be used to update the Homepage Bookmark.
        * @return Error code, including:
        *   - KErrArgument if the supplied item is not item, or is not in
        *     the root folder.
        */
        IMPORT_C TInt SetHomepage( CFavouritesItem& aItem );

        /**
        * Update the Last Visited. If does not exist, it is now
        * created. The old Last Visited, if any, is overwritten.
        * If successful, its Uid is updated on return.
        * Name needs not be unique.
        * @since 0.9 
        * @param aItem Contents from this item (except Uid) will
        * be used to update the Last Visited Item.
        * @return Error code, including:
        *   - KErrArgument if the supplied item is not item, or is not in
        *     the root folder.
        */
        IMPORT_C TInt SetLastVisited( CFavouritesItem& aItem );

        /**
        * Set factory item flag on an item.
        * (Item with this flag set will be deleted if RFS is executed.)
        * @since 0.9 
        * @param aUid Uid of item.
        * @param aFactoryItem Flag value to set.
        * @return Error code, including:
        *   - KErrNotFound if the item is not found.
        */
        IMPORT_C TInt SetFactoryItem( TInt aUid, TBool aFactoryItem );

        /**
        * Set read-only flag on an item.
        * @since 0.9 
        * @param aUid Uid of item.
        * @param aReadOnly Flag value to set.
        * @return Error code, including:
        *   - KErrNotFound if the item is not found.
        */
        IMPORT_C TInt SetReadOnly( TInt aUid, TBool aReadOnly );

        /**
        * Manual setting of Last Modification Time of an item.
        * Note that the Last Modification Time is automatically set by any
        * edit, so this method need not be used in usual circumstances. It is
        * provided for administration purposes only.
        * @since 0.9 
        * @param aUid Uid of item.
        * @param aModified Last Modification Time to set.
        * @return Error code, including:
        *   - KErrNotFound if the item is not found.
        */
        IMPORT_C TInt SetModified( TInt aUid, TTime aModified );

        /**
        * Set preferred Uid for a folder.
        * @since 0.9 
        * @param aFolder Folder Uid.
        * @param aUid Uid to be set as preferred. Not checked to exist in the folder.
        * @return Error code, including:
        * - KErrNotFound if aFolder is not found;
        * - KErrArgument if aFolder is not a folder.
        */
        IMPORT_C TInt SetPreferredUid( TInt aFolder, TInt aUid );

        /**
        * Check if we already have this item.
        * @since 0.9 
        * @param aUid The item Uid to be checked.
        * @param aItemExists Returned value.
        * @return Error code.
        */
        IMPORT_C TInt ItemExists( TInt aUid, TBool& aItemExists );

        /**
        * Check if the folder exists.
        * @since 0.9 
        * @param aFolder The folder to be checked.
        * @param aFolderExists Returned value.
        * @return Error code.
        */
        IMPORT_C TInt FolderExists( TInt aFolder, TBool& aFolderExists );

        /**
        * Count all items matching the supplied criteria.
        * @since 0.9 
        * @param aCount Placeholder for the returned item count. In case of
        * any error, existing value is unchanged.
        * @param aParentFolderFilter Uid value to filter. KFavouritesNullUid
        * clears (all accepted); this is the default.
        * @param aTypeFilter EItem or EFolder to use filter; ENone to clear
        * filter (all accepted); this is the default.
        * @param aNameFilter Wildcard pattern to be used for name matching.
        * NULL clears (all accepted); this is the default.
        * @param aContextIdFilter ContextId value to filter.
        * KFavouritesNullContextId clears (all accepted); this is the default.
        * @return Error code.
        */
        IMPORT_C TInt Count
            (
            TInt& aCount,
            TInt aParentFolderFilter = KFavouritesNullUid,
            CFavouritesItem::TType aTypeFilter = CFavouritesItem::ENone,
            const TDesC* aNameFilter = NULL,
            TInt32 aContextIdFilter = KFavouritesNullContextId
            );

    public:     // extra data

        /**
        * Set data associated with an item. Any existing data, belonging to
        * item having aUid, is now replaced. The item itself is not changed.
        * In case of any errors, the data is not saved.
        * @since 0.9 
        * @param aUid The uid of the item, to which the data belongs.
        * @param aData Data) which replaces existing data.
        * @return Error code, including:
        *   - KErrNotFound No item is found with aUid.
        */
        IMPORT_C TInt SetData( TInt aUid, const MFavouritesItemData& aData );

        /**
        * Get data associated with an item.
        * @since 0.9 
        * @param aUid The uid of the item, to which the data belongs.
        * @param aData Data object, which receives the data.
        * @return Error code, including:
        *   - KErrNotFound No item is found with aUid.
        */
        IMPORT_C TInt GetData( TInt aUid, MFavouritesItemData& aData );

    public:     // Browser data

        /**
        * Set Browser data associated with an item. Any existing data,
        * belonging to  item having aUid, is now replaced. The item itself is
        * not changed.
        * This data is for Browser's dedicated use, do not tamper.
        * In case of any errors, the data is not saved.
        * @since 0.9 
        * @param aUid The uid of the item, to which the data belongs.
        * @param aData Data) which replaces existing data.
        * @return Error code, including:
        *   - KErrNotFound No item is found with aUid.
        */
        IMPORT_C TInt SetBrowserData( TInt aUid, const MFavouritesItemData& aData );

        /**
        * Get Browser associated with an item.
        * This data is for Browser's dedicated use, do not tamper.
        * @since 0.9 
        * @param aUid The uid of the item, to which the data belongs.
        * @param aData Data object, which receives the data.
        * @return Error code, including:
        *   - KErrNotFound No item is found with aUid.
        */
        IMPORT_C TInt GetBrowserData( TInt aUid, MFavouritesItemData& aData );

    public:     // unique name support

        /**
        * Check if aName is unique in aFolder; and if not, change to
        * an unique one, appending a number. In case of any errors, aName is
        * unchanged. Names of special items (Start Page etc.) are not
        * considered (can have conflicting names).
        * @since 0.9         
        * @param aName Descriptor containing the original name and receiving
        * the resulting unique name. Must be large enough to accomodate the
        * result. (The appended text is KFavouritesMaxPostfix characters at
        * most; the resulting length is KFavouritesMaxName at most.)
        * @param aFolder Folder to be used for uniqueness-checking.
        * @return Error code, including:
        *   - KErrArgument aFolder is not found.
        *   - KErrBadName aName is empty.
        */
        IMPORT_C TInt MakeUniqueName( TDes& aName, TInt aFolder );

        /**
        * Check if aName is unique in its folder; and if not, change to
        * an unique one, appending a number. In case of any errors, aItem is
        * unchanged. Names of special items (Start Page etc.) are not
        * considered (can have conflicting names).
        * @since 0.9 
        * @param aItem Item to set unique name for.
        * @return Error code, including:
        *   - KErrArgument aFolder is not found.
        *   - KErrBadName Current name is empty.
        */
        IMPORT_C TInt MakeUniqueName( CFavouritesItem& aItem );

    public:     // Browser support

        /**
        * Create an empty item with uid KFavouritesStartPageUid. Owner is the
        * caller. Except its uid, the item is uninitialized. The Browser
        * needs this. Note that this item does not exist in the database.
        * @since 0.9 
        * @return The created item.
        */
        IMPORT_C CFavouritesItem* CreateStartPageItemL();

        /**
        * Create a folder with uid KFavouritesAdaptiveItemsFolderUid.
        * Owner is the caller. Uid, type (folder) and parent (root) is set,
        * other properties are uninitialized. The Browser  needs this. Note
        * that this item does not exist in the database.
        * @since 0.9 
        * @return The created item.
        */
        IMPORT_C CFavouritesItem* CreateAdaptiveItemsFolderL();

    public:     // Files

        /**
        * Delete file. See RFavouritesFile.
        * @since 0.9 
        * @param aUid Uid of the item.
        * @return Errro code.
        */
        IMPORT_C TInt DeleteFile( TInt aUid );

    public:     // RFS

        /**
        * User-level Restore Factory Settings operation.
        * Delete all items that has "factory item" flag set, then add new
        * ones from reference database. In case of name conflilcts, new
        * names are generated. Leaves on any error.
        * @since 0.9 
        * @param aName Database name.
        * @param aReferenceDbPath Full pathname of reference database.
        * @param aApMapper Access Point mapper to be used.
        */
        IMPORT_C static void RestoreFactorySettingsL
            (
            const TDesC& aName,
            const TDesC& aReferenceDbPath,
            MRfsApMapper& aApMapper
            );

    private:    // New methods

        /**
        * Set Homepage / Last Visited Page.
        * @since 0.9 
        * @param aItem Item data.
        * @param aUid Uid of the item to be set.
        * @return Error code.
        */
        TInt SetSpecialItem( CFavouritesItem& aItem, TInt aUid );

        /**
        * Set data associated with an item.
        * @since 0.9 
        * @param aFunction Function.
        * @param aUid The uid of the item, to which the data belongs.
        * @param aData Data which replaces existing data.
        * @return Error code.
        */
        TInt SetData
            ( TInt aFunction, TInt aUid, const MFavouritesItemData& aData );

        /**
        * Get data associated with an item.
        * @since 0.9 
        * @param aFunction Function.
        * @param aUid The uid of the item, to which the data belongs.
        * @param aData Data object, which receives the data.
        * @return Error code.
        */
        TInt GetData
            ( TInt aFunction, TInt aUid, MFavouritesItemData& aData );

        /**
        * Implementation of RestoreFactorySettingsL().
        * @since 0.9 
        * @param aReferenceDbPath Full pathname of reference database.
        * @param aApMapper Access Point mapper to be used.
        */
        void DoRestoreFactorySettingsL
            ( const TDesC& aReferenceDbPath, MRfsApMapper& aApMapper );

        /**
        * Cleanup helper, static wrapper around the rollback call.
        * @since 0.9 
        * @param aPtr This as TAny*.
        */
        static void StaticRollback( TAny* aPtr );

    };

#endif
            
// End of File
