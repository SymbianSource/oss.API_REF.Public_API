// Copyright (c) 1997-2009 Nokia Corporation and/or its subsidiary(-ies).
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
// Some standard definitions used in GRID
// 
//

#if !defined(__GRDDEF_H__)
#define __GRDDEF_H__

/** Defines the direction and the amount by which a 
cursor is to move, when performing a scrolling operation.
@publishedAll
@released
@see CGridLay::PageScroll()
@see CGridImg::MoveCursorL() */
enum TMoveDirectionAndAmount
	{
	/** Move up by one row. */
	EMoveRowUp,
	/** Move down by one row. */
	EMoveRowDown,
	/** Move left by one column. */
	EMoveColumnLeft,
	/** Move right by one column. */
	EMoveColumnRight,
	/** Move up by one page. */
	EMovePageUp,
	/** Move down by one page. */
	EMovePageDown,
	/** Move left by one page. */
	EMovePageLeft,
	/** Move right by one page. */
	EMovePageRight,
	/** Move to the start of the row. */
	EMoveRowStart,
	/** Move to the end of the row */
	EMoveRowEnd,
	/** Move to the home position. */
	EMoveHome,
	/** Move to the end position. */
	EMoveEnd,
	/** Do not move the cursor. */
	EMoveNone,
	/** Move to the start of the column. */
	EMoveColumnStart,
	/** Move to the end of the column. */
	EMoveColumnEnd
	};


#endif
