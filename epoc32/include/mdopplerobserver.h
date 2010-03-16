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
* Description:  This is the definition of the doppler effect observer class.
*
*
*/


#ifndef MDOPPLEROBSERVER_H
#define MDOPPLEROBSERVER_H

// INCLUDES

#include <e32base.h>
#include <DopplerBase.h>
#include <MAudioEffectObserver.h>


// CLASS DECLARATION

/**
*  This is the doppler effect observer class. Object interested in receiving notification
*  when the CDoppler object changes state should derive from this class and implement its
*  interface.
*
*  @since 3.0
*/

class MDopplerObserver : public MAudioEffectObserver
	{
	public:
		static const TUint KFactorChanged = KSpecificEffectBase + 1;
		static const TUint KCartesianVelocityChanged = KSpecificEffectBase + 2;
		static const TUint KSphericalVelocityChanged = KSpecificEffectBase + 3;
		static const TUint KMaxFactorChanged = KSpecificEffectBase + 4;
	};

#endif	// of MDOPPLEROBSERVER_H

// End of File