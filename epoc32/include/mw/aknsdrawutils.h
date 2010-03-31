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
* Description:  Defines a public static class AknsDrawUtils and related 
*                constants.
*
*/


#ifndef AKNSDRAWUTILS_H
#define AKNSDRAWUTILS_H

// INCLUDES
#include <AknsUtils.h>

// CONSTANTS

/**
* Default value for drawing parameters.
*
* @since 2.0
*/
static const TInt KAknsDrawParamDefault                 = 0x0;

/**
* Drawing parameter that limits processing of layout levels to the first one.
* This can be used to temporarily disable secondary layout levels.
*
* @since 2.0
*/
static const TInt KAknsDrawParamLimitToFirstLevel       = 0x1;

/**
* Drawing parameter that suspends clearing under images. Only the first
* layout level is affected.
*
* @since 2.0
*/
static const TInt KAknsDrawParamNoClearUnderImage       = 0x2;

/**
* Drawing parameter that causes the layouts and bitmaps to be prepared,
* but no actual drawing takes place.
*
* @since 2.8
*/
static const TInt KAknsDrawParamPrepareOnly             = 0x04;

/**
* Drawing parameter that draws only the RGB channel of data.
*
* @since 3.0
*/
static const TInt KAknsDrawParamRGBOnly                 = 0x8;

/**
* Drawing parameter that draws only the alpha channel of data. If the data
* is unmasked, the result is undefined.
*
* @since 3.0
*/
static const TInt KAknsSDMAlphaOnly                     = 0x10;
/**
* Drawing parameter that allows empty SCALABLEITEMS to use
* the parent bitmap directly
*
* @since 3.0
*/
static const TInt KAknsDrawParamChained                     = 0x20;

/**
* Forces drawing the bottom level in chain to use RGBOnly. Bottom level is the
* first drawn level, visually the bottom most level.
*
* @since 3.0
*/
static const TInt KAknsDrawParamBottomLevelRGBOnly            = 0x40;

/**
* Ignores layer mask when drawing layers.
*
* @since 3.2
*/

static const TInt KAknsDrawParamIgnoreLayerMask               = 0x80;

/**
* Direction, from where notes and queries slide to the screen.
*
* @since 3.1
*/
enum TSlidingMode
    {
    /** Sliding is disabled either by skin or compile time */
    ESlidingDisabled = 0,

    /** Slide from the CBA side */
    ESlidingFromCBA,

    /** Slide from left */
    ESlidingFromLeft,

    /** Slide from topleft */
    ESlidingFromTopLeft, 

    /** Slide from top */
    ESlidingFromTop,

    /** Slide from topright */
    ESlidingFromTopRight, 

    /** Slide from right */
    ESlidingFromRight, 

    /** Slide from bottomright */
    ESlidingFromBottomRight, 

    /** Slide from bottom */
    ESlidingFromBottom, 

    /** Slide from bottomleft */
    ESlidingFromBottomLeft,

    /** Slide from random direction (any of the 8 directions) */
    ESlidingFromRandom
    };


// FORWARD DECLARATIONS
class MAknsSkinInstance;
class MAknsControlContext;
class CWindowGc;
class CFbsBitGc;
class CCoeControl;

// CLASS DECLARATION

/**
* Static utility class to support Avkon Skins drawing operations.
* AknsDrawUtils provides utility methods to perform skin-aware drawing
* operations, such as background drawing.
*
* This is a public static class with exported functions.
* The class is not intended for derivation outside the library.
*
* @lib AknSkins.lib
*
* @since 2.0
*/
class AknsDrawUtils
    {
    public: // New functions        

        /**
        * Returns pointer to the current control context.
        * If aMop parameter is specified retrieves the nearest control context
        * in control hierarchy. If none is found (or @c NULL parameter was
        * given) returns @c NULL.
        *
        * @since 2.0
        *
        * @param aMop Object provider to be used to find the control context
        *   or @c NULL.
        *
        * @return Pointer to the nearest control context or @c NULL if none 
        *   was found.
        */
        IMPORT_C static MAknsControlContext* ControlContext( 
            const MObjectProvider* aMop );

        /**
        * Returns pointer to the control context of the parent of the given
        * control. The context possibly supplied by the control itself is ignored.
        *
        * @since 2.6
        *
        * @param aControl Pointer to CCoeControl or @c NULL.
        *
        * @return Pointer to the nearest control context of the parent control
        *   or @c NULL if none was found.
        */
        IMPORT_C static MAknsControlContext* ControlContextOfParent( 
            const CCoeControl* aControl );

        /**
        * Draws background with assumed origin.
        * Draws bacground to the specified rectangle. Origin is assumed
        * to be (0,0). This overload can not be used with parent absolute 
        * layouts.
        *
        * See @c DrawBackground for details on chained layouts.
        *
        * @since 2.0
        *
        * @param aInstance Pointer to skin instance as obtained from
        *   AknsUtils::SkinInstance(). If @c NULL rectangle is cleared
        *   without bitmap.
        *
        * @param aContext Control context to obtain context specific 
        *   information about background drawing. If @c NULL and skin
        *   instance was given, default parameters are used.
        *
        * @param aGc Graphics context to be used for drawing.
        *
        * @param aRect Rectangle to be drawn.
        *
        * @return ETrue if background was drawn with a bitmap, EFalse
        *   otherwise.
        */
        IMPORT_C static TBool Background( MAknsSkinInstance* aInstance,
            MAknsControlContext* aContext, CWindowGc& aGc, const TRect& aRect );

        /**
        * Draws background with proper origin.
        * Draws bacground to the specified rectangle. The origin is queried
        * from the control position list (if given using 
        * AknsUtils::RegisterControlPosition). If not found, the origin is
        * queried from the given control, which may result in a window server
        * flush.
        *
        * See @c DrawBackground for details on chained layouts.
        *
        * @since 2.0
        *
        * @param aInstance Pointer to skin instance as obtained from
        *   AknsUtils::SkinInstance(). If @c NULL rectangle is cleared
        *   without bitmap.
        *
        * @param aContext Control context to obtain context specific 
        *   information about background drawing. Must be specified, if
        *   aInstance is not @c NULL.
        *
        * @param aControl Control that knows the current window.
        *   Must be specified if parent absolute layout can be used,
        *   otherwise @c NULL may be given.
        *
        * @param aGc Graphics context to be used for drawing.
        *
        * @param aRect Rectangle to be drawn.
        *
        * @return ETrue if background was drawn with a bitmap, EFalse
        *   otherwise. Note that many scalable skins implicitly define
        *   background bitmaps for seemingly blank areas.
        */
        IMPORT_C static TBool Background( MAknsSkinInstance* aInstance,
            MAknsControlContext* aContext, const CCoeControl* aControl,
            CWindowGc& aGc, const TRect& aRect );

        /**
        * Draws background with proper origin and drawing parameters.
        * Draws bacground to the specified rectangle. The origin is queried
        * from the control position list (if given using 
        * AknsUtils::RegisterControlPosition). If not found, the origin is
        * queried from the given control, which may result in a window server
        * flush. Drawing parameters may be used to control drawing.
        *
        * See @c DrawBackground for details on chained layouts.
        *
        * @since 2.0
        *
        * @param aInstance Pointer to skin instance as obtained from
        *   AknsUtils::SkinInstance(). If @c NULL rectangle is cleared
        *   without bitmap.
        *
        * @param aContext Control context to obtain context specific 
        *   information about background drawing. Must be specified, if
        *   aInstance is not @c NULL.
        *
        * @param aControl Control that knows the current window.
        *   Must be specified if parent absolute layout can be used,
        *   otherwise @c NULL may be given.
        *
        * @param aGc Graphics context to be used for drawing.
        *
        * @param aRect Rectangle to be drawn.
        *
        * @param aDrawParam Bitwise combination of drawing parameters. 
        *   @c KAknsDrawParamDefault should be used if no special handling 
        *   is required.
        *
        * @return ETrue if background was drawn with a bitmap, EFalse
        *   otherwise. Note that many scalable skins implicitly define
        *   background bitmaps for seemingly blank areas.
        */
        IMPORT_C static TBool Background( MAknsSkinInstance* aInstance,
            MAknsControlContext* aContext, const CCoeControl* aControl,
            CWindowGc& aGc, const TRect& aRect, const TInt aDrawParam );

        /**
        * Draws background to the given graphics context.
        * The origin is queried from the control position list (if given using
        * AknsUtils::RegisterControlPosition). If not found, the origin is
        * queried from the given control, which may result in a window server
        * flush.
        *
        * If background contains multiple layers, they are drawn in the
        * sequence specified by the context. If multiple contexts are chained
        * (using @c SetParentContext), they are drawn in reverse order, i.e.
        * the context given as parameter to this method call is drawn last.
        *
        * Drawing parameter KAknsDrawParamNoClearUnderImage is automatically
        * assumed for all the chained contexts, except the deepest one.
        *
        * @since 2.0
        *
        * @param aInstance Pointer to skin instance as obtained from
        *   AknsUtils::SkinInstance(). If @c NULL rectangle is cleared
        *   without bitmap.
        *
        * @param aContext Control context to obtain context specific 
        *   information about background drawing. Must be specified, if
        *   aInstance is not @c NULL.
        *
        * @param aControl Control that knows the current window.
        *   Must be specified if parent absolute layout can be used,
        *   otherwise @c NULL may be given.
        *
        * @param aGc Graphics context to be used for drawing.
        *
        * @param aDstPos Destination position (top-left corner of the area
        *   to be drawn) in graphics context coordinate system.
        *
        * @param aControlRect Rectangle (in the control coordinate system) 
        *   to be drawn.
        *
        * @param aDrawParam Bitwise combination of drawing parameters. 
        *   @c KAknsDrawParamDefault should be used if no special handling 
        *   is required.
        *
        * @return ETrue if background was drawn with a bitmap, EFalse
        *   otherwise. Note that many scalable skins implicitly define
        *   background bitmaps for seemingly blank areas.
        */
        IMPORT_C static TBool DrawBackground( MAknsSkinInstance* aInstance,
            MAknsControlContext* aContext, const CCoeControl* aControl,
            CBitmapContext& aGc, const TPoint& aDstPos,
            const TRect& aControlRect, const TInt aDrawParam );

        /**
        * Draws background between rects.
        * Draws bacground between specified rectangles. Origin is assumed
        * to be (0,0).
        *
        * See @c DrawBackground for details on chained layouts.
        *
        * @since 2.0
        *
        * @param aInstance Pointer to skin instance as obtained from
        *   AknsUtils::SkinInstance(). If @c NULL rectangle is cleared
        *   without bitmap.
        *
        * @param aContext Control context to obtain context specific 
        *   information about background drawing. If @c NULL and skin
        *   instance was given, default parameters are used.
        *
        * @param aGc Graphics context to be used for drawing.
        *
        * @param aOuterRect Outer rectangle.
        *
        * @param aInnerRect Inner rectangle.
        *
        * @return ETrue if background was drawn with a bitmap, EFalse
        *   otherwise. Note that many scalable skins implicitly define
        *   background bitmaps for seemingly blank areas.
        */
        IMPORT_C static TBool BackgroundBetweenRects( 
            MAknsSkinInstance* aInstance,
            MAknsControlContext* aContext, CWindowGc& aGc, 
            const TRect& aOuterRect,const TRect& aInnerRect );

        /**
        * Draws background between rects.
        * Draws bacground between specified rectangles. 
        *
        * See @c DrawBackground for details on chained layouts.
        *
        * @since 2.0
        *
        * @param aInstance Pointer to skin instance as obtained from
        *   AknsUtils::SkinInstance(). If @c NULL rectangle is cleared
        *   without bitmap.
        *
        * @param aContext Control context to obtain context specific 
        *   information about background drawing. Must be specified if
        *   aInstance is not @c NULL.
        *
        * @param aControl Control that knows the current window.
        *   Must be specified if parent absolute layout can be used,
        *   otherwise @c NULL may be given.
        *
        * @param aGc Graphics context to be used for drawing.
        *
        * @param aOuterRect Outer rectangle.
        *
        * @param aInnerRect Inner rectangle.
        *
        * @return ETrue if background was drawn with a bitmap, EFalse
        *   otherwise. Note that many scalable skins implicitly define
        *   background bitmaps for seemingly blank areas.
        */
        IMPORT_C static TBool BackgroundBetweenRects( 
            MAknsSkinInstance* aInstance,
            MAknsControlContext* aContext, const CCoeControl* aControl, 
            CWindowGc& aGc, 
            const TRect& aOuterRect,const TRect& aInnerRect );

        /**
        * Draws background between rects.
        * Draws bacground between specified rectangles with drawing parameters. 
        *
        * @since 2.0
        *
        * @param aInstance Pointer to skin instance as obtained from
        *   AknsUtils::SkinInstance(). If @c NULL rectangle is cleared
        *   without bitmap.
        *
        * @param aContext Control context to obtain context specific 
        *   information about background drawing. Must be specified if
        *   aInstance is not @c NULL.
        *
        * @param aControl Control that knows the current window.
        *   Must be specified if parent absolute layout can be used,
        *   otherwise @c NULL may be given.
        *
        * @param aGc Graphics context to be used for drawing.
        *
        * @param aOuterRect Outer rectangle.
        *
        * @param aInnerRect Inner rectangle.
        *
        * @param aDrawParam Bitwise combination of drawing parameters. 
        *   @c KAknsDrawParamDefault should be used if no special handling 
        *   is required.
        *
        * @return ETrue if background was drawn with a bitmap, EFalse
        *   otherwise. Note that many scalable skins implicitly define
        *   background bitmaps for seemingly blank areas.
        */
        IMPORT_C static TBool BackgroundBetweenRects( 
            MAknsSkinInstance* aInstance,
            MAknsControlContext* aContext, const CCoeControl* aControl, 
            CWindowGc& aGc, 
            const TRect& aOuterRect, const TRect& aInnerRect, 
            const TInt aDrawParam );

        /**
        * Determines whether background drawing would be done with
        * a bitmap (deprecated).
        *
        * @param aInstance Pointer to skin instance. If @c NULL,
        *   method returns EFalse.
        *
        * @param aContext Control context, or @c NULL if no context 
        *   is used. Note that absence of control context affects
        *   the result.
        *
        * @return @c ETrue if background would be drawn with a bitmap,
        *   @c EFalse otherwise. If a scalable skin is currently active,
        *   the return value is undefined, and does not necessarily
        *   reflect the return value of the actual drawing operation.
        *
        * @deprecated This method is deprecated as of release 2.8.
        *   Use the return values of background drawing functions to
        *   determine whether the background was drawn with skinned
        *   content. The return value is always ETrue starting from
        *   rel 3.1
        */
        IMPORT_C static TBool HasBitmapBackground(
            MAknsSkinInstance* aInstance,
            MAknsControlContext* aContext );

        /**
        * Draws a cached image (with its attributes specified in the skin)
        * to the given rectangle.
        *
        * @param aInstance Pointer to the skin instance. If @c NULL,
        *   the method returns immediately.
        *
        * @param aGc Graphics context to be used for drawing.
        *
        * @param aRect Rectangle specifying the pane used for drawing. The
        *   image is laid out within the rectangle.
        *
        * @param aID Item ID of the image to be drawn.
        */
        IMPORT_C static void DrawCachedImage( MAknsSkinInstance* aInstance,
            CWindowGc& aGc, const TRect& aRect, const TAknsItemID& aID );

        /**
        * Draws a cached image (with its attributes specified in the skin)
        * to the given rectangle in an off-screen graphics context.
        *
        * @since 2.8
        *
        * @param aInstance Pointer to the skin instance. If @c NULL,
        *   the method returns immediately.
        *
        * @param aGc Bitmapped graphics context to be used for drawing.
        *
        * @param aRect Rectangle specifying the pane used for drawing. The
        *   image is laid out within the rectangle.
        *
        * @param aID Item ID of the image to be drawn.
        */
        IMPORT_C static void DrawCachedImage( MAknsSkinInstance* aInstance,
            CFbsBitGc& aGc, const TRect& aRect, const TAknsItemID& aID );

        /**
        * Draws a frame (with cached images) to the specified area.
        *
        * @param aInstance Pointer to the skin instance. If @c NULL, the 
        *   method returns EFalse.
        *
        * @param aGc Graphics context to be used for drawing.
        *
        * @param aOuterRect Outer rectangle of the frame. Frame elements
        *   will be drawn within this rectangle.
        *
        * @param aInnerRect Inner rectangle of the frame. Frame center 
        *   will be drawn within this rectangle.
        *
        * @param aFrameID Item ID of the entire frame.
        *
        * @param aCenterID Item ID of the center part of the frame. If
        *   @c KAknsIIDNone, no center will be drawn. If @c KAknsIIDDefault,
        *   the default value from the frame itself will be used. Other values,
        *   the item to be used for the center part. If the frame is 
        *   specified as 1 part graphics in the skin instead of 9 part
        *   graphics, this parameter has no effect.
        *
        * @return EFalse, if the frame was not drawn at all. ETrue, if the
        *   frame was (at least partially) drawn.
        */
        IMPORT_C static TBool DrawFrame( MAknsSkinInstance* aInstance,
            CWindowGc& aGc, const TRect& aOuterRect, const TRect& aInnerRect, 
            const TAknsItemID& aFrameID, const TAknsItemID& aCenterID );

        /**
        * Prepares the frame graphics for drawing. This function should be
        * called when the frame sizes are known and in places where Flushing
        * the Window server buffer will not cause flicker. For example, a
        * good place to call PrepareFrame() would be controls SizeChanged 
        * function. Altough its not mandatory to call PrepareFrame()
        * before DrawFrame(), it's highly recommended in order to avoid
        * unnecessary flushes in the middle of the actual drawing routine. 
        *
        * Note that the rect parameters must be exactly the same for
        * PrepareFrame and subsequent DrawFrame calls. Otherwise the 
        * DrawFrame functions will cause a flush, which leads
        * to flicker.
        *
        * @since 2.8
        *
        * @param aInstance Pointer to the skin instance. If @c NULL, the 
        *   method returns EFalse.
        *
        * @param aOuterRect Outer rectangle of the frame. Frame elements
        *   are scaled to this size.
        *
        * @param aInnerRect Inner rectangle of the frame. Frame center 
        *   is scaled to this size
        *
        * @param aFrameID Item ID of the entire frame.
        *
        * @param aCenterID Item ID of the center part of the frame. If
        *   @c KAknsIIDNone, no center part will be prepared.
        *   If @c KAknsIIDDefault, the default value from the frame
        *   itself will be used. Other values, the item to be used 
        *   for the center part. If the frame is specified as 1 part
        *   graphics in the skin instead of 9 part graphics, this
        *   parameter has no effect.
        *
        * @return EFalse, if were nothing to prepare. ETrue, if the
        *   frame was (at least partially) prepared.
        */
        IMPORT_C static TBool PrepareFrame( MAknsSkinInstance* aInstance,
            const TRect& aOuterRect, const TRect& aInnerRect, 
            const TAknsItemID& aFrameID, const TAknsItemID& aCenterID);

        /**
        * Draws a frame (with cached images) to the specified area
        * in an off-screen graphics context.
        *
        * @since 2.8
        *
        * @param aInstance Pointer to the skin instance. If @c NULL, the 
        *   method returns EFalse.
        *
        * @param aGc Bitmapped graphics context to be used for drawing.
        *
        * @param aOuterRect Outer rectangle of the frame. Frame elements
        *   will be drawn within this rectangle.
        *
        * @param aInnerRect Inner rectangle of the frame. Frame center 
        *   will be drawn within this rectangle.
        *
        * @param aFrameID Item ID of the entire frame.
        *
        * @param aCenterID Item ID of the center part of the frame. If
        *   @c KAknsIIDNone, no center will be drawn. If @c KAknsIIDDefault,
        *   the default value from the frame itself will be used. Other values,
        *   the item to be used for the center part. If unsure, specify
        *   @c KAknsIIDDefault. If the frame is specified as 1 part 
        *   graphics in the skin instead of 9 part graphics, this 
        *   parameter has no effect.
        *
        * @param aDrawParam Bitwise combination of drawing parameters. 
        *   @c KAknsDrawParamDefault should be used if no special handling 
        *   is required.
        *
        * @return EFalse, if the frame was not drawn at all. ETrue, if the
        *   frame was (at least partially) drawn.
        */
        IMPORT_C static TBool DrawFrame( MAknsSkinInstance* aInstance,
            CFbsBitGc& aGc, const TRect& aOuterRect, const TRect& aInnerRect, 
            const TAknsItemID& aFrameID, const TAknsItemID& aCenterID,
            const TInt aDrawParam );

        /**
        * Draws a frame (with cached images) to the specified area
        * in an off-screen graphics context.
        *
        * @since 2.8
        *
        * @param aInstance Pointer to the skin instance. If @c NULL, the 
        *   method returns EFalse.
        *
        * @param aGc Bitmapped graphics context to be used for drawing.
        *
        * @param aOuterRect Outer rectangle of the frame. Frame elements
        *   will be drawn within this rectangle.
        *
        * @param aInnerRect Inner rectangle of the frame. Frame center 
        *   will be drawn within this rectangle.
        *
        * @param aFrameID Item ID of the entire frame.
        *
        * @param aCenterID Item ID of the center part of the frame. If
        *   @c KAknsIIDNone, no center will be drawn. If @c KAknsIIDDefault,
        *   the default value from the frame itself will be used. Other values,
        *   the item to be used for the center part. If unsure, specifi
        *   @c KAknsIIDDefault. If the frame is specified as 1 part 
        *   graphics in the skin instead of 9 part graphics, this
        *   parameter has no effect.
        *
        * @return EFalse, if the frame was not drawn at all. ETrue, if the
        *   frame was (at least partially) drawn.
        */
        IMPORT_C static TBool DrawFrame( MAknsSkinInstance* aInstance,
            CFbsBitGc& aGc, const TRect& aOuterRect, const TRect& aInnerRect, 
            const TAknsItemID& aFrameID, const TAknsItemID& aCenterID );

        /**
        * Draws the specified part of the frame (with a cached image) to the
        * specified rectangle.
        *
        * @par Compatibility note:
        * Prior to Series 60 release 2.8, the entire outer rectangle could
        * be given as the rectangle of a corner part. Due to scalable UI
        * compatibility, this is no longer supported in release 2.8, and thus
        * the exact corner rectangle is required. This funtion may not
        * function correctly if the skin specifies the frame as 1 part
        * graphics.
        *
        * @param aInstance Pointer to the skin instance. If @c NULL, the 
        *   method returns @c EFalse.
        *
        * @param aGc Graphics context to be used for drawing.
        *
        * @param aRect Rectangle for drawing. This must be the rectangle
        *   of the specific part of the drawn that will be drawn, e.g.
        *   top-left corner rectangle if the top-left corner is being drawn.
        *
        * @param aFrameID Item ID of the entire frame.
        *
        * @param aFrameElement Element (index) of the frame element to
        *   be drawn.
        *
        * @return ETrue, if the element was drawn. EFalse otherwise.
        */
        IMPORT_C static TBool DrawFramePart( MAknsSkinInstance* aInstance,
            CWindowGc& aGc, const TRect& aRect, const TAknsItemID& aFrameID,
            const TAknsFrameElementIndex aFrameElement );

        /**
        * Returns a boolean value indicating whether list separator lines
        * should be drawn.
        *
        * This method checks:
        *  - The value of @c KAknsIIDPropertyListSeparatorLines property.
        *  - The presence of (non-scalable) column bitmaps.
        *       If found, @c EFalse is returned.
        *  - The presence of generic list background (non-scalable).
        *       If found, @c EFalse is returned.
        *
        * Note that the exact internal implementation of the checks is
        * subject to change.
        *
        * @since 2.8
        *
        * @param aInstance Pointer to the skin instance. If @c NULL, 
        *   the method returns @c ETrue.
        *
        * @return @c ETrue, if list separator lines should drawn. 
        *   @c EFalse, if list separator lines should not be drawn
        *   and, consequently, list column and slice bitmaps (if any) from the
        *   skin content should be drawn.
        */
        IMPORT_C static TBool IsListSeperatorLines(
            MAknsSkinInstance* aInstance );

        /**
        * Returns an enum value indicating the way notes and queries appear
        * to the screen (sliding animation)
        *
        * @since 3.1
        *
        * @param aInstance Pointer to the skin instance. If @c NULL, 
        *   the method returns @c ESlidingDisabled.
        *
        * @return @c Sliding mode from enumeration TSlidingMode
        */
        IMPORT_C static TSlidingMode SlidingMode(
            MAknsSkinInstance* aInstance );

    private: // Prohibited constructors and destructor
        
        // Construction prohibited (static class)
        AknsDrawUtils();
        // Destruction prohibited (static class)
        ~AknsDrawUtils();
    };

#endif // AKNSDRAWUTILS_H

// End of File
