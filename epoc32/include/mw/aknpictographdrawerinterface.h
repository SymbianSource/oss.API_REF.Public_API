/*
* Copyright (c) 2002 Nokia Corporation and/or its subsidiary(-ies).
* All rights reserved.
* This component and the accompanying materials are made available
* under the terms of the License "Symbian Foundation License v1.0" to Symbian Foundation members and "Symbian Foundation End User License Agreement v1.0" to non-members
* which accompanies this distribution, and is available
* at the URL "http://www.symbianfoundation.org/legal/licencesv10.html".
*
* Initial Contributors:
* Nokia Corporation - initial contribution.
*
* Contributors:
*
* Description:  Pictograph drawer interface.
*
*
*/


#ifndef AKN_PICTOGRAPH_DRAWER_INTERFACE_H
#define AKN_PICTOGRAPH_DRAWER_INTERFACE_H

// INCLUDES
#include <e32std.h>
#include <gdi.h>

// CONSTANTS

enum TAknPictographHeight
    {
    EHeight12 = 0,
    EHeight16 = 1,
    EHeight18 = 2,
    EHeight24 = 3,
    EHeight30 = 4
    };

enum TAknPictographDrawingMode
    {
    EDrawingModeNormal = 0,
    EDrawingModeWhite  = 1
    };

// FORWARD DECLARATIONS

class CBitmapContext;
class CFont;

// CLASS DECLARATION

class MAknPictographAnimatorCallBack
    {
    public:
        /**
        * This function is called when a redraw is needed for drawing
        * new frames of animated pictographs. It should
        *
        * 1) Draw or clear the background of pictographs
        * 2) If the pictographs are amongst text, draw the text
        * 3) Draw the pictographs using MAknPictographDrawer interface
        *
        * In many cases, it is sufficient to implement this simply by
        * calling CCoeControl::DrawNow for the appropriate control.
        */
        virtual void DrawPictographArea() = 0;
    };

/**
* Pictograph drawer interface
*
*  @lib N/A
*  @since 2.6
*/
NONSHARABLE_CLASS(MAknPictographDrawer) 
	{
    public:  // Constructors and destructor

        /**
        * Destructor.
        */
        inline virtual ~MAknPictographDrawer() {};

    public: // New functions

        /**
        * Returns a heap descriptor filled with all supported
        * pictograph codes.
        * They are sorted in ascending pictograph code order.
        * Ownership of the returned object is transferred to the caller.
        *
        * @since 2.6
        * @return Heap descriptor filled with all supported
        *         pictograph codes.
        */
        virtual HBufC* SupportedPictographCodesL() const = 0;

        /**
        * Tells whether the character is in the pictograph code range.
        *
        * @since 2.6
        * @param aCode Character code in Unicode.
        * @return ETrue if in pictograph code range, EFalse if not.
        */
        virtual TBool IsPictograph( TText aCode ) const = 0;

        /**
        * Tells whether the text contains any pictographs.
        *
        * @since 2.6
        * @param aText Text.
        * @return ETrue if the text contains any pictographs, EFalse if not.
        */
        virtual TBool ContainsPictographs( const TDesC& aText ) const = 0;

        /**
        * Draws pictograph bitmap in the given position.
        * This method sets aGc to use CGraphicsContext::ENullBrush.
        *
        * @since 2.6
        * @param aGc Graphics context.
        * @param aTopLeft Top left coordinates of the rendering position .
        * @param aCode Pictograph code in Unicode.
        * @param aHeight Pictograph height.
        */
	    virtual void DrawPictograph(
            CBitmapContext& aGc,
            const TPoint& aTopLeft,
            TText aCode,
            TAknPictographHeight aHeight ) const = 0;

        /**
        * Draws pictograph bitmap centered in the given rect.
        * This method sets aGc to use CGraphicsContext::ENullBrush.
        *
        * @since 2.6
        * @param aGc Graphics context.
        * @param aRect Rectangle, where the pictograph is centered in.
        * @param aCode Pictograph code in Unicode.
        * @param aHeight Pictograph height.
        */
	    virtual void DrawPictograph(
            CBitmapContext& aGc,
            const TRect& aRect,
            TText aCode,
            TAknPictographHeight aHeight ) const = 0;

        /**
        * Draws pictograph bitmap centered in the given rect,
        * clipped with clipping rect.
        * This method sets aGc to use CGraphicsContext::ENullBrush.
        *
        * @since 2.6
        * @param aGc Graphics context.
        * @param aRect Rectangle, where the pictograph is centered in.
        * @param aClipRect Clipping rectangle.
        * @param aCode Pictograph code in Unicode.
        * @param aHeight Pictograph height.
        */
	    virtual void DrawPictograph(
            CBitmapContext& aGc,
            const TRect& aRect,
            const TRect& aClipRect,
            TText aCode,
            TAknPictographHeight aHeight ) const = 0;

        /**
        * Draws text using CGraphicsContext::DrawText and then
        * draws pictographs on top of that.
        *
        * Suitable pictograph height is chosen based on aFont.
        *
        * The graphics context aGc must be set to use font aFont
        * before calling this method.
        *
        * This method sets aGc to use CGraphicsContext::ENullBrush.
        *
        * @since 2.6
        * @param aGc Graphics context.
        * @param aFont Used font.
        * @param aText Text.
        * @param aPosition Text baseline coordinates of the starting position.
        */
        virtual void DrawText(
            CBitmapContext& aGc,
            const CFont& aFont,
            const TDesC& aText,
            const TPoint& aPosition ) const = 0;

        /**
        * Draws text using CGraphicsContext::DrawText and then
        * draws pictographs on top of that.
        *
        * Suitable pictograph height is chosen based on aFont.
        *
        * The graphics context aGc must be set to use font aFont
        * before calling this method.
        *
        * This method sets aGc to use CGraphicsContext::ENullBrush.
        *
        * @since 2.6
        * @param aGc Graphics context.
        * @param aFont Used font.
        * @param aText Text.
        * @param aBox Rectangle, where the text is rendered.
        * @param aBaselineOffset Offset from the top of the rectangle to
        *   the baseline to the text.
        * @param aAlignment Text alignment.
        * @param aLeftMargin The left margin for left-aligned text, or the right
        *   margin for right-aligned text
        */
        virtual void DrawText(
            CBitmapContext& aGc,
            const CFont& aFont,
            const TDesC& aText,
            const TRect& aBox,
            TInt aBaselineOffset,
            CGraphicsContext::TTextAlign aAlignment =
                CGraphicsContext::ELeft,
            TInt aLeftMargin = 0 ) const = 0;

        /**
        * Draws pictographs that are encountered in the text.
        * Suitable pictograph height is chosen based on aFont.
        * This method sets aGc to use CGraphicsContext::ENullBrush.
        *
        * @since 2.6
        * @param aGc Graphics context.
        * @param aFont Used font.
        * @param aText Text.
        * @param aPosition Text baseline coordinates of the starting position.
        */
        virtual void DrawPictographsInText(
            CBitmapContext& aGc,
            const CFont& aFont,
            const TDesC& aText,
            const TPoint& aPosition ) const = 0;

        /**
        * Draws pictographs that are encountered in the text.
        * This method sets aGc to use CGraphicsContext::ENullBrush.
        *
        * @since 2.6
        * @param aGc Graphics context.
        * @param aFont Used font.
        * @param aText Text.
        * @param aBox Rectangle, where the text is rendered.
        * @param aBaselineOffset Offset from the top of the rectangle to
        *   the baseline to the text.
        * @param aAlignment Text alignment.
        * @param aLeftMargin The left margin for left-aligned text, or the right
        *   margin for right-aligned text
        */
        virtual void DrawPictographsInText(
            CBitmapContext& aGc,
            const CFont& aFont,
            const TDesC& aText,
            const TRect& aBox,
            TInt aBaselineOffset,
            CGraphicsContext::TTextAlign aAlignment =
                CGraphicsContext::ELeft,
            TInt aLeftMargin = 0 ) const = 0;

        /**
        * Tells whether the given pictograph is animated or not.
        *
        * @since 2.6
        * @param aCode Pictograph code in Unicode.
        */
        virtual TBool IsAnimated( TText aCode, TAknPictographHeight aHeight ) const = 0;

        /**
        * Tries to find a matching pictograph height for a given font.
        *
        * @since 2.8
        * @param aFont Used font.
        * @param aHeight Pictograph height.
        * @return KErrNone if a supported pictograph height is found that matches
        *         aFont otherwise returns KErrNotSupported
        */
        virtual TInt SelectPictographHeightForFont(
            const CFont& aFont,
            TAknPictographHeight& aHeight
            ) const = 0;

        /**
        * Sets the pictograph drawing mode for DrawPictograph calls. Other functions e.g.
        * DrawText, etc are unaffected by this function.
        * The drawing mode is set to EDrawingModeNormal by default.
        * Note: When drawing mode EDrawingModeWhite is set only a single DrawPictograph call
        * is supported per component->Draw() call.
        *
        * @since 2.8
        * @param aDrawingMode the new pictograph drawing mode to be used.
        * @return the value of the previous pictograph drawing mode.
        */
        virtual TAknPictographDrawingMode SetPictographDrawingMode(
            TAknPictographDrawingMode aDrawingMode) = 0;
    };

#endif // AKN_PICTOGRAPH_DRAWER_INTERFACE_H
            
// End of File
