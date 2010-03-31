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
* Description:  ?Description
*
*/


#ifndef AKNSRLPARAMETER_H
#define AKNSRLPARAMETER_H

/**
* Parameter type enumeration.
*
* @since 2.8
*/
enum TAknsRlParameterType
    {
    EAknsRlParameterTypeNumber    = 0,
    EAknsRlParameterTypeString    = 1,
    EAknsRlParameterTypeGraphics  = 2
    };

/**
* Content structure for graphics parameters.
*
* @since 2.8
*/
struct TAknsRlGraphicsParam 
    {
    const TDesC16* iFilename;
    TInt iIndex;
    TInt iMaskIndex;
    };

/**
* Parameter data structure.
*
* @since 2.8
*/
struct TAknsRlParameterData
    {
    /**
    * Name (key) of the parameter.
    * No ownership is vested in this structure.
    * Guaranteed to be non-null.
    *
    * @since 2.8
    */
    const TDesC16* iName;

    /**
    * Type of the parameter.
    *
    * @since 2.8
    */
    TAknsRlParameterType iType;

    union {
        /**
        * Value of a number parameter.
        * This field is only valid in number parameters.
        *
        * @since 2.8
        */
        TInt iNumber;

        /**
        * Value of a string parameter.
        * No ownership is vested in this structure.
        * This field is only valid in string parameters, and guaranteed
        * to be non-null for them.
        *
        * @since 2.8
        */
        const TDesC16* iString;

        /**
        * Value of a graphics parameter.
        * No ownership is vested in this structure.
        * This field is only valid in graphics parameters, and guaranteed
        * to be non-null for them.
        *
        * @since 2.8
        */
        const TAknsRlGraphicsParam* iGfx;
        
        };
    };

// FORWARD DECLARATIONS

// CLASS DECLARATION

/**
* Interface to skin effect parameter iterator.
*
* @since 2.8
*/
class MAknsRlParameterIterator
    {
    public: // Constructors and destructor

        /**
        * Destructor for internal use.
        *
        * Destructor is reserved for internal use. Client code usually does
        * not destroy iterators.
        */
        inline virtual ~MAknsRlParameterIterator() {}

    public: // New functions

        /**
        * Checks whether there are more parameters available.
        *
        * @return @c ETrue if subsequent @c GetNextL should succeed,
        *   @c EFalse if @c GetNextL must not be called anymore.
        *
        * @since 2.8
        */
        virtual TBool HasNext() =0;

        /**
        * Gets the next parameter.
        *
        * @return Pointer to the parameter data. The ownership is not
        *   transferred. The data is guaranteed to be valid until
        *   the next call to @c HasNext, @c NextL, or the iterator is
        *   destroyed.
        *
        * @since 2.8
        */
        virtual const TAknsRlParameterData* NextL() =0;
    };

#endif // AKNSRLPARAMETER_H
            
// End of File
