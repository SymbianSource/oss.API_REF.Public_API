/*
* Copyright (c) 2002 Nokia Corporation and/or its subsidiary(-ies).
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
* Description:  Defines a public interface class MAknsSkinInstance and related
*                enumerations.
*
*/


#ifndef AKNSSKININSTANCE_H
#define AKNSSKININSTANCE_H

//  INCLUDES
#include <e32std.h>

#include <AknsDataContext.h>
#include <AknsItemData.h>

// FORWARD DECLARATIONS
class CFbsBitGc;
class CAknsItemDef;

// DATA TYPES

/**
* Type enumeration for skin client errors.
*
* @since 2.0
*/
enum TAknsClientError
    {
    /**
    * Unspecified error.
    */
    EAknsClientErrorUnspecified     = 0,

    /**
    * Out of memory.
    *
    * @since 2.5
    */
    EAknsClientErrorOOM             = -4
    };

/**
* Type enumeration for the last skin change reason.
*
* @since 3.1
*
*/
enum TAknsSkinChangeReason
    {
    // For normal skin change events, ie. all item change
    ENormalSkinChange       = 0,
    // When a morphing state is changed, ie. only backgrounds change
    EMorphingStateChange    = 1,
    // When the wallpaper is changed, ie. only the wallpaper change
    EWallpaperChange        = 2
    };


// CLASS DECLARATION

/**
* Interface to skin instance.
* Skin instance is a singleton object that can be retrieved using
* AknsUtils::SkinInstance(). It maintains item cache, but also
* local item definition list and root data context. While skin instance
* can be used directly by client code, it is often easier to use utility
* methods provided in AknsUtils and AknsDrawUtils.
*
* This is a public interface class that contains no exported functions.
* The class is not intended for derivation outside the library.
*
* @since 2.0
*/
class MAknsSkinInstance
    {
    public:  // Constructors and destructor
        
        /**
        * Destructor for internal use.
        * Destructor is reserved for internal use and should be never
        * called by client code on singleton instance.
        *
        * @internal
        */
        inline virtual ~MAknsSkinInstance() {}

    public: // New functions - Item data

        /**
        * Returns root data context.
        * Root data context is used by other data context instances to
        * indicate data reservations and releases. It may also be used
        * directly by application code, if no other context is available.
        * Nearest data context can be retrieved using 
        * AknsUtils::DataContext(MObjectProvider* aMop) utility method.
        *
        * @since 2.0
        *
        * @return Pointer to root data context. Skin instance still owns the
        *   data context and its lifetime is that of skin instance itself.
        */
        virtual MAknsDataContext* RootDataContext() =0;

        /**
        * Returns (and constructs if necessary) cached item data object.
        * The method first searches the cache for the specified item. 
        * If none is found, it creates and caches a new instance of the 
        * item data.
        *
        * @since 2.0
        *
        * @param aID Item ID of the item to be retrieved.
        *
        * @param aType Type of the item.
        *
        * @return Item data for the specified item, or @c NULL value if
        *   none was found or an error occured. The caller can assume that a
        *   non-NULL value is a pointer that can be casted to the subclass
        *   corresponding to aType.
        *
        * @par Exceptions:
        *   Since this is a non-leaving method, the skin instance may perform
        *   error handling, e.g., by instructing the system to switch to the
        *   default skin.
        */
        virtual CAknsItemData* GetCachedItemData( const TAknsItemID& aID,
            const TAknsItemType aType ) =0;

        /**
        * Returns (and constructs if necessary) cached item data object.
        * The method first searches the cache for the specified item. 
        * If none is found, it creates and caches a new instance of the 
        * item data. 
        *
        * This overload can be used to retrieve items if the type of the
        * item is not known beforehand. In other cases, the first overload
        * shold be preferred, since it may be considerably faster.
        *
        * @since 2.0
        *
        * @param aID Item ID of the item to be retrieved.
        *
        * @return Item data for the specified item, or @c NULL value if
        *   none was found or an error occured.
        *
        * @par Exceptions:
        *   Since this is a non-leaving method, the skin instance may perform
        *   error handling, e.g., by instructing the system to switch to the
        *   default skin.
        */
        virtual CAknsItemData* GetCachedItemData( const TAknsItemID& aID ) =0;

        /**
        * Creates a new non-cached item data object.
        * The method constructs a new instance of item data of the specified 
        * skin item and returns it.
        *
        * @since 2.0
        *
        * @param aID Item ID of the item to be created.
        *
        * @param aType Type of the item.
        *
        * @return Newly created item data object. Ownership of the object is
        *   transferred to the caller. If no item definition for the specified
        *   ID was found, @c NULL value is returned. The caller can assume that
        *   a non-NULL value is a pointer that can be casted to the subclass
        *   corresponding to aType.
        *
        * @par Exceptions:
        *   If item data construction fails, function leaves with an error code.
        */
        virtual CAknsItemData* CreateUncachedItemDataL( const TAknsItemID& aID,
            const TAknsItemType aType ) =0;

        /**
        * Creates a new non-cached item data object.
        * The method constructs a new instance of item data of the specified 
        * skin item and returns it.
        *
        * This overload can be used to create items if the type of the
        * item is not known beforehand. In other cases, the first overload
        * shold be preferred, since it may be considerably faster.
        *
        * @since 2.0
        *
        * @param aID Item ID of the item to be created.
        *
        * @return Newly created item data object. Ownership of the object is
        *   transferred to the caller. If no item definition for the specified
        *   ID was found, @c NULL value is returned.
        *
        * @par Exceptions:
        *   If item data construction fails, function leaves with an error code.
        */
        virtual CAknsItemData* CreateUncachedItemDataL( const TAknsItemID& aID ) =0;
 
    public: // New functions - Item definitions

        /**
        * Sets local item definition.
        * Adds (or replaces if one already exists) a local item definition.
        *
        * @since 2.0
        *
        * @param aDef New local item definition. Ownership of definition object
        *   is transferred to skin instance and caller should make no access
        *   to it after this call.
        *
        * @par Exceptions:
        *   If an error occurs, function leaves with an error code. Item 
        *   definition object is either added into local definition list or
        *   destroyed depending on when the error occured.
        *
        * @par Note:
        *   Since the method always assumes ownership of @c aDef, it must
        *   not be pushed into the cleanup stack.
        */
        virtual void SetLocalItemDefL( CAknsItemDef* aDef ) =0;   
        
        /**
        * Enables or disables change notifications.
        * When enabled, resource change events are sent to the application when
        * item definitions change. If a change occurs when events are disabled,
        * it will be sent (collated, only one event) when events are re-enabled.
        *
        * @since 2.0
        *
        * @param aEnabled ETrue to enable events, EFalse to disable them.
        */
        virtual void SetChangeEventsEnabled( TBool aEnabled ) =0;

    public: // New functions - Error handling

        /**
        * Notifies the skin instance about an error condition.
        * Errors that can be reported to the skin instance include incorrect
        * skin content (e.g., a bitmap that can not be constructed) or
        * out of memory situations. The error condition is usually handled by
        * switching to the default system skin. Error notifications will be
        * ignored when there is no reasonable recovery operation available.
        *
        * @since 2.0
        *
        * @param aError Error type. Currently only EAknsClientErrorUnspecified
        *   is supported.
        */
        virtual void NotifyClientError( const TAknsClientError aError ) =0;
    
    public: // New functions - querying the skin change reason.
        /**
        * Queries the last skin change reason. This function can be used
        * to query the last reason why skin change occurred. Usually client
        * would use this inside the HandleResourceChange call. If no skin
        * change events have been reported for the application, the function
        * returns ENormalSkinChange.
        *
        * @since 3.1
        *
        * @return the last skin change reason.
        */
        virtual TAknsSkinChangeReason SkinChangeReason() = 0;
        
    public:
        /**
        * Removes all local item defs from this instance set by
        * SetLocalItemDefL
        */
        virtual void RemoveLocalItemDefs() = 0;
        
        /**
        * Checks whether a skin update is currently being done.
        *
        * @since 5.0
        */
        virtual TBool IsUpdateInProgress() = 0;       
    };

#endif      // AKNSSKININSTANCE_H   
            
// End of File
