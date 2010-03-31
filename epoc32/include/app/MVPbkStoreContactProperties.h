/*
* Copyright (c) 2002-2008 Nokia Corporation and/or its subsidiary(-ies).
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
* Description:  Auxiliary contact properties.
*
*/


#ifndef CVPBKSTORECONTACTPROPERTIES_H
#define CVPBKSTORECONTACTPROPERTIES_H

// INCLUDES
#include <e32std.h>

// FORWARD DECLARATIONS

// CLASS DECLARATIONS

/**
 * Auxiliary contact properties.
 *
 * @lib VPbkEng.lib
 */
class MVPbkStoreContactProperties
    {
    public: // Constructors and Destructor
        virtual ~MVPbkStoreContactProperties() {}

    public:  // interface
        /**
         * Returns the contact's last modified date/time.
         *
         * @return modification date/time
         * @exception KErrNotSupported If the contact's store doesn't support
         *            last modified property
         */
        virtual TTime LastModifiedL() const =0;

        /**
         * Returns the contact's guid.
         *
         * @return guid
         * @exception KErrNotSupported If the contact's store doesn't support
         *            contact guid property
         */
        virtual TPtrC GuidL() const =0;
        
    };

#endif // CVPBKSTORECONTACTPROPERTIES_H

// End of file
