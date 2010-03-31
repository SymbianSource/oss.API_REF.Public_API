/*
* Copyright (c) 2002-2007 Nokia Corporation and/or its subsidiary(-ies).
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
* Description:  Virtual Phonebook bookmark for referencing to any type of 
*                item in the view. Can be used to find an item from the 
*                view that was previously saved as a bookmark.
*
*/



#ifndef MVPBKCONTACTBOOKMARK_H
#define MVPBKCONTACTBOOKMARK_H

// INCLUDES
#include <e32cmn.h>
#include <e32std.h>

// CLASS DECLARATIONS

/**
 * Virtual Phonebook Contact bookmark.
 * This bookmark interface can be used to reference any type
 * of item in a Virtual Phonebook view.
 */
class MVPbkContactBookmark
    {
    public: // destructor
        /**
         * Destructor.
         */
        virtual ~MVPbkContactBookmark() { }

        /**
         * Returns an extension point for this interface or NULL.
         * @param aExtensionUid Uid of extension
         * @return Extension point or NULL
         */
        virtual TAny* ContactBookmarkExtension(
                TUid /*aExtensionUid*/) { return NULL; }
    };

#endif // MVPBKCONTACTBOOKMARK_H

// End of file
