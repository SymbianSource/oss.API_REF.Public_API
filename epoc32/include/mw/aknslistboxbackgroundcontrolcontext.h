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
*                CAknsListBoxBackgroundControlContext.
*
*/


#ifndef AKNSLISTBOXBACKGROUNDCONTROLCONTEXT_H
#define AKNSLISTBOXBACKGROUNDCONTROLCONTEXT_H

//  INCLUDES
#include <AknsBasicBackgroundControlContext.h>

// CLASS DECLARATION

/**
*  Implementation of a control context that provides a layout background with
*  a background bitmap, its layout rectangle, a secondary bitmap that will
*  be tiled in its own layout rectangle and third bitmap for the bottom part
*  with its layout rectangle.
*
*  This is a public class with exported functions.
*  The class is not intended for derivation outside the library.
*
*  @lib AknSkins.lib
*
*  @since 2.0
*/
NONSHARABLE_CLASS(CAknsListBoxBackgroundControlContext) : 
    public CAknsBasicBackgroundControlContext
    {
    public:  // Constructors and destructor
        
        /**
        * Two-phased constructor.
        *
        * @since 2.0
        *
        * @param aImageID Item ID of the background bitmap.
        *
        * @param aRect Rectangle where the bitmap should be laid out.
        *
        * @param aParentAbsolute ETrue if parent absolute layout should be
        *   used, EFalse otherwise. If a parent absolute layout is used,
        *   the parent position must be set and updated using SetParentPos.
        *
        * @param aTiledBitmapID Item ID of the second bitmap that will
        *   be tiled in another layout rectangle.
        *
        * @param aTiledRect Rectangle where the second bitmap should be
        *   tiled to.
        *
        * @return Newly constructed object.
        */
        IMPORT_C static CAknsListBoxBackgroundControlContext* NewL(
            const TAknsItemID& aImageID, const TRect& aRect, 
            const TBool aParentAbsolute, const TAknsItemID& aTiledBitmapID,
            const TRect& aTiledRect );
        
        /**
        * Destructor.
        */
        virtual ~CAknsListBoxBackgroundControlContext();

    public: // New functions
        
        /**
        * Sets the item ID of the tiled bitmap.
        *
        * @since 2.0
        *
        * @param aID Item ID of the bitmap.
        */
        IMPORT_C void SetTiledBitmap( const TAknsItemID& aID );

        /**
        * Sets the layout rectangle of the tiled bitmap.
        *
        * @since 2.0
        *
        * @param aRect Rectangle where the bitmap should be laid out.
        */
        IMPORT_C void SetTiledRect( const TRect& aRect );

        /**
        * Sets the item ID of the bottom part bitmap.
        *
        * @since 2.0
        *
        * @param aID Item ID of the bitmap.
        */
        IMPORT_C void SetBottomBitmap( const TAknsItemID& aID );

        /**
        * Sets the layout rectangle of the bottom part bitmap.
        *
        * @since 2.0
        *
        * @param aRect Rectangle where the bitmap should be laid out.
        */
        IMPORT_C void SetBottomRect( const TRect& aRect );

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
        * Implementation in CAknsListBoxBackgroundControlContext 
        * disables any non-existing levels.
        *
        * @since 2.8
        *
        * @return Return value reserved for future use. Currently returns 0.
        */
        TInt UpdateContext();
        
    protected:

        /**
        * C++ constructor.
        */
        CAknsListBoxBackgroundControlContext();

        /**
        * Symbian 2nd phase constructor.
        */
        void ConstructL( const TRect& aRect, const TBool aParentAbsolute,
            const TAknsItemID& aImageID,
            const TAknsItemID& aTiledBitmapID, const TRect& aTiledRect );
    
    protected:  // Data
        
        /**
        * Structure for tiled layout.
        */
        TAknsBackground* iTiledLayout;

        /**
        * Structure for bottom part layout.
        */
        TAknsBackground* iBottomLayout;

    };

#endif      // AKNSLISTBOXBACKGROUNDCONTROLCONTEXT_H
            
// End of File
