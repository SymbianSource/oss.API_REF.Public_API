// Copyright (c) 2006-2009 Nokia Corporation and/or its subsidiary(-ies).
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
// Comms-infras\Elements\cftransportmacro.h
// This header file is exported to \EPOC32\include\comms-infras
// 
//

#ifndef CFTRANSPORTMACRO_H
#define CFTRANSPORTMACRO_H

#if (defined SYMBIAN_NON_SEAMLESS_NETWORK_BEARER_MOBILITY) || (defined SYMBIAN_C32_SERCOMMS_V2)
	#define SYMBIAN_NETWORKING_CFTRANSPORT
#endif

#endif // CFTRANSPORTMACRO_H
