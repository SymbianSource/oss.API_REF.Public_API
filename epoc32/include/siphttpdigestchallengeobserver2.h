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
* Name        : siphttpdigestchallengeobserver2.h
* Part of     : SIP Client
* Interface   : SDK API, SIP Client API
* Version     : 1.0
*
*/



#ifndef MSIPHTTPDIGESTCHALLENGEOBSERVER2_H
#define MSIPHTTPDIGESTCHALLENGEOBSERVER2_H

// INCLUDES
#include <e32std.h>

// FORWARD DECLARATIONS
class CSIPClientTransaction;
class CSIPRefresh;

// CLASS DECLARATION
/**
* @publishedAll
* @released
*
* The user should implement this interface if it intends to
* provide HTTP Digest credentials upon received challenges
* from the SIP servers on the signaling path.
* The user should provide credentials or ignore the challenge
* using functions defined in CSIPHttpDigest class.
*
*  @lib n/a
*/
class MSIPHttpDigestChallengeObserver2
	{
    public: // New functions
		/**
		* A SIP request resulted in 401/407 response that contains
		* 1..n challenges. 
		* The challenges can be obtained from Proxy-Authenticate- and/or
		* WWW-Authenticate-headers in the CSIPResponseElements
		* attached to the CSIPClientTransaction.
		* The user must call CSIPHttpDigest::SetCredentialsL or
		* CSIPHttpDigest::IgnoreChallenge for each challenge.
		*
		* @param aTransaction transaction which was completed with 
		*        a response containing HTTP Digest challenge.
		*/
		virtual void ChallengeReceived(
		    const CSIPClientTransaction& aTransaction) = 0;

		/**
		* A refreshed SIP request resulted in 401/407 response that contains
		* 1..n challenges.
		* The challenges can be obtained from Proxy-Authenticate- and/or
		* WWW-Authenticate-headers in the CSIPResponseElements
		* attached to the CSIPClientTransaction attached to the CSIPRefresh.
		* The user must call CSIPHttpDigest::SetCredentialsL or
		* CSIPHttpDigest::IgnoreChallenge for each challenge.		 
		*
		* @param aRefresh the refresh for which a transaction completed with 
		*        a response containing HTTP Digest challenge.
		*/		    
		virtual void ChallengeReceived(
		    const CSIPRefresh& aRefresh) = 0;		    
	};

#endif // MSIPHTTPDIGESTCHALLENGEOBSERVER2_H
