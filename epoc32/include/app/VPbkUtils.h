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
* Description:  Utilities for contact management.
*
*/


#ifndef VPBKUTILS_H
#define VPBKUTILS_H

// INCLUDES
#include <e32def.h>


// FORWARD DECLARATIONS
class MVPbkFieldType;
class MVPbkFieldTypeList;
class MVPbkBaseContactField;
class TResourceReader;
class MVPbkBaseContact;
class RFs;
class MVPbkStoreContact;


/**
 * Utilities for contact management.
 */
namespace VPbkUtils
{

/**
 * Returns the field type if aField matches one of the aFieldTypeList
 * elements otherwise returns NULL.
 *
 * @param aFieldTypeList The field type list to use.
 * @param aField The field whose type to match.
 * @return The matched field type.
 */
IMPORT_C const MVPbkFieldType* MatchFieldType(
    const MVPbkFieldTypeList& aFieldTypeList,
    const MVPbkBaseContactField& aField);
    
/**
 * Checks if aField matches the required field type from aFieldTypeList
 * and the field type of aField matches to field type selector.
 *
 * @param aFieldTypeList A field type list for matching aField.
 * @param aField The field whose type to check.
 * @param aResourceReader A reader to VPBK_FIELD_TYPE_SELECTOR in
 *                        VPbkFieldType.rh.
 * @return ETrue If field type is included.
 */
IMPORT_C TBool IsFieldTypeIncludedL(
    const MVPbkFieldTypeList& aFieldTypeList,
    const MVPbkBaseContactField& aField,
    TResourceReader& aResourceReader);

/**
 * Checks whether the contact contains a field that matches
 * to given field type selector.
 *
 * @param aFieldTypeList A field type list for matching aField.
 * @param aContact The contact whose fields are cheked.
 * @param aResourceReader A reader to VPBK_FIELD_TYPE_SELECTOR in
 *                        VPbkFieldType.rh.
 * @return ETrue If field type is included.
 */
IMPORT_C TBool IsFieldTypeIncludedInContactL(
    const MVPbkFieldTypeList& aFieldTypeList,
    const MVPbkBaseContact& aContact,
    TResourceReader& aResourceReader);

/**
 * Verifies the existance of the syncronization field.
 *
 * The data for the fields are defined in VPbkSyncConstants.h.
 * Adds the field with the default value if not present.
 * If the syncronization field is empty assigns a default value.
 * If field contains invalid data default value is assigned.
 *
 * @param aFs A handle to an open file handle.
 * @param aSupportedFieldTypeList Field types supported by the store. See
 *                                MVPbkContactStoreProperties::SupportedFields.
 * @param aContact A contact whose syncronization field and content is verified.
 */
IMPORT_C TBool VerifySyncronizationFieldL(
        RFs& aFs,
        const MVPbkFieldTypeList& aSupportedFieldTypeList,
        MVPbkStoreContact& aContact);


} // namespace VPbkUtils

#endif // VPBKUTILS_H

//End of file

