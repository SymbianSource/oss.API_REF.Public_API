// Copyright (c) 2006-2009 Nokia Corporation and/or its subsidiary(-ies).
// All rights reserved.
// This component and the accompanying materials are made available
// under the terms of the License "Symbian Foundation License v1.0" to Symbian Foundation members and "Symbian Foundation End User License Agreement v1.0" to non-members
// which accompanies this distribution, and is available
// at the URL "http://www.symbianfoundation.org/legal/licencesv10.html".
//
// Initial Contributors:
// Nokia Corporation - initial contribution.
//
// Contributors:
//
// Description:
//



/**
 @file
 @publishedAll
 @released
*/

#ifndef ICL_PROPERTYUIDS_H
#define ICL_PROPERTYUIDS_H


#include <icl/icl_propertyuids.hrh>


/** 
Identifier for the hardware codec property. 
 @see KHwCodecUidValue
*/ 
const TUid KUidHwCodec   = {KHwCodecUidValue};

/** 
Identifier for the software codec property.
 @see KSwCodecUidValue
*/ 
const TUid KUidSwCodec   = {KSwCodecUidValue};

/** 
Identifier for the default codec property.
 @see KDefaultCodecUidValue
*/ 
const TUid KUidDefaultCodec   = {KDefaultCodecUidValue};

/** 
Identifier for the Exif support property.
 @see KExifSupportUidValue
*/ 
const TUid KUidExifSupport  = {KExifSupportUidValue};

/** 
Identifier for the JPEG Sequential property.
 @see KJPGSequentialUidValue
*/ 
const TUid KUidJPGSequential   = {KJPGSequentialUidValue};

/** 
Identifier for the JPEG Progressive property.
 @see KJPGProgressiveUidValue
*/ 
const TUid KUidJPGProgressive   = {KJPGProgressiveUidValue};

/** 
Identifier for the arbitrary scaling property.
 @see KArbitraryScalingUidValue
*/ 
const TUid KUidArbitraryScaling   = {KArbitraryScalingUidValue};

/** 
Identifier for the EColor16MA support property.
 @see KEColor16MASupportUidValue
*/ 
const TUid KUidEColor16MASupport   = {KEColor16MASupportUidValue};

/** 
Identifier for the thumbnail support property. 
 @see KThumbnailSupportUidValue
*/ 
const TUid KUidThumbnailSupport   = {KThumbnailSupportUidValue};

/** 
Identifier for the  thumbnail autogeneration property.
 @see KThumbnailAutogenerationUidValue
*/ 
const TUid KUidThumbnailAutogeneration   = {KThumbnailAutogenerationUidValue};

/** 
Identifier for the decoding to reduced size support property.
 @see KDecodeToReducedSizeSupportUidValue
*/ 
const TUid KUidDecodeToReducedSizeSupport   = {KDecodeToReducedSizeSupportUidValue};

/**
Identifier for an ICL Extension. This is used in the opaque_data section of an ICL
codec plugin as part of a pair of values "KUidICLExtension <extension_flags_modifier>"
where extension_flags_modifier is a bitfield advertising extensions that the codec supports.
 @see KICLExtensionUidValue 
 @see CImageDecoder::TOptions and CImageEncoder::TOptions for EOptionExt* flags which are valid.
*/
const TUid KUidICLExtension = {KICLExtensionUidValue};

#endif // ICL_PROPERTYUIDS_H
