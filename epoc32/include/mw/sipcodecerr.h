/*
* Copyright (c) 2007-2009 Nokia Corporation and/or its subsidiary(-ies).
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
* Description:
* Name        : sipcodecerr.h
* Part of     : SIP Codec
* Interface   : SDK API, SIP Codec API
* Version     : SIP/6.0 
*
*/



#ifndef SIPCODECERR_H
#define SIPCODECERR_H

/**
* @file
* @publishedAll
* @released
*/

/** SIP parsing (decoding) errors */
// General errors
const TInt KErrSipCodecPreParser=-17750;
const TInt KErrSipCodecTokenizer=-17751;
const TInt KErrSipCodecNotAllowed=-17752;
const TInt KErrSipCodecHeaderName=-17753;
const TInt KErrSipCodecHeaderValue=-17754;
const TInt KErrSipCodecRequestLine=-17755;
const TInt KErrSipCodecResponseLine=-17756;
const TInt KErrSipCodecResponseCode=-17757;
const TInt KErrSipCodecSIPVersion=-17758;
const TInt KErrSipCodecSIPMethod=-17759;
const TInt KErrSipCodecReasonPhrase=-17760;
const TInt KErrSipCodecAnyParam=-17761;
const TInt KErrSipCodecAnyParamName=-17762;
const TInt KErrSipCodecAnyParamValue=-17763;
const TInt KErrSipCodecDuplicateParam=-17764;
const TInt KErrSipCodecHostPort=-17765;
const TInt KErrSipCodecHost=-17766;
const TInt KErrSipCodecPort=-17767;
// sip-address
const TInt KErrSipCodecSIPAddress=-17768;
const TInt KErrSipCodecDisplayName=-17769;
// URI
const TInt KErrSipCodecURI=-17770;
const TInt KErrSipCodecURIScheme=-17771;
const TInt KErrSipCodecURIParams=-17772;
const TInt KErrSipCodecURIHeaders=-17773;
// From and To
const TInt KErrSipCodecFromOrToAddress=-17774;
const TInt KErrSipCodecFromOrToParams=-17775;
// Contact
const TInt KErrSipCodecContactHeader=-17776;
const TInt KErrSipCodecContactSetToStar=-17777;
const TInt KErrSipCodecContactAddress=-17778;
const TInt KErrSipCodecContactParams=-17779;
// Other SIP headers
const TInt KErrSipCodecViaHeader=-17780;
const TInt KErrSipCodecCallIdHeader=-17781;
const TInt KErrSipCodecCSeqHeader=-17782;
const TInt KErrSipCodecContentLengthHeader=-17783;
const TInt KErrSipCodecExpiresHeader=-17784;
const TInt KErrSipCodecMaxForwardsHeader=-17785;
const TInt KErrSipCodecContentTypeHeader=-17786;
const TInt KErrSipCodecRouteHeader=-17787;
const TInt KErrSipCodecMinExpiresHeader=-17788;
const TInt KErrSipCodecTokenBaseHeader=-17789;
const TInt KErrSipCodecRequireHeader=-17790;
const TInt KErrSipCodecContentEncodingHeader=-17791;
const TInt KErrSipCodecProxyRequireHeader=-17792;
const TInt KErrSipCodecSupportedHeader=-17793;
const TInt KErrSipCodecUnsupportedHeader=-17794;
const TInt KErrSipCodecAllowHeader=-17795;
const TInt KErrSipCodecSecurityHeader=-17796;
const TInt KErrSipCodecContentDispositionHeader=-17797;
const TInt KErrSipCodecSubscriptionStateHeader=-17798;
const TInt KErrSipCodecAcceptHeader=-17799;
const TInt KErrSipCodecAcceptEncodingHeader=-17800;
const TInt KErrSipCodecAcceptLanguageHeader= -17801;
const TInt KErrSipCodecAcceptParams=-17802;
const TInt KErrSipCodecEventHeader=-17803;
const TInt KErrSipCodecAllowEventsHeader=-17804;
const TInt KErrSipCodecAuthenticationInfoHeader=-17805;
const TInt KErrSipCodecReferToHeader=-17806;
const TInt KErrSipCodecAuthenticationHeader=-17807;
const TInt KErrSipCodecAuthScheme=-17808;
const TInt KErrSipCodecAuthorizationHeader=-17809;
const TInt KErrSipCodecURIContainer=-17810;
const TInt KErrSipCodecRAckHeader=-17811;
const TInt KErrSipCodecRSeqHeader=-17812;
const TInt KErrSipCodecReplyToHeader=-17813;
const TInt KErrSipCodecTimestampHeader=-17814;
const TInt KErrSipCodecRetryAfterHeader=-17815;
const TInt KErrSipCodecRetryAfterParams=-17816;
const TInt KErrSipCodecAcceptContactHeader=-17817;
const TInt KErrSipCodecPAssociatedURIHeader=-17818;
const TInt KErrSipCodecPAccessNetworkInfoHeader=-17819;

// Last error code allocated to SIP Codec is -17874.
// This value must not be exceeded.

#endif // SIPCODECERR_H

// End of File
