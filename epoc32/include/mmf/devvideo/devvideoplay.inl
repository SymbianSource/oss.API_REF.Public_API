// Copyright (c) 2003-2009 Nokia Corporation and/or its subsidiary(-ies).
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


CMMFDevVideoPlay::TBufferOptions::TBufferOptions() : 
	iPreDecodeBufferSize(0), 
	iMaxPostDecodeBufferSize(0), 
	iPreDecoderBufferPeriod(0), 
	iPostDecoderBufferPeriod(0), 
	iMaxInputBufferSize(0), 
	iMinNumInputBuffers(0) 
	{
	}

CMMFDevVideoPlay::TPictureCounters::TPictureCounters() :
	iPicturesSkipped(0),
	iPicturesDecoded(0),
	iPicturesDisplayed(0),
	iTotalPictures(0)
	{
	}


CMMFDevVideoPlay::TBitstreamCounters::TBitstreamCounters() :
	iLostPackets(0),
	iTotalPackets(0)
	{
	}
