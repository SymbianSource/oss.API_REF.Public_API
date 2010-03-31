/*
* Copyright (c) 2005 - 2009 Nokia Corporation and/or its subsidiary(-ies).
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
* Description:  Contains the OMA DRM CAF Agent specific data types, commands
*                and attributes
*
*/



#ifndef OMA2AGENT_H
#define OMA2AGENT_H

//  INCLUDES
#include <caf/caftypes.h>

// CONSTANTS
_LIT(KOmaDrm2AgentName, "OMA DRM Agent");
_LIT8(KOma1DrmMessageContentType, "application/vnd.oma.drm.message");
_LIT8(KOma1XmlRoContentType, "application/vnd.oma.drm.rights+xml");
_LIT8(KOma1WbxmlRoContentType, "application/vnd.oma.drm.rights+wbxml");
_LIT8(KOma2RoContentType, "application/vnd.oma.drm.roap-pdu+xml");
_LIT8(KOma2ProtectedRoType, "application/vnd.oma.drm.ro+xml");
_LIT8(KOma2TriggerContentType, "application/vnd.oma.drm.roap-trigger+xml");
_LIT8(KOma1DcfContentType, "application/vnd.oma.drm.content");
_LIT8(KOma2DcfContentType, "application/vnd.oma.drm.dcf");
_LIT8(KOmaImportContentType, "application/x-vnd.oma.drm.import");
_LIT8(KOmaImportMimeTypeField, "Content-type");
_LIT8(KOmaImportRightsField, "Rights");
_LIT8(KOma2DcfRoBoxId, "cid:Oma2DcfRightsObjectBox@localhost");
_LIT8(KOma2DcfTransactionBoxId, "cid:Oma2DcfTransactionBox@localhost");
_LIT8(KOma2DcfBranding, "\000\000\000\024ftypodcf\000\000\000\002odcf");
_LIT8(KCafMimeType, "application/x-caf");
_LIT(KOma1DcfExtension, ".dcf");
_LIT(KOma2DcfExtension, ".odf");
_LIT(KOma2DcfExtensionAudio, ".o4a");
_LIT(KOma2DcfExtensionVideo, ".o4v");

// DATA TYPES

// Transport scheme for encrypted rights objects

enum TKeyTransportScheme
    {
    EOma,
    ECmlaIp1,
    ECmlaIp2,
    ECmlaIp3,
    ECmlaIp4,
    ECmlaIp5,
    ECmlaIp6,
    ECmlaIp7,
    };

namespace ContentAccess
{
// Agent specific attribute identifiers

enum TOma2AgentAttribute
    {
    EFileType = EAgentSpecificAttributeBase + 1,
    EPreviewType,
    ESilentRightsType,
    EDeliveryMethod,
    ERecordingYear
    };

enum TOma2AgentStringAttribute
    {
    EInstantPreviewUri = EAgentSpecificAttributeBase + 1,
    EPreviewRightsUri,
    ERightsIssuerUrl,
    ESilentRightsUrl,
    ETransactionTrackingId,
    EEmbeddedRightsObject,
    EGroupId,
    EDomainRightsIssuerUrl,
    EDomainId,
    EDomainRightsIssuerId,
    EContentVendor,
    ECopyright,
    EContentName,
    EOmaDrmContentLocation,
    EOmaDrmContentVersion,
    EPerformer,
    EOmaDrmGenre,
    ERatingInfo,
    EClassificationInfo,
    EKeyword,
    ELocInfoName,
    ELocInfoAstronomicalBody,
    ELocInfoAdditionalNotes,
    EAlbumTitle,
    EAlbumTrack,
    ECoverUri,
    ELyricsUrl,
    EFileName
    };

// File types
// EOma1DcfBased, The file type is derived from Oma1Dcf but has some extensions to it
enum
    {
    ENoDcf = 0,
    EOma1Dcf = 1,
    EOma2Dcf = 2,
    EOma1DcfBased = 4 
    };

// Delivery method

enum TOmaDrmDeliveryMethod
    {
    EOmaDrm1LocalDataFile,
    EOmaDrm1ForwardLock,
    EOmaDrm1ForwardLockDcf,
    EOmaDrm1CombinedDelivery,
    EOmaDrm1CombinedDeliveryDcf,
    EOmaDrm1SeparateDelivery,
    EOmaDrm2
    };

// Encryption methods for OMA DRM 2 DCF files

enum TEncryptionMethod
    {
    EMethodNULL = 0x00,
    EMethodAES_128_CBC = 0x01,
    EMethodAES_128_CTR = 0x02
    };

// Padding options

enum TEncryptionPadding
    {
    EPaddingNone = 0x00,
    EPaddingRFC_2630 = 0x01
    };

// Rights refresh and preview options

enum TSilentRefresh
    {
    ENoSilentRefresh = 0x00,
    EOnDemand = 0x01,
    EInAdvance = 0x02
    };

enum TPreview
    {
    ENoPreview = 0x00,
    EInstantPreview = 0x01,
    EPreviewRights = 0x02
    };

// Rights Object version (stored in the iVersionMain field of the version)

enum
    {
    EOma1Rights = 1,
    EOma2Rights = 2,
    ECmlaRights = 3
    };

// Agent specific commands

enum
    {
    /**
    * Embed any present domain RO into a CContent object
    * Works as an agent specific command for CContent
    * Input buffer: unused
    * Output buffer: unused
    */
    EEmbedDomainRo,

    /**
    * Return the supported OMA DRM methods
    * Works as an agent specific command for CManager
    * Input buffer: unused
    * Output buffer: String containing the following tokens
    *                FL if OMA DRM 1.0 Forward Lock is supported
    *                CD if OMA DRM 1.0 Combined Delivery is supported
    *                SD if OMA DRM 1.0 Separate Delivery is supported
    *                OMADRM2 if OMA DRM 2.0 is supported
    */
    EOmaDrmMethods,

    /**
    * Set the value of the x-oma header
    * works as an agent specific command for CManager
    * Input buffer: String containing the following data
    *               4 bytes(TInt) | ContentURI
    * Output buffer: unused
    */
    ESetPendingRightsETA,

    /**
    * Checks whether a memory buffer contains an OMA DRM 1.0 DCF
    * Input buffer: Memory buffer to check
    * Output buffer: unused
    * Return value: KErrNone if the buffer contains a DCF
    */
    EBufferContainsOma1Dcf,

    /**
    * Decrypt an OMA DRM 1.0 DCF memory buffer
    * Input buffer: Intent of the decryption (EPlay, ...) in the first byte,
    *               followed by the memory buffer to decrypt
    * Output buffer: Decrypted data
    */
    EDecryptOma1DcfBuffer,


    /**
    * Set the content name
    * Input buffer: first memory buffer 4 bytes of length of the content name |
    *               memory buffer of the new content name |
    *               content id
    * Output buffer: unused
    */
    ESetContentName,

    };
}

#endif      // OMA2AGENT_H

// End of File
