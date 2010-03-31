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
// This is the plugin API for the Image Transform framework
// 
//

/**
 @file
 @publishedAll
 @released
*/

#ifndef __IMAGETRANSFORMPLUGIN_H__
#define __IMAGETRANSFORMPLUGIN_H__

#include <e32base.h>
#include <imagetransform.h>

// fwd ref
class CImageTransformFramework;
class CImageTransformPluginExtension;

/**
This is the plugin API for the Image Transform framework
Intended for use by plugin writers only.

@publishedAll
@released
*/
class CImageTransformPlugin : public CBase
	{
	friend class CImageTransformFramework;

public:
	IMPORT_C ~CImageTransformPlugin();

protected:
	/**
	Initialise the plugin and check the image transform settings.

	This is called by the ImageTransform framework when the client app calls
	CImageTransform::SetupL(). 
	
	The plugin should check the validity of the source image and all other settings
	set by the client API. If any of these is unsupported then it should leave with 
	KErrNotSupported.

	A plugin implementing CImageTransformPluginExtension to allow extension of the 
	client API should initialise it here.

	This is a virtual function that each individual plugin must implement.

	@leave  KErrUnsupported
	The plugin decoder doesn not support the request transformation
	*/
	virtual void OpenL() = 0;

	/**
	Initiate the image transform operation

	This is a virtual function that each individual plugin must implement.

	@param  aStatus
			The client's request status. 
			On completion contains an error code.
			KErrNone if image was transformed successfully,
	*/
	virtual void Transform(TRequestStatus& aStatus) = 0;

	/**
	Cancel the image transform operation
	May be called by the framework even when there is no outstanding request.

	This is a virtual function that each individual plugin must implement.
	*/
	virtual void CancelTransform() = 0;

	IMPORT_C CImageTransformPlugin();

	// getters
	IMPORT_C TBool SourceIsFilename() const;
	IMPORT_C TBool SourceIsData() const;
	IMPORT_C const TDesC& SourceFilename() const;
	IMPORT_C const TDesC8& SourceData() const;
	IMPORT_C const TDesC8& SourceMimeType() const;
	IMPORT_C const TUid SourceImageType() const;
	IMPORT_C const TUid SourceImageSubType() const;
	IMPORT_C TBool SourceRect(TRect& aRect) const;
	IMPORT_C TBool DestIsFilename() const;
	IMPORT_C TBool DestIsData() const;
	IMPORT_C const TDesC& DestFilename() const;
	IMPORT_C HBufC8*& DestData() const;
	IMPORT_C const TSize& DestinationSizeInPixels() const;
	IMPORT_C TUint Options() const;
	IMPORT_C TBool MaintainAspectRatio() const;
	IMPORT_C TBool PreserveImageData() const;
	IMPORT_C virtual CImageTransformPluginExtension* Extension() const;

private:
	IMPORT_C static CImageTransformPlugin* NewL(
		TUid aImplementationUid, CImageTransformFramework& aFramework);

	// Future proofing
	IMPORT_C virtual void ReservedVirtual1();
	IMPORT_C virtual void ReservedVirtual2();
	IMPORT_C virtual void ReservedVirtual3();
public:
	IMPORT_C virtual CImageTransformPluginExtension* Extension(TUid aExtensionUid, TInt& aError) const;

private:
	CImageTransformFramework* iFramework;
	};

#endif // __IMAGETRANSFORMPLUGIN_H__

