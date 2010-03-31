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

#ifndef MEMAILDATA_H
#define MEMAILDATA_H

// System includes
#include <memailmailboxdata.h>

namespace EmailInterface {

/**
 * Container interface to data that plugin offers
 * Plugin must ensure that the data is available when MailboxesL() returns
 * Client will access the data always through this API; no direct references are
 * stored permanently in the client
 */
class MEmailData
    {
public:
    /**
     * Accessor for mailbox information that this plugin is offering
     * @ return pointer array of mailbox data interfaces
     */
    virtual RPointerArray<MMailboxData>& MailboxesL() = 0;
    };

} // namespace

#endif // MEMAILDATA_H
