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


#ifndef LOUDNESSOBSERVER_H
#define LOUDNESSOBSERVER_H

// INCLUDES

#include <e32base.h>
#include <LoudnessBase.h>
#include <MAudioEffectObserver.h>


// CLASS DECLARATION

/**
*  This is the noise reduction effect observer class. Object interested in receiving notification
*  when the CLoudness object changes state should derive from this class and implement its
*  interface.
*
*  @since 3.0
*/

class MLoudnessObserver : public MAudioEffectObserver
	{
		// No specific event ID other than the ones from the base observer class.
	};

#endif	// of LOUDNESSOBSERVER_H

// End of File