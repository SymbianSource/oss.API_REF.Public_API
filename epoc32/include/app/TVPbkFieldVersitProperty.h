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
* Description:  A basic field Versit property.
*
*/


#ifndef TVPBKFIELDVERSITPROPERTY_H
#define TVPBKFIELDVERSITPROPERTY_H


// INCLUDES
#include <e32std.h>
#include <vpbkfieldtype.hrh>
#include <tvpbkfieldtypeparameters.h>


// FORWARD DECLARATIONS
class TResourceReader;
/// Reserved name for class TVPbkFieldVersitProperty future extension.
class TVPbkFieldVersitPropertyExt;


// CLASS DECLARATIONS

/**
 * A basic field Versit property.
 *
 * The structure of Versit property is defined in VBK_FIELD_VERSIT_PROPERTY
 * in VPbkFieldType.rh.
 *
 * @see MVPbkFieldType
 * @see MVPbkFieldType::Matches
 * @lib VPbkEng.lib
 */
class TVPbkFieldVersitProperty
    {
    public:  // Constructors
        /**
         * Default constructor. Resets all fields to null values.
         */
        IMPORT_C TVPbkFieldVersitProperty();

        /**
         * Constructs this object from a VBK_FIELD_VERSIT_PROPERTY resource.
         *
         * Sets also the Versit extension name. Only a reference to the
         * extension name is stored so the client must either keep the resource
         * buffer alive or make a copy of the extension name and use
         * SetExtensionName. The reference must be valid for the lifetime of
         * this object.
         *
         * @param aResReader A reader to the VBK_FIELD_VERSIT_PROPERTY 
         *                   resource.
         */
        IMPORT_C TVPbkFieldVersitProperty(TResourceReader& aResReader);

    public:  // New functions
        /**
         * Returns the Versit property name.
         *
         * @return The Versit property name.
         */
        inline TVPbkFieldTypeName Name() const;

        /**
         * Returns the Versit property subfield.
         *
         * @return The Versit property subfield.
         */
        inline TVPbkSubFieldType SubField() const;

        /**
         * Returns the Versit property parameters (read-only).
         *
         * @return The Versit property parameters (read-only).
         */
        inline const TVPbkFieldTypeParameters& Parameters() const;

        /**
         * Returns the Versit property parameters (read-write).
         *
         * @return The Versit property parameters (read-write).
         */
        inline TVPbkFieldTypeParameters& Parameters();

        /**
         * Returns the Versit extension name.
         *
         * @return The Versit extension name.
         */
        inline TPtrC8 ExtensionName() const;

        /**
         * Sets the Versit property name.
         *
         * @param aName The name that is set to this property.
         */
        inline void SetName(TVPbkFieldTypeName aName);

        /**
         * Sets the Versit property subfield.
         *
         * @param aSubField The sub field that is set to this property.
         */
        inline void SetSubField(TVPbkSubFieldType aSubField);

        /**
         * Sets the Versit property parameters.
         *
         * @param aParameters Parameters that are set to this property.
         */
        inline void SetParameters(const TVPbkFieldTypeParameters& aParameters);

        /**
         * Sets the Versit extension name.
         *
         * Only a reference to the name is stored. The reference must be
         * valid for the lifetime of this object.
         *
         * @param aExtensionName The extension name reference that is set to
         *                       this property.
         */
        inline void SetExtensionName(const TDesC8& aExtensionName);

        /**
         * Reads this object's contents from a VBK_FIELD_VERSIT_PROPERTY 
         * resource. 
         *
         * Sets also the Versit extension name. Only a reference to the
         * extension name is stored so the client must either keep the resource
         * buffer alive or make a copy of the extension name and use
         * SetExtensionName. The reference must be valid for the lifetime of
         * this object.
         *
         * @param aResReader A reader to the VBK_FIELD_VERSIT_PROPERTY 
         *                   resource. 
         */
        IMPORT_C void ReadFromResource(TResourceReader& aResReader);

        /**
         * Returns true if this versit property matches aOther.
         *
         * If aOther matches this property it doesn't necessary mean that
         * this property will match to aOther.
         *
         * @param aOther Another property that is matched to this property.
         */
        IMPORT_C TBool Matches(const TVPbkFieldVersitProperty& aOther) const;

    private: // Friends
        /// For testing only
        friend class T_TVPbkFieldVersitProperty;


    private: // Data
        ///Own: Versit property name.
        TVPbkFieldTypeName iName;
        ///Own: Versit subfield.
        TVPbkSubFieldType iSubField;
        ///Own: Versit parameters.
        TVPbkFieldTypeParameters iParameters;
        ///Ref: Name of a versit extension property.
        TPtrC8 iExtensionName;
        ///Own: Extension point for this class.
        TVPbkFieldVersitPropertyExt* iExtension;
    };


inline TVPbkFieldTypeName TVPbkFieldVersitProperty::Name() const
    {
    return iName;
    }

inline TVPbkSubFieldType TVPbkFieldVersitProperty::SubField() const
    {
    return iSubField;
    }

inline const TVPbkFieldTypeParameters& TVPbkFieldVersitProperty::Parameters
        ( ) const
    {
    return iParameters;
    }

inline TVPbkFieldTypeParameters& TVPbkFieldVersitProperty::Parameters()
    {
    return iParameters;
    }

inline TPtrC8 TVPbkFieldVersitProperty::ExtensionName() const
    {
    return iExtensionName;
    }

inline void TVPbkFieldVersitProperty::SetName(TVPbkFieldTypeName aName)
    {
    iName = aName;
    }

inline void TVPbkFieldVersitProperty::SetSubField(TVPbkSubFieldType aSubField)
    {
    iSubField = aSubField;
    }

inline void TVPbkFieldVersitProperty::SetParameters
        (const TVPbkFieldTypeParameters& aParameters)
    {
    iParameters = aParameters;
    }

inline void TVPbkFieldVersitProperty::SetExtensionName
        (const TDesC8& aExtensionName)
    {
    iExtensionName.Set(aExtensionName);
    }

#endif  // TVPBKFIELDVERSITPROPERTY_H

//End of file

