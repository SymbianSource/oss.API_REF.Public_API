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
* Description:  An interface for contact view base extension.
*
*/


#ifndef MVPBKCONTACTVIEWBASECHILDACCESSEXT_H
#define MVPBKCONTACTVIEWBASECHILDACCESSEXT_H

// INCLUDES
#include <e32cmn.h>
#include <vpbkcontactview.hrh>
#include <bamdesca.h>

// FORWARD DECLARATIONS

// CLASS DECLARATIONS

/// This is the UID that identifies this interface.
const TUint KVPbkViewBaseExtChildAccess = 123; // TODO Allocate UID.

/**
 * This is an extension to MVPbkContactViewBase for accessing child views
 * of a composite.
 */
class MVPbkContactViewBaseChildAccessExtension
    {
    public: // types

    public:  // Destructor

        /**
         * Destructor.
         */
        virtual ~MVPbkContactViewBaseChildAccessExtension() { }

    public:  // New functions

        /**
         * Tells the number of child views.
         */
        virtual TInt ChildViewCount() const = 0;

        /**
         * Gives reference to a specific child view.
         * @param aIndex Index of child view.
         */
        virtual MVPbkContactViewBase& ChildViewAt(TInt aIndex) = 0;
        
        /**
         * Gives pointer to a specific child view.
         * @param aId Id of child view.
         */
        virtual MVPbkContactViewBase* GetChildViewById(TInt aId) = 0;
  
        /**
         * Gives a current view id.
         */
        virtual TInt GetViewId() = 0;
        /**
         * Returns an extension point for this interface or NULL.
         *
         * @param aExtensionUid no extensions defined currently.
         * @return an extension point for this interface or NULL.
         */
        virtual TAny* MVPbkContactViewBaseChildAccessExtensionExtension(TUid /*aExtensionUid*/) 
                { return NULL; }
    };


#endif // MVPBKCONTACTVIEWBASECHILDACCESSEXT_H

// End of File
