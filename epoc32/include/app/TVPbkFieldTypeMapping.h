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
* Description:  A helper class for mapping field types to Versit 
*                or non-Versit types.           
*
*/


#ifndef TVPBKFIELDTYPEMAPPING_H
#define TVPBKFIELDTYPEMAPPING_H

#include <vpbkfieldtype.hrh>
#include <tvpbkfieldversitproperty.h>

class MVPbkFieldType;
class MVPbkFieldTypeList;

/**
 * A helper class for mapping field types to Versit or non-Versit types.
 *
 * Can be used also for finding a field type from a field type list.
 * @see VPbkFieldType.rh
 * @lib VPbkEng.lib
 */
class TVPbkFieldTypeMapping
    {
    public:
        /**
         * Constructs this object from a VPBK_FIELD_TYPE_MAPPING resource.
         *
         * @param aReader A resource reader to VPBK_FIELD_TYPE_MAPPING that
         *                is defined in VPbkFieldType.rh.
         */
        IMPORT_C TVPbkFieldTypeMapping(TResourceReader& aReader);

        /**
         * Constructs an empty mapping.
         */
        IMPORT_C TVPbkFieldTypeMapping();
        
    public: // Interface
        /**
         * Returns a field type that matches this type mapping or NULL.
         *
         * @param aFieldTypeList A field type list that is for searching.
         * @return A matched field type or NULL.
         */
        IMPORT_C const MVPbkFieldType* FindMatch(
                const MVPbkFieldTypeList& aFieldTypeList) const;

        /**
         * Sets the Versit property of this field type mapping.
         *
         * @param aVersitProperty A new Versit property for the mapping.
         */
        IMPORT_C void SetVersitProperty(
                TVPbkFieldVersitProperty aVersitProperty);

        /**
         * Sets the non-Versit type of this field type mapping.
         *
         * @param aNonVersitType A new non-Versit type.
         */
        IMPORT_C void SetNonVersitType(
                TVPbkNonVersitFieldType aNonVersitType);

    private: // Data
        ///Own: Versit property
        TVPbkFieldVersitProperty iVersitProperty;
        ///Own: non-Versit property
        TVPbkNonVersitFieldType iNonVersitType;
        ///Own: Spare for future extension
        TAny* iSpare;
	};

#endif // TVPBKFIELDTYPEMAPPING_H

//End of file
