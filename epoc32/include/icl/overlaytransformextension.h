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
// This is Image Transform extension for Overlay/Replace transformations
// 
//

/**
 @file
 @publishedAll 
 @released
*/

#ifndef __OVERLAYTRANFORMEEXTENSION_H__
#define __OVERLAYTRANFORMEEXTENSION_H__

#include <e32base.h>
#include <e32cmn.h>
#include <icl/imagetransformpluginext.h>

//fwd decl
class CFbsBitmap;
class CImageFrame;

/**
@publishedAll 
@released

Overlay/Replace Extension to the ImageTransform plugin

The class provides the methods to set the overlay/replace parameters and is intended to be implemented
by the plugins supporting the blending of the images. The client can set the overlay image, the overlay 
position and the transparency of the overlay image. The plugin supporting this extension must use 
the opaque_data v2 format in RSS file and also the overlay flag must be set in the opaque_data.
The client must retrieve this extension implementation from the plugin using its extension UID.
*/
class COverlayTransformExtension : public CImageTransformPluginExtension
	{
public:
	IMPORT_C void SetPosition(const TPoint& aPosition);
	IMPORT_C void SetTransparencyLevelL(TUint aLevel);
	IMPORT_C void SetOverlayFileL(const TDesC& aFilename, const TUid& aOverlayImageUid);
	IMPORT_C void SetOverlayDataL(const TDesC8& aData, const TUid& aOverlayImageUid);
	IMPORT_C void SetOverlayImageL(const CFbsBitmap& aBitmap);
	IMPORT_C void SetOverlayImageL(const CImageFrame& aImageFrame);
	IMPORT_C void SupportedOverlayInputFormatsL(RArray<TUid>& aFormats) const;
	IMPORT_C void SupportedOverlayInputSubFormatsL(TUid aFormat, RArray<TUid>& aSubFormats) const;
	
protected:
	virtual void DoSetPosition(const TPoint& aPosition) = 0;
	virtual void DoSetTransparencyLevelL(TUint aLevel) = 0;
	virtual void DoSetOverlayFileL(const TDesC& aFilename, const TUid& aOverlayImageUid) = 0;
	virtual void DoSetOverlayDataL(const TDesC8& aData, const TUid& aOverlayImageUid) =0;
	virtual void DoSetOverlayImageL(const CFbsBitmap& aBitmap) =0;
	virtual void DoSetOverlayImageL(const CImageFrame& aImageFrame) =0;
	virtual void DoSupportedOverlayInputFormatsL(RArray<TUid>& aFormats) const =0;
	virtual void DoSupportedOverlayInputSubFormatsL(TUid aFormat, RArray<TUid>& aSubFormats) const = 0;

private:
	IMPORT_C virtual void ReservedVirtual5();

private:	
	// Future proofing
	TAny* iPad;
	};

#endif // __OVERLAYTRANFORMEEXTENSION_H__
