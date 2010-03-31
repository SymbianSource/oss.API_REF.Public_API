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
// Image Transform Panic Codes
// 
//

/**
 @file
 @publishedAll
 @released
*/

#ifndef __IMAGE_TRANSFORM_PANIC_CODES_H__
#define __IMAGE_TRANSFORM_PANIC_CODES_H__

/**
@publishedAll
@released

Panic codes for CImageTransform & CImageTransformPlugin
*/
enum TImageTransformPanic
	{
	/*
	This panic is raised if one of the reserved virtual functions is called
	*/
	EReservedCall,
	/*
	This panic can be raised by, for example, 
	calling Transform() without calling SetupL() first or
	calling SetupL() without specifying the source & destination & dest size
	*/
	EIllegalCallSequence,
	/*
	This panic is raised if no source is defined
	*/
	EUndefinedSourceType,
	/*
	This panic is raised if no destination is defined
	*/
	EUndefinedDestType,
	/*
	This panic is raised if no destination size is defined
	*/
	EUndefinedDestSize,
	/* 
	This panic can be raised by, for example, 
	calling SourceFilename() when source is a descriptor.
	Likewise for SourceDescriptor(), DestFilename(), DestDescriptor()
	*/
	EImageWrongType,
	/*
	This panic is raised if a zero-length MIME type is given
	*/
	EUndefinedMIMEType,
	/*
	This panic is raised if KNullUid is given as the image type
	and a non-null value for the subtype
	*/
	EIllegalImageSubType,
	};


#endif	// __IMAGE_TRANSFORM_PANIC_CODES_H__
