/*
* Copyright (c) 2006 Nokia Corporation and/or its subsidiary(-ies). 
* All rights reserved.
* This component and the accompanying materials are made available
* under the terms of "Eclipse Public License v1.0"
* which accompanies this distribution, and is available
* at the URL "http://www.eclipse.org/legal/epl-v10.html".
*
* Initial Contributors:
* Nokia Corporation - initial contribution.
*
* Contributors:
*
* Description:  Implementation of settings UI
*
*/

#ifndef C_CMSETTINGSUI_H
#define C_CMSETTINGSUI_H

#include <e32def.h>
#include <e32base.h>

class CCmSettingsUiImpl;

/**
 *  Implementation of Setting UI
 *
 *  @lib cmmanager.lib
 *  @since S60 v3.2
 */
NONSHARABLE_CLASS(CCmSettingsUi) : public CBase
    {
    public:

        enum TResult
                {
                EBack,
                EExit
                };

        /** Epoc constructor */
        IMPORT_C static CCmSettingsUi* NewL();

        /** Destructor */
        virtual ~CCmSettingsUi();

    //=========================================================================    
    // UI API
    //
    public:

        /**
        * Launches the Settings UI 
        * for handling Destinations and Connection Methods
        * @since 3.2
        * @return TResult - the softkey the user exited with
        */
        IMPORT_C TResult RunSettingsL();
        
        /**
        * Launches a dialog with a list of Destination
        * @since 3.2
        * @param  aDestinationId ID of the selected Destination
        * @return TBool
        */
        IMPORT_C TBool SelectDestinationDlgL( TUint32& aDestinationId );

    private:

        /** First stage constructor */
        CCmSettingsUi();

        /** Epoc constructor */
        void ConstructL();

    private: // data

        CCmSettingsUiImpl* iImpl;
    };

#endif // C_CMSETTINGSUI_H
