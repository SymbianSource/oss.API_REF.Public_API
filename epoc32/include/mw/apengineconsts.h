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
* Description:  Used constants of the ApEngine.
*
*/


#ifndef APENGINE_CONSTS_H
#define APENGINE_CONSTS_H

// Deprecation warning
#warning This header file has been deprecated. Will be removed in one of the next SDK releases.
 
 
#include <ApEngineVer.h>


// ERROR CODES
// Used either as return values or leave codes. Apart from these, system error
// codes can also be returned or leaved with.

/// Attempting to read or write a column which does not exists.
const TInt  KErrInvalidColumn       = -300;

/// The given bearer is not valid.
const TInt  KErrInvalidBearer       = -301;

/// The type of the database is not valid
const TInt  KErrInvalidDatabaseType = -302;

/// The name of the AP is not valid (length = 0)
const TInt  KErrInvalidName         = -303;

const TInt  KErrDescOverflow        = -304;

/// The passed pointer was invalid = NULL
const TInt  KErrNullPointerPassed   = -305;

/// The filter is not valid
const TInt  KErrInvalidFilterType   = -310;

/// The bearer is not valid
const TInt  KErrInvalidBearerType   = -311;

/// The ISP type given is invalid
const TInt  KErrInvalidIspRequest   = -312;

/// Used when the requested value was not specified in the database
const TInt  KErrValueUnspecified    = -323;

const TInt  KApEngineMaxSql              = 255;



/// These constants are used to represent the sorting order used in CApSelect.
const TInt  KEApSortUidAscending         = 0x00000001;  ///< The sorting is
                                                        ///< done according to
                                                        ///< the ID of the
                                                        ///< access points in
                                                        ///< ascending order.
const TInt  KEApSortUidDescending        = 0x00000002;  ///< The sorting is
                                                        ///< done according to
                                                        ///< the ID of the
                                                        ///< access points in
                                                        ///< descending order.
const TInt  KEApSortNameAscending        = 0x00000003;  ///< The sorting is
                                                        ///< done according to
                                                        ///< the name of the
                                                        ///< access points in
                                                        ///< ascending order.
const TInt  KEApSortNameDescending       = 0x00000004;  ///< The sorting is
                                                        ///< done according to
                                                        ///< the name of the
                                                        ///< access points in
                                                        ///< descending order.


/// These enums are used to represent one the filtering criterias in CApSelect.
const TInt  KEApIspTypeInternetOnly     = 0x00000001;   ///< Filter allows only
                                                        ///< access points that
                                                        ///< are capable of
                                                        ///< only internet
                                                        ///< access.
const TInt  KEApIspTypeWAPOnly          = 0x00000002;   ///< Filter allows only
                                                        ///< access points that
                                                        ///< are capable of
                                                        ///< only WAP access.
const TInt  KEApIspTypeInternetAndWAP   = 0x00000004;   ///< Filter allows only
                                                        ///< access points that
                                                        ///< are capable of
                                                        ///< internet AND
                                                        ///< WAP access.
const TInt  KEApIspTypeWAPMandatory     = 0x00000008;   ///< Filter allows only
                                                        ///< access points that
                                                        ///< are capable of
                                                        ///< WAP access AND
                                                        ///< contain mandatory
                                                        ///< WAP settings.
const TInt  KEApIspTypeAll              = 0x00000010;   ///< No filtering is
                                                        ///< done, all access
                                                        ///< points are shown.
const TInt  KEApIspTypeMMSMandatory     = 0x00000020;   ///< Filter allows only
                                                        ///< access points that
                                                        ///< are capable of MMS
                                                        ///< and contain MMS
                                                        ///< mandatory settings
                                                        ///< Starting Page




const TInt KModifiableTextLength        = 100;
const TInt KModifiableLongTextLength    = 1000;


// typedef
enum TApBearerType      /// These enums are used to represent the possible
                        /// bearer types and the filtering criteria
                        /// in CApSelect.
    {
    EApBearerTypeCSD        = 0x00000001,   ///< Filter allows only access
                                            ///< points that has CSD as bearer.
    EApBearerTypeGPRS       = 0x00000002,   ///< Filter allows only access
                                            ///< points that has GPRS as bearer
    EApBearerTypeHSCSD      = 0x00000004,   ///< Filter allows only access
                                            ///< points that has HSCSD
                                            ///< as bearer.

// Will be deprecated, use EApBearerTypeAllBearers instead !
    EApBearerTypeAll        = 0x00000008,   ///< No filtering is done,
                                            ///< all access points are shown.
                                            
    EApBearerTypeCDMA       = 0x00000010,   ///< Filter allows only access
                                            ///< points that has CDMA as bearer
    EApBearerTypeWLAN       = 0x00000020,   ///< Filter allows only access
                                            ///< points that has WLAN as bearer
    EApBearerTypeLAN        = 0x00000040,   ///< Filter allows only access
                                            ///< points that has LAN as bearer
    EApBearerTypeLANModem   = 0x00000080,   ///< Filter allows only access
                                            ///< points with LAN modem bearer
    EApBearerTypeAllBearers = 0xffffffff    ///< No filtering is done,
                                            ///< all access points are shown.
    };


enum TApCallSpeed       /// These enums are used to represent
                        /// the connection speed.
    {
    KSpeedAutobaud=0x00000000,          ///< Autodetect
    KSpeed9600=0x00000001,              ///< 9600
    KSpeed14400=0x00000002,             ///< 14400
    KSpeed19200=0x00000003,             ///< 19200
    KSpeed28800=0x00000004,             ///< 28800
    KSpeed38400=0x00000005,             ///< 38400
    KSpeed43200=0x00000006,             ///< 43200
    KSpeed56000=0x00000007              ///< 56000
    };


enum TApCallType        /// These enums are used to represent
                        /// the conn. type Analogue/ISDNv110/ISDNv120
    {
    ECallTypeAnalogue,          ///< Analogue
    ECallTypeISDNv110,          ///< ISDN v. 110
    ECallTypeISDNv120           ///< ISDN v. 120
    };

const TUint32 KMaxAnalogueSpeed    = KSpeed28800;
const TUint32 KMaxIsdnSpeed        = KSpeed43200;

//if WCDMA is enabled, then the max speed are :
const TUint32 KMaxAnalogueSpeedWcdma    = KSpeed28800;
const TUint32 KMaxIsdnSpeedWdma         = KSpeed56000;


enum TIPvType
    {
    EIPv4       = 1,
    EIPv6       = 2
    };


enum TWlanNetMode
    {
    EAdhoc       = 0,
    EInfra       = 1
    };


enum TWlanSecMode
    {
    EOpen       = 1,
    EWep        = 2,
    E802_1x     = 4,
    EWpa        = 8,
    EWpa2       = 16
    };


#define KApMaxConnNameLength            30

// The following constants are deprecated, DO NOT USE THEM!
// DO NOT USE STARTS
#define KApMaxGprsApNameLength          100
#define KApMaxLoginNameLength           32
#define KApMaxStartPageLength           1000
#define KApMaxAccessNumLength           21
#define KApCBInfoLength                 21
#define KApMaxServiceCentreAddrLength   21
#define KApMaxIpAddressLength           100
#define KApMaxLoginScriptLength         1000
#define KApMaxLoginPasswordLength       20
// DO NOT USE ENDS


_LIT( KSqlSelectNum, "SELECT %s from %s WHERE %s=%d" );
_LIT( KSqlSelectBaseNum, "SELECT * from %s WHERE %s=%d" );

/// 'Dynamic' IP address to use in comparisons
_LIT( KDynIpAddress, "0.0.0.0" );

/// A start page, which have to be considered as invalid.
_LIT( KInvStartPage, "http://" );

/// A name for the 'location' to use
_LIT( KLocation, "Mobile" );


/// Modem bearer names for (HS)CSD Access Points
_LIT( KModemBearerCSD, "CSD Modem" ); 

/// Modem bearer names for GPRS/WCDMA Access Points
_LIT( KModemBearerGPRS, "GPRS Modem" );

/// Modem bearer names for CDMA Access Points
_LIT( KModemBearerCDMA, "CDMA Modem" );

/// Modem bearer names for WLAN Access Points
_LIT( KModemBearerWLAN, "WLANBearer" );

/// Modem bearer names for LAN Access Points
_LIT( KModemBearerLAN, "LANBearer" );

/// Modem bearer names for LAN Modem Access Points
_LIT( KModemBearerLANModem, "LANModem" );


/// Number of retries that are used in database operations
const TInt KRetryCount              = 5;


/// Time to wait before retry database operation 
// (==0.10 secs = 100000microsec.)
#define KRetryWait  100000 /* in TTimeIntervalMicroSeconds32 */

// callback timeout in microseconds
const TUint32 KCallBackTimeOut  = 60000000;

_LIT( KDynIpv6Address, "0:0:0:0:0:0:0:0" );


_LIT( KDaemonManagerName, "NetCfgExtnDhcp" );
_LIT( KConfigDaemonName, "!DhcpServ" );


#endif

// End of File
