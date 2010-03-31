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
* Description:  Interface header for event listener.
*
*/

#ifndef MEMAILOBSERVERLISTENER_H
#define MEMAILOBSERVERLISTENER_H

namespace EmailInterface {

// Forward declarations
class MEmailObserverPlugin;
class MEmailData;

/**
 * Interface class that is implemented by the plugin instantiator
 */
class MEmailObserverListener
{
    public:
    /**
     * Client callback routine. Client should override this method to implement
     * event handling routine.
     * Plugin calls this when it wishes to update data on the widget
     * @param aEmailData reference to email data provided by the plugin
     */
    virtual void EmailObserverEvent( MEmailData& aEmailData ) = 0;
};

} // namespace

#endif // MEMAILOBSERVERLISTENER_H
