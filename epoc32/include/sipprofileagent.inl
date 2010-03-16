/*
* Copyright (c) 2002-2009 Nokia Corporation and/or its subsidiary(-ies).
* All rights reserved.
* This component and the accompanying materials are made available
* under the terms of the License "Symbian Foundation License v1.0" to Symbian Foundation members and "Symbian Foundation End User License Agreement v1.0" to non-members
* which accompanies this distribution, and is available
* at the URL "http://www.symbianfoundation.org/legal/licencesv10.html".
*
* Initial Contributors:
* Nokia Corporation - initial contribution.
*
* Contributors:
*
* Description:
* Name        : sipprofileagent.inl
* Part of     : sip profile agent
* inline functions
* Version     : 1.0
*
*/



const TUid KSIPProfileAgentInterfaceUid = {0x101F4136};


// ============================ MEMBER FUNCTIONS ===============================


// Destructor
inline CSIPProfileAgent::~CSIPProfileAgent()
	{
	REComSession::DestroyedImplementation(iDtor_ID_Key);
	}

// -----------------------------------------------------------------------------
// CSIPProfileAgent::CSIPProfileAgent
// C++ default constructor can NOT contain any code, that
// might leave.
// -----------------------------------------------------------------------------
//
inline CSIPProfileAgent::CSIPProfileAgent()
	{
	}

// -----------------------------------------------------------------------------
// CSIPProfileAgent::NewL
// Two-phased constructor.
// -----------------------------------------------------------------------------
//
inline CSIPProfileAgent* CSIPProfileAgent::NewL(
	const TDesC8& aProfileType, 
	TSIPProfileAgentInitParams& aSIPProfileAgentInitParams)

	{
	TEComResolverParams resolverParams;
	resolverParams.SetDataType(aProfileType);
	return reinterpret_cast<CSIPProfileAgent*>(
	    REComSession::CreateImplementationL(
	        KSIPProfileAgentInterfaceUid,
	        _FOFF(CSIPProfileAgent,iDtor_ID_Key),
	        &aSIPProfileAgentInitParams,
	        resolverParams));
	}

// -----------------------------------------------------------------------------
// CSIPProfileAgent::ListAllImplementationsL
// lists all interface implementations
// (other items were commented in a header).
// -----------------------------------------------------------------------------
//

inline void CSIPProfileAgent::ListAllImplementationsL(
	RImplInfoPtrArray& aImplInfoArray)
	{
	REComSession::ListImplementationsL(
	    KSIPProfileAgentInterfaceUid,
		aImplInfoArray);
	}
