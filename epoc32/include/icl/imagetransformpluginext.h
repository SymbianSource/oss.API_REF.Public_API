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
// This is the extension to the plugin API for the Image Transform framework
// 
//

/**
 @file
 @publishedAll
 @released
*/

#ifndef __IMAGETRANSFORMPLUGINEXT_H__
#define __IMAGETRANSFORMPLUGINEXT_H__

#include <e32base.h>

/**
This class should be derived by a plugin writer wishing to extend the client 
API defined in CImageTransform

@publishedAll
@released
*/
class CImageTransformPluginExtension : public CBase
	{
public:
	
	/**
	Get a Uid by which a plugin extension can be identified.

	@return A Uid unique to the specific plugin extension
	*/
	IMPORT_C virtual const TUid Uid() const = 0;
private:
	// Future proofing
	IMPORT_C virtual void ReservedVirtual1();
	IMPORT_C virtual void ReservedVirtual2();
	IMPORT_C virtual void ReservedVirtual3();
	IMPORT_C virtual void ReservedVirtual4();
	};

#endif // __IMAGETRANSFORMPLUGINEXT_H__
