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
// Implement some of the ECOM Core Dump Formatter interface.
//



/**
 @file
 @publishedPartner
 @released
*/

// Set default to be first implementation found by resolver
_LIT8(KDefaultImplementation,"*");

#include <debuglogging.h>

inline CCoreDumpFormatter::CCoreDumpFormatter()
    {
	LOG_MSG( "CCoreDumpFormatter::CCoreDumpFormatter()\n" );
    }

inline CCoreDumpFormatter::~CCoreDumpFormatter()
    {
	LOG_MSG2( "CCoreDumpFormatter::~CCoreDumpFormatter() with iDtor_ID_Key=0x%X\n", iDtor_ID_Key );
    // Destroy any instance variables and then
    // inform the framework that this specific
    // instance of the interface has been destroyed.
    REComSession::DestroyedImplementation( iDtor_ID_Key );
    }

inline CCoreDumpFormatter* CCoreDumpFormatter::NewL()
    {
	LOG_MSG( "CCoreDumpFormatter::NewL()\n" );
    // Set up the interface find for the default resolver.
    TEComResolverParams resolverParams;
    resolverParams.SetDataType(KDefaultImplementation());
    //resolverParams.SetGenericMatch(ETrue);     // Allow wildcard matching
	resolverParams.SetWildcardMatch(ETrue);     // Allow wildcard matching

    // Set up some empty initialisation parameters
    TExampleInterfaceInitParams initParams;
    initParams.integer      = 0;
    initParams.descriptor   = NULL;

    return reinterpret_cast<CCoreDumpFormatter*>(
                            REComSession::CreateImplementationL(KCCoreDumpFormatterUid,
                                                             _FOFF(CCoreDumpFormatter,iDtor_ID_Key),
                                                             &initParams,
                                                             resolverParams));
    }

inline CCoreDumpFormatter* CCoreDumpFormatter::NewL(const TDesC8& aCue)
	{
	LOG_MSG( "CCoreDumpFormatter::NewL(const TDesC8& aCue)\n" );

	TEComResolverParams resolverParams;
	resolverParams.SetDataType(aCue);
	resolverParams.SetGenericMatch(ETrue);
	TAny* symbianElf = REComSession::CreateImplementationL(KCCoreDumpFormatterUid, _FOFF(CCoreDumpFormatter, iDtor_ID_Key),
		resolverParams);
	return reinterpret_cast<CCoreDumpFormatter*>(symbianElf);
	}


inline CCoreDumpFormatter* CCoreDumpFormatter::NewL(const TUid& aUid)
	{
	LOG_MSG( "CCoreDumpFormatter::NewL(const TUid& aUid)\n" );

	LOG_MSG2( "->REComSession::CreateImplementationL(aUid=0x%X)\n", (aUid) );
	
	TAny* symbianElf = REComSession::CreateImplementationL( aUid, _FOFF(CCoreDumpFormatter, iDtor_ID_Key) );
	LOG_MSG2( "<-REComSession::CreateImplementationL() iDtor_ID_Key=0x%X\n", _FOFF(CCoreDumpFormatter, iDtor_ID_Key) );
		
	return reinterpret_cast<CCoreDumpFormatter*>(symbianElf);
	}


inline void CCoreDumpFormatter::ListAllImplementationsL(RImplInfoPtrArray& aImplInfoArray)
	{
	REComSession::ListImplementationsL(KCCoreDumpFormatterUid, aImplInfoArray);
	}
