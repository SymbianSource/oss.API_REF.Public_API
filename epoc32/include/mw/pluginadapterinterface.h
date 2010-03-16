/*
* Copyright (c) 2006 Nokia Corporation and/or its subsidiary(-ies).
* All rights reserved.
* This component and the accompanying materials are made available
* under the terms of the License "Eclipse Public License v1.0"
* which accompanies this distribution, and is available
* at the URL "http://www.eclipse.org/legal/epl-v10.html".
*
* Initial Contributors:
* Nokia Corporation - initial contribution.
*
* Contributors:
*
* Description:  The plug-in can use this interface to communicate with the browser.
*
*/


#ifndef MPLUGINADAPTER_H
#define MPLUGINADAPTER_H

//  INCLUDES
#include "coecntrl.h"
#include "coecobs.h"
#include "npupp.h"

// FORWARD DECLARATIONS
class MPluginNotifier;


class MOptionMenuHandler;
class CEikMenuPane;

// CLASS DECLARATION

/**
*  The plug-in can use this interface to communicate with the browser.
*
*  @lib PluginAdapterUtil in Series 80 Platforms and the Nokia 7710 smartphone
*  @since Series 60 2nd Edition, Feature Pack 2 and Series 80 Platforms and the Nokia 7710 smartphone
*/
class MPluginAdapter
    {
    public: // New functions
        
        /**
        * Gets the pointer to the minor version number of the plug-in version number of the Browser Plug-in API.
        * @since Series 60 2nd Edition, Feature Pack 2 and Series 80 Platforms and the Nokia 7710 smartphone
        * @return Series 60 returns 1. Series 80 and the Nokia 7710 smartphone return 101.
        */
    virtual TUint16 GetVersion()=0;

        /**
        * Called when the plug-in has completed its creation.
        * This function is called from the constructL function of the plug-in.
        * @since Series 60 2nd Edition, Feature Pack 2 and Series 80 Platforms and the Nokia 7710 smartphone
        * @param aPluginControl A pointer to the plug-in control window
        * @return None
        */
    virtual void PluginConstructedL(CCoeControl* aPluginControl)=0;

        /**
        * Called after the plug-in has been deleted.
        * This function is called from the destructor of the plug-in.
        * @since Series 60 2nd Edition, Feature Pack 2 and Series 80 Platforms and the Nokia 7710 smartphone
        * @return None
        */
    virtual void PluginFinishedL()=0;

        /**
        * Returns the window system level control object for the plug-in.
        * @since Series 60 2nd Edition, Feature Pack 2 and Series 80 Platforms and the Nokia 7710 smartphone
        * @return A pointer to the parent control window.
        */
    virtual CCoeControl* GetParentControl()=0;

        /**
        * Returns the observer for the plug-in control.
        * @since Series 60 2nd Edition, Feature Pack 2 and Series 80 Platforms and the Nokia 7710 smartphone
        * @return Observer that the plug-in can use to send events to the browser.
        */
    virtual MCoeControlObserver* GetParentControlObserver()=0;

        /**
        * Sets the plug-in notifier allowing the plug-in to control portions of the browser.
        * @since Series 60 2nd Edition, Feature Pack 2 and Series 80 Platforms and the Nokia 7710 smartphone
        * @param aNotifier Pointer to an interface that the browser can use to send events to the plug-in.
        * @return None
        */
    virtual void SetPluginNotifier(MPluginNotifier *aNotifier)=0;
        

        /**
        * Sets the plug-in option menu handler allowing the plug-in to handle the custom menu commands
        * from the browser.
        * @since Series 60 3nd Edition
        * @param aOptionMenuHandler Pointer to an interface that the browser can use to send option menu
        * commands to the plug-in.
        * @return None
        */
    virtual void SetOptionMenuHandler(MOptionMenuHandler* /*aOptionMenuHandler*/) {};
    };


/**
*  Contains notification ability for plug-ins.
*  These methods are implemented in the plugin.
*
*  @lib
*  @since Series 60 2nd Edition, Feature Pack 2 and Series 80 Platforms and the Nokia 7710 smartphone
*/
class MPluginNotifier
    {
    public:     // Data
        // Types of notifications which can be passed to the plugin.
    enum TNotificationType {
       EEditCut,
       EEditCopy, 
       EEditPaste, 
       EEditDelete, 
       EApplicationFocusChanged, 
       ESystemNotification,
       EPluginInvisible,
       EPluginActivated,
       EPluginDeactivated,
       EMenuOptionEnableDecider,
       EPluginPause
    };


    public: // New functions
        
        /**
        * Notifies the plugin of an event.
        * @since Series 60 2nd Edition, Feature Pack 2 and Series 80 Platforms and the Nokia 7710 smartphone
        * @param aCallType The event type that is passed to the plug-in
        * @param aParam The parameter associated with the event
        * @return Not used
        */
    virtual TInt NotifyL (TNotificationType aCallType, TAny *aParam)=0;

    };


/**
*  Contains the ability for plug-ins to handle the menu option commands.
*  These methods are implemented in the plugin.
*
*  @lib
*  @since Series 60 3rd Edition
*/
class MOptionMenuHandler
    {
    public: // New functions
        
        /**
        * AddPluginOptionMenuItemsL
        * Add the Option Menu items to the menuPane, these will be handled by plugin.
        *
        * @since 3.1
        * @param aMenuPane handle of the menu that will contain the options 
        * @param aCommandBase base id that needs to be added to the command ID 
        * @param aAfter Plugin options should be added after this index
        * @return void
        */
    virtual void AddPluginOptionMenuItemsL(CEikMenuPane& aMenuPane, TInt aCommandBase, TInt aAfter)=0;
    
        /**
        * HandlePluginCommandL
        * Handle the user command from the option menu to the plugin.
        *
        * @since 3.1
        * @param aCommandId the command ID of the option
        * @return void
        */
    virtual void HandlePluginCommandL(TInt aCommandId)=0;

    };

#endif      // MPLUGINADAPTER_H   

            
// End of File
