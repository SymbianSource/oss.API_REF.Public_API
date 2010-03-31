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
* Description:  An interface for static contact store properties
*
*/


#ifndef MVPBKCONTACTSTOREPROPERTIES2_H
#define MVPBKCONTACTSTOREPROPERTIES2_H


// INCLUDES
#include <e32cmn.h>

// CLASS DECLARATIONS

/**
 * This class is an extension to MVPbkContactStoreProperties.
 * See documentation of MVPbkContactStoreProperties from header MVPbkContactStoreProperties.h
 *
 * You can access this extension by calling MVPbkContactStoreProperties->ContactStorePropertiesExtension()
 */
class MVPbkContactStoreProperties2
    {
    protected:

        /**
         * This extension cannot be destroyed through this interface.
         */
        virtual ~MVPbkContactStoreProperties2() {};

    public:

        /**
         * Returns true if the store supports own contact.
         *
         * @return ETrue if the store supports own contact.
         */
        virtual TBool SupportsOwnContact() const =0;
    };


#endif  // MVPBKCONTACTSTOREPROPERTIES_H

//End of file
