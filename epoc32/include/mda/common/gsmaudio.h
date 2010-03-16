// Copyright (c) 2000-2009 Nokia Corporation and/or its subsidiary(-ies).
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

#ifndef __GSMAUDIO_H__
#define __GSMAUDIO_H__


//*******************************************************************
//* INCLUDE FILES:
//*******************************************************************

// Standard EPOC32 includes
#include <e32base.h>
// Public Media Server includes
#include <mda/common/base.h>
#include <mda/common/resource.h>
#include <mda/common/controller.h>
#include <mda/common/audio.hrh>
#include <mda/common/gsmaudio.hrh>


//*******************************************************************
//* CONSTANTS:
//*******************************************************************

// Wav Codec Uids
/**
@publishedAll
@released
Uid value for GSM610 codec
*/
const TUint KUidMdaGsmWavCodecValue = KUidMdaGsmWavCodecDefine;
/**
@publishedAll
@released
Uid for GSM610 codec
*/
const TUid  KUidMdaGsmWavCodec      = { KUidMdaGsmWavCodecValue };


//*******************************************************************
//* TMdaGsmWavCodec Class:
//*******************************************************************


class TMdaGsmWavCodec : public TMdaWavCodec
/** 
 * @internalTechnology
 */
	{
public:
	inline TMdaGsmWavCodec();
	};


//*******************************************************************
//* INLINE FUNCTIONS:
//*******************************************************************

inline TMdaGsmWavCodec::TMdaGsmWavCodec() :
	TMdaWavCodec (KUidMdaGsmWavCodec, sizeof(TMdaGsmWavCodec) )
	{
	}


#endif	// __GSMAUDIO_H__
