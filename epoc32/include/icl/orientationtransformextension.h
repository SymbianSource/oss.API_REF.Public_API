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
// This is Image Transform extension for Rotate/Flip Transformations
// 
//

/**
 @file
 @publishedAll 
 @released
*/

#ifndef __ORIENTATIONTRANFORMEEXTENSION_H__
#define __ORIENTATIONTRANFORMEEXTENSION_H__

#include <e32base.h>
#include <icl/imagetransformpluginext.h>
#include <icl/icl_uids.hrh>

/**
@publishedAll 
@released

The Orientation Extension to the ImageTransform plugin.
 
The class provides the methods to set the image orientation and is intended to be implemented
by the plugins supporting the rotation of the image based on the orientation. The plugin
supporting this extension must use the opaque_data v2 format in RSS file and also the orientation flag
must be set in the opaque_data. The client must retrieve this extension implementation from 
the plugin using its extension UID. 
*/
class COrientationTransformExtension : public CImageTransformPluginExtension
	{
public:
	/** 
	The possible orientations of the image. Similar to the EXIF orientation tag
	*/
	enum TOrientation
		{
		/**
		No rotation done
		*/
		ERotationNone = 1,
		/**
		Rotate the image clockwise through 90 degrees.
		*/
		ERotation90DegreesClockwise = 6,
		/**
		Rotate the image clockwise through 180 degrees.
		*/
		ERotation180DegreesClockwise = 3,
		/**
		Rotate the image clockwise through 270 degrees.
		*/
		ERotation270DegreesClockwise = 8,
		/** 
		Mirror the image over its vertical axis
		*/
		EMirrorVerticalAxis = 2,
		/**
		Mirror the image over its horizontal axis
		*/
		EMirrorHorizontalAxis = 4,
		/**
		Transpose (or mirror) the image across a diagonal running from top-left to lower-right.
		*/
		ETransposeOverMainDiagonal = 5,
		/**
		Transpose (or mirror) the image across a diagonal running from top-right to lower-left.
		*/
		ETransposeOverMinorDiagonal = 7
		};	

	IMPORT_C void SetOrientationL(TOrientation aOrientation ) ;

protected:
	virtual void DoSetOrientationL(TOrientation aOrientation) = 0;

private:
	IMPORT_C virtual void ReservedVirtual5();

private:	
	// Future proofing
	TAny* iPad;
	};

#endif // __ORIENTATIONTRANFORMEEXTENSION_H__
