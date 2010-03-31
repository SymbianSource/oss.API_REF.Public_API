/*
* Copyright (c) 2005-2009 Nokia Corporation and/or its subsidiary(-ies).
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
* Authserver publish and subscribe properties.  
*
*/


/**
 @file  
 @publishedAll
 @released
*/

#ifndef ASPUBSUBDEFS_H
#define ASPUBSUBDEFS_H

namespace AuthServer
{
/**
 * Used to write to and read from the publish and subscribe property
 * KUidAuthServerLastAuth. 
 *
 * @see KUidAuthServerLastAuth
 **/
NONSHARABLE_STRUCT(TLastAuth)
	{
	TLastAuth() { Mem::FillZ(this, sizeof(TLastAuth)); }
	/// The identities id number or KUnknownIdentity
	TIdentityId iId;
	/// The time of the authentication, 0 if unknown 
	TTime       iAuthTime;
	/// The highest number of combinations of the authentication methods
	/// used
	TEntropy    iMaxCombinations;
	/// the lowest false positive rate of the methods used
	TPercentage iFalsePositiveRate;
	/// the lowest false negative rate of the methods used
	TPercentage iFalseNegativeRate;
	/// the number of factors (i.e. plugins) combined to make the
	/// authentication
	TInt32      iNumFactors;
	};

/**
 * This is the publish and subscribe property used by the Authentication
 * Server to publish the details of the last authentication. The
 * value is of type TLastAuth and can be retrieved using code such as:
 * <code>
 * TLastAuth lastAuth;
 * TPckg<TLastAuth> authPkg(lastAuth);
 * RProperty::Get(KAuthServerSecureId, KUidAuthServerLastAuth, authPkg);
 * </code>
 *
 * The property is published each time an authentication or deauthentication
 * is made, even if the same identity is authenticated. To be notified only
 * when the identity changes, subscribe to KUidAuthServerAuthChangeEvent.
 *
 */
const TUint KUidAuthServerLastAuth = { 0x10281843 };


/**
 * This is the publish and subscribe property used by the Authentication
 * Server to notify subscribers of a change of authenticated identity.  The
 * published value is of type TUint and will contain the id number of the last
 * identity authenticated.
 *
 * The property is published only when the identity changes, reauthentication
 * with a different method will not result in notification.
 *
 */
const TUint KUidAuthServerAuthChangeEvent = { 0x10281845 };

}

#endif /*ASPUBSUBDEFS_H*/

