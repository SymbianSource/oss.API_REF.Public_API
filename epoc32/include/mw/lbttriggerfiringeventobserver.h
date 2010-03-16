/*
* Copyright (c) 2006 Nokia Corporation and/or its subsidiary(-ies).
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
* Description:  location triggering server client library
*
*/



#ifndef LBTTRIGGERFIRINGEVENTOBSERVER_H
#define LBTTRIGGERFIRINGEVENTOBSERVER_H


#include <lbtcommon.h>

/**
 * The class defines the interface for receiving 
 * trigger firing event. 
 *
 * This interface is used together with class 
 * CLbtTriggerFiringEventNotifier.
 *
 * @lib lbt.lib
 *
 * @since S60 5.1
 */
class MLbtTriggerFiringEventObserver
    {
public:
    /**
     * This function is called when a trigger(either a session
     * trigger or a start-up trigger) is fired.
     *
     * Note, the leave of this function is trapped and 
     * ignored in class CLbtTriggerFiringEventNotifier. 
     * 
     * @param[out] aFireInfo Contains the fired  
     * trigger's firing information.
     */
    virtual void TriggerFiredL(
        const TLbtTriggerFireInfo& aFireInfo
        ) = 0;
    };

#endif //LBTTRIGGERFIRINGEVENTOBSERVER_H
