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
* Description:   Utility functions related to scalable icons.
*
*/




#ifndef AKN_ICON_UTILS_H
#define AKN_ICON_UTILS_H

// INCLUDES
#include <e32std.h>
#include <gdi.h>

// FORWARD DECLARATIONS
class CFbsBitmap;
class MAknIconObserver;

// ENUMERATIONS
enum TScaleMode
    {
    /*
    * Scales the icon to the maximum size that fits in the given size,
    * whilst preserving the aspect ratio of the icon. The sizes of the resulting
    * bitmaps are exactly of the given size. If the aspect ratio of
    * the given size differs from the aspect ratio of the icon,
    * the resulting bitmaps will contain an unused area.
    */
    EAspectRatioPreserved = 0,

    /*
    * Scales the icon to the maximum size that fits in the given size,
    * whilst preserving the aspect ratio of the icon. The resulting bitmaps
    * are resized so that any unused portion of the given size is not
    * present in them.
    *
    * This mode should be used when only the height or the width of the icon
    * is known and the other should be based on the aspect ratio of the icon.
    * The unknown dimension should be defined high enough (e.g. KMaxTInt) so
    * that it does not limit the scaling based on the aspect ratio of the icon.
    */
    EAspectRatioPreservedAndUnusedSpaceRemoved = 1,

    /*
    * Scales the icon exactly to the given size. Does not preserve the aspect
    * ratio of the icon.
    */
    EAspectRatioNotPreserved = 2,
        
    /*
    * Scales the icon to the minimum size that covers the given size,
    * whilst preserving the aspect ratio of the icon. The sizes of the resulting
    * bitmaps are exactly of the given size. If the aspect ratio of
    * the given size differs from the aspect ratio of the icon, some parts of the 
    * icon will be sliced from the resulting bitmaps.
    *
    * @since 3.1
    */
    EAspectRatioPreservedSlice = 3
    };

// CLASS DECLARATIONS

/**
* Class for storing the content dimensions of icons.
*/
class TAknContentDimensions
	{
	public:

        /**
         * C++ default constructor.
         */
        inline TAknContentDimensions();	

        /**
         * Constructor.
         *
         * @param aWidth Icons width.
         * @param aHeight Icons height.
         */
        inline TAknContentDimensions(TReal32 aWidth, TReal32 aHeight);

        /**
         * Sets the content dimensions.
         *
         * @param aWidth Width of the icon.
         * @param aHeight Height of the icon.
         */
        inline void SetDimensions(TReal32 aWidth, TReal32 aHeight);	
 
        /**
         * Sets the content size of the icon.
         *
         * @param aDimensions Two-dimensional size as a width and a height 
                              value of the icon.
         */
        inline void SetDimensions(const TSize& aDimensions);	

	public:
    
        /** Icons width. */
        TReal32 iWidth;

        /** Icons height. */
		TReal32 iHeight;
	};

/**
 * Cleanup stack helper. Owns the bitmap and the mask.
 */
NONSHARABLE_CLASS(CAknIcon) : public CBase
    {
    public:
    
        /**
         * Two-phased constructor.
         *
         * Creates and returns a pointer to a new @c CAknIcon object.
         *
         * @return New @c CAknIcon.
         */
        IMPORT_C static CAknIcon* NewL();
    
        /**
         * Destructor.
         */
        ~CAknIcon();
    
    public:
    
        /**
         * Gets the bitmap.
         *
         * @return The icon's bitmap.
         */
        IMPORT_C CFbsBitmap* Bitmap() const;
    
        /**
         * Gets the mask.
         *
         * @return The icon's mask.
         */    
        IMPORT_C CFbsBitmap* Mask() const;
    
        /**
         * Sets the bitmap.
         *
         * @param aBitmap The icon's bitmap.
         */    
        IMPORT_C void SetBitmap( CFbsBitmap* aBitmap );
    
        /**
         * Sets the mask.
         *
         * @param aMask The icon's mask.
         */    
        IMPORT_C void SetMask( CFbsBitmap* aMask );
    
    private:
    
        /**
         * Default constructor.
         */
        inline CAknIcon() {}

    private:
    
        CFbsBitmap* iBitmap; // owned
        CFbsBitmap* iMask; // owned
    };

/**
* The purpose of this class is for clients to provide opened file handles
* to icon files, which reside in private directories,
* where AknIcon server has no access.
*
* MIF file is always generated, when building icons with MifConv tool.
* The corresponding MBM file is generated only if there are bitmap icons
* amongst the source icons.
*
*/
class MAknIconFileProvider
    {
    public:

        enum TIconFileType
            {
            EMbmFile = 0,
            EMifFile = 1
            };

    public:

        /**
        * Destructor.
        */
        virtual ~MAknIconFileProvider() {}

        /**
        * Returns an open file handle to the icon file.
        * This method should leave if an icon file with specified type does
        * not exist. That may be the case e.g. with MBM file,
        * if there are no bitmap icons.
        *
        * Note! RFs::ShareProtected must be called to the RFs instance used
        * for opening the file.
        *
        * @param aFile Icon file should be opened in this file handle, which
        * is an empty file handle, when the AknIcon framework calls this method.
        * The AknIcon framework takes care of closing the file handle after
        * having used it.
        * @param aType Icon file type.
        */
        virtual void RetrieveIconFileHandleL(
            RFile& aFile, const TIconFileType aType ) = 0;

        /**
        * With this method, AknIcon framework informs that it does not use
        * this MAknIconFileProvider instance any more. After this call,
        * it is ok to delete the object. This can be implemented simply
        * e.g. by deleting self in this callback.
        * Normally, this callback is invoked when the icon in question
        * is deleted.
        * Note, however, that if the same MAknIconFileProvider instance is
        * supplied in multiple CreateIcon calls, then it must be accessible
        * by AknIcon framework until it has signalled a matching amount
        * of these callbacks.
        */
        virtual void Finished() = 0;
    };

/**
* AknIconUtils
*
* Note: The CFbsBitmap objects for bitmaps and mask returned by this class
* may be compressed in background. 
* Client code directly accessing the bitmap pixel data should not
* assume that the bitmap and mask objects are not compressed. 
*
* Bitmap compression can be disabled for an icon if desired using
* AknIconUtils::DisableCompression().
*/
class AknIconUtils
    {
    public:

        /**
        * Creates bitmap and mask for an icon.
        * Allocates bitmap and mask objects and sets aBitmap and
        * aMask to point at them. Ownership of those is transferred to the caller.
        * These bitmaps are not ready for drawing until they are initialized with
        * SetSize method. Usually, UI controls do this.
        *
        * Use this method only if aBitmap and aMask are member variables.
        * Otherwise, use method CreateIconLC.
        *
        * @since 2.8
        * @param aBitmap icon bitmap is stored here
        * @param aMask icon mask is stored here
        * @param aFileName File name. Can be either MBM or MIF file.
        * Extension is changed based on the given bitmap ID.
        * @param aBitmapId bitmap Id
        * @param aMaskId mask Id
        */
        IMPORT_C static void CreateIconL(
            CFbsBitmap*& aBitmap,
            CFbsBitmap*& aMask,
            const TDesC& aFileName,
            TInt aBitmapId,
            TInt aMaskId );

        /**
        * Creates bitmap and mask for an icon.
        * Allocates bitmap and mask objects and sets aBitmap and
        * aMask to point at them. Ownership of those is transferred to the caller.
        * These bitmaps are not ready for drawing until they are initialized with
        * SetSize method. Usually, UI controls do this.
        *
        * This method puts both aBitmap and aMask in the cleanup stack.
        *
        * @since 2.8
        * @param aBitmap icon bitmap is stored here
        * @param aMask icon mask is stored here
        * @param aFileName File name. Can be either MBM or MIF file.
        * Extension is changed based on the given bitmap ID.
        * @param aBitmapId bitmap ID
        * @param aMaskId mask ID
        */
        IMPORT_C static void CreateIconLC(
            CFbsBitmap*& aBitmap,
            CFbsBitmap*& aMask,
            const TDesC& aFileName,
            TInt aBitmapId,
            TInt aMaskId );

        /**
        * Creates the bitmap for an icon.
        * Use this variant when a mask is not needed.
        * Ownership of the returned object is transferred to the caller.
        * The bitmap is not ready for drawing until it is initialized with
        * SetSize method. Usually, UI controls do this.
        *
        * @since 2.8
        * @param aBitmap icon bitmap is stored here
        * @param aFileName File name. Can be either MBM or MIF file.
        * Extension is changed based on the given bitmap ID.
        * @param aBitmapId bitmap ID
        */
        IMPORT_C static CFbsBitmap* CreateIconL(
            const TDesC& aFileName,
            TInt aBitmapId );

        /**
        * Creates bitmap and mask for an icon.
        * Allocates bitmap and mask objects and sets aBitmap and
        * aMask to point at them. Ownership of those is transferred to the caller.
        * These bitmaps are not ready for drawing until they are initialized with
        * SetSize method. Usually, UI controls do this.
        *
        * If this method leaves, MAknIconFileProvider::Finished is called for the
        * supplied aFileProvider.
        *
        * Use this method only if aBitmap and aMask are member variables.
        * Otherwise, use method CreateIconLC.
        *
        * @since 3.0
        * @param aBitmap icon bitmap is stored here
        * @param aMask icon mask is stored here
        * @param aFileProvider Icon file handle provider.
        * @param aBitmapId bitmap Id
        * @param aMaskId mask Id
        */
        IMPORT_C static void CreateIconL(
            CFbsBitmap*& aBitmap,
            CFbsBitmap*& aMask,
            MAknIconFileProvider& aFileProvider,
            TInt aBitmapId,
            TInt aMaskId );

        /**
        * Creates bitmap and mask for an icon.
        * Allocates bitmap and mask objects and sets aBitmap and
        * aMask to point at them. Ownership of those is transferred to the caller.
        * These bitmaps are not ready for drawing until they are initialized with
        * SetSize method. Usually, UI controls do this.
        *
        * This method puts both aBitmap and aMask in the cleanup stack.
        *
        * If this method leaves, MAknIconFileProvider::Finished is called for the
        * supplied aFileProvider.
        *
        * @since 3.0
        * @param aBitmap icon bitmap is stored here
        * @param aMask icon mask is stored here
        * @param aFileProvider Icon file handle provider.
        * @param aBitmapId bitmap Id
        * @param aMaskId mask Id
        */
        IMPORT_C static void CreateIconLC(
            CFbsBitmap*& aBitmap,
            CFbsBitmap*& aMask,
            MAknIconFileProvider& aFileProvider,
            TInt aBitmapId,
            TInt aMaskId );

        /**
        * Creates the bitmap for an icon.
        * Use this variant when a mask is not needed.
        * Ownership of the returned object is transferred to the caller.
        * The bitmap is not ready for drawing until it is initialized with
        * SetSize method. Usually, UI controls do this.
        *
        * If this method leaves, MAknIconFileProvider::Finished is called for the
        * supplied aFileProvider.
        *
        * @since 3.0
        * @param aFileProvider Icon file handle provider.
        * @param aBitmapId bitmap ID
        * @return The icon bitmap.
        */
        IMPORT_C static CFbsBitmap* CreateIconL(
            MAknIconFileProvider& aFileProvider,
            TInt aBitmapId );

        /**
        * Preserves the icon data (e.g. SVG-T data) related to the given icon
        * in memory. After this, the icon data is destroyed when either
        * DestroyIconData is explicitly called or the bitmap(s) of the icon are
        * deleted.
        *
        * This method should be called to improve performance if more than one
        * call to methods SetSize, SetSizeAndRotation or GetContentDimensions
        * is made successively on a particular icon. It should be called prior
        * to the above-mentioned calls. Without calling this method,
        * the icon data is destroyed after any of the method calls mentioned
        * above and then loaded from the storage medium and parsed from scratch
        * again in a new operation.
        *
        * Note! Icon data may consume considerable amounts of memory. In order
        * to save memory, any code that calls PreserveIconData should also
        * explicitly call DestroyIconData when the icon data is no longer
        * required.
        *
        * @since 2.8
        * @param aBitmap bitmap or mask of the icon.
        */
        IMPORT_C static void PreserveIconData( CFbsBitmap* aBitmap );

        /**
        * Destroys the icon data related to the given icon,
        * if it was preserved in memory. Note that this does not affect
        * the rendered frame buffers (CFbsBitmap objects).
        *
        * @since 2.8
        * @param aBitmap bitmap or mask of the icon.
        */
        IMPORT_C static void DestroyIconData( CFbsBitmap* aBitmap );

        /**
        * Initializes the icon to the given size, if the parameter aBitmap is
        * an instance of CAknBitmap, i.e. created with AknIconUtils methods.
        * If it is not CAknBitmap, this method does nothing. Note that this call
        * sets the sizes of both bitmap and mask (if it exists), regardless of
        * which is given as the parameter.
        *
        * @since 2.8
        * @param aBitmap bitmap or mask of the icon
        * @param aSize icon size
        * @param aMode scale mode
        * @return Standard Symbian OS error code. In error cases, it is guaranteed
        * that the returned bitmap is a valid CFbsBitmap, but there is no guarantee
        * of its size, except that it is non-negative.
        */
        IMPORT_C static TInt SetSize(
            CFbsBitmap* aBitmap,
            const TSize& aSize,
            TScaleMode aMode = EAspectRatioPreserved );

        /**
        * Initializes the icon to the given size, if the parameter aBitmap is
        * an instance of CAknBitmap, i.e. created with AknIconUtils methods.
        * If it is not CAknBitmap, this method does nothing. Note that this call
        * sets the sizes of both bitmap and mask (if it exists), regardless of
        * which is given as the parameter. Additionally, this method rotates
        * the icon according to the given angle.
        *
        * @since 2.8
        * @param aBitmap bitmap or mask of the icon
        * @param aSize icon size
        * @param aAngle Rotation angle in degrees.
        * @return Standard Symbian OS error code. In error cases, it is guaranteed
        * that the returned bitmap is a valid CFbsBitmap, but there is no guarantee
        * of its size, except that it is non-negative.
        */
        IMPORT_C static TInt SetSizeAndRotation(
            CFbsBitmap* aBitmap,
            const TSize& aSize,
            TScaleMode aMode,
            TInt aAngle );

        /**
        * Sets observer for change notification.
        * 
        * The method BitmapChanged() will be called when the contents of the CFbsBitmap
        * are changed. Controls can use this to redraw themselves when icon
        * animation progresses.
        * 
        * @since 2.8
        * @param aBitmap bitmap
        * @param aObserver observer
        */
        IMPORT_C static void SetObserver( CFbsBitmap* aBitmap, MAknIconObserver* aObserver );

        /**
        * Returns the file name of Avkon's icon file, containing full path.
        *
        * @since 2.8
        * @ret Avkon's icon file name, containing full path.
        */
        IMPORT_C static const TDesC& AvkonIconFileName();

        /**
        * Validates logical app icon ID so that it can be used as a parameter to
        * CreateIconL or CreateIconLC. If the given icon file name is .MBM file,
        * this method does nothing. If it is .MIF file, a predefined offset is
        * added to the given IDs.
        *
        * This method is only intended to be used when loading icons from the
        * icon file retrieved from AppArc.
        *
        * @param aIconFileName Icon file name retrieved from AppArc.
        * @param aId Logical bitmap ID used in the app icon file, usually 0.
        * @param aId Logical mask ID used in the app icon file, usually 1.
        */
        IMPORT_C static void ValidateLogicalAppIconId( 
            const TDesC& aIconFileName,
            TInt& aBitmapId,
            TInt& aMaskId );

        /**
        * Tells whether the given file name is recognized as a MIF file or not.
        * Only the file name extension is examined, not the contents of the file.
        *
        * @since 2.8
        * @param aFileName file name
        *
        * @return ETrue if MIF file, EFalse otherwise.
        */
        IMPORT_C static TBool IsMifFile( const TDesC& aFileName );

        /**
        * Tells whether the given bitmap is a part of a MIF icon or not.
        * Accepts any pointer (also NULL) as a parameter.
        *
        * @since 2.8
        * @param aBitmap bitmap
        *
        * @return ETrue if the given bitmap is part of a MIF icon,
        * EFalse otherwise.
        */
        IMPORT_C static TBool IsMifIcon( const CFbsBitmap* aBitmap );

        /**
        * Returns the content dimensions of the given icon.
        * In case of MBM icons, this is the original size of the bitmap.
        * In case of SVG icons, this is defined in the icon data.
        *
        * If SetSize or SetSizeAndRotation is going to be called on the same
        * icon after this call, the performance can be improved by calling
        * PreserveIconData before calling this method.
        * 
        * @deprecated
        * @since 2.8
        * @param aBitmap bitmap
        * @param aContentDimensions The content dimensions are returned here.
        *
        * @ret Standard Symbian OS error code.
        */
        IMPORT_C static TInt GetContentDimensions(
            CFbsBitmap* aBitmap,
            TSize& aContentDimensions );
            
        /**
        * Returns the content dimensions of the given icon.
        * In case of MBM icons, this is the original size of the bitmap.
        * In case of SVG icons, this is defined in the icon data.
        *
        * If SetSize or SetSizeAndRotation is going to be called on the same
        * icon after this call, the performance can be improved by calling
        * PreserveIconData before calling this method.
        * 
        * @since 3.0
        * @param aBitmap bitmap
        * @param aContentDimensions The content dimensions are returned here.
        *
        * @ret Standard Symbian OS error code.
        */
        IMPORT_C static TInt GetContentDimensions(
            CFbsBitmap* aBitmap,
            TAknContentDimensions& aContentDimensions );
            

        /**
        * Creates bitmap and mask for an icon.
        * Allocates bitmap and mask objects and sets aResultIcon to point at them.
        *
        * When this method returns, the resulting bitmaps are
        * duplicates of the source bitmaps.
        * Also the source bitmap instances are preserved in memory.
        *
        * Ownership of aSourceIcon is transferred from caller.
        * This method takes the responsibility of deleting the object
        * even if the method leaves.
        *
        * The returned icon bitmaps are instances of CAknBitmap,
        * so AknIconUtils::SetSize is functional for them.
        *
        * AknIconUtils::SetSize first creates duplicates of the source bitmaps
        * and after that, if required, creates new bitmaps and performs scaling.
        *
        * Note that due to the additional memory consumption caused by the source bitmaps,
        * this method should only be used if it is not possible to use the variant of
        * CreateIconL that takes icon file name and IDs as parameters.
        *
        * @since 2.8
        *
        * @param aSourceIcon Contains source bitmap and mask.
        *   Ownership of aSourceIcon is transferred from caller.
        *   This method takes the responsibility of deleting the object
        *   even if the method leaves.
        *
        * @ret Resulting icon. Ownership transferred to the caller.
        */
        IMPORT_C static CAknIcon* CreateIconL( CAknIcon* aSourceIcon );

        /**
        * Non-masked variant of CreateIconL.
        *
        * Ownership of aSourceBitmap is transferred from caller.
        * This method takes the responsibility of deleting the object
        * even if the method leaves.
        * 
        * @since 2.8
        * @param aSourceBitmap Source bitmap.
        *   Ownership is transferred from caller.
        *   This method takes the responsibility of deleting the object
        *   even if the method leaves.
        *
        * @ret Resulting icon bitmap. Ownership transferred to the caller.
        */
        IMPORT_C static CFbsBitmap* CreateIconL( CFbsBitmap* aSourceBitmap );

        /**
        * Determines the icon color. Only effective if the given bitmap is
        * an instance of CAknBitmap. This method only needs to be called either
        * for the bitmap or the mask of an icon, but to be effective, it needs
        * to be called before calling SetSize or SetSizeAndRotation.
        *
        * @since 2.8
        * @param aBitmap bitmap
        * @param aColor icon color
        */
        IMPORT_C static void SetIconColor( CFbsBitmap* aBitmap, const TRgb aColor );
        
        
        /**
        * Excludes the icon form the icon cache.
        * Only effective if the given bitmap is an instance of CAknBitmap. This call
        * sets the sizes of both bitmap and mask (if it exists), regardless of
        * which is given as the parameter. 
        * This method should be called after calling CreateIconL or CreateIconLC
        * and before calling AknIconUtils::SetSize.
        * 
        * By default icons are being put to icon cache after they are no longer used. 
        * This makes it possible to retrieve recently used icons fast without the need to
        * render them again.
        * The icon cache has a limited size and when the cache is full to cache new icons
        * the oldest icons from the cache will be removed.
        * In certain situations it might be feasible to exclude some icons from the
        * icon cache (e.g. in case of infrequently used large icons) to prevent some more
        * frequently used icon being kicked out from the cache. Excluding infrequently used
        * icons from icon cache could improve performance and memory usage of the system.
        * 
        * 
        * @since 3.1
        * @param aBitmap bitmap        
        */
        IMPORT_C static void ExcludeFromCache( CFbsBitmap* aBitmap );
        
        /**
        * Disables bitmap compression for the icon.
        * Only effective if the given bitmap is an instance of CAknBitmap. This call
        * prevents AknIcon framework from compressing the CFbsBitmap objects 
        * (bitmap, mask) of the icon.
        * This method should be called after calling CreateIconL or CreateIconLC
        * and before calling AknIconUtils::SetSize.
        * 
        * @since 3.1
        * @param aBitmap bitmap        
        */
        IMPORT_C static void DisableCompression( CFbsBitmap* aBitmap );
        

        /**
        * Performs bitmap scaling. 
        * Draws a source bitmap to fit a given rectangle within a target bitmap. 
        * This is ~15x faster than scaling with Symbian's DrawBitmap. Following
        * bitmap modes are supported: EGray256, EColor4K, EColor64K, EColor256,
        * EColor16MU. For all other bitmap modes, Symbian's DrawBitmap API will
        * be used. Bitmap modes of the source and target bitmap should be the 
        * same.
        * @ since 3.2
        * @ param aTrgRect  target rect inside the target bitmap
        * @ param aTrgBitmap the target bitmap 
        * @ param aSrcBitmap the source bitmap 
        * @leave KErrArgument
        *        If source bitmap mode is not the same as target bitmap mode.
        * @leave Any other Symbian OS specific error codes.
        */
        IMPORT_C static void ScaleBitmapL( 
            const TRect& aTrgRect,
            CFbsBitmap* aTrgBitmap,
            CFbsBitmap* aSrcBitmap );

        /**
        * Bitmap rotation and scaling. Might be exported later. Scales and
        * rotates the given bitmap according to the parameters. Supported 
        * bitmap modes are EGray2, EGray256, EColor256, EColor4K, EColor64K and 
        * EColor16MU. All other bitmap depts will cause a leave with
        * KErrNotSupported. The only supported scalemode is 
        * EAspectRatioPreserved. The unused area in the target bitmap is
        * filled with black color unless the bitmap depth is EGray8 when the
        * area is filled with white. Areas that do not fit to the target area
        * after rotation are clipped out
        *
        * If the bitmap depth is EGray2, the routine will perform noticeably worse.
        * 
        * @param aTrgRect target rect inside the target bitmap
        * @param aTrgBitmap the target bitmap
        * @param aSrcBitmap the source bitmap
        * @param aAngle the rotation angle in degrees
        */
        static void RotateAndScaleBitmapL(
            const TRect& aTrgRect,
            CFbsBitmap* aTrgBitmap, 
            CFbsBitmap* aSrcBitmap,
            TInt aAngle );

        /**
         * @internal
         */
        static TBool DoesScaleBitmapUseFallBack( 
            CFbsBitmap* aSrcBitmap );

        /**
         * @internal
         */
        static void ScaleBitmapExtL( 
            const TRect& aTrgRect,
            CFbsBitmap* aTrgBitmap,
            CFbsBitmap* aSrcBitmap,
            TBool aForceFallBack );
            
    private:

        /**
        * Utility for down-cast of CFbsBitmap objects. It informs whether
        * the given CFbsBitmap is CAknBitmap or not. A list of CAknBitmap
        * pointers is managed in TLS for this.
        * 
        * @param aBitmap bitmap
        * @ret ETrue iff the given CFbsBitmap is an CAknBitmap instance.
        */
        static TBool IsAknBitmap( const CFbsBitmap* aBitmap );
        
        /**
        * Internal utility.
        */
        static void CreateIconLC(
            CFbsBitmap*& aBitmap,
            CFbsBitmap*& aMask,
            const TDesC& aFileName,
            TInt aBitmapId,
            TInt aMaskId,
            MAknIconFileProvider* aFileProvider );

        /**
        * Internal utility.
        * @deprecated
        */
        static void CreateIconLC(
            CFbsBitmap*& aBitmap,
            CFbsBitmap*& aMask,
            const TDesC& aFileName,
            TInt aBitmapId,
            TInt aMaskId,
            RFile& aFile );
        
    private:

        AknIconUtils();
    };

#include "AknIconUtils.inl"
#endif // AKN_ICON_UTILS_H
            
// End of File
