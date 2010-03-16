/*
* Copyright (c) 2006-2009 Nokia Corporation and/or its subsidiary(-ies).
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
* Name        : sipprofileagentinitparams.inl
* Part of     : sip profile agent
* inline functions
* Version     : 1.0
* CSIPProfileAgent::CSIPProfileAgent
*
*/



inline TSIPProfileAgentInitParams::TSIPProfileAgentInitParams(
	CDeltaTimer& aDeltaTimer,
	MSIPProfileAgentObserver& aSIPProfileAgentObserver) :
    iDeltaTimer(aDeltaTimer),
	iSIPProfileAgentObserver(aSIPProfileAgentObserver)
	{
	}
