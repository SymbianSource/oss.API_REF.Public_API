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

#ifndef __IMAGE_PROCESSOR_OUTPUT_INFO_H__
#define __IMAGE_PROCESSOR_OUTPUT_INFO_H__

#include <e32base.h>

namespace ImageProcessor
	{

class CImageProcessorImpl;
	
namespace Plugin
	{
	class MOutputInfo;
	}

/**
This class provides functions to write image output details.

@publishedAll
@released
*/
class TOutputInfo
	{
public:
	IMPORT_C void SetJpegQualityL(TReal32& aQuality);
	IMPORT_C void SetSamplingL(TUid& aSampling);
	IMPORT_C TAny* Extension(TUid aExtension) const;
	
private:
	friend class CImageProcessorImpl;
	TOutputInfo(Plugin::MOutputInfo& aOutputInfoImpl, CImageProcessorImpl& aImageProcessorImpl);

	CImageProcessorImpl& iImageProcessorImpl;
	Plugin::MOutputInfo& iOutputInfoImpl;

	TInt iReserved; // future proof
	};

	}

#endif //__IMAGE_PROCESSOR_OUTPUT_INFO_H__
