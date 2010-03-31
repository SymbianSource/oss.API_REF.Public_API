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
* Description:  Definition of attributes used by every Connection Methods.
*
*/

#ifndef CMCONNECTIONMETHODDEF_H
#define CMCONNECTIONMETHODDEF_H

// INCLUDES
#include <e32base.h>

// CONSTANTS

// Beginning of the CMManager enum range (internal use)
const TUint KLanBaseSpecificAttributes = 20000;
const TUint KLanBaseIfNetworks = 20100; 
// End of the CMManager enum range (internal use)
const TUint KLanBaseRangeMax = 29999;

/**  ECOM interface UID */
const TUint KCMPluginInterfaceUid = 0x10207377;

namespace CMManager
    {
    //Enumeration for possible values of seamlessness field 
    //in IAP Metadata table 
    /**  Naming method options */
    enum TNamingMethod
        {
        ENamingNothing,     ///< Do nothing with name set via ECmName
        ENamingUnique,      ///< Make name unique when ECmName is set.
        ENamingNotAccept    ///< Do not accept duplication. It will leave with
                            ///< KErrArgument.
        };
    
    // Enumeration for IPv6 types
    enum TIPv6Types
        {
        EIPv6Unspecified,   ///< Unspecified IPv6 type
        EIPv6WellKnown,     ///< Well known IPv6 type
        EIPv6UserDefined    ///< User defined IPv6 type
        };
    
    enum TSeamlessnessValue
        {
        ESeamlessnessNotRoamedTo,   // NOT supported
        ESeamlessnessConfirmFirst,  // Confirm first
        ESeamlessnessShowprogress,  // Shows progress
        ESeamlessnessFullySeamless  // NOT supported
        };
    
    
    /// Unspecified IPv4 address
    _LIT( KUnspecifiedIPv4, "0.0.0.0" );
    
    /// Known IPv6 name server 1
    _LIT( KKnownIp6NameServer1, "fec0:000:0000:ffff::1" );
    /// Known IPv6 name server 2
    _LIT( KKnownIp6NameServer2, "fec0:000:0000:ffff::2" );
    
    /// Dynamic IPv6 address
    _LIT( KDynamicIpv6Address, "0:0:0:0:0:0:0:0" );

    /// Default proxy protocol name
    _LIT( KDefProxyProtocolName, "http" );
    
    /// Default proxy port number
    _LIT( KDefaultProxyPortNumber, "0" );

    /// IPv4 network protocol
    _LIT( KDefIspIfNetworksIPv4, "ip" );
    /// IPv6 network protocol
    _LIT( KDefIspIfNetworksIPv6, "ip6" );
    /// IPv4 and IPv6 network protocols
    _LIT( KDefIspIfNetworksIPv4IPv6, "ip,ip6" );
    /// IPv4 and IPv6 network protocols for LAN bearers
    _LIT( KDefIspIfNetworksIPv4IPv6LAN, "ip" );

    _LIT( KDaemonManagerName, "NetCfgExtnDhcp" );
    _LIT( KConfigDaemonName, "!DhcpServ" );


    /**
    * This enum lists all the common attributes of Connection Methods.
    */
    enum TConnectionMethodCommonAttributes
        {
        /**
        * The following attributes can be queried via both 
        * the manager interface's and connection method interface's ::Get functions.
        */
        ECmCoverage,                /**<
                                    * Checks if there's coverage for this bearer.
                                    * (TBool - default: none - read only)
                                    */
                        
        ECmDefaultPriority,         /**<
                                    * Default global priority of the CM's bearer 
                                    * type.
                                    * (TUint32 - default: none - read only)
                                    */
                        
        ECmDestination,             /**<
                                    * ETrue if this connection method is 
                                    * an embedded destination.
                                    * (TBool - default: none - read only)
                                    */
                            
        ECmBearerHasUi,             /**<
                                    * Indicates whether the bearer has any UI.
                                    * (TBool - default: none - read only)
                                    */

        ECmIPv6Supported,           /**<
                                    * Returns ETrue if IPv6 is supported.
                                    * (TBool - default: none - read only)
                                    */
                                    
        ECmDefaultUiPriority,       /**<
                                    * Priority of this bearer type when shown in UI for 
                                    * configuring a new IAP.
                                    * (TUint32 - default: none - read only)
                                    */

        ECmBearerIcon = 100,        /**<
                                    * Return the bearer specific icon. Assumes that
                                    * there's an existing EEikEnv in the client.                        
                                    * Type cast return value from TUint32 to 
                                    * CGuiIcon*.
                                    * Return value 0 means bearer has no icon.
                                    * (TUint32 - default: none - read only)
                                    */ 
                        
        ECmBearerAvailableIcon,     /**<
                                    * Return the bearer available specific icon. 
                                    * Assumes that there's an existing EEikEnv 
                                    * in the client. Type cast return value from 
                                    * TUint32 to CGuiIcon*.
                                    * Return value 0 means bearer has no icon.
                                    * (TUint32 - default: none - read only)
                                    */
                        
        ECmBearerAvailableName = 200,   /**<
                                        * Name of the bearer. Can be used in 
                                        * layout 
                                        * list_double_large_graphic_popup_menu_pane.
                                        * (String - default: none - read only)
                                        */
                        
        ECmBearerSupportedName,     /**<
                                    * Name of the bearer. Can be used in 
                                    * layout list_single_popup_menu_pane_1.
                                    * (String - default: none - read only)
                                    */
                        
        ECmBearerAvailableText,     /**<
                                    * Localized text 'Available'. Can be used in 
                                    * layout 
                                    * list_double_large_graphic_popup_menu_pane.
                                    * (String - default: none - read only)
                                    */
                        
        ECmBearerNamePopupNote,     /**<
                                    * Localized text of the bearer type name.
                                    * Can be used in layout popup note.
                                    * (String - default: none - read only)
                                    */

        ECmCommsDBBearerType,       /**<
                                    * For backward compatibility, connection method
                                    * can return its CommsDB specific bearer type.
                                    * (TUint32 - default: none - read only)
                                    * Leaves with KErrUnknown if no associated bearer 
                                    * type exists in CommsDat.
                                    */
                                
        ECmBearerSettingName,       /**<
                                    * Name of the data bearer used when 
                                    * accessing external network.
                                    * (String - default: none - read only)
                                    */
        
        ECmVirtual,                 /**<
                                    * Is the given connection method virtual?
                                    * (TBool - default: none - read only)
                                    */

        /**
        * These are not bearer specific, but controling attributes.
        */    
        ECmInvalidAttribute = 400,  /**<
                                    * Client application can check which attribute 
                                    * was incorrect in UpdateL().
                                    * (TUint32 - default: none - read only)
                                    */
                                    
        ECmAddToAvailableList,      /**<
                                    * Bearer type has to be added to the avaialable
                                    * bearer type list.
                                    * (TBool - default: EFalse - read only)
                                    */                   
                        
        ECmLoadResult,              /**<
                                    * Result of the load process. KErrNone if there
                                    * was no error. Otherwise a system wide
                                    * error code.
                                    * (TUint32 - default: KErrNone - read only)
                                    */
        
        /**
        * Attributes the can be queried only via
        * - connection method's GetXXXAttributeL()
        * - connection manager's function GetConnectionMethodInfoXXXL()
        * functions
        */
        ECmBearerType = 500,        /**<   
                                    * Bearer type of the CM 
                                    * (TUint - default: none - read only)
                                    */
                        
        ECmName,                    /**<   
                                    * Name of the CM
                                    * (String - default: none)
                                    */
        
        ECmIapId,                   /**<    
                                    * IAP id
                                    * (TUint32 - default: none - read only)
                                    */
                        
        ECmStartPage,               /**<
                                    * Start page of the connection method
                                    * (String - default: empty string)
                                    */

        ECmHidden,                  /**<
                                    * Connection method is hidden. 
                                    * (not supported yet)
                                    * (TBool - default: EFalse)
                                    */

        ECmProtected,               /**<
                                    * This connection method is protected. 
                                    * Modifying it needs NetworkControl capability.
                                    * (TBool - default: EFalse)
                                    */
                        
        ECmNamingMethod,            /**<
                                    * See acceptable values in TNamingControl.
                                    * (TUint32 - default: ENamingUnique)
                                    */             
        
        ECmSeamlessnessLevel,   /**<
                                * Defines whether an IAP can be roamed to.
                                * See details in TSeamlessnessValue.
                                * (TUint32 - default: ESeamlessnessConfirmFirst )
                                */
                                
        ECmElementID,           /**<
                                * Element id of the connection method in IAP table.
                                * (TUint32 - default: none - read only)
                                */
        
        ECmNetworkId,           /**<
                                * Network id of the connection method.
                                * (TUint32 - default: none - read only)
                                */
                                
        ECmConnected,           /**<
                                * Is network connection created with connection
                                * method?
                                * (TBool - default: none - read only)
                                */

        ECmId,                  /**<    
                                * ID to uniquely identify the connection
                                * methods
                                * It is guaranteed that every connection
                                * method has an ECmId
                                * (TUint32 - default: none - read only)
                                */

        ECmWapId,               /**
		                        * Provided for backwards compatibility only.
                                * The record ID of the connection methods' 
                                * corresponding WAP_ACCESS_POINT record, which
                                * use had been deprecated as the main ID 
                                * should now be ECmIapId, ECmElementID or ECmId.
                                * (TUint32 - default: none - read only)
                                */

        ECmIapServiceId,        /**
		                        * Provided for backwards compatibility only.
                                * The record ID of the connection methods' 
                                * service record
                                * (TUint32 - default: none - read only)
                                */

        /**
        * The following attributes are stored in the connection method's 
        * meta data record.
        */
        ECmMetaHighlight = 600, /**<
                                * Set to indicate that this connection method is
                                * highlighted in Agent dialog. Only one connection
                                * method can have this flag set.
                                * (TBool - default: EFalse)
                                */
                                
        ECmMetaHiddenAgent,     /**<
                                * Set to hide this connection method in Agent
                                * dialog.
                                * (TBool - default: EFalse)
                                */
                                
        // These attributes can be used with virtual bearer type
        // connection methods.
        ECmNextLayerIapId,      /**<
                                * Returns the linked connection method's IAP id.
                                * (TUint32 - default: None)
                                */
                                
        ECmNextLayerSNAPId,     /**<
                                * Returns the linked connection method's SNAP id.
                                * (TUint32 - default: None)
                                */
        
        // Proxy attributes
        ECmProxyUsageEnabled = 1000,    /**<
                                        * Set to enable/disable proxy setting
                                        * of connection method.
                                        * Disabling: record is deleted from proxy 
                                        * when UpdateL() is called.
                                        * Proxy record is deleted on UpdateL() 
                                        * if ECmProxyServerName is an empty string.
                                        * It can be queried only via the 
                                        * connection method's GetXXXAttributeL()
                                        * (TBool: default: EFalse)
                                        */
     
        ECmProxyServerName,             /**<
                                        * Name of the host.
                                        * It can be queried only via the 
                                        * connection method's GetXXXAttributeL()
                                        * (String - default: none)
                                        */
                                        
        ECmProxyProtocolName,           /**<
                                        * Name of the protocol for which this proxy 
                                        * can be used.
                                        * It can be queried only via the 
                                        * connection method's GetXXXAttributeL()
                                        * (String - default: none)
                                        */
                                        
        ECmProxyPortNumber,             /**< 
                                        * Port number
                                        * It can be queried only via the 
                                        * connection method's GetXXXAttributeL()
                                        * (TUint32 - default: none)
                                        */
                                        
        ECmProxyExceptions,             /**<
                                        * ";" separated list of the addresses for 
                                        * which the proxy server should not be used.
                                        * It can be queried only via the 
                                        * connection method's GetXXXAttributeL()
                                        * (String - default: none)
                                        */
                                        
        ECmProxyRangeMax = 1999,        /**<
                                        * Marks the end of the proxy range
                                        */
                                  
        ECmChargeCardUsageEnabled = 2000,   /**<
                                            * Same as in ECmProxyUsageEnabled but 
                                            * for charge card. 
                                            * (TBool - default: EFalse)
                                            */      
                                            
        ECmChargeCardAccountNumber,         /**<
                                            * Account number
                                            * (String - default: none)
                                            */
                                            
        ECmChargeCardPIN,                   /**<
                                            * PIN number
                                            * (String - default: none)
                                            */
        
        ECmChargeCardLocalRule,             /**<
                                            * Order of dialling account number, 
                                            * PIN and phone number for local calls.
                                            * (String - default: none)
                                            */
                                            
        ECmChargeCardNatRule,               /**<
                                            * Order of dialling account number, 
                                            * PIN and phone number for national 
                                            * calls.
                                            * (String - default: none)
                                            */

        ECmChargeCardIntlRule,              /**<
                                            * Order of  dialling account number, 
                                            * PIN and phone number for 
                                            * international calls.
                                            * (String - default: none)
                                            */
        
        ECmChargeCardRangeMax = 2999,       /**<
                                            * Marks the end of the chargecard range
                                            */
                                            
        ECmLocationUsageEnabled = 3000,     /**<
                                            * Same as in ECmProxyUsageEnabled but 
                                            * for location. 
                                            * (TBool - default: EFalse)
                                            */
                                            
        ECmLocationIntlPrefixCode,          /**<
                                            * International prefix code.
                                            * (String - default: none)
                                            */
                                            
        ECmLocationNatPrefixCode,           /**<
                                            * National prefix code.
                                            * (String - default: none)
                                            */
                                            
        ECmLocationNatCode,                 /**<
                                            * National code
                                            * (String - default: none)
                                            */
                                            
        ECmLocationAreaCode,                /**<
                                            * Area code.
                                            * (String - default: none)
                                            */
                                            
        ECmLocationDialOutCode,             /**<
                                            * Number to dial for an outside line.
                                            * (String - default: none)
                                            */
                                            
        ECmLocationDisableCallWaitingCode,  /**<
                                            * Code to dial to disable call waiting 
                                            * facility.
                                            * (String - default: none)
                                            */
                                            
        ECmLocationMobile,                  /**<
                                            * Mobile phone?
                                            * (TBool - default: none)
                                            */
                                            
        ECmLocationUsePulseDial,            /**<
                                            * Use pulse dialling?
                                            * (TBool - default: none)
                                            */
                                            
        ECmLocationWaitForDialTone,         /**<
                                            * Wait for the dial tone?
                                            * (TBool - default: none)
                                            */
                                            
        ECmLocationPauseAfterDialOut,       /**<
                                            * Pause time after dial out.
                                            * (TUint32 - default: none)
                                            */
                                            
        ECmLocationRangeMax = 3999,         /**<
                                            * Marks the end of the location
                                            * range
                                            */
        
        // WAP specific attributes
        ECmWapIPGatewayAddress = 4000,      /**<
                                            * WAP Gateway address, in this case an 
                                            * IP address.
                                            * (String - default: none)
                                            */
                                            
        ECmWapIPWSPOption,          /**<
                                    * Enum value indicating whether 
                                    * connection-oriented 
                                    * or connectionless API should be used.
                                    * See valid values in TWapWSPOption.
                                    * (TUint32 - default: 
                                    * ECmWapWspOptionConnectionless)
                                    */
                                            
        ECmWapIPSecurity,           /**<
                                    * Attempt secure WTLS connection to the gateway
                                    * (TBool - default: EFalse)
                                    */
        
        ECmWapIPProxyPort,          /**<
                                    * Proxy port number. Required for WAP2.0 only.
                                    * (TUint32 - default: none)
                                    */
                                            
        ECmWapIPProxyLoginName,     /**<
                                    * Proxy login name. Required for WAP2.0 only.
                                    * (String - default: none)
                                    */
                                            
        ECmWapIPProxyLoginPass,     /**<
                                    * Proxy login password. 
                                    * Required for WAP2.0 only.
                                    * (String - default: none)
                                    */
                                            
        ECmWapRangeMax = 4099,      /**<
                                    * Marks the end of the WAP specific range
                                    */

        /** 
        * The following attributes are common for many bearer types.
        * It's not sure that every IF or IP attribute is supported by
        * all bearer types.
        * It's not possible to query these attributes via 
        * GetConnectionInfoXXX() functions.
        */
        ECmCommonAttributesStart = 5000, /**<
                                         * Marks the beginning of the common
                                         * attributes
                                         */
        
        ECmIFName,                  /**<
                                    * Interface name
                                    * It can be queried only via the 
                                    * connection method's GetXXXAttributeL()
                                    * (String - default: none)
                                    */
                                    
        ECmIFParams,                /**<
                                    * Interface parameter string
                                    * It can be queried only via the 
                                    * connection method's GetXXXAttributeL()
                                    * (String - default: none)
                                    */
                                    
        ECmIFNetworks,              /**<
                                    * List of network protocols
                                    * It can be queried only via the 
                                    * connection method's GetXXXAttributeL()
                                    * (String - default: none)
                                    */
                                    
        ECmIFPromptForAuth,         /**<
                                    * Prompt user for authentication
                                    * It can be queried only via the 
                                    * connection method's GetXXXAttributeL()
                                    * (TBool - default: none)
                                    */
                                    
        ECmIFAuthName,              /**<
                                    * Authentication user name used by PPP
                                    * It can be queried only via the 
                                    * connection method's GetXXXAttributeL()
                                    * (String - default: none)
                                    */
                                    
        ECmIFAuthPass,              /**<
                                    * Authentication password used by PPP
                                    * It can be queried only via the 
                                    * connection method's GetXXXAttributeL()
                                    * (String - default: none)
                                    */
                                    
        ECmIFAuthRetries,           /**<
                                    * Number of times for retrying authentication
                                    * if it fails
                                    * It can be queried only via the 
                                    * connection method's GetXXXAttributeL()
                                    * (TUint32 - default: none)
                                    */
        
        ECmIPNetmask = 5050,        /**<
                                    * IP net mask of interface
                                    * It can be queried only via the 
                                    * connection method's GetXXXAttributeL()
                                    * (String - default: none)
                                    */
                                    
        ECmIPGateway,               /**<
                                    * IP address of gateway
                                    * It can be queried only via the 
                                    * connection method's GetXXXAttributeL()
                                    * (String - default: none)
                                    */
                                    
        ECmIPAddFromServer,         /**<
                                    * Get IP address from server?
                                    * It can be queried only via the 
                                    * connection method's GetXXXAttributeL()
                                    * (TBool - default: none)
                                    */
                                    
        ECmIPAddress,               /**<
                                    * IP address of interface
                                    * It can be queried only via the 
                                    * connection method's GetXXXAttributeL()
                                    * (String - default: none)
                                    */
                                    
        ECmIPDNSAddrFromServer,     /**<
                                    * Get DNS addresses from server?
                                    * It can be queried only via the 
                                    * connection method's GetXXXAttributeL()
                                    * (TBool - default: none)
                                    */
                                    
        ECmIPNameServer1,           /**<
                                    * IP address of primary name server
                                    * It can be queried only via the 
                                    * connection method's GetXXXAttributeL()
                                    * (String - default: none)
                                    */
                                    
        ECmIPNameServer2,           /**<
                                    * IP address of secondary name server
                                    * It can be queried only via the 
                                    * connection method's GetXXXAttributeL()
                                    * (String - default: none)
                                    */
                                    
        ECmIP6DNSAddrFromServer,    /**<
                                    * Get IP6 DNS addresses from server?
                                    * It can be queried only via the 
                                    * connection method's GetXXXAttributeL()
                                    * (TBool - default: none)
                                    */
                                    
        ECmIP6NameServer1,          /**<
                                    * IP6 address of primary name server
                                    * It can be queried only via the 
                                    * connection method's GetXXXAttributeL()
                                    * (String - default: none)
                                    */
                                    
        ECmIP6NameServer2,          /**<
                                    * IP6 address of secondary name server
                                    * It can be queried only via the 
                                    * connection method's GetXXXAttributeL()
                                    * (String - default: none)
                                    */
                                    
        ECmIPAddrLeaseValidFrom,    /**<
                                    * IP address valid from this time, used to
                                    * store dynamically assigned address lease
                                    * info
                                    * It can be queried only via the 
                                    * connection method's GetXXXAttributeL()
                                    * (String - default: none)
                                    */
                                    
        ECmIPAddrLeaseValidTo,      /**<
                                    * IP address valid for use until this time,
                                    * used to store dynamically assigned
                                    * address lease info
                                    * It can be queried only via the 
                                    * connection method's GetXXXAttributeL()
                                    * (String - default: none)
                                    */
        
        ECmConfigDaemonManagerName = 5100, /**<
                                            * Name of the ECom configuration
                                            * daemon manager component. This
                                            * component interfaces with the
                                            * server identified in
                                            * ECmConfigDaemonName. If
                                            * specified, ECmConfigDaemonName
                                            * should also be specified.                                            
                                            * It can be queried only via the 
                                            * connection method's GetXXXAttributeL()
                                            * (String - default: none)
                                            */
                                            
        ECmConfigDaemonName,        /**<
                                    * Name of the configuration daemon server.
                                    * This server is used to provide further
                                    * configuration for a connection, e.g.
                                    * dynamic IP address assignment. If
                                    * specified, ECmConfigDaemonManagerName
                                    * should also be specified.
                                    * It can be queried only via the 
                                    * connection method's GetXXXAttributeL()
                                    * (String - default: none)
                                    */
        
        ECmEnableLPCExtension = 5110,   /**<
                                        * Enable LCP extensions?
                                        * It can be queried only via the 
                                        * connection method's GetXXXAttributeL()
                                        * (TBool - default: none)
                                        */
                                        
        ECmDisablePlainTextAuth,        /**<
                                        * Disable plaintext authentication?
                                        * It can be queried only via the 
                                        * connection method's GetXXXAttributeL()
                                        * (TBool - default: none)
                                        */
                                        
        ECmCommonAttributesEnd = 5999,  /**<
                                        * Marks the end of common attributes
                                        */
        
        /**
        * The following methods can be queried only via 
        * connection method's GetXXXAttributeL()
        */
        ECmSpecialAttributes = 6000,   /**<
                                        * Marks the beginning of special
                                        * attributes
                                        */
        
        ECmIsLinked,                /**<
                                    * Is connection method linked to any
                                    * virtual connection method?
                                    * It can be queried only via the 
                                    * connection method's GetXXXAttributeL()
                                    * (TBool - default: none)
                                    */
                                    
        ECmSpecialAttributesEnd = 8999  /**<
                                        * Marks the end of special attributes
                                        */
        };

    /**  WAP WSP options */        
    enum TWapWSPOption
        {
        /**
        * Indicates that connectionless APIs should be used
        */
        ECmWapWspOptionConnectionless,
        
        /**
        * Indicates that connection oriented APIs should be used
        */
        ECmWapWspOptionConnectionOriented
        };
       
    }   // namespace CMManager

#endif // CMCONNECTIONMETHODDEF_H
