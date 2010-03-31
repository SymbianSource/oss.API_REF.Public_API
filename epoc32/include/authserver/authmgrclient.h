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
* RAuthMgrClient - external authentication client session interface
* The defined fuctionality is used by clients to access the authentication
* server for the purpose of managing identities.
* The access to a specific functionality is dependant on the client 
* capabilities and may be restricted.             
*
*/


/**
 @file 
 @publishedAll
 @released
*/

#ifndef AUTHMGRCLIENT_H
#define AUTHMGRCLIENT_H

#include "authserver/authclient.h"

namespace AuthServer
{

/**
 * Client side interface to the authentication server providing identity
 * management services.
 */	
class RAuthMgrClient : public RAuthClient
	{
public:

	IMPORT_C void RegisterIdentityL(CIdentity*& aIdentity,
								   const TDesC& aDescription,  
								   TRequestStatus& aRequest);

	IMPORT_C void RemoveIdentityL(TIdentityId aId);


	IMPORT_C void TrainPlugin(TIdentityId aId,
							  TPluginId aPlugin,
							  TRequestStatus& aRequest);

	IMPORT_C void ForgetPluginL(TIdentityId aId,
					  TPluginId aPlugin);

	IMPORT_C void SetPreferredTypePluginL(TAuthPluginType aPluginType,
										  TPluginId aPluginId);

	IMPORT_C void ResetIdentityL(TIdentityId aId,
								const TDesC& aRegistrationInformation);

	IMPORT_C void ResetIdentityL(TIdentityId aId,
								TAuthPluginType aPluginType,
								const TDesC& aRegistrationInformation);

	IMPORT_C void ResetIdentityL(TIdentityId aId,
								RArray<TPluginId>& aPluginIdList,
								RPointerArray<const HBufC>& aRegistrationInformation);
	};
} // namespace
#endif
