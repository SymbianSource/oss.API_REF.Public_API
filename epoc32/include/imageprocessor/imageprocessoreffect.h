// Copyright (c) 2008-2009 Nokia Corporation and/or its subsidiary(-ies).
// All rights reserved.
// This component and the accompanying materials are made available
// under the terms of "Eclipse Public License v1.0"
// which accompanies this distribution, and is available
// at the URL "http://www.eclipse.org/legal/epl-v10.html".
//
// Initial Contributors:
// Nokia Corporation - initial contribution.
//
// Contributors:
//
// Description:
//

/**
 @file
 @publishedAll 
 @released 
*/

#ifndef __IMAGE_PROCESSOR_EFFECT_H__
#define __IMAGE_PROCESSOR_EFFECT_H__

#include <e32base.h>
#include <imageprocessor/imageprocessor_uids.hrh>
#include <imageprocessor/imageprocessor.h>

namespace ImageProcessor
	{
	class CImageProcessorImpl;
	
	namespace Plugin
		{
		class MEffect;
		}
   	
   	//Effects Uids
	/** 
	Uid used to gain access to the Sepia effect. @see ImageProcessor::CImgProcessor::EffectL
	*/
	const TUid KEffectSepiaUid = {KEffectSepiaUidValue};
	/** 
	Uid used to gain access to the Grayscale effect. @see ImageProcessor::CImgProcessor::EffectL
	*/
	const TUid KEffectGrayscaleUid = {KEffectGrayscaleUidValue};
	/** 
	Uid used to gain access to the Negative effect. @see ImageProcessor::CImgProcessor::EffectL
	*/
	const TUid KEffectNegativeUid = {KEffectNegativeUidValue};
	/** 
	Uid used to gain access to the GrayscaleNegative effect. @see ImageProcessor::CImgProcessor::EffectL
	*/
	const TUid KEffectGrayscaleNegativeUid = {KEffectGrayscaleNegativeUidValue};
	/** 
	Uid used to gain access to the Oily effect. @see ImageProcessor::CImgProcessor::EffectL
	*/
	const TUid KEffectOilyUid = {KEffectOilyUidValue};
	/** 
	Uid used to gain access to the Paint effect. @see ImageProcessor::CImgProcessor::EffectL
	*/
	const TUid KEffectPaintUid = {KEffectPaintUidValue};
	/** 
	Uid used to gain access to the Milky effect. @see ImageProcessor::CImgProcessor::EffectL
	*/
	const TUid KEffectMilkyUid = {KEffectMilkyUidValue};
	/** 
	Uid used to gain access to the Fog effect. @see ImageProcessor::CImgProcessor::EffectL
	*/
	const TUid KEffectFogUid = {KEffectFogUidValue};
	/** 
	Uid used to gain access to the MirrorLeftToRight effect. @see ImageProcessor::CImgProcessor::EffectL
	*/
	const TUid KEffectMirrorLeftToRightUid = {KEffectMirrorLeftToRightUidValue};
	/** 
	Uid used to gain access to the MagicPen effect. @see ImageProcessor::CImgProcessor::EffectL
	*/
	const TUid KEffectMagicPenUid = {KEffectMagicPenUidValue};
	/** 
	Uid used to gain access to the Brightness effect. @see ImageProcessor::CImgProcessor::EffectL
	*/
	const TUid KEffectBrightnessUid = {KEffectBrightnessUidValue};
	/** 
	Uid used to gain access to the Sharpness effect. @see ImageProcessor::CImgProcessor::EffectL
	*/
	const TUid KEffectSharpnessUid = {KEffectSharpnessUidValue};
	/** 
	Uid used to gain access to the Rotation effect. @see ImageProcessor::CImgProcessor::EffectL
	*/
	const TUid KEffectRotationUid = {KEffectRotationUidValue};
	/** 
	Uid used to gain access to the Contrast effect. @see ImageProcessor::CImgProcessor::EffectL
	*/
	const TUid KEffectContrastUid = {KEffectContrastUidValue};
	/** 
	Uid used to gain access to the RgbColorAdjust effect. @see ImageProcessor::CImgProcessor::EffectL
	*/
	const TUid KEffectRgbColorAdjustUid = {KEffectRgbColorAdjustUidValue};
	/** 
	Uid used to gain access to the Emboss effect. @see ImageProcessor::CImgProcessor::EffectL
	*/
	const TUid KEffectEmbossUid = {KEffectEmbossUidValue};
	/** 
	Uid used to gain access to the Solarize effect. @see ImageProcessor::CImgProcessor::EffectL
	*/
	const TUid KEffectSolarizeUid = {KEffectSolarizeUidValue};
	/** 
	Uid used to gain access to the Posterize effect. @see ImageProcessor::CImgProcessor::EffectL
	*/
	const TUid KEffectPosterizeUid = {KEffectPosterizeUidValue};
	/** 
	Uid used to gain access to the Stamp effect. @see ImageProcessor::CImgProcessor::EffectL
	*/
	const TUid KEffectStampUid = {KEffectStampUidValue};
	/** 
	Uid used to gain access to the Sketch effect. @see ImageProcessor::CImgProcessor::EffectL
	*/
	const TUid KEffectSketchUid = {KEffectSketchUidValue};
	/** 
	Uid used to gain access to the Noise effect. @see ImageProcessor::CImgProcessor::EffectL
	*/
	const TUid KEffectNoiseUid = {KEffectNoiseUidValue};
	/** 
	Uid used to gain access to the Moonlight effect. @see ImageProcessor::CImgProcessor::EffectL
	*/
	const TUid KEffectMoonlightUid = {KEffectMoonlightUidValue};
	/** 
	Uid used to gain access to the FrostedGlass effect. @see ImageProcessor::CImgProcessor::EffectL
	*/
	const TUid KEffectFrostedGlassUid = {KEffectFrostedGlassUidValue};
	/** 
	Uid used to gain access to the Despeckle effect. @see ImageProcessor::CImgProcessor::EffectL
	*/
	const TUid KEffectDespeckleUid = {KEffectDespeckleUidValue};
	/** 
	Uid used to gain access to the Blur effect. @see ImageProcessor::CImgProcessor::EffectL
	*/
	const TUid KEffectBlurUid = {KEffectBlurUidValue};
	/** 
	Uid used to gain access to the Colorization effect. @see ImageProcessor::CImgProcessor::EffectL
	*/
	const TUid KEffectColorizationUid = {KEffectColorizationUidValue};
	/** 
	Uid used to gain access to the Cartoon effect. @see ImageProcessor::CImgProcessor::EffectL
	*/
	const TUid KEffectCartoonUid = {KEffectCartoonUidValue};
	/** 
	Uid used to gain access to the LocalBoost effect. @see ImageProcessor::CImgProcessor::EffectL
	*/
	const TUid KEffectLocalBoostUid = {KEffectLocalBoostUidValue};
	/** 
	Uid used to gain access to the ColorBoost effect. @see ImageProcessor::CImgProcessor::EffectL
	*/
	const TUid KEffectColorBoostUid = {KEffectColorBoostUidValue};
	/** 
	Uid used to gain access to the WhiteBalance effect. @see ImageProcessor::CImgProcessor::EffectL
	*/
	const TUid KEffectWhiteBalanceUid = {KEffectWhiteBalanceUidValue};
	/** 
	Uid used to gain access to the AutoLevels effect. @see ImageProcessor::CImgProcessor::EffectL
	*/
	const TUid KEffectAutoLevelsUid = {KEffectAutoLevelsUidValue};
	/** 
	Uid used to gain access to the Levels effect. @see ImageProcessor::CImgProcessor::EffectL
	*/
	const TUid KEffectLevelsUid = {KEffectLevelsUidValue};
	/** 
	Uid used to gain access to the Exposure effect. @see ImageProcessor::CImgProcessor::EffectL
	*/
	const TUid KEffectExposureUid = {KEffectExposureUidValue};
	/** 
	Uid used to gain access to the SpotLight effect. @see ImageProcessor::CImgProcessor::EffectL
	*/
	const TUid KEffectSpotLightUid = {KEffectSpotLightUidValue};
	/** 
	Uid used to gain access to the CustomTransformation effect. @see ImageProcessor::CImgProcessor::EffectL
	*/
	const TUid KEffectCustomTransformationUid = {KEffectCustomTransformationUidValue};
	/** 
	Uid used to gain access to the Antique effect. @see ImageProcessor::CImgProcessor::EffectL
	*/
	const TUid KEffectAntiqueUid = {KEffectAntiqueUidValue};
	
	//Others
	/** 
	Uid used to gain access to the GeometricalOperation effect. @see ImageProcessor::CImgProcessor::EffectL
	*/
	const TUid KGeometricalOperationUid = {KGeometricalOperationUidValue};
	/** 
	Uid used to gain access to the Border effect. @see ImageProcessor::CImgProcessor::EffectL
	*/
	const TUid KEffectBorderUid = {KEffectBorderUidValue};
	   
/**
The class is the parent class of all effects.
The extended class should implement three stages/functions: "begin -> set -> end" 

@publishedAll
@released
*/
class TEffect
	{
public:
	/** Describes the type of the effect in terms of the type of parameter input to adjust levels. */
	enum TEffectInputType
		{
		EEffectInputTypeInt,
		EEffectInputTypeReal32,
		EEffectInputTypeCustom
		};

public:
	inline TUid Type() const;
	inline Plugin::MEffect& PluginEffect() const;
	inline TBool IsActive() const;
	
	IMPORT_C void BeginL();
	IMPORT_C void EndL();
	
	IMPORT_C TEffectInputType InputType() const;
	
	IMPORT_C void SetLevelL(TInt aLevel);
	IMPORT_C void LevelL(TInt& aLevel) const;
	IMPORT_C void LevelSettings(TInt& aMinimumLevel, TInt& aMaximumLevel, TInt& aLevelStep) const;
	
	IMPORT_C void SetLevelL(TReal32 aLevel);
	IMPORT_C void LevelL(TReal32& aLevel) const ;
	IMPORT_C void LevelSettings(TReal32& aMinimumLevel, TReal32& aMaximumLevel, TReal32& aLevelStep) const;
			
	IMPORT_C void ResetL();
	IMPORT_C TAny* Extension(TUid aExtension);

protected:
	friend class CImageProcessorImpl;
	/**
	@internalComponent
	*/
	TEffect(const TUid& aUid, Plugin::MEffect& aPluginEffect, CImageProcessorImpl& aImageProcessorImpl);
	Plugin::MEffect& iPluginEffect;
	TUid iUid;
	TBool iIsActive;
	CImageProcessorImpl& iImageProcessorImpl;
	
	TAny* iReserved;
	};

/**
Gets the effect type.

@return The UID of the effect.
*/
TUid TEffect::Type() const 
	{	
	return iUid;
	}

/**
Gets associated plugin of the effect.

@return A pointer to the related plugin effect instance.
*/
Plugin::MEffect& TEffect::PluginEffect() const 
	{	
	return iPluginEffect;
	}

/**
Gets the state of the effect.

@return	ETrue if the effect is active.
*/
TBool TEffect::IsActive() const 
	{	
	return iIsActive;
	}

/**
The class provides functions to apply sepia effect to an image.

@publishedAll
@released
*/
class TEffectSepia : public TEffect
	{
private:
	friend class CImageProcessorImpl;
	TEffectSepia(Plugin::MEffect& aEffect, CImageProcessorImpl& aImageProcessorImpl);
	};

/**
The class provides functions to convert an image to grayscale.

@publishedAll
@released
*/
class TEffectGrayscale : public TEffect
	{
private:
	friend class CImageProcessorImpl;
	TEffectGrayscale(Plugin::MEffect& aEffect, CImageProcessorImpl& aImageProcessorImpl);
	};

/**
The class provides functions to convert an image similar to a photographic negative.

@publishedAll
@released
*/
class TEffectNegative : public TEffect
	{
private:
	friend class CImageProcessorImpl;
	TEffectNegative(Plugin::MEffect& aEffect, CImageProcessorImpl& aImageProcessorImpl);
	};

/**
The class provides functions to convert an image to combined grayscale and negative. (Consider removing this effect)

@publishedAll
@released
*/
class TEffectGrayscaleNegative : public TEffect
	{
private:
	friend class CImageProcessorImpl;
	TEffectGrayscaleNegative(Plugin::MEffect& aEffect, CImageProcessorImpl& aImageProcessorImpl);
	};

/**
The class provides functions to make an image look like an oil painting. 

@publishedAll
@released
*/
class TEffectOily : public TEffect
	{
private:
	friend class CImageProcessorImpl;
	TEffectOily(Plugin::MEffect& aEffect, CImageProcessorImpl& aImageProcessorImpl);
	};

/**
The class provides functions to make an image look like a painting (how is this distinct from an oil painting effect?). 

@publishedAll
@released
*/
class TEffectPaint : public TEffect
	{
private:
	friend class CImageProcessorImpl;
	TEffectPaint(Plugin::MEffect& aEffect, CImageProcessorImpl& aImageProcessorImpl);
	};

/**
The class provides functions to apply a "milky" surface effect to an image. 

@publishedAll
@released
*/
class TEffectMilky : public TEffect
	{
private:
	friend class CImageProcessorImpl;
	TEffectMilky(Plugin::MEffect& aEffect, CImageProcessorImpl& aImageProcessorImpl);
	};

/**
The class provides functions to apply a fog effect to an image. 

@publishedAll
@released
*/
class TEffectFog : public TEffect
	{
private:
	friend class CImageProcessorImpl;
	TEffectFog(Plugin::MEffect& aEffect, CImageProcessorImpl& aImageProcessorImpl);
	};

/**
The class provides functions to apply Antique effect to an image. 

@publishedAll
@released
*/
class TEffectAntique : public TEffect
	{
private:
	friend class CImageProcessorImpl;
	TEffectAntique(Plugin::MEffect& aEffect, CImageProcessorImpl& aImageProcessorImpl);
	};

/**
The class provides functions to apply a mirror effect to an image. 
Mirrors the left side of the image on the right side of the image. 

@publishedAll
@released
*/
class TEffectMirrorLeftToRight : public TEffect
	{
private:
	friend class CImageProcessorImpl;
	TEffectMirrorLeftToRight(Plugin::MEffect& aEffect, CImageProcessorImpl& aImageProcessorImpl);
	};

/**
The class provides functions to apply a mix of edge distinction and color manipulation to an image.

@publishedAll
@released
*/
class TEffectMagicPen : public TEffect
	{
private:
	friend class CImageProcessorImpl;
	TEffectMagicPen(Plugin::MEffect& aEffect, CImageProcessorImpl& aImageProcessorImpl);
	};

/**
The class provides functions to adjust the brightness level of an image.

@publishedAll
@released
*/
class TEffectBrightness : public TEffect
	{
private:
	friend class CImageProcessorImpl;
	TEffectBrightness(Plugin::MEffect& aEffect, CImageProcessorImpl& aImageProcessorImpl);
	};

/**
The class provides functions to adjust the sharpness level of an image.

@publishedAll
@released
*/
class TEffectSharpness : public TEffect
	{
private:
	friend class CImageProcessorImpl;
	TEffectSharpness(Plugin::MEffect& aEffect, CImageProcessorImpl& aImageProcessorImpl);
	};

/**
The class provides functions to rotate an image through an arbitrary angle.

@publishedAll
@released
*/
class TEffectRotation : public TEffect
	{
public:	
	/**
	Parameters to control the scale of the image when rotation is applied
	*/
	enum TRotationScaleMode 
		{
		/** The image is not scaled when rotation is applied, which is the default mode*/
		ERotationScaleModeIgnore,
		/** The image will be rotated, and scaled to fit inside the margins of the original image*/
		ERotationScaleModeFitInside,
		/** The image will be rotated, and scaled to fully enclose the margins of the original image*/ 
		ERotationScaleModeFitOutside
		};

	IMPORT_C TRotationScaleMode ScaleModeL() const;
	IMPORT_C TReal32 AngleL() const;
	IMPORT_C void SetRotationL(TRotationScaleMode aScaleMode, TReal32 aAngle);

private:
	friend class CImageProcessorImpl;
	TEffectRotation(Plugin::MEffect& aEffect, CImageProcessorImpl& aImageProcessorImpl);
	};

/**
The class provides functions to apply contrast adjustment to an image.

@publishedAll
@released
*/
class TEffectContrast : public TEffect
	{
private:
	friend class CImageProcessorImpl;
	TEffectContrast(Plugin::MEffect& aEffect, CImageProcessorImpl& aImageProcessorImpl);
	};

/**
The class provides functions to adjust the RGB color composition of an image 

@publishedAll
@released
*/
class TEffectRgbColorAdjust : public TEffect
	{
public:	
	IMPORT_C TReal32 RedLevelL() const;
	IMPORT_C TReal32 GreenLevelL() const;
	IMPORT_C TReal32 BlueLevelL() const;
	IMPORT_C void SetRGBLevelL(TReal32 aRedLevel, TReal32 aGreenLevel, TReal32 aBlueLevel);

private:
	friend class CImageProcessorImpl;
	TEffectRgbColorAdjust(Plugin::MEffect& aEffect, CImageProcessorImpl& aImageProcessorImpl);
	};

/**
The class provides functions to apply an emboss effect in grayscale to an image.

@publishedAll
@released
*/
class TEffectEmboss : public TEffect
	{
private:
	friend class CImageProcessorImpl;
	TEffectEmboss(Plugin::MEffect& aEffect, CImageProcessorImpl& aImageProcessorImpl);
	};

/**
The class provides functions to apply a solarize look to an image.

@publishedAll
@released
*/
class TEffectSolarize : public TEffect
	{
private:
	friend class CImageProcessorImpl;
	TEffectSolarize(Plugin::MEffect& aEffect, CImageProcessorImpl& aImageProcessorImpl);
	};

/**
The class provides functions to apply a posterize effect to an image. The number of colors is reduced.

@publishedAll
@released
*/
class TEffectPosterize : public TEffect
	{
private:
	friend class CImageProcessorImpl;
	TEffectPosterize(Plugin::MEffect& aEffect, CImageProcessorImpl& aImageProcessorImpl);
	};

/**
The class provides functions to apply a rubber stamp effect. Result is a black/white image.

@publishedAll
@released
*/
class TEffectStamp : public TEffect
	{
public:	
	IMPORT_C TInt SmoothnessLevelL() const;
	IMPORT_C TInt ThresholdLevelL() const;
	IMPORT_C void SetStampLevelL(TInt aSmoothnessLevel, TInt aThresholdLevel);

private:
	friend class CImageProcessorImpl;
	TEffectStamp(Plugin::MEffect& aEffect, CImageProcessorImpl& aImageProcessorImpl);
	};
/**
The class provides functions to create a sketched representation of an image.

@publishedAll
@released
*/
class TEffectSketch : public TEffect
	{
public:
	/**
	Parameters to control the sketch mode.
	*/
	enum TSketchMode
		{
		/** Sketch the image in gray, which is the default mode*/
		ESketchModeGray,
		/** Sketch the image in color.*/
		ESketchColor
		};
public:	
	IMPORT_C TSketchMode SketchModeL() const;
	IMPORT_C void SetSketchModeL(TSketchMode aLevel);

private:
	friend class CImageProcessorImpl;
	TEffectSketch(Plugin::MEffect& aEffect, CImageProcessorImpl& aImageProcessorImpl);
	};

/**
The class provides functions to apply noise to an image

@publishedAll
@released
*/
class TEffectNoise : public TEffect
	{
private:
	friend class CImageProcessorImpl;
	TEffectNoise(Plugin::MEffect& aEffect, CImageProcessorImpl& aImageProcessorImpl);
	};

/**
The class provides functions to apply a Moonlight effect to an image.

@publishedAll
@released
*/
class TEffectMoonlight : public TEffect
	{
	TInt16 ClockL();
	void SetClockL(TInt16 aClock);

private:
	friend class CImageProcessorImpl;
	TEffectMoonlight(Plugin::MEffect& aEffect, CImageProcessorImpl& aImageProcessorImpl);
	};

/**
The class provides functions to apply a "frosted glass" surface effect to an image.

@publishedAll
@released
*/
class TEffectFrostedGlass : public TEffect
	{
private:
	friend class CImageProcessorImpl;
	TEffectFrostedGlass(Plugin::MEffect& aEffect, CImageProcessorImpl& aImageProcessorImpl);
	};

/**
The class provides functions to apply a "despeckle" surface effect to an image, which means to 
remove noise from images without blurring edges.

@publishedAll
@released
*/
class TEffectDespeckle : public TEffect
	{
private:
	friend class CImageProcessorImpl;
	TEffectDespeckle(Plugin::MEffect& aEffect, CImageProcessorImpl& aImageProcessorImpl);
	};

/**
The class provides functions to blur an area of the image.

@publishedAll
@released
*/
class TEffectBlur : public TEffect
	{
public:	
	IMPORT_C TRect RectL() const;
	IMPORT_C void SetRectL(TRect aRect);

private:
	friend class CImageProcessorImpl;
	TEffectBlur(Plugin::MEffect& aEffect, CImageProcessorImpl& aImageProcessorImpl);
	};

/**
The class provides functions to adjust color tone and luminance/chrominance levels. 

@publishedAll
@released
*/
class TEffectColorization : public TEffect
	{
public:	
	IMPORT_C TRgb ReferenceColorL() const;
	IMPORT_C TInt LuminanceStrengthL() const;
	IMPORT_C TInt ChrominanceStrengthL() const;
	IMPORT_C void SetColorizationL(TRgb aReferenceColor, TInt aLuminanceStrength, TInt aChrominanceStrength);

private:
	friend class CImageProcessorImpl;
	TEffectColorization(Plugin::MEffect& aEffect, CImageProcessorImpl& aImageProcessorImpl);
	};

/**
The class provides functions to transform an image to typical cartoon graphics style.

@publishedAll
@released
*/
class TEffectCartoon : public TEffect
	{
public:	
	IMPORT_C TBool DistinctEdgesL() const;
	IMPORT_C void SetDistinctEdgesL(TBool aDistinctEdges);

private:
	friend class CImageProcessorImpl;
	TEffectCartoon(Plugin::MEffect& aEffect, CImageProcessorImpl& aImageProcessorImpl);
	};

/**
The class provides functions to automatically boost and enhance images with unequal illumination. 

@publishedAll
@released
*/
class TEffectLocalBoost : public TEffect
	{
private:
	friend class CImageProcessorImpl;
	TEffectLocalBoost(Plugin::MEffect& aEffect, CImageProcessorImpl& aImageProcessorImpl);
	};

/**
The class provides functions to amplify the colors of an image.

@publishedAll
@released
*/
class TEffectColorBoost : public TEffect
	{
private:
	friend class CImageProcessorImpl;
	TEffectColorBoost(Plugin::MEffect& aEffect, CImageProcessorImpl& aImageProcessorImpl);
	};

/**
The class provides functions to perform white balance adjustment on an image.

@publishedAll
@released
*/
class TEffectWhiteBalance : public TEffect
	{
public:	
	/**
	Parameters to define the white balance modes.
	*/
	enum TWhiteBalanceMode
		{
		/**Uses the estimated mean gray for the color correction, which is the default mode.*/
		EWhiteBalanceMeanMode,
		/**Uses the estimated maximum intensity color.*/
		EWhiteBalanceMaxMode,
		/**Uses a white reference color. */
		EWhiteBalanceManualMode,
		/**Calulates the reference from the mean value of the 256-bin distribution.*/  
 		EWhiteBalanceClusterMode
		};	
		
public:	
	IMPORT_C TWhiteBalanceMode WhiteBalanceModeL() const;
	IMPORT_C TRgb ReferenceWhiteColorL() const;
	IMPORT_C void SetWhiteBalanceL(TWhiteBalanceMode aWhiteBalanceMode, TRgb aReferenceWhiteColor);
	
private:
	friend class CImageProcessorImpl;
	TEffectWhiteBalance(Plugin::MEffect& aEffect, CImageProcessorImpl& aImageProcessorImpl);
	};

/**
The class provides functions to apply auto level adjustment to an image.
Auto level adjustment balances the intensity level of the image, for example making dark images lighter and vice versa.

@publishedAll
@released
*/
class TEffectAutoLevels : public TEffect
	{
private:
	friend class CImageProcessorImpl;
	TEffectAutoLevels(Plugin::MEffect& aEffect, CImageProcessorImpl& aImageProcessorImpl);
	};

/**
The class provides functions to apply white, gray and black level adjustment to an image.

@publishedAll
@released
*/
class TEffectLevels : public TEffect
	{
public:	
	IMPORT_C TReal32 WhiteLevelL() const;
	IMPORT_C TReal32 GrayLevelL() const;
	IMPORT_C TReal32 BlackLevelL() const;
	IMPORT_C void SetWGBLevelL(TReal32 aWhiteLevel, TReal32 aGrayLevel, TReal32 aBlackLevel);

private:
	friend class CImageProcessorImpl;
	TEffectLevels(Plugin::MEffect& aEffect, CImageProcessorImpl& aImageProcessorImpl);
	};

/**
The class provides functions to control the exposure of an image.

@publishedAll
@released
*/
class TEffectExposure : public TEffect
	{
private:
	friend class CImageProcessorImpl;
	TEffectExposure(Plugin::MEffect& aEffect, CImageProcessorImpl& aImageProcessorImpl);
	};

/**
The class provides functions to create a spotlight on an image.

@publishedAll
@released
*/
class TEffectSpotLight : public TEffect
	{
public:	
	IMPORT_C void SpotLightOrientationL(TPoint &aPosition, TUint32& aRadius, TReal32& aTransitionSize) const;
	IMPORT_C void SetSpotLightOrientationL(const TPoint& aPosition, TUint32 aRadius, TReal32 aTransitionSize);

private:
	friend class CImageProcessorImpl;
	TEffectSpotLight(Plugin::MEffect& aEffect, CImageProcessorImpl& aImageProcessorImpl);
	};

/**
The class provides functions to make a custom transformation with an image.

@publishedAll
@released
*/
class TEffectCustomTransformation : public TEffect
	{
public:	
	IMPORT_C void SetInputL(const TDesC& aFilename);
	IMPORT_C void SetInputL(const TDesC8& aBuffer);

private:
	friend class CImageProcessorImpl;
	TEffectCustomTransformation(Plugin::MEffect& aEffect, CImageProcessorImpl& aImageProcessorImpl);
	};

/**
The class provides functions to geometrically control an image.

@publishedAll
@released
*/
class TGeometricalOperation : public TEffect
	{
public:	
	IMPORT_C CImgProcessor::TOperation Operation() const;
	IMPORT_C void SetOperationL(CImgProcessor::TOperation aOperation);

private:
	friend class CImageProcessorImpl;
	TGeometricalOperation(Plugin::MEffect& aEffect,CImageProcessorImpl& aImageProcessorImpl);
	};

/**
The class provides functions to insert a border to an image. 
The border file can be input as File, Buffer or Bitmap. 

@publishedAll
@released
*/
class TEffectBorder : public TEffect
	{
public:	
	IMPORT_C void SetInputL(const TDesC& aFilename);
	IMPORT_C void SetInputL(const TDesC8& aBuffer);
	IMPORT_C void SetInputL(const CFbsBitmap& aBitmap);
	
private:
	friend class CImageProcessorImpl;
	TEffectBorder(Plugin::MEffect& aEffect, CImageProcessorImpl& aImageProcessorImpl);
	};

	}//namespace ImageProcessor

#endif //__IMAGE_PROCESSOR_EFFECT_H__
