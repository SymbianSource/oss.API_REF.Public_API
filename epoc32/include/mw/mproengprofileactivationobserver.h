/*
* Copyright (c) 2002-2004 Nokia Corporation and/or its subsidiary(-ies).
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
* Description: Profile activation observer interface.
*
*/



#ifndef MPROENGPROFILEACTIVATIONOBSERVER_H
#define MPROENGPROFILEACTIVATIONOBSERVER_H

//  INCLUDES
#include <e32def.h>

// FORWARD DECLARATIONS
class MProEngProfileActivationObserverExt;

// CLASS DECLARATION

/**
* Profile activation observer interface.
* Implement this interface to get notifications when the current active profile
* changes.
*
*  @lib ProfileEngine.lib
*  @since Series 60 3.1
*/
class MProEngProfileActivationObserver
    {
    public: // New functions

        /**
        * Abstract method for handling profile activation event. This method is
        * called always when a profile is activated, even if the current active
        * profile is re-activated.
        * @since S60 3.1
        * @param aProfileId The ID of the new active profile.
        */
        virtual void HandleProfileActivatedL( TInt aProfileId ) = 0;
                                         
        /**
         * Error handler for handling the errors in the profile activation
         * notification process. If HandleProfileActivatedL() leaves, this
         * method is called with the leave code. This method has default empty
         * implementation.
         * @since S60 3.1
         * @param aError the code of the error which occurred during
         *        notification process.
         */
        virtual void HandleProfileActivationNotificationError(
                TInt /* aError */ ) {};


    protected:

        /**
        * Destructor.
        */
        virtual ~MProEngProfileActivationObserver() {}

    private: // Extension interface

        /**
        * This member is internal and not intended for use.
        */
        virtual MProEngProfileActivationObserverExt* Extension() {return NULL;}

    };

#endif      // MPROENGPROFILEACTIVATIONOBSERVER_H

// End of File

