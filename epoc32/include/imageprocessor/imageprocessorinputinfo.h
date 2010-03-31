// Copyright (c) 2008-2009 Nokia Corporation and/or its subsidiary(-ies).
// All rights reserved.
// This component and the accompanying materials are made available
// under the terms of "Eclipse Public License v1.0"
// which accompanies this distribution, and is available
// at the URL "http://www.eclipse.org/legal/epl-v10.html".
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

#ifndef __IMAGE_PROCESSOR_INPUT_INFO_H__
#define __IMAGE_PROCESSOR_INPUT_INFO_H__

#include <e32base.h>

namespace ImageProcessor
	{

class CImageProcessorImpl;

namespace Plugin
	{
	class MInputInfo;
	}

/**
This class provides functions to read image input details.

@publishedAll
@released
*/
class TInputInfo
	{
public:
	IMPORT_C TSize SizeL() const;
	IMPORT_C void FormatL(TUid& aFormat, TUid& aSubFormat) const;
	IMPORT_C TDisplayMode DisplayModeL() const; 
	IMPORT_C TUid ImageFrameFormatL() const;
	IMPORT_C TUid SamplingL() const; 
	IMPORT_C TUint32 BitsPerPixelL() const; 
	IMPORT_C TBool IsProgressiveL() const; 
	IMPORT_C TBool IsInterlacedL() const;
	IMPORT_C TBool HasAlphaL() const;
	IMPORT_C TAny* Extension(TUid aExtension) const;
	
private:
	friend class CImageProcessorImpl;
	TInputInfo(Plugin::MInputInfo& aInputInfoImpl, CImageProcessorImpl& aImageProcessorImpl);

	CImageProcessorImpl& iImageProcessorImpl;
	Plugin::MInputInfo& iInputInfoImpl;

	TInt iReserved; // future proof
	};

	}

#endif //__IMAGE_PROCESSOR_INPUT_INFO_H__
