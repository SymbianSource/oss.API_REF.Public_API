/*
* Copyright (c) 2006 Nokia Corporation and/or its subsidiary(-ies). 
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
* Description:  
*
*/

#ifndef C_CMAPPLICATIONSETTINGSUI_H
#define C_CMAPPLICATIONSETTINGSUI_H

#include <e32def.h>
#include <e32base.h>

class CCmConnSettingsUiImpl;
namespace CMManager
    {
    
    /**
    * CCmApplicationSettingsUi::RunApplicationSettingsL leaves with this 
    * error code if the selection dialog would have zero elements caused 
    * by filtering out all the Connection Methods with the aFilterArray
    * and not requesting other list elements by the aListItems bitfield.
    * See the comment of the RunApplicationSettingsL method for more 
    * detailes.
    * This error code is supported by the error resolver. 
    */
    const TInt KErrConnectionNotFound = -32700;
    
    /** 
    * The selection type of a list item in application settings UI
    */
    enum TCmSettingSelectionMode
        {
        EAlwaysAsk,         /**<
                            * The user selected Always ask 
                            */
        EDestination,       /**<
                            * The user selected a destination
                            */
        EConnectionMethod,  /**<
                            * The user selected a connection method
                            */
        EDefaultConnection // The user selected Default Connection 

        };
        
    
    /** 
    * These bitmasks controls what items does the selection UI containes.
    * Bitmasks not listed in the enum are reserved for future usage and they
    * are disabled by default. So extending these bitmasks does not cause 
    * BC break later.
    */
    enum TCmSelectionDialogItems
        {
        EShowAlwaysAsk = 0x01,          /**<
                                        * AlwaysAsk is added to the 
                                        * selection UI.
                                        */                                
        EShowDefaultConnection = 0x02,  /**<
                                        * DefaultConnection is added to the 
                                        * selection UI.
                                        */           
        
        /**
        * The following enumerations controls how destinations and 
        * Connection Methods are presented in the selection UI.
        * EShowDestinations is set and EShowConnectionMethods is set:
        *   Destination list is added to the selection UI and a Connection
        *   Method can be selected inside a Destination.
        * EShowDestinations is set and EShowConnectionMethods is not set:
        *   Destination list is added to the selection UI and no Connection
        *   Method can be selected inside a Destination. 
        * EShowDestinations is not set and EShowConnectionMethods is set:
        *   Connection Method list is added to the selection UI. Connection
        *   Methods are ordered according to the global bearer type 
        *   priorities. Destination cannot be selected.
        * EShowDestinations is not set and EShowConnectionMethods is not set:
        *   The selection UI will not contain any Destination or Connection 
        *   Method. E.g. If EShowAlwaysAsk and EShowDefaultConnection was set
        *   then the selection UI will contain two entries (AlwaysAsk and 
        *   DefaultConnection).
        */
        EShowDestinations = 0x04,       /**<
                                        * Destination list is added to the 
                                        * selection UI. Destinations which
                                        * does not contain any Connection
                                        * Methods are not shown.
                                        */
        EShowConnectionMethods = 0x08,  /**<
                                        * If EShowDestinations is set:
                                        *   Connection Method can be selected
                                        *   inside a destination.
                                        * If EShowDestinations is not set:
                                        *   Connection Method list is added to 
                                        *   the selection UI.
                                        */                                  
        };    
        
    }// namespace CMManger


    // Structs
    
/**
 * Stores the details of a setting selection
 *
 *  @lib cmmanager.lib
 *  @since S60 3.2
 */
NONSHARABLE_STRUCT( TCmSettingSelection )
    {
    /**
    * Selection mode, refers to the type of the list item which is selected
    */
    CMManager::TCmSettingSelectionMode iResult;
    
    /**
    * Id of the selected destination or connection method
    */
    TUint iId;
    };

/**
* Typedef of the bearer filter array.
* This type of array is used to filter Connection Methods
* by bearer types.
*
* The array elements are bearer IDs. The IDs are defined in the bearer
* type specific cmplugin...def.h files. E.g. the ID of the CSD bearer
* type (KUidCSDBearerType) can be found in the cmplugincsddef.h header.
*/
typedef RArray<TUint32> TBearerFilterArray;

/**
 * For launching the Application Settings UI
 *
 * Displays a radio button page for an application used to select
 * a destination or connection method
 *
 *  @lib cmmanager.lib
 *  @since S60 3.2
 */
NONSHARABLE_CLASS( CCmApplicationSettingsUi ) : public CBase
    {

    public: // construction/destruction

        /** Epoc constructor */
        IMPORT_C static CCmApplicationSettingsUi* NewL();

        /** Epoc constructor 
        * Pushes the object on the cleanup stack
        */
        IMPORT_C static CCmApplicationSettingsUi* NewLC();

        /** Destructor. */
        virtual ~CCmApplicationSettingsUi();

    //=======================================================================
    // UI API
    //
    public:

        /**
        * Launches the 'easy to use' Settings UI provided for applications
        * for handling Destinations and Connection Methods.
        * This function call launches the same selection dialog as the 
        * the extended RunApplicationSettingsL do (see below) with the
        * list items Default Connection, Destinations and  Connection Methods 
        * without any filtering.
        *
        * @since 3.2
        * @param aSelection If initialised to a valid value, sets the higlight to the
        * corresponding list item at startup. If a list of Destinations is displayed, and
        * the initial highlight is set to a Connection Method, the parent Destination
        * gets highlighted. On return, holds user selection.
        * @return TBool seleceted or not.
        */
        IMPORT_C TBool RunApplicationSettingsL( 
                                        TCmSettingSelection& aSelection );

        /**
        * Launches the 'easy to use' Settings UI provided for applications
        * for handling Destinations and Connection Methods
        *
        * @since 3.2
        * @param aSelection If initialised to a valid value, sets the higlight to the
        * corresponding list item at startup. If a list of Destinations is displayed, and
        * the initial highlight is set to a Connection Method, the parent Destination
        * gets highlighted. On return, holds user selection.
        * @param aListItems A bit field which indicates which items shoud be
        *                   shown in the selection dialog. The bitmasks are 
        *                   defined in the TCmSelectionDialogItems enum.
        *
        * The function leaves with KErrNotSupported  if all the items which 
        * were set to be shown are not supported/enabled. 
        * E.g. Default Connection availability/support is controlled by the 
        * Feature Manager so if only EShowDefaultConnection is set and the 
        * Default Connection feature is not enabled than the function leaves
        * with KErrNotSupported.
        *
        * In other cases (when an item or items are not supported/enabled but
        * not all) the selected but not supported/enabled items are not added
        * to the list. The request to show such an item is silently ignored.
        *
        *
        * Special note about the EShowDestinations and EShowConnectionMethods
        * bitmasks:      
        *   The following enumerations controls how how destinations and 
        *   Connection Methods are presented in the selection UI.
        *   General rule about the EShowDestinations:
        *     Destinations which does not contain any Connection Methods are 
        *     not shown in the selection dialog. The same rule is applied if
        *     the Destination containes Connection Methods but all of them 
        *     are filtered out by the filtering criteria.
        *   EShowDestinations is set and EShowConnectionMethods is set:
        *     Destination list is added to the selection UI and a Connection
        *     Method can be selected inside a Destination.
        *   EShowDestinations is set and EShowConnectionMethods is not set:
        *     Destination list is added to the selection UI and no Connection
        *     Method can be selected inside a Destination. 
        *   EShowDestinations is not set and EShowConnectionMethods is set:
        *     Connection Method list is added to the selection UI. Connection
        *     Methods are ordered according to the global bearer type 
        *     priorities. Destination cannot be selected.
        *   EShowDestinations is not set and EShowConnectionMethods is not set:
        *     The selection UI will not contain any Destination or Connection 
        *     Method. E.g. If EShowAlwaysAsk and EShowDefaultConnection was 
        *     set then the selection UI will contain two entries (AlwaysAsk
        *     and DefaultConnection).
        *
        * @param aFilterArray Only Connection Methods with bearer types from
        *                     the aFilterArray will be shown. 
        *                     All Connection Methods will be listed if the 
        *                     array has no element.
        * @return TBool seleceted or not.
        *
        * @leave KErrArgument If the selection dialog would have zero 
        *                     elements based on the aListItems bitmask
        *                     (aListItems is equal to zero). 
        *
        * @leave KErrNotSupported 
        *                     If the selection dialog would have zero 
        *                     elements based on the aListItems bitmask
        *                     (all the selected elements in aListItems  
        *	                  are not supported/disabled).
        *                     E.g. aListItems = EShowDefaultConnection but 
        *                     Default Connection feature is not enabled.
        *
        * @leave KErrConnectionNotFound 
        *                     If the selection dialog would have zero 
        *                     elements caused by filtering out all the 
        *                     Connection Methods with the aFilterArray
        *                     and not requesting other list elements by 
        *                     the aListItems bitfield than the function 
        *                     call leaves with KErrConnectionNotFound 
        *                     error code. A corresponding error note can
        *                     be shown using the error resolver. 
        *                     E.g. 
        *                       - aListItems = EShowConnectionMethods
        *                     but all Connection Methods are filtered 
        *                     out by the aFilterArray.
        */
        IMPORT_C TBool RunApplicationSettingsL( 
                                        TCmSettingSelection& aSelection, 
                                        TUint aListItems,
                                        TBearerFilterArray& aFilterArray);

    private:

        /** C++ constructor */
        CCmApplicationSettingsUi();

        /**
        * Epoc 2nd phase constructor
        *
        * @since S60 3.2        
        */
        void ConstructL();

    private: // data

        /**
         * implementation of the class
         */
        CCmConnSettingsUiImpl* iImpl;    
    };

#endif // C_CMAPPLICATIONSETTINGSUI_H
