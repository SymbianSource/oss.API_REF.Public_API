// Copyright (c) 1995-2009 Nokia Corporation and/or its subsidiary(-ies).
// All rights reserved.
// This component and the accompanying materials are made available
// under the terms of the License "Symbian Foundation License v1.0" to Symbian Foundation members and "Symbian Foundation End User License Agreement v1.0" to non-members
// which accompanies this distribution, and is available
// at the URL "http://www.symbianfoundation.org/legal/licencesv10.html".
//
// Initial Contributors:
// Nokia Corporation - initial contribution.
//
// Contributors:
//
// Description:
//

#ifndef FNTSTORE_H__
#define FNTSTORE_H__

#include <e32std.h>
#include <f32file.h>
#include <gdi.h>
#include <openfont.h>

class CLinkedTypefaceSpecification;
class CLinkedFontSpecification;
class TLinkedTypefaceSpecArgs;
class CFbClient;
class CFontStoreFile;
class CFontBitmap;
class RReadStream;
class TTypefaceFontBitmap;
class TShapeHeader;
class TShapeMessageParameters;
class CTypefaceSupportInfo;


/**
@internalTechnology
*/
class TCharacterMetrics
	{
	public:
	IMPORT_C TCharacterMetrics();

	TInt16 iAscentInPixels;
	TInt16 iHeightInPixels;
	TInt16 iLeftAdjustInPixels;
	TInt16 iMoveInPixels;
	TInt16 iRightAdjustInPixels;
	};

class TAlgStyle
/** 
An algorithmic style for how a font is drawn.

Holds attributes such as whether the font is bold or italic, and the width 
and height factors. This is used as an input parameter for the GetFontById() method
of some font management classes. See CWsScreenDevice::GetFontById() for more information.
@publishedAll
@released
@see CWsScreenDevice::GetFontById()
@see CFbsTypefaceStore::GetFontById()
@see CFbsDevice::GetFontById()
*/
	{
public:
	IMPORT_C TAlgStyle();
	IMPORT_C void SetIsBold(TBool aIsBold);
	IMPORT_C void SetIsItalic(TBool aIsItalic);
	IMPORT_C void SetIsMono(TBool aIsMono);
	IMPORT_C void SetWidthFactor(TInt aWidthFactor);
	IMPORT_C void SetHeightFactor(TInt aHeightFactor);
	IMPORT_C TBool IsBold() const;
	IMPORT_C TBool IsItalic() const;
	IMPORT_C TBool IsMono() const;
	IMPORT_C TInt WidthFactor() const;
	IMPORT_C TInt HeightFactor() const;
	IMPORT_C TBool operator==(const TAlgStyle& aAlgStyle) const;
	TBool operator!=(const TAlgStyle& aAlgStyle) const;
public:
	/** Baseline offset in pixels. */
	TInt iBaselineOffsetInPixels;
private:
	enum
		{
		EBold=1,
		EItalic=2,
		EMono=4,
		};
	/** This member is private and not intended for use. */
	TInt8 iFlags;
	/** This member is private and not intended for use. */
	TInt8 iWidthFactor;
	/** This member is private and not intended for use. */
	TInt8 iHeightFactor;
	};

class CLinkedFontInformation;

/** 
Bitmap font class.
An object of this class may either access and use a bitmap font (a CFontBitmap)
or an open font (a COpenFont).
Stored in a CFontStore.
@publishedAll
@released
*/
class CBitmapFont : public CFont
	{
	friend class CFontStore;
	friend class CLinkedFontSpecification;
	friend class CLinkedFontInformation;
public:
	// New functions
	TUid Uid() const;
	IMPORT_C TCharacterMetrics CharacterMetrics(TInt aCode,const TUint8*& aBytes) const;
	IMPORT_C TBool GetCharacterData(TInt aSessionHandle, TInt aCode, TOpenFontCharMetrics& aMetrics, const TUint8*& aBitmap) const;
	IMPORT_C TBool Rasterize(TInt aSessionHandle,TInt aCode,TOpenFontGlyphData* aGlyphData) const;
	IMPORT_C void GetFontMetrics(TOpenFontMetrics& aMetrics) const;
	IMPORT_C TBool GetFaceAttrib(TOpenFontFaceAttrib& aAttrib) const;
	IMPORT_C TInt BitmapEncoding() const;
	IMPORT_C TBool HasCharacterL(TInt aCode) const;
	IMPORT_C TBool CharacterNeedsToBeRasterized(TInt aSessionHandle,TInt aCode) const;
	IMPORT_C TShapeHeader* ShapeTextL(const TDesC16& aText,
		TInt aSessionHandle, const TShapeMessageParameters& aParams);
	IMPORT_C void DeleteShape(TInt aSessionHandle,TShapeHeader* aHeader);
	IMPORT_C void operator delete(TAny*);
	inline TBool IsOpenFont() const;
	inline COpenFont* OpenFont() const;
	inline TGlyphBitmapType GlyphBitmapType() const;
	IMPORT_C CLinkedFontInformation* LinkedFontInformation() const;
	IMPORT_C CBitmapFont* NextFontClientSpace() const;
	IMPORT_C TBool IsLinkedFont()const;
	IMPORT_C CBitmapFont* FontWithCharacter(TInt aCode, CLinkedFontInformation *&aInfo, TBool aSearchAllFonts, TBool aGetCanonicalDefault) const;
	
private:
	// From CFont
	IMPORT_C virtual TUid DoTypeUid() const;
	IMPORT_C virtual TInt DoHeightInPixels() const;
	IMPORT_C virtual TInt DoAscentInPixels() const;
	IMPORT_C virtual TInt DoCharWidthInPixels(TChar aChar) const;
	IMPORT_C virtual TInt DoTextWidthInPixels(const TDesC &aText) const;
	IMPORT_C virtual TInt DoBaselineOffsetInPixels() const;
	IMPORT_C virtual TInt DoTextCount(const TDesC &aText, TInt aWidthInPixels) const;
	IMPORT_C virtual TInt DoTextCount(const TDesC &aText, TInt aWidthInPixels, TInt &aExcessWidthInPixels) const;
	IMPORT_C virtual TInt DoMaxCharWidthInPixels() const;
	IMPORT_C virtual TInt DoMaxNormalCharWidthInPixels() const;
	IMPORT_C virtual TFontSpec DoFontSpecInTwips() const;
	IMPORT_C virtual TInt DoExtendedFunction(TUid aFunctionId, TAny* aParam = NULL) const;

private:
	CBitmapFont(RHeap* aHeap,const TFontSpec& aFontSpecInTwips, const TAlgStyle& aAlgStyle, CFontBitmap* aFontBitmap);
	CBitmapFont(RHeap* aHeap,const TFontSpec& aFontSpecInTwips, const TAlgStyle& aAlgStyle, COpenFont* aOpenFont);
	void ConstructL();
	~CBitmapFont();
	static CBitmapFont* NewL(RHeap* aHeap, const TFontSpec& aFontSpecInTwips, const TAlgStyle& aAlgStyle, CFontBitmap* aFontBitmap);
	static CBitmapFont* NewL(RHeap* aHeap, const TFontSpec& aFontSpecInTwips, const TAlgStyle& aAlgStyle, COpenFont* aOpenFont);
	inline void operator delete(TAny*, TAny*) {}
	TInt Width(TInt aNum) const;
	TInt Height(TInt aNum) const;
	CFontBitmap* FontBitmap() const;
	void InstallOpenFontShaper(COpenFont* aOpenFont, CShaper::TInput& aShaperInput);

private:
	TFontSpec iFontSpecInTwips;

public:
	/** The algorithmic font style. */
	TAlgStyle iAlgStyle;	// must not move this member

private:
	// Binary Compatibility warning - data member iOpenFont is referenced by inline methods
	RHeap* iHeap;
	TInt iFontBitmapOffset;
	COpenFont* iOpenFont;	// if iOpenFont is non-null this is an open font and many functions are forwarded to it

#ifdef SYMBIAN_SUPPORT_LINKED_FONTS	
	CLinkedFontInformation *iFontLinkage;
#endif	
	};
	
class CFontStore : public CTypefaceStore
/** 
A store for fonts.

Stores and handles both open and fixed-size fonts. Open fonts are made from 
open (scalable) typefaces by Open Font plug-in rasterizers. Fonts of other 
typefaces are stored in a limited number of fixed sizes. However, which is 
being used is transparent to the user of this class. For example the GetNearestFont...() 
functions get a bitmap font which may be retrieved from memory or generated 
via a rasterizer.
@publishedAll
@released
*/
    {
#ifdef SYMBIAN_SUPPORT_LINKED_FONTS    
friend class CLinkedFonts;
friend class CLinkedFontSpecification;
friend class CLinkedTypefaceSpecification; 
#endif

public:
	IMPORT_C static CFontStore* NewL(RHeap* aHeap);
	IMPORT_C ~CFontStore();
	IMPORT_C TUid AddFileL(const TDesC& aName);
	IMPORT_C void RemoveFile(TUid aFileUid);
	IMPORT_C TInt GetNearestFontInTwips(CFont *&aFont, const TFontSpec& aFontSpec);
	IMPORT_C TInt GetNearestFontInPixels(CFont *&aFont, const TFontSpec &aFontSpec);
	IMPORT_C TInt GetNearestFontToDesignHeightInTwips(CFont *&aFont, const TFontSpec& aFontSpec);
	IMPORT_C TInt GetNearestFontToDesignHeightInPixels(CFont *&aFont, const TFontSpec& aFontSpec);
	IMPORT_C TInt GetNearestFontToMaxHeightInTwips(CFont*& aFont, const TFontSpec& aFontSpec, TInt aMaxHeight);
	IMPORT_C TInt GetNearestFontToMaxHeightInPixels(CFont*& aFont, const TFontSpec& aFontSpec, TInt aMaxHeight);
	IMPORT_C TInt GetNearestFontInTwips(CFont *&aFont, const TOpenFontSpec& aFontSpec);
	IMPORT_C TInt GetNearestFontInPixels(CFont *&aFont, const TOpenFontSpec &aFontSpec);
	IMPORT_C TInt GetNearestFontToDesignHeightInTwips(CFont *&aFont, const TOpenFontSpec& aFontSpec);
	IMPORT_C TInt GetNearestFontToDesignHeightInPixels(CFont *&aFont, const TOpenFontSpec& aFontSpec);
	IMPORT_C TInt GetNearestFontToMaxHeightInTwips(CFont*& aFont, const TOpenFontSpec& aFontSpec, TInt aMaxHeight);
	IMPORT_C TInt GetNearestFontToMaxHeightInPixels(CFont*& aFont, const TOpenFontSpec& aFontSpec, TInt aMaxHeight);
	IMPORT_C TInt GetFontById(CFont *&aFont,TUid aUid,const TAlgStyle& aAlgStyle);
	IMPORT_C TInt NumTypefaces() const;
	IMPORT_C void TypefaceSupport(TTypefaceSupport &aTypefaceSupport,TInt aTypefaceIndex) const;
	IMPORT_C TInt FontHeightInTwips(TInt aTypefaceIndex,TInt aHeightIndex) const;
	IMPORT_C TInt FontHeightInPixels(TInt aTypefaceIndex,TInt aHeightIndex) const;
	IMPORT_C void InstallRasterizerL(COpenFontRasterizer* aRasterizer);
	IMPORT_C void DeleteSessionCache(TInt aSessionHandle);
	inline TGlyphBitmapType DefaultBitmapType() const;
	inline void SetDefaultBitmapType(TGlyphBitmapType aType);
	IMPORT_C void InstallShaperFactoryL(CShaperFactory* aShaperFactory);
	const CArrayPtrFlat<CShaperFactory>* ShaperFactoryList() const;
	COpenFontSessionCacheList* GetSessionCacheList();
	TInt GetShaperCacheMemUsage();
	void SetShaperCacheMemUsage(TInt aUsage);
	CArrayPtrFlat<COpenFontFile>* GetOpenFontFileList();
	void IncNumShaperCaches();
	void DecNumShaperCaches();
	TInt GetNumShaperCaches();
	IMPORT_C TInt CreateLinkedTypeface(const TLinkedTypefaceSpecArgs &aLinkedTypefaceSpec, TInt aSession, TInt& aId);
	IMPORT_C void RemoveLinkedFont(CBitmapFont *aFont);		
	IMPORT_C TBool IsValidLinkedFontSpecification(TInt aHandle);
	IMPORT_C TBool HaveTypefaceFamilyName(const TDesC& aName);
private:
	CFontStore(RHeap* aHeap);
	void ConstructL();
	void InternalizeFontStoreFileL(CFontStoreFile* aFontStoreFile, TInt aFontVersion);
	TTypeface* GetNearestTypeface(const TTypeface& aTypeface) const;
	TTypefaceFontBitmap GetNearestTypefaceFontBitmap(const TFontSpec& aFontSpecInPixels, TInt aMaxHeight);
	CFontBitmap* GetFontBitmapById(TUid aUid);
	TBool IsFontLoaded(CFont*& aFont, const TAlgStyle& aAlgStyle, const TFontSpec& aFontSpecInPixels, TUid aUid, TInt aMaxHeight = 0) const;
	TBool IsFontLoaded(CFont*& aFont, const TAlgStyle& aAlgStyle, const TOpenFontSpec& aFontSpecInPixels, TInt aMaxHeight) const;
	CBitmapFont* NewFontL(const TFontSpec& aFontSpecInTwips,const TAlgStyle& aAlgStyle,CFontBitmap* aFontBitmap);
	CBitmapFont* NewFontL(const TOpenFontSpec& aFontSpecInTwips,const TAlgStyle& aAlgStyle,COpenFont* aOpenFont);
	TInt VerticalPixelsToTwips(TInt aPixelHeight) const;
	TInt VerticalTwipsToPixels(TInt aTwipsHeight) const;
	void GetNearestBitmapFontInPixelsL(CFont*& aFont, TFontSpec& aFontSpec, TInt aMaxHeight);
	void GetNearestOpenFontInPixelsL(
	CFont*& aFont, TOpenFontSpec& aActualFontSpec, const TOpenFontSpec& aDesiredFontSpec, TInt aMaxHeight);
#ifdef SYMBIAN_SUPPORT_LINKED_FONTS	
	TInt GetNearestRealFontInPixels(CFont*& aFont, const TOpenFontSpec& aFontSpec, TInt aMaxHeight);
	TInt GetNearestFontInPixelsL(CFont*& aFont, const TOpenFontSpec& aFontSpec, TInt aMaxHeight);
	TInt CreateLinkedTypefaceL(const TLinkedTypefaceSpecArgs &aLinkedTypefaceSpec, TInt aSession, TInt& aId);
	TInt GetCanonicalIndex(TInt aTypefaceIndex) const;
	void TypefaceSupportLinked(TTypefaceSupport &aTypefaceSupport, TInt aTypefaceIndex) const;
#endif	
	TInt GetNearestFontInPixels(CFont*& aFont, const TOpenFontSpec& aFontSpec, TInt aMaxHeight);
	void SanityCheckForTtfL(RFile& aFile, TUint aFontFileSize, TBool aStrictChecking);
	void SanityCheckFontFileL(TParse& aParse);
	TInt GetNearestOpenFontInPixelsByFontName(COpenFont*& aNearestOpenFont, TOpenFontSpec& aActualFontSpec, const TOpenFontSpec& aDesiredFontSpec, TInt aMaxHeight);
	TInt GetNearestOpenFontInPixelsBySimilarity(COpenFont*& aNearestOpenFont, TOpenFontSpec& aActualFontSpec, const TOpenFontSpec& aDesiredFontSpec, TInt aMaxHeight);
	TInt AddTypefacesToSupportList(COpenFontFile* aOpenFontFile);
	void RemoveTypefacesFromSupportList(COpenFontFile* aOpenFontFile);
	TInt FindBitmapFontFileIndexByUid(TUid aUid);
	TBool IncRefCountOfLoadedFont(const TDesC& aFullName, TUid& aFontUid);
	TBool LoadFileAsOpenFontL(const TDesC& aFullName, TUid& aFontUid);
	TUid LoadFileAsBitmapFontL(TParse& aParse);
	static void CleanupRemoveFontFile(TAny* aCleanupInfo);

public:
	/** The width of 1000 pixels in twips.
	
	This is set in the constructor. If the appropriate HALData attributes are 
	set (EDisplayXPixels and EDisplayXTwips) then the value is calculated using 
	these; otherwise the value is set to 11860. */
	TInt iKPixelWidthInTwips;
	
	/** The height of 1000 pixels in twips.
	
	This is set in the constructor. If the appropriate HALData attributes are 
	set (EDisplayYPixels and EDisplayYTwips) then the value is calculated using 
	these; otherwise the value is set to 11860. */
	TInt iKPixelHeightInTwips;

private:
	// Binary Compatibility warning - data member iDefaultBitmapType is referenced by inline methods
	RFs iFs;
	RHeap* iHeap;
	CArrayPtrFlat<CFontStoreFile> iFontStoreFileList;
	CArrayPtrFlat<TTypeface> iTypefaceList;
	CArrayPtrFlat<CFontBitmap> iFontBitmapList;
	CArrayFixFlat<TTypefaceFontBitmap> iTypefaceFontBitmapList;
	CArrayPtrFlat<COpenFontFile> iOpenFontFileList;
	TInt iReserved[6];		// keep iDefaultBitmapType at the correct offset
	CArrayPtrFlat<COpenFontRasterizer> iOpenFontRasterizerList;
	COpenFontSessionCacheList* iOpenFontSessionCacheList;
	TInt iOpenFontUid;
	TGlyphBitmapType iDefaultBitmapType;
	CArrayPtrFlat<CShaperFactory> iShaperFactoryList;
	TInt iOpenFontShaperCacheMemUsage;
	TInt iNumberOfShaperCaches;
	RPointerArray<CTypefaceSupportInfo> iOpenFontTypefaceSupportList;
#ifdef SYMBIAN_SUPPORT_LINKED_FONTS	
	RPointerArray<CLinkedTypefaceSpecification> *iLinkedTypefaceSpecificationList;
	RPointerArray<CLinkedFontSpecification> *iLinkedFontSpecificationList;
#endif	
	};

// inline functions start here

/** Returns whether the bitmap font object is an open font (a COpenFont) rather 
than a bitmap font (a CFontBitmap).

@return ETrue if the bitmap font object is using an open font (a COpenFont);
EFalse if it is using a bitmap font (a CFontBitmap).
@see OpenFont()
*/
inline TBool CBitmapFont::IsOpenFont() const
	{
	return iOpenFont != NULL;
	}

/** Returns a pointer to the open font being used by the bitmap font object.

@return A pointer to an open font.
@see IsOpenFont()
*/
inline COpenFont* CBitmapFont::OpenFont() const
	{ 
	return iOpenFont;
	}

/** Gets the anti-aliasing setting for the font, see TGlyphBitmapType for 
the range of values.

This is only applicable to open fonts (COpenFonts) not bitmap fonts (CBitmapFonts).

Note that this setting is stored in the device-independent font specification 
which is set when the bitmap font object is constructed.

@return The anti-aliasing setting for the font.
@see IsOpenFont()
@see TGlyphBitmapType
@see COpenFont
@see CBitmapFont
*/
inline TGlyphBitmapType CBitmapFont::GlyphBitmapType() const
	{
	return iFontSpecInTwips.iFontStyle.BitmapType();
	}

/** Returns a default bitmap type.

@return A default bitmap type.
@see TGlyphBitmapType
*/
inline TGlyphBitmapType CFontStore::DefaultBitmapType() const
	{
	return iDefaultBitmapType;
	}

/** Sets a default bitmap type.

@param aType A default bitmap type.
@see TGlyphBitmapType
*/
inline void CFontStore::SetDefaultBitmapType(TGlyphBitmapType aType)
	{
	iDefaultBitmapType = aType;
	}

#endif
