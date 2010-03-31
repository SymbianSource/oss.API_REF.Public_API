/*
* Copyright (c) 2002-2007 Nokia Corporation and/or its subsidiary(-ies).
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
* Description:  Defines the item id class used to identify the skin items.
*
*/


#ifndef AKNSITEMID_H
#define AKNSITEMID_H

//  INCLUDES
#include <e32std.h>
#include <e32base.h>

// DATA TYPES

/**
* Type enumeration for skin items.
*
* @since 2.0
*/
enum TAknsItemType
    {
    /**
    * Unknown type, used by CAknsItemDef.
    */
    EAknsITUnknown      =0,

    /**
    * Bitmap type, used by CAknsBitmapItemData and CAknsBitmapItemDef.
    */
    EAknsITBitmap       =1,

    /**
    * Masked bitmap type, used by CAknsMaskedBitmapItemData and
    * CAknsMaskedBitmapItemDef.
    */
    EAknsITMaskedBitmap =2,

    /**
    * Color table type, used by CAknsColorTableItemData and
    * CAknsColorTableItemDef.
    */
    EAknsITColorTable   =3,

    /**
    * Image table type, used by CAknsImageTableItemData and
    * CAknsImageTableItemDef.
    */
    EAknsITImageTable   =4,

    /**
    * Image type, used by CAknsImageItemData and CAknsImageItemDef.
    */
    EAknsITImage        =5,

    /**
    * Bitmap animation type, used by CAknsBmpAnimItemData and CAknsBmpAnimItemDef.
    */
    EAknsITBmpAnim      =6,

    /**
    * String property type, used by CAknsStringItemData.
    *
    * @since 2.6
    */
    EAknsITString       =7,

    /**
    * Scalable item effect queue type, used by CAknsEffectQueueItemData.
    *
    * @since 2.8
    */
    EAknsITEffectQueue  =8,

    /**
    * Animation type, used by CAknsAnimationItemData
    */
    EAknsITAnimation    =9
    };

/**
* Image attribute enumeration for image skin items.
*
* @since 2.0
*/
enum TAknsImageAttribute
    {
    /**
    * No attribute defined.
    * @since 2.0
    */
    EAknsImageAttributeNone     =0x00,

    /**
    * Image should be placed acording to the given coordinates.
    * Currently unsupported.
    * @since 2.0
    */
    EAknsImageAttributeCoords   =0x01,

    /**
    * Image size should stretched to the given size.
    * Currently used only with application icons as a search shortcut.
    * @since 2.0
    */
    EAknsImageAttributeSize     =0x02,

    /**
    * Image should be stretched to cover the entire layout area.
    * Aspect ratio is not preserved.
    * @since 2.0
    */
    EAknsImageAttributeStretch  =0x04,

    /**
    * Image should be tiled (in both directions) to fill the area.
    * @since 2.0
    */
    EAknsImageAttributeTile     =0x08,

    /**
    * Image should be aligned according to the given parameter.
    * @since 2.0
    */
    EAknsImageAttributeAlign    =0x10,

    /**
    * Image should be scaled to fill the area maintaining the aspect
    * ratio.
    * Currently unsupported.
    * @since 2.0
    */
    EAknsImageAttributeScale    =0x20,

    /**
    * Image should be tiled in X-axis direction to fill the area.
    * @since 2.8
    */
    EAknsImageAttributeTileX    =0x40,

    /**
    * Image should be tiled in Y-axis direction to fill the area.
    * @since 2.8
    */
    EAknsImageAttributeTileY    =0x80,

    /**
    * The item is already scalability-aware and backward compatibility
    * should not be applied to it.
    * @internal
    * @since 2.8
    */
    EAknsImageAttributeNBC     =0x100
    };

/**
* Image alignment enumeration for image skin items.
*
* @since 2.0
*/
enum TAknsImageAlignment
    {
    EAknsImageAlignNone     =0x00,
    EAknsImageAlignVTop     =0x01,
    EAknsImageAlignVBottom  =0x02,
    EAknsImageAlignVCenter  =0x04,
    EAknsImageAlignHLeft    =0x08,
    EAknsImageAlignHRight   =0x10,
    EAknsImageAlignHCenter  =0x20,
    EAknsImageAlignTL       =EAknsImageAlignVTop|EAknsImageAlignHLeft,
    EAknsImageAlignTR       =EAknsImageAlignVTop|EAknsImageAlignHRight,
    EAknsImageAlignTC       =EAknsImageAlignVTop|EAknsImageAlignHCenter,
    EAknsImageAlignBL       =EAknsImageAlignVBottom|EAknsImageAlignHLeft,
    EAknsImageAlignBR       =EAknsImageAlignVBottom|EAknsImageAlignHRight,
    EAknsImageAlignBC       =EAknsImageAlignVBottom|EAknsImageAlignHCenter,
    EAknsImageAlignCL       =EAknsImageAlignVCenter|EAknsImageAlignHLeft,
    EAknsImageAlignCR       =EAknsImageAlignVCenter|EAknsImageAlignHRight,
    EAknsImageAlignCC       =EAknsImageAlignVCenter|EAknsImageAlignHCenter,
    EAknsImageAlignVMask    =EAknsImageAlignVTop|EAknsImageAlignVBottom|
                             EAknsImageAlignVCenter,
    EAknsImageAlignHMask    =EAknsImageAlignHLeft|EAknsImageAlignHRight|
                             EAknsImageAlignHCenter
    };


// FORWARD DECLARATIONS

class CFbsBitmap;

// CLASS DECLARATION

/**
* Item identifier used to identify items supplied through skin interfaces.
* Item ID consists of two integers: major and minor parts of the ID.
*
* Note that only LinearOrder() member function requires linking against
* the library, all the other methods are inlined.
*
* @lib AknSkinSrv.lib
*
* @since 2.0
*/
class TAknsItemID
    {
    public: // New functions

        /**
        * Sets specified major and minor parts.
        *
        * @param aMajor Major part of the item ID.
        *
        * @param aMinor Minor part of the item ID.
        */
        inline void Set( const TInt aMajor, const TInt aMinor );

        /**
        * Sets specified major and minor parts
        * where major part is given as a UID.
        *
        * @param aMajor Major part of the item ID as a UID.
        *
        * @param aMinor Minor part of the item ID.
        */
        inline void Set( const TUid aMajor, const TInt aMinor );

        /**
        * Sets major and minor parts according to the given item ID.
        *
        * @param aID Item ID to be used to get the values.
        */
        inline void Set( const TAknsItemID& aID );

        /**
        * Determines the order of two TAknsItemID objects.
        * Implements an algorithm that determines the order of two item ID
        * objects.
        *
        * @param aFirst Constant reference to the first object to be compared.
        *
        * @param aSecond Constant reference to the second object to be
        *   compared.
        *
        * @return 0 if the two objects are equal, negative value if the first
        *   object is less than the second and positive value if the first
        *   object is greater than the second.
        *
        * @par Implementation details:
        * To improve binary search, current implementation first compares minor
        *   part and after that the major part of the item ID. Since most lists
        *   have several objects with equal major parts this makes the algorithm
        *   more efficient.
        */
        IMPORT_C static TInt LinearOrder(
            const TAknsItemID& aFirst, const TAknsItemID& aSecond );

    public: // Data

        TInt iMajor;    //!< Major part of the item ID as an integer.
        TInt iMinor;    //!< Minor part of the item ID as an integer.

    };

// DATA TYPES (continued)

/**
* Simple array of item ID objects.
*/
typedef RArray<TAknsItemID> RAknsItemIDArray;

// FUNCTION PROTOTYPES

/**
* C++ equal operator.
* Checks whether two item ID objects (i.e. their major and minor parts)
* have identical content.
*
* @param aFirst First object to be compared.
*
* @param aSecond Second object to be compared.
*
* @return true if objects have identical content, false otherwise.
*/
inline TBool operator==( const TAknsItemID& aFirst, const TAknsItemID& aSecond );

/**
* C++ not equal operator.
* Checks whether two item ID objects (i.e. their major and minor parts)
* have identical content.
*
* @param aFirst First object to be compared.
*
* @param aSecond Second object to be compared.
*
* @return false if objects have identical content, true otherwise.
*/
inline TBool operator!=( const TAknsItemID& aFirst, const TAknsItemID& aSecond );

// INLINED MEMBERS

#include "AknsItemID.inl"

#endif // AKNSITEMID_H

// End of File
