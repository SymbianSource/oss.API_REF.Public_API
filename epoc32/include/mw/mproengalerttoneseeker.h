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
* Description:  Abstract interface for find media files suitable to be 
*  				set as an alert tone in Profiles.
*
*/



#ifndef MPROENGALERTTONESEEKER_H
#define MPROENGALERTTONESEEKER_H

//  INCLUDES
#include <e32def.h>

// FORWARD DECLARATIONS
class MProEngAlertToneSeekerExt;
class MProEngAlertToneSeekerObserver;

// CLASS DECLARATION

/**
*  This class can be used to find media files suitable to be set as an alert
*  tone in Profiles.
*
*  @lib ProfileEngine.lib
*  @since Series 60 3.1
*/
class MProEngAlertToneSeeker
    {
    public: // New functions

        /**
        * Asynchronous method that searches all the tone files that can be used
        * as alert tones in Profiles. The resulting list of the tone paths is
        * delivered to the MProEngAlertToneSeekerObserver.
        * This is a very long lasting operation (~minutes), so this shouldn't
        * be performed too often.
        * @since S 60 3.1
        * @param aObserver Reference to the client-implemented observer which
        *        will get the list of tones after the list has been constructed.
        */
        virtual void FetchAlertToneListL(
                MProEngAlertToneSeekerObserver& aObserver ) = 0;

        /**
         * Cancels the asynchronous fetch operation.
         * @since S60 3.1
         */
        virtual void CancelFetch() = 0;

    public:

        /**
        * Destructor.
        */
        virtual ~MProEngAlertToneSeeker() {}

    private: // Extension interface

        /**
        * This member is internal and not intended for use.
        */
        virtual MProEngAlertToneSeekerExt* Extension() { return NULL; }

    };

#endif      // MPROENGALERTTONESEEKER_H

// End of File

