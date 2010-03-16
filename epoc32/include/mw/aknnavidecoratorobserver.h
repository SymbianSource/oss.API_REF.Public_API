/*
* Copyright (c) 2005 Nokia Corporation and/or its subsidiary(-ies).
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
* Description: 
*     Interface class for navi decorator. This observer is used
*     by observers to get right or left arrow events of navipane
*     PointerEvents for arrow decorators are handled in Navigation 
*     decorator class.
*
*
*
*/


#ifndef AKNNAVIDECORATOROBSERVER_H
#define AKNNAVIDECORATOROBSERVER_H

#include <e32base.h>

class MAknNaviDecoratorObserver
    {
public:
    enum TAknNaviDecoratorEvents
        {
        /** Pointer tap event id for right arrow */
        EAknNaviDecoratorEventRightTabArrow,
        /** Pointer tap event id for left arrow */
        EAknNaviDecoratorEventLeftTabArrow,
        /** Pointer tap event id for navilabel */
        EAknNaviDecoratorEventNaviLabel
        }; 
        
public:

   	/**
     * Method for handling events in observed classes. 
     * 
     * @param aEventID Id of the event.
     *
     */
    virtual void HandleNaviDecoratorEventL( TInt aEventID ) = 0; 
    };

#endif // AKNNAVIDECORATOROBSERVER_H
