/*
* Copyright (c) 2007-2009 Nokia Corporation and/or its subsidiary(-ies).
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
* Description:
* Name          : sipprofilealrobserver.h
* Part of       : SIP / SIP Profile Agent
* Version       : SIP/6.0 
*
*/



#ifndef MSIPPROFILEALROBSERVER_H
#define MSIPPROFILEALROBSERVER_H

// INCLUDES
#include <e32std.h>

// CLASS DECLARATION
/**
* @publishedAll
* @released
*
* Callback to receive notifications about ALR (Application Level Roaming) 
* related events and errors.
*/
class MSipProfileAlrObserver
    {
    public:
    
        /** SIP Profile ALR events */
        enum TEvent
            {
             /** 
            * A new IAP became available.
            * When receiving this event the client must call 
            * CSipProfileAlrController::AllowMigrationL or DisallowMigrationL.
            */           
            EIapAvailable = 0,
            /** 
            * All the clients have allowed the migration to the new IAP and
            * the migration to the new IAP for the SIP profile has started. 
            */
            EMigrationStarted,
            /** 
            * Migration to a new IAP for a SIP profile has been completed and
            * the related SIP profile has been registered via the new IAP.
            */
            EMigrationCompleted
            };
                                   
        /**
        * ALR related event occurred.
        * @param aEvent the event that occurred
        * @param aProfileId identifies the SIP profile related to the event
        * @param aSnapId the SNAP related to the event
        * @param aIapId the IAP related to the event
        */
        virtual void AlrEvent( TEvent aEvent,
                               TUint32 aProfileId,
                               TUint32 aSnapId,
                               TUint32 aIapId ) = 0;
                               
        /**
        * ALR related error occurred.
        * @param aError the error that occurred
        * @param aProfileId identifies the SIP profile related to the error
        * @param aSnapId the SNAP related to the error
        * @param aIapId the IAP related to the error
        */
        virtual void AlrError( TInt aError,
                               TUint32 aProfileId,
                               TUint32 aSnapId,
                               TUint32 aIapId ) = 0;                                                                  
    };

#endif // MSIPPROFILEALROBSERVER_H
