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
// This is Image Transform extension for Squeeze Transformation 
// 
//

/**
 @file
 @publishedAll 
 @released
*/

#ifndef __SQUEEZETRANFORMEEXTENSION_H__
#define __SQUEEZETRANFORMEEXTENSION_H__

#include <e32base.h>
#include <icl/imagetransformpluginext.h>
#include <imageframeconst.h>

/** 
@publishedAll 
@released

This class provides advanced parameters for squeezing 
*/
class TAdvancedSqueezeParams
	{
public:
	/** 
	The different behaviours of auto resize 
	*/
	enum TAutoResizeAction
		{
		/** 
		Preserves the source encoding quality while shrinking the width and height of the image
		*/
		EAutoResizeActionPreserveSourceEncodingQuality,
		/**
		Tries to preserve the max image size while lowering the encoding quality 
		*/
		EAutoResizeActionPrioritizeLargeImageSize,
		/** 
		Tries to preserve the highest possible encoding quality while shrinking the width and height of the image 
		*/ 
		EAutoResizeActionResizePrioritizeHighEncodingQuality,
		/** 
		Simultaneously lower the encoding quality and shrink the width and height of the image 
		*/
		EAutoResizeActionMiddleCourse
		};

	IMPORT_C TAdvancedSqueezeParams();
	
	/** 
	The desired max size of the transformed image in bytes. 
	*/
	TUint iMaxDestSizeInBytes;

	/**
	The transformed image must not be smaller than this. The 
	size must be smaller than the iMaxImageSize 
	*/
	TSize iMinImageSize;

	/**
 	The transformed image must not be bigger than this. The size 
	must be bigger than the iMinImageSize 
	*/
	TSize iMaxImageSize;

	/** 
	The desired behaviour of the auto resize 
	*/
	TInt iResizeAction;

	/**
	The lowest desired encoding quality. 
	Must be in the range (0.0) to (1.0) 
	*/
	TReal32 iMinEncodingQuality;
	
	/**
	The color spacing of the transformed image 
	*/
	TUid iSamplingUid;
private:
	// Future proof
	TAny* iPad1;
	TAny* iPad2;
	TAny* iPad3;
	TAny* iPad4;
	};

/**
@publishedAll 
@released

Squeeze Extension to the ImageTransform plugin

The class provides the methods to set the squeeze parameters and is intended to be implemented
by the plugins supporting the squeezing of the images. The client can set the desired max size
(in bytes) of the squeezed image and it can also enable auto resizing of the image by setting the
advanced squeeze parameters. The plugin supporting this extension must use the opaque_data v2 format 
in RSS file and also the squeeze flag must be set in the opaque_data. The client must 
retrieve this extension implementation from the plugin using its extension UID.

In the case where the client's desired size cannot be met the operation will squeeze to the
smallest file possible and the transform operation will leave with KErrGeneral. The output file
must be examined by the client to determine its suitability. The client must clean up if the
output is not acceptable.
*/
class CSqueezeTransformExtension : public CImageTransformPluginExtension
	{
public:
	IMPORT_C void SetDestSizeInBytes(TUint aMaxDestDataSize ) ;
	IMPORT_C void SetAdvancedSqueezeModeL(TAdvancedSqueezeParams* aSqueezeAutoResizeParams ) ;

protected:
	virtual void DoSetDestSizeInBytes(TUint aMaxDestDataSize ) = 0;
	virtual void DoSetAdvancedSqueezeModeL(TAdvancedSqueezeParams* aSqueezeAutoResizeParams ) = 0;

private:
	IMPORT_C virtual void ReservedVirtual5();

private:	
	// Future proofing
	TAny* iPad;
	};

#endif // __SQUEEZETRANFORMEEXTENSION_H__
