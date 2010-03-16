/*
* Copyright (c) 2003-2009 Nokia Corporation and/or its subsidiary(-ies).
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
*
*/


#ifndef __SECURITYERR_H__
#define __SECURITYERR_H__

#include <e32std.h>

/**
 * @file
 *
 * Defines error codes for the security subsystem.  Codes -11000 to -11500 are
 * reserved for security.
 *
 * @internalTechnology
 */

/* Crypto libraries */

const TInt KErrBadPassphrase				= -11000;
const TInt KErrTotalLossOfEntropy			= -11001;
const TInt KErrKeyNotWeakEnough				= -11002;	
const TInt KErrInvalidPadding				= -11003;
const TInt KErrWeakKey						= -11004;
const TInt KErrNegativeExportNotSupported	= -11005;

/*
 * Key store
 *
 * These error codes relate to the cryptokens key store interfaces and the
 * software keystore.  They are described in the interfaces where they occur.
 */

const TInt KErrKeyAlgorithm	   				= -11006;
const TInt KErrKeyUsage						= -11007;
const TInt KErrKeyValidity				   	= -11008;
const TInt KErrKeySize						= -11009;
const TInt KErrKeyAccess					= -11010;
const TInt KErrPrivateKeyNotFound			= -11011;

#endif	//	__SECURITYERR_H__
