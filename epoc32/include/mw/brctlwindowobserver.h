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
* Description:  Handle multiple windows events such as open/close/etc
*
*/


#ifndef BRCTLWINDOWOBSERVER_H
#define BRCTLWINDOWOBSERVER_H

//  INCLUDES
#include <e32std.h>
#include <e32base.h>
#include <brctldefs.h>

// CONSTANTS

// MACROS

// DATA TYPES
enum TBrCtlWindowCommand
    {
    EFocusWindow,
    EUnfocusWindow,
    EShowWindow,
    ECloseWindow
    };

// FUNCTION PROTOTYPES

// FORWARD DECLARATIONS
class CBrCtlInterface;

/**
* The MBrCtlWindowObserver class handles window events such open/close/etc
*
* Usage:
*
* @code
*  #include <brctlwindowobserver.h>
*
* @see S60 Platform: Browser Control API Developer's Guide Version 2.0
* @lib BrowserEngine.lib
* @since 3.0
* @file brctlwindowobserver.h
* @endcode     *
*/
class MBrCtlWindowObserver
    {
    public: // New functions
        /**
        * Request the host applicaion to open the URL in a new window
        * @since 3.0
        * @param aUrl The Url of the request to be done in the new window
        * @param aTargetName The name of the new window
        * @param aUserInitiated ETrue if the new window is initiated by a user event (click)
        * @param aMethod The method to be used for fetching the supplied url
        * @param aContentType If the method is POST, this is the content type of the data to be posted 
        * @param aPostData If the method is POST, this is the data to be posted 
        * @param aBoundary The boundary used if the content is multipart/form-data
        * @param aReserved For future use
        * @return Return Value is the new browser control associated with the new window
        */
        virtual CBrCtlInterface* OpenWindowL(TDesC& aUrl, TDesC* aTargetName, TBool aUserInitiated, 
             TAny* aReserved) = 0;

        /**
        * Find a window by target name
        * @since 3.0
        * @param aTargetName name of the window to find
        * @return Return Value is the browser control associated with the window name
        */
        virtual CBrCtlInterface* FindWindowL( const TDesC& aTargetName ) const = 0;             

        /**
        * Handle window events such as close/focus etc
        * @since 3.0
        * @param aTargetName name of the window to send the event to
        * @param aCommand Command to pass to the window
        * @return void
        */
        virtual void HandleWindowCommandL( const TDesC& aTargetName, TBrCtlWindowCommand aCommand ) = 0;
    };

#endif      // BRCTLWINDOWOBSERVER_H
            
// End of File
