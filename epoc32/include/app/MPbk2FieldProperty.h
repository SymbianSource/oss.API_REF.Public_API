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


#ifndef MPBK2FIELDPROPERTY_H
#define MPBK2FIELDPROPERTY_H

// INCLUDE FILES
#include <e32def.h>
#include <pbk2fieldproperty.hrh>

// FORWARD DECLARATIONS
class MVPbkFieldType;
class TPbk2IconId;

//Use this UID to access field property interface extension 2. Used as
//a parameter to FieldPropertyExtension() method.
const TUid KMPbk2FieldPropertyExtension2Uid = { 2 };

/**
 * Phonebook 2 field property interface.
 *
 * Field property defines data for contact field presentation
 * in the UI. 
 */
class MPbk2FieldProperty
    {
    public: // Interface

        /**
         * Compares two field properties.
         *
         * @param aOther    The property to compare
         * @return  ETrue if properties are the same.
         */
        virtual TBool IsSame(
            const MPbk2FieldProperty& aOther ) const = 0;

        /**
         * Returns the field type of the property
         *
         * @return  The field type this property links to.
         */
        virtual const MVPbkFieldType& FieldType() const = 0;

        /**
         * Returns the multiplicity information
         *
         * @return  Multiplicity property which tells that can
         *          there be several fields of this type in the contact.
         */
        virtual TPbk2FieldMultiplicity Multiplicity() const = 0;

        /**
         * Returns the maximum length of the field.
         *
         * @return  Static maximum length of the field. Note, that the
         *          contact store can have it's own limits.
         */
        virtual TInt MaxLength() const = 0;

        /**
         * Returns the editing mode for the field editor.
         *
         * @return  Field editing mode..
         */
        virtual TPbk2FieldEditMode EditMode() const = 0;

        /**
         * Returns the default character case for the field editor.
         *
         * @return  Default character case.
         */
        virtual TPbk2FieldDefaultCase DefaultCase() const = 0;

        /**
         * Returns the icon id for the field.
         *
         * @return  Icon id.
         */
        virtual const TPbk2IconId& IconId() const = 0;

        /**
         * Returns the type of the field editor.
         *
         * @return  Type of the field editor (text, date, number etc.).
         */
        virtual TPbk2FieldCtrlType CtrlType() const = 0;

        /**
         * Returns the field property flags defined in
         * Pbk2FieldProperty.hrh.
         *
         * @return  Field property flags.
         */
        virtual TUint Flags() const = 0;

        /**
         * Returns the field ordering item.
         *
         * @return  Number that defines the ordering of the field.
         */
        virtual TInt OrderingItem() const = 0;

        /**
         * Returns the field ordering item in 'add item' dialog.
         *
         * @return  Number that defines the ordering of the field
         *          in the contact editor add item dialog.
         */
        virtual TInt AddItemOrdering() const = 0;

        /**
         * Returns field 'add item' text, or the default label if
         * there is no 'add item' text defined.
         *
         * @return  Add item text or the default label.
         */
        virtual const TDesC& AddItemText() const = 0;

        /**
         * Returns the location of the field.
         *
         * @return  Location of the field (home, work, etc.).
         */
        virtual TPbk2FieldLocation Location() const = 0;

        /**
         * Returns the group id of the property.
         *
         * @return  Group id.
         */
        virtual TPbk2FieldGroupId GroupId() const = 0;

        /**
         * Returns the default label that should be used if the store
         * doesn't define a label.
         *
         * @return  Default label.
         */
        virtual const TDesC& DefaultLabel() const = 0;

        /**
         * Returns an extension point for this interface or NULL.
         *
         * @param aExtensionUid     Extension UID.
         * @return  Extension point.
         */
        virtual TAny* FieldPropertyExtension(
                TUid /*aExtensionUid*/ )
            {
            return NULL;
            }
    };

#endif // MPBK2FIELDPROPERTY_H

// End of File
