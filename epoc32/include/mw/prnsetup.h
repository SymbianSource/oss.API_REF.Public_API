// Copyright (c) 1997-2009 Nokia Corporation and/or its subsidiary(-ies).
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

#ifndef __PRNSETUP_H__
#define __PRNSETUP_H__

#if !defined(__E32STD_H__)
#include <e32std.h>
#endif
#if !defined(__E32BASE_H__)
#include <e32base.h>
#endif
#if !defined(__FLDBLTIN_H__)
#include <fldbltin.h>
#endif
#if !defined(__PRNINF_H__)
#include <prninf.h>
#endif

#ifndef SYMBIAN_ENABLE_MIXED_HEADERS
#include <printinguisupport/prnpath.h>
#endif

/** 
@publishedAll 
@released */
const TInt KErrMorePages=4747; // Leave with this error code to print extra pages in PrintBandL

// Classes defined //
class CPrintSetup;
//

// Forward Reference
class CPreviewProcess;
class CPrintProcess;
class CPdrModelList;
class CPdrDevice;
class CHeaderFooter;
class TPageSpec;
class RReadStream;
class RWriteStream;
class MPageRegionPrinter;
class RFs;
class CPrinterDriver;
class CPrinterDriverUI;
//

class CPrintSetup : public CBase, private MFieldPageNumInfo
/** Print setup information.

This class stores the information needed to set up, start and stop a print 
job. This includes the target printer device, the page margins and 
the header and footer. The page specification, (page orientation and page 
dimensions) can be set via the printer device.

Print setup information is associated with a document and is stored as part 
of the persistent form of the document. Print parameters on the other hand, 
(class TPrintParameters) are associated with a particular print request, 
not with the document itself, so are not part of the print setup information. 

@publishedAll
@released */
	{
public:
	IMPORT_C static CPrintSetup* NewL();
	IMPORT_C virtual ~CPrintSetup();
	//
	// printer model selection/control functions
	IMPORT_C void AddPrinterDriverDirL(const TDesC& aDriverDir);
	IMPORT_C CPrinterModelList* ModelNameListL(RFs& aFs);
	IMPORT_C void FreeModelList();
	IMPORT_C void CreatePrinterDeviceL(TInt aModelIndex); // requires ModelList to exist
	IMPORT_C void CreatePrinterDeviceL(TUid aModelUid,RFs& aFs);
	IMPORT_C CPrinterDevice* PrinterDevice()const;
	IMPORT_C CPrinterDriverUI* CreatePrinterDriverUIL(); // ownership is transfered to the caller
	//
	// print functions
	IMPORT_C void EndPrint();
	IMPORT_C TInt StartPrintL(const TPrintParameters& aPrintParams,MPageRegionPrinter& aBodyPrinter,
				CPrinterPort* aPort,MPrintProcessObserver* anObserver);
	IMPORT_C TInt StartPreviewPrintL(const TPrintParameters& aPrintParams,MPageRegionPrinter& aBodyPrinter,
				MPrintProcessObserver* anObserver,CGraphicsDevice& aPreviewDev,const TRect& aHeaderRectInPixels,
				const TRect& aFooterRectInPixels,TInt aNumBands);
	//
	// accessors
	inline CHeaderFooter* Header()const;
	inline CHeaderFooter* Footer()const;
	//
	// persistence
	IMPORT_C TStreamId StoreL(CStreamStore& aStore)const;
	IMPORT_C void RestoreL(const CStreamStore& aStore,TStreamId aStreamId,const MFieldFileNameInfo* aFileNameInfo=NULL,const MFieldNumPagesInfo* aNumPagesInfo=NULL,MPictureFactory* aFactory=NULL);
	IMPORT_C void StoreComponentsL(CStreamStore& aStore,CStoreMap& aMap)const;
	IMPORT_C void RestoreComponentsL(const CStreamStore& aStore,const MFieldFileNameInfo* aFileNameInfo=NULL,const MFieldNumPagesInfo* aNumPagesInfo=NULL,MPictureFactory* aFactory=NULL);
	IMPORT_C void ExternalizeL(RWriteStream& aStream) const;
	IMPORT_C void InternalizeL(RReadStream& aStream);
	//
private:
	CPrintSetup();
	void ConstructL();
	void DoStartPrintL(const TPrintParameters& aPrintParams,MPageRegionPrinter& aBodyPrinter,MPrintProcessObserver* aObserver,CPrinterPort* aPort);
	void InitializePrintingL(CGraphicsDevice* aPrinterDev,const TPrintParameters& aPrintParams,MPrintProcessObserver* aObserver);
	void InitializePrintingL(const TPrintParameters& aPrintParams,MPrintProcessObserver* aObserver,
									 const TRect& aHeaderRectInPixels,const TRect& aFooterRectInPixels);
	// from MFieldPageNumInfo
	TInt UpdateFieldPageNum()const;
public:
	// Info regarding print setup etc.
	/** The header and footer offset and the width of the four margins. 
	
	All measurements are in twips.
	
	@see TPageMargins */
	TPageMargins iPageMarginsInTwips;
	/** The number of the first page in the document.
	
	This value is used for printing or displaying page numbering. Note that all 
	other page numbering is zero indexed, to preserve independence from user-defined 
	page numbering. */
	TInt iNumOfFirstPage; // value to start page numbering at
private:
	enum {
		ENumberFirstPage = 0x0001,
		};
private:
	CHeaderFooter* iHeader;
	CHeaderFooter* iFooter;
	CPrinterDriver* iPrinterDriver; // the target printer driver
	CPreviewProcess* iPrintProcess;
	CPdrModelList* iModelList;
	MPrintProcessObserver* iPrintObserver;
	TPrintParameters iPrintParams; // not persisted
	CArrayFixSeg<TFileName>* iDriverDirList;
	};


//
// inlines
//

inline CHeaderFooter* CPrintSetup::Header()const
/** Gets the header.

The CPrintSetup object owns the header and footer. CPrintSetup implements 
the MFieldPageNumInfo interface, which allows page numbering to be easily 
added to fields.

@return The header. */
	{ return iHeader; }

inline CHeaderFooter* CPrintSetup::Footer()const
/** Gets the footer.

@return The footer. */
	{ return iFooter; }




#endif
