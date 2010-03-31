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

#ifndef __IMAGE_PROCESSOR_PROGRESS_INFO_H__
#define __IMAGE_PROCESSOR_PROGRESS_INFO_H__

#include <e32base.h>

namespace ImageProcessor
	{

class CImageProcessorImpl;

namespace Plugin
	{
	class MProgressInfo;
	}

/**
This class provides functions to read progress information.

@publishedAll
@released
*/
class TProgressInfo
	{
public:
	IMPORT_C TInt CurrentIterationL() const;
	IMPORT_C TInt NumberOfIterationsL() const;
	IMPORT_C TAny* Extension(TUid aExtension) const;
	
private:
	friend class CImageProcessorImpl;
	TProgressInfo(Plugin::MProgressInfo& aProgressInfoImpl, CImageProcessorImpl& aImageProcessorImpl);

	CImageProcessorImpl& iImageProcessorImpl;
	Plugin::MProgressInfo& iProgressInfoImpl;

	TInt iReserved; // future proof
	};

	}

#endif //__IMAGE_PROCESSOR_PROGRESS_INFO_H__
