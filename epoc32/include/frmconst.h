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
// FOR INFORMATION ONLY (CONTAINS PANIC NUMBERS, ETC.) - NOT PART OF INTERFACE
// 
//

#ifndef __FRMCONST_H__
#define __FRMCONST_H__

#include <w32std.h>

/** 
Visible versions of control characters.
@internalComponent
*/
const TText KVisibleParagraphBreak = 0x00B6;		// paragraph sign (pilcrow)
const TText KVisibleLineBreak = 0x2193;				// down arrow
const TText KVisibleNonBreakSpace = 0x00B0;			// degree sign
const TText KVisiblePotentialHyphen = 0x00AC;		// not sign
const TText KVisibleNonBreakHyphen = 0x007E;		// spacing tilde
const TText KVisibleSpace = 0x00B7;					// middle dot
const TText KVisibleTab = 0x2192;					// right arrow
const TText KVisiblePicture = 0x25A3;				// white square containing small black square

/**
Control characters to allow or inhibit line breaks.
@internalComponent
*/
const TText KZeroWidthSpace = 0x200B;
const TText KZeroWidthNoBreakSpace = 0xFEFF;

/**
@publishedAll
@released
*/
enum TFormPanic
	{
	/** Not used 
	*/
	EFDummy = 0,				

	// Used in ASSERT_ALWAYS

	// Parameter errors
	/** Document handle NULL has been passed in
	*/
	EFInvalidDocument = 200,	
	/** A NULL layout handle has been passed in 
	*/
	EFInvalidLayout,			
	/** The character edit type was unknown or incompatible with the format changed value 
	*/
	EFBadCharacterEditType,		
	/** The horizontal scroll jump value has been set outside the allowable range (0,9999) 
	*/
	EFInvalidJumpValue,			

	// Document
	/** No or negative document position specified or greater than current document length 
	*/
	EFInvalidDocPos = 300,		

	// Drawing
	/** The function CTextView::SetLineCursorBitmap has not been called even though a line cursor is being used 
	*/
	EFLineCursorBitmapNotSet = 400,	

	// Pagination
	/** No document to paginate 
	*/
	EFDocumentToPaginateNotSet = 500, 
	/** Appending zero or negative characters per page to page list 
	*/
	EFInvalidNumberCharsOnPage,	
	/** Page list should not be empty at this point 
	*/
	EFPageListEmpty,			

	// Printing
	/** The array containing the number of characters per page has not been set or is defective 
	*/
	EFInvalidPageList = 600,	
	/** A page requested that is outside the page list given 
	*/
	EFInvalidPageNumber,		 

	// Used only in ASSERT_DEBUG

	// Errors in internal format information
	/** Format doesn't fill band but is not to end of document 
	*/
	EFNotEnoughFormat = 700,	
	/** A lines says it has height zero 
	*/
	EFZeroHeightLine,			
	/** The selected range flag is on but the selection has zero length 
	*/
	EFSelectedRangeZeroLen,		
	/** The cursor is a document position that is outside the formatted range 
	*/
	EFCursorNotInCurrentFormat,	
	/** GetLineRect pixel that was asked for 
	*/
	EFPixelNotInFormattedLine,	
	/** The complete scroll should have been possible 
	*/
 	EFScrollCurtailed,			

	// Logic error during format process
	/** Should not be calling HandleCharEdit when there is a selection 
	*/
	EFSelectionCannotCharEdit = 800,	
	/** This function should not be called when the format is out of date 
	*/
	EFFormatOutOfDate,			
	/** Background formatting should not be going on 
	*/
	EFBackgroundFormatting,		

	// Scrolling errors
	/** The request for a scroll returned zero as the ammount to scroll by 
	*/
	EFScrollByZero1 = 900,		
	/** A routine that does the scrolling is called with a value of zero or one having wrong sign 
	*/
	EFScrollByZero2,			
	/** Algorithmic or assumption error in the scroll routine 
	*/
	EFScrollError,				
	/** Error when scrolling text down 
	*/
	EFScrollDownError,			
	/** Error when scrolling text up 
	*/
	EFScrollUpError,			
	/** A scrolling routine was expecting a certain type of scroll and got a different one 
	*/
	EFInvalidScrollingType,		

	// Out of memory
	/** Cannot do this when in no memory mode 
	*/
	EFNoMemory = 1000,			
	/** Trying to recover from no_memory when no no_memory condition has occured 
	*/
	EFRecoverNoMemory,			

	// Cursor
	/** The cursor has been moved to a position off the screen 
	*/
	EFCursorOffDisplay = 1100,	
	/** Attempt to access the cursor navigation policy object when its pointer is 0 
	*/
	EFNoCursorPositionPolicy,	
	/** Invalid positioning hint value supplied to API 
	*/
	EFPosHintInvalid,			
	/** Curosr APIs found formatting not available for position supplied. 
	*/
	EFPositionNotFormatted,		
	/** The document position was out of range for the current source document. 
	*/
	EFPositionInvalid,			

	// Drawing
	/** Trying to toggle the highlight on part of the screen when the selection is not visible 
	*/
	EFSelectionNotVisible = 1200, 
	/** Clearing bottom partial line when not needed
	*/
 	EFPartialLineClearError,    
	/** The routine that does the display has been passed a null pointer to a graphics context 
	*/
	EFGcNotSet,					

	//Internal Coding Errors	   
	/** SetViewL has put the text at the wrong vertical height 
	*/
	EFViewNotPositionedCorrectly = 1300, 
	/** The function call should not leave in this situation 
	*/
	EFShouldNotLeave,			
	/** Trying to move cursor using wrong function call 
	*/
	EFIncorrectCursorMovement,	
	/** Should be current picture frame 
	*/
	EFNoPictureFrame,			
	/** A value of a system constant has changed to a value that has broken this code 
	*/
	EFSystemConstantsChanged	
	};

/**
@internalComponent
*/
void FormPanic(TFormPanic aPanic);


enum TCursorMove
/**
This enum holds all the allowed movements of the document cursor by this
cursor positioning framework.
@publishedPartner
@released
*/
	{
	/** No cursor movement 
	*/
	ECursNoMovement,
    /** Single character cursor movement to the left 
    */
    ECursLeft,
    /** Single character cursor movement to the right 
    */
    ECursRight,
    /** Line up cursor movement 
    */
    ECursLineUp,
    /** Line down cursor movement 
    */
    ECursLineDown,
    /** Not used, present for backwards compatibility for page movement 
    */
    ECursReserved1,
    ECursReserved2,
    /** Cursor movement to line start 
    */
    ECursLineBegin,
    /** Cursor movement to line end 
    */
    ECursLineEnd
	};


#endif // __FRMCONST_H__
