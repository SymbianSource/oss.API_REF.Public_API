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
* Description:  Resource headers for Dial Plugins.
*
*/

#ifndef CMPLUGINDIALCOMMONDEFS_H
#define CMPLUGINDIALCOMMONDEFS_H

namespace CMManager
    {
    /// callback timeout in microseconds
    const TUint32 KCallBackTimeOut  = 60000000;

    enum TCmCallType                /// These enums are used to represent
                                    ///< the conn. type Analogue/ISDNv110/ISDNv120
        {
        ECmCallTypeAnalogue,          ///< Analogue
        ECmCallTypeISDNv110,          ///< ISDN v. 110
        ECmCallTypeISDNv120           ///< ISDN v. 120
        };


    enum TCmCallSpeed                       /// These enums are used to represent
                                            ///< the connection speed.
        {
        ECmSpeedAutobaud=0x00000000,          ///< Autodetect
        ECmSpeed9600=0x00000001,              ///< 9600
        ECmSpeed14400=0x00000002,             ///< 14400
        ECmSpeed19200=0x00000003,             ///< 19200
        ECmSpeed28800=0x00000004,             ///< 28800
        ECmSpeed38400=0x00000005,             ///< 38400
        ECmSpeed43200=0x00000006,             ///< 43200
        ECmSpeed56000=0x00000007              ///< 56000
        };

    /// indicated the end of the array in the following max speed array sets
    const TInt KEndOfArray = -1;

    /// the set of max speeds available for CSD analogue
    const TInt KCsdAnalogue[]       = { ECmSpeedAutobaud, ECmSpeed9600, 
                                        ECmSpeed14400, 
                                        KEndOfArray };

    /// the set of speeds available for CSD wcdma analogue
    const TInt KCsdAnalogueWcdma[]  = { ECmSpeedAutobaud, ECmSpeed9600, 
                                        ECmSpeed14400, ECmSpeed28800, 
                                        KEndOfArray};

    /// the set of speeds available for CSD idsn 110
    const TInt KCsdIsdn110[]        = { ECmSpeed9600, ECmSpeed14400, 
                                        KEndOfArray};

    /// the set of speeds available for CSD isdn 110 wcdma
    const TInt KCsdIsdn110Wcdma[]   = { ECmSpeed9600, ECmSpeed14400, 
                                        ECmSpeed28800, ECmSpeed38400, 
                                        KEndOfArray};
    
    /// the set of speeds available for CSD isdn 120
    const TInt KCsdIsdn120[]        = { ECmSpeed9600, ECmSpeed14400, 
                                        KEndOfArray};

    /// the set of speeds available for CSD isdn 120 wcdma
    const TInt KCsdIsdn120Wcdma[]   = { ECmSpeed9600, ECmSpeed14400, 
                                        ECmSpeed28800, ECmSpeed56000,
                                        KEndOfArray};

    /// the set of speeds available for HSCSD analogue
    const TInt KHcsdAnal[]          = { ECmSpeedAutobaud, ECmSpeed9600, 
                                        ECmSpeed14400, ECmSpeed19200, 
                                        ECmSpeed28800, KEndOfArray };

    /// the set of speeds available for HSCSD isdn 110
    const TInt KHcsdIsdn110[]       = { ECmSpeed9600, ECmSpeed14400, 
                                        ECmSpeed19200, ECmSpeed28800, 
                                        ECmSpeed38400, KEndOfArray};

    /// the set of speeds available for HSCSD isdn 120
    const TInt KHcsdIsdn120[]       = { ECmSpeed9600, ECmSpeed14400, 
                                        ECmSpeed19200, ECmSpeed28800,
                                        ECmSpeed43200, KEndOfArray};

    /**
    * These are the common attribute of every dial in/out
    * bearer types.
    */
    enum TConnectionMethodCsdHscsdCommonAttributes
        {
        EPluginDialAttribStart = 10000,     /**<
                                            * Marks the beginning of common dial
                                            * in/out attributes.
                                            */
        
        EDialOut = 10001,                   /**<
                                            * Dial out or in. ETrue means dial out.
                                            * (TBool - default: ETrue)
                                            */
                                            
        EDialCallType = 10002,              /**<
                                            * Call type. See acceptable values 
                                            * in TCmCallType.
                                            * (TUint32 - default: ECmCallTypeAnalogue )
                                            */
                                            
        EDialMaxConnSpeed = 10003,          /**<
                                            * Maximum speed. See acceptable values
                                            * in TCmCallSpeed.
                                            * (TUint32 - default: ECmSpeedAutobaud )
                                            */
        
        EDialDescription = 10100,           /**<
                                            * Application's description of ISP.
                                            * (String - default: none)
                                            */

        EDialType = 10101,                  /**<
                                            * Enum value indicating ISP type, 
                                            * e.g. Internet ISP, WAP ISP. 
                                            * Selected from TCommsDbIspType
                                            * (TUint32 - default: EIspTypeInternetAndWap)
                                            */
                                            
        EDialDefaultTelNum = 10102,         /**<
                                            * Default phone number.
                                            * (Only for dial out)
                                            * (String - default: none)
                                            */
                                            
        EDialDialResolution = 10103,        /**<
                                            * Perform dialling resolution for 
                                            * default phone number?
                                            * (Only for dial out)
                                            * (TBool - default: none)
                                            */

        EDialChargeCard = 10104,            /**<
                                            * Identifier of the chargecard in 
                                            * this ISP.
                                            * (Only for dial out)
                                            * (TUint32 - default: none)
                                            */
                                            
        EDialUseLoginScript = 10105,        /**<
                                            * Use login script?
                                            * (TBool - default: EFalse)
                                            */
                                            
        EDialLoginScript = 10106,           /**<
                                            * Login script (used if Use Login 
                                            * Script is ETrue)
                                            * (String - default: none)
                                            */

        EDialAuthentication = 10107,        /**<
                                            * UNUSED (will eventually point to 
                                            * some authentication table/group)
                                            * (Only for dial in)
                                            * (TUint32 - default: none)
                                            */

        EDialPromptForLogin = 10108,        /**<
                                            * Prompt user for username and password?
                                            * (Only for dial out)
                                            * (TBool - default: EFalse)
                                            */
                                            
        EDialLoginName = 10109,             /**<
                                            * Login name.
                                            * (Only for dial out)
                                            * (String - default: none)
                                            */
                                            
        EDialLoginPassword = 10110,         /**<
                                            * Login password.
                                            * (Only for dial out)
                                            * (String - default: none)
                                            */
                                            
        EDialDisplayPCT = 10111,            /**<
                                            * Display PCT (without scanning 
                                            * script for READ command)?
                                            * (Only for dial out)
                                            * (TBool - default: none)
                                            */
                                            
        EDialIFParams = 10112,              /**<
                                            * Interface parameter string.
                                            * (String - default: none)
                                            */
                                            
        EDialIFNetworks = 10113,            /**<
                                            * Comma separated list of network 
                                            * protocols, e.g. "PPP"
                                            * (String - default: none)
                                            */
                                            
        EDialIFPromptForAuth = 10114,       /**<
                                            * Prompt user for authentication 
                                            * username and password?
                                            * (Only for dial out)
                                            * (TBool - default: EFalse)
                                            */
                                            
        EDialIFAuthName = 10115,            /**<
                                            * Authentication username used by PPP
                                            * (Only for dial out)
                                            * (String - default: none)
                                            */
                                            
        EDialIFAuthPass = 10116,            /**<
                                            * Authentication password used by PPP
                                            * (Only for dial out)
                                            * (String - default: none)
                                            */
                                            
        EDialIFAuthRetries = 10117,         /**<
                                            * Number of times to retry 
                                            * authentication if it fails.
                                            * (TUint32 - default: none)
                                            */
                                            
        EDialIFCallbackEnabled = 10118,     /**<
                                            * Callback enabled?
                                            * (Only for dial out)
                                            * (TBool - default: none)
                                            */
                                            
        EDialIFCallbackType = 10119,        /**<
                                            * Enum value indicating type of 
                                            * callback (if enabled). 
                                            * Selected from TCallbackAction.
                                            * (Only for dial out)
                                            * (TUint32 - default: none)
                                            */
                                            
        EDialIFCallbackInfo = 10120,        /**<
                                            * Info for callback request (if enabled)
                                            * This is an 8-bit string!
                                            * (Only for dial out)
                                            * (String - default: none)
                                            */
                                            
        EDialCallbackTimeout = 10121,       /**<
                                            * Time to wait for callback in 
                                            * microseconds (if enabled)
                                            * (Only for dial out)
                                            * (TUint32 - default: none)
                                            */

        EDialIFServerMode = 10122,          /**<
                                            * When PPP is configured as a server.
                                            * (Only for dial out)
                                            * (TBool - default: none)
                                            */
                                            
        EDialIPAddressFromServer = 10123,   /**<
                                            * Get IP address from server?
                                            * (TBool - default: none)
                                            */
                                            
        EDialIPAddress = 10124,             /**<
                                            * IP address of interface
                                            * (String - default: none)
                                            */
                                            
        EDialIPNetmask = 10125,             /**<
                                            * IP net mask of interface
                                            * (String - default: none)
                                            */
                                            
        EDialIPGateway = 10126,             /**<
                                            * IP address of gateway.
                                            * (String - default: none)
                                            */
                                            
        EDialIPDNSAddressFromServer = 10127,/**<
                                            * Get DNS addresses from server?
                                            * (TBool - default: none)
                                            */
                                            
        EDialIPNameServer1 = 10128,         /**<
                                            * IP Address of primary name server.
                                            * (String - default: none)
                                            */
                                            
        EDialIPNameServer2 = 10129,         /**<
                                            * IP Address of secondary name server.
                                            * (String - default: none)
                                            */
                                            
        EDialIP6DNSAddressFromServer = 10130,/**<
                                            * Get IP6 DNS addresses from server?
                                            * (TBool - default: none)
                                            */
                                            
        EDialIP6NameServer1 = 10131,        /**<
                                            * IP6 Address of primary name server
                                            * (String - default: none)
                                            */
                                            
        EDialIP6NameServer2 = 10132,        /**<
                                            * IP6 Address of secondary name server
                                            * (String - default: none)
                                            */
                                            
        EDialIPAddressLeaseValidFrom = 10133,/**<
                                            * IP address valid from this time, 
                                            * used to store dynamically assigned 
                                            * address lease info.
                                            * (Only for dial out)
                                            * (String - default: none)
                                            */
                                            
        EDialIPAddressLeaseValidTo = 10134, /**<
                                            * IP address valid for use until 
                                            * this time, used to store dynamically 
                                            * assigned address lease info.
                                            * (Only for dial out)
                                            * (String - default: none)
                                            */
                                            
        EDialConfigDaemonManagerName = 10135,/**<
                                            * Name of the ECOM configuration daemon 
                                            * manager component. This component 
                                            * interfaces with the server identified 
                                            * in ISP_CONFIG_DAEMON_NAME. 
                                            * If specified, ISP_CONFIG_DAEMON_NAME 
                                            * should also be specified.
                                            * (Only for dial out)
                                            * (String - default: none)
                                            */
                                            
        EDialConfigDaemonName = 10136,      /**<
                                            * Name of the configuration daemon 
                                            * server. This server is used to 
                                            * provide further configuration for 
                                            * a connection, e.g. dynamic IP address 
                                            * assignment. If specified, 
                                            * ISP_CONFIG_DAEMON_MANAGER_NAME 
                                            * should also be specified.
                                            * (Only for dial out)
                                            * (String - default: none)
                                            */
                                            
        EDialEnableIPHeaderComp = 10137,    /**<
                                            * Enable IP header compression?
                                            * (TBool - default: none)
                                            */
                                            
        EDialEnableLCPExtension = 10138,    /**<
                                            * Enable LCP extension?
                                            * (TBool - default: none)
                                            */
                                            
        EDialDisablePlainTextAuth = 10139,  /**<
                                            * Disable plain text authentication?
                                            * (TBool - default: none)
                                            */

        EDialEnableSWComp = 10140,          /**<
                                            * Enable software compression 
                                            * (e.g. Microsoft, STAC or Predictor 
                                            * compression)?
                                            * (TBool - default: none)
                                            */

        EDialBearerName = 10141,            /**<
                                            * Enum value specifying the name of the 
                                            * bearer, e.g. Asynchronous Modem.
                                            * Selected from 
                                            * RBasicGsmCall::TBearerName
                                            * (TUint32 - default: none)
                                            */

        EDialBearerSpeed = 10142,           /**<
                                            * Enum value specifying the bearer speed 
                                            * from RBasicGsmCall::TBearerSpeed
                                            * (TUint32 - default: none)
                                            */

        EDialBearerCE = 10143,              /**<
                                            * Enum value specifying the bearer CE, 
                                            * e.g. non-transparent. 
                                            * Selected from RbasicGsmCall::TBearerCE
                                            * (TUint32 - default: none)
                                            */

        EDialInitString = 10144,            /**<
                                            * Modem initialisation string to be used 
                                            * when this ISP is in use. 
                                            * This string is copied into the 
                                            * MODEM_ISP_INIT_STRING 
                                            * field by NetDial.
                                            * 8bit string!
                                            * (String- default: none)
                                            */

        EDialBearerService = 10145,         /**<
                                            * Enum of type 
                                            * RMobileCall::TMobileCallDataService.
                                            * (Only for dial out)
                                            * (TUint32 - default: none)
                                            */

        EDialBearerProtocol = 10146,        /**<
                                            * Enum of type 
                                            * RMobileCall::TMobileCallDataProtocol.
                                            * (Only for dial out)
                                            * (TUint32 - default: none)
                                            */

        EDialRLPVersion = 10147,            /**<
                                            * Enum of type 
                                            * RMobileCall::TMobileCallDataRLPVersion.
                                            * (Only for dial out)
                                            * (TUint32 - default: none)
                                            */

        EDialIWFtoMS = 10148,               /**<
                                            * Integer specifying network to 
                                            * MS window size.
                                            * (Only for dial out)
                                            * (TUint32 - default: none)
                                            */

        EDialMStoIWF = 10149,               /**<
                                            * Integer specifying MS to network 
                                            * window size.
                                            * (Only for dial out)
                                            * (TUint32 - default: none)
                                            */

        EDialAckTimer = 10150,              /**<
                                            * Integer specifying rlp ack timeout in 
                                            * microseconds.
                                            * (Only for dial out)
                                            * (TUint32 - default: none)
                                            */

        EDialRetransmissionAttempts = 10151,/**<
                                            * Integer specifying rlp retransmission 
                                            * attempts.
                                            * (Only for dial out)
                                            * (TUint32 - default: none)
                                            */

        EDialResequencePeriod = 10152,      /**<
                                            * Integer specifying resequencing 
                                            * period.
                                            * (Only for dial out)
                                            * (TUint32 - default: none)
                                            */

        EDialV42Compression = 10153,        /**<
                                            * Enum of type TMobileCallDataV42bis.
                                            * (Only for dial out)
                                            * (TUint32 - default: none)
                                            */

        EDialV42CodeWords = 10154,          /**<
                                            * Integer specifying V42bis codewords.
                                            * (Only for dial out)
                                            * (TUint32 - default: none)
                                            */

        EDialV42MaxLength = 10155,          /**<
                                            * Integer specifying V42bis maximum 
                                            * string length.
                                            * (Only for dial out)
                                            * (TUint32 - default: none)
                                            */

        EDialUseEdge = 10156,               /**<
                                            * EDGE parameter used by GSM.
                                            * (TBool - default: none)
                                            */
                                            
        EPluginDialAttribRangeMax = 19999   /**<
                                            * Marks the end of common dial
                                            * in/out attributes.
                                            */
        };



    } // namespace CMManager

#endif // CMPLUGINDIALCOMMONDEFS_H
