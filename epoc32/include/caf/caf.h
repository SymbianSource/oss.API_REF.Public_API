/*
* Copyright (c) 2003-2009 Nokia Corporation and/or its subsidiary(-ies).
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
* This contains all definitions required by clients accessing the 
* Content Access Framework.
*
*/




/**
 @file
 @publishedPartner
 @released
*/

#ifndef __CAF_H__
#define __CAF_H__

#include <e32std.h>

// Errors and Panics
#include <caf/caferr.h>
#include <caf/cafpanic.h>

// Enumerations
#include <caf/caftypes.h>

// Client side classes for use by the general public
#include <caf/agent.h>
#include <caf/content.h>
#include <caf/data.h>
#include <caf/manager.h>
#include <caf/supplier.h>
#include <caf/importfile.h>
#include <caf/rightsmanager.h>

// Utiltiy classes from CafUtils
#include <caf/supplieroutputfile.h>
#include <caf/metadata.h>
#include <caf/metadataarray.h>
#include <caf/virtualpath.h>
#include <caf/virtualpathptr.h>
#include <caf/embeddedobject.h>
#include <caf/attributeset.h>
#include <caf/rightsinfo.h>
#include <caf/attributeset.h>
#include <caf/stringattributeset.h>
#include <caf/streamableptrarray.h>
#include <caf/dirstreamable.h>

// deprecated headerfiles
#include <caf/attribute.h>
#include <caf/cafmimeheader.h>

#endif // __CAF_H__
