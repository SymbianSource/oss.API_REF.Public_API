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
// Created at: 04-Jan-99 10:35:54 AM
// Status enumeration for Data Collectors, Data Providers and Data Handlers.
// 
//


#if !defined(__ESTATUS_H__)
#define __ESTATUS_H__

#ifndef __E32DEF_H__
#include <e32def.h> // for TInt
#endif

// 
// values < 0 are error codes
//			0 - 100 are % processed
//		  > 100 are the enum values below...
//
enum TPluginStatus {	
					EPluginComplete=100,
					EPluginInitialised,
					EPluginWaitingForChild,
					EPluginProcessing,
					EPluginSuspend,
					EPluginCancelled,
					EConnectionChanged
				   };

#endif    // __ESTATUS_H__
