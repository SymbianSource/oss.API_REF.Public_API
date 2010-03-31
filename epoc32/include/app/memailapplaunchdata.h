/*
* Copyright (c) 2009 - 2009 Nokia Corporation and/or its subsidiary(-ies).
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
* Description:  Helper classes for interface.
*
*/

#ifndef MEMAILAPPLAUNCHDATA_H
#define MEMAILAPPLAUNCHDATA_H

#include <e32cmn.h>

namespace EmailInterface {

/**
 * Container for launch parameters
 * When user touches the widget, an application launch is initiated with
 * these parameters
 * (see MMailboxData::LaunchParameters() )
 */
class MEmailLaunchParameters
    {
public:
    /**
     * Application UID identifying the application to be launched
     */
    virtual TUid ApplicationUid() const = 0;

    /**
     * ViewId within the application
     */
    virtual TUid ViewId() const = 0;

    /**
     * TUid that will be delivered to the launched application
     */
    virtual TUid CustomMessageId() const = 0;

    /**
     * Data that will be delivered to the launched application
     */
    virtual const TDesC8& CustomMessage() const = 0;
    };

} // namespace

#endif // MEMAILAPPLAUNCHDATA_H
