// Copyright (c) 1997-2009 Nokia Corporation and/or its subsidiary(-ies).
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
 @publishedAll
 @released
*/
	
#if !defined(__ET_BUFFER_H__)
#define __ET_BUFFER_H__

//
//	Number of server-side slots for each notification (greater than 1)
//
/**
@internalTechnology
*/
const TUint KSlotNumbersDefault				= 1;
//
//	RCall
//
/**
@internalComponent
*/
const TUint KSlotNumbersCallCapsChange		= 2;
const TUint KSlotNumbersCallStatusChange	= 4;


//
//	RLine
//
/**
@internalComponent
*/
const TUint KSlotNumbersLineStatusChange	= 4;
const TUint KSlotNumbersLineCallAddedChange = 4;



#endif
