/*
* Copyright (c) 2002 Nokia Corporation and/or its subsidiary(-ies).
* All rights reserved.
* This component and the accompanying materials are made available
* under the terms of the License "Symbian Foundation License v1.0" to Symbian Foundation members and "Symbian Foundation End User License Agreement v1.0" to non-members
* which accompanies this distribution, and is available
* at the URL "http://www.symbianfoundation.org/legal/licencesv10.html".
*
* Initial Contributors:
* Nokia Corporation - initial contribution.
*
* Contributors:
*
* Description:  Pictograph interface instance.
*
*
*/



#ifndef AKN_PICTOGRAPH_INTERFACE_H
#define AKN_PICTOGRAPH_INTERFACE_H

// INCLUDES
#include <e32base.h>

// CONSTANTS

// FORWARD DECLARATIONS

class MAknPictographDrawer;
class MAknPictographAnimatorCallBack;
class CCoeControl;

// CLASS DECLARATION

/**
* Pictograph interface.
*
*  @lib AknPictograph.lib
*  @since 2.6
*/
NONSHARABLE_CLASS(CAknPictographInterface) : public CBase
	{
    public:  // Constructors and destructor
        
        /**
        * Returns a pictograph interface instance if pictograph feature is
        * supported.
        *
        * If pictograph feature is not supported, this method returns NULL.
        *
        * @since 2.6
        * @param aParent Not used at the moment. Reserved for future use.
        * @param aCallBack callback for drawing pictograph animations.
        */
	    IMPORT_C static CAknPictographInterface* NewL(
            CCoeControl& aParent,
            MAknPictographAnimatorCallBack& aCallBack );
        
        /**
        * Destructor.
        */
        ~CAknPictographInterface();

    public: // New functions

        inline MAknPictographDrawer* Interface() const;

    private:

        /**
        * C++ default constructor.
        */
        CAknPictographInterface(); 

        /**
        * 2nd phase constructor.
        */
        void ConstructL( MAknPictographAnimatorCallBack& aCallBack );

    private:    // Data        

        /**
        * Handle to the polymorphic pictograph DLL.
        */
        RLibrary iLib;

        /**
        * Pictograph interface instance. Owned.
        */
        MAknPictographDrawer* iInterface;

    };

#include "AknPictographInterface.inl"

#endif      // AKN_PICTOGRAPH_INTERFACE_H
            
// End of File
