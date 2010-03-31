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
* Description:  Virtual Phonebook interface for field ordering. 
*                Compares two fields.
*
*/


#ifndef MVPBKCONTACTFIELDORDERING_H
#define MVPBKCONTACTFIELDORDERING_H

// INCLUDES
#include <e32cmn.h>

// FORWARD DECLARATIONS
class MVPbkBaseContactField;

// CLASS DECLARATIONS

/**
 * Virtual Phonebook Contact field ordering interface.
 * This inteface is used for comparing two contact fields, when setting up
 * a field ordering.
 */
class MVPbkContactFieldOrdering
    {
    public:
        /**
         * Returns the relative ordering of two fields.
         *
         * @param aLhs  Left-hand side of the compare.
         * @param aRhs  Right-hand side of the compare.
         * @return <0 if aLhs < aRhs, >0 if aLhs > aRhs or 0 if aLhs==aRhs.
         */
        virtual TInt CompareFields(
                const MVPbkBaseContactField& aLhs, 
                const MVPbkBaseContactField& aRhs) const =0;

        /**
         * Returns an extension point for this interface or NULL.
         * @param aExtensionUid Uid of extension.
         * @return Extension point or NULL.
         */
        virtual TAny* ContactFieldOrderingExtension(
                TUid /*aExtensionUid*/) { return NULL; }

    protected:
        /**
         * Destructor.
         */
        virtual ~MVPbkContactFieldOrdering() { }

    };

#endif  // MVPBKCONTACTFIELDORDERING_H

// End of File
