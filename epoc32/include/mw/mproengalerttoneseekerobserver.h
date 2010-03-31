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
* Description: Interface to get the list of the alert tones from MProEngAlertToneSeeker.
*
*/



#ifndef MPROENGALERTTONESEEKEROBSERVER_H
#define MPROENGALERTTONESEEKEROBSERVER_H

//  INCLUDES
#include <e32def.h>

// FORWARD DECLARATIONS
class MProEngAlertToneSeekerObserverExt;

// CLASS DECLARATION

/**
*  Interface to get the list of the alert tones from MProEngAlertToneSeeker.
*  @lib ProfileEngine.lib
*  @since Series 60 3.1
*/
class MProEngAlertToneSeekerObserver
    {
    public: // New functions

        /**
        * Abstract method to get notification when the MProEngAlertToneSeeker
        * has completed the list of alert tones.
        * @since Series 60 3.1
        * @param aToneList Array containing the path names of the tones found.
        * The ownership of the array is transferred to the observer.
        */
        virtual void HandleAlertToneListCompletedL( MDesCArray* aToneList ) = 0;

        /**
        * Abstract method for handling errors in alert tone list creation
        * process. Also if HandleAlertToneListCompletedL() method leaves, the
        * leave code will be passed to this method.
        * @since Series 60 3.1
        * @param aError System wide error code.
        */
        virtual void HandleError( TInt aError ) = 0;

    protected:

        /**
        * Destructor.
        */
        virtual ~MProEngAlertToneSeekerObserver() {}

    private: // Extension interface

        /**
        * This member is internal and not intended for use.
        */
        virtual MProEngAlertToneSeekerObserverExt* Extension() { return NULL; }

    };

#endif      // MPROENGALERTTONESEEKEROBSERVER_H

// End of File

