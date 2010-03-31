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
* Contains the list of error values that may be returned. 
*
*/


/**
 @file 
 @publishedAll
 @released
*/

#ifndef AUTH_SRV_ERRS_H
#define AUTH_SRV_ERRS_H

#include <e32def.h>

/**
	Attempted to internalize an invalid authentication expression stream.
	
	If this error occurs on the server side because the client
	has sent an invalid externalization buffer they are panicked
	with "AUTHSERVER 3", instead of being completed with this
	error code.

	This error should not occur if clients use the supplied
	RAuthClient API.
 */
const TInt KErrAuthServInvalidInternalizeExpr = -10800;

/**
	Attempted to internalize an authentication expression stream
	with an unsupported version.
	
	The authentication server will complete an authentication
	request with this value if the supplied stream has an
	unsupported version number.

	This error code is rare and is caused by sending a corrupt
	externalized expression to the server, or if the expression
	was internalized with an older version of the client code.
	This error should not occur if clients use the supplied
	RAuthClient API.
 */
const TInt KErrAuthServUnsupportedExprVersion = -10801;

/**
    An attempt was made to reference a plugin by id number and no such 
    plugin exists  
 **/
const TInt KErrAuthServNoSuchPlugin = -10802;


/**
    An attempt was made to reference an identity by id number and no such 
    identity exists  
 **/
const TInt KErrAuthServNoSuchIdentity = -10803;

/**
    A plugin returns this on behalf of a user wanting to skip it.
 **/
const TInt KErrAuthServPluginCancelled = -10804;

/**
    A plugin returns this on behalf of a user wanting to completely quit the
    current operation.
 **/
const TInt KErrAuthServPluginQuit = -10805;


/**
    This error is reported when an operation is attempted for which an
    authentication must have already been performed.
 **/
const TInt KErrAuthServAuthenticationRequired = -10806;

/**
	Attempted to add a new identity to the authentication
	server database with an existing ID.
 */
const TInt KErrAuthServIdentityAlreadyExists = -10807;

/**
	Attempted to set or retrieve a description for an identity,
	or remove an identity which was not in the authentication database.
 */
const TInt KErrAuthServIdentityNotFound = -10808;

/**
	Attempted to remove or retrieve the key info for
	a training record that was not in the authentication
	database.
 */
const TInt KErrAuthServTrainingNotFound = -10809;

/**
    This error is reported when the authserver has not been able to register a
    new identity due to no plugins training successfully.
 **/
const TInt KErrAuthServRegistrationFailed = -10810;


/**
    This error is reported when an authclient attempts to remove the last
    identity.
 **/
const TInt KErrAuthServCanNotRemoveLastIdentity = -10811;


/**
    This error is reported when an authclient attempts to remove the last
    trained plugin for an identity.
 **/
const TInt KErrAuthServCanNotRemoveLastPlugin = -10812;


/**
    This error is reported when an attempt to use an inactive plugin is made.
 **/
const TInt KErrAuthServPluginNotActive = -10813;

/**
	Client attempted to create an identity with a description
	longer than 255 characters, or to change an existing identity's
	description to use more than 255 characters.
 */
const TInt KErrAuthServDescTooLong = -10814;

/**
	This error is reported when the authentication strength alias
	supplied by the client is not found in the authserver's
	central repository file.
 */

const TInt KErrUnknownAuthStrengthAlias = -10815;

/**
	This error is reported when an authentication strength in 
	the authserver's central repository file is undefined.
 */

const TInt KErrAuthStrengthAliasNotDefined = -10816;

/**
	This error is reported when an alias string defining an
	authentication strength in the authserver's central repository 
	file contains expression other than plugin Id, plugin Types 
	and operators ("& and "|").
 */

const TInt KErrAuthServInvalidAliasStringExpression = -10817;


/**
    This error is reported when an authclient attempts to remove the default
    identity.
 */
const TInt KErrAuthServCanNotRemoveDefaultIdentity = KErrAuthServCanNotRemoveLastIdentity;

/**
    This error is reported when an authentication manager client attempts to 
    reset an identity and this may result in zero plugins registering the new identity data.
    This can happen if a reset request is issued for all plugins registered for an identity 
    and none of the plugins are of knowledge type.
 */
const TInt KErrAuthServResetMayLoseIdentity = -10818;

#endif	// #ifndef AUTH_SRV_ERRS_H

