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

#ifndef __COEERROR_H__
#define __COEERROR_H__

/**
@internalTechnology
*/
#define KUidConeDllValue16 0x10003a41

/**
@internalTechnology
*/
const TUid KUidConeDll16={KUidConeDllValue16};


#if defined(_UNICODE)
/**
@internalTechnology
*/
#define KUidConeDllValue KUidConeDllValue16
/**
@internalTechnology
*/
const TUid KUidConeDll={KUidConeDllValue};
#else
#define KUidConeDllValue KUidConeDllValue8
const TUid KUidConeDll={KUidConeDllValue};
#endif


/** UI Control Framework errors.

@publishedAll
@deprecated */
enum
	{
	/** Not used. */
	KErrCoeResourceFileDuplicateOffset,
	/** Read fail. CCoeEnv::ReadResource() sets this as the
	active scheduler's extended error number if the read fails.	*/
	KErrCoeFailedToReadFromProgDisk
	};

#endif	// __COEERROR_H__
