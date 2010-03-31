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
//

#ifndef __EIKFCTRY_H__
#define __EIKFCTRY_H__

#include <e32def.h>

class CCoeControl;

/** Flags to determine the control status.

@publishedPartner
@released
*/
enum
	{
	/** Flag to determine whether a control has ears. Ears are triangular buttons
	for moving forwards or backwards through the list. */
	EEikControlHasEars=0x01,
	/** Flag to determine whether the control is unable to receive keyboard focus. */
	EEikControlIsNonFocusing=0x02,
	/** Flag to determine whether the control is higher than a normal control. */
	EEikControlHasExtraAscent=0x04,
	/** Flag to determine if a control should be placed directly
	 in the view/dialog or if it should be placed in a pop-out control. */
	EEikControlIsNonEditInPlace=0x08
	};

/** Structure to hold the control specific information. It is used by 
EikControlFactory.

@see EikControlFactory
@publishedAll
@released
*/
struct SEikControlInfo
    {
    CCoeControl* iControl;
	TInt iTrailerTextId;
    TInt iFlags;
    };


/** Abstract factory that creates controls by type. 

This class provides a unified way to create controls according to the 
specified control integer ID. 

@publishedAll 
@released */
class EikControlFactory
	{
public:
    IMPORT_C static SEikControlInfo CreateByTypeL(TInt aControlType);
	};

#endif	// __EIKFCTRY_H__
