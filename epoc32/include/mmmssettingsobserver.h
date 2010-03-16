// Copyright (c) 2005-2009 Nokia Corporation and/or its subsidiary(-ies).
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

#ifndef __MMMSSETTINGSOBSERVER_H__
#define __MMMSSETTINGSOBSERVER_H__


#include <e32base.h>



/** 
Provides the interface for notification of changes that occur in the Central Repository. 

@see CMmsAccounts::AddObserverL()
@see CMmsAccounts::RemoveObserver() 

@publishedAll
@released
*/
class MMmsSettingsObserver
 	{
public:
	/** 
	Settings event.
	*/
    enum TMmsSettingsEvent 
  		{ 
 		/** 
		Settings have been updated.
		*/ 		
       	ESettingsUpdated     
       	};
public: 
	/** 
	Indicates that a settings event has occurred. 
	
	@param	aEvent
	The Settings Event
	*/
  	virtual void HandleNotify(TMmsSettingsEvent aEvent) = 0;
   	};
          
#endif // __MMMSSETTINGSOBSERVER_H__
