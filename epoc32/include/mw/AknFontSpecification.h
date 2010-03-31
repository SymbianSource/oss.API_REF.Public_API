/*
* Copyright (c) 2002-2008 Nokia Corporation and/or its subsidiary(-ies).
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
* Description: 
*
*/



#ifndef AKNFONTSPECIFICATION_H
#define AKNFONTSPECIFICATION_H

#include <gdi.h>
#include <AknFontCategory.hrh>
#include <babitflags.h>

/**
* Object representing the series 60 requirements for a font. It contains information
* from the layout specification that fonts bound to the given font id should honor.
* 
* It formst the basis of the request to font provisioning to provide a suitable font
*
*  @lib FontUtils.lib
*  @since 2.8
*
*  @internal
*/
class TAknFontSpecification
    {
public:

    enum TAknFontSpecificationUnits
        {
        EPixels = 0,
        ETwips
        };

public:
    /**
    * Construct font specification from Font ID.
    *
    *@param aFontId     Series 60 font id from which to create a font.
    */
    IMPORT_C TAknFontSpecification( TInt aFontId );

    /**
    * Construct the font specifiation from Symbian OS TFontSpec and MGraphicsDeviceMap
    * The Symbian OS TFontSpec must be set in Twips.  The MGraphicsDeviceMap is used to convert to
    * pixels for the text pane height.
    *
    * Note that the units policy during and in effect at the end of this constructor is EPixels.
    * 
    * Note that the TTypeface part of the TFontSpec is lost in this construction
    *
    * @param aCategory      Series 60 Font category to use
    * @param aFontSpec      Provides the metrics and Style information to use for the match
    * @param aDeviceMap     Device map used to convert the aFontSpec's twips to pixels
    * 
    */
    IMPORT_C TAknFontSpecification(  
        TAknFontCategory aCategory, 
        const TFontSpec& aFontSpec, 
        const MGraphicsDeviceMap* aDeviceMap );
    
    /**
    * Sets the Series 60 font category.
    * 
    * @param aCategory  New category to set.
    */
    IMPORT_C void SetFontCategory( TAknFontCategory aCategory );
    
    /**
    * Series 60 Layout Specification font category: 
    *   Primary, Secondary, Title etc.
    *
    * @return   Series 60 font category
    */
    IMPORT_C TAknFontCategory FontCategory() const;

    /**
    * The requested height for a font. This represents the maximum vertical range that can be 
    * guraranteed to draw in the text pane.
    *
    * Note also that this value is the height requested by layout or the client, and might not correspond to 
    * the design height, ascent + descent, or max height reported by the attached font. See the APIs
    * CAknLayoutFont::TextPaneTopToBaseline and BaselineToTextPaneBottom. 
    *
    * If TextPaneHeightIsDesignHeight() is EFalse, then the font will be requested to fit entirely within
    * this range.  
    *
    * If TextPaneHeightIsDesignHeight() is set, then this value is passed to the font request as the font
    * design height, in which case the font may not render entirely within the "text pane height".
    * 
    * @param aNewHeight     Text pane height to be used by the font.
    */
    IMPORT_C void SetTextPaneHeight( TInt aNewHeight );

    /**
    * The requested height of the font. This represents the maximum vertical range that can be 
    * guaranteed to draw in the text pane.
    *
    * Note also that this value is the height requested by layout or the client, and may not correspond to 
    * the design height, ascent + descent, or max height reported by the attached font. See the APIs
    * CAknLayoutFont::TextPaneTopToBaseline and BaselineToTextPaneBottom. 
    * 
    * If TextPaneHeightIsDesignHeight() is EFalse, then the font is to be requested to fit entirely within
    * this range.  
    *
    * If TextPaneHeightIsDesignHeight() is set, then this value is passed to the font request as the font
    * design height, in which case the font may not render entirely within the "text pane height".
    *
    * Depending upon the value of TextPaneHeightIsInTwips(), the value returned is in Pixels or Twips. 
    * Note that calling SetTextPaneHeightIsInTwips() does not perform any conversion of the text pane height;
    * It retains its set value.
    * 
    * @return Requested text pane height.
    */
    IMPORT_C TInt TextPaneHeight() const;
       
    /**
    * Set the stoke weight to request using the Symbian OS stroke weight enumeration. 
    *
    * @aParam aWeight   The stroke weight. 
    */
    IMPORT_C void SetWeight( TFontStrokeWeight aWeight );
    
    /**
    * Sets the posture (e.g. upright, italic) of requested font using the Symbian OS enumeration.
    * @param aPostore   posture to request
    */
    IMPORT_C void SetPosture( TFontPosture aPosture );
    
    /**
    * Sets the policy to use in requesting the font height. Fonts may be requested either by "design height" (which is 
    * usually approximately the ascent + descent) or by maximum height.
    * If false, this setting means the number set by SetTextPaneHeight is intended to match
    * the font's maximum extent; all characters will fit within the text pane.
    * If true, then the value passed by SetTextPaneHeight will be used to request design height.
    *
    * This API has no effect if called on a TAknFontSpecification that has already been bound to a font
    *
    * The default value upon construction is EFalse.
    *
    * @param aTextPaneHeightIsDesignHeight  If EFalse, ensure that the font fits entirely
    *                                       within the text pane height
    *                                       If not EFalse, then the text pane height is treated as the font
    *                                       design height.
    */
    IMPORT_C void SetTextPaneHeightIsDesignHeight( TBool aTextPaneHeightIsDesignHeight );
    
    /**
    * Accessor API for the height policy.
    * 
    * @return   EFalse if text pane height is to be the maximum font extent.
    *           ETrue if text pane height is to be treated as the font's design height 
    */
    IMPORT_C TBool TextPaneIsDesignHeight() const;

    /**
    * Sets a flag indicating to font requests whether they should insist upon an exact match.
    * Whether a font match is treated as exact or not depends upon various things, including:
    *     - if a request is made via a generic font family or via a font family enumeration, then typeface is not tested for "exactness"
    *     - fonts may be forced to be rendered at certain sizes (within a small number of pixels). This still counts as an exact match
    * 
    * The default value upon construction is EFalse;
    *
    * @param aRequiresExactMatch       
    */
    IMPORT_C void SetExactMatchRequired ( TBool aRequiresExactMatch );
    
    /**
    * Accessor API for whether an exact match is required for the font (See SetExactMatchRequired() )
    *
    * @return   whether an exact match is required or not.
    */
    IMPORT_C TBool ExactMatchRequired() const;

    /**
    * Sets the units for the Text Pane Height APIs.  Note that calling this API does not 
    * result in the numerical value of the text pane height being recalculated. 
    * Upon construction, TAknFontSpecification objects store TextPaneHeight in pixels. 
    * If you then call SetUnits to Twips, you will also have to call SetTextPaneHeight to pass in the new
    * (twips) value. 
    *
    * @param aUnits
    */
    IMPORT_C void SetUnits( TAknFontSpecification::TAknFontSpecificationUnits aUnits );

    /**
    * Accessor API for the units being used.
    *
    * @return units currently being used.
    */
    IMPORT_C TAknFontSpecification::TAknFontSpecificationUnits Units() const;     
   
    /**
    * Accessor for the requested weight
    *
    * @return Symbian OS stroke weight enumeration (e.g. EStrokeWeightBold)
    */
    IMPORT_C TFontStrokeWeight Weight() const ;
    
    /**
    * Accessor for the requested posture
    *
    * @return Symbian OS font posture enumeration (e.g. EPostureItalic)
    */
    IMPORT_C TFontPosture Posture() const;

    /**
    * Accessor for the requested outline effect 
    *
    * @since 5.0
    *
    * @return ETrue iff outline font effect has been requested
    */
    IMPORT_C TBool IsOutlineEffectOn() const;

private:
    void LoadAnyCDLFontInstanceL();

private:
    TAknFontCategory iBaseFontCategory;
    TInt iTextPaneHeight;
    // Symbian OS Font Style object convenient for holding style info
    TFontStyle iRequiredStyle;
    TBitFlags iFlags;
    TInt iSpare2; 
    };

#endif
// End of File
