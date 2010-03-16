/*
* Copyright (c) 2001-2009 Nokia Corporation and/or its subsidiary(-ies).
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
* Description: 
* General Security Definitions
*
*/




/**
 @file 
 @internalAll
*/
 
#ifndef __SECURITYDEFS_H__
#define __SECURITYDEFS_H__

#include <e32std.h>
#include <e32base.h>

/** General Security Definitions */

// Old keystore interface, deprecated //////////////////////////////////////////

/**
 * What a key can be used for.
 * The values this can take are defined in TKeyUsageVals.
 *
 * @publishedAll
 * @deprecated
 */
typedef TInt TKeyUsage;

/**
 * What a key can be used for.
 *
 * These values can be ORed together if a key has several usages. EAllKeyUsages
 * is used when searching for all keys, rather than ones with a particular
 * usage.  As these can be combined, TKeyUsage is used to store them.
 *
 * @publishedAll
 * @deprecated
 */
enum TKeyUsageVals
	{
    EDigitalSignature =  0x80000000,
    ENonRepudiation =  0x40000000,
    EKeyEncipherment =  0x20000000,
    EDataEncipherment =  0x10000000,
    EKeyAgreement =   0x08000000,
    EKeyCertSign =   0x04000000,
    ECRLSign =    0x02000000,
    EEncipherOnly =   0x01000000,
    EDecipherOnly =   0x00800000,
    EAllKeyUsages =   -1
	};

// End of deprecated keystore API //////////////////////////////////////////////

/**
 * What a key can be used for - PKCS#15 scheme.
 *
 * @publishedAll
 * @released
 */
enum TKeyUsagePKCS15
	{
	EPKCS15UsageEncrypt				= 0x001,
	EPKCS15UsageDecrypt				= 0x002,
	EPKCS15UsageSign				= 0x004,
	EPKCS15UsageSignRecover			= 0x008,
	EPKCS15UsageWrap				= 0x010,
	EPKCS15UsageUnwrap				= 0x020,	
	EPKCS15UsageVerify				= 0x040,
	EPKCS15UsageVerifyRecover		= 0x080,
	EPKCS15UsageDerive				= 0x100,
	EPKCS15UsageNonRepudiation		= 0x200,
	// Common combinations
	EPKCS15UsageEncryptWrap         = 0x011,
	EPKCS15UsageVerifyVerifyRecover = 0x0C0,
	EPKCS15UsageDecryptUnwrap       = 0x022,
	EPKCS15UsageSignSignRecover     = 0x00C,
	EPKCS15UsageVerifyEncrypt       = 0x0D1,
	EPKCS15UsageSignDecrypt         = 0x02E,
	// For use in filters to return all keys
	EPKCS15UsageAll					= 0xffffffff,
	EPKCS15UsageNone				= 0x00000000
	};

inline TKeyUsagePKCS15 operator|(TKeyUsagePKCS15 aLeft, TKeyUsagePKCS15 aRight);
inline TKeyUsagePKCS15 operator&(TKeyUsagePKCS15 aLeft, TKeyUsagePKCS15 aRight);
inline const TKeyUsagePKCS15& operator|=(TKeyUsagePKCS15& aLeft, TKeyUsagePKCS15 aRight);
inline const TKeyUsagePKCS15& operator&=(TKeyUsagePKCS15& aLeft, TKeyUsagePKCS15 aRight);

/**
 * What a key can be used for - X.509 scheme.
 *
 * @publishedAll
 * @released
 */
enum TKeyUsageX509
	{
	EX509UsageDigitalSignature		= 0x80000000,
	EX509UsageNonRepudiation		= 0x40000000,
	EX509UsageKeyEncipherment		= 0x20000000,
	EX509UsageDataEncipherment		= 0x10000000,
	EX509UsageKeyAgreement			= 0x08000000,
	EX509UsageKeyCertSign			= 0x04000000,
	EX509UsageCRLSign				= 0x02000000,
	EX509UsageEncipherOnly			= 0x01000000,
	EX509UsageDecipherOnly			= 0x00800000,
	// Values for commonly permitted combinations
	EX509UsageAnySign               = 0x86000000,
	EX509UsageAllEncipher           = 0x30000000,
	EX509UsageAllSignEncipher       = 0xB6000000,
	/// For use in filters to return all keys
	EX509UsageAll					= 0xffffffff,
	EX509UsageNone					= 0x00000000
	};

inline TKeyUsageX509 operator|(TKeyUsageX509 aLeft, TKeyUsageX509 aRight);
inline TKeyUsageX509 operator&(TKeyUsageX509 aLeft, TKeyUsageX509 aRight);
inline const TKeyUsageX509& operator|=(TKeyUsageX509& aLeft, TKeyUsageX509 aRight);
inline const TKeyUsageX509& operator&=(TKeyUsageX509& aLeft, TKeyUsageX509 aRight);

/** 
 *
 *
 * @param aUsage
 * @return
 */
IMPORT_C TKeyUsageX509 KeyUsagePKCS15ToX509(TKeyUsagePKCS15 aUsage);

/** 
 *
 *
 * @param aUsage
 * @return
 */
IMPORT_C TKeyUsagePKCS15 KeyUsageX509ToPKCS15Private(TKeyUsageX509 aUsage);

/** 
 *
 *
 * @param aUsage
 * @return
 */
IMPORT_C TKeyUsagePKCS15 KeyUsageX509ToPKCS15Public(TKeyUsageX509 aUsage);

/**
 * Supported types of certificate format. Note these must be only 1 byte long as
 * the file cert store only seralises them as 1 byte.
 * 
 * @publishedAll
 * @released
 */
enum TCertificateFormat
	{
    EX509Certificate    = 0x00,
    EWTLSCertificate    = 0x01,
	EX968Certificate    = 0x02,
	EUnknownCertificate = 0x0f,
	EX509CertificateUrl = 0x10,
	EWTLSCertificateUrl = 0x11,
	EX968CertificateUrl = 0x12
	};

/**
 * The owner of a certificate.
 * 
 * @publishedAll
 * @released
 */
enum TCertificateOwnerType
	{
	ECACertificate,
	EUserCertificate,
	EPeerCertificate
	};

/** The length of a SHA-1 hash 
 * 
 * @publishedAll
 * @released
 */
const TInt KSHA1HashLengthBytes = 20;

/**
 * A SHA-1 hash.
 * 
 * @publishedAll
 * @released
 */
typedef  TBuf8<KSHA1HashLengthBytes> TSHA1Hash;

//const TInt KMD5HashLengthBytes = 16;
//typedef TMD5Hash TBufC8<KMD5HashLengthBytes>;

/**
 * A SHA-1 hash is also used as a key identifier.
 * 
 * @publishedAll
 * @released
 */
typedef TSHA1Hash TKeyIdentifier;

/**
 * Errors that can occur when validating a certificate chain.
 * 
 * Except EValidatedOK, all these are fatal errors unless specified.
 *
 * @publishedAll
 * @released
 */
enum TValidationError
	{
	/** Validation OK */
	EValidatedOK,
	/** Certificate chain has no root */
	EChainHasNoRoot,
	/** Invalid signature  */
	ESignatureInvalid,
	/** Date out of range */
	EDateOutOfRange,
	/** Name is excluded */
	ENameIsExcluded,
	/** Name is not permitted */
	ENameNotPermitted,	//subtle difference here!
	/** Not a CA certificate */
	ENotCACert,
	/** Certificate revoked */
	ECertificateRevoked,
	/** Unrecognized critical extension */
	EUnrecognizedCriticalExtension,
	/** No basic constraint in CA certificate */
	ENoBasicConstraintInCACert,
	/** No acceptable policy */
	ENoAcceptablePolicy,
	/** Path too long */
	EPathTooLong,
	/** Negative path length specified */
	ENegativePathLengthSpecified,
	/** Names do not chain */
	ENamesDontChain,
	/** Required policy not found */
	ERequiredPolicyNotFound,
	/** Bad key usage */
	EBadKeyUsage,
	/** 
	 * Root certificate not self-signed.
	 * 
	 * We cannot tell if this is fatal or not, as we lack the context.
	 */
	ERootCertNotSelfSigned,
	/** 
	 * Critical extended key usage
	 * 
	 * We cannot tell if this is fatal or not, as we lack the context.
	 */
	ECriticalExtendedKeyUsage,
	/** 
	 * Critical certificate policies with qualifiers
	 * 
	 * We cannot tell if this is fatal or not, as we lack the context.
	 */
	ECriticalCertPoliciesWithQualifiers,
	/** 
	 * Critical policy mapping
	 * 
	 * We cannot tell if this is fatal or not, as we lack the context.
	 */
	ECriticalPolicyMapping,
	/** 
	 * Critical Device Id
	 * 
	 * We cannot tell if this is fatal or not, as we lack the context.
	 */
	ECriticalDeviceId,
	/** 
	 * Critical Sid
	 * 
	 * We cannot tell if this is fatal or not, as we lack the context.
	 */
	ECriticalSid,
	/** 
	 * Critical Vid
	 * 
	 * We cannot tell if this is fatal or not, as we lack the context.
	 */
	ECriticalVid,
	/** 
	 * Critical Capabilities
	 * 
	 * We cannot tell if this is fatal or not, as we lack the context.
	 */
	ECriticalCapabilities
	};

// Certificate Applicability UIDs

/**
 * This UID is associated with certificates which are trusted for 
 * software installation of native applications. 
 *
 * @see MCertStore::Applications
 * @see MCTWritableCertStore::SetApplicability
 *
 * @publishedPartner
 * @released
 */
const TUid KSwiApplicabilityUid = {0x100042AB};

/**
 * This UID is associated with certificates which are trusted for 
 * OCSP checks.
 *
 * @see MCertStore::Applications
 * @see MCTWritableCertStore::SetApplicability
 *
 * @publishedPartner
 * @released
 */
const TUid KSwiOcspApplicabilityUid = {0x1000A8B6};

/**
 * This UID is associated with certificates which are trusted for 
 * Java midlet installation.
 *
 * @see MCertStore::Applications
 * @see MCTWritableCertStore::SetApplicability
 *
 * @publishedPartner
 * @released
 */
const TUid KMidletInstallApplicabilityUid = {0x101F9B28};

/**
 * This UID is associated with certificates which are trusted for 
 * SSL/TLS connectivity.
 *
 * @see MCertStore::Applications
 * @see MCTWritableCertStore::SetApplicability
 *
 * @publishedPartner
 * @released
 */
const TUid KTlsApplicabilityUid = {0x1000183D};

/**
 * This OID is associated with X.509 certificates
 * trusted for TLS WWW server authentication.
 *
 * @publishedPartner
 * @released
 */
_LIT(KServerAuthOID,"1.3.6.1.5.5.7.3.1");

/**
 * This OID is associated with X.509 certificates
 * trusted for TLS WWW client authentication.
 *
 * @publishedPartner
 * @released
 */
 // SSL Client
 _LIT(KClientAuthOID,"1.3.6.1.5.5.7.3.2");

/**
 * This OID is associated with X.509 certificates
 * trusted for signing of downloadable executable code.
 *
 * @publishedPartner
 * @released
 */
_LIT(KCodeSigningOID,"1.3.6.1.5.5.7.3.3");

/**
 * This OID is associated with X.509 certificates
 * trusted for email protection .
 *
 * @publishedPartner
 * @released
 */
_LIT(KEmailProtectionOID,"1.3.6.1.5.5.7.3.4");

/**
 * This OID is associated with X.509 certificates
 * trusted for Ipsec end system.
 *
 * @publishedPartner
 * @released
 */
_LIT(KIpsecEndSystemOID,"1.3.6.1.5.5.7.3.5");

/**
 * This OID is associated with X.509 certificates
 * trusted for Ipsec tunnel.
 *
 * @publishedPartner
 * @released
 */
_LIT(KIpsecTunnelOID,"1.3.6.1.5.5.7.3.6");

/**
 * This OID is associated with X.509 certificates
 * trusted for Ipsec user.
 *
 * @publishedPartner
 * @released
 */
_LIT(KIpsecUserOID, "1.3.6.1.5.5.7.3.7");

/**
 * This OID is associated with X.509 certificates
 * trusted for binding the hash of an object to a time.
 *
 * @publishedPartner
 * @released
 */
_LIT(KTimeStampingOID,"1.3.6.1.5.5.7.3.8");

/**
 * This OID is associated with X.509 certificates
 * trusted for signing OCSP responses.
 *
 * @publishedPartner
 * @released
 */
_LIT(KOCSPSigningOID,"1.3.6.1.5.5.7.3.9");



#include "securitydefs.inl"

#endif
