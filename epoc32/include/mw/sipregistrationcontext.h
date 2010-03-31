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
* Name        : sipregistrationcontext.h
* Part of     : SIP Client
* Interface   : SDK API, SIP API
* Version     : 1.0
*
*/




#ifndef MSIPREGISTRATIONCONTEXT_H
#define MSIPREGISTRATIONCONTEXT_H

//  INCLUDES
#include <e32base.h>

// CLASS DECLARATION

/**
*  @publishedAll
*  @released
*
*  The interface for providing
*  information for the SIP request and
*  dialog creation.
*
*  @lib n/a
*/
class MSIPRegistrationContext
	{
     public: // New functions
        /**
		* Destructor
		*/
        virtual ~MSIPRegistrationContext() {}

		/**
		* Checks if the registration context can be
		* used for creating SIP messages/dialogs
        *
		* @return ETrue if can be used, EFalse otherwise
		*/
		virtual TBool IsContextActive() const = 0;

		/**
		* Gets the context id.
        *
		* @return Context id
		* For internal use only
		*/
		virtual TUint32 ContextId() const = 0;
	};

#endif
