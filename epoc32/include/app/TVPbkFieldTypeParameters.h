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
* Description:  A class for managing field type parameters.
*
*/


#ifndef TVPBKFIELDTYPEPARAMETERS_H
#define TVPBKFIELDTYPEPARAMETERS_H


// INCLUDES
#include <e32std.h>
#include <vpbkfieldtype.hrh>

// FORWARD DECLARATIONS
class TResourceReader;

// CLASS DECLARATIONS

/**
 * A class for managing field type parameters.
 *
 * Parameters are based on the Versit 2.1 standard and they can be
 * found from TVPbkFieldTypeParameter in VPbkFieldType.hrh.
 *
 * @see VBK_FIELD_VERSIT_PROPERTY in VPbkFieldType.rh
 * @see TVPbkFieldVersitProperty
 * @lib VPbkEng.lib
 */
class TVPbkFieldTypeParameters
    {
    public:  // Constructors
        /**
         * Default constructor. Initializes this parameter set to empty.
         */
        inline TVPbkFieldTypeParameters();

        /**
         * Constructs this parameter set from a resource.
         * The resource must have LEN BYTE BYTE[] layout.
         *
         * @param aResReader A reader to resource LEN BYTE BYTE[] that
         *                   contains the parameters.
         * @exception VPbkError::Panic(
         *            VPbkError::EInvalidTypeParameterResource)
         *            if the resource is invalid.
         */
        inline TVPbkFieldTypeParameters(TResourceReader& aResReader);

    public:  // New functions
        /**
         * Initializes this parameter set from a resource. 
         * The resource must have LEN BYTE BYTE[] layout.
         *
         * @param aResReader A reader to resource LEN BYTE BYTE[] that
         *                   contains the parameters.
         * @exception VPbkError::Panic(
         *            VPbkError::EInvalidTypeParameterResource)
         *            if the resource is invalid.
         */
        IMPORT_C void ReadFromResource(TResourceReader& aResReader);
        
        /**
         * Adds parameter set from a resource. 
         * The resource must have LEN BYTE BYTE[] layout.
         *
         * @param aResReader A reader to resource LEN BYTE BYTE[] that
         *                   contains the parameters.
         * @exception VPbkError::Panic(
         *            VPbkError::EInvalidTypeParameterResource)
         *            if the resource is invalid.
         */
        void AddFromResource(TResourceReader& aResReader);

        /**
         * Adds aParam to this parameter set.
         *
         * @param aParam A new parameter to this set.
         * @precond aParam >= 0 && aParam < KVPbkMaxVersitParams.
         *          VPbkError::Panic(VPbkError::EInvalidTypeParameter)
         *          is raised if the precondition does not hold.
         * @return This object for easy chaining of calls.
         * @postcond Contains(aParam)
         */
        inline TVPbkFieldTypeParameters& Add(TVPbkFieldTypeParameter aParam);

        /**
         * Adds all parameters of another parameter set to this set.
         *
         * @param aParams A set of paramters that are added to this set.
         * @return This object for easy chaining of calls.
         * @postcond ContainsAll(aParams)
         */
        inline TVPbkFieldTypeParameters& AddAll(
                const TVPbkFieldTypeParameters& aParams);

        /**
         * Removes aParam from this parameter set.
         *
         * @param aParam A parameter that is removed from this set.
         * @precond aParam >= 0 && aParam < KVPbkMaxVersitParams.
         *          VPbkError::Panic(VPbkError::EInvalidTypeParameter)
         *          is raised if the precondition does not hold.
         * @return This object for easy chaining of calls.
         * @postcond !Contains(aParam)
         */
        inline TVPbkFieldTypeParameters& Remove(
                TVPbkFieldTypeParameter aParam);

        /**
         * Removes all parameters of another parameter set from this set.
         *
         * @param aParams Parameters that are removed from this set.
         * @return This object for easy chaining of calls.
         * @postcond ContainsAll(aParams)
         */
        inline TVPbkFieldTypeParameters& RemoveAll(
                const TVPbkFieldTypeParameters& aParams);

        /**
         * Removes all parameters from this set.
         */
        IMPORT_C void Reset();

        /**
         * Returns true if aParam is included in this parameter set.
         *
         * @param aParam A parameter that is looked for.
         * @precond aParam >= 0 && aParam < KVPbkMaxVersitParams
         * @return ETrue if aParam was found from this set.
         */
        IMPORT_C TBool Contains(TVPbkFieldTypeParameter aParam) const;

        /**
         * Returns true if this parameter set contains all the parameters in
         * aOtherParams.
         *
         * This function is more efficient than calling
         * Contains(TVPbkFieldTypeParameter) in a loop when multiple 
         * parameters are checked.
         *
         * @param aOtherParams A set of parameters that are looked for.
         * @return ETrue if all the aOtherParams were found from this set.
         */
        IMPORT_C TBool ContainsAll(
                const TVPbkFieldTypeParameters& aOtherParams) const;

        /**
         * Returns true if this parameter set contains none of the parameters
         * in aOtherParams.
         *
         * This function is more efficient than calling 
         * Contains(TVPbkFieldTypeParameter) in a loop when multiple
         * parameters are checked.
         *
         * @param aOtherParams A set of parameters that are looked for.
         * @return ETrue if none of the aOtherParams were found from this set.
         */
        IMPORT_C TBool ContainsNone(
                const TVPbkFieldTypeParameters& aOtherParams) const;
        
        /**
         * Returns field type params configuration.
         */
        TUint32* FieldTypeParameters();

        /**
         * Size of field type params configuration.
         */
        TInt Size();        

    private:  // Implementation
        IMPORT_C void DoAdd(TVPbkFieldTypeParameter aParam);
        IMPORT_C void DoAddAll(const TVPbkFieldTypeParameters& aParams);
        IMPORT_C void DoRemove(TVPbkFieldTypeParameter aParam);
        IMPORT_C void DoRemoveAll(const TVPbkFieldTypeParameters& aParams);
        
    private:  // Data
        /// A bit field set up for KVPbkMaxVersitParams parameters.
        enum { KSizeOfTUint32 = 32 };
        enum { KBufSize = KVPbkMaxVersitParams / KSizeOfTUint32 };
        ///Own: bit field for paramers (Contains spares for future extension)
        TUint32 iParams[KBufSize];
    };


// INLINE FUNCTIONS

inline TVPbkFieldTypeParameters::TVPbkFieldTypeParameters()
    {
    Reset();
    }

inline TVPbkFieldTypeParameters::TVPbkFieldTypeParameters(TResourceReader& aResReader)
    {
    ReadFromResource(aResReader);
    }

inline TVPbkFieldTypeParameters& TVPbkFieldTypeParameters::Add
        (TVPbkFieldTypeParameter aParam)
    {
    DoAdd(aParam);
    return *this;
    }

inline TVPbkFieldTypeParameters& TVPbkFieldTypeParameters::AddAll
        (const TVPbkFieldTypeParameters& aParams)
    {
    DoAddAll(aParams);
    return *this;
    }

inline TVPbkFieldTypeParameters& TVPbkFieldTypeParameters::Remove
        (TVPbkFieldTypeParameter aParam)
    {
    DoRemove(aParam);
    return *this;
    }

inline TVPbkFieldTypeParameters& TVPbkFieldTypeParameters::RemoveAll
        (const TVPbkFieldTypeParameters& aParams)
    {
    DoRemoveAll(aParams);
    return *this;
    }

#endif  // TVPBKFIELDTYPEPARAMETERS_H

//End of file
