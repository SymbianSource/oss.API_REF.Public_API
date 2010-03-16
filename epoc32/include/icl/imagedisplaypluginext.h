// Copyright (c) 2004-2009 Nokia Corporation and/or its subsidiary(-ies).
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
// This is the extension to the plugin API for the Image Display framework
// 
//

#ifndef __IMAGEDISPLAYPLUGINEXT_H__
#define __IMAGEDISPLAYPLUGINEXT_H__

#include <e32base.h>

/**
This class should be derived by a plugin writer wishing to extend the client 
API defined in CImageDisplay

@publishedAll
@released
*/
class MImageDisplayPluginExtension
	{
public:
	
	/**
	Get a Uid by which a plugin extension can be identified.

	@return A Uid unique to the specific plugin extension
	*/
	virtual const TUid Uid() const = 0;
	/**
	  Can be called to indicate that extension is no longer needed
	*/
	virtual void Release() = 0;
	};

#endif // __IMAGEDISPLAYPLUGINEXT_H__
