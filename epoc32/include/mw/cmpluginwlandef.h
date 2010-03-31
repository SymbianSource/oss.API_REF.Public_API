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
* Description:  ?description
*
*/

#ifndef CMPLUGIN_WLAN_DEF_H
#define CMPLUGIN_WLAN_DEF_H

#include <cmconnectionmethoddef.h>

/**  ECOM interface UID */
const TUint KUidWlanBearerType = 0x10281BB1;

namespace CMManager
    {
    /** enumerations for WLAN network modes */
    enum TWlanNetMode
        {
        EAdhoc       = 0,   ///< Ad-Hoc mode
        EInfra       = 1    ///< Infrastructure mode
        };
        
    /** enumerations for WLAN security modes 
     ** It's possible to extend this enumeration */
    enum TWlanSecMode
        {
        EWlanSecModeOpen    = 1,    ///< Open security mode
        EWlanSecModeWep     = 2,    ///< WEP security mode
        EWlanSecMode802_1x  = 4,    ///< 802.1x security mode
        EWlanSecModeWpa     = 8,    ///< WPA security mode
        EWlanSecModeWpa2    = 16,   ///< WPA2 security mode
        EWlanSecModeWAPI    = 32    ///< WAPI security mode
        };

    /** Wlan specific connection method attributes */
    enum TConnectionMethodWlanSpecificAttributes
        {
        /**
        * Comma separated list of network protocols, e.g. "PPP".
        * ( String - default: None)
        */
        EWlanIfNetworks = KLanBaseIfNetworks,

        /**
        * IP net mask of interface.
        * ( String - default: None)
        */        
        EWlanIpNetMask,
            
        /**
        * IP address of gateway
        * ( String - default: None)
        */
        EWlanIpGateway,
            
        /**
        * Get IP addresses (for EPOC) from server?
        * ( TBool - default: None)
        */
        EWlanIpAddrFromServer,
        
        /**
        * IP address of EPOC.
        * ( String - default: None)
        */
        EWlanIpAddr,
        
        /**
        * Get DNS addresses from server?
        * ( TBool - default: None)
        */
        EWlanIpDNSAddrFromServer,

        /**
        * IP Address of primary name server.
        * ( String - default: None)
        */
        EWlanIpNameServer1,
            
        /**
        * IP Address of secondary name server.
        * ( String - default: None)
        */
        EWlanIpNameServer2,
        
        /**
        * Get IP6 DNS addresses from server?
        * ( TBool - default: None)
        */
        EWlanIp6DNSAddrFromServer,
        
        /**
        * IP6 Address of primary name server.
        * ( String - default: None)
        */
        EWlanIp6NameServer1,
        
        /**
        * IP6 Address of secondary name server.
        * ( String - default: None)
        */
        EWlanIp6NameServer2,
        
        /**
        * IP address valid from this time, used to store 
        * dynamically assigned address lease info.
        * ( String - default: None)
        */
        EWlanIpAddrLeaseValidFrom,
            
        /**
        * IP address valid for use until this time, used to store
        * dynamically assigned address lease info.
        * ( String - default: None)
        */
        EWlanIpAddrLeaseValidTo,
            
        /**
        * Name of the ECOM configuration daemon manager component. 
        * This component interfaces with the server identified in 
        * ISP_CONFIG_DAEMON_NAME. If specified, ISP_CONFIG_DAEMON_NAME 
        * should also be specified. 
        * ( String - default: None)
        */
        EWlanConfigDaemonManagerName,
            
        /**
        * Name of the configuration daemon server. 
        * This server is used to provide further configuration for 
        * a connection, e.g. dynamic IP address assignment. 
        * If specified, ISP_CONFIG_DAEMON_MANAGER_NAME should also 
        * be specified.
        * ( String - default: None)
        */
        EWlanConfigDaemonName,
            
        /**
        * Name of the WLAN Service Extension table.
        * ( String - default: None)
        */
        EWlanServiceExtensionTableName,
            
        /**
        * The record ID of the linked WLAN Service Extension record in the
        * WLAN Service Extension table.
        * ( TUint32 - default: None)
        */
        EWlanServiceExtensionTableRecordId,
        
        /**
        * Marks the beginning of WLAN specific attributes.
        */
        EWlanSpecificAttributes = 30000,
            
        /**
        * The record ID to which IAP record these settings belong to.
        * ( TUint32 - default: None)
        */
        EWlanServiceId = 30100,
            
        /**
        * The connection mode. This can be either Ad-hoc or infrastructure.
        * TWlanNetMode enum is to be used.
        * ( TUint32 - default: EInfra )
        */
        EWlanConnectionMode,
            
        /**
        * The SSID of this WLAN connection.
        * ( String - default: None)
        */
        EWlanSSID,
            
        /**
        * Used SSID.
        * ( String - default: None)
        */
        EWlanUsedSSID,
            
        /**
        * The security mode of this WLAN connection. It is a TWlanSecMode enum.
        * ( TUint32 - default: EWlanSecModeOpen )
        */
        EWlanSecurityMode,
            
        /**
        * Authentication type: none, wep, wpa, wpapresharedkey
        * ( TUint32 - default: None )
        */
        EWlanAuthenticationMode,
            
        /**
        * Gives whether it should scan for the SSID.
        * (TBool - default: EFalse )
        */
        EWlanScanSSID,
        
        /**
        * This is the channel ID in ad-hoc network mode
        * ( TUint32 - default: EAdhocAutomatic, if set to EAdhocUserDefined default = 7 )
        */
        EWlanChannelID,
        
        /**
        * Gives whether it is allowed to roam inside one SSID or not.
        * (TBool - default: determined through variation )
        */
        EWlanAllowSSIDRoaming,
        
            
        // The following attributes before EWlanRangeMax are for internal use only
        /**
        * Internal limiter
        */
        EWlanRangeInternal = 35000,
            
        /**
        * Internal, used for the security settings.
        */
        EWlanSecuritySettings,
        
        /**
        * Marks the end of WLAN attributes.
        */
        EWlanRangeMax = 39999
        };
    } // namespace CMManager

#endif // CMPLUGIN_WLAN_DEF_H
