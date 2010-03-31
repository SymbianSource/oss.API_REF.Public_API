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
* Description:  Phonebook 2 contact name formatter factory.
*
*/


#ifndef PBK2CONTACTNAMEFORMATTERFACTORY_H
#define PBK2CONTACTNAMEFORMATTERFACTORY_H

//  INCLUDES
#include <e32base.h>

// FORWARD DECLARATIONS
class MVPbkFieldTypeList;
class MPbk2ContactNameFormatter;
class CPbk2SortOrderManager;
class TResourceReader;
class RFs;

// CLASS DECLARATION

/**
 * Phonebook 2 contact name formatter factory.
 * Pbk2ContactNameFormatterFactory is responsible for creating
 * name formatter objects.
 *
 * @see MPbk2ContactNameFormatter
 */
class Pbk2ContactNameFormatterFactory
    {
    public: // Interface

        /**
         * Creates and returns an MPbk2ContactNameFormatter instance.
         * Uses Phonebook default unnamed text.
         *
         * @param aMasterFieldTypeList  Master field type list of
         *                              Virtual Phonebook. Should be the
         *                              FieldTypes() from CVPbkContactManager.
         * @param aSortOrderManager     Sort order manager for fetching
         *                              current sort order.
         * @param aFs                   A file system session reference for
         *                              resource file handling. If NULL then
         *                              an own session is created.
         * @return  A new MPbk2ContactNameFormatter instance.
         */
        IMPORT_C static MPbk2ContactNameFormatter* CreateL(
                const MVPbkFieldTypeList& aMasterFieldTypeList,
                const CPbk2SortOrderManager& aSortOrderManager,
                RFs* aFs = NULL );

        /**
         * Creates and returns an MPbk2ContactNameFormatter instance.
         *
         * @param aUnnamedText          Text to use for unnamed contacts.
         * @param aMasterFieldTypeList  Master field type list of
         *                              Virtual Phonebook. Should be the
         *                              FieldTypes() from CVPbkContactManager.
         * @param aSortOrderManager     Sort order manager for fetching
         *                              current sort order.
         * @param aFs                   A file system session reference for
         *                              resource file handling. If NULL then
         *                              an own session is created.
         * @return  A new MPbk2ContactNameFormatter instance.
         */
        IMPORT_C static MPbk2ContactNameFormatter* CreateL(
                const TDesC& aUnnamedText,
                const MVPbkFieldTypeList& aMasterFieldTypeList,
                const CPbk2SortOrderManager& aSortOrderManager,
                RFs* aFs = NULL );

        /**
         * Creates and returns an MPbk2ContactNameFormatter instance.
         *
         * @param aMasterFieldTypeList      Master field type list of
         *                                  Virtual Phonebook. Should be the
         *                                  FieldTypes() from CVPbkContactManager.
         * @param aSortOrderManager         Sort order manager for fetching
         *                                  current sort order.
         * @param aTitleFieldSelectorReader VPBK_FIELD_TYPE_SELECTOR
         *                                  from VPbkFieldType.rh
         *                                  Defines field types that can be
         *                                  used for name formatting
         * @param aUnnamedText              Text to use for unnamed contacts.
         *                                  If NULL then default text is used
         * @param aFs                       A file system session reference for
         *                                  resource file handling. If NULL then
         *                                  an own session is created.
         * @return  A new MPbk2ContactNameFormatter instance.
         */
        IMPORT_C static MPbk2ContactNameFormatter* CreateL(
                const MVPbkFieldTypeList& aMasterFieldTypeList,
                const CPbk2SortOrderManager& aSortOrderManager,
                TResourceReader& aTitleFieldSelectorReader,
                const TDesC* aUnnamedText,
                RFs* aFs = NULL );

    private: // Disabled functions
        Pbk2ContactNameFormatterFactory();
    };

#endif // PBK2CONTACTNAMEFORMATTERFACTORY_H

// End of File
