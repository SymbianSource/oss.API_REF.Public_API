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
* RAuthclient - external authentication client session interface
* The defined fuctionality is used by clients to access the authentication
* server.
* The access to a specific functionality is dependant on the client 
* capabilities and may be restricted.             
*
*/


/**
 @file 
 @publishedAll
 @released
*/

#ifndef AUTHCLIENT_H
#define AUTHCLIENT_H

#include "authserver/identity.h"
#include "authserver/authexpression.h"
#include "authserver/plugindesc.h"
#include "authserver/idandstring.h"
#include <scs/scsclient.h>
namespace AuthServer
{

class CAsyncResponseDecoder;

/**
 * Client side interface to the authentication server providing general
 * authentication and plugin query services.
 *
 */	
class RAuthClient : public RScsClientBase
	{
	
	friend class CAsyncResponseDecoder;
	
public:

    IMPORT_C RAuthClient();
    
	IMPORT_C TInt Connect();

	IMPORT_C void AuthenticateL(
	    const CAuthExpression& aExpression,
	    TTimeIntervalSeconds   aTimeout,
		TBool                  aClientSpecificKey,
		TBool                  aWithString,
	    CIdentity*&            aIdentityResult, 
	    TRequestStatus&        aStatus);
	
	IMPORT_C CIdentity* AuthenticateL(
	    const CAuthExpression& aExpression,
	    TTimeIntervalSeconds   aTimeout,
		TBool                  aClientSpecificKey,
		TBool                  aWithString);

	IMPORT_C CIdentity* AuthenticateL(
			const CAuthExpression& 	aAuthExpression,
		    TTimeIntervalSeconds   	aTimeout,
			TBool                  	aClientSpecificKey,
			TUid 				   	aClientSid,
			TBool                  	aWithString,
			const TDesC&			aClientMessage);
			
	IMPORT_C void AuthenticateL(
		const CAuthExpression& 	aAuthExpression,
	    TTimeIntervalSeconds   	aTimeout,
		TBool                  	aClientSpecificKey,
		TUid 					aClientSid,
		TBool                  	aWithString,
	    const TDesC&			aClientMessage,
	    CIdentity*&            	aIdentityResult,
	    TRequestStatus&        	aStatus
		);

	IMPORT_C void DeauthenticateL();
	
	IMPORT_C void PluginsL(RPluginDescriptions& aPluginList);
	IMPORT_C void ActivePluginsL(RPluginDescriptions& aPluginList);
	IMPORT_C void PluginsOfTypeL(TAuthPluginType aType,
								  RPluginDescriptions& aPluginList);
	
	IMPORT_C void PluginsWithTrainingStatusL(
        TAuthTrainingStatus aStatus,
		RPluginDescriptions& aPluginList);
	
	IMPORT_C void IdentitiesL(RIdentityIdArray& aIdList);
	IMPORT_C void IdentitiesWithStringL(RIdAndStringArray& aList);

	IMPORT_C HBufC* IdentityStringL(TIdentityId aId);
	IMPORT_C void SetIdentityStringL(TIdentityId aId, const TDesC& aString);
	
	IMPORT_C TPluginId PreferredTypePluginL(TAuthPluginType aPluginType);
	
	IMPORT_C TUint Cancel();
	IMPORT_C void Close();
	
	IMPORT_C void ListAuthAliasesL(RPointerArray<HBufC>& aAuthAliasList);
	
	IMPORT_C CAuthExpression* CreateAuthExpressionL(const TDesC& aAuthString) const;
	
protected:
	/* @internalComponent */
	void CheckAsyncDecoderL();
	/* @internalComponent */
	HBufC8* SendReceiveBufferLC(TInt aMessage);
	/* @internalComponent */
	HBufC8* SendReceiveBufferLC(TInt aMessage, TIpcArgs& aArgs);
	
private:
	TInt StartAuthServer();

protected:
	CAsyncResponseDecoder* iAsyncResponseDecoder;
};
  
} // namespace
#endif

