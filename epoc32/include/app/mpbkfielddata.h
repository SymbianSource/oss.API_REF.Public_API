/*
* Copyright (c) 2002 Nokia Corporation and/or its subsidiary(-ies).
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
* Description: 
*       Interface classes for accessing Phonebook contact data.
*
*/


#ifndef __MPbkFieldData_H__
#define __MPbkFieldData_H__

//  INCLUDES
#include <cntdef.h>         // TStorageType
#include "PbkFields.hrh"    // TPbkFieldId

// FORWARD DECLARATIONS
class MPbkFieldData;

// CLASS DECLARATION

/**
 * Array of MPbkFieldData objects.
 */
class MPbkFieldDataArray
    {
    public:  // Destructor
        virtual ~MPbkFieldDataArray() {}

    public:  // Abstract interface
        /**
         * Returns the number of field data objects in this array.
         * @return The number of field data objects in this array.
         */
        virtual TInt PbkFieldCount() const = 0;

        /**
         * Returns the field data object at aIndex.
         * @param aIndex    The field to index.
         * @return The field data object at aIndex.
         */
        virtual MPbkFieldData& PbkFieldAt(TInt aIndex) = 0;

        /**
         * Returns the const field data object at aIndex.
         * @return The const field data object at aIndex.
         */
        virtual const MPbkFieldData& PbkFieldAt(TInt aIndex) const = 0;
    };

/**
 * Phonebook field data abstract interface. The interface is used as an
 * abstraction to handle phonebook contact item field data access. 
 * The Phonebook contact item field abstraction TPbkContactItemField 
 * implements this interface.
 */
class MPbkFieldData
    {
    public:  // Destructor
        /**
         * Destructor.
         */
        virtual ~MPbkFieldData() {}

    public:  // Interface
        /**
         * Returns the type of this field data.
         * @return KStrorageTypeText or KStoragetTypeDateTime.
         */
        virtual TStorageType PbkFieldType() const = 0;

        /**
         * Returns the field id of this field data.
         */
        virtual TPbkFieldId PbkFieldId() const = 0;

        /**
         * Returns the text value of this field data.
         * @precond PbkFieldType()==KStrorageTypeText.
         */
        virtual TPtrC PbkFieldText() const = 0;

        /**
         * Returns the Time value of this field data.
         * @precond PbkFieldType()==KStoragetTypeDateTime.
         */
        virtual TTime PbkFieldTime() const = 0;

    };


#endif // __MPbkFieldData_H__

// End of File
