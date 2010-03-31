/*
* Copyright (c) 2003-2007 Nokia Corporation and/or its subsidiary(-ies). 
* All rights reserved.
* This component and the accompanying materials are made available
* under the terms of "Eclipse Public License v1.0""
* which accompanies this distribution, and is available
* at the URL "http://www.eclipse.org/legal/epl-v10.html".
*
* Initial Contributors:
* Nokia Corporation - initial contribution.
*
* Contributors:
*
* Description:               MPtiObserver class definition.  
*
*/















#ifndef _PTI_OBSERVER_H
#define _PTI_OBSERVER_H

/**
* PtiEngine observer interface. A client side application can request
* notifications for certain PtiEngine operations through this 
* interface. It is set via CPtiEngine::SetObserver method.
*/
class MPtiObserver
	{
	public:
	    /**
	    * This method is called when multitapping timer
	    * expires. Related to EPtiEngineMultitaping input mode.
	    */
		virtual void KeyTimerExpired() = 0;
		
		/**
		* This method is called when last item in prediction
		* candidate list is reached. Related to EPtiEnginePredictive
		* input mode.
		*/
		virtual void LastWordInSelectionList() = 0;
		
	    /**
		* This method is called when the first item in prediction
		* candidate list is reached. Related to EPtiEnginePredictive
		* input mode.
		*/		
		virtual void FirstWordInSelectionList() = 0;
	};


#endif // _PTI_OBSERVER_H

// End of file
