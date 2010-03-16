/*
* Copyright (c) 2002-2006 Nokia Corporation and/or its subsidiary(-ies).
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


#ifndef AKNLAYOUT2ID_H
#define AKNLAYOUT2ID_H

#include <e32std.h>

/**
* Enum for identifying regional variants
*/
enum TAknLayoutId
	{
	/**
	* Identifies left to right layouts
	*/
	EAknLayoutIdELAF = 0,
	/**
	* Identifies right to left layouts
	*/
	EAknLayoutIdABRW = 1,
	/**
	* Identifies Asian and Pacific layouts
	*/
	EAknLayoutIdAPAC = 2
	};

#endif
// End of File
