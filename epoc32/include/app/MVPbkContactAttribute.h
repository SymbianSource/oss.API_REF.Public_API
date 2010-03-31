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
* Description:  Virtual Phonebook interface for contact attributes.
*                Attributes are e.g speed dial or defaults
*
*/


#ifndef MVPBKCONTACTATTRIBUTE_H
#define MVPBKCONTACTATTRIBUTE_H

// INCLUDE FILES
#include <e32cmn.h>
#include <e32std.h>

/**
 * Virtual Phonebook Contact attribute interface.
 * Base class for different kinds of attributes.
 * The UID returned by AttributeType uniquely identifies 
 * the implementation class of this interface.
 */
class MVPbkContactAttribute
    {
    public:
        /**
         * Destructor.
         */
        virtual ~MVPbkContactAttribute() {}
        
        /**
         * Returns the attribute type of the object.
         * @return The attribute type of the object.
         */
        virtual TUid AttributeType() const =0;
        
        /**
         * Returns a copy of this object.
         * @return A copy of this object.
         */
        virtual MVPbkContactAttribute* CloneLC() const =0;

        /**
         * Returns an extension point for this interface or NULL.
         * @param aExtensionUid Extension identifier.
         * @return An extension object.
         */
        virtual TAny* ContactAttributeExtension(
                TUid /*aExtensionUid*/) { return NULL; }
    };
    
#endif // MVPBKCONTACTATTRIBUTE_H

// End of File
