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
* Name          : sipnattraversalcontrollerinitparams.inl
* Part of       : SIP NAT Traversal Controller
* Version       : SIP/5.0 
*
*/



#ifndef TSIPNATTRAVERSALCONTROLLERINITPARAMS_INL
#define TSIPNATTRAVERSALCONTROLLERINITPARAMS_INL

// -----------------------------------------------------------------------------
// TSIPNATTraversalControllerInitParams::TSIPNATTraversalControllerInitParams
// -----------------------------------------------------------------------------
//
inline 
TSIPNATTraversalControllerInitParams::TSIPNATTraversalControllerInitParams(
    RSocketServ& aSocketServ)
    : iSocketServ(aSocketServ)
	{
	}
	
#endif // TSIPNATTRAVERSALCONTROLLERINITPARAMS_INL
