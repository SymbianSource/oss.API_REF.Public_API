// Copyright (c) 2004-2009 Nokia Corporation and/or its subsidiary(-ies).
// All rights reserved.
// This component and the accompanying materials are made available
// under the terms of the License "Symbian Foundation License v1.0" to Symbian Foundation members and "Symbian Foundation End User License Agreement v1.0" to non-members
// which accompanies this distribution, and is available
// at the URL "http://www.symbianfoundation.org/legal/licencesv10.html".
//
// Initial Contributors:
// Nokia Corporation - initial contribution.
//
// Contributors:
//
// Description:
//

#ifndef __EIKBUSYMSGWIN_H__
#define __EIKBUSYMSGWIN_H__

/** An interface class for creating customized busy message windows 

@publishedPartner 
@released */
class MEikBusyMsgWin
	{
public:
	/** Displays a busy message window after a specified duration.
	@param aText The text for the busy message.
	@param aCorner The alignment for the busy message.
	@param aInitialDelay The time period after which the busy message is displayed. */
	virtual void StartDisplaySpecifyingInitialDelay(const TDesC& aText, TGulAlignment aCorner, TTimeIntervalMicroSeconds32 aInitialDelay) =0;

	/** Displays the message window with the specified text and alignment.

	@param aText The text to display in the message. 
	@param aCorner The position in which the message window will appear. There 
	are 9 options for this, each square of a 3 by 3 matrix on the screen. */
	virtual void StartDisplay(const TDesC& aText, TGulAlignment aCorner) =0;
	
	/** Deletes the object, calling it's private destructor.
	*/
	virtual void Release() = 0;
	};
	
#endif	// __EIKBUSYMSGWIN_H__
