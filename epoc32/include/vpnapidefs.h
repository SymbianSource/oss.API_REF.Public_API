/*
* Copyright (c) 2003-2006 Nokia Corporation and/or its subsidiary(-ies).
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
* Description: VPN API definitions.
*
*/


/**  
 @file
 @released
 @publishedPartner
 
 VPN API definitions
 */

#ifndef __VPNAPIDEFS_H__
#define __VPNAPIDEFS_H__

// VPN API error codes
// NOTE! The error code values below MUST be kept in sync with
// the corresponding error code values defined together by
// vpnapi/data/vpnerr.rss and vpnapi/data/vpnerr.ra
const TInt KVpnErrNoPolicyFile                  = -5229;
const TInt KVpnErrNoPolicyInfoFile              = -5230;
const TInt KVpnErrInvalidPolicyFile             = -5231;
const TInt KVpnErrPolicyNotFound                = -5232;
const TInt KVpnErrInvalidCaCertFile             = -5233;
const TInt KVpnErrPeerCertFileMissing           = -5234;
const TInt KVpnErrInvalidUserCertFile           = -5235;
const TInt KVpnErrInvalidUserPrivKeyFile        = -5236;
const TInt KVpnErrImportOngoing                 = -5237;
const TInt KVpnErrPwdChangeOngoing              = -5238;
const TInt KVpnErrPolicyCountChanged            = -5239;
const TInt KVpnErrPolicySizeChanged             = -5239;

// Deprecated error code definitions
const TInt KVpnErrCaCertFileMissing             = -5233;
const TInt KVpnErrUserCertFileMissing           = -5235;
const TInt KVpnErrUserPrivKeyFileMissing        = -5236;

// Other constants
const TInt KMaxIdLength             = 50;
const TInt KMaxNameLength           = 128;
const TInt KMaxVersionLength        = 16;
const TInt KMaxDescriptionLength    = 256;

// Type definitions
typedef TBuf<KMaxIdLength> TVpnPolicyId;
typedef TBuf8<KMaxIdLength> TVpnPolicyId8;

typedef TBuf<KMaxNameLength> TVpnPolicyName;

/**
 * Policy usage status
 */
enum TPolicyUsageStatus
    {
    EUsageStatusUnknown = 1,    ///< For some reason, the usage status could not be found out
    EUsageStatusUnused,         ///< The policy is neither assigned to any IAP nor active
    EUsageStatusAssignedToIap,  ///< The policy is assigned to one or more IAPs but is not currently active
    EUsageStatusActive,         ///< The policy is assigned to one or more IAPs and is currently active
    };

/**
 * Policy PKI status
 */
enum TPolicyPkiStatus
    {
    EPkiStatusUnknown = 1,      ///< For some reason, the PKI status could not be found out
    EPkiStatusReady,            ///< The PKI information is present 
    EPkiStatusNoCert,           ///< At least one of the required certificates is missing 
    EPkiStatusCertExpired,      ///< At least one of the required certificates has expired 
    EPkiStatusCertNotValidYet,  ///< At least one of the required certificates is not yet valid 
    };

/**
 * A compact policy information structure
 */
struct TVpnPolicyInfo
    {
    TVpnPolicyId            iId;            ///< Policy ID
    TVpnPolicyName          iName;          ///< Policy name
    };

/**
 * A more detailed policy information structure
 */
struct TVpnPolicyDetails : public TVpnPolicyInfo
    {
    TBuf<KMaxDescriptionLength> iDescription;   ///< A short description of the policy
    TBuf<KMaxVersionLength>     iVersion;       ///< The version number of the policy
    TBuf<KMaxNameLength>        iIssuerName;    ///< The name of the organization or person who created the policy
    TBuf<KMaxNameLength>        iContactInfo;   ///< The phone number, email address, URL or other kind of issuer contact information
    TPolicyUsageStatus          iUsageStatus;   ///< Policy usage status
    TPolicyPkiStatus            iPkiStatus;     ///< Policy usage status
    };

_LIT(KHiddenPolicyIndicator, "<<HIDDEN>>");

#endif
