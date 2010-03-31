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
* Description:  Virtual Phonebook field selector interface needed 
*                by e.g. CVPbkFieldFilter.
*
*/


#ifndef MVPBKCONTACTFIELDSELECTOR_H
#define MVPBKCONTACTFIELDSELECTOR_H

// INCLUDES
#include <e32cmn.h>

// FORWARD DECLARATIONS
class MVPbkBaseContactField;

// CLASS DECLARATIONS

/**
 * Virtual Phonebook Contact field selector interface.
 * This interface can be used to create a selection object, which
 * can determine which fields belong to the set criteria.
 */
class MVPbkContactFieldSelector
    {
    public:
        /**
         * Returns true if aField belongs to the set defined by this field
         * selector.
         * 
         * In case field is an IMPP field service name is compared to 
         * existing service installations. Only matched IMPP service
         * providers are included.
         * 
         * @param aField    Contact field to check againt criteria.
         * @return ETrue if the field is included in the set.
         */
        virtual TBool IsFieldIncluded(
                const MVPbkBaseContactField& aField) const =0;
    
        /**
         * Returns an extension point for this interface or NULL.
         * @param aExtensionUid Uid of extension
         * @return Extension point or NULL
         */
        virtual TAny* ContactFieldSelectorExtension(
                TUid /*aExtensionUid*/) { return NULL; }

    protected:
        /**
         * Destructor.
         */
        virtual ~MVPbkContactFieldSelector() { }

    };

#endif  // MVPBKCONTACTFIELDSELECTOR_H

//End of file
