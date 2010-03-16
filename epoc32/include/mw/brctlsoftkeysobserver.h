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
* Description:  Handle softkeys updates
*
*/


#ifndef BRCTLSOFTKEYSOBSERVER_H
#define BRCTLSOFTKEYSOBSERVER_H

//  INCLUDES
#include <e32std.h>
#include <e32base.h>

/**
* Identifies which softkey is to be used
*/
enum TBrCtlKeySoftkey
    {
    EKeyRight, ///< Use the right softkey
    EKeyLeft   ///< Use the left softkey
    };

enum TBrCtlSoftkeyChangeReason
    {
    EChangeReasonElementType,
    EChangeReasonLoad,
    EChangeReasonIdle
    };

/**
* The MBrCtlSoftkeysObserver class handles requests to change the softkeys. 
*
* Usage:
*
* @code
*  #include <BrCtlSoftkeysObserver.h>
*
*  
* @see S60 Platform: Browser Control API Developer's Guide Version 2.0
* @lib BrowserEngine.lib
* @file BrCtlSoftkeysObserver.h
* @endcode     *
*/
class MBrCtlSoftkeysObserver
    {
    public: // New functions
        
        /**
        * Requests the host application to change a softkey. 
        * The host application may or may not change the softkey.
        * @since 2.8
        * @param aKeySoftkey Determines whether to update the left softkey or the right softkey.
        * Values:
        * EKeyRight to update the right softkey
        * EKeyLeft to update the left softkey
        * @param aLabel The label associated with the softkey update
        * @param aCommandId The command to use if the softkey is selected by the user
        * @param aBrCtlSoftkeyChangeReason Reason for the softkey change 
        * Value: EChangeReasonIdle (The other values are reserved for future use.)
        * @return void
        */
        virtual void UpdateSoftkeyL(TBrCtlKeySoftkey aKeySoftkey,
                                    const TDesC& aLabel,
                                    TUint32 aCommandId,
                                    TBrCtlSoftkeyChangeReason aBrCtlSoftkeyChangeReason) = 0;
    };

#endif      // BRCTLSOFTKEYSOBSERVER_H   
            
// End of File
