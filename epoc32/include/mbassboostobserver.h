/*
* Copyright (c) 2004 Nokia Corporation and/or its subsidiary(-ies). 
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
* Description:  This is the definition of the bassboost effect observer class.
*
*
*/


#ifndef BASSBOOSTOBSERVER_H
#define BASSBOOSTOBSERVER_H

// INCLUDES

#include <e32base.h>
#include <BassBoostBase.h>
#include <MAudioEffectObserver.h>


// CLASS DECLARATION

/**
*  This is the bassboost effect observer class. Object interested in receiving notification
*  when the CBassBoost object changes state should derive from this class and implement its
*  interface.
*
*  @since 3.0
*/

class MBassBoostObserver : public MAudioEffectObserver
	{
	public:
	static const TUint KBassBoostChanged = KSpecificEffectBase + 1;
	};

#endif	// of BASSBOOSTOBSERVER_H

// End of File