/*
* Copyright (c) 2002-2008 Nokia Corporation and/or its subsidiary(-ies).
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
* Description:    In case that Service Consumer (owner of SC instance) needs
*                some special, even properietary interface, it can request
*                an implementation of such interface by calling
*                CSenServiceConnection::InterfaceByUid(UID) and acquire
*                on of the M-class interfaces defined in this file.
*
*/




#ifndef M_SEN_SERVICE_CONNNECTION_INTERFACES_H
#define M_SEN_SERVICE_CONNNECTION_INTERFACES_H

// CONST
// UIDs for the supported, new *service connection interfaces*:
const TUid KSenInterfaceUidAlrServiceConnection      = { 0xE760F699 }; // MSenAlrServiceConnection


// CLASS DECLARATION
/**
 * Callback interface for service consumers
 */
    
class MSenAlrServiceConnection
    {
    public: 
        /**
        * With this method client can indicate that it wants to start using a new preferred 
        * connection as a response to PreferredCarrierAvailable() callback.
        *
        * @param aUserChoice TRUE(Yes) FALSE (No)
        * if UserChoice is TRUE then connection will migrated to new carrier
        * available,         
        * if UserChoice is FALSE connection will not migrate to new carrier        
        */
	    virtual void MigrateToPrefferedCarrierL(TBool &aUserChoice) = 0 ;

        /**
        * With this method client can indicate that it accepts to use a new preferred 
        * connection as a response to NewCarrierActive() callback.
        * 
        * Earlier the client has received MigrateToPrefferedCarrierL()
        * callback. Once it has agreed to migrate through NewCarrierAvailable(),
        * newCarrierActive() callback will be invoked in order
        * to get acceptance from the application.
        *
        * @param aUserChoice TRUE(Yes) FALSE (No)
        * if UserChoice is TRUE then new Carrier will be accepted
        * if UserChoice is FALSE connection will not accept the new carrier        
        */
	    virtual void NewCarrierAcceptedL(TBool &aUserChoice) = 0 ;		
    };    
    
#endif //  M_SEN_SERVICE_CONNNECTION_INTERFACES_H   