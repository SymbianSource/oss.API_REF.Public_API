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

#ifndef MEMAILMAILBOXDATA_H
#define MEMAILMAILBOXDATA_H

#include <memailmessagedata.h>

namespace EmailInterface {

class MEmailLaunchParameters;

/**
 *  Container interface for mailbox related info
 */
class MMailboxData
    {
public:
    /**
     * Accessor for mailbox id
     * @return mailbox identifier
     */
    virtual TUint MailboxId() const = 0;

    /**
     * Accessor for mailbox name
     * @return mailbox name
     */
    virtual const TDesC& Name() const = 0;

    /**
     * Accessor for mailbox branding icon specifier
     * @return path descriptor to branding icon
     *     e.g. "mif(z:\\resource\\apps\\myemailplugin.mif N1 N2)",
     *     where N1 is integer specifying the icon number in the mif file,
     *     and N2 is the number of the respective icon mask
     */
    virtual const TDesC& BrandingIcon() const = 0;

    /**
     * Is mailbox's outbox empty or not
     * @return boolean
     */
    virtual TBool IsOutboxEmpty() const = 0;

    /**
     * Accessor for seen/unseen status
     * i.e. whether user has been to inbox after last message has been received
     * @return boolean
     */
    virtual TBool Unseen() const = 0;

    /**
     * Accessor for launching parameters
     * These parameters specify what application is launched when widget is pressed
     * @return interface to launch parameters
     */
    virtual MEmailLaunchParameters& LaunchParameters() const = 0;

    /**
     * Accessor for total count of messages in inbox
     * @return total message count
     */
    virtual TInt MessageCount() const = 0;

    /**
     * Accessor for mailbox's messages. If there are more messages in the array
     * than fits the widget, only the newest will be published.
     * Assumption: array must be ordered based on timestamp (i.e. newest in index 0)
     * Assumption: plugin does not have to upkeep more than 2 latest messages
     * @return array of messages
     */
    virtual const RPointerArray<MMessageData>& LatestMessagesL() const = 0;
    };

} // namespace

#endif // EMAILMAILBOXDATA_H
