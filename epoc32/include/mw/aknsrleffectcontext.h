/*
* Copyright (c) 2004 Nokia Corporation and/or its subsidiary(-ies).
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
* Description:  ?Description
*
*/


#ifndef AKNSRLEFFECTCONTEXT_H
#define AKNSRLEFFECTCONTEXT_H

//  INCLUDES

#include <fbs.h>
#include <bitdev.h>

// CONSTANTS

/**
* Constant value indicating a rendering operation where the layer is not given 
* at all.
*
* @since 2.8
*/
const TInt KAknsRlLayerNone         = 0x1;

/**
* Constant value indicating a rendering operation where the layer has only an 
* RGB channel.
*
* @since 2.8
*/
const TInt KAknsRlLayerRGBOnly      = 0x2;

/**
* Constant value indicating a rendering operation where the layer has only an 
* alpha channel.
*
* @since 2.8
*/
const TInt KAknsRlLayerAlphaOnly    = 0x4;

/**
* Constant value indicating a rendering operation where the layer has both an
* RGB channel and an alpha channel.
*
* @since 2.8
*/
const TInt KAknsRlLayerRGBA         = 0x8;

// DATA TYPES

/**
* Structure that encapsulates information of a layer.
*
* @since 2.8
*/
struct TAknsRlLayerData 
    {
    /**
    * Default constructor initializes to zero.
    *
    * @since 2.8
    */
    inline TAknsRlLayerData() : iRGBBitmap(0), iRGBDevice(0), iRGBGc(0),
        iAlphaBitmap(0), iAlphaDevice(0), iAlphaGc(0) {};

    /**
    * Bitmap for RGB channel.
    *
    * @since 2.8
    */
    CFbsBitmap* iRGBBitmap;

    /**
    * Bitmap device for RGB channel.
    *
    * @since 2.8
    */
    CFbsBitmapDevice* iRGBDevice;

    /**
    * Bitmap graphics context for RGB channel.
    *
    * @since 2.8
    */
    CFbsBitGc* iRGBGc;

    /**
    * Bitmap for alpha channel.
    *
    * @since 2.8
    */
    CFbsBitmap* iAlphaBitmap;

    /**
    * Bitmap device for alpha channel.
    *
    * @since 2.8
    */
    CFbsBitmapDevice* iAlphaDevice;

    /**
    * Bitmap graphics context for alpha channel.
    *
    * @since 2.8
    */
    CFbsBitGc* iAlphaGc;
    };

// FORWARD DECLARATIONS

class RAknsSrvSession;

// CLASS DECLARATION

/**
* Interface to skin effect context.
* 
* Skin effect plugins receive a reference to their contexts upon activation.
* The context is then used to retrieve and manipulate layer data.
*
* The skin renderer sets the size of the layers of the particular skin
* item being rendered, and may initialize the content of one or more
* layers. Then the effects are executed, one at a time, to manipulate
* layer content. Finally, one or more layers are used as the content
* of the skin item being rendered.
*
* All the layers have the same size. All the RGB channels have the same
* color depth, and the color depth is either @c EColor64K or @c EColor16MU.
* All the alpha channels have color depth @c EGray256.
*
* @since 2.8
*/
class MAknsRlEffectContext
    {
    public: // Constructors and destructor

        /**
        * Destructor for internal use.
        *
        * Destructor is reserved for internal use. Client code must never
        * destroy effect contexts.
        */
        inline virtual ~MAknsRlEffectContext() {}

    public: // New functions - Layer support

        /**
        * Retrieves the size of the layers. Every layer has the same size.
        *
        * @since 2.8
        */
        virtual const TSize LayerSize() =0;

        /**
        * Retrieves the given layer data.
        *
        * Retrieves the required objects to manipulate layer content, and
        * optionally initializes the graphical content if the layer is
        * currently unused.
        *
        * The ownership of the objects included in @c aData structure stays
        * with the effect context. Calling code must not deactivate, close,
        * nor destroy any of the objects.
        *
        * Calling code must assume any initial brush, pen, or color 
        * configuration regarding the graphics devices. After rendering, 
        * the plugin must not leave any clipping configuration active in the 
        * graphics contexts. Brush, pen, and color configuration may be left 
        * in any state.
        *
        * Only the fields indicated by @c aLayerStatus parameter are
        * assigned. Other fields are set to @c NULL. For example, if only
        * the RGB channel is requested, fields for the alpha channel are
        * set to @c NULL.
        *
        * Note that both RGB and alpha channels are created, even if
        * the callers requests only one of them. Therefore it is strongly
        * recommended to use aInitialize parameter with @c ETrue value,
        * unless the caller knows that it will draw both the channels.
        *
        * @param aData Structure that will receive layer data. This is an 
        *   output parameter created and owned by the caller. Ownership of 
        *   the data objects themselves (i.e., the fields of the stucture)
        *   stays with the effect context.
        *
        * @param aLayerIndex Index of the layer to be retrieved.
        *
        * @param aLayerStatus One of the @c KAknsRlLayer constants
        *   indicating which channels of the layer are requested.
        *   This value must not be @c KAknsRlLayerNone nor a combination
        *   of constants.
        *
        * @param aInitialize @c ETrue if the context should initialize the
        *   layer content, @c EFalse otherwise. Regardless of this parameter,
        *   the objects included in layer data are always constructed and 
        *   drawable. If the layer is currently unused (i.e., no effect
        *   plugin or renderer has yet drawn to it), @c ETrue value
        *   instructs the context to perform the following initialization:
        *    - If RGB and alpha channels are requested, both of them are
        *       filled with black.
        *    - If only RGB channel is requested, it is filled with black.
        *       Alpha channel (not visible to the effect) is filled with
        *       white.
        *    - If only alpha channel is requested, it is filled with black.
        *       RGB channel (not visible to the effect) is filled with
        *       black.
        *   If @c EFalse is specified, the initial content of a previously
        *   unused layer is undefined. This also applies to the channel
        *   possibly not included in the request.
        *   Note that initialization is never done if the layer has been
        *   previously used by some effect or the renderer itself.
        *
        * @par Exceptions:
        * The method leaves with an error code if the layer can not be
        * retrieved or an invalid parameter is given. The result of the
        * subsequent GetLayerDataL calls is undefined. The plugin must
        * exit as soon as possible with an error code.
        */
        virtual void GetLayerDataL( TAknsRlLayerData& aData,
            const TInt aLayerIndex, const TInt aLayerStatus,
            const TBool aInitialize ) =0;
            
        /**
        * Retrieves current skin server session.
        *
        * @return Pointer to current skin server session. No ownership is
        *   transferred.
        *
        * @since 3.0 
        */
        virtual RAknsSrvSession* GetSkinSrvSession() = 0;
    };

#endif // AKNSRLEFFECTCONTEXT_H
            
// End of File
