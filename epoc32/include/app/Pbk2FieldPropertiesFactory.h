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
* Description:  Phonebook 2 field properties factory.
*
*/


#ifndef PBK2FIELDPROPERTIESFACTORY_H
#define PBK2FIELDPROPERTIESFACTORY_H

// INCLUDE FILES
#include <e32def.h>

// FORWARD DECLARATIONS
class MVPbkFieldTypeList;
class MPbk2FieldPropertyArray;
class RFs;

/**
 * Phonebook 2 field properties factory.
 * Pbk2FieldPropertiesFactory is responsible for creating field
 * property arrays.
 *
 * @see MPbk2FieldPropertyArray
 */
class Pbk2FieldPropertiesFactory
    {
    public: // Interface

        /**
         * Creates a new field property array.
         *
         * @param aSupportedFieldTypeList   A list of Virtual Phonebook
         *                                  field types. Pass the master
         *                                  field type list to have all
         *                                  the properties loaded.
         * @param aRFs                      A file system session reference
         *                                  for reading resources.
         *                                  If NULL then own session
         *                                  is created.
         * @return  Field property array.
         */
        IMPORT_C static MPbk2FieldPropertyArray* CreateL(
                const MVPbkFieldTypeList& aSupportedFieldTypeList,
                RFs* aRFs = NULL );
    
        /**
         * Creates a new field property array.
         *
         * @param aSupportedFieldTypeList   A list of Virtual Phonebook
         *                                  field types. Pass the master
         *                                  field type list to have all
         *                                  the properties loaded.
         * @param aRFs                      A file system session reference
         *                                  for reading resources.
         *                                  If NULL then own session
         *                                  is created.
         * @return  Field property array.
         */
        IMPORT_C static MPbk2FieldPropertyArray* CreateLC(
                const MVPbkFieldTypeList& aSupportedFieldTypeList,
                RFs* aRFs = NULL );
    };

#endif // PBK2FIELDPROPERTIESFACTORY_H

// End of File
