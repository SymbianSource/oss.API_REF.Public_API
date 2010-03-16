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



/**
 @file
 @publishedPartner
 @released
*/

#ifndef CLIENTTYPE_H
#define CLIENTTYPE_H

/**
Client type enumeration.
*/
enum TRemConClientType
	{
	/** Undefined client type. */
	ERemConClientTypeUndefined = 0,

	/** Controller. */
	ERemConClientTypeController,

	/** Target. */
	ERemConClientTypeTarget,
	};

#endif // CLIENTTYPE_H
