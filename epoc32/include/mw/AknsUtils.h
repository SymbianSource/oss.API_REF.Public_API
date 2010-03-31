/*
* Copyright (c) 2002-2004 Nokia Corporation and/or its subsidiary(-ies).
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
* Description:  Defines a public static utility class AknsUtils.
*
*/


#ifndef AKNSUTILS_H
#define AKNSUTILS_H

//  INCLUDES
#include <AknsSkinInstance.h>
#include <apgicnfl.h>
#include <AknIconUtils.h>

// FORWARD DECLARATIONS
class CFbsBitmap;
class CAknsItemDef;
class CCoeControl;
class CGulIcon;

// TYPE DEFINITIONS

/**
* Type of the application icon.
*
* @since 2.8
*/
enum TAknsAppIconType
    {
    EAknsAppIconTypeList    = 0,
    EAknsAppIconTypeContext = 1,
    EAknsAppIconType3D      = 2
    };

// CLASS DECLARATION

/**
* Static utility class to support AVKON SKINS common operations.
* AknsUtils provides utility method to initialize application skin support,
* retrieve current skin instance or data context, retrieve skin data
* items and to perform other skin-related tasks.
*
* This is a public static class with exported functions.
* The class is not intended for derivation outside the library.
*
* @lib AknSkins.lib
*
* @since 2.0
*/
class AknsUtils
    {    

    public: // New functions - Creators
        
        /**
        * Initializes application skin support.
        * Creates application skin instance. Method should be called once
        * in the construction phase of application, before any other 
        * skin-related operations take place.
        *
        * @since 2.0
        *
        * @par Notes:
        *   The framework calls this method automatically for each
        *   application. Thus, a normal application does not need to
        *   call this method explicitly.        
        *
        * @par Exceptions:
        *   - If allocation fails, function leaves with an error code.
        */
        IMPORT_C static void InitSkinSupportL();

        /**
        * Creates data context suitable for a container.
        * Constructs a new data context suitable for a container. Container
        * should store the pointer and perform proper destruction when 
        * the lifetime of the container itself ends.
        *
        * @since 2.0
        *
        * @return Newly created data context. Ownership of the context object
        *   is transferred to the caller.
        */
        IMPORT_C static MAknsDataContext* CreateDataContextForContainerL();

        /**
        * Constructs a new bitmap item definition object.
        *
        * @since 2.0
        *
        * @param aID Item ID of the item definition object to be created:
        *
        * @param aFile Filename of the MBM file.
        *
        * @param aIndex Index of the bitmap in the file.
        *
        * @return Newly constructed item definition object.
        *
        * @par Exceptions:
        *   If construction fails, the method leaves with an error code.
        */
        IMPORT_C static CAknsItemDef* CreateBitmapItemDefL( 
            const TAknsItemID& aID, const TDesC& aFilename, 
            const TInt aIndex );

        /**
        * Constructs a new masked bitmap item definition object.
        *
        * @since 2.0
        *
        * @param aID Item ID of the item definition object to be created:
        *
        * @param aFile Filename of the MBM file.
        *
        * @param aIndex Index of the bitmap in the file.
        *
        * @param aIndex Index of the bitmap mask in the file.
        *
        * @return Newly constructed item definition object. Ownership of the
        *   object is transferred to the caller.
        *
        * @par Exceptions:
        *   If construction fails, the method leaves with an error code.
        */
        IMPORT_C static CAknsItemDef* CreateMaskedBitmapItemDefL( 
            const TAknsItemID& aID, const TDesC& aFilename, 
            const TInt aIndex, const TInt aMaskIndex );

    public: // New functions - Skin access

		/**
        * Returns pointer to current skin instance.
        * Retrieves pointer to the current application skin instance singleton.
        * If there is none, @c NULL value is returned.
        *
        * @since 2.0
        *
        * @return Pointer to current skin instance, or @c NULL if no skin 
        *   support is available.
        */
        IMPORT_C static MAknsSkinInstance* SkinInstance();

        /**
        * Returns pointer to current data context.
        * If aMop parameter is specified, retrieves the nearest data context
        * in control hierarchy. If none is found (or @c NULL parameter was
        * given) returns root data context from skin instance. If there is
        * no skin instance, @c NULL value is returned.
        *
        * @since 2.0
        *
        * @param aMop Object provider to be used to find the nearest data
        *   context. In most cases this should be a pointer to the calling
        *   @c CCoeControl. @c NULL value is also valid.
        *
        * @return Pointer to the nearest data context, or @c NULL if no
        *   skin support is available.
        */
        IMPORT_C static MAknsDataContext* DataContext( MObjectProvider* aMop );

    public: // New functions - Item access w/ fallback support

        /**
        * Constructs an independent masked bitmap with fallback support.
        * Creates an independent (in terms of instance ownership) copy of a 
        * masked bitmap by the given item ID.
        *
        * If no matching item is found in the currently activate skin,
        * attempts to construct the item using the given file.
        *
        * @since 2.6
        *
        * @lib AknSkins.lib
        *
        * @param aInstance Pointer to the current skin instance.
        *   Usually retrieved using @c AknsUtils::SkinInstance.
        *
        * @param aID Item ID of the masked bitmap to be created.
        *
        * @param aBitmap If method succeeds, set to point to the
        *   newly constructed bitmap. Ownership of the bitmap is transferred 
        *   to the caller.
        *
        * @param aMask If method succeeds, set to point to the newly
        *   constructed mask bitmap. Ownership of the bitmap is transferred
        *   to the caller.
        *
        * @param aFilename Filename to be used to construct the item, 
        *   if no matching item was found in the currently active skin.
        *
        * @param aFileBitmapId ID of the bitmap in the file. 
        *   Used only if no matching item was found in the currently 
        *   active skin.
        *
        * @param aFileMaskId ID of the mask in the file.
        *   Used only if no matching item was found in the currently
        *   active skin.
        *
        * @par Exceptions:
        *   If data construction fails or bitmap is not found, the function
        *   leaves with an error code.
        */
        IMPORT_C static void CreateIconL(
            MAknsSkinInstance* aInstance, const TAknsItemID& aID,
            CFbsBitmap*& aBitmap, CFbsBitmap*& aMask,
            const TDesC& aFilename,
            const TInt aFileBitmapId, const TInt aFileMaskId );

        /**
        * Otherwise identical to CreateIconL, but leaves both the bitmaps
        * in the cleanup stack.
        * The order in which they are pushed into the stack and types of 
        * the items in the stack are both undefined.
        *
        * @copydoc AknsUtils::CreateIconL(MAknsSkinInstance*,TAknsItemID&,CFbsBitmap*&,CFbsBitmap*&,const TDesC&,const TInt,const TInt)
        *
        * @par Note:
        *   Since both the bitmaps are left in the cleanup stack,
        *   call to this method can not be enclosed in an immediate TRAP.
        */
        IMPORT_C static void CreateIconLC(
            MAknsSkinInstance* aInstance, const TAknsItemID& aID,
            CFbsBitmap*& aBitmap, CFbsBitmap*& aMask,
            const TDesC& aFilename,
            const TInt aFileBitmapId, const TInt aFileMaskId );

        /**
        * Constructs an independent non-masked bitmap with fallback support.
        * Creates an independent (in terms of instance ownership) copy of a 
        * non-masked bitmap by the given item ID.
        *
        * If no matching item is found in the currently activate skin,
        * attempts to construct the item using the given file.
        *
        * @since 2.6
        *
        * @lib AknSkins.lib
        *
        * @param aInstance Pointer to the current skin instance.
        *   Usually retrieved using @c AknsUtils::SkinInstance.
        *
        * @param aID Item ID of the non-masked bitmap to be created.
        *
        * @param aBitmap If method succeeds, set to point to the
        *   newly constructed bitmap. Ownership of the bitmap is transferred 
        *   to the caller.
        *
        * @param aFilename Filename to be used to construct the item, 
        *   if no matching item was found in the currently active skin.
        *
        * @param aFileBitmapId ID of the bitmap in the file. 
        *   Used only if no matching item was found in the currently 
        *   active skin.
        *
        * @par Exceptions:
        *   If data construction fails or bitmap is not found, the function
        *   leaves with an error code.
        */
        IMPORT_C static void CreateIconL(
            MAknsSkinInstance* aInstance, const TAknsItemID& aID,
            CFbsBitmap*& aBitmap,
            const TDesC& aFilename,
            const TInt aFileBitmapId );

        /**
        * Otherwise identical to CreateIconL, but leaves the bitmap
        * in the cleanup stack.
        * The type of the item pushed into the stack is undefined.
        *
        * @copydoc AknsUtils::CreateIconL(MAknsSkinInstance*,TAknsItemID&,CFbsBitmap*&,const TDesC&,const TInt)
        *
        * @par Note:
        *   Since the bitmap is left in the cleanup stack,
        *   call to this method can not be enclosed in an immediate TRAP.
        */
        IMPORT_C static void CreateIconLC(
            MAknsSkinInstance* aInstance, const TAknsItemID& aID,
            CFbsBitmap*& aBitmap,
            const TDesC& aFilename,
            const TInt aFileBitmapId );

        /**
        * Constructs an independent masked bitmap with fallback support.
        * Creates an independent (in terms of instance ownership) copy of a 
        * masked bitmap by the given item ID.
        *
        * If no matching item is found in the currently activate skin,
        * attempts to construct the item using the given file.
        *
        * @since 2.6
        *
        * @lib AknSkins.lib
        *
        * @param aInstance Pointer to the current skin instance.
        *
        * @param aID Item ID of the masked bitmap to be created.
        *
        * @param aFilename Filename to be used to construct the item, 
        *   if no matching item was found in the currently active skin.
        *
        * @param aFileIndex Index (for bitmap) in the file. 
        *   Used only if no matching item was found in the currently 
        *   active skin.
        *
        * @param aFileMaskIndex Index (for mask) in the file.
        *   Used only if no matching item was found in the currently 
        *   active skin.
        *
        * @return Pointer to the newly created CApaMaskedBitmap object.
        *   Ownership of the object is transferred to the caller.
        *
        * @par Exceptions:
        *   If data construction fails or bitmap is not found, the function
        *   leaves with an error code.
        *
        * @par Note:
        *   Since @c CApaMaskedBitmap can not be used to store scalable
        *   graphics, consider using @c CreateIconLC instead.
        */
        IMPORT_C static CApaMaskedBitmap* CreateMaskedBitmapL(
            MAknsSkinInstance* aInstance, const TAknsItemID& aID,
            const TDesC& aFilename,
            const TInt aFileIndex, const TInt aFileMaskIndex );

        /**
        * Constructs an independent CGulIcon object with fallback support.
        * Creates an independent (in terms of instance ownership) copy of a
        * masked bitmap by the given item ID, and returns it as a
        * newly constructed CGulIcon object.
        *
        * If no matching item is found in the currently active skin,
        * attempts to construct the item using the given file.
        *
        * @since 2.6
        *
        * @lib AknSkins.lib
        *
        * @param aInstance Pointer to the current skin instance.
        *
        * @param aID Item ID of the masked bitmap to be created.
        *
        * @param aFilename Filename to be used to construct the item, 
        *   if no matching item was found in the currently active skin.
        *
        * @param aFileIndex Index (for bitmap) in the file. 
        *   Used only if no matching item was found in the currently 
        *   active skin.
        *
        * @param aFileMaskIndex Index (for mask) in the file.
        *   Used only if no matching item was found in the currently 
        *   active skin.
        *
        * @return Pointer to the newly created CGulIcon object.
        *   Ownership of the object is transferred to the caller.
        *
        * @par Exceptions:
        *   If data construction fails or bitmap is not found, the function
        *   leaves with an error code.
        */
        IMPORT_C static CGulIcon* CreateGulIconL(
            MAknsSkinInstance* aInstance, const TAknsItemID& aID,
            const TDesC& aFilename,
            const TInt aFileIndex, const TInt aFileMaskIndex );

        /**
        * Constructs an application icon supporting scalable graphics.
        *
        * This method is fallback-enabled. If no icon is found in the 
        * currently active skin, the application icon is retrieved using
        * application resource file or AIF.
        *
        * After successful completion, the method leaves both the bitmaps
        * in the cleanup stack.
        * The order in which they are pushed into the stack and types of 
        * the items in the stack are both undefined.
        *
        * The caller must set the size of the returned bitmaps. 
        * See @c AknIconUtils for details.
        *
        * @par Note:
        *   Since both the bitmaps are left in the cleanup stack,
        *   call to this method can not be enclosed in an immediate TRAP. 
        *
        * @since 2.8
        *
        * @lib AknSkins.lib
        *
        * @param aInstance Pointer to current skin instance.
        *
        * @param aAppUid Application UID. Icon is searched with major IID
        *   ::EAknsIIDMajorAppIcon and minor IID aAppUid.
        * 
        * @param aType Type of the application icon (list or context).
        *   This parameter is tentative. If no icon of the given type
        *   is found, the other icon is returned. Only the following values
        *   are allowed: EAknsAppIconTypeList and EAknsAppIconTypeContext.
        *
        * @param aBitmap If method succeeds, set to point to the
        *   newly constructed bitmap. Ownership of the bitmap is transferred 
        *   to the caller.
        *
        * @param aMask If method succeeds, set to point to the newly
        *   constructed mask bitmap. Ownership of the bitmap is transferred
        *   to the caller.
        *
        * @par Exceptions:
        *   If the method fails, it leaves with a standard error code.
        */
        IMPORT_C static void CreateAppIconLC(
            MAknsSkinInstance* aInstance, TUid aAppUid,
            TAknsAppIconType aType,
            CFbsBitmap*& aBitmap, CFbsBitmap*& aMask );

        /**
        * Opens the file containing application icon data.
        *
        * This method first checks whether there is a data file of the given
        * type associated with the application icon of the given UID. If no 
        * file is found, an error code is returned and the caller should use 
        * @c CreateAppIconLC to construct the icon. Otherwise, one of the 
        * associated files is opened using the given @c RFile object.
        *
        * @since 3.0
        *
        * @lib AknSkins.lib
        *
        * @param aInstance Pointer to current skin instance.
        *
        * @param aAppUid Application UID. Icon is searched with major IID
        *   ::EAknsIIDMajorAppIcon and minor IID aAppUid.
        *
        * @param aType Only EAknsAppIconType3D is allowed.
        *
        * @param aFile Reference to a @c RFile. If @c KErrNone is returned,
        *   this handle refers to an open file containing the data.
        *   If an error code is returned, the file is not opened.
        *
        * @return @c KErrNone if a file was opened, an error code otherwise.
        */
        IMPORT_C TInt OpenAppIconFile(
            MAknsSkinInstance* aInstance, TUid aAppUid,
            TAknsAppIconType aType, RFile& aFile );

        /**
        * Constructs an independent masked color-customized icon with 
        * fallback support without setting its size.
        *
        * Creates an independent (in terms of instance ownership) copy of a 
        * masked bitmap by the given item ID and applies color-based
        * skinning to it.
        *
        * This method:
        *  - Creates a masked bitmap item from skin, or from the given
        *    MBM or MIF file if no matching item is found in the active skin.
        *  - If the icon can be color-skinned, applies the color retrieved
        *    from the given color table and index. If no color information
        *    is found in the active skin, uses the given fallback color value.
        *  - Returns the resulting bitmaps. If no color skinning was applied,
        *    returns the original bitmaps.
        *
        * The method fails only, if the masked bitmap can not be constructed
        * at all. If the icon can not be color-skinned, it is returned as-is.
        *
        * @since 2.6
        *
        * @lib AknSkins.lib
        *
        * @param aInstance Pointer to the current skin instance.
        *   Usually retrieved using @c AknsUtils::SkinInstance.
        *
        * @param aID Item ID of the masked bitmap to be created.
        *
        * @param aColorID Item ID of the color table.
        *
        * @param aColorIndex Index in the color table.
        *
        * @param aBitmap If method succeeds, set to point to the
        *   newly constructed bitmap. Ownership of the bitmap is transferred 
        *   to the caller.
        *
        * @param aMask If method succeeds, set to point to the newly
        *   constructed mask bitmap. Ownership of the bitmap is transferred
        *   to the caller.
        *
        * @param aFilename Filename to be used to construct the item, 
        *   if no matching item was found in the currently active skin.
        *
        * @param aFileBitmapId ID of the bitmap in the file. 
        *   Used only if no matching item was found in the currently 
        *   active skin.
        *
        * @param aFileMaskId ID of the mask in the file.
        *   Used only if no matching item was found in the currently
        *   active skin.
        *
        * @param aDefaultColor Color RGB value to be used, if no color
        *   is found in the currently active skin.
        *
        * @par Exceptions:
        *   If data construction fails or bitmap is not found, the function
        *   leaves with an error code.
        */
        IMPORT_C static void CreateColorIconL(
            MAknsSkinInstance* aInstance, const TAknsItemID& aID,
            const TAknsItemID& aColorID, const TInt aColorIndex,
            CFbsBitmap*& aBitmap, CFbsBitmap*& aMask,
            const TDesC& aFilename,
            const TInt aFileBitmapId, const TInt aFileMaskId,
            const TRgb aDefaultColor );

        /**
        * Otherwise identical to @c CreateColorIconL, but leaves both the 
        * bitmap and the mask in the cleanup stack. 
        * The order in which they are pushed into the stack and types of 
        * the items in the stack are both undefined.
        *
        * @since 2.6
        *
        * @lib AknSkins.lib
        *
        * @par Note:
        *   Since two bitmaps are left in the cleanup stack,
        *   call to this method can not be enclosed in an immediate TRAP.
        */
        IMPORT_C static void CreateColorIconLC(
            MAknsSkinInstance* aInstance, const TAknsItemID& aID,
            const TAknsItemID& aColorID, const TInt aColorIndex,
            CFbsBitmap*& aBitmap, CFbsBitmap*& aMask,
            const TDesC& aFilename,
            const TInt aFileBitmapId, const TInt aFileMaskId,
            const TRgb aDefaultColor );

        /**
        * Otherwise identical to @c CreateColorIconL without size parameters,
        * but calls @c SetSize to set the size of the resulting icon.
        *
        * @since 2.8
        *
        * @lib AknSkins.lib
        */
        IMPORT_C static void CreateColorIconL(
            MAknsSkinInstance* aInstance, const TAknsItemID& aID,
            const TAknsItemID& aColorID, const TInt aColorIndex,
            CFbsBitmap*& aBitmap, CFbsBitmap*& aMask,
            const TDesC& aFilename,
            const TInt aFileBitmapId, const TInt aFileMaskId,
            const TRgb aDefaultColor,
            const TSize& aSize, const TScaleMode aScaleMode );

        /**
        * Otherwise identical to @c CreateColorIconL, but leaves both the 
        * bitmap and the mask in the cleanup stack. 
        * The order in which they are pushed into the stack and types of 
        * the items in the stack are both undefined.
        *
        * @since 2.8
        *
        * @lib AknSkins.lib
        *
        * @par Note:
        *   Since two bitmaps are left in the cleanup stack,
        *   call to this method can not be enclosed in an immediate TRAP.
        */
        IMPORT_C static void CreateColorIconLC(
            MAknsSkinInstance* aInstance, const TAknsItemID& aID,
            const TAknsItemID& aColorID, const TInt aColorIndex,
            CFbsBitmap*& aBitmap, CFbsBitmap*& aMask,
            const TDesC& aFilename,
            const TInt aFileBitmapId, const TInt aFileMaskId,
            const TRgb aDefaultColor,
            const TSize& aSize, const TScaleMode aScaleMode );

    public: // New functions - Item access w/o support for scalable graphics

        /**
        * Constructs an application icon. Icon bitmaps are duplicated to the 
        * given CApaMaskedBitmap object.
        *
        * Since Series 60 Release 2.6, this method is fallback-enabled.
        * If no icon is found in the currently active skin, it uses
        * AppArch to construct the icon.
        *
        * @since 2.0
        *
        * @param aInstance Pointer to current skin instance.
        *
        * @param aAppUid Application UID. Icon is searched with major IID
        *   ::EAknsIIDMajorAppIcon and minor IID aAppUid. AppArch search
        *   is always performed with UID only.
        *
        * @param aSize Maximum size of the icon.
        *
        * @param aAppBitmap On return contains the icon.
        *
        * @return KErrNone if succeeded, KErrNotFound if no icon was found
        *   or size requirements were not met, other error code if
        *   another error occured.
        *
        * @par Note:
        *   This method does not support scalable graphics.
        *   Consider using @c CreateAppIconLC instead.
        */
        IMPORT_C static TInt GetAppIcon(
            MAknsSkinInstance* aInstance, TUid aAppUid, TSize aSize, 
            CApaMaskedBitmap& aAppBitmap );

    public: // New functions - Item access w/ ownership

        /**
        * Constructs an independent bitmap.
        * Creates an independent copy of bitmap (in terms of instance ownership)
        * by given item ID.
        *
        * @since 2.0
        *
        * @param aInstance Pointer to current skin instance.
        *
        * @param aID Item ID of the bitmap to be created.
        *
        * @return Pointer to the newly created bitmap. Ownership of the object
        *   is transferred to the caller.
        *
        * @par Exceptions:
        *   - If data construction fails or bitmap is not found, function
        *     leaves with an error code.
        */
        IMPORT_C static CFbsBitmap* CreateBitmapL( 
            MAknsSkinInstance* aInstance, const TAknsItemID& aID );

        /**
        * Constructs an independent masked bitmap.
        * Creates an independent (in terms of instance ownership) copy of a 
        * masked bitmap by the given item ID.
        *
        * Alternatively, masked bitmaps can be retrieved by using
        * @c MAknsSkinInstance::GetCachedItemData(TAknsItemID,TAknsItemType)
        * or
        * @c MAknsSkinInstance::CreateUncachedItemDataL(TAknsItemID,TAknsItemType)
        * methods. For these, @c ::EAknsITMaskedBitmap should be given as the
        * second parameter. Returned @c CAknsItemData pointer can be casted
        * to a @c CAknsMaskedBitmapItemData pointer in order to get access
        * to the bitmap objects themselves.
        *
        * @par Note:
        *   This method does not have fallback support (to load the bitmap from
        *   the specified file in case it is not available in the current 
        *   skin). Consider using one of the fallback-enabled overloads 
        *   instead.
        *
        * @since 2.0
        *
        * @param aInstance Pointer to the current skin instance.
        *
        * @param aID Item ID of the masked bitmap to be created.
        *
        * @return Pointer to the newly created CApaMaskedBitmap object.
        *   Ownership of the object is transferred to the caller.
        *
        * @par Exceptions:
        *   If data construction fails or bitmap is not found, the function
        *   leaves with an error code.
        *
        * @par Note:
        *   Since @c CApaMaskedBitmap can not be used to store scalable
        *   graphics, consider using @c CreateIconLC instead.
        */
        IMPORT_C static CApaMaskedBitmap* CreateMaskedBitmapL(
            MAknsSkinInstance* aInstance, const TAknsItemID& aID );

        /**
        * Constructs an independent CGulIcon object.
        * Creates an independent (in terms of instance ownership) copy of a
        * bitmap or a masked bitmap by the given item ID, and returns it as a
        * newly constructed CGulIcon object.
        *
        * @par Note:
        *   This method does not have fallback support (to load the bitmap from
        *   the specified file in case it is not available in the current 
        *   skin). Consider using one of the fallback-enabled overloads 
        *   instead.
        *
        * @since 2.1
        *
        * @lib AknSkins.lib
        *
        * @param aInstance Pointer to the current skin instance.
        *
        * @param aID Item ID of the bitmap or masked bitmap to be created.
        *
        * @param aRequireMask ETrue if masked bitmap is explicitly required.
        *   EFalse if mask is optional.
        *
        * @return Pointer to the newly created CGulIcon object.
        *   Ownership of the object is transferred to the caller.
        *
        * @par Exceptions:
        *   If data construction fails or bitmap is not found, the function
        *   leaves with an error code.
        */
        IMPORT_C static CGulIcon* CreateGulIconL(
            MAknsSkinInstance* aInstance, const TAknsItemID& aID,
            const TBool aRequireMask );

    public: // New functions - Item access w/o ownership

        /**
        * Returns pointer to a cached bitmap.
        * Retrieves (and constructs if necessary) a bitmap in skin instance
        * cache. Caller can use the bitmap temporarily (e.g. in drawing code),
        * but should not store pointer to it, since its lifetime is determined
        * by cache.
        *
        * @since 2.0
        *
        * @param aInstance Pointer to current skin instance. If @c NULL value
        *   is specified, method immediately returns with @c NULL return value.
        *
        * @param aID Item ID of the bitmap to be retrieved.
        *
        * @return Pointer to the bitmap, or @c NULL if no bitmap with given ID
        *   was found or an error occured.
        *
        * @par Exceptions:
        *   - Because the method can not leave, error handling procedure
        *     described in 
        *     MAknsSkinInstance::GetCachedItemData(const TAknsItemID& aID) is 
        *     used if data construction fails.
        */
        IMPORT_C static CFbsBitmap* GetCachedBitmap( 
            MAknsSkinInstance* aInstance, const TAknsItemID& aID );

        /**
        * Retrieves temporary pointers to a cached bitmap and its mask.
        * Retrieves (and constructs, if necessary) a masked bitmap in the skin
        * instance cache. Pointers to the bitmap (and its mask) are stored
        * to the pointers given as parameters. Caller can use the bitmaps
        * temporarily (e.g. in drawing code), but should not store them, since
        * their lifetimes are determined by the cache.
        *
        * @since 2.1
        *
        * @param aInstance Pointer to the current skin instance. If @c NULL
        *   value is specified, the method assigns @c NULL to both the given
        *   pointers and then returns.
        *
        * @param aID Item ID of the bitmap (or masked bitmap) to be retrieved.
        *
        * @param aBitmap Reference to the pointer that will receive the bitmap.
        *   @c NULL value is assigned if no bitmap with the given ID was found
        *   or an error occured.
        *
        * @param aMask Reference to the pointer that will receive the mask.
        *   @c NULL value is assigned if no bitmap with the given ID was found,
        *   or the bitmap did not have a mask, or an error occured.
        *
        * @par Exceptions:
        *   - Because the method can not leave, error handling procedure
        *     described in 
        *     MAknsSkinInstance::GetCachedItemData(const TAknsItemID& aID) is 
        *     used if data construction fails.
        */
        IMPORT_C static void GetCachedMaskedBitmap(
            MAknsSkinInstance* aInstance, const TAknsItemID& aID,
            CFbsBitmap*& aBitmap, CFbsBitmap*& aMask );

        /**
        * Returns a color value from a cached color table.
        * Retrieves (and constructs if necessary) a color table in
        * skin instance cache and returns a color value from it.
        *
        * Since release 2.8, this method also handles any backward 
        * compatibility operations possibly required.
        *
        * @since 2.0
        *
        * @param aInstance Pointer to current skin instance. If @c NULL value
        *   is specified, returns KErrNotSupported.
        *
        * @param aRgb Reference to a TRgb that will receive the color.
        *
        * @param aID Item ID of the color table.
        *
        * @param aIndex Index of the color in the color table.
        *
        * @return KErrNone if successful, otherwise an error code is returned.
        */
        IMPORT_C static TInt GetCachedColor(
            MAknsSkinInstance* aInstance, TRgb& aRgb, const TAknsItemID& aID,
            const TInt aIndex );

        /**
        * Retrieves the value of the given boolean property skin item.
        *
        * @since 2.8
        *
        * @param aInstance Pointer to current skin instance. If @c NULL value
        *   is specified, the method leaves.
        *
        * @param aID Item ID of the boolean property.
        *
        * @return Value of the boolean property as @c TBool.
        *
        * @par Exceptions:
        *   - If the item is not found, leaves with @c KErrNotFound.
        *   - If the item is not a boolean property or another error occures,
        *       leaves with a system-wide error code.
        */
        IMPORT_C static TBool BooleanPropertyL( MAknsSkinInstance* aInstance, 
            const TAknsItemID& aID );

        /**
        * Test whether the given type is derived from the given base type.
        *
        * @since 2.0
        *
        * @param aBaseType Base type.
        *
        * @param aDerivedType Derived type.
        *
        * @return ETrue if the type is derived from the base type, EFalse
        *   otherwise.
        *
        * @internal
        */
        static TBool IsDerivedType( const TAknsItemType aBaseType, 
            const TAknsItemType aDerivedType );

    public: // New functions - Avkon parameters

        /**
        * Sets the flag indicating whether default skin parameters should
        * be used for newly created Avkon controls in the scope of the
        * current AppUi. 
        *
        * @since 2.0
        *
        * @param Value of the flag as TBool.
        *
        * @par Exceptions:
        *   If construction of the storage object for the flag fails,
        *   leaves with an error code.
        */
        IMPORT_C static void SetAvkonSkinEnabledL( const TBool aEnabled );

        /**
        * Queries whether default skin parameters should be used for newly
        * created Avkon controls. Components supporting 
        * <code>SetSkinEnabledL</code> method should also check for this
        * value upon construction and set their internal state accordingly.
        *
        * Note that this flag is intended to be used to determine whether or
        * not controls should create skin backgrounds for main pane
        * layouts. Skins are always enabled for e.g. all the popup windows,
        * even through the flag may be @c EFalse, and therefore the flag 
        * must not be used as a generic "are skins enabled" switch.
        *
        * Most controls do not (and should not) query the flag value. If
        * control just fetches the skin control context with
        * @c AknsDrawUtils::ControlContext, it will get the proper @c NULL
        * value if no background has been defined.
        *
        * @since 2.0
        *
        * @return ETrue if default skin parameters should be used,
        *   EFalse otherwise. The default value is EFalse.
        */
        IMPORT_C static TBool AvkonSkinEnabled();

        /**
        * Sets the flag indicating whether highlight animations should be used
        * for Avkon list controls in the scope of the current AppUi.
        *
        * @since 3.0
        *
        * @param Value of the flag as TBool.
        *
        * @par Exceptions:
        *   If construction of the storage object for the flag fails,
        *   leaves with an error code.
        */
        IMPORT_C static void SetAvkonHighlightAnimationEnabledL( const TBool aEnabled );

        /**
        * Queries whether highlight animation should be used for newly created
        * Avkon list controls.
        *
        * @since 3.0
        *
        * @return ETrue if list highlight animation should be used, EFalse
        *         otherwise. The default value is ETrue.
        */
        IMPORT_C static TBool AvkonHighlightAnimationEnabled();

    public: // New functions - Control position list

        /**
        * Registers the position of the given control.
        * The position is stored in the thread-local control position list.
        * If the control has already been registered, its position is updated.
        *
        * Registering the position of the control enables background drawing
        * methods in AknsDrawUtils to calculate positions in
        * parent-absolute layouts without causing window server flushes.
        *
        * When a registered control goes out of scope, it must call
        * AknsUtils::DeregisterControlPosition to ensure that it is properly
        * removed from the list.
        *
        * @since 2.0
        *
        * @param aControl Pointer to the control that needs its position
        *   to be updated in the control position list.
        */
        IMPORT_C static void RegisterControlPosition( 
            const CCoeControl* aControl );

        /**
        * Registers the position of the given control with given position.
        * The position is stored in the thread-local control position list.
        * If the control has already been registered, its position is updated.
        *
        * Registering the position of the control enables background drawing
        * methods in AknsDrawUtils to calculate positions in
        * parent-absolute layouts without causing window server flushes.
        *
        * When a registered control goes out of scope, it must call
        * AknsUtils::DeregisterControlPosition to ensure that it is properly
        * removed from the list.
        *
        * @since 2.0
        *
        * @param aControl Pointer to the control that needs its position
        *   to be updated in the control position list.
        *
        * @param aPoint The new position to be registered with the given
        *   control (in screen coordinates).
        */
        IMPORT_C static void RegisterControlPosition( 
            const CCoeControl* aControl, const TPoint& aPoint );

        /**
        * Removes the position of the given control from the list.
        * The position of the given control is removed from the thread-local
        * control position list. If the control has not been registered,
        * this method does nothing.
        *
        * @since 2.0
        *
        * @param aControl Pointer to the control that needs to be removed
        *   from the control position list.
        */
        IMPORT_C static void DeregisterControlPosition( 
            const CCoeControl* aControl );

        /**
        * Gets the position of the control registered in the control position
        * list.
        *
        * @param aControl Pointer to the control whose position is to be 
        *   queried.
        *
        * @param aScreenPos Reference to the TPoint that will receive the
        *   position.
        *
        * @return KErrNone if successful, KErrNotFound if the control has
        *   not been registered.
        */
        IMPORT_C static TInt GetControlPosition( const CCoeControl* aControl,
            TPoint& aScreenPos );

    private: // Internal methods

        /**
        * Gets an application icon from skin.
        *
        * @since 2.8
        *
        * @internal
        */
        static TInt GetAppIconFromSkin(
            MAknsSkinInstance* aInstance, TUid aAppUid, TSize aSize, 
            CFbsBitmap*& aBitmap, CFbsBitmap*& aMask );

        /** 
        * Returns the best application icon bitmap IID among the listed icons.
        *
        * @since 2.1
        *
        * @param aSize Maximum size.
        *
        * @param aSkin Skin instance.
        *
        * @param aAppIconIID Item ID of the application icon.
        *
        * @return Icon bitmap IID.
        *
        * @internal
        */
        static TAknsItemID SelectBestAppIconBitmapL(
            const TSize& aSize, MAknsSkinInstance* aSkin,
            const TAknsItemID& aAppIconIID );

    private: // Reserved exports

        /**
        * Reserved for future use.
        *
        * @since 2.0
        *
        * @return Always returns zero.
        */
        IMPORT_C static TInt Reserved();

    private: // Prohibited constructors and destructor
        
        // Construction prohibited (static class)
        AknsUtils();
        // Destruction prohibited (static class)
        ~AknsUtils();
    };

#endif      // AKNSUTILS_H   
            
// End of File
