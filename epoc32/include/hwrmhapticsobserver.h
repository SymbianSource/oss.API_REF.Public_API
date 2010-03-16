/*
* Copyright (c) 2008 Nokia Corporation and/or its subsidiary(-ies). 
* All rights reserved.
* This component and the accompanying materials are made available
* under the terms of the License "Symbian Foundation License v1.0" to Symbian Foundation members and "Symbian Foundation End User License Agreement v1.0" to non-members
* which accompanies this distribution, and is available
* at the URL "http://www.symbianfoundation.org/legal/licencesv10.html".
*
* Initial Contributors:
* Nokia Corporation - initial contribution.
*
* Contributors:
*
* Description:  This file contains the header of the 
*                MHWRMHapticsObserver class.
*
*/


#ifndef M_HWRMHAPTICSOBSERVER_H
#define M_HWRMHAPTICSOBSERVER_H

#include <e32base.h>

/**
* MHWRMHapticsObserver observer class.
*
* A client should derive from this abstract class to receive haptics 
* status notifications and notification of effect completion. 
*
* @since S60 5.1
*/
class MHWRMHapticsObserver
    {
public:
    
    /**
    * Haptics status.
    */
    enum THWRMHapticsStatus 
        {
        /**
         * Haptics is available for the observing client.
         */
        EHWRMHapticsStatusAvailable = 0,

        /**
         * Haptics is reserved for another client. The client making 
         * the active reservation does not receive this notification, but
         * a success code for the reservation command.
         */
        EHWRMHapticsStatusReserved,

        /**
         * Haptics has been suspended for this client. This occurs, when
         * another client with higher priority makes reservation for 
         * haptics, or when this client is making reservation and haptics 
         * has already been reserved for a client with higher priority.
         *
         * In suspended state, haptics effects are not played for the
         * suspended client, but other commands are executed as normal.
         */
        EHWRMHapticsStatusSuspended
        };
        
    /** 
    * Called when the device's haptics feature state changes
    *
    * @param aStatus Indicates haptics status.
    *
    * @since S60 5.1
    *
    * @see CHWRMHaptics::THWRMHapticsStatus
    */
    virtual void HapticsStatusChangedL( THWRMHapticsStatus aStatus ) = 0;
        
    /** 
    * Called when effect has completed playing. 
    * 
    * Method reserved for future use.
    *
    * @param aError Reason of completion.
    * @param aEffectHandle The associated effectHandle to the effect.
    *
    * @since S60 5.1
    */
    virtual void EffectCompletedL( TInt aError, TInt aEffectHandle ) = 0;
    };

#endif // M_HWRMHAPTICSOBSERVER_H
