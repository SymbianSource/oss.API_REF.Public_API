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
* Description:  An interface for a field collection of a view contact
*
*/


#ifndef MVPBKVIEWCONTACTFIELDCOLLECTION_H
#define MVPBKVIEWCONTACTFIELDCOLLECTION_H


// INCLUDES
#include <e32def.h>
#include <mvpbkbasecontactfieldcollection.h>

// CLASS DECLARATIONS

/**
 * An interface for a field collection of a view contact.
 */
class MVPbkViewContactFieldCollection : public MVPbkBaseContactFieldCollection
    {
    public:  // Destructor
        /**
         * Destructor.
         */
        virtual ~MVPbkViewContactFieldCollection() { }

        /**
         * Returns an extension point for this interface or NULL.
         *
         * @param aExtensionUid no extensions defined currently.
         * @return An extension point for this interface or NULL.
         */
        virtual TAny* ViewContactFieldCollectionExtension( 
                TUid /*aExtensionUid*/ ) { return NULL; }
    };


#endif  // MVPBKVIEWCONTACTFIELDCOLLECTION_H

//End of file


