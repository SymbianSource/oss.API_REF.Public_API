// Copyright (c) 2000-2009 Nokia Corporation and/or its subsidiary(-ies).
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
//



/**
 @file
 @publishedPartner
 @released
*/

#ifndef __PLUGINKILLER_H__
#define __PLUGINKILLER_H__


#include <e32base.h>

///Forward Declarations
class CPushHandlerBase;

/** 
Utility class used by a WAP Push Application plugin to delete itself. 

@publishedPartner
@released
*/
class CPluginKiller: public CActive 
	{
public:
	virtual ~CPluginKiller();

	CPluginKiller(CPushHandlerBase* aPushPlugin);
	IMPORT_C void KillPushPlugin();

protected:
	virtual void DoCancel();
	virtual void RunL();

private:
	CPushHandlerBase*		iPushPlugin;
	TBool					iDeletePushPlugin;
	};

#endif //_PLUGINKILLER_H
