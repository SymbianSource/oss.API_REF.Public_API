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

#ifndef __EIKAMNT_H__
#define __EIKAMNT_H__

#include <e32base.h>

class CGulIcon;
class MEikAutoMenuObserver;

/** A menu title that will be added to a standard resource-constructed menu bar. 

If added to the CEikAutoMenuTitleArray stored by CEikonEnv during standard 
application start up, the menu pane specified will appear in all applications. 
The menu observer passed in is notified of any events on such menu panes in 
preference to the usual observer (C<MyApp>AppUi). 

@publishedAll 
@released */
NONSHARABLE_CLASS(CEikAutoMenuTitle) : public CBase
	{
public:
	/** Specifies the position of a menu title in a menu. 

	If an array of menu titles holds more than one menu title that is specified 
	for the start or end of a menu, the menu titles are placed in the same order 
	as that in which they appear in the array. This means the first menu title 
	specified with EStart in an array will be the first on a menu bar and the last 
	EEnd will be the last on a menu bar. */
	enum TTitlePos
		{
		/** The menu title is placed first in a menu. */
		EStart,
		/** The menu title is placed last in a menu. */
		EEnd
		};
	enum { ENominalTextLength=40 };
public:
	IMPORT_C static CEikAutoMenuTitle* NewLC(TTitlePos aPos, const TDesC& aText, MEikAutoMenuObserver& aMenuObserver,
										TInt aMenuPaneResourceId = 0, CGulIcon* aIcon = NULL);
	IMPORT_C ~CEikAutoMenuTitle();
private:
	CEikAutoMenuTitle(TTitlePos aPos, const TDesC& aText, MEikAutoMenuObserver& aMenuObserver,
						TInt aMenuPaneResourceId, CGulIcon* aIcon);
public:
	TTitlePos iPos;
	TBuf<ENominalTextLength> iText;
	MEikAutoMenuObserver& iMenuObserver;
	TInt iMenuPaneResourceId;
	CGulIcon* iIcon;
	};


/** Creates a standard array of CEikAutoMenuTitle objects. 

@publishedPartner 
@released */
NONSHARABLE_CLASS(CEikAutoMenuTitleArray) : public CArrayPtrFlat<CEikAutoMenuTitle>
// If more than one title is specified for the start or end, they will be placed in the same order they appear
// in the array (so the first EStart in the array will be the first on a menu bar also but the last EEnd will
// be the last).
	{
public:
	CEikAutoMenuTitleArray();
	~CEikAutoMenuTitleArray();
	};

#endif	// __EIKAMNT_H__
