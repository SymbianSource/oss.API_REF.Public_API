// Copyright (c) 2002-2009 Nokia Corporation and/or its subsidiary(-ies).
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
// This is the public client API for the BitmapTransforms library
// 
//

#ifndef BITMTRANSPANIC_H
#define BITMTRANSPANIC_H


#include <e32std.h>

/**
@panic	ENoSourceBitmap is raised when the src bitmap supplied to one of the api's
		has not been created (i.e. it has a null handle)
		ENoDestinationBitmap is raised when the destination bitmap supplied to one 
		of the api's has not been properly created
		EBitmapHasZeroDimension is raised when a bitmap has zero dimension

@publishedAll		
@released
*/

enum TBitmapTransformsPanic
	{
	/** Invalid source bitmap. */
	ENoSourceBitmap,
	/** Invalid destination bitmap. */
	ENoDestinationBitmap,
	/** The Bitmap has zero dimension. */
	EBitmapHasZeroDimension,
	/** Bad argument for scaling. */
	EBadArgumentScale,
	/** Bad argument for rotation. */
	EBadArgumentRotate,
	/** Null argument provided. */
	ENullArgument,
	/** Bad invariant. */
	EBadInvariant
	};


#endif // BITMTRANSPANIC_H

