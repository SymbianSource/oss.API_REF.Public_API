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

#ifndef SYMBIAN_C32_SERCOMMS_V2
// PLEASE NOTE: This file is part of Version 2 of C32 - that is, the multi-threaded version.
// The single-threaded C32 version of this file is in c32\Version1\SCOMM
// All defect fixes should be applied to both versions where appropriate.
// PLEASE NOTE: This comment is applicable to SercommsV2 but is surrounded by an "#ifndef"
// to enable the automatic removal of this comment once non-C32 V2 code is removed.
#endif


/**
 * @file
 *
 * implements inline methods of RComm
 */

inline void RComm::SetSignals(TUint aSetMask, TUint aClearMask)
/** Sets or clears RS232 output lines (DTR and RTS).

For many applications, these lines will be read and set under driver control 
as determined by the handshaking options selected.

@param aSetMask Set the handshaking lines in the mask. 
@param aClearMask Clear the handshaking lines in the mask. 
@publishedAll
@released
*/
	{
	SetSignalsToMark(aSetMask);
	SetSignalsToSpace(aClearMask);
	}
