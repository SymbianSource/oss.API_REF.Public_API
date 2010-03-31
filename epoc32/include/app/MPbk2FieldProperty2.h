/*
* Copyright (c) 2005-2007 Nokia Corporation and/or its subsidiary(-ies).
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
* Description:  Phonebook 2 field property interface.
*
*/


#ifndef MPBK2FIELDPROPERTY2_H
#define MPBK2FIELDPROPERTY2_H

// CLASS DECLARATION
/**
 * This class is an extension to MPbk2FieldProperty.
 * See documentation of MPbk2FieldProperty from header
 * MPbk2FieldProperty.h 
 * 
 * You can access this extension by calling
 * MPbk2FieldProperty->FieldPropertyExtension()
 */
class MPbk2FieldProperty2
    {
    public: // Interface

        /**
         * Returns name of external service provider.
         *
         * @return  A external service provider name.
         */
        virtual const TDesC& XSpName() const = 0;
    
    protected: // Protected destructor
        ~MPbk2FieldProperty2()
            {}
    };

#endif // MPBK2FIELDPROPERTY2_H

// End of File
