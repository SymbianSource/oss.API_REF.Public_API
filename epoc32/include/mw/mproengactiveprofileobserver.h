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
* Description:  Abstract interface for handling the active profile events.
*
*/



#ifndef MPROENGACTIVEPROFILEOBSERVER_H
#define MPROENGACTIVEPROFILEOBSERVER_H

//  INCLUDES
#include <e32def.h>

// FORWARD DECLARATIONS
class MProEngActiveProfileObserverExt;

// CLASS DECLARATION

/**
* Active profile modification observer interface.
* Implement this interface to get notifications of changes in the active profile
* data.
*
*  @lib ProfileEngine.lib
*  @since Series 60 3.1
*/
class MProEngActiveProfileObserver
    {
    public: // New functions

        /**
        * Abstract method for handling active profile modification event.
        * This method is called when the current active profile has been
        * modified some way. Note, this doesn't get events if a profile is
        * activated, for that implement MProEngProfileActivationObserver.
        * 
        * @since Series 60 3.1
        */
        virtual void HandleActiveProfileModifiedL() = 0;

        /**
         * Error handler for handling the errors in the active profile
         * modification notification process. If HandleActiveProfileModifiedL()
         * leaves, this method is called with the leave code. This method has
         * default empty implementation.
         * @since S60 3.1
         * @param aError the code of the error which occurred during
         *        notification process.
         */
        virtual void HandleActiveProfileNotificationError(
                TInt /* aError */ ) {};

    protected:

        /**
        * Destructor.
        */
        virtual ~MProEngActiveProfileObserver() {}

    private: // Extension interface

        /**
        * This member is internal and not intended for use.
        */
        virtual MProEngActiveProfileObserverExt* Extension() { return NULL; }

    };

#endif      // MPROENGACTIVEPROFILEOBSERVER_H

// End of File

