/*
* Copyright (c) 2005-2009 Nokia Corporation and/or its subsidiary(-ies). 
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
* @file
* This contains CTEFTimer
*
*/


#ifndef __TEF_TIMER_H__
#define __TEF_TIMER_H__

#include <e32base.h>

class MTEFTimerCallback
/**
 * @internalComponent
 * @test
 *
 * Timer completion callback
 */
	{
public:
	/**
	 * Method from which CTEFTimer informs the user that the timer has completed
	 */
	virtual void	TimerCompleted() = 0;
	};

class CTEFTimer : public CTimer
/**
 * @internalComponent
 * @test
 *
 * @see		CTimer
 * Timer help class
 */
	{
public:
	IMPORT_C static CTEFTimer*	NewL(MTEFTimerCallback& aCallback, TInt aPriority = EPriorityStandard);

protected:
	CTEFTimer(MTEFTimerCallback& aCallback, TInt aPriority);

	void				ConstructL();

	virtual void		RunL();

private:
	MTEFTimerCallback&	iCallback;
	};

#endif // __TEF_TIMER_H__
