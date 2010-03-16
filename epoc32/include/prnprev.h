// Copyright (c) 1997-2009 Nokia Corporation and/or its subsidiary(-ies).
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

#if !defined (__PRNPREV_H__)
#define __PRNPREV_H__

#if !defined(__E32STD_H__)
#include  <e32std.h>
#endif
#if !defined(__E32BASE_H__)
#include  <e32base.h>
#endif
#if !defined(__PRNSETUP_H__)
#include <prnsetup.h>
#endif

// classes defined:
class TPrintPreviewFormat;
class TPreviewPanel;
class CPrintPreviewImage;
//

// forward references:
class RWsSession;
class RWindow;
class CPrintPreviewDevice;
//


class TPrintPreviewFormat
/** Print preview format information.

The print preview format information is accessed via its public data members. 
Typically there is a system wide TPrintPreviewFormat supplied by the GUI framework. 

Preview information includes:

- panel settings: multiple pages can be previewed at once; the display area 
for each page is termed a panel.

- label settings: each panel can have an associated label, which specifies the 
corresponding document page number 

@publishedAll 
@released */
	{
public:
	/** The minimum panel gutter size, in pixels. */
	TSize iMinPanelGutterInPixels;
	/** The width of the panel shadow, in pixels. */
	TInt iPanelShadowWidthInPixels;
	/** The colour of the panel shadow. */
	TRgb iPanelShadowColor;
	/** The panel margin colour. */
	TRgb iPanelMarginColor;
	/** The color of both the paper and the window background. */
	TRgb iPreviewBackgroundColor;
	/** X pixel offset of the label text from the panel edge. */
	TInt iLabelOffsetInPixels;
	/** Font specification for the label text. */
	TFontSpec iLabelFontSpecInPixels;
	};


class CPrintPreviewImage : public CBase, private MPrintProcessObserver, private MPageRegionPrinter
/** Print preview image.

This class provides a standard print preview image. An object of this type 
should be owned by a control, which is in turn owned by the print preview 
dialog. The control's window provides the region into which this object draws 
the preview image.

The class provides a callback to the application code that draws the preview 
pages. 

@publishedAll 
@released */
	{
public:
	/** Margin display state flags. */
	enum TMarginState {
		/** Show margins in print preview image. */
		EShowMargins,
		/** Hide margins in print preview image. */
		EHideMargins
		};
public:
	IMPORT_C static CPrintPreviewImage* NewL(CPrintSetup& aPrintSetup,MPageRegionPrinter& aBodyPrinter,
											RWsSession& aWsSession,RWindow& aWindow,const TSize& aMaxWindowSize,
											const TPrintPreviewFormat& aStaticFormat);
	IMPORT_C virtual ~CPrintPreviewImage();
	IMPORT_C void SetMargins(TMarginState aState); // whether  or not to show margins
	IMPORT_C void SetObserver(MPrintProcessObserver& aObserver);
	IMPORT_C void SetNumBands(TInt aNum);
	IMPORT_C void FormatL(TInt aNumPagesInDoc,TInt aFirstPageToDisplay,TInt aNumPagesToView); // call when scrolling or changing num pages to view
	IMPORT_C void DrawL(const TPoint& aOrigin,const TRect& aInvalidRegion); // aOrigin is the point in the window I will treat as the origin (ie offset)
	//
private:
	class TPreviewPanel;
	class TRange
		{
	public:
		TInt iFrom;
		TInt iTo;
		};
private:
	CPrintPreviewImage(CPrintSetup& aPrintSetup,MPageRegionPrinter& aBodyPrinter,RWsSession& aWsSession,
						RWindow& aWindow,const TSize& aMaxWindowSize,const TPrintPreviewFormat& aStaticFormat);
	void ConstructL();
	void CalculateHeaderFooterRects(TRect& aHeaderRectInPixels,TRect& aFooterRectInPixels);
	TInt SetPanelArrayL(const TInt aFirstPage,const TInt aNumPagesToView); 
	void SetLabelWidth();
	void ScrollPanels();
	void DrawBorder(CGraphicsContext* aGc); // and shadow
	void DrawMargins(CGraphicsContext* aGc); // including header/footer lines
	void DrawLabel(CGraphicsContext* aGc,TInt aPageNo);
	void DrawToGutter(CGraphicsContext* aGc,TInt aPageNo); // blanks all the gutter areas associated to a particular panel
	void DrawExtremities(CGraphicsContext* aGc); // blanks very left and right of the window
	inline TBool IsFirstPanel(TInt aPageNum);
	inline TBool IsLastPanel(TInt aPageNum);
	// from MPrintProcessObserver
	virtual void NotifyPrintStarted(TPrintParameters aPrintParams);
	virtual void NotifyBandPrinted(TInt aPercentageOfPagePrinted, TInt aCurrentPageNum, TInt aCurrentCopyNum);
	virtual void NotifyPrintEnded(TInt anErrorCode);
	// from MPageRegionPrinter
	virtual void PrintBandL(CGraphicsDevice* aDevice,TInt aPageNo,const TBandAttributes& aBand);
private:
	CPrintPreviewDevice* iDevice;
	CPrintSetup* iPrintSetup;
	MPageRegionPrinter* iAppBodyPrinter;
	MPrintProcessObserver* iObserver; // may be null
	RWsSession* iWsSession;
	RWindow* iWindow;
	CFont* iLabelFont;
	CArrayFix<TPreviewPanel>* iPanelArray;
	//
	TPrintPreviewFormat iFormat;
	TPrintParameters iPrintParams; // current preview range
	TMarginState iMarginState; // whether the margins are on or not
	TSize iPanelSizeInPixels;
	TSize iWinSize; // size of the window (for layout purposes)
	TPoint iOrigin; // origin in the window to use for drawing
	TSize iLabelSize;
	TSize iActualGutter; // gap from the edge of the panel to either screen edge or adjacent panel
	TInt iNumPagesInDoc; 
	TInt iNumBands;
	TSize iRndError; // rounding error from calculation of iActualGutter
	TRange iDrawRange; // the pages that actually require drawing - ie have not been scrolled 
	};


/** Internalises the margin state from a read stream.

@param aThing The margin state to be internalised - on or off.
@param aStream The read stream from which the margin state is to be internalised. 

@publishedAll 
@released */
IMPORT_C void InternalizeL(CPrintPreviewImage::TMarginState& aThing,RReadStream& aStream);

inline RWriteStream& operator<<(RWriteStream& aStream,const CPrintPreviewImage::TMarginState& aThing) 
/**
@publishedAll 
@released 
*/
	{aStream.WriteUint8L(aThing);return aStream;}

inline RReadStream& operator>>(RReadStream& aStream,CPrintPreviewImage::TMarginState& aThing) 
/**
@publishedAll 
@released 
*/
	{InternalizeL(aThing,aStream);return aStream;}

//
// inlines
//

// move to private source...

inline TBool CPrintPreviewImage::IsFirstPanel(TInt aPageNum) 
	{ return aPageNum==iPrintParams.iFirstPage; }

inline TBool CPrintPreviewImage::IsLastPanel(TInt aPageNum) 
	{ return aPageNum==iPrintParams.iLastPage; }


#endif
