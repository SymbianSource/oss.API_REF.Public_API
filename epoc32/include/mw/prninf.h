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

#ifndef __PRNINF_H__
#define __PRNINF_H__

#if !defined(__E32STD_H__)
#include <e32std.h>
#endif
#if !defined(__GDI_H__)
#include <gdi.h>
#endif
#if !defined(__FLDBASE_H__)
#include <fldbase.h>
#endif

// Classes defined
//class TPageNumbers;
class CHeaderFooter;
class TPrintParameters;		
class TPageMargins;
class MPrintProcessObserver;	

// classes referenced
class RReadStream;
class RWriteStream;
class CRichText;
class CParaFormatLayer;
class CCharFormatLayer;
class MFieldFileNameInfo;
class MFieldPageNumInfo;
class MFieldNumPagesInfo;
//////////////////


class TPrintParameters
/** Print parameters.

This data is associated with a particular print request, not with the document 
to be printed, so is separate from the print setup information.

An object of this class is passed to CPrintSetup::StartPrintL() and to CPrintSetup::StartPreviewPrintL().

@see CPrintSetup 
@publishedAll 
@released */
	{
public:
	IMPORT_C TPrintParameters(); // sets to 1,0,0
public:
	/** The number of copies to print. */
	TInt iNumCopies;									
	/** The first page to be printed. 
	
	This value should be less than or equal to iLastPage. Zero indicates the first page 
	in the document. */
	TInt iFirstPage;			
	/** The last page to be printed. 
	
	This value should be greater than or equal to iFirstPage. Zero indicates the first 
	page in the document. */
	TInt iLastPage;
	};

class TPageMargins
/** Page margins.

Page margins are accessed via the public iPageMarginsInTwips member of class 
CPrintSetup. A single margin settings object applies throughout a document, 
so that gutter margins are not supported.

If the document contains headers and footers, they are located within the 
top and bottom margins respectively. 

@publishedAll 
@released */
	{
public:
	IMPORT_C void InternalizeL(RReadStream& aStream); 	
	IMPORT_C void ExternalizeL(RWriteStream& aStream)const;
public:
	/** The distance between the top of the header and the top of the page in twips 
	or pixels.
	
	This must be less than the height of the top margin to ensure that the header 
	is visible. */
	TInt iHeaderOffset;
	/** The distance between the top of the footer and the top of the bottom margin 
	in twips or pixels. 
	
	This must be less than the height of the bottom margin to ensure that the 
	footer is visible. */
	TInt iFooterOffset;
	/** The widths of each of the four margins in twips or pixels.
	
	@see TMargins */
	TMargins iMargins;
	};

class CHeaderFooter : public CBase, private MTextFieldFactory
/** A document header or footer.

The header is located in the top page margin and the footer in the 
bottom page margin. No more than one header or footer can exist in a document.

CHeaderFooter derives from MTextFieldFactory. This allows the insertion of 
various fields, including page number, current date or time and filename.

Rich text manipulation and formatting functions can be accessed through 
the rich text object which is owned by the header/footer.

The header and footer are retrieved using the CPrintSetup::Header() and Footer() 
functions and they are stored and restored together with the rest of the print 
setup information.

@publishedAll 
@released */
	{
public:
	IMPORT_C static CHeaderFooter* NewL();
	IMPORT_C virtual ~CHeaderFooter();
	//
	IMPORT_C void CreateTextL();
	IMPORT_C void SetFirstPageToPrintTo(TInt aPageNum); // allows the first few pages of a doc not to have a header on them
	inline TInt FirstPageToPrintTo()const; // relative to the first page being numbered 0
	//
	// persistence
	IMPORT_C TStreamId StoreL(CStreamStore& aStore)const;
	IMPORT_C void RestoreL(const CStreamStore& aStore,TStreamId aStreamId,MPictureFactory* aFactory);
	IMPORT_C void StoreComponentsL(CStreamStore& aStore,CStoreMap& aMap)const;
	IMPORT_C void RestoreComponentsL(const CStreamStore& aStore,MPictureFactory* aFactory);
	IMPORT_C void ExternalizeL(RWriteStream& aStream) const;
	IMPORT_C void InternalizeL(RReadStream& aStream);
	//
	// text bits
	IMPORT_C CRichText* Text()const;
	IMPORT_C CParaFormatLayer* ParaFormat()const;
	IMPORT_C CCharFormatLayer* CharFormat()const;
	IMPORT_C void SetText(CRichText* aText); // takes ownership
	IMPORT_C void SetParaFormat(CParaFormatLayer* aParaFormat); // takes ownership
	IMPORT_C void SetCharFormat(CCharFormatLayer* aCharFormat); // takes ownership
	//
	// field bits
	IMPORT_C void SetFileNameInfo(const MFieldFileNameInfo& aFileNameInfo); // call if you want headers/footers to support filename fields
	IMPORT_C void SetNumPagesInfo(const MFieldNumPagesInfo& aNumPagesInfo); // call if you want headers/footers to support "total number of pages" fields
	inline MFieldFileNameInfo* FileNameFieldInfo()const;
	inline MFieldNumPagesInfo* NumPagesFieldInfo()const;
	//
	void SetPageNumInfo(const MFieldPageNumInfo& aPageNumInfo); // called by CPrintSetup
private:
	CHeaderFooter();
	void CreateFormatLayersL();
	// from MTextFieldFactory
	CTextField* NewFieldL(TUid aFieldType);
private:
	TInt iFirstPageToPrintTo; // relative to the first page being numbered 0
	MFieldFileNameInfo* iFileNameInfo;
	MFieldPageNumInfo* iPageNumInfo;
	MFieldNumPagesInfo* iNumPagesInfo;
	CRichText* iText; // RichText Doc Handle
	CParaFormatLayer* iParaLayer;
	CCharFormatLayer* iCharLayer;
private:
	enum { ETextExists = 0x0001 };
	};

class MPrintProcessObserver
/** Print progress and status notification interface class.

The notification functions are called before, during and after a print or 
print preview operation, to give notification of its progress.

The print process observer will often be the GUI's standard print progress 
or print preview dialog.

An object of a class which implements this interface may be passed as a parameter 
to CPrintSetup::StartPrintL(), or to CPrintSetup::StartPreviewPrintL(). 

@publishedAll 
@released */
	{
public:
	/** Notifies that a print or print preview operation is about to begin.
	
	It may be used to display information about the document to be printed. It 
	is called once, immediately before printing or print previewing begins.
	
	When subclassing, add variables to store initialisation information as required.
	
	@param aPrintParams The parameters for the print job. */
	virtual void NotifyPrintStarted(TPrintParameters aPrintParams)=0;
	/** Notifies that a band is about to be printed.
	
	It may be used to display print progress information, including the current 
	page number. It is called immediately before each band is printed.
	
	@param aPercentageOfPagePrinted The percentage of the page that has been printed.
	@param aCurrentPageNum The number of the page currently being printed.
	@param aCurrentCopyNum The number of the copy currently being printed (if multiple 
	copies are being printed). */
	virtual void NotifyBandPrinted(TInt aPercentageOfPagePrinted, TInt aCurrentPageNum, TInt aCurrentCopyNum)=0;
	/** Notifies that the print or print preview operation has completed.
	
	It may be used to display information about how the operation completed, for 
	example any errors that occurred. It is called once, immediately after the 
	print job terminates.
	
	@param anErrorCode KErrNone if the print job completed successfully, otherwise 
	another of the system-wide error codes. */
	virtual void NotifyPrintEnded(TInt anErrorCode)=0;
	//
	};


//
// inlines
//

inline TInt CHeaderFooter::FirstPageToPrintTo()const
/** Gets the first page on which the header or footer is to be printed.

Page numbering begins at zero.

@return The number of the first page on which the header or footer is to be 
printed. */
	{ return iFirstPageToPrintTo; }

inline MFieldFileNameInfo* CHeaderFooter::FileNameFieldInfo()const
/** Gets the object which implements the MFieldFileNameInfo interface, as set by 
SetFileNameInfo().

@return The object which implements the MFieldFileNameInfo interface. */
	{ return iFileNameInfo; }

inline MFieldNumPagesInfo* CHeaderFooter::NumPagesFieldInfo()const
/** Gets the object which implements the MFieldNumPagesInfo interface, as set by 
SetNumPagesInfo().

@return The object which implements the MFieldNumPagesInfo interface. */
	{ return iNumPagesInfo; }

#endif
