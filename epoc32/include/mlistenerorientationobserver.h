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
* Description:  This is the definition of the listener location effect observer class.
*
*
*/


#ifndef MLISTENERORIENTATIONOBSERVER_H
#define MLISTENERORIENTATIONOBSERVER_H

// INCLUDES

#include <e32base.h>
#include <ListenerOrientationBase.h>
#include <MOrientationObserver.h>


// CLASS DECLARATION

/**
*  This is the Listener Orientation effect observer class. Object interested in receiving notification
*  when the CListenerOrientation object changes state should derive from this class and implement its
*  interface.
*
*  @since 3.0
*/

class MListenerOrientationObserver : public MOrientationObserver
	{
		// No specific event ID other than the ones from the base observer class.
	};

#endif	// of MLISTENERORIENTATIONOBSERVER_H

// End of File