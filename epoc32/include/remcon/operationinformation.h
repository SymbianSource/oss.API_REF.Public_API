// Copyright (c) 2008-2009 Nokia Corporation and/or its subsidiary(-ies).
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
// Operation information 
// Used by both Remote Control server side and Remote Control client side library.
// 
//



/**
 @file
 @internalComponent
*/

#ifndef OPERATIONINFORMATION_H
#define OPERATIONINFORMATION_H

#include <e32base.h>
#include <remcon/messagetype.h>


class TOperationInformation
	{
public:
	TUint iOperationId;
	TRemConMessageSubType iMessageSubType;
	};


#endif // OPERATIONINFORMATION_H
