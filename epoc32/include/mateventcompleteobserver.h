/*
* Copyright (c) 2002-2006 Nokia Corporation and/or its subsidiary(-ies).
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
* Description:  Callback interface to the client.
*
*/


#ifndef __MATEVENTCOMPLETEOBSERVER_H__
#define __MATEVENTCOMPLETEOBSERVER_H__

#include "ataudioeventconstants.hrh"

// CLASS DECLARATION

/**
*  Interface class for AudioEventAPI clients to inheritate.
*
*  @lib ATSoundServerClient.lib
*  @since Series 60 release 3.0
*/

class MATEventCompleteObserver
	{
	public:

		/**
		* Callback function for client API to call.
		*/
		virtual	void Complete( TInt  aError, TAudioThemeEvent aEvent ) = 0;

	};


#endif // __MATEVENTCOMPLETEOBSERVER_H__
