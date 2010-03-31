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
* Description:  Defines a public interface class MAknsControlContext and 
*                related enumerations.
*
*/


#ifndef AKNSCONTROLCONTEXT_H
#define AKNSCONTROLCONTEXT_H

//  INCLUDES
#include <AknsConstants.h>
#include <AknsItemID.h>
#include <coemop.h>

// DATA TYPES

/** 
* Skin parameter types for MAknsControlContext::SupplySkinParameter.
*
* @since 2.0
*/
enum TAknsCCParameter
    {
    // This enumeration is intentionally empty.
    };

/** 
* Values for skin object types (given as aObject parameter for 
* MAknsControlContext::SupplySkinObject).
*
* @since 2.0
*/
enum TAknsCCObject
    {

    /**
    * Item ID for layout background.
    *
    * MAknsControlContext::SupplySkinObject
    * should return a pointer to TAknsBackground or @c NULL (default used).
    *
    * @since 2.0
    */
    EAknsCCOBackground              = 0,
    
    /**
    * Pointer to parent context.
    *
    * MAknsControlContext::SupplySkinObject
    * should return a pointer to the parent context (of type 
    * @c MAknsControlContext) or @c NULL (no parent context).
    *
    * @since 2.6
    */
    EAknsCCOParentContext           = 1
    };

/**
* Control context type enumeration.
*
* @since 2.0
*/
enum TAknsControlContextType
    {

    /**
    * Unknown type. The control context can only be assumed to be compatible
    * with MAknsControlContext.
    *
    * @since 2.0
    */
    EAknsControlContextTypeUnknown  = 0,

    /**
    * The control context type for CAknsBasicBackgroundControlContext
    * (and derived types).
    *
    * @since 2.0
    */
    EAknsControlContextTypeBasic    = 1,

    /**
    * The control context type for CAknsLayeredBackgroundControlContext
    * (and derived types).
    *
    * @since 2.0
    */
    EAknsControlContextTypeLayered  = 2,

    /**
    * The control context type for CAknsListBoxBackgroundControlContext
    * (and derived types).
    *
    * @since 2.0
    */
    EAknsControlContextTypeListBox  = 3,

    /**
    * The control context type for CAknsFrameBackgroundControlContext
    * (and derived types).
    *
    * @since 2.0
    */
    EAknsControlContextTypeFrame    = 4,

    /**
    * The control context type for CAknsCombinedBackgroundControlContext
    * (and derived types).
    *
    * @since 3.2
    */
    EAknsControlContextTypeCombined = 5,

    /**
    * The control context type for CAknsMaskedFrameBackgroundControlContext
    * (and derived types).
    *
    * @since 3.2
    */
    EAknsControlContextTypeMasked = 6
    };

// CLASS DECLARATIONS

/**
* Interface that provides context specific skin parameters.
* This interface is used by AknsDrawUtils to query context specific parameters,
* such as background override. Application should instantiate a class that 
* implements this interface and provide pointer to it using 
* @c MObjectProvider::MopSupplyObject in the appropriate control. 
*
* This is a public class with exported functions.
* The class is not intended for user derivation - concrete classes implementing
* the interface are provided by the library. See 
* @c CAknsBasicBackgroundControlContext and 
* @c CAknsListBoxBackgroundControlContext for further details.
*
* @lib AknSkins.lib
*
* @since 2.0
*/
class MAknsControlContext
    {
    public: // Type UID
        /**         
        * Type ID declaration.
        * Type ID is used to make it possible to retrieve control context
        * through @c MObjectProvider::MopSupplyObject interface.        
        */
        DECLARE_TYPE_ID(0x10005a29)

    public: // Destructor

        /**
        * Destructor.
        * Destructor is provided only to enable deletion using base class
        * pointer. Caller should never delete control context retrieved through
        * @c MObjectProvider interface.
        */
        inline virtual ~MAknsControlContext() {}

    public: // New functions

        /**
        * Provides context specific integer parameter.
        *
        * @since 2.0
        *
        * @param aParam Type of the parameter to be retrieved. Possible values
        *   are defined in ::TAknsCCParameter enumeration.
        *
        * @return Integer value as defined in ::TAknsCCParameter for the 
        *   particular parameter. For unknown or unhandled values zero must be
        *   returned.        
        */
        virtual TInt SupplySkinParameter( TAknsCCParameter aParam ) =0;

        /**
        * Provides context specific object.
        *
        * @since 2.0
        *
        * @param aObject Type of the object to be retrieved. Possible values 
        *   are defined in ::TAknsCCObject enumeration.
        *
        * @return Pointer to object as defined in ::TAknsCCObject for that 
        *   specific aObject parameter value. For unknown or unhandled values
        *   @c NULL must be returned.        
        */
        virtual TAny* SupplySkinObject( TAknsCCObject aObject ) =0;

        /**
        * Determines whether this control context is compatible with the
        * given derived type.
        *
        * @since 2.0
        *
        * @param aType Type of the derived control context class (one of
        *   the values in TAknsControlContextType).
        *
        * @return ETrue if this control context instance is compatible with
        *   the given type (i.e. can be casted to the corresponding concrete
        *   class). EFalse otherwise.
        */
        virtual TBool IsCompatibleWithType( 
            const TAknsControlContextType aType ) const =0;

        /**
        * Updates the control context, if necessary.
        * This method is called by the framework before drawing with the 
        * context.
        *
        * Base class implementation returns 0.
        *
        * @since 2.6
        *
        * @return Return value reserved for future use. Currently returns 0.
        */
        virtual TInt UpdateContext();

    protected: // Reserved virtual functions

        /**
        * Reserved for future use.
        *
        * @since 2.0
        */
        virtual TInt Reserved2();

    public: // New functions

        /**
        * Returns type UID pointer that can be used in MopSupplyObject.
        *
        * @since 2.0
        *
        * @param aId Type UID, should be the same that was given as aId
        *   parameter of MopSupplyObject.
        *
        * @param aContext Pointer to an MAknsControlContext instance.
        *
        * @return Type UID pointer containing aContext, or @c NULL type UID
        *   pointer if given type UID does not match MAknsControlContext or
        *   aContext is @c NULL.
        */
        IMPORT_C static TTypeUid::Ptr SupplyMopObject( TTypeUid aId, 
            MAknsControlContext* aContext );

    };

#endif      // AKNSCONTROLCONTEXT_H   

// End of File
