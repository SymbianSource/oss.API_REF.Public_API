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
* Description:  Defines public item data classes.
*
*/


#ifndef AKNSITEMDATA_H
#define AKNSITEMDATA_H

// INCLUDES
#include <AknsItemID.h>
#include <AknsRlEffect.h>
#include <gdi.h>

// FORWARD DECLARATIONS
class CFbsBitmap;
struct TAknsAppIconInfo;
struct TAknsImageAttributeData;
struct TAknsColorTableEntry;
struct TAknsBmpAnimFrameInfo;
class CAknsEffectParameter;
class MAknsRlCommandIterator;
class MAknsAlIterator;
class CAknsNamedReference;
class CAknsSizeBoundParameter;
struct TAknsAlAnimationCommandData;
struct TAknsAlTimingModelData;
struct TAknsAlAnimationValueData;
struct TAknsAlNamedReferenceData;
struct TAknsAlSizeBoundParameterData;

// CLASS DECLARATIONS

/**
* Base class for item data classes.
* Item data encapsulates type information and resource instance (such as 
* CFbsBitmap object) of a specific skin item. Since actual data entries vary 
* depending on the type of the item, CAknsItemData contains only type 
* information and can not be instantiated. 
*
* This is a public class with exported functions.
* The class is not intended for derivation outside the library.
*
* @lib AknSkins.lib
*
* @since 2.0
*/
NONSHARABLE_CLASS(CAknsItemData) : public CBase
    {
    public:  // Constructors and destructor
                
        /**
        * Destructor.
        * CAknsItemData itself has no dynamically allocated members, but
        * derived classes may have them.
        */
        virtual ~CAknsItemData();

    public: // New functions

        /**
        * Sets the perceived type of this item without affecting the
        * real instance inheritance.
        *
        * @since 2.8
        *
        * @internal
        *
        * @param aType New type.
        */
        void SetType( const TAknsItemType aType );
        
        /**
        * Returns the type of the item data object. 
        * This method can be used to provide run-time type information.
        * Corresponding classes are listed in definition of ::TAknsItemType.
        *
        * @since 2.0
        *
        * @return Type of the item data as TAknsItemType.
        */
        IMPORT_C TAknsItemType Type() const;

    protected: // C++ protected constructor for derived classes
                
        /**
        * C++ constructor for derived classes.
        * Constructs item data object with given item type.
        *
        * @param aType Item type of the new item data object.
        *
        * @internal
        */
        CAknsItemData( const TAknsItemType aType );    
    
    protected:  // Data

        TAknsItemType iType;    //!< Type of the item data object.

    };

/**
* Image item data.
* Image item data contains (in addition to base class members) image 
* attributes, such as size or alignment. Item type for image item data
* objects is ::EAknsITImage.
*
* This is a public class with exported functions.
* The class is not intended for derivation outside the library.
*
* @lib AknSkins.lib
*
* @since 2.0
*/
NONSHARABLE_CLASS(CAknsImageItemData) : public CAknsItemData
    {
    public:  // Constructors and destructor
                
        /**
        * Destructor.        
        */
        virtual ~CAknsImageItemData();

    public: // New functions

        /**
        * Sets the image attributes for this image item data object.
        *
        * @since 2.0
        *
        * @param aAttributes Attribute data structure containing the new 
        *   values.
        */
        IMPORT_C void SetAttributesL( 
            const TAknsImageAttributeData& aAttributes );
        
        /**
        * Returns a pointer to the image attribute structure owned by the
        * item data object.
        *
        * @since 2.0
        *
        * @return Pointer to the image attribute structure, or @c NULL if
        *   there is none.
        */
        IMPORT_C const TAknsImageAttributeData* Attributes() const;

        IMPORT_C void SetParentIID(const TAknsItemID& aIID);
        IMPORT_C void SetDrawRect(const TRect& aRect);
        IMPORT_C TAknsItemID ParentIID();
        IMPORT_C TRect DrawRect();


    protected: // C++ protected constructor for derived classes
                
        /**
        * C++ constructor for derived classes.
        * Constructs an image item data object with given item type.
        *
        * @param aType Item type of the new item data object.
        *
        * @internal
        */
        CAknsImageItemData( const TAknsItemType aType );
    
    protected:  // Data

        TAknsImageAttributeData* iAttributeData;
        TAknsItemID iParentIID;
        TRect iDrawRect;

    
    };

/**
* Bitmap item data.
* Bitmap item data contains (in addition to base class members) CFbsBitmap
* instance of the bitmap. Item type for bitmap item data is always 
* ::EAknsITBitmap.
*
* This is a public class with exported functions.
* The class is not intended for derivation outside the library.
*
* @lib AknSkins.lib
*
* @since 2.0
*/
NONSHARABLE_CLASS(CAknsBitmapItemData) : public CAknsImageItemData
    {
    public:  // Constructors and destructor
            
        /**
        * Two-phased constructor.
        * Constructs a new CAknsBitmapItemData object with bitmap set to
        * @c NULL. Bitmap must be set afterwards by using 
        * SetBitmap(CFbsBitmap* aBitmap) method.
        *
        * @return Newly constructed CAknsBitmapItemData object.
        *
        * @par Exceptions:
        *   If allocation fails, function leaves with a system-wide error
        *   code.
        */
        IMPORT_C static CAknsBitmapItemData* NewL();
        
        /**
        * Destructor.
        * Deletes bitmap object, if present.
        */
        virtual ~CAknsBitmapItemData();

    public: // New functions
        
        /**
        * Sets the bitmap object for this item data instance.
        *
        * @since 2.0
        *
        * @c NULL value can be used to detach bitmap from item data.
        *
        * @param aBitmap Pointer to bitmap instance. Ownership of the bitmap
        *   object is transferred to item data. @c NULL value is also valid.
        */
        IMPORT_C void SetBitmap( CFbsBitmap* aBitmap );

        /**
        * Sets the bitmap object for this item data instance and destroys 
        * previous one, if any.
        *
        * @since 2.0
        *
        * @param aBitmap Pointer to bitmap instance. Ownership of the bitmap
        *   object is transferred to item data. @c NULL value is also valid.
        */
        IMPORT_C void DestroyAndSetBitmap( CFbsBitmap* aBitmap );

        /**
        * Returns the current bitmap object owned by item data instance.
        *
        * @since 2.0
        *
        * @return Pointer to bitmap instance, or @c NULL if none is currently
        *   associated with this item data.
        */
        IMPORT_C CFbsBitmap* Bitmap();
        
    protected:  // C++ protected constructor

        /**
        * C++ protected constructor.
        * Constructs a new CAknsBitmapItemData with bitmap set to @c NULL.
        *
        * @param aType Item type of the new item data object. While this
        *   is always ::EAknsITBitmap for instances of this class, derived
        *   classes may specify another value.
        *
        * @internal
        */
        CAknsBitmapItemData( const TAknsItemType aType );
    
    protected:  // Data
        CFbsBitmap* iBitmap;    //!< Pointer to associated bitmap instance.

    };

/**
* Masked bitmap item data.
* Masked bitmap item data contains (in addition to base class members) an
* additional member of type CFbsBitmap for the bitmap mask.
* Item type for bitmap item data is always ::EAknsITMaskedBitmap.
*
* This is a public class with exported functions.
* The class is not intended for derivation outside the library.
*
* @lib AknSkins.lib
*
* @since 2.0
*/
NONSHARABLE_CLASS(CAknsMaskedBitmapItemData) : public CAknsBitmapItemData
    {
    public:  // Constructors and destructor
            
        /**
        * Two-phased constructor.
        * Constructs a new CAknsMaskedBitmapItemData object with bitmaps set to
        * @c NULL. Bitmaps must be set afterwards by using 
        * SetBitmap(CFbsBitmap* aBitmap) and SetMask(CFbsBitmap* aBitmap) methods.
        *
        * @return Newly constructed CAknsMaskedBitmapItemData object.
        *
        * @par Exceptions:
        *   If allocation fails, function leaves with a system-wide error
        *   code.
        */
        IMPORT_C static CAknsMaskedBitmapItemData* NewL();
        
        /**
        * Destructor.
        * Deletes bitmap objects, if present.
        */
        virtual ~CAknsMaskedBitmapItemData();

    public: // New functions
        
        /**
        * Sets the mask bitmap object for this item data instance.
        * @c NULL value can be used to detach bitmap mask from item data.
        *
        * @since 2.0
        *
        * @param aMask Pointer to mask instance. Ownership of the bitmap
        *   object is transferred to item data. @c NULL value is also valid.
        */
        IMPORT_C void SetMask( CFbsBitmap* aMask );

        /**
        * Sets the mask bitmap object for this item data instance and destroys 
        * previous one, if any.
        *
        * @since 2.0
        *
        * @param aMask Pointer to mask instance. Ownership of the bitmap
        *   object is transferred to item data. @c NULL value is also valid.
        */
        IMPORT_C void DestroyAndSetMask( CFbsBitmap* aMask );

        /**
        * Returns the current bitmap mask object owned by item data instance.
        *
        * @since 2.0
        *
        * @return Pointer to mask instance, or @c NULL if none is currently
        *   associated with this item data.
        */
        IMPORT_C CFbsBitmap* Mask();
        
    protected:  // C++ protected constructor

        /**
        * C++ protected constructor.
        * Constructs a new CAknsMaskedBitmapItemData with bitmaps set to @c NULL.
        *
        * @param aType Item type of the new item data object. While this
        *   is always ::EAknsITMaskedBitmap for instances of this class, derived
        *   classes may specify another value.
        *
        * @internal
        */
        CAknsMaskedBitmapItemData( const TAknsItemType aType );    
    
    protected:  // Data
        CFbsBitmap* iMask;    //!< Pointer to associated mask bitmap instance.

    };

/**
* Color table item data.
* Color table item data contains (in addition to base class members) color 
* array of TRGB values. Item type for color item data is always 
* ::EAknsITColorTable.
*
* This is a public class with exported functions.
* The class is not intended for derivation outside the library.
*
* @lib AknSkins.lib
*
* @since 2.0
*/
NONSHARABLE_CLASS(CAknsColorTableItemData) : public CAknsImageItemData
    {
    public:  // Constructors and destructor
            
        /**
        * Two-phased constructor.
        * Constructs a new CAknsColorTableItemData object. Values must
        * be set separately using SetColorsL.
        *
        * @return Newly constructed CAknsColorTableItemData object.
        *
        * @par Exceptions:
        *   If allocation fails, function leaves with a system-wide error
        *   code.
        */
        IMPORT_C static CAknsColorTableItemData* NewL();
        
        /**
        * Destructor.
        * Destroys color value array.
        */
        virtual ~CAknsColorTableItemData();

    public: // New functions
        
        /**
        * Sets color values for this item data instance.
        *        
        * @since 2.0
        *
        * @param aNumberOfColors Number of colors in aColors.
        *
        * @param aColors Pointer to first color value. Values are copied
        *   into an internal array.
        */
        IMPORT_C void SetColorsL( const TInt aNumberOfColors, 
            const TAknsColorTableEntry* aColors );

        /**
        * Returns the indexed color value.
        *
        * @since 2.0
        *
        * @param aIndex Index of the color to be retrieved. This must
        *   be within 0 (inclusive) and aNumberOfColors (exclusive).
        *
        * @return Color value as TInt. If the value is -1, RGB value
        *   should be queried instead.
        *
        * @par Note:
        *   This method does not perform any bounds checking. An access
        *   violation or panic will occur, if the given index is not
        *   within the bounds of the internal array. Use @c GetColorL
        *   instead, if such checking is required.
        */
        IMPORT_C TInt ColorIndexed( const TInt aIndex ) const;

        /**
        * Returns the RGB color value.
        *
        * @since 2.0
        *
        * @param aIndex Index of the color to be retrieved. This must
        *   be within 0 (inclusive) and aNumberOfColors (exclusive).
        *
        * @return Color value as TRgb. Note that the value is only
        *   valid if ColorIndexed() returned -1.
        *
        * @par Note:
        *   This method does not perform any bounds checking. An access
        *   violation or panic will occur, if the given index is not
        *   within the bounds of the internal array. Use @c GetColorL
        *   instead, if such checking is required.
        */
        IMPORT_C TRgb ColorRgb( const TInt aIndex ) const;

        /**
        * Retrieves a color value (indexed or RGB) with bounds checking.
        *
        * @since 2.6
        *
        * @param aIndex Index of the color to be retrieved.
        *
        * @param aColor On return, contains the color as an RGB value.
        *   If the color is indexed, the appropriate mapping using current
        *   palette is used.
        *
        * @par Exceptions:
        *   If the given index is outside the bounds of the array,
        *   the method leaves with an error code.
        */
        IMPORT_C void GetColorL( const TInt aIndex, TRgb& aColor ) const;
        
    protected:  // C++ protected constructor

        /**
        * C++ protected constructor.
        * Constructs a new CAknsColorItemData without an array.
        *
        * @param aType Item type of the new item data object. While this
        *   is always ::EAknsITColorTable for instances of this class, derived
        *   classes may specify another value.
        *
        * @internal
        */
        CAknsColorTableItemData( const TAknsItemType aType );
    
    protected:  // Data

        TAknsColorTableEntry* iColorArray; //!< Color array.
        TInt iColorArraySize;

    };

/**
* Icon table item data.
* Icon table item data contains (in addition to base class members), an 
* array containing item IDs of images. Item type for 
* image table item data objects is always ::EAknsITImageTable.
*
* This is a public class with exported functions.
* The class is not intended for derivation outside the library.
*
* @lib AknSkins.lib
*
* @since 2.0
*/
NONSHARABLE_CLASS(CAknsImageTableItemData) : public CAknsImageItemData
    {
    public:  // Constructors and destructor
            
        /**
        * Two-phased constructor.
        * Constructs a new CAknsImageTableItemData object. Values must
        * be set separately using SetImagesL.
        *
        * @return Newly constructed CAknsImageTableItemData object.
        *
        * @par Exceptions:
        *   If allocation fails, function leaves with a system-wide error
        *   code.
        */
        IMPORT_C static CAknsImageTableItemData* NewL();
        
        /**
        * Destructor.
        * Destroys image array.
        */
        virtual ~CAknsImageTableItemData();

    public: // New functions
        
        /**
        * Sets image table values for this item data instance.
        *        
        * @since 2.0
        *
        * @param aNumberOfImages Number of images in aImages.
        *
        * @param aImages Pointer to first image ID. Values are 
        *   copied into an internal array.
        */
        IMPORT_C void SetImagesL( const TInt aNumberOfImages, 
            const TAknsItemID* aImages );        

        /**
        * Returns the item ID of an image.
        *
        * @since 2.0
        *
        * @param aIndex Index of the image. This value must
        *   be within 0 (inclusive) and NumberOfImages (exclusive).
        *
        * @return Item ID of the image.
        */
        IMPORT_C TAknsItemID ImageIID( const TInt aIndex ) const;

        /**
        * Returns pointer to the first entry in the image array, 
        * owned by this object.
        *
        * @since 2.0
        *        
        * @return Pointer to TAknsItemID.
        */
        IMPORT_C TAknsItemID* Images() const;

        /**
        * Returns the number of images.
        *
        * @since 2.0
        * 
        * @return Number of images as an integer.
        */
        IMPORT_C TInt NumberOfImages() const;
        
    protected:  // C++ protected constructor

        /**
        * C++ protected constructor.
        * Constructs a new CAknsImageTableItemData without an array.
        *
        * @param aType Item type of the new item data object. While this
        *   is always ::EAknsITImageTable for instances of this class, derived
        *   classes may specify another value.
        *
        * @internal
        */
        CAknsImageTableItemData( const TAknsItemType aType );
    
    protected:  // Data

        TInt iNumberOfImages;       //!< Number of images.
        TAknsItemID* iImageArray;   //!< Image array.

    };

/**
* Bitmap animation item data.
* Bitmap animation item data contains (in addition to base class members),  
* animation properties as well as an array containing frame properties
* Item type for bitmap animation item data objects is always ::EAknsITBmpAnim.
*
* This is a public class with exported functions.
* The class is not intended for derivation outside the library.
*
* @lib AknSkins.lib
*
* @since 2.0
*/
NONSHARABLE_CLASS(CAknsBmpAnimItemData) : public CAknsImageTableItemData
    {
    public:  // Constructors and destructor
            
        /**
        * Two-phased constructor.
        * Constructs a new CAknsBmpAnimItemData object. Values must
        * be set separately using SetImagesL and SetFrameInfosL.
        *
        * @return Newly constructed CAknsBmpAnimItemData object.
        *
        * @par Exceptions:
        *   If allocation fails, function leaves with a system-wide error
        *   code.
        */
        IMPORT_C static CAknsBmpAnimItemData* NewL();
        
        /**
        * Destructor.
        * Destroys arrays.
        */
        virtual ~CAknsBmpAnimItemData();

    public: // New functions
        
        /**
        * Sets frame property values for this item data instance.
        *
        * The number of entries in the given array must match
        * the number of images in the image table. Therefore
        * SetFrameInfosL must be called only after SetImagesL
        * has already been called.
        *        
        * @since 2.0
        *
        * @param aFrameInfos Pointer to first frame info. Values are 
        *   copied into an internal array.
        */
        IMPORT_C void SetFrameInfosL( const TAknsBmpAnimFrameInfo* aFrameInfos );

        /**
        * Returns pointer to the first entry in the frame property array, 
        * owned by this object.
        *
        * @since 2.0
        *        
        * @return Pointer to TAknsBmpAnimFrameInfo.
        */
        IMPORT_C TAknsBmpAnimFrameInfo* FrameInfos() const;

        /**
        * Sets the flag indicating whether the last frame should be
        * interpreted as the background (i.e. excluded from the animation
        * itself).
        *
        * @since 2.0
        *
        * @param aLastFrameBg Boolean value.
        */
        IMPORT_C void SetLastFrameBackground( TBool aLastFrameBg );

        /**
        * Retrieves the flag value indicating whether the last frame
        * should be interpreted as the background.
        *
        * @since 2.0
        *
        * @return Boolean value.
        */
        IMPORT_C TBool LastFrameBackground() const;

        /**
        * Sets the frame interval for the entire animation.
        *
        * @since 2.0
        *
        * @param aFrameInterval Frame interval in milliseconds or -1.
        */
        IMPORT_C void SetFrameInterval( const TInt16 aFrameInterval );

        /**
        * Retrieves the frame interval.
        *
        * @since 2.0
        *
        * @return Frame interval in milliseconds or -1.
        */
        IMPORT_C TInt16 FrameInterval() const;

        /**
        * Sets the play mode for the entire animation.
        *
        * @since 2.0
        *
        * @param aPlayMode Play mode.
        */
        IMPORT_C void SetPlayMode( const TInt16 aPlayMode );

        /**
        * Retrieves the play mode.
        *
        * @since 2.0
        *
        * @return Play mode.
        */
        IMPORT_C TInt16 PlayMode() const;

        /**
        * Sets the flash property for the entire animation.
        *
        * @since 2.0
        *
        * @param aFlash Flash flag value.
        */
        IMPORT_C void SetFlash( const TBool aFlash );

        /**
        * Retrieves the flash property.
        *
        * @since 2.0
        *
        * @return Flash flag value.
        */
        IMPORT_C TBool Flash() const;
        
    protected:  // C++ protected constructor

        /**
        * C++ protected constructor.
        * Constructs a new CAknsBmpAnimItemData without an array.
        *
        * @param aType Item type of the new item data object. While this
        *   is always ::EAknsITBmpAnim for instances of this class, derived
        *   classes may specify another value.
        *
        * @internal
        */
        CAknsBmpAnimItemData( const TAknsItemType aType );
    
    protected:  // Data

        TAknsBmpAnimFrameInfo* iFrameArray;   //!< Frame info array.

        TBool iLastFrameBackground; //!< Last frame used as background flag.
        TInt16 iFrameInterval;  //!< Frame interval.
        TInt16 iPlayMode;       //!< Play mode.
        TBool iFlash;           //!< Flash flag.

    };

/**
* String item data.
* String item data contains (in addition to base class members),  
* a single string value.
* Item type for string item data objects is always ::EAknsITString.
*
* This is a public class with exported functions.
* The class is not intended for derivation outside the library.
*
* @lib AknSkins.lib
*
* @since 2.6
*/
NONSHARABLE_CLASS(CAknsStringItemData) : public CAknsItemData
    {
    public:  // Constructors and destructor
            
        /**
        * Two-phased constructor.
        * Constructs a new CAknsStringItemData object. String value must
        * be set separately using SetStringL.
        *
        * @return Newly constructed CAknsStringItemData object.
        *
        * @par Exceptions:
        *   If allocation fails, function leaves with a system-wide error
        *   code.
        */
        IMPORT_C static CAknsStringItemData* NewL();
        
        /**
        * Destructor.
        * Destroys owned string instance.
        */
        virtual ~CAknsStringItemData();

    public: // New functions
        
        /**
        * Sets the string value of this item data instance.
        *
        * @since 2.6
        *
        * @param aValue New value. The value is copied to a newly created
        *   internal buffer, and any previous value is discarded.
        */
        IMPORT_C void SetStringL( const TDesC& aValue );

        /**
        * Returns a reference to the string value. The value is still owned
        * by the item data object and caller must take its lifetime properly
        * into account.
        *
        * @since 2.6
        *        
        * @return Reference to the value.
        */
        IMPORT_C const TDesC& String() const;

    protected:  // C++ protected constructor

        /**
        * C++ protected constructor.
        * Constructs a new CAknsStringItemData without an array.
        *
        * @param aType Item type of the new item data object. While this
        *   is always ::EAknsITString for instances of this class, derived
        *   classes may specify another value.
        *
        * @internal
        */
        CAknsStringItemData( const TAknsItemType aType );
    
    protected:  // Data

        HBufC* iString; //!< Buffer for string value.

    };

/**
* Effect command data class.
* Effect command class encapsulates the information of a single effect
* command that is used with effect queue item data objects.
*
* This is a public class with exported functions.
* The class is not intended for derivation outside the library.
*
* @lib AknSkins.lib
*
* @since 2.8
*/
NONSHARABLE_CLASS(CAknsEffectCommand) : public CBase
    {
    public:  // Constructors and destructor
            
        /**
        * Two-phased constructor.
        *
        * @return Newly constructed object.
        *
        * @par Exceptions:
        *   If allocation fails, function leaves with a system-wide error
        *   code.
        */
        IMPORT_C static CAknsEffectCommand* NewL();
        
        /**
        * Destructor.
        */
        virtual ~CAknsEffectCommand();

    public: // New functions

        /**
        * Sets the effect UID.
        *
        * @since 2.8
        *
        * @param aValue New effect UID.
        */
        IMPORT_C void SetEffectUid( const TUid aValue );

        /**
        * Returns the effect UID.
        * 
        * @since 2.8
        *
        * @return Effect UID.
        */
        IMPORT_C TUid EffectUid() const;

        /**
        * Sets the layer configuration.
        *
        * @since 2.8
        *
        * @param aValue New layer configuration.
        */
        IMPORT_C void SetLayerConf( const TAknsRlRenderOpParam aValue );

        /**
        * Returns the layer configuration.
        * 
        * @since 2.8
        *
        * @return Layer configuration.
        */
        IMPORT_C TAknsRlRenderOpParam LayerConf() const;

        /**
        * Appends a paramater to this effect command.
        *
        * @since 2.8
        *
        * @param aParameter Parameter to be appended. The given data is copied,
        * and thus no ownership is transferred.
        */
        IMPORT_C void AppendParameterL( 
            const TAknsRlParameterData& aParameter );

        /**
        * Creates and returns a new parameter iterator.
        *
        * @since 2.8
        *
        * @return A new parameter iterator. Multiple iterators can be created.
        *   The ownership of the iterator is transferred to the caller, and
        *   the caller must ensure that the lifetime of the iterator
        *   does not exceed the lifetime of this object.
        */
        IMPORT_C MAknsRlParameterIterator* CreateParameterIteratorL();

    protected:  // C++ protected constructor

        /**
        * C++ protected constructor.
        *
        * @internal
        */
        CAknsEffectCommand();
    
    protected:  // Data

        TUid iUid; //!< Effect UID.
        TAknsRlRenderOpParam iLayerConf; //!< Layer configuration.
        RPointerArray<CAknsEffectParameter> iParameters; //!< Parameters array.

    };

/**
* Effect queue item data.
* Effect queue item data contains (in addition to base class members),  
* the information required to render a single effect queue based
* skin element.
*
* Item type for effect queue item data objects is always ::EAknsITEffectQueue.
*
* This is a public class with exported functions.
* The class is not intended for derivation outside the library.
*
* @lib AknSkins.lib
*
* @since 2.8
*/
NONSHARABLE_CLASS(CAknsEffectQueueItemData) : public CAknsItemData
    {
    public:  // Constructors and destructor
            
        /**
        * Two-phased constructor.
        * Constructs a new CAknsEffectQueueItemData object.
        *
        * @return Newly constructed CAknsEffectQueueItemData object.
        *
        * @par Exceptions:
        *   If allocation fails, function leaves with a system-wide error
        *   code.
        */
        IMPORT_C static CAknsEffectQueueItemData* NewL();
        
        /**
        * Destructor.
        */
        virtual ~CAknsEffectQueueItemData();

    public: // New functions

        /**
        * Sets the referenced item ID.
        *
        * @since 2.8
        *
        * @param aValue
        */
        IMPORT_C void SetRefItem( const TAknsItemID aValue );

        /**
        * Returns the referenced item ID.
        * 
        * @since 2.8
        *
        * @return Referenced item ID, or @c KAknsIIDDefault if none.
        */
        IMPORT_C TAknsItemID RefItem() const;

        /**
        * Sets the input layer index value.
        *
        * @since 2.8
        *
        * @param aValue
        */
        IMPORT_C void SetInputLayer( const TInt aValue );

        /**
        * Returns the input layer index value.
        * 
        * @since 2.8
        *
        * @return Input layer index, or -1 if not used.
        */
        IMPORT_C TInt InputLayer() const;

        /**
        * Sets the input layer mode value.
        *
        * @since 2.8
        *
        * @param aValue
        */
        IMPORT_C void SetInputLayerMode( const TInt aValue );

        /**
        * Returns the input layer mode value.
        * 
        * @since 2.8
        *
        * @return Input layer mode.
        */
        IMPORT_C TInt InputLayerMode() const;

        /**
        * Sets the output layer index value.
        *
        * @since 2.8
        *
        * @param aValue
        */
        IMPORT_C void SetOutputLayer( const TInt aValue );

        /**
        * Returns the output layer index value.
        * 
        * @since 2.8
        *
        * @return Output layer index.
        */
        IMPORT_C TInt OutputLayer() const;

        /**
        * Sets the output layer mode value.
        *
        * @since 2.8
        *
        * @param aValue
        */
        IMPORT_C void SetOutputLayerMode( const TInt aValue );

        /**
        * Returns the output layer mode value.
        * 
        * @since 2.8
        *
        * @return Output layer mode.
        */
        IMPORT_C TInt OutputLayerMode() const;

        /**
        * Appends a command to this effect queue.
        *
        * @since 2.8
        *
        * @param aCommand Command to be appended. The ownership of the
        * given instance is transferred to this object, even if the method
        * leaves.
        */
        IMPORT_C void AppendCommandL( const CAknsEffectCommand* aCommand );

        /**
        * Creates and returns a new command iterator.
        *
        * @since 2.8
        *
        * @return A new command iterator. Multiple iterators can be created.
        *   The ownership of the iterator is transferred to the caller, and
        *   the caller must ensure that the lifetime of the iterator
        *   does not exceed the lifetime of this object.
        */
        IMPORT_C MAknsRlCommandIterator* CreateCommandIteratorL();

    protected:  // C++ protected constructor

        /**
        * C++ protected constructor.
        * Constructs a new CAknsEffectQueueItemData.
        *
        * @param aType Item type of the new item data object. While this
        *   is always ::EAknsITEffectQueue for instances of this class, derived
        *   classes may specify another value.
        *
        * @internal
        */
        CAknsEffectQueueItemData( const TAknsItemType aType );
    
    protected:  // Data

        TAknsItemID iRefId; //!< Referenced item ID.
        TInt iInputLayer; //!< Input layer value.
        TInt iInputLayerMode; //!< Input layer mode value.
        TInt iOutputLayer; //!< Output layer value.
        TInt iOutputLayerMode; //!< Output layer mode value.
        RPointerArray<CAknsEffectCommand> iCommands; //!< Commands array.

    };

/**
* Timing model data class.
* Timing model class encapsulates the information of a single timing model that
* is used with animation command item data objects.
*
* The class is not intended for derivation outside the library.
*
* @lib AknSkins.lib
*
* @since 3.0
*/
class CAknsTimingModel: public CBase
    {
    public: // Constructors and destructor
        static CAknsTimingModel* NewL();
        virtual ~CAknsTimingModel();

    protected: // C++ protected constructor
        CAknsTimingModel();

    public:
        void SetTimingModelUid( const TUid aValue );
        TUid TimingModelUid() const;

        void AppendParameterL( const TAknsRlParameterData& aParameter );
        MAknsRlParameterIterator* CreateParameterIteratorL();

    public: // Iteration support (internal)
        void AssignOutL( TAknsAlTimingModelData& aData );

        static void InitializeOut( TAknsAlTimingModelData& aData );
        static void ReleaseOut( TAknsAlTimingModelData& aData );

    private: // Data
         TUid iTimingModelUid;
         RPointerArray<CAknsEffectParameter> iParameters;
    };

/**
* Animation value data class.
* Animation value class encapsulates the information of a single animation
* value (animation value uid, parameters for animation value and timing model
* reference id) that is used with animation command item data objects.
*
* The class is not intended for derivation outside the library.
*
* @lib AknSkins.lib
*
* @since 3.0
*/
class CAknsAnimationValue: public CBase
    {
    public:
        static CAknsAnimationValue* NewL();
        virtual ~CAknsAnimationValue();

    private:
        CAknsAnimationValue();

    public:
        void SetAnimationValueUid( const TUid aValue );
        TUid AnimationValueUid() const;

        void SetTimingModelId( const TInt aId );
        TInt TimingModelId() const;

        void AppendParameterL( const TAknsRlParameterData& aParameter );
        MAknsRlParameterIterator* CreateParameterIteratorL();

    public: // Iteration support (internal)
        void AssignOutL( TAknsAlAnimationValueData& aData );

        static void InitializeOut( TAknsAlAnimationValueData& aData );
        static void ReleaseOut( TAknsAlAnimationValueData& aData );

    private:
         TInt iTimingModelId;
         TUid iAnimationValueUid;
         RPointerArray<CAknsEffectParameter> iParameters;
    };

/**
* Animation command data class.
* Animation command class encapsulates the information of a single animation
* command (in addition to base class members) that is used with animation item
* data objects.
*
* The class is not intended for derivation outside the library.
*
* @lib AknSkins.lib
*
* @since 3.0
*/
class CAknsAnimationCommand: public CAknsEffectCommand
    {
    public:
        static CAknsAnimationCommand* NewL();
        virtual ~CAknsAnimationCommand();

    private:
        CAknsAnimationCommand();

    public:
        void AppendNamedReferenceL( const TAknsAlNamedReferenceData& aData );
        MAknsAlIterator* CreateNamedReferenceIteratorL();

    public: // Iteration support (internal)
        void AssignOutL( TAknsAlAnimationCommandData& aData );

        static void InitializeOut( TAknsAlAnimationCommandData& aData );
        static void ReleaseOut( TAknsAlAnimationCommandData& aData );

    private:
         RPointerArray<CAknsNamedReference> iNamedReferences;
    };

/**
* Animation item data.
* Animation item data contains (in addition to base class members) the
* information required to create an AnimationLibrary animation.
*
* Item type for animation item data objects is always ::EAknsITAnimation.
*
* The class is not intended for derivation outside the library.
*
* @lib AknSkins.lib
*
* @since 3.0
*/
class CAknsAnimationItemData: public CAknsItemData
    {
    public:
        static CAknsAnimationItemData* NewL();
        virtual ~CAknsAnimationItemData();

    protected: // C++ protected constructor
        CAknsAnimationItemData();

    public: // New functions
        void SetMinInterval( TInt aMin );
        TInt MinInterval() const;

        void SetMorphing( TBool aMorphing );
        TBool Morphing() const;

        void SetInputLayer( const TInt aValue );
        TInt InputLayer() const;

        void SetInputLayerMode( const TInt aValue );
        TInt InputLayerMode() const;

        void SetOutputLayer( const TInt aValue );
        TInt OutputLayer() const;

        void SetOutputLayerMode( const TInt aValue );
        TInt OutputLayerMode() const;

        /**
        * @param aCommand Ownership is transferred
        */
        void AppendPreprocessCommandL( CAknsEffectCommand* aCommand );
        MAknsRlCommandIterator* PreprocessCommandIteratorL() const;

        /**
        * @param aCommand Ownership is transferred
        */
        void AppendCommandL( CAknsAnimationCommand* aCommand );
        MAknsAlIterator* CommandIteratorL() const;

        /**
        * @param aValue Ownership is transferred
        */
        void AppendTimingModelL( CAknsTimingModel* aModel );
        MAknsAlIterator* TimingModelIteratorL() const;

        /**
        * @param aValue Ownership is transferred
        */
        void AppendAnimationValueL( CAknsAnimationValue* aValue );
        MAknsAlIterator* AnimationValueIteratorL() const;

        void AppendSizeBoundParamL( const TAknsAlSizeBoundParameterData& aParam );
        MAknsAlIterator* SizeBoundParamIteratorL() const;

    private:
        TInt iMinInterval; // In milliseconds
        TBool iMorphing;

        TInt iInputLayer;
        TInt iInputLayerMode;
        TInt iOutputLayer;
        TInt iOutputLayerMode;

        RPointerArray<CAknsEffectCommand> iPreprocessCommands;
        RPointerArray<CAknsAnimationCommand> iAnimationCommands;
        RPointerArray<CAknsTimingModel> iTimingModels;
        RPointerArray<CAknsAnimationValue> iAnimationValues;
        RPointerArray<CAknsSizeBoundParameter> iSizeBoundParams;
    };

#endif // AKNSITEMDATA_H

// End of File
