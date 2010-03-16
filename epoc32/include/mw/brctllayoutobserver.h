/*
* Copyright (c) 2006 Nokia Corporation and/or its subsidiary(-ies).
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
* Description:  Handle scrollbar and tab events
*
*/


#ifndef BRCTLLAYOUTOBSERVER_H
#define BRCTLLAYOUTOBSERVER_H

//  INCLUDES
#include <e32std.h>
#include <e32base.h>


/**
* Defines whether a page is to be read from left-to-right or from right-to-left.
*/
enum TBrCtlLayout
  {
  EOriginTopLeft, ///< Page is to be read from left-to-right
  EOriginTopRight ///< Page is to be read from right-to-left
  };

enum TBrCtlTabDirection
    {
    ETabLeft,
    ETabRight,
    ETabUp,
    ETabDown
    };

/**
* The MBrCtlLayoutObserver class receives 
* scrolling events when the host application draws the scrollbar. 
*
* Usage:
*
* @code
*  #include <BrCtlLayoutObserver.h>
*
*  
* @see S60 Platform: Browser Control API Developer's Guide Version 2.0
* @lib BrowserEngine.lib
* @file BrCtlLayoutObserver.h
* @endcode     *
*/
class MBrCtlLayoutObserver
    {
    public: // New functions
        
        /**
        * Update the position of vertical scrollbar.
        * @since 2.8
        * @param aDocumentHeight The total height of the markup page
        * @param aDisplayHeight The height of the display
        * @param aDisplayPosY The current Y position
        * @return void
        */
        virtual void UpdateBrowserVScrollBarL(TInt aDocumentHeight, 
                                              TInt aDisplayHeight,
                                              TInt aDisplayPosY ) = 0;

        /**
        * Update the position of horizontal scrollbar.
        * @since 2.8
        * @param aDocumentWidth The total width of the markup page
        * @param aDisplayWidth The width of the display
        * @param aDisplayPosX The current X position
        * @return void
        */
        virtual void UpdateBrowserHScrollBarL(TInt aDocumentWidth, 
                                              TInt aDisplayWidth,
                                              TInt aDisplayPosX ) = 0;

        /**
        * Inform the layout of the page: right to left or left to right. 
        * Useful when the application draws the scrollbar itself.
        * @since 2.8
        * @param aNewLayout RTL (right to left) or LTR (left to right)
        * @return void
        * @attention This function is useful when the host application draws the scrollbar.
        * In RTL pages, the scroll bar should be on the left side. 
        */
        virtual void NotifyLayoutChange( TBrCtlLayout aNewLayout ) = 0;
        
        /**
        * Update the title of the page in history view
        * @since 3.0
        * @param aTitle Title of the page
        * @return void
        */
        virtual void UpdateTitleL( const TDesC& aTitle ) = 0;        
    };

#endif      // BRCTLLAYOUTOBSERVER_H
            
// End of File
