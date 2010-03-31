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
* Description:  An interface for objects that belongs to object hierarchy
*
*/


#ifndef MVPBKOBJECTHIERARCHY_H
#define MVPBKOBJECTHIERARCHY_H


// INCLUDES
#include <e32cmn.h>

// FORWARD DECLARATIONS
class MVPbkContactStore;


// CLASS DECLARATIONS

/**
 * An interface for objects that belongs to object hierarchy.
 *
 * The interface can be used to get the store from an object that
 * belongs to the hierarchy.
 */
class MVPbkObjectHierarchy
    {
    public:  // Destructor
        virtual ~MVPbkObjectHierarchy() { }

    public:  // New functions
        /**
         * Returns the parent object of this object. For the root of the 
         * hierarchy returns self.
         * @return The parent object.
         */
        virtual MVPbkObjectHierarchy& ParentObject() const = 0;

        /**
         * Returns the contact store where this object originates from.
         * @return The Contact store.
         */
        virtual MVPbkContactStore& ContactStore() const 
            {
            return ParentObject().ContactStore();
            }

        /**
         * Returns an extension point for this interface or NULL.
         *
         * @param aExtensionUid no extensions defined currently.
         * @return An extension point for this interface or NULL.
         */
        virtual TAny* ObjectHierarchyExtension(TUid /*aExtensionUid*/) 
                { return NULL; }
    };


#endif  // MVPBKOBJECTHIERARCHY_H

//End of file


