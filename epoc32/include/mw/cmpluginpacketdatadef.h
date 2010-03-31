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
* Description:  packet data specific enums
*
*/

#ifndef CMPLUGINPACKETDATADEF_H
#define CMPLUGINPACKETDATADEF_H

/**  ECOM interface UID */
const TUint KUidPacketDataBearerType = 0x10207378;

namespace CMManager
    {
    /** Packet Data specific connection method attributes */
enum TConnectionMethodPacketDataSpecificAttributes
    {
    EPacketDataSpecificAttributes = 10000,  /**<
                                            * Marks the beginning of packet
                                            * data specific attributes.
                                            */
    
    EPacketDataOutGoing,            /**<
                                    * Indicates the direction of this connection method. 
                                    * Value ETrue means outgoing, EFalse is incoming. 
                                    * Can be changed dynamically, 
                                    * but every packet data specific data is lost then.
                                    * (TBool - default: ETrue)
                                    */
                                    
    EPacketDataAPName = 10100,      /**<
                                    * Access point name.
                                    * (String - default: None)
                                    */
                                            
    EPacketDataPDPType,             /**<
                                    * PDP type. Values can be one 
                                    * (RPacketContext::TProtocolType):
                                    *   - EPdpTypeIPv4 or
                                    *   - EPdpTypeIPv6
                                    * (TUint32 - default: EPdpTypeIPv4 
                                    *                       if IPv4 only
                                    *                     EPdpTypeIPv6 
                                    *                       if IPv6 supported )
                                    */

    EPacketDataPDPAddress,          /**<
                                    * PDP address of phone.
                                    * ( String - default: None)
                                    */
                                            
    EPacketDataReqPrecedence,       /**<
                                    * Requested quality of service precedence class.
                                    * ( TUint32 - default: None)
                                    */

    EPacketDataReqDelay,            /**<
                                    * Requested quality of service delay class.
                                    * ( TUint32 - default: None)
                                    */

    EPacketDataReliability,         /**<
                                    * Requested quality of service reliability class.
                                    * ( TUint32 - default: None)
                                    */

    EPacketDataPeakThroughput,      /**<
                                    * Requested quality of service peak throughput class.
                                    * ( TUint32 - default: None)
                                    */

    EPacketDataMeanThroughput,      /**<
                                    * Requested quality of service mean throughput class.
                                    * ( TUint32 - default: None)
                                    */

    EPacketDataMinPrecedence,       /**<
                                    * Minimum quality of service precedence class.
                                    * ( TUint32 - default: None)
                                    */

    EPacketDataMinDelay,            /**<
                                    * Minimum quality of service delay class.
                                    * ( TUint32 - default: None)
                                    */

    EPacketDataMinReliability,      /**<
                                    * Minimum quality of service reliability class.
                                    * ( TUint32 - default: None)
                                    */

    EPacketDataMinPeakThroughput,   /**<
                                    * Minimum quality of service peak throughput class.
                                    * ( TUint32 - default: None)
                                    */

    EPacketDataMinMeanThroughput,   /**<
                                    * Minimum quality of service mean throughput class.
                                    * ( TUint32 - default: None)
                                    */

    EPacketDataDataCompression,     /**<
                                    * Data compression on?
                                    * ( TBool - default: None)
                                    */

    EPacketDataHeaderCompression,   /**<
                                    * IP header compression on?
                                    * ( TBool - default: None)
                                    */

    EPacketDataUseEdge,             /**<
                                    * EDGE parameter.
                                    * ( TBool - default: None)
                                    */

    EPacketDataAnonymousAccess,     /**<
                                    * Use anonymous access on?
                                    * ( TBool - default: None)
                                    */

    EPacketDataIFParams,            /**<
                                    * Interface parameter string.
                                    * ( String - default: None)
                                    */

    EPacketDataIFNetworks,          /**<
                                    * Comma separated list of network protocols,
                                    * e.g. "PPP".
                                    * ( String - default: None)
                                    */

    EPacketDataIFPromptForAuth,     /**<
                                    * Prompt user for authentication 
                                    * username and password?
                                    * ( TBool - default: None)
                                    */

    EPacketDataIFAuthName,          /**<
                                    * Authentication username used by PPP.
                                    * ( String - default: None)
                                    */

    EPacketDataIFAuthPass,          /**<
                                    * Authentication password used by PPP.
                                    * ( String - default: None)
                                    */

    EPacketDataIFAuthRetries,       /**<
                                    * Number of times to retry authentication if it fails.
                                    * ( TUint32 - default: None)
                                    */

    EPacketDataIPNetmask,           /**<
                                    * IP net mask of interface.
                                    * ( String - default: None)
                                    */

    EPacketDataIPGateway,           /**<
                                    * IP address of gateway
                                    * ( String - default: None)
                                    */

    EPacketDataIPAddrFromServer,    /**<
                                    * Get IP addresses (for EPOC) from server?
                                    * ( TBool - default: None)
                                    */

    EPacketDataIPAddr,              /**<
                                    * IP address of EPOC.
                                    * ( String - default: None)
                                    */

    EPacketDataIPDNSAddrFromServer, /**<
                                    * Get DNS addresses from server?
                                    * ( TBool - default: None)
                                    */

    EPacketDataIPNameServer1,       /**<
                                    * IP Address of primary name server.
                                    * ( String - default: None)
                                    */

    EPacketDataIPNameServer2,       /**<
                                    * IP Address of secondary name server.
                                    * ( String - default: None)
                                    */

    EPacketDataIPIP6DNSAddrFromServer,  /**<
                                        * Get IP6 DNS addresses from server?
                                        * ( TBool - default: None)
                                        */

    EPacketDataIPIP6NameServer1,    /**<
                                    * IP6 Address of primary name server.
                                    * ( String - default: None)
                                    */

    EPacketDataIPIP6NameServer2,    /**<
                                    * IP6 Address of secondary name server.
                                    * ( String - default: None)
                                    */

    EPacketDataIPAddrLeaseValidFrom,/**<
                                    * IP address valid from this time, used to store 
                                    * dynamically assigned address lease info.
                                    * ( String - default: None)
                                    */

    EPacketDataIPAddrLeaseValidTo,  /**<
                                    * IP address valid for use until this time, 
                                    * used to store.
                                    * ( String - default: None)
                                    */

    EPacketDataConfigDaemonManagerName, /**<
                                        * IP address valid for use until this time, 
                                        * used to store dynamically assigned address 
                                        * lease info.
                                        * ( String - default: None)
                                        */

    EPacketDataConfigDaemonName,    /**<
                                    * Name of the ECOM configuration daemon manager 
                                    * component. This component interfaces with the 
                                    * server identified in ISP_CONFIG_DAEMON_NAME. 
                                    * If specified, ISP_CONFIG_DAEMON_NAME 
                                    * should also be specified. 
                                    * Name of the configuration daemon server. 
                                    * This server is used to provide further
                                    * configuration for a connection, 
                                    * e.g. dynamic IP address assignment. 
                                    * If specified, ISP_CONFIG_DAEMON_MANAGER_NAME 
                                    * should also be specified.
                                    * ( String - default: None)
                                    */

    EPacketDataEnableLcpExtension,  /**<
                                    * Enable LCP extensions?
                                    * ( TBool - default: None)
                                    */

    EPacketDataDisablePlainTextAuth,/**<
                                    * Disable plain text authentication?
                                    * ( TBool - default: None)
                                    */

    EPacketDataApType,              /**<
                                    * Service supports Internet only, WAP only or both.
                                    * Values can be any of TPacketDataType.
                                    * ( TUint32 - default: None)
                                    */

    EPacketDataQoSWarningTimeOut,   /**<
                                    * If the requested QOS can not be satisfied warn
                                    * the user after this time in microseconds. 
                                    * Set to 0xffffffff to disable.
                                    * ( TUint32 - default: None)
                                    */

    EPacketDataServiceEnableLLMNR,  /**<
                                    * Enable LLMNR?
                                    * ( TBool - default: None)
                                    */

    EGPRSReqTrafficClass = 10200,   /**< 
                                    * Requested traffic class
                                    * Defined in etelqos.h in RPacketQoS::TTrafficClass.
                                    * (TUint32 - default: ETrafficClassUnspecified)
                                    */
    
    EGPRSMinTrafficClass,           /**< 
                                    * Minimum acceptable traffic class.
                                    * Defined in etelqos.h in RPacketQoS::TTrafficClass.
                                    * (TUint32 - default: ETrafficClassUnspecified)
                                    */

    EGPRSReqDeliveryOrder,          /**< 
                                    * Requested value for sequential SDU delivery.
                                    * Defined in etelqos.h in RPacketQoS::TDeliveryOrder.
                                    * (TUint32 - default: EDeliveryOrderUnspecified)
                                    */
    
    GPRSMinDeliveryOrder,           /**< 
                                    * Minimum acceptable value for sequential SDU delivery.
                                    * Defined in etelqos.h in RPacketQoS::TDeliveryOrder.
                                    * (TUint32 - default: EDeliveryOrderUnspecified)
                                    */
    
    EGPRSReqDeliverErroneousSDU,    /**< 
                                    * Requested value for erroneous SDU delivery.
                                    * Defined in etelqos.h in RPacketQoS::TErroneousSDUDelivery.
                                    * (TUint32 - default: EErroneousSDUDeliveryUnspecified)
                                    */
    
    EGPRSMinDeliverErroneousSDU,    /**< 
                                    * Minimum acceptable value for erroneous SDU delivery.
                                    * Defined in etelqos.h in RPacketQoS::TErroneousSDUDelivery.
                                    * (TUint32 - default: EErroneousSDUDeliveryUnspecified)
                                    */
    
    EGPRSReqMaxSDUSize,             /**< 
                                    * Request maximum SDU size.
                                    * (TInt32 - default: 0)
                                    */
    
    EGPRSMinAcceptableMaxSDUSize,	/**< 
                                    * Minimum acceptable SDU size.
                                    * (TInt32 - default: 0)
                                    */
    
    EGPRSReqMaxUplinkRate,          /**< 
                                    * Requested maximum bit rates on uplink.
                                    * (TInt32 - default: 0)
                                    */
    
    EGPRSReqMinUplinkRate,          /**< 
                                    * Requested minimum bit rates on uplink.
                                    * (TInt32 - default: 0)
                                    */
    
    EGPRSReqMaxDownlinkRate,        /**< 
                                    * Requested maximum bit rates on downlink.
                                    * (TInt32 - default: 0)
                                    */

    EGPRSReqMinDownlinkRate,        /**< 
                                    * Requested minimum bit rates on downlink.
                                    * (TInt32 - default: 0)
                                    */
    
    EGPRSReqBER,                    /**< 
                                    * Requested target BER.
                                    * Defined in etelqos.h in RPacketQoS::TBitErrorRatio.
                                    * (TUint32 - default: EBERUnspecified)
                                    */
    
    EGPRSMaxBER,                    /**< 
                                    * Maximum acceptable target BER.
                                    * Defined in etelqos.h in RPacketQoS::TBitErrorRatio.
                                    * (TUint32 - default: EBERUnspecified)
                                    */
    
    EGPRSReqSDUErrorRatio,          /**< 
                                    * Requested target SDU error ratio.
                                    * Defined in etelqos.h in RPacketQoS::TSDUErrorRatio.
                                    * (TUint32 - default: ESDUErrorRatioUnspecified)
                                    */
    
    EGPRSMaxSDUErrorRatio,          /**< 
                                    * Maximum acceptable target SDU error ratio.
                                    * Defined in etelqos.h in RPacketQoS::TSDUErrorRatio.
                                    * (TUint32 - default: ESDUErrorRatioUnspecified)
                                    */
    
    EGPRSReqTrafficHandlingPriority,	/**< 
                                        * Requested traffic handling priority.
                                        * Defined in etelqos.h in RPacketQoS::TTrafficHandlingPriority.
                                        * (TUint32 - default: ETrafficPriorityUnspecified)
                                        */
    
    EGPRSMinTrafficHandlingPriority,	/**< 
                                        * Minimum acceptable traffic handling priority.
                                        * Defined in etelqos.h in RPacketQoS::TTrafficHandlingPriority.
                                        * (TUint32 - default: ETrafficPriorityUnspecified)
                                        */
    
    EGPRSReqTransferDelay,          /**< 
                                    * Requested transfer delay(in milliseconds).
                                    * (TInt32 - default: 0)
                                    */
    
    EGPRSMaxTransferDelay,          /**< 
                                    * Maximum acceptable transfer delay(in milliseconds).
                                    * (TInt32 - default: 0)
                                    */
    
    EGPRSReqGuaranteedUplinkRate,       /**< 
                                        * Requested guaranteed bit rates on uplink.
                                        * (TInt32 - default: 0)
                                        */
    
    EGPRSMinGuaranteedUplinkRate,      	/**< 
                                        * Minimum acceptable guaranteed bit rates on uplink.
                                        * (TInt32 - default: 0)
                                        */
    
    EGPRSReqGuaranteedDownlinkRate,  	/**< 
                                        * Requested guaranteed bit rates on downlink.
                                        * (TInt32 - default: 0)
                                        */
    
    EGPRSMinGuaranteedDownlinkRate,	    /**< 
                                        * Minimum acceptable guaranteed bit rates on downlink.
                                        * (TInt32 - default: 0)
                                        */
    
    EGPRSSignallingIndication,		   	/**< 
                                        * Signalling indication.
                                        * (TBool - default: EFalse)
                                        */
    
    EGPRS_ImCnSignallingIndication,     /**< 
                                        * IP Multimeida System (IMS) Core Network (CN) Signalling Indicator.
                                        * (TBool - default: EFalse)
                                        */
    
    EGPRSSourceStatisticsDescriptor,    /**< 
                                        * Static source descriptor.
                                        * Defined in etelqos.h in RPacketQoS::TSourceStatisticsDescriptor.
                                        * (TUint32 - default: ESourceStatisticsDescriptorUnknown)
                                        */
    

    EPacketDataRangeMax = 19999     /**<
                                    * Marks the end of packet data specific
                                    * attributes.
                                    */
    };

/** Enumeration for packet data AP types */
enum TPacketDataApType
    {
    EPacketDataInternetOnly,    ///< Internet-only connection method
    EPacketDataWAPOnly,         ///< WAP-only connection method
    EPacketDataBoth             ///< Connection method supports both WAP and
                                ///< Internet
    };
} // namespace CMManager
    
#endif // CMPLUGINPACKETDATADEF_H
