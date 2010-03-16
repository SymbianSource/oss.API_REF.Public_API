// Copyright (c) 2007-2009 Nokia Corporation and/or its subsidiary(-ies).
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
// Constants and structs specific to On2 VP6.  See the DevVideo specs for more details.
// 
//

#ifndef __DEVVIDEO_ON2VP6_H__
#define __DEVVIDEO_ON2VP6_H__

#include <e32base.h>

/**
On2VP6 video packet header information
@publishedAll
@released
*/
class TOn2VP6VideoFrame
	{
public:
	/**
	Indicates frame type. 0 indicates an I-frame, 1 indicates a P-frame
	*/
	TUint iPictureType;
	/**
	Indicates the initial value of the quantization parameter
	*/
	TUint iQuantizer;
	};

#endif