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
* Description:  Declaration of FavouritesItem
*
*/


#ifndef FAVOURITES_ITEM_H
#define FAVOURITES_ITEM_H

//  INCLUDES

#include <e32base.h>
#include <FavouritesLimits.h>
#include <FavouritesWapAp.h>

// FORWARD DECLARATION

class CFavouritesItemImpl;
class RWriteStream;
class RReadStream;

// CLASS DECLARATION

/**
* CFavouritesItem is the base class for representing one favourites entry (item or folder).
* Instances of this class are used to exchange data between the Favourites
* Engine and clients using it.
*/
class CFavouritesItem: public CBase
    {

    public:     // Data types

       /**
        * Defines the type of an item (item or folder).
        */
        enum TType  /// Type of an item (item or folder).
            {
           /*
            * Invalid value, can not be set for a CFavouritesItem 
            * @see For more informaiton on ENone, see CFavouritesItem.
            */
            ENone,  
           /*
            * Favourites item
            * @see For more informaiton on ENone, see CFavouritesItem.
            */            
            EItem,  
           /*
            * Favourites folder.
            * @see For more informaiton on ENone, see CFavouritesItem.
            */
            EFolder 
            };

    public:     // Constructors and destructor
        
        /**
        * Two-phased constructor. Leaves on failure. Places the instance on the
        * cleanup stack.
        * @since 0.9       
        * @return The constructed item.
        */
        IMPORT_C static CFavouritesItem* NewLC();

        /**
        * Two-phased constructor. Leaves on failure.
        * @since 0.9       
        * @return The constructed item.
        */
        IMPORT_C static CFavouritesItem* NewL();

        /**
        * Destructor.
        * @since 0.9       
        */
        IMPORT_C virtual ~CFavouritesItem();

        /**
        * Assignment operator.
        * @since 0.9       
        * @param aCopyFrom Assign from this.
        */
        IMPORT_C CFavouritesItem& operator=
            ( const CFavouritesItem& aCopyFrom );

    public:     // Query

        /**
        * Get unique id of the item.
        * @since 0.9       
        * @return The unique id.
        */
        IMPORT_C TInt Uid() const;

        /**
        * Get the uid of the parent folder of this item.
        * @since 0.9       
        * @return The unique id of the parent folder.
        */
        IMPORT_C TInt ParentFolder() const;

        /**
        * Get type of the item (item or folder).
        * @since 0.9       
        * @return The type of the item. It is either EFolder or EItem
        * (never ENone).
        */

        IMPORT_C TType Type() const;

        /**
        * Get the name of this item.
        * @since 0.9       
        * @return The name of this item.
        */
        IMPORT_C const TPtrC Name() const;

        /**
        * Get the URL of this item.
        * @since 0.9       
        * @return The URL of this item.
        */
        IMPORT_C const TPtrC Url() const;

        /**
        * Get WAP Access Point id associated with this item.
        * @since 0.9       
        * @return The WAP Access Point id.
        */
        IMPORT_C TFavouritesWapAp WapAp() const;

        /**
        * Get the username associated with this item.
        * @since 0.9       
        * @return The username.
        */
        IMPORT_C const TPtrC UserName() const;

        /**
        * Get password associated with this item.
        * @since 0.9       
        * @return The password.
        */
        IMPORT_C const TPtrC Password() const;

        /**
        * Get context id associated with this item.
        * @since 0.9       
        * @return The context id.
        */
        IMPORT_C TInt32 ContextId() const;

        /**
        * Check if this is an item (not folder).
        * @since 0.9       
        * @return ETrue if this is an item.
        */
        IMPORT_C TBool IsItem() const;

        /**
        * Check if this is a folder.
        * @since 0.9       
        * @return ETrue if this is a folder.
        */
        IMPORT_C TBool IsFolder() const;

        /**
        * Check if this is a factory item.
        * @since 0.9       
        * @return ETrue if this is a factory item.
        */
        IMPORT_C TBool IsFactoryItem() const;

        /**
        * Check if this is a read-only in database. Note that ETrue value does
        * not prevent modifying this CFavouritesItem object.
        * @since 0.9       
        * @return ETrue if this is read-only in database.
        */
        IMPORT_C TBool IsReadOnly() const;

        /**
        * Get last modification time (of database entry), universal time.
        * This can be zero if:
        * - Last modification time is not available in database (old
        *   databases); or
        * - Engine does not support this feature.
        * Note that zero means Modified().Int64() == 0, and not
        * Time::NullTTime().
        * @since 0.9       
        * @return TTime, last modification time                 
        */
        IMPORT_C TTime Modified() const;

    public:     // update

        /**
        * Reset the item to default values.
        * @since 0.9       
        * @return void                         
        */
        IMPORT_C void ClearL();

        /**
        * Set parent folder.
        * @since 0.9       
        * @param aId The unique id of the parent folder.
        * @return void                                 
        */
        IMPORT_C void SetParentFolder( TInt aId );

        /**
        * Set item type (item or folder).
        * @since 0.9               
        * @param aType The type to be set. ENone cannot be set (if that is
        * specified, it is ignored).
        * @return void                                 
        */
        IMPORT_C void SetType( TType aType );

        /**
        * Set name of the item. Leading or trailing whitespace is trimmed.
        * Length limit is KFavouritesMaxName (leaves with KErrOverflow).
        * @since 0.9               
        * @param aName The name to be set.
        * @return void                                 
        */
        IMPORT_C void SetNameL( const TDesC& aName );

        /**
        * Set URL of the item.
        * @since 0.9                       
        * Length limit is KFavouritesMaxURL (leaves with KErrOverflow).
        * @param aUrl The URL to be set.
        * @return void                                 
        */
        IMPORT_C void SetUrlL( const TDesC& aUrl );

        /**
        * Set WAP Access Point of the item.
        * @since 0.9                       
        * @param aAccessPoint The WAP Access point to be set.
        * @return void                                 
        */
        IMPORT_C void SetWapAp( const TFavouritesWapAp& aAccessPoint );

        /**
        * Set username of the item.
        * Length limit is KFavouritesMaxUserName (leaves with KErrOverflow).
        * @since 0.9                       
        * @param aUserName The username to be set.
        * @return void                                 
        */
        IMPORT_C void SetUserNameL( const TDesC& aUserName );

        /**
        * Set password.
        * Length limit is KFavouritesMaxPassword (leaves with KErrOverflow).
        * @since 0.9                       
        * @param aPassword The password to be set.
        * @return void                                 
        */
        IMPORT_C void SetPasswordL( const TDesC& aPassword );

        /**
        * Set context id of the item.
        * @since 0.9                       
        * @param aContextId The context id to be set.
        * @return void                                 
        */
        IMPORT_C void SetContextId( TInt32 aContextId );
        
        /**
        * Check if this is a hidden.
        * @since 0.9       
        * @return ETrue if this is hidden.
        */
        IMPORT_C TBool IsHidden() const;        

        /**
        * Set hidden value of the item.
        * @since 0.9                       
        * @param aHidden The hidden value to be set.
        * @return void                                 
        */
        IMPORT_C TBool SetHidden(TBool aHidden) const;        
        
    public:     // (But not exported:) Streaming

        /**
        * Externalize into a stream.
        * @since 0.9                       
        * @param aStream The stream to externalize to.
        * @return void                                 
        */
        void ExternalizeL( RWriteStream& aStream ) const;

        /**
        * Internalize from a stream.
        * @since 0.9                       
        * @param aStream The stream to externalize from.
        * @return void                                 
        */
        void InternalizeL( RReadStream& aStream );

    private:    // Constructors
        
        /**
        * C++ constructor.
        * @since 0.9                       
        */
        CFavouritesItem();

        /**
        * Second-phase constructor.
        * @since 0.9                       
        */
        void ConstructL();

    private:    // Data

        CFavouritesItemImpl* iImpl; ///< Implementation. Owned.

    private:    // friends

        // Setting UID and accessing implementation is granted to this.
        friend class RFavouritesDb;

    };

#endif
            
// End of File
