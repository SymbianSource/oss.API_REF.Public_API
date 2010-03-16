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
* Description:   CFbsBitmap change observer
*
*/


#ifndef AKN_ICON_OBSERVER_H
#define AKN_ICON_OBSERVER_H

// INCLUDES

// CONSTANTS

// FORWARD DECLARATIONS
class CFbsBitmap;

// FUNCTION PROTOTYPES


// CLASS DECLARATION

/**
* MAknIconObserver.
*/
class MAknIconObserver
    {
public:

    /**
    * This is an abstract class for specifying an interface for 
    * receiving notifications when an icon's frame buffer has been updated.
    * An object of derived class implementing this interface should be registered
    * for a given icon to the AknIcon framework using 
    * function AknIconUtils::SetObserver().
    * 
    * AknIcon framework calls this function whenever the frame buffer of the observed icon
    * changes. This observer mechanism is mainly useful in animated icons cases.
    * The observer e.g. can redraw the icon on the screen when the frame of the animated 
    * icon has changed.
    *
    * @since 2.8
    * @param aBitmap bitmap or mask of the icon
    */
    virtual void BitmapChanged(CFbsBitmap *aBitmap)=0;
    };
    
/*
*
* This class is internal and not intended for use.
*
*/
class MAknIconChangeObserver
    {
public:
    virtual void BitmapChanged()=0;
    };
    
#endif // AKN_ICON_OBSERVER_H

// End of File
