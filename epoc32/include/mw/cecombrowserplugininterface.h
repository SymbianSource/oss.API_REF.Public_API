/*
* Copyright (c) 2006 Nokia Corporation and/or its subsidiary(-ies).
* All rights reserved.
* This component and the accompanying materials are made available
* under the terms of the License "Eclipse Public License v1.0"
* which accompanies this distribution, and is available
* at the URL "http://www.eclipse.org/legal/epl-v10.html".
*
* Initial Contributors:
* Nokia Corporation - initial contribution.
*
* Contributors:
*
* Description:  
*
*/

#ifndef CECOMBROWSERPLUGININTERFACE_H
#define CECOMBROWSERPLUGININTERFACE_H

// System includes
#include <e32base.h>
#include <ecom/ecom.h>

// User includes
#include "npupp.h"
#include "BrowserPluginInterface.h"

typedef struct
    {
    NPNetscapeFuncs* iNetscapeFuncs;
    NPPluginFuncs* iPluginFuncs;
    }TFuncs;

//
// The ECOM interface definition for a Netscape plugin interface class.
//
class CEcomBrowserPluginInterface: public CBase
	{
	public: 

        inline static CEcomBrowserPluginInterface* CreatePluginL(
                                        TUid aImplementationUid,
                                        NPNetscapeFuncs* aNetscapeFuncs,
                                        NPPluginFuncs* aPluginFuncs);
		
		inline virtual ~CEcomBrowserPluginInterface();
		
  public:

	private:
  //	The ECom destructor key identifier
	TUid iEcomDtorID;

	// A refedrence count
	TInt iCount;

	};

//
//
inline CEcomBrowserPluginInterface* CEcomBrowserPluginInterface::CreatePluginL(
        TUid aImplementationUid,
        NPNetscapeFuncs* aNetscapeFuncs,
        NPPluginFuncs* aPluginFuncs)
	{

	TFuncs initParams;
	initParams.iNetscapeFuncs = aNetscapeFuncs;
	initParams.iPluginFuncs = aPluginFuncs;

	TAny* ptr = REComSession::CreateImplementationL(aImplementationUid, 
									_FOFF(CEcomBrowserPluginInterface, iEcomDtorID),
                                    &initParams);

	return REINTERPRET_CAST(CEcomBrowserPluginInterface*, ptr);
	}

inline CEcomBrowserPluginInterface::~CEcomBrowserPluginInterface()
	{
	REComSession::DestroyedImplementation(iEcomDtorID);
	} 	


#endif // CECOMBROWSERPLUGININTERFACE_H




