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
* Description: 
*     Declares the main handler, CApSettingsHandler and public API for the 
*     Access Point settings.
*
*/


#ifndef APSETTINGS_HANDLER_H
#define APSETTINGS_HANDLER_H

// Deprecation warning
#warning This header file has been deprecated. Will be removed in one of the next SDK releases.
 
 
// INCLUDES
#include <ApSettingsHandlerCommons.h>
#include <ApEngineConsts.h>
#include <ApSelect.h>

// CONSTANTS
const   TUid    KUidApSettingsHandler = { 0x10008d3B };

typedef struct      ///< Extra data holder
    {
        TInt                iResOffset;
        TBool               iIsIpv6Supported;       // Default is NO 
        TBool               iIsFeatureManagerInitialised;
        TInt                iExtra;
        TInt                iSortType;
        TVpnFilterType      iVpnFilterType;
        TInt                iVariant;               /// Local variant value
        TBool               iIncludeEasyWlan;
    }TApSetHandlerExtra;

// FORWARD DECLARATIONS
class CActiveApDb;
class CApSelector;
class CApSettingsModel;
class CApSettings;
class CTextOverrides;
class CApAccessPointItem;

class CApSettingsHandlerImpl;

// CLASS DECLARATION
/**
* CApSettingsHandler class: It is the main handler for the Access Point 
* settings. It contains the only public API for other (sub)systems.
*
*/
class CApSettingsHandler : public CBase
    {

    public: // Constructors and destructor


        /**
        * Two-phased constructor. Leaves on failure.
        * This function shall be used to create the access point 
        * settings/selection handling UI object. It is customizable through 
        * the parameters. This object is a small layer above the UI part and
        * it provides a standard interface to select, edit, create access 
        * points. It has two main parts, Select and Edit. The first parameter,
        * aStartWithSelection gives whether we would like to select or edit.
        * In case of selection, there is the possibility to use this module in
        * many applications. For this, two layouts are implemented, 
        * one is list pane used by General Settings which provides the list in
        * a list-pane. The other layout is for the other applications 
        * requiring access point selection, a popup-list style as the decision
        * I know about was that General Settings will use list-pane and all
        * other apps. popup-list style. It is the caller who selects the style
        * so if spec. says otherwise, this module still can be used.
        * It is also possible to start the UI without selection, so if any 
        * module has a 'linked/default/etc.' access point and stored it's UID,
        * the module can simply call the editor part of the UI without having
        * to select the AP once more. In case of editing only, 
        * (aStartWithSelection is EFalse), all other construction parameters 
        * are ignored and after construction caller can simply call 
        * RunSettingsL(..). In case of selection, a lot of other parameters 
        * can be specified to fulfil all requirements. There are three types 
        * of Options menu available: 
        * EApSettingsSelMenuNormal, 
        * EApSettingsSelMenuSelectOnly,
        * EApSettingsSelMenuSelectNormal.
        * <br>
        *-EApSettingsSelMenuSelectOnly: Only Select is visible, 
        *                               no way to edit, delete, create, etc.
        * <br>
        * -EApSettingsSelMenuNormal:    Options menu specified in General 
        *                               Settings, contains Edit, Delete, 
        *                               Create new, etc. menu items.
        * <br>
        * -EApSettingsSelMenuSelectNormal: Same as in EApSettingsSelMenuNormal
        *                                BUT the first item is Select. 
        *                                This one makes it possible to select 
        *                                an access point and also possible to 
        *                                edit, create, delete, etc.
        * <br>
        * The following three parameters specify the filtering and ordering 
        * criteria for the selection list creation. First, it is possible to
        * specify which ISP-type we are looking for. The possible values are:
        * <br>
        * KEApIspTypeInternetOnly:  Filter allows only access points that are
        *                           capable of only internet access.
        * <br>
        * KEApIspTypeWAPOnly:       Filter allows only access points that are 
        *                           capable of only WAP access.
        * <br>
        * KEApIspTypeInternetAndWAP: Filter allows only access points that are
        *                           capable of internet AND WAP access.
        * <br>
        * KEApIspTypeWAPMandatory:  Filter allows only access points that are
        *                           capable of WAP access AND contain 
        *                           mandatory WAP settings.
        * <br>
        * KEApIspTypeAll:           No filtering is done for the isp-type,
        *                           all types of access points are shown.
        * <br>
        * It is possible to combine them by simply adding/or-ing together 
        * the values, filtering will be done in such a way that only access 
        * points with the listed ISP-types will be shown. Second filtering
        * possibility (aBearerFilter) is the desired bearer type. The possible
        * values are the values of the TApBearerType enum type and their 
        * combinations, as in case of the ISP type. The ordering of the list
        * can be specified with the aSortType parameter. It can have the
        * following values:
        * KEApSortUidAscending:     The sorting is done according to the ID 
        *                           of the access points in ascending order.
        * KEApSortUidDescending:    The sorting is done according to the ID 
        *                           of the access points in descending order.
        * KEApSortNameAscending:    The sorting is done according to the name
        *                           of the access points in ascending order.
        * KEApSortNameDescending:   The sorting is done according to the name
        *                           of the access points in descending order.
        * Caution! The ordering values can not be combined!
        * @param aStartWithSelection    A boolean value indicating whether to 
        *                               select or edit an ap.
        * @param aListType      A TSelectionListType enum indicating the 
        *                       desired list type.
        * @param aSelMenuType   A TSelectionMenuType enum indicating the 
        *                       desired menu type.
        * @param aIspTypeFilter Filtering criteria on ISP type
        * @param aBearerFilter Filtering criteria on bearer type
        * @param aSortType Specifies the sort order to use.
        * @return The constructed CApSettingsHandler object.
        *
        * @deprecated
        */
        IMPORT_C static CApSettingsHandler* NewLC(
                        TBool aStartWithSelection,
                        TSelectionListType aListType,
                        TSelectionMenuType aSelMenuType,
                        TInt aIspFilter,
                        TInt aBearerFilter,
                        TInt aSortType
                        );



        /**
        * Two-phased constructor. Leaves on failure.
        * This function shall be used to create the access point 
        * settings/selection handling UI object. It is customizable through 
        * the parameters. This object is a small layer above the UI part and
        * it provides a standard interface to select, edit, create 
        * access points. It has two main parts, Select and Edit. The first 
        * parameter, aStartWithSelection gives whether we would like to select
        * or edit. In case of selection, there is the possibility to use this 
        * module in many applications. For this, two layouts are implemented,
        * one is list pane used by General Settings which provides the list 
        * in a list-pane. The other layout is for the other applications 
        * requiring access point selection, a popup-list style as the 
        * decision I know about was that General Settings will use list-pane 
        * and all other apps. popup-list style. It is the caller who selects 
        * the style so if spec. says otherwise, this module still can be used.
        * It is also possible to start the UI without selection, so if any 
        * module has a 'linked/default/etc.' access point and stored it's UID,
        * the module can simply call the editor part of the UI without having
        * to select the AP once more.
        * In case of editing only, (aStartWithSelection is EFalse), all other 
        * construction parameters are ignored and after construction caller 
        * can simply call RunSettingsL(..).
        * In case of selection, a lot of other parameters can be specified 
        * to fulfil all requirements. There are three types of Options menu 
        * available: 
        * EApSettingsSelMenuNormal, 
        * EApSettingsSelMenuSelectOnly,
        * EApSettingsSelMenuSelectNormal.
        * <br>
        *-EApSettingsSelMenuSelectOnly:     Only Select is visible, no way to
        *                                   edit, delete, create, etc.
        * <br>
        * -EApSettingsSelMenuNormal:        Options menu specified in General 
        *                                   Settings, contains Edit, Delete, 
        *                                   Create new, etc. menu items.
        * <br>
        * -EApSettingsSelMenuSelectNormal:  Same as in EApSettingsSelMenuNormal
        *                                   BUT the first item is Select. 
        *                                   This one makes it possible to 
        *                                   select an access point and also 
        *                                   possible to edit, create, 
        *                                   delete, etc.
        * <br>
        * The following three parameters specify the filtering and ordering 
        * criteria for the selection list creation. First, it is possible to 
        * specify which ISP-type we are looking for. The possible values are:
        * <br>
        * KEApIspTypeInternetOnly:      Filter allows only access points that
        *                               are capable of only internet access.
        * <br>
        * KEApIspTypeWAPOnly:           Filter allows only access points that 
        *                               are capable of only WAP access.
        * <br>
        * KEApIspTypeInternetAndWAP:    Filter allows only access points that
        *                               are capable of internet AND WAP access.
        * <br>
        * KEApIspTypeWAPMandatory:      Filter allows only access points that
        *                               are capable of WAP access AND contain
        *                               mandatory WAP settings.
        * <br>
        * KEApIspTypeAll:               No filtering is done for the isp-type,
        *                               all types of access points are shown.
        * <br>
        * It is possible to combine them by simply adding/or-ing together the
        * values, filtering will be done in such a way that only access points
        * with the listed ISP-types will be shown.
        * Second filtering possibility (aBearerFilter) is the desired bearer 
        * type. The possible values are the values of the TApBearerType enum 
        * type and their combinations, as in case of the ISP type.
        * The ordering of the list can be specified with the aSortType 
        * parameter. It can have the following values:
        * KEApSortUidAscending:     The sorting is done according to the ID
        *                           of the access points in ascending order.
        * KEApSortUidDescending:    The sorting is done according to the ID 
        *                           of the access points in descending order.
        * KEApSortNameAscending:    The sorting is done according to the name 
        *                           of the access points in ascending order.
        * KEApSortNameDescending:   The sorting is done according to the name
        *                           of the access points in descending order.
        * Caution! The ordering values can not be combined!
        * @param aDb A database to work on
        * @param aStartWithSelection A boolean value indicating whether to 
        * select or edit an ap.
        * @param aListType A TSelectionListType enum indicating the desired
        * list type.
        * @param aSelMenuType A TSelectionMenuType enum indicating the desired
        * menu type.
        * @param aIspTypeFilter Filtering criteria on ISP type
        * @param aBearerFilter Filtering criteria on bearer type
        * @param aSortType Specifies the sort order to use.
        * @return The constructed CApSettingsHandler object.
        *
        * @deprecated
        */
        IMPORT_C static CApSettingsHandler* NewLC(
                        CActiveApDb& aDb,
                        TBool aStartWithSelection,
                        TSelectionListType aListType,
                        TSelectionMenuType aSelMenuType,
                        TInt aIspFilter,
                        TInt aBearerFilter,
                        TInt aSortType
                        );








        /**
        * Two-phased constructor. Leaves on failure.
        * This function shall be used to create the access point 
        * settings/selection handling UI object.It is customizable through the
        * parameters. This object is a small layer above the UI part and
        * it provides a standard interface to select, edit, create access 
        * points. It has two main parts, Select and Edit. The first parameter, 
        * aStartWithSelection gives whether we would like to select or edit.
        * In case of selection, there is the possibility to use this module in
        * many applications. For this, two layouts are implemented, one is 
        * list pane used by General Settings which provides the list in a 
        * list-pane. The other layout is for the other applications requiring 
        * access point selection, a popup-list style as the decision was that 
        * General Settings will use list-pane and all other apps. popup-list 
        * style. It is the caller who selects the style so if spec. says 
        * otherwise, this module still can be used.
        * It is also possible to start the UI without selection, so if any 
        * module has a 'linked/default/etc.' access point and stored it's UID,
        * the module can simply call the editor part of the UI without having
        * to select the AP once more.
        * In case of editing only, (aStartWithSelection is EFalse), all other 
        * construction parameters are ignored and after construction caller 
        * can simply call RunSettingsL(..).
        * In case of selection, a lot of other parameters can be specified to
        * fulfil all requirements. There are three types of Options menu 
        * available: EApSettingsSelMenuNormal, EApSettingsSelMenuSelectOnly,
        * EApSettingsSelMenuSelectNormal.
        * <br>
        *-EApSettingsSelMenuSelectOnly: Only Select is visible, no way to edit,
        *   delete, create, etc.
        * <br>
        * -EApSettingsSelMenuNormal:Options menu specified in General Settings,
        *   contains Edit, Delete, Create new, etc. menu items.
        * <br>
        * -EApSettingsSelMenuSelectNormal: Same as in EApSettingsSelMenuNormal 
        *   BUT the first item is Select. This one makes it possible to select 
        *   an access point and also possible to edit, create, delete, etc.
        * <br>
        * The following three parameters specify the filtering and ordering 
        * criteria for the selection list creation. First, it is possible to 
        * specify which ISP-type we are looking for. The possible values are:
        * <br>
        * KEApIspTypeInternetOnly: Filter allows only access points that are 
        *   capable of only internet access.
        * <br>
        * KEApIspTypeWAPOnly: Filter allows only access points that are 
        *   capable of only WAP access.
        * <br>
        * KEApIspTypeInternetAndWAP: Filter allows only access points that are 
        *   capable of internet AND WAP access.
        * <br>
        * KEApIspTypeWAPMandatory: Filter allows only access points that are 
        *   capable of WAP access AND contain mandatory WAP settings.
        * <br>
        * KEApIspTypeAll: No filtering is done for the isp-type, all types of
        *   access points are shown.
        * <br>
        * It is possible to combine them by simply adding/or-ing together the 
        * values, filtering will be done in such a way that only access points 
        * with the listed ISP-types will be shown.
        * Second filtering possibility (aBearerFilter) is the desired bearer 
        * type. The possible values are the values of the TApBearerType enum 
        * type and their combinations, as in case of the ISP type.
        * The ordering of the list can be specified with the aSortType 
        * parameter. It can have the following values:
        * KEApSortUidAscending: The sorting is done according to the ID of 
        *   the access points in ascending order.
        * KEApSortUidDescending: The sorting is done according to the ID of 
        *   the access points in descending order.
        * KEApSortNameAscending: The sorting is done according to the name of 
        *   the access points in ascending order.
        * KEApSortNameDescending: The sorting is done according to the name of 
        *   the access points in descending order.
        * Caution! The ordering values can not be combined!
        * @param aStartWithSelection A boolean value indicating whether to 
        *   select or edit an ap.
        * @param aListType A TSelectionListType enum indicating the desired
        *   list type.
        * @param aSelMenuType A TSelectionMenuType enum indicating the desired
        *   menu type.
        * @param aIspTypeFilter Filtering criteria on ISP type
        * @param aBearerFilter Filtering criteria on bearer type
        * @param aSortType Specifies the sort order to use.
        * @param aReqIpvType Specifies whether the caller would like to 
        *   have IPv4, IPv6 or both access points. If it is IPv6 or Both, 
        *   in case of IPv6 support is available as a feature, it will be 
        *   supported. If IPv6 feature is not supported by the phone, it 
        *   simply defaults to the normal IPv4 version.
        *   If it is IPv4, it uses the default IPv4 version independently 
        *   from IPv6 feature beeing available or not.
        * @return The constructed CApSettingsHandler object.
        *
        * @deprecated
        */
        IMPORT_C static CApSettingsHandler* NewLC(
                        TBool aStartWithSelection,
                        TSelectionListType aListType,
                        TSelectionMenuType aSelMenuType,
                        TInt aIspFilter,
                        TInt aBearerFilter,
                        TInt aSortType,
                        TInt aReqIpvType
                        );



        /**
        * Two-phased constructor. Leaves on failure.
        * This function shall be used to create the access point 
        * settings/selection handling UI object. It is customizable through 
        * the parameters. This object is a small layer above the UI part and
        * it provides a standard interface to select, edit, create access 
        * points. It has two main parts, Select and Edit. The first parameter,
        * aStartWithSelection gives whether we would like to select or edit.
        * In case of selection, there is the possibility to use this module in
        * many applications. For this, two layouts are implemented, one is list
        * pane used by General Settings which provides the list in a list-pane.
        * The other layout is for the other applications requiring access point
        * selection, a popup-list style as the decision was that General 
        * Settings will use list-pane and all other apps. popup-list style. 
        * It is the caller who selects the style so if spec. says otherwise,
        * this module still can be used. It is also possible to start the UI 
        * without selection, so if any module has a 'linked/default/etc.'
        * access point and stored it's UID, the module can simply call the 
        * editor part of the UI without having to select the AP once more.
        * In case of editing only, (aStartWithSelection is EFalse), all other 
        * construction parameters are ignored and after construction caller can
        * simply call RunSettingsL(..). In case of selection, a lot of other
        * parameters can be specified to fulfil all requirements. There are 
        * three types of Options menu available: EApSettingsSelMenuNormal, 
        * EApSettingsSelMenuSelectOnly, EApSettingsSelMenuSelectNormal.
        * <br>
        *-EApSettingsSelMenuSelectOnly: Only Select is visible, no way to edit,
        *   delete, create, etc.
        * <br>
        * -EApSettingsSelMenuNormal:Options menu specified in General Settings,
        *   contains Edit, Delete, Create new, etc. menu items.
        * <br>
        * -EApSettingsSelMenuSelectNormal: Same as in EApSettingsSelMenuNormal 
        *   BUT the first item is Select. This one makes it possible to select
        *   an access point and also possible to edit, create, delete, etc.
        * <br>
        * The following three parameters specify the filtering and ordering
        * criteria for the selection list creation. First, it is possible to 
        * specify which ISP-type we are looking for. The possible values are:
        * <br>
        * KEApIspTypeInternetOnly: Filter allows only access points that are 
        *   capable of only internet access.
        * <br>
        * KEApIspTypeWAPOnly: Filter allows only access points that are 
        *   capable of only WAP access.
        * <br>
        * KEApIspTypeInternetAndWAP: Filter allows only access points that are 
        *   capable of internet AND WAP access.
        * <br>
        * KEApIspTypeWAPMandatory: Filter allows only access points that are 
        *   capable of WAP access AND contain mandatory WAP settings.
        * <br>
        * KEApIspTypeAll: No filtering is done for the isp-type, all types of
        *   access points are shown.
        * <br>
        * It is possible to combine them by simply adding/or-ing together the
        * values, filtering will be done in such a way that only access points
        * with the listed ISP-types will be shown. Second filtering possibility
        * (aBearerFilter) is the desired bearer type. The possible values are 
        * the values of the TApBearerType enum type and their combinations, as
        * in case of the ISP type. The ordering of the list can be specified 
        * with the aSortType parameter. It can have the following values:
        * KEApSortUidAscending: The sorting is done according to the ID of 
        *   the access points in ascending order.
        * KEApSortUidDescending: The sorting is done according to the ID of 
        *   the access points in descending order.
        * KEApSortNameAscending: The sorting is done according to the name of
        *   the access points in ascending order.
        * KEApSortNameDescending: The sorting is done according to the name of
        *   the access points in descending order.
        * Caution! The ordering values can not be combined!
        * @param aDb A database to work on
        * @param aStartWithSelection A boolean value indicating whether to 
        *   select or edit an ap.
        * @param aListType A TSelectionListType enum indicating the desired
        *   list type.
        * @param aSelMenuType A TSelectionMenuType enum indicating the desired
        *   menu type.
        * @param aIspTypeFilter Filtering criteria on ISP type
        * @param aBearerFilter Filtering criteria on bearer type
        * @param aSortType Specifies the sort order to use.
        * @param aReqIpvType Specifies whether the caller would like to 
        *   have IPv4, IPv6 or both access points. If it is IPv6 or Both, 
        *   in case of IPv6 support is available as a feature, it will be 
        *   supported. If IPv6 feature is not supported by the phone, it 
        *   simply defaults to the normal IPv4 version.
        *   If it is IPv4, it uses the default IPv4 version independently 
        *   from IPv6 feature beeing available or not.
        * @return The constructed CApSettingsHandler object.
        *
        * @deprecated
        */
        IMPORT_C static CApSettingsHandler* NewLC(
                        CActiveApDb& aDb,
                        TBool aStartWithSelection,
                        TSelectionListType aListType,
                        TSelectionMenuType aSelMenuType,
                        TInt aIspFilter,
                        TInt aBearerFilter,
                        TInt aSortType,
                        TInt aReqIpvType
                        );




        /**
        * Two-phased constructor. Leaves on failure.
        * This function shall be used to create the access point 
        * settings/selection handling UI object.It is customizable through the
        * parameters. This object is a small layer above the UI part and
        * it provides a standard interface to select, edit, create access 
        * points. It has two main parts, Select and Edit. The first parameter, 
        * aStartWithSelection gives whether we would like to select or edit.
        * In case of selection, there is the possibility to use this module in
        * many applications. For this, two layouts are implemented, one is 
        * list pane used by General Settings which provides the list in a 
        * list-pane. The other layout is for the other applications requiring 
        * access point selection, a popup-list style as the decision was that 
        * General Settings will use list-pane and all other apps. popup-list 
        * style. It is the caller who selects the style so if spec. says 
        * otherwise, this module still can be used.
        * It is also possible to start the UI without selection, so if any 
        * module has a 'linked/default/etc.' access point and stored it's UID,
        * the module can simply call the editor part of the UI without having
        * to select the AP once more.
        * In case of editing only, (aStartWithSelection is EFalse), all other 
        * construction parameters are ignored and after construction caller 
        * can simply call RunSettingsL(..).
        * In case of selection, a lot of other parameters can be specified to
        * fulfil all requirements. There are three types of Options menu 
        * available: EApSettingsSelMenuNormal, EApSettingsSelMenuSelectOnly,
        * EApSettingsSelMenuSelectNormal.
        * <br>
        *-EApSettingsSelMenuSelectOnly: Only Select is visible, no way to edit,
        *   delete, create, etc.
        * <br>
        * -EApSettingsSelMenuNormal:Options menu specified in General Settings,
        *   contains Edit, Delete, Create new, etc. menu items.
        * <br>
        * -EApSettingsSelMenuSelectNormal: Same as in EApSettingsSelMenuNormal 
        *   BUT the first item is Select. This one makes it possible to select 
        *   an access point and also possible to edit, create, delete, etc.
        * <br>
        * The following three parameters specify the filtering and ordering 
        * criteria for the selection list creation. First, it is possible to 
        * specify which ISP-type we are looking for. The possible values are:
        * <br>
        * KEApIspTypeInternetOnly: Filter allows only access points that are 
        *   capable of only internet access.
        * <br>
        * KEApIspTypeWAPOnly: Filter allows only access points that are 
        *   capable of only WAP access.
        * <br>
        * KEApIspTypeInternetAndWAP: Filter allows only access points that are 
        *   capable of internet AND WAP access.
        * <br>
        * KEApIspTypeWAPMandatory: Filter allows only access points that are 
        *   capable of WAP access AND contain mandatory WAP settings.
        * <br>
        * KEApIspTypeAll: No filtering is done for the isp-type, all types of
        *   access points are shown.
        * <br>
        * It is possible to combine them by simply adding/or-ing together the 
        * values, filtering will be done in such a way that only access points 
        * with the listed ISP-types will be shown.
        * Second filtering possibility (aBearerFilter) is the desired bearer 
        * type. The possible values are the values of the TApBearerType enum 
        * type and their combinations, as in case of the ISP type.
        * The ordering of the list can be specified with the aSortType 
        * parameter. It can have the following values:
        * KEApSortUidAscending: The sorting is done according to the ID of 
        *   the access points in ascending order.
        * KEApSortUidDescending: The sorting is done according to the ID of 
        *   the access points in descending order.
        * KEApSortNameAscending: The sorting is done according to the name of 
        *   the access points in ascending order.
        * KEApSortNameDescending: The sorting is done according to the name of 
        *   the access points in descending order.
        * Caution! The ordering values can not be combined!
        * @param aStartWithSelection A boolean value indicating whether to 
        *   select or edit an ap.
        * @param aListType A TSelectionListType enum indicating the desired
        *   list type.
        * @param aSelMenuType A TSelectionMenuType enum indicating the desired
        *   menu type.
        * @param aIspTypeFilter Filtering criteria on ISP type
        * @param aBearerFilter Filtering criteria on bearer type
        * @param aSortType Specifies the sort order to use.
        * @param aReqIpvType Specifies whether the caller would like to 
        *   have IPv4, IPv6 or both access points. If it is IPv6 or Both, 
        *   in case of IPv6 support is available as a feature, it will be 
        *   supported. If IPv6 feature is not supported by the phone, it 
        *   simply defaults to the normal IPv4 version.
        *   If it is IPv4, it uses the default IPv4 version independently 
        *   from IPv6 feature beeing available or not.
        * @param aVpnFilterType a TVpnFilterType representing the possible 
        *   additional VPN filtering.
        * @return The constructed CApSettingsHandler object.
        *
        * @deprecated
        */
        IMPORT_C static CApSettingsHandler* NewLC(
                        TBool aStartWithSelection,
                        TSelectionListType aListType,
                        TSelectionMenuType aSelMenuType,
                        TInt aIspFilter,
                        TInt aBearerFilter,
                        TInt aSortType,
                        TInt aReqIpvType,
                        TVpnFilterType aVpnFilterType
                        );



        /**
        * Two-phased constructor. Leaves on failure.
        * This function shall be used to create the access point 
        * settings/selection handling UI object. It is customizable through 
        * the parameters. This object is a small layer above the UI part and
        * it provides a standard interface to select, edit, create access 
        * points. It has two main parts, Select and Edit. The first parameter,
        * aStartWithSelection gives whether we would like to select or edit.
        * In case of selection, there is the possibility to use this module in
        * many applications. For this, two layouts are implemented, one is list
        * pane used by General Settings which provides the list in a list-pane.
        * The other layout is for the other applications requiring access point
        * selection, a popup-list style as the decision was that General 
        * Settings will use list-pane and all other apps. popup-list style. 
        * It is the caller who selects the style so if spec. says otherwise,
        * this module still can be used. It is also possible to start the UI 
        * without selection, so if any module has a 'linked/default/etc.'
        * access point and stored it's UID, the module can simply call the 
        * editor part of the UI without having to select the AP once more.
        * In case of editing only, (aStartWithSelection is EFalse), all other 
        * construction parameters are ignored and after construction caller can
        * simply call RunSettingsL(..). In case of selection, a lot of other
        * parameters can be specified to fulfil all requirements. There are 
        * three types of Options menu available: EApSettingsSelMenuNormal, 
        * EApSettingsSelMenuSelectOnly, EApSettingsSelMenuSelectNormal.
        * <br>
        *-EApSettingsSelMenuSelectOnly: Only Select is visible, no way to edit,
        *   delete, create, etc.
        * <br>
        * -EApSettingsSelMenuNormal:Options menu specified in General Settings,
        *   contains Edit, Delete, Create new, etc. menu items.
        * <br>
        * -EApSettingsSelMenuSelectNormal: Same as in EApSettingsSelMenuNormal 
        *   BUT the first item is Select. This one makes it possible to select
        *   an access point and also possible to edit, create, delete, etc.
        * <br>
        * The following three parameters specify the filtering and ordering
        * criteria for the selection list creation. First, it is possible to 
        * specify which ISP-type we are looking for. The possible values are:
        * <br>
        * KEApIspTypeInternetOnly: Filter allows only access points that are 
        *   capable of only internet access.
        * <br>
        * KEApIspTypeWAPOnly: Filter allows only access points that are 
        *   capable of only WAP access.
        * <br>
        * KEApIspTypeInternetAndWAP: Filter allows only access points that are 
        *   capable of internet AND WAP access.
        * <br>
        * KEApIspTypeWAPMandatory: Filter allows only access points that are 
        *   capable of WAP access AND contain mandatory WAP settings.
        * <br>
        * KEApIspTypeAll: No filtering is done for the isp-type, all types of
        *   access points are shown.
        * <br>
        * It is possible to combine them by simply adding/or-ing together the
        * values, filtering will be done in such a way that only access points
        * with the listed ISP-types will be shown. Second filtering possibility
        * (aBearerFilter) is the desired bearer type. The possible values are 
        * the values of the TApBearerType enum type and their combinations, as
        * in case of the ISP type. The ordering of the list can be specified 
        * with the aSortType parameter. It can have the following values:
        * KEApSortUidAscending: The sorting is done according to the ID of 
        *   the access points in ascending order.
        * KEApSortUidDescending: The sorting is done according to the ID of 
        *   the access points in descending order.
        * KEApSortNameAscending: The sorting is done according to the name of
        *   the access points in ascending order.
        * KEApSortNameDescending: The sorting is done according to the name of
        *   the access points in descending order.
        * Caution! The ordering values can not be combined!
        * @param aDb A database to work on
        * @param aStartWithSelection A boolean value indicating whether to 
        *   select or edit an ap.
        * @param aListType A TSelectionListType enum indicating the desired
        *   list type.
        * @param aSelMenuType A TSelectionMenuType enum indicating the desired
        *   menu type.
        * @param aIspTypeFilter Filtering criteria on ISP type
        * @param aBearerFilter Filtering criteria on bearer type
        * @param aSortType Specifies the sort order to use.
        * @param aReqIpvType Specifies whether the caller would like to 
        *   have IPv4, IPv6 or both access points. If it is IPv6 or Both, 
        *   in case of IPv6 support is available as a feature, it will be 
        *   supported. If IPv6 feature is not supported by the phone, it 
        *   simply defaults to the normal IPv4 version.
        *   If it is IPv4, it uses the default IPv4 version independently 
        *   from IPv6 feature beeing available or not.
        * @param aVpnFilterType a TVpnFilterType representing the possible 
        *   additional VPN filtering.
        * @return The constructed CApSettingsHandler object.
        *
        * @deprecated
        */
        IMPORT_C static CApSettingsHandler* NewLC(
                        CActiveApDb& aDb,
                        TBool aStartWithSelection,
                        TSelectionListType aListType,
                        TSelectionMenuType aSelMenuType,
                        TInt aIspFilter,
                        TInt aBearerFilter,
                        TInt aSortType,
                        TInt aReqIpvType,
                        TVpnFilterType aVpnFilterType
                        );





        /**
        * Two-phased constructor. Leaves on failure.
        * This function shall be used to create the access point 
        * settings/selection handling UI object. It is customizable through 
        * the parameters. This object is a small layer above the UI part and
        * it provides a standard interface to select, edit, create access 
        * points. It has two main parts, Select and Edit. The first parameter,
        * aStartWithSelection gives whether we would like to select or edit.
        * In case of selection, there is the possibility to use this module in
        * many applications. For this, two layouts are implemented, one is list
        * pane used by General Settings which provides the list in a list-pane.
        * The other layout is for the other applications requiring access point
        * selection, a popup-list style as the decision was that General 
        * Settings will use list-pane and all other apps. popup-list style. 
        * It is the caller who selects the style so if spec. says otherwise,
        * this module still can be used. It is also possible to start the UI 
        * without selection, so if any module has a 'linked/default/etc.'
        * access point and stored it's UID, the module can simply call the 
        * editor part of the UI without having to select the AP once more.
        * In case of editing only, (aStartWithSelection is EFalse), all other 
        * construction parameters are ignored and after construction caller can
        * simply call RunSettingsL(..). In case of selection, a lot of other
        * parameters can be specified to fulfil all requirements. There are 
        * three types of Options menu available: EApSettingsSelMenuNormal, 
        * EApSettingsSelMenuSelectOnly, EApSettingsSelMenuSelectNormal.
        * <br>
        *-EApSettingsSelMenuSelectOnly: Only Select is visible, no way to edit,
        *   delete, create, etc.
        * <br>
        * -EApSettingsSelMenuNormal:Options menu specified in General Settings,
        *   contains Edit, Delete, Create new, etc. menu items.
        * <br>
        * -EApSettingsSelMenuSelectNormal: Same as in EApSettingsSelMenuNormal 
        *   BUT the first item is Select. This one makes it possible to select
        *   an access point and also possible to edit, create, delete, etc.
        * <br>
        * The following three parameters specify the filtering and ordering
        * criteria for the selection list creation. First, it is possible to 
        * specify which ISP-type we are looking for. The possible values are:
        * <br>
        * KEApIspTypeInternetOnly: Filter allows only access points that are 
        *   capable of only internet access.
        * <br>
        * KEApIspTypeWAPOnly: Filter allows only access points that are 
        *   capable of only WAP access.
        * <br>
        * KEApIspTypeInternetAndWAP: Filter allows only access points that are 
        *   capable of internet AND WAP access.
        * <br>
        * KEApIspTypeWAPMandatory: Filter allows only access points that are 
        *   capable of WAP access AND contain mandatory WAP settings.
        * <br>
        * KEApIspTypeAll: No filtering is done for the isp-type, all types of
        *   access points are shown.
        * <br>
        * It is possible to combine them by simply adding/or-ing together the
        * values, filtering will be done in such a way that only access points
        * with the listed ISP-types will be shown. Second filtering possibility
        * (aBearerFilter) is the desired bearer type. The possible values are 
        * the values of the TApBearerType enum type and their combinations, as
        * in case of the ISP type. The ordering of the list can be specified 
        * with the aSortType parameter. It can have the following values:
        * KEApSortUidAscending: The sorting is done according to the ID of 
        *   the access points in ascending order.
        * KEApSortUidDescending: The sorting is done according to the ID of 
        *   the access points in descending order.
        * KEApSortNameAscending: The sorting is done according to the name of
        *   the access points in ascending order.
        * KEApSortNameDescending: The sorting is done according to the name of
        *   the access points in descending order.
        * Caution! The ordering values can not be combined!
        * @param aDb A database to work on
        * @param aStartWithSelection A boolean value indicating whether to 
        *   select or edit an ap.
        * @param aListType A TSelectionListType enum indicating the desired
        *   list type.
        * @param aSelMenuType A TSelectionMenuType enum indicating the desired
        *   menu type.
        * @param aIspTypeFilter Filtering criteria on ISP type
        * @param aBearerFilter Filtering criteria on bearer type
        * @param aSortType Specifies the sort order to use.
        * @param aReqIpvType Specifies whether the caller would like to 
        *   have IPv4, IPv6 or both access points. If it is IPv6 or Both, 
        *   in case of IPv6 support is available as a feature, it will be 
        *   supported. If IPv6 feature is not supported by the phone, it 
        *   simply defaults to the normal IPv4 version.
        *   If it is IPv4, it uses the default IPv4 version independently 
        *   from IPv6 feature beeing available or not.
        * @param aVpnFilterType a TVpnFilterType representing the possible 
        *   additional VPN filtering.
        * @param aIncludeEasyWlan a TBool indicating whether it should 
        *   include the easy wlan AP in the list or not.
        * @return The constructed CApSettingsHandler object.
        *
        * @deprecated
        */
        IMPORT_C static CApSettingsHandler* NewLC(
                        CActiveApDb& aDb,
                        TBool aStartWithSelection,
                        TSelectionListType aListType,
                        TSelectionMenuType aSelMenuType,
                        TInt aIspFilter,
                        TInt aBearerFilter,
                        TInt aSortType,
                        TInt aReqIpvType,
                        TVpnFilterType aVpnFilterType,
                        TBool aIncludeEasyWlan
                        );




        /**
        * Destructor.
        *
        * @deprecated
        */
        IMPORT_C ~CApSettingsHandler();


    protected:
        /**
        * Constructor.
        * @param aStartWithSelection A boolean value indicating whether to 
        *   select or edit an ap.
        * @param aListType A TSelectionListType enum indicating the desired
        *   list type.
        * @param aSelMenuType A TSelectionMenuType enum indicating the desired
        *   menu type.
        *
        * @deprecated
        */
        IMPORT_C CApSettingsHandler(
                                    TBool aStartWithSelection,
                                    TSelectionListType aListType,
                                    TSelectionMenuType aSelMenuType
                                    );

        /**
        * Constructor.
        * @param aStartWithSelection A boolean value indicating whether to 
        *   select or edit an ap.
        * @param aListType A TSelectionListType enum indicating the desired
        *   list type.
        * @param aSelMenuType A TSelectionMenuType enum indicating the desired
        *   menu type.
        * @param aHelpMajor Major help ID
        *
        * @deprecated
        */
        IMPORT_C CApSettingsHandler(
                                    TBool aStartWithSelection,
                                    TSelectionListType aListType,
                                    TSelectionMenuType aSelMenuType,
                                    TUid aHelpMajor
                                    );


        /**
        * Constructor.
        * @param aStartWithSelection A boolean value indicating whether to 
        *   select or edit an ap.
        * @param aListType A TSelectionListType enum indicating the desired
        *   list type.
        * @param aSelMenuType A TSelectionMenuType enum indicating the desired
        *   menu type.
        * @param aNeedIpv6Support Whether IPv6 is supported or not
        */
        CApSettingsHandler(
                            TBool aStartWithSelection,
                            TSelectionListType aListType,
                            TSelectionMenuType aSelMenuType,
                            TBool aNeedIpv6Support
                            );



        /**
        * Second-phase constructor.
        * @param aIspTypeFilter Filtering criteria on ISP type
        * @param aBearerFilter Filtering criteria on bearer type
        * @param aSortType Specifies the sort order to use.
        *
        * @deprecated
        */
        IMPORT_C void ConstructL(
                                TInt aIspFilter,
                                TInt aBearerFilter,
                                TInt aSortType
                                );


        /**
        * Second-phase constructor.
        * @param aDb A database to work on
        * @param aIspTypeFilter Filtering criteria on ISP type
        * @param aBearerFilter Filtering criteria on bearer type
        * @param aSortType Specifies the sort order to use.
        *
        * @deprecated
        */
        IMPORT_C void ConstructL(
                                CActiveApDb& aDb,
                                TInt aIspFilter,
                                TInt aBearerFilter,
                                TInt aSortType
                                );


        /**
        * Second-phase constructor.
        * @param aIspTypeFilter Filtering criteria on ISP type
        * @param aBearerFilter Filtering criteria on bearer type
        * @param aSortType Specifies the sort order to use.
        * @param aVpnFilterType a TVpnFilterType representing the possible 
        *   additional VPN filtering.
        *
        * @deprecated
        */
        IMPORT_C void ConstructL(
                                TInt aIspFilter,
                                TInt aBearerFilter,
                                TInt aSortType,
                                TVpnFilterType aVpnFilterType
                                );


        /**
        * Second-phase constructor.
        * @param aDb A database to work on
        * @param aIspTypeFilter Filtering criteria on ISP type
        * @param aBearerFilter Filtering criteria on bearer type
        * @param aSortType Specifies the sort order to use.
        * @param aVpnFilterType a TVpnFilterType representing the possible 
        *   additional VPN filtering.
        *
        * @deprecated
        */
        IMPORT_C void ConstructL(
                                CActiveApDb& aDb,
                                TInt aIspFilter,
                                TInt aBearerFilter,
                                TInt aSortType,
                                TVpnFilterType aVpnFilterType
                                );




        /**
        * Second-phase constructor.
        * @param aDb A database to work on
        * @param aIspTypeFilter Filtering criteria on ISP type
        * @param aBearerFilter Filtering criteria on bearer type
        * @param aSortType Specifies the sort order to use.
        * @param aVpnFilterType a TVpnFilterType representing the possible 
        *   additional VPN filtering.
        * @param aIncludeEasyWlan a TBool indicating whether it should 
        *   include the easy wlan AP in the list or not.
        *
        * @deprecated
        */
        IMPORT_C void ConstructL(
                                CActiveApDb& aDb,
                                TInt aIspFilter,
                                TInt aBearerFilter,
                                TInt aSortType,
                                TVpnFilterType aVpnFilterType,
                                TBool aIncludeEasyWlan
                                );


    public: // New functions
        /**
        * Sets the filtering used in the access point selection.
        * @param aIspTypeFilter Filtering criteria on ISP type
        * @param aBearerFilter Filtering criteria on bearer type
        * @param aSortType Specifies the sort order to use.
        * @return No return value. Leaves on error.
        *
        * @deprecated
        */
        IMPORT_C void SetFilterL(
                                TInt aIspFilter,
                                TInt aBearerFilter,
                                TInt aSortType
                                );


        /**
        * Sets possible overrides of some texts.
        * By default, text is read from resources. This provides a way to 
        * change some of the text to a caller-supplied one. The text must 
        * be read from resource and must be already localized.
        * More than one text can be substituted, they are stored internally
        * in an array.
        * Currently not supported and supporting it is under discussion.
        * @param aText2Change TTextID to identify the text to be replaced with
        * @param aNewText Reference to the substitute text.
        *
        * @deprecated
        */
        IMPORT_C void SetTextOverrideL( TTextID aText2Change, 
                                        const TDesC& aNewText );


        /**
        * Gets possible overrides of a text.
        * By default, text is read from resources. This provides a way to 
        * change some of the text to a caller-supplied one. The text must
        * be read from resource and must be already localized.
        * More than one text can be substituted, they are stored internally
        * in an array.
        * Currently not supported and supporting it is under discussion
        * @param aTextID TTextID type to identify the text to be replaced with
        * @return Reference to the substitute text.
        *
        * @deprecated
        */
        IMPORT_C const TDesC& TextOverrideL( TTextID aTextId );


        /**
        * Starts the settings component.
        * Creates dialog(s) from scratch, launches and executes them.
        * Can leave with error codes.
        * @param TUint32 aHighlight The UID of the AP to highlight by default
        * @param TUint32 aSelected The UID of the access point selected 
        * by the user.
        * @return The accomplished task's flag-codes:
        * <br>
        * KApUiEventNone,
        * <br>
        * KApUiEventSelected,
        * <br>
        * KApUiEventCreatedBlank,
        * <br>
        * KApUiEventCreatedUsedOld,
        * <br>
        * KApUiEventEdited,
        * <br>
        * KApUiEventDeleted,
        * <br>
        * KApUiEventExitRequested
        * <br>and their combinations. ( Bitwise OR )
        * <br>
        * aSelected will be modified only if KApUiEventSelected is included 
        * in the flags.
        * <br>
        * In case it returns KApUiEventExitRequested, the user had choosen
        * the Exit option from the Options menu which means
        * that the caller application MUST exit!
        * <br>
        * Returns after completion!
        *
        * @deprecated
        */
        IMPORT_C TInt RunSettingsL( TUint32 aHighLight, TUint32& aSelected );


        /**
        * Component Validation Test.
        * @return KErrNone.
        *
        * @deprecated
        */
        IMPORT_C static TInt Cvt();


    protected:  // New functions
        /**
        * @Deprecated
        * Starts the settings component.
        * Creates dialog(s) from scratch, launches and executes them.
        * In case of error, leaves with error codes.
        * @param TUint32 aHighlight The UID of the AP to highlight by default
        * @param TUint32 aSelected The UID of the AP selected by the user
        * @return The accomplished task's flag-codes:
        * <br>
        * KApUiEventNone,
        * <br>
        * KApUiEventSelected,
        * <br>
        * KApUiEventCreatedBlank,
        * <br>
        * KApUiEventCreatedUsedOld,
        * <br>
        * KApUiEventEdited,
        * <br>
        * KApUiEventDeleted
        * <br>
        * and their combinations. ( Bitwise OR )
        * <br>
        * aSelected will be modified only if KApUiEventSelected is included 
        * in the flags.
        * <br>
        * Returns after completion!
        */
        TInt DoRunSettingsL( TUint32 aHighLight, TUint32& aSelected );


        /**
        * Starts the viewer component.
        * Creates dialog(s) from scratch, launches and executes it.
        * In case of error, leaves with error codes.
        * @param TUint32 aUid The UID of the AP to view/edit
        * @return Returns the completed task's flags
        * KApUiEventNone, KApUiEventSelected, KApUiEventCreatedBlank,
        * KApUiEventCreatedUsedOld, KApUiEventEdited, KApUiEventDeleted,
        * KApUiEventExitRequested and their combinations. ( Bitwise OR )
        * In case it returns KApUiEventExitRequested, the user had choosen
        * the Exit option from the Options menu which means
        * that the caller application MUST exit!
        * <br>
        * Returns after completion!
        *
        * @deprecated
        */
        IMPORT_C TInt RunViewerL( TUint32 aUid );


        /**
        * @Deprecated
        * Starts the viewer component.
        * Creates dialog(s) from scratch, launches and executes it.
        * In case of error, leaves with error codes.
        * @param TUint32 aUid The UID of the AP to view/edit
        * @return Returns the completed task's flags
        * KApUiEventNone, KApUiEventSelected, KApUiEventCreatedBlank,
        * KApUiEventCreatedUsedOld, KApUiEventEdited, KApUiEventDeleted,
        * KApUiEventExitRequested and their combinations. ( Bitwise OR )
        * Returns after completion!
        */
        TInt DoRunViewerL( TUint32 aUid );


        // handles the Delete access Point command.
        // @Deprecated
        void HandleApDeleteCmdL( TUint32 aUid, TBool aIsLast );


        // handles the Create blank new access Point command.
        // @Deprecated
        TUint32 HandleApBlankNewL( TInt aBearers, TInt aIsps );


        // handles the Create new access Point by using existing one command.
        // @Deprecated
        TUint32 HandleApUseOldNewL();


        // handles the Editing of the newly created access Point.
        // @Deprecated
        TUint32 EditAfterCreateL( TUint32 aUid, 
                                  CApAccessPointItem* aItem = NULL );


        /**
        * Second-phase internal constructor.
        * @param aDb A database to work on
        * @param aIspTypeFilter Filtering criteria on ISP type
        * @param aBearerFilter Filtering criteria on bearer type
        * @param aSortType Specifies the sort order to use.
        * @param aVpnFilterType a TVpnFilterType representing the possible 
        *   additional VPN filtering.
        * @param aIncludeEasyWlan a TBool indicating whether it should 
        *   include the easy wlan AP in the list or not.
        */
        void DoConstructL( CActiveApDb* aDb, TInt aIspFilter,
                           TInt aBearerFilter, TInt aSortType,
                           TVpnFilterType aVpnFilterType,
                           TBool aIncludeEasyWlan );


        /**
        * @Deprecated
        * Starts the selector component as a list
        * Creates dialog(s) from scratch, launches and executes them.
        * In case of error, leaves with error codes.
        * @param TUint32 aHighlight The UID of the AP to highlight by default
        * @param TUint32 aSelected The UID of the AP selected by the user
        * @return The accomplished task's flag-codes:
        * <br>
        * KApUiEventNone,
        * <br>
        * KApUiEventSelected,
        * <br>
        * KApUiEventCreatedBlank,
        * <br>
        * KApUiEventCreatedUsedOld,
        * <br>
        * KApUiEventEdited,
        * <br>
        * KApUiEventDeleted
        * <br>
        * and their combinations. ( Bitwise OR )
        * <br>
        * aSelected will be modified only if KApUiEventSelected is included 
        * in the flags.
        * <br>
        * Returns after completion!
        */
        void DoRunListSettingsL( TUint32 aHighLight, TUint32& aSelected );


        /**
        * @Deprecated        
        * Starts the selector component in a setting page
        * Creates dialog(s) from scratch, launches and executes them.
        * In case of error, leaves with error codes.
        * @param TUint32 aHighlight The UID of the AP to highlight by default
        * @param TUint32 aSelected The UID of the AP selected by the user
        * @return The accomplished task's flag-codes:
        * <br>
        * KApUiEventNone,
        * <br>
        * KApUiEventSelected,
        * <br>
        * KApUiEventCreatedBlank,
        * <br>
        * KApUiEventCreatedUsedOld,
        * <br>
        * KApUiEventEdited,
        * <br>
        * KApUiEventDeleted
        * <br>
        * and their combinations. ( Bitwise OR )
        * <br>
        * aSelected will be modified only if KApUiEventSelected is included
        * in the flags.
        * <br>
        * Returns after completion!
        */
        void DoRunSetPageSettingsL( TUint32 aHighLight, TUint32& aSelected );


        /**
        * @Deprecated
        * handles the Create new access Point by using existing one command.
        * Called after user has selected the AP to copy
        * Creates the new Ap and offers it for editing.
        * @param aSelected The UID of the AP to copy. Shall not be KErrNone.
        * @return The UID of the newly created Ap
        */
        TUint32 DoHandleApUseOldNewL( TUint32 aSelected );

        /**
        * @Deprecated
        * Selects the Ap to Copy, returns its UID.
        * If not selected, KErrNone is returned
        */
        TUint32 SelectApToCopyL();


        /**
        * @Deprecated
        * handles the Create blank new access Point command.
        */
        TUint32 DoHandleApBlankNewL( TInt aBearers, TInt aIsps );


        /**
        * @Deprecated
        * handles the Delete network group command.
        * @param aUid The uid of the network to delete
        */
        void HandleNetworkDeleteCmdL( TUint32 aUid );


        /**
        * @Deprecated
        * Gets the local variant value 
        * @return A TInt stating the variant
        */
        TInt GetVariantL();


        /**
        * @Deprecated
        * Gets confirmation about deleting an access point
        * @param aUid A TUint32 holding the WAP access point ID of the 
        * access point to be deleted.
        * @param aIsLast A TBool specifying whether the access point to be 
        * deleted is the last one or not.
        * @return A TInt stating the result
        */
        TInt ConfirmDeleteL( TUint32 aUid, TBool aIsLast );


        /**
        * @Deprecated
        * Wrapper for the public API
        */
        void HandleRunSettingsL( TUint32 aHighLight, TUint32& aSelected );
        

    protected:  // Functions from base classes

        friend class CApSettingsDlg;
        friend class CApSelectorDialog;
        friend class CApSelPopupList;
        friend class CApNetSelPopupList;

    private:
        /**
        * @Deprecated
        * Selects an appropriate bearer type for a given item according to 
        * the current filtering criterias
        * @param aBearers The current bearer filter set
        * @param aItem The CApAccessPointItem whoose bearer type is to be set.
        */
        void ChooseBearerTypeL( TInt aBearers, CApAccessPointItem& aItem );

        /**
        * @Deprecated
        * Duplciates an existing access point identified by the passed WAP ID
        * @param aUid The WAP Access Point ID of the access point to duplicate
        * @return The WAP Access Point ID of the newly created access point.
        */
        TUint32 HandleDuplicateL( TUint32 aUid );


    private: //data
        TBool                   iStartWithSelection;
        TSelectionListType      iListType;
        TSelectionMenuType      iSelMenuType;
 
        TInt                    iIspFilter;
        TInt                    iBearerFilter;
        TApSetHandlerExtra*     iExt;           // Extra data holder structure

        TInt                    iReqIpvType;    // Default is IPv4

// replacing iModel with iImpl, no size change
//        CApSettingsModel*       iModel;   
        CApSettingsHandlerImpl* iImpl;          // owned
        
        CTextOverrides*         iTextOverrides;
        TUint32                 iEventStore;    // to hold the events
        TUid                    iHelpMajor;

#ifdef __TEST_OOMDEBUG
        TBool                           iMemTestOn;
#endif // __TEST_OOMDEBUG

    };

#endif

// End of File
