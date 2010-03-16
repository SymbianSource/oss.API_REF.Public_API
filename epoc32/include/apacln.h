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


#if !defined(__APACLN_H__)
#define __APACLN_H__

#if !defined(__APPARC_H__)
#include <apparc.h>
#endif


class TApaDocCleanupItem
/** Allows CApaDocument-derived objects to be safely put onto the cleanup 
stack, by calling CApaProcess::DestroyDocument() should a leave or a call 
to CleanupStack::PopAndDestroy() occur.

It is used as follows.
@code
TApaDocCleanupItem cleanup(iEikonEnv->Process(),doc);
CleanupStack::PushL(cleanup);
// some potentially leaving code here ...
CleanupStack::Pop(cleanup);
@endcode
@publishedPartner
@deprecated
*/
	{
public:
	inline TApaDocCleanupItem(CApaProcess* aProcess,CApaDocument* aDoc);
	inline operator TCleanupItem();
private:
	IMPORT_C static void DoCleanup(TAny* aPtr);
public:
	/** The process object that will be used to destroy the document. */
	CApaProcess* iApaProcess;
	/** The document to destroy as part of cleanup. */
	CApaDocument* iApaDoc;
	};


inline TApaDocCleanupItem::TApaDocCleanupItem(CApaProcess* aProcess,CApaDocument* aDoc)
	: iApaProcess(aProcess), iApaDoc(aDoc)
/** Constructs a cleanup item object for the specified document.

@param aProcess A pointer to the process object that will be used to destroy the document.
@param aDoc The document to destroy as part of cleanup. */
	{}

inline TApaDocCleanupItem::operator TCleanupItem()
/** A TCleanupItem cast operator that enables the TApaDocCleanupItem object to be pushed to 
the cleanup stack as a TCleanupItem, so that the document will be properly destroyed 
(by a call to CApaProcess::DestroyDocument()) should a leave or a call to 
CleanupStack::PopAndDestroy() occur. */
	{return TCleanupItem(DoCleanup,this);}

#endif
