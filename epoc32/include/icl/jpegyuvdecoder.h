// Copyright (c) 1999-2009 Nokia Corporation and/or its subsidiary(-ies).
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

#ifndef __JPEG_YUV_DECODER_H__
#define __JPEG_YUV_DECODER_H__

#include <imageconversion.h>

/**
@internalAll

Extended decoder for JPEG images.
*/
class CJpegYuvDecoder : public CImageDecoder
	{
public:
	/**
	Flags to control how the image is decoded.
	These can be combined using an OR operation.
	*/
	enum TOptions
		{
		/** No flag set
		*/
		EOptionNone = 0x00,

		/** Decode the pixels in YUV format
		*/
		EOptionYuvDecode = 0x01
		};

public:
	IMPORT_C void ConvertYuv(TRequestStatus* aRequestStatus, CFbsBitmap& aDestination, TInt aFrameNumber = 0);
	IMPORT_C void ConvertYuv(TRequestStatus* aRequestStatus, CFbsBitmap& aDestination, CFbsBitmap& aDestinationMask, TInt aFrameNumber = 0);
	};

#endif // __JPEG_YUV_DECODER_H__
