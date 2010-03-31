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
* Description:  An interface for contact store views.
*
*/


#ifndef MVPBKCONTACTVIEW_H
#define MVPBKCONTACTVIEW_H

// INCLUDES
#include <mvpbkcontactviewbase.h>
#include <mvpbkobjecthierarchy.h>

// CLASS DECLARATIONS

/**
 * An interface for contact store views.
 *
 * The view contains contacts from a single contact store.
 * MVPbkObjectHierarchy interface can be used to navigate to the store.
 */
class MVPbkContactView : 
        public MVPbkContactViewBase,
        public MVPbkObjectHierarchy
    {
    public:  // Destructor
        /**
         * Destructor.
         */
        virtual ~MVPbkContactView() { }

        /**
         * Returns an extension point for this interface or NULL.
         *
         * @param aExtensionUid no extensions defined currently.
         * @return an extension point for this interface or NULL.
         */
        virtual TAny* ContactViewExtension(TUid /*aExtensionUid*/) 
                { return NULL; }
    };

#endif // MVPBKCONTACTVIEW_H

//End of file
