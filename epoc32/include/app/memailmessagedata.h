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

#ifndef MEMAILMESSAGEDATA_H
#define MEMAILMESSAGEDATA_H

// System includes
#include <e32std.h>

namespace EmailInterface {

/** Email message priority flag */
enum TEmailPriority
    {
    ENormal,
    ELow,
    EHigh
    };

/**
 * Container interface for message related info
 * Plugin implementor make implementation for this
 */
class MMessageData
    {
public:
    /**
     * Accessor for message sender information
     * @return sender as descriptor
     */
    virtual const TDesC& Sender() const = 0;

    /**
     * Accessor for message subject information
     * @return message subject
     */
    virtual const TDesC& Subject() const = 0;

    /**
     * Accessor for message timestamp information
     * @return timestamp
     */
    virtual TTime TimeStamp() const = 0;

    /**
     * Accessor for message read/unread status
     * @return boolean
     */
    virtual TBool Unread() const = 0;

    /**
     * Accessor for message priority status
     * @return one of message priority values
     */
    virtual TEmailPriority Priority() const = 0;

    /**
     * Accessor for message's attachment status
     * @return boolean depending whether message has any attachmants or not
     */
    virtual TBool Attachments() const = 0;

    /**
     * Accessor for info whether this is a calendar message or not
     * @return boolean
     */
    virtual TBool CalendarMsg() const = 0;

    /**
     * Accessor for info whether this message has been replied or not
     * @return boolean
     */
    virtual TBool Replied() const = 0;

    /**
     * Accessor for info whether this message has been forwarded or not
     * @return boolean
     */
    virtual TBool Forwarded() const = 0;
    };

} // namespace

#endif // MEMAILMESSAGEDATA_H
