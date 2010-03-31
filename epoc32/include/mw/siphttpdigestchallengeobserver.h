/*
* Copyright (c) 2005-2009 Nokia Corporation and/or its subsidiary(-ies).
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
* Name        : siphttpdigestchallengeobserver.h
* Part of     : SIP Client
* Interface   : SDK API, SIP Client API
* Version     : 1.0
*
*/



#ifndef MSIPHTTPDIGESTCHALLENGEOBSERVER_H
#define MSIPHTTPDIGESTCHALLENGEOBSERVER_H

// FORWARD DECLARATIONS

// CLASS DECLARATION

/**
* @publishedAll
* @released
*
* The user must implement this interface if it intends to
* provide HTTP Digest credentials upon received challenges
* from the SIP servers on the signaling path.
* The user should provide credentials or ignore the challenge
* using functions defined in TSIPHttpDigest class.
*
* MSIPHttpDigestChallengeObserver class is compliant with RFC 2543
* where Proxy use to forward only one challenge when it receives 
* multiple challenges on forking the request. Applications are 
* encouraged to use MSIPHttpDigestChallengeObserver2 class which
* provides interface to extract multiple challenges.
* MSIPHttpDigestChallengeObserver2 class is compliant to RFC 3261
*  @lib n/a
*/
class MSIPHttpDigestChallengeObserver
	{
    public: // New functions
		/**
		* SIP request resulted in 401/407 response that contains
		* a challenge.
		*
		* @param aRealm a realm for which the challenge was received
		*/
		virtual void ChallengeReceived(const TDesC8& aRealm) = 0;
	};

#endif
