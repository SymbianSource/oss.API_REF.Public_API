/*
* Copyright (c) 2004-2007 Nokia Corporation and/or its subsidiary(-ies).
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
* Description:  An interface for objects that can be expanded to a view
*
*/


#ifndef MVPBKEXPANDABLE_H
#define MVPBKEXPANDABLE_H

// INCLUDES
#include <e32std.h>

// FORWARD DECLARATIONS
class MVPbkContactViewBase;
class MVPbkContactViewObserver;
class MVPbkFieldTypeList;

// CLASS DECLARATIONS

/**
 * An interface for objects that can be expanded to a view
 *
 * E.g. a view contact that represents a group can be expanded
 * to the group members view.
 * @see MVPbkViewContact
 */
class MVPbkExpandable
    {
    protected: // destructor
        /**
         * Destructor.
         */
        virtual ~MVPbkExpandable() { }

    public: // interface
        /**
         * Returns an expanded view that is constructed asynchronously.
         *
         * A client must wait the expanded view to become ready before
         * usage.
         *
         * @param aObserver A contact view observer
         * @param aSortOrder A contact view sort order.
         * @return the expanded view.
         * @return The child view.
         */
        virtual MVPbkContactViewBase* ExpandLC(
            MVPbkContactViewObserver& aObserver,
            const MVPbkFieldTypeList& aSortOrder ) const =0;

        /**
         * Returns an extension point for this interface or NULL.
         *
         * @param aExtensionUid no extensions defined currently.
         * @return an extension point for this interface or NULL.
         */
        virtual TAny* ExpandableExtension( TUid /*aExtensionUid*/ ) 
                { return NULL; }
    };

#endif // MVPBKEXPANDABLE_H

//End of file
