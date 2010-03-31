/*
* Copyright (c) 2002-2009 Nokia Corporation and/or its subsidiary(-ies).
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
* Description:  RConnectionMonitor provides an interface for an application to
*                get information about active data connection. It also provides
*                a way to close any connection or all the connections.
*
*/

#ifndef __CONNECTIONMONITOR_H
#define __CONNECTIONMONITOR_H

#include <e32base.h>


// ===========================================================================
// TInt attribute constants, used by GetIntAttribute, SetIntAttribute.
// ===========================================================================
//
/** Bearer, defined in TConnMonBearerType.
*/
const TUint KBearer = 1;
/** Network status, defined in TConnMonNetworkStatus.
*/
const TUint KNetworkStatus = 2;
/** Connection status, progress constants are from nifvar.h.
*/
const TUint KConnectionStatus = 3;
/** Protocol, defined in TConnMonProtocolType.
*/
const TUint KProtocolType = 4;
/** Network registration values defined in TConnMonNetworkRegistration.
*/
const TUint KNetworkRegistration = 5;
/** Signal strength in dBm.
*/
const TUint KSignalStrength = 6;
/** WLAN mode, defined in TConnMonNetworkMode.
*/
const TUint KNetworkMode = 7;
/** WLAN connection security mode, defined in TConnMonSecurityMode.
*/
const TUint KSecurityMode = 8;
/** Bearer information, defined in TConnMonBearerInfo.
*/
const TUint KBearerInfo = 9;
/** Acceptable WLAN scan cache age in seconds. Set to -1 to use device
default. Only has meaning if KWlanScanMaxDelay is set to 0.
*/
const TUint KWlanScanCacheLifetime = 10;

/** Network registration values defined in TConnMonNetworkRegistration_v2.
*/
const TUint KNetworkRegistration_v2 = 11;

/** QoS - Not supported.
*/
const TUint KTrafficClass = 30;
/** QoS - Not supported.
*/
const TUint KDeliveryOrder = 31;
/** QoS - Not supported.
*/
const TUint KErroneousSDUDelivery = 32;
/** QoS - Not supported.
*/
const TUint KResidualBitErrorRatio = 33;
/** QoS - Not supported.
*/
const TUint KSDUErrorRatio = 34;


// ===========================================================================
// TUint attribute constants, used by GetUintAttribute, SetUintAttribute.
// ===========================================================================
//
/** Downlink data in bytes.
*/
const TUint KDownlinkData = 100;
/** Uplink data in bytes.
*/
const TUint KUplinkData = 101;
/** Used IAP ID.
*/
const TUint KIAPId = 102;
/** Network ID.
*/
const TUint KNetworkIdentifier = 103;
/** WLAN transmit power in mW.
*/
const TUint KTransmitPower = 104;
/** Current network mode, defined in TConnMonMobilePhoneNetworkMode.
*/
const TUint KMobilePhoneNetworkMode = 105;
/** QoS - Not supported.
*/
const TUint KMaximumBitrateDownlink = 130;
/** QoS - Not supported.
*/
const TUint KMaximumBitrateUplink = 131;
/** QoS - Not supported.
*/
const TUint KMaximumSDUSize = 132;
/** QoS - Not supported.
*/
const TUint KTransferDelay = 133;
/** QoS - Not supported.
*/
const TUint KGuaranteedBitrateDownlink = 134;
/** QoS - Not supported.
*/
const TUint KGuaranteedBitrateUplink = 135;
/** QoS - Not supported.
*/
const TUint KTrafficHandlingPriority = 136;
/** Enables EConnMonConnectionActivityChange events.
0 means off, minimum allowed is 5 seconds.
*/
const TUint KActivityTimeThreshold = 150;
/** Enables EConnMonDownlinkDataThreshold events.
0 means off, minimum allowed is 4096 bytes.
*/
const TUint KDownlinkDataThreshold = 151;
/** Enables EConnMonUplinkDataThreshold events.
0 means off, minimum allowed is 4096 bytes.
*/
const TUint KUplinkDataThreshold = 152;
/** Enables EConnMonBearerAvailabilityChange events.
*/
const TUint KBearerAvailabilityThreshold = 153;
/** Enables EConnMonSignalStrengthChange events.
*/
const TUint KSignalStrengthThreshold = 154;
/** If set, disables EConnMonBearerChange events and enables
EConnMonBearerInfoChange and EConnMonBearerGroupChange events instead.
*/
const TUint KBearerGroupThreshold = 155;
/** Acceptable delay in seconds for receiving WLAN scan results.
If set to 0 (default), KWlanScanCacheLifetime will be used.
*/
const TUint KWlanScanMaxDelay = 160;


// ===========================================================================
// TBool attribute constants, used by GetBoolAttribute, SetBoolAttribute.
// ===========================================================================
//
/** Connection activity.
*/
const TUint KConnectionActive = 200;
/** Bearer availability.
*/
const TUint KBearerAvailability = 201;
/** Packet data availability. Can be blocked if phone call is active and no
dual transfer mode support.
*/
const TUint KPacketDataAvailability = 202;
/** Stop a connection.
*/
const TUint KConnectionStop = 250;
/** Stop all connections.
*/
const TUint KConnectionStopAll = 251;


// ===========================================================================
// TDes attribute constants, used by GetStringAttribute, SetStringAttribute.
// ===========================================================================
//
/** Name of used IAP.
*/
const TUint KIAPName = 300;
/** Name of used access point.
*/
const TUint KAccessPointName = 301;
/** Used telephone number.
*/
const TUint KTelNumber = 302;
/** Name (SSID) of used WLAN.
*/
const TUint KNetworkName = 303;
/** WLAN name (SSID) to be used in SSID scan (KWlanSsidNetworks).
*/
const TUint KWlanSsid = 304;


// ===========================================================================
// TPckgBuf attribute constants, used by GetPckgAttribute.
// ===========================================================================
//
/** Connection start time. See TConnMonTimeBuf.
*/
const TUint KStartTime = 400;
/** All clients using a connection. See TConnMonClientEnumBuf.
*/
const TUint KClientInfo = 401;
/** Basic WLAN scan information. See TConnMonNetworkNamesBuf.
*/
const TUint KNetworkNames = 402;
/** Available IAP IDs. See TConnMonIapInfoBuf.
*/
const TUint KIapAvailability = 403;
/** Deprecated. Old WLAN scan results, use KWlanNetworks instead.
*/
const TUint KWLANNetworks = 404;
/** Available SNAP IDs. See TConnMonSNAPInfoBuf.
*/
const TUint KSNAPsAvailability = 405;
/** Available SNAP IDs, in a more flexible way. See ConnMonIdsArrayPckg.
*/
const TUint KAvailableSNAPsIds = 406;
/** WLAN scan results. See CConnMonWlanNetworksPtrArrayPckg.
*/
const TUint KWlanNetworks = 407;
/** Bearer group information. See TConnMonBearerGroupInfoBuf.
*/
const TUint KBearerGroupInfo = 408;
/** WLAN SSID scan results. Scans for WLANs with a specific SSID.
See CConnMonWlanNetworksPtrArrayPckg.
*/
const TUint KWlanSsidNetworks = 409;
/** Information about the currently used WLAN.
See CConnMonWlanNetworksPtrArrayPckg.
*/
const TUint KWlanCurrentNetwork = 410;
/** Beacon frames from a WLAN scan. See CConnMonWlanProbeRawBuffersPckg.
*/
const TUint KWlanProbeRawBuffers = 411;


/** Base value for plug-in specific attribute IDs.
*/
const TUint KConnMonPluginAttributeBase = 3000000;


/**
* Bearer type.
*/
enum TConnMonBearerType
    {
    EBearerUnknown           = 0,
    EBearerCSD               = 1,  ///< CSD (GSM)
    EBearerWCDMA             = 2,  ///< PSD (WCDMA)
    EBearerLAN               = 3,
    EBearerCDMA2000          = 4,
    EBearerGPRS              = 5,
    EBearerHSCSD             = 6,  ///< HSCSD (GSM)
    EBearerEdgeGPRS          = 7,
    EBearerWLAN              = 8,
    EBearerBluetooth         = 9,
    EBearerVirtual           = 10,
    EBearerVirtualVPN        = 11,
    EBearerWcdmaCSD          = 12, ///< CSD (WCDMA)

    EBearerExternalCSD       = 30, ///< external CSD (GSM)
    EBearerExternalWCDMA     = 31, ///< external PSD (WCDMA)
    EBearerExternalLAN       = 32,
    EBearerExternalCDMA2000  = 33,
    EBearerExternalGPRS      = 34,
    EBearerExternalHSCSD     = 35, ///< external HSCSD (GSM)
    EBearerExternalEdgeGPRS  = 36,
    EBearerExternalWLAN      = 37,
    EBearerExternalBluetooth = 38,
    EBearerExternalWcdmaCSD  = 39, ///< external CSD (WCDMA)
    };

/**
* Bearer specific general connection ID.
*/
enum TConnMonBearerId
    {
    EBearerIdAll        = 0,
    EBearerIdGPRS       = 2000000, ///< Internal/external GPRS and EdgeGPRS
    EBearerIdWCDMA      = 2000001, ///< Internal/external PSD (WCDMA)
    EBearerIdCSD        = 2000002, ///< Internal/external CSD and HSCSD (GSM)
    EBearerIdGSM        = 2000003, ///< Union of EBearerIdGPRS and EBearerIdCSD
    EBearerIdWLAN       = 2000004,
    EBearerIdLAN        = 2000005,
    EBearerIdWcdmaCSD   = 2000006, ///< Internal/external CSD (WCDMA)
    EBearerIdCDMA2000   = 2000007,
    EBearerIdVirtualVPN = 2000008
    };

/**
* Network status.
*/
enum TConnMonNetworkStatus
    {
    EConnMonStatusNotAvailable = 0,
    EConnMonStatusUnattached,
    EConnMonStatusAttached,
    EConnMonStatusActive,
    EConnMonStatusSuspended
    };

/**
* Protocol type (type of PDP). It may not be available for some
* bearers (returns EProtocolTypeUnknown).
*/
enum TConnMonProtocolType
    {
    EProtocolTypeUnknown = 0,
    EProtocolTypeIPv4,
    EProtocolTypeIPv6,
    EProtocolTypeX25,
    EProtocolTypePPP,
    EProtocolTypeCDPD,
    EProtocolTypeIP           ///< Connection uses both IPv4 and IPv6
    };

/**
* Asyncronous request codes.
*/
enum TConnMonAsyncRequest
    {
    EConnMonGetConnectionCount = 1,
    EConnMonGetIntAttribute,
    EConnMonGetUintAttribute,
    EConnMonGetBoolAttribute,
    EConnMonGetStringAttribute,
    EConnMonGetPckgAttribute
    };

/**
* Events sent by Connection Monitor. See SDK documentation for more details.
*/
enum TConnMonEvent
    {
    EConnMonCreateConnection          = 1,
    EConnMonDeleteConnection          = 2,
    EConnMonCreateSubConnection       = 3,  ///< Not supported
    EConnMonDeleteSubConnection       = 4,  ///< Not supported
    EConnMonDownlinkDataThreshold     = 5,
    EConnMonUplinkDataThreshold       = 6,
    EConnMonNetworkStatusChange       = 7,
    EConnMonConnectionStatusChange    = 8,
    EConnMonConnectionActivityChange  = 9,
    EConnMonNetworkRegistrationChange = 10,
    EConnMonBearerChange              = 11,
    EConnMonSignalStrengthChange      = 12, ///< For cellular, not WLAN
    EConnMonBearerAvailabilityChange  = 13,
    EConnMonIapAvailabilityChange     = 14,
    EConnMonTransmitPowerChange       = 15, ///< For WLAN
    EConnMonSNAPsAvailabilityChange   = 16,
    EConnMonNewWLANNetworkDetected    = 17,
    EConnMonOldWLANNetworkLost        = 18,
    EConnMonPacketDataAvailable       = 19,
    EConnMonPacketDataUnavailable     = 20,
    EConnMonBearerInfoChange          = 21,
    EConnMonBearerGroupChange         = 22,

    EConnMonPluginEventBase           = 4000000
    };

/**
* Network registration status. Valid for CSD, GPRS and WCDMA.
*/
enum TConnMonNetworkRegistration
    {
    ENetworkRegistrationNotAvailable = 0,
    ENetworkRegistrationUnknown,
    ENetworkRegistrationNoService,
    ENetworkRegistrationEmergencyOnly,
    ENetworkRegistrationSearching,
    ENetworkRegistrationBusy,
    ENetworkRegistrationHomeNetwork,
    ENetworkRegistrationDenied,
    ENetworkRegistrationRoaming
    };

/**
* Network registration status. Valid for CSD, GPRS and WCDMA.
* New values will be added to the end of the enumeration.
*/
enum TConnMonNetworkRegistration_v2
    {
    ENetworkRegistrationExtNotAvailable = 0,
    ENetworkRegistrationExtUnknown,
    ENetworkRegistrationExtNoService,
    ENetworkRegistrationExtEmergencyOnly,
    ENetworkRegistrationExtSearching,
    ENetworkRegistrationExtBusy,
    ENetworkRegistrationExtHomeNetwork,
    ENetworkRegistrationExtDenied,
    ENetworkRegistrationExtRoamingNational,
    ENetworkRegistrationExtRoamingInternational
    };
    
/**
* QoS. Traffic class.
*/
enum TQosTrafficClass
    {
    EQosTrafficClassConversational = 1,
    EQosTrafficClassStreaming,
    EQosTrafficClassInteractive,
    EQosTrafficClassBackground
    };

/**
* QoS. Delivery order.
*/
enum TQosDeliveryOrder
    {
    EQosDeliveryOrderYes = 1,
    EQosDeliveryOrderNo
    };

/**
* QoS. Delivery of erroneous SDUs.
*/
enum TQosErroneousSDUDelivery
    {
    EQosErroneousSDUDeliveryYes = 1,
    EQosErroneousSDUDeliveryNo,
    EQosErroneousSDUDeliveryUnspecified
    };

/**
* QoS. Residual bit error ratio.
*/
enum TQosBitErrorRatio
    {
    EQosBERFivePerHundred = 1,
    EQosBEROnePerHundred,
    EQosBERFivePerThousand,
    EQosBEROnePerThousand,
    EQosBEROnePerTenThousand,
    EQosBEROnePerMillion
    };

/**
* QoS. SDU error ratio.
*/
enum TQosSDUErrorRatio
    {
    EQosSDUErrorRatioOnePerHundred = 1,
    EQosSDUErrorRatioSevenPerThousand,
    EQosSDUErrorRatioOnePerThousand,
    EQosSDUErrorRatioOnePerTenThousand,
    EQosSDUErrorRatioOnePerHundredThousand
    };

/**
* Client-server requests.
*/
enum TConnMonRequests
    {
    EReqGetConnectionCount            = 0,
    EReqGetConnectionInfo             = 1,
    EReqGetSubConnectionInfo          = 2,
    EReqGetIntAttribute               = 3,
    EReqGetUintAttribute              = 4,
    EReqGetBoolAttribute              = 5,
    EReqGetStringAttribute            = 6,
    EReqGetPckgAttribute              = 7,
    EReqSetIntAttribute               = 8,
    EReqSetUintAttribute              = 9,
    EReqSetBoolAttribute              = 10,
    EReqSetStringAttribute            = 11,
    EReqSetPckgAttribute              = 12,
    EReqCancelAsyncRequest            = 13,
    EReqReceiveEvent                  = 14,
    EReqCancelReceiveEvent            = 15,

    EReqPluginCreateSubSession        = 500,
    EReqPluginCloseSubSession         = 501,
    EReqPluginRegisterAttribute       = 502,
    EReqPluginCancelRegisterAttribute = 503,
    EReqPluginEvent                   = 504,
    EReqPluginGetQuery                = 505,
    EReqPluginCancelGetQuery          = 506,
    EReqPluginAttribute               = 507,

    EReqInternalSetThreshold          = 600,
    EReqInternalResetThreshold        = 601
    };

/**
* WLAN connection modes.
*/
enum TConnMonNetworkMode
    {
    EConnMonInfraStructure = 0,
    EConnMonAdHoc          = 1,
    EConnMonSecureInfra    = 2
    };

/**
* WLAN connection security modes.
*/
enum TConnMonSecurityMode
    {
    EConnMonSecurityOpen   = 0,
    EConnMonSecurityWep    = 1,
    EConnMonSecurity802d1x = 2,
    EConnMonSecurityWpa    = 3,
    EConnMonSecurityWpaPsk = 4
    };

/**
* Network Modes.
*/
enum TConnMonMobilePhoneNetworkMode
    {
    EConnMonNetworkModeUnknown = 0,  ///< Network mode is unknown
    EConnMonNetworkModeUnregistered, ///< ME is not registered
    EConnMonNetworkModeGsm,          ///< GSM/GPRS or DCS1800 network
    EConnMonNetworkModeAmps,         ///< AMPS network (CDMA)
    EConnMonNetworkModeCdma95,       ///< CDMA (IS-95) network
    EConnMonNetworkModeCdma2000,     ///< CDMA (cdma2000) network
    EConnMonNetworkModeWcdma,        ///< WCDMA (UTRA FDD) network
    EConnMonNetworkModeTdcdma        ///< TD-CDMA (UTRA TDD) network (WCDMA)
    };

/** Maximum size of a plug-in's event data.
*/
const TUint KConnMonMaxPluginDataSize = 512;
/** Maximum size of a plug-in's attribute.
*/
const TUint KConnMonMaxStringAttributeLength = 64;

/**
* Package class definition for getting the TTime.
*/
typedef TPckgBuf<TTime> TConnMonTimeBuf;

/** Maximum number of clients contained in TConnMonClientEnum class.
*/
const TUint KConnMonMaxClientUids = 10;

/**
* Class to contain client UIDs of a connection.
*/
class TConnMonClientEnum
    {
public:
    /**
    * Constructor.
    */
    inline TConnMonClientEnum():iCount( 0 )
        {
        }
public:
    /**
    * Number of UIDs in iUid array.
    */
    TUint iCount;
    /**
    * Array for client UIDs.
    */
    TUid iUid[KConnMonMaxClientUids];
    };

/**
* Package class definition for getting the client information.
*/
typedef TPckgBuf<TConnMonClientEnum> TConnMonClientEnumBuf;

/** Maximum number of WLANs contained in TConnMonNetworkNames class.
*/
const TUint KConnMonMaxNetworkCount = 10;

/**
* Class to contain basic WLAN information.
*/
class TConnMonNetwork
{
public:
    /**
    * Constructor.
    */
    inline TConnMonNetwork():iType( 0 ), iSignalStrength( 0 )
        {
        }
public:
    /**
    * WLAN name (SSID).
    */
    TBuf8<32> iName;
    /**
    * WLAN mode, defined in TConnMonNetworkMode.
    */
    TInt8 iType;
    /**
    * Signal strength in dBm. Given as absolute, correct value is negative.
    */
    TUint8 iSignalStrength;
    };

/**
* Class to contain an array of basic WLAN information.
*/
class TConnMonNetworkNames
    {
public:
    /**
    * Constructor.
    */
    inline TConnMonNetworkNames():iCount( 0 )
        {
        }
    /**
    * This method returns the number of WLANs contained in this class.
    *
    * @return Number of WLANs.
    */
    inline TUint Count()
        {
        return iCount;
        }
public:
    /**
    * Number of items in WLAN array.
    */
    TUint iCount;
    /**
    * Array of WLANs.
    */
    TConnMonNetwork iNetwork[KConnMonMaxNetworkCount];
    };

/**
* Package class definition for getting basic WLAN scan information.
*/
typedef TPckgBuf<TConnMonNetworkNames> TConnMonNetworkNamesBuf;

/** Maximum number of IAPs contained in TConnMonIapInfo class.
*/
const TUint KConnMonMaxIAPCount = 25;

/**
* Class representing an IAP.
*/
class TConnMonIap
    {
public:
    /**
    * Constructor.
    */
    inline TConnMonIap():iIapId( 0 )
        {
        }
public:
    /**
    * IAP ID number.
    */
    TUint iIapId;
    };

/**
* Class to contain an array of IAPs.
*/
class TConnMonIapInfo
    {
public:
    /**
    * Constructor.
    */
    inline TConnMonIapInfo():iCount( 0 )
        {
        }
    /**
    * This method returns the number of IAPs contained in this class.
    *
    * @return Number of IAPs.
    */
    inline TUint Count()
        {
        return iCount;
        }
public:
    /**
    * Number of items in IAP array.
    */
    TUint iCount;
    /**
    * Array of IAPs.
    */
    TConnMonIap iIap[KConnMonMaxIAPCount];
    };

/** Package class definiton for getting available IAPs.
*/
typedef TPckgBuf<TConnMonIapInfo> TConnMonIapInfoBuf;

/** Maximum number of SNAPs contained in TConnMonSNAPInfo class.
*/
const TUint KConnMonMaxSNAPsCount = 25;

/**
* Class representing a SNAP.
*/
class TConnMonSNAPId
    {
public:
    /**
    * Constructor.
    */
    inline TConnMonSNAPId():iSNAPId( 0 )
        {
        }
public:
    /**
    * SNAP ID number.
    */
    TUint iSNAPId;
    };

/**
* Class to contain an array of SNAPs.
*/
class TConnMonSNAPInfo
    {
public:
    /**
    * Constructor.
    */
    inline TConnMonSNAPInfo():iCount( 0 )
        {
        }
    /**
    * This method returns the number of SNAPs contained in this class.
    *
    * @return Number of SNAPs.
    */
    inline TUint Count()
        {
        return iCount;
        }
public:
    /**
    * Number of items in SNAP array.
    */
    TUint iCount;
    /**
    * Array of SNAPs.
    */
    TConnMonSNAPId iSNAP[KConnMonMaxSNAPsCount];
    };

/** Package class definiton for getting available SNAPs.
*/
typedef TPckgBuf<TConnMonSNAPInfo> TConnMonSNAPInfoBuf;

/**
* Bearer group definition, new values will be added to the end of the
* enumeration.
*/
enum TConnMonBearerGroup
    {
    EBearerGroupUnknown                    = 0,
    EBearerGroupCellular                   = 0x00000001,
    EBearerGroupNonCellular                = 0x00000002,
    EBearerGroupCellularPacket             = 0x00000004,
    EBearerGroupCircuitSwitched            = 0x00000008,
    EBearerGroup2G                         = 0x00000010,
    EBearerGroup2GPacket                   = 0x00000020,
    EBearerGroup3G                         = 0x00000040,
    EBearerGroup3GPacket                   = 0x00000080,
    EBearerGroupHSPA                       = 0x00000100,
    EBearerGroupLANBased                   = 0x00000200,
    EBearerGroupWLAN                       = 0x00000400,
    EBearerGroupIPOverConnectivityProtocol = 0x00000800,
    EBearerGroupWired                      = 0x00001000,
    EBearerGroupVirtual                    = 0x00002000
    };

/**
* Bearer definition, new values will be added to the end of the enumeration.
* These are used if KBearerInfo attribute is set or in events if
* KBearerGroupThreshold is set.
*/
enum TConnMonBearerInfo
    {
    EBearerInfoUnknown = 0,
    EBearerInfoCSD,
    EBearerInfoWCDMA,
    EBearerInfoLAN,
    EBearerInfoCDMA2000,
    EBearerInfoGPRS,
    EBearerInfoHSCSD,
    EBearerInfoEdgeGPRS,
    EBearerInfoWLAN,
    EBearerInfoBluetooth,
    EBearerInfoVirtual,
    EBearerInfoVirtualVPN,
    EBearerInfoWcdmaCSD,
    EBearerInfoHSDPA,
    EBearerInfoHSUPA,
    EBearerInfoHSxPA
    };

/**
* Class to contain bearer group information.
*/
class TConnMonBearerGroupInfo
    {
public:
    /**
    * Constructor.
    */
    inline TConnMonBearerGroupInfo():
            iInternal( ETrue ),
            iBearerGroups( 0 ),
            iBearerGroups2( 0 )
        {
        }
public:
    /**
    * Connection is internal or external.
    */
    TBool iInternal;
    /**
    * Bearer group bitmask.
    */
    TUint iBearerGroups;
    /**
    * Reserved for future use.
    */
    TUint iBearerGroups2;
    };

/** Package class definiton for getting bearer group information.
*/
typedef TPckgBuf<TConnMonBearerGroupInfo> TConnMonBearerGroupInfoBuf;

/**
* Class to represent a WLAN. Used when reporting WLAN scan results back to a
* client.
*/
NONSHARABLE_CLASS( CConnMonWlanNetwork ) : public CBase
    {
public:
    /** Maximum length of a WLAN name (SSID).
    */
    static const TUint KMaxNameLength = 32;
    /** WLAN BSSID length (mac address).
    */
    static const TUint KWlanBssId = 6;
    /** Reserved for future use.
    */
    static const TUint KExtraCount = 10;

    /**
    * Constructor.
    *
    * @param aName Name (SSID) of the network.
    * @param aConnectionMode Mode of the network.
    * @param aSignalStrength Signal strength of the network.
    * @param aSecurityMode Security mode of the network.
    * @param aBssId Mac address (BSSID) of the base station.
    * @param aVendorData Not in use.
    * @return Pointer to the created CConnMonWlanNetwork object.
    */
    IMPORT_C static CConnMonWlanNetwork* NewL(
            const TBuf<KMaxNameLength>& aName,
            TUint aConnectionMode,
            TUint aSignalStrength,
            TUint aSecurityMode,
            const TBuf8<KWlanBssId>& aBssId,
            const TDesC& aVendorData );

    /**
    * Constructor.
    *
    * @return Pointer to the created empty CConnMonWlanNetwork object.
    */
    IMPORT_C static CConnMonWlanNetwork* NewL();

    /**
    * Copy constructor.
    *
    * @param aConnMonWlanNetwork The object which is copied.
    * @return Pointer to the created CConnMonWlanNetwork object.
    */
    IMPORT_C static CConnMonWlanNetwork* NewL(
            CConnMonWlanNetwork& aConnMonWlanNetwork );

    /**
    * Destructor.
    */
    IMPORT_C ~CConnMonWlanNetwork();

    /**
    * Assignment operator.
    *
    * @param aConnMonWlanNetwork The object which is assigned.
    */
    IMPORT_C CConnMonWlanNetwork& operator=(
            CConnMonWlanNetwork& aConnMonWlanNetwork );

    /**
    * Compares two networks by signal strength.
    *
    * @param aFirst Reference to first WLAN object.
    * @param aSecond Reference to second WLAN object.
    * @return Result of the comparison, 1 if first is less than second, 0 if
    * they are equal and -1 otherwise.
    */
    IMPORT_C static TInt CompareBySignal(
            const CConnMonWlanNetwork& aFirst,
            const CConnMonWlanNetwork& aSecond );

    /**
    * Obtains the name (SSID) of the network.
    *
    * @return Name of the wlan network.
    */
    inline TBuf<KMaxNameLength> Name()
        {
        return iName;
        }

    /**
    * Obtains the connection mode of the network.
    *
    * @return Connection mode (defined in TConnMonNetworkMode).
    */
    inline TUint ConnectionMode()
        {
        return iConnectionMode;
        }

    /**
    * Obtains the signal strength of the network.
    *
    * @return Signal strength in dBm.
    */
    inline TUint SignalStrength()
        {
        return iSignalStrength;
        }

    /**
    * Obtains the security mode of the network.
    *
    * @return Security mode (defined in TConnMonSecurityMode).
    */
    inline TUint SecurityMode()
        {
        return iSecurityMode;
        }

    /**
    * Obtains the mac address (BSSID) of the base station.
    *
    * @return Mac address (BSSID).
    */
    inline TBuf8<KWlanBssId> WlanBssid()
        {
        return iWlanBssId;
        }

    /**
    * Obtains a pointer to vendor specific data buffer.
    * Ownership of the data is NOT transferred. Not in use, use package
    * attribute KWlanProbeRawBuffers instead.
    *
    * @return Pointer to vendor specific data if available.
    */
    inline HBufC* VendorData()
        {
        return iVendorData;
        }

    /**
    * Writes object of class CConnMonWlanNetwork to memory.
    * Ownership of newly created buffer is transferred to caller.
    *
    * @return Pointer to heap descriptor. NULL if memory allocation failed.
    */
    IMPORT_C const HBufC* ToBuf() const;

    /**
    * Reads object of class CConnMonWlanNetwork from memory.
    *
    * @param aPtrC Pointer to the beginning of the CConnMonWlanNetwork object
    * in buffer.
    * @param aConnMonWlanNetwork Pointer to CConnMonWlanNetwork object where
    * unpacked contents are written.
    * @return A Symbian OS error code.
    */
    IMPORT_C static TInt FromPtrC(
            const TPtrC& aPtrC,
            CConnMonWlanNetwork* aConnMonWlanNetwork );

private:
    /**
    * Constructor.
    */
    CConnMonWlanNetwork();

    /**
    * Constructor.
    *
    * @param aName Name (SSID) of the network.
    * @param aConnectionMode Mode of the network.
    * @param aSignalStrength Signal strength of the network.
    * @param aSecurityMode Security mode of the network.
    * @param aBssId Mac address (BSSID) of the base station.
    * @param aVendorData Not in use.
    */
    CConnMonWlanNetwork(
            const TBuf<KMaxNameLength>& aName,
            TUint aConnectionMode,
            TUint aSignalStrength,
            TUint aSecurityMode,
            const TBuf8<KWlanBssId>& aBssId,
            const TDesC& aVendorData );

    /**
    * Second-phase constructor.
    */
    void ConstructL();

private:
    TBuf<KMaxNameLength> iName;   // Network name
    TUint iConnectionMode;        // WLAN mode, see TConnMonNetworkMode
    TUint iSignalStrength;        // Signal strength in absolute dBm
    TUint iSecurityMode;          // See TConnMonSecurityMode
    TBuf8<KWlanBssId> iWlanBssId; // BSSID
    HBufC* iVendorData;           // For vendor specific data
    TUint iExtraBuf[KExtraCount]; // Reserved for future
    };

/** Class definition for a pointer array of CConnMonWlanNetwork objects.
*/
typedef RPointerArray<CConnMonWlanNetwork> RConnMonWlanNetworksPtrArray;

/**
* Class to contain a package of a pointer array of CConnMonWlanNetwork objects.
*/
class CConnMonWlanNetworksPtrArrayPckg : public CBase
    {
public:
    /**
    * Constructor. Constructs the package of an array of pointers to
    * CConnMonWlanNetwork objects on the heap.
    *
    * @param aRef Array of pointers to CConnMonWlanNetwork objects.
    * @param aBufSize Size of the buffer, intended to contain the package.
    */
    CConnMonWlanNetworksPtrArrayPckg(
            const RPointerArray<CConnMonWlanNetwork>& aRef,
            TUint aBufSize );

    /**
    * Constructor. Constructs an empty package on the heap.
    *
    * @param aBufSize Size of the buffer, intended to contain the package.
    */
    IMPORT_C CConnMonWlanNetworksPtrArrayPckg( TUint aBufSize );

    /**
    * Destructor.
    */
    IMPORT_C virtual ~CConnMonWlanNetworksPtrArrayPckg();

    /**
    * Unpacks the package to a pointer array of CConnMonWlanNetwork objects.
    *
    * @param aRef Array that will contain the pointers to unpacked objects.
    */
    IMPORT_C void UnpackToL( RPointerArray<CConnMonWlanNetwork>& aRef ) const;

    /**
    * Obtains a pointer to the package buffer.
    *
    * @return Pointer to the package buffer.
    */
    IMPORT_C HBufC* Buf() const;

private:
    /**
    * Pointer to the package Buffer on the heap.
    */
    HBufC* iBuf;
    };

/**
* Class to represent a WLAN beacon frame. Used when reporting WLAN scan
* results back to a client.
*/
NONSHARABLE_CLASS( CConnMonWlanProbeRawBuffer ) : public CBase
    {
    public:
    /**
    * Constructor.
    *
    * @param aRawBuffer Beacon frame buffer to be copied to this object.
    * @return Pointer to the created CConnMonWlanProbeRawBuffer object.
    */
    IMPORT_C static CConnMonWlanProbeRawBuffer* NewL(
            const HBufC8* aRawBuffer );

    /**
    * Constructor.
    *
    * @return Pointer to the created empty CConnMonWlanProbeRawBuffer object.
    */
    IMPORT_C static CConnMonWlanProbeRawBuffer* NewL();

    /**
    * Copy constructor.
    *
    * @param aConnMonWlanProbeRawBuffer The object which is copied.
    * @return Pointer to the created CConnMonWlanProbeRawBuffer object.
    */
    IMPORT_C static CConnMonWlanProbeRawBuffer* NewL(
            CConnMonWlanProbeRawBuffer& aConnMonWlanProbeRawBuffer );

    /**
    * Destructor.
    */
    IMPORT_C virtual ~CConnMonWlanProbeRawBuffer();

    /**
    * Assignment operator.
    *
    * @param aConnMonWlanProbeRawBuffer The object which is assigned.
    */
    IMPORT_C CConnMonWlanProbeRawBuffer& operator=(
            CConnMonWlanProbeRawBuffer& aConnMonWlanProbeRawBuffer );

    /**
    * Obtains a pointer to the beacon frame buffer.
    *
    * @return Pointer to the beacon frame buffer.
    */
    IMPORT_C HBufC8* RawBuffer() const;

    /**
    * Writes object of class CConnMonWlanProbeRawBuffer to memory.
    * Ownership of newly created buffer is transferred to caller.
    *
    * @return Pointer to heap descriptor, NULL if memory allocation failed.
    */
    const HBufC8* ToBuf() const;

    /**
    * Reads object of class CConnMonWlanProbeRawBuffer from memory.
    *
    * @param aPtrC Pointer to the beginning of the CConnMonWlanProbeRawBuffer
    * object in buffer.
    * @param aConnMonWlanProbeRawBuffer Pointer to CConnMonWlanProbeRawBuffer
    * object where unpacked contents are written.
    * @return A Symbian OS error code.
    */
    static TInt FromPtrC(
            const TPtrC8& aPtrC,
            CConnMonWlanProbeRawBuffer* aConnMonWlanProbeRawBuffer );

private:
    /**
    * Constructor.
    */
    CConnMonWlanProbeRawBuffer();

    /**
    * Second-phase constructor.
    */
    void ConstructL();

    /**
    * Second-phase constructor.
    *
    * @param aRawBuffer Buffer to be copied to this object.
    */
    void ConstructL( const HBufC8* aRawBuffer );

private:
    HBufC8* iRawBuffer; // Beacon frame buffer
    };

/** Class definition for a pointer array of CConnMonWlanProbeRawBuffer objects.
*/
typedef RPointerArray<CConnMonWlanProbeRawBuffer> RConnMonWlanProbeRawBuffersPtrArray;

/**
* Class to contain a package of a pointer array of CConnMonWlanProbeRawBuffer
* objects.
*/
class CConnMonWlanProbeRawBuffersPckg : public CBase
    {
public:
    /**
    * Constructor. Constructs the package of an array of pointers to
    * CConnMonWlanProbeRawBuffer objects on the heap.
    *
    * @param aRef Array of pointers to CConnMonWlanProbeRawBuffer objects.
    * @param aBufSize Size of the buffer, intended to contain the package.
    */
    CConnMonWlanProbeRawBuffersPckg(
            const RConnMonWlanProbeRawBuffersPtrArray& aRef,
            TUint aBufSize );

    /**
    * Constructor. Constructs an empty package on the heap.
    *
    * @param aBufSize Size of the buffer, intended to contain the package.
    */
    IMPORT_C CConnMonWlanProbeRawBuffersPckg( TUint aBufSize );

    /**
    * Destructor.
    */
    IMPORT_C virtual ~CConnMonWlanProbeRawBuffersPckg();

    /**
    * Unpacks the package to a pointer array of CConnMonWlanProbeRawBuffer
    * objects.
    *
    * @param aRef Array that will contain the pointers to unpacked objects.
    */
    IMPORT_C void UnpackToL( RConnMonWlanProbeRawBuffersPtrArray& aRef ) const;

    /**
    * Obtains a pointer to the package buffer.
    *
    * @return Pointer to the package buffer.
    */
    IMPORT_C HBufC8* Buf() const;

    /**
    * Obtains the total number of found WLANs.
    *
    * @return Total count (iBuf[0]).
    */
    IMPORT_C TUint Total() const;

    /**
    * Obtains the number of trasferred WLANs. This will be less than total
    * count if there was not enough memory in buffer to include all found
    * WLANs.
    *
    * @return Transfered count in buffer (iBuf[1]).
    */
    IMPORT_C TUint Count() const;

private:
    /**
    * Pointer to the package buffer on the heap.
    */
    HBufC8* iBuf;
    };

/**
* Interface template for the class T serialization to/from HBuf/TPtr.
* Class T could be any type of class (T, C, etc.).
*/
template <class T>
    class MDesSerializer
    {
public:
    /**
    * Have to pack the object of class T to HBufC.
    * Ownership of newly created pointer is transferred to caller.
    *
    * @return Pointer to the heap descriptor.
    */
    virtual const HBufC* ToBuf() const = 0;

    /**
    * Have to unpack object of class T from aPtrC.
    *
    * @return Constant pointer to the heap descriptor.
    */
    static T FromPtrC( const TPtrC& aPtrC );
    };

/**
* Class representing an ID number.
* MDesSerializer - abstract interface for class serialization.
*/
class TConnMonId : public MDesSerializer<TConnMonId>
    {
public:
    /**
    * Defines the maximum size of the object in TChar's.
    * +1 is for rounding to bigger integer.
    */
    static const TUint KMaxSize = ( sizeof( TUint ) ) / sizeof( TChar ) + 1;

    /**
    * Defines shifts of fields inside the object.
    */
    enum FieldsShifts
        {
        EId = 0
        };

    /**
    * Constructor.
    *
    * @param aId ID number.
    */
    IMPORT_C TConnMonId( TUint aId );

    /**
    * Obtains the ID number.
    *
    * @return ID number.
    */
    IMPORT_C TUint Id() const;

    // From MDesSerializer

    /**
    * Writes object of class TConnMonId to memory.
    * Ownership of newly created buffer is transferred to caller.
    *
    * @return Pointer to heap descriptor, NULL if memory allocation failed.
    */
    IMPORT_C const HBufC* ToBuf() const;

    /**
    * Reads object of class TConnMonId from memory.
    *
    * @param aPtrC Pointer to the beginning of the TConnMonId object in buffer.
    * @return The newly created TConnMonId object.
    */
    IMPORT_C static TConnMonId FromPtrC( const TPtrC& aPtrC );

protected:
    /**
    * ID number.
    */
    const TUint iId;
    };

/** Class definition for an array of TConnMonId objects.
*/
typedef RArray<TConnMonId> RConnMonIdsArray;

/**
* Class to contain a package of an array of TConnMonId objects.
*/
class ConnMonIdsArrayPckg
    {
public:
    /**
    * Constructor. Constructs the package of an array of TConnMonId objects
    * on the heap.
    *
    * @param aRef Array of TConnMonId objects.
    * @param aBufSize Size of the buffer, intended to contain the package.
    */
    ConnMonIdsArrayPckg( const RArray<TConnMonId>& aRef, TUint aBufSize );

    /**
    * Constructor. Constructs an empty package on the heap.
    *
    * @param aBufSize Size of the buffer, intended to contain the package.
    */
    IMPORT_C ConnMonIdsArrayPckg( TUint aBufSize );

    /**
    * Destructor.
    */
    IMPORT_C virtual ~ConnMonIdsArrayPckg();

    /**
    * Unpacks the package to an array of TConnMonId objects.
    *
    * @param aRef Array that will contain the unpacked objects.
    */
    IMPORT_C void UnpackToL( RArray<TConnMonId>& aRef ) const;

    /**
    * Obtains a pointer to the package buffer.
    *
    * @return Pointer to the package buffer.
    */
    IMPORT_C HBufC* Buf() const;

protected:
    /**
    * Pointer to the package buffer on the heap.
    */
    HBufC* iBuf;
    };

// Forward declarations
class CConnMonEventBase;
class CConnMonEventHandler;

/**
* Client application must implement the MConnectionMonitorObserver interface in
* order to receive notifications. MConnectionMonitorObserver::EventL() method
* will be called every time an event arrives.
*
* @lib CONNMON.LIB
*/
class MConnectionMonitorObserver
    {
public:
    /**
    * This method is called every time an event occurs.
    *
    * @param aConnMonEvent The event information.
    */
    virtual void EventL( const CConnMonEventBase &aConnMonEvent ) = 0;
    };

/**
* RConnectionMonitor
*
* @lib CONNMON.LIB
*/
class RConnectionMonitor : public RSessionBase
    {
public:
    /**
    * Constructor.
    */
    inline RConnectionMonitor():
            RSessionBase(),
            iHandler( 0 ),
            iPtrArray(),
            iIndex( 0 )
        {
        }

public:
    /**
    * Connects the client to the Connection Monitor Server. It must be called
    * before any of other methods during the Connection Monitor session.
    *
    * @return KErrNone if successful, a system-wide error code if not.
    */
    IMPORT_C TInt ConnectL();

    /**
    * Closes the Connection Monitor session. An opened RConnectionMonitor must
    * be closed explicitily to prevent a resource (memory) leak.
    */
    IMPORT_C void Close();

    /**
    * Gathers information on currently active connections.
    *
    * @param aConnectionCount On completion, contains the number of active
    * connections.
    * @param aStatus KErrNone if successful, a system-wide error code if not.
    */
    IMPORT_C void GetConnectionCount(
            TUint& aConnectionCount,
            TRequestStatus& aStatus );

    /**
    * Gets the connection ID and the count of the subconnections for the given
    * index. GetConnectionCount() must be called to gather the information on
    * active connections before calling this method.
    *
    * @param aIndex Must be between 1 and the count returned by
    * GetConnectionCount().
    * @param aConnectionId On return, contains the connection ID.
    * @param aSubConnectionCount On return, contains the number of
    * subconnections.
    * @return KErrNone if successful, a system-wide error code if not.
    */
    IMPORT_C TInt GetConnectionInfo(
            const TUint aIndex,
            TUint& aConnectionId,
            TUint& aSubConnectionCount ) const;

    /**
    * Gets the subconnection ID for the given index.
    *
    * @param aConnectionId Connection ID.
    * @param aIndex Must be between 1 and the subconnection count returned by
    * GetConnectionInfo().
    * @param aSubConnectionId On return, contains the subconnection ID.
    * @return KErrNone if successful, a system-wide error code if not.
    */
    IMPORT_C TInt GetSubConnectionInfo(
            const TUint aConnectionId,
            const TUint aIndex,
            TUint& aSubConnectionId ) const;

    /**
    * Gets the value for a TInt attribute.
    *
    * @param aConnectionId Connection ID.
    * @param aSubConnectionId Subconnection ID. If set to 0, method applies to
    * connection.
    * @param aAttribute Identifies the attribute to be retrieved.
    * @param aValue On completion, contains the requested TInt attribute.
    * @param aStatus KErrNone if successful, a system-wide error code if not.
    */
    IMPORT_C void GetIntAttribute(
            const TUint aConnectionId,
            const TUint aSubConnectionId,
            const TUint aAttribute,
            TInt& aValue,
            TRequestStatus& aStatus );

    /**
    * Gets the value for a TUint attribute.
    *
    * @param aConnectionId Connection ID.
    * @param aSubConnectionId Subconnection ID. If set to 0, method applies to
    * connection.
    * @param aAttribute Identifies the attribute to be retrieved.
    * @param aValue On completion, contains the requested TUint attribute.
    * @param aStatus KErrNone if successful, a system-wide error code if not.
    */
    IMPORT_C void GetUintAttribute(
            const TUint aConnectionId,
            const TUint aSubConnectionId,
            const TUint aAttribute,
            TUint& aValue,
            TRequestStatus& aStatus );

    /**
    * Gets the value for a TBool attribute.
    *
    * @param aConnectionId Connection ID.
    * @param aSubConnectionId Subconnection ID. If set to 0, method applies to
    * connection.
    * @param aAttribute Identifies the attribute to be retrieved.
    * @param aValue On completion, contains the requested TBool attribute.
    * @param aStatus KErrNone if successful, a system-wide error code if not.
    */
    IMPORT_C void GetBoolAttribute(
            const TUint aConnectionId,
            const TUint aSubConnectionId,
            const TUint aAttribute,
            TBool& aValue,
            TRequestStatus& aStatus );

    /**
    * Gets the value for a string attribute.
    *
    * @param aConnectionId Connection ID.
    * @param aSubConnectionId Subconnection ID. If set to 0, method applies to
    * connection.
    * @param aAttribute Identifies the attribute to be retrieved.
    * @param aValue On completion, contains the requested string. Use a 16-bit
    * descriptor!
    * @param aStatus KErrNone if successful, a system-wide error code if not.
    */
    IMPORT_C void GetStringAttribute(
            const TUint aConnectionId,
            const TUint aSubConnectionId,
            const TUint aAttribute,
            TDes& aValue,
            TRequestStatus& aStatus ) const;

    /**
    * Gets the value for a packaged attribute.
    *
    * @param aConnectionId Connection ID.
    * @param aSubConnectionId Subconnection ID. If set to 0, method applies to
    * connection.
    * @param aAttribute Identifies the attribute to be retrieved.
    * @param aValue On completion, contains the requested packaged attribute.
    * @param aStatus KErrNone if successful, a system-wide error code if not.
    */
    IMPORT_C void GetPckgAttribute(
            const TUint aConnectionId,
            const TUint aSubConnectionId,
            const TUint aAttribute,
            TDes8& aValue,
            TRequestStatus& aStatus ) const;

    /**
    * Gets the value for a packaged attribute.
    *
    * @param aConnectionId Connection ID.
    * @param aSubConnectionId Subconnection ID. If set to 0, method applies to
    * connection.
    * @param aAttribute Identifies the attribute to be retrieved.
    * @param aValue On completion, contains the requested packaged attribute.
    * @param aStatus KErrNone if successful, a system-wide error code if not.
    */
    IMPORT_C void GetPckgAttribute(
            const TUint aConnectionId,
            const TUint aSubConnectionId,
            const TUint aAttribute,
            TDes16& aValue,
            TRequestStatus& aStatus ) const;

    /**
    * Sets the value for a TInt attribute.
    *
    * @param aConnectionId Connection ID.
    * @param aSubConnectionId Subconnection ID. If set to 0, method applies to
    * connection.
    * @param aAttribute Identifies the attribute to be set.
    * @param aValue The value to be set.
    * @return KErrNone if successful, a system-wide error code if not.
    */
    IMPORT_C TInt SetIntAttribute(
            const TUint aConnectionId,
            const TUint aSubConnectionId,
            const TUint aAttribute,
            const TInt aValue ) const;

    /**
    * Sets the value for a TUint attribute.
    *
    * @param aConnectionId Connection ID.
    * @param aSubConnectionId Subconnection ID. If set to 0, method applies to
    * connection.
    * @param aAttribute Identifies the attribute to be set.
    * @param aValue The value to be set.
    * @return KErrNone if successful, a system-wide error code if not.
    */
    IMPORT_C TInt SetUintAttribute(
            const TUint aConnectionId,
            const TUint aSubConnectionId,
            const TUint aAttribute,
            const TUint aValue ) const;

    /**
    * Sets the value for a TBool attribute.
    *
    * This method can be used to stop a connection (KConnectionStop).
    * @param aConnectionId Connection ID.
    * @param aSubConnectionId Subconnection ID. If set to 0, method applies to
    * connection.
    * @param aAttribute Identifies the attribute to be set.
    * @param aValue The value to be set.
    * @return KErrNone if successful, a system-wide error code if not.
    */
    IMPORT_C TInt SetBoolAttribute(
            const TUint aConnectionId,
            const TUint aSubConnectionId,
            const TUint aAttribute,
            const TBool aValue ) const;

    /**
    * Sets the value for a string attribute.
    *
    * @param aConnectionId Connection ID.
    * @param aSubConnectionId Subconnection ID. If set to 0, method applies to
    * connection.
    * @param aAttribute Identifies the attribute to be set.
    * @param aValue The string value to be set. Must be a 16-bit descriptor.
    * @return KErrNone if successful, a system-wide error code if not.
    */
    IMPORT_C TInt SetStringAttribute(
            const TUint aConnectionId,
            const TUint aSubConnectionId,
            const TUint aAttribute,
            const TDes& aValue ) const;

    /**
    * Sets the value for a packaged attribute. There is currently no packaged
    * attributes that can be set.
    *
    * @param aConnectionId Connection ID.
    * @param aSubConnectionId Subconnection ID. If set to 0, method applies to
    * connection.
    * @param aAttribute Identifies the attribute to be set.
    * @param aValue The value to be set.
    * @return KErrNone if successful, a system-wide error code if not.
    */
    IMPORT_C TInt SetPckgAttribute(
            const TUint aConnectionId,
            const TUint aSubConnectionId,
            const TUint aAttribute,
            const TDes8& aValue ) const;

    /**
    * Cancels an asyncronous request. If there is several active requests of
    * the same type (for example GetIntAttribute), they will all be cancelled.
    * When a request is cancelled, it is completed with error code KErrCancel.
    *
    * @param aReqToCancel Identifies the request type to be cancelled.
    * The different types are defined in TConnMonAsyncRequest.
    */
    IMPORT_C void CancelAsyncRequest( TInt aReqToCancel );

    /**
    * Registers an event observer to catch connection monitor events.
    *
    * @param aObserver The event observer.
    * @return KErrNone if successful, a system-wide error code if not.
    */
    IMPORT_C TInt NotifyEventL( MConnectionMonitorObserver& aObserver );

    /**
    * Cancels the notifications from connection monitor.
    */
    IMPORT_C void CancelNotifications();

private:
    void ReceiveEvent(
            TDes8& aBuffer,
            TDes8& aExtraBuf,
            TRequestStatus& aStatus );
    void CancelReceiveEvent();
    TBool IsConnected() const;
    TPtr8& NextPtr();

private:
    CConnMonEventHandler* iHandler;
    RArray<TPtr8> iPtrArray;
    TInt iIndex;

private:
    friend class CConnMonEventHandler;
    };

/**
* Base class for all ConnMon event types.
*
* Example how to convert an event according to type.
* @code
* void CMyConnMonObserver::EventL( const CConnMonEventBase& aEvent )
*     {
*     switch( aEvent.EventType() )
*         {
*         case EConnMonCreateConnection:
*             CConnMonCreateConnection* realEvent;
*             realEvent = (CConnMonCreateConnection*) &aEvent;
*             //...
* @endcode
*/
NONSHARABLE_CLASS( CConnMonEventBase ) : public CBase
    {
public:
    /**
    * Constructor.
    *
    * @param aEventType Event type.
    * @param iConnectionId Connection ID.
    */
    CConnMonEventBase( const TInt aEventType, const TUint iConnectionId );

    /**
    * Destructor.
    */
    ~CConnMonEventBase();

public:
    /**
    * Gets the type of the event.
    *
    * @return Type of the event. Values are defined in TConnMonEventType.
    */
    IMPORT_C TInt EventType() const;

    /**
    * Gets the connection ID of the connection.
    *
    * @return Connection ID.
    */
    IMPORT_C TUint ConnectionId() const;

private:
    TInt iEventType;
    TUint iConnectionId;
    };

/**
* This event is triggered when a new connection has been created. The
* connection ID passed in the event is a new ID number that ConnMon assigned to
* the new connection.
*
* @lib CONNMON.LIB
*/
NONSHARABLE_CLASS( CConnMonCreateConnection ) : public CConnMonEventBase
    {
public:
    /**
    * Constructor.
    *
    * @param aConnectionId Connection ID.
    */
    CConnMonCreateConnection( const TUint aConnectionId );

    /**
    * Destructor.
    */
    ~CConnMonCreateConnection();
    };

/**
* This event is triggered when a connection has been deleted. The connection ID
* passed in the event is the connection ID of the deleted connection.
*
* @lib CONNMON.LIB
*/
NONSHARABLE_CLASS( CConnMonDeleteConnection ) : public CConnMonEventBase
    {
public:
    /**
    * Constructor.
    *
    * @param aConnectionId Connection ID.
    * @param aDownlinkData Downlink data volume.
    * @param aUplinkData Uplink data volume.
    * @param aAuthDelete Was connection stopped in an authoritative way.
    */
    CConnMonDeleteConnection(
            const TUint aConnectionId,
            const TUint aDownlinkData,
            const TUint aUplinkData,
            const TBool aAuthDelete );

    /**
    * Destructor.
    */
    ~CConnMonDeleteConnection();

public:
    /**
    * Gets the downlink data volume.
    *
    * @return Downlink data volume in bytes.
    */
    IMPORT_C TUint DownlinkData() const;

    /**
    * Gets the uplink data volume.
    *
    * @return Uplink data volume in bytes.
    */
    IMPORT_C TUint UplinkData() const;

    /**
    * Checks if the connection was stopped in an authoritative way.
    * ETrue will be returned if the user has deactivated the connection by
    * using Connection Monitor or if some application has issued
    * RConnection::Stop( RConnection::EStopAuthoritative ).
    *
    * @return ETrue if connection has been deactivated in an authoritative
    * way, otherwise returns EFalse.
    */
    IMPORT_C TBool AuthoritativeDelete() const;

private:
    TUint iDownlinkData;
    TUint iUplinkData;
    TBool iAuthDelete;
    };

/**
* This event is triggered when a new subconnection has been created.
* Subconnections are not supported currently.
*
* @lib CONNMON.LIB
*/
NONSHARABLE_CLASS( CConnMonCreateSubConnection ) : public CConnMonEventBase
    {
public:
    /**
    * Constructor.
    *
    * @param aConnectionId Connection ID.
    * @param aSubConnectionId Subconnection ID.
    */
    CConnMonCreateSubConnection(
            const TUint aConnectionId,
            const TUint aSubConnectionId );

    /**
    * Destructor.
    */
    ~CConnMonCreateSubConnection();

public:
    /**
    * Gets the new subconnection ID.
    *
    * @return Subconnection ID.
    */
    IMPORT_C TUint SubConnectionId() const;

private:
    TUint iSubConnectionId;
    };

/**
* This event is triggered when a subconnection has been deleted.
* Subconnections are not supported currently.
*
* @lib CONNMON.LIB
*/
NONSHARABLE_CLASS( CConnMonDeleteSubConnection ) : public CConnMonEventBase
    {
public:
    /**
    * Constructor.
    *
    * @param aConnectionId Connection ID.
    * @param aSubConnectionId Subconnection ID.
    * @param aDownlinkData Downlink data volume.
    * @param aUplinkData Uplink data volume.
    * @param aAuthDelete Was connection stopped in an authoritative way.
    */
    CConnMonDeleteSubConnection(
            const TUint aConnectionId,
            const TUint aSubConnectionId,
            const TUint aDownlinkData,
            const TUint aUplinkData,
            const TBool aAuthDelete );

    /**
    * Destructor.
    */
    ~CConnMonDeleteSubConnection();

public:
    /**
    * Gets the subconnection ID of the deleted subconnection.
    *
    * @return Subconnection ID.
    */
    IMPORT_C TUint SubConnectionId() const;

    /**
    * Gets the downlink data volume.
    *
    * @return Downlink data volume in bytes.
    */
    IMPORT_C TUint DownlinkData() const;

    /**
    * Gets the uplink data volume.
    *
    * @return Uplink data volume in bytes.
    */
    IMPORT_C TUint UplinkData() const;

    /**
    * Checks if the connection was stopped in an authoritative way.
    * ETrue will be returned if the user has deactivated the connection by
    * using Connection Monitor or if some application has issued
    * RConnection::Stop( RConnection::EStopAuthoritative ).
    *
    * @return ETrue if connection has been deactivated in an authoritative
    * way, otherwise returns EFalse.
    */
    IMPORT_C TBool AuthoritativeDelete() const;

private:
    TUint iSubConnectionId;
    TUint iDownlinkData;
    TUint iUplinkData;
    TBool iAuthDelete;
    };

/**
* This event is triggered when there is a sufficient change in the volume of
* downlink data for a specific connection. The event is sent each time a client
* specified amount (KDownlinkDataThreshold) of new data has been sent. If
* another ConnMon client has requested for these events for the same
* connection, the smallest threshold value will be used globally. If
* KDownlinkDataThreshold is 0 (default), events will not be sent for that
* connection. To prevent rapid flooding of these events, different bearers have
* appropriate minimum threshold values which will be used to override too small
* thresholds when necessary.
*
* @lib CONNMON.LIB
*/
NONSHARABLE_CLASS( CConnMonDownlinkDataThreshold ) : public CConnMonEventBase
    {
public:
    /**
    * Constructor.
    *
    * @param aConnectionId Connection ID.
    * @param aSubConnectionId Subconnection ID.
    * @param aDownlinkData Downlink data volume.
    */
    CConnMonDownlinkDataThreshold(
            const TUint aConnectionId,
            const TUint aSubConnectionId,
            const TUint aDownlinkData );

    /**
    * Destructor.
    */
    ~CConnMonDownlinkDataThreshold();

public:
    /**
    * Gets the subconnection ID.
    *
    * @return Subconnection ID.
    */
    IMPORT_C TUint SubConnectionId() const;

    /**
    * Gets the downlink data volume.
    *
    * @return Downlink data volume in bytes.
    */
    IMPORT_C TUint DownlinkData() const;

private:
    TUint iSubConnectionId;
    TUint iDownlinkData;
    };

/**
* This event is triggered when there is a sufficient change in the volume of
* uplink data for a specific connection. The event is sent each time a client
* specified amount (KUplinkDataThreshold) of new data has been received. If
* another ConnMon client has requested for these events for the same
* connection, the smallest threshold value will be used globally. If
* KUplinkDataThreshold is 0 (default), events will not be sent for that
* connection. To prevent rapid flooding of these events, different bearers have
* appropriate minimum threshold values which will be used to override too small
* thresholds when necessary.
*
* @lib CONNMON.LIB
*/
NONSHARABLE_CLASS( CConnMonUplinkDataThreshold ) : public CConnMonEventBase
    {
public:
    /**
    * Constructor.
    *
    * @param aConnectionId Connection ID.
    * @param aSubConnectionId Subconnection ID.
    * @param aUplinkData Uplink data volume.
    */
    CConnMonUplinkDataThreshold(
            const TUint aConnectionId,
            const TUint aSubConnectionId,
            const TUint aUplinkData );

    /**
    * Destructor.
    */
    ~CConnMonUplinkDataThreshold();

public:
    /**
    * Gets the subconnection ID.
    *
    * @return Subconnection ID.
    */
    IMPORT_C TUint SubConnectionId() const;

    /**
    * Gets the uplink data volume.
    *
    * @return Uplink data volume in bytes.
    */
    IMPORT_C TUint UplinkData() const;

private:
    TUint iSubConnectionId;
    TUint iUplinkData;
    };

/**
* This event is triggered when network status changes for some packet data
* connection. The connection ID passed in the event is a bearer specific
* connection ID (see TConnMonBearerId). The same information can be retrieved
* with TInt attribute KNetworkStatus.
*
* @lib CONNMON.LIB
*/
NONSHARABLE_CLASS( CConnMonNetworkStatusChange ) : public CConnMonEventBase
    {
public:
    /**
    * Constructor.
    *
    * @param aConnectionId Connection ID.
    * @param aNetworkStatus Network status.
    */
    CConnMonNetworkStatusChange(
            const TUint aConnectionId,
            const TInt aNetworkStatus );

    /**
    * Destructor.
    */
    ~CConnMonNetworkStatusChange();

public:
    /**
    * Gets the network status.
    *
    * @return Network status. Values are defined in TConnMonNetworkStatus.
    */
    IMPORT_C TInt NetworkStatus() const;

private:
    TInt iNetworkStatus;
    };

/**
* This event is triggered when the status of some connection changes.
* The same information can be retrieved with TInt attribute KConnectionStatus.
* Connection status values are defined in nifvar.h.
*
* @lib CONNMON.LIB
*/
NONSHARABLE_CLASS( CConnMonConnectionStatusChange ) : public CConnMonEventBase
    {
public:
    /**
    * Constructor.
    *
    * @param aConnectionId Connection ID.
    * @param aSubConnectionId Subconnection ID.
    * @param aConnectionStatus Connection status.
    */
    CConnMonConnectionStatusChange(
            const TUint aConnectionId,
            const TUint aSubConnectionId,
            const TInt aConnectionStatus );

    /**
    * Destructor.
    */
    ~CConnMonConnectionStatusChange();

public:
    /**
    * Gets the subconnection ID.
    *
    * @return Subconnection ID.
    */
    IMPORT_C TUint SubConnectionId() const;

    /**
    * Gets the connection status.
    *
    * @return Connection status. Values are defined in nifvar.h.
    */
    IMPORT_C TInt ConnectionStatus() const;

private:
    TUint iSubConnectionId;
    TInt iConnectionStatus;
    };

/**
* This event is triggered when some connection changes from active to idle or
* vice versa. The client must set KActivityTimeThreshold to receive these
* events. KActivityTimeThreshold defines the period (in seconds) for checking
* wether the connection is active or not. The minimum allowed value is 5
* seconds. The connection is considered active, if data has been passed during
* the last period, otherwise it is considered inactive. The same information
* can be retrieved with TBool attribute KConnectionActive.
*
* @lib CONNMON.LIB
*/
NONSHARABLE_CLASS( CConnMonConnectionActivityChange ) : public CConnMonEventBase
    {
public:
    /**
    * Constructor.
    *
    * @param aConnectionId Connection ID.
    * @param aSubConnectionId Subconnection ID.
    * @param aActivity Connection activity.
    */
    CConnMonConnectionActivityChange(
            const TUint aConnectionId,
            const TUint aSubConnectionId,
            const TBool aActivity );

    /**
    * Destructor.
    */
    ~CConnMonConnectionActivityChange();

public:
    /**
    * Gets the subconnection ID.
    *
    * @return Subconnection ID.
    */
    IMPORT_C TUint SubConnectionId() const;

    /**
    * Gets the connection activity.
    *
    * @return ETrue if the connection is active, EFalse if not.
    */
    IMPORT_C TBool ConnectionActivity() const;

private:
    TUint iSubConnectionId;
    TBool iActivity;
    };

/**
* This event is triggered when network registration status (GSM/GPRS/WCDMA)
* changes. The connection ID passed in the event is a bearer specific
* connection ID (see TConnMonBearerId). The same information can be retrieved
* with TInt attribute KNetworkRegistration. Network registration values are
* defined in TConnMonNetworkRegistration.
*
* @lib CONNMON.LIB
*/
NONSHARABLE_CLASS( CConnMonNetworkRegistrationChange ) : public CConnMonEventBase
    {
public:
    /**
    * Constructor.
    *
    * @param aConnectionId Connection ID.
    * @param aRegistrationStatus Network registration status.
    */
    CConnMonNetworkRegistrationChange(
            const TUint aConnectionId,
            const TInt aRegistrationStatus );

    /**
    * Destructor.
    */
    ~CConnMonNetworkRegistrationChange();

public:
    /**
    * Gets the network registration status.
    *
    * @return Registration status. Values are defined in
    * TConnMonNetworkRegistration.
    */
    IMPORT_C TInt RegistrationStatus() const;

private:
    TInt iRegistrationStatus;
    };

/**
* This event is triggered when bearer type (GPRS/EdgeGPRS/WCDMA) changes. The
* connection ID passed in the event is a bearer specific connection ID, either
* EBearerIdGPRS or EBearerIdWCDMA (see TConnMonBearerId). The new bearer passed
* in the event can be EBearerGPRS, EBearerEdgeGPRS or EBearerWCDMA (see
* TConnMonBearerType). The same information can be retrieved with TInt
* attribute KBearer.
*
* Note: If TUint attribute KBearerGroupThreshold is set, these events are
* disabled and events EConnMonBearerInfoChange and EConnMonBearerGroupChange
* are used instead. Use these events, for example, if HSDPA related information
* is required.
*
* @lib CONNMON.LIB
*/
NONSHARABLE_CLASS( CConnMonBearerChange ) : public CConnMonEventBase
    {
public:
    /**
    * Constructor.
    *
    * @param aConnectionId Connection ID.
    * @param aBearer Bearer.
    */
    CConnMonBearerChange( const TUint aConnectionId, const TInt aBearer );

    /**
    * Destructor.
    */
    ~CConnMonBearerChange();

public:
    /**
    * Gets the new bearer.
    *
    * @return New bearer. Values are defined in TConnMonBearerType.
    */
    IMPORT_C TInt Bearer() const;

private:
    TInt iBearer;
    };

/**
* This event is triggered when signal strength changes. The connection ID
* passed in the event is a bearer specific connection ID (see
* TConnMonBearerId). This event is valid only for cellular (GPRS, WCDMA, etc.)
* bearers and not for other bearers, e.g. WLAN. The client must set
* KSignalStrengthThreshold to 1 to receive these events.
*
* @lib CONNMON.LIB
*/
NONSHARABLE_CLASS( CConnMonSignalStrengthChange ) : public CConnMonEventBase
    {
public:
    /**
    * Constructor.
    *
    * @param aConnectionId Connection ID.
    * @param aSignalStrength Signal strength in dBm.
    */
    CConnMonSignalStrengthChange(
            const TUint aConnectionId,
            const TInt aSignalStrength );

    /**
    * Destructor.
    */
    ~CConnMonSignalStrengthChange();

public:
    /**
    * Gets the signal strength.
    *
    * @return Signal strength in dBm.
    */
    IMPORT_C TInt SignalStrength() const;

private:
    TInt iSignalStrength;
    };

/**
* This event is triggered when the availability of some bearer changes. The
* connection ID passed in the event is a bearer specific connection ID (see
* TConnMonBearerId). The client must set KBearerAvailabilityThreshold to 1 to
* receive these events. Using this event for detecting changes in WLAN
* availability requires WLAN background scanning to be enabled.
*
* @lib CONNMON.LIB
*/
NONSHARABLE_CLASS( CConnMonBearerAvailabilityChange ) : public CConnMonEventBase
    {
public:
    /**
    * Constructor.
    *
    * @param aConnectionId Connection ID.
    * @param aAvailability Availability of the bearer.
    */
    CConnMonBearerAvailabilityChange(
            const TUint aConnectionId,
            const TBool aAvailability );

    /**
    * Destructor.
    */
    ~CConnMonBearerAvailabilityChange();

public:
    /**
    * Gets the availability of the bearer.
    *
    * @return ETrue if the bearer is available, EFalse if not.
    */
    IMPORT_C TBool Availability() const;

private:
    TBool iAvailability;
    };

/**
* This event is triggered when a plug-in sends a bearer specific event that is
* unknown to ConnMon.
*
* @lib CONNMON.LIB
*/
NONSHARABLE_CLASS( CConnMonGenericEvent ) : public CConnMonEventBase
    {
public:
    /**
    * Constructor.
    *
    * @param aType Event type.
    * @param aConnectionId Connection ID.
    * @param aData Pointer to the event data.
    */
    CConnMonGenericEvent(
            const TUint aType,
            const TUint aConnectionId,
            TAny* aData );

    /**
    * Destructor.
    */
    ~CConnMonGenericEvent();

public:
    /**
    * Gets a pointer to the event data.
    * The pointer is valid only inside EventL().
    *
    * @return Pointer to the event data.
    */
    IMPORT_C TAny* Data() const;

private:
    TAny* iData;
    };

/**
* This event is triggered when IAP availability changes. The connection ID
* passed in the event is the generic connection ID EBearerIdAll. The ID numbers
* of available IAPs are included in the event (see TConnMonIapInfo). The same
* information can be retrieved with packaged attribute KIapAvailability.
*
* @lib CONNMON.LIB
*/
NONSHARABLE_CLASS( CConnMonIapAvailabilityChange ) : public CConnMonEventBase
    {
public:
    /**
    * Constructor.
    *
    * @param aConnectionId Connection ID.
    * @param aIapInfoPtr Pointer to the IAP availability information.
    */
    CConnMonIapAvailabilityChange(
            const TUint aConnectionId,
            const TConnMonIapInfo* aIapInfoPtr );

    /**
    * Destructor.
    */
    ~CConnMonIapAvailabilityChange();

public:
    /**
    * Gets the IAP availability information.
    *
    * @return IAP availability information.
    */
    IMPORT_C TConnMonIapInfo IapAvailability() const;

private:
    TConnMonIapInfo iIapInfo;
    };

/**
* This event is triggered when the used WLAN transmit power changes. The
* connection ID passed in the event is the bearer specific connection ID
* EBearerIdWLAN. Transmit power is given in milliwatts (mW). The same
* information can be retrieved with TUint attribute KTransmitPower.
*
* @lib CONNMON.LIB
*/
NONSHARABLE_CLASS( CConnMonTransmitPowerChange ) : public CConnMonEventBase
    {
public:
    /**
    * Constructor.
    *
    * @param aConnectionId Connection ID.
    * @param aTransmitPower Transmit power in mW.
    */
    CConnMonTransmitPowerChange(
            const TUint aConnectionId,
            const TUint aTransmitPower );

    /**
    * Destructor.
    */
    ~CConnMonTransmitPowerChange();

public:
    /**
    * Gets the transmit power.
    *
    * @return Transmit power in mW.
    */
    IMPORT_C TUint TransmitPower() const;

private:
    TUint iTransmitPower;
    };

/**
* This event is triggered when SNAP availability changes. The connection ID
* passed in the event is the generic connection ID EBearerIdAll. The ID numbers
* of available SNAPs are included in the event (see TConnMonSNAPInfo). The same
* information can be retrieved with packaged attributes KSNAPsAvailability and
* KAvailableSNAPsIds.
*
* @lib CONNMON.LIB
*/
NONSHARABLE_CLASS( CConnMonSNAPsAvailabilityChange ) : public CConnMonEventBase
    {
public:
    /**
    * Constructor.
    *
    * @param aConnectionId Connection ID.
    * @param aSNAPsAvailable Number of available SNAPs.
    * @param aSNAPInfoPtr Pointer to the SNAP availability information.
    */
    CConnMonSNAPsAvailabilityChange(
            const TUint aConnectionId,
            const TUint aSNAPsAvailable,
            const TConnMonSNAPInfo* aSNAPInfoPtr );

    /**
    * Destructor.
    */
    ~CConnMonSNAPsAvailabilityChange();

public:
    /**
    * Gets the SNAP availability information.
    *
    * @return SNAP availability information.
    */
    IMPORT_C TConnMonSNAPInfo SNAPAvailability() const;

    /**
    * Gets the number of available SNAPs.
    *
    * @return Number of available SNAPs.
    */
    IMPORT_C TUint SNAPsAvailabile() const;

private:
    TConnMonSNAPInfo iSNAPInfo;
    TUint iSNAPsAvailable;
    };

/**
* This event is triggered when new WLAN networks are detected during a WLAN
* scan. The connection ID passed in the event is the bearer specific connection
* ID EBearerIdWLAN. To receive these events, WLAN background scanning must be
* enabled, or some other mechanism must be used to trigger the necessary WLAN
* scans.
*
* @lib CONNMON.LIB
*/
NONSHARABLE_CLASS( CConnMonNewWLANNetworkDetected ) : public CConnMonEventBase
    {
public:
    /**
    * Constructor.
    *
    * @param aConnectionId Connection ID.
    */
    CConnMonNewWLANNetworkDetected( const TUint aConnectionId );

    /**
    * Destructor.
    */
    ~CConnMonNewWLANNetworkDetected();
    };

/**
* This event is triggered when one or more WLAN networks have been lost since
* the last WLAN scan. The connection ID passed in the event is the bearer
* specific connection ID EBearerIdWLAN. To receive these events, WLAN
* background scanning must be enabled, or some other mechanism must be used to
* trigger the necessary WLAN scans.
*
* @lib CONNMON.LIB
*/
NONSHARABLE_CLASS( CConnMonOldWLANNetworkLost ) : public CConnMonEventBase
    {
public:
    /**
    * Constructor.
    *
    * @param aConnectionId Connection ID.
    */
    CConnMonOldWLANNetworkLost( const TUint aConnectionId );

    /**
    * Destructor.
    */
    ~CConnMonOldWLANNetworkLost();
    };

/**
* This event is triggered when GPRS or WCDMA bearer availability changes, a
* phone call is started, or a phone call ends. The connection ID passed in the
* event is a bearer specific connection ID, either EBearerIdGPRS or
* EBearerIdWCDMA (see TConnMonBearerId).
*
* EConnMonPacketDataUnavailable and EConnMonPacketDataAvailable events form a
* pair. Two events are always sent, one with connection ID EBearerIdGPRS for 2G
* network, and one with connection ID EBearerIdWCDMA for 3G network. The event
* for the network that the phone is not registered to is always of type
* EConnMonPacketDataUnavailable. If the phone does not support dual transfer
* mode and a call is started, a GPRS or WCDMA packet data connection will be
* put on hold. In this scenario, both will be of type
* EConnMonPacketDataUnavailable. The same information can be retrieved with
* TBool attribute KPacketDataAvailability.
*
* @lib CONNMON.LIB
*/
NONSHARABLE_CLASS( CConnMonPacketDataUnavailable ) : public CConnMonEventBase
    {
public:
    /**
    * Constructor.
    *
    * @param aConnectionId Bearer specific connection ID, EBearerIdGPRS or
    * EBearerIdWCDMA.
    */
    CConnMonPacketDataUnavailable( const TUint aConnectionId );

    /**
    * Destructor.
    */
    virtual ~CConnMonPacketDataUnavailable();
    };

/**
* This event is triggered when GPRS or WCDMA bearer availability changes, a
* phone call is started, or a phone call ends. The connection ID passed in the
* event is a bearer specific connection ID, either EBearerIdGPRS or
* EBearerIdWCDMA (see TConnMonBearerId).
*
* EConnMonPacketDataAvailable and EConnMonPacketDataUnavailable events form a
* pair. Two events are always sent, one with connection ID EBearerIdGPRS for 2G
* network, and one with connection ID EBearerIdWCDMA for 3G network. The event
* for the network that the phone is not registered to is always of type
* EConnMonPacketDataUnavailable. If the phone does not support dual transfer
* mode and a call is started, a GPRS or WCDMA packet data connection will be
* put on hold. In this scenario, both will be of type
* EConnMonPacketDataUnavailable. The same information can be retrieved with
* TBool attribute KPacketDataAvailability.
*
* @lib CONNMON.LIB
*/
NONSHARABLE_CLASS( CConnMonPacketDataAvailable ) : public CConnMonEventBase
    {
public:
    /**
    * Constructor.
    *
    * @param aConnectionId Bearer specific connection ID, EBearerIdGPRS or
    * EBearerIdWCDMA.
    */
    CConnMonPacketDataAvailable( const TUint aConnectionId );

    /**
    * Destructor.
    */
    virtual ~CConnMonPacketDataAvailable();
    };

/**
* This event is triggered when there is a change in bearer information for an
* existing connection, or if the network mode changes e.g. from 2G to 3G. For
* connection specific events, the connection ID passed in the event is the
* respective connection specific ID, and for network level events, the
* connection ID is EBearerIdAll. The same connection level information can be
* retrieved with TInt attribute KBearerInfo. The bearer info values are defined
* in TConnMonBearerInfo.
*
* Note: The client needs to set the TUint attribute KBearerGroupThreshold in
* order to receive these events. This also disables EConnMonBearerChange events.
*
* @lib CONNMON.LIB
*/
NONSHARABLE_CLASS( CConnMonBearerInfoChange ) : public CConnMonEventBase
    {
public:
    /**
    * Constructor.
    *
    * @param aConnectionId Connection ID.
    * @param aBearerInfo Bearer information.
    */
    CConnMonBearerInfoChange(
            const TUint aConnectionId,
            const TInt aBearerInfo );

    /**
    * Destructor.
    */
    ~CConnMonBearerInfoChange();

public:
    /**
    * Gets the new bearer information. Values are defined in TConnMonBearerInfo.
    *
    * @return New bearer information.
    */
    IMPORT_C TInt BearerInfo() const;

private:
    TInt iBearerInfo;
    };

/**
* This event is triggered when there is a change in bearer group information
* for an existing connection. The connection ID passed in the event is the
* respective connection specific ID. The same information can be retrieved with
* packaged attribute KBearerGroupInfo. The bearer group bitmask is defined in
* TConnMonBearerGroup.
*
* Note: The client needs to set the TUint attribute KBearerGroupThreshold in
* order to receive these events. This also disables EConnMonBearerChange events.
*
* @lib CONNMON.LIB
*/
NONSHARABLE_CLASS( CConnMonBearerGroupChange ) : public CConnMonEventBase
    {
public:
    /**
    * Constructor.
    *
    * @param aConnectionId Connection ID.
    * @param aBearerGroups1 First bearer group bitmask.
    * @param aBearerGroups2 Second bearer group bitmask.
    * @param aInternal ETrue if connection is internal, EFalse if external.
    */
    CConnMonBearerGroupChange(
            const TUint aConnectionId,
            const TUint aBearerGroups1,
            const TUint aBearerGroups2,
            const TBool aInternal );

    /**
    * Destructor.
    */
    ~CConnMonBearerGroupChange();

public:
    /**
    * Gets the new bearer groups. Values are defined in TConnMonBearerGroup.
    *
    * @param aBearerGroups1 Will contain the first bearer group bitmask.
    * @param aBearerGroups2 Will contain the second bearer group bitmask.
    */
    IMPORT_C void BearerGroups(
            TUint& aBearerGroups1,
            TUint& aBearerGroups2 ) const;

    /**
    * Gets the information whether the current connection bearer is internal
    * or external.
    *
    * @return ETrue if the bearer is internal and EFalse if external.
    */
    IMPORT_C TBool Internal() const;

private:
    TBool iInternal;      // ETrue for internal, EFalse for external connection.
    TUint iBearerGroups1; // Contains the groups as bitmask.
    TUint iBearerGroups2; // Reserved for the future use.
    };

#endif // __CONNECTIONMONITOR_H

// End of file
