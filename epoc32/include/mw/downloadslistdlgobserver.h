/*
* Copyright (c) 2002-2004 Nokia Corporation and/or its subsidiary(-ies).
* All rights reserved.
* This component and the accompanying materials are made available
* under the terms of the License "Eclipse Public License v1.0"
* which accompanies this distribution, and is available
* at the URL "http://www.eclipse.org/legal/epl-v10.html".
*
* Initial Contributors:
* Nokia Corporation - initial contribution.
*
* Contributors:
*
* Description:  Dialog observer M class
*
*/



#ifndef DOWNLOADSLISTDLGOBSERVER_H
#define DOWNLOADSLISTDLGOBSERVER_H

//  INCLUDES
#include <e32def.h>
#include <coedef.h>
#include <w32std.h>

// FORWARD DECLARATIONS
class CDownloadsListDlg;
class CEikMenuPane;

// CLASS DECLARATION

/**
*  Observer interface of CDownloadsListDlg.
*
*  @lib Download Manager UI Lib
*  @since Series 60 2.8
*/
NONSHARABLE_CLASS( MDownloadsListDlgObserver )
    {
    public:

        /**
        * Called for layouting the dialog before executing it.
        */
        virtual void PreLayoutDynInitL( CDownloadsListDlg& aDialog ) = 0;

        /**
        * Called for processing not dialog specific commands.
        */
        virtual void ProcessCommandL( CDownloadsListDlg& aDialog, TInt aCommandId ) = 0;

        /**
        * Called for initializing Options menu.
        */
        virtual void DynInitMenuPaneL( CDownloadsListDlg& aDialog, TInt aResourceId, CEikMenuPane* aMenuPane ) = 0;

        /**
        * Key events first forwarded to the observer.
        */
        virtual TKeyResponse OfferKeyEventL( CDownloadsListDlg& aDialog, const TKeyEvent& aKeyEvent, TEventCode aType ) = 0;

    };

#endif /* DOWNLOADSLISTDLGOBSERVER_H */

