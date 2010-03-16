// Copyright (c) 1999-2009 Nokia Corporation and/or its subsidiary(-ies).
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
// The main header file for TAGMA, the low-level text formatting engine for EPOC.
// 'Tm' stands for 'TAGMA' and is the standard prefix for TAGMA classes, after
// the C, T, or whatever.
// 
//



#ifndef __TAGMA_H__
#define __TAGMA_H__

#include <e32base.h>
#include <openfont.h>
#include <txtfrmat.h>
#include <txtstyle.h>
#include <linebreak.h>

// forward declarations
class TTmLineInfo;
class CTmTextImp;
class RWindow;
class RWsSession;
class RParagraphStyleInfo;
class CStyleList;
class TTmDocPosSpec;
class TTmDocPos;
class TCursorSelection;
class TTmHighlightExtensions;
class TBidirectionalContext;

/** 
A bit mask for selecting one or more attributes of a TTmCharFormat object. 
@internalComponent
*/
class TTmCharFormatMask

	{
public:
	/** Constants, that are also bit assignments, representing character format attributes */
	enum TAttrib
		{
		EFontName = 0x1,
		EFontCoverage = 0x2,
		EBold = 0x4,
		EItalic = 0x8,
		ESerif = 0x10,
		EMonoWidth = 0x20,
		EHeight = 0x40,
		EPrintPosition = 0x80,
		ETextColor = 0x100,
		EBackgroundColor = 0x200,
		EBackground = 0x400,
		EUnderline = 0x800,
		EStrikethrough = 0x1000,
		EShadow = 0x2000,
		EUserDefinedEffects = 0x4000,
		ELanguage = 0x8000,
		EPictureAlignment = 0x10000
		};

	inline TTmCharFormatMask();
	IMPORT_C TTmCharFormatMask(const TCharFormatMask& aMask);
	IMPORT_C void GetTCharFormatMask(TCharFormatMask& aMask) const;
	inline void Clear(TAttrib aAttrib);
	inline void Set(TAttrib aAttrib);
	inline TBool IsSet(TAttrib aAttrib); 

	TUint iFlags;
	};

/** 
A character format; all dimensions are in twips. A character format object
stores all text style attributes that can differ from any one character to the
next. Attributes that affect an entire paragraph only are kept in RTmParFormat
objects. 
@internalComponent
*/
class TTmCharFormat
	{
public:
	/** Bit assignments for effects */
	enum
		{
		EBackground = 1,	///< Text background is drawn in the background colour
		ERounded = 2,		///< Text background (if any) has rounded corners
		EUnderline = 4,	///< Text is underlined
		EStrikethrough = 8,	///< Text is struck through with a horizontal line.
		EShadow = 16,	///< Text has a drop shadow.
		/** Bits 24-31 are reserved for styles defined by the custom drawer. */
		EUserDefinedMask = 0xFF000000,
		/** Shift TCharFormat highlight styles left by this to get the
		TTmCharFormat effects portion. */
		EUserDefinedShift = 24,
		/** For custom drawers: draw whatever is wanted for "no matches" in the FEP. */
		ENoMatchesIndicator = 0x4000000,
		/** Reset if the effect in bits 24-30 is defined defined by Symbian,
		set if it is defined externally. */
		ECustomDrawEffectIsExternallyDefined = 0x80000000
		};

	/** Picture alignment */
	enum TPictureAlignment
		{
		EPictureAlignBaseline,
		EPictureAlignTop,
		EPictureAlignBottom,
		EPictureAlignCenter
		};

	IMPORT_C TTmCharFormat();
	IMPORT_C TTmCharFormat(const TDesC& aFontName,TInt aFontHeight);
	IMPORT_C void operator=(const TCharFormat& aFormat);
	inline TTmCharFormat(const TCharFormat& aFormat);
	IMPORT_C void GetTCharFormat(TCharFormat& aFormat) const;
	IMPORT_C TBool operator==(const TTmCharFormat& aFormat) const;
	inline TBool operator!=(const TTmCharFormat& aFormat) const;

	TOpenFontSpec iFontSpec;
	TLogicalRgb iTextColor;
	TLogicalRgb iBackgroundColor;		// used only when EBackground flag is set in iEffects
	TUint iEffects;						// bit flags as defined above;
										// note that effects NEVER change character metrics and so can
										// be ignored when measuring text
	TUint iLanguage;					// language used for proofing
	TPictureAlignment iPictureAlignment;// vertical alignment of embedded objects
	TUint iTag;							// tag for use by URL parsers, etc.; a way of marking a range of
										// text without using any typographic attributes
	};

/** 
A tabulation position, measured from the start of the line, which will be
the left end for paragraphs with a left-to-right base direction, and vice
versa. 
@internalComponent
*/
class TTmTab

	{
public:
	/** Tab type */
	enum TType
		{
		EStandardTab,	// text is placed after the tab, in the current paragraph direction
		ECenterTab,		// text is centred around the tab
		EReverseTab		// text is placed before the tab, in the current paragraph direction
		};

	inline TTmTab();
	inline TTmTab(const TTabStop& aTab);
	IMPORT_C void operator=(const TTabStop& aTab);
	IMPORT_C void GetTTabStop(TTabStop& aTab) const;
	IMPORT_C TBool operator==(const TTmTab& aTab) const;
	inline TBool operator!=(const TTmTab& aTab) const;

	TInt iPosition;
	TType iType;
	};

/** 
A bullet or other label inserted automatically at the start of a paragraph.
As well as an actual bullet, it can be a number or a letter. 
@internalComponent
*/
class TTmBullet

	{
public:
	/** Bullet style */
	enum TStyle
		{
		EBulletStyle,
		EArabicNumberStyle,
		ESmallRomanNumberStyle,
		ECapitalRomanNumberStyle,
		ESmallLetterStyle,
		ECapitalLetterStyle
		};

	/** The alignment within the margin of bullets or other text used in TTmBullet objects */
 	enum TAlignment
		{
		/** Bullet forward aligned. */
		ELeftAlign,
		/** Bullet centre aligned. */
		ECenterAlign,
		/** Bullet reverse aligned. */
		ERightAlign
		};

	IMPORT_C TTmBullet();
	IMPORT_C void operator=(const TBullet& aBullet);
	inline TTmBullet(const TBullet& aBullet);
	IMPORT_C void GetTBullet(TBullet& aBullet) const;
	IMPORT_C TBool operator==(const TTmBullet& aBullet) const;
	inline TBool operator!=(const TTmBullet& aBullet) const;

	TChar iCharacterCode;		// the bullet or other symbol used if iStyle is EBulletStyle
	TOpenFontSpec iFontSpec;
	TBool iHangingIndent;
	TLogicalRgb iColor;
	TStyle iStyle;				// is this a bullet or a number or a letter?
	TInt iStartNumber;			// the number of the first paragraph in a run of paragraphs in this style
	TAlignment iAlignment;		// alignment of the bullet or number within the margin
	};

/** 
A specification of a paragraph border rule: that is, a line or lines drawn
above, below, to the left, or to the right of a paragraph. 
@internalComponent
*/
class TTmParBorder

	{
public:
	/** Paragraph border style */
	enum TStyle
		{
		ESolidStyle,
		EDoubleStyle,
		EDotStyle,
		EDashStyle,
		EDotDashStyle,
		EDotDotDashStyle
		};

	IMPORT_C TTmParBorder();
	IMPORT_C void operator=(const TParaBorder& aBorder);
	inline TTmParBorder(const TParaBorder& aBorder);
	IMPORT_C void GetTParaBorder(TParaBorder& aBorder) const;
	IMPORT_C TBool operator==(const TTmParBorder& aBorder) const;
	inline TBool operator!=(const TTmParBorder& aBorder) const;

	TStyle iStyle;
	TInt iWeight;
	TLogicalRgb iColor;
	TBool iAutoColor;
	};


/** 
A bit mask for selecting one or more attributes of an RTmParFormat. 
@internalComponent
*/	
class TTmParFormatMask

	{
public:
	/** Constants, that are also bit assignments, representing paragraph format attributes */
	enum TAttrib
		{
		EAlignment = 0x1,
		EDirection = 0x2,
		EKeepTogether = 0x4,
		EKeepWithNext = 0x8,
		EStartNewPage = 0x10,
		EWidowOrphan = 0x20,
		ENoWrap = 0x40,
		EExactLineSpacing = 0x80,
		EPixelLineSpacing = 0x100,
		ELeadingMargin = 0x200,
		ETrailingMargin = 0x400,
		EFirstLineIndent = 0x800,
		ELineSpacing = 0x1000,
		ESpaceAbove = 0x2000,
		ESpaceBelow = 0x4000,
		ETabSize = 0x8000,
		EBorderMargin = 0x10000,
		ETabList = 0x20000,
		EBullet = 0x40000,
		EBorder = 0x80000
		};

	inline TTmParFormatMask();
	IMPORT_C TTmParFormatMask(const TParaFormatMask& aMask);
	IMPORT_C void GetTParaFormatMask(TParaFormatMask& aMask) const;
	inline void Clear(TAttrib aAttrib);
	inline void Set(TAttrib aAttrib);
	inline TBool IsSet(TAttrib aAttrib);

	TUint iFlags;
	};

/** 
Paragraph format; all dimensions are in twips unless otherwise specified. 
@internalComponent
*/
class RTmParFormat

	{
public:
	/** Index used to select one of the four borders of a paragraph */
	enum TBorderIndex
		{
		ETopBorder = 0,
		EBottomBorder = 1,
		ELeadingBorder = 2,
		ETrailingBorder = 3,
		};

	/** Bit assignments for RTmParFormat::iFlags. */
	enum
		{
		/** Base direction of paragraph is right-to-left (as for Arabic) */
		ERightToLeft = 1,
		/** Do not allow paragraph to straddle page boundaries. */
		EKeepTogether = 2,
		/** Put this paragraph on the same page as the next. */
		EKeepWithNext = 4,
		/** Put this paragraph at the start of a new page. */
		EStartNewPage = 8,
		/** Suppress widows and orphans. */
		EWidowOrphan = 16,
		/** Suppresses line breaking. */
		ENoWrap = 32,
		/** Force line spacing distance to be respected even on lines that are
		 * taller than the specified height. */
		EExactLineSpacing = 64,
		/** Line spaceing is in pixels, not twips. */
		EPixelLineSpacing = 128,
		/** Work out paragraph directionality from the text. */
		EDirectionalityFromText = 256
		};

	/** Paragraph alignment */
	enum TAlignment
		{
		EAlignNormalBidirectional,
		EAlignNormal = EAlignNormalBidirectional,		/** @deprecated in 7.0s */
		EAlignCenter,
		EAlignReverseBidirectional,
		EAlignReverse = EAlignReverseBidirectional,		/** @deprecated in 7.0s */
		EAlignJustify,
		EAlignAbsoluteLeft,
		EAlignAbsoluteRight
		};

	IMPORT_C RTmParFormat();
	IMPORT_C void Close();
#ifdef _DEBUG
	inline ~RTmParFormat();
#endif
	IMPORT_C void CopyL(const RTmParFormat& aFormat);
	IMPORT_C void CopyL(const CParaFormat& aFormat);
	IMPORT_C void GetCParaFormatL(CParaFormat& aFormat) const;
	IMPORT_C TBool operator==(const RTmParFormat& aFormat) const;
	inline TBool operator!=(const RTmParFormat& aFormat) const;
	IMPORT_C TInt Tabs() const;
	inline const TTmTab& Tab(TInt aIndex) const;
	inline const TTmBullet* Bullet() const;
	inline const TTmParBorder* Border(TBorderIndex aIndex) const;
	IMPORT_C TBool HaveBorders() const;
	inline TBool RightToLeft() const;

	TAlignment iAlignment;
	TUint iFlags;						// bit flags as defined above
	TInt iLeadingMargin;				// left margin, or right if right-to-left
	TInt iTrailingMargin;				// right margin, or left if right-to-left
	TInt iFirstLineIndent;				// added to first line leading margin
	TInt iLineSpacing;					// distance between baselines
	TInt iSpaceAbove;					// space above the paragraph
	TInt iSpaceBelow;					// space below the paragraph
	TInt iTabSize;						// default size of tabs
	TInt iBorderMargin;					// distance between the text and the border if any
	TLogicalRgb iBackgroundColor;		// paragraph background colour

private:
	RTmParFormat(const RTmParFormat& aFormat);	// deliberately unimplemented
	void operator=(const RTmParFormat& aFormat);// deliberately unimplemented

	RArray<TTmTab>* iTabList;			// custom tabs if any
	TTmBullet* iBullet;					// bullet if any
	TTmParBorder* iBorder[4];			// borders if any
	};

/** 
The text customization interface. You can customize the colors, word
spacing, line breaking, line height calculation, background drawing, and text
appearance, of a text object by supplying an implementation of the MTmCustom
class, either directly (as in CTmText::CustomizeL, which takes a pointer to
MTmCustom) or indirectly, making use of the fact that MTmSource is derived from
MTmCustom (as in CTmTextLayout::SetTextL, which takes a reference to
MTmSource).
@publishedAll
@released
*/
class MTmCustom 
				: public MLineBreaker
	{
public:
	/**
    TLineHeightParam structure is used in MTmCustom::SetLineHeight() method to set 
    text line height related parameters such as max character height, max ascent and descent,
    height and depth of the tallest pictures (top-aligned, bottom-aligned or centered).
    @see MTmCustom::SetLineHeight()
	@publishedAll
	@released
	*/
	class TLineHeightParam
		{
	public:
		inline TLineHeightParam();
        /** Height of the highest character in the line. */
		TInt iMaxCharHeight;
        /** Depth of the deepest character in the line. */
		TInt iMaxCharDepth;
        /** Height plus depth of the tallest top-aligned picture. */
		TInt iMaxTopPictureHeight;
        /** Height plus depth of the tallest bottom-aligned picture. */
		TInt iMaxBottomPictureHeight;
        /** Height plus depth of the tallest centred picture. */
		TInt iMaxCenterPictureHeight;
        /** Height of the tallest character of any in the fonts in the line. */
		TInt iFontMaxCharHeight;
        /** Depth of the deepest character of any in the fonts in the line. */
		TInt iFontMaxCharDepth;
        /** Maximum ascent of the fonts in the line. */
		TInt iFontMaxAscent;
        /** Maximum descent of the fonts in the line. */
		TInt iFontMaxDescent;
        /** Desired precise or minimum line height. */
		TInt iDesiredLineHeight;
        /** True if the line height must be precise. */
		TBool iExactLineHeight;
		};

	/**	The Unicode line breaking classes; see Unicode Technical Report 14.
	Not a named enumerated type, so that overriding applications can add new
	line breaking classes freely.
	The description of each constant gives the name of the line-breaking
	class, an example and a brief, imprecise description of the default
	behaviour of characters of that class.
	*/
	enum
		{
		/** Opening Punctuation (e.g. '['). Breaking after prohibited. */
		EOpLineBreakClass,
		/** Closing Punctuation (e.g. ']'). Breaking before prohibited. */
		EClLineBreakClass,
		/** Ambiguous Quotes (e.g. '"'). Breaking before and after prohibited. */
		EQuLineBreakClass,
		/** Glue (e.g. Non-breaking space). Breaking before and after prohibited
		unless spaces are present. */
		EGlLineBreakClass,
		/** Non-Starter (e.g. small Japanese kana). Breaking before prohibited
		if no spaces present. */
		ENsLineBreakClass,
		/** Exclamation or Interrogation (e.g. '?'). Like closing punctuation
		except before Postfix or Non-starter. */
		EExLineBreakClass,
		/** Symbol (e.g. '/'. Like Alphabetic, but allows breaking before
		Alphabetic. */
		ESyLineBreakClass,
		/** Numeric Infix Separator (e.g. ','). Forbids breaking after any and before
		Numeric. */
		EIsLineBreakClass,
		/** Numeric Prefix (e.g. '$'). Forbids breaking before Numeric. */
		EPrLineBreakClass,
		/** Numeric Postfix (e.g. '%'). Forbids breaking after Numeric. */
		EPoLineBreakClass,
		/** Numeric (e.g. '1'). */
		ENuLineBreakClass,
		/** Alphabetic (e.g. 'a'). */
		EAlLineBreakClass,
		/** Ideographic (e.g. Japanese Kanji). Generally break before or after */
		EIdLineBreakClass,
		/** Inseparable (e.g. ellipsis). Forbid breaks between Inseparables. */
		EInLineBreakClass,
		/** Hyphen (e.g. '-'). Allows a break after except before Numeric. */
		EHyLineBreakClass,
		/** Break After. Generally allow a break after. Breaking between Break
		Afters not separated by spaces is prohibited. */
		EBaLineBreakClass,
		/** Break Before. Generally allow a break before. Breaking between Break
		Befores not separated by spaces is prohibited. */
		EBbLineBreakClass,
		/** Break Before and After. Generally allow a break before or after.
		Breaking between Break Before and Afters is prohibited, even if spaces
		are present. */
		EB2LineBreakClass,
		/** Zero-Width Space. Allow a break. */
		EZwLineBreakClass,
		/** Combining Mark. Takes on the class of its base class. */
		ECmLineBreakClass,
		/** Mandatory Break. */
		EBkLineBreakClass,
		/** Carriage Return. Break after unless part of a CRLF pair. */
		ECrLineBreakClass,
		/** Line Feed. Break after. */
		ELfLineBreakClass,
		/** Surrogate. Half of a surrogate pair. */
		ESgLineBreakClass,
		/** Contingent Break (e.g. embedded pictures). Uses external
		information */
		ECbLineBreakClass,

		/** Space. Intervening characters of class Space are indicated by
		aHaveSpaces in LineBreakPossible. */
		ESpLineBreakClass, 

		/** Complex Context (e.g. Thai). Runs of Complex Context are passed to
		GetLineBreakInContext. */
		ESaLineBreakClass,

		/** Ambiguous. Characters of ambiguous East Asian width are treated
		as Alphabetic, unless they are resolved as being "Wide", in which case
		they are treated as Ideographic. */
		EAiLineBreakClass,

		/** The Xx class is used when the class is unknown; e.g.; outside the provided context. */
		EXxLineBreakClass,

		/** The number of Unicode line break classes. */
		ELineBreakClasses
		};

	IMPORT_C virtual TRgb SystemColor(TUint aColorIndex,TRgb aDefaultColor) const;
	IMPORT_C virtual TInt Stretch(TUint aChar) const;
	IMPORT_C virtual TUint Map(TUint aChar) const;
	IMPORT_C virtual void SetLineHeight(const TLineHeightParam& aParam,TInt& aAscent,TInt& aDescent) const;
	IMPORT_C virtual void DrawBackground(CGraphicsContext& aGc,const TPoint& aTextLayoutTopLeft,const TRect& aRect,
										 const TLogicalRgb& aBackground,TRect& aRectDrawn) const;
	IMPORT_C virtual void DrawLineGraphics(CGraphicsContext& aGc,const TPoint& aTextLayoutTopLeft,const TRect& aRect,
										   const TTmLineInfo& aLineInfo) const;
	IMPORT_C virtual void DrawText(CGraphicsContext& aGc,const TPoint& aTopLeft,const TRect& aRect,
								   const TTmLineInfo& aLineInfo,const TTmCharFormat& aFormat,
								   const TDesC& aText,const TPoint& aTextOrigin,TInt aExtraPixels) const;
	IMPORT_C virtual void DrawPicture(CGraphicsContext& aGc,
		const TPoint& aTextLayoutTopLeft, const TRect& aRect,
		MGraphicsDeviceMap& aDevice, const CPicture& aPicture) const;
	IMPORT_C virtual TUint LineBreakClass(TUint aCode,TUint& aRangeStart,TUint& aRangeEnd) const;
	IMPORT_C virtual TBool LineBreakPossible(TUint aPrevClass,TUint aNextClass,TBool aHaveSpaces) const;
	IMPORT_C virtual TBool GetLineBreakInContext(const TDesC& aText,TInt aMinBreakPos,TInt aMaxBreakPos,
												 TBool aForwards,TInt& aBreakPos) const;
	IMPORT_C virtual TBool IsHangingCharacter(TUint aChar) const;

	// non-virtuals
	IMPORT_C void SetPenColor(CGraphicsContext& aGc,TLogicalRgb aColor) const;
	IMPORT_C void SetBrushColor(CGraphicsContext& aGc,TLogicalRgb aColor) const;
	IMPORT_C TRgb SystemColor(TLogicalRgb aColor) const;
	};

/**
MTmTextDrawExt interface UID.
@internalComponent
*/
const TUid KTmTextDrawExtId = {0x10203665};

/**
Text drawing - an extension interface. It offfers
DrawLine(), DrawText() and DrawRect() methods.
The idea is to move out from RTm<Name>Interpreter implementations all 
CGraphicsContext::Draw<Item> calls and replace them with the corresponding 
MTmTextDrawExt::Draw<Item> calls. The implementations of MTmTextDrawExt interface can customize
drawing methods implementations - for example - including opaque drawing support.
The MTmTextDrawExt interface UID is KTmTextDrawExtId. The interface implementation can be queried
through a MTmSource::GetExtendedInterface() call.
@internalComponent
*/
class MTmTextDrawExt
	{
public:
	virtual void DrawLine(CGraphicsContext& aGc, const TPoint& aPt1, const TPoint& aPt2) const = 0;
	virtual void DrawText(CGraphicsContext& aGc, const TDesC& aText, const TPoint& aPt) const = 0;
	virtual void DrawRect(CGraphicsContext& aGc, const TRect& aRc) const = 0;
	};

/**
@internalComponent
*/
const TUid KFormLabelApiExtensionUid = { 0x101FD03C};

/** 
MTmSource is an interface class that must be implemented by users of
CTmTextLayout to provide text content and attributes. MTmSource is derived from
MTmCustom, which contains the functions to customise the layout and display, so
that this can be done in CTmText without affecting the content.
@internalComponent
*/
class MTmSource: public MTmCustom

	{
public:
	/** Label type used in LabelModeSelect */
	enum TLabelType
		{
		/** Not a label; used for TLabelTypes not yet assigned. */
		ENoLabel,

		/** Paragraph label of the type supported by FORM. */
		EParLabel
		};

	enum
		{
		/**
		The maximum number of characters supplied to GetLineBreak, after aMaxBreakPos,
		and after trailing whitespace, to provide context for line breaking decisions.
		*/
		ELineBreakContext = 32
		};

	// pure virtuals
	
	/** Return the device used to format the text. */
	virtual MGraphicsDeviceMap& FormatDevice() const = 0;

	/**
	Return the device used to draw the text and when converting between x-y coordinates and document positions.
	If the formatting and interpreting devices are different, text is scaled appropriately when it is drawn;
	this allows text to be formatted for printer fonts and displayed on the screen, giving a wysiwyg print preview.
	*/
	virtual MGraphicsDeviceMap& InterpretDevice() const = 0;

	/** Return the length of the document in characters. */
	virtual TInt DocumentLength() const = 0;

	/**
	Return at least one character of text, but preferably as many as possible, starting at aPos. Put its character
	format in aFormat. The text must be a run of characters sharing the same character format.
	*/
	virtual void GetText(TInt aPos,TPtrC& aText,TTmCharFormat& aFormat) const = 0;

	/**
	Return the paragraph format of the paragraph containing aPos. End-of-paragraph characters belong to the preceding
	paragraph.
	*/
	virtual void GetParagraphFormatL(TInt aPos,RTmParFormat& aFormat) const = 0;

	/**
	Return the document position of the start of the paragraph containing aPos. End-of-paragraph characters belong to
	the preceding paragraph.
	*/
	virtual TInt ParagraphStart(TInt aPos) const = 0;

	// ordinary virtuals
	IMPORT_C virtual CPicture* PictureL(TInt aPos) const;
	IMPORT_C virtual TInt GetPictureSizeInTwipsL(TInt aPos,TSize& aSize) const;
	IMPORT_C virtual TAny* GetExtendedInterface(const TUid& aInterfaceId);
	IMPORT_C virtual void MTmSource_Reserved_1();
	IMPORT_C virtual void MTmSource_Reserved_2();
	IMPORT_C virtual TBool PageBreakInRange(TInt aStartPos,TInt aEndPos) const;

	// non-virtuals
	IMPORT_C TInt ParagraphEnd(TInt aPos) const;
	IMPORT_C TBool GetLineBreakL(const TDesC& aText,TInt aDocPos,TInt aMinBreakPos,TInt aMaxBreakPos,TBool aForwards,
								 TInt& aBreakPos,TInt& aHangingChars,TInt& aBreakPosAfterSpaces) const;
	IMPORT_C static void GetStandardLineBreak(const TDesC& aText,TInt aMinBreakPos,TInt aMaxBreakPos,
											  TInt& aBreakPos,TInt& aNextLineStart);
	};

/**
Class used to provide label functionality within Form
as an extended interface (via the GetExtendedInterface mechanism
supplied in MTmSource). This class is entirely internal to Form.
@internalComponent
@see MTmSource::GetExtendedInterface
@since Sirocco
*/
class MFormLabelApi
	{
public:
	IMPORT_C virtual TBool LabelModeSelect(MTmSource::TLabelType aType, TInt aPos);
	IMPORT_C virtual void LabelModeCancel();
	IMPORT_C virtual void LabelMetrics(MTmSource::TLabelType aType, TSize& aLabelSize, TInt& aMarginSize) const;
	};

/**
@internalTechnology
*/
class CTmBufSeg: public CBufSeg
	{
public:
	inline CTmBufSeg(TInt aExpandSize);
	TInt MemoryUsed() const;
	};

/** @internalTechnology */
class CTmCode: public CBase
	{
public:
	inline ~CTmCode();
	void InsertByteL(TUint8 aByte,TInt aPos);
	TInt InsertNumberL(TInt aNumber,TInt aPos);
	TInt InsertRectL(const TRect& aRect,TInt aPos);
	void AppendByteL(TUint8 aByte);
	TInt AppendNumberL(TInt aNumber);
	TInt AppendRectL(const TRect& aRect);
	void ChangeL(TInt aStart,TInt aEnd,CTmCode& aNewCode);
	TInt MemoryUsed() const;
	TInt Size() const;
	void Delete(TInt aPos,TInt aLength);
	void Reset();
	inline TPtr8 Ptr(TInt aPos);
	void CreateBufferL();
	inline CBufBase* Buffer();
	inline const CBufBase* Buffer() const;

private:
	enum
		{
		EExpandSize = 512
		};
	TInt WriteNumber(TInt aNumber,TUint8* aBuffer);

	CTmBufSeg* iBuffer;
	};

/**
Formatting parameters used when formatting part of a layout object.
@internalComponent
*/
class TTmFormatParamBase

	{
public:
	enum
		{
		EWrap = 1,							// wrap the text at iWrapWidth
		EAtLeastMaxHeight = 2,				// stop adding text only when iMaxHeight has been reached or exceeded
		ETruncateWithEllipsis = 4,			// truncate any text that sticks out; see iEllipsis below
		ELegalLineBreaksOnly = 8			// break only at allowed line breaks, even if that
											// results in the text not fitting the measure
		};

	IMPORT_C TTmFormatParamBase();
	inline TBool IsWrapping() const;
	inline TBool IsTruncatingWithEllipsis() const;
	inline TBool LegalLineBreaksOnly() const;

	TInt iWrapWidth;					// wrapping width of the text including margins and indents, if wrapping is on
	TInt iMaxHeight;					// maximum height of the text
	TInt iMaxLines;						// maximum number of lines to be formatted
	TInt iFlags;						// flags defined above
	TChar iEllipsis;					// if truncating and not 0xFFFF, insert this ellipsis char (defaults to '...').
				
	};

/** 
Formatting parameters used when formatting an entire layout object or
creating a section of format code.
@internalComponent
*/
class TTmFormatParam: public TTmFormatParamBase

	{
public:
	IMPORT_C TTmFormatParam();
	IMPORT_C TTmFormatParam(const TTmFormatParamBase& aBase);

	TInt iStartChar;					// first character position to be formatted
	TInt iEndChar;						// last character position to be formatted
	TInt iLineInPar;					// starting line number in the paragraph
	};

/** 
Additional parameters used when reformatting.
@internalComponent
*/
class TTmReformatParam

	{
public:
	IMPORT_C TTmReformatParam();

	TInt iStartChar;					// start of changed text
	TInt iOldLength;					// length of text before the change
	TInt iNewLength;					// length of text after the change
	TInt iMaxExtraLines;				// maximum lines in the partial paragraph after the end of the changed text
										// to format in one go; the remainder can be handled by background formatting
	TBool iParFormatChanged;			// TRUE if the paragraph format of the changed text has changed
	TBool iParInvalid;					// format to the end of the paragraph
	};

/** 
Information returned when reformatting. 
@internalComponent
*/
class TTmReformatResult

	{
public:
	IMPORT_C TTmReformatResult();

	TRect iRedrawRect;					// rectangle to be redrawn
	TInt iHeightChange;					// change in height of the reformatted text
	TInt iUnchangedTop;					// y coordinate, before formatting, of the top of text needing no change,
										// including text in any section not yet formatted by this call
	TInt iUnformattedStart;				// start of any unformatted section; KMaxTInt if none
	};

/** 
A structure for returning information about a line. One of these is
returned by all hit-detection functions. Typically, after finding the position
in the document that corresponds to given x-y coordinates, you will want some
more information like the line's bounding rectangle. When you call, for
example, CTmTextLayout::FindXyPos you will receive a TTmLineInfo object that
will tell you this, and much more. 
@publishedAll
@released
*/
class TTmLineInfo

	{
public:
	// bit values for iFlags
	enum
		{
		EParStart = 1,
		EParEnd = 2,
		EParRightToLeft = 4,
 		ELineEndsInForcedLineBreak = 8,
 		EPictureButtsLowerEdge = 16,	/**< @deprecated - no effect, present for compatibility only */
 		EPictureButtsUpperEdge = 32	/**< @deprecated - no effect, present for compatibility only */
		};

	inline TTmLineInfo();
	
	/** Outer enclosing rectangle including margins */
	TRect iOuterRect;	
	
	/** Inner enclosing rectangle: the text only */
	TRect iInnerRect;
	
	/** y coordinate of the baseline */
	TInt iBaseline;	
	
	/** Start document position */
	TInt iStart;
	
	/** End document position */
	TInt iEnd;			
	
	/** Line number */
	TInt iLineNumber;
	
	/** Paragraph number */
	TInt iParNumber;	
	
	/** Line number in the paragraph */
	TInt iLineInPar;
	
	/** y coordinate of the top of the paragraph */
	TInt iParTop;

	/** Start of paragraph, end of paragraph, etc. */
	TUint iFlags;		
	};

/**
A structure to hold a logical document position that can be converted to a raw
document position or an x-y position.

A document position can specify a leading or trailing edge or a text
directionality so that bidirectional hit testing can use both these
distinctions.

The leading edge at position N is the position before character N in logical
order, and the trailing edge is the position after character in logical order.

Specification by directionality works differently. Character N in left-to-right
text is preceded by position N (left-to-right) and followed by position N+1
(left-to-right). Character N in right-to-left text is preceded (in display
order) by position N+1 (right-to-left) and followed by position N
(right-to-left).
@publishedAll
@released
*/
class TTmDocPosSpec

	{
public:
	/**
	The cursor type.
	*/
	enum TType
		{
		/** trailing edge */
		ETrailing,

		/** leading edge */
		ELeading,

		/** left-to-right */
		ELeftToRight,

		/** right-to-left */
		ERightToLeft
		};

	inline TTmDocPosSpec();
	inline TTmDocPosSpec(TInt aPos,TType aType);
	inline TTmDocPosSpec(const TTmDocPos& aRawDocPos);

	/** the edge position in the document; 0 ... document length */
	TInt iPos;
	/** the type as specified above */
	TType iType;	
	};

/** 
A structure for holding a raw document position that can be converted to or
from an x-y position and compared ordinally, which cannot be done with the more
abstract TTmDocPosSpec class. Leading edges are distinguished from trailing
edges so that bidirectional hit testing and cursor positioning can distinguish
between 'after character N', and 'before character N + 1', which may be some
distance apart if N and N + 1 are in runs of opposite directionality. 
@publishedAll
@released
*/
class TTmDocPos

	{
public:
	inline TTmDocPos();
	inline TTmDocPos(TInt aPos,TBool aLeadingEdge);
	IMPORT_C TBool operator==(const TTmDocPos& aPos) const;
	inline TBool operator!=(const TTmDocPos& aPos) const;
	IMPORT_C TBool operator>(const TTmDocPos& aPos) const;
	IMPORT_C TBool operator>=(const TTmDocPos& aPos) const;
	inline TBool operator<(const TTmDocPos& aPos) const;
	inline TBool operator<=(const TTmDocPos& aPos) const;

	/** the edge position in the document; 0 ... document length */
	TInt iPos;
	/** true if the position is a leading edge */
	TBool iLeadingEdge;	
	};

/** 
Holds information about a position in a document. 
@publishedAll
@released
*/	
class TTmPosInfo2

	{
public:
	/** Document position. */
	TTmDocPos iDocPos;
	/** True if the position is attatched to text flowing right-to-left. */
	TBool iRightToLeft;
	/** Intersection of the character edge with the baseline. */
	TPoint iEdge;
	};

/** 
A structure for returning information about a position in a line.
@deprecated 7.0s 
@internalComponent
*/
class TTmPosInfo

	{
public:
	TTmPosInfo() {}
	TTmPosInfo(const TTmPosInfo2& a) : iDocPos(a.iDocPos), iEdge(a.iEdge) {}
	TTmDocPos iDocPos;	// the document position
	TPoint iEdge;			// intersection of the character edge at iDocPos with the baseline
	};

/**
@internalComponent
*/
class TTmHighlightExtensions

	{
public:
	inline TTmHighlightExtensions();
	inline void SetAll(TInt aExtension);
	inline void SetLeftExtension(TInt aExtension);
	inline void SetRightExtension(TInt aExtension);
	inline void SetTopExtension(TInt aExtension);
	inline void SetBottomExtension(TInt aExtension);
	inline TInt LeftExtension() const;
	inline TInt RightExtension() const;
	inline TInt TopExtension() const;
	inline TInt BottomExtension() const;
	inline TBool Extends() const;
	inline TBool Shrinks() const;
	inline void ExtendRect(TRect& aRect) const;
	inline void AdjustRect(TRect& aRect) const;
	inline TBool IsNull() const;
	inline void AbsExtendRect(TRect& aRect) const;
public:
	TInt iLeftExtension;
	TInt iRightExtension;
	TInt iTopExtension;
	TInt iBottomExtension;
	};

/** 
Cursor placement. Used as an argument to CTextView::SetCursorPlacement().
@see CTextView::SetCursorPlacement()
@publishedAll
*/
enum TTmCursorPlacement
	{
	 /** The text cursor is a vertical line at the insertion position, with its height 
	and depth based on the metrics of the previous character in the paragraph 
	or if none, the next character. */
	ECursorVertical,		
	/** The text cursor is an underline below the character logically after the insertion 
	position. */
	ECursorUnderlineNext,
	/** The text cursor is an underline below the character logically before the insertion 
	position. */
	ECursorUnderlinePrev
	};

/**
The text layout for a single rectangular piece of text. The object does not own its text or format attributes but
gets them from an interface class called MTmSource.

There are functions for setting the text, drawing it, and converting between x-y coordinates and document positions.

Ranges

All ranges of character positions and pixels include the start but not the end. This means that if a line is described
by a TTmLineInfo object as starting at document position 345 and ending at 389, character positions 345 to 388 are in
the line; 389 is in the next line if any.

Coordinates and units

All coordinates used in TAGMA classes and function arguments are in pixels and are relative to the origin of the object,
which is the top left corner of the ordinary text, not including paragraph labels. Vertical coordinates increase from
top to bottom.

Document format and positions

A TAGMA document, as supplied by the MTmSource interface, has a length as returned by MTmSource::DocumentLength of
zero or more characters. It consists of Unicode text split into paragraphs by standard Unicode paragraph delimiters
(character value 0x2029), so the number of paragraphs in the entire document is one more than the number of
paragraph delimiters. A document position is a value in the range 0 to one more than the document length.
Lines contain all document positions from their start to one less than their end position. These conventions allow
all lines to end in a delimiter; the last line contains an imaginary paragraph end, which need not be supplied by
the MTmSource interface, at a position equal to the document length. A CTmTextLayout object formatted for an
empty document will thus have a start position (returned by StartChar) of 0 and an end position
(returned by EndChar) of 1.
@internalComponent
*/
class CTmTextLayout: public CBase

	{
public:
	
	class TTmChunkDescription
	/** 
	Output from FindAdjacentChunks. Describes a chunk of text that is of a
	constant format and directionality. 
	@internalComponent
	*/
		{
	public:
		/** Position of the first character in the chunk. A negative number
		indicates "no such chunk". */
		TInt iStart;
		/** One past the position of the last character in the chunk. */
		TInt iEnd;
		/** ETrue if the chunk is displayed right-to-left. */
		TBool iRightToLeft;
		};

	IMPORT_C CTmTextLayout();
	IMPORT_C ~CTmTextLayout();
	IMPORT_C void SetTextL(MTmSource& aSource,const TTmFormatParam& aParam);
	IMPORT_C void FormatL(const TTmFormatParamBase& aParam,const TTmReformatParam& aReformatParam,
						  TTmReformatResult& TTmReformatResult);
	IMPORT_C TBool AddParL(const TTmFormatParamBase& aParam,TBool aAtStart,TInt& aHeightIncrease,TInt& aParagraphsIncrease);
	IMPORT_C TBool DeletePar(const TTmFormatParamBase& aParam,TBool aAtStart,TInt aMaxDeletedHeight,TInt& aHeightDecrease);
	IMPORT_C void Clear();
	IMPORT_C void DrawLayout(CGraphicsContext& aGc,const TPoint& aTopLeft,const TRect& aClipRect,
							 const TLogicalRgb* aDocBackground,TBool aDrawParBackground) const;
	IMPORT_C void DrawBackground(CGraphicsContext& aGc,const TPoint& aTopLeft,const TRect& aClipRect,
								 const TLogicalRgb& aBackground) const;
	IMPORT_C void InvertLayout(CGraphicsContext& aGc, const TPoint& aTopLeft,
		TInt aStartDocPos, TInt aEndDocPos) const;
	IMPORT_C void HighlightSection(CGraphicsContext& aGc, const TPoint& aTopLeft,
		TInt aStartDocPos, TInt aEndDocPos, const TRect& aClipRect) const;
	IMPORT_C void DrawSection(CGraphicsContext& aGc, const TPoint& aTopLeft,
		TInt aStartDocPos, TInt aEndDocPos, const TRect& aClipRect) const;
	IMPORT_C void HighlightSection(CGraphicsContext& aGc, const TPoint& aTopLeft,
		TInt aStartDocPos, TInt aEndDocPos, const TRect& aClipRect, const TTmHighlightExtensions& aHighlightExtensions,
		TInt aHighlightStartDocPos, TInt aHighlightEndDocPos) const;
	IMPORT_C void InvertLayout(CGraphicsContext& aGc,
		const TPoint& aTopLeft, TInt aStartDocPos,TInt aEndDocPos, const TTmHighlightExtensions& aHighlightExtensions,
		TInt aHighlightStartDocPos, TInt aHighlightEndDocPos) const;
	IMPORT_C void DrawSection(CGraphicsContext& aGc, const TPoint& aTopLeft,
		TInt aStartDocPos, TInt aEndDocPos, const TRect& aClipRect, const TTmHighlightExtensions& aHighlightExtensions,
		TInt aHighlightStartDocPos, TInt aHighlightEndDocPos) const;
	IMPORT_C TBool FindDocPos(const TTmDocPosSpec& aDocPos,TTmPosInfo2& aPosInfo,TTmLineInfo& aLineInfo) const;
	IMPORT_C TBool FindXyPos(const TPoint& aXyPos,TTmPosInfo2& aPosInfo,TTmLineInfo& aLineInfo) const;
	IMPORT_C TBool FindXyPosWithDisambiguation(const TPoint& aXyPos,
		TTmPosInfo2& aPosLeft, TTmPosInfo2& aPosRight,
		TTmLineInfo& aLineInfo) const;
	IMPORT_C TInt FindNextPos(TInt aStart) const;
	IMPORT_C TInt FindPreviousPos(TInt aStart) const;
	IMPORT_C TInt Lines() const;
	IMPORT_C TInt Paragraphs() const;
	IMPORT_C TBool DocPosToLine(const TTmDocPosSpec& aDocPos,TTmLineInfo& aLineInfo) const;
	IMPORT_C TBool LineNumberToLine(TInt aLineNumber,TTmLineInfo& aLineInfo) const;
	IMPORT_C TBool ParNumberToLine(TInt aParNumber,TInt aLineInPar,TTmLineInfo& aLineInfo) const;
	IMPORT_C TBool YPosToLine(TInt aYPos,TTmLineInfo& aLineInfo) const;
	IMPORT_C TBool GetDisplayedTextL(TInt aLineNumber,TDes& aText,TInt& aNeeded) const;
	IMPORT_C void GetMinimumLayoutSizeL(TInt aWrapWidth,TSize& aSize) const;
	IMPORT_C void GetMinimumLayoutSizeL(TInt aWrapWidth,TBool aAllowLegalLineBreaksOnly,TSize& aSize) const;
	IMPORT_C TInt WidthOfWidestLine(TInt aTop = 0,TInt aBottom = KMaxTInt) const;
	IMPORT_C void HorizontalExtremes(TInt &aLeft, TInt &aRight,
		TInt aTopY = 0, TInt aBottomY = KMaxTInt) const;
	IMPORT_C TBool GetNextVisualCursorPos(const TTmDocPosSpec& aDocPos,TTmPosInfo2& aInfo,TBool aToLeft) const;
	IMPORT_C TBool GetNextPosLeftWithDisambiguation(const TTmDocPosSpec& aDocPos,
		TTmPosInfo2& aPosLeft, TTmPosInfo2& aPosRight) const;
	IMPORT_C TBool GetNextPosRightWithDisambiguation(const TTmDocPosSpec& aDocPos,
		TTmPosInfo2& aPosLeft, TTmPosInfo2& aPosRight) const;
	IMPORT_C TBool LineExtreme(const TTmDocPosSpec& aPos, TBool aToRight,
		TTmDocPos& aExtreme) const;
	IMPORT_C TBool FindAdjacentChunks(const TTmDocPosSpec& aPos,
		TTmChunkDescription& aLeft, TTmChunkDescription& aRight) const;
	IMPORT_C TBool GetCursor(const TTmDocPosSpec& aDocPos,TTmCursorPlacement aPlacement,
							 TTmLineInfo& aLineInfo,TPoint& aOrigin,TInt& aWidth,TInt& aAscent,TInt& aDescent) const;
	IMPORT_C TInt MemoryUsed() const;
	inline TInt StartChar() const;
	inline TInt EndChar() const;
	inline TInt LayoutWidth() const;
	inline TInt LayoutHeight() const;
	inline MTmSource* Source();
	inline const MTmSource* Source() const;
	inline const CTmCode& Code() const;
 	IMPORT_C void MakeVisible(TBool aVisible);
 	TInt GetDrawingInterpFlags() const;
	IMPORT_C void DeleteFormattingFromEndL(
		const TTmFormatParamBase& aParam, TInt aMaxDeletedHeight, TInt& aHeightDecrease);
	IMPORT_C void ExtendFormattingDownwardsL(TTmFormatParam& aParam);

	// deprecated functions
	// deprecated 7.0
	IMPORT_C TBool GetDisplayedText(TInt aLineNumber,TDes& aText,TInt& aNeeded) const;
	// deprecated 7.0s
	IMPORT_C TBool FindDocPos(const TTmDocPos& aDocPos,TTmPosInfo& aPosInfo,TTmLineInfo& aLineInfo) const;
	// deprecated 7.0s
	IMPORT_C TBool FindXyPos(const TPoint& aXyPos,TTmPosInfo& aPosInfo,TTmLineInfo& aLineInfo) const;
	// deprecated 7.0s
	IMPORT_C TBool GetNextVisualCursorPos(const TTmDocPos& aDocPos,TTmPosInfo& aInfo,TBool aToLeft) const;
	// deprecated 7.0s
	IMPORT_C TBool DocPosToLine(const TTmDocPos& aDocPos,TTmLineInfo& aLineInfo) const;
	// deprecated 7.0s
	IMPORT_C TBool GetCursor(const TTmDocPos& aDocPos,
		TTmCursorPlacement aPlacement, TTmLineInfo& aLineInfo,
		TPoint& aOrigin, TInt& aWidth, TInt& aAscent, TInt& aDescent) const;

	IMPORT_C void DrawLayout(CGraphicsContext& aGc,const TPoint& aTopLeft,const TRect& aClipRect,
							 const TLogicalRgb* aDocBackground,TBool aDrawParBackground,
							 const TCursorSelection* aHighlight,
							 const TTmHighlightExtensions* aHighlightExtensions) const;
	IMPORT_C void GetUpdateBoundingRect(TInt aStartDocPos, TInt aEndDocPos, const TPoint& aTopLeft,
		TRect& aBoundingRect) const;

	IMPORT_C TBool FindDocPos(const TTmDocPosSpec& aDocPos,TTmPosInfo2& aPosInfo,TTmLineInfo& aLineInfo, TInt& aSubscript) const;
private:
	TBool LastLine(TTmLineInfo& aLine);
#ifdef _DEBUG
	void Invariant() const;
#else
	void Invariant() const { }
#endif
	void AdjustWidth(const TTmFormatParamBase& aParam,TInt aWidthOfNewText);

	MTmSource* iSource;				// source of text and text attributes; not owned
	CTmCode iCode;					// the layout bytecode
	TInt iWidth;					// width in pixels
	TInt iHeight;					// height in pixels
	TInt iStartChar;				// start character position in the document
	TInt iEndChar;					// end character position in the document
	TBidirectionalContext* iBdStateAtEnd; //bidirectional state at end of formatted range
	TInt iDrawingInterpFlags;		// flags destined for the RTmDrawingInterpreter object
	// please try to avoid removing or adding any new members to this class. although it
	// is internal, it is included by value in CTextLayout which is published.  therefore
	// a size change in this class would mean a size change in CTextLayout and a BC break.
	// if adding or removing members is unavoidable, please remember to update the dummy
	// member in CTextLayout accordingly.
	};

/**
A mixin class to make it easy for higher-level classes that own a CTmTextLayout
object to have enquiry functions without it being necessary to implement them
all as forwarding functions. The owner class just implements TextLayout and
overrides GetOrigin if necessary.

Non-const CTmTextLayout functions like Clear are not included because allowing
them to be called on owner classes would probably put the owner class into an
inconsistent state.

The word Layout is prefixed, suffixed or infixed to functions with names that
would usually conflict with owner class names. For example, we have DrawLayout,
not Draw, and GetMinimumLayoutSizeL, not GetMinimumSizeL.
@internalComponent
*/
class MTmTextLayoutForwarder

	{
public:
	IMPORT_C void DrawLayout(CGraphicsContext& aGc,const TPoint& aTopLeft,const TRect& aClipRect,
							 const TLogicalRgb* aDocBackground,TBool aDrawParBackground) const;
	IMPORT_C void DrawBackground(CGraphicsContext& aGc,const TPoint& aTopLeft,const TRect& aClipRect,
								 const TLogicalRgb& aBackground) const;
	IMPORT_C void InvertLayout(CGraphicsContext& aGc,const TPoint& aTopLeft,TInt aStartDocPos,TInt aEndDocPos);
	IMPORT_C TBool FindDocPos(const TTmDocPosSpec& aDocPos,TTmPosInfo2& aPosInfo,TTmLineInfo& aLineInfo) const;
	IMPORT_C TBool FindXyPos(const TPoint& aXyPos,TTmPosInfo2& aPosInfo,TTmLineInfo& aLineInfo) const;
	IMPORT_C TBool FindXyPosWithDisambiguation(const TPoint& aXyPos,
		TTmPosInfo2& aPosLeft, TTmPosInfo2& aPosRight,
		TTmLineInfo& aLineInfo) const;
	IMPORT_C TBool DocPosToLine(const TTmDocPosSpec& aDocPos,TTmLineInfo& aLineInfo) const;
	IMPORT_C TBool LineNumberToLine(TInt aLineNumber,TTmLineInfo& aLineInfo) const;
	IMPORT_C TBool ParNumberToLine(TInt aParNumber,TInt aLineInPar,TTmLineInfo& aLineInfo) const;
	IMPORT_C TBool YPosToLine(TInt aYPos,TTmLineInfo& aLineInfo) const;
	IMPORT_C TInt WidthOfWidestLine(TInt aTop = 0,TInt aBottom = KMaxTInt) const;
	IMPORT_C void HorizontalExtremes(TInt &aLeft, TInt &aRight,
		TInt aTopY = 0, TInt aBottomY = KMaxTInt) const;
	IMPORT_C TBool GetNextVisualCursorPos(const TTmDocPosSpec& aDocPos,TTmPosInfo2& aInfo,TBool aToLeft) const;
	IMPORT_C TBool GetNextPosLeftWithDisambiguation(const TTmDocPosSpec& aDocPos,
		TTmPosInfo2& aPosLeft, TTmPosInfo2& aPosRight) const;
	IMPORT_C TBool GetNextPosRightWithDisambiguation(const TTmDocPosSpec& aDocPos,
		TTmPosInfo2& aPosLeft, TTmPosInfo2& aPosRight) const;
	IMPORT_C TBool GetCursor(const TTmDocPosSpec& aDocPos,TTmCursorPlacement aPlacement,
							 TTmLineInfo& aLineInfo,TPoint& aOrigin,TInt& aWidth,TInt& aAscent,TInt& aDescent) const;

	IMPORT_C TInt Lines() const;
	IMPORT_C TInt Paragraphs() const;
	IMPORT_C TBool GetDisplayedText(TInt aLineNumber,TDes& aText,TInt& aNeeded) const;
	IMPORT_C void GetMinimumLayoutSizeL(TInt aWrapWidth,TSize& aSize) const;
	IMPORT_C void GetMinimumLayoutSizeL(TInt aWrapWidth,TBool aAllowLegalLineBreaksOnly,TSize& aSize) const;
	IMPORT_C TInt StartChar() const;
	IMPORT_C TInt EndChar() const;
	IMPORT_C TInt LayoutWidth() const;
	IMPORT_C TInt LayoutHeight() const;

	// deprecated functions
	// deprecated 7.0s
	IMPORT_C TBool FindDocPos(const TTmDocPos& aDocPos,TTmPosInfo& aPosInfo,TTmLineInfo& aLineInfo) const;
	// deprecated 7.0s
	IMPORT_C TBool FindXyPos(const TPoint& aXyPos,TTmPosInfo& aPosInfo,TTmLineInfo& aLineInfo) const;
	// deprecated 7.0s
	IMPORT_C TBool DocPosToLine(const TTmDocPos& aDocPos,TTmLineInfo& aLineInfo) const;
	// deprecated 7.0s
	IMPORT_C TBool GetNextVisualCursorPos(const TTmDocPos& aDocPos,TTmPosInfo& aInfo,TBool aToLeft) const;
	// deprecated 7.0s
	IMPORT_C TBool GetCursor(const TTmDocPos& aDocPos,
		TTmCursorPlacement aPlacement, TTmLineInfo& aLineInfo,
		TPoint& aOrigin, TInt& aWidth, TInt& aAscent, TInt& aDescent) const;
private:
	/** Returns a reference to the CTmTextLayoutObject this
	MTmTextLayoutForwarder forwards inquiries to. */
	virtual const CTmTextLayout& TextLayout() const = 0;
	
	/** The origin is subtracted from coordinates passed in and added to those
	passed out. */
	IMPORT_C virtual void GetOrigin(TPoint& aPoint) const;

	void FixUpLineInfo(TTmLineInfo& aInfo,const TPoint* aOrigin = NULL) const;
	};

/** 
A character format layer. Unmasked attributes are transparent. 
@internalComponent
*/	
class TTmCharFormatLayer

	{
public:
	inline TTmCharFormatLayer();
	IMPORT_C TTmCharFormatLayer(const CCharFormatLayer& aFormat);

	TTmCharFormat iFormat;
	TTmCharFormatMask iMask;
	};

/** 
A paragraph format layer. Unmasked attributes are transparent. 
@internalComponent
*/
class RTmParFormatLayer

	{
public:
	inline void Close();
	IMPORT_C void CopyL(const CParaFormatLayer& aFormat);

	RTmParFormat iFormat;
	TTmParFormatMask iMask;
	};

/**
 A style. 
@internalComponent
*/
class RTmStyle

	{
public:
	enum
		{
		EMaxName = KMaxParagraphStyleName
		};

	inline void Close();
	IMPORT_C void CopyL(const RParagraphStyleInfo& aStyle);
	IMPORT_C void GetRParagraphStyleInfoL(RParagraphStyleInfo& aStyle,
		const CParaFormatLayer& aGlobalParaFormatLayer,const CCharFormatLayer& aGlobalCharFormatLayer,
		const CStyleList& aList) const;

	TBuf<KMaxName> iName;
	TBuf<KMaxName> iNextStyleName;
	TTmCharFormatLayer iCharFormat;
	RTmParFormatLayer iParFormat;
	TInt iOutlineLevel;
	};

/** 
A self-contained text object. It owns both layout and content. It is
intended for labels and the general display of small-to-medium-sized amounts of
text. 
@internalComponent
*/
class CTmText: public CBase, public MTmTextLayoutForwarder

	{
public:
	IMPORT_C static CTmText* NewL(MGraphicsDeviceMap* aDevice = NULL,const TTmFormatParamBase* aFormatParam = NULL);
	IMPORT_C static CTmText* NewL(MGraphicsDeviceMap& aDevice,const TTmFormatParamBase& aFormatParam);
	IMPORT_C static CTmText* NewL(MGraphicsDeviceMap& aDevice,TInt aWrapWidth,TInt aFlags);
	IMPORT_C ~CTmText();
	IMPORT_C void InsertL(TInt aPos,const TDesC& aText,
						  const TTmCharFormat* aCharFormat = NULL,const RTmParFormat* aParFormat = NULL,
						  TRect* aRedrawRect = NULL,TInt* aScroll = NULL);
	IMPORT_C void GetFormat(TTmFormatParamBase& aFormatParam) const;
	IMPORT_C void SetWrapWidthL(TInt aWrapWidth);
	IMPORT_C void ChangeFormatL(const TTmFormatParamBase& aFormatParam);
	IMPORT_C void Clear();
	IMPORT_C void CustomizeL(const MTmCustom* aCustom);
	IMPORT_C TInt MemoryUsed() const;
	inline void Draw(CGraphicsContext& aGc,const TPoint& aTopLeft,const TRect& aClipRect,
					 const TLogicalRgb* aDocBackground,TBool aDrawParBackground);

private:
	CTmText();
	IMPORT_C void Spare1();

	// implementations of MTmTextLayoutForwarder virtual functions
	const CTmTextLayout& TextLayout() const;

	CTmTextImp* iImp;		// the implementation
	};

// inline functions
/** Constructs a TTmCharFormatMask. Turns all the flags on. */
TTmCharFormatMask::TTmCharFormatMask(): iFlags(0xFFFFFFFF)
	{
	}

/** Clears the selected flag.*/
void TTmCharFormatMask::Clear(TAttrib aAttrib)
	{
	iFlags &= ~aAttrib;
	}

/** Sets the selected flag. */
void TTmCharFormatMask::Set(TAttrib aAttrib)
	{
	iFlags |= aAttrib;
	}

/** Returns true if the selected attribute is set. */
TBool TTmCharFormatMask::IsSet(TAttrib aAttrib)
	{
	return iFlags & aAttrib;
	}

/** Constructs a TTmCharFormat by converting the information in a TCharFormat. */
TTmCharFormat::TTmCharFormat(const TCharFormat& aFormat)
	{
	*this = aFormat;
	}

/** The inequality operator. Return TRUE if this object and aFormat differ in any way. */
TBool TTmCharFormat::operator!=(const TTmCharFormat& aFormat) const
	{
	return !operator==(aFormat);
	}

/** Constructs a TTmTab and set it to a standard tab stop with a position of 0. */
TTmTab::TTmTab():
	iPosition(0),
	iType(EStandardTab)
	{
	}

/** Constructs a TTmTab by converting the information in a TTabStop. */
TTmTab::TTmTab(const TTabStop& aTab)
	{
	*this = aTab;
	}

/** The inequality operator. Returns TRUE if this object and aTab differ in any
way. */
TBool TTmTab::operator!=(const TTmTab& aTab) const
	{
	return !operator==(aTab);
	}

/** Constructs a TTmBullet by converting the information in a TBullet. */
TTmBullet::TTmBullet(const TBullet& aBullet)
	{
	*this = aBullet;
	}

/** The inequality operator. Returns true if this object and aBullet differ in
any way. */
TBool TTmBullet::operator!=(const TTmBullet& aBullet) const
	{
	return !operator==(aBullet);
	}

/** Constructs a TTmParBorder by converting the information in a TParaBorder. */
TTmParBorder::TTmParBorder(const TParaBorder& aBorder)
	{
	*this = aBorder;
	}

/** The inequality operator. Returns TRUE if this object and aBorder differ in
any way. */
TBool TTmParBorder::operator!=(const TTmParBorder& aBorder) const
	{
	return !operator==(aBorder);
	}

/** Constructs a TTmParFormatMask with all the flags on. */
TTmParFormatMask::TTmParFormatMask():
	iFlags(0xFFFFFFFF)
	{
	}

/** Clears the selected flag. */
void TTmParFormatMask::Clear(TAttrib aAttrib)
	{
	iFlags &= ~aAttrib;
	}

/** Sets the selected flag. */
void TTmParFormatMask::Set(TAttrib aAttrib)
	{
	iFlags |= aAttrib;
	}

/**
Returns true if the selected flag is Set.
*/
TBool TTmParFormatMask::IsSet(TAttrib aAttrib)
	{
	return iFlags & aAttrib;
	}

#ifdef _DEBUG
RTmParFormat::~RTmParFormat()
	{
	__ASSERT_DEBUG(!iTabList && !iBullet && !HaveBorders(), User::Invariant());
	}
#endif

/** The inequality operator. Returns true if this object and aFormat differ in
any way.
*/
TBool RTmParFormat::operator!=(const RTmParFormat& aFormat) const
	{
	return !operator==(aFormat);
	}

/** Returns a reference to the tab selected by aIndex. */
const TTmTab& RTmParFormat::Tab(TInt aIndex) const
	{
	return (*iTabList)[aIndex];
	}

/** Returns a pointer to the TTmBullet object if any. Returns null if the
RTmParFormat does not contain a TTmBullet. */
const TTmBullet* RTmParFormat::Bullet() const
	{
	return iBullet;
	}

/** Returns a pointer to the border selected by aIndex. Returns null if the
selected border is not present. */
const TTmParBorder* RTmParFormat::Border(TBorderIndex aIndex) const
	{
	return iBorder[aIndex];
	}

/** Returns true if the paragraph's base direction is right-to-left. */
TBool RTmParFormat::RightToLeft() const
	{
	return iFlags & ERightToLeft;
	}

/** Constructs a line height parameter structure, setting all the data members
to zero. */
MTmCustom::TLineHeightParam::TLineHeightParam()
	{
	Mem::FillZ(this,sizeof(*this));
	}

CTmBufSeg::CTmBufSeg(TInt aExpandSize):
	CBufSeg(aExpandSize)
	{
	}

CTmCode::~CTmCode()
	{
	delete iBuffer;
	}

TPtr8 CTmCode::Ptr(TInt aPos)
	{
	return iBuffer->Ptr(aPos);
	}

CBufBase* CTmCode::Buffer()
	{
	return iBuffer;
	}

const CBufBase* CTmCode::Buffer() const
	{
	return iBuffer;
	}

/** Returns true if wrapping is turned on. */
TBool TTmFormatParamBase::IsWrapping() const
	{
	return iFlags & EWrap;
	}

/** Returns true if truncation with ellipsis is turned on. */
TBool TTmFormatParamBase::IsTruncatingWithEllipsis() const
	{
	return iFlags & ETruncateWithEllipsis;
	}

/** Returns true if line breaking must only occur at legal line breaks, even if
the line cannot legally be broken at the desired wrap width. */
TBool TTmFormatParamBase::LegalLineBreaksOnly() const
	{
	return iFlags & ELegalLineBreaksOnly;
	}

/** Constructs a TTmLineInfo object, setting all data members to 0. */
TTmLineInfo::TTmLineInfo()
	{
	Mem::FillZ(this,sizeof(*this));
	}

/** Constructs a TTmDocPos object, setting iPos to 0 and iLeadingEdge to false.
This is the lowest legal value for a TTmDocPos object. A trailing edge comes
before a leading edge because it is the trailing edge of the character before
the position, while the leading edge is that of the character after the
position. ('Leading' means the first to be encountered when traversing the
document in logical order). */
TTmDocPos::TTmDocPos():
	iPos(0),
	iLeadingEdge(FALSE)
	{
	}

/** Constructs a TTmDocPos object, setting iPos to aPos and iLeadingEdge to
aLeadingEdge.
*/
TTmDocPos::TTmDocPos(TInt aPos,TBool aLeadingEdge):
	iPos(aPos),
	iLeadingEdge(aLeadingEdge)
	{
	}

/** Constructs a TTmDocPosSpec, setting the position to 0 and the type to
trailing. */
TTmDocPosSpec::TTmDocPosSpec():
	iPos(0),
	iType(ETrailing)
	{
	}
	

/**
The not equal operator.
@return True if both sides have different values.
*/
TBool TTmDocPos::operator!=(const TTmDocPos& aPos) const { return !((*this)==aPos); }

/**
Smaller than operator.
@return
	True if the right side of the operator is further on in the document than
	the left hand side.
*/
TBool TTmDocPos::operator<(const TTmDocPos& aPos) const { return !((*this)>=aPos); }

/**
Smaller than or equal to operator.
@return
	True if the right side of the operator is further on in the document than
	the left hand side or if both sides are identical.
*/
TBool TTmDocPos::operator<=(const TTmDocPos& aPos) const { return !((*this)>aPos); }

/** Constructs a TTmDocPosSpec, setting the position to aPos and the type to
aType.
*/
TTmDocPosSpec::TTmDocPosSpec(TInt aPos,TType aType):
	iPos(aPos),
	iType(aType)
	{
	}

/** Constructs a TTmDocPosSpec from a TTmDocPos. */
TTmDocPosSpec::TTmDocPosSpec(const TTmDocPos& aDocPos):
	iPos(aDocPos.iPos),
	iType(aDocPos.iLeadingEdge ? ELeading : ETrailing)
	{
	}

/** Returns the first formatted character. */
TInt CTmTextLayout::StartChar() const
	{
	return iStartChar;
	}

/** Returns the character after the last formatted character. */
TInt CTmTextLayout::EndChar() const
	{
	return iEndChar;
	}

/** Return the width in pixels of the formatted text, not including paragraph
labels if present. */
TInt CTmTextLayout::LayoutWidth() const
	{
	return iWidth;
	}

/** Returns the height in pixels of the formatted text. */
TInt CTmTextLayout::LayoutHeight() const
	{
	return iHeight;
	}

/** Returns a pointer to to the MTmSource object, if any, that provides text
and formatting to this object. Returns null if no source object has been set. */
MTmSource* CTmTextLayout::Source()
	{
	return iSource;
	}

const MTmSource* CTmTextLayout::Source() const
	{
	return iSource;
	}

/**
Returns a reference to the CTmCode object containing the bytecode
representing the text layout.
@internalComponent
*/
const CTmCode& CTmTextLayout::Code() const
	{
	return iCode;
	}

/** Constructs a TTmCharFormatLayer object containing default TTmCharFormat and
TTmCharFormatMask objects. */
TTmCharFormatLayer::TTmCharFormatLayer()
	{
	}

/** Closes an RTmParFormatLayer object by freeing any objects allocated on the
heap. */
void RTmParFormatLayer::Close()
	{
	iFormat.Close();
	}

/** Closes an RTmStyle object by freeing any objects allocated on the heap.
*/
void RTmStyle::Close()
	{
	iParFormat.Close();
	}

/** Draws the formatted text. This inline function just calls
CTmText::DrawLayout and is identical to it. It is provided for coding
convenience because of the expectation that a drawing function called Draw
exists. */
void CTmText::Draw(CGraphicsContext& aGc,const TPoint& aTopLeft,const TRect& aClipRect,
				   const TLogicalRgb* aDocBackground,TBool aDrawParBackground)
	{
	DrawLayout(aGc,aTopLeft,aClipRect,aDocBackground,aDrawParBackground);
	}

/** Contains the extensions to character rectangle used when highlighting 
the text in reverse video
*/
TTmHighlightExtensions::TTmHighlightExtensions()
	{
	}

void TTmHighlightExtensions::SetAll(TInt aExtension)
	{
	iLeftExtension=iRightExtension=iTopExtension=iBottomExtension=aExtension;
	}

void TTmHighlightExtensions::SetLeftExtension(TInt aExtension)
	{
	iLeftExtension=aExtension;
	}

void TTmHighlightExtensions::SetRightExtension(TInt aExtension)
	{
	iRightExtension=aExtension;
	}

void TTmHighlightExtensions::SetTopExtension(TInt aExtension)
	{
	iTopExtension=aExtension;
	}

void TTmHighlightExtensions::SetBottomExtension(TInt aExtension)
	{
	iBottomExtension=aExtension;
	}

TInt TTmHighlightExtensions::LeftExtension() const
	{
	return iLeftExtension;
	}

TInt TTmHighlightExtensions::RightExtension() const
	{
	return iRightExtension;
	}

TInt TTmHighlightExtensions::TopExtension() const
	{
	return iTopExtension;
	}

TInt TTmHighlightExtensions::BottomExtension() const
	{
	return iBottomExtension;
	}

inline TBool TTmHighlightExtensions::Extends() const
	{
	return (iTopExtension > 0 || iBottomExtension > 0 || iLeftExtension > 0 || iRightExtension > 0);
	}

inline TBool TTmHighlightExtensions::Shrinks() const
	{
	return (iTopExtension < 0 || iBottomExtension < 0 || iLeftExtension < 0 || iRightExtension < 0);
	}

inline void TTmHighlightExtensions::ExtendRect(TRect& aRect) const
	{
	if (iLeftExtension>0)
		aRect.iTl.iX-=iLeftExtension;
	if (iRightExtension>0)
		aRect.iBr.iX+=iRightExtension;
	if (iTopExtension>0)
		aRect.iTl.iY-=iTopExtension;
	if (iBottomExtension>0)
		aRect.iBr.iY+=iBottomExtension;
	}

inline void TTmHighlightExtensions::AdjustRect(TRect& aRect) const
	{
	aRect.iTl.iX-=iLeftExtension;
	aRect.iTl.iY-=iTopExtension;
	aRect.iBr.iX+=iRightExtension;
	aRect.iBr.iY+=iBottomExtension;
	}

inline TBool TTmHighlightExtensions::IsNull() const
	{
	return 0 == iLeftExtension && 0 == iTopExtension && 0 == iRightExtension && 0 == iBottomExtension;
	}

inline void TTmHighlightExtensions::AbsExtendRect(TRect& aRect) const
	{
	if (iLeftExtension>0)
		aRect.iTl.iX-=iLeftExtension;
	else
		aRect.iTl.iX+=iLeftExtension;

	if (iRightExtension>0)
		aRect.iBr.iX+=iRightExtension;
	else
		aRect.iBr.iX-=iRightExtension;

	if (iTopExtension>0)
		aRect.iTl.iY-=iTopExtension;
	else
		aRect.iTl.iY+=iTopExtension;

	if (iBottomExtension>0)
		aRect.iBr.iY+=iBottomExtension;
	else
		aRect.iBr.iY-=iBottomExtension;
	}

#endif // __TAGMA_H__
