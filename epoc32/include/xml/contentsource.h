// Copyright (c) 2003-2009 Nokia Corporation and/or its subsidiary(-ies).
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
// Plugin interface
// 
//

#ifndef __CONTENTSOURCE_H__
#define __CONTENTSOURCE_H__

namespace Xml
{

class MContentHandler;

class MContentSource
/** This interface must be implemented by xml framework plugins wishing
to pass data as part of a chain of plugins.

@publishedPartner
@released
*/
	{
public:
/** This method tells us what's the next content handler in the chain. */
	virtual void SetContentSink (MContentHandler& aContentHandler) = 0;
	};

}

#endif //__CONTENTSOURCE_H__
