/*
* Copyright (c) 2006-2007 Nokia Corporation and/or its subsidiary(-ies).
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
* Description:  Virtual Phonebook interface for contact bookmark collections.
*
*/


#ifndef MVPBKCONTACTBOOKMARKCOLLECTION_H
#define MVPBKCONTACTBOOKMARKCOLLECTION_H

#include <e32def.h>

// FORWARD DECLARATIONS
class MVPbkContactBookmark;

/**
 * Virtual Phonebook interface for contact bookmark collections.
 *
 * A bookmark collection owns its bookmarks and the destructor
 * will delete all the bookmarks in the array.
 */
class MVPbkContactBookmarkCollection
    {
    public:
        /**
         * Destructor.
         */
        virtual ~MVPbkContactBookmarkCollection() {}
        
        /**
         * Returns the number of bookmarks in the collections.
         *
         * @return The number of bookmarks in the collections.
         */
        virtual TInt Count() const = 0;
        
        /**
         * Returns a bookmark at given position.
         *
         * @param aIndex    Position of the bookmark in the collection.
         * @return A bookmark at given position.
         */ 
        virtual const MVPbkContactBookmark& At( TInt aIndex ) const = 0;
        
        /**
         * Returns an extension point for this interface or NULL.
         * @param aExtensionUid Extension identifier.
         * @return Extension object.
         */
        virtual TAny* ContactBookmarkCollectionExtension(
                TUid /*aExtensionUid*/) { return NULL; }

    };

#endif // MVPBKCONTACTBOOKMARKCOLLECTION_H

// End of File
