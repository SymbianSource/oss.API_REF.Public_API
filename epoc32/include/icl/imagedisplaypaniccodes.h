// Copyright (c) 2004-2009 Nokia Corporation and/or its subsidiary(-ies).
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
// Image Display Panic Codes
// 
//

#ifndef __IMAGE_DISPLAY_PANIC_CODES_H__
#define __IMAGE_DISPLAY_PANIC_CODES_H__

/**
@publishedAll
@released

Panic codes for CImageDisplay & CImageDisplayPlugin
*/
enum TImageDisplayPanic
	{
	/**
	This panic is raised if one of the reserved virtual functions is called
	*/
	EReservedCall=0,	
	/**
	This panic can be raised by, for example, 
	calling PlayL() without calling SetupL() first or
	calling SetupL() without specifying the source
	*/
	EIllegalCallSequence,		// 1
	/**
	This panic is raised if no source is defined
	*/
	EUndefinedSourceType,		// 2
	/**
	This panic is raised if no destination size is defined
	*/
	EUndefinedDestSize,			// 3
	/** 
	This panic can be raised by, for example, 
	calling SourceFilename() when source is a descriptor.
	*/
	EImageWrongType,			// 4
	/**
	This panic is raised if a zero-length MIME type is given
	*/
	EUndefinedMIMEType,			// 5
	/**
	This panic is raised if KNullUid is given as the image type
	and a non-null value for the subtype
	*/
	EIllegalImageSubType,		// 6
	/**
	This panic is raised if callback is still active
	and Play() method is called again
	*/
	ECallbackStillActive,		// 7
	};


#endif	// __IMAGE_DISPLAY_PANIC_CODES_H__
