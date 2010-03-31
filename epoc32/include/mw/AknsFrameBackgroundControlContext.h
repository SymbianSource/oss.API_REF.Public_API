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
*                CAknsFrameBackgroundControlContext.
*
*/


#ifndef AKNSFRAMEBACKGROUNDCONTROLCONTEXT_H
#define AKNSFRAMEBACKGROUNDCONTROLCONTEXT_H

//  INCLUDES
#include <AknsLayeredBackgroundControlContext.h>

// CLASS DECLARATION

/**
*  Implementation of a control context that provides a layout background 
*  generated from a frame item.
*
*  This is a public class with exported functions.
*  The class is not intended for derivation outside the library.
*
*  @lib AknSkins.lib
*
*  @since 2.0
*/
NONSHARABLE_CLASS(CAknsFrameBackgroundControlContext) : 
    public CAknsLayeredBackgroundControlContext
    {
    public:  // Constructors and destructor
        
        /**
        * Two-phased constructor.
        *
        * @since 2.0
        *
        * @param aFrameID Item ID of the entire frame.
        *
        * @param aOuterRect Outer rectangle of the frame.
        *
        * @param aInnerRect Inner rectangle of the frame.
        *
        * @param aParentAbsolute ETrue if parent absolute layout should be
        *   used, EFalse otherwise. If a parent absolute layout is used,
        *   the parent position must be set and updated using SetParentPos.
        *
        * @return Newly constructed object.
        */
        IMPORT_C static CAknsFrameBackgroundControlContext* NewL(
            const TAknsItemID& aFrameID, const TRect& aOuterRect, 
            const TRect& aInnerRect, const TBool aParentAbsolute );
        
        /**
        * Destructor.
        */
        virtual ~CAknsFrameBackgroundControlContext();

    public: // New functions
        
        /**
        * Reconstructs the entire frame from the given item ID.
        *
        * @since 2.0
        *
        * @param aID Item ID of the entire frame.
        */
        IMPORT_C void SetFrame( const TAknsItemID& aFrameID );

        /**
        * Sets the outer and the inner rectangles of the frame. 
        *
        * @since 2.0
        *
        * @param aOuterRect The outer rectangle of the frame.
        *
        * @param aInnerRect The inner rectangle of the frame.
        */
        IMPORT_C void SetFrameRects( const TRect& aOuterRect, 
            const TRect& aInnerRect );

        /**
        * Overrides the center part of the frame.
        *
        * @since 2.0
        *
        * @param aID Item ID of the center part to be used.
        */
        IMPORT_C void SetCenter( const TAknsItemID& aID );

        /**
        * Sets the rectangle of a single part of the frame.
        *
        * @since 2.0
        *
        * @param aRect Rectangle of the specific part of the frame.
        *
        * @param aFrameElement Element (index) of the frame element 
        *   to which the rectangle is applied.
        *
        */
        IMPORT_C void SetFramePartRect( const TRect& aRect,
            const TAknsFrameElementIndex aFrameElement );

    public: // From MAknsControlContext

        /**
        * @copydoc MAknsControlContext::IsCompatibleWithType
        */
        TBool IsCompatibleWithType( const TAknsControlContextType aType ) const;

        /**
        * Updates the control context, if necessary.
        * This method is called by the framework before drawing with the 
        * context.
        *
        * Implementation in CAknsFrameBackgroundControlContext updates the
        * items to ensure that transition between single-bitmap and 
        * multi-bitmap frames work as expected.
        *
        * @since 2.6
        *
        * @return Return value reserved for future use. Currently returns 0.
        */
        TInt UpdateContext();

    protected: // New methods

        /**
        * Updates the type-dependant parameters of the frame.
        *
        * @since 2.6
        *
        * @internal
        */
        void UpdateFrame();
        
    protected:

        /**
        * C++ constructor.
        */
        CAknsFrameBackgroundControlContext();

        /**
        * Symbian 2nd phase constructor.
        */
        void ConstructL( const TAknsItemID& aFrameID, const TRect& aOuterRect, 
            const TRect& aInnerRect, const TBool aParentAbsolute );

    protected: // Data
        TAknsItemID iFrameID;
        TAknsItemID iCenterID;

        TRect iInnerRect;
        TRect iOuterRect;

        TBool iSingleElementFrame;

    };

#endif      // AKNSFRAMEBACKGROUNDCONTROLCONTEXT_H
            
// End of File
