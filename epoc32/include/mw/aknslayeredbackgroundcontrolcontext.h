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
* Description:  Defines a concrete public class 
*                CAknsLayeredBackgroundControlContext.
*
*/


#ifndef AKNSLAYEREDBACKGROUNDCONTROLCONTEXT_H
#define AKNSLAYEREDBACKGROUNDCONTROLCONTEXT_H

//  INCLUDES
#include <AknsBasicBackgroundControlContext.h>

// CLASS DECLARATION

/**
*  Implementation of a control context that provides one or more layered
*  backgrounds with their layout rectangles.
*
*  This is a public class with exported functions.
*  The class is not intended for derivation outside the library.
*
*  @lib AknSkins.lib
*
*  @since 2.0
*/
NONSHARABLE_CLASS(CAknsLayeredBackgroundControlContext) : 
    public CAknsBasicBackgroundControlContext
    {
    public:  // Constructors and destructor
        
        /**
        * Two-phased constructor.
        *
        * @since 2.0
        *
        * @param aImageID Item ID of the first background bitmap.
        *
        * @param aRect Rectangle where the first bitmap should be laid out.
        *
        * @param aParentAbsolute ETrue if parent absolute layout should be
        *   used, EFalse otherwise. If a parent absolute layout is used,
        *   the parent position must be set and updated using SetParentPos.
        *
        * @param aNumberOfLayers Total number of layers as an integer.
        *   This must be 1 or more.
        *
        * @return Newly constructed object.
        */
        IMPORT_C static CAknsLayeredBackgroundControlContext* NewL(
            const TAknsItemID& aImageID, const TRect& aRect, 
            const TBool aParentAbsolute, const TInt aNumberOfLayers );
        
        /**
        * Destructor.
        */
        virtual ~CAknsLayeredBackgroundControlContext();

    public: // New functions
        
        /**
        * Sets the item ID of the specified layer.
        *
        * @since 2.0
        *
        * @param aLayer Index of the layer, where 0 is the first one.
        *   The index must be less than aNumberOfLayers given to @c NewL().
        *
        * @param aID Item ID of the image.
        */
        IMPORT_C void SetLayerImage( const TInt aLayer, 
            const TAknsItemID& aID );

        /**
        * Sets the layout rectangle of the specified layer.
        *
        * @since 2.0
        *
        * @param aLayer Index of the layer, where 0 is the first one.
        *   The index must be less than aNumberOfLayers given to @c NewL().
        *
        * @param aRect Rectangle where the image should be laid out.
        */
        IMPORT_C void SetLayerRect( const TInt aLayer, 
            const TRect& aRect );

    public: // From MAknsControlContext

        /**
        * @copydoc MAknsControlContext::IsCompatibleWithType
        */
        TBool IsCompatibleWithType( const TAknsControlContextType aType ) const;

    protected:

        /**
        * C++ constructor.
        */
        CAknsLayeredBackgroundControlContext();

        /**
        * Symbian 2nd phase constructor.
        */
        void ConstructL( const TRect& aRect, const TBool aParentAbsolute,
            const TAknsItemID& aImageID, const TInt aNumberOfLayers );
    
    protected:  // Data
        
        /**
        * Array of layered layouts.
        */
        TAknsBackground* iLayoutArray;

        /**
        * Size of the layer array.
        */
        TInt iLayoutArraySize;

    };

#endif      // AKNSLAYEREDBACKGROUNDCONTROLCONTEXT_H
            
// End of File
