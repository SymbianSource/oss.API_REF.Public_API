/*
* Copyright (c) 1997-1999 Nokia Corporation and/or its subsidiary(-ies).
* All rights reserved.
* This component and the accompanying materials are made available
* under the terms of the License "Symbian Foundation License v1.0" to Symbian Foundation members and "Symbian Foundation End User License Agreement v1.0" to non-members
* which accompanies this distribution, and is available
* at the URL "http://www.symbianfoundation.org/legal/licencesv10.html".
*
* Initial Contributors:
* Nokia Corporation - initial contribution.
*
* Contributors:
*
* Description:
*
*/


#ifndef __LAFVCURS_H__
#define __LAFVCURS_H__

#include <e32std.h>
#include <w32std.h>


class LafVirtualCursor
/** Virtual cursor LAF support.

@publishedPartner 
@released */
	{
public:
	/** Gets the mode that should be used when the virtual cursor is switched on. 
	
	The return value has no effect for devices not using a virtual cursor. 
	
	@return Cursor mode */
	IMPORT_C static TPointerCursorMode PointerCursorOnMode();
	};

#endif
